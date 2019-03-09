REM Read and print the eeprom contents from a TSL unit 

REM clear out the rrormessage variable since we use this to see if everything OK
set "errormessage="

set tempeepromfile=%tmp%\burniteeprom.txt
set tempdeviceidfile=%tmp%\burnitdeviceid.txt


REM Lets capture the device ID from the ATMEGA chip
REM https://electronics.stackexchange.com/questions/414087/how-can-you-read-out-the-serial-number-of-an-xmega-chip-in-a-batch-file-during-p
"C:\Program Files (x86)\Atmel\Studio\7.0\atbackend\atprogram.exe" --tool avrispmk2 --interface pdi --device atxmega128b3 read --prodsignature --offset 0x08 --size 11 --format hex --file %tempdeviceidfile%
if errorlevel 1 (
	set errormessage=Error getting device ID from unit XMEGA 
	goto end
)
set /p deviceid=<%tempdeviceidfile%


REM And now read the  eeprom block from the XMEGA
"C:\Program Files (x86)\Atmel\Studio\7.0\atbackend\atprogram.exe" --tool avrispmk2 --interface pdi --device atxmega128b3 read --eeprom --format bin --file %tempeepromfile% 

echo error %errorlevel%

if errorlevel 1 (
	echo in error
	set errormessage=Error reading eeprom block from XMEGA 
	goto end
)

echo we got here

:end


if "%errormessage%"=="" (
	REM Color white on green
	color 27
	@echo SUCCESS
	
	@echo DEVICEID %deviceid%
	eeprom-utils-bin\tsl-read-block.exe %tempeepromfile%
	
	
) else (
	REM Color white on red
	color 47
	@echo ============================================================================================================
	@echo ERROR !!!  %errormessage% !!!	
)

REM Clean up after ourselves 
@del %tempeepromfile%
@del %tempdeviceidfile%


@ENDLOCAL

