#include "229E0.h"

#ifdef VERSION_US

s32 D_80124D00[19];

extern u8 D_437620[];
extern u8 D_437670[];
void func_80035620(void) {
    s32 *src;
    s32 i;

    main_pool_push_state('ROMT');
    src = func_800042C0(D_437620, D_437670, 0, 0);
    for (i = 0; i < 19; i++) {
        D_80124D00[i] = src[i];
    }
    main_pool_pop_state('ROMT');
}

s32 func_800356CC(s32 arg0) { s32 result = 0; if (arg0 >= 0 && arg0 < 19) result = *((s32 *)((u8 *)D_80124D00 + arg0 * 4)); return result; }

#endif
