This program writes the code that updates the LCD in the TSL firmware.

To update...

1. Make changes to the code in `code2code.cpp`
2. Build
3. From a command prompt in the `Release` directory, run `code2code.exe >code2code_output.s`
4. Now copy the `code2code_output.s` output file to the TSL firmware `software\AS7\TSL` directory over writing the existing file.  
5. Rebuild the TSL firmware



 