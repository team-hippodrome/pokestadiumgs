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

/* mkdraft:func_87E04AFC begin */
extern void func_87F0B1A4(u8 *, f32 *, f32, f32, f32, s32, s32);
extern void func_87F0B24C(u8 *, f32 *, f32, f32, f32, s32, s32);
extern void func_87F0B2F4(u8 *, s16 *, f32, f32, f32, s32, s32);
extern u32 func_8003570C(void);

// Walks the list at arg0 + 0x14. Each node carries an object at offset 0x20;
// the object's drawable at object + 0xC and the node's position floats at
// 0x48..0x50 go to func_87F0B1A4. When the object's word at offset 0 matches
// the owner's word at arg0 + 4 the drawable is placed at 0.0f/36.5f with the
// height from +0x50 (priority 10), and func_87F0B24C scales it by 2.0f in all
// three axes from the node's floats at +0x54. Otherwise the position floats
// are used raw with the second shifted by -360 degrees (priority 15), and
// func_87F0B2F4 sets the rotation from the halfword pair at +0x42 plus three
// LCG draws at func_8003570C, each scaled from [0,1) over 4294967296.0f to
// -45..45, -45..45 and -180..180 degrees.
// The same call pair over the same list shape is in func_87E01F44 and
// func_87E04D2C.
//@src/fragments/63/fragment63_305090.c


void func_87E04AFC(void *arg0) {
    f32 second_angle;
    f32 third_angle;
    u32 first_draw;
    u32 second_draw;
    u32 third_draw;
    u8 *object;
    u8 *state;
    u8 *node;

    node = *(u8 **)((u8 *)arg0 + 0x14);
    if (node != NULL) {
        do {
            object = *(u8 **)(node + 0x20);
            state = object + 0xC;
            if (*(s32 *)((u8 *)arg0 + 4) == *(s32 *)object) {
                func_87F0B1A4(state, (f32 *)(node + 0x48), 0.0f, 36.5f,
                    *(f32 *)(node + 0x50), 0xA, 0x2000);
                func_87F0B24C(state, (f32 *)(node + 0x54), 2.0f, 2.0f, 2.0f,
                    0xA, 0);
            } else {
                func_87F0B1A4(state, (f32 *)(node + 0x48), *(f32 *)(node + 0x48),
                    *(f32 *)(node + 0x4C) + -360.0f, *(f32 *)(node + 0x50), 0xF,
                    0x2000);
                first_draw = func_8003570C();
                second_draw = func_8003570C();
                third_draw = func_8003570C();
                second_angle = (f32)(u32)second_draw;
                third_angle = (f32)(u32)third_draw;
                func_87F0B2F4(state, (s16 *)(node + 0x42),
                    (((f32)first_draw / 4294967296.0f) * 90.0f) - 45.0f,
                    ((second_angle / 4294967296.0f) * 90.0f) - 45.0f,
                    ((third_angle / 4294967296.0f) * 360.0f) - 180.0f, 0xF, 0);
            }
            node = *(u8 **)(node + 4);
        } while (node != NULL);
    }
}
/* mkdraft:func_87E04AFC end */

/* mkdraft:func_87E04D2C begin */
extern void func_87F0B1A4(u8 *, f32 *, f32, f32, f32, s32, s32);
extern void func_87F0B2F4(u8 *, s16 *, f32, f32, f32, s32, s32);
extern u32 func_8003570C(void);

// Walks the node list at arg0 + 0x14. Each node's state pointer (the word at
// node + 0x20, plus 0xC) goes to func_87F0B1A4 with the node's position floats
// at 0x48..0x50, the second shifted by -360 degrees, priority 15.
// func_87F0B2F4 then receives the same state pointer with the node's halfword
// pair at 0x42 and three angles built from func_8003570C draws, each scaled
// from [0,1) over 4294967296.0f to -45..45 for the first two and -180..180 for
// the third.
// The same pair of calls runs over another node list in func_87E0AF44.
//@src/fragments/63/fragment63_30E370.c


void func_87E04D2C(void *arg0) {
    f32 second_angle;
    f32 third_angle;
    u8 *state;
    u32 first_draw;
    u32 second_draw;
    u32 third_draw;
    u8 *object;
    u8 *node;

    node = *(u8 **)((u8 *)arg0 + 0x14);
    if (node != NULL) {
        do {
            object = *(u8 **)(node + 0x20);
            state = object + 0xC;
            func_87F0B1A4(state, (f32 *)(node + 0x48), *(f32 *)(node + 0x48),
                *(f32 *)(node + 0x4C) + -360.0f, *(f32 *)(node + 0x50), 0xF, 0x2000);
            first_draw = func_8003570C();
            second_draw = func_8003570C();
            third_draw = func_8003570C();
            second_angle = (f32)(u32)second_draw;
            third_angle = (f32)(u32)third_draw;
            func_87F0B2F4(state, (s16 *)(node + 0x42),
                (((f32)first_draw / 4294967296.0f) * 90.0f) - 45.0f,
                ((second_angle / 4294967296.0f) * 90.0f) - 45.0f,
                ((third_angle / 4294967296.0f) * 360.0f) - 180.0f, 0xF, 0);
            node = *(u8 **)(node + 4);
        } while (node != NULL);
    }
}
/* mkdraft:func_87E04D2C end */

/* mkdraft:func_87E04ED4 begin */
extern void func_800226C0(s32);
extern s32 func_800279C4(s32);
extern void func_87E0168C(s32 arg0, u8 arg1, s32 arg2);
extern u8 *func_87E016C8(void);
extern void func_87E04AFC(void *arg0);
extern void func_87E04D2C(void *arg0);
extern void func_87E134E8(void);
extern s32 func_87E13688(void);
extern s32 func_87E1369C(void);
extern void func_87F0277C(void *arg0);
extern s32 func_87F0E610(u8 *arg0, u8 *arg1);
extern u8 *D_87E1EB80;



s32 func_87E04ED4(u8 *arg0) {
    s32 sp3C;
    s32 var_a0;
    // FAKE: unused local. Its 0x34 home is never read or written; it only pads
    // the frame to 0x40. Without it the frame is 0x38 (score 114), because the
    // other three locals then shift down by 8.
    s32 sp38;
    u16 sp32;

    sp3C = 5;
    D_87E1EB80 = arg0;
    sp32 = func_87F0E610(func_87E016C8(), (u8 *)-1);
    switch (*(s32 *)arg0) {
    case 0:
        if (func_87E04AC4((u32) arg0) != 0) {
            *(s32 *)arg0 = 1;
        }
        break;
    case 1:
        if (func_87E043F0(arg0) != 0) {
            var_a0 = 0;
        } else {
            var_a0 = 1;
        }
        if ((func_87E1369C() != 0) && !(sp32 & 0x8000) && !(sp32 & 0x4000)) {
            *(s32 *)(arg0 + 4) = (*(s32 *)(arg0 + 4) + ((sp32 & 0x400) > 0)) - ((sp32 & 0x800) > 0);
            if (*(s32 *)(arg0 + 4) < var_a0) {
                *(s32 *)(arg0 + 4) = 3;
            }
            if (*(s32 *)(arg0 + 4) >= 4) {
                *(s32 *)(arg0 + 4) = var_a0;
            }
            if (sp32 & 0xC00) {
                func_800279C4(0xCF01);
            }
        }
        var_a0 = sp32 & 0x4000;
        if (sp32 & 0x8000) {
            func_87E04AFC(arg0);
            *(s32 *)arg0 = 2;
            func_87E134E8();
            func_800279C4(0xCF02);
            func_87E0168C(3, 0x8CU, 9);
        }
        if ((var_a0 != 0) && (func_87E13688() != 0)) {
            func_87E04D2C(arg0);
            *(s32 *)arg0 = 3;
            func_800226C0(3);
            func_87E0168C(3, 0x8CU, 0xE);
        }
        break;
    case 2:
        if (func_87E04AC4((u32) arg0) != 0) {
            switch (*(s32 *)(arg0 + 4)) {
            case 0:
                sp3C = 0;
                *(s8 *)(*(u8 **)(arg0 + 0x270) + 0x2181) = 3;
                break;
            case 1:
                sp3C = 1;
                *(s8 *)(*(u8 **)(arg0 + 0x270) + 0x2181) = 2;
                break;
            case 2:
                sp3C = 2;
                *(s8 *)(*(u8 **)(arg0 + 0x270) + 0x2181) = 1;
                break;
            case 3:
                sp3C = 3;
                *(s8 *)(*(u8 **)(arg0 + 0x270) + 0x2181) = 0;
                break;
            }
        }
        break;
    case 3:
        if (func_87E04AC4((u32) arg0) != 0) {
            sp3C = 4;
        }
        break;
    }
    func_87F0277C(arg0 + 8);
    func_87E04400(arg0);
    return sp3C;
}
/* mkdraft:func_87E04ED4 end */

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
