// tsl-make-block.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Reads current time GMT and creates an EEPROM bin file to be programmed into a Time Since Launch by CW&T
// https://cwandt.com/products/time-since-launch?variant=12156662513723


#include "pch.h"
#include <iostream>

#include <time.h>
#include <stdio.h>

using namespace std;

uint8_t c2bcd(uint8_t c) {

	uint8_t tens = c / 10;
	uint8_t ones = c - (tens * 10);

	return (tens * 16) + ones;

}

void write_bcd( FILE *f , uint8_t v) {


	uint8_t b = c2bcd(v);

	fputc(b, f);

}

int parse2digitstr(int  *n, const char* s) {

	int tens, ones;
	
	if (!isdigit(*s)) {
		return -1;
	}

	tens = *s - '0';

	s++;

	if (!isdigit(*s)) {
		return -1;
	}

	ones = *s - '0';

	
	*n = (tens * 10) + ones;

	return 0; 

}

void printtm(struct tm* tm) {
	char buffer[26];
	strftime(buffer, 26, "%Y:%m:%d %H:%M:%S", tm);
	std::cout << buffer;		
}

// Returns string of the malformed field, or null if success

const char *parsetimestr(struct tm *tm_out, const char* s) {

	struct tm tm;

	int century, year;

	if (parse2digitstr(&century,s)) return "Bad digit in century";
	if (century < 20 || century> 147 ) return "Century must be 20-147";
	s += 2;

	if (parse2digitstr(&year, s)) return "Bad digit in year";
	s += 2;

	tm.tm_year = (century-19) * 100 + year;		// tm year 0=1900

	if (parse2digitstr(&tm.tm_mon, s)) return "Bad digit in month";
	if ( tm.tm_mon < 1 || tm.tm_mon > 12) return "Month must be 1-12";

	tm.tm_mon -= 1;		//struct tm mon: The number of months since January, in the range 0 to 11.  


	s += 2;
	if (parse2digitstr(&tm.tm_mday, s)) return "Bad digit in day";
	if (tm.tm_mday < 1 || tm.tm_mday > 31) return "Day must be 1-31";

	s += 2;

	if (parse2digitstr(&tm.tm_hour, s)) return "Bad digit in hour";
	if (tm.tm_hour < 0 || tm.tm_hour > 23) return "Hour must be 0-23";

	s += 2;
	if (parse2digitstr(&tm.tm_min, s)) return "Bad digit in min";
	if (tm.tm_min < 0 || tm.tm_min > 59) return "Min must be 0-59";

	s += 2;
	if (parse2digitstr(&tm.tm_sec, s)) return "Bad digit in sec";
	if (tm.tm_sec < 0 || tm.tm_sec > 59) return "Sec must be 0-59";

	s += 2;

	*tm_out = tm;

	return NULL;

}

void writetimeblock(FILE* f, tm* tm_gmt , uint8_t flag ) {

	int y = tm_gmt->tm_year;		// years since 1900

	uint8_t ci = (y - 100) / 50;	// Normalized to 2000 base, find century interlock value. 

	// Start time block
	write_bcd(f, tm_gmt->tm_sec);
	write_bcd(f, tm_gmt->tm_min);
	write_bcd(f, tm_gmt->tm_hour);
	write_bcd(f, 1);					// Weeks. We don't use, but must be a valid power of two 1-64.
	write_bcd(f, tm_gmt->tm_mday);
	write_bcd(f, tm_gmt->tm_mon +1 );				// gmtime() month returned by gmtime is 0-based! But not day?!
	write_bcd(f, y % 100);							// 2 digit year
	write_bcd(f, ci);								// Century intelock 

	// flag
	write_bcd(f, flag  );			// for set means set this time, for trigger means trigger has been pulled
	write_bcd(f, 0);								// Padding
}

int main( int argc , char **argv ) {
	
    std::cout << "tsl-make-block (c)2018 josh.com\n"; 

	if ( argc < 2 ) {
		std::cout << "Usage: tsl-make-block fname [-o offset_secs] [-s YYYYMMDDHHMMSS] [-t YYYYMMDDHHMMSS] [-v]\n";
		std::cout << "Where: fname is the name of the biary EEPROM file to be created\n";
		std::cout << "       offset_secs is number of seconds to add or subtract to current time to set start time\n";
		std::cout << "       times are GMT by convention. If you use offset, current time will convert to GMT\n";
		return 1;
	}

	// Grab time now first

	tm tm_start_gmt;
	memset(&tm_start_gmt, 0xff , sizeof(tm_start_gmt));		// Just use 0xff in the case where this value is not used so they start out and will cause errors.
	bool starttime_set_flag = false;

	tm tm_trigger_gmt;
	memset(&tm_trigger_gmt, 0xff , sizeof(tm_trigger_gmt));		// Just use 0xff in the case where this value is not used so they start out and will cause errors.
	bool triggertime_set_flag = false;

	bool low_voltage_flag = false;

	int arg = 1;

	// Open the output file

	FILE* f;
	#pragma warning(suppress : 4996)
	f = fopen(argv[arg++], "wb");

	while ( arg < argc ) {

		cout << "arg:" << arg << endl;

		if (argv[arg][0] != '-') {

			std::cout << "ERROR: I don't undertsand the argument `" << argv[arg] << "`" << endl;
			return 1;

		}

		switch (argv[arg++][1]) {

			case 'o':  {// Offset

				if (arg >= argc) {

					std::cout << "ERROR: Missing arg for offset." << endl;
					return 1;

				}

				int offset = atoi(argv[arg++]);

				time_t starttime;
				starttime= time(NULL);
				starttime += offset;

				#pragma warning(suppress : 4996)
				tm_start_gmt = *gmtime(&starttime);

				starttime_set_flag = true;

				cout << "Using offset: " << offset << endl;

			
				cout << "BURNTIME:";  // This string is searched for by burnthis.bat so don't change it. 
				printtm(&tm_start_gmt);
				cout << endl;


				break;

			}


			case 's': { // Start time

				if (arg >= argc) {

					std::cout << "ERROR: Missing arg for starttime." << endl;
					return 1;

				}

				const char* time_parse_err = parsetimestr(&tm_start_gmt, argv[arg++]);

				if (time_parse_err) {

					std::cout << "ERROR parsing starttime " << time_parse_err << endl;
					return 1;
				}


				starttime_set_flag = true;

				break;
			}

			case 't': { // Trigger time

				if (arg >= argc) {

					std::cout << "ERROR: Missing arg for triggertime." << endl;
					return 1;

				}

				const char* time_parse_err = parsetimestr(&tm_trigger_gmt, argv[arg++]);

				if (time_parse_err) {

					std::cout << "ERROR parsing trigger" << time_parse_err << endl;
					return 1;

				}

				triggertime_set_flag = true;

				cout << "Using triggertime. " << endl;

				break;
			}

			case 'v': {// Low voltage flag

				low_voltage_flag = true;

				cout << "Using low voltage flag. " << endl;

				break;

			}
		}

	}

	writetimeblock(f, &tm_start_gmt , starttime_set_flag ? 0x00 : 0x01 );		// 0x00=set this time, 0x01=time already set
	writetimeblock(f, &tm_trigger_gmt, triggertime_set_flag ? 0x01: 0x00 );		// 0x00=trigger not pulled, 0x01=trigger pulled

	// low voltage flag 
	write_bcd(f,0);									//  0 indicates that we have not seen a low voltage since inital programming
	write_bcd(f,0);									// Padding

	fclose(f); 

	if (starttime_set_flag) {
		char buffer[26];
		strftime(buffer, 26, "%Y:%m:%d %H:%M:%S", &tm_start_gmt);
		std::cout << "Start time set to:" << buffer << endl;
	}

	if (triggertime_set_flag) {
		char buffer[26];
		strftime(buffer, 26, "%Y:%m:%d %H:%M:%S", &tm_trigger_gmt);
		std::cout << "Trigger time set to:" << buffer << endl;
	}

	if (low_voltage_flag) {

		std::cout << "Low voltage flag set. " << endl;

	}


	return 0;

}
