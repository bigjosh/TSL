# LCD update code that writes code

To save power, we want to spend as much time sleeping as possible. When we wake up, we need to update the LCD display as quickly as possible and then go back to sleep.

To this end, we want to find the optimal set of instructions to update the LCD display from the current value to the next one in as few cycles as possible. We need an LCD compiler!

The LCD display segments are represented as bits in the XMEGA LCD registers. Because the LCD module is multiplexed, these bits are not contiguous across registers. The bits for the segments in each digit are spread across as many as 4 registers (one for each of the common pins). 

Luckily the registers ended up organized so that each group of 4 registers controls a contiguous block of four digits. Here is a map of which registers hold segments for each of the 12 digits...  

### LCD register usage by digit map

| Reg  | 11 | 10 | 09 | 08 | 07 | 06 | 05 | 04 | 03 | 02 | 01 | 00 |
| ---  | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- | -- |
| [00] |  X |  X |  X |  X |    |    |    |    |    |    |    |    |
| [01] |    |    |    |    |  X |  X |  X |  X |    |    |    |    |
| [02] |    |    |    |    |    |    |    |    |  X |  X |  X |  X |
| [03] |    |    |    |    |    |    |    |    |    |    |    |    |
| [04] |  X |  X |  X |  X |    |    |    |    |    |    |    |    |
| [05] |    |    |    |    |  X |  X |  X |  X |    |    |    |    |
| [06] |    |    |    |    |    |    |    |    |  X |  X |  X |  X |
| [07] |    |    |    |    |    |    |    |    |    |    |    |    |
| [08] |  X |  X |  X |  X |    |    |    |    |    |    |    |    |
| [09] |    |    |    |    |  X |  X |  X |  X |    |    |    |    |
| [10] |    |    |    |    |    |    |    |    |  X |  X |  X |  X |
| [11] |    |    |    |    |    |    |    |    |    |    |    |    |
| [12] |  X |  X |  X |  X |    |    |    |    |    |    |    |    |
| [13] |    |    |    |    |  X |  X |  X |  X |    |    |    |    |
| [14] |    |    |    |    |    |    |    |    |  X |  X |  X |  X |
| [15] |    |    |    |    |    |    |    |    |    |    |    |    |
| [16] |    |    |    |    |    |    |    |    |    |    |    |    |

Notice how digits 00-03 all use the same set of registers (02, 06, 10, and 14)?

This means that as long as we know the full current value for the first 4 digits, we can blindly write to these registers without having to load them, adjust the bits, and rewrite them.

With all this in mind, we now know that we can represent an hour of updates (0000-5959 in the rightmost 4 digits) with a sequence of blind writes to registers 02 ,06, 10, and 14! 

This is a total of 3600 updates to these registers, but the updates are not just increments or bit shifts because the bits represent the 7 physical visible segments on the LCDs. For example, to show a `0` we have to light 6 segments, but to show a `1` we only have to light 2 segments. See?

So we have to map the LCD font into the bits of the registers. The fastest way to do this is to precompute the needed values for each of the 4 registers for each of the 3600 steps. 

We could store all of these precomputed values in an array in flash and then load them in a loop, but loading data  from flash costs cycles as does the overhead of loops. Since we have plenty of flash memory available, we instead will just explicitly hardcode each step into the sequence of instructions. The pseudocode looks like...

    1. Update register 02 with value that reflects LCD display of 0000.
    2. Update register 06 with value that reflects LCD display of 0000.
    3. Update register 10 with value that reflects LCD display of 0000.
    4. Update register 14 with value that reflects LCD display of 0000.
    5. Sleep until next update
    6. Update register 02 with value that reflects LCD display of 0001.
    7. Update register 06 with value that reflects LCD display of 0001.
    8. Update register 10 with value that reflects LCD display of 0001.
    9. Update register 14 with value that reflects LCD display of 0001.
    10. Sleep until next update
    11. Update register 02 with value that reflects LCD display of 0002.
    12. Update register 06 with value that reflects LCD display of 0002.
    13. Update register 10 with value that reflects LCD display of 0002.
    14. Update register 14 with value that reflects LCD display of 0002.
    15. Sleep until next update
    etc...
    
At first you might say "Why not only update the single register for the digit that changed?" But remember that the bits for each digit are scattered across the 4 registers. 
  
Here is a map of how that happens to land....
         
## Segment map of each digit 

        D
    C       E
        G
    B       F
        A

(NOTE: LCD modules are mounted upside down for maximum contrast when viewed from 30 deg above)
    
## Map of segments to (register:bit)

| Digit | A | B | C | D | E | F |
| - | - | - | - | - | - | - |
| 11 |  00:0 | 04:0 | 08:0 | 12:1 | 08:1 | 00:1 | 04:1 |
| 10 |  00:2 | 04:2 | 08:2 | 12:3 | 08:3 | 00:3 | 04:3 |
| 09 |  00:4 | 04:4 | 08:4 | 12:5 | 08:5 | 00:5 | 04:5 |
| 08 |  00:6 | 04:6 | 08:6 | 12:7 | 08:7 | 00:7 | 04:7 |
| 07 |  01:0 | 05:0 | 09:0 | 13:1 | 09:1 | 01:1 | 05:1 |
| 06 |  01:2 | 05:2 | 09:2 | 13:3 | 09:3 | 01:3 | 05:3 |
| 05 |  01:4 | 05:4 | 09:4 | 13:5 | 09:5 | 01:5 | 05:5 |
| 04 |  01:6 | 05:6 | 09:6 | 13:7 | 09:7 | 01:7 | 05:7 |
| 03 |  02:0 | 06:0 | 10:0 | 14:1 | 10:1 | 02:1 | 06:1 |
| 02 |  02:2 | 06:2 | 10:2 | 14:3 | 10:3 | 02:3 | 06:3 |
| 01 |  02:4 | 06:4 | 10:4 | 14:5 | 10:5 | 02:5 | 06:5 |
| 00 |  02:6 | 06:6 | 10:6 | 14:7 | 10:7 | 02:7 | 06:7 |

## Skipping redundant updates

We can, however, skip updating a register if it happens that none of the bits in that register changed between steps. This happens quite frequently, but it is not obvious when it will happen unless you memorize which segments map to which registers. It is just luck when the next digit happens to not change any segments in a given register. Here is a map of the changes to segments when the digit is incremented...   

## LCD changes by digit (`X`=changed)

| Digit |  COM0 | COM1 | COM2 | COM3 |
| - | - | - | - | - |
 | 00 | X | X | X | X |
 | 01 | X | X | X | X |
 | 02 | X | X |   | X |
 | 03 | X | X |   |   |
 | 04 | X |   | X | X |
 | 05 | X |   | X | X |
 | 06 |   | X |   |   |
 | 07 | X | X | X |   |
 | 08 | X | X | X |   |
 | 09 |   | X |   |   |
 | 00 |   | X |   |   |
 | 01 | X | X | X | X |
 | 02 | X | X |   | X |

So it turns out that we can condense the pseudo code above to...

    1. Update register 02 with value that reflects LCD display of 0000.
    2. Update register 06 with value that reflects LCD display of 0000.
    3. Update register 10 with value that reflects LCD display of 0000.
    4. Update register 14 with value that reflects LCD display of 0000.
    5. Sleep until next update
    6. Update register 02 with value that reflects LCD display of 0001.
    7. Update register 06 with value that reflects LCD display of 0001.
    8. Update register 10 with value that reflects LCD display of 0001.
    9. Update register 14 with value that reflects LCD display of 0001.
    10. Sleep until next update
    11. Update register 02 with value that reflects LCD display of 0002.
    12. Update register 06 with value that reflects LCD display of 0002.
    13. Update register 14 with value that reflects LCD display of 0002.
    14. Sleep until next update
    etc...
    
See how we removed the line...

    13. Update register 10 with value that reflects LCD display of 0002.

..because no bits in register 10 happened to change when updating from `0001` to `0002`?

### Startup

Note that we always want to to all 4 registers when executing step `0000` just so we do not have to worry about what happened to be on the display when we first start.

# Code that makes code

Calculating the correct values of each of the 4 registers for each of the 3600 steps - and then deleting the redundant ones - would be a lot of fiddling and typing.

So instead we will use some code.... to write our code. This is much simpler than it sounds. We will just write a very simple C++ program that does the computations above and uses normal `printf()`s to print out the lines of code that do the updates. We can then run our program, capture its output, and then paste this output into the program that will run on the TSL.

Note that this program does not run on the TSL itself, it runs on a real computer with `printf()`. You have to capture this output (which is source code text) and then manually copy this new source code back into the TSL project. 

This code lives in `software/code2code`. It is currently set up as a Visual Studio project, but you can just as easily compile and run the single `code2code.cpp` source file with GCC. 

## Cutting and pasting

This code that writes code needs to know all about the LCD layout and the register locations and such. I could have made  a fancy system to share all this info between the TSL project and the code2code project and had make files automatically keep them up to date, but since you only have to update `code2code` when some hardware parameter changes in the TSL project (and because I am lazy),  instead now you have to do it manually. Here are the steps...

1. Update the `LCD.c` source with new values.
2. Cut and paste the code between the `cut here` marks from `LCD.c` to `code2code.cpp`.
3. Compile and run the new `code2code` code and capture the output into `output.c`.
4. Copy/paste this new `output.c` to the TSL project, covering over the  one.
5. Rebuild the `TSL` project.
 
# The actual code

So what is the best way to actually implement the pseduo code above on our XMEGA?

## Naive

The simplest method is to update each of the 4 LCD registers with their desired values on each step. 

Each register update requires an `LDI` load (1 cycle) to put the value we want into an XMEGA register, and then an `STS` store (2 cycles) to the LCD register address.      

This gives us 3 cycles per LCD register*  4 LCD registers per update = 12 cycles per update.

12 cycles per update * 3600 updates = 43,200 cycles per sequence

Here is an example update where all 4 LCD registers are updated....

    // ---- Step 3599 (59:59)
    LDI r18,0xff             ; Was UNKNOWN
    STS 0x0D12,r18           ; direct store to LCD register 02
    LDI r18,0xaa             ; Was UNKNOWN
    STS 0x0D16,r18           ; direct store to LCD register 06
    LDI r18,0xdd             ; Was UNKNOWN
    STS 0x0D1A,r18           ; direct store to LCD register 10
    LDI r18,0xaa             ; Was UNKNOWN
    STS 0x0D1E,r18           ; direct store to LCD register 14
    // --- Cycles in this step: 12

## Skip redundant stores

If an LCD register already has a value then we do not need to store that value again on the next step. This does not happen as often as you might hope because the pixels in the digits are spread across the LCD registers, but it does happen when there are two consecutive steps that only have a single pixel change like xxx5->xxx6 or xxx8->xxx9.

Here is an example here only a single register needs to be updated between 59:58 and 59:59 because there is only pixel that needs to change (see which?)...

    // ---- Step 3598 (59:58)
    LDI r18,0xff             ; Was bf
    STS 0x0D12,r18           ; direct store to LCD register 02
    LDI r18,0xea             ; Was 2a
    STS 0x0D16,r18           ; direct store to LCD register 06
    LDI r18,0xdd             ; Was 9d
    STS 0x0D1A,r18           ; direct store to LCD register 10
    // --- Cycles in this step: 9
    SLEEP                    ; Wait for interrupt from TX8900

    // ---- Step 3599 (59:59)
    LDI r18,0xaa             ; Was ea
    STS 0x0D16,r18           ; direct store to LCD register 06
    // --- Cycles in this step: 3


## Indirect stores save a cycle

Indirect stores on the XMEGA with `ST` only take 1 cycle, but there are only a total of 3 indirect pointers (X,Y,Z). We need 4 LCD registers to generally update any digit (or set of 4 contiguous digits). So we pick the 3 LCD registers that are updated most often and we initialize the 3 indirect pointers to point to those. For the 4th (least used) register, we bite the bullet and do an `STS` directly to the address which costs 2 cycles.

The LCD registers are listed in order of popularity in a comment at the top of the output.c file for reference. Here are the current values...

    // Most accessed LCD registers:
    //    REG:  6 Count: 2880
    //    REG:  2 Count: 2868
    //    REG: 10 Count: 2040
    //    REG: 14 Count: 1709
    
The index registers are loaded with the addresses of the top 3 LCD registers at the very top of the `emit_code_for_lcd_steps()` function. Note that we must `PUSH` register `Y` and then pop it again before returning since it is guaranteed to be [saved across function calls](https://www.microchip.com/webdoc/AVRLibcReferenceManual/FAQ_1faq_reg_usage.html).  Luckily these pushes and pops only cost 1 cycle each, so a total of 4 cycles to save about 2040 cycles over the course of the 3600 updates.

Note that X, Y, and Z registers are actually pairs of XMEGA registers r27:r26, r29:r28 and r31:r30. Some instructions use the letters (`ST X`) and others use the numbers (`LDI R27`).  

Here is an example where it only takes 2 cycles to update from 59:58 to 59:59 because only one LCD register changes, and that LCD register is assigned to the `X` index register so it only takes 1 cycle to write to it..

    // ---- Step 3599 (59:59)
    LDI r18,0xaa             ; Was ea
    ST X,r18                 ; 2874 accesses to R06
    // --- Cycles in this step: 2

## Stashing the values that get stored into the LCD registers

Both the indirect `ST` and the direct `STS` store instructions store a value that is already loaded into one of the XMEGA registers. 

The fastest way to load a precomputed value into an XMEGA register is using the `LDI` instruction, which takes 1 cycle. 

Since we have some extra XMEGA registers to work with, we can preload the most used values into specific XMEGA registers and then store from those.

To do this, we sort the values in order of most used and pre-load the most used ones into XMEGA general purpose registers so we can even skip the `LDI` sometimes and directly store the general purpose register int the LCD register. In the best case where we are updating one of the top 3 LCD registers with one of the cached values and we only need to update 1 of the LCD registers, we can get away with just 1 indirect store of 1 cycle for a digit increment!

Here are the current top LCD register load values   

```
// Most common values saved to LCD registers:
//    Value: 170 Count: 511
//    Value:  42 Count: 328
//    Value: 255 Count: 267
//    Value: 238 Count: 261
//    Value: 234 Count: 240
//    Value: 254 Count: 239
//    Value: 239 Count: 227
//    Value: 138 Count: 216
//    Value: 191 Count: 200
//    Value: 174 Count: 198
//    Value: 168 Count: 190
```

There is some very complicated code to map the values into AVR cache registers since not all registers are the same. We can only sue some register because some are used for other things, some of the registers must be saved before we use them and then restored before we return to the normal C program ("call saved registers"), and some registers can not be a target of the `LDI` instruction so we need to account for the extra cost of loading the value into a temp register and then loading into the target register.

Also note that we need to save a "working register" that is not used as a cache. We use this register to load on the fly any values that did not make it into a cache register.  We pick register r18 for this because we need a register that can take direct `LDI`s.

But is it all worth it! Look at this single cycle update from 59:58 to 59:59...

## Suppressing working register reloads

OK, we are really scraping the bottom of the cycle barrel here, folks!

It is possible that two consecutive loads of the working register could happened to have the save value, in which case we can skip the redundant load.

This is a pretty esoteric case. We would need the same uncached value to get consecutively loaded into different LCD registers (if it was in the same register then it would already get skipped as a redundant LCD reg update above). 

Does it ever happen?....

Wholey crap! Wow! It actually happens 24 times!!! Are you surprised? 

The first time is at 11:11... 

    STEP_0671:               ; 11:11
    // Found value 170 in cache register
    ST Y,r19                 ; 2868 accesses to R02
    LDI r18,0x00             ; Load uncached value into working register
    ST X,r18                 ; 2880 accesses to R06
    // Found value 170 in cache register
    ST Z,r19                 ; 2040 accesses to R10
    // Skipped redundant load of value   0 into working register. Wow.
    STS 0x0D1E,r18           ; direct store to LCD register 14
    // --- Cycles in this step: 6

Then again at 11:13 (the 128 was loaded into r18 at 11:12)...

    STEP_0673:               ; 11:13
    // Found value 234 in cache register
    ST Y,r23                 ; 2868 accesses to R02
    // Skipped redundant load of value 128 into working register. Wow.
    ST X,r18                 ; 2880 accesses to R06
    // --- Cycles in this step: 2

Here are all the occurrences...

    // Value   0 already in working register at step  671 at 11:11. Wow.
    // Value 128 already in working register at step  673 at 11:13. Wow.
    // Value  32 already in working register at step  691 at 11:31. Wow.
    // Value 160 already in working register at step  693 at 11:33. Wow.
    // Value 160 already in working register at step  713 at 11:53. Wow.
    // Value   8 already in working register at step  791 at 13:11. Wow.
    // Value 232 already in working register at step  818 at 13:38. Wow.
    // Value 232 already in working register at step  828 at 13:48. Wow.
    // Value 232 already in working register at step  878 at 14:38. Wow.
    // Value 232 already in working register at step  888 at 14:48. Wow.
    // Value   8 already in working register at step 1151 at 19:11. Wow.
    // Value 232 already in working register at step 1178 at 19:38. Wow.
    // Value 232 already in working register at step 1188 at 19:48. Wow.
    // Value   2 already in working register at step 1871 at 31:11. Wow.
    // Value 130 already in working register at step 1873 at 31:13. Wow.
    // Value  34 already in working register at step 1891 at 31:31. Wow.
    // Value 202 already in working register at step 1998 at 33:18. Wow.
    // Value 106 already in working register at step 2020 at 33:40. Wow.
    // Value 202 already in working register at step 2058 at 34:18. Wow.
    // Value 202 already in working register at step 2358 at 39:18. Wow.
    // Value 202 already in working register at step 2598 at 43:18. Wow.
    // Value 202 already in working register at step 2658 at 44:18. Wow.
    // Value 202 already in working register at step 2958 at 49:18. Wow.
    // Value 130 already in working register at step 3073 at 51:13. Wow.


 OK, this last optimization saved us 24 cycles at 8Mhz over a 1 hour sequence. That adds up to a power savings of less than [one ten millionth of a percent](https://www.google.com/search?ei=L5Z7XIz5HY-1_AaXsqU4&q=24+*+%281%2F%288Mhz%29%29+%2F+%28+1+hour+%29+in+percent&oq=15+*+%281%2F%288Mhz%29%29+%2F+%28+1+hour+%29+in+percent&gs_l=psy-ab.3..33i160.6737.7593..7746...0.0..0.71.478.7......0....1..gws-wiz.......0i71j33i299j33i10i160.x4a450ifR-Q). We can expect a TSL with this optimization to get an additional [26.29 seconds](https://www.google.com/search?ei=1JZ7XLzoJYu2ggevjLrIBA&q=%2815+*+%281%2F%288Mhz%29%29+%2F+%281+hour%29%29+*+%281000+years%29&oq=%2815+*+%281%2F%288Mhz%29%29+%2F+%281+hour%29%29+*+%281000+years%29&gs_l=psy-ab.3...1600.4886..5165...0.0..0.130.586.7j1......0....1..gws-wiz.......0i71j33i299j33i160j33i10i299j33i10i160.FUJ9Mi_3FJk) of battery life over a 1,000 year run time. I think it is time to go to bed! :)

## Top O the hour

Every time the the hour rolls, this code returns to the main TSL code, which updates the hours and days and does some other rare stuff like maybe checking for low battery. Then the TSL code jump right back into the optimized sequencer to start at 0000 again.

The sequencer code explicitly sets every LCD register on the first step. This simplifies everything and makes it so that (1) you don't have to know what the LCD looks like when you jump into the optimized code and (2) you can make the optimized code loop back and repeat the steps without having to precompute how the final step will leave the LCD. Ultimately this is worth the dozen or so instructions it costs each time the sequence is run. 

## Jump right in

When the TSL starts after a battery change then we starts at whatever time the TSL should be showing (calculated from the internal clock - the trigger time).

We need to make a way that we can start at any step in this 1 hour sequence so we can start at whatever time we need after a battery change. 

To do this, you might think we could just jump to whatever the current time is... but remember that every update in this sequence has an unpredictable number of instructions in it so how do we find the address of the one we want?

Well, I made an amazingly cool jump table system that would set up all the registers and then jump directly into the requested step by push the target onto the stack and then doing a (fake) return.... but it turns out we do not have enough FLASH for all that code!

If you want to be impressed, check out the `/setup-step` branch.

I the meantime we have no choice but to go ghetto and run though the remaining time in the current hour anytime we wake after a battery change. Once we are back at the top of an hour, we can jump into the optimized code. This is aesthetically displeasing but it is gonna be ok because this code will likely never run in our lifetime, and even then will will run for less than an hour every century. 

...but do go look at the jump table code, I worked really hard on it and it is super smooth. 

## We built it, now let's leverage it!

Ok, we did all this work to basically build an optimizing compiler for LCD updating, and then we run out our time updating code though it.

But what about life before the pin pulls?

It turns out we can run our Ready Mode figure 8 animation though the same optimizer and get all the benefits!

One wrinkle is that the ready mode repeats indefinitely until the trigger pin is pulled, rather than a fixed number of steps like the hour steps.

To handle this we add two new parameters to the code emitter: the interstep macro and a loop flag. 

The interstep macro is inserted between each step of the sequence. For the hour display, it just sleeps and then interlocks on FOUT to make sure 1 second has passed. For the ready display, it also checks the trigger pin and if the pin is pulled then it immediately returns. Things are set up so that on that return all of the register and the stack are restored before returning to the caller of the optimized function. 

## Heck, mind as well make a sine wave display

If you have a compiler, use it! I made a new sine wave display that looks real nice. Here I made the interstep macro check the LCD frame complete flag, so the display updates as fast as the LCD can show the next fame. Sweet! 


We can use this to replace the boring dashes display at startup!

## Results

### Cycles 

| Optimization | Total Display Update Cycles |
| - | -: |
| None | 43,200 |
| Skip redundant stores |  28,377 |
| Use 3 index registers |  20,595 |
| Use cache registers | |  15,845 |
| Suppress redundant working register loads | 15,821 |

### Power 

Measured at Vcc=3.6V, Temp=25C
Sampled over 1 minute

| Mode | Before | After |
| - | -: |
| Ready to Launch | 7.86uA | 4.64uA |
| Run  | 6.57uA | 6.00uA |

This about as low as we can go with optimization. Right now changing the font so a six does not have the top segment lit would save more power than removing *all* of the update code. That's right folks, the code that now runs on a TSL in Time Since Launch mode now uses less essentially an unmeasurable amount of power.   

### Even better

If I was cool, I would have used [graph coloring](https://en.wikipedia.org/wiki/Register_allocation#Graph-coloring_allocation) to optimally allocate these registers rather than static allocation. Unfortunately I am lazy and this would be much more work for probably an unnoticeable increase in battery life. Still, if you are reading this then you should probably implement this and send me a pull request with your awesome code! :)  

While you are at it, we could also optimize the order of assignments in each step to maximize the number of times that a register loaded in one step can be reused in the next step. I'm sure there is a general solution to this, but a brute force approach could just try all 4*4 orders and keep track of the one that has the lowest number of loads and use that one.

Keep in mind that these further optimizations will have diminishing returns beyond the extraordinary ones already in place. You will be lucky to find more than an additional 1 second of battery life over a 100 year run-time, so just know that you are doing it for the love of the cycles! 
