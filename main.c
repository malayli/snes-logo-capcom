/*---------------------------------------------------------------------------------


    Logo SNES Project


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

// RAM

u16 bgTileIndex;
u16 bg3TileMap[1024];

void initLogoMusic() {
    spcSetBank(&SOUNDBANK__);
    spcLoad(0);
}

/*!\brief Set all the tiles to 0, set a palette number and a tile priority.
*/
void clearBgTextEx(u16 *tileMap, u8 paletteNumber, u8 priority) {
    for (bgTileIndex=0; bgTileIndex < 1024;) {
        tileMap[bgTileIndex] = 0 | (paletteNumber<<10) | (priority<<13);
        bgTileIndex += 1;
    }
}

void initBg3Black() {
    bgSetMapPtr(BG2, 0x0000 + 2048, SC_32x32);
    bgSetGfxPtr(BG2, 0x5000);
    clearBgTextEx((u16 *)bg3TileMap, PAL0, 0);
    WaitForVBlank();
    setPaletteColor(PAL0, blackColor);
    dmaCopyVram((u8 *)bg3TileMap, 0x1000, 32*32*2);
    dmaCopyVram((u8 *)emptyPicture, 0x5000, 32);
}

int main(void) {
    // Initialize sound engine (take some time)
    spcBoot();

    // Initialize SNES
    consoleInit();

    dmaClearVram();

    // Load company fire on BG1
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
    initLogoMusic(MOD_LOGO);
    
    WaitForVBlank();
    spcPlay(0);
    
    setMode(BG_MODE1, 0);
    bgSetEnable(BG0);
    bgSetDisable(BG1);
    bgSetDisable(BG2);
    bgSetDisable(BG3);

    setFadeEffect(FADE_IN);
	WaitForVBlank();
    
    while (1) {
        // Update music / sfx stream and wait vbl
        spcProcess();

        // Wait vblank and display map on screen
        WaitForVBlank();
    }
    return 0;
}
