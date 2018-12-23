# TSL Factory Programming

Each TSL needs to get programmed with firmware and the current time before it can launch!

This setup assumes you are programming using a Windows computer with Atmel Studio 7 installed and an Atmel MkII programmer.

TODO: This windows stuff is hokey and brittle. Use a dedicated Raspberry Pi with GPS to do programming.

## Set up

Get to a command prompt in the directory with this readme. 

Make sure your computer has the right time and date. It is probably a good idea to install an NTP client or GPS slave at some point to keep the time accurate to the second.

### Adjust `atprogram` path 

Find the location of you "atprogram.exe" that was installed with Atmel Studio. If it is not at `C:\Program Files (x86)\Atmel\Studio\7.0\atbackend\atprogram.exe` then edit the `burnthis.bat` file to fix the path.

### Adjust programming lag offset

The programming procedure takes more than a second to complete, so if we just programmed the current adjusted time then the TSL would end up behind.

You can specify a number of seconds to add or subtract to the current time when programming the TSL to account for these delays in the programming process. 

Try programming a unit with the default offset and then compare the clock time on the TSL to the the time on the computer. If the TSL is off by more than +/- 1 second then adjust the value of `offset` in the `burnthis.bat` file and try again. 
  
## Procedure

1. Connect the TSL to the programming jig.
2. Enter the command `burnthis.bat` on the command line. (Use up arrow or F3 on subsequent passes)
3. Watch it program.
4. Remove the TSL and check that is has the correct GMT time on the LCD.
5. Insert the trigger pin.
6. Confirm that the TSL goes to Ready To Launch mode and all the segments look good.


## How it works

### tsl-make-block

First the batch file uses the `tsl-make-block` to create a binary file to be programmed into the TSL EEPROM. The program checks the clock on the local PC, converts the current time to GMT, and then adds in the delay offset. Then it writes out the EEPROM data block in the format that the TSL firmware expects to find when it runs. The block contains:

1. The current time GMT
2. A flag that tells the firmware to copy this time to the RX8900 RTC when it sees it
3. The trigger time and flag, which we set to "not triggered yet". 
4. A flag that remembers if the RTC in the TSL has ever reported that it lost power, which we initialize to `not set`.
 
### atprogram

Next the batch file uses the `atprogram` command to actually download the firmware flash image and the newly created EEPROM data block into the XMEGA on the TSL.  The `atprogram` is equivalent to `avrdude` but it written by Atmel and runs on Windows and uses the Atmel drivers. We used `atprogram`  because `avrdude` can have problems talking to an `MkII` when Atmel Studio is installed because of USB driver conflicts.  

#### Fuses

The `atrprogram` command sets the fuses like so...

JTAGUSERID = 0xFF
WDWP = <none selected>
WDP = <none selected>
BOOTRST = APPLICATION
TOSCSEL = XTAL
BODPD = DISABLED
RSTDISBL = [X]
SUT = 0MS
WDLOCK = [ ]
JTAGEN = [X]
BODACT = DISABLED
EESAVE = [X]
BODLVL = 1V6

FUSEBYTE0 = 0xFF (valid)
FUSEBYTE1 = 0xFF (valid)
FUSEBYTE2 = 0xFF (valid)
FUSEBYTE4 = 0xEE (valid)
FUSEBYTE5 = 0xF7 (valid)


