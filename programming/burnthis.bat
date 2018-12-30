REM Program a TSL unit and then add a record to the airtable units database
REM Args: Label serial number of the unit to be programmed

SETLOCAL

REM run in default color
color

set errormessage=

set serialno=

IF "%~1" == "" (
	REM No serial number passed
	SET /p serialno= Serial Number or blank to quit:
) else (
	set serialno=%1
)


REM Update delayseconds to reflect the number of seconds to add to thet start time to account for
REM the delay in getting everything programmed into the EEPROM

set delayseconds=4
set firmwarefile=tsl.hex

set tempunparsedstarttimefile=%tmp%\unparsedstarttime.txt
set tempeepromfile=%tmp%\burniteeprom.txt
set tempdeviceidfile=%tmp%\burnitdeviceid.txt
set tempfirmwarehashfile=%tmp%\burnitfirmwarehash.txt
set tempfirmwarerecordfile=%tmp%\burnitfirmwarerecord.txt


REM Test if serialno was set. Note this must be after the IF or it does not work
if "%serialno%"=="" (
	set errormessage=No serial number specified
	goto end 
)

REM Generate a fingerprint of the firmware we just programming
call md5\md5.bat %firmwarefile% >%tempfirmwarehashfile%
set /p firmwarehash=<%tempfirmwarehashfile%


REM Lets make sure that this firmware hash is in the airtable firmwares table
REM We have to do this because Airtable is hokey and will not let us create a new record with a linked field
REM unless we provide the "record ID" of the target of the linked field. :/

curl\bin\curl "https://api.airtable.com/v0/app11MZ4rXXpEyFnj/Firmwares?fields=&filterByFormula=Hash='%firmwarehash%'&maxRecords=1" -H "Authorization: Bearer keyfJVUThzOsPBNNJ" >%tempfirmwarerecordfile%
if errorlevel 1 (
	set errormessage=Error with firmware record lookup request on airtable.com
	goto end
)

set /p firmwarerecord=<%tempfirmwarerecordfile%

REM  The returned string has embeded quotes. This escapes them so we can use the string. OMG this is so ugly.
REM https://stackoverflow.com/a/562131/3152071
REM Note that I had to convert the quotes to "Q" to get this to work otherwise the IF was choking on all the quoted quotes.
REM No chance of the Q having a collision in this context. 

set firmwarerecordescaped=%firmwarerecord:"=Q%

REM If firmware hash is found, then the returned string from airtable looks {"records":[{"id":"recG6cEJLSYWvHXHU",
REM If not, then it looks like {"records":[]}

if "%firmwarerecordescaped:~0,14%"=="{QrecordsQ:[]}" (
	set errormessage=Firmware hash not found in Firmwares table on airtable.com. Add it!
	goto end
)

if NOT "%firmwarerecordescaped:~0,19%"=="{QrecordsQ:[{QidQ:Q" (
	set errormessage=Unexpected format for returned record ID in Firmwares table on airtable.com. 
	goto end
)

if NOT "%firmwarerecordescaped:~36,1%"=="Q" (
	set errormessage=Closing quote not found on returned record ID in Firmwares table on airtable.com. 
	goto end
)

set firwarerecordid=%firmwarerecordescaped:~19,17%

echo %firwarerecordid%

goto end


REM First lets capture the device ID from the ATMEGA chip
REM https://electronics.stackexchange.com/questions/414087/how-can-you-read-out-the-serial-number-of-an-xmega-chip-in-a-batch-file-during-p
"C:\Program Files (x86)\Atmel\Studio\7.0\atbackend\atprogram.exe" --tool avrispmk2 --interface pdi --device atxmega128b3 read --prodsignature --offset 0x08 --size 11 --format hex --file %tempdeviceidfile%
if errorlevel 1 (
	set errormessage=Error getting device ID from unit XMEGA 
	goto end
)
set /p deviceid=<%tempdeviceidfile%

REM Next lets write fuses on the XMEGA. We turn program RSTDSBL
"C:\Program Files (x86)\Atmel\Studio\7.0\atbackend\atprogram.exe" --tool avrispmk2 --interface pdi --device atxmega128b3 write --fuses --values FFFFFFFFEEF7
if errorlevel 1 (
	set errormessage=Error programming XMEGA fuses
	goto end
)

REM Next lets program the firmware and fuses into the flash on the XMEGA
"C:\Program Files (x86)\Atmel\Studio\7.0\atbackend\atprogram.exe" --tool avrispmk2 --interface pdi --device atxmega128b3 program --flash --chiperase --format hex --verify --file %firmwarefile% 
if errorlevel 1 (
	set errormessage=Error downloading firmware to flash on XMEGA 
	goto end
)

REM Next lets generate the eeprom block with the current time as start time
tsl-make-block %tempeepromfile% %delayseconds% | findstr "Start time" >%tempunparsedstarttimefile%
set /p starttimeline=<%tempunparsedstarttimefile%
REM The time is after the string "Start time:"
REM This funcky syntax does a substring starting at pos 10
set "starttime=%starttimeline:~11%"

REM And now program the eeprom block into the XMEGA
"C:\Program Files (x86)\Atmel\Studio\7.0\atbackend\atprogram.exe" --tool avrispmk2 --interface pdi --device atxmega128b3 erase --eeprom program --eeprom --format bin --verify --file %tempeepromfile% 
if errorlevel 1 (
	set errormessage=Error writing eeprom block to XMEGA 
	goto end
)


REM Starttime in quotes because it has embeded spaces
call airtable-insert.bat "%starttime%" %serialno% %firmwarehash% %deviceid%

if errorlevel 1 (
	set errormessage=Error adding unit record to airtable database
	goto end
)


:end

REM Clean up after ourselves 
rm %tempeepromfile%
rm %tempunparsedstarttimefile%
rm %tempdeviceidfile%
rm %tempfirmwarehashfile%
rm %tempfirmwarerecordfile%


@if "%errormessage%"=="" (
	REM Color white on green
	color 27
	@echo SUCCESS
) else (
	REM Color white on red
	color 47
	@echo ERROR !!!  %errormessage% !!!	
)

@ENDLOCAL

