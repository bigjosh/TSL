REM Insters a record into the units database on airtable 
REM Args: Starttime, Serialnumber, Firmware, DeviceID, APIkey

SETLOCAL
REM %~1 will remove enclosing quotes
set "starttime=%~1"
set "serialnumber=%2"
set "firmware=%3"
set "deviceid=%4"
set "apikey=%5"

set temp_req_file=%tmp%\airtablejson.txt
set temp_res_file=%tmp%\airtableresp.txt

REM Escaping the quotes in the JSON string...
REM https://stackoverflow.com/questions/12849017/echo-of-string-with-double-quotes-to-output-file-using-windows-batch

echo { ^"fields^": { ^"Starttime^": ^"%starttime%^", ^"Serialnumber^": ^"%serialnumber%^", ^"Firmware^": [^"%firmware%^"], ^"DeviceID^": ^"%deviceid%^" } } >%temp_req_file%

REM This command string comes from airtable...
REM https://airtable.com/app11MZ4rXXpEyFnj/api/docs#curl/table:units:create
REM ...but the syntax was a little wrong (like the XPOST?). We also use the `@` for the `-d` command to send data from a file. 

curl\bin\curl -v https://api.airtable.com/v0/app11MZ4rXXpEyFnj/Units -H "Authorization: Bearer %apikey%" -d @%temp_req_file% -H "Content-Type: application/json" >%airtableresp%

if errorlevel 1 (

	rm %temp_req_file%
	ENDLOCAL
	
	exit /B 1
	
)


REM next we need to parse out the record ID from that insert into the units database so we can use it
REM in the instert into the junction table

set /p airtableres=<%temp_res_file%

REM  The returned string has embeded quotes. This escapes them so we can use the string. OMG this is so ugly.
REM https://stackoverflow.com/a/562131/3152071
REM Note that I had to convert the quotes to "Q" to get this to work otherwise the IF was choking on all the quoted quotes.
REM No chance of the Q having a collision in this context. 

set airtableresescaped=%airtableres:"=Q%

echo %airtableresescaped%

exit /B 0 

