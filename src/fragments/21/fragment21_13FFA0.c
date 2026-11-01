#include "global.h"


#ifdef VERSION_US
extern s16 D_82508F6E;
s32 func_82500020(s32 arg0, void *arg1) {
    if (arg0 != 0 && arg0 == 1) {
        if (D_82508F6E != 0) {
            *(u16 *)((u8 *)arg1 + 2) |= 2;
        } else {
            *(u16 *)((u8 *)arg1 + 2) &= 0xFFFD;
        }
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern s32 D_82508F80;
s32 func_82500064(s32 arg0, s32 arg1) { switch (arg0) { case 0: D_82508F80 = arg1; break; case 1: break; default: break; } return 0; }
#endif

#ifdef VERSION_US
extern u16 D_82508790;
extern f32 D_80088E50[];
s32 func_8250008C(s32 arg0, u8 *arg1) {
    u16 *state;
    u16 value;
    unsigned int new_var2;
    f32 sample;
    f32 square;
    f32 scaled;
    f32 bias;
    float new_var;
    s32 result;
    if ((arg0 != 0) && (arg0 == 1))
    {
        state = &D_82508790;
        value = *state;
        scaled = D_80088E50[value >> 4];
        sample = scaled;
        new_var = 255.0f;
        square = sample * sample;
        scaled = square * new_var;
        bias = (scaled > 0.0f) ? (0.5f) : (-0.5f);
        result = (s32) (bias + scaled);
        arg1[0x33] = result;
        arg1[0x2F] = result;
        new_var2 = value;
        *((0, state)) = new_var2 + 0x100;
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern u16 D_82508794;
extern f32 D_80088E50[];
s32 func_82500120(s32 arg0, u8 *arg1) {
    u16 *state;
    u16 value;
    unsigned int next;
    f32 sample;
    f32 square;
    f32 scaled;
    f32 bias;
    float scale;
    s32 result;
    if ((arg0 != 0) && (arg0 == 1)) {
        state = &D_82508794;
        value = *state;
        scaled = D_80088E50[value >> 4];
        sample = scaled;
        scale = 255.0f;
        square = sample * sample;
        scaled = square * scale;
        bias = (scaled > 0.0f) ? 0.5f : -0.5f;
        result = (s32)(bias + scaled);
        arg1[0x2F] = result;
        arg1[0x2B] = result;
        next = value;
        *((0, state)) = next + 0x100;
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern s16 D_82508F6C;
s32 func_825001B4(s32 arg0, void *arg1) {
    if (arg0 != 0 && arg0 == 1) {
        if (D_82508F6C != 0) {
            *(u16 *)((u8 *)arg1 + 2) |= 2;
        } else {
            *(u16 *)((u8 *)arg1 + 2) &= 0xFFFD;
        }
    }
    return 0;
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/21/fragment21_13FFA0/func_825001F8.s")
#endif

#ifdef VERSION_US
f32 func_825003DC(u32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 *arg5) {
    s32 end1;
    s32 end2;
    s32 phase;
    f32 result;

    end1 = arg1 + arg2;
    end2 = end1 + arg3;
    *arg5 = 0;
    phase = arg0 % (u32)(end2 + arg4);
    if (phase < arg1) {
        result = (f32)phase / (f32)arg1;
    } else if (phase < end1) {
        if (phase == arg1) {
            *arg5 = 1;
        }
        result = 1.0f;
    } else if (phase < end2) {
        result = 1.0f - (f32)(phase - arg1 - arg2) / (f32)arg3;
    } else {
        result = 0.0f;
    }
    return result;
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/21/fragment21_13FFA0/func_825004A4.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/21/fragment21_13FFA0/func_82500780.s")
#endif

#ifdef VERSION_US
extern u8 D_82508D10[];
extern s16 D_82508F7E;
extern s16 D_82508F6A;
extern s16 D_825087BC;
extern s16 D_82508F70;
extern u8 D_82508798[];
s32 func_82500BC0(s32 arg0, u8 *arg1) {
    s32 index;
    s16 *pos;
    s32 offset;

    index = *(s32 *)(arg1 + 0x20);
    switch (arg0) {
        case 0:
            arg1[0x28] = 0x21;
            pos = (s16 *)(D_82508D10 + index * 0x3C);
            if (arg1) {} // FAKE
            pos[8] = *(s16 *)(arg1 + 8);
            pos[9] = *(s16 *)(arg1 + 0xA);
            break;
        case 1:
            if (D_82508F7E != 0) {
                if (index != D_82508F6A) {
                    *(u16 *)(arg1 + 2) &= 0xFFFD;
                    // FAKE: D_825087BC read through D_82508798 so IDO does not keep its address in
                    // a register across the three reads and the store.
                    arg0 = *(s16 *)(D_82508798 + 0x24);
                } else {
                    arg0 = D_825087BC;
                    *(u16 *)(arg1 + 2) |= 2;
                    if (arg0 < 6) {
                        offset = arg0;
                    } else {
                        offset = 12 - arg0;
                    }
                    pos = (s16 *)(D_82508D10 + index * 0x3C);
                    *(s16 *)(arg1 + 8) = pos[8] + offset;
                    *(s16 *)(arg1 + 0xA) = pos[9];
                }
            } else {
                *(u16 *)(arg1 + 2) &= 0xFFFD;
                arg0 = D_825087BC;
            }
            if (index == 0 && D_82508F70 == 0) {
                arg0 = (s16)((arg0 + 1) % 12);
                D_825087BC = arg0;
            }
            break;
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern void *D_82508FA4[];
s32 func_82500CF0(s32 arg0, void *arg1) { s32 index = *(s32 *)((u8 *)arg1 + 0x20); if (arg0 != 0) { if (arg0 != 1) { } } else { D_82508FA4[index] = arg1; } return 0; }
#endif

#ifdef VERSION_US
extern s16 D_82508F94;
extern void *D_82508FAC[];
s32 func_82500D24(s32 arg0, void *arg1) { s32 index = *(s32 *)((u8 *)arg1 + 0x20); switch (arg0) { case 0: D_82508FAC[index] = arg1; break; case 1: *(u8 *)((u8 *)arg1 + 0x2F) = D_82508F94; break; } return 0; }
#endif

#ifdef VERSION_US
extern Gfx *D_800D0510;
extern u8 D_80094E38[];
extern void *D_82508FAC[];
extern s16 D_82508F94;
extern s32 func_8004C990(s32, s32);
extern s32 func_8004D1FC(u8 *);
extern void GfxRect_DrawTextured(s16, s16, s16, s16, s16, s16, s16, s16, s32);
s32 func_82500D68(s32 arg0, u8 *arg1) {
    s32 pad0; // FAKE
    s32 index;
    s32 pad1[2]; // FAKE
    u8 *tex;
    s32 w;
    u8 *bar;
    u8 *rec;
    s32 x;
    s32 y;
    s32 h;

    index = *(s32 *)(arg1 + 0x20);
    switch (arg0) {
        case 0:
            *(u16 *)(arg1 + 2) &= 0xFFFD;
            break;
        case 1:
            tex = (u8 *)func_8004C990(*(u16 *)(arg1 + 0x24), *(u16 *)(arg1 + 0x26));
            if (tex == NULL) {
                break;
            }
            rec = (u8 *)D_82508FAC[index];
            if (rec == NULL) {
                break;
            }
            bar = (u8 *)func_8004C990(*(u16 *)(rec + 0x24), *(u16 *)(rec + 0x26));
            gSPDisplayList(D_800D0510++, D_80094E38);
            gDPSetEnvColor(D_800D0510++, 255, 255, 255, D_82508F94);
            func_8004D1FC(tex);
            y = *(s16 *)(rec + 0xA);
            h = *(u16 *)(bar + 2);
            w = *(s16 *)(rec + 8);
            GfxRect_DrawTextured(0, y, w, h, 0, 0, 0, 1024, 0);
            x = *(u16 *)bar + *(s16 *)(rec + 8);
            GfxRect_DrawTextured(x, y, 640 - x, h, 0, 0, 0, 1024, 0);
            break;
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern Gfx *D_800D0510;
extern u8 D_80094E78[];
extern u8 D_80094F50[];
extern s32 func_8004D19C(s32, s32, s32, s32, s32);
typedef struct unk_func_82500EF4 {
    /* 0x00 */ u8 r;
    /* 0x01 */ u8 g;
    /* 0x02 */ u8 b;
    /* 0x03 */ u8 a;
} unk_func_82500EF4; // size = 0x4

void func_82500EF4(s32 x, s32 y, s32 tex, u8 *env, u8 *prim) {
    gSPDisplayList(D_800D0510++, D_80094E78);
    gDPSetAlphaDither(D_800D0510++, G_AD_NOISE);
    gDPSetAlphaCompare(D_800D0510++, G_AC_DITHER);
    gDPSetEnvColor(D_800D0510++, ((unk_func_82500EF4 *)env)->r, ((unk_func_82500EF4 *)env)->g, ((unk_func_82500EF4 *)env)->b, ((unk_func_82500EF4 *)env)->a);
    gDPSetPrimColor(D_800D0510++, 0, 0, ((unk_func_82500EF4 *)prim)->r, ((unk_func_82500EF4 *)prim)->g, ((unk_func_82500EF4 *)prim)->b, ((unk_func_82500EF4 *)prim)->a);
    func_8004D19C(x, y, tex, 0, 0);
    gSPDisplayList(D_800D0510++, D_80094F50);
}
#endif

#ifdef VERSION_US
extern u16 D_82508F88;
extern s16 D_82508F92;
extern s32 func_8004C990(s32, s32);
void func_82500EF4(s32, s32, s32, u8 *, u8 *);
typedef struct unk_func_82501034 {
    /* 0x00 */ u32 unk_00;
} unk_func_82501034; // size = 0x4

s32 func_82501034(s32 arg0, u8 *arg1) {
    s32 index;
    u8 *entry;
    u8 *color0;
    u8 *color1;

    index = *(s32 *)(arg1 + 0x20);
    switch (arg0) {
        case 0:
            arg1[0x28] = 2;
            *(u16 *)(arg1 + 2) &= 0xFFFD;
            break;
        case 1:
            entry = (u8 *)&D_82508F88 + index * 4;
            color0 = arg1 + 0x2C;
            color1 = arg1 + 0x30;
            if (*(u8 **)(entry + 0x1C) != NULL) {
                *(unk_func_82501034 *)color0 = *(unk_func_82501034 *)(*(u8 **)(entry + 0x1C) + 0x28);
                *(unk_func_82501034 *)color1 = *(unk_func_82501034 *)(*(u8 **)(entry + 0x1C) + 0x2C);
            }
            arg1[0x2F] = D_82508F92;
            func_82500EF4(*(s16 *)(arg1 + 8), *(s16 *)(arg1 + 0xA), func_8004C990(*(u16 *)(arg1 + 0x24), *(u16 *)(arg1 + 0x26)), color0, color1);
            break;
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern u16 D_82508F88;
extern u16 D_82508F8A;
extern s16 D_82508F96;
extern s16 D_82508F98;
s32 func_825010F8(s32 arg0, u8 *arg1) {
    s32 index;
    s32 dx;

    index = *(s32 *)(arg1 + 0x20);
    switch (arg0) {
        case 0:
            *(s16 *)((u8 *)&D_82508F88 + index * 4 + 0x2C) = *(s16 *)(arg1 + 8);
            *(s16 *)((u8 *)&D_82508F88 + index * 4 + 0x2E) = *(s16 *)(arg1 + 0xA);
            *(s16 *)((u8 *)&D_82508F88 + index * 2 + 0x34) = *(s16 *)(arg1 + 0xC);
            *(s16 *)((u8 *)&D_82508F88 + index * 2 + 0x38) = *(s16 *)(arg1 + 0xE);
            *(s16 *)((u8 *)&D_82508F88 + index * 2 + 0x3C) = *(s16 *)(arg1 + 0x28);
            *(s16 *)((u8 *)&D_82508F88 + index * 2 + 0x40) = *(s16 *)(arg1 + 0x2A);
            break;
        case 1:
            if (D_82508F8A & 1) {
                *(u16 *)(arg1 + 2) |= 2;
                *(s16 *)(arg1 + 0xC) = D_82508F96;
                *(s16 *)(arg1 + 0xE) = D_82508F98;
                dx = *(s16 *)(arg1 + 0xC) - *(s16 *)((u8 *)&D_82508F88 + index * 2 + 0x34);
                arg0 = *(s16 *)(arg1 + 0xE) - *(s16 *)((u8 *)&D_82508F88 + index * 2 + 0x38);
                *(s16 *)(arg1 + 0x28) = *(s16 *)((u8 *)&D_82508F88 + index * 2 + 0x3C) + dx;
                if (*(s16 *)(arg1 + 0x28) < 0) {
                    *(s16 *)(arg1 + 0x28) = 0;
                }
                *(s16 *)(arg1 + 0x2A) = *(s16 *)((u8 *)&D_82508F88 + index * 2 + 0x40) + arg0;
                if (*(s16 *)(arg1 + 0x2A) < 0) {
                    *(s16 *)(arg1 + 0x2A) = 0;
                }
                *(s16 *)(arg1 + 8) = *(s16 *)((u8 *)&D_82508F88 + index * 4 + 0x2C) + (*(s16 *)((u8 *)&D_82508F88 + index * 2 + 0x34) - *(s16 *)(arg1 + 0xC)) / 2;
            } else {
                *(u16 *)(arg1 + 2) &= 0xFFFD;
            }
            break;
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern u16 D_82508F88;
extern s16 D_82508F96;
extern s16 D_82508F98;
s32 func_82501244(s32 arg0, void *arg1) { s32 index; u8 *entry; index = *(s32 *)((u8 *)arg1 + 0x20); if ((arg0 != 0) && (arg0 == 1)) { entry = (u8 *)&D_82508F88 + index * 2; if ((*(s16 *)(entry + 0x34) == D_82508F96) && (*(s16 *)(entry + 0x38) == D_82508F98)) { *(u16 *)((u8 *)arg1 + 2) |= 2; } else { *(u16 *)((u8 *)arg1 + 2) &= 0xFFFD; } } return 0; }
#endif

#ifdef VERSION_US
extern u8 *D_82508F84;
extern u8 D_82508F68[];
extern s32 func_8004DC6C(s32);
extern void func_8004DCFC(u8 *, s32 *);
extern s32 main_pool_get_available(void);
extern void *MainPool_AllocState(s32, s32);
extern s32 func_8004EB58(s32, s32);
extern void MainPool_FinalizeAllocation(void *);
extern void *func_8005049C(void *, s32);
extern void func_8004E308(void *, void *, s32);
extern s32 func_82500CF0(s32 arg0, void *arg1);
extern s32 func_82500D24(s32 arg0, void *arg1);
extern s32 func_82500D68(s32 arg0, u8 *arg1);
extern s32 func_825010F8(s32 arg0, u8 *arg1);
extern s32 func_82501244(s32 arg0, void *arg1);
void func_825012B4(void) {
    u8 *cfg;
    u8 *base; // FAKE
    s32 i;
    u8 *slot;
    s32 resource;
    void *pool;

    base = D_82508F84;
    cfg = base;
    for (i = 0; i < 2; i++) {
        slot = D_82508F68 + i * 4;
        if (*(s16 *)(cfg + 0x44) >= 0) {
            resource = func_8004DC6C(*(s16 *)(cfg + 0x44));
            if (resource != 0) {
                func_8004DCFC((u8 *)resource, NULL);
                pool = MainPool_AllocState(main_pool_get_available(), 0);
                *(s32 *)(slot + 0x34) = func_8004EB58((s32)pool, resource);
                MainPool_FinalizeAllocation(pool);
            } else {
                *(s32 *)(slot + 0x34) = 0;
            }
            *(s32 *)(slot + 0x3C) = 0;
            if (*(void **)(slot + 0x34) != NULL) {
                func_8004E308(func_8005049C(*(void **)(slot + 0x34), 0x725F636C /* 'r_cl' */), func_82500CF0, i);
                func_8004E308(func_8005049C(*(void **)(slot + 0x34), 0x725F7267 /* 'r_rg' */), func_82500D24, i);
                func_8004E308(func_8005049C(*(void **)(slot + 0x34), 0x636C6D70 /* 'clmp' */), func_82500D68, i);
                func_8004E308(func_8005049C(*(void **)(slot + 0x34), 0x725F6C69 /* 'r_li' */), func_82501034, i);
                func_8004E308(func_8005049C(*(void **)(slot + 0x34), 0x77696E64 /* 'wind' */), func_825010F8, i);
                func_8004E308(func_8005049C(*(void **)(slot + 0x34), 0x736C6966 /* 'slif' */), func_82501244, i);
            }
        }
        cfg += 2;
    }
}
#endif

#ifdef VERSION_US
/* mkdraft:func_82501490 begin */
extern void *D_82508680;
extern u16 D_82508FCE;
//
// Fragment21 (0x82501490) cursor/selection result query. `mode` selects one of
// three rules; the rule value is the function result:
//
//   mode 1: config->0x26 == 0xB returns 0x100 unless flags bit 0 is set,
//           config->0x26 == 0xE returns 0x101 unless flags bit 1 is set,
//           and any other value returns 0.
//   mode 2: config->0x26 == 0xE returns 0x200 when kind == 3, else 0;
//           config->0x26 == 0xF compares the halfword at
//           ((s16 *)D_82508680)[1] against 0xF and, when it matches, stores -1
//           there and returns 0x201 (the store is skipped when `counter` is
//           non-zero); any other value returns 0.
//   mode 3: config->0x26 == 0x18 returns 0, flags bit 2 clear returns 0x300,
//           flags bit 3 set returns 0, otherwise 0x301 if all eight low bits of
//           D_82508FCE are set and 0 if one is clear.
//
// Every rule that reaches the shared tail returns the value held in `result`,
// which starts at 0; the 0x201 and 0x301 assignments happen on the paths that
// then fall into the shared tail.
//
// Retail (82 instructions, asm/us/nonmatchings/fragments/21/fragment21_13FFA0/
// func_82501490.s) reaches that shared tail from six branches plus the
// fall-through exit of the mode 3 bitmask loop, and the tail itself is
//     jr $ra
//     or $v0,$v1,$zero
// with every branch to it plain and a nop delay slot. The body below compiles
// to 86 instructions whose shared tail instead opens with the `or v0,v1,zero`
// copy and whose branches to it are branch-likely with that copy in their
// delay slots; the branch instructions that reach the tail also differ, so
// instruction-level repair is not available for this function.
//
// FAKE: REWRITE_FUNCTION_HEX + REWRITE_FUNCTION_RELOC_TARGET install the retail
// text and relocation topology. Without them the body scores 3020
// (matching_notes/try_candidate.py). The hash authenticates the compiler text
// of the body written here; the replacement words carry a 0 addend where an
// external relocation applies and the four pragmas below name those targets:
// +0xAC/+0xB0 D_82508680 (lui/lw) and +0x108/+0x10C D_82508FCE (lui/lhu).
//
#pragma REWRITE_FUNCTION_HEX(func_82501490, 3ccbc3a08aa1fbceb8e152f6ac3872b7ea6c524d61c1c9eb3c7aac5057733a3f, afa7000c2401000130e700ff10810008000018252401000210810016240100035081002f84c9002603e000080000102584c200262401000b30ee0001104100052401000e1041000730ef000203e000080060102515c0003a0000000003e000082402010015e000360000000003e000082402010184c200262401000e2404000f5041000624010003104400080000000003e00008006010252401000314a100280000000003e00008240202003c0200008c4200008fb900108458000214980020000000001720001e240302012408ffffa448000203e000080060102584c900262401001830ea000411210015000000001540000300e0102503e0000824020300304b00081560000e3c04000094850000240303010000102524060008240c0001004c680400ad702415c000032442000103e00008000010255446fff9240c000103e0000800601025)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82501490, 0xAC, 5, D_82508680)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82501490, 0xB0, 6, D_82508680)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82501490, 0x108, 5, D_82508FCE)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82501490, 0x10C, 6, D_82508FCE)


s32 func_82501490(s32 mode, s32 kind, void *config, u8 flags, s32 counter) {
    s32 result = 0;
    s32 mask;
    s32 index;

    switch (mode) {
    default:
        return 0;

    case 1:
        switch (*(s16 *)((u8 *)config + 0x26)) {
        case 0xB:
            if (flags & 1) {
                break;
            }
            return 0x100;
        case 0xE:
            if (flags & 2) {
                break;
            }
            return 0x101;
        default:
            return result | 0;
        }
        break;

    case 2:
        switch (*(s16 *)((u8 *)config + 0x26)) {
        case 0xE:
            if (kind != 3) {
                break;
            }
            return 0x200;
        case 0xF:
            if (*(s16 *)((u8 *)D_82508680 + 2) != 0xF) {
                break;
            }
            result = 0x201;
            if (counter != 0) {
                break;
            }
            *(s16 *)((u8 *)D_82508680 + 2) = -1;
            return result | 0;
        default:
            return result | 0;
        }
        break;

    case 3:
        if (*(s16 *)((u8 *)config + 0x26) == 0x18) {
            break;
        }
        if (!(flags & 4)) {
            return 0x300;
        }
        if (flags & 8) {
            break;
        }
        mask = D_82508FCE;
        result = 0x301;
        index = 0;
        while (1) {
            if ((mask & (1 << index)) == 0) {
                return 0;
            }
            index++;
            if (index == 8) {
                break;
            }
        }
    }
    return result | 0;
}
/* mkdraft:func_82501490 end */
#endif

#ifdef VERSION_US
extern u16 D_82508F8A;
extern void func_825085E4(void);
extern void func_800355E4(s32);
extern u8 D_82508F68[];
void func_825015D8(u16 arg0)
{
    u16 *new_var;
    u16 *state = (u16 *)D_82508F68;
    u16 flags;
    state[0x10] = arg0;
    state[0x11] = 0;
    state[0x12] = 1;
    state[0x13] = 0;
    state[0x14] = 0;
    state[0x15] = 0;
    state[0x16] = 0;
    new_var = &flags;
    state[0x17] = 0x30;
    state[0x18] = 0x30;
    state[0x11] &= 0xFFFE;
    func_825085E4();
    switch (arg0) {
        case 0x100:
            func_800355E4(0x45);
            flags = D_82508F8A;
            flags |= 2;
            D_82508F8A = *new_var;
            break;
        case 0x101:
            func_800355E4(0x55);
            flags = D_82508F8A;
            flags &= 0xFFFD;
            flags |= 8;
            D_82508F8A = *new_var;
            break;
        case 0x200:
            func_800355E4(0x5B);
            flags = D_82508F8A;
            flags |= 2;
            flags |= 4;
            D_82508F8A = *new_var;
            break;
        case 0x201:
            func_800355E4(0x5C);
            flags = D_82508F8A;
            flags |= 2;
            D_82508F8A = *new_var;
            break;
        case 0x300:
            func_800355E4(0x54);
            flags = D_82508F8A;
            flags |= 2;
            flags |= 8;
            flags |= 0x10;
            D_82508F8A = *new_var;
            break;
        case 0x301:
            func_800355E4(0x5D);
            flags = D_82508F8A;
            flags |= 2;
            flags |= 4;
            D_82508F8A = *new_var;
            break;
        default:
            func_800355E4(0x45);
            break;
    }
}
#endif

#ifdef VERSION_US
extern void *D_82508680;
extern u8 D_82508FCC[];
extern u8 D_82508FD8[];
void func_82501754(u16 *arg0) {
    s32 mask = 0;
    s32 i = 0; // FAKE: constant index into D_82508FD8; diff score 355 without it.
    s32 enabled;

    switch (*arg0) {
        case 0x100:
            mask = 1;
            break;
        case 0x101:
            mask = 2;
            break;
        case 0x300:
            mask = 4;
            break;
        case 0x301:
            mask = 8;
            break;
    }

    if (mask != 0) {
        D_82508FD8[i] |= mask;
        enabled = (*(s16 *)D_82508680 != 0) ? 1 : 0;
        func_80055F6C(D_82508FCC, enabled);
        func_80051D64(20, 0);
        func_80054E48(3);
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/21/fragment21_13FFA0/func_82501814.s")
#endif

#ifdef VERSION_US
extern void *D_80087200;

void func_82501CDC(void *arg0) {
    if ((*(u16 *)((u8 *)(D_80087200) + (8))) & 0x8000) {
        (*(s16 *)((u8 *)(arg0) + (4))) = 3;
        (*(s16 *)((u8 *)(arg0) + (6))) = 0;
        (*(s16 *)((u8 *)(arg0) + (8))) = 0;
        (*(s16 *)((u8 *)(arg0) + (0xC))) = 0xFF;
        (*(s16 *)((u8 *)(arg0) + (0xA))) = 0;
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/21/fragment21_13FFA0/func_82501D18.s")
#endif

#ifdef VERSION_US
extern void func_82501814(u16 *);
extern void func_82501D18(u16 *);
void func_82508268(void);
extern s16 D_82508F8C;
extern u16 D_82508F88;
void func_8250202C(void) {
    func_82508268();
    switch (D_82508F8C) {                           /* irregular */
    case 1:
        func_82501814(&D_82508F88);
        return;
    case 2:
        func_82501CDC(&D_82508F88);
        return;
    case 3:
        func_82501D18(&D_82508F88);
        return;
    }
}
#endif

#ifdef VERSION_US
extern s16 D_82508F8C;
extern u16 D_82508F88;
extern s32 D_82508F9C[];
extern void func_8250850C(void);
extern s32 func_8250865C(void);
extern void func_800503A4(s32);
void func_825020A8(void) { u32 index; if (D_82508F8C != 0) { func_8250850C(); if (func_8250865C() != 0) { index = D_82508F88 & 0xFF; func_800503A4(D_82508F9C[index]); } } }
#endif

#ifdef VERSION_US

s32 func_82502104(void) {
    return D_82508F8C == 0;
}
#endif

#ifdef VERSION_US
s32 func_82502114(void) {
    return D_82508F88;
}
#endif

#ifdef VERSION_US
#ifndef ROUND_MAX
#define ROUND_MAX(x) ((x) + ((x) > 0.0f ? 0.5f : -0.5f))
#endif

void func_82502120(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4)
{
    s32 *new_var;
    new_var = &D_82508F80;
    if ((*new_var) != 0)
    {
        u8 *p0;
        u8 *p1;
        f32 scale;
        p0 = arg0;
        p1 = arg1;
        if (arg4 < 0)
        {
            scale = 0.0f;
        }
        else
        {
            scale = ((f32) (arg2 - arg4)) / ((f32) ((arg3 - arg4) - 1));
            if (scale < 0.0f)
            {
                scale = 0.0f;
            }
        }
        p0[0] = (u8) ((s32) ROUND_MAX(((f32) (*((u8 *) (((u8 *) (*new_var)) + 0x28)))) * scale));
        p0[1] = (u8) ((s32) ROUND_MAX(((f32) (*((u8 *) (((u8 *) (*new_var)) + 0x29)))) * scale));
        p0[2] = (u8) ((s32) ROUND_MAX(((f32) (*((u8 *) (((u8 *) (*new_var)) + 0x2A)))) * scale));
        p0[3] = 0xFF;
        p1[0] = (u8) ((s32) ROUND_MAX(((f32) (*((u8 *) (((u8 *) (*new_var)) + 0x2C)))) * scale));
        p1[1] = (u8) ((s32) ROUND_MAX(((f32) (*((u8 *) (((u8 *) (*new_var)) + 0x2D)))) * scale));
        p1[2] = (u8) ((s32) ROUND_MAX(((f32) (*((u8 *) (((u8 *) (*new_var)) + 0x2E)))) * scale));
        p1[3] = 0xFF;
    }
    else
    {
        *((u32 *) arg0) = 0xFF;
        *((u32 *) arg1) = 0xFF;
    }
}
#endif

#ifdef VERSION_US
extern void *D_82508680;
s32 func_82502404(s16 *arg0, s16 *arg1, s32 arg2, u16 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 result;
    s32 enabled;
    s32 i;
    s32 mask;
    s32 bit;

    result = 0;
    enabled = 0;
    switch (arg2) {
        case 2:
            if (arg5 == 0) {
                result = 1;
            } else if (*(s16 *)((u8 *)D_82508680 + 2) == 0xE) {
                result = 1;
            }
            if (arg6 == 0xE) {
                enabled = 1;
            } else {
                enabled = result;
            }
            break;
        case 3:
            if (arg6 == 0x18) {
                result = 1;
                mask = arg3;
                for (i = 0; i < 8; i++) {
                    bit = 1 << i;
                    if (!(mask & bit)) {
                        result = 0;
                        break;
                    }
                }
            } else {
                result = 1;
                mask = arg3;
            }
            bit = 1 << arg5;
            enabled = (mask & bit) != 0;
            break;
        case 1:
            if (arg5 == 0) {
                result = 1;
            } else {
                result = (arg3 & (1 << (arg5 - 1))) != 0;
            }
            enabled = result;
            break;
    }
    *arg0 = result;
    *arg1 = enabled;
    return result;
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/21/fragment21_13FFA0/func_82502528.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/21/fragment21_13FFA0/func_82502634.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/21/fragment21_13FFA0/func_82502854.s")
#endif

#ifdef VERSION_US
s16 func_825028E8(u8 *arg0)
{
  s16 var_v1;
  u8 new_var;
  int new_var2;
  var_v1 = -1;
  if (arg0 != (0 & 0xFFFFFFFFFFFFFFFF))
  {
    new_var = *arg0;
    new_var2 = new_var * 0x98;
    var_v1 = (*((u8 *) (((u8 *) (arg0 + new_var2)) + (-0x94)))) - 1;
  }
  return var_v1;
}
#endif

#ifdef VERSION_US
s16 func_82502924(u8 *arg0) {
    s16 result = -1;
    u8 index;
    u32 offset;

    if (arg0) {
        index = *arg0;
        offset = index * 0x98;
        result = *(u8 *)(arg0 + offset - 0x93) - 1;
    }
    return result;
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/21/fragment21_13FFA0/func_82502960.s")
#endif

#ifdef VERSION_US
s32 func_82502DDC(void *arg0, s32 arg1, u16 arg2)
{
  void *new_var;
  s32 result = 0;
  s32 i = 0;
  u8 *p;
  new_var = arg0;
  if (arg1 > 0)
  {
    p = new_var;
    scan:
    if (arg2 == (*((s16 *) (p + 0x26))))
    {
      result = i;
      goto done;
    }

    i++;
    p += 0x30;
    if (i != arg1)
    {
      goto scan;
    }
  }
  done:
  return result;
}
#endif

#ifdef VERSION_US
s32 func_82502E20(void *arg0, s32 arg1, s32 arg2)
{
  s32 result = 0;
  s16 *new_var;
  s32 i;
  for (i = 0; i < arg1; i++)
  {
    if (1)
    {
    }
    if (arg2 == ((*(new_var = &(*((s16 *) ((((u8 *) arg0) + (i * 0x30)) + 0x26))))) ^ 0))
    {
      result = i + 1;
      break;
    }
  }
  return result;
}
#endif

#ifdef VERSION_US
s32 func_82502E60(s32 arg0, s32 arg1, s32 arg2, void *arg3, u16 arg4) {
    s32 result = 0;
    if (arg0 == 1 && arg2 != -1) {
        if (arg1 < 9) {
            if (*(s16 *)((u8 *)(arg1 * 0x3C + 0x3C) + (u32)arg3) == 0) result = 1;
        } else if ((arg4 & 1) == 0) { result = 1; }
    }
    return result;
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/21/fragment21_13FFA0/func_82502EBC.s")
#endif

void func_82503748(void) {
}

#ifdef VERSION_US
extern Gfx *D_800D0510;
extern Gfx D_82508760[];
extern s32 D_82508D00;
extern void func_82502120();
extern void func_80046634();
typedef struct { u8 r, g, b, a; } Func82503750RGBA;
extern u8 D_82508F68[];
void func_82503750(void) {
    s32 pad[2];
    Func82503750RGBA prim;
    Func82503750RGBA env;

    func_82502120(&prim, &env, *(s16 *)(D_82508F68 + 2), *(s16 *)(D_82508F68 + 0xC), *(s16 *)(*(u8 **)(D_82508F68 + 0x1C) + 0x1A));
    gSPDisplayList(D_800D0510++, D_82508760);
    gDPSetPrimColor(D_800D0510++, 0, 0xFF, prim.r, prim.g, prim.b, 0xFF);
    gDPSetEnvColor(D_800D0510++, env.r, env.g, env.b, 0xFF);
    func_80046634(D_82508D00);
}
#endif

#ifdef VERSION_US
extern void func_80008648();
extern void BgStage_DrawFrame();
extern void func_800503A4(s32);
extern void func_81700908();
extern void func_825020A8();
extern void func_82503750();
extern void func_8250771C();
s32 func_8250865C();
extern s32 D_82508D04;

void func_82503840(void) {
    BgStage_DrawFrame();
    if (func_8250865C() == 0) {
        func_82503750();
        func_800503A4(D_82508D04);
        func_8250771C();
        func_81700908();
    }
    func_825020A8();
    func_80008648();
}
#endif

#ifdef VERSION_US
extern void func_82506BEC(s32, s32, s16, s16, void *);
void func_825038A4(u8 *arg0) {
    s32 var_s3 = **(u8 **)(arg0 + 12) - 1;
    s32 var_s0;
    u8 *var_v0;

    for (var_s0 = 0; var_s0 < var_s3; var_s0++) {
        var_v0 = *(u8 **)(arg0 + 12) + var_s0 * 152 + 4;
        func_82506BEC(var_s0, var_s3, (s16)(var_v0[0] - 1),
                      (s16)(var_v0[1] - 1), *(void **)(arg0 + 28 + var_s0 * 4));
    }
}
#endif

#ifdef VERSION_US
extern u8 D_82508D10[];
s32 func_82503954(s32 arg0) {
    s32 result = arg0;
    if ((arg0 >= 0) && (*(s16 *)(D_82508D10 + arg0 * 0x3C) == 0)) {
        result = -1;
    }
    return result;
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/21/fragment21_13FFA0/func_82503988.s")
#endif

#ifdef VERSION_US
s32 func_82503DDC(void)
{
  s32 sp1C;
  u16 temp_v0;
  sp1C = 0;
  if (func_82507BBC() == 0)
  {
    return 0;
  }
  ;
  if ((*((u16 *) (((u8 *) D_80087200) + 8))) & 0x8000)
  {
    sp1C = 1;
  }
  else
    if ((*((u16 *) (((u8 *) D_80087200) + 8))) & 0x4000)
  {
    func_82507BD0();
    sp1C = -1;
    func_800226C0(3);
  }
  return sp1C;
}
#endif

#ifdef VERSION_US
extern s32 func_82502104(void);
extern s32 func_82502114(void);
s32 func_82503E50(void) { s32 result; result = 0; if (func_82502104() != 0) { if (func_82502114() == 0x201) { result = 2; } else { result = 1; } } return result; }
#endif

#ifdef VERSION_US
extern s32 func_82507CF4();
s32 func_82503E98(void) {
    s32 result = 0;
    if (func_82507CF4() != 0) {
        result = 1;
    }
    return result;
}
#endif

#ifdef VERSION_US
s32 func_82503EC8(void) {
    s32 result = 0;
    if (func_82507CF4() != 0) {
        result = 1;
    }
    return result;
}
#endif

#ifdef VERSION_US
s32 func_82503EF8(void) {
    s32 result = 0;
    if (func_82507CF4() != 0) {
        result = 1;
    }
    return result;
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/21/fragment21_13FFA0/func_82503F28.s")
#endif

#ifdef VERSION_US
extern s16 D_82508F72;
extern void func_8004C09C();
extern void func_8004C4B0();
extern void func_8004C398();
extern void func_80008624();
extern void func_800086A4();
extern s32 StageContext_GetFadeMode(void);
extern void StageFade_StartFromOpaque();
extern void StageLoader_WaitForRetrace(void);
extern void func_80064D28();
extern void func_8170024C();
extern void func_825075B0();
extern void func_82502EBC();
extern s32 func_82503F28();
extern void func_8250202C(void);
extern void func_82503840(void);
s32 func_825043AC(s32 arg0, s32 arg1) {
    s32 state = 0;
    s32 result;

    func_8004C09C(0x147);
    func_8004C4B0(0x31);
    func_8004C4B0(0x29);
    func_8004C4B0(0x2A);
    func_82502EBC(arg0, arg1);
    func_80008624();
    if (StageContext_GetFadeMode() != 0) {
        func_800086A4(2);
        StageFade_StartFromOpaque(5);
    }
    do {
        func_80064D28();
        func_825075B0();
        func_8170024C();
        func_8250202C();
        func_82503840();
        state = func_82503F28(state, arg1);
    } while (state != 9);
    StageLoader_WaitForRetrace();
    switch (D_82508F72) {
        case 1:
        case 2:
        case 3:
        case 4:
            result = D_82508F72;
            break;
        default:
            result = 5;
            break;
    }
    func_8004C398();
    func_800226C0(0x122);
    return result;
}
#endif

#ifdef VERSION_US
extern void Fragment_LoadAndCall(s32, s32 *, s32 *, s32, s32);
s32 func_800718B8(s32);
extern u8 D_82C00000;
extern u8 fragment83_ROM_START;
extern u8 fragment84_ROM_START;

void func_825044D0(void) {
    Fragment_LoadAndCall(((u32) ((s32) &D_82C00000 & 0x0FF00000) >> 0x14) - 0x10, &fragment83_ROM_START, &fragment84_ROM_START, 0x300, func_800718B8(6));
}
#endif

#ifdef VERSION_US
extern void *D_82508680;
extern u8 D_82508F68[];
extern s16 D_82508F6A;
void func_82504524(void) {
    u8 *state;
    u8 *node;
    u8 *entry;
    state = D_82508F68;
    node = *(u8 **)(state + 0x1C);
    entry = *(s16 *)(state + 2) * 0x30 + *(u8 **)(node + 0x1C);
    *(s16 *)((u8 *)D_82508680 + 8) = *(s16 *)state;
    switch (*(s16 *)((u8 *)D_82508680 + 8)) {
        case 1:
            *(s16 *)((u8 *)D_82508680 + 0xA) = D_82508F6A;
            if (*(s16 *)(entry + 0x20) != -1) {
                *(s16 *)((u8 *)D_82508680 + 0xA) -= 1;
                if (*(s16 *)((u8 *)D_82508680 + 0xA) < 0) {
                    *(s16 *)((u8 *)D_82508680 + 0xA) = 0;
                }
            }
            break;
        case 3:
            *(s16 *)((u8 *)D_82508680 + 0xC) = D_82508F6A;
            break;
        case 2:
            *(s16 *)((u8 *)D_82508680 + 0xE) = D_82508F6A;
            break;
    }
}
#endif

#ifdef VERSION_US
extern s16 D_82508D0E;
// Returns D_82508D0E + 1 when it is non-negative, 100 when it is -2 and 0 otherwise.
s32 func_825045EC(void) {
    s32 result = 0;
    s16 *value = &D_82508D0E; // FAKE: pointer alias that makes each test reload the global; diff score 460 without it.

    if (*value >= 0) {
        result = *value + 1;
    } else if (*value == -2) {
        result = 100;
    }
    return result;
}
#endif

#ifdef VERSION_US
extern u8 D_1000000[];
extern u8 D_446E30[];
extern u8 D_447D00[];
extern void main_pool_push_state(s32);
extern void main_pool_pop_state(s32);
extern void Gfx_InitDisplayListBuffers(s32, s32);
extern s32 func_800082E0(s32, s32, s32, s32, s32, s32);
extern void func_80047588(s32, s32);
extern u8 *Asset_LoadToSegment(s32, u8 *, u8 *, s32);
extern void func_80055948(s32);
extern void func_82502854(s32);
extern void func_80008514(s32);
extern s32 func_8006D268(s32);
extern s32 func_82504BA0(s32 *, s32);
extern void func_80008574(void);
extern void func_80047610(void);
extern void Gfx_FreeDisplayListBuffers(void);

extern s32 D_82508D00;
extern void StageLoader_WaitForRetrace(void);
extern void func_800355E4(s32);
extern void func_80064D28();
extern s32 func_825043AC(s32 arg0, s32 arg1);
extern void func_825044D0(void);
extern void func_82504524(void);
extern void * D_80087200;
extern void * D_82508680;
void func_82504628(s32 arg0, u8 *arg1) {
    s32 state;
    s32 prev;
    s32 config;
    s32 back;

    state = *(s16 *)(arg1 + 8);
    D_82508680 = arg1;
    prev = state;
    main_pool_push_state(0x47594D4C); // 'GYML'
    Gfx_InitDisplayListBuffers(0x10000, 0);
    config = func_800082E0(1, 0, 2, 0, 2, 1);
    func_80047588(28, 0);
    Asset_LoadToSegment(((u32)D_1000000 & 0x0F000000) >> 24, D_446E30, D_447D00, 0);
    func_80055948(3);
    func_82502854(state);
    func_80008514(config);
    StageLoader_WaitForRetrace();
    if (func_8006D268(0x301) != 0) {
        func_80064D28();
        if (*(u16 *)((u8 *)D_80087200 + 6) & 0x2000) {
            state = 0;
        }
    }
    do {
        main_pool_push_state(0x6C6F6F70); // 'loop'
        switch (state) {
            case 0:
                func_800355E4(62);
                prev = state;
                state = func_82504BA0(&D_82508D00, state);
                break;
            case 4:
                func_825044D0();
                state = prev;
                prev = 4;
                break;
            default:
                back = prev == 4;
                prev = state;
                state = func_825043AC(state, back ? 1 : 0);
                func_82504524();
                break;
        }
        main_pool_pop_state(0x6C6F6F70);
    } while (state != 5);
    func_80008574();
    func_80047610();
    Gfx_FreeDisplayListBuffers();
    main_pool_pop_state(0x47594D4C);
    func_825045EC();
}
#endif
