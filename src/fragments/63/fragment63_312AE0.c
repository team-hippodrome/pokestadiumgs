#include "global.h"


#ifdef VERSION_US
void func_87E0F170(void) {
    extern u32 D_87E1EBB8;
    u8 *base = (u8 *)(u32)D_87E1EBB8;
    *(s32 *)base = 0;
    *(u16 *)(base + 6) = 0;
    base[4] = 0;
}

extern u32 D_87E1EBB8;
void func_87E0F188(s32 arg0) { u8 *base = (u8 *)(u32)D_87E1EBB8; if ((*(s32 *)base != arg0) && ((*(s8 *)(base + 4) & 1) == 0)) { *(s32 *)base = arg0; *(s16 *)(base + 6) = 0; *(u8 *)(base + 4) = 1; } }

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_312AE0/func_87E0F1C4.s")

extern void Audio_PlayDefaultSound(s32);
void func_87E0F288(void *arg0, s32 arg1) {
    void *state = arg0;
    s32 value = *(s32 *)((u8 *)state + 0xC);
    if (((value << 3) >= 0) && ((arg1 << 3) < 0)) {
        Audio_PlayDefaultSound(0xCF01);
        value = *(s32 *)((u8 *)state + 0xC);
    }
    if (((value << 2) >= 0) && ((arg1 << 2) < 0)) {
        Audio_PlayDefaultSound(0xCF02);
        value = *(s32 *)((u8 *)state + 0xC);
    }
    if (((value << 1) >= 0) && ((arg1 << 1) < 0)) {
        Audio_PlayDefaultSound(0xCF01);
        value = *(s32 *)((u8 *)state + 0xC);
    }
    *(s32 *)((u8 *)state + 0xC) = value | arg1;
    *(s32 *)((u8 *)state + 0x1C) = 0;
}

/* mkdraft:func_87E0F33C begin */
extern void *D_87F119DC;
extern f32 D_80088E50[];
extern void func_87E0F288(void *, s32);



void func_87E0F33C(void) {
    s32 rounded;
    f32 angle;
    f32 level;

    // Bit 30 of the flags word, shifted into the sign bit as func_87E0F288 above tests
    // bits 28..30. An `& 0x40000000` test instead shares that constant with the
    // 0x40000000 call argument below, which loads a1 in the entry block rather than at
    // 87E0F4B8.
    if ((*(s32 *)((u8 *)D_87F119DC + 0xC) << 1) < 0) {
        if (*(s32 *)((u8 *)D_87F119DC + 0x1C) >= 5) {
            *(s16 *)((u8 *)D_87F119DC + 0x46) = 0;
            *(s32 *)((u8 *)D_87F119DC + 0xC) &= ~0x40000000;
            *(s32 *)((u8 *)D_87F119DC + 0x1C) = 0;
        } else {
            angle = ((f32)*(s32 *)((u8 *)D_87F119DC + 0x1C) / 4) * 90.0f * 182.04167f;
            if (angle >= 0.0f) {
                rounded = (s32)(angle + 0.5f);
            } else {
                rounded = (s32)(angle - 0.5f);
            }
            // The table entry is bound to a local so both scaled terms read it from a
            // register: the retail object loads it at 87E0F434, then multiplies
            // (mul.s at 87E0F438). Inlined, the two mul.s results swap registers.
            {
                f32 cos_value = D_80088E50[(rounded & 0xFFFF) >> 4];
                angle = 90.0f * cos_value * 182.04167f;
            }
            if (angle >= 0.0f) {
                *(s16 *)((u8 *)D_87F119DC + 0x46) = (s16)(s32)(angle + 0.5f);
            } else {
                *(s16 *)((u8 *)D_87F119DC + 0x46) = (s16)(s32)(angle - 0.5f);
            }
        }
    }
    if (*(s32 *)((u8 *)D_87F119DC + 0xC) & 0x20000000) {
        if (*(s32 *)((u8 *)D_87F119DC + 0x1C) >= 5) {
            *(s32 *)((u8 *)D_87F119DC + 0xC) &= ~0x20000000;
            func_87E0F288(D_87F119DC, 0x40000000);
        } else {
            angle = ((f32)*(s32 *)((u8 *)D_87F119DC + 0x1C) / 4) * 90.0f * 182.04167f;
            if (angle >= 0.0f) {
                rounded = (s32)(angle + 0.5f);
            } else {
                rounded = (s32)(angle - 0.5f);
            }
            // The table entry is bound to a local so the subtraction from 1.0f starts
            // the scaled expression: the retail object loads the entry at 87E0F55C and
            // materializes 1.0f at 87E0F560.
            {
                f32 cos_value = D_80088E50[(rounded & 0xFFFF) >> 4];
                angle = ((f32)1 - cos_value) * 90.0f * 182.04167f;
            }
            if (angle >= 0.0f) {
                *(s16 *)((u8 *)D_87F119DC + 0x46) = (s16)(s32)(angle + 0.5f);
            } else {
                *(s16 *)((u8 *)D_87F119DC + 0x46) = (s16)(s32)(angle - 0.5f);
            }
        }
    }
    if (*(s32 *)((u8 *)D_87F119DC + 0xC) & 0x10000000) {
        *(f32 *)((u8 *)D_87F119DC + 0x5C) += 0.25f;
    } else {
        *(f32 *)((u8 *)D_87F119DC + 0x5C) -= 0.25f;
    }
    level = *(f32 *)((u8 *)D_87F119DC + 0x5C);
    if (level > 1.0f) {
        *(f32 *)((u8 *)D_87F119DC + 0x5C) = 1.0f;
        level = *(f32 *)((u8 *)D_87F119DC + 0x5C);
    }
    if (level < 0.0f) {
        *(f32 *)((u8 *)D_87F119DC + 0x5C) = 0.0f;
        level = *(f32 *)((u8 *)D_87F119DC + 0x5C);
    }
    *(f32 *)((u8 *)D_87F119DC + 0x58) = level;
    *(f32 *)((u8 *)D_87F119DC + 0x54) = level;
}
/* mkdraft:func_87E0F33C end */

extern void *D_8009491C;
extern Gfx *D_800D0510;
extern s32 func_8004C990(s32, s32);
extern u8 *func_8004CA60(u8 *);
extern void GeoRender_ApplyMaterialState(void);
void func_87E0F664(s32 arg0, s32 arg1) {
    void *temp_v0;
    u8 *context;

    if (arg0 == 5) {
        context = (u8 *)D_8009491C;
        temp_v0 = *(void **)(context + 0x14);
        gDPPipeSync(D_800D0510++);
        gDPSetCombine(D_800D0510++, 0xFCFFFFFF, 0xFFFCF238);
        gSPSegment(D_800D0510++, 0xF,
                   func_8004CA60((u8 *)func_8004C990(0x170, 0)));
        gSPDisplayList(D_800D0510++, *(void **)((u8 *)temp_v0 + 0x648));
        GeoRender_ApplyMaterialState();
    }
}

void func_87E0F740(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 4) = arg1;
    *(s32 *)arg0 = 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_312AE0/func_87E0F74C.s")

extern u32 func_8003570C(void);
void func_87E0FBB4(s32 arg0, u8 *arg1, u32 arg2, u32 arg3) {
    if (arg0 != 0 && (*(u32 *)(arg1 + 0x14) & 1)) {
        *(u32 *)(arg1 + 8) = (++*(u32 *)(arg1 + 4) % (arg3 * arg2)) / arg3;
        if (arg2 == *(u32 *)(arg1 + 8) + 1) {
            *(u32 *)(arg1 + 0x14) &= ~1;
        }
    } else {
        *(u32 *)(arg1 + 8) = 0;
        *(u32 *)(arg1 + 0x14) &= ~1;
        if (func_8003570C() % 61 == 0) {
            *(u32 *)(arg1 + 4) = 0;
            *(u32 *)(arg1 + 0x14) |= 1;
        }
    }
}

extern u32 func_8003570C(void);
void func_87E0FC90(s32 arg0, u8 *arg1, void *arg2, u32 arg3, u32 arg4) {
    struct Pair { u32 *data; u32 count; } *entry;
    u32 frame;
    if (arg0 != 0 && (*(u32 *)(arg1 + 0x14) & 2)) {
        entry = (struct Pair *)arg2 + *(u32 *)(arg1 + 0xC);
        frame = ++*(u32 *)arg1 % (arg4 * entry->count) / arg4;
        *(u32 *)(arg1 + 0x10) = entry->data[frame];
        if (entry->count == frame + 1) {
            *(u32 *)(arg1 + 0x14) &= ~2;
        }
    } else {
        *(s32 *)(arg1 + 0x10) = -1;
        if (func_8003570C() % 21 == 0) {
            *(u32 *)arg1 = 0;
            *(u32 *)(arg1 + 0x14) |= 2;
            *(u32 *)(arg1 + 0xC) = func_8003570C() % arg3;
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_312AE0/func_87E0FDB4.s")

extern Gfx *D_800D0510;
extern u8 D_80094E38[];
extern u8 D_80094F50[];
extern void func_800504BC(s16 *);
extern s32 func_8004C990(s32, s32);
extern s32 func_8004D1FC(u8 *);
extern void func_80044270(s16, s16, s16, s16, s32, s32, s32, s32, s32);
void func_87E0FFA0(void *arg0, s32 arg1) {
    s32 temp_v0;
    s32 sp40;
    s16 coords[2];

    if (arg1 != -1) {
        func_800504BC(coords);
        gSPDisplayList(D_800D0510++, D_80094E38);
        temp_v0 = func_8004C990(*(u16 *)((u8 *)arg0 + 0x24), arg1);
        sp40 = temp_v0;
        func_8004D1FC((u8 *)(u32)temp_v0);
        func_80044270((s16)(*(s16 *)((u8 *)arg0 + 8) + coords[0]),
                      (s16)(*(s16 *)((u8 *)arg0 + 0xA) + coords[1]),
                      *(s16 *)((u8 *)(u32)sp40),
                      *(s16 *)((u8 *)(u32)sp40 + 2),
                      0, 0, 0x400, 0x400, 0);
        gSPDisplayList(D_800D0510++, D_80094F50);
    }
}

/* mkdraft:func_87E10094 begin */
extern s32 D_87E1A800[];
extern s32 D_87E1A81C[];
extern void func_87E0FFA0(void *arg0, s32 arg1);
extern u32 D_87E1EBB8;

void func_87E10094(s32 arg0, void *arg1) {
    s32 value = -1;
    switch (arg0) {
      case 0: *(u16 *)((u8 *)arg1 + 2) &= ~2; break;
      case 1:
        switch (*(u32 *)((u8 *)arg1 + 0x20)) {
            case 0:
                value = D_87E1A800[*(s32 *)((u8 *)(u32)D_87E1EBB8 + 0x1EC)];
                break;
            case 1:
                value = D_87E1A81C[*(s32 *)((u8 *)(u32)D_87E1EBB8 + 0x1EC)];
                break;
            case 2:
                value = *(s32 *)((u8 *)(u32)D_87E1EBB8 + 0x1F4);
                break;
        }
        func_87E0FFA0(arg1, value);
        break;
    }
}
/* mkdraft:func_87E10094 end */

extern s32 D_87E1A8A0[];
extern s32 D_87E1A8BC[];
extern void func_87E0FFA0(void *arg0, s32 arg1);
extern u32 D_87E1EBB8;
void func_87E10154(s32 arg0, void *arg1) {
    s32 value = -1;
    switch (arg0) {
      case 0: *(u16 *)((u8 *)arg1 + 2) &= ~2; break;
      case 1:
        switch (*(u32 *)((u8 *)arg1 + 0x20)) {
            case 0:
                value = D_87E1A8A0[*(s32 *)((u8 *)(u32)D_87E1EBB8 + 0x204)];
                break;
            case 1:
                value = D_87E1A8BC[*(s32 *)((u8 *)(u32)D_87E1EBB8 + 0x204)];
                break;
            case 2:
                value = *(s32 *)((u8 *)(u32)D_87E1EBB8 + 0x20C);
                break;
        }
        func_87E0FFA0(arg1, value);
        break;
    }
}

extern s32 D_87E1A9A0[];
extern s32 D_87E1A9BC[];
extern void func_87E0FFA0(void *arg0, s32 arg1);
extern u32 D_87E1EBB8;
void func_87E10214(s32 arg0, void *arg1) {
    s32 value = -1;
    switch (arg0) {
      case 0: *(u16 *)((u8 *)arg1 + 2) &= ~2; break;
      case 1:
        switch (*(u32 *)((u8 *)arg1 + 0x20)) {
            case 0:
                value = D_87E1A9A0[*(s32 *)((u8 *)(u32)D_87E1EBB8 + 0x21C)];
                break;
            case 1:
                value = D_87E1A9BC[*(s32 *)((u8 *)(u32)D_87E1EBB8 + 0x21C)];
                break;
            case 2:
                value = *(s32 *)((u8 *)(u32)D_87E1EBB8 + 0x224);
                break;
        }
        func_87E0FFA0(arg1, value);
        break;
    }
}

/* mkdraft:func_87E102D4 begin */
extern void GfxRect_DrawTextured(s16 x, s16 y, s16 width, s16 height, s16 s, s16 t, s16 dsdx, s16 dtdy, s32 cycle);

// Integer return type: the final gSPDisplayList keeps the display-list head in v0 and its
// incremented value in t1. The body itself has no return statement, so no value is produced;
// a void declaration colours the head v1 and its increment t9 instead.


s32 func_87E102D4(s32 arg0, u8 *arg1) {
    s16 sp58[4];
    u16 *obj;
    s32 sp50;

    switch (arg0) {
    case 0:
        *(u16 *)(arg1 + 2) &= 0xFFFD;
        return;
    case 1:
        if (((1 << *(s32 *)(arg1 + 0x20)) & *(u8 *)((u8 *)*(void **)((u8 *)(u32)D_87E1EBB8 + 0x2C4) + 0x2182)) != 0) {
            sp50 = *(s32 *)(arg1 + 0x20) + ((((1 << *(s32 *)(arg1 + 0x20)) & *(u8 *)((u8 *)*(void **)((u8 *)(u32)D_87E1EBB8 + 0x2C4) + 0x2182)) != 0) ? 6 : 2);
            func_800504BC(sp58);
            gSPDisplayList(D_800D0510++, D_80094E38);
            obj = (u16 *)func_8004C990(*(u16 *)(arg1 + 0x24), sp50);
            func_8004D1FC((u8 *)obj);
            GfxRect_DrawTextured((s16) (*(s16 *)(arg1 + 8) + sp58[0]), (s16) (*(s16 *)(arg1 + 0xA) + sp58[1]),
                                 (s16) (((f32) (u32)obj[0] * 0.6f >= 0.0f) ? (s32) ((f32) (u32)obj[0] * 0.6f + 0.5f) : (s32) ((f32) (u32)obj[0] * 0.6f - 0.5f)),
                                 (s16) (((f32) (u32)obj[1] * 0.6f >= 0.0f) ? (s32) ((f32) (u32)obj[1] * 0.6f + 0.5f) : (s32) ((f32) (u32)obj[1] * 0.6f - 0.5f)),
                                 0, 0, 0x6AB, 0x6AB, 0);
            gSPDisplayList(D_800D0510++, D_80094F50);
        }
        return;
    }
}
/* mkdraft:func_87E102D4 end */

void func_87E10500(s32 arg0, u8 *arg1) { if ((arg0 != 0) && (arg0 == 1)) { *(s16 *)(arg1 + 0x26) = *(s8 *)((u8 *)(u32)D_87E1EBB8 + 0x938); } }

void func_87E10524(void *arg0, s32 (*arg1)(s32, void *), s32 arg2) {
    void *temp_s3;
    void *var_s0;

    temp_s3 = (*(void **)((u8 *)(arg0) + (0x18)));
    var_s0 = temp_s3;
    if (temp_s3 != NULL) {
        do {
            if (arg1 != NULL) {
                arg1(arg2, var_s0);
            }
            func_87E10524(var_s0, arg1, arg2);
            var_s0 = (*(void **)((u8 *)(var_s0) + (0x14)));
        } while (var_s0 != temp_s3);
    }
}

s32 func_87E10598(s32 arg0, void *arg1) {
    u8 *p = arg1;
    s32 value;

    value = (arg0 != 0xFF) ? 0 : 0xFF;
    switch (p[0]) {
        case 3:
            p[0x2F] = arg0;
            break;
        case 4:
            p[0x2B] = value;
            p[0x2F] = value;
            break;
        case 2:
            p[0x3F] = value;
            p[0x43] = value;
            p[0x47] = value;
            break;
    }
}

extern s32 func_87E10598(s32, void *);
extern s32 func_8004C990(s32, s32);
extern s32 D_87E1A5EC[];
extern s32 D_87E1A620[];
extern s32 D_87E1A684[];
extern s32 D_87E1A6E8[];
void func_87E105FC(void *arg0, u8 arg1) {
    func_87E10524(arg0, func_87E10598, arg1);
}

extern void func_8004C8C0(s32);
void func_87E10628(void) { func_8004C8C0(0x164); func_8004C8C0(0x165); func_8004C8C0(0x171); func_8004C8C0(0x170); func_8004C8C0(0x1B5); func_8004C8C0(0x1B8); }

extern void *func_87F025B8(void *, void *);
extern void func_8003F1DC(void *);
extern void func_8003F114(void *, s32, s32, s32);
extern void func_87E0F33C(void);

void func_87E10670(void) {
    u8 *entry;
    u8 *node;
    s32 i;

    for (i = 0; i < 4; i++) {
        entry = func_87F025B8((u8 *)D_87E1EBB8 + 0x2C8, func_87E0F33C);
        if (entry != NULL) {
            node = entry + 0x24;
            func_8003F1DC(node);
            func_8003F114(node, 0, -1, *(s32 *)((u8 *)D_87E1EBB8 + 0x90C));
            *(f32 *)(entry + 0x48) = i * 44.0f + 96.0f + -160.0f;
            *(f32 *)(entry + 0x4C) = -38.0f;
            *(f32 *)(entry + 0x50) = 0.0f;
            *(f32 *)(entry + 0x5C) = 0.0f;
            *(f32 *)(entry + 0x58) = 0.0f;
            *(f32 *)(entry + 0x54) = 0.0f;
        }
    }
}

extern void func_87F02684(s32);
void func_87E1078C(void) {
    func_87F02684(D_87E1EBB8 + 712);
}

extern s32 D_87E1AA4C;
extern u8 D_87E1EBA0;
extern s32 main_pool_get_available(void);
extern s32 MainPool_AllocState(s32, s32);
extern void MainPool_FinalizeAllocation(s32);
extern s32 process_geo_layout(s32, s32 *);
extern s32 func_8004C990(s32, s32);
extern s32 func_87F08DF8(void *, f32, f32, s32);
extern void func_87F0252C(void *, void *, void *, s32);
void func_87E107B4(void *arg0) {
    void *sp20;
    s32 sp28;

    sp28 = MainPool_AllocState(main_pool_get_available(), 0);
    *(s32 *)((u8 *)arg0 + 0x90c) = process_geo_layout(sp28, &D_87E1AA4C);
    MainPool_FinalizeAllocation(sp28);
    *(s32 *)((u8 *)arg0 + 0x910) = func_87F08DF8((void *)func_8004C990(0x170, 0), 0.0f, 25.0f, 0x0f000000);
    sp20 = (u8 *)arg0 + 0x2c8;
    func_87F0252C(&D_87E1EBA0, sp20, (u8 *)arg0 + 0x2dc, 4);
    *(s32 *)((u8 *)arg0 + 0x930) = 0;
    *(s32 *)((u8 *)arg0 + 0x92c) = 0;
    *(s32 *)((u8 *)arg0 + 0x928) = 0;
    *(s32 *)((u8 *)arg0 + 0x924) = 0;
    *(s32 *)((u8 *)arg0 + 0x920) = 0;
    *(s32 *)((u8 *)arg0 + 0x91c) = 0;
    *(s32 *)((u8 *)arg0 + 0x914) = 0;
    *(s32 *)((u8 *)arg0 + 0x918) = 0;
    *(s32 *)((u8 *)arg0 + 0x4a0) = (s32)sp20;
    *(s32 *)((u8 *)arg0 + 0x62c) = (s32)sp20;
    *(s32 *)((u8 *)arg0 + 0x7b8) = (s32)sp20;
    *(s32 *)((u8 *)arg0 + 0x314) = (s32)sp20;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_312AE0/func_87E1087C.s")

extern void func_87F0A6C8(s32, s32, s32 *, s32 *);
extern void func_87F0AA80(s32, s32, s32 *);
typedef struct TreeNode_80050428 TreeNode_80050428;
void *func_87F0AB08(TreeNode_80050428 *, s32, void (*)(s32, u8 *), void *);
extern u8 D_87E1A5D0;
extern u8 D_87E1A5D4;
extern u8 D_87E1A5E4;
void func_87E1097C(s32 *arg0, s32 arg1) {
    if (arg1 == 0xE3) {
        func_87F0A6C8(*arg0, 0x44425F43, &D_87E1A5D0, &D_87E1A5D4);
        func_87F0AA80(*arg0, 0x44425F4D, &D_87E1A5E4);
        func_87F0AB08((TreeNode_80050428 *)*arg0, 0x44425F50, func_87E10500, NULL);
    }
}

void func_87E109FC(s32 *arg0, s32 arg1) {
    switch (arg1) {
        case 149:
            func_87F0AB08((TreeNode_80050428 *)*arg0, 0x504C4D31, func_87E10094, (void *)0); // 'PLM1'
            func_87F0AB08((TreeNode_80050428 *)*arg0, 0x50524D31, func_87E10094, (void *)1); // 'PRM1'
            func_87F0AB08((TreeNode_80050428 *)*arg0, 0x504D4D31, func_87E10094, (void *)2); // 'PMM1'
            func_87F0AB08((TreeNode_80050428 *)*arg0, 0x424C4D31, func_87E10154, (void *)0); // 'BLM1'
            func_87F0AB08((TreeNode_80050428 *)*arg0, 0x42524D31, func_87E10154, (void *)1); // 'BRM1'
            func_87F0AB08((TreeNode_80050428 *)*arg0, 0x424D4D31, func_87E10154, (void *)2); // 'BMM1'
            break;
        case 150:
            func_87F0AB08((TreeNode_80050428 *)*arg0, 0x4B4C4D31, func_87E10214, (void *)0); // 'KLM1'
            func_87F0AB08((TreeNode_80050428 *)*arg0, 0x4B524D31, func_87E10214, (void *)1); // 'KRM1'
            func_87F0AB08((TreeNode_80050428 *)*arg0, 0x4B4D4D31, func_87E10214, (void *)2); // 'KMM1'
            break;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_312AE0/func_87E10B30.s")

void func_87E10E64(s32 arg0) {
    if ((arg0 >= -1) && (arg0 < 2) && (arg0 != (*(s32 *)((u8 *)(D_87E1EBB8) + (8))))) {
        (*(s32 *)((u8 *)(D_87E1EBB8) + (8))) = arg0;
        func_87E0F170();
    }
}

extern void func_87E1078C(void);
extern u32 D_87E1EBB8;
void func_87E10EA8(s32 arg0) { if (arg0 >= -1 && arg0 < 50) { s32 sentinel = 5; s32 current = *(s32 *)((u8 *)(u32)D_87E1EBB8 + 0xC); if (arg0 != current) { if (arg0 == sentinel) { if (sentinel == current) { sentinel = current; } else { func_87E10670(); } } else { func_87E1078C(); } *(s32 *)((u8 *)(u32)D_87E1EBB8 + 0xC) = arg0; func_87E0F170(); } } }

void func_87E10F2C(s32 arg0) {
    if ((arg0 >= -1) && (arg0 < 4)) {
        (*(s32 *)((u8 *)(D_87E1EBB8) + (0x10))) = arg0;
    }
}

void func_87E10F50(s32 arg0) {
    if ((arg0 >= -1) && (arg0 <= 0)) {
        (*(s32 *)((u8 *)(D_87E1EBB8) + (0x14))) = arg0;
    }
}

void func_87E10F74(void *arg0, s32 arg1) {
    u32 index = ((u32)*(s32 *)((u8 *)(u32)D_87E1EBB8 + 0x2C0) % 26U) >> 1;
    *(s32 *)((u8 *)arg0 + 4) = func_8004C990(0x164, D_87E1A5EC[index]);
}

void func_87E10FD0(void *arg0, s32 arg1) {
    u32 index = ((u32)*(s32 *)((u8 *)(u32)D_87E1EBB8 + 0x2C0) % 50U) >> 1;
    *(s32 *)((u8 *)arg0 + 4) = func_8004C990(0x164, D_87E1A620[index]);
}

void func_87E1102C(void *arg0, s32 arg1) {
    u32 index = ((u32)*(s32 *)((u8 *)(u32)D_87E1EBB8 + 0x2C0) % 50U) >> 1;
    *(s32 *)((u8 *)arg0 + 4) = func_8004C990(0x165, D_87E1A684[index]);
}

void func_87E11088(void *arg0, s32 arg1) {
    u32 index = ((u32)*(s32 *)((u8 *)(u32)D_87E1EBB8 + 0x2C0) % 50U) >> 1;
    *(s32 *)((u8 *)arg0 + 4) = func_8004C990(0x165, D_87E1A6E8[index]);
}

extern s32 func_8004C990(s32, s32);
extern u32 D_87E1EBB8;
void func_87E110E4(void *arg0, s32 arg1) { u8 *base = (u8 *)(u32)D_87E1EBB8; s32 index = (s32)*(s8 *)(base + 0x938); s32 result = (((*(u8 **)(base + 0x2C4))[0x2182] & (1 << index)) != 0) ? 4 : 0; *(s32 *)((u8 *)arg0 + 4) = func_8004C990(0x1B5, result + index); }

extern u8 D_87E1AA40[];
extern s32 func_8004C990(s32, s32);
extern u32 D_87E1EBB8;
void func_87E11148(void *arg0, s32 arg1) {
    u8 digit;
    u16 value;
    switch (*(s32 *)((u8 *)arg0 + 0xC)) {
    case 0:
        digit = (*(u16 *)((u8 *)(u32)D_87E1EBB8 + 0x93A) % 1000) / 100;
        if (digit == 0) digit = 10;
        break;
    case 1:
        digit = (*(u16 *)((u8 *)(u32)D_87E1EBB8 + 0x93A) % 100) / 10;
        if (digit == 0 && *(u16 *)((u8 *)(u32)D_87E1EBB8 + 0x93A) < 100) digit = 10;
        break;
    case 2:
        digit = *(u16 *)((u8 *)(u32)D_87E1EBB8 + 0x93A) % 10;
        break;
    }
    *(s32 *)((u8 *)arg0 + 4) = func_8004C990(0x1B8, D_87E1AA40[(u8)digit]);
}

void func_87E11248(u8 *arg0) {
    func_800476A0(arg0 + 0x22C, 9);
    func_800476FC(arg0 + 0x22C, 9);
    func_80047738(0, func_8004C990(356, D_87E1A5EC[0]), func_87E10F74, 0);
    func_80047738(1, func_8004C990(357, D_87E1A684[0]), func_87E1102C, 0);
    func_80047738(2, func_8004C990(357, D_87E1A6E8[0]), func_87E11088, 0);
    func_80047738(3, func_8004C990(356, D_87E1A620[0]), func_87E10FD0, 0);
    func_80047738(4, func_8004C990(369, 0), NULL, 0);
    func_80047738(5, func_8004C990(437, 0), func_87E110E4, 0);
    func_80047738(6, func_8004C990(440, 0), func_87E11148, 0);
    func_80047738(7, func_8004C990(440, 1), func_87E11148, 1);
    func_80047738(8, func_8004C990(440, 2), func_87E11148, 2);
}

s32 process_geo_layout(s32, s32 *);
extern u8 D_87E1AA80;
extern u8 D_87E1EBA0;
void func_87E113C8(void) {
    s32 sp1C;
    s32 temp_v0;

    GeoNode_CreateContainer(0, &D_87E1EBA0);
    temp_v0 = MainPool_AllocState(main_pool_get_available(), 0);
    sp1C = temp_v0;
    (*(s32 *)((u8 *)(D_87E1EBB8) + (0x934))) = process_geo_layout(temp_v0, &D_87E1AA80);
    MainPool_FinalizeAllocation(sp1C);
}

extern void func_8004C4B0(s32);
void func_87E1142C(void) {
    func_8004C4B0(50);
}

extern void func_87E10B30(void);
extern void func_87E0F170(void);
extern void func_87E10628(void);
extern void func_87E113C8(void);
extern void func_87E1142C(void);
extern u32 D_87E1EBB8;
void func_87E1144C(s32 arg0, s32 arg1) {
    D_87E1EBB8 = (u32)arg0;
    *(s32 *)((u8 *)(u32)D_87E1EBB8 + 0x8) = -1;
    *(s32 *)((u8 *)(u32)D_87E1EBB8 + 0xC) = -1;
    *(s32 *)((u8 *)(u32)D_87E1EBB8 + 0x10) = -1;
    *(s32 *)((u8 *)(u32)D_87E1EBB8 + 0x14) = -1;
    *(s32 *)((u8 *)(u32)D_87E1EBB8 + 0x18) = 0;
    *(s32 *)((u8 *)(u32)D_87E1EBB8 + 0x2C4) = arg1;
    *(s32 *)((u8 *)(u32)D_87E1EBB8 + 0x1E4) = 0;
    *(s32 *)((u8 *)(u32)D_87E1EBB8 + 0x1E8) = 0;
    *(s32 *)((u8 *)(u32)D_87E1EBB8 + 0x1EC) = 0;
    *(s32 *)((u8 *)(u32)D_87E1EBB8 + 0x1F8) = 0;
    *(s32 *)((u8 *)(u32)D_87E1EBB8 + 0x1FC) = 0;
    *(s32 *)((u8 *)(u32)D_87E1EBB8 + 0x200) = 0;
    *(s32 *)((u8 *)(u32)D_87E1EBB8 + 0x204) = 0;
    *(s32 *)((u8 *)(u32)D_87E1EBB8 + 0x210) = 0;
    *(s32 *)((u8 *)(u32)D_87E1EBB8 + 0x214) = 0;
    *(s32 *)((u8 *)(u32)D_87E1EBB8 + 0x218) = 0;
    *(s32 *)((u8 *)(u32)D_87E1EBB8 + 0x21C) = 0;
    *(s32 *)((u8 *)(u32)D_87E1EBB8 + 0x228) = 0;
    *(u8 *)((u8 *)(u32)D_87E1EBB8 + 0x938) = 0;
    *(s16 *)((u8 *)(u32)D_87E1EBB8 + 0x93A) = 0;
    func_87E113C8();
    func_87E10628();
    func_87E10B30();
    func_87E1142C();
    func_87E0F170();
}

extern void func_87E105FC(void *arg0, u8 arg1);
s32 func_87E11534(s32 count, s32 selected, u8 *entry, u8 inc, u8 dec) {
    s32 done = 0;
    s32 i = 0;
    s32 maximum = 0xFF;
    u8 saturation = 0xFF;
    if (count > 0) {
        do {
            if (i == selected) {
                s32 value = entry[4];
                if (value < maximum - inc) {
                    entry[4] = (s32)value + inc;
                } else {
                    entry[4] = saturation;
                    done = 1;
                }
            } else {
                s32 value = entry[4];
                if (dec < value) {
                    entry[4] = value - dec;
                } else {
                    entry[4] = 0;
                }
            }
            func_87E105FC(*(void **)entry, entry[4]);
            i++;
            entry += 8;
        } while (i != count);
    }
    return done;
}

/* mkdraft:func_87E1162C begin */
void func_87E0FBB4(s32 arg0, u8 *arg1, u32 arg2, u32 arg3);
void func_87E0FC90(s32 arg0, u8 *arg1, void *arg2, u32 arg3, u32 arg4);
s32 func_87E0FDB4(s32, u8 *, void *, u32, u32);
extern s32 D_87E1A870[];
extern s32 D_87E1A988[];
extern s32 D_87E1AA10[];



void func_87E1162C(s32 *arg0, s32 *arg1, s32 *arg2) {
    s32 advance;
    u8 *node;
    s32 i;

    // Func_87E11534 fades the selected entry of the two 8-byte entries at
    // base+0x1C and returns 1 once it has reached 0xFF.
    advance = 1;
    if (func_87E11534(2, *(s32 *)((u8 *)(u32)D_87E1EBB8 + 8), (u8 *)(u32)D_87E1EBB8 + 0x1C, 0x20, 0x20) != 0) {
        *arg0 = *(s32 *)((u8 *)(u32)D_87E1EBB8 + 0xC);
        *arg1 = *(s32 *)((u8 *)(u32)D_87E1EBB8 + 0x10);
        *arg2 = *(s32 *)((u8 *)(u32)D_87E1EBB8 + 0x14);
    } else {
        *arg0 = -1;
        *arg1 = -1;
        *arg2 = -1;
    }
    switch (*arg0) {
        case 6:
            advance = 0;
            break;
        case 48:
            advance = 0;
            break;
        default:
            for (node = (u8 *)(u32)D_87E1EBB8 + 0x1C, i = 0; i != 2; i++) {
                if ((node[4] < 0xFF) && (node[4] > 0)) {
                    advance = 0;
                }
                node += 8;
            }
            break;
    }
    // A zero first argument makes the frame helpers below reset their frame
    // instead of advancing it (//@{src/fragments/63/fragment63_312AE0.c}
    // func_87E0FBB4, func_87E0FC90, func_87E0FDB4).
    func_87E0FBB4(advance, (u8 *)(u32)D_87E1EBB8 + 0x1FC, 7, 3);
    i = 2; // FAKE: reuses the loop counter so the 2 is shared with the calls below; passing the literal 2 instead scores 710
    func_87E0FC90(advance, (u8 *)(u32)D_87E1EBB8 + 0x1FC, D_87E1A988, 3, 3);
    func_87E0FBB4(advance, (u8 *)(u32)D_87E1EBB8 + 0x1E4, 7, i);
    func_87E0FDB4((*(s32 *)((u8 *)(u32)D_87E1EBB8 + 8) == 0) && (advance != 0),
                  (u8 *)(u32)D_87E1EBB8 + 0x1E4, D_87E1A870, 6, i);
    func_87E0FBB4(advance, (u8 *)(u32)D_87E1EBB8 + 0x214, 7, i);
    func_87E0FDB4((*(s32 *)((u8 *)(u32)D_87E1EBB8 + 8) == 1) && (advance != 0),
                  (u8 *)(u32)D_87E1EBB8 + 0x214, D_87E1AA10, 6, i);
    if (advance != 0) {
        // 0x1EC indexes D_87E1A800 / D_87E1A81C in func_87E10094.
        switch (*arg0) {
            case 36:
            case 41:
                *(s32 *)((u8 *)(u32)D_87E1EBB8 + 0x1EC) = 2;
                break;
        }
    }
}
/* mkdraft:func_87E1162C end */

extern void *func_8005049C(void *, s32);
extern s32 func_8004C874(s32, s32);
extern void func_87E0F188(s32);
extern s32 func_87E11534(s32, s32, u8 *, u8, u8);
void func_87E11850(s32 arg0) {
    volatile u32 *base;
    u8 *entry;
    s32 i;
    s32 marker;
    long count;
    s32 flag;
    void *value;

    base = &D_87E1EBB8;
    func_87E11534(0x32, arg0, *base + 0x2C, 0xFF, 0xFF);
    entry = (u8 *)*base + 0x2C;
    marker = 0x50414B55;
    flag = 0xFF;
    count = 0x32;
    for (i = 0; i != 0x32; i++) {
        if ((i == arg0) && (entry[4] == flag)) {
            value = func_8005049C(*(void **)entry, marker);
            if (value != NULL) {
                func_87E0F188(func_8004C874(*(u16 *)((u8 *)value + 0x30), *(u16 *)((u8 *)value + 0x32)));
            }
        }
        entry += 8;
    }
}

void func_87E11924(s32 arg0) {
    s32 i;
    u8 *entry;

    func_87E11534(1, arg0, D_87E1EBB8 + 0x1DC, 0xFF, 0xFF);
    entry = D_87E1EBB8 + 0x1DC;
    for (i = 0; i != 1; i += 1, entry += 8) {
        if (i == 0) {
            if (((1 << *(s8 *)(D_87E1EBB8 + 0x938)) & *(*(u8 **)(D_87E1EBB8 + 0x2C4) + 0x2182)) != 0) {
                *(u16 *)(*(u8 **)entry + 2) |= 1;
            } else {
                *(u16 *)(*(u8 **)entry + 2) &= ~1;
            }
        }
    }
}

extern void func_87E1162C(s32 *, s32 *, s32 *);
extern s32 func_87E11534(s32, s32, u8 *, u8, u8);
extern void func_87E11850(s32);
extern void func_87E11924(s32);
extern void func_87F0277C();
void func_87E119DC(void) {
    s32 sp2C;
    s32 sp24;
    s32 sp28;
    (*(s32 *)((u8 *)(u32)D_87E1EBB8 + 0x2C0))++;
    func_87E1162C(&sp2C, &sp28, &sp24);
    func_87E11534(4, sp28, D_87E1EBB8 + 0x1BC, 0xFF, 0xFF);
    func_87E11850(sp2C);
    func_87E11924(sp24);
    func_87F0277C(D_87E1EBB8 + 0x2C8);
}

extern void func_800503A4(void *);
void func_87E11A5C(s32 arg0, s32 arg1) {
    s32 i = 0;
    while (i < arg0) {
        if (*(u8 *)(arg1 + 4) > 0) {
            func_800503A4(*(void **)arg1);
        }
        i++;
        arg1 += 8;
    }
}

extern void Geo_RenderRootNode(s32);
extern void func_87E11A5C(s32, s32);
void func_87E11AB8(void) {
    func_87E11A5C(2, D_87E1EBB8 + 0x1C);
    func_87E11A5C(4, D_87E1EBB8 + 0x1BC);
    func_87E11A5C(0x32, D_87E1EBB8 + 0x2C);
    func_87E11A5C(1, D_87E1EBB8 + 0x1DC);
    Geo_RenderRootNode((*(s32 *)((u8 *)(D_87E1EBB8) + (0x934))));
}

extern u8 D_87E1A4B0[];
extern void func_8004C54C(s32, s32);
void func_87E11B30(s32 arg0) {
    u8 *var_a1;
    u8 *temp_v0;
    *(u8 *)((u8 *)(u32)D_87E1EBB8 + 0x938) = arg0;
    temp_v0 = *(u8 **)((u8 *)(u32)D_87E1EBB8 + 0x2C4);
    if (*(u8 *)(temp_v0 + 0x2182) & (1 << arg0)) {
        var_a1 = ((u8 *)(u32)temp_v0) + (arg0 * 0x6C0) + 0x6AA;
    } else {
        var_a1 = D_87E1A4B0;
    }
    func_8004C54C(0x15, (s32)var_a1);
}

extern s32 func_8004C874(s32, s32);
extern void func_8004C54C(s32, s32);
extern s32 func_80054668(s32);
void func_87E11BA4(s32 arg0) {
    s32 sp1C;
    s32 sp18;
    switch (arg0) {
    case 0:
        sp1C = 0x39;
        sp18 = 0;
        break;
    case 1:
        sp1C = 0x38;
        sp18 = 1;
        break;
    case 2:
        sp1C = 0x37;
        sp18 = 2;
        break;
    }
    func_8004C54C(0x53, func_8004C874(0x32, sp1C));
    *(s16 *)((u8 *)(u32)D_87E1EBB8 + 0x93A) = func_80054668(sp18);
}

extern s32 func_8004C594(s32, s32);
extern u8 D_87E1A4B4[];
extern void func_8004C54C(s32, s32);
extern s32 func_8004C874(s32, s32);
void func_87E11C38(s32 arg0) {
    u8 *entry;
    if ((arg0 < 5) || (arg0 >= 10)) {
        arg0 = 7;
    }
    func_8004C594(1, arg0);
    entry = D_87E1A4B4;
    entry += (arg0 - 5) * 8;
    func_8004C594(2, entry[0]);
    func_8004C54C(0x54, func_8004C874(0x32, *((s32 *)(entry + 4))));
}

extern void *D_87F119DC;

void func_87E11CC0(void) {
    s32 (*temp_v1)();
    void *temp_v0;

    temp_v0 = (*(void **)((u8 *)(D_87F119DC) + (0x38)));
    temp_v1 = (*(s32 (**)())((u8 *)(temp_v0) + (0x94)));
    (*(s32 *)((u8 *)(temp_v0) + (0x8C))) = (s32) ((*(s32 *)((u8 *)(temp_v0) + (0x8C))) + 1);
    if (temp_v1 != NULL) {
        temp_v1();
    }
}

extern s32 D_87E1AB14[];

void func_87E11D00(s32 arg0, s32 arg1) {
    u8 *context;
    void *temp_v0;
    u8 *model;
    s32 index;

    if (arg0 != 5) {
        return;
    }

    context = (u8 *)D_8009491C;
    temp_v0 = *(void **)(context + 0x14);
    model = *(u8 **)((u8 *)temp_v0 + 0x90);

    gDPPipeSync(D_800D0510++);
    gDPSetCombine(D_800D0510++, 0xFCFFD3FF, 0xFFFCFE38);
    gDPSetEnvColor(D_800D0510++, 0, 0, 0, context[0x1D]);
    index = *(u32 *)((u8 *)temp_v0 + 0x8C) % 7;
    gSPSegment(D_800D0510++, 0xF, func_8004CA60((u8 *)func_8004C990(352, D_87E1AB14[index])));
    gSPDisplayList(D_800D0510++, *(void **)(model + 0x14));
    GeoRender_ApplyMaterialState();
}

extern void func_87E11E48(s32 *, s32, s32);
extern u8 D_80126420;

void func_87E11E18(s32 arg0, s32 arg1) {
    func_87E11E48(&D_80126420, arg0, arg1);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_312AE0/func_87E11E48.s")

extern void *func_87F025B8(void *, void *);
extern void func_8003F1DC(void *);
extern void func_8003F114(void *, s32, s32, s32);
extern void func_87E11CC0(void);
void *func_87E12070(void *arg0, s32 arg1, s32 arg2) {
    void *temp_v0;
    void *temp_a0;
    temp_v0 = func_87F025B8(arg0, func_87E11CC0);
    if (temp_v0 != NULL) {
        temp_a0 = (u8 *)temp_v0 + 0x24;
        func_8003F1DC(temp_a0);
        func_8003F114(temp_a0, 0, -1, *(s32 *)((u8 *)arg0 + 0x18));
        *(u8 *)((u8 *)temp_v0 + 0x26) |= 8;
        temp_a0 = *(void **)((u8 *)temp_v0 + 0x38);
        *(s32 *)((u8 *)temp_a0 + 0x94) = arg1;
        *(s32 *)temp_a0 = arg2;
    }
    return temp_v0;
}

extern void func_87F0277C(void);
void func_87E120F8(void) {
    func_87F0277C();
}
#pragma C_FUNCTION_PADDING(8)
#endif
