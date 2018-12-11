# TSL Test

PCB and firmware for the CW&T Time Since Launch project.

## Design goals:

* Run for decades on 2xAA batteries.
* Stay accurate to to within +/-2ppm over the lifetime.  
* Replaceable batteries, with continued timekeeping during a reasonable battery swap time period.  

## Critical parts:

* ATMEGA169P processor for LCD driving and supervision
* Optional 32768Hz tuning fork quartz watch crystal 
* RX8900 for precision timekeeping
* 2x  AIExpress 6-digit, 7-segment dynamic LCD glass 
* 2x Energizer Ultimate Lithium AA batteries

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

    #define EEPROM_ADDRESS_STARTIME EEPROM_ADDRESS( 0)   // Set by the at the Factory to real time GMT when initially programmed
    #define EEPROM_ADDRESS_TRIGGERTIME  EEPROM_ADDRESS( 8)   // Set by the RTC when the trigger pin is pulled
    #define EEPROM_ADDRESS_STARTFLAGEEPROM_ADDRESS( 9)   // Set 0x00 to indicate that STARTTIME block has time in it, set to 0x01 when STARTTIME set to the RTC the first time we power up
    #define EEPROM_ADDRESS_TRIGGERFLAG  EEPROM_ADDRESS(10)   // Set when the trigger pin is pulled and the RTC time is aves to the TRIGGER_TIME block
 


## Method of Operation


### Factory power up
The factory programs the firmware into flash and also stores the current GMT time into `STARTTIME` in the EEPROM block. 

On initial power up, we check EEPROM to see if we need to set the RTC to the time in `STARTTIME`. If so, then we set it and set the `STARTFLAG`. 

If the pin is out at this point we go into clock mode and show the current GMT time until the pin is inserted. THIS CLOCKMODE IS MEANT FOR TESTING ONLY. It is very high power, so be sure to insert the pin as soon as you have verified the correct time.  

Once the pin is in, we go into WAITING FOR TRIGGER mode. 
 

### Waiting for trigger



## Display modes

### Clock mode

Shows current real time as MMDDYY HHMMSS with blinking ":"'s.

This time comes from the RTC and should be correct GMT +/2ppm if it was programmed correctly at the factory. 

This is shown after initial time is set by the programming fixture until the pin is inserted.  

WARING: Clock mode uses about 50x as much power as normal Time Since Launch mode, so don't leave it on for too long! For diagnostics only! 

### Ready To Launch mode 



### Time Since Launch Mode

### Where Has the Time Gone mode

Shows the 

### Impossible Future Mode

Shows "888888 777777".

This is shown on start-up if the time the trigger happened time is in the future. This should never, ever happen unless there is an EEPROM corruption or people are messing with bits. 

 

Shows the time the trigger pin was pulled in MMDDYY HHMMSS blinking at 0.5Hz. 

Indicates that the trigger pin was pulled and we marked the moment shown on the display, but since then the real time was lost and needs to be set before we can show Time Since Launch mode. 

### Late To The Party Mode

Shows "------ ------" blinking.

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
