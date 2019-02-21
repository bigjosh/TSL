
//---------------CUT HERE FOR SEG MAP PRINTOUT

// The code between the cut points can be run to print a map of which
// registers are used for which digits using printRegMap()

// You will need these to make this block compile independently...
#include <stdio.h>

#ifndef uint8_t
    typedef unsigned char uint8_t;
#endif


// Maximum number of common lines. Defined in datasheets.
#define LCD_MAX_NBR_OF_COM  4
// Maximum number of segment lines. Defined in datasheets.
#define LCD_MAX_NBR_OF_SEG  25

// Map LCD segments to registers
// compute at compile time
// Taken from 25.5.11 DATA – LCD Data Memory Mapping

// Return the offset of the register that holds the requested pixel

inline static uint8_t LCD_REG_OFF( uint8_t com , uint8_t seg ) {
    
    uint8_t reg = ( com * ((LCD_MAX_NBR_OF_SEG + 7) / 8)) + ( seg / 8);
    
    return reg;
}


// Return the bit in the register that holds the requested pixel

inline static uint8_t LCD_REG_BIT( uint8_t com , uint8_t seg ) {
    
    return  seg % 8;
    
}


// LCD FONT----

// Map 7 segments A-G to internal representation bits
// A=0b00000001, B=0b00000010, etc
// Just luck that 7 segments fits into an 8 bit byte

#define LCD_SEG_BIT( letter ) ( 1 << (letter - 'A') )

#define SEG_A LCD_SEG_BIT('A')
#define SEG_B LCD_SEG_BIT('B')
#define SEG_C LCD_SEG_BIT('C')
#define SEG_D LCD_SEG_BIT('D')
#define SEG_E LCD_SEG_BIT('E')
#define SEG_F LCD_SEG_BIT('F')
#define SEG_G LCD_SEG_BIT('G')

/*

    NOTE: LCD modules are mounted upside down for maximum contrast when viewed from
          30 deg above
          
    Here is the segment map in the upside down position:

        D
    C       E
        G
    B       F
        A

*/


const uint8_t lcd_font_digits[] = {
    SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F ,         // 0
    SEG_E | SEG_F ,                                         // 1
    SEG_A | SEG_B | SEG_G | SEG_E | SEG_D ,                 // 2
    SEG_A | SEG_F | SEG_G | SEG_E | SEG_D ,                 // 3
    SEG_F | SEG_G | SEG_E | SEG_C ,                         // 4
    SEG_A | SEG_F | SEG_G | SEG_C | SEG_D ,                 // 5
    SEG_A | SEG_C | SEG_D | SEG_B | SEG_F | SEG_G ,         // 6
    SEG_D | SEG_E | SEG_F ,                                 // 7
    SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F | SEG_G , // 8
    SEG_A | SEG_E | SEG_C | SEG_D | SEG_F | SEG_G ,         // 9
};


const uint8_t lcd_font_char_dash = { SEG_G };                                 // '-'
const uint8_t lcd_font_char_c    = { SEG_G | SEG_B | SEG_A };                 // c
const uint8_t lcd_font_char_L    = { SEG_C | SEG_B | SEG_A };                 // L
const uint8_t lcd_font_char_o    = { SEG_G | SEG_B | SEG_A | SEG_F };         // o
const uint8_t lcd_font_char_E    = { SEG_D | SEG_C | SEG_G | SEG_B | SEG_A }; // E
const uint8_t lcd_font_char_r    = { SEG_B | SEG_G };                         // r
const uint8_t lcd_font_char_P    = { SEG_E | SEG_D | SEG_C | SEG_G | SEG_B }; // P

const uint8_t lcd_font_char_J    = { SEG_B | SEG_A | SEG_F | SEG_F | SEG_E }; // J
const uint8_t lcd_font_char_O    = { SEG_D | SEG_C | SEG_B | SEG_A | SEG_F | SEG_E }; // O
const uint8_t lcd_font_char_S    = { SEG_D | SEG_C | SEG_G | SEG_F | SEG_A }; // S
const uint8_t lcd_font_char_H    = { SEG_B | SEG_C | SEG_F | SEG_G | SEG_E }; // H

const uint8_t lcd_font_char_n    = { SEG_B | SEG_G | SEG_F };                 // n
const uint8_t lcd_font_char_t    = { SEG_B | SEG_C | SEG_A | SEG_G };         // t
const uint8_t lcd_font_char_i    = { SEG_B };                                 // i
const uint8_t lcd_font_char_G    = { SEG_D | SEG_C | SEG_B | SEG_A | SEG_F  }; // G

const uint8_t lcd_font_char_V    = { SEG_C | SEG_B | SEG_A | SEG_F | SEG_E }; // V (ok, not really)
const uint8_t lcd_font_char_l    = { SEG_C | SEG_B };                         // l

const uint8_t lcd_font_char_b    = { SEG_C | SEG_B | SEG_A | SEG_F | SEG_G }; // b
const uint8_t lcd_font_char_A    = { SEG_C | SEG_B | SEG_D | SEG_E | SEG_G | SEG_F };   // A
const uint8_t lcd_font_char_d    = { SEG_G | SEG_B | SEG_A | SEG_F | SEG_E};  // d
const uint8_t lcd_font_char_U    = { SEG_C | SEG_B | SEG_A | SEG_F | SEG_E};  // d


// Map LCD seg pins to MCU seg pins (set by PCB layout)

#define LCD_SEG_R01 24
#define LCD_SEG_R02 23
#define LCD_SEG_R03 22
#define LCD_SEG_R04 21
#define LCD_SEG_R05 20
#define LCD_SEG_R06 19
#define LCD_SEG_R07 18
#define LCD_SEG_R08 17
#define LCD_SEG_R09 16
#define LCD_SEG_R10 15
#define LCD_SEG_R11 14
#define LCD_SEG_R12 13
#define LCD_SEG_R13 12


#define LCD_SEG_L01 24
#define LCD_SEG_L02 11
#define LCD_SEG_L03 10
#define LCD_SEG_L04  9
#define LCD_SEG_L05  8
#define LCD_SEG_L06  7
#define LCD_SEG_L07  6
#define LCD_SEG_L08  5
#define LCD_SEG_L09  4
#define LCD_SEG_L10  3
#define LCD_SEG_L11  2
#define LCD_SEG_L12  1
#define LCD_SEG_L13  0


// Map LCD COM pins to MCU com pins (set by PCB layout)

#define LCD_COM_R1 0
#define LCD_COM_R2 1
#define LCD_COM_R3 2
#define LCD_COM_R4 3

#define LCD_COM_L1 0
#define LCD_COM_L2 1
#define LCD_COM_L3 2
#define LCD_COM_L4 3



// Map LCD icons to seg/com (set by LCD datasheet)

// Map each of the 7 visible LCD icons A-G in each of the 6 digits per LCD

typedef struct {
    uint8_t com;
    uint8_t seg;
} lcd_visible_segment ;

// TODO: PROGMEM and then statically compiled transitions

// Maps segments in each digit to corresponding SEG and COM pin
// 0=rightmost digit, 11=leftmost

const lcd_visible_segment  digitmap[12][7] = {

    // Right LCD

    {     //1 on the datasheet= 0 in digitmap array
        {LCD_COM_R1 , LCD_SEG_R03 },       //A
        {LCD_COM_R2 , LCD_SEG_R03 },       //B
        {LCD_COM_R3 , LCD_SEG_R03 },       //C
        {LCD_COM_R4 , LCD_SEG_R02 },       //D
        {LCD_COM_R3 , LCD_SEG_R02 },       //E
        {LCD_COM_R1 , LCD_SEG_R02 },       //F
        {LCD_COM_R2 , LCD_SEG_R02 },       //G
    },

    {     //2
        {LCD_COM_R1 , LCD_SEG_R05 },       //A
        {LCD_COM_R2 , LCD_SEG_R05 },       //B
        {LCD_COM_R3 , LCD_SEG_R05 },       //C
        {LCD_COM_R4 , LCD_SEG_R04 },       //D
        {LCD_COM_R3 , LCD_SEG_R04 },       //E
        {LCD_COM_R1 , LCD_SEG_R04 },       //F
        {LCD_COM_R2 , LCD_SEG_R04 },       //G
    },

    {     //3
        {LCD_COM_R1 , LCD_SEG_R07 },       //A
        {LCD_COM_R2 , LCD_SEG_R07 },       //B
        {LCD_COM_R3 , LCD_SEG_R07 },       //C
        {LCD_COM_R4 , LCD_SEG_R06 },       //D
        {LCD_COM_R3 , LCD_SEG_R06 },       //E
        {LCD_COM_R1 , LCD_SEG_R06 },       //F
        {LCD_COM_R2 , LCD_SEG_R06 },       //G
    },

    {     //4
        {LCD_COM_R1 , LCD_SEG_R09 },       //A
        {LCD_COM_R2 , LCD_SEG_R09 },       //B
        {LCD_COM_R3 , LCD_SEG_R09 },       //C
        {LCD_COM_R4 , LCD_SEG_R08 },       //D
        {LCD_COM_R3 , LCD_SEG_R08 },       //E
        {LCD_COM_R1 , LCD_SEG_R08 },       //F
        {LCD_COM_R2 , LCD_SEG_R08 },       //G
    },

    {     //5
        {LCD_COM_R1 , LCD_SEG_R11 },       //A
        {LCD_COM_R2 , LCD_SEG_R11 },       //B
        {LCD_COM_R3 , LCD_SEG_R11 },       //C
        {LCD_COM_R4 , LCD_SEG_R10 },       //D
        {LCD_COM_R3 , LCD_SEG_R10 },       //E
        {LCD_COM_R1 , LCD_SEG_R10 },       //F
        {LCD_COM_R2 , LCD_SEG_R10 },       //G
    },

    {     //6
        {LCD_COM_R1 , LCD_SEG_R13 },       //A
        {LCD_COM_R2 , LCD_SEG_R13 },       //B
        {LCD_COM_R3 , LCD_SEG_R13 },       //C
        {LCD_COM_R4 , LCD_SEG_R12 },       //D
        {LCD_COM_R3 , LCD_SEG_R12 },       //E
        {LCD_COM_R1 , LCD_SEG_R12 },       //F
        {LCD_COM_R2 , LCD_SEG_R12 },       //G
    },

    // Left LCD

    {     //1 on the datasheet= 0 in digitmap array
        {LCD_COM_L1 , LCD_SEG_L03 },       //A
        {LCD_COM_L2 , LCD_SEG_L03 },       //B
        {LCD_COM_L3 , LCD_SEG_L03 },       //C
        {LCD_COM_L4 , LCD_SEG_L02 },       //D
        {LCD_COM_L3 , LCD_SEG_L02 },       //E
        {LCD_COM_L1 , LCD_SEG_L02 },       //F
        {LCD_COM_L2 , LCD_SEG_L02 },       //G
    },

    {     //2
        {LCD_COM_L1 , LCD_SEG_L05 },       //A
        {LCD_COM_L2 , LCD_SEG_L05 },       //B
        {LCD_COM_L3 , LCD_SEG_L05 },       //C
        {LCD_COM_L4 , LCD_SEG_L04 },       //D
        {LCD_COM_L3 , LCD_SEG_L04 },       //E
        {LCD_COM_L1 , LCD_SEG_L04 },       //F
        {LCD_COM_L2 , LCD_SEG_L04 },       //G
    },

    {     //3
        {LCD_COM_L1 , LCD_SEG_L07 },       //A
        {LCD_COM_L2 , LCD_SEG_L07 },       //B
        {LCD_COM_L3 , LCD_SEG_L07 },       //C
        {LCD_COM_L4 , LCD_SEG_L06 },       //D
        {LCD_COM_L3 , LCD_SEG_L06 },       //E
        {LCD_COM_L1 , LCD_SEG_L06 },       //F
        {LCD_COM_L2 , LCD_SEG_L06 },       //G
    },

    {     //4
        {LCD_COM_L1 , LCD_SEG_L09 },       //A
        {LCD_COM_L2 , LCD_SEG_L09 },       //B
        {LCD_COM_L3 , LCD_SEG_L09 },       //C
        {LCD_COM_L4 , LCD_SEG_L08 },       //D
        {LCD_COM_L3 , LCD_SEG_L08 },       //E
        {LCD_COM_L1 , LCD_SEG_L08 },       //F
        {LCD_COM_L2 , LCD_SEG_L08 },       //G
    },

    {     //5
        {LCD_COM_L1 , LCD_SEG_L11 },       //A
        {LCD_COM_L2 , LCD_SEG_L11 },       //B
        {LCD_COM_L3 , LCD_SEG_L11 },       //C
        {LCD_COM_L4 , LCD_SEG_L10 },       //D
        {LCD_COM_L3 , LCD_SEG_L10 },       //E
        {LCD_COM_L1 , LCD_SEG_L10 },       //F
        {LCD_COM_L2 , LCD_SEG_L10 },       //G
    },

    {     //6
        {LCD_COM_L1 , LCD_SEG_L13 },       //A
        {LCD_COM_L2 , LCD_SEG_L13 },       //B
        {LCD_COM_L3 , LCD_SEG_L13 },       //C
        {LCD_COM_L4 , LCD_SEG_L12 },       //D
        {LCD_COM_L3 , LCD_SEG_L12 },       //E
        {LCD_COM_L1 , LCD_SEG_L12 },       //F
        {LCD_COM_L2 , LCD_SEG_L12 },       //G
    },



};

#include <stdio.h>

// Total number of LCD registers
#define LCD_REG_COUNT (((LCD_MAX_NBR_OF_SEG + 7)/8)*LCD_MAX_NBR_OF_COM)

// For each of the LCD data regs, put an X if any pixel of the digit touches that reg
// Good for getting a view of which digits impact other digits when updating


void printLcdMap() {
    
    // Step though each register, listing them vertically down the page

    printf("### LCD register usage by digit map\r\n");

    // Print table header

    printf("\r\n| Reg  | ");

    for( uint8_t dc=0; dc<12;dc++ ) {
        // Digit #11 is the leftmost on the display
        
        uint8_t d= 11-dc;
        printf("%2.2d | " , d );

    }


    printf("\r\n| ---  | ");

    for( uint8_t dc=0; dc<12;dc++ ) {
        // Digit #11 is the leftmost on the display
        
        printf("-- | " );

    }


    // Print rows
    
    for( uint8_t reg = 0; reg <= LCD_REG_COUNT ; reg++ ) {
        
        printf( "\r\n| [%2.2d] |" , reg );
        
        
        // Step though each of the 12 digits, listing them horizontally across the page
        
        
        for( uint8_t dc=0; dc<12;dc++ ) {
            
            
            // Digit #11 is the leftmost on the display
            
            uint8_t d= 11-dc;
            
            // step though the pixels in this digit to see if current register is used.
            
            // Note that a register can be used multiple times by the same digit, be we only care if it is used at all
            uint8_t reg_used_flag = 0;
            
            for( uint8_t p=0; p<7;p++ ) {
                
                const lcd_visible_segment current_pixel = digitmap[d][p];
                
                if ( reg == LCD_REG_OFF( current_pixel.com , current_pixel.seg )  ) {
                    
                    reg_used_flag = 1 ;
                    
                }
                
            }
            
            printf( "  %c |" , reg_used_flag ? 'X' : ' ');
            
        }
        
    }
    
}





// For each of the LCD data regs, put an X if any pixel of the digit touches that reg
// Good for getting a view of which digits impact other digits when updating

void printLcdLocationMap() {
    
    // Step though each pixel in each digit and show which register it is in

    printf("\r\n\r\n### LCD register by pixel map (register:bit)\r\n");

    // Print table header

    printf("\r\n| Digit | A | B | C | D | E | F |\r\n");
    printf("| - | - | - | - | - | - | - |\r\n");

    // Print rows
    
    // Step though each of the 12 digits, listing them horizontally across the page
    
    
    for( uint8_t dc=0; dc<12;dc++ ) {
        
        
        // Digit #11 is the leftmost on the display
        
        uint8_t d= 11-dc;
        
        printf("| %2.2d | " , d );
        
        // step though the pixels in this digit and print the register used (A-F = 7 pixels)
        
        for( uint8_t p=0; p<7;p++ ) {
            
            const lcd_visible_segment current_pixel = digitmap[d][p];
            
            printf( " %2.2d:%1.1d |"  , LCD_REG_OFF( current_pixel.com , current_pixel.seg ) ,  current_pixel.seg % 8 );
            
        }
        
        printf( "\r\n");
        
    }
    
}

// Print the linear progression of LCD steps as digits increment

void printLcdSegSteps() {
    
    printf("\r\n\r\n### LCD changes by digit\r\n");
    
    // Print table header

    printf("\r\n| Digit |  COM0 | COM1 | COM2 | COM3 | \r\n");
    printf("| - | - | - | - | - | \r\n");

    // Print rows
    
    uint8_t coms[LCD_MAX_NBR_OF_COM];
    
    coms[0]=LCD_COM_L1;
    coms[1]=LCD_COM_L2;
    coms[2]=LCD_COM_L3;
    coms[3]=LCD_COM_L4;
    
    uint8_t prev_pixels=0;      // So we can track what changes
    
    for(uint8_t c=0; c<13; c++  ) {     // We count up to 11 so we can see the transition from 9 to 0 to 1
        
        uint8_t digit = c % 10;
        
        uint8_t current_pixels = lcd_font_digits[digit];
        
        printf( "| %2.2d |" , digit );
        
        // Step though each com to see if its register for this digit had to change
        
        for( uint8_t com=0;com<LCD_MAX_NBR_OF_COM;com++) {
            
            uint8_t com_changed_flag=0;
            
            for( uint8_t p =0; p<7 ;p++ ) {
                
                // Check to see if (1) this pixel changed since last digit, and (2) this pixel is on the COM we are checking right now.
                
                if ( ((prev_pixels & (1<<p)) !=  ( current_pixels & (1<<p))) && (digitmap[digit][p].com==coms[com])  )    {
                    com_changed_flag=1;
                }
                
            }
            
            printf( " %c |" , com_changed_flag ? 'X' : ' '  );
        }
        
        prev_pixels = current_pixels;
        
        printf("\r\n");
        
    }
}

// A snapshot of the LCD regs

typedef struct {
    uint8_t regs[LCD_REG_COUNT];
} lcd_reg_state ;


// Just to have a zeroed out one to copy

lcd_reg_state regs_zero;


// Just to have a zeroed out one to copy

lcd_reg_state regs_zero;

// Actually write out the code block.
// Note that we want the entire list of all state changes here at once rather than taking them one at a time.
// This lets us potentially do global optimizations on them. 

void emit_code_for_lcd_steps( lcd_reg_state initial_lcd_reg_state, lcd_reg_state sequence_of_lcd_reg_states[] , int sequence_count ) {
    
    lcd_reg_state regs_now = initial_lcd_reg_state;
    
    for( int i=0; i<sequence_count; i++ ) {
        
        lcd_reg_state regs_next = sequence_of_lcd_reg_states[i];
        
        for( uint8_t r=0; r<LCD_REG_COUNT ; r++) {
            
            if ( regs_now.regs[r] != regs_next.regs[r] ) {
                
                // Note: we use R18 becuase it is not expected to be saved across calls and LDI needs a register higher than r16 so we can't use temp_reg
                
                printf("asm(\"ldi r18,0x%2.02x\":::\"r18\");  // Was %2.2x\r\n" , regs_next.regs[r] , regs_now.regs[r] );
                printf("asm(\"sts 0x%4.04x,r18\");\r\n" , 0x0D00 + 0x0010 + r );            // 0D00 is the base of the LCD memory, 0x0010 is where the display registers start
                
                regs_now.regs[r] = regs_next.regs[r];
                
            }
            
        }

        printf("asm(\"sleep\");  // Step %d \r\n" ,  i );
        
    }
    
    
}


// paint a number (0-9) into the indicated place (0-11, 0=right) on the LCD
// assumes pixels are off (does not clear any not set pixels).

void setlcdregsfordigit( lcd_reg_state *lcd_regs , uint8_t place , uint8_t n ) {
    
    // Step though all the pixels in the current digit and see which ones are lit
    for( uint8_t p = 0; p<7;p++) {
        
        if ( lcd_font_digits[n] & (1<<p) ) {
            
            // This pixel is lit, so set the bit in the show regs
            
            lcd_regs->regs[ LCD_REG_OFF( digitmap[place][p].com , digitmap[place][p].seg) ] |= ( 1<< LCD_REG_BIT( digitmap[place][p].com , digitmap[place][p].seg) ) ;

            printf("set place=%d n=%d p=%d\r\n",place,n,p);
            
        }
        
    }
}


// Emit code to update the LCD
// For an hour starting at 0000 going to 5959
// Overwrites whatever is in the pixels in the rightmost 4 digits
// does not change any other digits

void lcdEmit1hourCode( ) {
    
    lcd_reg_state regs_init = regs_zero;
    
    lcd_reg_state reg_steps[60*60];
    
    int step=0;
    
    for( uint8_t m=0; m<60;m++) {
        
        for( uint8_t s=0; s<60; s++ ) {

            printf("m=%d s=%d\r\n",m,s);


            // Init to all 0 so we only need to set pixels that should be on.

            // Since all other digits start at 0 and end at zero and since the code emitter
            // does not output anything for registers that do not change between steps, then
            // the emitted code will only touch the rightmost 4 digits on the LCD display
            // and leave the others however they were.
            
            lcd_reg_state lcd_regs = regs_zero;
            
            setlcdregsfordigit( &lcd_regs, 0 , s % 10 );
            setlcdregsfordigit( &lcd_regs, 1 , s / 10 );
            setlcdregsfordigit( &lcd_regs, 2 , m % 10 );
            setlcdregsfordigit( &lcd_regs, 3 , m / 10 );
            
            // Ok, now the shadow_regs_next have the values that should be in the LCD registers when we are done.
            
            reg_steps[step++] = lcd_regs;
        }
        
    }

    printf("step=%d\r\n",step);

    emit_code_for_lcd_steps( regs_init , reg_steps , step  );
    
}



void main() {
    lcdEmit1hourCode();
}

//---------------- END CUT
