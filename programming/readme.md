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

Since all time calculations inside a running TSL are relative, it does not practically matter how accurate the programmed clock time is for normal operation. Having accurate TSL time is nice when a TSL needs to be reset. It is also nice to have it accurate to +/-1 second just so we can keep track of how how much TSLs are drifting in the wild over time.     

The programming procedure takes more than a second to complete, so if we just programmed the current time then the TSL would end up behind.

You can specify a number of seconds to add or subtract to the current time when programming the TSL to account for these delays in the programming process. 

First try programming a unit with the default offset and then compare the clock time on the TSL to the the time on the computer. If the TSL is off by more than +/- 1 second then adjust the value of `offset` in the `burnthis.bat` file and try again.

### Accurate time base

We want the local windows clock to be as accurate as possible since all the TSLs programmed will be based on this time (+/- the lag offset above). You can manually set the windows clock though Windows' settings, but probably best to install an NTP client on the programming computer to always keep it synced.

Here is one that is free and works...

http://www.timesynctool.com/

You can check against the real time here...

https://time.gov/
  

## Procedure

1. Connect the TSL to the programming jig.
2. Enter the command `burnthis.bat` on the command line followed by the unit serial number. (Use up arrow or F3 on subsequent passes)
3. Watch it program.
4. Remove the TSL and check that is has the correct GMT time on the LCD.
5. Insert the trigger pin.
6. Confirm that the TSL goes to Ready To Launch mode and all the segments look good.

### Batch programming mode

If you enter just `burnthis.bat` without specifying a serial number, then you will go into batch programming mode where You will be asked to enter a serial number and after the programming cycle successfully competes then it will ask for the next serial number. 

This works great if you have a bar code scanner to enter the serial numbers.   

## How it works

### tsl-make-block

First the batch file uses the `tsl-make-block` to create a binary file to be programmed into the TSL EEPROM. The program checks the clock on the local PC, converts the current time to GMT, and then adds in the delay offset. Then it writes out the EEPROM data block in the format that the TSL firmware expects to find when it runs. The block contains:

1. The current time GMT
2. A flag that tells the firmware to copy this time to the RX8900 RTC when it sees it
3. The trigger time and flag, which we set to "not triggered yet". 
4. A flag that remembers if the RTC in the TSL has ever reported that it lost power, which we initialize to `not set`.
 
### atprogram
The batch file uses the `atprogram` command to actually download the firmware flash image and the newly created EEPROM data block into the XMEGA on the TSL.  The `atprogram` is equivalent to `avrdude` but it written by Atmel and runs on Windows and uses the Atmel drivers. We used `atprogram`  because `avrdude` can have problems talking to an `MkII` when Atmel Studio is installed because of USB driver conflicts.  

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

### Airtable integration

The programming cycle automatically inserts a record into the [Units database](https://airtable.com/tblunHqmlHFKtvaZ1/viw4lIvKlyMFLtk5F) for each unit programmed. 

Before creating the record, it checks so make sure there is already a record for the current firmware hash in the [Firmwares database](https://airtable.com/tbl5LY3zBKoeetbQW/viwRVB4nIbvjLaZ3i). If not, then it will fail with an error. If this happens, you need to add a record for the new firmware version.

### Airtable API key 

In order to update the databases in Airtable.com, this batch file needs to know your Airtable API key. You can get it here...

https://airtable.com/account

Copy the value if one is there, hit generate if not.

The first time you run the procedure below, you will be prompted to enter the API key. The key you enter will be stored in the Windows registry for the local user on the local computer so you do not need to enter again.

If you ever want to remove the stored API key (you are selling the computer, or you need to enter a new value), you can run this command...

`REG delete HKCU\Environment /V burnthis_airtable_api_key`

...and the next time you run `burnthis.bat`you will be asked to enter a new key.
    