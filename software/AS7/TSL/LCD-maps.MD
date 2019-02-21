# LCD update code that writes code

To save power, we want to spend as much time sleeping as possible. When we wake up, we need to update the LCD display as quickly as possible and then go back to sleep.

To this end, we want to find the optimal set of instruction to update the LCD display from the current value to the next one in as few cycles as possible.

The LCD display segments are represented as bits in the XMEGA LCD registers. Because the LCD module is multiplex, these bits are not contiguous across registers. The bits for the segments in each digit are spread across as many as 4 registers (one for each of the common pins). 

Luckily the registers ended up organized so that each ground of 4 registers controls a contiguous block of four digits. Here is a map of which registers hold segments for each of the 12 digits...  
 

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

This means that as long as we know the current value for the first 4 digits, we can blindly write to these registers without having to first load them.

With all this in mind, we now know that we can represent an hour of updates (0000-5959 in the rightmost 4 digits) with a sequence of blind writes to registers 02 ,06, 10, and 14! 

This is a total of 3600 updates to these registers, but the updates are not just increments or bit shifts because the bits represent the 7 physical visible segments on the LCDs. For example, to show a `0` we have to light 6 segments, but to show a `1` we only have to light 2 segments. See?

So we have to map the LCD font into the bits of the registers. The fastest way to do this is to precompute to 4 registers for each of the 3600 steps. 

We could store all of these precomputed values in an array in flash and then load them in a loop, but loading data  from flash cost cycles as does the overhead of loops. Since we have plenty of flash memory available, we instead will just explicit hardcode each step into the sequence of instructions. The pseudocode looks like...

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

We can, however, skip updating a register if it happens that none of the bits in that register changed between steps. This happens quite frequently, but it is not obvious when it will happen unless you memorize which segments map to with registers. It is just luck when the next digit happens to not change any segments in a given register. Here is a map of the changes to segments when the digit is incremented...   

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

Calculating the correct values of each of the 4 registers for each of the 3600 steps - and then deleing the redundant ones - would be a lot of fiddling and typing.

So instead we will use some code.... to write our code. This is much simpler than it sounds. We will just write a very simple C program that does the computations above and uses normal `printf()`s to print out the lines of code that do the updates. We can then run our program, capture its output, and then paste this output into the program that will run on the TSL.

As a practical matter, this code that writes code needs to know all about the LCD layout and the register locations and such, so it is just easier to keep it inside the normal TSL LCD source file. It is between the comments that say "Cut here". Note that this program that writes the program is commented out in the TSL project - we need to run it on a real computer with `printf()` to get the output. I used Visual Studio, but you can use `gcc` or whatever you want if you ever changes things and need to regenerate the code written by the code.   

# The actual code

So what is the best way to actually implement the pseduo code above on our XMEGA?

Indirect stores on the XMEGA with `ST` only take 1 cycle, but there are only a total of 3 indirect pointers. We need 4 registers to generally update any digit (or set of 4 contiguous digits). So we pick the 3 LCD registers that are updated most often and we initialize the 3 indirect pointers to point to those. For the 4th (least used) register, we bite the bullet and do an `STS` directly to the address which costs 2 cycles.

Since we pre-compute the values that will go into the LCD registers, we can hard code these bytes into `LDI` instructions which only take 1 cycle. We also sort these in order of most used and pre-load the top few into XMEGA general purpose registers so we can even skip the `LDI` sometimes and directly store the general purpose register int the LCD register. In the best case where we are updating one of the top 3 LCD registers with one of the top vales and we only need to update 2 of the LCD registers, we can get away with just 2 indirect stores of 1 cycle each for a digit increment!  


 

  

