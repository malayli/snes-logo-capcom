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

// ROM

// Graphics available outside the file
extern char logoPic, logoPic_end, logoPalette; // for map & tileset of map
extern char logoLayerMap, logoTilesDef, logoTilesProp;

#define blackColor RGB5(0x00, 0x00, 0x00)

extern char SOUNDBANK__;

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

// RAM

s16 mapscx; // camera x variable
u8 logoState;
u8 logoTimer;
u16 palEntryTemp;

void initLogoMusic() {
    spcSetBank(&SOUNDBANK__);
    spcLoad(0);
}

void initBackgroundPalette(u8 *source, u16 tilePaletteNumber) {
    palEntryTemp = tilePaletteNumber<<4;
    dmaCopyCGram(source, palEntryTemp, 32);
}

void updateLogo() {
    if (logoState == 1) {
        return;
    }

    if (logoTimer == 48 + 68) {
        initBackgroundPalette((u8 *)logoPalette2, PAL0);

    } else if (logoTimer == 52 + 68) {
        initBackgroundPalette((u8 *)logoPalette3, PAL0);

    } else if (logoTimer == 56 + 68) {
        initBackgroundPalette((u8 *)logoPalette4, PAL0);

    } else if (logoTimer == 60 + 68) {
        initBackgroundPalette((u8 *)logoPalette5, PAL0);

    } else if (logoTimer == 64 + 68) {
        initBackgroundPalette((u8 *)logoPalette6, PAL0);

    } else if (logoTimer == 68 + 68) {
        initBackgroundPalette((u8 *)logoPalette1, PAL0);
        logoState = 1;
    }

    logoTimer++;
}

int main(void) {
    // Initialize sound engine (take some time)
    spcBoot();

    // Initialize SNES
    consoleInit();

    logoState = 0;
    logoTimer = 0;

    // Init layer with tiles and init also map length 0x6800 is mandatory for map engine
    bgInitTileSet(BG0, 
        &logoPic, 
        &logoPalette, 
        PAL0, 
        (&logoPic_end - &logoPic), 
        16 * 2, 
        BG_16COLORS, 
        0x2000);

    bgSetMapPtr(BG0, 0x6800, SC_64x32);

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

    // Load map in memory and update it regarding current location of the sprite
    mapLoad((u8 *)&logoLayerMap, (u8 *)&logoTilesDef, (u8 *)&logoTilesProp);

    // generic playing loop
    mapscx = 16 * 8; // middle of screen
    
    while (1) {
        updateLogo();

        // Update the map regarding the camera
        mapUpdate();

        // update camera regarding scrolling
        mapUpdateCamera(mapscx, 0);
        
        // Update music / sfx stream and wait vbl
        spcProcess();

        // Wait vblank and display map on screen
        WaitForVBlank();
        mapVblank();
    }
    return 0;
}
