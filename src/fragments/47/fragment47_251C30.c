#include "global.h"


#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/47/fragment47_251C30/func_8600B610.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/47/fragment47_251C30/func_8600BA50.s")

#include "color_adjustment.h"
extern s32 main_pool_get_available(void);
extern u8 *MainPool_AllocState(s32, s32);
extern void MainPool_FinalizeAllocation(void *);
extern s32 func_8004DDF4(s32);
extern void *func_8004DFEC(s32, s32, ColorAdjustment);
extern ColorAdjustment func_87F0AD50(s32, s32, s32);
void func_8600CD10(void **arg0, s32 arg1) {
    u8 *pool;
    s32 i;

    for (i = 0; i < 4; i++) {
        func_8004DDF4(0x73);
        pool = MainPool_AllocState(main_pool_get_available(), 0);
        arg0[i] = func_8004DFEC((s32)pool, 0x73, func_87F0AD50(arg1, 1, i));
        MainPool_FinalizeAllocation(pool);
    }
}
#endif
