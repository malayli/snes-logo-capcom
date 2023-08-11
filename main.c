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

    WaitForVBlank();
    initLevelMusic(MOD_LOGO);
    
    WaitForVBlank();
    spcPlay(0);
    
    setMode(BG_MODE1, 0);
    bgSetDisable(BG0);
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
        mapVblank();
    }
    return 0;
}
