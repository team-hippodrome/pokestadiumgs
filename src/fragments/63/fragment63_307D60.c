#include "global.h"


#ifdef VERSION_US
s32 func_87E043F0(u8 *arg0) {
    return (*(u16 *)(arg0 + 0x274) & 4) != 0;
}

s32 func_87E10E64(s32);
s32 func_87E10EA8(s32);
s32 func_87E10F2C(s32);
// 12-byte entries whose three fields are passed one each to func_87E10E64,
// func_87E10EA8 and func_87E10F2C. D_87E19A74 is a parallel table starting
// 0x30 bytes (four entries) after D_87E19A44.
typedef struct unk_func_87E04400 {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
} unk_func_87E04400;
extern unk_func_87E04400 D_87E19A44[];
extern unk_func_87E04400 D_87E19A74[];
void func_87E04400(void *arg0) {
    unk_func_87E04400 *var_v0;
    s32 temp_v1;

    if (*(u8 *)(*(u8 **)((u8 *)arg0 + 0x270) + 0x2180) == 0) {
        var_v0 = &D_87E19A44[*(s32 *)((u8 *)arg0 + 4)];
    } else {
        var_v0 = &D_87E19A74[*(s32 *)((u8 *)arg0 + 4)];
    }
    temp_v1 = *(s32 *)arg0;
    if ((temp_v1 == 2) || (temp_v1 == 3)) {
        func_87E10EA8(-1);
        func_87E10F2C(-1);
        return;
    }
    func_87E10E64(var_v0->unk_00);
    func_87E10EA8(var_v0->unk_04);
    func_87E10F2C(var_v0->unk_08);
}
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_307D60/func_87E044B8.s")

/* mkdraft:func_87E0469C begin */
extern Gfx *D_800D0510;
extern void *D_8009491C;
extern void func_8003CD84(void);
typedef struct { u8 pad_60[0x60]; u8 red; u8 green; u8 blue; } Func87E0375CColor;

void func_87E0469C(s32 arg0, s32 arg1) {
    u8 *context;
    Func87E0375CColor *temp_a0;
    void *temp_a1;
    if (arg0 == 5) {
        context = (u8 *)D_8009491C;
        temp_a0 = *(Func87E0375CColor **)(context + 0x14);
        temp_a1 = *(void **)((u8 *)temp_a0 + 0x20);
        gDPPipeSync(D_800D0510++);
        gDPSetCombine(D_800D0510++, 0x50FFFF, -0xDC8);
        gDPSetEnvColor(D_800D0510++, temp_a0->red, temp_a0->green,
                       temp_a0->blue, 0xFF);
        gSPSegment(D_800D0510++, 0xF,
                   *(void **)((u8 *)(*(void **)((u8 *)temp_a1 + 0x4)) + 8));
        gSPDisplayList(D_800D0510++, *(void **)((u8 *)temp_a1 + 8));
        func_8003CD84();
    }}
/* mkdraft:func_87E0469C end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_307D60/func_87E04790.s")

extern s32 main_pool_alloc(s32, s32);
extern void func_87F024CC(void);
extern void func_87F024F4(void *, u8 *, s32);
void func_87E049A4(void * arg0) {
    u8 *mem;
    s32 i;

    mem = (u8 *)main_pool_alloc(0x630, 0);
    for (i = 0; i < 4; i++) {
        *(u8 **)(mem + 0x20 + i * 0x18C) = (u8 *)arg0 + 0x1C + i * 0x94;
    }
    func_87F024CC();
    func_87F024F4((u8 *)arg0 + 8, mem, 4);
}

extern void func_87E04790(u8 *);
extern void func_87E134C0(void);
extern void func_87E13490(void);
extern void func_87E13480(u8 *);
void func_87E04A14(u8 *arg0) {
    switch (*(s8 *)(*(u8 **)(arg0 + 0x270) + 0x2181)) {
        case 0: *(s32 *)(arg0 + 4) = 3; break;
        case 1: *(s32 *)(arg0 + 4) = 2; break;
        case 2: *(s32 *)(arg0 + 4) = 1; break;
        case 3: *(s32 *)(arg0 + 4) = 0; break;
    }
    *(s32 *)arg0 = 0;
    func_87E04790(arg0);
    func_87E134C0();
    func_87E13490();
    func_87E13480(NULL);
}

extern void func_87F02684(s32);
void func_87E04AA4(s32 arg0) {
    func_87F02684(arg0 + 8);
}

s32 func_87E04AC4(u32 arg0) {
    u8 *entry = (u8 *)arg0 + 0x1C;
    s32 result = 1;
    s32 index;
    arg0 = 4;
    index = 0;
    do {
        index++;
        if (*(s32 *)(entry + 0x90) != 0) {
            result = 0;
            break;
        }
        entry += 0x94;
    } while (index != arg0);
    return result;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_307D60/func_87E04AFC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_307D60/func_87E04D2C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_307D60/func_87E04ED4.s")

extern void func_8004C8C0(s32);
void func_87E05128(void) {
    func_8004C8C0(426);
}

extern u8 D_87E19970[];
void func_87E05148(void *arg0) {
    s32 state;
    s32 unk;
    s32 i;
    s32 temp;
    u8 *record;

    state = MainPool_AllocState(main_pool_get_available(), 0);
    *(s32 *)((u8 *)arg0 + 0x26C) = func_80040E80(state, &D_87E19970);
    MainPool_FinalizeAllocation(state);
    unk = func_87F08E7C(100, 26, 0, 2, 0xF000000);
    record = (u8 *)arg0 + 0x1C;
    // FAKE: the store of temp into the previous record sits in the loop's
    // increment expression instead of the body.
    for (i = 0; i != 4; i++, record += 0x94, *(s32 *)(record - 0x90) = temp) {
        *(s32 *)(record + 0) = i;
        *(s32 *)(record + 8) = unk;
        temp = func_800071A4(0, 2, 100, 26, 0);
    }
}

extern void func_8005493C(void *);
extern void func_87E05128(void);
extern void func_87E05148(void *);
extern void func_87E049A4(void *);
void func_87E0520C(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0x270) = arg1;
    *(s32 *)arg0 = 0;
    func_8005493C((u8 *)arg0 + 0x274);
    func_87E05128();
    func_87E05148(arg0);
    func_87E049A4(arg0);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_307D60/func_87E05258.s")

extern void func_87E05258(void);
extern void BgStage_DrawFrame(void);
void func_87E053D0(void) {
    func_87E05258();
    BgStage_DrawFrame();
}
#pragma C_FUNCTION_PADDING(8)
#endif
