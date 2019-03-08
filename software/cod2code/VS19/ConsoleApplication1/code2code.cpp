
/*

	This program will genrate the source code that updates the TSL LCD. You should run this program on a 
	computer (not on the TSL) and then capture the output, paste it into the output.c file in the TSL project,
	and then recompile the TSL project. 

	See code2code.MD for more info on how this all works. 

*/


// You will need these to make this block compile independently...
#include <stdio.h>

#ifndef uint8_t
	typedef unsigned char uint8_t;
#endif


	//---------------CUT HERE FOR SEG MAP PRINTOUT
	// This code should be copy/pasted from LCD.C to ConsoleApplication1.cpp any time
	// it is changed and you want to regenerate the LCD updater code in output.c. 


	// Maximum number of common lines. Defined in datasheets.
#define LCD_MAX_NBR_OF_COM  4
// Maximum number of segment lines. Defined in datasheets.
#define LCD_MAX_NBR_OF_SEG  25


// Use these for addressing the LCD pixel registers
#define LCD_REGS_BASE_HIGH	(0x0D)		// High byte of the LCD registers base address
#define LCD_REGS_BASE_LOW	(0x10)		// Low byte of the LCD registers base address


// Map LCD segments to registers
// compute at compile time
// Taken from 25.5.11 DATA – LCD Data Memory Mapping

// Return the offset of the register that holds the requested pixel

	inline static uint8_t LCD_REG_OFF(uint8_t com, uint8_t seg) {

		uint8_t reg = (com * ((LCD_MAX_NBR_OF_SEG + 7) / 8)) + (seg / 8);

		return reg;
	}


	// Return the bit in the register that holds the requested pixel

	inline static uint8_t LCD_REG_BIT(uint8_t com, uint8_t seg) {

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
	const uint8_t lcd_font_char_c = { SEG_G | SEG_B | SEG_A };                 // c
	const uint8_t lcd_font_char_L = { SEG_C | SEG_B | SEG_A };                 // L
	const uint8_t lcd_font_char_o = { SEG_G | SEG_B | SEG_A | SEG_F };         // o
	const uint8_t lcd_font_char_E = { SEG_D | SEG_C | SEG_G | SEG_B | SEG_A }; // E
	const uint8_t lcd_font_char_r = { SEG_B | SEG_G };                         // r
	const uint8_t lcd_font_char_P = { SEG_E | SEG_D | SEG_C | SEG_G | SEG_B }; // P

	const uint8_t lcd_font_char_J = { SEG_B | SEG_A | SEG_F | SEG_F | SEG_E }; // J
	const uint8_t lcd_font_char_O = { SEG_D | SEG_C | SEG_B | SEG_A | SEG_F | SEG_E }; // O
	const uint8_t lcd_font_char_S = { SEG_D | SEG_C | SEG_G | SEG_F | SEG_A }; // S
	const uint8_t lcd_font_char_H = { SEG_B | SEG_C | SEG_F | SEG_G | SEG_E }; // H

	const uint8_t lcd_font_char_n = { SEG_B | SEG_G | SEG_F };                 // n
	const uint8_t lcd_font_char_t = { SEG_B | SEG_C | SEG_A | SEG_G };         // t
	const uint8_t lcd_font_char_i = { SEG_B };                                 // i
	const uint8_t lcd_font_char_G = { SEG_D | SEG_C | SEG_B | SEG_A | SEG_F }; // G

	const uint8_t lcd_font_char_V = { SEG_C | SEG_B | SEG_A | SEG_F | SEG_E }; // V (ok, not really)
	const uint8_t lcd_font_char_l = { SEG_C | SEG_B };                         // l

	const uint8_t lcd_font_char_b = { SEG_C | SEG_B | SEG_A | SEG_F | SEG_G }; // b
	const uint8_t lcd_font_char_A = { SEG_C | SEG_B | SEG_D | SEG_E | SEG_G | SEG_F };   // A
	const uint8_t lcd_font_char_d = { SEG_G | SEG_B | SEG_A | SEG_F | SEG_E };  // d
	const uint8_t lcd_font_char_U = { SEG_C | SEG_B | SEG_A | SEG_F | SEG_E };  // d


	static const uint8_t figureEightSteps[] = {
		SEG_A, SEG_B , SEG_G , SEG_E , SEG_D , SEG_C , SEG_G , SEG_F
	};

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
	} lcd_visible_segment;

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

//---------------- END CUT

#include <stdio.h>

#include <iostream>
using namespace std;

// Total number of LCD registers
#define LCD_REG_COUNT (((LCD_MAX_NBR_OF_SEG + 7)/8)*LCD_MAX_NBR_OF_COM)

// For each of the LCD data regs, put an X if any pixel of the digit touches that reg
// Good for getting a view of which digits impact other digits when updating


void printLcdMap() {

	// Step though each register, listing them vertically down the page

	printf("### LCD register usage by digit map\r\n");

	// Print table header

	printf("\r\n| Reg  | ");

	for (uint8_t dc = 0; dc < 12; dc++) {
		// Digit #11 is the leftmost on the display

		uint8_t d = 11 - dc;
		printf("%2.2d | ", d);

	}


	printf("\r\n| ---  | ");

	for (uint8_t dc = 0; dc < 12; dc++) {
		// Digit #11 is the leftmost on the display

		printf("-- | ");

	}


	// Print rows

	for (uint8_t reg = 0; reg <= LCD_REG_COUNT; reg++) {

		printf("\r\n| [%2.2d] |", reg);


		// Step though each of the 12 digits, listing them horizontally across the page


		for (uint8_t dc = 0; dc < 12; dc++) {


			// Digit #11 is the leftmost on the display

			uint8_t d = 11 - dc;

			// step though the pixels in this digit to see if current register is used.

			// Note that a register can be used multiple times by the same digit, be we only care if it is used at all
			uint8_t reg_used_flag = 0;

			for (uint8_t p = 0; p < 7; p++) {

				const lcd_visible_segment current_pixel = digitmap[d][p];

				if (reg == LCD_REG_OFF(current_pixel.com, current_pixel.seg)) {

					reg_used_flag = 1;

				}

			}

			printf("  %c |", reg_used_flag ? 'X' : ' ');

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


	for (uint8_t dc = 0; dc < 12; dc++) {


		// Digit #11 is the leftmost on the display

		uint8_t d = 11 - dc;

		printf("| %2.2d | ", d);

		// step though the pixels in this digit and print the register used (A-F = 7 pixels)

		for (uint8_t p = 0; p < 7; p++) {

			const lcd_visible_segment current_pixel = digitmap[d][p];

			printf(" %2.2d:%1.1d |", LCD_REG_OFF(current_pixel.com, current_pixel.seg), current_pixel.seg % 8);

		}

		printf("\r\n");

	}

}

void printLcdCodeHeader() {

	cout << "    // Ths code was generated by the code2code console app " << endl;
	cout << "    // so don't manually edit it. See code2code.MD for more info." << endl;
	cout << "    // " << endl;
	cout << "    // The setuplcdsequence() function gets everything ready and only needs to" << endl;
	cout << "    // be called once when the TSL poweres up. After that, every time you call " << endl;
	cout << "    // runlcdsequence() it will step though a full hour of 1 second updates." << endl;
	cout << "    " << endl;
	cout << "    void setuplcdsequence() {" << endl;

}

// Print the linear progression of LCD steps as digits increment

void printLcdSegSteps() {

	printf("\r\n\r\n### LCD changes by digit\r\n");

	// Print table header

	printf("\r\n| Digit |  COM0 | COM1 | COM2 | COM3 | \r\n");
	printf("| - | - | - | - | - | \r\n");

	// Print rows

	uint8_t coms[LCD_MAX_NBR_OF_COM];

	coms[0] = LCD_COM_L1;
	coms[1] = LCD_COM_L2;
	coms[2] = LCD_COM_L3;
	coms[3] = LCD_COM_L4;

	uint8_t prev_pixels = 0;      // So we can track what changes

	for (uint8_t c = 0; c < 13; c++) {     // We count up to 11 so we can see the transition from 9 to 0 to 1

		uint8_t digit = c % 10;

		uint8_t current_pixels = lcd_font_digits[digit];

		printf("| %2.2d |", digit);

		// Step though each com to see if its register for this digit had to change

		for (uint8_t com = 0; com < LCD_MAX_NBR_OF_COM; com++) {

			uint8_t com_changed_flag = 0;

			for (uint8_t p = 0; p < 7; p++) {

				// Check to see if (1) this pixel changed since last digit, and (2) this pixel is on the COM we are checking right now.

				if (((prev_pixels& (1 << p)) != (current_pixels & (1 << p))) && (digitmap[digit][p].com == coms[com])) {
					com_changed_flag = 1;
				}

			}

			printf(" %c |", com_changed_flag ? 'X' : ' ');
		}

		prev_pixels = current_pixels;

		printf("\r\n");

	}
}

#include <iostream> 
#include <map> 
#include <set>
#include <vector>
#include <stack>

#include <forward_list>
#include <algorithm>
#include <sstream>      // std::stringstream


using namespace std;

// A snapshot of the LCD regs

struct reg {

	bool used;				// Did we use this register? (Avoids need for a special "not used" value for value)	
	uint8_t value;			// Current value

};

struct lcd_reg_state {
	reg regs[LCD_REG_COUNT];		// You can use -1 to mean "not known" since it will always be different than a real value
};

#define REG_VALUE_UNKNOWN (-1)

// Count all occurances of a key so you can find the most popular ones

template <class key_type>
struct Top_finder {

	map<key_type, int> keys_to_counts;

	void increment(key_type key) {

		keys_to_counts[key]++;

	}


	int get_count_by_key(key_type key) {

		return keys_to_counts[key];

	}

	bool cmp_by_key(int a, int b) {

		return a < b;

	}

	struct Record {

		key_type key;
		int count;

		Record(key_type key, int count) : key(key), count(count) {}

	};


	static bool compare_count_decending(Record a, Record b)
	{
		return (a.count > b.count);
	}

	static bool compare_count_ascending(Record a, Record b)
	{
		return (a.count < b.count);
	}


	vector<Record> sorted_by_count(bool (*sort_function)(Record a, Record b)) {

		vector<Record> keys_sorted_by_count;

		// Add alll the keys/counts to a vector

		for (auto const& pair : keys_to_counts)			// C+++17 only!!!
		{

			key_type key = pair.first;
			int count = pair.second;

			Record new_record(key, count);

			keys_sorted_by_count.push_back(new_record);		// Not insert()!! Ahhh!!!!

		}

		// Sort by count decending

		sort(keys_sorted_by_count.begin(), keys_sorted_by_count.end(), sort_function);


		return keys_sorted_by_count;

	}

	vector<Record> sorted_by_count_decending() {
		return sorted_by_count(compare_count_decending);
	}

	vector<Record> sorted_by_count_ascending() {
		return sorted_by_count(compare_count_ascending);
	}


};

const int string_bufer_len = 80;
typedef char string_buffer[string_bufer_len];

void printc(const char* s, const char * clobbers , const char *comment) {

	string_buffer clobbers_string;
	string_buffer comment_string;

	if (clobbers && *clobbers) {
		sprintf_s(clobbers_string, string_bufer_len, "\"%s\"", clobbers);
	}
	else {
		sprintf_s(clobbers_string, string_bufer_len, "     " );		// empty (5 spaces balance the quotes and 3 letter register name so everythign lines up nice)
	}

	if (comment && *comment ) {
		sprintf_s(comment_string, string_bufer_len, "    // %s", comment);
	}
	else {
		sprintf_s(comment_string, string_bufer_len, "");		// empty
	}

	printf("    asm(\"%-20s\":::%s);%s\n",  s , clobbers_string , comment_string );

}

void printasm(const char* s, const char* clobbers, const char* comment) {

	string_buffer comment_string;

	if (comment && *comment) {
		sprintf_s(comment_string, string_bufer_len, "    ; %s", comment);
	}
	else {
		sprintf_s(comment_string, string_bufer_len, "");		// empty
	}

	printf("    %-20s %s\n", s,  comment_string);

}



void printcomment(const char* comment) {

	printf("    // %s\n", comment);

}

void printblankline() {
	printf("\n");
}


// Actually write out the code block.
// Note that we want the entire list of all state changes here at once rather than taking them one at a time.
// This lets us potentially do global optimizations on them. 

// interstpe macro is a macro that will be called between steps.
// if loop is true, then the sequence will loop forever (unless it hit s RET in the interloop macro), otherise
// it will return at the end of the last step. 

// For now the intial_state is not really used. Instead we just always set all used registers on step 0.

void emit_code_for_lcd_steps( const char *seq_name , lcd_reg_state initial_lcd_reg_state, lcd_reg_state sequence_of_lcd_reg_states[], int sequence_count, const char *interstep_macro , bool loop ) {

	cout << "    // Sequence name: " << seq_name << endl;
	cout << "    // Sequence count: " << sequence_count << endl;
	cout << "" << endl;

	lcd_reg_state regs_now;		// Used to hold current register values between steps


	cout << "// Actual function called from C to \n\n";
	cout << "// step though a full hour of LCD updates (3600 in all)\n\n";
	cout << endl;
	cout << ".global lcd_optimized_run_" << seq_name << endl;		// Make visible to linker and C
	cout << "lcd_optimized_run_" << seq_name << ":" << endl;		// The label to jump to to start the LCD update sequence

	// First we do a trial pass to find which 
	// LCD registers are accessed most often and values are stored most often 

	Top_finder<int> lcd_reg_access_top_finder;
	Top_finder<int> lcd_load_values_access_top_finder;

	// Now count up the accesses!

	regs_now = initial_lcd_reg_state;

	for (int i = 0; i < sequence_count; i++) {

		lcd_reg_state regs_next = sequence_of_lcd_reg_states[i];

		for (uint8_t r = 0; r < LCD_REG_COUNT; r++) {

			// Only care if (1) new value is set, and new value is different from old value
			// note that this will catch a change from unknown to anything else

			// Note that we load all LCD registers if i=0 becuase that means this is the inital step so we don't know 
			// what happens to be in the LCD registers at the moment. Here we explicity check for i=0
			// and count all values in that first step. 

			if (regs_next.regs[r].used && (i==0 || (regs_now.regs[r].value != regs_next.regs[r].value )) ) {		

				// Count the access to this register
				lcd_reg_access_top_finder.increment(r);

				lcd_load_values_access_top_finder.increment(regs_next.regs[r].value);

				regs_now.regs[r] = regs_next.regs[r];

			}

		}

	}

	/*

	printf("| LCD Register | Access Count |\n");
	printf("| - | - |\n");
	lcd_reg_access_counter.print_sorted_key_count_md();

	printf("| LCD Register Value | Access Count |\n");
	printf("| - | - |\n");
	lcd_load_values_access_counter.print_sorted_key_count_md();

	printf("sorted:\n");

	*/


	auto sorted_lcd_regsisters = lcd_reg_access_top_finder.sorted_by_count_decending();

	/*

	cout << "// Most accessed LCD registers: " << endl;


	for (auto const& reg : sorted_lcd_regsisters) {

		printf("//    REG: %2d Count: %3d\n", reg.key , reg.count );

	}

	cout << "" << endl;
	cout << "// Most common values saved to LCD registers: " << endl;

	*/

	auto sorted_lcd_values = lcd_load_values_access_top_finder.sorted_by_count_decending();

	/*

	for (auto const& reg : sorted_lcd_values) {

		printf("//    Value: %02x Count: %3d\n", reg.key, reg.count);

	}

	*/



	cout << "" << endl;


	printcomment("First we will load up the some available XMEGA registers with the most commonly");
	printcomment("stored values so we can save an LDI to load them again.");
	printcomment("We do this first becuase this will naturally PUSH the registers used");
	printcomment("by the Y index adn therefore save them before they get clobbered in the");
	printcomment("index allocation below.");

	struct avr_reg_type {

		bool available;		// Can we use this reg? (false means either we already used it or it is needed for something else
		bool callsaved;		// do we need to save it? 
		bool ldi_target;	// Can we directly LDI to this register?

	};


	// Problems	1711 1717 = step 1031

	const avr_reg_type avr_regs[32] = {

		{true , true, false },			// 0 = temp_reg. We will use this for values that are not cached.
		{true , true, false },			// 1 = zero_reg. This comes preloaded. We must save and restore it, but if we do then we can use it for other things. 

		{true  , true, false },			// r2-r17 "Call-used registers. Assembler subroutines are responsible for saving and restoring these registers, if changed."
		{true  , true, false },
		{true  , true, false },
		{true  , true, false },
		{true  , true, false },
		{true  , true, false },
		{true  , true, false },
		{true  , true, false },
		{true  , true, false },
		{true  , true, false },
		{true  , true, false },
		{true  , true, false },
		{true  , true, false },
		{true  , true, false },
		{true  , true, false },
		{true  , true, true  },			// LDI can address r16-31

		{false  , false, true  },		// r18-r25 "You may use them freely in assembler subroutines." We save r18 to use as a "working" register in cases where we need a value that is not cached.
		{true  , false, true  },
		{true  , false, true  },
		{true  , false, true  },
		{true  , false, true  },
		{true  , false, true  },
		{true  , false, true  },
		{true  , false, true  },

		{false  , false, true  },		// r26-r27. This is the X index. We will use it for addressing. Need not be saved.
		{false  , false, true  },

		{false  , true , true  },		// r28-r29. This is the Y index. We will use it for addressing. It is call saved (used for stack frame)
		{false  , true , true  },

		{false  , false, true  },		// r30-r31. This is the Z index. We will use it for addressing. Need not be saved.
		{false  , false, true  },

	};

	const int working_reg = 18;		//  We marked this as not availabel above so we can use it as a working register. 
									// We want something that is LDI direct loadable. 

	int working_reg_value = REG_VALUE_UNKNOWN;		// Keep track of the current value in the working reg so we can skip redundant loads


	// Keep track of pushed and popped registers
	struct stack_manager_type {
		stack<int> pushed_regs;		// Save a list of every pushed reg so we can pop then when we exist

		void push(int r) {

			string_buffer asm_buffer;
			string_buffer comment_buffer;

			sprintf_s(asm_buffer, string_bufer_len, "PUSH r%02d", r);
			sprintf_s(comment_buffer, string_bufer_len, "Save reg %02d to stack", r);
			printasm(asm_buffer, "", comment_buffer);

			pushed_regs.push(r);
		}

		void popall() {

			while (!pushed_regs.empty()) {

				auto r = pushed_regs.top();

				string_buffer asm_buffer;
				string_buffer comment_buffer;

				sprintf_s(asm_buffer, string_bufer_len, "POP r%02d", r);
				sprintf_s(comment_buffer, string_bufer_len, "Restore reg %02d from stack", r);
				printasm(asm_buffer, "", comment_buffer);

				pushed_regs.pop();

			}

		}
	};

	stack_manager_type stack_manager;
	

	// First build a table of all the registers with thier costs

	struct avr_reg_and_cost_type {
		int reg;		// Register number (index into avr_regs_
		bool available;	// Have we allocated it yet?
		int cost;		// Computer cost in cycles to use this register. 

		bool assigned;	// Did we assign a value to this reg?
		int value;		// The assigned value
				
		// Sort by lowest cost first 
		bool operator<(const avr_reg_and_cost_type& b) const {
			return b.cost  > cost;
		}
		
	};



	vector<avr_reg_and_cost_type> avr_reg_table;

	for (int i = 0; i < 32; i++) {

		avr_reg_type avr_reg = avr_regs[i];

		int cost = 0;

		if (avr_reg.callsaved) {
			cost += 2;				// If we need to save it, then 1 cycle for the push and 1 for the pop
		}

		if (!avr_reg.ldi_target) {
			cost += 1;				// If we can't use LDI, then we have to LDI it into temp and then move from temp to reg 
		}

		avr_reg_and_cost_type new_reg_and_cost;

		new_reg_and_cost.reg = i;
		new_reg_and_cost.available = avr_regs[i].available;
		new_reg_and_cost.cost = cost;

		avr_reg_table.push_back(new_reg_and_cost);

	}
	
	// Sort the table by cost (the sorting function is inside the struct

	std::sort(avr_reg_table.begin(), avr_reg_table.end());


	// OK! Now we have a nice list of registers sorted by thier costs
	// We will start allocating these registers to the most used values
	// until either we run out of registers or the cost gets higher than it is worth. 

	// Remeber these are sotred by most used first

	for (auto const& reg_value : sorted_lcd_values) {

		// Look for the lowest cost, still available register on our list

		auto lowest_cost_available_reg = std::find_if(avr_reg_table.begin(), avr_reg_table.end(), [](avr_reg_and_cost_type s) { return s.available; });

		if (lowest_cost_available_reg != avr_reg_table.end()) {

			// OK, we have an available register!

			int reg = lowest_cost_available_reg->reg;

			string_buffer asm_buffer;
			string_buffer comment_buffer;

			if (avr_regs[reg].callsaved) {

				// Do we have to save this reg? 

				stack_manager.push(reg);

			}

			if (avr_regs[reg].ldi_target) {

				// We can directly LDI to this reg

				sprintf_s(asm_buffer, string_bufer_len, "LDI r%02d,%3d", reg, reg_value.key);

				sprintf_s(comment_buffer, string_bufer_len, "Cache value %3d in reg %02d (used %d times)", reg_value.key, reg, reg_value.count);
				printasm(asm_buffer, "", comment_buffer);

			}
			else {

				// We can NOT LDI directly to this reg, so we have to use temp reg to load it

				sprintf_s(asm_buffer, string_bufer_len, "LDI r%02d,%3d", working_reg , reg_value.key);
				sprintf_s(comment_buffer, string_bufer_len, "Load cache value %3d into working_reg", reg_value.key );
				printasm(asm_buffer, "", comment_buffer);

				working_reg_value = reg_value.key;

				sprintf_s(asm_buffer, string_bufer_len, "MOV r%02d,%3d", reg , working_reg );
				sprintf_s(comment_buffer, string_bufer_len, "Move value %3d into reg %02d (used %d times)", reg_value.key, reg, reg_value.count);
				printasm(asm_buffer, "", comment_buffer);

			}

			lowest_cost_available_reg->value = reg_value.key;
			lowest_cost_available_reg->available = false;
			lowest_cost_available_reg->assigned = true;

		}

	}

	// Remeber the ASM string will will output to store a AVR register to this LCD register
	// This output string must have a %d in it it that will accept the XMEGA register number

	printcomment("This macro will load up the indirect pointers to point to the top 3 LCD addresses");
	printcomment("so we can get to those in 1 cycle with ST rather than 2 cycles for an STS");
	printcomment("This macro does NOT alter the stack (important)");

	string_buffer reg_access_asm_strings[LCD_REG_COUNT];
	string_buffer reg_access_comment_strings[LCD_REG_COUNT];
	int reg_access_cyclecount[LCD_REG_COUNT];					// Keep track of how many cycles this instruction takes for metrics

	// Run though the LCD registers, most popular first, and asign the top ones to index registers. 

	struct index_reg_t {

		char name;
		int high_reg;
		int low_reg;
		bool assigned;
		int lcd_address_offset;

	};

	vector<index_reg_t> index_regs = {
		{ 'X' ,  27 , 26 , false , 0 },
		{ 'Y' ,  29 , 28 , false , 0 },
		{ 'Z' ,  31 , 30 , false , 0 },
	};


	for (auto const& reg : sorted_lcd_regsisters) {

		// See if any index registers are still available to alocate....
		// (remeber we are processing registers most popular first, so grab the indexes as quick as you can!)

		auto first_free_index_reg = std::find_if( index_regs.begin(), index_regs.end() , [](index_reg_t s) { return !s.assigned; });

		if ( first_free_index_reg != index_regs.end() ) { 

			string_buffer asm_buffer;
			string_buffer comment_buffer;
			string_buffer clobber_buffer;

			if (first_free_index_reg->name == 'Y') {

				printcomment("We have to manually save Y becuase C expects it to be the same when we return");
				stack_manager.push(first_free_index_reg->high_reg );
				stack_manager.push(first_free_index_reg->low_reg);

			}

			sprintf_s( asm_buffer , string_bufer_len, "LDI r%02d,0x%2.02x" , first_free_index_reg->high_reg,  LCD_REGS_BASE_HIGH );		// Store to index reg the location of the LCD register
			sprintf_s( comment_buffer, string_bufer_len, "Store high byte of address of LCD reg %02d to %c", reg.key , first_free_index_reg->name  );		// Store to index reg Z the location of the LCD register
			sprintf_s(clobber_buffer, string_bufer_len, "r%02d", first_free_index_reg->high_reg);		// Store to index reg the location of the LCD register
			printasm(asm_buffer, clobber_buffer , comment_buffer);	// Apparently clobbers filed doesnt know about *H register name

			sprintf_s(asm_buffer, string_bufer_len, "LDI r%02d,0x%2.02x", first_free_index_reg->low_reg, LCD_REGS_BASE_LOW + reg.key);		// Store to index reg the location of the LCD register
			sprintf_s(comment_buffer, string_bufer_len, "Store low byte of address of LCD reg %02d to %c", reg.key, first_free_index_reg->name);		// Store to index reg Z the location of the LCD register
			sprintf_s(clobber_buffer, string_bufer_len, "r%02d", first_free_index_reg->low_reg);		// Store to index reg the location of the LCD register
			printasm(asm_buffer, clobber_buffer, comment_buffer);	// Apparently clobbers filed doesnt know about *H register name

			sprintf_s( reg_access_asm_strings[reg.key] , string_bufer_len, "ST %c,r%%02d" , first_free_index_reg->name );		// Store to index reg X location
			sprintf_s( reg_access_comment_strings[reg.key], string_bufer_len, "%d accesses to R%02d" , reg.count , reg.key );		// Store to index reg X location
			reg_access_cyclecount[reg.key] = 1; // ST only 1 cycle!

			first_free_index_reg->assigned = true;

		}
		else {
					
			sprintf_s( reg_access_asm_strings[reg.key] ,  string_bufer_len, "STS 0x%04X,r%%02d" , (LCD_REGS_BASE_HIGH<<8) + LCD_REGS_BASE_LOW + reg.key );		// // All other registers have to use lowly direct store (2 cycles)
			sprintf_s( reg_access_comment_strings[reg.key], string_bufer_len, "direct store to LCD register %02d", reg.key);		// Store to index reg X location
			reg_access_cyclecount[reg.key] = 2; // STS 2 cycles on XMEGA

		}

	}


	printblankline();

	// Reset back to start
	regs_now = initial_lcd_reg_state;

	// USed for building emmited strings
	string_buffer asm_buffer;
	string_buffer comment_buffer;

	int total_cycle_count = 0;		// Keep track of total cycles to run though the sequence (assming no blocks or banches)

	//sequence_count = 20;

	if (loop) {
		cout << "lcd_optimized_run_" << seq_name << "_loop:" << endl;
	}

	for (int i = 0; i < sequence_count; i++) {

		int step_cycle_count = 0;		// How many cycles in this step? 

		lcd_reg_state regs_next = sequence_of_lcd_reg_states[i];

		printblankline();

		/*
		// Print the new LCD regs values for debugging

		printf("// STEP:%4d - REGS:", i);
		for (uint8_t r = 0; r < LCD_REG_COUNT; r++) {
			printf("%02d:%3d ", r, regs_next.regs[r] );
		}
		printf("\n");
		*/

		sprintf_s(comment_buffer, string_bufer_len, "---- Step %04d (%02d:%02d)", i ,  i/60 , i%60 );
		printcomment(comment_buffer );	

		// Note that we also emit code if i=0 becuase that means this is the inital step so we don't know 
		// what happens to be in the LCD registers at the moment

		// It would really be slightly more efficient to start at 5959 so we could optimize for the case
		// where wer are stepping to the next hour, but only a couple cycles here and this is always safe
		// otherwise we would either have to (1) special case out for when we jump in, or (2) we'd have to flash
		// a 5959 on the screen before the first jump to initial 0000

		if (i == 0) {

			printcomment("We special case step 0 and brute force update all LCD registers since we don't know what they were coming in");
		}

		for (uint8_t r = 0; r < LCD_REG_COUNT; r++) {

			// Only care if (1) new value is set, and new value is different from old value
			// note that this will catch a change from unknown to anything else

			if (regs_next.regs[r].used && (i==0 || (regs_now.regs[r].value != regs_next.regs[r].value )) )  {

				int new_value = regs_next.regs[r].value;		// This is the value we want to store 

				// Look and see if we have this value in a cache register...

				struct assigned_and_matching_value_functor : std::unary_function< avr_reg_and_cost_type , bool>
				{
					assigned_and_matching_value_functor(const int& value) : value(value) {}
					bool operator()(const avr_reg_and_cost_type& arg) const { return arg.assigned && arg.value == value; }
					const int& value;
				};

				int source_reg;		// The AVR register that has the value that we want to store in it (assigned either to a cache or to temp reg

				auto found_cache_reg = std::find_if(avr_reg_table.begin(), avr_reg_table.end(), assigned_and_matching_value_functor( new_value ) );

				if (found_cache_reg != avr_reg_table.end()) {

					// We found a matching value in the table of cache registers that we can use directly

					sprintf_s(comment_buffer, string_bufer_len, "Found value %3d in cache register" , new_value );
					printcomment(comment_buffer);

					source_reg = found_cache_reg->reg;

				} else {

					// This value is not in a cache register , so we need it int the working register
					// and will use it from there

					if (new_value == working_reg_value) {		// No need to load the working_reg with a value if it is already set from last time

						sprintf_s(comment_buffer, string_bufer_len, "Skipped redundant load of value %3d into working register. Wow.", new_value);
						printcomment(comment_buffer);

						//sprintf_s(comment_buffer, string_bufer_len, "Value %3d already in working register at step %4d at %02d:%02d. Wow.", new_value , i , i/60 , i% 60 );
						//printcomment(comment_buffer);

					} else {

						// Need to get the new_value into the working reg

						sprintf_s(asm_buffer, string_bufer_len, "LDI r%02d,0x%2.02x", working_reg, new_value);
						printasm(asm_buffer, "", "Load uncached value into working register");	// Apparently clobber field only likes lower case

						working_reg_value = new_value;

						step_cycle_count += 1;		// LDI = 1 cycle

					}

					source_reg = working_reg;

				}

				sprintf_s(asm_buffer, string_bufer_len, reg_access_asm_strings[r], source_reg );
				printasm(asm_buffer, "", reg_access_comment_strings[r] );

				step_cycle_count += reg_access_cyclecount[r];		// Count how ever many cycles this store took

				regs_now.regs[r] = regs_next.regs[r];

			}

		}

		sprintf_s(comment_buffer, string_bufer_len, "--- Cycles in this step: %d", step_cycle_count);
		printcomment(comment_buffer);

		total_cycle_count += step_cycle_count;

		// Interlock motif

		// Here we have the motif that will sleep until the next second transition
		// It is slightly complicted by the fact that the TSL V5 sometimes has sputious triggers on the
		// the FOUT line due to static electricity so we must interlock on it and test both edges
		// to avoid skipping steps. Hopefully the next version will fix this and we can just use a 
		// signle sleep triggered on the rising FOUT edge. 

		// NOTE THAT THIS HAS A HARDCODED ASSUMPTION THAT FOUT IS ON VPORT2 PIN 2!!!!

		printblankline();
		printasm( interstep_macro , "", "Interstep macro");

		/*
		printf("    asm(\"sleep\");  //\n");
		printf("    asm(\"sleep\");  // while (!PORTB.IN & _BV(2))\n");
		printf("    asm(\"sleep\");  \n");
		printf("    asm(\"sleep\");  // while (PORTB.IN & _BV(2))\n");
		*/

	}

	if (loop) {
		// Jump back to the first step!
		// (We stuck the label in at the top right before the first step)
		sprintf_s(asm_buffer, string_bufer_len, "JMP lcd_optimized_run_%s_loop" , seq_name );
		printasm(asm_buffer, "", "loop was set so back we go");
	}


	cout << endl;
	stack_manager.popall();

	cout << endl;
	sprintf_s(comment_buffer, string_bufer_len, "--- Total display update cycles in sequence: %d", total_cycle_count );
	printcomment(comment_buffer);


	cout << endl; 
	printasm("RET", "", "All done!");


}

void setLCDpixels(lcd_reg_state* lcd_regs, uint8_t place, uint8_t pixelbits) {		// Pixel is a bit set that represents segements A-F on the LCD 

	// Step though all the pixels in the current digit and see which ones are lit
	for (uint8_t p = 0; p < 7; p++) {

		uint8_t target_reg = LCD_REG_OFF(digitmap[place][p].com, digitmap[place][p].seg);

		// We touched this pixel in sewtting this digit. Doesn't matter if it is on or off since
		// it could have been on before we enetered here, and off now so we need to set it back to 0. 

		lcd_regs->regs[target_reg].used = true;

		if ( pixelbits & (1 << p)) {

			// This pixel is lit, so set the bit in the show regs

			lcd_regs->regs[target_reg].value |= (1 << LCD_REG_BIT(digitmap[place][p].com, digitmap[place][p].seg));

			//printf("set place=%d n=%d p=%d\r\n", place, n, p);

		}

	}



}

// paint a number (0-9) into the indicated place (0-11, 0=right) on the LCD
// assumes pixels are off (does not clear any not set pixels).

void setlcdregsfordigit(lcd_reg_state * lcd_regs, uint8_t place, uint8_t n) {

	uint8_t pixelbits = lcd_font_digits[n];

	setLCDpixels(lcd_regs, place, pixelbits);

}


// Emit code to update the LCD
// For an hour starting at 0000 going to 5959
// Overwrites whatever is in the pixels in the rightmost 4 digits
// does not change any other digits

void lcdEmit1hourCode() {

	cout << ".MACRO PAUSE" << endl;
	printcomment("This macro will pause until the next second starts.");
	printcomment("It has hardcoded the VPORT and bit for the FOUT pin.");
	printcomment("Someday we can shrinnk this down to just a SLEEP when");
	printcomment("PCB V6 comes out.");
	printcomment("Interlock on a high-to-low then low-to-high transition on FOUT (1 second)");
	printasm("SLEEP", "", "Wait for any edge interrupt from RX8900");
	printasm("SBIC 0x1a, 2", "", "Skip to next phase if !(VPORT2.IN & 0x04)");
	printasm("RJMP . + 6", "", "...or go back to sleep and wait again");
	printasm("SLEEP", "", "Wait for any edge interrupt from RX8900");
	printasm("SBIS 0x1a, 2", "", "Skip to next phase if (VPORT2.IN & 0x04)");
	printasm("RJMP . + 6", "", "...or go back to sleep and wait again");
	cout << ".ENDM";
	cout << endl;

	// All regs set to untouched, value=0

	lcd_reg_state regs_untouched;

	// Initialize
	for (auto  &reg : regs_untouched.regs) {
		reg.used = false;
		reg.value = 0;
	}

	lcd_reg_state regs_init = regs_untouched;		// We do't know any of the registers when we start

	lcd_reg_state reg_steps[60 * 60];			// 60 seconds * 60 minutes = 1 hour

	int step = 0;

	cout << endl;
	cout << "// Compute steps 0000 - 5959 " << endl;

	for (uint8_t m = 0; m < 60; m++) {

		for (uint8_t s = 0; s < 60; s++) {


			// Initial all regs to unknown. The set functions below check to see if a 
			// reg that wan to update is unknown, and if so they will set it to zero
			// before setting the pixel bits. 

			// This way any regs that are not touched will stay unknown.

			lcd_reg_state lcd_regs = regs_untouched;

			setlcdregsfordigit(&lcd_regs, 0, s % 10);
			setlcdregsfordigit(&lcd_regs, 1, s / 10);
			setlcdregsfordigit(&lcd_regs, 2, m % 10);
			setlcdregsfordigit(&lcd_regs, 3, m / 10);

			// Ok, now the shadow_regs_next have the values that should be in the LCD registers when we are done.


			/*

			// Print the new LCD regs values for debugging

			printf("// STEP:%4d (%02d:%02d) - BITS:" , m*60+s , m, s );
			for (uint8_t r = 0; r < LCD_REG_COUNT; r++) {

				if (lcd_regs.regs[r].touched) {
					for (int b = 0; b < 8; b++) {

						printf("%c", lcd_regs.regs[r].value & (1 << (7 - b)) ? '1' : '0');
					}
					printf(" ");
					//printf("%02d:%3d ", r, lcd_regs.regs[r]);
				}
				else {
					// Not touched
					printf("--------");
				}
			}
			printf("\n");

			*/


			reg_steps[step++] = lcd_regs;
		}

	}

	cout << endl;


	//printf("step=%d\r\n", step);

	emit_code_for_lcd_steps( "hour" , regs_init, reg_steps, step , "PAUSE" , false );



}


void figure8On(lcd_reg_state* lcd_regs, uint8_t d,  uint8_t s ) {

    uint8_t segementBits = figureEightSteps[s];

    setLCDpixels( lcd_regs , d ,  segementBits );
}

// Emit code to update the LCD
// Does a pretty figure eight pattern

void lcdEmitReadyToLaunchPatternCode() {


	cout << ".MACRO HALF_PAUSE_CHECK_TRIGGER" << endl;
	printcomment("This macro will pause until the next second starts.");
	printcomment("It has hardcoded the VPORT and bit for the FOUT pin.");
	printcomment("Someday we can shrinnk this down to just a SLEEP when");
	printcomment("PCB V6 comes out.");
	printcomment("Interlock on a high-to-low then low-to-high transition on FOUT (1 second)");
	printasm("SLEEP", "", "Wait for any edge interrupt from RX8900");
	printasm("SBIC 0x1a, 2", "", "Skip to next phase if !(VPORT2.IN & 0x04)");
	printasm("RJMP . + 6", "", "...or go back to sleep and wait again");
	printasm("SLEEP", "", "Wait for any edge interrupt from RX8900");
	printasm("SBIS 0x1a, 2", "", "Skip to next phase if (VPORT2.IN & 0x04)");
	printasm("RJMP . + 6", "", "...or go back to sleep and wait again");
	cout << ".ENDM";
	cout << endl;


	// All regs set to untouched, value=0

	lcd_reg_state regs_untouched;

	// Initialize
	for (auto& reg : regs_untouched.regs) {
		reg.used = false;
		reg.value = 0;
	}

	lcd_reg_state regs_init = regs_untouched;		// We do't know any of the registers when we start

	lcd_reg_state reg_steps[7];			// 7 segments, 7 steps

	int step = 0;

	cout << endl;
	cout << "// Compute steps" << endl;

	for (uint8_t s = 0; s < 8; s++) {

		// Initial all regs to unknown. The set functions below check to see if a 
		// reg that wan to update is unknown, and if so they will set it to zero
		// before setting the pixel bits. 

		// This way any regs that are not touched will stay unknown.

		lcd_reg_state lcd_regs = regs_untouched;

		// SHow the signature alternatinve figure 8 pattern that TSL fans know and love

		for (uint8_t d = 0; d < 12; ) {
			setLCDpixels(&lcd_regs, d, figureEightSteps[ s ] );
			d++;
			setLCDpixels(&lcd_regs, d, figureEightSteps[ 7 - ((s+3)  % 8 ) ]);
			d++;
		}

		reg_steps[step++] = lcd_regs;
		
	}

	cout << endl;


	emit_code_for_lcd_steps( "ready" ,  regs_init, reg_steps, step , "HALF_PAUSE_CHECK_TRIGGER" , true );

}


// Emit code to update the LCD
// Does a pretty figure eight pattern

void lcdEmitSineWavePatternCode() {

	cout << endl;
	cout << "// This macro will wait until the current LCD frame is completed" << endl;
	cout << "// Note that this could be more power efficient." << endl; 
	cout << ".MACRO PAUSE_UNTIL_LCD_FRAME_COMPLETE" << endl;

	//printasm("1:", "", "");
	printasm("PUSH r18", "", "// Optimized code depends o continuity in all regs so save this");
	printasm("LDS r18,0x0d04", "", "// LCD INTFLAGS – Interrupt Flag register");
	printasm("ANDI r18,0x01", "", "// Check if fram complede bit set");
	printasm("BREQ . - 8", "", "//  Tests the Zero flag (Z) and branches relatively to PC if Z is set.");
	printasm("LDI r18,0x01", "", "Bit 0 – FCIF: LCD Frames Completed Interrupt Flag");
	printasm("STS 0x0d04,r18", "", "// Write a 1 to clear the flag for next time");
	printasm("POP r18", "", "// Optimized code depends o continuity in all regs");

	cout << ".ENDM";
	cout << endl;

	// All regs set to untouched, value=0

	lcd_reg_state regs_untouched;

	// Initialize
	for (auto& reg : regs_untouched.regs) {
		reg.used = false;
		reg.value = 0;
	}

	lcd_reg_state regs_init = regs_untouched;		// We do't know any of the registers when we start

	lcd_reg_state reg_steps[7];			// 7 segments, 7 steps

	int step = 0;

	cout << endl;
	cout << "// Compute steps" << endl;

	for( int pass= 0; pass <  8 ; pass ++ ) {		// We need this many passes to make a smooth transiston between loops

		cout << "// pass " << pass << endl;

		int s = pass;

		// Initial all regs to unknown. The set functions below check to see if a 
		// reg that wan to update is unknown, and if so they will set it to zero
		// before setting the pixel bits. 

		// This way any regs that are not touched will stay unknown.

		lcd_reg_state lcd_regs = regs_untouched;

		for (int d = 0; d < 12; d++) {

			//cout << "// digit=" << d << "s=" << s << endl;

			setLCDpixels(&lcd_regs, d, figureEightSteps[  s % 8 ]);
			s++;
			if (d == 5) s++;		// Skip the visual gap inbetween the LCD modules

		}

		reg_steps[step++] = lcd_regs;

	}

	cout << "// Emitting magic sinewave code now... " << endl;

	cout << endl;

	emit_code_for_lcd_steps("sinewave", regs_init, reg_steps, step, "PAUSE_UNTIL_LCD_FRAME_COMPLETE", false );

//	emit_code_for_lcd_steps("sinewave", regs_init, reg_steps, step, "SLEEP", true);

}




int main() {

	cout << "// DO NOT EDIT!" << endl;
	cout << "// This code was automatically generated by the code2code.cpp program" << endl;
	cout << "// See the LCD-maps.MD file for more info." << endl;
	cout << "" << endl;

	cout << "" << endl;
	cout << ".section    .text    ; Everything in this file is pure code in the TEXT linker section" << endl;

	printblankline();



	lcdEmit1hourCode();
	lcdEmitReadyToLaunchPatternCode();
	lcdEmitSineWavePatternCode();


	cout << ".end" << endl;

	return 0;
}
