/*
 * lcd.h
 *
 * Created: 10/25/2017 11:53:48 PM
 *  Author: josh
 */


#ifndef LCD_H_
#define LCD_H_

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

void digitOn( uint8_t d,  uint8_t n );

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

#endif /* LCD_H_ */