#include "global.h"
#include "controller.h"


#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/47/fragment47_24AE60/func_86004840.s")

void func_86004968(void *arg0) {
    typedef struct {
        u8 pad[0xAED0];
        f32 values[2][4][4];
    } Ctx;
    s32 i;
    s32 j;
    s32 k;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                ((Ctx *)arg0)->values[i][j][k] = 0.0f;
            }
        }
    }
}
typedef struct {
    u8 pad0[1];
    u8 flags;
    u8 pad2[0x166];
} Func860049B8Node;
typedef struct {
    u8 pad_0000[0x81D0];
    Func860049B8Node nodes[2][4][4];
    f32 values[2][4][4];
} Func860049B8Context;
extern void ModelAnim_SetAnimation(void *, s32);
extern void ModelAnim_SetSpeed(void *, s32);
extern void ModelAnim_SetFrame(void *, s16);
extern u8 D_8600DE30[];
void func_860049B8(Func860049B8Context *arg0, f64 arg1) {
    s32 i;
    s32 j;
    s32 k;
    s32 frame;
    Func860049B8Node *node;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            for (k = j + 1; k < 4; k++) {
                node = &arg0->nodes[i][j][k];
                if (arg0->values[i][j][k] > 0.0f) {
                    frame = 16.0 - ((f64)(arg0->values[i][j][k] * 16.0f) / *(f64 *)(D_8600DE30 + 0x2D0));
                    ModelAnim_SetAnimation(node, 0);
                    ModelAnim_SetSpeed(node, 0);
                    ModelAnim_SetFrame(node, frame);
                    node->flags |= 1;
                    arg0->values[i][j][k] -= arg1;
                } else {
                    node->flags &= ~1;
                }
            }
        }
    }
}

void func_86004BC4(void) {}
void func_86004BC4_padding(void) {}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/47/fragment47_24AE60/func_86004BD4.s")

typedef struct {
    u8 pad[0x7518];
    s32 value;
} Func86004E84State;
s32 func_86004E84(Func86004E84State *arg0) {
    s32 result;
    result = arg0->value == 2;
    if (result == 0) {
        result = arg0->value == 3;
    }
    return result;
}

extern s32 func_86009C08(void *, void *);
extern f64 func_86009C58(void *, void *);
extern f64 func_87C007DC(const f64 *, const f64 *);
f64 func_86004EA8(void *arg0, void *arg1)
{
    if (func_86009C08(((u8 *) arg0) + 0x66B8, arg1) != 0)
    {
        return func_86009C58(((u8 *) arg0) + 0x66B8, arg1);
    }
    if (func_86009C08(((u8 *) arg0) + 0x6668, arg1) != 0)
    {
        return func_86009C58(((u8 *) arg0) + 0x6668, arg1);
    }
    return func_87C007DC(((u8 *) arg0) + 0x6848, arg1);
}

extern s32 func_86009FB8(void *arg0, void *arg1, void *arg2);
typedef struct Fragment47Vec3d {
    f64 v[3];
} Fragment47Vec3d;
void func_86004F2C(void *arg0, void *arg1, Fragment47Vec3d *arg2)
{
    if (func_86009C08(((u8 *) arg0) + 0x66B8, arg1) != 0)
    {
        func_86009FB8(((u8 *) arg0) + 0x66B8, arg1, arg2);
    } else if (func_86009C08(((u8 *) arg0) + 0x6668, arg1) != 0)
    {
        func_86009FB8(((u8 *) arg0) + 0x6668, arg1, arg2);
    } else {
        *arg2 = *(Fragment47Vec3d *)((u8 *) arg0 + 0x6848);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/47/fragment47_24AE60/func_86004FDC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/47/fragment47_24AE60/func_8600520C.s")

typedef struct Func860053F8Record {
    u8 pad_0000[0x1814];
    s32 value;
    u8 pad_1818[0x180];
} Func860053F8Record;
s32 func_860053F8(Func860053F8Record *arg0) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if (arg0[i].value != arg0[i + 1].value) {
            return 0;
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/47/fragment47_24AE60/func_86005434.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/47/fragment47_24AE60/func_860057D0.s")

/* mkdraft:func_86005A00 begin */
extern f32 D_8600D8B8;
extern f32 D_8600D8BC;
extern f32 D_8600D8C0;
extern f32 D_8600D8C4;
extern f32 D_8600D8C8;
extern f32 D_8600D8CC;

// Direction deltas: 64 along an axis, 64/sqrt(2) = 45.255 diagonally.
// 0x100/0x200 select +x/-x, 0x800/0x400 select +y/-y; with no axis bit set
// the direction is (0, +-64).
//
// The value pairs are block-scoped temporaries. IDO allocates a temporary
// pair per block and reuses the lowest free pair, which reproduces the retail
// register usage: $f0/$f2 in the 0x800 cases and 0x400&0x100 ($f2 alone for
// 0x400&0x200), $f4/$f6 in the 0x800-only and 0x200-only cases, $f8/$f10 in
// 0x400-only and the first s16 conversion, $f16/$f18 in 0x100-only and the
// second conversion.


void func_86005A00(void *arg0, f32 *arg1, f32 *arg2) {
    s32 temp_v0;

    temp_v0 = *(u16 *)((u8 *)arg0 + 6);
    if (temp_v0 & 0xF00) {
        if (temp_v0 & 0x800) {
            if (temp_v0 & 0x100) {
                {
                    f32 a = D_8600D8B8;
                    *arg1 = a;
                    *arg2 = a;
                }
                return;
            }
            if (temp_v0 & 0x200) {
                // The first value loaded is the one that goes to *arg2.
                {
                    f32 a = D_8600D8BC, b = D_8600D8C0;
                    *arg1 = b;
                    *arg2 = a;
                }
                return;
            }
            {
                f32 a = 0.0f, b = 64.0f;
                *arg1 = a;
                *arg2 = b;
            }
            return;
        }
        if (temp_v0 & 0x400) {
            if (temp_v0 & 0x100) {
                {
                    f32 a = D_8600D8C4, b = D_8600D8C8;
                    *arg1 = a;
                    *arg2 = b;
                }
                return;
            }
            if (temp_v0 & 0x200) {
                {
                    f32 a = D_8600D8CC, b = D_8600D8CC;
                    *arg1 = a;
                    *arg2 = b;
                }
                return;
            }
            {
                f32 a = 0.0f, b = -64.0f;
                *arg1 = a;
                *arg2 = b;
            }
            return;
        }
        if (temp_v0 & 0x100) {
            {
                f32 a = 64.0f, b = 0.0f;
                *arg1 = a;
                *arg2 = b;
            }
            return;
        }
        if (temp_v0 & 0x200) {
            {
                f32 a = -64.0f, b = 0.0f;
                *arg1 = a;
                *arg2 = b;
            }
        }
    } else {
        *arg1 = (f32) *(s16 *)((u8 *)arg0 + 2);
        *arg2 = (f32) *(s16 *)((u8 *)arg0 + 4);
    }
}
/* mkdraft:func_86005A00 end */

/* mkdraft:func_86005B3C begin */
extern s32 func_8003F210(void *, s32);

extern s32 D_8600E0DC;
extern f64 D_8600E100;



void func_86005B3C(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3, s32 arg4) {
    u8 *base;
    u8 *node;

    if (D_8600E0DC != 0) {
        base = (u8 *) ((u32) arg0 + arg1 * 0x5A0 + arg2 * 0x168);
        node = base + 0x81D0;
        ((f32 *)(base + 0x8000))[0x7D] = (f32) *(f64 *)(arg3 + 0);
        ((f32 *)(base + 0x8000))[0x7E] = (f32) *(f64 *)(arg3 + 8);
        ((f32 *)(base + 0x8000))[0x7F] = (f32) *(f64 *)(arg3 + 0x10);
        func_8003F210(node, 0);
        node[1] |= 1;
        ((f32 *)(arg0 + arg1 * 16 + arg2 * 4 + 0x8000))[0xBB4] = (f32) D_8600E100;
        if (arg4 != 0) {
            ((f32 *)(base + 0x8000))[0x61D] = (f32) *(f64 *)(arg3 + 0);
            ((f32 *)(base + 0x8000))[0x61E] = (f32) *(f64 *)(arg3 + 8);
            ((f32 *)(base + 0x8000))[0x61F] = (f32) *(f64 *)(arg3 + 0x10);
            node = base + 0x9850;
            func_8003F210(node, 0);
            node[1] |= 1;
            ((f32 *)(arg0 + arg1 * 16 + arg2 * 4 + 0x8000))[0xBC4] = (f32) D_8600E100;
        }
    }
}
/* mkdraft:func_86005B3C end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/47/fragment47_24AE60/func_86005CB4.s")

s32 func_860062E0(s32 arg0, u16 arg1) {
    if (D_800CE060[0].buttonsPressed & arg1) {
        return 1;
    }
    return 0;
}
void func_860062E0_padding(void) {}

extern void func_86001AFC(s32);
void func_86006318(s32 arg0) {
    s32 var_s0;
    s32 var_s1;

    var_s0 = 0;
    var_s1 = arg0 + 0x75C8;
    do {
        func_86001AFC(var_s1);
        var_s0 += 0x2D8;
        var_s1 += 0x2D8;
    } while (var_s0 != 0xB60);
}

extern void func_87C037C0(void *, void *);
extern void *func_87C007B0(f32 *, void *);
extern void func_87C03B60(void *, void *, void *);
extern void func_800278C0(u16, u8, void *, f32);
void func_86006364(s32 arg0) {
    s32 i;
    u8 *obj;
    f32 pos[3];
    void *data;

    data = *(void **)(*(u8 **)((u8 *)arg0 + 0x7590) + 0xC);
    func_87C037C0((u8 *)arg0 + 0x8150, data);
    for (i = 0; i < 4; i++) {
        if (*(s32 *)((u8 *)arg0 + i * 0x2D8 + 0x775C) != 0) {
            obj = (u8 *)arg0 + i * 0x1998 + 0x1890;
            func_87C03B60((u8 *)arg0 + 0x8150, func_87C007B0(pos, (u8 *)arg0 + i * 0x2D8 + 0x7760), obj);
            func_800278C0(0x4401, i, obj, 1.25f);
        }
    }
}

extern s32 func_87F08208(void *);
extern void func_800226C0(s32);
extern s32 StageContext_GetFadeMode(void);
extern void func_860057D0(s32, f64);
extern void func_86006318(s32 arg0);
extern void func_86006364(s32);
extern void func_86007648(s32 arg0, s32 arg1);
extern u8 D_8600DE30[];
void func_86006448(s32 arg0) {
    typedef struct { unsigned int enabled : 1; unsigned int rest : 7; } Flags;
    s32 i;

    func_86006318(arg0);
    func_86006364(arg0);
    if (StageContext_GetFadeMode() == 0) {
        switch (func_87F08208((void *)(arg0 + 0x7584))) {
            case 1:
                func_86007648(arg0, 1);
                break;
            case 2:
                ((Flags *)(arg0 + 0x75C0))->enabled = 1;
                func_800226C0(3);
                break;
        }
    }
    for (i = 0; i < *(s32 *)D_8600DE30; i++) {
        func_860057D0(arg0, *(f64 *)(arg0 + 0x6890) / *(s32 *)D_8600DE30);
    }
}

extern u8 D_8600DE30[];
extern void func_86006364(s32);
extern void func_860057D0(s32, f64);
extern s32 StageContext_GetFadeMode(void);
extern void func_86007648(s32, s32);
extern void func_86006318(s32 arg0);
void func_86006538(s32 arg0) {
    s32 count;
    s32 i;

    func_86006318(arg0);
    func_86006364(arg0);
    if (StageContext_GetFadeMode() == 1) {
        func_86007648(arg0, 2);
    }
    count = *(s32 *)D_8600DE30;
    i = 0;
    if (count > 0) {
        do {
            func_860057D0(arg0, *(f64 *)((u8 *)arg0 + 0x6890) / (f64)count);
            count = *(s32 *)D_8600DE30;
            i++;
        } while (i < count);
    }
}

extern s32 func_87F01A40(s32);
s32 func_860065E8(s32 arg0) {
    typedef struct { u8 b7 : 1; u8 b6 : 1; u8 b5 : 1; u8 b4 : 1; u8 rest : 4; } StateFlags;
    switch (func_87F01A40(arg0)) {
        case 3:
            ((StateFlags *)((u8 *)arg0 + 0x75C0))->b5 = 1;
            ((StateFlags *)((u8 *)arg0 + 0x75C0))->b7 = 1;
            ((StateFlags *)((u8 *)arg0 + 0x75C0))->b4 = 1;
            return 1;
        case 4:
            ((StateFlags *)((u8 *)arg0 + 0x75C0))->b5 = 0;
            ((StateFlags *)((u8 *)arg0 + 0x75C0))->b7 = 1;
            ((StateFlags *)((u8 *)arg0 + 0x75C0))->b4 = 1;
            return 1;
    }
    //!bug: no return value when the result is neither 3 nor 4
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/47/fragment47_24AE60/func_8600666C.s")

extern void func_860076EC(s32);
extern s32 func_860065E8(s32);
extern s32 func_87F00930(void);
extern void func_87F006BC(void);
extern void func_86005434(s32);
extern void func_80028118(s32);
extern u8 D_8600DE30[];
void func_86006774(s32 arg0) {
    s32 count;
    s32 i;
    func_860076EC(arg0);
    if ((func_860065E8(arg0) == 0) && (func_87F00930() == 0)) {
        func_87F006BC();
        *(f64 *)(arg0 + 0x6888) += *(f64 *)(arg0 + 0x6890);
        for (i = 0; i < (count = *(s32 *)D_8600DE30); i++) {
            func_86005CB4(arg0, *(f64 *)(arg0 + 0x6890) / (f64)count, 1);
        }
        func_86005434(arg0);
        if ((f64)*(s32 *)(D_8600DE30 + 0x20C) - *(f64 *)(arg0 + 0x6888) < 30.0) {
            func_80028118(4);
            *(u8 *)(arg0 + 0x75C0) = (*(u8 *)(arg0 + 0x75C0) & 0xFF) | 4;
        }
    }
}

extern void func_87F0A098(void *, s32, s32, s32, s32, s32, s32);
void func_8600688C(u8 *arg0) {
    s32 flags[4];
    s32 all;
    s32 i;

    all = 1;
    for (i = 0; i < 4; i++) {
        flags[i] = (*(s32 *)(arg0 + i * 0x1998 + 0x1828) == 6) || (*(s32 *)(arg0 + i * 0x1998 + 0x1828) == 5);
        all = all && flags[i];
    }
    if (all) {
        func_87F0A098(arg0 + 0x751C, *(s32 *)(arg0 + 0x7580), 1, 0, 0, 0, 0);
    } else {
        func_87F0A098(arg0 + 0x751C, *(s32 *)(arg0 + 0x7580), 1, flags[0], flags[1], flags[2], flags[3]);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/47/fragment47_24AE60/func_86006964.s")

extern s32 func_87F02104(void);
extern void func_86007648(s32 arg0, s32 arg1);
extern u8 D_8600DE30[];
void func_86006C30(s32 arg0) {
    typedef struct { u8 b7 : 1; u8 b6 : 1; u8 b5 : 1; u8 b4 : 1; u8 rest : 4; } StateFlags;
    s32 count;
    s32 i;

    count = *(s32 *)D_8600DE30;
    i = 0;
    if (count > 0) {
        do {
            func_86005CB4(arg0, *(f64 *)((u8 *)arg0 + 0x6890) / (f64)count, 0);
            count = *(s32 *)D_8600DE30;
            i++;
        } while (i < count);
    }
    switch (func_87F02104()) {
        case 1:
            func_86007648(arg0, 6);
            break;
        case 2:
            ((StateFlags *)((u8 *)arg0 + 0x75C0))->b7 = 1;
            ((StateFlags *)((u8 *)arg0 + 0x75C0))->b5 = 1;
            break;
        case 3:
            ((StateFlags *)((u8 *)arg0 + 0x75C0))->b7 = 1;
            ((StateFlags *)((u8 *)arg0 + 0x75C0))->b5 = 0;
            break;
    }
}

extern void StageFade_StartFromOpaque(s32);
s32 StageContext_GetFadeMode();
extern void func_86007648(s32, s32);

void func_86006D24(s32 arg0) {
    if (StageContext_GetFadeMode() == 1) {
        StageFade_StartFromOpaque(0xA);
        func_86007648(arg0, 0);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/47/fragment47_24AE60/func_86006D64.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/47/fragment47_24AE60/func_86006F20.s")

extern void func_86001B1C(s32);
void func_86007300(s32 arg0) {
    s32 var_s0;
    s32 var_s1;

    var_s0 = 0;
    var_s1 = arg0 + 0x75C8;
    do {
        func_86001B1C(var_s1);
        var_s0 += 0x2D8;
        var_s1 += 0x2D8;
    } while (var_s0 != 0xB60);
}

typedef struct Func8600734CRecord {
    u8 pad000[0x198];
    f64 value198;
    u8 pad1A0[0x118];
    f64 value2B8;
    u8 pad2C0[0x10];
    s32 value2D0;
    u8 pad2D4[4];
} Func8600734CRecord;
typedef struct Func8600734CContext {
    u8 pad0000[0x75C8];
    Func8600734CRecord records[4];
} Func8600734CContext;
extern void func_86001BFC();
extern void StageContext_SetClearColor(s32);
extern void StageFade_StartFromTransparent(s32);
extern void Audio_PlayDefaultSound(s32);
void func_8600734C(s32 arg0) {
    s32 i;
    Func8600734CRecord *selected;

    selected = &((Func8600734CContext *)arg0)->records[((s32)MathUtil_Random16() % 12) / 3];
    StageContext_SetClearColor(0xFFFF);
    StageFade_StartFromTransparent(20);
    for (i = 0; i < 4; i++) {
        func_86001BFC(&((Func8600734CContext *)arg0)->records[i]);
    }
    selected->value2D0 = selected->value2B8 < selected->value198;
    func_800225C4(40);
    Audio_PlayDefaultSound(0xCF0B);
}

/* mkdraft:func_86007428 begin */
extern void func_87F00688();
extern void func_86004BD4(s32);
extern void func_86004968();
extern void func_860021C4(s32, s32, f32, void *, s32);
extern void func_86003EFC(s32, s32);
extern void func_8600062C();
extern void StageContext_SetClearColor(s32);
extern void StageFade_StartFromOpaque(s32);
extern u8 D_8600DE30[];

// Four stage slots of stride 0x1998; D_8600DE30+0x214 is the first slot that
// func_86003EFC(ptr, 7) still has to run on, and 0x6660 is 4 slots.



void func_86007428(s32 arg0) {
    s32 i;
    s32 offset;
    s32 ptr;
    void *callback;
    void *node;
    *(f64 *)(arg0 + 0x6888) = 0.0;
    *(u8 *)(arg0 + 0x75C0) &= 0xFF7F;
    *(f64 *)(arg0 + 0x6898) = 0.0;
    StageContext_SetClearColor(0xFFFF);
    StageFade_StartFromOpaque(0x14);
    func_87F00688();
    func_86004BD4(arg0);
    func_86004968(arg0);
    offset = 0;
    for (i = 0; i < 4; i++) {
        node = *(void **)(arg0 + 0x7580);
        callback = (*(u8 *)((u8 *)node + 0x2182) & (1 << i) &&
                    (*(u8 *)((u8 *)node + 0x2180) == 4) == 0) ? NULL : &func_8600062C;
        func_860021C4(arg0 + offset, i, (f32)*(f64 *)(D_8600DE30 + 0xF8), callback, arg0);
        offset += 0x1998;
    }
    i = *(s32 *)(D_8600DE30 + 0x214);
    if (i < 4) {
        offset = i * 0x1998;
        ptr = arg0 + offset;
        do {
            func_86003EFC(ptr, 7);
            offset += 0x1998;
            ptr += 0x1998;
        } while (offset != 0x6660);
    }
    *(s8 *)(arg0 + 0x75C1) = MathUtil_Random16() % 4;
    *(s32 *)(arg0 + 0xAF5C) = 0x15F90;
}
/* mkdraft:func_86007428 end */

extern void func_80021ED8(s32);
extern void func_86004968();
void func_860075A8(void *arg0) {
    func_80021ED8(0x21);
    func_86004968(arg0);
    (*(u8 *)((u8 *)(arg0) + (0x75C0))) = (u8) ((*(u8 *)((u8 *)(arg0) + (0x75C0))) & 0xFFFB);
}

extern void func_87F02328();
void func_860075E4(void *arg0) {
    (*(u8 *)((u8 *)(arg0) + (0x75C0))) = (u8) ((*(u8 *)((u8 *)(arg0) + (0x75C0))) & 0xFFF7);
    func_86004968(arg0);
    func_87F02328();
}

extern void StageContext_SetClearColor(s32); extern void StageFade_StartFromTransparent(s32);
void func_86007614(void *arg0) { StageContext_SetClearColor(1); StageFade_StartFromTransparent(0xA); }

void func_86007640(u8 *arg0) {}

extern void func_86007300(s32);
extern void func_8600734C(s32);
extern void func_86007428(s32);

void func_86007648(s32 arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x7518) = arg1;
    switch (arg1) {
        case 0:
            func_86007300(arg0);
            break;
        case 1:
            func_8600734C(arg0);
            break;
        case 2:
            func_86007428(arg0);
            break;
        case 3:
            func_860075A8((void *)arg0);
            break;
        case 4:
            func_860075E4((void *)arg0);
            break;
        case 6:
            func_86007614((void *)arg0);
            break;
        case 5:
            func_86007640((u8 *)arg0);
            break;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/47/fragment47_24AE60/func_860076EC.s")
#endif
