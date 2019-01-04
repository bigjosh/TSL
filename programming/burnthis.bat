REM Program a TSL unit and then add a record to the airtable units database
REM Args: Label serial number of the unit to be programmed

REM We need the APIKEY to access airtable, but we do not want to store it inside this batch file
REM since then it would be exposed. So we keep it in the local machine registry under the 
REM name `burnthis_airtable_api_key`. If you ever want to delete this key, you run the command...
REM `REG delete HKCU\Environment /V burnthis_airtable_api_key`

color

REM Update delayseconds to reflect the number of seconds to add to the start time to account for
REM the delay in getting everything programmed into the EEPROM

set delayseconds=7
set firmwarefile=tsl.hex

set tempunparsedstarttimefile=%tmp%\unparsedstarttime.txt
set tempeepromfile=%tmp%\burniteeprom.txt
set tempdeviceidfile=%tmp%\burnitdeviceid.txt
set tempfirmwarehashfile=%tmp%\burnitfirmwarehash.txt
set tempfirmwarerecordfile=%tmp%\burnitfirmwarerecord.txt

if NOT "%burnthis_airtable_api_key%"=="" goto have_api_key

@echo *** We need your Airtable API key!
@echo *** You can get it here...
@echo *** https://airtable.com/account
@echo *** You only need to do this once per user/computer.
@note *** Note this key is stored in plaintext in the registry. 
@echo *** Instructions for deleting removing key are
@echo *** are in the comments of this batch file. 
SET /p burnthis_airtable_api_key= Airtable API key or blank to quit:	

REM We have to use delayed explanation here because, well, this is batch
REM https://stackoverflow.com/questions/9102422/windows-batch-set-inside-if-not-working

if "%burnthis_airtable_api_key%"=="" (
	set errormessage=No Airtable API key set
	goto end 
)
	
REM Save for next time...
setx burnthis_airtable_api_key %burnthis_airtable_api_key%


:have_api_key

REM Note that we hold off on setlocal so that this command window will keep  the
REM burnthis_airtable_api_key variable as long as it is open. This is needed because
REM setx will not set the variable for this window, only ones started in the future. 

SETLOCAL

:nextserial

set errormessage=

set serialno=

IF "%~1" == "" (
	REM No serial number passed
	SET /p serialno= Serial Number or blank to quit:
) else (
	set serialno=%1
)


REM Test if serialno was set. Note this must be after the IF or it does not work
if "%serialno%"=="" (
	set errormessage=No serial number specified
	goto end 
)

REM Running programming cycle in black background
REM Will turn red or green when done
color

REM Generate a fingerprint of the firmware we just programming
call md5\md5.bat %firmwarefile% >%tempfirmwarehashfile%
set /p firmwarehash=<%tempfirmwarehashfile%


REM Lets make sure that this firmware hash is in the airtable firmwares table
REM We have to do this because Airtable is hokey and will not let us create a new record with a linked field
REM unless we provide the "record ID" of the target of the linked field. :/

curl\bin\curl "https://api.airtable.com/v0/app11MZ4rXXpEyFnj/Firmwares?fields=&filterByFormula=Hash='%firmwarehash%'&maxRecords=1" -H "Authorization: Bearer %burnthis_airtable_api_key%" >%tempfirmwarerecordfile%
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
	set errormessage=Firmware hash '%firmwarehash%' not found in Firmwares table on airtable.com. Add it!
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

REM Ok, now we finally have the recordID we need to give airtable for it to let us create a record in Units. 

set firwarerecordid=%firmwarerecordescaped:~19,17%


REM Lets capture the device ID from the ATMEGA chip
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

echo Starting time programming sequence at %time%

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

echo Ending time programming sequence at %time%


REM Starttime in quotes because it has embeded spaces
call airtable-insert.bat "%starttime%" %serialno% %firwarerecordid% %deviceid% %burnthis_airtable_api_key%

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
	REM Loop back for next unit if we started in scanning batch mode
	IF "%~1" == "" goto nextserial
) else (
	REM Color white on red
	color 47
	@echo ============================================================================================================
	@echo ERROR !!!  %errormessage% !!!	
)

@ENDLOCAL

