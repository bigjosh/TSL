# TSL Test

PCB and firmware for the CW&T Time Since Launch project.

## Design goals:

* Run for decades on 2xAA batteries.
* Stay accurate to to within the precision of the display over the lifetime.  
* Replaceable batteries, with continued timekeeping during a reasonable replacement time period.  

## Critical parts:

* ATMEGA169P processor for LCD driving and supervision
* 32768Hz tuning fork quartz watch crystal 
* DS3231S for precision timekeeping
* 2x  AIExpress 6-digit, 7-segment dynamic LCD glass 
* 2x Energizer Ultimate Lithium AA batteries

## Interesting twists

We actually have two oscillators running simultaneously here, one connected to the ATMEGA and one inside the DS3231S. The ATMEGA uses the XTAL to drive the LCD controller and maintain a local time count which updates the display digits. Without temperature compensation, the watch crystal is only accurate to ~20ppm, which is not good enough for the desired accuracy. To get around this, the ATMEGA trims to the DS3231S once every 24 hours. Since the DS3231S is accurate to ~2ppm (not counting aging), this keeps the display accurate over the lifetime.

It would seem like having redundant oscillators would not be power efficient, but empirical tests show that the ATMEGA running synchronously on an external 32768 oscillator uses ~50% more power than it does running off a locally driven crystal. Tested with a DS3232 which has push/pull 32768Hz output). 


## Status

Working breadboard, pre-prototype PCB. 

We are at an average of 10uA running current over the full voltage range. 

If the battery datasheets are to be believed, this suggests a runtime of 10-20 years.


## Future directions

If the datasheets are to be believed, switching to an ultra low power ARM (like SAM22L) or STM8 could reduce power drastically, at the cost of higher cost. This needs to be tested.

It might be possible to do temperature compensation inside the MCU and get rid of the DS3231S while achieving more accuracy (would take a higher precision temp sensor than the one in the DS, and better characterization of each individual unit) . While this could also potentially save power in theory, it seems unlikely that it would in practice since that part astonishingly pulls less than 1uA in practice. 
