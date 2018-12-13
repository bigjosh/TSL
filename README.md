# TSL

PCB and firmware for the CW&T Time Since Launch project.

## Design goals:

* Run for decades on 2xAA batteries.
* Stay accurate to to within +/-2ppm over the lifetime.  
* Replaceable batteries, with continued timekeeping during a reasonable battery swap time period.  

## Critical parts:

* ATXMEGA128B3 processor for LCD driving and supervision. 
* RX8900 RTC for precision timekeeping
* 2x  AIExpress 6-digit, 7-segment dynamic LCD glass 
* 2x Energizer Ultimate Lithium AA batteries
* Optional 32768Hz tuning fork quartz watch crystal 


## Interesting twists

We actually have two oscillators running simultaneously here.

The ATMEGA uses either the XTAL or the internal ULP oscillator to drive the LCD controller. The xtal uses about 0.3uA less current, but requires an extra part (the ULP is built in to the XMEGA).  

The RX8900 is programmed to generate a 1Hz output pulse (FOUT) taht is connected to ain IO pin on the XMEGA. Each of these pulses causes an interrupt on the XMEGA which wakes it from deep sleep. The XMEGA then increments the count and updates the display and goes back to deep sleep until the next pulse.  

## XMEGA EEPROM usage

We use a block at the start of EEPROM to ...

1. Initially set the current real time on first power up at the factory.
2. Remember that we set the current time at the factory. 
3. Remember if/when the trigger was pulled.
4. Remember if the RTC has ever lost power. 
 
Here is the format of that block...

    #define EEPROM_ADDRESS_STARTIME     EEPROM_ADDRESS( 0)  // Set by the at the Factory to real time GMT when initially programmed. RX8900 register block layout. Values are BCD.
    #define EEPROM_ADDRESS_STARTFLAG    EEPROM_ADDRESS( 8)  // Set 0x00 to indicate that STARTTIME block has time in it, set to 0x01 when STARTTIME set to the RTC the first time we power up

    #define EEPROM_ADDRESS_TRIGGERTIME  EEPROM_ADDRESS(10)  // Set to RTC time when the trigger pin is pulled. RX8900 register block layout. Values are BCD.
    #define EEPROM_ADDRESS_TRIGGERFLAG  EEPROM_ADDRESS(18)  // Set to 0x01 when the trigger pin is pulled and the RTC time is aves to the TRIGGER_TIME block.


	#define EEPROM_ADDRESS_LOWVOLTFLAG  EEPROM_ADDRESS(20)  // Set to 0x01 if we ever power up and find a low voltage condition.



The times are in RX8900 register block format....

| Address | Function |
| - | - |
| 00 |  SEC | 
|01  | MIN | 
|02  | HOUR |
|03  | WEEK |
|04  | DAY |
|05  | MONTH | 
|06  | YEAR |
|07  | RAM |

We ignore the `WEEK` register, but set it to a sensical value (1-7) since the datasheet warns of problems otherwise. 

We use the `RAM` location to hold our century interlock. 

### Century interlock

The RX8900 only saves 2 digits for the year, so when we roll from 2099 to 2100, the year will go from 99 to 0.
This would make us loose 100 years worth of days on the first battery change of the new century when we go to
compute how long since the pin was pulled.

To buy ourselves extra centuries, we use a century interlock stored in the RAM register of the RX8900.
When we first program a unit (presumably in the 1st half of the 2000 century), we set the interlock to '00' BCD (0x00).

On every power up (typically due to battery change) every 10 - 30 years(? We'll see!), we check the current year. If it is greater than 50 and the century interlock is even, then we increment the century interlock. If it is less than 50  and the century interlock is odd, then we increment the century interlock. This also has the effect of re-writing the EEPROM every few decades, which [may or may not extend the retention](https://electronics.stackexchange.com/questions/411616/for-maximum-eeprom-readability-into-the-future-is-it-better-to-write-once-and-le). 


When we want to compute the total days elapsed since epoch Jan 1, 2000 then we divide the century interlock by 2 and drop the remainder. We when multiply this by the number of days in an RX8900 century and we will get the correct value.

This will get us an additional 127 centuries of run time, which puts us at the year 14700. We will need to patch the firmware before then if we want to continue to keep accurate count.

### The leap year problem

The RX8900 counts any year ending in `00` as a leap year, but in real life, 2100 is not a leap year.

This means that if a unit is programmed in the 2000's and triggered on 3/1/2100 then the trigger date in EEPROM will be 2/29/2100, and any day after that will be 1 day behind the actual calendar date when the trigger was pulled. The count will still always be right, and the only way you'd know about this is if you inspect the trigger time with the diagnostic mode.

This divergence will increase by 1 for each non-leap year ending in `00` after 2000, including 2200 and 2300 (2400 is a leap). 

Why don't we just correct for this? Well because as far as the RX8900 is concerned 2/29/2100 actually happened, so a trigger could happen on that day.

Since this problem is predicable we can account for it when serving units after 2100. 

## Method of Operation


### Factory power up
The factory burns the firmware into flash and also stores the current GMT time into `STARTTIME` in the EEPROM block. 

On initial power up, firmware csee a new time block in EEPROM and uses it to set the RTC. It then sets the START FLAG so that the time is not programmed again on subsequent power ups.  

If the pin is out at this point we go into clock mode and show the current GMT time until the pin is inserted. THIS CLOCKMODE IS MEANT FOR TESTING ONLY. It is very high power (like 50x normal count!), so be sure to insert the pin as soon as you have verified the correct time.  

Once the pin is in, we go into WAITING FOR TRIGGER mode. 
 
## Display modes

### Warm up mode

Every time the XMEGA powers up (on initial programming or after battery change), it will display `------ ------` for 1 second while it waits for the RX8900 RTC to oscillator to stabilize. 

Do we need this? Well we certainly do not need it if the RTC is already running, but it is unclear if we can poll the RTC to see if it is running before the oscillator has settled. The datasheets are unclear. 
> 
> "Please perform initial setting only tSTA (oscillation start time), 
> when the built-in oscillation is stable."
> 

...so we wait. 

### Clock mode

Shows current real time as MMDDYY HHMMSS with blinking ":"'s.

This time comes from the RTC and should be correct GMT +/2ppm if it was programmed correctly at the factory. 

This is shown after initial time is set by the programming fixture until the pin is inserted.    

WARING: Clock mode uses about 50x as much power as normal Time Since Launch mode, so don't leave it on for too long! For diagnostics only! 

### Ready To Launch mode 

Shows a mesmerizing winding pattern with 1Hz update rate. 

The purpose of this pattern is to show the user that we are ready and willing, and also make apparent any bad LCD segments either stuck on or off. 

We enter this mode on power up if the trigger pin has never been pulled before, and we exit it when the pin is pulled. When the pin is finally pulled, we blink the LEDs and save the current time from the RTC into EPPROM in the TRIGGER TIME block to remember the trigger time.  


### Time Since Launch Mode

Her we count up the days, hours, minutes, and seconds since the trigger was pulled. 

When we reach 1,000,000 days we switch to Long Now mode. 

### Where Has the Time Gone mode

Shows the time the trigger pin was pulled in MMDDYY HHMMSS blinking at 0.5Hz. 

Indicates that the trigger pin was pulled and we marked the moment shown on the display, but since then the real time was lost (RTC lost power) and needs to be set before we can show Time Since Launch mode. 

The unit can be factory serviced and set with the correct real time and pick up where it left off. 

### Clock Error mode

Shows `cLoc Error` blinking forever.

Indicates that the trigger pin has never been pulled, and that the real time was lost so now needs the real time to be set before we can go to Ready To Launch mode.    

This likely means that the unit was stored as old new stock for 100+ year and the batteries we allowed to go completely dead before first use. The unit can be factory serviced to set the real time and then will be ready for first trigger.   

### Low Battery mode

### Long Now mode

Shows `999999 235959` blinking forevermore. 

Indicates that the trigger was more than 1 million days (~2740 years) ago so we can not display it accurately. 

The idea here is to avoid problems of people trying to ebay old TSL units that have rolled over by misrepresenting their true age. 


### EEPROM Error Mode

Shows `EEPro ErrorX` blinking forever.

This is shown on start-up if the EEPROM is in an inconsistent state. This usually means either that the EEPROM was never programmed (it defaults to 0xff), or it got corrupted somehow. 

The `X` after `EEPro` is a code that tells you the first problem found (they are checked in order). 

| Code | Reason 
| - | - |
| 1 | Invalid LOW VOLTAGE flag |
| 2 | Invalid START flag |
| 3 | Invalid TRIGGER flag |
| 4 | TRIGGER flag set but START flag not set |
| 5 | TRIGGER time is before START time |  

#### Codes 1-3

All flags must have a value of either 0 (not set) or 1 (set). If not, then an invalid flag EEPRo Error will come up.

#### Code 4

How could the user have pulled the trigger if we never set the start time? Impossible. 

#### Code 5

To find the Time Since Launch, we need to subtract the START time from the TRIGGER time, so the TRIGGER time must be after the START time. 

#### Code 6

We encountered a month that was not 1-12. Use diagnostics to see which one.  

#### Code 7 

Start time failed validity checks on start up. (i.e. month was greater than 12)

#### Code 8 

Trigger time failed validity checks on start up. (i.e. month was greater than 12)



## Diagnostics

### Factory program

On the initial power-up after the time as been set to the value supplied in the START TIME EEPROM block, the display will show the current time for as long as the pin is out. 

This is handy for verifying the correct time was programmed. 

### Field service 

There are two test pins on the 6-pin ISP connector on the board labeled `B` and `T`. They are internally pulled up, so you connect them the to the ground pin (labeled `G`) to activate them.

They are only checked at start up. You can force a start up by grounding the RESET pin (labeled `C`) to reset the unit and then quickly (you have the 1 second warmup) ground one of the test pins.

#### `B` Pin

Grounding the `B` pin will show the current time as loaded from the RTC on the display. This will show even if the clock has not been initialized. 

The right `:` is lit to differentiate this mode.

Left decimal point means low voltage flag set in RX8900 right now.

Right decimal point means low voltage flag is set in EEPROM (we have seen a low voltage on RX8900 in the past). Once set, the low voltage flag in EEPROM stays set forever. 

The low voltage flag indicates that the voltage to the RTC dropped low enough that the RTC at least stopped counting, and possibly lost all the values in the time registers.

The RX8900 low voltage is checked and the EEPROM flag is set *after* this diagnostic screen, so you can see the RTC showing low voltage but the EEPROM flag not set if this is the first time we are powering up since the low voltage event happened on the RTC.  

The low voltage flag is cleared in the RX8900 when it is programmed with the start time at the factory. 


#### `T` Pin

Grounding the `T` pin will show the stored trigger time. This will show even if the trigger has not happened. The left `:` is lit to differentiate this mode.

The display will show "no TriG" if the EEPROM trigger flag is not set.   

## Build notes


gcc optimization: `-O3 -flto`

```
-x c -funsigned-char -funsigned-bitfields -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\XMEGAB_DFP\1.1.55\include"  -O3 -flto -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atxmega128b3 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\XMEGAB_DFP\1.1.55\gcc\dev\atxmega128b3" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" 
```

## Status


We are at an average of <6uA running current over the full voltage range. 

If the battery datasheets are to be believed, this suggests a runtime of ~66 years. Even derating a few percent for internal leakage, we should get a decent run time between battery changes. 


## Future directions

If the datasheets are to be believed, switching to an ultra low power ARM (like SAM22L or STM32L) or STM8 could reduce power drastically, at the cost of higher cost. This needs to be tested.

It might be possible to do temperature compensation inside the MCU and get rid of the DS3231S while achieving more accuracy (would take a higher precision temp sensor than the one in the RX, and better characterization of each individual unit) . While this could also potentially save power in theory, it seems unlikely that it would in practice since that part astonishingly pulls less than 1uA in practice. 
