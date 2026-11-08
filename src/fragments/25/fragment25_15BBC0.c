#include "global.h"


#ifdef VERSION_US
/* C-owned .rodata slice [0x82104110, 0x82104130), the yaml subsegment
 * [0x15E150, .rodata, fragments/25/fragment25_15BBC0] at the end of the
 * fragment25 segment. This file provides the u16 table as the only named
 * const data; the remaining words are compiler literals that IDO emits in
 * function order -- func_82101B94's pi/2 (0x82104118) and the asm-processor
 * dummy constants at the GLOBAL_ASM pragma slots, patched with each
 * function's .late_rodata: func_82101D88's 2*pi lands at 0x8210411C
 * (D_8210411C), func_82101E70's 2*pi at 0x82104120 (D_82104120) and
 * func_82102190's 1.01 at 0x82104124 (D_82104124), matching the addresses
 * their instruction words load. IDO pads .rodata to 16-byte units, so the
 * whole slice is 0x20 bytes and the fragment25_data2 segment (still
 * asm-owned, starting at D_82104130) begins at 0x82104130. */
const u16 D_82104110[4] = {0, 1, 2, 0};

u8 *func_82101B80(u8 *arg0)
{
  return (arg0 + ((*((u32 *) (arg0 + 0x24))) * 8)) + ((0, 4));
}

/* mkdraft:func_82101B94 begin */
extern void *MainPool_AllocAligned(void *, size_t, s32);
extern void func_82102D34(f32 *);
extern f32 __sinf(f32);
extern f32 __cosf(f32);

f32 *func_82101B94(void *arg0, f32 *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    f32 *var_s1;
    f32 temp_fs0;
    s32 var_s0;

    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, 0x2C, 4);
    }
    *(f32 *)((u8 *)arg1 + 0) = arg3 + 1.570796371f;
    func_82102D34(arg1);
    *(f32 *)((u8 *)arg1 + 0x28) = arg2;
    for (var_s0 = 0, var_s1 = arg1; var_s0 != 4; var_s0++, var_s1 += 2) {
        temp_fs0 = arg3 - ((f32) (3 - var_s0) * arg4);
        *(f32 *)((u8 *)var_s1 + 4) = (f32) ((__sinf(temp_fs0) * arg7) + arg5);
        *(f32 *)((u8 *)var_s1 + 8) = (__cosf(temp_fs0) * arg7) + arg6;
    }
    *(u32 *)((u8 *)arg1 + 0x24) = 3;
    return arg1;
}
/* mkdraft:func_82101B94 end */

extern f32 __sinf(f32);
extern f32 __cosf(f32);

void func_82101CB4(f32 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    f32 *var_s1;
    f32 temp_fs0;
    s32 var_s0;

    for (var_s0 = 0, var_s1 = arg0; var_s0 != 4; var_s0++, var_s1 += 2) {
        temp_fs0 = arg5 - ((f32) (3 - var_s0) * arg4);
        *(f32 *)((u8 *)var_s1 + 4) = (f32) ((__sinf(temp_fs0) * arg3) + arg1);
        *(f32 *)((u8 *)var_s1 + 8) = (__cosf(temp_fs0) * arg3) + arg2;
    }
}
/* The anonymous 6.2831855f literal in the loop is load-bearing for .rodata:
 * as1 materializes it as the pool word D_8210411C (0x40C90FDB) at the front
 * of this function's .rodata slice, because this function precedes
 * func_82101E70 in the file. func_82101E70's own inline 6.2831855f supplies
 * the following word, so the C in this file reproduces the whole
 * [0x82104110, 0x82104120) slice without asm-processor .late_rodata dummies. */
extern void func_82101CB4(f32 *, f32, f32, f32, f32, f32);


void func_82101D88(void *arg0, f32 arg1, f32 arg2, f32 arg3) {
    u8 *var_s1;
    u8 *var_s2;
    u8 *var_s3;
    s32 var_s0;

    for (var_s0 = 0, var_s1 = arg0, var_s2 = arg0, var_s3 = arg0; var_s0 != 3;
         var_s0++, var_s1 += 0x2C, var_s2 += 4, var_s3 += 0x2C) {
        func_82101CB4((f32 *)var_s1, arg1, arg2, arg3,
                      *(f32 *)((u8 *)arg0 + 0x94),
                      ((f32)var_s0 * 6.2831855f) / 3);
        *(u8 **)(var_s2 + 0x84) = var_s3;
    }
}

/* mkdraft:func_82101E70 begin */
f32 *func_82101E70(void *arg0, f32 *arg1, f32 arg2, f32 arg3, f32 arg4,
                   f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9) {
    f32 *var_s1;
    f32 *var_s2;
    f32 *var_s3;
    s32 var_s0;

    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, 0xA0, 4);
    }
    *(f32 *)((u8 *)arg1 + 0x90) = arg3;
    *(f32 *)((u8 *)arg1 + 0x94) = arg2;
    *(f32 *)((u8 *)arg1 + 0x98) = arg5;
    *(f32 *)((u8 *)arg1 + 0x9C) = arg6;
    for (var_s0 = 0, var_s1 = arg1, var_s2 = arg1, var_s3 = arg1; var_s0 != 3;
         var_s0++, var_s1 += 11, var_s2 += 1, var_s3 += 11) {
        func_82101B94(NULL, var_s1, arg4, ((f32) var_s0 * 6.2831855f) / 3, arg2,
                      arg7, arg8, arg9);
        *(f32 **)((u8 *)var_s2 + 0x84) = var_s3;
    }
    return arg1;
}
/* mkdraft:func_82101E70 end */

/* mkdraft:func_82101FB4 begin */
extern void func_82102C54(f32 *, f32 *, u8 *);
extern f32 func_82102C98(f32 *);
// The definition in fragment25_15CBC0.c is void; the value this caller reads is
// func_821028E0's f32 return value, which that body leaves in $fv0.
//@src/fragments/25/fragment25_15CBC0.c
extern f32 func_82102D10(f32 *);
extern void func_82102B94(u8 *, f32, f32);
extern void func_82102BE8(u8 *, u8 *);



void func_82101FB4(u8 *arg0, f32 *arg1, f32 arg2) {
    f32 temp_ft5; // FAKE: unused stack slot at 0x3C; diff score 102 without it.
    f32 sp38;
    s32 sp34;
    f32 sp2C[2];

    func_82102C54(sp2C, arg1, func_82101B80(arg0));
    if (func_82102C98(sp2C) > 0.0f) {
        // FAKE: the negation sits on the loaded value and the call result is added to it.
        // Written naturally as func_82102D10(sp2C) - *(f32 *)(arg0 + 0) the same sub.s is
        // emitted, but the pointer spill lands at 0x20(sp) instead of 0x24(sp).
        sp38 = -*(f32 *)(arg0 + 0) + func_82102D10(sp2C);
        func_82102D34(&sp38);
        sp38 *= *(f32 *)(arg0 + 0x28);
        *(f32 *)(arg0 + 0) += sp38;
        func_82102D34((f32 *)arg0);
    }
    if (*(s32 *)(arg0 + 0x24) + 1 == 4) {
        sp34 = 0;
    } else {
        sp34 = *(s32 *)(arg0 + 0x24) + 1;
    }
    func_82102B94((u8 *)((u32)arg0 + sp34 * 8 + 4), arg2, *(f32 *)(arg0 + 0));
    func_82102BE8((u8 *)((u32)arg0 + sp34 * 8 + 4), func_82101B80(arg0));
    *(s32 *)(arg0 + 0x24) = sp34;
}
/* mkdraft:func_82101FB4 end */

extern f32 func_82102CE4(u8 *arg0, u8 *arg1);
u8 *func_82101B80(u8 *arg0);
extern f32 D_82103DB0;


void func_821020B0(u8 **list, u8 *state) {
    s32 index;
    s32 other;
    f32 values[3];
    f32 limit;
    u8 *ptr;
    for (index = 0; index != 3; index++) {
        ptr = func_82101B80(list[index]);
        values[index] = func_82102CE4(state, ptr);
    }
    limit = D_82103DB0;
    for (other = 0; other != 3; other++) {
        for (index = 2; index != 0; index--) {
            if (values[index - 1] > values[index] + limit) {
                f32 temporary = values[index - 1];
                ptr = list[index - 1];
                values[index - 1] = values[index];
                list[index - 1] = list[index];
                values[index] = temporary;
                list[index] = ptr;
            }
        }
    }
}

extern f32 D_82103DB4;
extern void func_82102B80(f32 *, f32, f32);
extern f32 func_82102C78(f32 *);
extern f32 func_82102D10(f32 *);
extern void func_82102D34(f32 *);
extern void func_82101FB4(u8 *, f32 *, f32);
void func_821020B0(u8 **list, u8 *state);



s32 func_82102190(u8 *arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 junk1;
    f32 target[2];
    f32 position[2];
    f32 scaled_step;
    f32 scale;
    f32 remaining;
    f32 junk4[2];
    f32 *speed_step;
    f32 target2[2];
    f32 anchor[2];
    f32 speed;
    f32 t;
    s32 done = 0;
    s32 i;
    u8 *ptr;
    u8 *object;

    func_82102B80(position, arg1, arg2);
    func_82102C54(target, func_82101B80(*(u8 **)(arg0 + 0x84)), position);
    speed = func_82102D10(target);
    remaining = *(f32 *)(*(u8 **)(arg0 + 0x84)) - speed;
    func_82102D34(&remaining);
    speed += (remaining > 0) ? *(f32 *)(arg0 + 0x94) : -*(f32 *)(arg0 + 0x94);
    i = 0;
    ptr = arg0;
    junk1 = 1.00999999f; // FAKE: dead store; keeps the load of this float literal
    for (; i != 12; i += 4, ptr += 4) {
        object = *(u8 **)(ptr + 0x84);
        func_82102B94(anchor, arg3, speed);
        func_82102BE8(anchor, position);
        func_82102C54(target2, func_82101B80(object), position);
        t = func_82102C78(target2) - arg3;
        if (*(f32 *)(arg0 + 0x9C) < t) {
            done = 1;
        }
        t = (t > 0) ? t : -t;
        scale = (*(f32 *)(arg0 + 0x98) < t) ? 1.f : t / *(f32 *)(arg0 + 0x98);
        scaled_step = (arg3 * *(f32 *)(arg0 + 0x94)) *
                   ((*(f32 *)(arg0 + 0x90) - 1.f) * scale + ((i == 0) ? 1.0f : junk1));
        func_82101FB4(object, anchor, scaled_step);
        speed_step = &D_82103DB4;
        speed += (remaining <= 0) ? (*speed_step) : (-*speed_step);
    }
    if (done) {
        func_821020B0(arg0 + 0x84, position);
    }
    return done == 0;
}

extern void func_82102444(s32, s32);
void func_821023F4(s32 arg0) {
    s32 var_s0;
    s32 var_s1;

    var_s0 = 0;
    var_s1 = arg0;
    do {
        func_82102444(var_s1, var_s0);
        var_s0 += 1;
        var_s1 += 0x2C;
    } while (var_s0 != 3);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/25/fragment25_15BBC0/func_82102444.s")
#endif
