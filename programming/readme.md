# TSL Factory Programming

Each TSL needs to get programmed with firmware and the current time.

This setup assumes you are programming using a Windows computer with Atmel Studio 7 installed and an Atmel MkII programmer.

TODO: This windows stuff is hokey and brittle. Use a dedicated Raspberry Pi with GPS to do programming.

## Set up

Get to a command prompt in the directory with this readme. 

Find the location of you "atprogram.exe" that was installed with Atmel Studio. If it is not at `C:\Program Files (x86)\Atmel\Studio\7.0\atbackend\atprogram.exe` then edit the `burnthis.bat` file to fix the path.

Make sure your computer has the right time and date. It is probably a good idea to install an NTP client or GPS slave at some point to keep the time accurate to the second.

## Figuring out the programming lag offset for your set up

You can specify a number of seconds to add or subtract to the current time when programming the TSL to Account for delays in the programming process. 

Try programming a unit with the default offset and then compare the clock time on the TSL to the the time on the computer. If the TSL is off by more than +/- 1 second then adjust the value of `offset` in the `burnthis.bat` file and try again. 
  
## Procedure

1. Connect the TSL to the programming jig.
2. Enter the command `burnthis.bat` on the command line. (Use up arrow or F3 on subsequent passes)
3. Watch it program.
4. Remove the TSL and check that is has the correct GMT time on the LCD.
5. Insert the trigger pin.
6. Confirm that the TSL goes to Ready To Launch mode and all the segments look good.


 