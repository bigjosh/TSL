void lcd_run_for_an_hour() {
asm("ldi r18,0xff":::"r18");  // Was 00
asm("sts 0x0d12,r18");
asm("ldi r18,0x55":::"r18");  // Was 00
asm("sts 0x0d16,r18");
asm("ldi r18,0xff":::"r18");  // Was 00
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 00
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 0 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x15":::"r18");  // Was 55
asm("sts 0x0d16,r18");
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xd5":::"r18");  // Was 15
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0x95":::"r18");  // Was d5
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 4 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x7f":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 5 
asm("ldi r18,0xd5":::"r18");  // Was 95
asm("sts 0x0d16,r18");
asm("sleep");  // Step 6 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x15":::"r18");  // Was d5
asm("sts 0x0d16,r18");
asm("ldi r18,0xbf":::"r18");  // Was 7f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 7 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xd5":::"r18");  // Was 15
asm("sts 0x0d16,r18");
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 8 
asm("ldi r18,0x95":::"r18");  // Was d5
asm("sts 0x0d16,r18");
asm("sleep");  // Step 9 
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x45":::"r18");  // Was 95
asm("sts 0x0d16,r18");
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 10 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x05":::"r18");  // Was 45
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 11 
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xc5":::"r18");  // Was 05
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 12 
asm("ldi r18,0xef":::"r18");  // Was 6f
asm("sts 0x0d12,r18");
asm("ldi r18,0x85":::"r18");  // Was c5
asm("sts 0x0d16,r18");
asm("sleep");  // Step 13 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 14 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0x6f":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 15 
asm("ldi r18,0xc5":::"r18");  // Was 85
asm("sts 0x0d16,r18");
asm("sleep");  // Step 16 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x05":::"r18");  // Was c5
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was 6f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 17 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xc5":::"r18");  // Was 05
asm("sts 0x0d16,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 18 
asm("ldi r18,0x85":::"r18");  // Was c5
asm("sts 0x0d16,r18");
asm("sleep");  // Step 19 
asm("ldi r18,0xdf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x75":::"r18");  // Was 85
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 20 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x35":::"r18");  // Was 75
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 21 
asm("ldi r18,0x5f":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0xf5":::"r18");  // Was 35
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 22 
asm("ldi r18,0xdf":::"r18");  // Was 5f
asm("sts 0x0d12,r18");
asm("ldi r18,0xb5":::"r18");  // Was f5
asm("sts 0x0d16,r18");
asm("sleep");  // Step 23 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 24 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0x6f":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 25 
asm("ldi r18,0xf5":::"r18");  // Was b5
asm("sts 0x0d16,r18");
asm("sleep");  // Step 26 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x35":::"r18");  // Was f5
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was 6f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 27 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0xf5":::"r18");  // Was 35
asm("sts 0x0d16,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 28 
asm("ldi r18,0xb5":::"r18");  // Was f5
asm("sts 0x0d16,r18");
asm("sleep");  // Step 29 
asm("ldi r18,0xff":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x65":::"r18");  // Was b5
asm("sts 0x0d16,r18");
asm("sleep");  // Step 30 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x25":::"r18");  // Was 65
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 31 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xe5":::"r18");  // Was 25
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 32 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0xa5":::"r18");  // Was e5
asm("sts 0x0d16,r18");
asm("sleep");  // Step 33 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 34 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x6f":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 35 
asm("ldi r18,0xe5":::"r18");  // Was a5
asm("sts 0x0d16,r18");
asm("sleep");  // Step 36 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x25":::"r18");  // Was e5
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was 6f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 37 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xe5":::"r18");  // Was 25
asm("sts 0x0d16,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 38 
asm("ldi r18,0xa5":::"r18");  // Was e5
asm("sts 0x0d16,r18");
asm("sleep");  // Step 39 
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x65":::"r18");  // Was a5
asm("sts 0x0d16,r18");
asm("ldi r18,0xff":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 40 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x25":::"r18");  // Was 65
asm("sts 0x0d16,r18");
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 41 
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xe5":::"r18");  // Was 25
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 42 
asm("ldi r18,0xef":::"r18");  // Was 6f
asm("sts 0x0d12,r18");
asm("ldi r18,0xa5":::"r18");  // Was e5
asm("sts 0x0d16,r18");
asm("sleep");  // Step 43 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 44 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0x7f":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 45 
asm("ldi r18,0xe5":::"r18");  // Was a5
asm("sts 0x0d16,r18");
asm("sleep");  // Step 46 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x25":::"r18");  // Was e5
asm("sts 0x0d16,r18");
asm("ldi r18,0xbf":::"r18");  // Was 7f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 47 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xe5":::"r18");  // Was 25
asm("sts 0x0d16,r18");
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 48 
asm("ldi r18,0xa5":::"r18");  // Was e5
asm("sts 0x0d16,r18");
asm("sleep");  // Step 49 
asm("ldi r18,0xff":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x65":::"r18");  // Was a5
asm("sts 0x0d16,r18");
asm("ldi r18,0xdf":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 50 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x25":::"r18");  // Was 65
asm("sts 0x0d16,r18");
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 51 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xe5":::"r18");  // Was 25
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 52 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0xa5":::"r18");  // Was e5
asm("sts 0x0d16,r18");
asm("sleep");  // Step 53 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 54 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x5f":::"r18");  // Was df
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 55 
asm("ldi r18,0xe5":::"r18");  // Was a5
asm("sts 0x0d16,r18");
asm("sleep");  // Step 56 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x25":::"r18");  // Was e5
asm("sts 0x0d16,r18");
asm("ldi r18,0x9f":::"r18");  // Was 5f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 57 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xe5":::"r18");  // Was 25
asm("sts 0x0d16,r18");
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 58 
asm("ldi r18,0xa5":::"r18");  // Was e5
asm("sts 0x0d16,r18");
asm("sleep");  // Step 59 
asm("ldi r18,0xfb":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x51":::"r18");  // Was a5
asm("sts 0x0d16,r18");
asm("ldi r18,0xfb":::"r18");  // Was df
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 60 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x11":::"r18");  // Was 51
asm("sts 0x0d16,r18");
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 61 
asm("ldi r18,0x7b":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xd1":::"r18");  // Was 11
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 62 
asm("ldi r18,0xfb":::"r18");  // Was 7b
asm("sts 0x0d12,r18");
asm("ldi r18,0x91":::"r18");  // Was d1
asm("sts 0x0d16,r18");
asm("sleep");  // Step 63 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 64 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0x7b":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 65 
asm("ldi r18,0xd1":::"r18");  // Was 91
asm("sts 0x0d16,r18");
asm("sleep");  // Step 66 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x11":::"r18");  // Was d1
asm("sts 0x0d16,r18");
asm("ldi r18,0xbb":::"r18");  // Was 7b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 67 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xd1":::"r18");  // Was 11
asm("sts 0x0d16,r18");
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 68 
asm("ldi r18,0x91":::"r18");  // Was d1
asm("sts 0x0d16,r18");
asm("sleep");  // Step 69 
asm("ldi r18,0xeb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x41":::"r18");  // Was 91
asm("sts 0x0d16,r18");
asm("ldi r18,0xeb":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x82":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 70 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x01":::"r18");  // Was 41
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x02":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 71 
asm("ldi r18,0x6b":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0xc1":::"r18");  // Was 01
asm("sts 0x0d16,r18");
asm("ldi r18,0x82":::"r18");  // Was 02
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 72 
asm("ldi r18,0xeb":::"r18");  // Was 6b
asm("sts 0x0d12,r18");
asm("ldi r18,0x81":::"r18");  // Was c1
asm("sts 0x0d16,r18");
asm("sleep");  // Step 73 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("ldi r18,0x02":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 74 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0x6b":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x82":::"r18");  // Was 02
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 75 
asm("ldi r18,0xc1":::"r18");  // Was 81
asm("sts 0x0d16,r18");
asm("sleep");  // Step 76 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x01":::"r18");  // Was c1
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was 6b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 77 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0xc1":::"r18");  // Was 01
asm("sts 0x0d16,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 78 
asm("ldi r18,0x81":::"r18");  // Was c1
asm("sts 0x0d16,r18");
asm("sleep");  // Step 79 
asm("ldi r18,0xdb":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x71":::"r18");  // Was 81
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 80 
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d12,r18");
asm("ldi r18,0x31":::"r18");  // Was 71
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 81 
asm("ldi r18,0x5b":::"r18");  // Was 9b
asm("sts 0x0d12,r18");
asm("ldi r18,0xf1":::"r18");  // Was 31
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 82 
asm("ldi r18,0xdb":::"r18");  // Was 5b
asm("sts 0x0d12,r18");
asm("ldi r18,0xb1":::"r18");  // Was f1
asm("sts 0x0d16,r18");
asm("sleep");  // Step 83 
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 84 
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d12,r18");
asm("ldi r18,0x6b":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 85 
asm("ldi r18,0xf1":::"r18");  // Was b1
asm("sts 0x0d16,r18");
asm("sleep");  // Step 86 
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d12,r18");
asm("ldi r18,0x31":::"r18");  // Was f1
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was 6b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 87 
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d12,r18");
asm("ldi r18,0xf1":::"r18");  // Was 31
asm("sts 0x0d16,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 88 
asm("ldi r18,0xb1":::"r18");  // Was f1
asm("sts 0x0d16,r18");
asm("sleep");  // Step 89 
asm("ldi r18,0xfb":::"r18");  // Was db
asm("sts 0x0d12,r18");
asm("ldi r18,0x61":::"r18");  // Was b1
asm("sts 0x0d16,r18");
asm("sleep");  // Step 90 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x21":::"r18");  // Was 61
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 91 
asm("ldi r18,0x7b":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xe1":::"r18");  // Was 21
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 92 
asm("ldi r18,0xfb":::"r18");  // Was 7b
asm("sts 0x0d12,r18");
asm("ldi r18,0xa1":::"r18");  // Was e1
asm("sts 0x0d16,r18");
asm("sleep");  // Step 93 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 94 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0x6b":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 95 
asm("ldi r18,0xe1":::"r18");  // Was a1
asm("sts 0x0d16,r18");
asm("sleep");  // Step 96 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x21":::"r18");  // Was e1
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was 6b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 97 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xe1":::"r18");  // Was 21
asm("sts 0x0d16,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 98 
asm("ldi r18,0xa1":::"r18");  // Was e1
asm("sts 0x0d16,r18");
asm("sleep");  // Step 99 
asm("ldi r18,0xeb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x61":::"r18");  // Was a1
asm("sts 0x0d16,r18");
asm("ldi r18,0xfb":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x82":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 100 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x21":::"r18");  // Was 61
asm("sts 0x0d16,r18");
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x02":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 101 
asm("ldi r18,0x6b":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0xe1":::"r18");  // Was 21
asm("sts 0x0d16,r18");
asm("ldi r18,0x82":::"r18");  // Was 02
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 102 
asm("ldi r18,0xeb":::"r18");  // Was 6b
asm("sts 0x0d12,r18");
asm("ldi r18,0xa1":::"r18");  // Was e1
asm("sts 0x0d16,r18");
asm("sleep");  // Step 103 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x02":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 104 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0x7b":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x82":::"r18");  // Was 02
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 105 
asm("ldi r18,0xe1":::"r18");  // Was a1
asm("sts 0x0d16,r18");
asm("sleep");  // Step 106 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x21":::"r18");  // Was e1
asm("sts 0x0d16,r18");
asm("ldi r18,0xbb":::"r18");  // Was 7b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 107 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0xe1":::"r18");  // Was 21
asm("sts 0x0d16,r18");
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 108 
asm("ldi r18,0xa1":::"r18");  // Was e1
asm("sts 0x0d16,r18");
asm("sleep");  // Step 109 
asm("ldi r18,0xfb":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x61":::"r18");  // Was a1
asm("sts 0x0d16,r18");
asm("ldi r18,0xdb":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 110 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x21":::"r18");  // Was 61
asm("sts 0x0d16,r18");
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 111 
asm("ldi r18,0x7b":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xe1":::"r18");  // Was 21
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 112 
asm("ldi r18,0xfb":::"r18");  // Was 7b
asm("sts 0x0d12,r18");
asm("ldi r18,0xa1":::"r18");  // Was e1
asm("sts 0x0d16,r18");
asm("sleep");  // Step 113 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 114 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0x5b":::"r18");  // Was db
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 115 
asm("ldi r18,0xe1":::"r18");  // Was a1
asm("sts 0x0d16,r18");
asm("sleep");  // Step 116 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x21":::"r18");  // Was e1
asm("sts 0x0d16,r18");
asm("ldi r18,0x9b":::"r18");  // Was 5b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 117 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xe1":::"r18");  // Was 21
asm("sts 0x0d16,r18");
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 118 
asm("ldi r18,0xa1":::"r18");  // Was e1
asm("sts 0x0d16,r18");
asm("sleep");  // Step 119 
asm("ldi r18,0xf7":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x5d":::"r18");  // Was a1
asm("sts 0x0d16,r18");
asm("ldi r18,0xfb":::"r18");  // Was db
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 120 
asm("ldi r18,0xb7":::"r18");  // Was f7
asm("sts 0x0d12,r18");
asm("ldi r18,0x1d":::"r18");  // Was 5d
asm("sts 0x0d16,r18");
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 121 
asm("ldi r18,0x77":::"r18");  // Was b7
asm("sts 0x0d12,r18");
asm("ldi r18,0xdd":::"r18");  // Was 1d
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 122 
asm("ldi r18,0xf7":::"r18");  // Was 77
asm("sts 0x0d12,r18");
asm("ldi r18,0x9d":::"r18");  // Was dd
asm("sts 0x0d16,r18");
asm("sleep");  // Step 123 
asm("ldi r18,0xb7":::"r18");  // Was f7
asm("sts 0x0d12,r18");
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 124 
asm("ldi r18,0xf7":::"r18");  // Was b7
asm("sts 0x0d12,r18");
asm("ldi r18,0x7b":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 125 
asm("ldi r18,0xdd":::"r18");  // Was 9d
asm("sts 0x0d16,r18");
asm("sleep");  // Step 126 
asm("ldi r18,0xb7":::"r18");  // Was f7
asm("sts 0x0d12,r18");
asm("ldi r18,0x1d":::"r18");  // Was dd
asm("sts 0x0d16,r18");
asm("ldi r18,0xbb":::"r18");  // Was 7b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 127 
asm("ldi r18,0xf7":::"r18");  // Was b7
asm("sts 0x0d12,r18");
asm("ldi r18,0xdd":::"r18");  // Was 1d
asm("sts 0x0d16,r18");
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 128 
asm("ldi r18,0x9d":::"r18");  // Was dd
asm("sts 0x0d16,r18");
asm("sleep");  // Step 129 
asm("ldi r18,0xe7":::"r18");  // Was f7
asm("sts 0x0d12,r18");
asm("ldi r18,0x4d":::"r18");  // Was 9d
asm("sts 0x0d16,r18");
asm("ldi r18,0xeb":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 130 
asm("ldi r18,0xa7":::"r18");  // Was e7
asm("sts 0x0d12,r18");
asm("ldi r18,0x0d":::"r18");  // Was 4d
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 131 
asm("ldi r18,0x67":::"r18");  // Was a7
asm("sts 0x0d12,r18");
asm("ldi r18,0xcd":::"r18");  // Was 0d
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 132 
asm("ldi r18,0xe7":::"r18");  // Was 67
asm("sts 0x0d12,r18");
asm("ldi r18,0x8d":::"r18");  // Was cd
asm("sts 0x0d16,r18");
asm("sleep");  // Step 133 
asm("ldi r18,0xa7":::"r18");  // Was e7
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 134 
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d12,r18");
asm("ldi r18,0x6b":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 135 
asm("ldi r18,0xcd":::"r18");  // Was 8d
asm("sts 0x0d16,r18");
asm("sleep");  // Step 136 
asm("ldi r18,0xa7":::"r18");  // Was e7
asm("sts 0x0d12,r18");
asm("ldi r18,0x0d":::"r18");  // Was cd
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was 6b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 137 
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d12,r18");
asm("ldi r18,0xcd":::"r18");  // Was 0d
asm("sts 0x0d16,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 138 
asm("ldi r18,0x8d":::"r18");  // Was cd
asm("sts 0x0d16,r18");
asm("sleep");  // Step 139 
asm("ldi r18,0xd7":::"r18");  // Was e7
asm("sts 0x0d12,r18");
asm("ldi r18,0x7d":::"r18");  // Was 8d
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 140 
asm("ldi r18,0x97":::"r18");  // Was d7
asm("sts 0x0d12,r18");
asm("ldi r18,0x3d":::"r18");  // Was 7d
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 141 
asm("ldi r18,0x57":::"r18");  // Was 97
asm("sts 0x0d12,r18");
asm("ldi r18,0xfd":::"r18");  // Was 3d
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 142 
asm("ldi r18,0xd7":::"r18");  // Was 57
asm("sts 0x0d12,r18");
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d16,r18");
asm("sleep");  // Step 143 
asm("ldi r18,0x97":::"r18");  // Was d7
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 144 
asm("ldi r18,0xd7":::"r18");  // Was 97
asm("sts 0x0d12,r18");
asm("ldi r18,0x6b":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 145 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d16,r18");
asm("sleep");  // Step 146 
asm("ldi r18,0x97":::"r18");  // Was d7
asm("sts 0x0d12,r18");
asm("ldi r18,0x3d":::"r18");  // Was fd
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was 6b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 147 
asm("ldi r18,0xd7":::"r18");  // Was 97
asm("sts 0x0d12,r18");
asm("ldi r18,0xfd":::"r18");  // Was 3d
asm("sts 0x0d16,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 148 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d16,r18");
asm("sleep");  // Step 149 
asm("ldi r18,0xf7":::"r18");  // Was d7
asm("sts 0x0d12,r18");
asm("ldi r18,0x6d":::"r18");  // Was bd
asm("sts 0x0d16,r18");
asm("sleep");  // Step 150 
asm("ldi r18,0xb7":::"r18");  // Was f7
asm("sts 0x0d12,r18");
asm("ldi r18,0x2d":::"r18");  // Was 6d
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 151 
asm("ldi r18,0x77":::"r18");  // Was b7
asm("sts 0x0d12,r18");
asm("ldi r18,0xed":::"r18");  // Was 2d
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 152 
asm("ldi r18,0xf7":::"r18");  // Was 77
asm("sts 0x0d12,r18");
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d16,r18");
asm("sleep");  // Step 153 
asm("ldi r18,0xb7":::"r18");  // Was f7
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 154 
asm("ldi r18,0xf7":::"r18");  // Was b7
asm("sts 0x0d12,r18");
asm("ldi r18,0x6b":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 155 
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d16,r18");
asm("sleep");  // Step 156 
asm("ldi r18,0xb7":::"r18");  // Was f7
asm("sts 0x0d12,r18");
asm("ldi r18,0x2d":::"r18");  // Was ed
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was 6b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 157 
asm("ldi r18,0xf7":::"r18");  // Was b7
asm("sts 0x0d12,r18");
asm("ldi r18,0xed":::"r18");  // Was 2d
asm("sts 0x0d16,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 158 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d16,r18");
asm("sleep");  // Step 159 
asm("ldi r18,0xe7":::"r18");  // Was f7
asm("sts 0x0d12,r18");
asm("ldi r18,0x6d":::"r18");  // Was ad
asm("sts 0x0d16,r18");
asm("ldi r18,0xfb":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 160 
asm("ldi r18,0xa7":::"r18");  // Was e7
asm("sts 0x0d12,r18");
asm("ldi r18,0x2d":::"r18");  // Was 6d
asm("sts 0x0d16,r18");
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 161 
asm("ldi r18,0x67":::"r18");  // Was a7
asm("sts 0x0d12,r18");
asm("ldi r18,0xed":::"r18");  // Was 2d
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 162 
asm("ldi r18,0xe7":::"r18");  // Was 67
asm("sts 0x0d12,r18");
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d16,r18");
asm("sleep");  // Step 163 
asm("ldi r18,0xa7":::"r18");  // Was e7
asm("sts 0x0d12,r18");
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 164 
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d12,r18");
asm("ldi r18,0x7b":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 165 
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d16,r18");
asm("sleep");  // Step 166 
asm("ldi r18,0xa7":::"r18");  // Was e7
asm("sts 0x0d12,r18");
asm("ldi r18,0x2d":::"r18");  // Was ed
asm("sts 0x0d16,r18");
asm("ldi r18,0xbb":::"r18");  // Was 7b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 167 
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d12,r18");
asm("ldi r18,0xed":::"r18");  // Was 2d
asm("sts 0x0d16,r18");
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 168 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d16,r18");
asm("sleep");  // Step 169 
asm("ldi r18,0xf7":::"r18");  // Was e7
asm("sts 0x0d12,r18");
asm("ldi r18,0x6d":::"r18");  // Was ad
asm("sts 0x0d16,r18");
asm("ldi r18,0xdb":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 170 
asm("ldi r18,0xb7":::"r18");  // Was f7
asm("sts 0x0d12,r18");
asm("ldi r18,0x2d":::"r18");  // Was 6d
asm("sts 0x0d16,r18");
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 171 
asm("ldi r18,0x77":::"r18");  // Was b7
asm("sts 0x0d12,r18");
asm("ldi r18,0xed":::"r18");  // Was 2d
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 172 
asm("ldi r18,0xf7":::"r18");  // Was 77
asm("sts 0x0d12,r18");
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d16,r18");
asm("sleep");  // Step 173 
asm("ldi r18,0xb7":::"r18");  // Was f7
asm("sts 0x0d12,r18");
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 174 
asm("ldi r18,0xf7":::"r18");  // Was b7
asm("sts 0x0d12,r18");
asm("ldi r18,0x5b":::"r18");  // Was db
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 175 
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d16,r18");
asm("sleep");  // Step 176 
asm("ldi r18,0xb7":::"r18");  // Was f7
asm("sts 0x0d12,r18");
asm("ldi r18,0x2d":::"r18");  // Was ed
asm("sts 0x0d16,r18");
asm("ldi r18,0x9b":::"r18");  // Was 5b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 177 
asm("ldi r18,0xf7":::"r18");  // Was b7
asm("sts 0x0d12,r18");
asm("ldi r18,0xed":::"r18");  // Was 2d
asm("sts 0x0d16,r18");
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 178 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d16,r18");
asm("sleep");  // Step 179 
asm("ldi r18,0xff":::"r18");  // Was f7
asm("sts 0x0d12,r18");
asm("ldi r18,0x59":::"r18");  // Was ad
asm("sts 0x0d16,r18");
asm("ldi r18,0xfb":::"r18");  // Was db
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 180 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x19":::"r18");  // Was 59
asm("sts 0x0d16,r18");
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 181 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xd9":::"r18");  // Was 19
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 182 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0x99":::"r18");  // Was d9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 183 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 184 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x7b":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 185 
asm("ldi r18,0xd9":::"r18");  // Was 99
asm("sts 0x0d16,r18");
asm("sleep");  // Step 186 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x19":::"r18");  // Was d9
asm("sts 0x0d16,r18");
asm("ldi r18,0xbb":::"r18");  // Was 7b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 187 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xd9":::"r18");  // Was 19
asm("sts 0x0d16,r18");
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 188 
asm("ldi r18,0x99":::"r18");  // Was d9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 189 
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x49":::"r18");  // Was 99
asm("sts 0x0d16,r18");
asm("ldi r18,0xeb":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 190 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x09":::"r18");  // Was 49
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 191 
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xc9":::"r18");  // Was 09
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 192 
asm("ldi r18,0xef":::"r18");  // Was 6f
asm("sts 0x0d12,r18");
asm("ldi r18,0x89":::"r18");  // Was c9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 193 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 194 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0x6b":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 195 
asm("ldi r18,0xc9":::"r18");  // Was 89
asm("sts 0x0d16,r18");
asm("sleep");  // Step 196 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x09":::"r18");  // Was c9
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was 6b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 197 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xc9":::"r18");  // Was 09
asm("sts 0x0d16,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 198 
asm("ldi r18,0x89":::"r18");  // Was c9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 199 
asm("ldi r18,0xdf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x79":::"r18");  // Was 89
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 200 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x39":::"r18");  // Was 79
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 201 
asm("ldi r18,0x5f":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0xf9":::"r18");  // Was 39
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 202 
asm("ldi r18,0xdf":::"r18");  // Was 5f
asm("sts 0x0d12,r18");
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 203 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 204 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0x6b":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 205 
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 206 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x39":::"r18");  // Was f9
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was 6b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 207 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0xf9":::"r18");  // Was 39
asm("sts 0x0d16,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 208 
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 209 
asm("ldi r18,0xff":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x69":::"r18");  // Was b9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 210 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x29":::"r18");  // Was 69
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 211 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xe9":::"r18");  // Was 29
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 212 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 213 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 214 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x6b":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 215 
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 216 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x29":::"r18");  // Was e9
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was 6b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 217 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xe9":::"r18");  // Was 29
asm("sts 0x0d16,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 218 
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 219 
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x69":::"r18");  // Was a9
asm("sts 0x0d16,r18");
asm("ldi r18,0xfb":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 220 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x29":::"r18");  // Was 69
asm("sts 0x0d16,r18");
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 221 
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xe9":::"r18");  // Was 29
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 222 
asm("ldi r18,0xef":::"r18");  // Was 6f
asm("sts 0x0d12,r18");
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 223 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 224 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0x7b":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 225 
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 226 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x29":::"r18");  // Was e9
asm("sts 0x0d16,r18");
asm("ldi r18,0xbb":::"r18");  // Was 7b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 227 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xe9":::"r18");  // Was 29
asm("sts 0x0d16,r18");
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 228 
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 229 
asm("ldi r18,0xff":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x69":::"r18");  // Was a9
asm("sts 0x0d16,r18");
asm("ldi r18,0xdb":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 230 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x29":::"r18");  // Was 69
asm("sts 0x0d16,r18");
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 231 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xe9":::"r18");  // Was 29
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 232 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 233 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 234 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x5b":::"r18");  // Was db
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 235 
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 236 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x29":::"r18");  // Was e9
asm("sts 0x0d16,r18");
asm("ldi r18,0x9b":::"r18");  // Was 5b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 237 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xe9":::"r18");  // Was 29
asm("sts 0x0d16,r18");
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 238 
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 239 
asm("ldi r18,0xfb":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x59":::"r18");  // Was a9
asm("sts 0x0d16,r18");
asm("ldi r18,0xff":::"r18");  // Was db
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 240 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x19":::"r18");  // Was 59
asm("sts 0x0d16,r18");
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 241 
asm("ldi r18,0x7b":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xd9":::"r18");  // Was 19
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 242 
asm("ldi r18,0xfb":::"r18");  // Was 7b
asm("sts 0x0d12,r18");
asm("ldi r18,0x99":::"r18");  // Was d9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 243 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 244 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0x7f":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 245 
asm("ldi r18,0xd9":::"r18");  // Was 99
asm("sts 0x0d16,r18");
asm("sleep");  // Step 246 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x19":::"r18");  // Was d9
asm("sts 0x0d16,r18");
asm("ldi r18,0xbf":::"r18");  // Was 7f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 247 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xd9":::"r18");  // Was 19
asm("sts 0x0d16,r18");
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 248 
asm("ldi r18,0x99":::"r18");  // Was d9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 249 
asm("ldi r18,0xeb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x49":::"r18");  // Was 99
asm("sts 0x0d16,r18");
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0x82":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 250 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x09":::"r18");  // Was 49
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x02":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 251 
asm("ldi r18,0x6b":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0xc9":::"r18");  // Was 09
asm("sts 0x0d16,r18");
asm("ldi r18,0x82":::"r18");  // Was 02
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 252 
asm("ldi r18,0xeb":::"r18");  // Was 6b
asm("sts 0x0d12,r18");
asm("ldi r18,0x89":::"r18");  // Was c9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 253 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("ldi r18,0x02":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 254 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0x6f":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x82":::"r18");  // Was 02
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 255 
asm("ldi r18,0xc9":::"r18");  // Was 89
asm("sts 0x0d16,r18");
asm("sleep");  // Step 256 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x09":::"r18");  // Was c9
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was 6f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 257 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0xc9":::"r18");  // Was 09
asm("sts 0x0d16,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 258 
asm("ldi r18,0x89":::"r18");  // Was c9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 259 
asm("ldi r18,0xdb":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x79":::"r18");  // Was 89
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 260 
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d12,r18");
asm("ldi r18,0x39":::"r18");  // Was 79
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 261 
asm("ldi r18,0x5b":::"r18");  // Was 9b
asm("sts 0x0d12,r18");
asm("ldi r18,0xf9":::"r18");  // Was 39
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 262 
asm("ldi r18,0xdb":::"r18");  // Was 5b
asm("sts 0x0d12,r18");
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 263 
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 264 
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d12,r18");
asm("ldi r18,0x6f":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 265 
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 266 
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d12,r18");
asm("ldi r18,0x39":::"r18");  // Was f9
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was 6f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 267 
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d12,r18");
asm("ldi r18,0xf9":::"r18");  // Was 39
asm("sts 0x0d16,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 268 
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 269 
asm("ldi r18,0xfb":::"r18");  // Was db
asm("sts 0x0d12,r18");
asm("ldi r18,0x69":::"r18");  // Was b9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 270 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x29":::"r18");  // Was 69
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 271 
asm("ldi r18,0x7b":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xe9":::"r18");  // Was 29
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 272 
asm("ldi r18,0xfb":::"r18");  // Was 7b
asm("sts 0x0d12,r18");
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 273 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 274 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0x6f":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 275 
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 276 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x29":::"r18");  // Was e9
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was 6f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 277 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xe9":::"r18");  // Was 29
asm("sts 0x0d16,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 278 
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 279 
asm("ldi r18,0xeb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x69":::"r18");  // Was a9
asm("sts 0x0d16,r18");
asm("ldi r18,0xff":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x82":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 280 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x29":::"r18");  // Was 69
asm("sts 0x0d16,r18");
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0x02":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 281 
asm("ldi r18,0x6b":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0xe9":::"r18");  // Was 29
asm("sts 0x0d16,r18");
asm("ldi r18,0x82":::"r18");  // Was 02
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 282 
asm("ldi r18,0xeb":::"r18");  // Was 6b
asm("sts 0x0d12,r18");
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 283 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d1a,r18");
asm("ldi r18,0x02":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 284 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0x7f":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0x82":::"r18");  // Was 02
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 285 
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 286 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x29":::"r18");  // Was e9
asm("sts 0x0d16,r18");
asm("ldi r18,0xbf":::"r18");  // Was 7f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 287 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0xe9":::"r18");  // Was 29
asm("sts 0x0d16,r18");
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 288 
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 289 
asm("ldi r18,0xfb":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x69":::"r18");  // Was a9
asm("sts 0x0d16,r18");
asm("ldi r18,0xdf":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 290 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x29":::"r18");  // Was 69
asm("sts 0x0d16,r18");
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 291 
asm("ldi r18,0x7b":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xe9":::"r18");  // Was 29
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 292 
asm("ldi r18,0xfb":::"r18");  // Was 7b
asm("sts 0x0d12,r18");
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 293 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 294 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0x5f":::"r18");  // Was df
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 295 
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 296 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x29":::"r18");  // Was e9
asm("sts 0x0d16,r18");
asm("ldi r18,0x9f":::"r18");  // Was 5f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 297 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xe9":::"r18");  // Was 29
asm("sts 0x0d16,r18");
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 298 
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 299 
asm("ldi r18,0xff":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x59":::"r18");  // Was a9
asm("sts 0x0d16,r18");
asm("ldi r18,0xf7":::"r18");  // Was df
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 300 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x19":::"r18");  // Was 59
asm("sts 0x0d16,r18");
asm("ldi r18,0xb7":::"r18");  // Was f7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 301 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xd9":::"r18");  // Was 19
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 302 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0x99":::"r18");  // Was d9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 303 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xf7":::"r18");  // Was b7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 304 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x77":::"r18");  // Was f7
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 305 
asm("ldi r18,0xd9":::"r18");  // Was 99
asm("sts 0x0d16,r18");
asm("sleep");  // Step 306 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x19":::"r18");  // Was d9
asm("sts 0x0d16,r18");
asm("ldi r18,0xb7":::"r18");  // Was 77
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 307 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xd9":::"r18");  // Was 19
asm("sts 0x0d16,r18");
asm("ldi r18,0xf7":::"r18");  // Was b7
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 308 
asm("ldi r18,0x99":::"r18");  // Was d9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 309 
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x49":::"r18");  // Was 99
asm("sts 0x0d16,r18");
asm("ldi r18,0xe7":::"r18");  // Was f7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 310 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x09":::"r18");  // Was 49
asm("sts 0x0d16,r18");
asm("ldi r18,0xa7":::"r18");  // Was e7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 311 
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xc9":::"r18");  // Was 09
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 312 
asm("ldi r18,0xef":::"r18");  // Was 6f
asm("sts 0x0d12,r18");
asm("ldi r18,0x89":::"r18");  // Was c9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 313 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 314 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0x67":::"r18");  // Was e7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 315 
asm("ldi r18,0xc9":::"r18");  // Was 89
asm("sts 0x0d16,r18");
asm("sleep");  // Step 316 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x09":::"r18");  // Was c9
asm("sts 0x0d16,r18");
asm("ldi r18,0xa7":::"r18");  // Was 67
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 317 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xc9":::"r18");  // Was 09
asm("sts 0x0d16,r18");
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 318 
asm("ldi r18,0x89":::"r18");  // Was c9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 319 
asm("ldi r18,0xdf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x79":::"r18");  // Was 89
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 320 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x39":::"r18");  // Was 79
asm("sts 0x0d16,r18");
asm("ldi r18,0xa7":::"r18");  // Was e7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 321 
asm("ldi r18,0x5f":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0xf9":::"r18");  // Was 39
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 322 
asm("ldi r18,0xdf":::"r18");  // Was 5f
asm("sts 0x0d12,r18");
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 323 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 324 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0x67":::"r18");  // Was e7
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 325 
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 326 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x39":::"r18");  // Was f9
asm("sts 0x0d16,r18");
asm("ldi r18,0xa7":::"r18");  // Was 67
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 327 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0xf9":::"r18");  // Was 39
asm("sts 0x0d16,r18");
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 328 
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 329 
asm("ldi r18,0xff":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x69":::"r18");  // Was b9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 330 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x29":::"r18");  // Was 69
asm("sts 0x0d16,r18");
asm("ldi r18,0xa7":::"r18");  // Was e7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 331 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xe9":::"r18");  // Was 29
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 332 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 333 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 334 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x67":::"r18");  // Was e7
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 335 
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 336 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x29":::"r18");  // Was e9
asm("sts 0x0d16,r18");
asm("ldi r18,0xa7":::"r18");  // Was 67
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 337 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xe9":::"r18");  // Was 29
asm("sts 0x0d16,r18");
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 338 
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 339 
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x69":::"r18");  // Was a9
asm("sts 0x0d16,r18");
asm("ldi r18,0xf7":::"r18");  // Was e7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 340 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x29":::"r18");  // Was 69
asm("sts 0x0d16,r18");
asm("ldi r18,0xb7":::"r18");  // Was f7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 341 
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xe9":::"r18");  // Was 29
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 342 
asm("ldi r18,0xef":::"r18");  // Was 6f
asm("sts 0x0d12,r18");
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 343 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0xf7":::"r18");  // Was b7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 344 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0x77":::"r18");  // Was f7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 345 
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 346 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x29":::"r18");  // Was e9
asm("sts 0x0d16,r18");
asm("ldi r18,0xb7":::"r18");  // Was 77
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 347 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xe9":::"r18");  // Was 29
asm("sts 0x0d16,r18");
asm("ldi r18,0xf7":::"r18");  // Was b7
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 348 
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 349 
asm("ldi r18,0xff":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x69":::"r18");  // Was a9
asm("sts 0x0d16,r18");
asm("ldi r18,0xd7":::"r18");  // Was f7
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 350 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x29":::"r18");  // Was 69
asm("sts 0x0d16,r18");
asm("ldi r18,0x97":::"r18");  // Was d7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 351 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xe9":::"r18");  // Was 29
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 352 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 353 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xd7":::"r18");  // Was 97
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 354 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x57":::"r18");  // Was d7
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 355 
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 356 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x29":::"r18");  // Was e9
asm("sts 0x0d16,r18");
asm("ldi r18,0x97":::"r18");  // Was 57
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 357 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xe9":::"r18");  // Was 29
asm("sts 0x0d16,r18");
asm("ldi r18,0xd7":::"r18");  // Was 97
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 358 
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 359 
asm("ldi r18,0x5d":::"r18");  // Was a9
asm("sts 0x0d16,r18");
asm("ldi r18,0xf7":::"r18");  // Was d7
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 360 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x1d":::"r18");  // Was 5d
asm("sts 0x0d16,r18");
asm("ldi r18,0xb7":::"r18");  // Was f7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 361 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xdd":::"r18");  // Was 1d
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 362 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0x9d":::"r18");  // Was dd
asm("sts 0x0d16,r18");
asm("sleep");  // Step 363 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xf7":::"r18");  // Was b7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 364 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x77":::"r18");  // Was f7
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 365 
asm("ldi r18,0xdd":::"r18");  // Was 9d
asm("sts 0x0d16,r18");
asm("sleep");  // Step 366 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x1d":::"r18");  // Was dd
asm("sts 0x0d16,r18");
asm("ldi r18,0xb7":::"r18");  // Was 77
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 367 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xdd":::"r18");  // Was 1d
asm("sts 0x0d16,r18");
asm("ldi r18,0xf7":::"r18");  // Was b7
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 368 
asm("ldi r18,0x9d":::"r18");  // Was dd
asm("sts 0x0d16,r18");
asm("sleep");  // Step 369 
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x4d":::"r18");  // Was 9d
asm("sts 0x0d16,r18");
asm("ldi r18,0xe7":::"r18");  // Was f7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 370 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x0d":::"r18");  // Was 4d
asm("sts 0x0d16,r18");
asm("ldi r18,0xa7":::"r18");  // Was e7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 371 
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xcd":::"r18");  // Was 0d
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 372 
asm("ldi r18,0xef":::"r18");  // Was 6f
asm("sts 0x0d12,r18");
asm("ldi r18,0x8d":::"r18");  // Was cd
asm("sts 0x0d16,r18");
asm("sleep");  // Step 373 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 374 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0x67":::"r18");  // Was e7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 375 
asm("ldi r18,0xcd":::"r18");  // Was 8d
asm("sts 0x0d16,r18");
asm("sleep");  // Step 376 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x0d":::"r18");  // Was cd
asm("sts 0x0d16,r18");
asm("ldi r18,0xa7":::"r18");  // Was 67
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 377 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xcd":::"r18");  // Was 0d
asm("sts 0x0d16,r18");
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 378 
asm("ldi r18,0x8d":::"r18");  // Was cd
asm("sts 0x0d16,r18");
asm("sleep");  // Step 379 
asm("ldi r18,0xdf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x7d":::"r18");  // Was 8d
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 380 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x3d":::"r18");  // Was 7d
asm("sts 0x0d16,r18");
asm("ldi r18,0xa7":::"r18");  // Was e7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 381 
asm("ldi r18,0x5f":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0xfd":::"r18");  // Was 3d
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 382 
asm("ldi r18,0xdf":::"r18");  // Was 5f
asm("sts 0x0d12,r18");
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d16,r18");
asm("sleep");  // Step 383 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 384 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0x67":::"r18");  // Was e7
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 385 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d16,r18");
asm("sleep");  // Step 386 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x3d":::"r18");  // Was fd
asm("sts 0x0d16,r18");
asm("ldi r18,0xa7":::"r18");  // Was 67
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 387 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0xfd":::"r18");  // Was 3d
asm("sts 0x0d16,r18");
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 388 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d16,r18");
asm("sleep");  // Step 389 
asm("ldi r18,0xff":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x6d":::"r18");  // Was bd
asm("sts 0x0d16,r18");
asm("sleep");  // Step 390 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2d":::"r18");  // Was 6d
asm("sts 0x0d16,r18");
asm("ldi r18,0xa7":::"r18");  // Was e7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 391 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xed":::"r18");  // Was 2d
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 392 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d16,r18");
asm("sleep");  // Step 393 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 394 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x67":::"r18");  // Was e7
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 395 
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d16,r18");
asm("sleep");  // Step 396 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2d":::"r18");  // Was ed
asm("sts 0x0d16,r18");
asm("ldi r18,0xa7":::"r18");  // Was 67
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 397 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xed":::"r18");  // Was 2d
asm("sts 0x0d16,r18");
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 398 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d16,r18");
asm("sleep");  // Step 399 
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x6d":::"r18");  // Was ad
asm("sts 0x0d16,r18");
asm("ldi r18,0xf7":::"r18");  // Was e7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 400 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x2d":::"r18");  // Was 6d
asm("sts 0x0d16,r18");
asm("ldi r18,0xb7":::"r18");  // Was f7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 401 
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xed":::"r18");  // Was 2d
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 402 
asm("ldi r18,0xef":::"r18");  // Was 6f
asm("sts 0x0d12,r18");
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d16,r18");
asm("sleep");  // Step 403 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0xf7":::"r18");  // Was b7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 404 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0x77":::"r18");  // Was f7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 405 
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d16,r18");
asm("sleep");  // Step 406 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x2d":::"r18");  // Was ed
asm("sts 0x0d16,r18");
asm("ldi r18,0xb7":::"r18");  // Was 77
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 407 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xed":::"r18");  // Was 2d
asm("sts 0x0d16,r18");
asm("ldi r18,0xf7":::"r18");  // Was b7
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 408 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d16,r18");
asm("sleep");  // Step 409 
asm("ldi r18,0xff":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x6d":::"r18");  // Was ad
asm("sts 0x0d16,r18");
asm("ldi r18,0xd7":::"r18");  // Was f7
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 410 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2d":::"r18");  // Was 6d
asm("sts 0x0d16,r18");
asm("ldi r18,0x97":::"r18");  // Was d7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 411 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xed":::"r18");  // Was 2d
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 412 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d16,r18");
asm("sleep");  // Step 413 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xd7":::"r18");  // Was 97
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 414 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x57":::"r18");  // Was d7
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 415 
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d16,r18");
asm("sleep");  // Step 416 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2d":::"r18");  // Was ed
asm("sts 0x0d16,r18");
asm("ldi r18,0x97":::"r18");  // Was 57
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 417 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xed":::"r18");  // Was 2d
asm("sts 0x0d16,r18");
asm("ldi r18,0xd7":::"r18");  // Was 97
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 418 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d16,r18");
asm("sleep");  // Step 419 
asm("ldi r18,0xfb":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x51":::"r18");  // Was ad
asm("sts 0x0d16,r18");
asm("ldi r18,0xfb":::"r18");  // Was d7
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 420 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x11":::"r18");  // Was 51
asm("sts 0x0d16,r18");
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 421 
asm("ldi r18,0x7b":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xd1":::"r18");  // Was 11
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 422 
asm("ldi r18,0xfb":::"r18");  // Was 7b
asm("sts 0x0d12,r18");
asm("ldi r18,0x91":::"r18");  // Was d1
asm("sts 0x0d16,r18");
asm("sleep");  // Step 423 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 424 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0x7b":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 425 
asm("ldi r18,0xd1":::"r18");  // Was 91
asm("sts 0x0d16,r18");
asm("sleep");  // Step 426 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x11":::"r18");  // Was d1
asm("sts 0x0d16,r18");
asm("ldi r18,0xbb":::"r18");  // Was 7b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 427 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xd1":::"r18");  // Was 11
asm("sts 0x0d16,r18");
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 428 
asm("ldi r18,0x91":::"r18");  // Was d1
asm("sts 0x0d16,r18");
asm("sleep");  // Step 429 
asm("ldi r18,0xeb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x41":::"r18");  // Was 91
asm("sts 0x0d16,r18");
asm("ldi r18,0xeb":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 430 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x01":::"r18");  // Was 41
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 431 
asm("ldi r18,0x6b":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0xc1":::"r18");  // Was 01
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 432 
asm("ldi r18,0xeb":::"r18");  // Was 6b
asm("sts 0x0d12,r18");
asm("ldi r18,0x81":::"r18");  // Was c1
asm("sts 0x0d16,r18");
asm("sleep");  // Step 433 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 434 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0x6b":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 435 
asm("ldi r18,0xc1":::"r18");  // Was 81
asm("sts 0x0d16,r18");
asm("sleep");  // Step 436 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x01":::"r18");  // Was c1
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was 6b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 437 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0xc1":::"r18");  // Was 01
asm("sts 0x0d16,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 438 
asm("ldi r18,0x81":::"r18");  // Was c1
asm("sts 0x0d16,r18");
asm("sleep");  // Step 439 
asm("ldi r18,0xdb":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x71":::"r18");  // Was 81
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 440 
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d12,r18");
asm("ldi r18,0x31":::"r18");  // Was 71
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 441 
asm("ldi r18,0x5b":::"r18");  // Was 9b
asm("sts 0x0d12,r18");
asm("ldi r18,0xf1":::"r18");  // Was 31
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 442 
asm("ldi r18,0xdb":::"r18");  // Was 5b
asm("sts 0x0d12,r18");
asm("ldi r18,0xb1":::"r18");  // Was f1
asm("sts 0x0d16,r18");
asm("sleep");  // Step 443 
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 444 
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d12,r18");
asm("ldi r18,0x6b":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 445 
asm("ldi r18,0xf1":::"r18");  // Was b1
asm("sts 0x0d16,r18");
asm("sleep");  // Step 446 
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d12,r18");
asm("ldi r18,0x31":::"r18");  // Was f1
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was 6b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 447 
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d12,r18");
asm("ldi r18,0xf1":::"r18");  // Was 31
asm("sts 0x0d16,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 448 
asm("ldi r18,0xb1":::"r18");  // Was f1
asm("sts 0x0d16,r18");
asm("sleep");  // Step 449 
asm("ldi r18,0xfb":::"r18");  // Was db
asm("sts 0x0d12,r18");
asm("ldi r18,0x61":::"r18");  // Was b1
asm("sts 0x0d16,r18");
asm("sleep");  // Step 450 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x21":::"r18");  // Was 61
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 451 
asm("ldi r18,0x7b":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xe1":::"r18");  // Was 21
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 452 
asm("ldi r18,0xfb":::"r18");  // Was 7b
asm("sts 0x0d12,r18");
asm("ldi r18,0xa1":::"r18");  // Was e1
asm("sts 0x0d16,r18");
asm("sleep");  // Step 453 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 454 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0x6b":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 455 
asm("ldi r18,0xe1":::"r18");  // Was a1
asm("sts 0x0d16,r18");
asm("sleep");  // Step 456 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x21":::"r18");  // Was e1
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was 6b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 457 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xe1":::"r18");  // Was 21
asm("sts 0x0d16,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 458 
asm("ldi r18,0xa1":::"r18");  // Was e1
asm("sts 0x0d16,r18");
asm("sleep");  // Step 459 
asm("ldi r18,0xeb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x61":::"r18");  // Was a1
asm("sts 0x0d16,r18");
asm("ldi r18,0xfb":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 460 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x21":::"r18");  // Was 61
asm("sts 0x0d16,r18");
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 461 
asm("ldi r18,0x6b":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0xe1":::"r18");  // Was 21
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 462 
asm("ldi r18,0xeb":::"r18");  // Was 6b
asm("sts 0x0d12,r18");
asm("ldi r18,0xa1":::"r18");  // Was e1
asm("sts 0x0d16,r18");
asm("sleep");  // Step 463 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 464 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0x7b":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 465 
asm("ldi r18,0xe1":::"r18");  // Was a1
asm("sts 0x0d16,r18");
asm("sleep");  // Step 466 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x21":::"r18");  // Was e1
asm("sts 0x0d16,r18");
asm("ldi r18,0xbb":::"r18");  // Was 7b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 467 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0xe1":::"r18");  // Was 21
asm("sts 0x0d16,r18");
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 468 
asm("ldi r18,0xa1":::"r18");  // Was e1
asm("sts 0x0d16,r18");
asm("sleep");  // Step 469 
asm("ldi r18,0xfb":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x61":::"r18");  // Was a1
asm("sts 0x0d16,r18");
asm("ldi r18,0xdb":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 470 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x21":::"r18");  // Was 61
asm("sts 0x0d16,r18");
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 471 
asm("ldi r18,0x7b":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xe1":::"r18");  // Was 21
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 472 
asm("ldi r18,0xfb":::"r18");  // Was 7b
asm("sts 0x0d12,r18");
asm("ldi r18,0xa1":::"r18");  // Was e1
asm("sts 0x0d16,r18");
asm("sleep");  // Step 473 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 474 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0x5b":::"r18");  // Was db
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 475 
asm("ldi r18,0xe1":::"r18");  // Was a1
asm("sts 0x0d16,r18");
asm("sleep");  // Step 476 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x21":::"r18");  // Was e1
asm("sts 0x0d16,r18");
asm("ldi r18,0x9b":::"r18");  // Was 5b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 477 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xe1":::"r18");  // Was 21
asm("sts 0x0d16,r18");
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 478 
asm("ldi r18,0xa1":::"r18");  // Was e1
asm("sts 0x0d16,r18");
asm("sleep");  // Step 479 
asm("ldi r18,0xff":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x5d":::"r18");  // Was a1
asm("sts 0x0d16,r18");
asm("ldi r18,0xff":::"r18");  // Was db
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 480 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x1d":::"r18");  // Was 5d
asm("sts 0x0d16,r18");
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 481 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xdd":::"r18");  // Was 1d
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 482 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0x9d":::"r18");  // Was dd
asm("sts 0x0d16,r18");
asm("sleep");  // Step 483 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 484 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x7f":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 485 
asm("ldi r18,0xdd":::"r18");  // Was 9d
asm("sts 0x0d16,r18");
asm("sleep");  // Step 486 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x1d":::"r18");  // Was dd
asm("sts 0x0d16,r18");
asm("ldi r18,0xbf":::"r18");  // Was 7f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 487 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xdd":::"r18");  // Was 1d
asm("sts 0x0d16,r18");
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 488 
asm("ldi r18,0x9d":::"r18");  // Was dd
asm("sts 0x0d16,r18");
asm("sleep");  // Step 489 
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x4d":::"r18");  // Was 9d
asm("sts 0x0d16,r18");
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 490 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x0d":::"r18");  // Was 4d
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 491 
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xcd":::"r18");  // Was 0d
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 492 
asm("ldi r18,0xef":::"r18");  // Was 6f
asm("sts 0x0d12,r18");
asm("ldi r18,0x8d":::"r18");  // Was cd
asm("sts 0x0d16,r18");
asm("sleep");  // Step 493 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 494 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0x6f":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 495 
asm("ldi r18,0xcd":::"r18");  // Was 8d
asm("sts 0x0d16,r18");
asm("sleep");  // Step 496 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x0d":::"r18");  // Was cd
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was 6f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 497 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xcd":::"r18");  // Was 0d
asm("sts 0x0d16,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 498 
asm("ldi r18,0x8d":::"r18");  // Was cd
asm("sts 0x0d16,r18");
asm("sleep");  // Step 499 
asm("ldi r18,0xdf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x7d":::"r18");  // Was 8d
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 500 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x3d":::"r18");  // Was 7d
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 501 
asm("ldi r18,0x5f":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0xfd":::"r18");  // Was 3d
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 502 
asm("ldi r18,0xdf":::"r18");  // Was 5f
asm("sts 0x0d12,r18");
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d16,r18");
asm("sleep");  // Step 503 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 504 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0x6f":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 505 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d16,r18");
asm("sleep");  // Step 506 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x3d":::"r18");  // Was fd
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was 6f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 507 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0xfd":::"r18");  // Was 3d
asm("sts 0x0d16,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 508 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d16,r18");
asm("sleep");  // Step 509 
asm("ldi r18,0xff":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x6d":::"r18");  // Was bd
asm("sts 0x0d16,r18");
asm("sleep");  // Step 510 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2d":::"r18");  // Was 6d
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 511 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xed":::"r18");  // Was 2d
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 512 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d16,r18");
asm("sleep");  // Step 513 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 514 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x6f":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 515 
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d16,r18");
asm("sleep");  // Step 516 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2d":::"r18");  // Was ed
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was 6f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 517 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xed":::"r18");  // Was 2d
asm("sts 0x0d16,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 518 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d16,r18");
asm("sleep");  // Step 519 
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x6d":::"r18");  // Was ad
asm("sts 0x0d16,r18");
asm("ldi r18,0xff":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 520 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x2d":::"r18");  // Was 6d
asm("sts 0x0d16,r18");
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 521 
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xed":::"r18");  // Was 2d
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 522 
asm("ldi r18,0xef":::"r18");  // Was 6f
asm("sts 0x0d12,r18");
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d16,r18");
asm("sleep");  // Step 523 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 524 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0x7f":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 525 
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d16,r18");
asm("sleep");  // Step 526 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x2d":::"r18");  // Was ed
asm("sts 0x0d16,r18");
asm("ldi r18,0xbf":::"r18");  // Was 7f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 527 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xed":::"r18");  // Was 2d
asm("sts 0x0d16,r18");
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 528 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d16,r18");
asm("sleep");  // Step 529 
asm("ldi r18,0xff":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x6d":::"r18");  // Was ad
asm("sts 0x0d16,r18");
asm("ldi r18,0xdf":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 530 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2d":::"r18");  // Was 6d
asm("sts 0x0d16,r18");
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 531 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xed":::"r18");  // Was 2d
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 532 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d16,r18");
asm("sleep");  // Step 533 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 534 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x5f":::"r18");  // Was df
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 535 
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d16,r18");
asm("sleep");  // Step 536 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2d":::"r18");  // Was ed
asm("sts 0x0d16,r18");
asm("ldi r18,0x9f":::"r18");  // Was 5f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 537 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xed":::"r18");  // Was 2d
asm("sts 0x0d16,r18");
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 538 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d16,r18");
asm("sleep");  // Step 539 
asm("ldi r18,0x59":::"r18");  // Was ad
asm("sts 0x0d16,r18");
asm("ldi r18,0xff":::"r18");  // Was df
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 540 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x19":::"r18");  // Was 59
asm("sts 0x0d16,r18");
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 541 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xd9":::"r18");  // Was 19
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 542 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0x99":::"r18");  // Was d9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 543 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 544 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x7f":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 545 
asm("ldi r18,0xd9":::"r18");  // Was 99
asm("sts 0x0d16,r18");
asm("sleep");  // Step 546 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x19":::"r18");  // Was d9
asm("sts 0x0d16,r18");
asm("ldi r18,0xbf":::"r18");  // Was 7f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 547 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xd9":::"r18");  // Was 19
asm("sts 0x0d16,r18");
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 548 
asm("ldi r18,0x99":::"r18");  // Was d9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 549 
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x49":::"r18");  // Was 99
asm("sts 0x0d16,r18");
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 550 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x09":::"r18");  // Was 49
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 551 
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xc9":::"r18");  // Was 09
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 552 
asm("ldi r18,0xef":::"r18");  // Was 6f
asm("sts 0x0d12,r18");
asm("ldi r18,0x89":::"r18");  // Was c9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 553 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 554 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0x6f":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 555 
asm("ldi r18,0xc9":::"r18");  // Was 89
asm("sts 0x0d16,r18");
asm("sleep");  // Step 556 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x09":::"r18");  // Was c9
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was 6f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 557 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xc9":::"r18");  // Was 09
asm("sts 0x0d16,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 558 
asm("ldi r18,0x89":::"r18");  // Was c9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 559 
asm("ldi r18,0xdf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x79":::"r18");  // Was 89
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 560 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x39":::"r18");  // Was 79
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 561 
asm("ldi r18,0x5f":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0xf9":::"r18");  // Was 39
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 562 
asm("ldi r18,0xdf":::"r18");  // Was 5f
asm("sts 0x0d12,r18");
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 563 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 564 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0x6f":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 565 
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 566 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x39":::"r18");  // Was f9
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was 6f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 567 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0xf9":::"r18");  // Was 39
asm("sts 0x0d16,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 568 
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 569 
asm("ldi r18,0xff":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x69":::"r18");  // Was b9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 570 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x29":::"r18");  // Was 69
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 571 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xe9":::"r18");  // Was 29
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 572 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 573 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 574 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x6f":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 575 
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 576 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x29":::"r18");  // Was e9
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was 6f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 577 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xe9":::"r18");  // Was 29
asm("sts 0x0d16,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 578 
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 579 
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x69":::"r18");  // Was a9
asm("sts 0x0d16,r18");
asm("ldi r18,0xff":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 580 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x29":::"r18");  // Was 69
asm("sts 0x0d16,r18");
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 581 
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xe9":::"r18");  // Was 29
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 582 
asm("ldi r18,0xef":::"r18");  // Was 6f
asm("sts 0x0d12,r18");
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 583 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 584 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0x7f":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 585 
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 586 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x29":::"r18");  // Was e9
asm("sts 0x0d16,r18");
asm("ldi r18,0xbf":::"r18");  // Was 7f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 587 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xe9":::"r18");  // Was 29
asm("sts 0x0d16,r18");
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 588 
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 589 
asm("ldi r18,0xff":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x69":::"r18");  // Was a9
asm("sts 0x0d16,r18");
asm("ldi r18,0xdf":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 590 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x29":::"r18");  // Was 69
asm("sts 0x0d16,r18");
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 591 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xe9":::"r18");  // Was 29
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 592 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 593 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 594 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x5f":::"r18");  // Was df
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 595 
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 596 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x29":::"r18");  // Was e9
asm("sts 0x0d16,r18");
asm("ldi r18,0x9f":::"r18");  // Was 5f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 597 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xe9":::"r18");  // Was 29
asm("sts 0x0d16,r18");
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 598 
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d16,r18");
asm("sleep");  // Step 599 
asm("ldi r18,0xfe":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x54":::"r18");  // Was a9
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was df
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 600 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x14":::"r18");  // Was 54
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 601 
asm("ldi r18,0x7e":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xd4":::"r18");  // Was 14
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 602 
asm("ldi r18,0xfe":::"r18");  // Was 7e
asm("sts 0x0d12,r18");
asm("ldi r18,0x94":::"r18");  // Was d4
asm("sts 0x0d16,r18");
asm("sleep");  // Step 603 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 604 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0x7e":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 605 
asm("ldi r18,0xd4":::"r18");  // Was 94
asm("sts 0x0d16,r18");
asm("sleep");  // Step 606 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x14":::"r18");  // Was d4
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was 7e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 607 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xd4":::"r18");  // Was 14
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 608 
asm("ldi r18,0x94":::"r18");  // Was d4
asm("sts 0x0d16,r18");
asm("sleep");  // Step 609 
asm("ldi r18,0xee":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x44":::"r18");  // Was 94
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 610 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x04":::"r18");  // Was 44
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 611 
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xc4":::"r18");  // Was 04
asm("sts 0x0d16,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 612 
asm("ldi r18,0xee":::"r18");  // Was 6e
asm("sts 0x0d12,r18");
asm("ldi r18,0x84":::"r18");  // Was c4
asm("sts 0x0d16,r18");
asm("sleep");  // Step 613 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 614 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 615 
asm("ldi r18,0xc4":::"r18");  // Was 84
asm("sts 0x0d16,r18");
asm("sleep");  // Step 616 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x04":::"r18");  // Was c4
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was 6e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 617 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xc4":::"r18");  // Was 04
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 618 
asm("ldi r18,0x84":::"r18");  // Was c4
asm("sts 0x0d16,r18");
asm("sleep");  // Step 619 
asm("ldi r18,0xde":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x74":::"r18");  // Was 84
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 620 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0x34":::"r18");  // Was 74
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 621 
asm("ldi r18,0x5e":::"r18");  // Was 9e
asm("sts 0x0d12,r18");
asm("ldi r18,0xf4":::"r18");  // Was 34
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 622 
asm("ldi r18,0xde":::"r18");  // Was 5e
asm("sts 0x0d12,r18");
asm("ldi r18,0xb4":::"r18");  // Was f4
asm("sts 0x0d16,r18");
asm("sleep");  // Step 623 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 624 
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 625 
asm("ldi r18,0xf4":::"r18");  // Was b4
asm("sts 0x0d16,r18");
asm("sleep");  // Step 626 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0x34":::"r18");  // Was f4
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was 6e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 627 
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d12,r18");
asm("ldi r18,0xf4":::"r18");  // Was 34
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 628 
asm("ldi r18,0xb4":::"r18");  // Was f4
asm("sts 0x0d16,r18");
asm("sleep");  // Step 629 
asm("ldi r18,0xfe":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0x64":::"r18");  // Was b4
asm("sts 0x0d16,r18");
asm("sleep");  // Step 630 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x24":::"r18");  // Was 64
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 631 
asm("ldi r18,0x7e":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xe4":::"r18");  // Was 24
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 632 
asm("ldi r18,0xfe":::"r18");  // Was 7e
asm("sts 0x0d12,r18");
asm("ldi r18,0xa4":::"r18");  // Was e4
asm("sts 0x0d16,r18");
asm("sleep");  // Step 633 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 634 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 635 
asm("ldi r18,0xe4":::"r18");  // Was a4
asm("sts 0x0d16,r18");
asm("sleep");  // Step 636 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x24":::"r18");  // Was e4
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was 6e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 637 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xe4":::"r18");  // Was 24
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 638 
asm("ldi r18,0xa4":::"r18");  // Was e4
asm("sts 0x0d16,r18");
asm("sleep");  // Step 639 
asm("ldi r18,0xee":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x64":::"r18");  // Was a4
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 640 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x24":::"r18");  // Was 64
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 641 
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xe4":::"r18");  // Was 24
asm("sts 0x0d16,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 642 
asm("ldi r18,0xee":::"r18");  // Was 6e
asm("sts 0x0d12,r18");
asm("ldi r18,0xa4":::"r18");  // Was e4
asm("sts 0x0d16,r18");
asm("sleep");  // Step 643 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 644 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0x7e":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 645 
asm("ldi r18,0xe4":::"r18");  // Was a4
asm("sts 0x0d16,r18");
asm("sleep");  // Step 646 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x24":::"r18");  // Was e4
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was 7e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 647 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xe4":::"r18");  // Was 24
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 648 
asm("ldi r18,0xa4":::"r18");  // Was e4
asm("sts 0x0d16,r18");
asm("sleep");  // Step 649 
asm("ldi r18,0xfe":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x64":::"r18");  // Was a4
asm("sts 0x0d16,r18");
asm("ldi r18,0xde":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 650 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x24":::"r18");  // Was 64
asm("sts 0x0d16,r18");
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 651 
asm("ldi r18,0x7e":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xe4":::"r18");  // Was 24
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 652 
asm("ldi r18,0xfe":::"r18");  // Was 7e
asm("sts 0x0d12,r18");
asm("ldi r18,0xa4":::"r18");  // Was e4
asm("sts 0x0d16,r18");
asm("sleep");  // Step 653 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 654 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0x5e":::"r18");  // Was de
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 655 
asm("ldi r18,0xe4":::"r18");  // Was a4
asm("sts 0x0d16,r18");
asm("sleep");  // Step 656 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x24":::"r18");  // Was e4
asm("sts 0x0d16,r18");
asm("ldi r18,0x9e":::"r18");  // Was 5e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 657 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xe4":::"r18");  // Was 24
asm("sts 0x0d16,r18");
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 658 
asm("ldi r18,0xa4":::"r18");  // Was e4
asm("sts 0x0d16,r18");
asm("sleep");  // Step 659 
asm("ldi r18,0xfa":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x50":::"r18");  // Was a4
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was de
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa0":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 660 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x10":::"r18");  // Was 50
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x20":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 661 
asm("ldi r18,0x7a":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0xd0":::"r18");  // Was 10
asm("sts 0x0d16,r18");
asm("ldi r18,0xa0":::"r18");  // Was 20
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 662 
asm("ldi r18,0xfa":::"r18");  // Was 7a
asm("sts 0x0d12,r18");
asm("ldi r18,0x90":::"r18");  // Was d0
asm("sts 0x0d16,r18");
asm("sleep");  // Step 663 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("ldi r18,0x20":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 664 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0x7a":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa0":::"r18");  // Was 20
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 665 
asm("ldi r18,0xd0":::"r18");  // Was 90
asm("sts 0x0d16,r18");
asm("sleep");  // Step 666 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x10":::"r18");  // Was d0
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was 7a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 667 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0xd0":::"r18");  // Was 10
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 668 
asm("ldi r18,0x90":::"r18");  // Was d0
asm("sts 0x0d16,r18");
asm("sleep");  // Step 669 
asm("ldi r18,0xea":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x40":::"r18");  // Was 90
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x80":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 670 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0x00":::"r18");  // Was 40
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x00":::"r18");  // Was 80
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 671 
asm("ldi r18,0x6a":::"r18");  // Was aa
asm("sts 0x0d12,r18");
asm("ldi r18,0xc0":::"r18");  // Was 00
asm("sts 0x0d16,r18");
asm("ldi r18,0x80":::"r18");  // Was 00
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 672 
asm("ldi r18,0xea":::"r18");  // Was 6a
asm("sts 0x0d12,r18");
asm("ldi r18,0x80":::"r18");  // Was c0
asm("sts 0x0d16,r18");
asm("sleep");  // Step 673 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x00":::"r18");  // Was 80
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 674 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x80":::"r18");  // Was 00
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 675 
asm("ldi r18,0xc0":::"r18");  // Was 80
asm("sts 0x0d16,r18");
asm("sleep");  // Step 676 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0x00":::"r18");  // Was c0
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 6a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 677 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d12,r18");
asm("ldi r18,0xc0":::"r18");  // Was 00
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 678 
asm("ldi r18,0x80":::"r18");  // Was c0
asm("sts 0x0d16,r18");
asm("sleep");  // Step 679 
asm("ldi r18,0xda":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0x70":::"r18");  // Was 80
asm("sts 0x0d16,r18");
asm("ldi r18,0xa0":::"r18");  // Was 80
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 680 
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d12,r18");
asm("ldi r18,0x30":::"r18");  // Was 70
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x20":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 681 
asm("ldi r18,0x5a":::"r18");  // Was 9a
asm("sts 0x0d12,r18");
asm("ldi r18,0xf0":::"r18");  // Was 30
asm("sts 0x0d16,r18");
asm("ldi r18,0xa0":::"r18");  // Was 20
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 682 
asm("ldi r18,0xda":::"r18");  // Was 5a
asm("sts 0x0d12,r18");
asm("ldi r18,0xb0":::"r18");  // Was f0
asm("sts 0x0d16,r18");
asm("sleep");  // Step 683 
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x20":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 684 
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa0":::"r18");  // Was 20
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 685 
asm("ldi r18,0xf0":::"r18");  // Was b0
asm("sts 0x0d16,r18");
asm("sleep");  // Step 686 
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d12,r18");
asm("ldi r18,0x30":::"r18");  // Was f0
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 6a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 687 
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d12,r18");
asm("ldi r18,0xf0":::"r18");  // Was 30
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 688 
asm("ldi r18,0xb0":::"r18");  // Was f0
asm("sts 0x0d16,r18");
asm("sleep");  // Step 689 
asm("ldi r18,0xfa":::"r18");  // Was da
asm("sts 0x0d12,r18");
asm("ldi r18,0x60":::"r18");  // Was b0
asm("sts 0x0d16,r18");
asm("sleep");  // Step 690 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x20":::"r18");  // Was 60
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x20":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 691 
asm("ldi r18,0x7a":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0xe0":::"r18");  // Was 20
asm("sts 0x0d16,r18");
asm("ldi r18,0xa0":::"r18");  // Was 20
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 692 
asm("ldi r18,0xfa":::"r18");  // Was 7a
asm("sts 0x0d12,r18");
asm("ldi r18,0xa0":::"r18");  // Was e0
asm("sts 0x0d16,r18");
asm("sleep");  // Step 693 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x20":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 694 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa0":::"r18");  // Was 20
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 695 
asm("ldi r18,0xe0":::"r18");  // Was a0
asm("sts 0x0d16,r18");
asm("sleep");  // Step 696 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x20":::"r18");  // Was e0
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 6a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 697 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0xe0":::"r18");  // Was 20
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 698 
asm("ldi r18,0xa0":::"r18");  // Was e0
asm("sts 0x0d16,r18");
asm("sleep");  // Step 699 
asm("ldi r18,0xea":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x60":::"r18");  // Was a0
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x80":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 700 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0x20":::"r18");  // Was 60
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x00":::"r18");  // Was 80
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 701 
asm("ldi r18,0x6a":::"r18");  // Was aa
asm("sts 0x0d12,r18");
asm("ldi r18,0xe0":::"r18");  // Was 20
asm("sts 0x0d16,r18");
asm("ldi r18,0x80":::"r18");  // Was 00
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 702 
asm("ldi r18,0xea":::"r18");  // Was 6a
asm("sts 0x0d12,r18");
asm("ldi r18,0xa0":::"r18");  // Was e0
asm("sts 0x0d16,r18");
asm("sleep");  // Step 703 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("ldi r18,0x00":::"r18");  // Was 80
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 704 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d12,r18");
asm("ldi r18,0x7a":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x80":::"r18");  // Was 00
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 705 
asm("ldi r18,0xe0":::"r18");  // Was a0
asm("sts 0x0d16,r18");
asm("sleep");  // Step 706 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0x20":::"r18");  // Was e0
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was 7a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 707 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d12,r18");
asm("ldi r18,0xe0":::"r18");  // Was 20
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 708 
asm("ldi r18,0xa0":::"r18");  // Was e0
asm("sts 0x0d16,r18");
asm("sleep");  // Step 709 
asm("ldi r18,0xfa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0x60":::"r18");  // Was a0
asm("sts 0x0d16,r18");
asm("ldi r18,0xda":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa0":::"r18");  // Was 80
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 710 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x20":::"r18");  // Was 60
asm("sts 0x0d16,r18");
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d1a,r18");
asm("ldi r18,0x20":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 711 
asm("ldi r18,0x7a":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0xe0":::"r18");  // Was 20
asm("sts 0x0d16,r18");
asm("ldi r18,0xa0":::"r18");  // Was 20
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 712 
asm("ldi r18,0xfa":::"r18");  // Was 7a
asm("sts 0x0d12,r18");
asm("ldi r18,0xa0":::"r18");  // Was e0
asm("sts 0x0d16,r18");
asm("sleep");  // Step 713 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d1a,r18");
asm("ldi r18,0x20":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 714 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0x5a":::"r18");  // Was da
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa0":::"r18");  // Was 20
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 715 
asm("ldi r18,0xe0":::"r18");  // Was a0
asm("sts 0x0d16,r18");
asm("sleep");  // Step 716 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x20":::"r18");  // Was e0
asm("sts 0x0d16,r18");
asm("ldi r18,0x9a":::"r18");  // Was 5a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 717 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0xe0":::"r18");  // Was 20
asm("sts 0x0d16,r18");
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 718 
asm("ldi r18,0xa0":::"r18");  // Was e0
asm("sts 0x0d16,r18");
asm("sleep");  // Step 719 
asm("ldi r18,0xf6":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x5c":::"r18");  // Was a0
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was da
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 720 
asm("ldi r18,0xb6":::"r18");  // Was f6
asm("sts 0x0d12,r18");
asm("ldi r18,0x1c":::"r18");  // Was 5c
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 721 
asm("ldi r18,0x76":::"r18");  // Was b6
asm("sts 0x0d12,r18");
asm("ldi r18,0xdc":::"r18");  // Was 1c
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 722 
asm("ldi r18,0xf6":::"r18");  // Was 76
asm("sts 0x0d12,r18");
asm("ldi r18,0x9c":::"r18");  // Was dc
asm("sts 0x0d16,r18");
asm("sleep");  // Step 723 
asm("ldi r18,0xb6":::"r18");  // Was f6
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 724 
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d12,r18");
asm("ldi r18,0x7a":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 725 
asm("ldi r18,0xdc":::"r18");  // Was 9c
asm("sts 0x0d16,r18");
asm("sleep");  // Step 726 
asm("ldi r18,0xb6":::"r18");  // Was f6
asm("sts 0x0d12,r18");
asm("ldi r18,0x1c":::"r18");  // Was dc
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was 7a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 727 
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d12,r18");
asm("ldi r18,0xdc":::"r18");  // Was 1c
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 728 
asm("ldi r18,0x9c":::"r18");  // Was dc
asm("sts 0x0d16,r18");
asm("sleep");  // Step 729 
asm("ldi r18,0xe6":::"r18");  // Was f6
asm("sts 0x0d12,r18");
asm("ldi r18,0x4c":::"r18");  // Was 9c
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 730 
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d12,r18");
asm("ldi r18,0x0c":::"r18");  // Was 4c
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 731 
asm("ldi r18,0x66":::"r18");  // Was a6
asm("sts 0x0d12,r18");
asm("ldi r18,0xcc":::"r18");  // Was 0c
asm("sts 0x0d16,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 732 
asm("ldi r18,0xe6":::"r18");  // Was 66
asm("sts 0x0d12,r18");
asm("ldi r18,0x8c":::"r18");  // Was cc
asm("sts 0x0d16,r18");
asm("sleep");  // Step 733 
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 734 
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 735 
asm("ldi r18,0xcc":::"r18");  // Was 8c
asm("sts 0x0d16,r18");
asm("sleep");  // Step 736 
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d12,r18");
asm("ldi r18,0x0c":::"r18");  // Was cc
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 6a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 737 
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d12,r18");
asm("ldi r18,0xcc":::"r18");  // Was 0c
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 738 
asm("ldi r18,0x8c":::"r18");  // Was cc
asm("sts 0x0d16,r18");
asm("sleep");  // Step 739 
asm("ldi r18,0xd6":::"r18");  // Was e6
asm("sts 0x0d12,r18");
asm("ldi r18,0x7c":::"r18");  // Was 8c
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 740 
asm("ldi r18,0x96":::"r18");  // Was d6
asm("sts 0x0d12,r18");
asm("ldi r18,0x3c":::"r18");  // Was 7c
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 741 
asm("ldi r18,0x56":::"r18");  // Was 96
asm("sts 0x0d12,r18");
asm("ldi r18,0xfc":::"r18");  // Was 3c
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 742 
asm("ldi r18,0xd6":::"r18");  // Was 56
asm("sts 0x0d12,r18");
asm("ldi r18,0xbc":::"r18");  // Was fc
asm("sts 0x0d16,r18");
asm("sleep");  // Step 743 
asm("ldi r18,0x96":::"r18");  // Was d6
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 744 
asm("ldi r18,0xd6":::"r18");  // Was 96
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 745 
asm("ldi r18,0xfc":::"r18");  // Was bc
asm("sts 0x0d16,r18");
asm("sleep");  // Step 746 
asm("ldi r18,0x96":::"r18");  // Was d6
asm("sts 0x0d12,r18");
asm("ldi r18,0x3c":::"r18");  // Was fc
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 6a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 747 
asm("ldi r18,0xd6":::"r18");  // Was 96
asm("sts 0x0d12,r18");
asm("ldi r18,0xfc":::"r18");  // Was 3c
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 748 
asm("ldi r18,0xbc":::"r18");  // Was fc
asm("sts 0x0d16,r18");
asm("sleep");  // Step 749 
asm("ldi r18,0xf6":::"r18");  // Was d6
asm("sts 0x0d12,r18");
asm("ldi r18,0x6c":::"r18");  // Was bc
asm("sts 0x0d16,r18");
asm("sleep");  // Step 750 
asm("ldi r18,0xb6":::"r18");  // Was f6
asm("sts 0x0d12,r18");
asm("ldi r18,0x2c":::"r18");  // Was 6c
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 751 
asm("ldi r18,0x76":::"r18");  // Was b6
asm("sts 0x0d12,r18");
asm("ldi r18,0xec":::"r18");  // Was 2c
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 752 
asm("ldi r18,0xf6":::"r18");  // Was 76
asm("sts 0x0d12,r18");
asm("ldi r18,0xac":::"r18");  // Was ec
asm("sts 0x0d16,r18");
asm("sleep");  // Step 753 
asm("ldi r18,0xb6":::"r18");  // Was f6
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 754 
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 755 
asm("ldi r18,0xec":::"r18");  // Was ac
asm("sts 0x0d16,r18");
asm("sleep");  // Step 756 
asm("ldi r18,0xb6":::"r18");  // Was f6
asm("sts 0x0d12,r18");
asm("ldi r18,0x2c":::"r18");  // Was ec
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 6a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 757 
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d12,r18");
asm("ldi r18,0xec":::"r18");  // Was 2c
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 758 
asm("ldi r18,0xac":::"r18");  // Was ec
asm("sts 0x0d16,r18");
asm("sleep");  // Step 759 
asm("ldi r18,0xe6":::"r18");  // Was f6
asm("sts 0x0d12,r18");
asm("ldi r18,0x6c":::"r18");  // Was ac
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 760 
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d12,r18");
asm("ldi r18,0x2c":::"r18");  // Was 6c
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 761 
asm("ldi r18,0x66":::"r18");  // Was a6
asm("sts 0x0d12,r18");
asm("ldi r18,0xec":::"r18");  // Was 2c
asm("sts 0x0d16,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 762 
asm("ldi r18,0xe6":::"r18");  // Was 66
asm("sts 0x0d12,r18");
asm("ldi r18,0xac":::"r18");  // Was ec
asm("sts 0x0d16,r18");
asm("sleep");  // Step 763 
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 764 
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d12,r18");
asm("ldi r18,0x7a":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 765 
asm("ldi r18,0xec":::"r18");  // Was ac
asm("sts 0x0d16,r18");
asm("sleep");  // Step 766 
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d12,r18");
asm("ldi r18,0x2c":::"r18");  // Was ec
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was 7a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 767 
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d12,r18");
asm("ldi r18,0xec":::"r18");  // Was 2c
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 768 
asm("ldi r18,0xac":::"r18");  // Was ec
asm("sts 0x0d16,r18");
asm("sleep");  // Step 769 
asm("ldi r18,0xf6":::"r18");  // Was e6
asm("sts 0x0d12,r18");
asm("ldi r18,0x6c":::"r18");  // Was ac
asm("sts 0x0d16,r18");
asm("ldi r18,0xda":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 770 
asm("ldi r18,0xb6":::"r18");  // Was f6
asm("sts 0x0d12,r18");
asm("ldi r18,0x2c":::"r18");  // Was 6c
asm("sts 0x0d16,r18");
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 771 
asm("ldi r18,0x76":::"r18");  // Was b6
asm("sts 0x0d12,r18");
asm("ldi r18,0xec":::"r18");  // Was 2c
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 772 
asm("ldi r18,0xf6":::"r18");  // Was 76
asm("sts 0x0d12,r18");
asm("ldi r18,0xac":::"r18");  // Was ec
asm("sts 0x0d16,r18");
asm("sleep");  // Step 773 
asm("ldi r18,0xb6":::"r18");  // Was f6
asm("sts 0x0d12,r18");
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 774 
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d12,r18");
asm("ldi r18,0x5a":::"r18");  // Was da
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 775 
asm("ldi r18,0xec":::"r18");  // Was ac
asm("sts 0x0d16,r18");
asm("sleep");  // Step 776 
asm("ldi r18,0xb6":::"r18");  // Was f6
asm("sts 0x0d12,r18");
asm("ldi r18,0x2c":::"r18");  // Was ec
asm("sts 0x0d16,r18");
asm("ldi r18,0x9a":::"r18");  // Was 5a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 777 
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d12,r18");
asm("ldi r18,0xec":::"r18");  // Was 2c
asm("sts 0x0d16,r18");
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 778 
asm("ldi r18,0xac":::"r18");  // Was ec
asm("sts 0x0d16,r18");
asm("sleep");  // Step 779 
asm("ldi r18,0xfe":::"r18");  // Was f6
asm("sts 0x0d12,r18");
asm("ldi r18,0x58":::"r18");  // Was ac
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was da
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 780 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x18":::"r18");  // Was 58
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 781 
asm("ldi r18,0x7e":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xd8":::"r18");  // Was 18
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 782 
asm("ldi r18,0xfe":::"r18");  // Was 7e
asm("sts 0x0d12,r18");
asm("ldi r18,0x98":::"r18");  // Was d8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 783 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 784 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0x7a":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 785 
asm("ldi r18,0xd8":::"r18");  // Was 98
asm("sts 0x0d16,r18");
asm("sleep");  // Step 786 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x18":::"r18");  // Was d8
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was 7a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 787 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xd8":::"r18");  // Was 18
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 788 
asm("ldi r18,0x98":::"r18");  // Was d8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 789 
asm("ldi r18,0xee":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x48":::"r18");  // Was 98
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 790 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x08":::"r18");  // Was 48
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 791 
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xc8":::"r18");  // Was 08
asm("sts 0x0d16,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 792 
asm("ldi r18,0xee":::"r18");  // Was 6e
asm("sts 0x0d12,r18");
asm("ldi r18,0x88":::"r18");  // Was c8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 793 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 794 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 795 
asm("ldi r18,0xc8":::"r18");  // Was 88
asm("sts 0x0d16,r18");
asm("sleep");  // Step 796 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x08":::"r18");  // Was c8
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 6a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 797 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xc8":::"r18");  // Was 08
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 798 
asm("ldi r18,0x88":::"r18");  // Was c8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 799 
asm("ldi r18,0xde":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x78":::"r18");  // Was 88
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 800 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0x38":::"r18");  // Was 78
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 801 
asm("ldi r18,0x5e":::"r18");  // Was 9e
asm("sts 0x0d12,r18");
asm("ldi r18,0xf8":::"r18");  // Was 38
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 802 
asm("ldi r18,0xde":::"r18");  // Was 5e
asm("sts 0x0d12,r18");
asm("ldi r18,0xb8":::"r18");  // Was f8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 803 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 804 
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 805 
asm("ldi r18,0xf8":::"r18");  // Was b8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 806 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0x38":::"r18");  // Was f8
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 6a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 807 
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d12,r18");
asm("ldi r18,0xf8":::"r18");  // Was 38
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 808 
asm("ldi r18,0xb8":::"r18");  // Was f8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 809 
asm("ldi r18,0xfe":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0x68":::"r18");  // Was b8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 810 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x28":::"r18");  // Was 68
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 811 
asm("ldi r18,0x7e":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xe8":::"r18");  // Was 28
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 812 
asm("ldi r18,0xfe":::"r18");  // Was 7e
asm("sts 0x0d12,r18");
asm("ldi r18,0xa8":::"r18");  // Was e8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 813 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 814 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 815 
asm("ldi r18,0xe8":::"r18");  // Was a8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 816 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x28":::"r18");  // Was e8
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 6a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 817 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xe8":::"r18");  // Was 28
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 818 
asm("ldi r18,0xa8":::"r18");  // Was e8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 819 
asm("ldi r18,0xee":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x68":::"r18");  // Was a8
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 820 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x28":::"r18");  // Was 68
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 821 
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xe8":::"r18");  // Was 28
asm("sts 0x0d16,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 822 
asm("ldi r18,0xee":::"r18");  // Was 6e
asm("sts 0x0d12,r18");
asm("ldi r18,0xa8":::"r18");  // Was e8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 823 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 824 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0x7a":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 825 
asm("ldi r18,0xe8":::"r18");  // Was a8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 826 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x28":::"r18");  // Was e8
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was 7a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 827 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xe8":::"r18");  // Was 28
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 828 
asm("ldi r18,0xa8":::"r18");  // Was e8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 829 
asm("ldi r18,0xfe":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x68":::"r18");  // Was a8
asm("sts 0x0d16,r18");
asm("ldi r18,0xda":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 830 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x28":::"r18");  // Was 68
asm("sts 0x0d16,r18");
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 831 
asm("ldi r18,0x7e":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xe8":::"r18");  // Was 28
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 832 
asm("ldi r18,0xfe":::"r18");  // Was 7e
asm("sts 0x0d12,r18");
asm("ldi r18,0xa8":::"r18");  // Was e8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 833 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 834 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0x5a":::"r18");  // Was da
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 835 
asm("ldi r18,0xe8":::"r18");  // Was a8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 836 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x28":::"r18");  // Was e8
asm("sts 0x0d16,r18");
asm("ldi r18,0x9a":::"r18");  // Was 5a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 837 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xe8":::"r18");  // Was 28
asm("sts 0x0d16,r18");
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 838 
asm("ldi r18,0xa8":::"r18");  // Was e8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 839 
asm("ldi r18,0xfa":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x58":::"r18");  // Was a8
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was da
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa0":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 840 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x18":::"r18");  // Was 58
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x20":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 841 
asm("ldi r18,0x7a":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0xd8":::"r18");  // Was 18
asm("sts 0x0d16,r18");
asm("ldi r18,0xa0":::"r18");  // Was 20
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 842 
asm("ldi r18,0xfa":::"r18");  // Was 7a
asm("sts 0x0d12,r18");
asm("ldi r18,0x98":::"r18");  // Was d8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 843 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("ldi r18,0x20":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 844 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0x7e":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa0":::"r18");  // Was 20
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 845 
asm("ldi r18,0xd8":::"r18");  // Was 98
asm("sts 0x0d16,r18");
asm("sleep");  // Step 846 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x18":::"r18");  // Was d8
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was 7e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 847 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0xd8":::"r18");  // Was 18
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 848 
asm("ldi r18,0x98":::"r18");  // Was d8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 849 
asm("ldi r18,0xea":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x48":::"r18");  // Was 98
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x80":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 850 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0x08":::"r18");  // Was 48
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x00":::"r18");  // Was 80
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 851 
asm("ldi r18,0x6a":::"r18");  // Was aa
asm("sts 0x0d12,r18");
asm("ldi r18,0xc8":::"r18");  // Was 08
asm("sts 0x0d16,r18");
asm("ldi r18,0x80":::"r18");  // Was 00
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 852 
asm("ldi r18,0xea":::"r18");  // Was 6a
asm("sts 0x0d12,r18");
asm("ldi r18,0x88":::"r18");  // Was c8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 853 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("ldi r18,0x00":::"r18");  // Was 80
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 854 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x80":::"r18");  // Was 00
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 855 
asm("ldi r18,0xc8":::"r18");  // Was 88
asm("sts 0x0d16,r18");
asm("sleep");  // Step 856 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0x08":::"r18");  // Was c8
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was 6e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 857 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d12,r18");
asm("ldi r18,0xc8":::"r18");  // Was 08
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 858 
asm("ldi r18,0x88":::"r18");  // Was c8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 859 
asm("ldi r18,0xda":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0x78":::"r18");  // Was 88
asm("sts 0x0d16,r18");
asm("ldi r18,0xa0":::"r18");  // Was 80
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 860 
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d12,r18");
asm("ldi r18,0x38":::"r18");  // Was 78
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x20":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 861 
asm("ldi r18,0x5a":::"r18");  // Was 9a
asm("sts 0x0d12,r18");
asm("ldi r18,0xf8":::"r18");  // Was 38
asm("sts 0x0d16,r18");
asm("ldi r18,0xa0":::"r18");  // Was 20
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 862 
asm("ldi r18,0xda":::"r18");  // Was 5a
asm("sts 0x0d12,r18");
asm("ldi r18,0xb8":::"r18");  // Was f8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 863 
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("ldi r18,0x20":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 864 
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa0":::"r18");  // Was 20
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 865 
asm("ldi r18,0xf8":::"r18");  // Was b8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 866 
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d12,r18");
asm("ldi r18,0x38":::"r18");  // Was f8
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was 6e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 867 
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d12,r18");
asm("ldi r18,0xf8":::"r18");  // Was 38
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 868 
asm("ldi r18,0xb8":::"r18");  // Was f8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 869 
asm("ldi r18,0xfa":::"r18");  // Was da
asm("sts 0x0d12,r18");
asm("ldi r18,0x68":::"r18");  // Was b8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 870 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x28":::"r18");  // Was 68
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x20":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 871 
asm("ldi r18,0x7a":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0xe8":::"r18");  // Was 28
asm("sts 0x0d16,r18");
asm("ldi r18,0xa0":::"r18");  // Was 20
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 872 
asm("ldi r18,0xfa":::"r18");  // Was 7a
asm("sts 0x0d12,r18");
asm("ldi r18,0xa8":::"r18");  // Was e8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 873 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("ldi r18,0x20":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 874 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa0":::"r18");  // Was 20
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 875 
asm("ldi r18,0xe8":::"r18");  // Was a8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 876 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x28":::"r18");  // Was e8
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was 6e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 877 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0xe8":::"r18");  // Was 28
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 878 
asm("ldi r18,0xa8":::"r18");  // Was e8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 879 
asm("ldi r18,0xea":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x68":::"r18");  // Was a8
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x80":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 880 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0x28":::"r18");  // Was 68
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x00":::"r18");  // Was 80
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 881 
asm("ldi r18,0x6a":::"r18");  // Was aa
asm("sts 0x0d12,r18");
asm("ldi r18,0xe8":::"r18");  // Was 28
asm("sts 0x0d16,r18");
asm("ldi r18,0x80":::"r18");  // Was 00
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 882 
asm("ldi r18,0xea":::"r18");  // Was 6a
asm("sts 0x0d12,r18");
asm("ldi r18,0xa8":::"r18");  // Was e8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 883 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("ldi r18,0x00":::"r18");  // Was 80
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 884 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d12,r18");
asm("ldi r18,0x7e":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x80":::"r18");  // Was 00
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 885 
asm("ldi r18,0xe8":::"r18");  // Was a8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 886 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0x28":::"r18");  // Was e8
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was 7e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 887 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d12,r18");
asm("ldi r18,0xe8":::"r18");  // Was 28
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 888 
asm("ldi r18,0xa8":::"r18");  // Was e8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 889 
asm("ldi r18,0xfa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0x68":::"r18");  // Was a8
asm("sts 0x0d16,r18");
asm("ldi r18,0xde":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa0":::"r18");  // Was 80
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 890 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x28":::"r18");  // Was 68
asm("sts 0x0d16,r18");
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d1a,r18");
asm("ldi r18,0x20":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 891 
asm("ldi r18,0x7a":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0xe8":::"r18");  // Was 28
asm("sts 0x0d16,r18");
asm("ldi r18,0xa0":::"r18");  // Was 20
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 892 
asm("ldi r18,0xfa":::"r18");  // Was 7a
asm("sts 0x0d12,r18");
asm("ldi r18,0xa8":::"r18");  // Was e8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 893 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d1a,r18");
asm("ldi r18,0x20":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 894 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0x5e":::"r18");  // Was de
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa0":::"r18");  // Was 20
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 895 
asm("ldi r18,0xe8":::"r18");  // Was a8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 896 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x28":::"r18");  // Was e8
asm("sts 0x0d16,r18");
asm("ldi r18,0x9e":::"r18");  // Was 5e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 897 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0xe8":::"r18");  // Was 28
asm("sts 0x0d16,r18");
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 898 
asm("ldi r18,0xa8":::"r18");  // Was e8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 899 
asm("ldi r18,0xfe":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x58":::"r18");  // Was a8
asm("sts 0x0d16,r18");
asm("ldi r18,0xf6":::"r18");  // Was de
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 900 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x18":::"r18");  // Was 58
asm("sts 0x0d16,r18");
asm("ldi r18,0xb6":::"r18");  // Was f6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 901 
asm("ldi r18,0x7e":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xd8":::"r18");  // Was 18
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 902 
asm("ldi r18,0xfe":::"r18");  // Was 7e
asm("sts 0x0d12,r18");
asm("ldi r18,0x98":::"r18");  // Was d8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 903 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 904 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0x76":::"r18");  // Was f6
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 905 
asm("ldi r18,0xd8":::"r18");  // Was 98
asm("sts 0x0d16,r18");
asm("sleep");  // Step 906 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x18":::"r18");  // Was d8
asm("sts 0x0d16,r18");
asm("ldi r18,0xb6":::"r18");  // Was 76
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 907 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xd8":::"r18");  // Was 18
asm("sts 0x0d16,r18");
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 908 
asm("ldi r18,0x98":::"r18");  // Was d8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 909 
asm("ldi r18,0xee":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x48":::"r18");  // Was 98
asm("sts 0x0d16,r18");
asm("ldi r18,0xe6":::"r18");  // Was f6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 910 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x08":::"r18");  // Was 48
asm("sts 0x0d16,r18");
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 911 
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xc8":::"r18");  // Was 08
asm("sts 0x0d16,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 912 
asm("ldi r18,0xee":::"r18");  // Was 6e
asm("sts 0x0d12,r18");
asm("ldi r18,0x88":::"r18");  // Was c8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 913 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 914 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0x66":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 915 
asm("ldi r18,0xc8":::"r18");  // Was 88
asm("sts 0x0d16,r18");
asm("sleep");  // Step 916 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x08":::"r18");  // Was c8
asm("sts 0x0d16,r18");
asm("ldi r18,0xa6":::"r18");  // Was 66
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 917 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xc8":::"r18");  // Was 08
asm("sts 0x0d16,r18");
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 918 
asm("ldi r18,0x88":::"r18");  // Was c8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 919 
asm("ldi r18,0xde":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x78":::"r18");  // Was 88
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 920 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0x38":::"r18");  // Was 78
asm("sts 0x0d16,r18");
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 921 
asm("ldi r18,0x5e":::"r18");  // Was 9e
asm("sts 0x0d12,r18");
asm("ldi r18,0xf8":::"r18");  // Was 38
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 922 
asm("ldi r18,0xde":::"r18");  // Was 5e
asm("sts 0x0d12,r18");
asm("ldi r18,0xb8":::"r18");  // Was f8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 923 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 924 
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d12,r18");
asm("ldi r18,0x66":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 925 
asm("ldi r18,0xf8":::"r18");  // Was b8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 926 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0x38":::"r18");  // Was f8
asm("sts 0x0d16,r18");
asm("ldi r18,0xa6":::"r18");  // Was 66
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 927 
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d12,r18");
asm("ldi r18,0xf8":::"r18");  // Was 38
asm("sts 0x0d16,r18");
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 928 
asm("ldi r18,0xb8":::"r18");  // Was f8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 929 
asm("ldi r18,0xfe":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0x68":::"r18");  // Was b8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 930 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x28":::"r18");  // Was 68
asm("sts 0x0d16,r18");
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 931 
asm("ldi r18,0x7e":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xe8":::"r18");  // Was 28
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 932 
asm("ldi r18,0xfe":::"r18");  // Was 7e
asm("sts 0x0d12,r18");
asm("ldi r18,0xa8":::"r18");  // Was e8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 933 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 934 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0x66":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 935 
asm("ldi r18,0xe8":::"r18");  // Was a8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 936 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x28":::"r18");  // Was e8
asm("sts 0x0d16,r18");
asm("ldi r18,0xa6":::"r18");  // Was 66
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 937 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xe8":::"r18");  // Was 28
asm("sts 0x0d16,r18");
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 938 
asm("ldi r18,0xa8":::"r18");  // Was e8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 939 
asm("ldi r18,0xee":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x68":::"r18");  // Was a8
asm("sts 0x0d16,r18");
asm("ldi r18,0xf6":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 940 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x28":::"r18");  // Was 68
asm("sts 0x0d16,r18");
asm("ldi r18,0xb6":::"r18");  // Was f6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 941 
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xe8":::"r18");  // Was 28
asm("sts 0x0d16,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 942 
asm("ldi r18,0xee":::"r18");  // Was 6e
asm("sts 0x0d12,r18");
asm("ldi r18,0xa8":::"r18");  // Was e8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 943 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 944 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0x76":::"r18");  // Was f6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 945 
asm("ldi r18,0xe8":::"r18");  // Was a8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 946 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x28":::"r18");  // Was e8
asm("sts 0x0d16,r18");
asm("ldi r18,0xb6":::"r18");  // Was 76
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 947 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xe8":::"r18");  // Was 28
asm("sts 0x0d16,r18");
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 948 
asm("ldi r18,0xa8":::"r18");  // Was e8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 949 
asm("ldi r18,0xfe":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x68":::"r18");  // Was a8
asm("sts 0x0d16,r18");
asm("ldi r18,0xd6":::"r18");  // Was f6
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 950 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x28":::"r18");  // Was 68
asm("sts 0x0d16,r18");
asm("ldi r18,0x96":::"r18");  // Was d6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 951 
asm("ldi r18,0x7e":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xe8":::"r18");  // Was 28
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 952 
asm("ldi r18,0xfe":::"r18");  // Was 7e
asm("sts 0x0d12,r18");
asm("ldi r18,0xa8":::"r18");  // Was e8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 953 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0xd6":::"r18");  // Was 96
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 954 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0x56":::"r18");  // Was d6
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 955 
asm("ldi r18,0xe8":::"r18");  // Was a8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 956 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x28":::"r18");  // Was e8
asm("sts 0x0d16,r18");
asm("ldi r18,0x96":::"r18");  // Was 56
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 957 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xe8":::"r18");  // Was 28
asm("sts 0x0d16,r18");
asm("ldi r18,0xd6":::"r18");  // Was 96
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 958 
asm("ldi r18,0xa8":::"r18");  // Was e8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 959 
asm("ldi r18,0x5c":::"r18");  // Was a8
asm("sts 0x0d16,r18");
asm("ldi r18,0xf6":::"r18");  // Was d6
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 960 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x1c":::"r18");  // Was 5c
asm("sts 0x0d16,r18");
asm("ldi r18,0xb6":::"r18");  // Was f6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 961 
asm("ldi r18,0x7e":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xdc":::"r18");  // Was 1c
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 962 
asm("ldi r18,0xfe":::"r18");  // Was 7e
asm("sts 0x0d12,r18");
asm("ldi r18,0x9c":::"r18");  // Was dc
asm("sts 0x0d16,r18");
asm("sleep");  // Step 963 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 964 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0x76":::"r18");  // Was f6
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 965 
asm("ldi r18,0xdc":::"r18");  // Was 9c
asm("sts 0x0d16,r18");
asm("sleep");  // Step 966 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x1c":::"r18");  // Was dc
asm("sts 0x0d16,r18");
asm("ldi r18,0xb6":::"r18");  // Was 76
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 967 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xdc":::"r18");  // Was 1c
asm("sts 0x0d16,r18");
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 968 
asm("ldi r18,0x9c":::"r18");  // Was dc
asm("sts 0x0d16,r18");
asm("sleep");  // Step 969 
asm("ldi r18,0xee":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x4c":::"r18");  // Was 9c
asm("sts 0x0d16,r18");
asm("ldi r18,0xe6":::"r18");  // Was f6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 970 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x0c":::"r18");  // Was 4c
asm("sts 0x0d16,r18");
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 971 
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xcc":::"r18");  // Was 0c
asm("sts 0x0d16,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 972 
asm("ldi r18,0xee":::"r18");  // Was 6e
asm("sts 0x0d12,r18");
asm("ldi r18,0x8c":::"r18");  // Was cc
asm("sts 0x0d16,r18");
asm("sleep");  // Step 973 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 974 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0x66":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 975 
asm("ldi r18,0xcc":::"r18");  // Was 8c
asm("sts 0x0d16,r18");
asm("sleep");  // Step 976 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x0c":::"r18");  // Was cc
asm("sts 0x0d16,r18");
asm("ldi r18,0xa6":::"r18");  // Was 66
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 977 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xcc":::"r18");  // Was 0c
asm("sts 0x0d16,r18");
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 978 
asm("ldi r18,0x8c":::"r18");  // Was cc
asm("sts 0x0d16,r18");
asm("sleep");  // Step 979 
asm("ldi r18,0xde":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x7c":::"r18");  // Was 8c
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 980 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0x3c":::"r18");  // Was 7c
asm("sts 0x0d16,r18");
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 981 
asm("ldi r18,0x5e":::"r18");  // Was 9e
asm("sts 0x0d12,r18");
asm("ldi r18,0xfc":::"r18");  // Was 3c
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 982 
asm("ldi r18,0xde":::"r18");  // Was 5e
asm("sts 0x0d12,r18");
asm("ldi r18,0xbc":::"r18");  // Was fc
asm("sts 0x0d16,r18");
asm("sleep");  // Step 983 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 984 
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d12,r18");
asm("ldi r18,0x66":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 985 
asm("ldi r18,0xfc":::"r18");  // Was bc
asm("sts 0x0d16,r18");
asm("sleep");  // Step 986 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0x3c":::"r18");  // Was fc
asm("sts 0x0d16,r18");
asm("ldi r18,0xa6":::"r18");  // Was 66
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 987 
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d12,r18");
asm("ldi r18,0xfc":::"r18");  // Was 3c
asm("sts 0x0d16,r18");
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 988 
asm("ldi r18,0xbc":::"r18");  // Was fc
asm("sts 0x0d16,r18");
asm("sleep");  // Step 989 
asm("ldi r18,0xfe":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0x6c":::"r18");  // Was bc
asm("sts 0x0d16,r18");
asm("sleep");  // Step 990 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x2c":::"r18");  // Was 6c
asm("sts 0x0d16,r18");
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 991 
asm("ldi r18,0x7e":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xec":::"r18");  // Was 2c
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 992 
asm("ldi r18,0xfe":::"r18");  // Was 7e
asm("sts 0x0d12,r18");
asm("ldi r18,0xac":::"r18");  // Was ec
asm("sts 0x0d16,r18");
asm("sleep");  // Step 993 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 994 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0x66":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 995 
asm("ldi r18,0xec":::"r18");  // Was ac
asm("sts 0x0d16,r18");
asm("sleep");  // Step 996 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x2c":::"r18");  // Was ec
asm("sts 0x0d16,r18");
asm("ldi r18,0xa6":::"r18");  // Was 66
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 997 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xec":::"r18");  // Was 2c
asm("sts 0x0d16,r18");
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 998 
asm("ldi r18,0xac":::"r18");  // Was ec
asm("sts 0x0d16,r18");
asm("sleep");  // Step 999 
asm("ldi r18,0xee":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x6c":::"r18");  // Was ac
asm("sts 0x0d16,r18");
asm("ldi r18,0xf6":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1000 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x2c":::"r18");  // Was 6c
asm("sts 0x0d16,r18");
asm("ldi r18,0xb6":::"r18");  // Was f6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1001 
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xec":::"r18");  // Was 2c
asm("sts 0x0d16,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1002 
asm("ldi r18,0xee":::"r18");  // Was 6e
asm("sts 0x0d12,r18");
asm("ldi r18,0xac":::"r18");  // Was ec
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1003 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1004 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0x76":::"r18");  // Was f6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1005 
asm("ldi r18,0xec":::"r18");  // Was ac
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1006 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x2c":::"r18");  // Was ec
asm("sts 0x0d16,r18");
asm("ldi r18,0xb6":::"r18");  // Was 76
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1007 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xec":::"r18");  // Was 2c
asm("sts 0x0d16,r18");
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1008 
asm("ldi r18,0xac":::"r18");  // Was ec
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1009 
asm("ldi r18,0xfe":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x6c":::"r18");  // Was ac
asm("sts 0x0d16,r18");
asm("ldi r18,0xd6":::"r18");  // Was f6
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1010 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x2c":::"r18");  // Was 6c
asm("sts 0x0d16,r18");
asm("ldi r18,0x96":::"r18");  // Was d6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1011 
asm("ldi r18,0x7e":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xec":::"r18");  // Was 2c
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1012 
asm("ldi r18,0xfe":::"r18");  // Was 7e
asm("sts 0x0d12,r18");
asm("ldi r18,0xac":::"r18");  // Was ec
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1013 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0xd6":::"r18");  // Was 96
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1014 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0x56":::"r18");  // Was d6
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1015 
asm("ldi r18,0xec":::"r18");  // Was ac
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1016 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x2c":::"r18");  // Was ec
asm("sts 0x0d16,r18");
asm("ldi r18,0x96":::"r18");  // Was 56
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1017 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xec":::"r18");  // Was 2c
asm("sts 0x0d16,r18");
asm("ldi r18,0xd6":::"r18");  // Was 96
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1018 
asm("ldi r18,0xac":::"r18");  // Was ec
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1019 
asm("ldi r18,0xfa":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x50":::"r18");  // Was ac
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was d6
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1020 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x10":::"r18");  // Was 50
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1021 
asm("ldi r18,0x7a":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0xd0":::"r18");  // Was 10
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1022 
asm("ldi r18,0xfa":::"r18");  // Was 7a
asm("sts 0x0d12,r18");
asm("ldi r18,0x90":::"r18");  // Was d0
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1023 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1024 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0x7a":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1025 
asm("ldi r18,0xd0":::"r18");  // Was 90
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1026 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x10":::"r18");  // Was d0
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was 7a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1027 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0xd0":::"r18");  // Was 10
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1028 
asm("ldi r18,0x90":::"r18");  // Was d0
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1029 
asm("ldi r18,0xea":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x40":::"r18");  // Was 90
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1030 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0x00":::"r18");  // Was 40
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1031 
asm("ldi r18,0x6a":::"r18");  // Was aa
asm("sts 0x0d12,r18");
asm("ldi r18,0xc0":::"r18");  // Was 00
asm("sts 0x0d16,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1032 
asm("ldi r18,0xea":::"r18");  // Was 6a
asm("sts 0x0d12,r18");
asm("ldi r18,0x80":::"r18");  // Was c0
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1033 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1034 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1035 
asm("ldi r18,0xc0":::"r18");  // Was 80
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1036 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0x00":::"r18");  // Was c0
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 6a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1037 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d12,r18");
asm("ldi r18,0xc0":::"r18");  // Was 00
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1038 
asm("ldi r18,0x80":::"r18");  // Was c0
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1039 
asm("ldi r18,0xda":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0x70":::"r18");  // Was 80
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1040 
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d12,r18");
asm("ldi r18,0x30":::"r18");  // Was 70
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1041 
asm("ldi r18,0x5a":::"r18");  // Was 9a
asm("sts 0x0d12,r18");
asm("ldi r18,0xf0":::"r18");  // Was 30
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1042 
asm("ldi r18,0xda":::"r18");  // Was 5a
asm("sts 0x0d12,r18");
asm("ldi r18,0xb0":::"r18");  // Was f0
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1043 
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1044 
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1045 
asm("ldi r18,0xf0":::"r18");  // Was b0
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1046 
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d12,r18");
asm("ldi r18,0x30":::"r18");  // Was f0
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 6a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1047 
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d12,r18");
asm("ldi r18,0xf0":::"r18");  // Was 30
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1048 
asm("ldi r18,0xb0":::"r18");  // Was f0
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1049 
asm("ldi r18,0xfa":::"r18");  // Was da
asm("sts 0x0d12,r18");
asm("ldi r18,0x60":::"r18");  // Was b0
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1050 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x20":::"r18");  // Was 60
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1051 
asm("ldi r18,0x7a":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0xe0":::"r18");  // Was 20
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1052 
asm("ldi r18,0xfa":::"r18");  // Was 7a
asm("sts 0x0d12,r18");
asm("ldi r18,0xa0":::"r18");  // Was e0
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1053 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1054 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1055 
asm("ldi r18,0xe0":::"r18");  // Was a0
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1056 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x20":::"r18");  // Was e0
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 6a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1057 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0xe0":::"r18");  // Was 20
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1058 
asm("ldi r18,0xa0":::"r18");  // Was e0
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1059 
asm("ldi r18,0xea":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x60":::"r18");  // Was a0
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1060 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0x20":::"r18");  // Was 60
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1061 
asm("ldi r18,0x6a":::"r18");  // Was aa
asm("sts 0x0d12,r18");
asm("ldi r18,0xe0":::"r18");  // Was 20
asm("sts 0x0d16,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1062 
asm("ldi r18,0xea":::"r18");  // Was 6a
asm("sts 0x0d12,r18");
asm("ldi r18,0xa0":::"r18");  // Was e0
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1063 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1064 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d12,r18");
asm("ldi r18,0x7a":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1065 
asm("ldi r18,0xe0":::"r18");  // Was a0
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1066 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0x20":::"r18");  // Was e0
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was 7a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1067 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d12,r18");
asm("ldi r18,0xe0":::"r18");  // Was 20
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1068 
asm("ldi r18,0xa0":::"r18");  // Was e0
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1069 
asm("ldi r18,0xfa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0x60":::"r18");  // Was a0
asm("sts 0x0d16,r18");
asm("ldi r18,0xda":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1070 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x20":::"r18");  // Was 60
asm("sts 0x0d16,r18");
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1071 
asm("ldi r18,0x7a":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0xe0":::"r18");  // Was 20
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1072 
asm("ldi r18,0xfa":::"r18");  // Was 7a
asm("sts 0x0d12,r18");
asm("ldi r18,0xa0":::"r18");  // Was e0
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1073 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1074 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0x5a":::"r18");  // Was da
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1075 
asm("ldi r18,0xe0":::"r18");  // Was a0
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1076 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x20":::"r18");  // Was e0
asm("sts 0x0d16,r18");
asm("ldi r18,0x9a":::"r18");  // Was 5a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1077 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0xe0":::"r18");  // Was 20
asm("sts 0x0d16,r18");
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1078 
asm("ldi r18,0xa0":::"r18");  // Was e0
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1079 
asm("ldi r18,0xfe":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x5c":::"r18");  // Was a0
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was da
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1080 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x1c":::"r18");  // Was 5c
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1081 
asm("ldi r18,0x7e":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xdc":::"r18");  // Was 1c
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1082 
asm("ldi r18,0xfe":::"r18");  // Was 7e
asm("sts 0x0d12,r18");
asm("ldi r18,0x9c":::"r18");  // Was dc
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1083 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1084 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0x7e":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1085 
asm("ldi r18,0xdc":::"r18");  // Was 9c
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1086 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x1c":::"r18");  // Was dc
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was 7e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1087 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xdc":::"r18");  // Was 1c
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1088 
asm("ldi r18,0x9c":::"r18");  // Was dc
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1089 
asm("ldi r18,0xee":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x4c":::"r18");  // Was 9c
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1090 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x0c":::"r18");  // Was 4c
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1091 
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xcc":::"r18");  // Was 0c
asm("sts 0x0d16,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1092 
asm("ldi r18,0xee":::"r18");  // Was 6e
asm("sts 0x0d12,r18");
asm("ldi r18,0x8c":::"r18");  // Was cc
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1093 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1094 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1095 
asm("ldi r18,0xcc":::"r18");  // Was 8c
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1096 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x0c":::"r18");  // Was cc
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was 6e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1097 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xcc":::"r18");  // Was 0c
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1098 
asm("ldi r18,0x8c":::"r18");  // Was cc
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1099 
asm("ldi r18,0xde":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x7c":::"r18");  // Was 8c
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1100 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0x3c":::"r18");  // Was 7c
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1101 
asm("ldi r18,0x5e":::"r18");  // Was 9e
asm("sts 0x0d12,r18");
asm("ldi r18,0xfc":::"r18");  // Was 3c
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1102 
asm("ldi r18,0xde":::"r18");  // Was 5e
asm("sts 0x0d12,r18");
asm("ldi r18,0xbc":::"r18");  // Was fc
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1103 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1104 
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1105 
asm("ldi r18,0xfc":::"r18");  // Was bc
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1106 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0x3c":::"r18");  // Was fc
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was 6e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1107 
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d12,r18");
asm("ldi r18,0xfc":::"r18");  // Was 3c
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1108 
asm("ldi r18,0xbc":::"r18");  // Was fc
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1109 
asm("ldi r18,0xfe":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0x6c":::"r18");  // Was bc
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1110 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x2c":::"r18");  // Was 6c
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1111 
asm("ldi r18,0x7e":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xec":::"r18");  // Was 2c
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1112 
asm("ldi r18,0xfe":::"r18");  // Was 7e
asm("sts 0x0d12,r18");
asm("ldi r18,0xac":::"r18");  // Was ec
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1113 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1114 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1115 
asm("ldi r18,0xec":::"r18");  // Was ac
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1116 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x2c":::"r18");  // Was ec
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was 6e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1117 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xec":::"r18");  // Was 2c
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1118 
asm("ldi r18,0xac":::"r18");  // Was ec
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1119 
asm("ldi r18,0xee":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x6c":::"r18");  // Was ac
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1120 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x2c":::"r18");  // Was 6c
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1121 
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xec":::"r18");  // Was 2c
asm("sts 0x0d16,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1122 
asm("ldi r18,0xee":::"r18");  // Was 6e
asm("sts 0x0d12,r18");
asm("ldi r18,0xac":::"r18");  // Was ec
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1123 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1124 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0x7e":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1125 
asm("ldi r18,0xec":::"r18");  // Was ac
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1126 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x2c":::"r18");  // Was ec
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was 7e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1127 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xec":::"r18");  // Was 2c
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1128 
asm("ldi r18,0xac":::"r18");  // Was ec
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1129 
asm("ldi r18,0xfe":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x6c":::"r18");  // Was ac
asm("sts 0x0d16,r18");
asm("ldi r18,0xde":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1130 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x2c":::"r18");  // Was 6c
asm("sts 0x0d16,r18");
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1131 
asm("ldi r18,0x7e":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xec":::"r18");  // Was 2c
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1132 
asm("ldi r18,0xfe":::"r18");  // Was 7e
asm("sts 0x0d12,r18");
asm("ldi r18,0xac":::"r18");  // Was ec
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1133 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1134 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0x5e":::"r18");  // Was de
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1135 
asm("ldi r18,0xec":::"r18");  // Was ac
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1136 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x2c":::"r18");  // Was ec
asm("sts 0x0d16,r18");
asm("ldi r18,0x9e":::"r18");  // Was 5e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1137 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xec":::"r18");  // Was 2c
asm("sts 0x0d16,r18");
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1138 
asm("ldi r18,0xac":::"r18");  // Was ec
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1139 
asm("ldi r18,0x58":::"r18");  // Was ac
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was de
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1140 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x18":::"r18");  // Was 58
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1141 
asm("ldi r18,0x7e":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xd8":::"r18");  // Was 18
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1142 
asm("ldi r18,0xfe":::"r18");  // Was 7e
asm("sts 0x0d12,r18");
asm("ldi r18,0x98":::"r18");  // Was d8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1143 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1144 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0x7e":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1145 
asm("ldi r18,0xd8":::"r18");  // Was 98
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1146 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x18":::"r18");  // Was d8
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was 7e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1147 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xd8":::"r18");  // Was 18
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1148 
asm("ldi r18,0x98":::"r18");  // Was d8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1149 
asm("ldi r18,0xee":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x48":::"r18");  // Was 98
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1150 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x08":::"r18");  // Was 48
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1151 
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xc8":::"r18");  // Was 08
asm("sts 0x0d16,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1152 
asm("ldi r18,0xee":::"r18");  // Was 6e
asm("sts 0x0d12,r18");
asm("ldi r18,0x88":::"r18");  // Was c8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1153 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1154 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1155 
asm("ldi r18,0xc8":::"r18");  // Was 88
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1156 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x08":::"r18");  // Was c8
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was 6e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1157 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xc8":::"r18");  // Was 08
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1158 
asm("ldi r18,0x88":::"r18");  // Was c8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1159 
asm("ldi r18,0xde":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x78":::"r18");  // Was 88
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1160 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0x38":::"r18");  // Was 78
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1161 
asm("ldi r18,0x5e":::"r18");  // Was 9e
asm("sts 0x0d12,r18");
asm("ldi r18,0xf8":::"r18");  // Was 38
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1162 
asm("ldi r18,0xde":::"r18");  // Was 5e
asm("sts 0x0d12,r18");
asm("ldi r18,0xb8":::"r18");  // Was f8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1163 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1164 
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1165 
asm("ldi r18,0xf8":::"r18");  // Was b8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1166 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0x38":::"r18");  // Was f8
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was 6e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1167 
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d12,r18");
asm("ldi r18,0xf8":::"r18");  // Was 38
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1168 
asm("ldi r18,0xb8":::"r18");  // Was f8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1169 
asm("ldi r18,0xfe":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0x68":::"r18");  // Was b8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1170 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x28":::"r18");  // Was 68
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1171 
asm("ldi r18,0x7e":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xe8":::"r18");  // Was 28
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1172 
asm("ldi r18,0xfe":::"r18");  // Was 7e
asm("sts 0x0d12,r18");
asm("ldi r18,0xa8":::"r18");  // Was e8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1173 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1174 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1175 
asm("ldi r18,0xe8":::"r18");  // Was a8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1176 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x28":::"r18");  // Was e8
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was 6e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1177 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xe8":::"r18");  // Was 28
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1178 
asm("ldi r18,0xa8":::"r18");  // Was e8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1179 
asm("ldi r18,0xee":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x68":::"r18");  // Was a8
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1180 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x28":::"r18");  // Was 68
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1181 
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xe8":::"r18");  // Was 28
asm("sts 0x0d16,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1182 
asm("ldi r18,0xee":::"r18");  // Was 6e
asm("sts 0x0d12,r18");
asm("ldi r18,0xa8":::"r18");  // Was e8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1183 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1184 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0x7e":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1185 
asm("ldi r18,0xe8":::"r18");  // Was a8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1186 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x28":::"r18");  // Was e8
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was 7e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1187 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xe8":::"r18");  // Was 28
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1188 
asm("ldi r18,0xa8":::"r18");  // Was e8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1189 
asm("ldi r18,0xfe":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x68":::"r18");  // Was a8
asm("sts 0x0d16,r18");
asm("ldi r18,0xde":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1190 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x28":::"r18");  // Was 68
asm("sts 0x0d16,r18");
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1191 
asm("ldi r18,0x7e":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xe8":::"r18");  // Was 28
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1192 
asm("ldi r18,0xfe":::"r18");  // Was 7e
asm("sts 0x0d12,r18");
asm("ldi r18,0xa8":::"r18");  // Was e8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1193 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1194 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0x5e":::"r18");  // Was de
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1195 
asm("ldi r18,0xe8":::"r18");  // Was a8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1196 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x28":::"r18");  // Was e8
asm("sts 0x0d16,r18");
asm("ldi r18,0x9e":::"r18");  // Was 5e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1197 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xe8":::"r18");  // Was 28
asm("sts 0x0d16,r18");
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1198 
asm("ldi r18,0xa8":::"r18");  // Was e8
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1199 
asm("ldi r18,0xfd":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x57":::"r18");  // Was a8
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was de
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1200 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x17":::"r18");  // Was 57
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1201 
asm("ldi r18,0x7d":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0xd7":::"r18");  // Was 17
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1202 
asm("ldi r18,0xfd":::"r18");  // Was 7d
asm("sts 0x0d12,r18");
asm("ldi r18,0x97":::"r18");  // Was d7
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1203 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1204 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0x7e":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1205 
asm("ldi r18,0xd7":::"r18");  // Was 97
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1206 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x17":::"r18");  // Was d7
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was 7e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1207 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0xd7":::"r18");  // Was 17
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1208 
asm("ldi r18,0x97":::"r18");  // Was d7
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1209 
asm("ldi r18,0xed":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x47":::"r18");  // Was 97
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1210 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0x07":::"r18");  // Was 47
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1211 
asm("ldi r18,0x6d":::"r18");  // Was ad
asm("sts 0x0d12,r18");
asm("ldi r18,0xc7":::"r18");  // Was 07
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1212 
asm("ldi r18,0xed":::"r18");  // Was 6d
asm("sts 0x0d12,r18");
asm("ldi r18,0x87":::"r18");  // Was c7
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1213 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1214 
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1215 
asm("ldi r18,0xc7":::"r18");  // Was 87
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1216 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0x07":::"r18");  // Was c7
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was 6e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1217 
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d12,r18");
asm("ldi r18,0xc7":::"r18");  // Was 07
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1218 
asm("ldi r18,0x87":::"r18");  // Was c7
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1219 
asm("ldi r18,0xdd":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0x77":::"r18");  // Was 87
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1220 
asm("ldi r18,0x9d":::"r18");  // Was dd
asm("sts 0x0d12,r18");
asm("ldi r18,0x37":::"r18");  // Was 77
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1221 
asm("ldi r18,0x5d":::"r18");  // Was 9d
asm("sts 0x0d12,r18");
asm("ldi r18,0xf7":::"r18");  // Was 37
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1222 
asm("ldi r18,0xdd":::"r18");  // Was 5d
asm("sts 0x0d12,r18");
asm("ldi r18,0xb7":::"r18");  // Was f7
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1223 
asm("ldi r18,0x9d":::"r18");  // Was dd
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1224 
asm("ldi r18,0xdd":::"r18");  // Was 9d
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1225 
asm("ldi r18,0xf7":::"r18");  // Was b7
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1226 
asm("ldi r18,0x9d":::"r18");  // Was dd
asm("sts 0x0d12,r18");
asm("ldi r18,0x37":::"r18");  // Was f7
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was 6e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1227 
asm("ldi r18,0xdd":::"r18");  // Was 9d
asm("sts 0x0d12,r18");
asm("ldi r18,0xf7":::"r18");  // Was 37
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1228 
asm("ldi r18,0xb7":::"r18");  // Was f7
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1229 
asm("ldi r18,0xfd":::"r18");  // Was dd
asm("sts 0x0d12,r18");
asm("ldi r18,0x67":::"r18");  // Was b7
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1230 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x27":::"r18");  // Was 67
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1231 
asm("ldi r18,0x7d":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0xe7":::"r18");  // Was 27
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1232 
asm("ldi r18,0xfd":::"r18");  // Was 7d
asm("sts 0x0d12,r18");
asm("ldi r18,0xa7":::"r18");  // Was e7
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1233 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1234 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1235 
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1236 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x27":::"r18");  // Was e7
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was 6e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1237 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0xe7":::"r18");  // Was 27
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1238 
asm("ldi r18,0xa7":::"r18");  // Was e7
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1239 
asm("ldi r18,0xed":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x67":::"r18");  // Was a7
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1240 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0x27":::"r18");  // Was 67
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1241 
asm("ldi r18,0x6d":::"r18");  // Was ad
asm("sts 0x0d12,r18");
asm("ldi r18,0xe7":::"r18");  // Was 27
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1242 
asm("ldi r18,0xed":::"r18");  // Was 6d
asm("sts 0x0d12,r18");
asm("ldi r18,0xa7":::"r18");  // Was e7
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1243 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1244 
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d12,r18");
asm("ldi r18,0x7e":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1245 
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1246 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0x27":::"r18");  // Was e7
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was 7e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1247 
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d12,r18");
asm("ldi r18,0xe7":::"r18");  // Was 27
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1248 
asm("ldi r18,0xa7":::"r18");  // Was e7
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1249 
asm("ldi r18,0xfd":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0x67":::"r18");  // Was a7
asm("sts 0x0d16,r18");
asm("ldi r18,0xde":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1250 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x27":::"r18");  // Was 67
asm("sts 0x0d16,r18");
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1251 
asm("ldi r18,0x7d":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0xe7":::"r18");  // Was 27
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1252 
asm("ldi r18,0xfd":::"r18");  // Was 7d
asm("sts 0x0d12,r18");
asm("ldi r18,0xa7":::"r18");  // Was e7
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1253 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1254 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0x5e":::"r18");  // Was de
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1255 
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1256 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x27":::"r18");  // Was e7
asm("sts 0x0d16,r18");
asm("ldi r18,0x9e":::"r18");  // Was 5e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1257 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0xe7":::"r18");  // Was 27
asm("sts 0x0d16,r18");
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1258 
asm("ldi r18,0xa7":::"r18");  // Was e7
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1259 
asm("ldi r18,0xf9":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x53":::"r18");  // Was a7
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was de
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1260 
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d12,r18");
asm("ldi r18,0x13":::"r18");  // Was 53
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1261 
asm("ldi r18,0x79":::"r18");  // Was b9
asm("sts 0x0d12,r18");
asm("ldi r18,0xd3":::"r18");  // Was 13
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1262 
asm("ldi r18,0xf9":::"r18");  // Was 79
asm("sts 0x0d12,r18");
asm("ldi r18,0x93":::"r18");  // Was d3
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1263 
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1264 
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d12,r18");
asm("ldi r18,0x7a":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1265 
asm("ldi r18,0xd3":::"r18");  // Was 93
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1266 
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d12,r18");
asm("ldi r18,0x13":::"r18");  // Was d3
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was 7a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1267 
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d12,r18");
asm("ldi r18,0xd3":::"r18");  // Was 13
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1268 
asm("ldi r18,0x93":::"r18");  // Was d3
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1269 
asm("ldi r18,0xe9":::"r18");  // Was f9
asm("sts 0x0d12,r18");
asm("ldi r18,0x43":::"r18");  // Was 93
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x82":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1270 
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d12,r18");
asm("ldi r18,0x03":::"r18");  // Was 43
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x02":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1271 
asm("ldi r18,0x69":::"r18");  // Was a9
asm("sts 0x0d12,r18");
asm("ldi r18,0xc3":::"r18");  // Was 03
asm("sts 0x0d16,r18");
asm("ldi r18,0x82":::"r18");  // Was 02
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1272 
asm("ldi r18,0xe9":::"r18");  // Was 69
asm("sts 0x0d12,r18");
asm("ldi r18,0x83":::"r18");  // Was c3
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1273 
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x02":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1274 
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x82":::"r18");  // Was 02
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1275 
asm("ldi r18,0xc3":::"r18");  // Was 83
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1276 
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d12,r18");
asm("ldi r18,0x03":::"r18");  // Was c3
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 6a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1277 
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d12,r18");
asm("ldi r18,0xc3":::"r18");  // Was 03
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1278 
asm("ldi r18,0x83":::"r18");  // Was c3
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1279 
asm("ldi r18,0xd9":::"r18");  // Was e9
asm("sts 0x0d12,r18");
asm("ldi r18,0x73":::"r18");  // Was 83
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1280 
asm("ldi r18,0x99":::"r18");  // Was d9
asm("sts 0x0d12,r18");
asm("ldi r18,0x33":::"r18");  // Was 73
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1281 
asm("ldi r18,0x59":::"r18");  // Was 99
asm("sts 0x0d12,r18");
asm("ldi r18,0xf3":::"r18");  // Was 33
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1282 
asm("ldi r18,0xd9":::"r18");  // Was 59
asm("sts 0x0d12,r18");
asm("ldi r18,0xb3":::"r18");  // Was f3
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1283 
asm("ldi r18,0x99":::"r18");  // Was d9
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1284 
asm("ldi r18,0xd9":::"r18");  // Was 99
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1285 
asm("ldi r18,0xf3":::"r18");  // Was b3
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1286 
asm("ldi r18,0x99":::"r18");  // Was d9
asm("sts 0x0d12,r18");
asm("ldi r18,0x33":::"r18");  // Was f3
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 6a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1287 
asm("ldi r18,0xd9":::"r18");  // Was 99
asm("sts 0x0d12,r18");
asm("ldi r18,0xf3":::"r18");  // Was 33
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1288 
asm("ldi r18,0xb3":::"r18");  // Was f3
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1289 
asm("ldi r18,0xf9":::"r18");  // Was d9
asm("sts 0x0d12,r18");
asm("ldi r18,0x63":::"r18");  // Was b3
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1290 
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d12,r18");
asm("ldi r18,0x23":::"r18");  // Was 63
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1291 
asm("ldi r18,0x79":::"r18");  // Was b9
asm("sts 0x0d12,r18");
asm("ldi r18,0xe3":::"r18");  // Was 23
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1292 
asm("ldi r18,0xf9":::"r18");  // Was 79
asm("sts 0x0d12,r18");
asm("ldi r18,0xa3":::"r18");  // Was e3
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1293 
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1294 
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1295 
asm("ldi r18,0xe3":::"r18");  // Was a3
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1296 
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d12,r18");
asm("ldi r18,0x23":::"r18");  // Was e3
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 6a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1297 
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d12,r18");
asm("ldi r18,0xe3":::"r18");  // Was 23
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1298 
asm("ldi r18,0xa3":::"r18");  // Was e3
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1299 
asm("ldi r18,0xe9":::"r18");  // Was f9
asm("sts 0x0d12,r18");
asm("ldi r18,0x63":::"r18");  // Was a3
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x82":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1300 
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d12,r18");
asm("ldi r18,0x23":::"r18");  // Was 63
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x02":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1301 
asm("ldi r18,0x69":::"r18");  // Was a9
asm("sts 0x0d12,r18");
asm("ldi r18,0xe3":::"r18");  // Was 23
asm("sts 0x0d16,r18");
asm("ldi r18,0x82":::"r18");  // Was 02
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1302 
asm("ldi r18,0xe9":::"r18");  // Was 69
asm("sts 0x0d12,r18");
asm("ldi r18,0xa3":::"r18");  // Was e3
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1303 
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("ldi r18,0x02":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1304 
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d12,r18");
asm("ldi r18,0x7a":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x82":::"r18");  // Was 02
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1305 
asm("ldi r18,0xe3":::"r18");  // Was a3
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1306 
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d12,r18");
asm("ldi r18,0x23":::"r18");  // Was e3
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was 7a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1307 
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d12,r18");
asm("ldi r18,0xe3":::"r18");  // Was 23
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1308 
asm("ldi r18,0xa3":::"r18");  // Was e3
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1309 
asm("ldi r18,0xf9":::"r18");  // Was e9
asm("sts 0x0d12,r18");
asm("ldi r18,0x63":::"r18");  // Was a3
asm("sts 0x0d16,r18");
asm("ldi r18,0xda":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1310 
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d12,r18");
asm("ldi r18,0x23":::"r18");  // Was 63
asm("sts 0x0d16,r18");
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1311 
asm("ldi r18,0x79":::"r18");  // Was b9
asm("sts 0x0d12,r18");
asm("ldi r18,0xe3":::"r18");  // Was 23
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1312 
asm("ldi r18,0xf9":::"r18");  // Was 79
asm("sts 0x0d12,r18");
asm("ldi r18,0xa3":::"r18");  // Was e3
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1313 
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d12,r18");
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1314 
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d12,r18");
asm("ldi r18,0x5a":::"r18");  // Was da
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1315 
asm("ldi r18,0xe3":::"r18");  // Was a3
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1316 
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d12,r18");
asm("ldi r18,0x23":::"r18");  // Was e3
asm("sts 0x0d16,r18");
asm("ldi r18,0x9a":::"r18");  // Was 5a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1317 
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d12,r18");
asm("ldi r18,0xe3":::"r18");  // Was 23
asm("sts 0x0d16,r18");
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1318 
asm("ldi r18,0xa3":::"r18");  // Was e3
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1319 
asm("ldi r18,0xf5":::"r18");  // Was f9
asm("sts 0x0d12,r18");
asm("ldi r18,0x5f":::"r18");  // Was a3
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was da
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1320 
asm("ldi r18,0xb5":::"r18");  // Was f5
asm("sts 0x0d12,r18");
asm("ldi r18,0x1f":::"r18");  // Was 5f
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1321 
asm("ldi r18,0x75":::"r18");  // Was b5
asm("sts 0x0d12,r18");
asm("ldi r18,0xdf":::"r18");  // Was 1f
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1322 
asm("ldi r18,0xf5":::"r18");  // Was 75
asm("sts 0x0d12,r18");
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1323 
asm("ldi r18,0xb5":::"r18");  // Was f5
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1324 
asm("ldi r18,0xf5":::"r18");  // Was b5
asm("sts 0x0d12,r18");
asm("ldi r18,0x7a":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1325 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1326 
asm("ldi r18,0xb5":::"r18");  // Was f5
asm("sts 0x0d12,r18");
asm("ldi r18,0x1f":::"r18");  // Was df
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was 7a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1327 
asm("ldi r18,0xf5":::"r18");  // Was b5
asm("sts 0x0d12,r18");
asm("ldi r18,0xdf":::"r18");  // Was 1f
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1328 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1329 
asm("ldi r18,0xe5":::"r18");  // Was f5
asm("sts 0x0d12,r18");
asm("ldi r18,0x4f":::"r18");  // Was 9f
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1330 
asm("ldi r18,0xa5":::"r18");  // Was e5
asm("sts 0x0d12,r18");
asm("ldi r18,0x0f":::"r18");  // Was 4f
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1331 
asm("ldi r18,0x65":::"r18");  // Was a5
asm("sts 0x0d12,r18");
asm("ldi r18,0xcf":::"r18");  // Was 0f
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1332 
asm("ldi r18,0xe5":::"r18");  // Was 65
asm("sts 0x0d12,r18");
asm("ldi r18,0x8f":::"r18");  // Was cf
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1333 
asm("ldi r18,0xa5":::"r18");  // Was e5
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1334 
asm("ldi r18,0xe5":::"r18");  // Was a5
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1335 
asm("ldi r18,0xcf":::"r18");  // Was 8f
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1336 
asm("ldi r18,0xa5":::"r18");  // Was e5
asm("sts 0x0d12,r18");
asm("ldi r18,0x0f":::"r18");  // Was cf
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 6a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1337 
asm("ldi r18,0xe5":::"r18");  // Was a5
asm("sts 0x0d12,r18");
asm("ldi r18,0xcf":::"r18");  // Was 0f
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1338 
asm("ldi r18,0x8f":::"r18");  // Was cf
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1339 
asm("ldi r18,0xd5":::"r18");  // Was e5
asm("sts 0x0d12,r18");
asm("ldi r18,0x7f":::"r18");  // Was 8f
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1340 
asm("ldi r18,0x95":::"r18");  // Was d5
asm("sts 0x0d12,r18");
asm("ldi r18,0x3f":::"r18");  // Was 7f
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1341 
asm("ldi r18,0x55":::"r18");  // Was 95
asm("sts 0x0d12,r18");
asm("ldi r18,0xff":::"r18");  // Was 3f
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1342 
asm("ldi r18,0xd5":::"r18");  // Was 55
asm("sts 0x0d12,r18");
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1343 
asm("ldi r18,0x95":::"r18");  // Was d5
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1344 
asm("ldi r18,0xd5":::"r18");  // Was 95
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1345 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1346 
asm("ldi r18,0x95":::"r18");  // Was d5
asm("sts 0x0d12,r18");
asm("ldi r18,0x3f":::"r18");  // Was ff
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 6a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1347 
asm("ldi r18,0xd5":::"r18");  // Was 95
asm("sts 0x0d12,r18");
asm("ldi r18,0xff":::"r18");  // Was 3f
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1348 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1349 
asm("ldi r18,0xf5":::"r18");  // Was d5
asm("sts 0x0d12,r18");
asm("ldi r18,0x6f":::"r18");  // Was bf
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1350 
asm("ldi r18,0xb5":::"r18");  // Was f5
asm("sts 0x0d12,r18");
asm("ldi r18,0x2f":::"r18");  // Was 6f
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1351 
asm("ldi r18,0x75":::"r18");  // Was b5
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was 2f
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1352 
asm("ldi r18,0xf5":::"r18");  // Was 75
asm("sts 0x0d12,r18");
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1353 
asm("ldi r18,0xb5":::"r18");  // Was f5
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1354 
asm("ldi r18,0xf5":::"r18");  // Was b5
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1355 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1356 
asm("ldi r18,0xb5":::"r18");  // Was f5
asm("sts 0x0d12,r18");
asm("ldi r18,0x2f":::"r18");  // Was ef
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 6a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1357 
asm("ldi r18,0xf5":::"r18");  // Was b5
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was 2f
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1358 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1359 
asm("ldi r18,0xe5":::"r18");  // Was f5
asm("sts 0x0d12,r18");
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1360 
asm("ldi r18,0xa5":::"r18");  // Was e5
asm("sts 0x0d12,r18");
asm("ldi r18,0x2f":::"r18");  // Was 6f
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1361 
asm("ldi r18,0x65":::"r18");  // Was a5
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was 2f
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1362 
asm("ldi r18,0xe5":::"r18");  // Was 65
asm("sts 0x0d12,r18");
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1363 
asm("ldi r18,0xa5":::"r18");  // Was e5
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1364 
asm("ldi r18,0xe5":::"r18");  // Was a5
asm("sts 0x0d12,r18");
asm("ldi r18,0x7a":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1365 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1366 
asm("ldi r18,0xa5":::"r18");  // Was e5
asm("sts 0x0d12,r18");
asm("ldi r18,0x2f":::"r18");  // Was ef
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was 7a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1367 
asm("ldi r18,0xe5":::"r18");  // Was a5
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was 2f
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1368 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1369 
asm("ldi r18,0xf5":::"r18");  // Was e5
asm("sts 0x0d12,r18");
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d16,r18");
asm("ldi r18,0xda":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1370 
asm("ldi r18,0xb5":::"r18");  // Was f5
asm("sts 0x0d12,r18");
asm("ldi r18,0x2f":::"r18");  // Was 6f
asm("sts 0x0d16,r18");
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1371 
asm("ldi r18,0x75":::"r18");  // Was b5
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was 2f
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1372 
asm("ldi r18,0xf5":::"r18");  // Was 75
asm("sts 0x0d12,r18");
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1373 
asm("ldi r18,0xb5":::"r18");  // Was f5
asm("sts 0x0d12,r18");
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1374 
asm("ldi r18,0xf5":::"r18");  // Was b5
asm("sts 0x0d12,r18");
asm("ldi r18,0x5a":::"r18");  // Was da
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1375 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1376 
asm("ldi r18,0xb5":::"r18");  // Was f5
asm("sts 0x0d12,r18");
asm("ldi r18,0x2f":::"r18");  // Was ef
asm("sts 0x0d16,r18");
asm("ldi r18,0x9a":::"r18");  // Was 5a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1377 
asm("ldi r18,0xf5":::"r18");  // Was b5
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was 2f
asm("sts 0x0d16,r18");
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1378 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1379 
asm("ldi r18,0xfd":::"r18");  // Was f5
asm("sts 0x0d12,r18");
asm("ldi r18,0x5b":::"r18");  // Was af
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was da
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1380 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x1b":::"r18");  // Was 5b
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1381 
asm("ldi r18,0x7d":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0xdb":::"r18");  // Was 1b
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1382 
asm("ldi r18,0xfd":::"r18");  // Was 7d
asm("sts 0x0d12,r18");
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1383 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1384 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0x7a":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1385 
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1386 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x1b":::"r18");  // Was db
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was 7a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1387 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0xdb":::"r18");  // Was 1b
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1388 
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1389 
asm("ldi r18,0xed":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x4b":::"r18");  // Was 9b
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1390 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0x0b":::"r18");  // Was 4b
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1391 
asm("ldi r18,0x6d":::"r18");  // Was ad
asm("sts 0x0d12,r18");
asm("ldi r18,0xcb":::"r18");  // Was 0b
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1392 
asm("ldi r18,0xed":::"r18");  // Was 6d
asm("sts 0x0d12,r18");
asm("ldi r18,0x8b":::"r18");  // Was cb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1393 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1394 
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1395 
asm("ldi r18,0xcb":::"r18");  // Was 8b
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1396 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0x0b":::"r18");  // Was cb
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 6a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1397 
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d12,r18");
asm("ldi r18,0xcb":::"r18");  // Was 0b
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1398 
asm("ldi r18,0x8b":::"r18");  // Was cb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1399 
asm("ldi r18,0xdd":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0x7b":::"r18");  // Was 8b
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1400 
asm("ldi r18,0x9d":::"r18");  // Was dd
asm("sts 0x0d12,r18");
asm("ldi r18,0x3b":::"r18");  // Was 7b
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1401 
asm("ldi r18,0x5d":::"r18");  // Was 9d
asm("sts 0x0d12,r18");
asm("ldi r18,0xfb":::"r18");  // Was 3b
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1402 
asm("ldi r18,0xdd":::"r18");  // Was 5d
asm("sts 0x0d12,r18");
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1403 
asm("ldi r18,0x9d":::"r18");  // Was dd
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1404 
asm("ldi r18,0xdd":::"r18");  // Was 9d
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1405 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1406 
asm("ldi r18,0x9d":::"r18");  // Was dd
asm("sts 0x0d12,r18");
asm("ldi r18,0x3b":::"r18");  // Was fb
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 6a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1407 
asm("ldi r18,0xdd":::"r18");  // Was 9d
asm("sts 0x0d12,r18");
asm("ldi r18,0xfb":::"r18");  // Was 3b
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1408 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1409 
asm("ldi r18,0xfd":::"r18");  // Was dd
asm("sts 0x0d12,r18");
asm("ldi r18,0x6b":::"r18");  // Was bb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1410 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x2b":::"r18");  // Was 6b
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1411 
asm("ldi r18,0x7d":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was 2b
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1412 
asm("ldi r18,0xfd":::"r18");  // Was 7d
asm("sts 0x0d12,r18");
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1413 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1414 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1415 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1416 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x2b":::"r18");  // Was eb
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 6a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1417 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was 2b
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1418 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1419 
asm("ldi r18,0xed":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x6b":::"r18");  // Was ab
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1420 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0x2b":::"r18");  // Was 6b
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1421 
asm("ldi r18,0x6d":::"r18");  // Was ad
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was 2b
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1422 
asm("ldi r18,0xed":::"r18");  // Was 6d
asm("sts 0x0d12,r18");
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1423 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1424 
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d12,r18");
asm("ldi r18,0x7a":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1425 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1426 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0x2b":::"r18");  // Was eb
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was 7a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1427 
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was 2b
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1428 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1429 
asm("ldi r18,0xfd":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0x6b":::"r18");  // Was ab
asm("sts 0x0d16,r18");
asm("ldi r18,0xda":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1430 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x2b":::"r18");  // Was 6b
asm("sts 0x0d16,r18");
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1431 
asm("ldi r18,0x7d":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was 2b
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1432 
asm("ldi r18,0xfd":::"r18");  // Was 7d
asm("sts 0x0d12,r18");
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1433 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1434 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0x5a":::"r18");  // Was da
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1435 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1436 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x2b":::"r18");  // Was eb
asm("sts 0x0d16,r18");
asm("ldi r18,0x9a":::"r18");  // Was 5a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1437 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was 2b
asm("sts 0x0d16,r18");
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1438 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1439 
asm("ldi r18,0xf9":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x5b":::"r18");  // Was ab
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was da
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1440 
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d12,r18");
asm("ldi r18,0x1b":::"r18");  // Was 5b
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1441 
asm("ldi r18,0x79":::"r18");  // Was b9
asm("sts 0x0d12,r18");
asm("ldi r18,0xdb":::"r18");  // Was 1b
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1442 
asm("ldi r18,0xf9":::"r18");  // Was 79
asm("sts 0x0d12,r18");
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1443 
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1444 
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d12,r18");
asm("ldi r18,0x7e":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1445 
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1446 
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d12,r18");
asm("ldi r18,0x1b":::"r18");  // Was db
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was 7e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1447 
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d12,r18");
asm("ldi r18,0xdb":::"r18");  // Was 1b
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1448 
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1449 
asm("ldi r18,0xe9":::"r18");  // Was f9
asm("sts 0x0d12,r18");
asm("ldi r18,0x4b":::"r18");  // Was 9b
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x82":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1450 
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d12,r18");
asm("ldi r18,0x0b":::"r18");  // Was 4b
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x02":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1451 
asm("ldi r18,0x69":::"r18");  // Was a9
asm("sts 0x0d12,r18");
asm("ldi r18,0xcb":::"r18");  // Was 0b
asm("sts 0x0d16,r18");
asm("ldi r18,0x82":::"r18");  // Was 02
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1452 
asm("ldi r18,0xe9":::"r18");  // Was 69
asm("sts 0x0d12,r18");
asm("ldi r18,0x8b":::"r18");  // Was cb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1453 
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("ldi r18,0x02":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1454 
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x82":::"r18");  // Was 02
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1455 
asm("ldi r18,0xcb":::"r18");  // Was 8b
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1456 
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d12,r18");
asm("ldi r18,0x0b":::"r18");  // Was cb
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was 6e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1457 
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d12,r18");
asm("ldi r18,0xcb":::"r18");  // Was 0b
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1458 
asm("ldi r18,0x8b":::"r18");  // Was cb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1459 
asm("ldi r18,0xd9":::"r18");  // Was e9
asm("sts 0x0d12,r18");
asm("ldi r18,0x7b":::"r18");  // Was 8b
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1460 
asm("ldi r18,0x99":::"r18");  // Was d9
asm("sts 0x0d12,r18");
asm("ldi r18,0x3b":::"r18");  // Was 7b
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1461 
asm("ldi r18,0x59":::"r18");  // Was 99
asm("sts 0x0d12,r18");
asm("ldi r18,0xfb":::"r18");  // Was 3b
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1462 
asm("ldi r18,0xd9":::"r18");  // Was 59
asm("sts 0x0d12,r18");
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1463 
asm("ldi r18,0x99":::"r18");  // Was d9
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1464 
asm("ldi r18,0xd9":::"r18");  // Was 99
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1465 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1466 
asm("ldi r18,0x99":::"r18");  // Was d9
asm("sts 0x0d12,r18");
asm("ldi r18,0x3b":::"r18");  // Was fb
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was 6e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1467 
asm("ldi r18,0xd9":::"r18");  // Was 99
asm("sts 0x0d12,r18");
asm("ldi r18,0xfb":::"r18");  // Was 3b
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1468 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1469 
asm("ldi r18,0xf9":::"r18");  // Was d9
asm("sts 0x0d12,r18");
asm("ldi r18,0x6b":::"r18");  // Was bb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1470 
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d12,r18");
asm("ldi r18,0x2b":::"r18");  // Was 6b
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1471 
asm("ldi r18,0x79":::"r18");  // Was b9
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was 2b
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1472 
asm("ldi r18,0xf9":::"r18");  // Was 79
asm("sts 0x0d12,r18");
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1473 
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1474 
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1475 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1476 
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d12,r18");
asm("ldi r18,0x2b":::"r18");  // Was eb
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was 6e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1477 
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was 2b
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1478 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1479 
asm("ldi r18,0xe9":::"r18");  // Was f9
asm("sts 0x0d12,r18");
asm("ldi r18,0x6b":::"r18");  // Was ab
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x82":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1480 
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d12,r18");
asm("ldi r18,0x2b":::"r18");  // Was 6b
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x02":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1481 
asm("ldi r18,0x69":::"r18");  // Was a9
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was 2b
asm("sts 0x0d16,r18");
asm("ldi r18,0x82":::"r18");  // Was 02
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1482 
asm("ldi r18,0xe9":::"r18");  // Was 69
asm("sts 0x0d12,r18");
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1483 
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("ldi r18,0x02":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1484 
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d12,r18");
asm("ldi r18,0x7e":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x82":::"r18");  // Was 02
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1485 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1486 
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d12,r18");
asm("ldi r18,0x2b":::"r18");  // Was eb
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was 7e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1487 
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was 2b
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1488 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1489 
asm("ldi r18,0xf9":::"r18");  // Was e9
asm("sts 0x0d12,r18");
asm("ldi r18,0x6b":::"r18");  // Was ab
asm("sts 0x0d16,r18");
asm("ldi r18,0xde":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1490 
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d12,r18");
asm("ldi r18,0x2b":::"r18");  // Was 6b
asm("sts 0x0d16,r18");
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1491 
asm("ldi r18,0x79":::"r18");  // Was b9
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was 2b
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1492 
asm("ldi r18,0xf9":::"r18");  // Was 79
asm("sts 0x0d12,r18");
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1493 
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d12,r18");
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1494 
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d12,r18");
asm("ldi r18,0x5e":::"r18");  // Was de
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1495 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1496 
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d12,r18");
asm("ldi r18,0x2b":::"r18");  // Was eb
asm("sts 0x0d16,r18");
asm("ldi r18,0x9e":::"r18");  // Was 5e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1497 
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was 2b
asm("sts 0x0d16,r18");
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1498 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1499 
asm("ldi r18,0xfd":::"r18");  // Was f9
asm("sts 0x0d12,r18");
asm("ldi r18,0x5b":::"r18");  // Was ab
asm("sts 0x0d16,r18");
asm("ldi r18,0xf6":::"r18");  // Was de
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1500 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x1b":::"r18");  // Was 5b
asm("sts 0x0d16,r18");
asm("ldi r18,0xb6":::"r18");  // Was f6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1501 
asm("ldi r18,0x7d":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0xdb":::"r18");  // Was 1b
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1502 
asm("ldi r18,0xfd":::"r18");  // Was 7d
asm("sts 0x0d12,r18");
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1503 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1504 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0x76":::"r18");  // Was f6
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1505 
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1506 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x1b":::"r18");  // Was db
asm("sts 0x0d16,r18");
asm("ldi r18,0xb6":::"r18");  // Was 76
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1507 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0xdb":::"r18");  // Was 1b
asm("sts 0x0d16,r18");
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1508 
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1509 
asm("ldi r18,0xed":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x4b":::"r18");  // Was 9b
asm("sts 0x0d16,r18");
asm("ldi r18,0xe6":::"r18");  // Was f6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1510 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0x0b":::"r18");  // Was 4b
asm("sts 0x0d16,r18");
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1511 
asm("ldi r18,0x6d":::"r18");  // Was ad
asm("sts 0x0d12,r18");
asm("ldi r18,0xcb":::"r18");  // Was 0b
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1512 
asm("ldi r18,0xed":::"r18");  // Was 6d
asm("sts 0x0d12,r18");
asm("ldi r18,0x8b":::"r18");  // Was cb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1513 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1514 
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d12,r18");
asm("ldi r18,0x66":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1515 
asm("ldi r18,0xcb":::"r18");  // Was 8b
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1516 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0x0b":::"r18");  // Was cb
asm("sts 0x0d16,r18");
asm("ldi r18,0xa6":::"r18");  // Was 66
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1517 
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d12,r18");
asm("ldi r18,0xcb":::"r18");  // Was 0b
asm("sts 0x0d16,r18");
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1518 
asm("ldi r18,0x8b":::"r18");  // Was cb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1519 
asm("ldi r18,0xdd":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0x7b":::"r18");  // Was 8b
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1520 
asm("ldi r18,0x9d":::"r18");  // Was dd
asm("sts 0x0d12,r18");
asm("ldi r18,0x3b":::"r18");  // Was 7b
asm("sts 0x0d16,r18");
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1521 
asm("ldi r18,0x5d":::"r18");  // Was 9d
asm("sts 0x0d12,r18");
asm("ldi r18,0xfb":::"r18");  // Was 3b
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1522 
asm("ldi r18,0xdd":::"r18");  // Was 5d
asm("sts 0x0d12,r18");
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1523 
asm("ldi r18,0x9d":::"r18");  // Was dd
asm("sts 0x0d12,r18");
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1524 
asm("ldi r18,0xdd":::"r18");  // Was 9d
asm("sts 0x0d12,r18");
asm("ldi r18,0x66":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1525 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1526 
asm("ldi r18,0x9d":::"r18");  // Was dd
asm("sts 0x0d12,r18");
asm("ldi r18,0x3b":::"r18");  // Was fb
asm("sts 0x0d16,r18");
asm("ldi r18,0xa6":::"r18");  // Was 66
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1527 
asm("ldi r18,0xdd":::"r18");  // Was 9d
asm("sts 0x0d12,r18");
asm("ldi r18,0xfb":::"r18");  // Was 3b
asm("sts 0x0d16,r18");
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1528 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1529 
asm("ldi r18,0xfd":::"r18");  // Was dd
asm("sts 0x0d12,r18");
asm("ldi r18,0x6b":::"r18");  // Was bb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1530 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x2b":::"r18");  // Was 6b
asm("sts 0x0d16,r18");
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1531 
asm("ldi r18,0x7d":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was 2b
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1532 
asm("ldi r18,0xfd":::"r18");  // Was 7d
asm("sts 0x0d12,r18");
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1533 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1534 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0x66":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1535 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1536 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x2b":::"r18");  // Was eb
asm("sts 0x0d16,r18");
asm("ldi r18,0xa6":::"r18");  // Was 66
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1537 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was 2b
asm("sts 0x0d16,r18");
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1538 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1539 
asm("ldi r18,0xed":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x6b":::"r18");  // Was ab
asm("sts 0x0d16,r18");
asm("ldi r18,0xf6":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1540 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0x2b":::"r18");  // Was 6b
asm("sts 0x0d16,r18");
asm("ldi r18,0xb6":::"r18");  // Was f6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1541 
asm("ldi r18,0x6d":::"r18");  // Was ad
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was 2b
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1542 
asm("ldi r18,0xed":::"r18");  // Was 6d
asm("sts 0x0d12,r18");
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1543 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1544 
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d12,r18");
asm("ldi r18,0x76":::"r18");  // Was f6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1545 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1546 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0x2b":::"r18");  // Was eb
asm("sts 0x0d16,r18");
asm("ldi r18,0xb6":::"r18");  // Was 76
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1547 
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was 2b
asm("sts 0x0d16,r18");
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1548 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1549 
asm("ldi r18,0xfd":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0x6b":::"r18");  // Was ab
asm("sts 0x0d16,r18");
asm("ldi r18,0xd6":::"r18");  // Was f6
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1550 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x2b":::"r18");  // Was 6b
asm("sts 0x0d16,r18");
asm("ldi r18,0x96":::"r18");  // Was d6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1551 
asm("ldi r18,0x7d":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was 2b
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1552 
asm("ldi r18,0xfd":::"r18");  // Was 7d
asm("sts 0x0d12,r18");
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1553 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0xd6":::"r18");  // Was 96
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1554 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0x56":::"r18");  // Was d6
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1555 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1556 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x2b":::"r18");  // Was eb
asm("sts 0x0d16,r18");
asm("ldi r18,0x96":::"r18");  // Was 56
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1557 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was 2b
asm("sts 0x0d16,r18");
asm("ldi r18,0xd6":::"r18");  // Was 96
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1558 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1559 
asm("ldi r18,0x5f":::"r18");  // Was ab
asm("sts 0x0d16,r18");
asm("ldi r18,0xf6":::"r18");  // Was d6
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1560 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x1f":::"r18");  // Was 5f
asm("sts 0x0d16,r18");
asm("ldi r18,0xb6":::"r18");  // Was f6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1561 
asm("ldi r18,0x7d":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0xdf":::"r18");  // Was 1f
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1562 
asm("ldi r18,0xfd":::"r18");  // Was 7d
asm("sts 0x0d12,r18");
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1563 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1564 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0x76":::"r18");  // Was f6
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1565 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1566 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x1f":::"r18");  // Was df
asm("sts 0x0d16,r18");
asm("ldi r18,0xb6":::"r18");  // Was 76
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1567 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0xdf":::"r18");  // Was 1f
asm("sts 0x0d16,r18");
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1568 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1569 
asm("ldi r18,0xed":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x4f":::"r18");  // Was 9f
asm("sts 0x0d16,r18");
asm("ldi r18,0xe6":::"r18");  // Was f6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1570 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0x0f":::"r18");  // Was 4f
asm("sts 0x0d16,r18");
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1571 
asm("ldi r18,0x6d":::"r18");  // Was ad
asm("sts 0x0d12,r18");
asm("ldi r18,0xcf":::"r18");  // Was 0f
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1572 
asm("ldi r18,0xed":::"r18");  // Was 6d
asm("sts 0x0d12,r18");
asm("ldi r18,0x8f":::"r18");  // Was cf
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1573 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1574 
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d12,r18");
asm("ldi r18,0x66":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1575 
asm("ldi r18,0xcf":::"r18");  // Was 8f
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1576 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0x0f":::"r18");  // Was cf
asm("sts 0x0d16,r18");
asm("ldi r18,0xa6":::"r18");  // Was 66
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1577 
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d12,r18");
asm("ldi r18,0xcf":::"r18");  // Was 0f
asm("sts 0x0d16,r18");
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1578 
asm("ldi r18,0x8f":::"r18");  // Was cf
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1579 
asm("ldi r18,0xdd":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0x7f":::"r18");  // Was 8f
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1580 
asm("ldi r18,0x9d":::"r18");  // Was dd
asm("sts 0x0d12,r18");
asm("ldi r18,0x3f":::"r18");  // Was 7f
asm("sts 0x0d16,r18");
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1581 
asm("ldi r18,0x5d":::"r18");  // Was 9d
asm("sts 0x0d12,r18");
asm("ldi r18,0xff":::"r18");  // Was 3f
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1582 
asm("ldi r18,0xdd":::"r18");  // Was 5d
asm("sts 0x0d12,r18");
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1583 
asm("ldi r18,0x9d":::"r18");  // Was dd
asm("sts 0x0d12,r18");
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1584 
asm("ldi r18,0xdd":::"r18");  // Was 9d
asm("sts 0x0d12,r18");
asm("ldi r18,0x66":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1585 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1586 
asm("ldi r18,0x9d":::"r18");  // Was dd
asm("sts 0x0d12,r18");
asm("ldi r18,0x3f":::"r18");  // Was ff
asm("sts 0x0d16,r18");
asm("ldi r18,0xa6":::"r18");  // Was 66
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1587 
asm("ldi r18,0xdd":::"r18");  // Was 9d
asm("sts 0x0d12,r18");
asm("ldi r18,0xff":::"r18");  // Was 3f
asm("sts 0x0d16,r18");
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1588 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1589 
asm("ldi r18,0xfd":::"r18");  // Was dd
asm("sts 0x0d12,r18");
asm("ldi r18,0x6f":::"r18");  // Was bf
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1590 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x2f":::"r18");  // Was 6f
asm("sts 0x0d16,r18");
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1591 
asm("ldi r18,0x7d":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was 2f
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1592 
asm("ldi r18,0xfd":::"r18");  // Was 7d
asm("sts 0x0d12,r18");
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1593 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1594 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0x66":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1595 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1596 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x2f":::"r18");  // Was ef
asm("sts 0x0d16,r18");
asm("ldi r18,0xa6":::"r18");  // Was 66
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1597 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was 2f
asm("sts 0x0d16,r18");
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1598 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1599 
asm("ldi r18,0xed":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d16,r18");
asm("ldi r18,0xf6":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1600 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0x2f":::"r18");  // Was 6f
asm("sts 0x0d16,r18");
asm("ldi r18,0xb6":::"r18");  // Was f6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1601 
asm("ldi r18,0x6d":::"r18");  // Was ad
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was 2f
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1602 
asm("ldi r18,0xed":::"r18");  // Was 6d
asm("sts 0x0d12,r18");
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1603 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1604 
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d12,r18");
asm("ldi r18,0x76":::"r18");  // Was f6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1605 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1606 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0x2f":::"r18");  // Was ef
asm("sts 0x0d16,r18");
asm("ldi r18,0xb6":::"r18");  // Was 76
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1607 
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was 2f
asm("sts 0x0d16,r18");
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1608 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1609 
asm("ldi r18,0xfd":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d16,r18");
asm("ldi r18,0xd6":::"r18");  // Was f6
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1610 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x2f":::"r18");  // Was 6f
asm("sts 0x0d16,r18");
asm("ldi r18,0x96":::"r18");  // Was d6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1611 
asm("ldi r18,0x7d":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was 2f
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1612 
asm("ldi r18,0xfd":::"r18");  // Was 7d
asm("sts 0x0d12,r18");
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1613 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0xd6":::"r18");  // Was 96
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1614 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0x56":::"r18");  // Was d6
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1615 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1616 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x2f":::"r18");  // Was ef
asm("sts 0x0d16,r18");
asm("ldi r18,0x96":::"r18");  // Was 56
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1617 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was 2f
asm("sts 0x0d16,r18");
asm("ldi r18,0xd6":::"r18");  // Was 96
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1618 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1619 
asm("ldi r18,0xf9":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x53":::"r18");  // Was af
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was d6
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1620 
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d12,r18");
asm("ldi r18,0x13":::"r18");  // Was 53
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1621 
asm("ldi r18,0x79":::"r18");  // Was b9
asm("sts 0x0d12,r18");
asm("ldi r18,0xd3":::"r18");  // Was 13
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1622 
asm("ldi r18,0xf9":::"r18");  // Was 79
asm("sts 0x0d12,r18");
asm("ldi r18,0x93":::"r18");  // Was d3
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1623 
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1624 
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d12,r18");
asm("ldi r18,0x7a":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1625 
asm("ldi r18,0xd3":::"r18");  // Was 93
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1626 
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d12,r18");
asm("ldi r18,0x13":::"r18");  // Was d3
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was 7a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1627 
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d12,r18");
asm("ldi r18,0xd3":::"r18");  // Was 13
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1628 
asm("ldi r18,0x93":::"r18");  // Was d3
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1629 
asm("ldi r18,0xe9":::"r18");  // Was f9
asm("sts 0x0d12,r18");
asm("ldi r18,0x43":::"r18");  // Was 93
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1630 
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d12,r18");
asm("ldi r18,0x03":::"r18");  // Was 43
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1631 
asm("ldi r18,0x69":::"r18");  // Was a9
asm("sts 0x0d12,r18");
asm("ldi r18,0xc3":::"r18");  // Was 03
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1632 
asm("ldi r18,0xe9":::"r18");  // Was 69
asm("sts 0x0d12,r18");
asm("ldi r18,0x83":::"r18");  // Was c3
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1633 
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1634 
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1635 
asm("ldi r18,0xc3":::"r18");  // Was 83
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1636 
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d12,r18");
asm("ldi r18,0x03":::"r18");  // Was c3
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 6a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1637 
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d12,r18");
asm("ldi r18,0xc3":::"r18");  // Was 03
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1638 
asm("ldi r18,0x83":::"r18");  // Was c3
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1639 
asm("ldi r18,0xd9":::"r18");  // Was e9
asm("sts 0x0d12,r18");
asm("ldi r18,0x73":::"r18");  // Was 83
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1640 
asm("ldi r18,0x99":::"r18");  // Was d9
asm("sts 0x0d12,r18");
asm("ldi r18,0x33":::"r18");  // Was 73
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1641 
asm("ldi r18,0x59":::"r18");  // Was 99
asm("sts 0x0d12,r18");
asm("ldi r18,0xf3":::"r18");  // Was 33
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1642 
asm("ldi r18,0xd9":::"r18");  // Was 59
asm("sts 0x0d12,r18");
asm("ldi r18,0xb3":::"r18");  // Was f3
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1643 
asm("ldi r18,0x99":::"r18");  // Was d9
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1644 
asm("ldi r18,0xd9":::"r18");  // Was 99
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1645 
asm("ldi r18,0xf3":::"r18");  // Was b3
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1646 
asm("ldi r18,0x99":::"r18");  // Was d9
asm("sts 0x0d12,r18");
asm("ldi r18,0x33":::"r18");  // Was f3
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 6a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1647 
asm("ldi r18,0xd9":::"r18");  // Was 99
asm("sts 0x0d12,r18");
asm("ldi r18,0xf3":::"r18");  // Was 33
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1648 
asm("ldi r18,0xb3":::"r18");  // Was f3
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1649 
asm("ldi r18,0xf9":::"r18");  // Was d9
asm("sts 0x0d12,r18");
asm("ldi r18,0x63":::"r18");  // Was b3
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1650 
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d12,r18");
asm("ldi r18,0x23":::"r18");  // Was 63
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1651 
asm("ldi r18,0x79":::"r18");  // Was b9
asm("sts 0x0d12,r18");
asm("ldi r18,0xe3":::"r18");  // Was 23
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1652 
asm("ldi r18,0xf9":::"r18");  // Was 79
asm("sts 0x0d12,r18");
asm("ldi r18,0xa3":::"r18");  // Was e3
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1653 
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1654 
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1655 
asm("ldi r18,0xe3":::"r18");  // Was a3
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1656 
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d12,r18");
asm("ldi r18,0x23":::"r18");  // Was e3
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 6a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1657 
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d12,r18");
asm("ldi r18,0xe3":::"r18");  // Was 23
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1658 
asm("ldi r18,0xa3":::"r18");  // Was e3
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1659 
asm("ldi r18,0xe9":::"r18");  // Was f9
asm("sts 0x0d12,r18");
asm("ldi r18,0x63":::"r18");  // Was a3
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1660 
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d12,r18");
asm("ldi r18,0x23":::"r18");  // Was 63
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1661 
asm("ldi r18,0x69":::"r18");  // Was a9
asm("sts 0x0d12,r18");
asm("ldi r18,0xe3":::"r18");  // Was 23
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1662 
asm("ldi r18,0xe9":::"r18");  // Was 69
asm("sts 0x0d12,r18");
asm("ldi r18,0xa3":::"r18");  // Was e3
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1663 
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1664 
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d12,r18");
asm("ldi r18,0x7a":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1665 
asm("ldi r18,0xe3":::"r18");  // Was a3
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1666 
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d12,r18");
asm("ldi r18,0x23":::"r18");  // Was e3
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was 7a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1667 
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d12,r18");
asm("ldi r18,0xe3":::"r18");  // Was 23
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1668 
asm("ldi r18,0xa3":::"r18");  // Was e3
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1669 
asm("ldi r18,0xf9":::"r18");  // Was e9
asm("sts 0x0d12,r18");
asm("ldi r18,0x63":::"r18");  // Was a3
asm("sts 0x0d16,r18");
asm("ldi r18,0xda":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1670 
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d12,r18");
asm("ldi r18,0x23":::"r18");  // Was 63
asm("sts 0x0d16,r18");
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1671 
asm("ldi r18,0x79":::"r18");  // Was b9
asm("sts 0x0d12,r18");
asm("ldi r18,0xe3":::"r18");  // Was 23
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1672 
asm("ldi r18,0xf9":::"r18");  // Was 79
asm("sts 0x0d12,r18");
asm("ldi r18,0xa3":::"r18");  // Was e3
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1673 
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d12,r18");
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1674 
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d12,r18");
asm("ldi r18,0x5a":::"r18");  // Was da
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1675 
asm("ldi r18,0xe3":::"r18");  // Was a3
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1676 
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d12,r18");
asm("ldi r18,0x23":::"r18");  // Was e3
asm("sts 0x0d16,r18");
asm("ldi r18,0x9a":::"r18");  // Was 5a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1677 
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d12,r18");
asm("ldi r18,0xe3":::"r18");  // Was 23
asm("sts 0x0d16,r18");
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1678 
asm("ldi r18,0xa3":::"r18");  // Was e3
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1679 
asm("ldi r18,0xfd":::"r18");  // Was f9
asm("sts 0x0d12,r18");
asm("ldi r18,0x5f":::"r18");  // Was a3
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was da
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1680 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x1f":::"r18");  // Was 5f
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1681 
asm("ldi r18,0x7d":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0xdf":::"r18");  // Was 1f
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1682 
asm("ldi r18,0xfd":::"r18");  // Was 7d
asm("sts 0x0d12,r18");
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1683 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1684 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0x7e":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1685 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1686 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x1f":::"r18");  // Was df
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was 7e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1687 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0xdf":::"r18");  // Was 1f
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1688 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1689 
asm("ldi r18,0xed":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x4f":::"r18");  // Was 9f
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1690 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0x0f":::"r18");  // Was 4f
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1691 
asm("ldi r18,0x6d":::"r18");  // Was ad
asm("sts 0x0d12,r18");
asm("ldi r18,0xcf":::"r18");  // Was 0f
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1692 
asm("ldi r18,0xed":::"r18");  // Was 6d
asm("sts 0x0d12,r18");
asm("ldi r18,0x8f":::"r18");  // Was cf
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1693 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1694 
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1695 
asm("ldi r18,0xcf":::"r18");  // Was 8f
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1696 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0x0f":::"r18");  // Was cf
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was 6e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1697 
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d12,r18");
asm("ldi r18,0xcf":::"r18");  // Was 0f
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1698 
asm("ldi r18,0x8f":::"r18");  // Was cf
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1699 
asm("ldi r18,0xdd":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0x7f":::"r18");  // Was 8f
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1700 
asm("ldi r18,0x9d":::"r18");  // Was dd
asm("sts 0x0d12,r18");
asm("ldi r18,0x3f":::"r18");  // Was 7f
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1701 
asm("ldi r18,0x5d":::"r18");  // Was 9d
asm("sts 0x0d12,r18");
asm("ldi r18,0xff":::"r18");  // Was 3f
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1702 
asm("ldi r18,0xdd":::"r18");  // Was 5d
asm("sts 0x0d12,r18");
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1703 
asm("ldi r18,0x9d":::"r18");  // Was dd
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1704 
asm("ldi r18,0xdd":::"r18");  // Was 9d
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1705 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1706 
asm("ldi r18,0x9d":::"r18");  // Was dd
asm("sts 0x0d12,r18");
asm("ldi r18,0x3f":::"r18");  // Was ff
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was 6e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1707 
asm("ldi r18,0xdd":::"r18");  // Was 9d
asm("sts 0x0d12,r18");
asm("ldi r18,0xff":::"r18");  // Was 3f
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1708 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1709 
asm("ldi r18,0xfd":::"r18");  // Was dd
asm("sts 0x0d12,r18");
asm("ldi r18,0x6f":::"r18");  // Was bf
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1710 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x2f":::"r18");  // Was 6f
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1711 
asm("ldi r18,0x7d":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was 2f
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1712 
asm("ldi r18,0xfd":::"r18");  // Was 7d
asm("sts 0x0d12,r18");
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1713 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1714 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1715 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1716 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x2f":::"r18");  // Was ef
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was 6e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1717 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was 2f
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1718 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1719 
asm("ldi r18,0xed":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1720 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0x2f":::"r18");  // Was 6f
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1721 
asm("ldi r18,0x6d":::"r18");  // Was ad
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was 2f
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1722 
asm("ldi r18,0xed":::"r18");  // Was 6d
asm("sts 0x0d12,r18");
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1723 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1724 
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d12,r18");
asm("ldi r18,0x7e":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1725 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1726 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0x2f":::"r18");  // Was ef
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was 7e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1727 
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was 2f
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1728 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1729 
asm("ldi r18,0xfd":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d16,r18");
asm("ldi r18,0xde":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1730 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x2f":::"r18");  // Was 6f
asm("sts 0x0d16,r18");
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1731 
asm("ldi r18,0x7d":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was 2f
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1732 
asm("ldi r18,0xfd":::"r18");  // Was 7d
asm("sts 0x0d12,r18");
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1733 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1734 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0x5e":::"r18");  // Was de
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1735 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1736 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x2f":::"r18");  // Was ef
asm("sts 0x0d16,r18");
asm("ldi r18,0x9e":::"r18");  // Was 5e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1737 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was 2f
asm("sts 0x0d16,r18");
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1738 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1739 
asm("ldi r18,0x5b":::"r18");  // Was af
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was de
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1740 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x1b":::"r18");  // Was 5b
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1741 
asm("ldi r18,0x7d":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0xdb":::"r18");  // Was 1b
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1742 
asm("ldi r18,0xfd":::"r18");  // Was 7d
asm("sts 0x0d12,r18");
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1743 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1744 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0x7e":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1745 
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1746 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x1b":::"r18");  // Was db
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was 7e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1747 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0xdb":::"r18");  // Was 1b
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1748 
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1749 
asm("ldi r18,0xed":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x4b":::"r18");  // Was 9b
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1750 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0x0b":::"r18");  // Was 4b
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1751 
asm("ldi r18,0x6d":::"r18");  // Was ad
asm("sts 0x0d12,r18");
asm("ldi r18,0xcb":::"r18");  // Was 0b
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1752 
asm("ldi r18,0xed":::"r18");  // Was 6d
asm("sts 0x0d12,r18");
asm("ldi r18,0x8b":::"r18");  // Was cb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1753 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1754 
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1755 
asm("ldi r18,0xcb":::"r18");  // Was 8b
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1756 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0x0b":::"r18");  // Was cb
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was 6e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1757 
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d12,r18");
asm("ldi r18,0xcb":::"r18");  // Was 0b
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1758 
asm("ldi r18,0x8b":::"r18");  // Was cb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1759 
asm("ldi r18,0xdd":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0x7b":::"r18");  // Was 8b
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1760 
asm("ldi r18,0x9d":::"r18");  // Was dd
asm("sts 0x0d12,r18");
asm("ldi r18,0x3b":::"r18");  // Was 7b
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1761 
asm("ldi r18,0x5d":::"r18");  // Was 9d
asm("sts 0x0d12,r18");
asm("ldi r18,0xfb":::"r18");  // Was 3b
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1762 
asm("ldi r18,0xdd":::"r18");  // Was 5d
asm("sts 0x0d12,r18");
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1763 
asm("ldi r18,0x9d":::"r18");  // Was dd
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1764 
asm("ldi r18,0xdd":::"r18");  // Was 9d
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1765 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1766 
asm("ldi r18,0x9d":::"r18");  // Was dd
asm("sts 0x0d12,r18");
asm("ldi r18,0x3b":::"r18");  // Was fb
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was 6e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1767 
asm("ldi r18,0xdd":::"r18");  // Was 9d
asm("sts 0x0d12,r18");
asm("ldi r18,0xfb":::"r18");  // Was 3b
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1768 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1769 
asm("ldi r18,0xfd":::"r18");  // Was dd
asm("sts 0x0d12,r18");
asm("ldi r18,0x6b":::"r18");  // Was bb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1770 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x2b":::"r18");  // Was 6b
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1771 
asm("ldi r18,0x7d":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was 2b
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1772 
asm("ldi r18,0xfd":::"r18");  // Was 7d
asm("sts 0x0d12,r18");
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1773 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1774 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1775 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1776 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x2b":::"r18");  // Was eb
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was 6e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1777 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was 2b
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1778 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1779 
asm("ldi r18,0xed":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x6b":::"r18");  // Was ab
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1780 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0x2b":::"r18");  // Was 6b
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1781 
asm("ldi r18,0x6d":::"r18");  // Was ad
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was 2b
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1782 
asm("ldi r18,0xed":::"r18");  // Was 6d
asm("sts 0x0d12,r18");
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1783 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1784 
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d12,r18");
asm("ldi r18,0x7e":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1785 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1786 
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0x2b":::"r18");  // Was eb
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was 7e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1787 
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was 2b
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1788 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1789 
asm("ldi r18,0xfd":::"r18");  // Was ed
asm("sts 0x0d12,r18");
asm("ldi r18,0x6b":::"r18");  // Was ab
asm("sts 0x0d16,r18");
asm("ldi r18,0xde":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1790 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x2b":::"r18");  // Was 6b
asm("sts 0x0d16,r18");
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1791 
asm("ldi r18,0x7d":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was 2b
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1792 
asm("ldi r18,0xfd":::"r18");  // Was 7d
asm("sts 0x0d12,r18");
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1793 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1794 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0x5e":::"r18");  // Was de
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1795 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1796 
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x2b":::"r18");  // Was eb
asm("sts 0x0d16,r18");
asm("ldi r18,0x9e":::"r18");  // Was 5e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1797 
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was 2b
asm("sts 0x0d16,r18");
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1798 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1799 
asm("ldi r18,0xff":::"r18");  // Was fd
asm("sts 0x0d12,r18");
asm("ldi r18,0x56":::"r18");  // Was ab
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was de
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1800 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x16":::"r18");  // Was 56
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1801 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xd6":::"r18");  // Was 16
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1802 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0x96":::"r18");  // Was d6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1803 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1804 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x7e":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1805 
asm("ldi r18,0xd6":::"r18");  // Was 96
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1806 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x16":::"r18");  // Was d6
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was 7e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1807 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xd6":::"r18");  // Was 16
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1808 
asm("ldi r18,0x96":::"r18");  // Was d6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1809 
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x46":::"r18");  // Was 96
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1810 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x06":::"r18");  // Was 46
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1811 
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xc6":::"r18");  // Was 06
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1812 
asm("ldi r18,0xef":::"r18");  // Was 6f
asm("sts 0x0d12,r18");
asm("ldi r18,0x86":::"r18");  // Was c6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1813 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1814 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1815 
asm("ldi r18,0xc6":::"r18");  // Was 86
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1816 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x06":::"r18");  // Was c6
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was 6e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1817 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xc6":::"r18");  // Was 06
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1818 
asm("ldi r18,0x86":::"r18");  // Was c6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1819 
asm("ldi r18,0xdf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x76":::"r18");  // Was 86
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1820 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x36":::"r18");  // Was 76
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1821 
asm("ldi r18,0x5f":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0xf6":::"r18");  // Was 36
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1822 
asm("ldi r18,0xdf":::"r18");  // Was 5f
asm("sts 0x0d12,r18");
asm("ldi r18,0xb6":::"r18");  // Was f6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1823 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1824 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1825 
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1826 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x36":::"r18");  // Was f6
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was 6e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1827 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0xf6":::"r18");  // Was 36
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1828 
asm("ldi r18,0xb6":::"r18");  // Was f6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1829 
asm("ldi r18,0xff":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x66":::"r18");  // Was b6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1830 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x26":::"r18");  // Was 66
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1831 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xe6":::"r18");  // Was 26
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1832 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1833 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1834 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1835 
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1836 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x26":::"r18");  // Was e6
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was 6e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1837 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xe6":::"r18");  // Was 26
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1838 
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1839 
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x66":::"r18");  // Was a6
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1840 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x26":::"r18");  // Was 66
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1841 
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xe6":::"r18");  // Was 26
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1842 
asm("ldi r18,0xef":::"r18");  // Was 6f
asm("sts 0x0d12,r18");
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1843 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1844 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0x7e":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1845 
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1846 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x26":::"r18");  // Was e6
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was 7e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1847 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xe6":::"r18");  // Was 26
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1848 
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1849 
asm("ldi r18,0xff":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x66":::"r18");  // Was a6
asm("sts 0x0d16,r18");
asm("ldi r18,0xde":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1850 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x26":::"r18");  // Was 66
asm("sts 0x0d16,r18");
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1851 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xe6":::"r18");  // Was 26
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1852 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1853 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1854 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x5e":::"r18");  // Was de
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1855 
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1856 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x26":::"r18");  // Was e6
asm("sts 0x0d16,r18");
asm("ldi r18,0x9e":::"r18");  // Was 5e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1857 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xe6":::"r18");  // Was 26
asm("sts 0x0d16,r18");
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1858 
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1859 
asm("ldi r18,0xfb":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x52":::"r18");  // Was a6
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was de
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1860 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x12":::"r18");  // Was 52
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1861 
asm("ldi r18,0x7b":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xd2":::"r18");  // Was 12
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1862 
asm("ldi r18,0xfb":::"r18");  // Was 7b
asm("sts 0x0d12,r18");
asm("ldi r18,0x92":::"r18");  // Was d2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1863 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1864 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0x7a":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1865 
asm("ldi r18,0xd2":::"r18");  // Was 92
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1866 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x12":::"r18");  // Was d2
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was 7a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1867 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xd2":::"r18");  // Was 12
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1868 
asm("ldi r18,0x92":::"r18");  // Was d2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1869 
asm("ldi r18,0xeb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x42":::"r18");  // Was 92
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x82":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1870 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x02":::"r18");  // Was 42
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x02":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1871 
asm("ldi r18,0x6b":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0xc2":::"r18");  // Was 02
asm("sts 0x0d16,r18");
asm("ldi r18,0x82":::"r18");  // Was 02
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1872 
asm("ldi r18,0xeb":::"r18");  // Was 6b
asm("sts 0x0d12,r18");
asm("ldi r18,0x82":::"r18");  // Was c2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1873 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x02":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1874 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x82":::"r18");  // Was 02
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1875 
asm("ldi r18,0xc2":::"r18");  // Was 82
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1876 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x02":::"r18");  // Was c2
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 6a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1877 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0xc2":::"r18");  // Was 02
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1878 
asm("ldi r18,0x82":::"r18");  // Was c2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1879 
asm("ldi r18,0xdb":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x72":::"r18");  // Was 82
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1880 
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d12,r18");
asm("ldi r18,0x32":::"r18");  // Was 72
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1881 
asm("ldi r18,0x5b":::"r18");  // Was 9b
asm("sts 0x0d12,r18");
asm("ldi r18,0xf2":::"r18");  // Was 32
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1882 
asm("ldi r18,0xdb":::"r18");  // Was 5b
asm("sts 0x0d12,r18");
asm("ldi r18,0xb2":::"r18");  // Was f2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1883 
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1884 
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1885 
asm("ldi r18,0xf2":::"r18");  // Was b2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1886 
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d12,r18");
asm("ldi r18,0x32":::"r18");  // Was f2
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 6a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1887 
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d12,r18");
asm("ldi r18,0xf2":::"r18");  // Was 32
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1888 
asm("ldi r18,0xb2":::"r18");  // Was f2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1889 
asm("ldi r18,0xfb":::"r18");  // Was db
asm("sts 0x0d12,r18");
asm("ldi r18,0x62":::"r18");  // Was b2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1890 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x22":::"r18");  // Was 62
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1891 
asm("ldi r18,0x7b":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xe2":::"r18");  // Was 22
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1892 
asm("ldi r18,0xfb":::"r18");  // Was 7b
asm("sts 0x0d12,r18");
asm("ldi r18,0xa2":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1893 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1894 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1895 
asm("ldi r18,0xe2":::"r18");  // Was a2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1896 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x22":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 6a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1897 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xe2":::"r18");  // Was 22
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1898 
asm("ldi r18,0xa2":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1899 
asm("ldi r18,0xeb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x62":::"r18");  // Was a2
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x82":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1900 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x22":::"r18");  // Was 62
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x02":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1901 
asm("ldi r18,0x6b":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0xe2":::"r18");  // Was 22
asm("sts 0x0d16,r18");
asm("ldi r18,0x82":::"r18");  // Was 02
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1902 
asm("ldi r18,0xeb":::"r18");  // Was 6b
asm("sts 0x0d12,r18");
asm("ldi r18,0xa2":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1903 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("ldi r18,0x02":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1904 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0x7a":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x82":::"r18");  // Was 02
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1905 
asm("ldi r18,0xe2":::"r18");  // Was a2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1906 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x22":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was 7a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1907 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0xe2":::"r18");  // Was 22
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1908 
asm("ldi r18,0xa2":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1909 
asm("ldi r18,0xfb":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x62":::"r18");  // Was a2
asm("sts 0x0d16,r18");
asm("ldi r18,0xda":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1910 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x22":::"r18");  // Was 62
asm("sts 0x0d16,r18");
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1911 
asm("ldi r18,0x7b":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xe2":::"r18");  // Was 22
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1912 
asm("ldi r18,0xfb":::"r18");  // Was 7b
asm("sts 0x0d12,r18");
asm("ldi r18,0xa2":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1913 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1914 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0x5a":::"r18");  // Was da
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1915 
asm("ldi r18,0xe2":::"r18");  // Was a2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1916 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x22":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("ldi r18,0x9a":::"r18");  // Was 5a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1917 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xe2":::"r18");  // Was 22
asm("sts 0x0d16,r18");
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1918 
asm("ldi r18,0xa2":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1919 
asm("ldi r18,0xf7":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x5e":::"r18");  // Was a2
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was da
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1920 
asm("ldi r18,0xb7":::"r18");  // Was f7
asm("sts 0x0d12,r18");
asm("ldi r18,0x1e":::"r18");  // Was 5e
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1921 
asm("ldi r18,0x77":::"r18");  // Was b7
asm("sts 0x0d12,r18");
asm("ldi r18,0xde":::"r18");  // Was 1e
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1922 
asm("ldi r18,0xf7":::"r18");  // Was 77
asm("sts 0x0d12,r18");
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1923 
asm("ldi r18,0xb7":::"r18");  // Was f7
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1924 
asm("ldi r18,0xf7":::"r18");  // Was b7
asm("sts 0x0d12,r18");
asm("ldi r18,0x7a":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1925 
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1926 
asm("ldi r18,0xb7":::"r18");  // Was f7
asm("sts 0x0d12,r18");
asm("ldi r18,0x1e":::"r18");  // Was de
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was 7a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1927 
asm("ldi r18,0xf7":::"r18");  // Was b7
asm("sts 0x0d12,r18");
asm("ldi r18,0xde":::"r18");  // Was 1e
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1928 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1929 
asm("ldi r18,0xe7":::"r18");  // Was f7
asm("sts 0x0d12,r18");
asm("ldi r18,0x4e":::"r18");  // Was 9e
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1930 
asm("ldi r18,0xa7":::"r18");  // Was e7
asm("sts 0x0d12,r18");
asm("ldi r18,0x0e":::"r18");  // Was 4e
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1931 
asm("ldi r18,0x67":::"r18");  // Was a7
asm("sts 0x0d12,r18");
asm("ldi r18,0xce":::"r18");  // Was 0e
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1932 
asm("ldi r18,0xe7":::"r18");  // Was 67
asm("sts 0x0d12,r18");
asm("ldi r18,0x8e":::"r18");  // Was ce
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1933 
asm("ldi r18,0xa7":::"r18");  // Was e7
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1934 
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1935 
asm("ldi r18,0xce":::"r18");  // Was 8e
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1936 
asm("ldi r18,0xa7":::"r18");  // Was e7
asm("sts 0x0d12,r18");
asm("ldi r18,0x0e":::"r18");  // Was ce
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 6a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1937 
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d12,r18");
asm("ldi r18,0xce":::"r18");  // Was 0e
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1938 
asm("ldi r18,0x8e":::"r18");  // Was ce
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1939 
asm("ldi r18,0xd7":::"r18");  // Was e7
asm("sts 0x0d12,r18");
asm("ldi r18,0x7e":::"r18");  // Was 8e
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1940 
asm("ldi r18,0x97":::"r18");  // Was d7
asm("sts 0x0d12,r18");
asm("ldi r18,0x3e":::"r18");  // Was 7e
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1941 
asm("ldi r18,0x57":::"r18");  // Was 97
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was 3e
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1942 
asm("ldi r18,0xd7":::"r18");  // Was 57
asm("sts 0x0d12,r18");
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1943 
asm("ldi r18,0x97":::"r18");  // Was d7
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1944 
asm("ldi r18,0xd7":::"r18");  // Was 97
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1945 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1946 
asm("ldi r18,0x97":::"r18");  // Was d7
asm("sts 0x0d12,r18");
asm("ldi r18,0x3e":::"r18");  // Was fe
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 6a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1947 
asm("ldi r18,0xd7":::"r18");  // Was 97
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was 3e
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1948 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1949 
asm("ldi r18,0xf7":::"r18");  // Was d7
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was be
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1950 
asm("ldi r18,0xb7":::"r18");  // Was f7
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was 6e
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1951 
asm("ldi r18,0x77":::"r18");  // Was b7
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1952 
asm("ldi r18,0xf7":::"r18");  // Was 77
asm("sts 0x0d12,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1953 
asm("ldi r18,0xb7":::"r18");  // Was f7
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1954 
asm("ldi r18,0xf7":::"r18");  // Was b7
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1955 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1956 
asm("ldi r18,0xb7":::"r18");  // Was f7
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 6a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1957 
asm("ldi r18,0xf7":::"r18");  // Was b7
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1958 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1959 
asm("ldi r18,0xe7":::"r18");  // Was f7
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1960 
asm("ldi r18,0xa7":::"r18");  // Was e7
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was 6e
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1961 
asm("ldi r18,0x67":::"r18");  // Was a7
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1962 
asm("ldi r18,0xe7":::"r18");  // Was 67
asm("sts 0x0d12,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1963 
asm("ldi r18,0xa7":::"r18");  // Was e7
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1964 
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d12,r18");
asm("ldi r18,0x7a":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1965 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1966 
asm("ldi r18,0xa7":::"r18");  // Was e7
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was 7a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1967 
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1968 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1969 
asm("ldi r18,0xf7":::"r18");  // Was e7
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("ldi r18,0xda":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1970 
asm("ldi r18,0xb7":::"r18");  // Was f7
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was 6e
asm("sts 0x0d16,r18");
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1971 
asm("ldi r18,0x77":::"r18");  // Was b7
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1972 
asm("ldi r18,0xf7":::"r18");  // Was 77
asm("sts 0x0d12,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1973 
asm("ldi r18,0xb7":::"r18");  // Was f7
asm("sts 0x0d12,r18");
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1974 
asm("ldi r18,0xf7":::"r18");  // Was b7
asm("sts 0x0d12,r18");
asm("ldi r18,0x5a":::"r18");  // Was da
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1975 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1976 
asm("ldi r18,0xb7":::"r18");  // Was f7
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("ldi r18,0x9a":::"r18");  // Was 5a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1977 
asm("ldi r18,0xf7":::"r18");  // Was b7
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1978 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1979 
asm("ldi r18,0xff":::"r18");  // Was f7
asm("sts 0x0d12,r18");
asm("ldi r18,0x5a":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was da
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1980 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x1a":::"r18");  // Was 5a
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1981 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xda":::"r18");  // Was 1a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1982 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1983 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1984 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x7a":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1985 
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1986 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x1a":::"r18");  // Was da
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was 7a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1987 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xda":::"r18");  // Was 1a
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1988 
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1989 
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x4a":::"r18");  // Was 9a
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1990 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x0a":::"r18");  // Was 4a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1991 
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xca":::"r18");  // Was 0a
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1992 
asm("ldi r18,0xef":::"r18");  // Was 6f
asm("sts 0x0d12,r18");
asm("ldi r18,0x8a":::"r18");  // Was ca
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1993 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1994 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 1995 
asm("ldi r18,0xca":::"r18");  // Was 8a
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1996 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x0a":::"r18");  // Was ca
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 6a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1997 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xca":::"r18");  // Was 0a
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 1998 
asm("ldi r18,0x8a":::"r18");  // Was ca
asm("sts 0x0d16,r18");
asm("sleep");  // Step 1999 
asm("ldi r18,0xdf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x7a":::"r18");  // Was 8a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2000 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x3a":::"r18");  // Was 7a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2001 
asm("ldi r18,0x5f":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was 3a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2002 
asm("ldi r18,0xdf":::"r18");  // Was 5f
asm("sts 0x0d12,r18");
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2003 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2004 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2005 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2006 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x3a":::"r18");  // Was fa
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 6a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2007 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was 3a
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2008 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2009 
asm("ldi r18,0xff":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ba
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2010 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was 6a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2011 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2012 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2013 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2014 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2015 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2016 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 6a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2017 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2018 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2019 
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2020 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was 6a
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2021 
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2022 
asm("ldi r18,0xef":::"r18");  // Was 6f
asm("sts 0x0d12,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2023 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2024 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0x7a":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2025 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2026 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was 7a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2027 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2028 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2029 
asm("ldi r18,0xff":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("ldi r18,0xda":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2030 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was 6a
asm("sts 0x0d16,r18");
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2031 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2032 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2033 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2034 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x5a":::"r18");  // Was da
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2035 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2036 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("ldi r18,0x9a":::"r18");  // Was 5a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2037 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2038 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2039 
asm("ldi r18,0xfb":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x5a":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was da
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2040 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x1a":::"r18");  // Was 5a
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2041 
asm("ldi r18,0x7b":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xda":::"r18");  // Was 1a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2042 
asm("ldi r18,0xfb":::"r18");  // Was 7b
asm("sts 0x0d12,r18");
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2043 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2044 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0x7e":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2045 
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2046 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x1a":::"r18");  // Was da
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was 7e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2047 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xda":::"r18");  // Was 1a
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2048 
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2049 
asm("ldi r18,0xeb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x4a":::"r18");  // Was 9a
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x82":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2050 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x0a":::"r18");  // Was 4a
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x02":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2051 
asm("ldi r18,0x6b":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0xca":::"r18");  // Was 0a
asm("sts 0x0d16,r18");
asm("ldi r18,0x82":::"r18");  // Was 02
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2052 
asm("ldi r18,0xeb":::"r18");  // Was 6b
asm("sts 0x0d12,r18");
asm("ldi r18,0x8a":::"r18");  // Was ca
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2053 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("ldi r18,0x02":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2054 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x82":::"r18");  // Was 02
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2055 
asm("ldi r18,0xca":::"r18");  // Was 8a
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2056 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x0a":::"r18");  // Was ca
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was 6e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2057 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0xca":::"r18");  // Was 0a
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2058 
asm("ldi r18,0x8a":::"r18");  // Was ca
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2059 
asm("ldi r18,0xdb":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x7a":::"r18");  // Was 8a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2060 
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d12,r18");
asm("ldi r18,0x3a":::"r18");  // Was 7a
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2061 
asm("ldi r18,0x5b":::"r18");  // Was 9b
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was 3a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2062 
asm("ldi r18,0xdb":::"r18");  // Was 5b
asm("sts 0x0d12,r18");
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2063 
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2064 
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2065 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2066 
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d12,r18");
asm("ldi r18,0x3a":::"r18");  // Was fa
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was 6e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2067 
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was 3a
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2068 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2069 
asm("ldi r18,0xfb":::"r18");  // Was db
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ba
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2070 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was 6a
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2071 
asm("ldi r18,0x7b":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2072 
asm("ldi r18,0xfb":::"r18");  // Was 7b
asm("sts 0x0d12,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2073 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2074 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2075 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2076 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was 6e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2077 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2078 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2079 
asm("ldi r18,0xeb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x82":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2080 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was 6a
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x02":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2081 
asm("ldi r18,0x6b":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0x82":::"r18");  // Was 02
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2082 
asm("ldi r18,0xeb":::"r18");  // Was 6b
asm("sts 0x0d12,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2083 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("ldi r18,0x02":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2084 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0x7e":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x82":::"r18");  // Was 02
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2085 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2086 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was 7e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2087 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2088 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2089 
asm("ldi r18,0xfb":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("ldi r18,0xde":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2090 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was 6a
asm("sts 0x0d16,r18");
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2091 
asm("ldi r18,0x7b":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2092 
asm("ldi r18,0xfb":::"r18");  // Was 7b
asm("sts 0x0d12,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2093 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2094 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0x5e":::"r18");  // Was de
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2095 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2096 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("ldi r18,0x9e":::"r18");  // Was 5e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2097 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2098 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2099 
asm("ldi r18,0xff":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x5a":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("ldi r18,0xf6":::"r18");  // Was de
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2100 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x1a":::"r18");  // Was 5a
asm("sts 0x0d16,r18");
asm("ldi r18,0xb6":::"r18");  // Was f6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2101 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xda":::"r18");  // Was 1a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2102 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2103 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2104 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x76":::"r18");  // Was f6
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2105 
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2106 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x1a":::"r18");  // Was da
asm("sts 0x0d16,r18");
asm("ldi r18,0xb6":::"r18");  // Was 76
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2107 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xda":::"r18");  // Was 1a
asm("sts 0x0d16,r18");
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2108 
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2109 
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x4a":::"r18");  // Was 9a
asm("sts 0x0d16,r18");
asm("ldi r18,0xe6":::"r18");  // Was f6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2110 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x0a":::"r18");  // Was 4a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2111 
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xca":::"r18");  // Was 0a
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2112 
asm("ldi r18,0xef":::"r18");  // Was 6f
asm("sts 0x0d12,r18");
asm("ldi r18,0x8a":::"r18");  // Was ca
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2113 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2114 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0x66":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2115 
asm("ldi r18,0xca":::"r18");  // Was 8a
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2116 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x0a":::"r18");  // Was ca
asm("sts 0x0d16,r18");
asm("ldi r18,0xa6":::"r18");  // Was 66
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2117 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xca":::"r18");  // Was 0a
asm("sts 0x0d16,r18");
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2118 
asm("ldi r18,0x8a":::"r18");  // Was ca
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2119 
asm("ldi r18,0xdf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x7a":::"r18");  // Was 8a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2120 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x3a":::"r18");  // Was 7a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2121 
asm("ldi r18,0x5f":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was 3a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2122 
asm("ldi r18,0xdf":::"r18");  // Was 5f
asm("sts 0x0d12,r18");
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2123 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2124 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0x66":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2125 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2126 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x3a":::"r18");  // Was fa
asm("sts 0x0d16,r18");
asm("ldi r18,0xa6":::"r18");  // Was 66
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2127 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was 3a
asm("sts 0x0d16,r18");
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2128 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2129 
asm("ldi r18,0xff":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ba
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2130 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was 6a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2131 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2132 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2133 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2134 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x66":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2135 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2136 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("ldi r18,0xa6":::"r18");  // Was 66
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2137 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2138 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2139 
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("ldi r18,0xf6":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2140 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was 6a
asm("sts 0x0d16,r18");
asm("ldi r18,0xb6":::"r18");  // Was f6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2141 
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2142 
asm("ldi r18,0xef":::"r18");  // Was 6f
asm("sts 0x0d12,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2143 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2144 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0x76":::"r18");  // Was f6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2145 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2146 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("ldi r18,0xb6":::"r18");  // Was 76
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2147 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2148 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2149 
asm("ldi r18,0xff":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("ldi r18,0xd6":::"r18");  // Was f6
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2150 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was 6a
asm("sts 0x0d16,r18");
asm("ldi r18,0x96":::"r18");  // Was d6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2151 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2152 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2153 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xd6":::"r18");  // Was 96
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2154 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x56":::"r18");  // Was d6
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2155 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2156 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("ldi r18,0x96":::"r18");  // Was 56
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2157 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xd6":::"r18");  // Was 96
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2158 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2159 
asm("ldi r18,0x5e":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("ldi r18,0xf6":::"r18");  // Was d6
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2160 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x1e":::"r18");  // Was 5e
asm("sts 0x0d16,r18");
asm("ldi r18,0xb6":::"r18");  // Was f6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2161 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xde":::"r18");  // Was 1e
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2162 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2163 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2164 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x76":::"r18");  // Was f6
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2165 
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2166 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x1e":::"r18");  // Was de
asm("sts 0x0d16,r18");
asm("ldi r18,0xb6":::"r18");  // Was 76
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2167 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xde":::"r18");  // Was 1e
asm("sts 0x0d16,r18");
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2168 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2169 
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x4e":::"r18");  // Was 9e
asm("sts 0x0d16,r18");
asm("ldi r18,0xe6":::"r18");  // Was f6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2170 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x0e":::"r18");  // Was 4e
asm("sts 0x0d16,r18");
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2171 
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xce":::"r18");  // Was 0e
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2172 
asm("ldi r18,0xef":::"r18");  // Was 6f
asm("sts 0x0d12,r18");
asm("ldi r18,0x8e":::"r18");  // Was ce
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2173 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2174 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0x66":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2175 
asm("ldi r18,0xce":::"r18");  // Was 8e
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2176 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x0e":::"r18");  // Was ce
asm("sts 0x0d16,r18");
asm("ldi r18,0xa6":::"r18");  // Was 66
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2177 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xce":::"r18");  // Was 0e
asm("sts 0x0d16,r18");
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2178 
asm("ldi r18,0x8e":::"r18");  // Was ce
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2179 
asm("ldi r18,0xdf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x7e":::"r18");  // Was 8e
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2180 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x3e":::"r18");  // Was 7e
asm("sts 0x0d16,r18");
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2181 
asm("ldi r18,0x5f":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was 3e
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2182 
asm("ldi r18,0xdf":::"r18");  // Was 5f
asm("sts 0x0d12,r18");
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2183 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2184 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0x66":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2185 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2186 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x3e":::"r18");  // Was fe
asm("sts 0x0d16,r18");
asm("ldi r18,0xa6":::"r18");  // Was 66
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2187 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was 3e
asm("sts 0x0d16,r18");
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2188 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2189 
asm("ldi r18,0xff":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was be
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2190 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was 6e
asm("sts 0x0d16,r18");
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2191 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2192 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2193 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2194 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x66":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2195 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2196 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("ldi r18,0xa6":::"r18");  // Was 66
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2197 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2198 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2199 
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("ldi r18,0xf6":::"r18");  // Was e6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2200 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was 6e
asm("sts 0x0d16,r18");
asm("ldi r18,0xb6":::"r18");  // Was f6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2201 
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2202 
asm("ldi r18,0xef":::"r18");  // Was 6f
asm("sts 0x0d12,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2203 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2204 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0x76":::"r18");  // Was f6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2205 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2206 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("ldi r18,0xb6":::"r18");  // Was 76
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2207 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2208 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2209 
asm("ldi r18,0xff":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("ldi r18,0xd6":::"r18");  // Was f6
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2210 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was 6e
asm("sts 0x0d16,r18");
asm("ldi r18,0x96":::"r18");  // Was d6
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2211 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2212 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2213 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xd6":::"r18");  // Was 96
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2214 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x56":::"r18");  // Was d6
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2215 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2216 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("ldi r18,0x96":::"r18");  // Was 56
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2217 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xd6":::"r18");  // Was 96
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2218 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2219 
asm("ldi r18,0xfb":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x52":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was d6
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2220 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x12":::"r18");  // Was 52
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2221 
asm("ldi r18,0x7b":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xd2":::"r18");  // Was 12
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2222 
asm("ldi r18,0xfb":::"r18");  // Was 7b
asm("sts 0x0d12,r18");
asm("ldi r18,0x92":::"r18");  // Was d2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2223 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2224 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0x7a":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2225 
asm("ldi r18,0xd2":::"r18");  // Was 92
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2226 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x12":::"r18");  // Was d2
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was 7a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2227 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xd2":::"r18");  // Was 12
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2228 
asm("ldi r18,0x92":::"r18");  // Was d2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2229 
asm("ldi r18,0xeb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x42":::"r18");  // Was 92
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2230 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x02":::"r18");  // Was 42
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2231 
asm("ldi r18,0x6b":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0xc2":::"r18");  // Was 02
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2232 
asm("ldi r18,0xeb":::"r18");  // Was 6b
asm("sts 0x0d12,r18");
asm("ldi r18,0x82":::"r18");  // Was c2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2233 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2234 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2235 
asm("ldi r18,0xc2":::"r18");  // Was 82
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2236 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x02":::"r18");  // Was c2
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 6a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2237 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0xc2":::"r18");  // Was 02
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2238 
asm("ldi r18,0x82":::"r18");  // Was c2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2239 
asm("ldi r18,0xdb":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x72":::"r18");  // Was 82
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2240 
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d12,r18");
asm("ldi r18,0x32":::"r18");  // Was 72
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2241 
asm("ldi r18,0x5b":::"r18");  // Was 9b
asm("sts 0x0d12,r18");
asm("ldi r18,0xf2":::"r18");  // Was 32
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2242 
asm("ldi r18,0xdb":::"r18");  // Was 5b
asm("sts 0x0d12,r18");
asm("ldi r18,0xb2":::"r18");  // Was f2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2243 
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2244 
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2245 
asm("ldi r18,0xf2":::"r18");  // Was b2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2246 
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d12,r18");
asm("ldi r18,0x32":::"r18");  // Was f2
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 6a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2247 
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d12,r18");
asm("ldi r18,0xf2":::"r18");  // Was 32
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2248 
asm("ldi r18,0xb2":::"r18");  // Was f2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2249 
asm("ldi r18,0xfb":::"r18");  // Was db
asm("sts 0x0d12,r18");
asm("ldi r18,0x62":::"r18");  // Was b2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2250 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x22":::"r18");  // Was 62
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2251 
asm("ldi r18,0x7b":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xe2":::"r18");  // Was 22
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2252 
asm("ldi r18,0xfb":::"r18");  // Was 7b
asm("sts 0x0d12,r18");
asm("ldi r18,0xa2":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2253 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2254 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2255 
asm("ldi r18,0xe2":::"r18");  // Was a2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2256 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x22":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 6a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2257 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xe2":::"r18");  // Was 22
asm("sts 0x0d16,r18");
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2258 
asm("ldi r18,0xa2":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2259 
asm("ldi r18,0xeb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x62":::"r18");  // Was a2
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was ea
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2260 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x22":::"r18");  // Was 62
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2261 
asm("ldi r18,0x6b":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0xe2":::"r18");  // Was 22
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2262 
asm("ldi r18,0xeb":::"r18");  // Was 6b
asm("sts 0x0d12,r18");
asm("ldi r18,0xa2":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2263 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2264 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0x7a":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2265 
asm("ldi r18,0xe2":::"r18");  // Was a2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2266 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x22":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("ldi r18,0xba":::"r18");  // Was 7a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2267 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0xe2":::"r18");  // Was 22
asm("sts 0x0d16,r18");
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2268 
asm("ldi r18,0xa2":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2269 
asm("ldi r18,0xfb":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x62":::"r18");  // Was a2
asm("sts 0x0d16,r18");
asm("ldi r18,0xda":::"r18");  // Was fa
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2270 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x22":::"r18");  // Was 62
asm("sts 0x0d16,r18");
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2271 
asm("ldi r18,0x7b":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xe2":::"r18");  // Was 22
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2272 
asm("ldi r18,0xfb":::"r18");  // Was 7b
asm("sts 0x0d12,r18");
asm("ldi r18,0xa2":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2273 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2274 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0x5a":::"r18");  // Was da
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2275 
asm("ldi r18,0xe2":::"r18");  // Was a2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2276 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x22":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("ldi r18,0x9a":::"r18");  // Was 5a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2277 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xe2":::"r18");  // Was 22
asm("sts 0x0d16,r18");
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2278 
asm("ldi r18,0xa2":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2279 
asm("ldi r18,0xff":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x5e":::"r18");  // Was a2
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was da
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2280 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x1e":::"r18");  // Was 5e
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2281 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xde":::"r18");  // Was 1e
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2282 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2283 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2284 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x7e":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2285 
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2286 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x1e":::"r18");  // Was de
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was 7e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2287 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xde":::"r18");  // Was 1e
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2288 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2289 
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x4e":::"r18");  // Was 9e
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2290 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x0e":::"r18");  // Was 4e
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2291 
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xce":::"r18");  // Was 0e
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2292 
asm("ldi r18,0xef":::"r18");  // Was 6f
asm("sts 0x0d12,r18");
asm("ldi r18,0x8e":::"r18");  // Was ce
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2293 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2294 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2295 
asm("ldi r18,0xce":::"r18");  // Was 8e
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2296 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x0e":::"r18");  // Was ce
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was 6e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2297 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xce":::"r18");  // Was 0e
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2298 
asm("ldi r18,0x8e":::"r18");  // Was ce
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2299 
asm("ldi r18,0xdf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x7e":::"r18");  // Was 8e
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2300 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x3e":::"r18");  // Was 7e
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2301 
asm("ldi r18,0x5f":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was 3e
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2302 
asm("ldi r18,0xdf":::"r18");  // Was 5f
asm("sts 0x0d12,r18");
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2303 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2304 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2305 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2306 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x3e":::"r18");  // Was fe
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was 6e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2307 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was 3e
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2308 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2309 
asm("ldi r18,0xff":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was be
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2310 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was 6e
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2311 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2312 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2313 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2314 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2315 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2316 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was 6e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2317 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2318 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2319 
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2320 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was 6e
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2321 
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2322 
asm("ldi r18,0xef":::"r18");  // Was 6f
asm("sts 0x0d12,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2323 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2324 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0x7e":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2325 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2326 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was 7e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2327 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2328 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2329 
asm("ldi r18,0xff":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("ldi r18,0xde":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2330 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was 6e
asm("sts 0x0d16,r18");
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2331 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2332 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2333 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2334 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x5e":::"r18");  // Was de
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2335 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2336 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("ldi r18,0x9e":::"r18");  // Was 5e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2337 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2338 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2339 
asm("ldi r18,0x5a":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was de
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2340 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x1a":::"r18");  // Was 5a
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2341 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xda":::"r18");  // Was 1a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2342 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2343 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2344 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x7e":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2345 
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2346 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x1a":::"r18");  // Was da
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was 7e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2347 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xda":::"r18");  // Was 1a
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2348 
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2349 
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x4a":::"r18");  // Was 9a
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2350 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x0a":::"r18");  // Was 4a
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2351 
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xca":::"r18");  // Was 0a
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2352 
asm("ldi r18,0xef":::"r18");  // Was 6f
asm("sts 0x0d12,r18");
asm("ldi r18,0x8a":::"r18");  // Was ca
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2353 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2354 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2355 
asm("ldi r18,0xca":::"r18");  // Was 8a
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2356 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x0a":::"r18");  // Was ca
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was 6e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2357 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xca":::"r18");  // Was 0a
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2358 
asm("ldi r18,0x8a":::"r18");  // Was ca
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2359 
asm("ldi r18,0xdf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x7a":::"r18");  // Was 8a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2360 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x3a":::"r18");  // Was 7a
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2361 
asm("ldi r18,0x5f":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was 3a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2362 
asm("ldi r18,0xdf":::"r18");  // Was 5f
asm("sts 0x0d12,r18");
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2363 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2364 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2365 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2366 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x3a":::"r18");  // Was fa
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was 6e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2367 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was 3a
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2368 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2369 
asm("ldi r18,0xff":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ba
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2370 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was 6a
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2371 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2372 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2373 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2374 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2375 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2376 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("ldi r18,0xae":::"r18");  // Was 6e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2377 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2378 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2379 
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was ee
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2380 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was 6a
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2381 
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2382 
asm("ldi r18,0xef":::"r18");  // Was 6f
asm("sts 0x0d12,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2383 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2384 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0x7e":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2385 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2386 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("ldi r18,0xbe":::"r18");  // Was 7e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2387 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2388 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2389 
asm("ldi r18,0xff":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("ldi r18,0xde":::"r18");  // Was fe
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2390 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was 6a
asm("sts 0x0d16,r18");
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2391 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2392 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2393 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2394 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x5e":::"r18");  // Was de
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2395 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2396 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("ldi r18,0x9e":::"r18");  // Was 5e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2397 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2398 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2399 
asm("ldi r18,0xfe":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x56":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("ldi r18,0xff":::"r18");  // Was de
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2400 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x16":::"r18");  // Was 56
asm("sts 0x0d16,r18");
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2401 
asm("ldi r18,0x7e":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xd6":::"r18");  // Was 16
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2402 
asm("ldi r18,0xfe":::"r18");  // Was 7e
asm("sts 0x0d12,r18");
asm("ldi r18,0x96":::"r18");  // Was d6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2403 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2404 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0x7f":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2405 
asm("ldi r18,0xd6":::"r18");  // Was 96
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2406 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x16":::"r18");  // Was d6
asm("sts 0x0d16,r18");
asm("ldi r18,0xbf":::"r18");  // Was 7f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2407 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xd6":::"r18");  // Was 16
asm("sts 0x0d16,r18");
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2408 
asm("ldi r18,0x96":::"r18");  // Was d6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2409 
asm("ldi r18,0xee":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x46":::"r18");  // Was 96
asm("sts 0x0d16,r18");
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2410 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x06":::"r18");  // Was 46
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2411 
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xc6":::"r18");  // Was 06
asm("sts 0x0d16,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2412 
asm("ldi r18,0xee":::"r18");  // Was 6e
asm("sts 0x0d12,r18");
asm("ldi r18,0x86":::"r18");  // Was c6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2413 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2414 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0x6f":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2415 
asm("ldi r18,0xc6":::"r18");  // Was 86
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2416 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x06":::"r18");  // Was c6
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was 6f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2417 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xc6":::"r18");  // Was 06
asm("sts 0x0d16,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2418 
asm("ldi r18,0x86":::"r18");  // Was c6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2419 
asm("ldi r18,0xde":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x76":::"r18");  // Was 86
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2420 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0x36":::"r18");  // Was 76
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2421 
asm("ldi r18,0x5e":::"r18");  // Was 9e
asm("sts 0x0d12,r18");
asm("ldi r18,0xf6":::"r18");  // Was 36
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2422 
asm("ldi r18,0xde":::"r18");  // Was 5e
asm("sts 0x0d12,r18");
asm("ldi r18,0xb6":::"r18");  // Was f6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2423 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2424 
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d12,r18");
asm("ldi r18,0x6f":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2425 
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2426 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0x36":::"r18");  // Was f6
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was 6f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2427 
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d12,r18");
asm("ldi r18,0xf6":::"r18");  // Was 36
asm("sts 0x0d16,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2428 
asm("ldi r18,0xb6":::"r18");  // Was f6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2429 
asm("ldi r18,0xfe":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0x66":::"r18");  // Was b6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2430 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x26":::"r18");  // Was 66
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2431 
asm("ldi r18,0x7e":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xe6":::"r18");  // Was 26
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2432 
asm("ldi r18,0xfe":::"r18");  // Was 7e
asm("sts 0x0d12,r18");
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2433 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2434 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0x6f":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2435 
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2436 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x26":::"r18");  // Was e6
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was 6f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2437 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xe6":::"r18");  // Was 26
asm("sts 0x0d16,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2438 
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2439 
asm("ldi r18,0xee":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x66":::"r18");  // Was a6
asm("sts 0x0d16,r18");
asm("ldi r18,0xff":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2440 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x26":::"r18");  // Was 66
asm("sts 0x0d16,r18");
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2441 
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xe6":::"r18");  // Was 26
asm("sts 0x0d16,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2442 
asm("ldi r18,0xee":::"r18");  // Was 6e
asm("sts 0x0d12,r18");
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2443 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2444 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0x7f":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2445 
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2446 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x26":::"r18");  // Was e6
asm("sts 0x0d16,r18");
asm("ldi r18,0xbf":::"r18");  // Was 7f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2447 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xe6":::"r18");  // Was 26
asm("sts 0x0d16,r18");
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2448 
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2449 
asm("ldi r18,0xfe":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x66":::"r18");  // Was a6
asm("sts 0x0d16,r18");
asm("ldi r18,0xdf":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2450 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x26":::"r18");  // Was 66
asm("sts 0x0d16,r18");
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2451 
asm("ldi r18,0x7e":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xe6":::"r18");  // Was 26
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2452 
asm("ldi r18,0xfe":::"r18");  // Was 7e
asm("sts 0x0d12,r18");
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2453 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2454 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0x5f":::"r18");  // Was df
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2455 
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2456 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x26":::"r18");  // Was e6
asm("sts 0x0d16,r18");
asm("ldi r18,0x9f":::"r18");  // Was 5f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2457 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xe6":::"r18");  // Was 26
asm("sts 0x0d16,r18");
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2458 
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2459 
asm("ldi r18,0xfa":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x52":::"r18");  // Was a6
asm("sts 0x0d16,r18");
asm("ldi r18,0xfb":::"r18");  // Was df
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa0":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2460 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x12":::"r18");  // Was 52
asm("sts 0x0d16,r18");
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x20":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2461 
asm("ldi r18,0x7a":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0xd2":::"r18");  // Was 12
asm("sts 0x0d16,r18");
asm("ldi r18,0xa0":::"r18");  // Was 20
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2462 
asm("ldi r18,0xfa":::"r18");  // Was 7a
asm("sts 0x0d12,r18");
asm("ldi r18,0x92":::"r18");  // Was d2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2463 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x20":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2464 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0x7b":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa0":::"r18");  // Was 20
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2465 
asm("ldi r18,0xd2":::"r18");  // Was 92
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2466 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x12":::"r18");  // Was d2
asm("sts 0x0d16,r18");
asm("ldi r18,0xbb":::"r18");  // Was 7b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2467 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0xd2":::"r18");  // Was 12
asm("sts 0x0d16,r18");
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2468 
asm("ldi r18,0x92":::"r18");  // Was d2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2469 
asm("ldi r18,0xea":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x42":::"r18");  // Was 92
asm("sts 0x0d16,r18");
asm("ldi r18,0xeb":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x80":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2470 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0x02":::"r18");  // Was 42
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x00":::"r18");  // Was 80
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2471 
asm("ldi r18,0x6a":::"r18");  // Was aa
asm("sts 0x0d12,r18");
asm("ldi r18,0xc2":::"r18");  // Was 02
asm("sts 0x0d16,r18");
asm("ldi r18,0x80":::"r18");  // Was 00
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2472 
asm("ldi r18,0xea":::"r18");  // Was 6a
asm("sts 0x0d12,r18");
asm("ldi r18,0x82":::"r18");  // Was c2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2473 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("ldi r18,0x00":::"r18");  // Was 80
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2474 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d12,r18");
asm("ldi r18,0x6b":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x80":::"r18");  // Was 00
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2475 
asm("ldi r18,0xc2":::"r18");  // Was 82
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2476 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0x02":::"r18");  // Was c2
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was 6b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2477 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d12,r18");
asm("ldi r18,0xc2":::"r18");  // Was 02
asm("sts 0x0d16,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2478 
asm("ldi r18,0x82":::"r18");  // Was c2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2479 
asm("ldi r18,0xda":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0x72":::"r18");  // Was 82
asm("sts 0x0d16,r18");
asm("ldi r18,0xa0":::"r18");  // Was 80
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2480 
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d12,r18");
asm("ldi r18,0x32":::"r18");  // Was 72
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x20":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2481 
asm("ldi r18,0x5a":::"r18");  // Was 9a
asm("sts 0x0d12,r18");
asm("ldi r18,0xf2":::"r18");  // Was 32
asm("sts 0x0d16,r18");
asm("ldi r18,0xa0":::"r18");  // Was 20
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2482 
asm("ldi r18,0xda":::"r18");  // Was 5a
asm("sts 0x0d12,r18");
asm("ldi r18,0xb2":::"r18");  // Was f2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2483 
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("ldi r18,0x20":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2484 
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d12,r18");
asm("ldi r18,0x6b":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa0":::"r18");  // Was 20
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2485 
asm("ldi r18,0xf2":::"r18");  // Was b2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2486 
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d12,r18");
asm("ldi r18,0x32":::"r18");  // Was f2
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was 6b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2487 
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d12,r18");
asm("ldi r18,0xf2":::"r18");  // Was 32
asm("sts 0x0d16,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2488 
asm("ldi r18,0xb2":::"r18");  // Was f2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2489 
asm("ldi r18,0xfa":::"r18");  // Was da
asm("sts 0x0d12,r18");
asm("ldi r18,0x62":::"r18");  // Was b2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2490 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x22":::"r18");  // Was 62
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x20":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2491 
asm("ldi r18,0x7a":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0xe2":::"r18");  // Was 22
asm("sts 0x0d16,r18");
asm("ldi r18,0xa0":::"r18");  // Was 20
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2492 
asm("ldi r18,0xfa":::"r18");  // Was 7a
asm("sts 0x0d12,r18");
asm("ldi r18,0xa2":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2493 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("ldi r18,0x20":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2494 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0x6b":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa0":::"r18");  // Was 20
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2495 
asm("ldi r18,0xe2":::"r18");  // Was a2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2496 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x22":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was 6b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2497 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0xe2":::"r18");  // Was 22
asm("sts 0x0d16,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2498 
asm("ldi r18,0xa2":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2499 
asm("ldi r18,0xea":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x62":::"r18");  // Was a2
asm("sts 0x0d16,r18");
asm("ldi r18,0xfb":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x80":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2500 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0x22":::"r18");  // Was 62
asm("sts 0x0d16,r18");
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x00":::"r18");  // Was 80
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2501 
asm("ldi r18,0x6a":::"r18");  // Was aa
asm("sts 0x0d12,r18");
asm("ldi r18,0xe2":::"r18");  // Was 22
asm("sts 0x0d16,r18");
asm("ldi r18,0x80":::"r18");  // Was 00
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2502 
asm("ldi r18,0xea":::"r18");  // Was 6a
asm("sts 0x0d12,r18");
asm("ldi r18,0xa2":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2503 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x00":::"r18");  // Was 80
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2504 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d12,r18");
asm("ldi r18,0x7b":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x80":::"r18");  // Was 00
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2505 
asm("ldi r18,0xe2":::"r18");  // Was a2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2506 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0x22":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("ldi r18,0xbb":::"r18");  // Was 7b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2507 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d12,r18");
asm("ldi r18,0xe2":::"r18");  // Was 22
asm("sts 0x0d16,r18");
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2508 
asm("ldi r18,0xa2":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2509 
asm("ldi r18,0xfa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0x62":::"r18");  // Was a2
asm("sts 0x0d16,r18");
asm("ldi r18,0xdb":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa0":::"r18");  // Was 80
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2510 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x22":::"r18");  // Was 62
asm("sts 0x0d16,r18");
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d1a,r18");
asm("ldi r18,0x20":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2511 
asm("ldi r18,0x7a":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0xe2":::"r18");  // Was 22
asm("sts 0x0d16,r18");
asm("ldi r18,0xa0":::"r18");  // Was 20
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2512 
asm("ldi r18,0xfa":::"r18");  // Was 7a
asm("sts 0x0d12,r18");
asm("ldi r18,0xa2":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2513 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d1a,r18");
asm("ldi r18,0x20":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2514 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0x5b":::"r18");  // Was db
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa0":::"r18");  // Was 20
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2515 
asm("ldi r18,0xe2":::"r18");  // Was a2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2516 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x22":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("ldi r18,0x9b":::"r18");  // Was 5b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2517 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0xe2":::"r18");  // Was 22
asm("sts 0x0d16,r18");
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2518 
asm("ldi r18,0xa2":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2519 
asm("ldi r18,0xf6":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x5e":::"r18");  // Was a2
asm("sts 0x0d16,r18");
asm("ldi r18,0xfb":::"r18");  // Was db
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2520 
asm("ldi r18,0xb6":::"r18");  // Was f6
asm("sts 0x0d12,r18");
asm("ldi r18,0x1e":::"r18");  // Was 5e
asm("sts 0x0d16,r18");
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2521 
asm("ldi r18,0x76":::"r18");  // Was b6
asm("sts 0x0d12,r18");
asm("ldi r18,0xde":::"r18");  // Was 1e
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2522 
asm("ldi r18,0xf6":::"r18");  // Was 76
asm("sts 0x0d12,r18");
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2523 
asm("ldi r18,0xb6":::"r18");  // Was f6
asm("sts 0x0d12,r18");
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2524 
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d12,r18");
asm("ldi r18,0x7b":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2525 
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2526 
asm("ldi r18,0xb6":::"r18");  // Was f6
asm("sts 0x0d12,r18");
asm("ldi r18,0x1e":::"r18");  // Was de
asm("sts 0x0d16,r18");
asm("ldi r18,0xbb":::"r18");  // Was 7b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2527 
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d12,r18");
asm("ldi r18,0xde":::"r18");  // Was 1e
asm("sts 0x0d16,r18");
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2528 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2529 
asm("ldi r18,0xe6":::"r18");  // Was f6
asm("sts 0x0d12,r18");
asm("ldi r18,0x4e":::"r18");  // Was 9e
asm("sts 0x0d16,r18");
asm("ldi r18,0xeb":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2530 
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d12,r18");
asm("ldi r18,0x0e":::"r18");  // Was 4e
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2531 
asm("ldi r18,0x66":::"r18");  // Was a6
asm("sts 0x0d12,r18");
asm("ldi r18,0xce":::"r18");  // Was 0e
asm("sts 0x0d16,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2532 
asm("ldi r18,0xe6":::"r18");  // Was 66
asm("sts 0x0d12,r18");
asm("ldi r18,0x8e":::"r18");  // Was ce
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2533 
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2534 
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d12,r18");
asm("ldi r18,0x6b":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2535 
asm("ldi r18,0xce":::"r18");  // Was 8e
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2536 
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d12,r18");
asm("ldi r18,0x0e":::"r18");  // Was ce
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was 6b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2537 
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d12,r18");
asm("ldi r18,0xce":::"r18");  // Was 0e
asm("sts 0x0d16,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2538 
asm("ldi r18,0x8e":::"r18");  // Was ce
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2539 
asm("ldi r18,0xd6":::"r18");  // Was e6
asm("sts 0x0d12,r18");
asm("ldi r18,0x7e":::"r18");  // Was 8e
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2540 
asm("ldi r18,0x96":::"r18");  // Was d6
asm("sts 0x0d12,r18");
asm("ldi r18,0x3e":::"r18");  // Was 7e
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2541 
asm("ldi r18,0x56":::"r18");  // Was 96
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was 3e
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2542 
asm("ldi r18,0xd6":::"r18");  // Was 56
asm("sts 0x0d12,r18");
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2543 
asm("ldi r18,0x96":::"r18");  // Was d6
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2544 
asm("ldi r18,0xd6":::"r18");  // Was 96
asm("sts 0x0d12,r18");
asm("ldi r18,0x6b":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2545 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2546 
asm("ldi r18,0x96":::"r18");  // Was d6
asm("sts 0x0d12,r18");
asm("ldi r18,0x3e":::"r18");  // Was fe
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was 6b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2547 
asm("ldi r18,0xd6":::"r18");  // Was 96
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was 3e
asm("sts 0x0d16,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2548 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2549 
asm("ldi r18,0xf6":::"r18");  // Was d6
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was be
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2550 
asm("ldi r18,0xb6":::"r18");  // Was f6
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was 6e
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2551 
asm("ldi r18,0x76":::"r18");  // Was b6
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2552 
asm("ldi r18,0xf6":::"r18");  // Was 76
asm("sts 0x0d12,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2553 
asm("ldi r18,0xb6":::"r18");  // Was f6
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2554 
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d12,r18");
asm("ldi r18,0x6b":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2555 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2556 
asm("ldi r18,0xb6":::"r18");  // Was f6
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was 6b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2557 
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2558 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2559 
asm("ldi r18,0xe6":::"r18");  // Was f6
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("ldi r18,0xfb":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2560 
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was 6e
asm("sts 0x0d16,r18");
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2561 
asm("ldi r18,0x66":::"r18");  // Was a6
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2562 
asm("ldi r18,0xe6":::"r18");  // Was 66
asm("sts 0x0d12,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2563 
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d12,r18");
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2564 
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d12,r18");
asm("ldi r18,0x7b":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2565 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2566 
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("ldi r18,0xbb":::"r18");  // Was 7b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2567 
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2568 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2569 
asm("ldi r18,0xf6":::"r18");  // Was e6
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("ldi r18,0xdb":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2570 
asm("ldi r18,0xb6":::"r18");  // Was f6
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was 6e
asm("sts 0x0d16,r18");
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2571 
asm("ldi r18,0x76":::"r18");  // Was b6
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2572 
asm("ldi r18,0xf6":::"r18");  // Was 76
asm("sts 0x0d12,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2573 
asm("ldi r18,0xb6":::"r18");  // Was f6
asm("sts 0x0d12,r18");
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2574 
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d12,r18");
asm("ldi r18,0x5b":::"r18");  // Was db
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2575 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2576 
asm("ldi r18,0xb6":::"r18");  // Was f6
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("ldi r18,0x9b":::"r18");  // Was 5b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2577 
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2578 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2579 
asm("ldi r18,0xfe":::"r18");  // Was f6
asm("sts 0x0d12,r18");
asm("ldi r18,0x5a":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("ldi r18,0xfb":::"r18");  // Was db
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2580 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x1a":::"r18");  // Was 5a
asm("sts 0x0d16,r18");
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2581 
asm("ldi r18,0x7e":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xda":::"r18");  // Was 1a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2582 
asm("ldi r18,0xfe":::"r18");  // Was 7e
asm("sts 0x0d12,r18");
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2583 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2584 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0x7b":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2585 
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2586 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x1a":::"r18");  // Was da
asm("sts 0x0d16,r18");
asm("ldi r18,0xbb":::"r18");  // Was 7b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2587 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xda":::"r18");  // Was 1a
asm("sts 0x0d16,r18");
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2588 
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2589 
asm("ldi r18,0xee":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x4a":::"r18");  // Was 9a
asm("sts 0x0d16,r18");
asm("ldi r18,0xeb":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2590 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x0a":::"r18");  // Was 4a
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2591 
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xca":::"r18");  // Was 0a
asm("sts 0x0d16,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2592 
asm("ldi r18,0xee":::"r18");  // Was 6e
asm("sts 0x0d12,r18");
asm("ldi r18,0x8a":::"r18");  // Was ca
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2593 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2594 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0x6b":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2595 
asm("ldi r18,0xca":::"r18");  // Was 8a
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2596 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x0a":::"r18");  // Was ca
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was 6b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2597 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xca":::"r18");  // Was 0a
asm("sts 0x0d16,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2598 
asm("ldi r18,0x8a":::"r18");  // Was ca
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2599 
asm("ldi r18,0xde":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x7a":::"r18");  // Was 8a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2600 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0x3a":::"r18");  // Was 7a
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2601 
asm("ldi r18,0x5e":::"r18");  // Was 9e
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was 3a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2602 
asm("ldi r18,0xde":::"r18");  // Was 5e
asm("sts 0x0d12,r18");
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2603 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2604 
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d12,r18");
asm("ldi r18,0x6b":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2605 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2606 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0x3a":::"r18");  // Was fa
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was 6b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2607 
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was 3a
asm("sts 0x0d16,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2608 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2609 
asm("ldi r18,0xfe":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ba
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2610 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was 6a
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2611 
asm("ldi r18,0x7e":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2612 
asm("ldi r18,0xfe":::"r18");  // Was 7e
asm("sts 0x0d12,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2613 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2614 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0x6b":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2615 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2616 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was 6b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2617 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2618 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2619 
asm("ldi r18,0xee":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("ldi r18,0xfb":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2620 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was 6a
asm("sts 0x0d16,r18");
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2621 
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2622 
asm("ldi r18,0xee":::"r18");  // Was 6e
asm("sts 0x0d12,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2623 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2624 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0x7b":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2625 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2626 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("ldi r18,0xbb":::"r18");  // Was 7b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2627 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2628 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2629 
asm("ldi r18,0xfe":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("ldi r18,0xdb":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2630 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was 6a
asm("sts 0x0d16,r18");
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2631 
asm("ldi r18,0x7e":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2632 
asm("ldi r18,0xfe":::"r18");  // Was 7e
asm("sts 0x0d12,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2633 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2634 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0x5b":::"r18");  // Was db
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2635 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2636 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("ldi r18,0x9b":::"r18");  // Was 5b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2637 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2638 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2639 
asm("ldi r18,0xfa":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x5a":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("ldi r18,0xff":::"r18");  // Was db
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa0":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2640 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x1a":::"r18");  // Was 5a
asm("sts 0x0d16,r18");
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0x20":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2641 
asm("ldi r18,0x7a":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0xda":::"r18");  // Was 1a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa0":::"r18");  // Was 20
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2642 
asm("ldi r18,0xfa":::"r18");  // Was 7a
asm("sts 0x0d12,r18");
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2643 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d1a,r18");
asm("ldi r18,0x20":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2644 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0x7f":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa0":::"r18");  // Was 20
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2645 
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2646 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x1a":::"r18");  // Was da
asm("sts 0x0d16,r18");
asm("ldi r18,0xbf":::"r18");  // Was 7f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2647 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0xda":::"r18");  // Was 1a
asm("sts 0x0d16,r18");
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2648 
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2649 
asm("ldi r18,0xea":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x4a":::"r18");  // Was 9a
asm("sts 0x0d16,r18");
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0x80":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2650 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0x0a":::"r18");  // Was 4a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x00":::"r18");  // Was 80
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2651 
asm("ldi r18,0x6a":::"r18");  // Was aa
asm("sts 0x0d12,r18");
asm("ldi r18,0xca":::"r18");  // Was 0a
asm("sts 0x0d16,r18");
asm("ldi r18,0x80":::"r18");  // Was 00
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2652 
asm("ldi r18,0xea":::"r18");  // Was 6a
asm("sts 0x0d12,r18");
asm("ldi r18,0x8a":::"r18");  // Was ca
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2653 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("ldi r18,0x00":::"r18");  // Was 80
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2654 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d12,r18");
asm("ldi r18,0x6f":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x80":::"r18");  // Was 00
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2655 
asm("ldi r18,0xca":::"r18");  // Was 8a
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2656 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0x0a":::"r18");  // Was ca
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was 6f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2657 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d12,r18");
asm("ldi r18,0xca":::"r18");  // Was 0a
asm("sts 0x0d16,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2658 
asm("ldi r18,0x8a":::"r18");  // Was ca
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2659 
asm("ldi r18,0xda":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0x7a":::"r18");  // Was 8a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa0":::"r18");  // Was 80
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2660 
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d12,r18");
asm("ldi r18,0x3a":::"r18");  // Was 7a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x20":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2661 
asm("ldi r18,0x5a":::"r18");  // Was 9a
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was 3a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa0":::"r18");  // Was 20
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2662 
asm("ldi r18,0xda":::"r18");  // Was 5a
asm("sts 0x0d12,r18");
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2663 
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("ldi r18,0x20":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2664 
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d12,r18");
asm("ldi r18,0x6f":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa0":::"r18");  // Was 20
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2665 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2666 
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d12,r18");
asm("ldi r18,0x3a":::"r18");  // Was fa
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was 6f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2667 
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was 3a
asm("sts 0x0d16,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2668 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2669 
asm("ldi r18,0xfa":::"r18");  // Was da
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ba
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2670 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was 6a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x20":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2671 
asm("ldi r18,0x7a":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa0":::"r18");  // Was 20
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2672 
asm("ldi r18,0xfa":::"r18");  // Was 7a
asm("sts 0x0d12,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2673 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("ldi r18,0x20":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2674 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0x6f":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa0":::"r18");  // Was 20
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2675 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2676 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was 6f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2677 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2678 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2679 
asm("ldi r18,0xea":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("ldi r18,0xff":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x80":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2680 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was 6a
asm("sts 0x0d16,r18");
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0x00":::"r18");  // Was 80
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2681 
asm("ldi r18,0x6a":::"r18");  // Was aa
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0x80":::"r18");  // Was 00
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2682 
asm("ldi r18,0xea":::"r18");  // Was 6a
asm("sts 0x0d12,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2683 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d1a,r18");
asm("ldi r18,0x00":::"r18");  // Was 80
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2684 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d12,r18");
asm("ldi r18,0x7f":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0x80":::"r18");  // Was 00
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2685 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2686 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("ldi r18,0xbf":::"r18");  // Was 7f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2687 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2688 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2689 
asm("ldi r18,0xfa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("ldi r18,0xdf":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa0":::"r18");  // Was 80
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2690 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was 6a
asm("sts 0x0d16,r18");
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d1a,r18");
asm("ldi r18,0x20":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2691 
asm("ldi r18,0x7a":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa0":::"r18");  // Was 20
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2692 
asm("ldi r18,0xfa":::"r18");  // Was 7a
asm("sts 0x0d12,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2693 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d1a,r18");
asm("ldi r18,0x20":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2694 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0x5f":::"r18");  // Was df
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa0":::"r18");  // Was 20
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2695 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2696 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("ldi r18,0x9f":::"r18");  // Was 5f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2697 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2698 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2699 
asm("ldi r18,0xfe":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x5a":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("ldi r18,0xf7":::"r18");  // Was df
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was a0
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2700 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x1a":::"r18");  // Was 5a
asm("sts 0x0d16,r18");
asm("ldi r18,0xb7":::"r18");  // Was f7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2701 
asm("ldi r18,0x7e":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xda":::"r18");  // Was 1a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2702 
asm("ldi r18,0xfe":::"r18");  // Was 7e
asm("sts 0x0d12,r18");
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2703 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0xf7":::"r18");  // Was b7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2704 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0x77":::"r18");  // Was f7
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2705 
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2706 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x1a":::"r18");  // Was da
asm("sts 0x0d16,r18");
asm("ldi r18,0xb7":::"r18");  // Was 77
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2707 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xda":::"r18");  // Was 1a
asm("sts 0x0d16,r18");
asm("ldi r18,0xf7":::"r18");  // Was b7
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2708 
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2709 
asm("ldi r18,0xee":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x4a":::"r18");  // Was 9a
asm("sts 0x0d16,r18");
asm("ldi r18,0xe7":::"r18");  // Was f7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2710 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x0a":::"r18");  // Was 4a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa7":::"r18");  // Was e7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2711 
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xca":::"r18");  // Was 0a
asm("sts 0x0d16,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2712 
asm("ldi r18,0xee":::"r18");  // Was 6e
asm("sts 0x0d12,r18");
asm("ldi r18,0x8a":::"r18");  // Was ca
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2713 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2714 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0x67":::"r18");  // Was e7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2715 
asm("ldi r18,0xca":::"r18");  // Was 8a
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2716 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x0a":::"r18");  // Was ca
asm("sts 0x0d16,r18");
asm("ldi r18,0xa7":::"r18");  // Was 67
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2717 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xca":::"r18");  // Was 0a
asm("sts 0x0d16,r18");
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2718 
asm("ldi r18,0x8a":::"r18");  // Was ca
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2719 
asm("ldi r18,0xde":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x7a":::"r18");  // Was 8a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2720 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0x3a":::"r18");  // Was 7a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa7":::"r18");  // Was e7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2721 
asm("ldi r18,0x5e":::"r18");  // Was 9e
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was 3a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2722 
asm("ldi r18,0xde":::"r18");  // Was 5e
asm("sts 0x0d12,r18");
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2723 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2724 
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d12,r18");
asm("ldi r18,0x67":::"r18");  // Was e7
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2725 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2726 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0x3a":::"r18");  // Was fa
asm("sts 0x0d16,r18");
asm("ldi r18,0xa7":::"r18");  // Was 67
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2727 
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was 3a
asm("sts 0x0d16,r18");
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2728 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2729 
asm("ldi r18,0xfe":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ba
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2730 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was 6a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa7":::"r18");  // Was e7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2731 
asm("ldi r18,0x7e":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2732 
asm("ldi r18,0xfe":::"r18");  // Was 7e
asm("sts 0x0d12,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2733 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2734 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0x67":::"r18");  // Was e7
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2735 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2736 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("ldi r18,0xa7":::"r18");  // Was 67
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2737 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2738 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2739 
asm("ldi r18,0xee":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("ldi r18,0xf7":::"r18");  // Was e7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2740 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was 6a
asm("sts 0x0d16,r18");
asm("ldi r18,0xb7":::"r18");  // Was f7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2741 
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2742 
asm("ldi r18,0xee":::"r18");  // Was 6e
asm("sts 0x0d12,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2743 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0xf7":::"r18");  // Was b7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2744 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0x77":::"r18");  // Was f7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2745 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2746 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("ldi r18,0xb7":::"r18");  // Was 77
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2747 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xf7":::"r18");  // Was b7
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2748 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2749 
asm("ldi r18,0xfe":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("ldi r18,0xd7":::"r18");  // Was f7
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2750 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was 6a
asm("sts 0x0d16,r18");
asm("ldi r18,0x97":::"r18");  // Was d7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2751 
asm("ldi r18,0x7e":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2752 
asm("ldi r18,0xfe":::"r18");  // Was 7e
asm("sts 0x0d12,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2753 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0xd7":::"r18");  // Was 97
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2754 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0x57":::"r18");  // Was d7
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2755 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2756 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("ldi r18,0x97":::"r18");  // Was 57
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2757 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xd7":::"r18");  // Was 97
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2758 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2759 
asm("ldi r18,0x5e":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("ldi r18,0xf7":::"r18");  // Was d7
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2760 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x1e":::"r18");  // Was 5e
asm("sts 0x0d16,r18");
asm("ldi r18,0xb7":::"r18");  // Was f7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2761 
asm("ldi r18,0x7e":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xde":::"r18");  // Was 1e
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2762 
asm("ldi r18,0xfe":::"r18");  // Was 7e
asm("sts 0x0d12,r18");
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2763 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0xf7":::"r18");  // Was b7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2764 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0x77":::"r18");  // Was f7
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2765 
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2766 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x1e":::"r18");  // Was de
asm("sts 0x0d16,r18");
asm("ldi r18,0xb7":::"r18");  // Was 77
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2767 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xde":::"r18");  // Was 1e
asm("sts 0x0d16,r18");
asm("ldi r18,0xf7":::"r18");  // Was b7
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2768 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2769 
asm("ldi r18,0xee":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x4e":::"r18");  // Was 9e
asm("sts 0x0d16,r18");
asm("ldi r18,0xe7":::"r18");  // Was f7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2770 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x0e":::"r18");  // Was 4e
asm("sts 0x0d16,r18");
asm("ldi r18,0xa7":::"r18");  // Was e7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2771 
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xce":::"r18");  // Was 0e
asm("sts 0x0d16,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2772 
asm("ldi r18,0xee":::"r18");  // Was 6e
asm("sts 0x0d12,r18");
asm("ldi r18,0x8e":::"r18");  // Was ce
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2773 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2774 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0x67":::"r18");  // Was e7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2775 
asm("ldi r18,0xce":::"r18");  // Was 8e
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2776 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x0e":::"r18");  // Was ce
asm("sts 0x0d16,r18");
asm("ldi r18,0xa7":::"r18");  // Was 67
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2777 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xce":::"r18");  // Was 0e
asm("sts 0x0d16,r18");
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2778 
asm("ldi r18,0x8e":::"r18");  // Was ce
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2779 
asm("ldi r18,0xde":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x7e":::"r18");  // Was 8e
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2780 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0x3e":::"r18");  // Was 7e
asm("sts 0x0d16,r18");
asm("ldi r18,0xa7":::"r18");  // Was e7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2781 
asm("ldi r18,0x5e":::"r18");  // Was 9e
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was 3e
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2782 
asm("ldi r18,0xde":::"r18");  // Was 5e
asm("sts 0x0d12,r18");
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2783 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2784 
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d12,r18");
asm("ldi r18,0x67":::"r18");  // Was e7
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2785 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2786 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0x3e":::"r18");  // Was fe
asm("sts 0x0d16,r18");
asm("ldi r18,0xa7":::"r18");  // Was 67
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2787 
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was 3e
asm("sts 0x0d16,r18");
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2788 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2789 
asm("ldi r18,0xfe":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was be
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2790 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was 6e
asm("sts 0x0d16,r18");
asm("ldi r18,0xa7":::"r18");  // Was e7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2791 
asm("ldi r18,0x7e":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2792 
asm("ldi r18,0xfe":::"r18");  // Was 7e
asm("sts 0x0d12,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2793 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2794 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0x67":::"r18");  // Was e7
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2795 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2796 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("ldi r18,0xa7":::"r18");  // Was 67
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2797 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2798 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2799 
asm("ldi r18,0xee":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("ldi r18,0xf7":::"r18");  // Was e7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2800 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was 6e
asm("sts 0x0d16,r18");
asm("ldi r18,0xb7":::"r18");  // Was f7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2801 
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2802 
asm("ldi r18,0xee":::"r18");  // Was 6e
asm("sts 0x0d12,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2803 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0xf7":::"r18");  // Was b7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2804 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0x77":::"r18");  // Was f7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2805 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2806 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("ldi r18,0xb7":::"r18");  // Was 77
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2807 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xf7":::"r18");  // Was b7
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2808 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2809 
asm("ldi r18,0xfe":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("ldi r18,0xd7":::"r18");  // Was f7
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2810 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was 6e
asm("sts 0x0d16,r18");
asm("ldi r18,0x97":::"r18");  // Was d7
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2811 
asm("ldi r18,0x7e":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2812 
asm("ldi r18,0xfe":::"r18");  // Was 7e
asm("sts 0x0d12,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2813 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0xd7":::"r18");  // Was 97
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2814 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0x57":::"r18");  // Was d7
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2815 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2816 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("ldi r18,0x97":::"r18");  // Was 57
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2817 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xd7":::"r18");  // Was 97
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2818 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2819 
asm("ldi r18,0xfa":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x52":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("ldi r18,0xfb":::"r18");  // Was d7
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2820 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x12":::"r18");  // Was 52
asm("sts 0x0d16,r18");
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2821 
asm("ldi r18,0x7a":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0xd2":::"r18");  // Was 12
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2822 
asm("ldi r18,0xfa":::"r18");  // Was 7a
asm("sts 0x0d12,r18");
asm("ldi r18,0x92":::"r18");  // Was d2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2823 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2824 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0x7b":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2825 
asm("ldi r18,0xd2":::"r18");  // Was 92
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2826 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x12":::"r18");  // Was d2
asm("sts 0x0d16,r18");
asm("ldi r18,0xbb":::"r18");  // Was 7b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2827 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0xd2":::"r18");  // Was 12
asm("sts 0x0d16,r18");
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2828 
asm("ldi r18,0x92":::"r18");  // Was d2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2829 
asm("ldi r18,0xea":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x42":::"r18");  // Was 92
asm("sts 0x0d16,r18");
asm("ldi r18,0xeb":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2830 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0x02":::"r18");  // Was 42
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2831 
asm("ldi r18,0x6a":::"r18");  // Was aa
asm("sts 0x0d12,r18");
asm("ldi r18,0xc2":::"r18");  // Was 02
asm("sts 0x0d16,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2832 
asm("ldi r18,0xea":::"r18");  // Was 6a
asm("sts 0x0d12,r18");
asm("ldi r18,0x82":::"r18");  // Was c2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2833 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2834 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d12,r18");
asm("ldi r18,0x6b":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2835 
asm("ldi r18,0xc2":::"r18");  // Was 82
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2836 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0x02":::"r18");  // Was c2
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was 6b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2837 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d12,r18");
asm("ldi r18,0xc2":::"r18");  // Was 02
asm("sts 0x0d16,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2838 
asm("ldi r18,0x82":::"r18");  // Was c2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2839 
asm("ldi r18,0xda":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0x72":::"r18");  // Was 82
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2840 
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d12,r18");
asm("ldi r18,0x32":::"r18");  // Was 72
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2841 
asm("ldi r18,0x5a":::"r18");  // Was 9a
asm("sts 0x0d12,r18");
asm("ldi r18,0xf2":::"r18");  // Was 32
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2842 
asm("ldi r18,0xda":::"r18");  // Was 5a
asm("sts 0x0d12,r18");
asm("ldi r18,0xb2":::"r18");  // Was f2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2843 
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2844 
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d12,r18");
asm("ldi r18,0x6b":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2845 
asm("ldi r18,0xf2":::"r18");  // Was b2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2846 
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d12,r18");
asm("ldi r18,0x32":::"r18");  // Was f2
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was 6b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2847 
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d12,r18");
asm("ldi r18,0xf2":::"r18");  // Was 32
asm("sts 0x0d16,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2848 
asm("ldi r18,0xb2":::"r18");  // Was f2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2849 
asm("ldi r18,0xfa":::"r18");  // Was da
asm("sts 0x0d12,r18");
asm("ldi r18,0x62":::"r18");  // Was b2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2850 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x22":::"r18");  // Was 62
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2851 
asm("ldi r18,0x7a":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0xe2":::"r18");  // Was 22
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2852 
asm("ldi r18,0xfa":::"r18");  // Was 7a
asm("sts 0x0d12,r18");
asm("ldi r18,0xa2":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2853 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2854 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0x6b":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2855 
asm("ldi r18,0xe2":::"r18");  // Was a2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2856 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x22":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("ldi r18,0xab":::"r18");  // Was 6b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2857 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0xe2":::"r18");  // Was 22
asm("sts 0x0d16,r18");
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2858 
asm("ldi r18,0xa2":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2859 
asm("ldi r18,0xea":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x62":::"r18");  // Was a2
asm("sts 0x0d16,r18");
asm("ldi r18,0xfb":::"r18");  // Was eb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2860 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0x22":::"r18");  // Was 62
asm("sts 0x0d16,r18");
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2861 
asm("ldi r18,0x6a":::"r18");  // Was aa
asm("sts 0x0d12,r18");
asm("ldi r18,0xe2":::"r18");  // Was 22
asm("sts 0x0d16,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2862 
asm("ldi r18,0xea":::"r18");  // Was 6a
asm("sts 0x0d12,r18");
asm("ldi r18,0xa2":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2863 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2864 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d12,r18");
asm("ldi r18,0x7b":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2865 
asm("ldi r18,0xe2":::"r18");  // Was a2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2866 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0x22":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("ldi r18,0xbb":::"r18");  // Was 7b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2867 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d12,r18");
asm("ldi r18,0xe2":::"r18");  // Was 22
asm("sts 0x0d16,r18");
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2868 
asm("ldi r18,0xa2":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2869 
asm("ldi r18,0xfa":::"r18");  // Was ea
asm("sts 0x0d12,r18");
asm("ldi r18,0x62":::"r18");  // Was a2
asm("sts 0x0d16,r18");
asm("ldi r18,0xdb":::"r18");  // Was fb
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2870 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x22":::"r18");  // Was 62
asm("sts 0x0d16,r18");
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2871 
asm("ldi r18,0x7a":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0xe2":::"r18");  // Was 22
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2872 
asm("ldi r18,0xfa":::"r18");  // Was 7a
asm("sts 0x0d12,r18");
asm("ldi r18,0xa2":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2873 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2874 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0x5b":::"r18");  // Was db
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2875 
asm("ldi r18,0xe2":::"r18");  // Was a2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2876 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x22":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("ldi r18,0x9b":::"r18");  // Was 5b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2877 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d12,r18");
asm("ldi r18,0xe2":::"r18");  // Was 22
asm("sts 0x0d16,r18");
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2878 
asm("ldi r18,0xa2":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2879 
asm("ldi r18,0xfe":::"r18");  // Was fa
asm("sts 0x0d12,r18");
asm("ldi r18,0x5e":::"r18");  // Was a2
asm("sts 0x0d16,r18");
asm("ldi r18,0xff":::"r18");  // Was db
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2880 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x1e":::"r18");  // Was 5e
asm("sts 0x0d16,r18");
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2881 
asm("ldi r18,0x7e":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xde":::"r18");  // Was 1e
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2882 
asm("ldi r18,0xfe":::"r18");  // Was 7e
asm("sts 0x0d12,r18");
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2883 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2884 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0x7f":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2885 
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2886 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x1e":::"r18");  // Was de
asm("sts 0x0d16,r18");
asm("ldi r18,0xbf":::"r18");  // Was 7f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2887 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xde":::"r18");  // Was 1e
asm("sts 0x0d16,r18");
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2888 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2889 
asm("ldi r18,0xee":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x4e":::"r18");  // Was 9e
asm("sts 0x0d16,r18");
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2890 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x0e":::"r18");  // Was 4e
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2891 
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xce":::"r18");  // Was 0e
asm("sts 0x0d16,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2892 
asm("ldi r18,0xee":::"r18");  // Was 6e
asm("sts 0x0d12,r18");
asm("ldi r18,0x8e":::"r18");  // Was ce
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2893 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2894 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0x6f":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2895 
asm("ldi r18,0xce":::"r18");  // Was 8e
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2896 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x0e":::"r18");  // Was ce
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was 6f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2897 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xce":::"r18");  // Was 0e
asm("sts 0x0d16,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2898 
asm("ldi r18,0x8e":::"r18");  // Was ce
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2899 
asm("ldi r18,0xde":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x7e":::"r18");  // Was 8e
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2900 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0x3e":::"r18");  // Was 7e
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2901 
asm("ldi r18,0x5e":::"r18");  // Was 9e
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was 3e
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2902 
asm("ldi r18,0xde":::"r18");  // Was 5e
asm("sts 0x0d12,r18");
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2903 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2904 
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d12,r18");
asm("ldi r18,0x6f":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2905 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2906 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0x3e":::"r18");  // Was fe
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was 6f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2907 
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was 3e
asm("sts 0x0d16,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2908 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2909 
asm("ldi r18,0xfe":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was be
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2910 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was 6e
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2911 
asm("ldi r18,0x7e":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2912 
asm("ldi r18,0xfe":::"r18");  // Was 7e
asm("sts 0x0d12,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2913 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2914 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0x6f":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2915 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2916 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was 6f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2917 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2918 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2919 
asm("ldi r18,0xee":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("ldi r18,0xff":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2920 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was 6e
asm("sts 0x0d16,r18");
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2921 
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2922 
asm("ldi r18,0xee":::"r18");  // Was 6e
asm("sts 0x0d12,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2923 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2924 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0x7f":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2925 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2926 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("ldi r18,0xbf":::"r18");  // Was 7f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2927 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2928 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2929 
asm("ldi r18,0xfe":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("ldi r18,0xdf":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2930 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was 6e
asm("sts 0x0d16,r18");
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2931 
asm("ldi r18,0x7e":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2932 
asm("ldi r18,0xfe":::"r18");  // Was 7e
asm("sts 0x0d12,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2933 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2934 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0x5f":::"r18");  // Was df
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2935 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2936 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("ldi r18,0x9f":::"r18");  // Was 5f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2937 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2938 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2939 
asm("ldi r18,0x5a":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("ldi r18,0xff":::"r18");  // Was df
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2940 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x1a":::"r18");  // Was 5a
asm("sts 0x0d16,r18");
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2941 
asm("ldi r18,0x7e":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xda":::"r18");  // Was 1a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2942 
asm("ldi r18,0xfe":::"r18");  // Was 7e
asm("sts 0x0d12,r18");
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2943 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2944 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0x7f":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2945 
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2946 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x1a":::"r18");  // Was da
asm("sts 0x0d16,r18");
asm("ldi r18,0xbf":::"r18");  // Was 7f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2947 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xda":::"r18");  // Was 1a
asm("sts 0x0d16,r18");
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2948 
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2949 
asm("ldi r18,0xee":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x4a":::"r18");  // Was 9a
asm("sts 0x0d16,r18");
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2950 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x0a":::"r18");  // Was 4a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2951 
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xca":::"r18");  // Was 0a
asm("sts 0x0d16,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2952 
asm("ldi r18,0xee":::"r18");  // Was 6e
asm("sts 0x0d12,r18");
asm("ldi r18,0x8a":::"r18");  // Was ca
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2953 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2954 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0x6f":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2955 
asm("ldi r18,0xca":::"r18");  // Was 8a
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2956 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x0a":::"r18");  // Was ca
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was 6f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2957 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xca":::"r18");  // Was 0a
asm("sts 0x0d16,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2958 
asm("ldi r18,0x8a":::"r18");  // Was ca
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2959 
asm("ldi r18,0xde":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x7a":::"r18");  // Was 8a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2960 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0x3a":::"r18");  // Was 7a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2961 
asm("ldi r18,0x5e":::"r18");  // Was 9e
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was 3a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2962 
asm("ldi r18,0xde":::"r18");  // Was 5e
asm("sts 0x0d12,r18");
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2963 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2964 
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d12,r18");
asm("ldi r18,0x6f":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2965 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2966 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0x3a":::"r18");  // Was fa
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was 6f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2967 
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was 3a
asm("sts 0x0d16,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2968 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2969 
asm("ldi r18,0xfe":::"r18");  // Was de
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ba
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2970 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was 6a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2971 
asm("ldi r18,0x7e":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2972 
asm("ldi r18,0xfe":::"r18");  // Was 7e
asm("sts 0x0d12,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2973 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2974 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0x6f":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2975 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2976 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("ldi r18,0xaf":::"r18");  // Was 6f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2977 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2978 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2979 
asm("ldi r18,0xee":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("ldi r18,0xff":::"r18");  // Was ef
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2980 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was 6a
asm("sts 0x0d16,r18");
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2981 
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2982 
asm("ldi r18,0xee":::"r18");  // Was 6e
asm("sts 0x0d12,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2983 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d1a,r18");
asm("ldi r18,0x08":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2984 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0x7f":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0x88":::"r18");  // Was 08
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2985 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2986 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("ldi r18,0xbf":::"r18");  // Was 7f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2987 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2988 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2989 
asm("ldi r18,0xfe":::"r18");  // Was ee
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("ldi r18,0xdf":::"r18");  // Was ff
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 88
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2990 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was 6a
asm("sts 0x0d16,r18");
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2991 
asm("ldi r18,0x7e":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2992 
asm("ldi r18,0xfe":::"r18");  // Was 7e
asm("sts 0x0d12,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2993 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d1a,r18");
asm("ldi r18,0x28":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2994 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0x5f":::"r18");  // Was df
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa8":::"r18");  // Was 28
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 2995 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2996 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("ldi r18,0x9f":::"r18");  // Was 5f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2997 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 2998 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 2999 
asm("ldi r18,0xff":::"r18");  // Was fe
asm("sts 0x0d12,r18");
asm("ldi r18,0x56":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("ldi r18,0xfd":::"r18");  // Was df
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was a8
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3000 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x16":::"r18");  // Was 56
asm("sts 0x0d16,r18");
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3001 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xd6":::"r18");  // Was 16
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3002 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0x96":::"r18");  // Was d6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3003 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3004 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x7d":::"r18");  // Was fd
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3005 
asm("ldi r18,0xd6":::"r18");  // Was 96
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3006 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x16":::"r18");  // Was d6
asm("sts 0x0d16,r18");
asm("ldi r18,0xbd":::"r18");  // Was 7d
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3007 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xd6":::"r18");  // Was 16
asm("sts 0x0d16,r18");
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3008 
asm("ldi r18,0x96":::"r18");  // Was d6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3009 
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x46":::"r18");  // Was 96
asm("sts 0x0d16,r18");
asm("ldi r18,0xed":::"r18");  // Was fd
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3010 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x06":::"r18");  // Was 46
asm("sts 0x0d16,r18");
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3011 
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xc6":::"r18");  // Was 06
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3012 
asm("ldi r18,0xef":::"r18");  // Was 6f
asm("sts 0x0d12,r18");
asm("ldi r18,0x86":::"r18");  // Was c6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3013 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3014 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0x6d":::"r18");  // Was ed
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3015 
asm("ldi r18,0xc6":::"r18");  // Was 86
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3016 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x06":::"r18");  // Was c6
asm("sts 0x0d16,r18");
asm("ldi r18,0xad":::"r18");  // Was 6d
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3017 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xc6":::"r18");  // Was 06
asm("sts 0x0d16,r18");
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3018 
asm("ldi r18,0x86":::"r18");  // Was c6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3019 
asm("ldi r18,0xdf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x76":::"r18");  // Was 86
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3020 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x36":::"r18");  // Was 76
asm("sts 0x0d16,r18");
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3021 
asm("ldi r18,0x5f":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0xf6":::"r18");  // Was 36
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3022 
asm("ldi r18,0xdf":::"r18");  // Was 5f
asm("sts 0x0d12,r18");
asm("ldi r18,0xb6":::"r18");  // Was f6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3023 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3024 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0x6d":::"r18");  // Was ed
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3025 
asm("ldi r18,0xf6":::"r18");  // Was b6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3026 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x36":::"r18");  // Was f6
asm("sts 0x0d16,r18");
asm("ldi r18,0xad":::"r18");  // Was 6d
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3027 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0xf6":::"r18");  // Was 36
asm("sts 0x0d16,r18");
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3028 
asm("ldi r18,0xb6":::"r18");  // Was f6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3029 
asm("ldi r18,0xff":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x66":::"r18");  // Was b6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3030 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x26":::"r18");  // Was 66
asm("sts 0x0d16,r18");
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3031 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xe6":::"r18");  // Was 26
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3032 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3033 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3034 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x6d":::"r18");  // Was ed
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3035 
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3036 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x26":::"r18");  // Was e6
asm("sts 0x0d16,r18");
asm("ldi r18,0xad":::"r18");  // Was 6d
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3037 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xe6":::"r18");  // Was 26
asm("sts 0x0d16,r18");
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3038 
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3039 
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x66":::"r18");  // Was a6
asm("sts 0x0d16,r18");
asm("ldi r18,0xfd":::"r18");  // Was ed
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3040 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x26":::"r18");  // Was 66
asm("sts 0x0d16,r18");
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3041 
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xe6":::"r18");  // Was 26
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3042 
asm("ldi r18,0xef":::"r18");  // Was 6f
asm("sts 0x0d12,r18");
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3043 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3044 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0x7d":::"r18");  // Was fd
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3045 
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3046 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x26":::"r18");  // Was e6
asm("sts 0x0d16,r18");
asm("ldi r18,0xbd":::"r18");  // Was 7d
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3047 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xe6":::"r18");  // Was 26
asm("sts 0x0d16,r18");
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3048 
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3049 
asm("ldi r18,0xff":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x66":::"r18");  // Was a6
asm("sts 0x0d16,r18");
asm("ldi r18,0xdd":::"r18");  // Was fd
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3050 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x26":::"r18");  // Was 66
asm("sts 0x0d16,r18");
asm("ldi r18,0x9d":::"r18");  // Was dd
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3051 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xe6":::"r18");  // Was 26
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3052 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3053 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xdd":::"r18");  // Was 9d
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3054 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x5d":::"r18");  // Was dd
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3055 
asm("ldi r18,0xe6":::"r18");  // Was a6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3056 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x26":::"r18");  // Was e6
asm("sts 0x0d16,r18");
asm("ldi r18,0x9d":::"r18");  // Was 5d
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3057 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xe6":::"r18");  // Was 26
asm("sts 0x0d16,r18");
asm("ldi r18,0xdd":::"r18");  // Was 9d
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3058 
asm("ldi r18,0xa6":::"r18");  // Was e6
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3059 
asm("ldi r18,0xfb":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x52":::"r18");  // Was a6
asm("sts 0x0d16,r18");
asm("ldi r18,0xf9":::"r18");  // Was dd
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3060 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x12":::"r18");  // Was 52
asm("sts 0x0d16,r18");
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3061 
asm("ldi r18,0x7b":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xd2":::"r18");  // Was 12
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3062 
asm("ldi r18,0xfb":::"r18");  // Was 7b
asm("sts 0x0d12,r18");
asm("ldi r18,0x92":::"r18");  // Was d2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3063 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3064 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0x79":::"r18");  // Was f9
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3065 
asm("ldi r18,0xd2":::"r18");  // Was 92
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3066 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x12":::"r18");  // Was d2
asm("sts 0x0d16,r18");
asm("ldi r18,0xb9":::"r18");  // Was 79
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3067 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xd2":::"r18");  // Was 12
asm("sts 0x0d16,r18");
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3068 
asm("ldi r18,0x92":::"r18");  // Was d2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3069 
asm("ldi r18,0xeb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x42":::"r18");  // Was 92
asm("sts 0x0d16,r18");
asm("ldi r18,0xe9":::"r18");  // Was f9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x82":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3070 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x02":::"r18");  // Was 42
asm("sts 0x0d16,r18");
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x02":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3071 
asm("ldi r18,0x6b":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0xc2":::"r18");  // Was 02
asm("sts 0x0d16,r18");
asm("ldi r18,0x82":::"r18");  // Was 02
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3072 
asm("ldi r18,0xeb":::"r18");  // Was 6b
asm("sts 0x0d12,r18");
asm("ldi r18,0x82":::"r18");  // Was c2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3073 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x02":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3074 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0x69":::"r18");  // Was e9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x82":::"r18");  // Was 02
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3075 
asm("ldi r18,0xc2":::"r18");  // Was 82
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3076 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x02":::"r18");  // Was c2
asm("sts 0x0d16,r18");
asm("ldi r18,0xa9":::"r18");  // Was 69
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3077 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0xc2":::"r18");  // Was 02
asm("sts 0x0d16,r18");
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3078 
asm("ldi r18,0x82":::"r18");  // Was c2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3079 
asm("ldi r18,0xdb":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x72":::"r18");  // Was 82
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3080 
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d12,r18");
asm("ldi r18,0x32":::"r18");  // Was 72
asm("sts 0x0d16,r18");
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3081 
asm("ldi r18,0x5b":::"r18");  // Was 9b
asm("sts 0x0d12,r18");
asm("ldi r18,0xf2":::"r18");  // Was 32
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3082 
asm("ldi r18,0xdb":::"r18");  // Was 5b
asm("sts 0x0d12,r18");
asm("ldi r18,0xb2":::"r18");  // Was f2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3083 
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d12,r18");
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3084 
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d12,r18");
asm("ldi r18,0x69":::"r18");  // Was e9
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3085 
asm("ldi r18,0xf2":::"r18");  // Was b2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3086 
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d12,r18");
asm("ldi r18,0x32":::"r18");  // Was f2
asm("sts 0x0d16,r18");
asm("ldi r18,0xa9":::"r18");  // Was 69
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3087 
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d12,r18");
asm("ldi r18,0xf2":::"r18");  // Was 32
asm("sts 0x0d16,r18");
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3088 
asm("ldi r18,0xb2":::"r18");  // Was f2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3089 
asm("ldi r18,0xfb":::"r18");  // Was db
asm("sts 0x0d12,r18");
asm("ldi r18,0x62":::"r18");  // Was b2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3090 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x22":::"r18");  // Was 62
asm("sts 0x0d16,r18");
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3091 
asm("ldi r18,0x7b":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xe2":::"r18");  // Was 22
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3092 
asm("ldi r18,0xfb":::"r18");  // Was 7b
asm("sts 0x0d12,r18");
asm("ldi r18,0xa2":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3093 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3094 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0x69":::"r18");  // Was e9
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3095 
asm("ldi r18,0xe2":::"r18");  // Was a2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3096 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x22":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("ldi r18,0xa9":::"r18");  // Was 69
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3097 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xe2":::"r18");  // Was 22
asm("sts 0x0d16,r18");
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3098 
asm("ldi r18,0xa2":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3099 
asm("ldi r18,0xeb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x62":::"r18");  // Was a2
asm("sts 0x0d16,r18");
asm("ldi r18,0xf9":::"r18");  // Was e9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x82":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3100 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x22":::"r18");  // Was 62
asm("sts 0x0d16,r18");
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x02":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3101 
asm("ldi r18,0x6b":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0xe2":::"r18");  // Was 22
asm("sts 0x0d16,r18");
asm("ldi r18,0x82":::"r18");  // Was 02
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3102 
asm("ldi r18,0xeb":::"r18");  // Was 6b
asm("sts 0x0d12,r18");
asm("ldi r18,0xa2":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3103 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x02":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3104 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0x79":::"r18");  // Was f9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x82":::"r18");  // Was 02
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3105 
asm("ldi r18,0xe2":::"r18");  // Was a2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3106 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x22":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("ldi r18,0xb9":::"r18");  // Was 79
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3107 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0xe2":::"r18");  // Was 22
asm("sts 0x0d16,r18");
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3108 
asm("ldi r18,0xa2":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3109 
asm("ldi r18,0xfb":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x62":::"r18");  // Was a2
asm("sts 0x0d16,r18");
asm("ldi r18,0xd9":::"r18");  // Was f9
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3110 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x22":::"r18");  // Was 62
asm("sts 0x0d16,r18");
asm("ldi r18,0x99":::"r18");  // Was d9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3111 
asm("ldi r18,0x7b":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xe2":::"r18");  // Was 22
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3112 
asm("ldi r18,0xfb":::"r18");  // Was 7b
asm("sts 0x0d12,r18");
asm("ldi r18,0xa2":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3113 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0xd9":::"r18");  // Was 99
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3114 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0x59":::"r18");  // Was d9
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3115 
asm("ldi r18,0xe2":::"r18");  // Was a2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3116 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x22":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("ldi r18,0x99":::"r18");  // Was 59
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3117 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xe2":::"r18");  // Was 22
asm("sts 0x0d16,r18");
asm("ldi r18,0xd9":::"r18");  // Was 99
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3118 
asm("ldi r18,0xa2":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3119 
asm("ldi r18,0xf7":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x5e":::"r18");  // Was a2
asm("sts 0x0d16,r18");
asm("ldi r18,0xf9":::"r18");  // Was d9
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3120 
asm("ldi r18,0xb7":::"r18");  // Was f7
asm("sts 0x0d12,r18");
asm("ldi r18,0x1e":::"r18");  // Was 5e
asm("sts 0x0d16,r18");
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3121 
asm("ldi r18,0x77":::"r18");  // Was b7
asm("sts 0x0d12,r18");
asm("ldi r18,0xde":::"r18");  // Was 1e
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3122 
asm("ldi r18,0xf7":::"r18");  // Was 77
asm("sts 0x0d12,r18");
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3123 
asm("ldi r18,0xb7":::"r18");  // Was f7
asm("sts 0x0d12,r18");
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3124 
asm("ldi r18,0xf7":::"r18");  // Was b7
asm("sts 0x0d12,r18");
asm("ldi r18,0x79":::"r18");  // Was f9
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3125 
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3126 
asm("ldi r18,0xb7":::"r18");  // Was f7
asm("sts 0x0d12,r18");
asm("ldi r18,0x1e":::"r18");  // Was de
asm("sts 0x0d16,r18");
asm("ldi r18,0xb9":::"r18");  // Was 79
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3127 
asm("ldi r18,0xf7":::"r18");  // Was b7
asm("sts 0x0d12,r18");
asm("ldi r18,0xde":::"r18");  // Was 1e
asm("sts 0x0d16,r18");
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3128 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3129 
asm("ldi r18,0xe7":::"r18");  // Was f7
asm("sts 0x0d12,r18");
asm("ldi r18,0x4e":::"r18");  // Was 9e
asm("sts 0x0d16,r18");
asm("ldi r18,0xe9":::"r18");  // Was f9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3130 
asm("ldi r18,0xa7":::"r18");  // Was e7
asm("sts 0x0d12,r18");
asm("ldi r18,0x0e":::"r18");  // Was 4e
asm("sts 0x0d16,r18");
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3131 
asm("ldi r18,0x67":::"r18");  // Was a7
asm("sts 0x0d12,r18");
asm("ldi r18,0xce":::"r18");  // Was 0e
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3132 
asm("ldi r18,0xe7":::"r18");  // Was 67
asm("sts 0x0d12,r18");
asm("ldi r18,0x8e":::"r18");  // Was ce
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3133 
asm("ldi r18,0xa7":::"r18");  // Was e7
asm("sts 0x0d12,r18");
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3134 
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d12,r18");
asm("ldi r18,0x69":::"r18");  // Was e9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3135 
asm("ldi r18,0xce":::"r18");  // Was 8e
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3136 
asm("ldi r18,0xa7":::"r18");  // Was e7
asm("sts 0x0d12,r18");
asm("ldi r18,0x0e":::"r18");  // Was ce
asm("sts 0x0d16,r18");
asm("ldi r18,0xa9":::"r18");  // Was 69
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3137 
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d12,r18");
asm("ldi r18,0xce":::"r18");  // Was 0e
asm("sts 0x0d16,r18");
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3138 
asm("ldi r18,0x8e":::"r18");  // Was ce
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3139 
asm("ldi r18,0xd7":::"r18");  // Was e7
asm("sts 0x0d12,r18");
asm("ldi r18,0x7e":::"r18");  // Was 8e
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3140 
asm("ldi r18,0x97":::"r18");  // Was d7
asm("sts 0x0d12,r18");
asm("ldi r18,0x3e":::"r18");  // Was 7e
asm("sts 0x0d16,r18");
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3141 
asm("ldi r18,0x57":::"r18");  // Was 97
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was 3e
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3142 
asm("ldi r18,0xd7":::"r18");  // Was 57
asm("sts 0x0d12,r18");
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3143 
asm("ldi r18,0x97":::"r18");  // Was d7
asm("sts 0x0d12,r18");
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3144 
asm("ldi r18,0xd7":::"r18");  // Was 97
asm("sts 0x0d12,r18");
asm("ldi r18,0x69":::"r18");  // Was e9
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3145 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3146 
asm("ldi r18,0x97":::"r18");  // Was d7
asm("sts 0x0d12,r18");
asm("ldi r18,0x3e":::"r18");  // Was fe
asm("sts 0x0d16,r18");
asm("ldi r18,0xa9":::"r18");  // Was 69
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3147 
asm("ldi r18,0xd7":::"r18");  // Was 97
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was 3e
asm("sts 0x0d16,r18");
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3148 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3149 
asm("ldi r18,0xf7":::"r18");  // Was d7
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was be
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3150 
asm("ldi r18,0xb7":::"r18");  // Was f7
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was 6e
asm("sts 0x0d16,r18");
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3151 
asm("ldi r18,0x77":::"r18");  // Was b7
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3152 
asm("ldi r18,0xf7":::"r18");  // Was 77
asm("sts 0x0d12,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3153 
asm("ldi r18,0xb7":::"r18");  // Was f7
asm("sts 0x0d12,r18");
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3154 
asm("ldi r18,0xf7":::"r18");  // Was b7
asm("sts 0x0d12,r18");
asm("ldi r18,0x69":::"r18");  // Was e9
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3155 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3156 
asm("ldi r18,0xb7":::"r18");  // Was f7
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("ldi r18,0xa9":::"r18");  // Was 69
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3157 
asm("ldi r18,0xf7":::"r18");  // Was b7
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3158 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3159 
asm("ldi r18,0xe7":::"r18");  // Was f7
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("ldi r18,0xf9":::"r18");  // Was e9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3160 
asm("ldi r18,0xa7":::"r18");  // Was e7
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was 6e
asm("sts 0x0d16,r18");
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3161 
asm("ldi r18,0x67":::"r18");  // Was a7
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3162 
asm("ldi r18,0xe7":::"r18");  // Was 67
asm("sts 0x0d12,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3163 
asm("ldi r18,0xa7":::"r18");  // Was e7
asm("sts 0x0d12,r18");
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3164 
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d12,r18");
asm("ldi r18,0x79":::"r18");  // Was f9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3165 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3166 
asm("ldi r18,0xa7":::"r18");  // Was e7
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("ldi r18,0xb9":::"r18");  // Was 79
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3167 
asm("ldi r18,0xe7":::"r18");  // Was a7
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3168 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3169 
asm("ldi r18,0xf7":::"r18");  // Was e7
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("ldi r18,0xd9":::"r18");  // Was f9
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3170 
asm("ldi r18,0xb7":::"r18");  // Was f7
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was 6e
asm("sts 0x0d16,r18");
asm("ldi r18,0x99":::"r18");  // Was d9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3171 
asm("ldi r18,0x77":::"r18");  // Was b7
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3172 
asm("ldi r18,0xf7":::"r18");  // Was 77
asm("sts 0x0d12,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3173 
asm("ldi r18,0xb7":::"r18");  // Was f7
asm("sts 0x0d12,r18");
asm("ldi r18,0xd9":::"r18");  // Was 99
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3174 
asm("ldi r18,0xf7":::"r18");  // Was b7
asm("sts 0x0d12,r18");
asm("ldi r18,0x59":::"r18");  // Was d9
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3175 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3176 
asm("ldi r18,0xb7":::"r18");  // Was f7
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("ldi r18,0x99":::"r18");  // Was 59
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3177 
asm("ldi r18,0xf7":::"r18");  // Was b7
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xd9":::"r18");  // Was 99
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3178 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3179 
asm("ldi r18,0xff":::"r18");  // Was f7
asm("sts 0x0d12,r18");
asm("ldi r18,0x5a":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("ldi r18,0xf9":::"r18");  // Was d9
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3180 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x1a":::"r18");  // Was 5a
asm("sts 0x0d16,r18");
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3181 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xda":::"r18");  // Was 1a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3182 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3183 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3184 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x79":::"r18");  // Was f9
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3185 
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3186 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x1a":::"r18");  // Was da
asm("sts 0x0d16,r18");
asm("ldi r18,0xb9":::"r18");  // Was 79
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3187 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xda":::"r18");  // Was 1a
asm("sts 0x0d16,r18");
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3188 
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3189 
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x4a":::"r18");  // Was 9a
asm("sts 0x0d16,r18");
asm("ldi r18,0xe9":::"r18");  // Was f9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3190 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x0a":::"r18");  // Was 4a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3191 
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xca":::"r18");  // Was 0a
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3192 
asm("ldi r18,0xef":::"r18");  // Was 6f
asm("sts 0x0d12,r18");
asm("ldi r18,0x8a":::"r18");  // Was ca
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3193 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3194 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0x69":::"r18");  // Was e9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3195 
asm("ldi r18,0xca":::"r18");  // Was 8a
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3196 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x0a":::"r18");  // Was ca
asm("sts 0x0d16,r18");
asm("ldi r18,0xa9":::"r18");  // Was 69
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3197 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xca":::"r18");  // Was 0a
asm("sts 0x0d16,r18");
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3198 
asm("ldi r18,0x8a":::"r18");  // Was ca
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3199 
asm("ldi r18,0xdf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x7a":::"r18");  // Was 8a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3200 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x3a":::"r18");  // Was 7a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3201 
asm("ldi r18,0x5f":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was 3a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3202 
asm("ldi r18,0xdf":::"r18");  // Was 5f
asm("sts 0x0d12,r18");
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3203 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3204 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0x69":::"r18");  // Was e9
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3205 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3206 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x3a":::"r18");  // Was fa
asm("sts 0x0d16,r18");
asm("ldi r18,0xa9":::"r18");  // Was 69
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3207 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was 3a
asm("sts 0x0d16,r18");
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3208 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3209 
asm("ldi r18,0xff":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ba
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3210 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was 6a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3211 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3212 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3213 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3214 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x69":::"r18");  // Was e9
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3215 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3216 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("ldi r18,0xa9":::"r18");  // Was 69
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3217 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3218 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3219 
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("ldi r18,0xf9":::"r18");  // Was e9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3220 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was 6a
asm("sts 0x0d16,r18");
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3221 
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3222 
asm("ldi r18,0xef":::"r18");  // Was 6f
asm("sts 0x0d12,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3223 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3224 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0x79":::"r18");  // Was f9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3225 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3226 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("ldi r18,0xb9":::"r18");  // Was 79
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3227 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3228 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3229 
asm("ldi r18,0xff":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("ldi r18,0xd9":::"r18");  // Was f9
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3230 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was 6a
asm("sts 0x0d16,r18");
asm("ldi r18,0x99":::"r18");  // Was d9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3231 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3232 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3233 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xd9":::"r18");  // Was 99
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3234 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x59":::"r18");  // Was d9
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3235 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3236 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("ldi r18,0x99":::"r18");  // Was 59
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3237 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xd9":::"r18");  // Was 99
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3238 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3239 
asm("ldi r18,0xfb":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x5a":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("ldi r18,0xfd":::"r18");  // Was d9
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3240 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x1a":::"r18");  // Was 5a
asm("sts 0x0d16,r18");
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3241 
asm("ldi r18,0x7b":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xda":::"r18");  // Was 1a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3242 
asm("ldi r18,0xfb":::"r18");  // Was 7b
asm("sts 0x0d12,r18");
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3243 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3244 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0x7d":::"r18");  // Was fd
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3245 
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3246 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x1a":::"r18");  // Was da
asm("sts 0x0d16,r18");
asm("ldi r18,0xbd":::"r18");  // Was 7d
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3247 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xda":::"r18");  // Was 1a
asm("sts 0x0d16,r18");
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3248 
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3249 
asm("ldi r18,0xeb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x4a":::"r18");  // Was 9a
asm("sts 0x0d16,r18");
asm("ldi r18,0xed":::"r18");  // Was fd
asm("sts 0x0d1a,r18");
asm("ldi r18,0x82":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3250 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x0a":::"r18");  // Was 4a
asm("sts 0x0d16,r18");
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d1a,r18");
asm("ldi r18,0x02":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3251 
asm("ldi r18,0x6b":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0xca":::"r18");  // Was 0a
asm("sts 0x0d16,r18");
asm("ldi r18,0x82":::"r18");  // Was 02
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3252 
asm("ldi r18,0xeb":::"r18");  // Was 6b
asm("sts 0x0d12,r18");
asm("ldi r18,0x8a":::"r18");  // Was ca
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3253 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d1a,r18");
asm("ldi r18,0x02":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3254 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0x6d":::"r18");  // Was ed
asm("sts 0x0d1a,r18");
asm("ldi r18,0x82":::"r18");  // Was 02
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3255 
asm("ldi r18,0xca":::"r18");  // Was 8a
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3256 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x0a":::"r18");  // Was ca
asm("sts 0x0d16,r18");
asm("ldi r18,0xad":::"r18");  // Was 6d
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3257 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0xca":::"r18");  // Was 0a
asm("sts 0x0d16,r18");
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3258 
asm("ldi r18,0x8a":::"r18");  // Was ca
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3259 
asm("ldi r18,0xdb":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x7a":::"r18");  // Was 8a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3260 
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d12,r18");
asm("ldi r18,0x3a":::"r18");  // Was 7a
asm("sts 0x0d16,r18");
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3261 
asm("ldi r18,0x5b":::"r18");  // Was 9b
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was 3a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3262 
asm("ldi r18,0xdb":::"r18");  // Was 5b
asm("sts 0x0d12,r18");
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3263 
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d12,r18");
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3264 
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d12,r18");
asm("ldi r18,0x6d":::"r18");  // Was ed
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3265 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3266 
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d12,r18");
asm("ldi r18,0x3a":::"r18");  // Was fa
asm("sts 0x0d16,r18");
asm("ldi r18,0xad":::"r18");  // Was 6d
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3267 
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was 3a
asm("sts 0x0d16,r18");
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3268 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3269 
asm("ldi r18,0xfb":::"r18");  // Was db
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ba
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3270 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was 6a
asm("sts 0x0d16,r18");
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3271 
asm("ldi r18,0x7b":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3272 
asm("ldi r18,0xfb":::"r18");  // Was 7b
asm("sts 0x0d12,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3273 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3274 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0x6d":::"r18");  // Was ed
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3275 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3276 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("ldi r18,0xad":::"r18");  // Was 6d
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3277 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3278 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3279 
asm("ldi r18,0xeb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("ldi r18,0xfd":::"r18");  // Was ed
asm("sts 0x0d1a,r18");
asm("ldi r18,0x82":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3280 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was 6a
asm("sts 0x0d16,r18");
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d1a,r18");
asm("ldi r18,0x02":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3281 
asm("ldi r18,0x6b":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0x82":::"r18");  // Was 02
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3282 
asm("ldi r18,0xeb":::"r18");  // Was 6b
asm("sts 0x0d12,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3283 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d1a,r18");
asm("ldi r18,0x02":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3284 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0x7d":::"r18");  // Was fd
asm("sts 0x0d1a,r18");
asm("ldi r18,0x82":::"r18");  // Was 02
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3285 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3286 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("ldi r18,0xbd":::"r18");  // Was 7d
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3287 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3288 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3289 
asm("ldi r18,0xfb":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("ldi r18,0xdd":::"r18");  // Was fd
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 82
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3290 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was 6a
asm("sts 0x0d16,r18");
asm("ldi r18,0x9d":::"r18");  // Was dd
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3291 
asm("ldi r18,0x7b":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3292 
asm("ldi r18,0xfb":::"r18");  // Was 7b
asm("sts 0x0d12,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3293 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0xdd":::"r18");  // Was 9d
asm("sts 0x0d1a,r18");
asm("ldi r18,0x22":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3294 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0x5d":::"r18");  // Was dd
asm("sts 0x0d1a,r18");
asm("ldi r18,0xa2":::"r18");  // Was 22
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3295 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3296 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("ldi r18,0x9d":::"r18");  // Was 5d
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3297 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xdd":::"r18");  // Was 9d
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3298 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3299 
asm("ldi r18,0xff":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x5a":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("ldi r18,0xf5":::"r18");  // Was dd
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was a2
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3300 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x1a":::"r18");  // Was 5a
asm("sts 0x0d16,r18");
asm("ldi r18,0xb5":::"r18");  // Was f5
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3301 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xda":::"r18");  // Was 1a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3302 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3303 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xf5":::"r18");  // Was b5
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3304 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x75":::"r18");  // Was f5
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3305 
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3306 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x1a":::"r18");  // Was da
asm("sts 0x0d16,r18");
asm("ldi r18,0xb5":::"r18");  // Was 75
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3307 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xda":::"r18");  // Was 1a
asm("sts 0x0d16,r18");
asm("ldi r18,0xf5":::"r18");  // Was b5
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3308 
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3309 
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x4a":::"r18");  // Was 9a
asm("sts 0x0d16,r18");
asm("ldi r18,0xe5":::"r18");  // Was f5
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3310 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x0a":::"r18");  // Was 4a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa5":::"r18");  // Was e5
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3311 
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xca":::"r18");  // Was 0a
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3312 
asm("ldi r18,0xef":::"r18");  // Was 6f
asm("sts 0x0d12,r18");
asm("ldi r18,0x8a":::"r18");  // Was ca
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3313 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0xe5":::"r18");  // Was a5
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3314 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0x65":::"r18");  // Was e5
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3315 
asm("ldi r18,0xca":::"r18");  // Was 8a
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3316 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x0a":::"r18");  // Was ca
asm("sts 0x0d16,r18");
asm("ldi r18,0xa5":::"r18");  // Was 65
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3317 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xca":::"r18");  // Was 0a
asm("sts 0x0d16,r18");
asm("ldi r18,0xe5":::"r18");  // Was a5
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3318 
asm("ldi r18,0x8a":::"r18");  // Was ca
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3319 
asm("ldi r18,0xdf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x7a":::"r18");  // Was 8a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3320 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x3a":::"r18");  // Was 7a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa5":::"r18");  // Was e5
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3321 
asm("ldi r18,0x5f":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was 3a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3322 
asm("ldi r18,0xdf":::"r18");  // Was 5f
asm("sts 0x0d12,r18");
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3323 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0xe5":::"r18");  // Was a5
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3324 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0x65":::"r18");  // Was e5
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3325 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3326 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x3a":::"r18");  // Was fa
asm("sts 0x0d16,r18");
asm("ldi r18,0xa5":::"r18");  // Was 65
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3327 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was 3a
asm("sts 0x0d16,r18");
asm("ldi r18,0xe5":::"r18");  // Was a5
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3328 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3329 
asm("ldi r18,0xff":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ba
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3330 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was 6a
asm("sts 0x0d16,r18");
asm("ldi r18,0xa5":::"r18");  // Was e5
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3331 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3332 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3333 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xe5":::"r18");  // Was a5
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3334 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x65":::"r18");  // Was e5
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3335 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3336 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("ldi r18,0xa5":::"r18");  // Was 65
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3337 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xe5":::"r18");  // Was a5
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3338 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3339 
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("ldi r18,0xf5":::"r18");  // Was e5
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3340 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was 6a
asm("sts 0x0d16,r18");
asm("ldi r18,0xb5":::"r18");  // Was f5
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3341 
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3342 
asm("ldi r18,0xef":::"r18");  // Was 6f
asm("sts 0x0d12,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3343 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0xf5":::"r18");  // Was b5
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3344 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0x75":::"r18");  // Was f5
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3345 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3346 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("ldi r18,0xb5":::"r18");  // Was 75
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3347 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xf5":::"r18");  // Was b5
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3348 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3349 
asm("ldi r18,0xff":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("ldi r18,0xd5":::"r18");  // Was f5
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3350 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was 6a
asm("sts 0x0d16,r18");
asm("ldi r18,0x95":::"r18");  // Was d5
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3351 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3352 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3353 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xd5":::"r18");  // Was 95
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3354 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x55":::"r18");  // Was d5
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3355 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3356 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("ldi r18,0x95":::"r18");  // Was 55
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3357 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xd5":::"r18");  // Was 95
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3358 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3359 
asm("ldi r18,0x5e":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("ldi r18,0xf5":::"r18");  // Was d5
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3360 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x1e":::"r18");  // Was 5e
asm("sts 0x0d16,r18");
asm("ldi r18,0xb5":::"r18");  // Was f5
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3361 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xde":::"r18");  // Was 1e
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3362 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3363 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xf5":::"r18");  // Was b5
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3364 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x75":::"r18");  // Was f5
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3365 
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3366 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x1e":::"r18");  // Was de
asm("sts 0x0d16,r18");
asm("ldi r18,0xb5":::"r18");  // Was 75
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3367 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xde":::"r18");  // Was 1e
asm("sts 0x0d16,r18");
asm("ldi r18,0xf5":::"r18");  // Was b5
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3368 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3369 
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x4e":::"r18");  // Was 9e
asm("sts 0x0d16,r18");
asm("ldi r18,0xe5":::"r18");  // Was f5
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3370 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x0e":::"r18");  // Was 4e
asm("sts 0x0d16,r18");
asm("ldi r18,0xa5":::"r18");  // Was e5
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3371 
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xce":::"r18");  // Was 0e
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3372 
asm("ldi r18,0xef":::"r18");  // Was 6f
asm("sts 0x0d12,r18");
asm("ldi r18,0x8e":::"r18");  // Was ce
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3373 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0xe5":::"r18");  // Was a5
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3374 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0x65":::"r18");  // Was e5
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3375 
asm("ldi r18,0xce":::"r18");  // Was 8e
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3376 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x0e":::"r18");  // Was ce
asm("sts 0x0d16,r18");
asm("ldi r18,0xa5":::"r18");  // Was 65
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3377 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xce":::"r18");  // Was 0e
asm("sts 0x0d16,r18");
asm("ldi r18,0xe5":::"r18");  // Was a5
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3378 
asm("ldi r18,0x8e":::"r18");  // Was ce
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3379 
asm("ldi r18,0xdf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x7e":::"r18");  // Was 8e
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3380 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x3e":::"r18");  // Was 7e
asm("sts 0x0d16,r18");
asm("ldi r18,0xa5":::"r18");  // Was e5
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3381 
asm("ldi r18,0x5f":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was 3e
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3382 
asm("ldi r18,0xdf":::"r18");  // Was 5f
asm("sts 0x0d12,r18");
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3383 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0xe5":::"r18");  // Was a5
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3384 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0x65":::"r18");  // Was e5
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3385 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3386 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x3e":::"r18");  // Was fe
asm("sts 0x0d16,r18");
asm("ldi r18,0xa5":::"r18");  // Was 65
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3387 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was 3e
asm("sts 0x0d16,r18");
asm("ldi r18,0xe5":::"r18");  // Was a5
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3388 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3389 
asm("ldi r18,0xff":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was be
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3390 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was 6e
asm("sts 0x0d16,r18");
asm("ldi r18,0xa5":::"r18");  // Was e5
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3391 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3392 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3393 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xe5":::"r18");  // Was a5
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3394 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x65":::"r18");  // Was e5
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3395 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3396 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("ldi r18,0xa5":::"r18");  // Was 65
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3397 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xe5":::"r18");  // Was a5
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3398 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3399 
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("ldi r18,0xf5":::"r18");  // Was e5
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3400 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was 6e
asm("sts 0x0d16,r18");
asm("ldi r18,0xb5":::"r18");  // Was f5
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3401 
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3402 
asm("ldi r18,0xef":::"r18");  // Was 6f
asm("sts 0x0d12,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3403 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0xf5":::"r18");  // Was b5
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3404 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0x75":::"r18");  // Was f5
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3405 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3406 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("ldi r18,0xb5":::"r18");  // Was 75
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3407 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xf5":::"r18");  // Was b5
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3408 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3409 
asm("ldi r18,0xff":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("ldi r18,0xd5":::"r18");  // Was f5
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3410 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was 6e
asm("sts 0x0d16,r18");
asm("ldi r18,0x95":::"r18");  // Was d5
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3411 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3412 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3413 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xd5":::"r18");  // Was 95
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3414 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x55":::"r18");  // Was d5
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3415 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3416 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("ldi r18,0x95":::"r18");  // Was 55
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3417 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xd5":::"r18");  // Was 95
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3418 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3419 
asm("ldi r18,0xfb":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x52":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("ldi r18,0xf9":::"r18");  // Was d5
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3420 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x12":::"r18");  // Was 52
asm("sts 0x0d16,r18");
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3421 
asm("ldi r18,0x7b":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xd2":::"r18");  // Was 12
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3422 
asm("ldi r18,0xfb":::"r18");  // Was 7b
asm("sts 0x0d12,r18");
asm("ldi r18,0x92":::"r18");  // Was d2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3423 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3424 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0x79":::"r18");  // Was f9
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3425 
asm("ldi r18,0xd2":::"r18");  // Was 92
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3426 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x12":::"r18");  // Was d2
asm("sts 0x0d16,r18");
asm("ldi r18,0xb9":::"r18");  // Was 79
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3427 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xd2":::"r18");  // Was 12
asm("sts 0x0d16,r18");
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3428 
asm("ldi r18,0x92":::"r18");  // Was d2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3429 
asm("ldi r18,0xeb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x42":::"r18");  // Was 92
asm("sts 0x0d16,r18");
asm("ldi r18,0xe9":::"r18");  // Was f9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3430 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x02":::"r18");  // Was 42
asm("sts 0x0d16,r18");
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3431 
asm("ldi r18,0x6b":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0xc2":::"r18");  // Was 02
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3432 
asm("ldi r18,0xeb":::"r18");  // Was 6b
asm("sts 0x0d12,r18");
asm("ldi r18,0x82":::"r18");  // Was c2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3433 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3434 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0x69":::"r18");  // Was e9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3435 
asm("ldi r18,0xc2":::"r18");  // Was 82
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3436 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x02":::"r18");  // Was c2
asm("sts 0x0d16,r18");
asm("ldi r18,0xa9":::"r18");  // Was 69
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3437 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0xc2":::"r18");  // Was 02
asm("sts 0x0d16,r18");
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3438 
asm("ldi r18,0x82":::"r18");  // Was c2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3439 
asm("ldi r18,0xdb":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x72":::"r18");  // Was 82
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3440 
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d12,r18");
asm("ldi r18,0x32":::"r18");  // Was 72
asm("sts 0x0d16,r18");
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3441 
asm("ldi r18,0x5b":::"r18");  // Was 9b
asm("sts 0x0d12,r18");
asm("ldi r18,0xf2":::"r18");  // Was 32
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3442 
asm("ldi r18,0xdb":::"r18");  // Was 5b
asm("sts 0x0d12,r18");
asm("ldi r18,0xb2":::"r18");  // Was f2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3443 
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d12,r18");
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3444 
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d12,r18");
asm("ldi r18,0x69":::"r18");  // Was e9
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3445 
asm("ldi r18,0xf2":::"r18");  // Was b2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3446 
asm("ldi r18,0x9b":::"r18");  // Was db
asm("sts 0x0d12,r18");
asm("ldi r18,0x32":::"r18");  // Was f2
asm("sts 0x0d16,r18");
asm("ldi r18,0xa9":::"r18");  // Was 69
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3447 
asm("ldi r18,0xdb":::"r18");  // Was 9b
asm("sts 0x0d12,r18");
asm("ldi r18,0xf2":::"r18");  // Was 32
asm("sts 0x0d16,r18");
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3448 
asm("ldi r18,0xb2":::"r18");  // Was f2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3449 
asm("ldi r18,0xfb":::"r18");  // Was db
asm("sts 0x0d12,r18");
asm("ldi r18,0x62":::"r18");  // Was b2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3450 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x22":::"r18");  // Was 62
asm("sts 0x0d16,r18");
asm("ldi r18,0xa9":::"r18");  // Was e9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3451 
asm("ldi r18,0x7b":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xe2":::"r18");  // Was 22
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3452 
asm("ldi r18,0xfb":::"r18");  // Was 7b
asm("sts 0x0d12,r18");
asm("ldi r18,0xa2":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3453 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3454 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0x69":::"r18");  // Was e9
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3455 
asm("ldi r18,0xe2":::"r18");  // Was a2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3456 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x22":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("ldi r18,0xa9":::"r18");  // Was 69
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3457 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xe2":::"r18");  // Was 22
asm("sts 0x0d16,r18");
asm("ldi r18,0xe9":::"r18");  // Was a9
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3458 
asm("ldi r18,0xa2":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3459 
asm("ldi r18,0xeb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x62":::"r18");  // Was a2
asm("sts 0x0d16,r18");
asm("ldi r18,0xf9":::"r18");  // Was e9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3460 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x22":::"r18");  // Was 62
asm("sts 0x0d16,r18");
asm("ldi r18,0xb9":::"r18");  // Was f9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3461 
asm("ldi r18,0x6b":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0xe2":::"r18");  // Was 22
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3462 
asm("ldi r18,0xeb":::"r18");  // Was 6b
asm("sts 0x0d12,r18");
asm("ldi r18,0xa2":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3463 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3464 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0x79":::"r18");  // Was f9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3465 
asm("ldi r18,0xe2":::"r18");  // Was a2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3466 
asm("ldi r18,0xab":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x22":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("ldi r18,0xb9":::"r18");  // Was 79
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3467 
asm("ldi r18,0xeb":::"r18");  // Was ab
asm("sts 0x0d12,r18");
asm("ldi r18,0xe2":::"r18");  // Was 22
asm("sts 0x0d16,r18");
asm("ldi r18,0xf9":::"r18");  // Was b9
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3468 
asm("ldi r18,0xa2":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3469 
asm("ldi r18,0xfb":::"r18");  // Was eb
asm("sts 0x0d12,r18");
asm("ldi r18,0x62":::"r18");  // Was a2
asm("sts 0x0d16,r18");
asm("ldi r18,0xd9":::"r18");  // Was f9
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3470 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x22":::"r18");  // Was 62
asm("sts 0x0d16,r18");
asm("ldi r18,0x99":::"r18");  // Was d9
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3471 
asm("ldi r18,0x7b":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xe2":::"r18");  // Was 22
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3472 
asm("ldi r18,0xfb":::"r18");  // Was 7b
asm("sts 0x0d12,r18");
asm("ldi r18,0xa2":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3473 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0xd9":::"r18");  // Was 99
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3474 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0x59":::"r18");  // Was d9
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3475 
asm("ldi r18,0xe2":::"r18");  // Was a2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3476 
asm("ldi r18,0xbb":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x22":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("ldi r18,0x99":::"r18");  // Was 59
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3477 
asm("ldi r18,0xfb":::"r18");  // Was bb
asm("sts 0x0d12,r18");
asm("ldi r18,0xe2":::"r18");  // Was 22
asm("sts 0x0d16,r18");
asm("ldi r18,0xd9":::"r18");  // Was 99
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3478 
asm("ldi r18,0xa2":::"r18");  // Was e2
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3479 
asm("ldi r18,0xff":::"r18");  // Was fb
asm("sts 0x0d12,r18");
asm("ldi r18,0x5e":::"r18");  // Was a2
asm("sts 0x0d16,r18");
asm("ldi r18,0xfd":::"r18");  // Was d9
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3480 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x1e":::"r18");  // Was 5e
asm("sts 0x0d16,r18");
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3481 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xde":::"r18");  // Was 1e
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3482 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3483 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3484 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x7d":::"r18");  // Was fd
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3485 
asm("ldi r18,0xde":::"r18");  // Was 9e
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3486 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x1e":::"r18");  // Was de
asm("sts 0x0d16,r18");
asm("ldi r18,0xbd":::"r18");  // Was 7d
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3487 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xde":::"r18");  // Was 1e
asm("sts 0x0d16,r18");
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3488 
asm("ldi r18,0x9e":::"r18");  // Was de
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3489 
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x4e":::"r18");  // Was 9e
asm("sts 0x0d16,r18");
asm("ldi r18,0xed":::"r18");  // Was fd
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3490 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x0e":::"r18");  // Was 4e
asm("sts 0x0d16,r18");
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3491 
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xce":::"r18");  // Was 0e
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3492 
asm("ldi r18,0xef":::"r18");  // Was 6f
asm("sts 0x0d12,r18");
asm("ldi r18,0x8e":::"r18");  // Was ce
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3493 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3494 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0x6d":::"r18");  // Was ed
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3495 
asm("ldi r18,0xce":::"r18");  // Was 8e
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3496 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x0e":::"r18");  // Was ce
asm("sts 0x0d16,r18");
asm("ldi r18,0xad":::"r18");  // Was 6d
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3497 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xce":::"r18");  // Was 0e
asm("sts 0x0d16,r18");
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3498 
asm("ldi r18,0x8e":::"r18");  // Was ce
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3499 
asm("ldi r18,0xdf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x7e":::"r18");  // Was 8e
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3500 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x3e":::"r18");  // Was 7e
asm("sts 0x0d16,r18");
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3501 
asm("ldi r18,0x5f":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was 3e
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3502 
asm("ldi r18,0xdf":::"r18");  // Was 5f
asm("sts 0x0d12,r18");
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3503 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3504 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0x6d":::"r18");  // Was ed
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3505 
asm("ldi r18,0xfe":::"r18");  // Was be
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3506 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x3e":::"r18");  // Was fe
asm("sts 0x0d16,r18");
asm("ldi r18,0xad":::"r18");  // Was 6d
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3507 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0xfe":::"r18");  // Was 3e
asm("sts 0x0d16,r18");
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3508 
asm("ldi r18,0xbe":::"r18");  // Was fe
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3509 
asm("ldi r18,0xff":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was be
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3510 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was 6e
asm("sts 0x0d16,r18");
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3511 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3512 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3513 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3514 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x6d":::"r18");  // Was ed
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3515 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3516 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("ldi r18,0xad":::"r18");  // Was 6d
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3517 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3518 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3519 
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("ldi r18,0xfd":::"r18");  // Was ed
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3520 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was 6e
asm("sts 0x0d16,r18");
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3521 
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3522 
asm("ldi r18,0xef":::"r18");  // Was 6f
asm("sts 0x0d12,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3523 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3524 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0x7d":::"r18");  // Was fd
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3525 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3526 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("ldi r18,0xbd":::"r18");  // Was 7d
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3527 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3528 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3529 
asm("ldi r18,0xff":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x6e":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("ldi r18,0xdd":::"r18");  // Was fd
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3530 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was 6e
asm("sts 0x0d16,r18");
asm("ldi r18,0x9d":::"r18");  // Was dd
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3531 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3532 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3533 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xdd":::"r18");  // Was 9d
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3534 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x5d":::"r18");  // Was dd
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3535 
asm("ldi r18,0xee":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3536 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2e":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("ldi r18,0x9d":::"r18");  // Was 5d
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3537 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xee":::"r18");  // Was 2e
asm("sts 0x0d16,r18");
asm("ldi r18,0xdd":::"r18");  // Was 9d
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3538 
asm("ldi r18,0xae":::"r18");  // Was ee
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3539 
asm("ldi r18,0x5a":::"r18");  // Was ae
asm("sts 0x0d16,r18");
asm("ldi r18,0xfd":::"r18");  // Was dd
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3540 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x1a":::"r18");  // Was 5a
asm("sts 0x0d16,r18");
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3541 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xda":::"r18");  // Was 1a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3542 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3543 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3544 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x7d":::"r18");  // Was fd
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3545 
asm("ldi r18,0xda":::"r18");  // Was 9a
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3546 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x1a":::"r18");  // Was da
asm("sts 0x0d16,r18");
asm("ldi r18,0xbd":::"r18");  // Was 7d
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3547 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xda":::"r18");  // Was 1a
asm("sts 0x0d16,r18");
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3548 
asm("ldi r18,0x9a":::"r18");  // Was da
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3549 
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x4a":::"r18");  // Was 9a
asm("sts 0x0d16,r18");
asm("ldi r18,0xed":::"r18");  // Was fd
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3550 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x0a":::"r18");  // Was 4a
asm("sts 0x0d16,r18");
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3551 
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xca":::"r18");  // Was 0a
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3552 
asm("ldi r18,0xef":::"r18");  // Was 6f
asm("sts 0x0d12,r18");
asm("ldi r18,0x8a":::"r18");  // Was ca
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3553 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3554 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0x6d":::"r18");  // Was ed
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3555 
asm("ldi r18,0xca":::"r18");  // Was 8a
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3556 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x0a":::"r18");  // Was ca
asm("sts 0x0d16,r18");
asm("ldi r18,0xad":::"r18");  // Was 6d
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3557 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xca":::"r18");  // Was 0a
asm("sts 0x0d16,r18");
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3558 
asm("ldi r18,0x8a":::"r18");  // Was ca
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3559 
asm("ldi r18,0xdf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x7a":::"r18");  // Was 8a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3560 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x3a":::"r18");  // Was 7a
asm("sts 0x0d16,r18");
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3561 
asm("ldi r18,0x5f":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was 3a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3562 
asm("ldi r18,0xdf":::"r18");  // Was 5f
asm("sts 0x0d12,r18");
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3563 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3564 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0x6d":::"r18");  // Was ed
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3565 
asm("ldi r18,0xfa":::"r18");  // Was ba
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3566 
asm("ldi r18,0x9f":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x3a":::"r18");  // Was fa
asm("sts 0x0d16,r18");
asm("ldi r18,0xad":::"r18");  // Was 6d
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3567 
asm("ldi r18,0xdf":::"r18");  // Was 9f
asm("sts 0x0d12,r18");
asm("ldi r18,0xfa":::"r18");  // Was 3a
asm("sts 0x0d16,r18");
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3568 
asm("ldi r18,0xba":::"r18");  // Was fa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3569 
asm("ldi r18,0xff":::"r18");  // Was df
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was ba
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3570 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was 6a
asm("sts 0x0d16,r18");
asm("ldi r18,0xad":::"r18");  // Was ed
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3571 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3572 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3573 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3574 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x6d":::"r18");  // Was ed
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3575 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3576 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("ldi r18,0xad":::"r18");  // Was 6d
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3577 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xed":::"r18");  // Was ad
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3578 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3579 
asm("ldi r18,0xef":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("ldi r18,0xfd":::"r18");  // Was ed
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3580 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was 6a
asm("sts 0x0d16,r18");
asm("ldi r18,0xbd":::"r18");  // Was fd
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3581 
asm("ldi r18,0x6f":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3582 
asm("ldi r18,0xef":::"r18");  // Was 6f
asm("sts 0x0d12,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3583 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d1a,r18");
asm("ldi r18,0x0a":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3584 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0x7d":::"r18");  // Was fd
asm("sts 0x0d1a,r18");
asm("ldi r18,0x8a":::"r18");  // Was 0a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3585 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3586 
asm("ldi r18,0xaf":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("ldi r18,0xbd":::"r18");  // Was 7d
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3587 
asm("ldi r18,0xef":::"r18");  // Was af
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xfd":::"r18");  // Was bd
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3588 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3589 
asm("ldi r18,0xff":::"r18");  // Was ef
asm("sts 0x0d12,r18");
asm("ldi r18,0x6a":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("ldi r18,0xdd":::"r18");  // Was fd
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 8a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3590 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was 6a
asm("sts 0x0d16,r18");
asm("ldi r18,0x9d":::"r18");  // Was dd
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3591 
asm("ldi r18,0x7f":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3592 
asm("ldi r18,0xff":::"r18");  // Was 7f
asm("sts 0x0d12,r18");
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3593 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0xdd":::"r18");  // Was 9d
asm("sts 0x0d1a,r18");
asm("ldi r18,0x2a":::"r18");  // Was aa
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3594 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0x5d":::"r18");  // Was dd
asm("sts 0x0d1a,r18");
asm("ldi r18,0xaa":::"r18");  // Was 2a
asm("sts 0x0d1e,r18");
asm("sleep");  // Step 3595 
asm("ldi r18,0xea":::"r18");  // Was aa
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3596 
asm("ldi r18,0xbf":::"r18");  // Was ff
asm("sts 0x0d12,r18");
asm("ldi r18,0x2a":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("ldi r18,0x9d":::"r18");  // Was 5d
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3597 
asm("ldi r18,0xff":::"r18");  // Was bf
asm("sts 0x0d12,r18");
asm("ldi r18,0xea":::"r18");  // Was 2a
asm("sts 0x0d16,r18");
asm("ldi r18,0xdd":::"r18");  // Was 9d
asm("sts 0x0d1a,r18");
asm("sleep");  // Step 3598 
asm("ldi r18,0xaa":::"r18");  // Was ea
asm("sts 0x0d16,r18");
asm("sleep");  // Step 3599 
}
