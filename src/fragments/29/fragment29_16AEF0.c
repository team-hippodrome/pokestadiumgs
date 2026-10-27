#include "global.h"
#include "controller.h"


#ifdef VERSION_US
extern s8 D_8800EF20;

void func_88004EB0(void) {
    D_8800EF20 = 10;
}

s32 func_88004EC0(void) {
    ControllerState *input = D_80087200;
    s32 buttons = input->buttonsPressed;

    if (buttons & 0x200) {
        D_8800EF20 = 10;
        return 0x200;
    }
    if (buttons & 0x100) {
        D_8800EF20 = 10;
        return 0x100;
    }
    if (buttons & 0x800) {
        D_8800EF20 = 10;
        return 0x800;
    }
    if (buttons & 0x400) {
        D_8800EF20 = 10;
        return 0x400;
    }
    D_8800EF20--;
    if (D_8800EF20 <= 0) {
        D_8800EF20 = 0;
        buttons = input->buttonsHeld;
        if (buttons & 0x200) {
            return (D_8800EF20 = 2, 0x200);
        }
        if (buttons & 0x100) {
            D_8800EF20 = 2;
            return 0x100;
        }
        if (buttons & 0x800) {
            D_8800EF20 = 2;
            return 0x800;
        }
        if (buttons & 0x400) {
            D_8800EF20 = 2;
            return 0x400;
        }
    }
    return 0;
}
#endif
