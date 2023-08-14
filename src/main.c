/*---------------------------------------------------------------------------------


    Logo SNES Project


---------------------------------------------------------------------------------*/
#include <snes.h>
#include "logo.h"

int main(void) {
    // Initialize sound engine (take some time)
    spcBoot();

    // Initialize SNES
    consoleInit();

    initLogo();
    
    while (1) {
        updateLogo();
        
        // Update music / sfx stream and wait vbl
        spcProcess();

        // Wait vblank and display map on screen
        WaitForVBlank();
        mapVblank();
    }
    return 0;
}
