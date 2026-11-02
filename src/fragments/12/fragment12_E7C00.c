#include "global.h"

typedef struct Fragment12Row {
    /* 0x000 */ f32 values[0x80];
    /* 0x200 */ f32 unk_200;
    /* 0x204 */ f32 unk_204;
    /* 0x208 */ s16 unk_208;
    /* 0x20A */ u8 unk_20A;
    /* 0x20B */ u8 unk_20B;
    /* 0x20C */ s32 unk_20C;
} Fragment12Row; // size = 0x210

typedef struct Fragment12Rows {
    /* 0x000 */ Fragment12Row rows[6];
    /* 0xC60 */ u8 unk_C60[0x4C];
    /* 0xCAC */ f32 unk_CAC;
    /* 0xCB0 */ s8 unk_CB0;
} Fragment12Rows;


// This file's .rodata tables, in retail order (D_81407954 is an alias for D_81407950[1]).
const s32 D_81407950[6] = { 0, 220, 497, 480, 230, -17 };
const s16 D_81407968[2][5][4][2] = { 339, 31, 339, 31, 43, 301, 43, 301, 339, 110, 339, 110, 82, 240, 82, 240, 339, 110, 339, 110, 130, 254, 130, 254, 339, 31, 339, 31, 43, 301, 43, 301, 339, 110, 339, 110, 82, 240, 82, 240, 82, 67, 339, 67, 43, 265, 300, 265, 82, 67, 339, 67, 43, 265, 300, 265, 125, 83, 382, 83, 86, 281, 343, 281, 82, 67, 339, 67, 43, 265, 300, 265, 82, 67, 339, 67, 43, 265, 300, 265 };
const s16 D_81407A08[5][2] = { 261, 121, 222, 103, 174, 89, 261, 121, 222, 103 };
const s16 D_81407A1C[4][2] = { 339, 31, 339, 31, 221, 339, 221, 339 };
const s16 D_81407A2C[4][2] = { 418, 31, 418, 31, 98, 371, 98, 371 };
const s16 D_81407A3C[16] = { 82, -193, 640, 31, -261, 229, 300, 480, 640, 31, 640, 31, -261, 229, -261, 229 };
const s16 D_81407A5C[8] = { 82, 31, 339, 31, 43, 229, 300, 229 };
// Label-draw format strings that func_814057CC passes to func_800495BC/func_800495F8. Its
// nonmatchings .s carried these bytes in its .rodata section; the definitions keep the
// object's .rodata byte-identical now that the function is C.
const char D_81407A6C[4] = "%d";
const char D_81407A70[4] = "%d";
const char D_81407A74[4] = "%d";
const char D_81407A78[4] = "%d";
const char D_81407A7C[4] = "%d";
const char D_81407A80[4] = "%d";
const char D_81407A84[4] = "%d";
const char D_81407A88[8] = "%s%d";

#ifdef VERSION_US
f32 MathUtil_Random_ZeroOne();

s32 func_814028F0(void) {
    return (s32) ((MathUtil_Random_ZeroOne() * 15.0f) + 6.0f);
}

void func_81402930(void *arg0, f32 arg1, s32 arg2, s32 arg3) { s32 limit=0x80; s32 i=0; u8 *ptr=arg0; loop: i+=4; *(f32 *)(ptr+4)=arg1; *(f32 *)(ptr+8)=arg1; *(f32 *)(ptr+0xC)=arg1; ptr+=0x10; *(f32 *)(ptr-0x10)=arg1; if(i!=limit) goto loop; *(s16 *)((u8 *)arg0+0x208)=arg2; *(s32 *)((u8 *)arg0+0x20C)=0; *(u8 *)((u8 *)arg0+0x20B)=arg3; *(f32 *)((u8 *)arg0+0x200)=0.0f; *(f32 *)((u8 *)arg0+0x204)=0.0f; }

void func_81402978(void *arg0, f32 arg1, s32 arg2) {
    *(s16 *)((u8 *)arg0 + 8) = arg2;
    *(f32 *)arg0 = arg1;

    if (arg2 >= 0) {
        *(f32 *)((u8 *)arg0 + 4) = 400.0f;
    } else {
        *(f32 *)((u8 *)arg0 + 4) = 0.0f;
    }
}

void func_814029AC(void *arg0, f32 arg1) {
    f32 temp_fs0;
    s32 var_s0;
    u8 *var_s1;
    u8 *var_s2;

    *(s8 *)((u8 *)arg0 + 0xCB0) = 0;
    var_s0 = 0;
    var_s1 = arg0;
    var_s2 = (u8 *)arg0 + 0xC60;
    *(f32 *)((u8 *)arg0 + 0xCAC) = arg1;
    *(f32 *)((u8 *)arg0 + 0xCA8) = 0.0f;
    do {
        temp_fs0 = arg1 + 180.0f + (f32)var_s0;
        func_81402930(var_s1, temp_fs0, -1, 0);
        func_81402978(var_s2, temp_fs0, -1);
        var_s0 += 22;
        var_s1 += 528;
        var_s2 += 12;
    } while (var_s0 != 132);
}
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/12/fragment12_E7C00/func_81402A64.s")

void func_81402CD8(void *arg0, f32 arg1) {
    arg1 *= 100.0f;
    if (*(f32 *)((u8 *)arg0 + 0xCA8) < arg1)
        *(f32 *)((u8 *)arg0 + 0xCA8) = arg1;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/12/fragment12_E7C00/func_81402D08.s")

extern void func_81402930(void *arg0, f32 arg1, s32 arg2, s32 arg3);
void func_81403244(Fragment12Rows *arg0, s32 arg1, s32 arg2) {
    f32 max;
    s32 i;

    max = arg0->unk_CAC + 180.0f;
    for (i = 0; i < 6; i++) {
        if (max < arg0->rows[i].values[arg0->unk_CB0]) {
            max = arg0->rows[i].values[arg0->unk_CB0];
        }
    }
    for (i = 0; i < 6; i++) {
        if (arg0->rows[i].unk_208 < 0) {
            func_81402930(&arg0->rows[i], max + 22.0f + 1.0f, arg1, arg2);
            return;
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/12/fragment12_E7C00/func_81403304.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/12/fragment12_E7C00/func_81403400.s")

s32 func_81403710(void *arg0) {
    s8 *entry;
    u8 result = 0;
    s32 bit;
    s32 i;
    for (i = 0; i < 2; i++) {
        entry = ((s8 **)arg0)[i];
        if (entry) {
            bit = entry[8];
            if (bit >= 0) {
                result |= 1 << bit;
            }
        }
    }
    return result;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/12/fragment12_E7C00/func_81403758.s")

s16 func_81403758();
void func_81403828(void *arg0, void *arg1) {
    s16 temp_v0;

    temp_v0 = func_81403758();
    (*(s16 *)((u8 *)(arg1) + (4))) = 0x20;
    if ((*(s32 *)((u8 *)(arg0) + (0xCC4))) != 0) {
        (*(s16 *)((u8 *)(arg1) + (0))) = 0x233;
        (*(s16 *)((u8 *)(arg1) + (2))) = temp_v0;
        (*(s16 *)((u8 *)(arg1) + (6))) = (s16) (0x1E0 - temp_v0);
        return;
    }
    (*(s16 *)((u8 *)(arg1) + (0))) = 0x2F;
    (*(s16 *)((u8 *)(arg1) + (2))) = 0;
    (*(s16 *)((u8 *)(arg1) + (6))) = temp_v0;
}

extern void func_814029AC(void *, f32);
void func_81403894(void *arg0, s32 arg1) {
    void *temp_a0;
    *(s32 *)((u8 *)arg0 + 0xCC4) = arg1;
    *(u8 *)((u8 *)arg0 + 0xCC0) = 0;
    *(s32 *)((u8 *)arg0 + 0) = 0;
    *(s32 *)((u8 *)arg0 + 4) = 0;
    *(u8 *)((u8 *)arg0 + 0xCC2) = 0;
    temp_a0 = (u8 *)arg0 + 8;
    *(f32 *)((u8 *)temp_a0 + 0xCB4) = 0.0f;
    func_814029AC(temp_a0, 22.0f);
}

void func_814038D4(void *arg0, void *arg1) {
    s32 i;
    void **items = (void **)arg0;

    for (i = 0; i != 2; i++) {
        if (items[i] == 0) {
            items[i] = arg1;
            *(u8 *)((u8 *)arg0 + 0xCC2) += *(s8 *)((u8 *)arg1 + 0x12);
            return;
        }
    }
}

extern void func_81403244(Fragment12Rows *, s32, s32);
void func_81403918(s32 arg0, s32 arg1, s32 arg2) {
    func_81403244((Fragment12Rows *)(arg0 + 8), arg1, arg2);
}

extern s32 func_81403304(s32);
s32 func_81403938(s32 arg0)
{
    f64 alignmentPad;
    s32 found = 0;
    s32 offset = 0;
    u8 *scan = (u8 *) arg0;
    s8 **slot;
    s32 j;
    s32 slotOffset;
    if (!scan)
    {
    }
    j = 0xC60;
    do
    {
        offset += 0x210;
        if ((*((s16 *) (scan + 0x210))) >= 0)
        {
            found = 1;
            break;
        }
        scan += 0x210;
    }
    while (offset != j);
    func_81403304(arg0 + 8);
    slotOffset = 0;
    slot = (s8 **) arg0;
    do
    {
        slotOffset += 4;
        if ((*slot) != 0)
        {
            for (j = 0; j < 6; j++)
            {
                (*slot)[0xA + j] = -1;
            }
        }
        slot++;
    }
    while (slotOffset != 8);
    if (found)
    {
        func_80023110(1, *((s32 *) (arg0 + 0xCC4)), 0);
    }
}

void func_81403A18(void *arg0) {
    u8 temp_v0;

    temp_v0 = (*(u8 *)((u8 *)(arg0) + (0xCC0)));
    switch (temp_v0) {                              /* irregular */
    case 0:
        (*(f32 *)((u8 *)(arg0) + (0xCBC))) = 0.0f;
        /* fallthrough */
    case 1:
    case 3:
        (*(u8 *)((u8 *)(arg0) + (0xCC0))) = 1U;
        /* fallthrough */
    case 2:
        return;
    }
}

s32 func_81403A64(u8 *arg0) {
    *(f32 *)(arg0 + 0xCBC) = 0.0f;
    return 0;
}

extern void func_81402D08(void *arg0);
f32 func_816092FC(void);
s32 func_81403A74(void *arg0) {
    void *p = arg0;
    f32 delta;
    func_81402D08((u8 *)p + 8);
    delta = func_816092FC();
    *(f32 *)((u8 *)p + 0xCBC) += delta;
    if (*(f32 *)((u8 *)p + 0xCBC) >= 16.0f) {
        *(f32 *)((u8 *)p + 0xCBC) = 16.0f;
        *(u8 *)((u8 *)p + 0xCC0) = 2;
    }
    return 1;
}

extern void func_81402D08(void *);
s32 func_81403AE0(void *arg0) {
    func_81402D08((u8 *)arg0 + 8);
    *(f32 *)((u8 *)arg0 + 0xCBC) = 16.0f;
    return 1;
}

s32 func_81403B18(void *arg0) {
    u8 *p = (u8 *)arg0;
    func_81402D08(p + 8);
    *(f32 *)(p + 0xCBC) = *(f32 *)(p + 0xCBC) - func_816092FC();
    if (*(f32 *)(p + 0xCBC) <= 0.0f) {
        *(f32 *)(p + 0xCBC) = 0.0f;
        *(u8 *)(p + 0xCC0) = 0;
    }
    return 1;
}

extern void func_81403828(void *arg0, void *arg1);
extern s32 func_81403A64(u8 *arg0);
extern s32 func_81403A74(void *arg0);
extern s32 func_81403AE0(void *arg0);
extern s32 func_81403B18(void *arg0);
extern void func_81600A34(void *arg0, void *arg1, void *arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void func_81403B7C(u8 *arg0, void *arg1)
{
    s16 out[4];
    void *result;
    f32 value;
    *((f32 *) (arg0 + 0xCB0)) = 0.0f;
    switch (arg0[0xCC0]) {
        case 0: result = (void *) func_81403A64(arg0); break;
        case 3: result = (void *) func_81403B18(arg0); break;
        case 1: result = (void *) func_81403A74(arg0); break;
        case 2: result = (void *) func_81403AE0(arg0); break;
    }
    ;
    if ((*((f32 *) (arg0 + 0xCB0))) > 410.0f) {
        func_80023110(0, *((s32 *) (arg0 + 0xCC4)), 0);
    } else if ((*((f32 *) (arg0 + 0xCB0))) > 150.0f) {
        func_80023110(0, *((s32 *) (arg0 + 0xCC4)), 1);
    } else if ((*((f32 *) (arg0 + 0xCB0))) > 20.0f) {
        func_80023110(0, *((s32 *) (arg0 + 0xCC4)), 2);
    }
    func_81403828(arg0, out);
    func_81600A34(arg1, arg0, result, out[0], out[1], out[2], out[3]);
}

extern s32 func_81600DA8(void *, void *);
extern s32 func_81602D70(s32);
extern void Gfx_SetScissorRect(Gfx **, s32, s32, s32, s32);
extern void func_81607360(void *);
extern void func_81607408(void);
extern void Fragment12_DrawUpperAnimatedPanel(s32, s32, u8, u8 *, u8 *, s32);
extern void Fragment12_DrawLowerAnimatedPanel(s32, s32, u8, u8 *, u8 *, s32);
extern void func_81403400(void *, s32, s32, s32);
extern Gfx *D_800D0510;
extern s32 func_81403710(void *arg0);
extern s16 func_81403758();
extern void func_81403828(void *arg0, void *arg1);
void func_81403CD0(void *arg0, void *arg1) {
    u8 bits;
    s32 value;
    s32 second;
    s16 rect[4];
    s32 first;
    u8 *entry;
    if (func_81600DA8(arg1, arg0) != 0) {
        bits = func_81403710(arg0);
        entry = *(u8 **)arg0;
        if (entry != 0) {
            value = func_81602D70(entry[7]);
        } else {
            value = func_81602D70(entry[7]);
        }
        first = value;
        entry = *(u8 **)((u8 *)arg0 + 4);
        if (entry != 0) {
            second = func_81602D70(entry[7]);
        } else {
            second = value;
        }
        Gfx_SetScissorRect(&D_800D0510, 0, 0, 0x280, 0x1E0);
        func_81403828(arg0, rect);
        func_81607360(rect);
        if (*(s32 *)((u8 *)arg0 + 0xCC4) != 0) {
            Fragment12_DrawLowerAnimatedPanel(rect[0], rect[1], bits, (u8 *)first, (u8 *)second, *(u8 *)((u8 *)arg0 + 0xCC2));
        } else {
            Fragment12_DrawUpperAnimatedPanel(rect[0], rect[3] + rect[1], bits, (u8 *)first, (u8 *)second, *(u8 *)((u8 *)arg0 + 0xCC2));
        }
        func_81403400((u8 *)arg0 + 8, rect[2] / 2 + rect[0], func_81403758(arg0), *(s32 *)((u8 *)arg0 + 0xCC4));
        func_81607408();
    }
}

void func_81403E2C(void *arg0) {
    u8 temp_v0;

    temp_v0 = (*(u8 *)((u8 *)(arg0) + (0xCC0)));
    switch (temp_v0) {                              /* irregular */
    case 2:
        (*(f32 *)((u8 *)(arg0) + (0xCBC))) = 16.0f;
        /* fallthrough */
    case 1:
    case 3:
        (*(u8 *)((u8 *)(arg0) + (0xCC0))) = 3U;
        /* fallthrough */
    case 0:
        return;
    }
}

void func_81403E7C(void *arg0, s16 *arg1) {
    typedef struct { s16 width; s16 height; } Extent;
    s32 mode;
    f32 scale;
    f32 inv;
    f32 divisor = 16.0f;
    s16 *p;
    Extent *q;

    mode = *(s32 *)((u8 *)arg0 + 0x14) ? 1 : 0;
    scale = *(f32 *)((u8 *)arg0 + 4) / divisor;
    p = D_81407968[mode][*(s8 *)((u8 *)arg0 + 0xE)][*(u8 *)((u8 *)arg0 + 0xD)];
    q = (Extent *)D_81407A08[*(s8 *)((u8 *)arg0 + 0xE)];
    inv = 1.0f - scale;
    arg1[0] = p[0] + q->width * 0.5f * inv;
    arg1[1] = p[1] + q->height * 0.5f * inv;
    arg1[2] = q->width * scale;
    arg1[3] = q->height * scale;
}

extern u8 D_800CE060;

void *func_81403FAC(void *arg0) {
    s8 temp_v1;

    temp_v1 = (*(s8 *)((u8 *)(arg0) + (0xF)));
    if (temp_v1 >= 0) {
        return (temp_v1 * 0x28) + &D_800CE060;
    }
    return NULL;
}

void func_81403FDC(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    *(u8 *)((u8 *)arg0 + 0xF) = arg1;
    *(s8 *)((u8 *)arg0 + 0xE) = -1;
    *(s32 *)((u8 *)arg0 + 0x14) = arg3;
    *(u8 *)((u8 *)arg0 + 0xD) = arg2;
    *(u8 *)((u8 *)arg0 + 0xC) = 0;
    *(f32 *)((u8 *)arg0 + 4) = 0.0f;
    *(u8 *)((u8 *)arg0 + 0x11) = func_814028F0();
    *(s32 *)((u8 *)arg0 + 0) = 0;
    *(f32 *)((u8 *)arg0 + 8) = 0.0f;
}

s32 func_81404030(u8 *arg0) {
    *(f32 *)(arg0 + 4) = 0.0f;
    return 0;
}

extern f32 func_816092FC(void);
extern void func_800226C0(s32 arg0);
s32 func_81404040(void *arg0) {
    *(f32 *)((u8 *)arg0 + 4) += func_816092FC();
    if (16.0f <= *(f32 *)((u8 *)arg0 + 4)) {
        switch (*(u8 *)((u8 *)arg0 + 0xE)) {
        case 3:
        case 4:
            func_800226C0(5);
            break;
        case 0:
        case 1:
        case 2:
            break;
        }
        *(u8 *)((u8 *)arg0 + 0xC) = 2;
        *(f32 *)((u8 *)arg0 + 4) = 16.0f;
    }
    return 1;
}

/* mkdraft:func_814040D8 begin */
// Flags for this frame come from the u16 at +8 of func_81403FAC(arg0)'s record.
// When that call returns null, the countdown byte at 0x11 drops by
// func_816092FC() per frame and, at 0, is refilled by func_814028F0() (a random
// 6..21) while the flags become 0x8000. Bit 0x800 clears the 0x10 latch and bit
// 0x400 sets it, each calling func_800226C0(1) only when the latch sits on the
// other side. 0x8000 and 0x4000 store 3 into the 0xC state, call func_800226C0
// with a sub-state-dependent id (0xA1/0xA2 from the 0x10 latch for cases 0-2,
// else 2) and re-read the 0xE sub-state, which the return value compares to 2.



s32 func_814040D8(void *arg0) {
    u16 var_a2 = 0;
    void *temp_v0;
    s32 var_v0;
    s8 var_v1;

    temp_v0 = func_81403FAC(arg0);
    if (temp_v0 != 0) {
        var_a2 = *(u16 *)((u8 *)temp_v0 + 8);
    } else {
        *(s8 *)((u8 *)arg0 + 0x11) = (s8)(s32)((f32)(*(s8 *)((u8 *)arg0 + 0x11)) - func_816092FC());
        if (*(s8 *)((u8 *)arg0 + 0x11) <= 0) {
            *(u8 *)((u8 *)arg0 + 0x11) = func_814028F0();
            var_a2 = 0x8000;
        }
    }
    var_v1 = *(s8 *)((u8 *)arg0 + 0xE);
    *(f32 *)((u8 *)arg0 + 4) = 16.0f;
    if (var_v1 == 0 || var_v1 == 1) {
        var_v0 = var_a2;
        if (var_a2 & 0x800) {
            if (*(s8 *)((u8 *)arg0 + 0x10) > 0) {
                func_800226C0(1);
                *(u8 *)((u8 *)arg0 + 0x10) = 0;
                // FAKE: u8 lvalue for a signed field. With (s8 *) here the reload
                // is cloned into the 0x8000 arm too, so the compiler emits a
                // second lb of 0xE instead of the single shared lb after the
                // join: differ 280, versus 0 with this spelling. The byte holds
                // the small sub-state tested by the switches below, so the
                // zero-extending load yields the same value.
                var_v1 = *(u8 *)((u8 *)arg0 + 0xE);
            }
        } else if ((var_v0 & 0x400) && *(s8 *)((u8 *)arg0 + 0x10) <= 0) {
            func_800226C0(1);
            *(u8 *)((u8 *)arg0 + 0x10) = 1;
            var_v1 = *(s8 *)((u8 *)arg0 + 0xE);
        }
        if (var_v0 & 0x8000) {
            switch (var_v1) {
            case 0:
            case 1:
            case 2:
                func_800226C0(*(s8 *)((u8 *)arg0 + 0x10) == 0 ? 0xA1 : 0xA2);
                break;
            case 3:
            case 4:
                func_800226C0(2);
                break;
            }
            *(u8 *)((u8 *)arg0 + 0xC) = 3;
            var_v1 = *(s8 *)((u8 *)arg0 + 0xE);
        } else if (var_v0 & 0x4000) {
            *(s8 *)((u8 *)arg0 + 0x10) = -2;
            switch (var_v1) {
            case 0:
            case 1:
                func_800226C0(0xA2);
                *(u8 *)((u8 *)arg0 + 0x10) = 1;
                break;
            case 2:
                func_800226C0(0xA2);
                break;
            case 3:
            case 4:
                func_800226C0(2);
                break;
            }
            *(u8 *)((u8 *)arg0 + 0xC) = 3;
            var_v1 = *(s8 *)((u8 *)arg0 + 0xE);
            *(f32 *)((u8 *)arg0 + 4) = 16.0f;
        }
    } else if (var_a2 & 0x4000) {
        func_800226C0(0xA2);
        *(s8 *)((u8 *)arg0 + 0x10) = -2;
        *(u8 *)((u8 *)arg0 + 0xC) = 3;
        var_v1 = *(s8 *)((u8 *)arg0 + 0xE);
        *(f32 *)((u8 *)arg0 + 4) = 16.0f;
    }
    return var_v1 != 2;
}
/* mkdraft:func_814040D8 end */

f32 func_816092FC(void);
s32 func_81404334(void *arg0) {
    (*(f32 *)((u8 *)(arg0) + (4))) = (f32) ((*(f32 *)((u8 *)(arg0) + (4))) - func_816092FC());
    if ((*(f32 *)((u8 *)(arg0) + (4))) <= 0.0f) {
        (*(f32 *)((u8 *)(arg0) + (4))) = 0.0f;
        (*(s8 *)((u8 *)(arg0) + (0xC))) = 4;
    }
    return 1;
}

extern s32 func_814040D8(void *arg0);
extern void func_81403E7C(void *arg0, s16 *arg1);
extern s32 func_81404030(u8 *arg0);
extern s32 func_81404040(void *arg0);
extern s32 func_81404334(void *arg0);
extern void func_81600A34(void *arg0, void *arg1, void *arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void func_8140438C(void *arg0, void *arg1) {
    void *result;
    s16 rect[4];

    result = NULL;
    switch (*(u8 *)((u8 *)arg0 + 0xC)) {
    case 0:
    case 4:
        result = (void *)func_81404030(arg0);
        break;
    case 1:
        result = (void *)func_81404040(arg0);
        break;
    case 2:
        result = (void *)func_814040D8(arg0);
        break;
    case 3:
        result = (void *)func_81404334(arg0);
        break;
    }
    if (*(u8 *)((u8 *)arg0 + 0xC) != 0 && *(u8 *)((u8 *)arg0 + 0xC) != 4) {
        func_81403E7C(arg0, rect);
        func_81600A34(arg1, arg0, result, rect[0], rect[1], rect[2], rect[3]);
    }
}

extern void func_81400A50(s32, s32, s32, s32, f32, s32, s32, void *);
extern void func_81400884(s32, s32, s32, s32, f32, s32, s32, void *);
extern void func_81400C24(s32, s32, s32, s32, f32, s32);
extern void func_81400DE8(s32, s32, s32, s32, s32, f32, s32);
extern void func_81400FA4(s32, s32, s32, s32, s32, f32, s32);
extern void func_81403E7C(void *arg0, s16 *arg1);
extern s32 func_81600DA8(void *, void *);
void func_81404470(void *arg0, void *arg1) {
    s16 rect[4];

    if (func_81600DA8(arg1, arg0) != 0) {
        func_81403E7C(arg0, rect);
        switch (*(u8 *)((u8 *)arg0 + 0xE)) {
        case 1:
            func_81400A50(rect[0], rect[1], rect[2], rect[3], 1.0f - *(f32 *)((u8 *)arg0 + 4) / 16, 0,
                          *(s8 *)((u8 *)arg0 + 0x10), (u8 *)arg0 + 8);
            break;
        case 0:
            func_81400884(rect[0], rect[1], rect[2], rect[3], 1.0f - *(f32 *)((u8 *)arg0 + 4) / 16, 0,
                          *(s8 *)((u8 *)arg0 + 0x10), (u8 *)arg0 + 8);
            break;
        case 2:
            func_81400C24(rect[0], rect[1], rect[2], rect[3], 1.0f - *(f32 *)((u8 *)arg0 + 4) / 16, 0);
            break;
        case 3:
            func_81400DE8(rect[0], rect[1], rect[2], rect[3], *(s32 *)arg0, 1.0f - *(f32 *)((u8 *)arg0 + 4) / 16, 0);
            break;
        case 4:
            func_81400FA4(rect[0], rect[1], rect[2], rect[3], *(s32 *)arg0, 1.0f - *(f32 *)((u8 *)arg0 + 4) / 16, 0);
            break;
        }
    }
}

s32 func_8140463C(void *arg0, s32 arg1, s32 arg2) {
    s32 index;

    if (arg1 != *(s8 *)((u8 *)arg0 + 0xE)) {
        switch (*(u8 *)((u8 *)arg0 + 0xC)) {
        case 0:
        case 2:
        case 4:
            *(f32 *)((u8 *)arg0 + 4) = 0.0f;
        case 3:
            *(u8 *)((u8 *)arg0 + 0xC) = 1;
        case 1:
            *(s8 *)((u8 *)arg0 + 0xE) = arg1;
            *(s8 *)((u8 *)arg0 + 0x10) = 0;
            *(s32 *)arg0 = arg2;
            break;
        }
    } else if (*(u8 *)((u8 *)arg0 + 0xC) == 4) {
        index = *(s8 *)((u8 *)arg0 + 0x10);
        *(s8 *)((u8 *)arg0 + 0xE) = -1;
        *(s8 *)((u8 *)arg0 + 0x10) = -2;
        return index + 1;
    }
    return 0;
}

void func_814046C4(void *arg0) {
    *(s8 *)((u8 *)arg0 + 0x10) = -2;
    switch (*(u8 *)((u8 *)arg0 + 0xC)) {
    case 1:
    case 2:
        *(u8 *)((u8 *)arg0 + 0xC) = 3;
        break;
    case 0:
    case 3:
    case 4:
        break;
    }
}

s32 func_81404700(u8 *arg0) {
    s32 ret = *(s32 *)(arg0 + 0x14) != 0;

    if (ret) {
        return *(s8 *)(arg0 + 0x10) >= 0;
    }
    //!bug No return when the word at 0x14 is 0; callers get whatever is left in v0 (here 0).
}

void func_81404724(void *arg0, void *arg1) {
    f32 t;
    f32 inv;
    s16 *pos;
    s16 *out = arg1;
    t = *((f32 *)arg0) / 16;
    inv = 1.0f - t;
    pos = D_81407A1C[*((s8 *)((u8 *)arg0 + 9))];
    out[0] = pos[0] + (41.5f * inv);
    out[1] = pos[1] + (41.5f * inv);
    out[2] = 83.0f * t;
    out[3] = 83.0f * t;
}

void func_814047C0(void *arg0, void *arg1)
{
  f32 t;
  f32 inv;
  s16 *pos;
  s16 *out = arg1;
  t = (*((f32 *) arg0)) / 16;
  inv = 1.0f - t;
  pos = D_81407A2C[*((s8 *) (((u8 *) arg0) + 9))];
  out[0] = pos[0] + (63.5f * inv);
  out[1] = pos[1] + (25.5f * inv);
  out[2] = 127.0f * t;
  out[3] = 51.0f * t;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/12/fragment12_E7C00/func_8140487C.s")


void *func_814049CC(void *arg0) {
    s8 temp_v1;

    temp_v1 = (*(s8 *)((u8 *)(arg0) + (8)));
    if ((temp_v1 >= 0) && ((*(s32 *)((u8 *)(arg0) + (0x4D60))) == 0)) {
        return (temp_v1 * 0x28) + &D_800CE060;
    }
    return NULL;
}

typedef struct Candidate81404A08Record { s32 words[22]; } Candidate81404A08Record;
extern s32 func_814028F0(void);
extern void func_814038D4(void *arg0, void *arg1);
extern void func_81403FDC(void *arg0, s32 arg1, s32 arg2, s32 arg3);
void func_81404A08(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, void *arg5, void *arg6, s32 arg7, s32 arg8, s32 arg9, char *arg10, s32 arg11, s32 arg12)
{
    u8 *parentSlot;
    s32 i;
    Candidate81404A08Record *dst;
    u8 *guard;
    int timerOffset;
    Candidate81404A08Record *src;
    u8 *timerSlot;
    s32 count = 0;
    s32 mode;
    arg0[7] = arg3;
    *(s32 *)(arg0 + 0x4D60) = arg12;
    *(s32 *)(arg0 + 0x1C) = arg8;
    *(s32 *)(arg0 + 0x20) = 0;
    timerOffset = 4;
    arg0[8] = arg1;
    parentSlot = arg0 + 0x3C;
    for (i = 0; i < 6; i++) {
        *(s8 *)((arg0 + 0xA) + i) = -1;
    }
    *(void **)parentSlot = arg6;
    i = 0;
    timerSlot = arg0 + timerOffset;
    guard = arg0;
    src = arg5;
    dst = (Candidate81404A08Record *)(arg0 + 0x4B40);
    for (; i != 6; i++, guard += 0x58, dst++, src++) {
        *dst = *src;
        if (guard[0x4B40] > 0) {
            func_8004D878((void *)((arg0 + 0x40) + (i * 0xC80)), 0, (void *)dst);
            count++;
        }
    }
    if (count < arg4) {
        arg4 = count;
    }
    if (arg9 <= 0) {
        *(s16 *)timerSlot = 600;
    } else {
        *(s16 *)timerSlot = arg9;
    }
    arg0[0x12] = arg4;
    func_814038D4(arg6, arg0);
    mode = (arg0[9] = arg2);
    *(s32 *)(arg0 + 0x14) = arg7;
    *(s8 *)(arg0 + 0x10) = -1;
    arg0[6] = 0;
    *(f32 *)arg0 = 0.0f;
    arg0[0x11] = func_814028F0();
    *(s32 *)(arg0 + 0x18) = 0;
    *(s32 *)(arg0 + 0x4D5C) = arg11;
    func_81403FDC(arg0 + 0x24, (*(s32 *)(arg0 + 0x4D60)) ? -1 : arg1, arg2, arg7 == 0);
    HAL_Strcpy((char *)(arg0 + 0x4D50), arg10);
}

void func_81404BEC(void *arg0) {
    switch (*(u8 *)((u8 *)arg0 + 6)) {
    case 0:
        *(f32 *)arg0 = 0.0f;
    case 6:
        *(u8 *)((u8 *)arg0 + 6) = 1;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
        break;
    }
}

s32 func_81404C2C(u8 *arg0) {
    *(f32 *)(arg0 + 0) = 0.0f;
    return 0;
}

s32 func_81404C3C(void *arg0) {
    (*(f32 *)((u8 *)(arg0) + (0))) = (f32) ((*(f32 *)((u8 *)(arg0) + (0))) - func_816092FC());
    if ((*(f32 *)((u8 *)(arg0) + (0))) < 0.0f) {
        (*(f32 *)((u8 *)(arg0) + (0))) = 0.0f;
        (*(s8 *)((u8 *)(arg0) + (6))) = 7;
    }
    return 0;
}

s32 func_81404C94(u8 *arg0) {
    *(f32 *)(arg0 + 0) = 0.0f;
    return 0;
}

s32 func_81404CA4(void *arg0)
{
  f32 new_var;
  new_var = func_816092FC();
  *((f32 *) (((u8 *) arg0) + 0)) = (f32) ((*((f32 *) (((u8 *) arg0) + 0))) + new_var);
  if ((*((f32 *) (((u8 *) arg0) + 0))) >= 16.0f)
  {
    *((s8 *) (((u8 *) arg0) + 6)) = 2;
    *((f32 *) (((u8 *) arg0) + 0)) = 16.0f;
  }
  return 0;
}

s32 func_81404D00(void *arg0) { s32 i=0; s32 count=*(s8 *)((u8 *)arg0+0x12); u8 *p=arg0; if(count<=0) goto done; loop: if(*(s8 *)((u8 *)p+0xA)<0) return i; ++i; p=(u8 *)p+1; if(i<count) goto loop; done: return count; }

s32 func_81404D44(void *arg0)
{
    s32 count;
    s32 sum;
    s32 i;
    u8 *ptr;
    s32 index;
    sum = 0;
    i = 0;
    count = *((s8 *) (((u8 *) arg0) + 0x12));
    ;
    ptr = arg0;
    if ((count >= (0 + 1)) ^ 0)
    {
        if (1)
        {
loop:
            index = *((s8 *) (ptr + 0xA));
            if (index < 0)
            {
                return sum;
            }
            sum += *((((u8 *) arg0) + (index * 0x58)) + 0x4B5D);
            i++;
            ptr++;
            index += 0;
        }
        if (i < count)
        {
            goto loop;
        }
    }
    return sum;
}

s32 func_81404DA0(void *arg0, s32 arg1)
{
  s8 limit;
  s32 result;
  u8 *ptr;
  result = 0;
  limit = *((s8 *) (((u8 *) arg0) + 0x12));
  ptr = (u8 *) arg0;
  if (limit <= 0)
  {
    goto done;
  }
  loop:
  result += 1;

  if (arg1 != (*((s8 *) (ptr + 0xA))))
  {
    goto next;
  }
  return 1;
  next:
  ptr += 1;

  if (result < limit)
  {
    goto loop;
  }
  done:
  return 0;

}

s32 func_81404DE4(u16 arg0) {
    switch (arg0 & 0xC00F) {
        case 0x4000: return 0;
        case 0x2: return 1;
        case 0x8: return 2;
        case 0x8000: return 3;
        case 0x4: return 4;
        case 0x1: return 5;
        default: return -1;
    }
}

void func_81404DE4_padding(void) {
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/12/fragment12_E7C00/func_81404E68.s")

extern s32 func_81403938(s32 arg0);
extern s32 func_8140463C(void *arg0, s32 arg1, s32 arg2);
extern void func_814046C4(void *arg0);
extern s32 func_81404D00(void *arg0);
s32 func_814050EC(void *arg0) {
    typedef struct {
        u8 pad0[4];
        u16 unk4;
        u8 unk6;
        u8 unk7;
        u8 pad8[8];
        s8 unk10;
        s8 unk11;
        s8 unk12;
        s8 unk13;
        s32 unk14;
        s32 unk18;
        u8 pad1c[8];
        u8 unk24[0x18];
        s32 unk3c;
    } State;
    State *state;
    s32 sp28;
    s32 sp24;
    void *temp_v0;
    s32 result;
    s32 mode;

    state = arg0;
    sp28 = func_81404D00(arg0);
    sp24 = state->unk18;
    temp_v0 = func_814049CC(state);
    if (sp28 < state->unk12) {
        state->unk6 = 2;
        func_814046C4(state->unk24);
        return 0;
    }
    if (state->unk14 != 0) {
        mode = 1;
    } else {
        mode = 0;
    }
    result = func_8140463C(state->unk24, mode, 0);
    state->unk10 = -1;
    if ((temp_v0 != NULL) && ((*(u16 *)((u8 *)temp_v0 + 6) & 0x10) != 0)) {
        state->unk18 = 1;
    } else {
        state->unk18 = 0;
    }
    if (result < 0 || result == 2) {
        func_81403938(state->unk3c);
        state->unk6 = 2;
    } else if (result == 1) {
        state->unk6 = 5;
    }
    mode = (state->unk14 == 0);
    if (mode == 0) {
        mode = (sp24 != state->unk18);
    }
    return mode;
}

extern s32 func_81403938(s32 arg0);
extern s32 func_8140463C(void *arg0, s32 arg1, s32 arg2);
extern void func_814046C4(void *arg0);
extern s32 func_81404D00(void *arg0);

s32 func_81405208(void *arg0) {
    typedef struct {
        u8 pad0[4]; u16 unk4; u8 unk6; u8 unk7; u8 pad8[8];
        s8 unk10; s8 unk11; s8 unk12; s8 unk13;
        s32 unk14; s32 unk18; u8 pad1c[8]; u8 unk24[0x18]; s32 unk3c;
    } State;
    State *state;
    s32 sp28;
    s32 sp24;
    void *temp_v0;
    s32 temp_v0_2;
    s32 var_v1;

    state = arg0;
    sp28 = func_81404D00(arg0);
    sp24 = state->unk18;
    temp_v0 = func_814049CC(state);
    if (sp28 < state->unk12) {
        state->unk6 = 2;
        func_814046C4(state->unk24);
        return 0;
    }
    if ((temp_v0 != NULL) && ((*(u16 *)((u8 *)temp_v0 + 0x6) & 0x10) != 0))
        state->unk18 = 1;
    else
        state->unk18 = 0;
    temp_v0_2 = func_8140463C(state->unk24, 2, 0);
    state->unk10 = -1;
    if (temp_v0_2 < 0) {
        func_81403938(state->unk3c);
        state->unk6 = 2;
    } else if (temp_v0_2 > 0) {
        state->unk6 = 6;
    }
    var_v1 = (state->unk14 == 0);
    if (var_v1 == 0)
        var_v1 = (sp24 != state->unk18);
    return var_v1;
}

extern s32 func_81403938(s32 arg0);
extern void func_814046C4(void *arg0);
extern s32 func_81404D00(void *arg0);
extern s32 func_8140463C(void *arg0, s32 arg1, s32 arg2);
s32 func_814052F4(void *arg0) {
    typedef struct {
        u8 pad0[4];
        u16 unk4;
        u8 unk6;
        u8 unk7;
        u8 pad8[8];
        s8 unk10;
        s8 unk11;
        s8 unk12;
        s8 unk13;
        s32 unk14;
        s32 unk18;
        u8 pad1c[8];
        u8 unk24[0x18];
        s32 unk3c;
    } State;
    State *state;
    s32 sp28;
    s32 sp24;
    void *temp_v0;
    s32 temp_v0_2;
    s32 mode;

    state = arg0;
    sp28 = func_81404D00(arg0);
    sp24 = state->unk18;
    temp_v0 = func_814049CC(state);
    if (sp28 < state->unk12) {
        state->unk6 = 2;
        func_814046C4(state->unk24);
        return 0;
    }
    if ((temp_v0 != NULL) && ((*(u16 *)((u8 *)temp_v0 + 6) & 0x10) != 0)) {
        state->unk18 = 1;
    } else {
        state->unk18 = 0;
    }
    if (state->unk14 != 0) {
        mode = 4;
    } else {
        mode = 3;
    }
    temp_v0_2 = func_8140463C(state->unk24, mode, state->unk4);
    state->unk10 = -1;
    if (temp_v0_2 != 0) {
        func_81403938(state->unk3c);
        state->unk6 = 2;
    }
    mode = (state->unk14 == 0);
    if (mode == 0) {
        mode = (sp24 != state->unk18);
    }
    return mode;
}

extern void func_81404724(void *arg0, void *arg1);
extern void func_814047C0(void *arg0, void *arg1);
extern void func_81600A34(void *arg0, void *arg1, void *arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void func_814053E4(void *arg0, void *arg1, void *arg2) {
    s16 first[4];
    s16 second[4];

    if (*(s32 *)((u8 *)arg0 + 0x14) == 0)
        return;
    func_81404724(arg0, first);
    func_814047C0(arg0, second);
    if (*(s8 *)((u8 *)arg0 + 9) < 2)
        func_81600A34(arg1, (u8 *)arg0 + 1, arg2, first[0], first[1], first[2], first[3]);
    func_81600A34(arg1, (u8 *)arg0 + 2, arg2, second[0], second[1], second[2], second[3]);
    if (*(s8 *)((u8 *)arg0 + 9) >= 2)
        func_81600A34(arg1, (u8 *)arg0 + 1, arg2, first[0], first[1], first[2], first[3]);
}


void func_814054CC(u8 *arg0, void *arg1)
{
    switch (arg0[6])
    {
        case 0:
        case 1:
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            func_8140438C(arg0 + 0x24, arg1);
            break;
        case 6:
        case 7:
            break;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/12/fragment12_E7C00/func_81405514.s")

/* mkdraft:func_814057CC begin */
extern u8 D_80094E38[];
extern u8 D_80094F50[];
extern void func_800495BC(s32 arg0, s32 arg1, const char *arg2, ...);
extern void func_800495F8(s32 x, s32 y, s32 mode, const char *format, ...);
extern void func_800496A4(s32 a0, s32 a1);
extern void func_8004972C(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_800498C4(void);
extern void func_800499EC(void);
extern void *func_8004C874(s32 arg0, s32 arg1);
extern void func_8004D998(s32 arg0, s32 arg1, u8 *arg2, s32 arg3, s32 arg4);
extern void *func_80062CE0(u8 arg0);
extern u8 func_80062D98(u8 arg0);
extern s32 func_80063270(u8 arg0);
extern u8 func_8006397C(u8 arg0);
extern u8 func_800639C0(u8 arg0);
extern void func_81602DA4(s32 arg0);
extern void func_81603C84(s32 arg0, s32 arg1, s32 arg2);
extern void func_8160877C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4);
extern void func_81608890(s32 arg0, s32 arg1, u8 *arg2);

extern const char D_81407A6C[4];
extern const char D_81407A70[4];
extern const char D_81407A74[4];
extern const char D_81407A78[4];
extern const char D_81407A7C[4];
extern const char D_81407A80[4];
extern const char D_81407A84[4];
extern const char D_81407A88[8];

// The y-coordinate sums put the constant before the index (`arg1 + 0x6A + i * 0x14`):
// that add order emits `addu base,index`; with the index first, IDO commutes the
// operands to `addu index,base`.


void func_814057CC(s32 arg0, s32 arg1, u8 *arg2, u8 *arg3) {
    s32 i;

    func_800498C4();
    func_800496A4(8, 1);
    func_800495F8(arg0 + 0xA, arg1 + 8, 0, (const char *)(arg2 + 0x34));
    func_800496A4(4, 1);
    func_800495BC(arg0 + 0x89, arg1 + 8, func_8004C874(0xD, 3));
    func_800495BC(arg0 + 0x89, arg1 + 0x1B, func_8004C874(0xD, 4));
    func_800495BC(arg0 + 0x89, arg1 + 0x2E, func_8004C874(0xD, 6));
    func_800495BC(arg0 + 0x89, arg1 + 0x41, func_8004C874(0xD, 7));
    func_800495BC(arg0 + 0x89, arg1 + 0x54, func_8004C874(0xD, 5));
    func_800495F8(arg0 + 0xF7, arg1 + 8, 2, D_81407A6C, *(u16 *)(arg2 + 0x2A));
    func_800495F8(arg0 + 0xF7, arg1 + 0x1B, 2, D_81407A70, *(u16 *)(arg2 + 0x2C));
    func_800495F8(arg0 + 0xF7, arg1 + 0x2E, 2, D_81407A74, *(u16 *)(arg2 + 0x30));
    func_800495F8(arg0 + 0xF7, arg1 + 0x41, 2, D_81407A78, *(u16 *)(arg2 + 0x32));
    func_800495F8(arg0 + 0xF7, arg1 + 0x54, 2, D_81407A7C, *(u16 *)(arg2 + 0x2E));

    i = 0;
    for (; i < 4; i++) {
        if (arg2[i + 2] <= 0)
            break;
        func_81602DA4(func_80062D98(arg2[i + 2]));
        func_800495BC(arg0 + 0x6B, arg1 + 0x6A + i * 0x14, func_80062CE0(arg2[i + 2]));
        func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
        func_800495F8(arg0 + 0xF7, arg1 + 0x6A + i * 0x14, 2, D_81407A80, arg2[i + 0x18] & 0x3F);
    }
    func_800495BC(arg0 + 0xA, arg1 + 0x68, func_8004C874(0xD, 0x12));
    func_81602DA4(func_8006397C(arg2[0]));
    func_800495BC(arg0 + 0x14, arg1 + 0x7C, func_80063270(func_8006397C(arg2[0])));
    func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
    if (func_8006397C(arg2[0]) != func_800639C0(arg2[0])) {
        func_800495BC(arg0 + 0xA, arg1 + 0x90, func_8004C874(0xD, 0x13));
        func_81602DA4(func_800639C0(arg2[0]));
        func_800495BC(arg0 + 0x14, arg1 + 0xA4, func_80063270(func_800639C0(arg2[0])));
        func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
    }
    if (arg2[1] > 0) {
        func_8004972C(0xFF, 0xBE, 0, 0xFF);
        func_800495BC(arg0 + 0xA, arg1 + 0x54, func_8004C874(8, arg2[1] - 1));
        func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
    }
    func_800495BC(arg0 + 0x34, arg1 + 0x34, func_8004C874(0xD, 2));
    func_800495BC(arg0 + 0x54, arg1 + 0x34, D_81407A84, *(u16 *)(arg2 + 0x28));
    func_800495BC(arg0 + 0x34, arg1 + 0x20, D_81407A88, func_8004C874(0xD, 0x15), arg2[0x1D]);
    func_81608890(arg0 + 0x6E, arg1 + 0xC, arg2);
    func_800499EC();
    gSPDisplayList(D_800D0510++, D_80094E38);
    for (i = 0; i != 4; i++) {
        if (arg2[i + 2] > 0)
            func_81603C84(arg0 + 0x55, arg1 + 0x68 + i * 0x14, func_80062D98(arg2[i + 2]));
    }
    func_8004D998(arg0 + 0xA, arg1 + 0x1E, arg3, 0, 1);
    func_8160877C(arg0 + 0xA, arg1 + 0x43, arg2[1], 1, 1.0f);
    gSPDisplayList(D_800D0510++, D_80094F50);
}
/* mkdraft:func_814057CC end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/12/fragment12_E7C00/func_81405CC4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/12/fragment12_E7C00/func_814063A0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/12/fragment12_E7C00/func_81406700.s")

void func_81406A30(void *arg0) {
    switch (*(u8 *)((u8 *)arg0 + 6)) {
        case 0:
        case 4:
        case 6:
            break;
        case 2:
        case 3:
        case 5:
            *(f32 *)arg0 = 16.0f;
            /* fallthrough */
        case 1:
            *(u8 *)((u8 *)arg0 + 6) = 6;
            break;
    }
}

s32 func_81406A74(u8 *arg0) {
    return arg0[6] == 5 && arg0[0x30] == 2;
}

s32 func_81406A9C(u8 *arg0) {
    return arg0[6] == 7;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/12/fragment12_E7C00/func_81406AAC.s")

extern void func_81404BEC(void *arg0);
extern void func_800226C0(s32 arg0);
void func_81406EA8(void *arg0) {
    s32 i;

    for (i = 0; i != 4; i++) {
        if (*(s32 *)((u8 *)arg0 + 0x18F48 + i * 4) != 0)
            func_81404BEC((u8 *)arg0 + i * 0x4D68 + 0x1990);
    }
    func_800226C0(0xA5);
    func_81403A18(arg0);
    func_81403A18((u8 *)arg0 + 0xCC8);
}

typedef struct { u8 padding[0x18F58]; s32 finished; s32 activated; } F81406F44StoreView;
typedef struct { u8 padding[0xF48]; s32 active[4]; s32 finished; s32 activated; } F81406F44TailView;
extern void func_814071C4(void *arg0);
extern void func_81405514(void *arg0, void *arg1);
extern void func_81403B7C(u8 *arg0, void *arg1);
extern void func_800225C4(s32 arg0);
extern void func_81406A30(void *arg0);
extern s32 func_81406A74(u8 *arg0);
void func_81406F44(void *arg0, void *arg1) {
    s32 i;
    s32 done = 1;

    if (((F81406F44TailView *)((u8 *)arg0 + 0x18000))->finished != 0) {
        func_814071C4(arg0);
    }
    if (((F81406F44TailView *)((u8 *)arg0 + 0x18000))->activated == 0) {
        for (i = 0; i < 4; i++) {
            if (*(s32 *)((u8 *)arg0 + 0x18F48 + i * 4) != 0) {
                if (*(s32 *)((u8 *)arg0 + i * 0x4D68 + 0x19B0) != 0) {
                    ((F81406F44StoreView *)arg0)->activated = 1;
                    break;
                }
            }
        }
        if (((F81406F44TailView *)((u8 *)arg0 + 0x18000))->activated != 0) {
            for (i = 0; i != 4; i++) {
                if (*(s32 *)((u8 *)arg0 + 0x18F48 + i * 4) != 0) {
                    func_81406A30((u8 *)arg0 + i * 0x4D68 + 0x1990);
                }
            }
        }
    }
    for (i = 0; i != 4; i++) {
        if (*(s32 *)((u8 *)arg0 + 0x18F48 + i * 4) != 0) {
            func_81405514((u8 *)arg0 + i * 0x4D68 + 0x1990, arg1);
            if (func_81406A74((u8 *)arg0 + i * 0x4D68 + 0x1990) == 0) {
                done = 0;
            }
        }
    }
    if (done != 0 && ((F81406F44TailView *)((u8 *)arg0 + 0x18000))->finished == 0) {
        func_800225C4(0x10);
        ((F81406F44StoreView *)arg0)->finished = 1;
    }
    func_81403B7C(arg0, arg1);
    func_81403B7C((u8 *)arg0 + 0xCC8, arg1);
}

extern void func_81406700(void *arg0, void *arg1);
extern void func_81403CD0(void *arg0, void *arg1);
void func_81407118(void *arg0, void *arg1) {
    s32 i;

    for (i = 0; i != 4; i++) {
        if (*(s32 *)((u8 *)arg0 + 0x18F48 + i * 4) != 0)
            func_81406700((u8 *)arg0 + i * 0x4D68 + 0x1990, arg1);
    }
    func_81403CD0(arg0, arg1);
    func_81403CD0((u8 *)arg0 + 0xCC8, arg1);
}

extern void func_81406A30(void *arg0);
extern void func_81403E2C(void *arg0);
void func_814071C4(void *arg0) {
    s32 i;
    u8 *ptr;

    ptr = (u8 *)arg0 + 0x18000;
    i = 0;
    do {
        if (*(s32 *)(ptr + 0xF48) != 0) {
            func_81406A30((u8 *)arg0 + i * 0x4D68 + 0x1990);
        }
        i++;
        ptr += 4;
    } while (i != 4);
    func_81403E2C(arg0);
    func_81403E2C((u8 *)arg0 + 0xCC8);
}

extern s32 func_81406A9C(u8 *arg0);
s32 func_81407258(void *arg0) {
    s32 i;
    s32 result;

    for (i = 0; i != 4; i++) {
        if (*(s32 *)((u8 *)arg0 + 0x18F48 + i * 4) != 0) {
            if (func_81406A9C((u8 *)arg0 + i * 0x4D68 + 0x1990) == 0)
                return 0;
        }
    }
    if (*(s32 *)((u8 *)arg0 + 0x18F5C) != 0)
        result = -1;
    else
        result = 1;
    return result;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/12/fragment12_E7C00/func_81407310.s")
#endif
