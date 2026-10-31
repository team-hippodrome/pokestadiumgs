#include "global.h"


#ifdef VERSION_US
extern s32 func_8004C990(s32, s32);
void func_87E01720(s32 arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4) {
    u32 index;

    index = ((u32)arg0 % ((u32)arg1 * (u32)arg2)) / (u32)arg1;
    func_8004C990(arg3, ((u8 *)arg4)[index]);
}

extern u8 D_87E19720[];
extern void func_87E01720(s32, s32, s32, s32, void *);
void func_87E01798(s32 arg0) {
    func_87E01720(arg0, 4, 4, 0x1A6, D_87E19720);
}

extern u8 D_87E19724[];
void func_87E017CC(s32 arg0) {
    func_87E01720(arg0, 3, 8, 0x1A7, D_87E19724);
}

extern u8 D_87E1972C[];
void func_87E01800(s32 arg0) {
    func_87E01720(arg0, 3, 6, 0x1A4, D_87E1972C);
}

extern u8 D_87E19734[];
void func_87E01834(s32 arg0) {
    func_87E01720(arg0, 3, 8, 0x1A5, D_87E19734);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_305090/func_87E01868.s")

/* mkdraft:func_87E01A5C begin */
extern Gfx *D_800D0510;
extern void *D_8009491C;
extern void func_8003CD84(void);
typedef struct { u8 pad_60[0x60]; u8 red; u8 green; u8 blue; } Func87E0375CColor;

void func_87E01A5C(s32 arg0, s32 arg1) {
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
                   *(void **)((u8 *)(*(void **)((u8 *)temp_a1 + 0xC)) + 8));
        gSPDisplayList(D_800D0510++, *(void **)((u8 *)temp_a1 + 8));
        func_8003CD84();
    }}
/* mkdraft:func_87E01A5C end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_305090/func_87E01B50.s")

extern s32 main_pool_alloc(s32, s32);
extern void func_87F024CC(void);
extern void func_87F024F4(void *, u8 *, s32);
void func_87E01DB4(void * arg0) {
    u8 *mem;
    s32 i;

    mem = (u8 *)main_pool_alloc(0x630, 0);
    for (i = 0; i < 4; i++) {
        *(u8 **)(mem + 0x20 + i * 0x18C) = (u8 *)arg0 + 0x1C + i * 0x98;
    }
    func_87F024CC();
    func_87F024F4((u8 *)arg0 + 8, mem, 4);
}

typedef struct { u8 pad_00[0x2180]; u8 mode; } F1E24ObjB;
typedef struct { u8 pad_00[4]; s32 value; u8 pad_08[0x278]; F1E24ObjB *obj; s8 out_284; s8 out_285; } F1E24StateB;
void func_87E01E24(F1E24StateB *arg0) {
    s32 value;
    switch (arg0->obj->mode) {
        case 0: arg0->value = 0; break;
        case 1: arg0->value = 1; break;
        case 2: arg0->value = 2; break;
        case 3: arg0->value = 3; break;
    }
    value = arg0->value;
    arg0->out_284 = value % 2;
    arg0->out_285 = value / 2;
}

extern void func_87E01E24();
extern void func_87E01B50();
extern void func_87E134C0();
extern void func_87E13490();
extern void func_87E13480();
extern void func_87E0168C();
void func_87E01EB0(void *arg0) {
    *(s32 *)arg0 = 0;
    func_87E01E24(arg0);
    func_87E01B50(arg0);
    func_87E134C0();
    func_87E13490();
    func_87E13480(1);
    func_87E0168C(3, 0x8C, 0x2D);
}

void func_87E01F04(u8 *arg0) {}

s32 func_87E01F0C(u32 arg0) {
    u8 *entry = (u8 *)arg0 + 0x1C;
    s32 result = 1;
    s32 index;
    arg0 = 4;
    index = 0;
    do {
        index++;
        if (*(s32 *)(entry + 0x94) != 0) {
            result = 0;
            break;
        }
        entry += 0x98;
    } while (index != arg0);
    return result;
}

extern void func_87F0B1A4(u8 *arg0, f32 *arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, s32 arg6);
extern void func_87F0B2F4(u8 *, u8 *, f32, f32, f32, s32, s32);
extern u32 func_8003570C(void);

// Walks the list at arg0 + 0x14. Each entry carries an object at offset
// 0x20; func_87F0B1A4 receives the object's state at object + 0x10 and the
// entry's position floats at offsets 0x48..0x50. When the entry's word at
// offset 4 matches the owner's word at arg0 + 4 (arg2..arg4 are 0.0f, 20.0f
// and the third float plus 200.0f, priority 10), the angles stay fixed;
// otherwise the same call runs with the raw floats (second shifted by
// -360.0f, priority 15) and func_87F0B2F4 randomizes the rotation from
// three LCG draws at func_8003570C, each scaled from [0,1) over
// 4294967296.0f to -45..45, -45..45 and -180..180 degrees.
void func_87E01F44(void *arg0) {
    f32 var_ft1;
    f32 var_ft2;
    u32 temp_s2;
    u32 temp_s3;
    u32 temp_v0_2;
    u8 *temp_s1;
    u8 *temp_v0;
    u8 *var_s0;

    var_s0 = *(u8 **)((u8 *)arg0 + 0x14);
    if (var_s0 != NULL) {
        do {
            temp_v0 = *(u8 **)(var_s0 + 0x20);
            temp_s1 = temp_v0 + 0x10;
            if (*(s32 *)((u8 *)arg0 + 4) == *(s32 *)(temp_v0 + 4)) {
                func_87F0B1A4(temp_v0 + 0x10, var_s0 + 0x48, 0.0f, 20.0f,
                    *(f32 *)(var_s0 + 0x50) + 200.0f, 0xA, 0x2000);
            } else {
                func_87F0B1A4(temp_s1, var_s0 + 0x48, *(f32 *)(var_s0 + 0x48),
                    *(f32 *)(var_s0 + 0x4C) + -360.0f, *(f32 *)(var_s0 + 0x50), 0xF, 0x2000);
                temp_s2 = func_8003570C();
                temp_s3 = func_8003570C();
                temp_v0_2 = func_8003570C();
                var_ft2 = (f32)(u32)temp_s3;
                var_ft1 = (f32)(u32)temp_v0_2;
                func_87F0B2F4(temp_s1, var_s0 + 0x42, (((f32)temp_s2 / 4294967296.0f) * 90.0f) - 45.0f,
                    ((var_ft2 / 4294967296.0f) * 90.0f) - 45.0f,
                    ((var_ft1 / 4294967296.0f) * 360.0f) - 180.0f, 0xF, 0);
            }
            var_s0 = *(u8 **)(var_s0 + 4);
        } while (var_s0 != NULL);
    }
}

extern u8 D_87E1979C[];
extern void func_87E10E64(s32);
extern void func_87E10EA8(s32);
extern void func_87E10F2C(s32);
void func_87E02150(s32 *arg0) {
    s32 *entry = (s32 *)(D_87E1979C + arg0[1] * 0xC);

    if (arg0[0] == 2) {
        func_87E10EA8(-1);
        func_87E10F2C(-1);
    } else {
        func_87E10E64(entry[0]);
        func_87E10EA8(entry[1]);
        func_87E10F2C(entry[2]);
    }
}

/* mkdraft:func_87E021CC begin */
extern void func_800226C0(s32);
extern s32 func_800279C4(s32);
extern u8 *func_87E016C8(void);
extern void func_87E0168C(s32, s32, s32);
extern s32 func_87E01F0C(u32);
extern void func_87E01F44(void *);
extern void func_87E02150(s32 *);
extern void func_87E134E8(void);
extern s32 func_87E13688(void);
extern s32 func_87E1369C(void);
extern void func_87F0277C(void *);
extern s32 func_87F0E610(u8 *, u8 *);

extern u32 D_87E1EB50;



s32 func_87E021CC(u32 arg0) {
    u32 sp34;
    s32 sp30;
    u16 temp_a1;

    sp34 = 5;
    sp30 = func_87E01F0C(arg0);
    D_87E1EB50 = arg0;
    temp_a1 = func_87F0E610(func_87E016C8(), (u8 *)-1);
    switch (*(s32 *)((u8 *)arg0 + 0)) {
    case 0:
        if (sp30 != 0) {
            *(s32 *)((u8 *)arg0 + 0) = 1;
        }
        break;
    case 1:
        if ((func_87E1369C() != 0) && !(temp_a1 & 0x8000) && !(temp_a1 & 0x4000)) {
            *(s8 *)((u8 *)arg0 + 0x284) = (s8) ((*(s8 *)((u8 *)arg0 + 0x284) + ((temp_a1 & 0x400) > 0)) - ((temp_a1 & 0x800) > 0));
            *(s8 *)((u8 *)arg0 + 0x285) = (s8) ((*(s8 *)((u8 *)arg0 + 0x285) + ((temp_a1 & 0x100) > 0)) - ((temp_a1 & 0x200) > 0));
            if (*(s8 *)((u8 *)arg0 + 0x284) < 0) {
                *(s8 *)((u8 *)arg0 + 0x284) = 1;
            }
            if (*(s8 *)((u8 *)arg0 + 0x284) >= 2) {
                *(s8 *)((u8 *)arg0 + 0x284) = 0;
            }
            if (*(s8 *)((u8 *)arg0 + 0x285) < 0) {
                *(s8 *)((u8 *)arg0 + 0x285) = 1;
            }
            if (*(s8 *)((u8 *)arg0 + 0x285) >= 2) {
                *(s8 *)((u8 *)arg0 + 0x285) = 0;
            }
            *(s32 *)((u8 *)arg0 + 4) = (s32) ((*(s8 *)((u8 *)arg0 + 0x285) * 2) + *(s8 *)((u8 *)arg0 + 0x284));
            if (temp_a1 & 0xF00) {
                func_800279C4(0xCF01);
            }
        }
        if (temp_a1 & 0x8000) {
            func_87E01F44(arg0);
            *(s32 *)((u8 *)arg0 + 0) = 2;
            func_87E134E8();
            func_800279C4(0xCF02);
            func_87E0168C(3, 0x8C, 0xE);
        }
        if ((temp_a1 & 0x4000) && (func_87E13688() != 0)) {
            sp34 = 4;
            func_800226C0(3);
        }
        break;
    case 2:
        if (sp30 != 0) {
            switch (*(s32 *)((u8 *)arg0 + 4)) {
            case 0:
                *(u8 *)((u8 *)(*(void **)((u8 *)arg0 + 0x280)) + 0x2180) = 0;
                sp34 = 0;
                break;
            case 1:
                *(u8 *)((u8 *)(*(void **)((u8 *)arg0 + 0x280)) + 0x2180) = 1;
                sp34 = 1;
                break;
            case 2:
                *(u8 *)((u8 *)(*(void **)((u8 *)arg0 + 0x280)) + 0x2180) = 2;
                sp34 = 2;
                break;
            case 3:
                *(u8 *)((u8 *)(*(void **)((u8 *)arg0 + 0x280)) + 0x2180) = 3;
                sp34 = 3;
                break;
            }
        }
        break;
    }
    func_87F0277C(arg0 + 8);
    if (sp30 != 0) {
        func_87E02150((s32 *) arg0);
    }
    return sp34;
}
/* mkdraft:func_87E021CC end */

extern void func_8004C8C0(s32);
void func_87E02438(void) {
    func_8004C8C0(0x1A4);
    func_8004C8C0(0x1A5);
    func_8004C8C0(0x1A6);
    func_8004C8C0(0x1A7);
}

extern s32 main_pool_get_available(void);
extern s32 MainPool_AllocState(s32, s32);
extern void MainPool_FinalizeAllocation(s32);
extern s32 func_80040E80(s32, void *);
extern u8 D_87E197CC;
extern s32 func_87F08E7C(u16, u16, u8, u8, s32);
extern s32 func_800071A4(s32, s32, s32, s32, s32);

void func_87E02470(u8 *arg0) {
    s32 state;
    s32 unk;
    s32 i;
    s32 temp;
    u8 *record;

    state = MainPool_AllocState(main_pool_get_available(), 0);
    *(s32 *)((u8 *)arg0 + 0x27C) = func_80040E80(state, &D_87E197CC);
    MainPool_FinalizeAllocation(state);
    unk = func_87F08E7C(124, 51, 0, 2, 0xF000000);
    record = (u8 *)arg0 + 0x1C;
    // FAKE: the store of temp into the previous record sits in the loop's
    // increment expression instead of the body.
    for (i = 0; i != 4; i++, record += 0x98, *(s32 *)(record - 0x8C) = temp) {
        *(s32 *)(record + 0) = 0;
        *(s32 *)(record + 4) = i;
        *(s32 *)(record + 8) = unk;
        temp = func_800071A4(0, 2, 124, 51, 0);
    }
}
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_305090/func_87E02538.s")

extern void func_87E02538(void);
extern void BgStage_DrawFrame(void);
void func_87E0276C(void) {
    func_87E02538();
    BgStage_DrawFrame();
}

extern void func_87E02438();
extern void func_87E02470();
extern void func_87E01DB4();
void func_87E02794(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0x280) = arg1;
    *(s32 *)arg0 = 0;
    func_87E01E24(arg0);
    func_87E02438();
    func_87E02470(arg0);
    func_87E01DB4(arg0);
}
#endif
