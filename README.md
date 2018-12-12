# TSL Test

PCB and firmware for the CW&T Time Since Launch project.

## Design goals:

* Run for decades on 2xAA batteries.
* Stay accurate to to within +/-2ppm over the lifetime.  
* Replaceable batteries, with continued timekeeping during a reasonable battery swap time period.  

## Critical parts:

* ATXMEGA128B3 processor for LCD driving and supervision
* RX8900 for precision timekeeping
* 2x  AIExpress 6-digit, 7-segment dynamic LCD glass 
* 2x Energizer Ultimate Lithium AA batteries
* Optional 32768Hz tuning fork quartz watch crystal 


## Interesting twists

We actually have two oscillators running simultaneously here, one connected to the ATMEGA and one inside the RX8900. The ATMEGA uses either the XTAL or the internal ULP oscillator to drive the LCD controller and maintain a local time count which updates the display digits. The xtal uses about 0.3uA less current, but requires an extra part (the ULP is built in to the XMEGA).  

The RX8900 is programmed to generate a 1Hz output pulse (FOUT) Each of these pulses causes an interrupt on the XMEGA which wakes it from deep sleep. The XMEGA then increments the count and updates the display and goes back to deep sleep until the next pulse.  

## XMEGA EEPROM usage

We use a block at the start of EEPROM to 
...

1. Initially set the current time on first power up at the factory.
2. Remember that we set the current time at the factory. 
3. Remember if/when the trigger was pulled. 
 
Here is the format of that block...

    #define EEPROM_ADDRESS_STARTIME     EEPROM_ADDRESS( 0)  // Set by the at the Factory to real time GMT when initially programmed. RX8900 register block layout. Values are BCD.
    #define EEPROM_ADDRESS_STARTFLAG    EEPROM_ADDRESS( 8)  // Set 0x00 to indicate that STARTTIME block has time in it, set to 0x01 when STARTTIME set to the RTC the first time we power up

    #define EEPROM_ADDRESS_TRIGGERTIME  EEPROM_ADDRESS(10)  // Set to RTC time when the trigger pin is pulled. RX8900 register block layout. Values are BCD.
    #define EEPROM_ADDRESS_TRIGGERFLAG  EEPROM_ADDRESS(18)  // Set to 0x01 when the trigger pin is pulled and the RTC time is aves to the TRIGGER_TIME block


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

We use the `RAM` location to hold our century interlock. 

### Century interlock

Century interlock explained:

The RX8900 only saves 2 digits for the year, so when we roll from 2099 to 2100, the year will go from 99 to 0.
This would make us loose 100 years worth of days on the first battery change of the new century when we go to
compute how long since the pin was pulled.

To buy ourselves extra centuries, we use a century interlock stored in the RAM register of the RX8900.
When we first program a unit (presumably in the 1st half of the 2000 century), we set the interlock to '00' BCD (0x3030).

On every power up (typically due to battery change) every 10 - 30 years(? We'll see!), we check the current year. If it is greater than 50
and the century interlock is even, then we increment the century interlock. If it is less than 50  and the century
interlock is odd, then we increment the century interlock. This also has the effect of re-writing the EEPROM every few decades, which [may or may not extend the retention](https://electronics.stackexchange.com/questions/411616/for-maximum-eeprom-readability-into-the-future-is-it-better-to-write-once-and-le). 


When we want to compute the total days elapsed since epoch Jan 1, 2000 then we divide the century interlock by
2 and drop the remainder. We when multiply this by the number of days in an RX8900 century and we will get the correct value.

This will get us an additional 127 centuries of run time, which puts us at the year 14700. We will need to patch the firmware before
then if we want to continue to keep accurate count.


## Method of Operation



### Factory power up
The factory programs the firmware into flash and also stores the current GMT time into `STARTTIME` in the EEPROM block. 

On initial power up, we check EEPROM to see if we need to set the RTC to the time in `STARTTIME`. If so, then we set it and set the `STARTFLAG`. 

If the pin is out at this point we go into clock mode and show the current GMT time until the pin is inserted. THIS CLOCKMODE IS MEANT FOR TESTING ONLY. It is very high power, so be sure to insert the pin as soon as you have verified the correct time.  

Once the pin is in, we go into WAITING FOR TRIGGER mode. 
 

## Display modes

### Warm up mode

Every time the XMEGA powers up (on initially programming or after battery change), it will display `------ ------` for 1 second while it waits for the RX8900 RTC to oscillator to stabilize. 

Do we need this? Well we certainly do not need it if the RTC is already running, but it is unclear if we can poll the RTC to see if it is running before the oscillator has settled. The datasheets are unclear. 
> 
> "Please perform initial setting only tSTA (oscillation start time), 
> when the built-in oscillation is stable."
> 


### Clock mode

Shows current real time as MMDDYY HHMMSS with blinking ":"'s.

This time comes from the RTC and should be correct GMT +/2ppm if it was programmed correctly at the factory. 

This is shown after initial time is set by the programming fixture until the pin is inserted.  

WARING: Clock mode uses about 50x as much power as normal Time Since Launch mode, so don't leave it on for too long! For diagnostics only! 

### Ready To Launch mode 

Shows a mesmerizing winding pattern with 1Hz update rate. 

The purpose of this pattern is to show the user that we are ready and willing, and also make apparent any bad LCD segment either stuck on or off. 

We enter this mode on power up if the trigger pin has never been pulled before, and we exit it when the pin is pulled. When the pin is finally pulled, we blink the LEDs and save the current time from the RTC into EPPROM to remember the trigger time.  


### Time Since Launch Mode



### EEPROM Error Mode

Shows `EEProX Error` blinking forever

This is shown on start-up if the EEPROM is in an inconsistent state.

If `X` is `1`, then the trigger pin was already showing as pulled, even though the time had never been factory set. 

If `X` is `2`, then the time the trigger happened is in the future. 

Neither of these should ever happen unless there is an EEPROM corruption or people are messing with bits. 

### Where Has the Time Gone mode

Shows the time the trigger pin was pulled in MMDDYY HHMMSS blinking at 0.5Hz. 

Indicates that the trigger pin was pulled and we marked the moment shown on the display, but since then the real time was lost and needs to be set before we can show Time Since Launch mode. 

### Clock Error mode

Shows `cLoc Error` blinking forever.

Indicates that the trigger pin has never been pulled, and that the real time was lost so now needs the real time to be set before we can go to Ready To Launch mode.    

### Low Battery mode

## Build notes

gcc optimization: `-O3 -flto`

```
-x c -funsigned-char -funsigned-bitfields -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\XMEGAB_DFP\1.1.55\include"  -O3 -flto -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atxmega128b3 -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\XMEGAB_DFP\1.1.55\gcc\dev\atxmega128b3" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" 
```

## Status

Working breadboard, pre-prototype PCB. 

We are at an average of 10uA running current over the full voltage range. 

If the battery datasheets are to be believed, this suggests a runtime of 10-20 years.


## Future directions

If the datasheets are to be believed, switching to an ultra low power ARM (like SAM22L or STM32L) or STM8 could reduce power drastically, at the cost of higher cost. This needs to be tested.

It might be possible to do temperature compensation inside the MCU and get rid of the DS3231S while achieving more accuracy (would take a higher precision temp sensor than the one in the DS, and better characterization of each individual unit) . While this could also potentially save power in theory, it seems unlikely that it would in practice since that part astonishingly pulls less than 1uA in practice. 
