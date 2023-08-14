/*---------------------------------------------------------------------------------


    Capcom Logo for SNES Projects


---------------------------------------------------------------------------------*/
#include <snes.h>
#include "soundbank.h"

#define BG0 0
#define BG1 1
#define BG2 2
#define BG3 3
#define PAL0 0
#define PAL1 1

// ROM

#define blackColor RGB5(0x00, 0x00, 0x00)

const u8 emptyPicture[] = {
    // First part
    0b00000000, 0b00000000, // Bit plane 1 + Bit plane 0
    0b00000000, 0b00000000, 
    0b00000000, 0b00000000, 
    0b00000000, 0b00000000, 
    0b00000000, 0b00000000, 
    0b00000000, 0b00000000, 
    0b00000000, 0b00000000, 
    0b00000000, 0b00000000,

    // Second part
    0b00000000, 0b00000000, 
    0b00000000, 0b00000000, 
    0b00000000, 0b00000000, 
    0b00000000, 0b00000000, 
    0b00000000, 0b00000000, 
    0b00000000, 0b00000000, 
    0b00000000, 0b00000000, 
    0b00000000, 0b00000000
};

extern char SOUNDBANK__;

extern char logoPic, logoPic_end;
extern char logoPalette;

const u16 logoTileMap[] = {
37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 
37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 
37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 
37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 
37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 
37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 
37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 
37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 
37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 
37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 
37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 
37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 
37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 00 | (PAL1<<10), 01 | (PAL1<<10), 02 | (PAL1<<10), 03 | (PAL1<<10), 04 | (PAL1<<10), 05 | (PAL1<<10), 06 | (PAL1<<10), 07 | (PAL1<<10), 8 | (PAL1<<10), 9 | (PAL1<<10), 10 | (PAL1<<10), 11 | (PAL1<<10),  37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 
37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 12 | (PAL1<<10), 13 | (PAL1<<10), 14 | (PAL1<<10), 15 | (PAL1<<10), 16 | (PAL1<<10), 17 | (PAL1<<10), 18 | (PAL1<<10), 19 | (PAL1<<10), 20 | (PAL1<<10), 21 | (PAL1<<10), 22 | (PAL1<<10), 23 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10),
37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 24 | (PAL1<<10), 25 | (PAL1<<10), 26 | (PAL1<<10), 27 | (PAL1<<10), 28 | (PAL1<<10), 29 | (PAL1<<10), 30 | (PAL1<<10), 31 | (PAL1<<10), 32 | (PAL1<<10), 33 | (PAL1<<10), 34 | (PAL1<<10), 35 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10),
37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 
37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 
37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 
37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 
37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 
37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 
37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 
37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 
37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 
37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 
37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 
37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 
37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 
37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 
37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 
37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 
37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10), 37 | (PAL1<<10)
};

const u16 logoPalette1[] = {
    blackColor, 

    RGB8(255, 255, 239),
    RGB8(255, 247, 41), 
    RGB8(231, 214, 33), 

    RGB8(214, 181, 0),
    RGB8(181, 148, 0),

    RGB8(247, 231, 222),
    RGB8(231, 181, 0),
    RGB8(173, 123, 0),
    RGB8(132, 82, 0),
    RGB8(107, 57, 0),

    RGB8(41, 74, 173),
    RGB8(33, 66, 165),
    RGB8(24, 57, 156),
    RGB8(16, 49, 148),

    RGB8(16, 16, 16)
};

const u16 logoPalette2[] = {
    blackColor, 

    RGB8(255, 247, 41), 
    RGB8(255, 255, 239),
    RGB8(231, 214, 33), 

    RGB8(214, 181, 0),
    RGB8(181, 148, 0),

    RGB8(231, 181, 0),
    RGB8(247, 231, 222),
    RGB8(173, 123, 0),
    RGB8(132, 82, 0),
    RGB8(107, 57, 0),

    RGB8(16, 49, 148),
    RGB8(41, 74, 173),
    RGB8(33, 66, 165),
    RGB8(24, 57, 156),

    RGB8(16, 16, 16)
};

const u16 logoPalette3[] = {
    blackColor, 

    RGB8(231, 214, 33), 
    RGB8(255, 247, 41), 
    RGB8(255, 255, 239),

    RGB8(214, 181, 0),
    RGB8(181, 148, 0),

    RGB8(107, 57, 0),
    RGB8(231, 181, 0),
    RGB8(247, 231, 222),
    RGB8(173, 123, 0),
    RGB8(132, 82, 0),

    RGB8(24, 57, 156),
    RGB8(16, 49, 148),
    RGB8(41, 74, 173),
    RGB8(33, 66, 165),

    RGB8(16, 16, 16)
};

const u16 logoPalette4[] = {
    blackColor, 

    RGB8(214, 181, 0),
    RGB8(231, 214, 33), 
    RGB8(255, 247, 41), 

    RGB8(255, 255, 239),
    RGB8(255, 255, 239),

    RGB8(132, 82, 0),
    RGB8(173, 123, 0),
    RGB8(231, 181, 0),
    RGB8(247, 231, 222),
    RGB8(247, 231, 222),

    RGB8(33, 66, 165),
    RGB8(24, 57, 156),
    RGB8(16, 49, 148),
    RGB8(41, 74, 173),

    RGB8(16, 16, 16)
};

const u16 logoPalette5[] = {
    blackColor, 

    RGB8(231, 214, 33), 
    RGB8(255, 247, 41), 
    RGB8(255, 255, 239),

    RGB8(214, 181, 0),
    RGB8(181, 148, 0),

    RGB8(107, 57, 0),
    RGB8(231, 181, 0),
    RGB8(247, 231, 222),
    RGB8(173, 123, 0),
    RGB8(132, 82, 0),

    RGB8(24, 57, 156),
    RGB8(16, 49, 148),
    RGB8(41, 74, 173),
    RGB8(33, 66, 165),

    RGB8(16, 16, 16)
};

const u16 logoPalette6[] = {
    blackColor, 

    RGB8(255, 247, 41), 
    RGB8(255, 255, 239),
    RGB8(231, 214, 33), 

    RGB8(214, 181, 0),
    RGB8(181, 148, 0),

    RGB8(231, 181, 0),
    RGB8(247, 231, 222),
    RGB8(173, 123, 0),
    RGB8(132, 82, 0),
    RGB8(107, 57, 0),

    RGB8(16, 49, 148),
    RGB8(41, 74, 173),
    RGB8(33, 66, 165),
    RGB8(24, 57, 156),

    RGB8(16, 16, 16)
};

const u8 logoTimerOffset = 0;

// RAM

u16 bgTileIndex;
u16 bg3TileMap[1024];
u8 logoState;
u8 logoTimer;

/*!\brief Load the logo music.
*/
void initLogoMusic() {
    spcSetBank(&SOUNDBANK__);
    spcLoad(MOD_LOGO);
}

/*!\brief Set all the tiles to 0, set a palette number and a tile priority.
*/
void clearBgTextEx(u16 *tileMap, u8 paletteNumber, u8 priority) {
    for (bgTileIndex=0; bgTileIndex < 1024;) {
        tileMap[bgTileIndex] = 0 | (paletteNumber<<10) | (priority<<13);
        bgTileIndex += 1;
    }
}

/*!\brief Load a black background on BG3.
*/
void initBg3Black() {
    bgSetMapPtr(BG2, 0x0000 + 2048, SC_32x32);
    bgSetGfxPtr(BG2, 0x5000);
    clearBgTextEx((u16 *)bg3TileMap, PAL0, 0);
    WaitForVBlank();
    setPaletteColor(PAL0, blackColor);
    dmaCopyVram((u8 *)bg3TileMap, 0x1000, 32*32*2);
    dmaCopyVram((u8 *)emptyPicture, 0x5000, 32);
}

/*!\brief Copy the given palette to CGRAM.
*/
void initBackgroundPalette(u8 *source, u16 tilePaletteNumber) {
    dmaCopyCGram(source, tilePaletteNumber<<4, 32);
}

/*!\brief Initialize the logo screen.
*/
void initLogo() {
    logoState = 0;
    logoTimer = 0;

    // Load logo on BG1
    bgSetMapPtr(BG0, 0x0000, SC_32x32);
    bgInitTileSet(BG0, 
        &logoPic,
        &logoPalette,
        PAL1,
        (&logoPic_end - &logoPic),
        16*2,
        BG_16COLORS,
        0x3000);
    WaitForVBlank();
    dmaCopyVram((u8 *)logoTileMap, 0x0000, 1024*2);

    initBg3Black();

    WaitForVBlank();
    initLogoMusic();
    
    WaitForVBlank();
    spcPlay(0);
    spcProcess();
    WaitForVBlank();
    
    setMode(BG_MODE1, 0);
    bgSetEnable(BG0);
    bgSetDisable(BG1);
    bgSetDisable(BG2);
    bgSetDisable(BG3);
}

/*!\brief Update the logo animation.
*/
void updateLogo() {
    if (logoState == 1) {
        return;
    }

    if (logoTimer == logoTimerOffset) {
        initBackgroundPalette((u8 *)logoPalette2, PAL1);

    } else if (logoTimer == logoTimerOffset + 4) {
        initBackgroundPalette((u8 *)logoPalette3, PAL1);

    } else if (logoTimer == logoTimerOffset + 8) {
        initBackgroundPalette((u8 *)logoPalette4, PAL1);

    } else if (logoTimer == logoTimerOffset + 12) {
        initBackgroundPalette((u8 *)logoPalette5, PAL1);

    } else if (logoTimer == logoTimerOffset + 16) {
        initBackgroundPalette((u8 *)logoPalette6, PAL1);

    } else if (logoTimer == logoTimerOffset + 20) {
        initBackgroundPalette((u8 *)logoPalette1, PAL1);
        logoState = 1;
    }

    logoTimer++;
}