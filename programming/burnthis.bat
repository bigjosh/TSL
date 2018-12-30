REM Program a TSL unit and then add a record to the airtable units database
REM Args: Label serial number of the unit to be programmed

SETLOCAL
echo 1 %1 1

set serialno=

IF "%~1" == "" (
	REM No serial number passed
	SET /p serialno= Serial Number or blank to quit:
) else (
	set serialno=%1
)

REM TEst if serialno was set. Note this must be after the IF or it does not work
if "%serialno%"=="" goto end 


REM Update delayseconds to reflect the number of seconds to add to thet start time to account for
REM the delay in getting everything programmed into the EEPROM

set delayseconds=4
set firmwarefile=tsl.hex

set tempunparsedstarttimefile=%tmp%\unparsedstarttime.txt
set tempeepromfile=%tmp%\burniteeprom.txt
set tempdeviceidfile=%tmp%\burnitdeviceid.txt
set tempfirmwarehashfile=%tmp%\burnitfirmwarehash.txt

REM First lets capture the device ID from the ATMEGA chip
REM https://electronics.stackexchange.com/questions/414087/how-can-you-read-out-the-serial-number-of-an-xmega-chip-in-a-batch-file-during-p
"C:\Program Files (x86)\Atmel\Studio\7.0\atbackend\atprogram.exe" --tool avrispmk2 --interface pdi --device atxmega128b3 read --prodsignature --offset 0x08 --size 11 --format hex --file %tempdeviceidfile%
if errorlevel 1 (
	echo ERROR GETTING DEVICE ID
	goto end
)
set /p deviceid=<%tempdeviceidfile%

REM Next lets write fuses on the XMEGA. We turn program RSTDSBL
"C:\Program Files (x86)\Atmel\Studio\7.0\atbackend\atprogram.exe" --tool avrispmk2 --interface pdi --device atxmega128b3 write --fuses --values FFFFFFFFEEF7
if errorlevel 1 (
	echo ERROR PROGRAMMING FUSES
	goto end
)

REM Next lets program the firmware and fuses into the flash on the XMEGA
"C:\Program Files (x86)\Atmel\Studio\7.0\atbackend\atprogram.exe" --tool avrispmk2 --interface pdi --device atxmega128b3 program --flash --chiperase --format hex --verify --file %firmwarefile% 
if errorlevel 1 (
	echo ERROR PROGRAMMING FIRMWARE
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
	echo ERROR PROGRAMMING EEPROM DATA BLOCK
	goto end
)


REM next generate a fingerprint of the firmware we just programming
call md5\md5.bat %firmwarefile% >%tempfirmwarehashfile%
set /p firmwarehash=<%tempfirmwarehashfile%

REM Clean up after ourselves 
rm %tempeepromfile%
rm %tempunparsedstarttimefile%
rm %tempdeviceidfile%
rm %tempfirmwarehashfile%

REM Starttime in quotes because it has embeded spaces
call airtable-insert.bat "%starttime%" %serialno% %firmwarehash% %deviceid%
 
ENDLOCAL

:end