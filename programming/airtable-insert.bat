REM Insters a record into the units database on airtable 
REM Args: Starttime, Serialnumber, Firmware, DeviceID, APIkey

SETLOCAL
REM %~1 will remove enclosing quotes
set "starttime=%~1"
set "serialnumber=%2"
set "firmware=%3"
set "deviceid=%4"
set "apikey=%5"

set tempfile=%tmp%\airtablejson.txt

REM Escaping the quotes in the JSON string...
REM https://stackoverflow.com/questions/12849017/echo-of-string-with-double-quotes-to-output-file-using-windows-batch

echo { ^"fields^": { ^"Starttime^": ^"%starttime%^", ^"Serialnumber^": ^"%serialnumber%^", ^"Firmware^": [^"%firmware%^"], ^"DeviceID^": ^"%deviceid%^" } } >%tempfile%

REM This command string comes from airtable...
REM https://airtable.com/app11MZ4rXXpEyFnj/api/docs#curl/table:units:create
REM ...but the syntax was a little wrong (like the XPOST?). We also use the `@` for the `-d` command to send data from a file. 

curl\bin\curl -v https://api.airtable.com/v0/app11MZ4rXXpEyFnj/Units -H "Authorization: Bearer %apikey%" -d @%tempfile% -H "Content-Type: application/json"

if errorlevel 1 (

	rm %tempfile%
	ENDLOCAL
	
	exit /B 1
	
)

exit /B 0 

