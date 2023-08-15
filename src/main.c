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

    setScreenOn();
	WaitForVBlank();
    
    while (1) {
        updateLogo();

        spcProcess();

        // Wait for vblank
        WaitForVBlank();
    }
    return 0;
}
