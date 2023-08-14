/*---------------------------------------------------------------------------------


    Capcom Logo for SNES Projects


---------------------------------------------------------------------------------*/
#include <snes.h>
#include "logo.h"

int main(void) {
    // Initialize sound engine (take some time)
    spcBoot();

    // Initialize SNES
    consoleInit();

    dmaClearVram();

    initLogo();

    setFadeEffectEx(FADE_IN, 8);
	WaitForVBlank();
    
    while (1) {
        updateLogo();

        spcProcess();

        // Wait vblank and display map on screen
        WaitForVBlank();
    }
    return 0;
}
