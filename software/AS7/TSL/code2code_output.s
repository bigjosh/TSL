
/*
 * code2code_output.s
 *
 * Created: 3/3/2019 12:35:36 AM
 *  Author: passp
 */ 

 .global update_lcd_1_hour

.section .text

update_lcd_1_hour:   
 
    // First we will load up the indirect pointers to point to the top 3 LCD addresses
    // so we can get to those in 1 cycle with ST rather than 2 cycles for an STS
    LDI r27,0x0d             ; Store high byte of address of LCD reg 06 to X
    LDI r26,0x16             ; Store low byte of address of LCD reg 06 to X
    LDI r29,0x0d             ; Store high byte of address of LCD reg 02 to Y
    LDI r28,0x12             ; Store low byte of address of LCD reg 02 to Y
    LDI r31,0x0d             ; Store high byte of address of LCD reg 10 to Z
    LDI r30,0x1a             ; Store low byte of address of LCD reg 10 to Z

    // Next we will load up the some available XMEGA registers with the most commonly
    // stored values so we can save an LDI to load them again.

    // ---- Step    0 (00:00)
    LDI r18,0xff             ; Was UNKNOWN
    ST Y,r18                 ; 2868 accesses to R02
    LDI r18,0x55             ; Was UNKNOWN
    ST X,r18                 ; 2874 accesses to R06
    LDI r18,0xff             ; Was UNKNOWN
    ST Z,r18                 ; 2040 accesses to R10
    LDI r18,0xaa             ; Was UNKNOWN
    STS 0x0D1E,r18           ; direct store to LCD register 14
    // --- Cycles in this step: 9
    SLEEP                    ; Wait for interrupt from TX8900

    // ---- Step    1 (00:01)
    LDI r18,0xbf             ; Was ff
    ST Y,r18                 ; 2868 accesses to R02
    LDI r18,0x15             ; Was 55
    ST X,r18                 ; 2874 accesses to R06
    LDI r18,0xbf             ; Was ff
    ST Z,r18                 ; 2040 accesses to R10
    LDI r18,0x2a             ; Was aa
    STS 0x0D1E,r18           ; direct store to LCD register 14
    // --- Cycles in this step: 9
    SLEEP                    ; Wait for interrupt from TX8900

    // ---- Step    2 (00:02)
    LDI r18,0x7f             ; Was bf
    ST Y,r18                 ; 2868 accesses to R02
    LDI r18,0xd5             ; Was 15
    ST X,r18                 ; 2874 accesses to R06
    LDI r18,0xaa             ; Was 2a
    STS 0x0D1E,r18           ; direct store to LCD register 14
    // --- Cycles in this step: 7
    SLEEP                    ; Wait for interrupt from TX8900

    // ---- Step    3 (00:03)
    LDI r18,0xff             ; Was 7f
    ST Y,r18                 ; 2868 accesses to R02
    LDI r18,0x95             ; Was d5
    ST X,r18                 ; 2874 accesses to R06
    // --- Cycles in this step: 4
    SLEEP                    ; Wait for interrupt from TX8900

    // ---- Step    4 (00:04)
    LDI r18,0xbf             ; Was ff
    ST Y,r18                 ; 2868 accesses to R02
    LDI r18,0xff             ; Was bf
    ST Z,r18                 ; 2040 accesses to R10
    LDI r18,0x2a             ; Was aa
    STS 0x0D1E,r18           ; direct store to LCD register 14
    // --- Cycles in this step: 7
    SLEEP                    ; Wait for interrupt from TX8900

    // ---- Step    5 (00:05)
    LDI r18,0xff             ; Was bf
    ST Y,r18                 ; 2868 accesses to R02
    LDI r18,0x7f             ; Was ff
    ST Z,r18                 ; 2040 accesses to R10
    LDI r18,0xaa             ; Was 2a
    STS 0x0D1E,r18           ; direct store to LCD register 14
    // --- Cycles in this step: 7
    SLEEP                    ; Wait for interrupt from TX8900

    // ---- Step    6 (00:06)
    LDI r18,0xd5             ; Was 95
    ST X,r18                 ; 2874 accesses to R06
    // --- Cycles in this step: 2
    SLEEP                    ; Wait for interrupt from TX8900

    // ---- Step    7 (00:07)
    LDI r18,0xbf             ; Was ff
    ST Y,r18                 ; 2868 accesses to R02
    LDI r18,0x15             ; Was d5
    ST X,r18                 ; 2874 accesses to R06
    LDI r18,0xbf             ; Was 7f
    ST Z,r18                 ; 2040 accesses to R10
    // --- Cycles in this step: 6
    SLEEP                    ; Wait for interrupt from TX8900

    // ---- Step    8 (00:08)
    LDI r18,0xff             ; Was bf
    ST Y,r18                 ; 2868 accesses to R02
    LDI r18,0xd5             ; Was 15
    ST X,r18                 ; 2874 accesses to R06
    LDI r18,0xff             ; Was bf
    ST Z,r18                 ; 2040 accesses to R10
    // --- Cycles in this step: 6
    SLEEP                    ; Wait for interrupt from TX8900

    // ---- Step    9 (00:09)
    LDI r18,0x95             ; Was d5
    ST X,r18                 ; 2874 accesses to R06
    // --- Cycles in this step: 2
    SLEEP                    ; Wait for interrupt from TX8900

    // ---- Step   10 (00:10)
    LDI r18,0xef             ; Was ff
    ST Y,r18                 ; 2868 accesses to R02
    LDI r18,0x45             ; Was 95
    ST X,r18                 ; 2874 accesses to R06
    LDI r18,0xef             ; Was ff
    ST Z,r18                 ; 2040 accesses to R10
    LDI r18,0x8a             ; Was aa
    STS 0x0D1E,r18           ; direct store to LCD register 14
    // --- Cycles in this step: 9
    SLEEP                    ; Wait for interrupt from TX8900

    // ---- Step   11 (00:11)
    LDI r18,0xaf             ; Was ef
    ST Y,r18                 ; 2868 accesses to R02
    LDI r18,0x05             ; Was 45
    ST X,r18                 ; 2874 accesses to R06
    LDI r18,0xaf             ; Was ef
    ST Z,r18                 ; 2040 accesses to R10
    LDI r18,0x0a             ; Was 8a
    STS 0x0D1E,r18           ; direct store to LCD register 14
    // --- Cycles in this step: 9
    SLEEP                    ; Wait for interrupt from TX8900

    // ---- Step   12 (00:12)
    LDI r18,0x6f             ; Was af
    ST Y,r18                 ; 2868 accesses to R02
    LDI r18,0xc5             ; Was 05
    ST X,r18                 ; 2874 accesses to R06
    LDI r18,0x8a             ; Was 0a
    STS 0x0D1E,r18           ; direct store to LCD register 14
    // --- Cycles in this step: 7
    SLEEP                    ; Wait for interrupt from TX8900

    // ---- Step   13 (00:13)
    LDI r18,0xef             ; Was 6f
    ST Y,r18                 ; 2868 accesses to R02
    LDI r18,0x85             ; Was c5
    ST X,r18                 ; 2874 accesses to R06
    // --- Cycles in this step: 4
    SLEEP                    ; Wait for interrupt from TX8900

    // ---- Step   14 (00:14)
    LDI r18,0xaf             ; Was ef
    ST Y,r18                 ; 2868 accesses to R02
    LDI r18,0xef             ; Was af
    ST Z,r18                 ; 2040 accesses to R10
    LDI r18,0x0a             ; Was 8a
    STS 0x0D1E,r18           ; direct store to LCD register 14
    // --- Cycles in this step: 7
    SLEEP                    ; Wait for interrupt from TX8900

    // ---- Step   15 (00:15)
    LDI r18,0xef             ; Was af
    ST Y,r18                 ; 2868 accesses to R02
    LDI r18,0x6f             ; Was ef
    ST Z,r18                 ; 2040 accesses to R10
    LDI r18,0x8a             ; Was 0a
    STS 0x0D1E,r18           ; direct store to LCD register 14
    // --- Cycles in this step: 7
    SLEEP                    ; Wait for interrupt from TX8900

    // ---- Step   16 (00:16)
    LDI r18,0xc5             ; Was 85
    ST X,r18                 ; 2874 accesses to R06
    // --- Cycles in this step: 2
    SLEEP                    ; Wait for interrupt from TX8900

    // ---- Step   17 (00:17)
    LDI r18,0xaf             ; Was ef
    ST Y,r18                 ; 2868 accesses to R02
    LDI r18,0x05             ; Was c5
    ST X,r18                 ; 2874 accesses to R06
    LDI r18,0xaf             ; Was 6f
    ST Z,r18                 ; 2040 accesses to R10
    // --- Cycles in this step: 6
    SLEEP                    ; Wait for interrupt from TX8900

    // ---- Step   18 (00:18)
    LDI r18,0xef             ; Was af
    ST Y,r18                 ; 2868 accesses to R02
    LDI r18,0xc5             ; Was 05
    ST X,r18                 ; 2874 accesses to R06
    LDI r18,0xef             ; Was af
    ST Z,r18                 ; 2040 accesses to R10
    // --- Cycles in this step: 6
    SLEEP                    ; Wait for interrupt from TX8900

    // ---- Step   19 (00:19)
    LDI r18,0x85             ; Was c5
    ST X,r18                 ; 2874 accesses to R06
    // --- Cycles in this step: 2
    SLEEP                    ; Wait for interrupt from TX8900
    // --- Total display update cycles in sequence: 118
    
.end    