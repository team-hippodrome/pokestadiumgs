#include "global.h"


#ifdef VERSION_US
extern u8 D_8220D79C[];
extern u8 D_8220D7A0[];
extern u8 D_8220D7A4[];
extern u8 D_8220D7A8[];
s32 func_82200600(u8 *arg0, u16 arg1) {
    typedef struct { u8 a, b, c; } Color;
    u8 *src = NULL;
    s32 result = 0;
    switch (arg1) {
    case 1: src = D_8220D79C; break;
    case 2: src = D_8220D7A0; break;
    case 3: src = D_8220D7A4; break;
    case 4: src = D_8220D7A8; break;
    }
    if (src != NULL) {
        *(Color *)arg0 = *(Color *)src;
        result = 1;
    }
    return result;
}

/* mkdraft:func_82200694 begin */
s32 func_82200694(void *arg0) {
    s32 i;
    s32 ret;

    ret = -1;
    for (i = 0; i != 30; i++) {
        if (*(s16 *)((u8 *)arg0 + 0x24 + i * 0xC) == 0) {
            ret = i;
            break;
        }
    }
    return ret;
}
/* mkdraft:func_82200694 end */

typedef struct F822006CC_Particle {
    s16 unk0;
    s16 unk2;
    f32 unk4;
    s16 unk8;
    s16 unkA;
} F822006CC_Particle;
extern f32 D_8220E0C8;
extern f32 D_8220E0CC;
extern f32 D_80088E50[];
extern f32 D_80087E50[];
void func_822006CC(F822006CC_Particle *arg0, s32 arg1, s32 arg2) {
    u16 angle;
    f32 radius;
    s32 index;

    angle = guRandom() & 0xFFFF;
    radius = (s32)guRandom() % 33;
    arg0->unk0 = 1;
    arg0->unk2 = 0;
    arg0->unk4 = ((f32)((s32)guRandom() % 101) * D_8220E0C8) / 100.0f + D_8220E0CC;
    index = (s32)angle >> 4;
    arg0->unk8 = (s16)(s32)(D_80088E50[index] * radius + (f32)arg1);
    arg0->unkA = (s16)(s32)(D_80087E50[index] * radius + (f32)arg2);
}

void func_822007D8(u8 *arg0) {
    s32 i;
    F822006CC_Particle *particle;

    for (i = 0; i < 30; i++) {
        particle = (F822006CC_Particle *)(arg0 + 36) + i;
        if (particle->unk0 != 0) {
            particle->unk2++;
            if (particle->unk2 >= 10) {
                particle->unk0 = 0;
            }
        }
    }
}

#pragma GLOBAL_ASM("hand_asm/fragments/17/func_82200918_manual.s")

extern void _bzero(void *, s32);
void func_82200C3C(u8* arg0) {
    _bzero(arg0 + 36, 360);
}

/* mkdraft:func_82200C60 begin */
extern s32 D_8220E4E0;
extern s32 D_8220EB10;



s32 func_82200C60(void) {
    u8 *var_a0;
    u8 *var_a2;
    s32 var_a1;
    s32 var_v1;
    s32 extra;

    /* FAKE: D_8220E0C8 is the f32 scale factor func_822006CC multiplies by;
     * it is not a byte counter. This dead byte read and the empty if(test)
     * after the loop exist only to move the loop cursor's register: with
     * them the ROM's assignment comes out (cursor a0, loop bound a3, 360 in
     * t0); without them the same body scores 110 with the cursor in v0, the
     * bound in a2 and 360 in a3. as1 drops the load because nothing reads
     * its result, so the pair costs no instruction. */
    extra = *(u8 *)&D_8220E0C8;
    var_v1 = 1;
    /* The `do` sits on this line deliberately: uopt hoists the loop bound
     * &D_8220EB10 into the preheader carrying the loop head's source line,
     * and as1 breaks the lui/addiu scheduling tie between the two address
     * computations by those lines. Same line puts the bound's addiu before
     * the cursor's, as in the ROM; separate lines put the cursor's first
     * (two-word residual, score 30). */
    var_a0 = (u8 *)&D_8220E4E0; do {
        var_a1 = 0;
        var_a2 = var_a0;
loop_2:
        var_a1 += 12;
        if (*(s16 *)(var_a2 + 0x24) != 0) {
            var_v1 = 0;
        } else {
            var_a2 += 12;
            if (var_a1 != 360) {
                goto loop_2;
            }
        }
        var_a0 += 396;
    } while (var_a0 != (u8 *)&D_8220EB10);
    /* FAKE: the dead use that keeps the load at the top of the function. */
    if (extra) { }
    return var_v1;
}
/* mkdraft:func_82200C60 end */

extern s32 func_8004C8C0(s32);
extern s32 D_8220E4E0;
void func_82200CB4(void) {
    _bzero(&D_8220E4E0, 0x630);
    func_8004C8C0(0x95);
    func_8004C8C0(0x93);
}

s32 func_82200CEC(s32 a0){s32 v1=0;volatile s32 *p=&a0;a0&=0xFF;if(a0==1||a0==2||a0==3||a0==4)v1=1;return v1;}

void func_82200D28(void *arg0, s32 arg1)
{
  if (func_82200CEC(arg1 & 0xFF) != 0)
  {
    *((s16 *) (((u8 *) arg0) + 0)) = 1;
    *((s16 *) (((u8 *) arg0) + 2)) = (s16) (guRandom() % 24U);
    *((s16 *) (((u8 *) arg0) + 0xA)) = 0x80;
    *((f32 *) (((u8 *) arg0) + 0x10)) = 1.5f;
  }
  if (!arg1)
  {
  }
}

extern s32 func_82200CEC(s32 a0);
void func_82200D8C(u8 *arg0, u8 arg1) { s32 result = func_82200CEC(arg1); *(u16 *)(arg0 + 4) = arg1; if (result != 0 && *(s16 *)arg0 == 1) { *(s16 *)arg0 = 2; *(s16 *)(arg0 + 2) = 0; *(s16 *)(arg0 + 8) = *(s16 *)(arg0 + 6); *(s16 *)(arg0 + 12) = *(s16 *)(arg0 + 10); *(f32 *)(arg0 + 20) = *(f32 *)(arg0 + 16); _bzero(arg0 + 36, 0x168); } }

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_10FFC0/func_82200E04.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_10FFC0/func_822011AC.s")

typedef struct Func82201460Record {
    s16 active;
    s16 unk02;
    u16 flags;
    s16 unk06;
    s16 unk08;
    s16 unk0A;
    s32 unk0C;
    s32 unk10;
    s32 unk14;
    s16 x;
    s16 y;
    s16 dx;
    s16 dy;
} Func82201460Record;
extern void func_822011AC(s16, s16, s32, s16, s32);
extern void func_82200918(void *, u16);
void func_82201460(Func82201460Record *arg0) {
    s16 x;
    s16 y;
    if (arg0->active != 0) {
        x = arg0->x + arg0->dx;
        y = arg0->y + arg0->dy;
        func_822011AC(x, y, arg0->unk10, arg0->unk0A, arg0->flags);
        func_82200918(arg0, arg0->flags);
    }
}

extern u8 D_8220E4C8[];
void func_822014D8(void) {
    *(u16 *)(D_8220E4C8 + 0) = 0;
    *(u16 *)(D_8220E4C8 + 2) = 0;
    *(u16 *)(D_8220E4C8 + 4) = 0x280;
    *(u16 *)(D_8220E4C8 + 6) = 0x1E0;
}

void func_822014FC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    *(u16 *)(D_8220E4C8 + 0) = arg0;
    *(u16 *)(D_8220E4C8 + 2) = arg1;
    *(u16 *)(D_8220E4C8 + 4) = arg2;
    *(u16 *)(D_8220E4C8 + 6) = arg3;
}

s32 func_82201518(u8 *arg0) { s32 result; if (arg0[1] != 0) { if (arg0[0] == 0) { if (arg0[3] != 0) result = 0; else result = 3; } else result = 4; } else if (arg0[0] == 2) result = 5; else if (arg0[4] != 0) result = 1; else result = 2; return result; }

s32 func_8220158C(void *arg0) {
    s32 var_v1;
    u8 temp_v0;

    temp_v0 = (*(u8 *)((u8 *)(arg0) + (5)));
    var_v1 = 1;
    if ((temp_v0 == 1) || (temp_v0 == 2)) {
        var_v1 = 0;
    }
    return var_v1;
}

// Game Boy save entry per controller port, 0x14 bytes each; func_822015B4 fills them.
typedef struct F822015B4_Entry {
    /* 0x00 */ u8 unk_00; // func_8005D8CC(port)
    /* 0x01 */ u8 unk_01; // func_8005D92C(port)
    /* 0x02 */ u8 unk_02; // func_8005D948(port)
    /* 0x03 */ u8 unk_03; // func_8005DDD4(port)
    /* 0x04 */ u8 connected; // bit `port` of func_800060E8's controller bits
    /* 0x05 */ u8 status; // func_82201518(entry)
    /* 0x06 */ u16 unk_06; // first halfword of func_8005D9E0's buffer
    /* 0x08 */ s8 name[12]; // string after it
} F822015B4_Entry;
extern u8 D_8220E310[];
extern u8 func_800060E8(void);
extern void func_8005D9E0(s32, void *);
extern u8 func_8005D8CC(s32);
extern u8 func_8005D92C(s32);
extern u8 func_8005D948(s32);
extern s32 func_8005DDD4(s32);
extern s8 *HAL_Strcpy(s8 *, s8 *);

// Same code as Pokemon Stadium's TransferPak_ScanAllPorts
// (src/fragments/transfer_pak_select/transfer_pak_select.c), refreshing the four
// entries at D_8220E310 from func_8005D9E0's buffer and the per-port getters; GS also
// stores func_82201518's status and returns how many entries func_8220158C accepts.
s32 func_822015B4(void) {
    s32 i;
    s32 count;
    struct {
        u16 id;
        s8 name[14];
    } buffer;
    F822015B4_Entry *entry;
    u8 controller_bits;

    count = 0;
    controller_bits = func_800060E8();

    for (i = 0; i < 4; i++) {
        entry = (F822015B4_Entry *)(D_8220E310 + i * 0x14);
        func_8005D9E0(i, &buffer);
        entry->unk_00 = func_8005D8CC(i);
        entry->unk_01 = func_8005D92C(i);
        entry->unk_02 = func_8005D948(i);
        entry->unk_03 = func_8005DDD4(i);
        entry->connected = (controller_bits & (1 << i)) != 0;
        entry->unk_06 = buffer.id;
        HAL_Strcpy(entry->name, buffer.name);
        entry->status = func_82201518((u8 *)entry);
        if (func_8220158C(entry)) {
            count++;
        }
    }
    return count;
}
extern s16 D_8220E378;
extern s16 D_8220E3B4;
extern s16 D_8220E3F0;
extern s16 D_8220E42C;
void Fragment17_ResetAnimationEntries(s32 inactive) {
    u8 *p;
    s32 i;

    for (i = 0; i < 4; i++) {
        p = (u8 *)&D_8220E378 + i * 0x3C;
        if (inactive != 0) {
            *(s16 *)(p + 0) = 0;
        } else {
            *(s16 *)(p + 0) = 2;
        }
        *(u16 *)(p + 2) = i * 0x4000;
        *(u16 *)(p + 4) = 0;
        *(u16 *)(p + 6) = 0;
        *(f32 *)(p + 8) = 0.0f;
        *(f32 *)(p + 0xC) = 0.0f;
    }
}
extern f32 D_80087E50[];
void func_822017B0(u8* arg0) {
    s16 var_v0;
    s16 var_v1;
    s16 var_a1;

    var_v0 = *(s16*)(arg0 + 0x18) - *(s16*)(arg0 + 0x10);
    var_v1 = *(s16*)(arg0 + 0x1A) - *(s16*)(arg0 + 0x12);
    var_a1 = *(s16*)(arg0 + 0x12);
    *(s16*)(arg0 + 0x1E) = (s16)(s32)(D_80087E50[*(u16*)(arg0 + 2) >> 4] * 10.0f + (f32)var_a1);
    *(s16*)(arg0 + 0x20) = *(s16*)(arg0 + 0x1C) + var_v0;
    *(s16*)(arg0 + 0x22) = *(s16*)(arg0 + 0x1E) + var_v1;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_10FFC0/func_82201834.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_10FFC0/func_82201960.s")

extern f32 D_80087E50[];
void func_82201AE0(u8 *arg0) {
    s16 deltaX;
    s16 deltaY;
    s16 y;

    deltaX = *(s16 *)(arg0 + 0x14) - *(s16 *)(arg0 + 0x10);
    deltaY = *(s16 *)(arg0 + 0x16) - *(s16 *)(arg0 + 0x12);
    *(s16 *)(arg0 + 2) += 0x400;
    y = *(s16 *)(arg0 + 0x12);
    *(s16 *)(arg0 + 0x1E) = (s16)(s32)(D_80087E50[(u16)*(s16 *)(arg0 + 2) >> 4] * 10.0f + (f32)y);
    *(s16 *)(arg0 + 0x20) = *(s16 *)(arg0 + 0x1C) + deltaX;
    *(s16 *)(arg0 + 0x22) = *(s16 *)(arg0 + 0x1E) + deltaY;
}

extern s16 D_8220E378;
extern u8 D_8220E468[];
extern void func_822017B0(u8 *);
extern void func_82201960(u8 *);
extern void func_82201AE0(u8 *arg0);
void func_82201B70(void) {
    u8 *p = (u8 *)&D_8220E378; do {
        switch (*(s16 *)p) {
        case 0: func_822017B0(p); break;
        case 1: func_82201960(p); break;
        case 2: func_82201AE0(p); break;
        }
        p += 0x3C;
    } while (p != D_8220E468);
}

extern s16 D_8220E378;
extern s16 D_8220E3B4;
extern s16 D_8220E3F0;
extern s16 D_8220E42C;
s32 func_82201C14(void) {
    s32 var_v1;

    var_v1 = 1;
    if (D_8220E378 != 2) {
        var_v1 = 0;
    }
    if (D_8220E3B4 != 2) {
        var_v1 = 0;
    }
    if (D_8220E3F0 != 2) {
        var_v1 = 0;
    }
    if (D_8220E42C != 2) {
        var_v1 = 0;
    }
    return var_v1;
}

typedef struct { s16 x; s16 y; } F82201C70_Pair;
typedef struct { s16 x; s16 y; s16 w; s16 h; } F82201C70_Rect;
typedef struct { s16 mode; s16 flags; F82201C70_Rect current; F82201C70_Rect saved; s16 k0; s16 k1; s16 k2; s16 k3; F82201C70_Pair currentPair; F82201C70_Pair savedPair; s16 z0; s16 z1; } F82201C70_State;
typedef struct { u8 pad00[8]; F82201C70_Rect rect; u8 pad10[0x18]; F82201C70_Pair pair; } F82201C70_Input;
typedef struct { F82201C70_Pair origin; s16 w; s16 h; } F82201C70_NestedRect;
typedef struct { s16 mode; s16 flags; F82201C70_NestedRect current; F82201C70_NestedRect saved; s16 k0; s16 k1; s16 k2; s16 k3; F82201C70_Pair currentPair; F82201C70_Pair savedPair; s16 z0; s16 z1; } F82201C70_NestedState;
void func_82201C70(F82201C70_State *arg0, F82201C70_Input *arg1) {
    arg0->mode = 1;
    arg0->flags = 0;
    arg0->current.x = arg1->rect.x;
    arg0->current.y = arg1->rect.y;
    arg0->current.w = arg1->rect.w;
    arg0->current.h = arg1->rect.h;
    *(F82201C70_Pair *)&arg0->saved = *(F82201C70_Pair *)&arg0->current;
    arg0->saved.w = arg0->current.w;
    arg0->saved.h = arg0->current.h;
    arg0->k0 = 0x3B;
    arg0->k1 = 0x16B;
    arg0->k2 = 0x1F4;
    arg0->k3 = 0x55;
    arg0->currentPair.x = arg1->pair.x;
    arg0->currentPair.y = arg1->pair.y;
    arg0->savedPair.x = arg0->currentPair.x;
    arg0->savedPair.y = arg0->currentPair.y;
    arg0->z0 = 0;
    arg0->z1 = 0;
}

s32 func_82201D08(void *arg0) {
    s32 var_v1;

    var_v1 = 0;
    if ((*(s16 *)((u8 *)(arg0) + (0))) == 1) {
        var_v1 = 1;
        (*(s16 *)((u8 *)(arg0) + (0))) = 2;
        (*(s16 *)((u8 *)(arg0) + (2))) = 0;
    }
    return var_v1;
}

// Steps the F82201C70_State animation started by func_82201D08: while mode is
// 2, advances the step counter at offset 2 and lerps the four current fields
// (current.x/y/w/h) from their saved values toward the k0..k3 constants over
// eight steps. currentPair.x/y is recomputed to keep the offset savedPair.x/y
// had from the saved width/height (current.w - (saved.w - savedPair.x));
// negative results clamp to zero. One step past seven the current fields snap
// to the k constants and mode becomes 3. Always returns 1.
s32 func_82201D30(u8 *arg0) {
    s32 saved_h_minus_pair_y;
    s32 saved_w_minus_pair_x;
    s32 step;

    if (*(s16 *)arg0 == 2) {
        saved_w_minus_pair_x = *(s16 *)(arg0 + 0x10) - *(s16 *)(arg0 + 0x20);
        saved_h_minus_pair_y = *(s16 *)(arg0 + 0x12) - *(s16 *)(arg0 + 0x22);

        if (*(s16 *)(arg0 + 2) < 8) {
            *(s16 *)(arg0 + 2) += 1;
        }

        if (*(s16 *)(arg0 + 2) < 8) {
            step = *(s16 *)(arg0 + 2);
            *(s16 *)(arg0 + 4) =
                ((((*(s16 *)(arg0 + 0x14) - *(s16 *)(arg0 + 0xC)) *
                   step) /
                  8) + *(s16 *)(arg0 + 0xC));
            *(s16 *)(arg0 + 8) =
                ((((*(s16 *)(arg0 + 0x18) - *(s16 *)(arg0 + 0x10)) *
                   step) /
                  8) + *(s16 *)(arg0 + 0x10));
            *(s16 *)(arg0 + 0x1C) = *(s16 *)(arg0 + 8) - saved_w_minus_pair_x;
            if (*(s16 *)(arg0 + 0x1C) < 0) {
                *(s16 *)(arg0 + 0x1C) = 0;
            }
            *(s16 *)(arg0 + 6) =
                ((((*(s16 *)(arg0 + 0x16) - *(s16 *)(arg0 + 0xE)) *
                   step) /
                  8) + *(s16 *)(arg0 + 0xE));
            *(s16 *)(arg0 + 0xA) =
                ((((*(s16 *)(arg0 + 0x1A) - *(s16 *)(arg0 + 0x12)) *
                   step) /
                  8) + *(s16 *)(arg0 + 0x12));
            *(s16 *)(arg0 + 0x1E) = *(s16 *)(arg0 + 0xA) - saved_h_minus_pair_y;
            if (*(s16 *)(arg0 + 0x1E) < 0) {
                *(s16 *)(arg0 + 0x1E) = 0;
            }
        } else {
            *(s16 *)(arg0 + 4) = *(s16 *)(arg0 + 0x14);
            *(s16 *)(arg0 + 8) = *(s16 *)(arg0 + 0x18);
            *(s16 *)(arg0 + 0x1C) = *(s16 *)(arg0 + 8) - saved_w_minus_pair_x;
            *(s16 *)(arg0 + 6) = *(s16 *)(arg0 + 0x16);
            *(s16 *)(arg0 + 0xA) = *(s16 *)(arg0 + 0x1A);
            *(s16 *)(arg0 + 0x1E) = *(s16 *)(arg0 + 0xA) - saved_h_minus_pair_y;
            *(s16 *)(arg0 + 0) = 3;
        }
    }
    return 1;
}

extern void func_8004C990(u16, u16, u8 *);
extern s16 D_8220D788;
extern u8 D_8220E368[];
s32 func_82201EB4(s32 arg0, u8 *arg1) {
    s32 sp18;
    s32 temp_v1;
    u8 *temp_v0;
    u8 *temp_v0_2;
    temp_v1 = *(s32 *)(arg1 + 0x20);
    switch (arg0) {
    case 0:
        if (temp_v1 == 0) {
            arg1[1] |= 4;
            sp18 = temp_v1;
            func_8004C990(*(u16 *)(arg1 + 0x24), *(u16 *)(arg1 + 0x26), arg1);
        } else {
            *(u16 *)(arg1 + 2) &= 0xFFFD;
        }
        temp_v0 = (u8 *)((u32)&D_8220E368 + temp_v1 * 4);
        *(s16 *)(temp_v0 + 0) = 0;
        *(s16 *)(temp_v0 + 2) = 0;
        *(s16 *)(temp_v0 + 8) = *(s16 *)(arg1 + 8);
        *(s16 *)(temp_v0 + 0xA) = *(s16 *)(arg1 + 0xA);
        break;
    case 1:
        temp_v0_2 = (u8 *)((u32)&D_8220E368 + (2 * temp_v1) * 2);
        if (D_8220D788 < *(s16 *)(temp_v0_2 + 2)) {
            *(s16 *)(arg1 + 8) = *(s16 *)(temp_v0_2 + 0) + *(s16 *)(temp_v0_2 + 8);
            *(s16 *)(arg1 + 0xA) = *(s16 *)(temp_v0_2 + 2) + *(s16 *)(temp_v0_2 + 0xA);
            *(u16 *)(arg1 + 2) |= 2;
        } else {
            *(u16 *)(arg1 + 2) &= 0xFFFD;
        }
        break;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_10FFC0/func_82201FBC.s")

extern u8 D_8220E310[];
extern u8 D_8220E338[];
extern void func_82201FBC(s32, s32, s32, s32);
extern s16 D_8220D788;
extern s16 D_8220E378;
s32 func_822023D8(s32 arg0, u8 *arg1)
{
  typedef struct
  {
    s16 x;
    s16 y;
  } Pair;
  s32 index = *((s32 *) (arg1 + 0x20));
  u8 *p;
  u8 *q;
  s32 offset;
  switch (arg0)
  {
    case 0:
    {
      p = ((u8 *) (&D_8220E378)) + (index * 0x3C);
      *((s16 *) (p + 0x10)) = *((s16 *) (arg1 + 8));
      *((s16 *) (p + 0x12)) = *((s16 *) (arg1 + 0xA));
      *((s16 *) (p + 0x34)) = 0;
      *((s16 *) (p + 0x36)) = 0;
      *((Pair *) (p + 0x1C)) = *((Pair *) (p + 0x10));
    }
 do { } while (0);
      break;

    case 1:
    {
      q = D_8220E310 + (index * 0x14);
      if (q[5] != 2)
      {
        p = ((u8 *) (&D_8220E378)) + (index * 0x3C);
        if (D_8220D788 < (*((s16 *) (p + 0x36))))
        {
          *((s16 *) (arg1 + 8)) = (*((s16 *) (p + 0x1C))) + (*((s16 *) (p + 0x34)));
          *((s16 *) (arg1 + 0xA)) = (*((s16 *) (p + 0x1E))) + (*((s16 *) (p + 0x36)));
          if (q >= D_8220E338)
          {
            offset = 0x24;
          }
          else
          {
            offset = 0x42;
          }
          *((u16 *) (arg1 + 2)) |= 2;
          func_82201FBC((*((s16 *) (arg1 + 8))) + offset, (*((s16 *) (arg1 + 0xA))) + 8, *((s16 *) (p + 0x30)), *((s16 *) (p + 0x32)));
        }
        else
        {
          *((u16 *) (arg1 + 2)) &= 0xFFFD;
        }
      }
      else
      {
        *((u16 *) (arg1 + 2)) &= 0xFFFD;
      }
    }
      break;

  }

  return 0;
}

s32 func_82202534(s32 arg0, u8 *arg1) {
    s32 index = *(s32 *)(arg1 + 0x20);
    u8 *p = (u8 *)&D_8220E378 + index * 0x3C;

    switch (arg0) {
        case 0:
            *(s16 *)(p + 0x24) = *(s16 *)(arg1 + 8);
            *(s16 *)(p + 0x26) = *(s16 *)(arg1 + 0xA);
            break;

        case 1:
            if (D_8220E310[index * 0x14 + 5] != 2) {
                if (D_8220D788 < *(s16 *)(p + 0x36)) {
                    *(s16 *)(arg1 + 8) = *(s16 *)(p + 0x24) + *(s16 *)(p + 0x34);
                    *(s16 *)(arg1 + 0xA) = *(s16 *)(p + 0x26) + *(s16 *)(p + 0x36);
                    *(u16 *)(arg1 + 2) |= 2;
                } else {
                    *(u16 *)(arg1 + 2) &= ~2;
                }
            } else {
                *(u16 *)(arg1 + 2) &= ~2;
            }
            break;
    }

    return 0;
}

const f32 D_8220E0D0[1] = { 0.001f };

s32 func_82202628(s32 arg0) {
    s32 var_v1;

    var_v1 = 5;
    switch (arg0) {
        case 1:
            var_v1 = 11;
            break;
        case 2:
            var_v1 = 7;
            break;
        case 3:
            var_v1 = 1;
            break;
        case 4:
            var_v1 = 15;
            break;
        case 5:
            var_v1 = 9;
            break;
        case 6:
            var_v1 = 13;
            break;
        case 7:
            var_v1 = 3;
            break;
    }

    return var_v1;
}
extern s32 func_82202628(s32 arg0);
s32 func_8220268C(s32 arg0, s32 arg1) {
    s32 sp1C = 4;

    switch (arg0) {
        case 1:
            sp1C = 10;
            break;
        case 2:
            sp1C = 6;
            break;
        case 3:
            sp1C = 0;
            break;
        case 4:
            sp1C = 14;
            break;
        case 5:
            sp1C = 8;
            break;
        case 6:
            sp1C = 12;
            break;
        case 7:
            sp1C = 2;
            break;
    }

    if (arg1 != 0) {
        sp1C = func_82202628(arg0);
    }

    return sp1C;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_10FFC0/func_82202718.s")

extern void func_800504BC(s16 *arg0);
extern u8 D_8220E315[];
extern u8 D_8220E36A[];

s32 func_82202A84(s32 arg0, u8 *arg1) {
    void *sp1C; s32 temp_v1; void *temp_v0; s32 sp30; s32 pad0; s32 pad1;
    temp_v1 = *(s32 *)(arg1 + 0x20);
    if (arg0 != 0) {
        if (arg0 == 1) {
            if (D_8220E315[temp_v1 * 0x14] != 2) {
                temp_v0 = (u8 *)&D_8220E378 + (temp_v1 * 0x3C);
                sp1C = temp_v0;
                sp30 = temp_v1;
                func_800504BC((s16 *)((u8 *)temp_v0 + 0x30));
                *(s16 *)((u8 *)temp_v0 + 0x30) = *(s16 *)((u8 *)arg1 + 8) + *(s16 *)((u8 *)temp_v0 + 0x30) + 9;
                *(s16 *)((u8 *)temp_v0 + 0x32) = *(s16 *)((u8 *)arg1 + 0xA) + *(s16 *)((u8 *)temp_v0 + 0x32) + 0xE;
                if (D_8220D788 < *(s16 *)(D_8220E36A + (sp30 * 4))) {
                    *(u16 *)((u8 *)arg1 + 2) = *(u16 *)((u8 *)arg1 + 2) | 2;
                } else {
                    *(u16 *)((u8 *)arg1 + 2) = *(u16 *)((u8 *)arg1 + 2) & 0xFFFD;
                }
            } else {
                *(u16 *)((u8 *)arg1 + 2) = *(u16 *)((u8 *)arg1 + 2) & 0xFFFD;
            }
        }
    }
    return 0;
}

extern u16 D_8220E4C0;
s32 func_82202B80(s32 arg0, u8 *arg1) {
    switch (arg0) {
    case 0:
        *(u16 *)(arg1 + 2) &= 0xFFFD;
        break;
    case 1:
        if (D_8220E4C0 & 4) {
            *(u16 *)(arg1 + 2) |= 2;
        } else {
            *(u16 *)(arg1 + 2) &= 0xFFFD;
        }
        break;
    default:
        break;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_10FFC0/func_82202BE4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_10FFC0/func_82202E0C.s")

extern u8 D_8220E310[];
extern u8 *func_8004C874(s32, s32);
extern void func_8004C54C(s32, void *);
typedef struct F82202FC8_Record { u8 pad0[5]; u8 type; u8 pad6[2]; u8 payload[12]; } F82202FC8_Record;
extern u16 D_8220E4C0;
s32 func_82202FC8(s32 arg0, u8 *arg1) {
    s32 index = *(s32 *)(arg1 + 0x20);
    u8 *data = NULL;
    u8 *record;
    s32 type;

    switch (arg0) {
        case 0:
            break;
        case 1:
            record = D_8220E310 + index * 0x14;
            type = record[5];
            switch (type) {
                case 0:
                case 3:
                    data = record + 8;
                    break;
                case 4:
                case 5:
                    data = func_8004C874(0x17, 0x40);
                    break;
            }
            if (data != NULL) {
                func_8004C54C(0x15, data);
                if (D_8220E4C0 & 8) {
                    *(u16 *)(arg1 + 2) |= 2;
                } else {
                    *(u16 *)(arg1 + 2) &= 0xFFFD;
                }
            } else {
                *(u16 *)(arg1 + 2) &= 0xFFFD;
            }
            break;
    }
    return 0;
}

extern u8 D_8220EB60[];
extern char D_8220E0C0[];
int sprintf(char *, const char *, ...);
extern void func_8004C54C(s32, void *);
extern u8 * func_8004C874(s32, s32);
extern u8 D_8220E310[];
extern u16 D_8220E4C0;
s32 func_822030BC(s32 arg0, u8 *arg1) {
    s32 index = *(s32 *)(arg1 + 0x20);
    u8 *data = NULL;
    u8 *record;
    s32 type;

    switch (arg0) {
        case 0:
            break;
        case 1:
            record = D_8220E310 + index * 0x14;
            type = record[5];
            switch (type) {
                case 0:
                case 3:
                    sprintf(D_8220EB60, D_8220E0C0, *(u16 *)(record + 6));
                    data = D_8220EB60;
                    break;
                case 4:
                case 5:
                    data = func_8004C874(0x17, 0x41);
                    break;
            }
            if (data != NULL) {
                func_8004C54C(0x16, data);
                if (D_8220E4C0 & 8) {
                    *(u16 *)(arg1 + 2) |= 2;
                } else {
                    *(u16 *)(arg1 + 2) &= 0xFFFD;
                }
            } else {
                *(u16 *)(arg1 + 2) &= 0xFFFD;
            }
            break;
    }
    return 0;
}

extern u8 *D_8220E4D0[];
s32 func_822031D0(s32 arg0, u8 *arg1) {
    s32 temp_v0 = *(s32 *)(arg1 + 0x20);
    switch (arg0) {
    case 0:
        *(u16 *)(arg1 + 2) &= 0xFFFD;
        D_8220E4D0[temp_v0] = arg1;
        break;
    case 1:
        break;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_10FFC0/func_82203210.s")

extern Gfx *D_800D0510;
s32 func_8220336C(s32 arg0, s32 arg1) { gDPPipeSync(D_800D0510++); gDPSetEnvColor(D_800D0510++, 0xFF, 0xFF, 0, 0xFF); return 0; }

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_10FFC0/func_822033BC.s")

/* mkdraft:func_822037E4 begin */
extern void Font_EnableTwoCycleTexturing();
extern void func_8004972C();



void func_822037E4(void) {
    u8 **slot;
    u8 *record;
    s32 flag; // FAKE: never read; diff score 18 without it.
    s32 result;
    s32 dirty;
    u8 *text;
    u8 *style; // FAKE: never read; diff score 10 without it and its assignment.
    u8 *old_color;
    u8 *new_color;
    s32 font_id;

    if (((*(u16 *)((u8 *)&D_8220E4C0)) & 8) == 0) {
        return;
    }
    func_800498C4();
    record = D_8220E310; slot = D_8220E4D0;
    do {
        text = *slot;
        style = text + 0x28; // FAKE: same value as new_color below.
        old_color = text + 0x2C;
        new_color = text + 0x28;
        dirty = 0;
        font_id = 0;
        switch (record[5]) {
        case 0: break;
        case 4: font_id = (s32)func_8004C874(23, 25); break;
        case 3: font_id = (s32)func_8004C874(23, 26); break;
        case 5: font_id = (s32)func_8004C874(23, 27); break;
        }
        if (font_id != 0) {
            Font_EnableTwoCycleTexturing();
            func_800496A4(*(u16 *)(text + 0x24), 1);
            func_8004989C(*(s8 *)(text + 0x26));
            func_8004972C(new_color[0], new_color[1], new_color[2], new_color[3]);
            if (*(u32 *)old_color != *(u32 *)new_color) {
                dirty = 1;
                Font_EnableTwoCycleTexturing();
                func_800497E4(old_color[0], old_color[1], old_color[2], old_color[3]);
            }
            if (font_id != 0) {
                result = func_80050518(text[0x27]);
                switch (result) {
                case 2:
                    func_800495BC(*(s16 *)(text + 8), *(s16 *)(text + 0xA), font_id);
                    break;
                case 0:
                    func_800495F8(*(s16 *)(text + 8), *(s16 *)(text + 0xA), 1, font_id);
                    break;
                case 1:
                    func_800495F8(*(s16 *)(text + 8), *(s16 *)(text + 0xA), 2, font_id);
                    break;
                }
            }
            if (dirty != 0) {
                Font_DisableTwoCycleTexturing();
            }
        }
        record += 0x14;
    } while (++slot != (u8 **)&D_8220E4E0);
    func_800499EC();
}
/* mkdraft:func_822037E4 end */

extern void *StageContext_GetCurrentImage(void);
extern void BgStage_DrawFrame(void);
extern void func_81600F0C(s32, s16, s16, s16, s32);
extern void Gfx_SetScissorRect(Gfx **, s32, s32, s16, s32);
extern void func_800503A4(u8 *);
extern void func_822037E4(void);
extern s32 func_80008648(void);
extern s32 D_8220D770;
extern void *D_8220E360;
extern u8 *D_8220E364;
extern s16 D_8220E4CA;
extern s16 D_8220E4CC;
extern s16 D_8220E4CE;
extern Gfx * D_800D0510;
extern u8 D_8220E4C8[];
void func_822039C8(void) {
    s32 pad;
    u8 *image;

    image = StageContext_GetCurrentImage();
    BgStage_DrawFrame();
    func_81600F0C(((s32 *)D_8220E360)[1], *(s16 *)D_8220E4C8, D_8220E4CA, D_8220E4CC, D_8220E4CE);
    Gfx_SetScissorRect(&D_800D0510, 0, 0, *(s16 *)(image + 4), *(u16 *)(image + 6));
    func_800503A4(D_8220E364);
    func_800503A4(*(u8 **)((u8 *)D_8220E360 + 0x1C));
    func_822037E4();
    func_80008648();
    D_8220D770 += 1;
}

extern s32 D_8220E4B8, D_8220D784;

void func_82203A84(void) {
    D_8220E4B8 = 0;
    D_8220D784 = 0;
}

extern s32 D_8220D848;
extern s32 func_82201834(s16 *);
extern s32 func_82201C14(void);
extern s16 D_8220E378;
extern u8 D_8220E468[];
s32 func_82203A98(void) {
    s16 *p;
    s32 result = 0;

    if (D_8220E4B8 < 0x14) {
        D_8220E4B8++;
    }
    p = &D_8220E378;
    if (D_8220E4B8 == D_8220D848) {
        do {
            func_82201834(p);
            p += 0x1E;
        } while (p != (s16 *)D_8220E468);
    } else if (D_8220D848 < D_8220E4B8) {
        if (func_82201C14() != 0) {
            result = 1;
        }
    }
    return result;
}

extern void *D_80087200; extern void func_800226C0(s32);
s32 func_82203B3C(void) { s32 result = 0; if ((*(u16 *)((u8 *)D_80087200 + 8) & 0x8000) != 0) { func_800226C0(0x33); result = 1; } else if ((*(u16 *)((u8 *)D_80087200 + 8) & 0x4000) != 0) { func_800226C0(3); result = -1; } return result; }

extern s32 D_8220D784;
extern s32 D_8220E4BC;
extern u8 D_8220E468[];
extern u8 D_8220E490[];
extern s32 func_82201D08(void *);
void func_82203B98(void) {
    D_8220E4BC = 0;
    func_82201D08(D_8220E468);
    func_82201D08(D_8220E490);
    D_8220D784 = 1;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/17/fragment17_10FFC0/func_82203BD8.s")

extern void func_822014D8();
extern void StageFade_StartFromTransparent();
extern void func_80035424();
void func_82203E40(void) { func_822014D8(); StageFade_StartFromTransparent(5); func_80035424(15); }

/* func_82203E70 is still GLOBAL_ASM, but its .s is hand-maintained (not the
 * splat-generated asm/us/nonmatchings/.../func_82203E70.s) so that it can
 * also carry jtbl_8220E10C's first entry (4 bytes) in a .late_rodata block
 * ahead of its .text. That word has to land immediately after
 * func_8220268C's own compiler-generated jump table (jtbl_8220E0F0) to
 * satisfy this fragment's SUBALIGN(16); a plain C global here would instead
 * be emitted by IDO BEFORE func_8220268C's switch table (IDO always emits
 * named/array rodata ahead of switch-table "late" rodata within one
 * compilation), landing at the wrong address. Placing it in a GLOBAL_ASM
 * .late_rodata block instead makes asm-processor position it correctly:
 * after all first-pass rodata and after func_8220268C's own late-rodata
 * jump table, matching retail. jtbl_8220E10C's remaining entries keep
 * coming from the unmodified data blob at their real retail addresses. */
#pragma GLOBAL_ASM("hand_asm/fragments/17/func_82203E70_manual.s")

extern void StageFade_StartFromOpaque(s32);
extern void func_800086A4(s32);
extern void func_80064D28();
extern s32 func_822015B4(void);
extern void func_82201B70();
extern void func_822039C8();
s32 func_82203E70(s32);

void func_8220402C(void) {
    s32 temp_v0;
    s32 var_s0;

    var_s0 = 0;
    func_800086A4(2);
    StageFade_StartFromOpaque(5);
    do {
        func_80064D28();
        func_822015B4();
        func_82201B70();
        func_822039C8();
        temp_v0 = func_82203E70(var_s0);
        var_s0 = temp_v0;
    } while (temp_v0 != 5);
}
#endif
