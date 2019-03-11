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

#define TRIGGER_VPORT (VPORT0)
#define TRIGGER_PIN (7)

// Count bottom 4 digits from 0000 to 5959 
// with a 1 second interlock on VPORT2.2
// FOUT must be low on entry or you will miss a second

extern void lcd_optimized_run_hour();
            
// Show the Ready Mode figure 8 pattern 
// with a 1 second interlock on VPORT2.2
// Run until 


extern void lcd_optimized_run_ready();

// Purrdee
// Just for show/fun. Takes about 0.5 sec

extern void lcd_optimized_run_sinewave();


#endif /* CODE2CODE_OUTPUT_H_ */