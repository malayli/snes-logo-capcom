/*---------------------------------------------------------------------------------


    Logo SNES Project


---------------------------------------------------------------------------------*/
#include <snes.h>
#include "soundbank.h"

#define BG0 0
#define PAL0 0

// Graphics available outside the file
extern char logoPic, logoPic_end, logoPalette; // for map & tileset of map
extern char logoLayerMap, logoTilesDef, logoTilesProp;

s16 mapscx; // camera x variable

extern char SOUNDBANK__;

void initLevelMusic() {
    spcSetBank(&SOUNDBANK__);
    spcLoad(0);
}

int main(void) {
    // Initialize sound engine (take some time)
    spcBoot();

    // Initialize SNES
    consoleInit();

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
    initLevelMusic(MOD_LOGO);
    
    WaitForVBlank();
    spcPlay(0);

    // Now Put in 16 color mode and disable Bgs except current
    setMode(BG_MODE1, 0);
    bgSetDisable(1);
    bgSetDisable(2);

    // Screen activated
    setScreenOn();

    // Load map in memory and update it regarding current location of the sprite
    mapLoad((u8 *)&logoLayerMap, (u8 *)&logoTilesDef, (u8 *)&logoTilesProp);

    // generic playing loop
    mapscx = 16 * 8; // middle of screen
    
    while (1) {
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
