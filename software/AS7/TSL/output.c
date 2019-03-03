// Step though a full hour of LCD updates (3600 in all)

void lcd_run_for_an_hour() {

    // First we will load up the indirect pointers to point to the top 3 LCD addresses
    // so we can get to those in 1 cycle with ST rather than 2 cycles for an STS
    asm("LDI r27,0x0d        ":::"r27");    // Store high byte of address of LCD reg 06 to X
    asm("LDI r26,0x16        ":::"r26");    // Store low byte of address of LCD reg 06 to X
    asm("LDI r31,0x0d        ":::"r31");    // Store high byte of address of LCD reg 02 to Z
    asm("LDI r30,0x12        ":::"r30");    // Store low byte of address of LCD reg 02 to Z

    // Next we will load up the some available XMEGA registers with the most commonly
    // stored values so we can save an LDI to load them again.

    // ---- Step    0 (00:00)
    asm("LDI r18,0xff        ":::"r18");    // Was UNKNOWN
    asm("ST Z,r18            ":::     );    // 2868 accesses to R02
    asm("LDI r18,0x55        ":::"r18");    // Was UNKNOWN
    asm("ST X,r18            ":::     );    // 2874 accesses to R06
    asm("LDI r18,0xff        ":::"r18");    // Was UNKNOWN
    asm("STS 0x0D1A,r18      ":::     );    // direct store to LCD register 10
    asm("LDI r18,0xaa        ":::"r18");    // Was UNKNOWN
    asm("STS 0x0D1E,r18      ":::     );    // direct store to LCD register 14
    // --- Cycles in this step: 10
    asm("SLEEP               ":::     );    // Wait for interrupt from TX8900

    // ---- Step    1 (00:01)
    asm("LDI r18,0xbf        ":::"r18");    // Was ff
    asm("ST Z,r18            ":::     );    // 2868 accesses to R02
    asm("LDI r18,0x15        ":::"r18");    // Was 55
    asm("ST X,r18            ":::     );    // 2874 accesses to R06
    asm("LDI r18,0xbf        ":::"r18");    // Was ff
    asm("STS 0x0D1A,r18      ":::     );    // direct store to LCD register 10
    asm("LDI r18,0x2a        ":::"r18");    // Was aa
    asm("STS 0x0D1E,r18      ":::     );    // direct store to LCD register 14
    // --- Cycles in this step: 10
    asm("SLEEP               ":::     );    // Wait for interrupt from TX8900

    // ---- Step    2 (00:02)
    asm("LDI r18,0x7f        ":::"r18");    // Was bf
    asm("ST Z,r18            ":::     );    // 2868 accesses to R02
    asm("LDI r18,0xd5        ":::"r18");    // Was 15
    asm("ST X,r18            ":::     );    // 2874 accesses to R06
    asm("LDI r18,0xaa        ":::"r18");    // Was 2a
    asm("STS 0x0D1E,r18      ":::     );    // direct store to LCD register 14
    // --- Cycles in this step: 7
    asm("SLEEP               ":::     );    // Wait for interrupt from TX8900

    // ---- Step    3 (00:03)
    asm("LDI r18,0xff        ":::"r18");    // Was 7f
    asm("ST Z,r18            ":::     );    // 2868 accesses to R02
    asm("LDI r18,0x95        ":::"r18");    // Was d5
    asm("ST X,r18            ":::     );    // 2874 accesses to R06
    // --- Cycles in this step: 4
    asm("SLEEP               ":::     );    // Wait for interrupt from TX8900

    // ---- Step    4 (00:04)
    asm("LDI r18,0xbf        ":::"r18");    // Was ff
    asm("ST Z,r18            ":::     );    // 2868 accesses to R02
    asm("LDI r18,0xff        ":::"r18");    // Was bf
    asm("STS 0x0D1A,r18      ":::     );    // direct store to LCD register 10
    asm("LDI r18,0x2a        ":::"r18");    // Was aa
    asm("STS 0x0D1E,r18      ":::     );    // direct store to LCD register 14
    // --- Cycles in this step: 8
    asm("SLEEP               ":::     );    // Wait for interrupt from TX8900

    // ---- Step    5 (00:05)
    asm("LDI r18,0xff        ":::"r18");    // Was bf
    asm("ST Z,r18            ":::     );    // 2868 accesses to R02
    asm("LDI r18,0x7f        ":::"r18");    // Was ff
    asm("STS 0x0D1A,r18      ":::     );    // direct store to LCD register 10
    asm("LDI r18,0xaa        ":::"r18");    // Was 2a
    asm("STS 0x0D1E,r18      ":::     );    // direct store to LCD register 14
    // --- Cycles in this step: 8
    asm("SLEEP               ":::     );    // Wait for interrupt from TX8900

    // ---- Step    6 (00:06)
    asm("LDI r18,0xd5        ":::"r18");    // Was 95
    asm("ST X,r18            ":::     );    // 2874 accesses to R06
    // --- Cycles in this step: 2
    asm("SLEEP               ":::     );    // Wait for interrupt from TX8900

    // ---- Step    7 (00:07)
    asm("LDI r18,0xbf        ":::"r18");    // Was ff
    asm("ST Z,r18            ":::     );    // 2868 accesses to R02
    asm("LDI r18,0x15        ":::"r18");    // Was d5
    asm("ST X,r18            ":::     );    // 2874 accesses to R06
    asm("LDI r18,0xbf        ":::"r18");    // Was 7f
    asm("STS 0x0D1A,r18      ":::     );    // direct store to LCD register 10
    // --- Cycles in this step: 7
    asm("SLEEP               ":::     );    // Wait for interrupt from TX8900

    // ---- Step    8 (00:08)
    asm("LDI r18,0xff        ":::"r18");    // Was bf
    asm("ST Z,r18            ":::     );    // 2868 accesses to R02
    asm("LDI r18,0xd5        ":::"r18");    // Was 15
    asm("ST X,r18            ":::     );    // 2874 accesses to R06
    asm("LDI r18,0xff        ":::"r18");    // Was bf
    asm("STS 0x0D1A,r18      ":::     );    // direct store to LCD register 10
    // --- Cycles in this step: 7
    asm("SLEEP               ":::     );    // Wait for interrupt from TX8900

    // ---- Step    9 (00:09)
    asm("LDI r18,0x95        ":::"r18");    // Was d5
    asm("ST X,r18            ":::     );    // 2874 accesses to R06
    // --- Cycles in this step: 2
    asm("SLEEP               ":::     );    // Wait for interrupt from TX8900
    // --- Total display update cycles in sequence: 65
}