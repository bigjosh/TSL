/*
 * code2code_output.h
 *
 * Created: 3/3/2019 12:37:11 AM
 *  Author: josh
 */ 


#ifndef CODE2CODE_OUTPUT_H_
#define CODE2CODE_OUTPUT_H_

// Note that these values are hardcoded in code2code so any changes 
// must be reflected there!

#define FOUT_VPORT (VPORT2)
#define FOUT_PIN   (2)

extern void update_lcd_1_hour();

// Jump to a specific step where step 0 is "0000" and step 3599 is "5959"
// Starts at the requested step and returns after reaching step 3600
// The requested step is displayed immediately 

extern void update_lcd_1_hour_starting_at(uint16_t step);

#endif /* CODE2CODE_OUTPUT_H_ */