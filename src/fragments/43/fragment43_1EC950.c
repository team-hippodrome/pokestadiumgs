#include "global.h"


#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/43/fragment43_1EC950/func_8AC06F60.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/43/fragment43_1EC950/func_8AC07378.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/43/fragment43_1EC950/func_8AC075A8.s")

// func_8AC075A8 packs each triple into an RDP color command.
typedef struct {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
} unk_func_8AC07AF4_00C;

typedef struct {
    s16 state;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
    s16 unk_08;
    u8 unk_0A[2];
    unk_func_8AC07AF4_00C unk_0C;
    unk_func_8AC07AF4_00C unk_0F;
    u8 unk_12[2];
    s32 resource;
    u8 tail[0x180];
} Entry_8AC07A8C;
extern Entry_8AC07A8C D_8AC099D0[3];
extern s32 func_8004C990(s32, s32);

void func_8AC07A8C(void) {
    Entry_8AC07A8C *entry = D_8AC099D0;
    s32 index;

    _bzero(entry, 0x4C8);
    index = 0;
    do {
        entry->state = 0;
        entry->resource = func_8004C990(0x93, 0);
        index++;
        entry++;
    } while (index != 3);
}

extern void func_8AC06F60(Entry_8AC07A8C *);

s32 func_8AC07AF4(s32 arg0, s32 arg1, u8 *arg2, u8 *arg3) {
    Entry_8AC07A8C *var_s0 = D_8AC099D0;
    s32 var_v0;

    for (var_v0 = 0; var_v0 < 3; var_v0++, var_s0++) {
        if (var_s0->state == 0) {
            var_s0->state = 1;
            var_s0->unk_02 = 0;
            var_s0->unk_04 = arg0;
            var_s0->unk_06 = arg1;
            var_s0->unk_0C = *(unk_func_8AC07AF4_00C *)arg2;
            var_s0->unk_0F = *(unk_func_8AC07AF4_00C *)arg3;
            var_s0->unk_08 = 255;
            func_8AC06F60(var_s0);
            return 1;
        }
    }
    return 0;
}
#endif
