/*
 * lcd.h
 *
 * Created: 10/25/2017 11:53:48 PM
 *  Author: josh
 */


#ifndef LCD_H_
#define LCD_H_

#define LCD_DIGITS  12      // 6 per module * 2 modules

// Maximum number of common lines.
#define LCD_MAX_NR_OF_COM  4
// Maximum number of segment lines.
#define LCD_MAX_NBR_OF_SEG  25

/*
#define LCD_MEM_REG( pixel_com , pixel_seg ) _SFR_MEM8( LCD.DATA0 + (  pixel_com * ( (MAX_SEG+7)/8) ) + (pixel_seg / 8 ) )

#define LCD_MEM_BIT( pixel_com , pixel_seg ) ( 1<< ( pixel_seg % 8))


inline void lcd_on( uint8_t com , uint8_t seg ) {
    LCD_MEM_REG( com ,  seg ) |= LCD_MEM_BIT( com ,  seg );
}

inline void lcd_off( uint8_t com , uint8_t seg ) {
    LCD_MEM_REG( com ,  seg ) &= ~LCD_MEM_BIT( com ,  seg );
}

*/
// This function is used to turn on individual icons on the display.
void lcd_set_pixel(uint8_t pix_com, uint8_t pix_seg);

// This function is used to turn off individual icons on the display.
void lcd_clear_pixel(uint8_t pix_com, uint8_t pix_seg);

// Level is -127 to 127 but there are really only 64 steps

inline void lcd_set_contrast( signed char level ) {
    LCD.CTRLF = level >> 2;                         // Loose lower 2 bits of resolution, but keep 2's complement bits
}

void spinOn( uint8_t d, uint8_t step );

void spinOff( uint8_t d, uint8_t step );

// Darken the segments in digit d (leftmost is 0) to display the number n

void digitOn(  uint8_t n , uint8_t d );

// Undarken the segments in digit d (leftmost is 0) to undisplay the number n

void digitOff( uint8_t d,  uint8_t n );

// Blank out the specified digit

void digitBlank( uint8_t d );


// Set or clear segments to show digit
void digitShow( uint8_t d,  uint8_t n );

// Display the decimal digit n (0-9) at position d (0-11 where 0 is leftmost) dark if onFlag, light if not

void displaydigit( uint8_t d,  uint8_t n , uint8_t onFlag);

// Animate an attractive figure 8 pattern. There are 8 steps

void figure8On( uint8_t d,  uint8_t s );


void figure8Off( uint8_t d,  uint8_t s );

void displaydigit01O();
void displaydigit02O();
void displaydigit01F();
void displaydigit02F();

// Chars

void showDash(uint8_t n );      // '-'

void showClocError();                 // "cloc   Error"
void showEEProError(uint8_t code);    // "EEProX  Error" where X is a single digit error code
void showc2018JOSH();                 // "c2018   JOSH"
void showNoTrig();                    // "no TriG"



// Battery icon
// Level = 0-3
// Level 0 is the outline

void battSegOn( uint8_t level);

void battSegOff(uint8_t level);


 // Colons between 4th and 5th digit on each module

 void colonLOn();

 void colonLOff();

 void colonROn();

 void colonROff();


// decimal points between 2th and 3th digit on each module

void decimalLOn();

void decimalLOff();

void decimalROn();

void decimalROff();

// Quickly blink the whole LCD

void lcd_blank();

void lcd_unblank();

// The text part of the Pin B Phase 1 diagnostics display
// (space left for numbers to be filled in)

void showPinBPhase3Text();

void showSetCloc();

void showReset();

// Bad interrupt

void showbAdint();

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

// Which segments A-G do we turn on for each of the displayed chars 0-9

/*
// This is rightside up font

const uint8_t lcd_font[] = {
    SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F ,         // 0
    SEG_B | SEG_C ,                                         // 1
    SEG_A | SEG_B | SEG_G | SEG_E | SEG_D ,                 // 2
    SEG_A | SEG_B | SEG_G | SEG_C | SEG_D ,                 // 3
    SEG_F | SEG_G | SEG_B | SEG_C ,                         // 4
    SEG_A | SEG_F | SEG_G | SEG_C | SEG_D ,                 // 5
    SEG_A | SEG_C | SEG_D | SEG_E | SEG_F | SEG_G ,         // 6
    SEG_A | SEG_B | SEG_C ,                                 // 7
    SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F | SEG_G , // 8
    SEG_A | SEG_B | SEG_C | SEG_D | SEG_F | SEG_G ,         // 9
};

*/

// This is upside down font

extern const uint8_t lcd_font_digits[];

extern const uint8_t lcd_font_char_dash;
extern const uint8_t lcd_font_char_c;
extern const uint8_t lcd_font_char_L;
extern const uint8_t lcd_font_char_o;
extern const uint8_t lcd_font_char_E;
extern const uint8_t lcd_font_char_r;
extern const uint8_t lcd_font_char_P;

extern const uint8_t lcd_font_char_J;
extern const uint8_t lcd_font_char_O;
extern const uint8_t lcd_font_char_S;
extern const uint8_t lcd_font_char_H;

extern const uint8_t lcd_font_char_n;
extern const uint8_t lcd_font_char_t;
extern const uint8_t lcd_font_char_i;                  // i
extern const uint8_t lcd_font_char_G;

extern const uint8_t lcd_font_char_V;
extern const uint8_t lcd_font_char_l;

extern const uint8_t lcd_font_char_b;
extern const uint8_t lcd_font_char_A;
extern const uint8_t lcd_font_char_d;
extern const uint8_t lcd_font_char_U;

void lcd_show_fontchar( uint8_t segs , uint8_t d );

#endif /* LCD_H_ */