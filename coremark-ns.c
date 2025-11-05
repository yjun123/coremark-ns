#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <switch.h>

#include "coremark.h"

extern MAIN_RETURN_TYPE coremark_main(int argc, char *argv[]);

int main(int argc, char* argv[])
{
    consoleInit(NULL);

    padConfigureInput(1, HidNpadStyleSet_NpadStandard);

    PadState pad;
    padInitializeDefault(&pad);

    printf("CoreMark\n");
    printf("Run on Nintendo Switch Lite\n");
    printf("Running...!\n");

    consoleUpdate(NULL);

    coremark_main(argc, argv);

    while (appletMainLoop())
    {
        padUpdate(&pad);

        u64 kDown = padGetButtonsDown(&pad);

        if (kDown & HidNpadButton_Plus)
            break;

        consoleUpdate(NULL);
    }

    consoleExit(NULL);
    return 0;
}
