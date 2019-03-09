// tsl-read-block.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#include <stdio.h>

uint8_t c2bcd(uint8_t c) {

	uint8_t tens = c / 10;
	uint8_t ones = c - (tens * 10);

	return (tens * 16) + ones;

}

uint8_t bcd2c(uint8_t bcd) {

	uint8_t tens = bcd / 16;
	uint8_t ones = bcd - (tens * 16);

	return (tens * 10) + ones;
}

// http://www.trytoprogram.com/c-examples/c-program-to-test-if-a-number-is-a-power-of-2/

int checkPowerofTwo(int x)
{
	//checks whether a number is zero or not
	if (x == 0)
		return 0;

	//true till x is not equal to 1
	while (x != 1)
	{
		//checks whether a number is divisible by 2
		if (x % 2 != 0)
			return 0;
		x /= 2;
	}
	return 1;
}

// Used for reading and writing registers 0-7 to the RX8900.
// These are the registers that hold the time, plus the RAM reg that we can use to put stuff in

typedef  struct {

	uint8_t time_regs[8];

} rx8900_time_regs_block_t;

// Load from buffer, update century interlock if necessary
// Mostly copy/pasted from TSL.c

static void rx8900_print_time_block(rx8900_time_regs_block_t* rx8900_time_regs_block) {

	printf("REGS [n:dec:bcdvalue]:\n");

	for( int j = 0 ; j < 8 ; j++ ) {

		int v = rx8900_time_regs_block->time_regs[j];

		printf("%d:%3d:%2d " , j , v , bcd2c( v )  );

	}

	printf("\n");

	uint8_t s = bcd2c(rx8900_time_regs_block->time_regs[0]);
	uint8_t m = bcd2c(rx8900_time_regs_block->time_regs[1]);
	uint8_t h = bcd2c(rx8900_time_regs_block->time_regs[2]);

	uint8_t w = bcd2c(rx8900_time_regs_block->time_regs[3]);

	uint8_t d = bcd2c(rx8900_time_regs_block->time_regs[4]);
	uint8_t mo = bcd2c(rx8900_time_regs_block->time_regs[5])+1;		// Jan = 0;

	uint8_t y = bcd2c(rx8900_time_regs_block->time_regs[6]);
	uint8_t i = bcd2c(rx8900_time_regs_block->time_regs[7]);     // Century interlock flag

	int year = 2000 + y +  (i / 2);		// We define year 0 as 2000

	if (
		(y >= 50 && !(i & 0x01)) // If the year is 50-99 and the interlock is currently even...
		||                        // ...or...
		(y < 50 && (i & 0x01)) // If the year is 00-49 and the interlock is currently odd...
		) {
		// Increment the century interlock and write back to RTC
		year++;
	}

	printf("%04d/%02d/%02d %02d:%02d:%02d (year=%02d interlock=%02d week=0x%02x)" , year , mo , d , h , m , s , y , i , w );

	if (!checkPowerofTwo(w)) {
		printf(" [Invalid week - must be power of two!!!]");
	};

}

int main(int argc, char** argv)
{
	std::cout << "tsl-read-block (c)2018 josh.com\n";

	if (argc < 2) {
		std::cout << "Usage: tsl-read-block fname \n";
		std::cout << "Where: fname is the name of the biary EEPROM file to be decoded\n";
		return 1;
	}

	// Open the output file

	FILE* f;
	#pragma warning(suppress : 4996)
	f = fopen(argv[1], "rb");

	if (!f) {
		std::cout << "ERROR: Could not open " << argv[1] << endl;
		return 1;
	}

	rx8900_time_regs_block_t starttime_block;

	if (fread(&starttime_block, 1, sizeof(starttime_block), f) != sizeof(starttime_block)) {
		
		cout << "ERROR reading start time block!" << endl; 
		return 1;

	}

	cout << "STARTTIME:" << endl; 
	rx8900_print_time_block(&starttime_block);
	cout << endl;


	uint8_t start_flag;
	if (fread(&start_flag, 1, sizeof(start_flag), f) != sizeof(start_flag)) {

		cout << "ERROR reading start flag!" << endl;
		return 1;

	}

	printf("STARTFLAG: 0x%02x", start_flag);;

	if (start_flag == 0x00) {
		cout << " (Time has has NOT set yet on device)";
	}
	else {
		cout << " (Time HAS been set on device)";
	}
	cout << endl;



	uint8_t start_buffer;		// Skip buffer space
	if (fread(&start_buffer, 1, sizeof(start_buffer), f) != sizeof(start_buffer)) {

		cout << "ERROR reading start buffer byte!" << endl;
		return 1;

	}
	cout << endl;

	rx8900_time_regs_block_t triggertime_block;

	if (fread(&triggertime_block, 1, sizeof(triggertime_block), f) != sizeof(triggertime_block)) {

		cout << "ERROR reading trigger time block!" << endl;
		return 1;

	}

	cout << "TRIGGERTIME:" << endl;
	rx8900_print_time_block(&triggertime_block);
	cout << endl;

	uint8_t trigger_flag;
	if (fread(&trigger_flag, 1, sizeof(trigger_flag), f) != sizeof(trigger_flag)) {

		cout << "ERROR reading start flag!" << endl;
		return 1;

	}

	printf("TRIGGERFLAG: 0x%02x", trigger_flag);;

	if (trigger_flag == 0x00) {
		cout << " (Trigger pin has NOT been pulled yet)";
	}
	else {
		cout << " (Trigger pin HAS been pulled)";
	}
	cout << endl;


}


