// tsl-make-block.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Reads current time GMT and creates an EEPROM bin file to be programmed into a Time Since Launch by CW&T
// https://cwandt.com/products/time-since-launch?variant=12156662513723


#include "pch.h"
#include <iostream>

#include <time.h>
#include <stdio.h>

uint8_t c2bcd(uint8_t c) {

	uint8_t tens = c / 10;
	uint8_t ones = c - (tens * 10);

	return (tens * 16) + ones;

}

void write_bcd( FILE *f , uint8_t v) {


	uint8_t b = c2bcd(v);

	fputc(b, f);

}

int main( int argc , char **argv )
{
    std::cout << "tsl-make-block (c)2018 josh.com\n"; 

	if ( argc != 2 && argc != 3) {

		std::cout << "Usage: tsl-make-block fname [offset_secs]\n";
		std::cout << "Where: fname is the name of the biary EEPROM file to be created\n";
		std::cout << "       offset_secs is optional number of seconds to or subtract to current time\n";
		return 1;
	}

	time_t now;

	now = time(NULL);

	if (argc == 3) {

		int offset = atoi(argv[2]);

		now += offset;

	}
	
	#pragma warning(suppress : 4996)
	tm *tm_gmt = gmtime(&now);;

	FILE *f;

	#pragma warning(suppress : 4996)
	f = fopen(argv[1], "wb");

	int y = tm_gmt->tm_year;		// years since 1900

	uint8_t ci = (y - 100) / 50;	// Normalized to 2000 base, find century interlock value. 


	// Start time block
	write_bcd(f,  tm_gmt->tm_sec);
	write_bcd(f,  tm_gmt->tm_min);
	write_bcd(f, tm_gmt->tm_hour);
	write_bcd(f,                1);					// Weeks. We don't use, but must be a sane value 1-7.
	write_bcd(f, tm_gmt->tm_mday);
	write_bcd(f, tm_gmt->tm_mon);
	write_bcd(f, y % 100 );							// 2 digit year
	write_bcd(f, ci );								// Century intelock 
	
	// Start time flag 
	write_bcd(f,0);									// Indicates that this time has not been written yet
	write_bcd(f,0);									// Padding


	// Trigger time block. Just use start time for now. It will be overritten when trigger pulled. 
	write_bcd(f, tm_gmt->tm_sec);
	write_bcd(f, tm_gmt->tm_min);
	write_bcd(f, tm_gmt->tm_hour);
	write_bcd(f,1);									// Weeks. We don't use, but must be a sane value 1-7.
	write_bcd(f, tm_gmt->tm_mday);
	write_bcd(f, tm_gmt->tm_mon);
	write_bcd(f, tm_gmt->tm_year % 100);			// 2 digit year
	write_bcd(f, (tm_gmt->tm_year - 2000) / 50);								// Century intelock 

	// Trigger time flag 
	write_bcd(f,0);									// 0 indicates that trigger not pulled yet
	write_bcd(f,0);									// Padding


	// low voltage flag 
	write_bcd(f,0);									//  0 indicates that we have not seen a low voltage since inital programming
	write_bcd(f,0);									// Padding


	fclose(f); 


	char buffer[26];
	strftime(buffer, 26, "%Y:%m:%d %H:%M:%S", tm_gmt );
	std::cout << "Start time:" << buffer ;

	return 0;

}
