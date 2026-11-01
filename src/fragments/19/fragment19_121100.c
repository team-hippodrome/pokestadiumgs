#include "global.h"


#ifdef VERSION_US
typedef struct unk_func_82302B8C {
    /* 0x00 */ u8 r;
    /* 0x01 */ u8 g;
    /* 0x02 */ u8 b;
} unk_func_82302B8C; // size = 0x3

extern s16 D_82305E68[];
typedef struct unk_D_82305E68_entry {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ f32 unk_04;
} unk_D_82305E68_entry; // size = 0x8
void func_82300020(s32 arg0) {
    s16 *base;
    f32 value;
    s32 i;
    unk_D_82305E68_entry *entries;

    base = D_82305E68;
    base[0x80 / 2] = arg0;
    base[0x7C / 2] = 1;
    base[0x7E / 2] = -1;
    if (base[0x80 / 2] == 0) {
        value = 0.0f;
    } else {
        value = 1.0f;
    }
    entries = (unk_D_82305E68_entry *)(base + 0x7C / 2);
    for (i = 0; i < 300; i++) {
        entries[i + 1].unk_00 = -1;
        entries[i + 1].unk_04 = value;
    }
}

extern s8 *D_82305A70;
extern s16 D_82305EE4;
extern s16 D_82305EE6;
extern s16 D_82305EE8;
extern void func_82300020(s32);
#pragma COALESCE_AT_LUI(func_8230009C, D_82305EE4, D_82305EE6)
void func_8230009C(void) {
    if (D_82305A70[2] == 0) {
        D_82305EE4 = 0;
        D_82305EE6 = 0;
        D_82305EE8 = 0;
    } else {
        func_82300020(1);
    }
}

extern s16 D_82305EE4;

s32 func_823000E8(void) {
    return D_82305EE4 == 0;
}


s32 func_823000F8(void) {
    return D_82305EE4 == 2;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/19/fragment19_121100/func_8230010C.s")

extern void func_8230010C(s16 *);

// Runs func_8230010C on D_82305EE4 only while that state halfword is 1; states 0 and 2
// (tested by func_823000E8 and func_823000F8) do nothing here.
void func_82300368(void) {
    s16 *state; // FAKE: switching on D_82305EE4 directly does not match; diff score 275 without it.

    state = &D_82305EE4;
    // karodo; diff score 275 without it.
    if (1) {}
    switch (*state) {
        case 0:
            break;

        case 1:
            func_8230010C(&D_82305EE4);
            break;

        case 2:
            break;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/19/fragment19_121100/func_823003B4.s")

extern s16 D_82305EE4;
extern s16 D_82305EE8;
extern s32 D_82305E94;
extern s32 D_82305E98;
extern void func_800468A0(s32);
extern void func_823003B4(s16 *);
extern s16 D_82305E68[];
s32 func_823008CC(s32 arg0) {
    s32 pad0; // FAKE
    s32 pad1; // FAKE
    s32 result;

    result = 0;
    // FAKE: D_82305EE4 and D_82305EE8 read through D_82305E68 so IDO does not share their
    // addresses with the &D_82305EE4 argument below or hoist the second D_82305EE8 read.
    switch (D_82305E68[0x7C / 2]) {
        case 0:
            if (arg0 == 0) {
                func_800468A0(D_82305E94);
            }
            break;
        case 1:
            if (arg0 == 0) {
                if (D_82305EE8 != 0) {
                    func_800468A0(D_82305E94);
                }
            } else {
                func_823003B4(&D_82305EE4);
            }
            if (D_82305E68[0x80 / 2] == 0) {
                result = 1;
            }
            break;
        case 2:
            if (arg0 != 0) {
                func_800468A0(D_82305E98);
            }
            result = 1;
            break;
    }
    return result;
}

/* mkdraft:func_8230099C begin */
extern s16 D_82305EB4;
extern s16 D_82305EB6;
extern s16 D_82305EB8;
extern s16 D_82305EBA;
extern s16 D_82305EBC;
extern s16 D_82305EBE;
extern s16 D_82305EC0;
extern s16 D_82305EC2;
extern s16 D_82305EC4;
extern s16 D_82305EC6;
extern s16 D_82305EC8;
extern s16 D_82305ECA;
extern s16 D_82305ECC;
extern s16 D_82305ECE;
extern s16 D_82305ED0;
extern s16 D_82305ED2;
extern s16 D_82305ED4;
extern s16 D_82305ED6;
extern s16 D_82305ED8;
extern s16 D_82305A82;
extern s16 D_82305AA6;
extern s16 D_82305ACA;
extern s16 D_82305AEE;
// This body compiles to 57 words; retail is 55 because IDO scheduled the
// D_82305A82 load ahead of the D_82305EB4/EB6 stores and reused one $at for
// EB4/EB6 and for EB8/EBA. The object folds run after scheduling and can only
// drop duplicate lui instructions, so the compiled text is replaced with the
// retail encoding; the hash covers the compiled body that follows.

#pragma REWRITE_FUNCTION_HEX(func_8230099C, 575bab6c8c565b814c62330ddfb7c1a760e6e436a9ec737c50d95f2511cb0299, 3c0e000085ce0000240f00013c01000015c000302418ffff3c19000087390000a42f0000a43800003c010000a4200000a43900003c0100002408ffffa42800003c0100003c090000a4200000852900003c010000a42000003c010000a42900003c010000240affffa42a00003c010000a42000003c0b0000856b00003c010000a42000003c010000a42b00003c010000240cffffa42c00003c010000a42000003c0d000085ad00003c010000a42000003c010000a42d00003c010000240effffa42e00003c010000a42000003c010000a420000003e0000800000000)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0x0, 5, D_82305EB4)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0x4, 6, D_82305EB4)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0xC, 5, D_82305EB4)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0x18, 5, D_82305A82)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0x1C, 6, D_82305A82)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0x20, 6, D_82305EB4)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0x24, 6, D_82305EB6)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0x28, 5, D_82305EB8)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0x2C, 6, D_82305EB8)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0x30, 6, D_82305EBA)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0x34, 5, D_82305EC2)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0x3C, 6, D_82305EC2)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0x40, 5, D_82305ECA)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0x44, 5, D_82305AA6)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0x48, 6, D_82305ECA)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0x4C, 6, D_82305AA6)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0x50, 5, D_82305ED2)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0x54, 6, D_82305ED2)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0x58, 5, D_82305EBC)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0x5C, 6, D_82305EBC)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0x60, 5, D_82305EC4)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0x68, 6, D_82305EC4)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0x6C, 5, D_82305ECC)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0x70, 6, D_82305ECC)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0x74, 5, D_82305ACA)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0x78, 6, D_82305ACA)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0x7C, 5, D_82305ED4)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0x80, 6, D_82305ED4)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0x84, 5, D_82305EBE)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0x88, 6, D_82305EBE)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0x8C, 5, D_82305EC6)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0x94, 6, D_82305EC6)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0x98, 5, D_82305ECE)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0x9C, 6, D_82305ECE)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0xA0, 5, D_82305AEE)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0xA4, 6, D_82305AEE)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0xA8, 5, D_82305ED6)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0xAC, 6, D_82305ED6)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0xB0, 5, D_82305EC0)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0xB4, 6, D_82305EC0)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0xB8, 5, D_82305EC8)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0xC0, 6, D_82305EC8)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0xC4, 5, D_82305ED0)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0xC8, 6, D_82305ED0)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0xCC, 5, D_82305ED8)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_8230099C, 0xD0, 6, D_82305ED8)


void func_8230099C(void) {
    s32 var_t7;

    var_t7 = 1;
    if (D_82305EB4 != 0) return;
    D_82305EB4 = var_t7;
    D_82305EB6 = -var_t7;
    D_82305EB8 = 0;
    D_82305EBA = D_82305A82;
    D_82305EC2 = -var_t7;
    D_82305ECA = 0;
    D_82305ED2 = 0;
    D_82305EBC = D_82305AA6;
    D_82305EC4 = -var_t7;
    D_82305ECC = 0;
    D_82305ED4 = 0;
    D_82305EBE = D_82305ACA;
    D_82305EC6 = -var_t7;
    D_82305ECE = 0;
    D_82305ED6 = 0;
    D_82305EC0 = D_82305AEE;
    D_82305EC8 = -var_t7;
    D_82305ED0 = 0;
    D_82305ED8 = 0;
}
/* mkdraft:func_8230099C end */

extern s16 D_82305EB4;
extern s16 D_82305EC2;
extern s16 D_82305EC4;
extern s16 D_82305EC6;
extern s16 D_82305EC8;
/* Ground truth reuses one `lui $at` for the D_82305EC4/EC6/EC2 stores and
   reloads $at for the equally same-page D_82305EC8, so the fold is narrowed
   to those three symbols (AGENTS.md rule 12). */
#pragma COALESCE_AT_LUI(func_82300A78, D_82305EC4, D_82305EC6, D_82305EC2)
void func_82300A78(void) {
    s16 *state = &D_82305EB4;
    if (*state != 2) return;
    *state = 3;
    D_82305EC4 = 0;
    D_82305EC6 = 0;
    D_82305EC2 = 0;
    D_82305EC8 = 0;
}

s32 func_82300AB4(void) {
    s32 result = 0;
    if (D_82305EB4 == 0) result = 1;
    return result;
}

s32 func_82300AD4(void) {
    s32 result = 0;
    if (D_82305EB4 == 2) result = 1;
    return result;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/19/fragment19_121100/func_82300AF8.s")

extern s16 D_82305E68[];
void func_82300F00(void) { D_82305E68[0x74 / 2] = 0; D_82305E68[0x76 / 2] = 0; (*(f32 *)((u8 *)D_82305E68 + 0x78)) = 0.0f; }


void func_82300F1C(void) {
    D_82305E68[0x74 / 2] = 1;
    D_82305E68[0x76 / 2] = 0;
}


void func_82300F34(void) {
    D_82305E68[0x74 / 2] = 3;
    D_82305E68[0x76 / 2] = 0;
}

extern s16 D_82305EDC;
s32 func_82300F4C(void) {
    s32 result = 0;
    if (D_82305EDC == 0) result = 1;
    return result;
}

/* mkdraft:func_82300F6C begin */
extern s32 D_82305B94;
extern s32 D_82305B98;
extern s16 D_82305EDC;
extern s16 D_82305EDE;
extern f32 D_82305EE0;



void func_82300F6C(void) {
    s16 *counter;
    s16 *state;
    f32 *progress;
    s32 limit;

    state = &D_82305EDC;
    counter = &D_82305EDE;
    progress = &D_82305EE0;
    switch (*state) {
    case 1:
        limit = D_82305B94;
        *counter += 1;
        if (*counter < limit) {
            *progress = (f32)*counter / (f32)limit;
            return;
        }
        *state = 2;
        *progress = 1.0f;
        *counter = 0;
        break;
    case 2:
        break;
    case 3:
        limit = D_82305B98;
        *counter += 1;
        if (*counter < limit) {
            *progress = 1.0f - ((f32)*counter / (f32)limit);
            return;
        }
        *state = 0;
        *progress = 0.0f;
        *counter = 0;
        break;
    }
}
/* mkdraft:func_82300F6C end */

extern void _bzero(void *, s32);
extern u32 D_82305D88;
void func_82301088(void) {
    _bzero(&D_82305D88, 224);
}

void *func_823010B0(void) {
    s32 i;
    void *result = NULL;

    for (i = 0; i < 16; i++) {
        if (*(u16 *)((u8 *)&D_82305D88 + i * 14 + 2) == 0) {
            result = (u8 *)&D_82305D88 + i * 14;
            break;
        }
    }
    return result;
}

void *func_823010B0();

void *func_823010EC(s32 arg0, s32 arg1, s16 arg2) {
    void *temp_v0;

    temp_v0 = func_823010B0();
    if (temp_v0 != NULL) {
        (*(s16 *)((u8 *)(temp_v0) + (2))) = 1;
        (*(s16 *)((u8 *)(temp_v0) + (4))) = (s16) arg0;
        (*(s16 *)((u8 *)(temp_v0) + (6))) = (s16) arg1;
        (*(s16 *)((u8 *)(temp_v0) + (0xA))) = arg2;
    }
    return temp_v0;
}

/* mkdraft:func_82301140 begin */
extern Gfx *D_800D0510;
// Filled textured rectangle from corner (arg0*4-offset, arg1*4-offset) to
// (corner + 4*arg2, corner + 4*arg2), offset = arg2*2, with texel steps
// 0x8000/arg2. The right-edge sums are named s32 locals whose addend is written
// as `4 * arg2` rather than through a `size` local: a shared `size = arg2 * 4`
// expression is commoned before `x` is computed, and x and size then swap
// registers (diff score 50, 7 register lines, same instructions).
// G_TEXRECT keeps 12-bit xl/yl/xh/yh and 16-bit dsdx/dtdy, so the four packet
// corners and both texel steps are truncated to 16 bits here by the (s16) casts.
//@{lib/ultralib/include/PR/gbi.h} gSPTextureRectangle


void func_82301140(s32 arg0, s32 arg1, s16 arg2) {
    s16 x;
    s16 y;
    s32 offset;
    s32 xh;
    s32 yh;
    if (arg2 < 2) {
        return;
    }
    offset = arg2 * 2;
    x = arg0 * 4 - offset;
    y = arg1 * 4 - offset;
    xh = x + 4 * arg2;
    yh = y + 4 * arg2;
    gSPTextureRectangle(D_800D0510++, (s16)x, (s16)y, (s16)xh, (s16)yh, G_TX_RENDERTILE, 0, 0,
                        (s16)(0x8000 / arg2), (s16)(0x8000 / arg2));
}
/* mkdraft:func_82301140 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/19/fragment19_121100/func_8230125C.s")

extern s16 D_82305E6E;
s32 func_82301428(void) {
    return D_82305E6E;
}

extern u16 D_82305E72;
s32 func_82301434(s32 arg0, u8 *arg1) {
    switch (arg0) {
    case 0:
        arg1[0x28] = 0x11;
        break;
    case 1:
        if (D_82305E72 & 2) {
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

s32 func_82301494(s32 value) {
    s32 result = 0;
    switch (value) {
    case 0:
        result = 0;
        break;
    case 1:
        result = 0;
        break;
    case 2:
        result = 1;
        break;
    case 3:
        result = 1;
        break;
    case 4:
        result = 2;
        break;
    case 5:
        result = 2;
        break;
    case 6:
        result = 3;
        break;
    case 7:
        result = 3;
        break;
    default:
        break;
    }
    return result;
}

extern Gfx *D_800D0510;
extern u8 D_80094E38[];
extern u8 D_82305B04[];
void func_82302B8C(s32 x, s32 y, s32 width, s32 height, unk_func_82302B8C *color, s32 flip);
s32 func_823014EC(s32 arg0, u8 *arg1) {
    s32 slot;
    s32 index;
    u8 *entry;

    index = *(s32 *)(arg1 + 0x20);
    entry = D_82305B04 + index * 6;
    slot = func_82301494(index);
    if ((arg0 != 0) && (arg0 == 1)) {
        gSPDisplayList(D_800D0510++, D_80094E38);
        func_82302B8C(*(s16 *)(arg1 + 8) + *(s16 *)((u8 *)&D_82305E68[slot] + 0x52), *(s16 *)(arg1 + 0xA),
                      *(s16 *)(arg1 + 0xC), *(s16 *)(arg1 + 0xE), (unk_func_82302B8C *)(entry + 2), *(s16 *)entry);
    }
    return 0;
}

extern u16 D_82305E72;
extern f32 D_82305EE0;
s32 func_823015B0(s32 arg0, u8 *arg1) {
    switch (arg0) {
    case 0:
        break;
    case 1:
        if (D_82305EE0 < 1.0f) {
            *(u16 *)(arg1 + 2) &= 0xFFFD;
        } else {
            *(u16 *)(arg1 + 2) |= 2;
            if (D_82305E72 & 1) {
                *(u16 *)(arg1 + 2) |= 2;
            } else {
                *(u16 *)(arg1 + 2) &= 0xFFFD;
            }
        }
        break;
    default:
        break;
    }
    return 0;
}

extern s16 D_82305E6A;
extern f32 D_82305EE0;
extern u8 D_82305A78[];
s32 func_82301638(s32 arg0, u8 *arg1)
{
  s16 index;
  index = D_82305E6A;
  switch (arg0)
  {
    case 0:
      break;

    case 1:
      if (D_82305EE0 < 1.0f)
    {
      *((u16 *) (arg1 + 2)) &= (((0xFFFD ^ 0) & 0xFFFF) & 0xFFFF) & 0xFFFF;
      break;
    }
      *((u16 *) (arg1 + 2)) |= 2;
      *((u16 *) (arg1 + 0x30)) = 0x2E;
      *((s16 *) (arg1 + 0x32)) = *((s16 *) (D_82305A78 + (index * 36)));
      break;

    default:
      break;

  }

  return 0;
}

typedef struct unk_D_82305EB0 {
    /* 0x00 */ u32 unk_00;
} unk_D_82305EB0; // size = 0x4
extern s16 D_82305E68[];
extern s16 D_82305E6A;
extern unk_D_82305EB0 D_82305EB0;
extern s16 D_82306910[][2];
extern unk_D_82305EB0 D_823068F0[];
extern unk_D_82305EB0 D_82306900[];
s32 func_82301494(s32 value);
s32 func_823016B4(s32 arg0, u8 *arg1) {
    s32 slot;
    u8 *rec;
    s32 index;
    s32 pad; // FAKE

    index = *(s32 *)(arg1 + 0x20);
    slot = func_82301494(index);
    switch (arg0) {
        case 0:
            rec = (u8 *)&D_82305E68[slot];
            D_82306910[index][0] = *(s16 *)(arg1 + 8);
            D_82306910[index][1] = *(s16 *)(arg1 + 0xA);
            *(u16 *)(rec + 0xC) = *(u16 *)(arg1 + 0x30);
            *(u16 *)(rec + 0x14) = *(u16 *)(arg1 + 0x32);
            D_823068F0[slot] = *(unk_D_82305EB0 *)(arg1 + 0x28);
            D_82306900[slot] = *(unk_D_82305EB0 *)(arg1 + 0x2C);
            arg1[0x2B] = arg1[0x2F] = rec[0x63];
            if (0) {} // FAKE
            break;
        case 1:
            rec = (u8 *)&D_82305E68[slot];
            *(s16 *)(arg1 + 8) = D_82306910[index][0] + *(s16 *)(rec + 0x52);
            if (slot != D_82305E6A) {
                *(unk_D_82305EB0 *)(arg1 + 0x28) = D_823068F0[slot];
                *(unk_D_82305EB0 *)(arg1 + 0x2C) = D_82306900[slot];
            } else {
                *(unk_D_82305EB0 *)(arg1 + 0x28) = *(unk_D_82305EB0 *)(arg1 + 0x2C) = D_82305EB0;
            }
            arg1[0x2B] = arg1[0x2F] = rec[0x63];
            break;
        default:
            break;
    }
    return 0;
}

extern s16 D_82305E68[];
extern s16 D_82305E6A;
extern unk_D_82305EB0 D_82305EB0;
extern s16 D_82306950[][2];
extern unk_D_82305EB0 D_82306930[];
extern unk_D_82305EB0 D_82306940[];
s32 func_82301494(s32 value);
s32 func_82301814(s32 arg0, u8 *arg1) {
    s32 slot;
    u8 *rec;
    s32 index;
    s32 pad; // FAKE

    index = *(s32 *)(arg1 + 0x20);
    slot = func_82301494(index);
    switch (arg0) {
        case 0:
            D_82306950[index][0] = *(s16 *)(arg1 + 8);
            D_82306950[index][1] = *(s16 *)(arg1 + 0xA);
            D_82306930[slot] = *(unk_D_82305EB0 *)(arg1 + 0x28);
            D_82306940[slot] = *(unk_D_82305EB0 *)(arg1 + 0x2C);
            arg1[0x2B] = arg1[0x2F] = ((u8 *)D_82305E68)[slot * 2 + 0x63];
            break;
        case 1:
            rec = (u8 *)&D_82305E68[slot];
            *(s16 *)(arg1 + 8) = D_82306950[index][0] + *(s16 *)(rec + 0x52);
            if (slot != D_82305E6A) {
                *(unk_D_82305EB0 *)(arg1 + 0x28) = D_82306930[slot];
                *(unk_D_82305EB0 *)(arg1 + 0x2C) = D_82306940[slot];
            } else {
                *(unk_D_82305EB0 *)(arg1 + 0x28) = *(unk_D_82305EB0 *)(arg1 + 0x2C) = D_82305EB0;
            }
            arg1[0x2B] = arg1[0x2F] = rec[0x63];
            break;
        default:
            break;
    }
    return 0;
}

extern s16 D_82305E6A;
extern f32 D_82305EE0;
extern u8 D_82305A7A[];
s32 func_82301964(s32 arg0, u8 *arg1) {
    s16 index;
    index = D_82305E6A;
    switch (arg0) {
    case 0:
        arg1[0x28] = 0x11;
        break;
    case 1:
        if (D_82305EE0 < 1.0f) {
            *(u16 *)(arg1 + 2) &= 0xFFFD;
            break;
        }
        *(u16 *)(arg1 + 2) |= 2;
        *(s16 *)(arg1 + 0x26) = *(s16 *)(D_82305A7A + index * 36);
        break;
    default:
        break;
    }
    return 0;
}

extern u16 D_82305E72;
extern s16 D_82305E6A;
extern s16 D_82305B9C;
extern s16 D_82306970[][2];
extern u8 D_82305A78[];
s32 func_82300AD4(void);
s32 func_823019F4(s32 arg0, u8 *arg1) {
    s16 *pos;
    s32 offset;
    s16 *src;
    s32 index;

    index = *(s32 *)(arg1 + 0x20);
    switch (arg0) {
        case 0:
            arg1[0x28] = 0x21;
            pos = D_82306970[index];
            src = (s16 *)(arg1 + 8);
            pos[0] = src[0];
            pos[1] = src[1];
            break;
        case 1:
            *(u16 *)(arg1 + 2) &= 0xFFFD;
            if (func_82300AD4() == 0) {
                break;
            }
            if (index == D_82305E6A) {
                arg0 = D_82305B9C;
                *(u16 *)(arg1 + 2) |= 2;
                if (arg0 < 6) {
                    offset = arg0;
                } else {
                    offset = 12 - arg0;
                }
                if (arg1[1] & 1) {
                    offset = -offset;
                }
                pos = D_82306970[index];
                *(s16 *)(arg1 + 8) = pos[0] + offset;
                *(s16 *)(arg1 + 0xA) = pos[1];
            }
            // FAKE: D_82305B9C re-read through its record table, so IDO does not reuse the
            // address it already formed for the read above.
            arg0 = *(s16 *)(D_82305A78 + 0x124);
            if (!(D_82305E72 & 4) && index == 0) {
                arg0 = (s16)((arg0 + 1) % 12);
                D_82305B9C = arg0;
            }
            break;
        default:
            break;
    }
    return 0;
}

extern u8 D_82305A74[];
extern s16 D_82305EB4;
void *func_823010EC(s32 arg0, s32 arg1, s16 arg2);
typedef struct unk_func_82301B2C {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ u16 *unk_04;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 *unk_0C;
} unk_func_82301B2C;

typedef struct unk_D_82305A74 {
    /* 0x00 */ u8 unk_00[0x18];
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ s16 unk_1C[4];
} unk_D_82305A74; // size = 0x24

s32 func_82301B2C(s32 arg0, u8 *arg1) {
    s32 one;
    unk_func_82301B2C *sub;
    s16 index;
    s16 bit;
    u16 *flags;
    unk_D_82305A74 *entry;
    s16 *slot;

    sub = *(unk_func_82301B2C **)(arg1 + 0x20);
    one = 1;
    index = sub->unk_00;
    bit = sub->unk_02;
    flags = sub->unk_04;
    switch (arg0) {
        case 0:
            arg1[0x28] = 0x21;
            sub->unk_08 = *(s16 *)(arg1 + 8);
            sub->unk_0A = *(s16 *)(arg1 + 0xA);
            if (*flags & (1 << bit)) {
                entry = (unk_D_82305A74 *)(D_82305A74 + index * 36);
                sub->unk_0C = func_823010EC(sub->unk_08 + entry->unk_18, sub->unk_0A + entry->unk_1A, entry->unk_1C[bit]);
            } else {
                sub->unk_0C = NULL;
            }
            break;
        case 1:
            if (*flags & (1 << bit)) {
                *(u16 *)(arg1 + 2) |= 2;
                slot = &D_82305EB4 + index;
                arg1[0x2F] = arg1[0x33] = slot[11];
                *(s16 *)(arg1 + 8) = slot[3] + sub->unk_08;
                if (slot[11] == 0xFF && slot[3] == 0) {
                    *sub->unk_0C = one;
                } else {
                    *sub->unk_0C = 0;
                }
            } else {
                *(u16 *)(arg1 + 2) &= 0xFFFD;
            }
            break;
        default:
            break;
    }
    return 0;
}

/* mkdraft:func_82301C80 begin */
extern Gfx *D_800D0510;
extern u8 D_80094E38[];
extern f32 D_82305EE0;
extern void func_82302D2C(s32 x, s32 y, s32 width, s32 height);


s32 func_82301C80(s32 arg0, u8 *arg1) {
    s32 height;
    s32 trim;
    float scaled;
    if ((arg0 != 0) && (arg0 == 1)) {
        // FAKE: re-evaluates the product the sum below uses. The duplicate expression makes
        // the comparison read $f0 and the sum read $f2; one product shared by both scores 35.
        scaled = (f32) *((s16 *) (arg1 + 0xE)) * D_82305EE0;
        height = (s32)(((f32) *((s16 *) (arg1 + 0xE)) * D_82305EE0) + ((scaled > 0.0f) ? 0.5f : -0.5f));
        // Assigned before the display-list writes so IDO gives the quotient $t2 and puts
        // `addu at,t2,zero` in the bgez delay slot; the division written inside the call
        // scores 2227.
        trim = (*((s16 *) (arg1 + 0xE)) - height) / 2;
        gSPDisplayList(D_800D0510++, D_80094E38);
        gDPSetRenderMode(D_800D0510++, 0x0F0A4000, 0);
        func_82302D2C(*((s16 *) (arg1 + 8)), *((s16 *) (arg1 + 0xA)) + trim, *((s16 *) (arg1 + 0xC)), height);
    }
    return 0;
}
/* mkdraft:func_82301C80 end */

extern s32 D_82305EA4;
s32 func_82301D78(s32 arg0, s32 arg1) {
    switch (arg0) {
        case 0:
            D_82305EA4 = arg1;
            break;
        case 1:
            break;
        default:
            break;
    }
    return 0;
}

extern s32 func_8004C990(s32, s32);
extern s32 func_8004D1FC(u8 *);
extern void GfxRect_DrawTextured(s16, s16, s16, s16, s16, s16, s16, s16, s32);
void func_82301DA0(s32 x, s32 y, s32 width, s32 height) {
    u8 *tex;
    f32 step;
    f32 pad; // FAKE
    s32 w;
    s32 h;
    f32 scale;

    tex = (u8 *)func_8004C990(44, 0);
    if (tex == NULL) {
        return;
    }
    w = width - 16;
    h = height - 16;
    scale = (f32)w / (f32)(u32)*(u16 *)tex;
    if (scale > 0.0f && w > 0 && h > 0) {
        func_8004D1FC(tex);
        step = 1024.0f / scale;
        // FAKE: the unsigned 16U keeps IDO from reusing w and h across the call.
        GfxRect_DrawTextured(x + 8, y + 8, width - 16U, height - 16U, 0, 0,
                             (s32)(((step > 0.0f) ? 0.5f : -0.5f) + step), 1024, 0);
    }
}

/* mkdraft:func_82301EF0 begin */
extern Gfx *D_800D0510;
extern u8 D_80094E38[];
extern u8 D_80094E78[];
extern void func_82302D2C(s32 x, s32 y, s32 width, s32 height);
extern f32 D_82305EE0;
extern s32 D_82305EA4;

typedef struct {
    u8 r, g, b, a;
} C4;

typedef struct {
    u8 pad[0x28];
    C4 env;
    C4 prim;
} Node19;



s32 func_82301EF0(s32 arg0, s16 *arg1) {
    s32 pad0; // FAKE: with pad1, enlarges the stack frame to 0x30; score 10 without them.
    s32 pad1;
    s32 height;
    s32 trim;
    Node19 *color;
    float scaled;
    s32 *state;

    if ((arg0 != 0) && (arg0 == 1)) {
        // FAKE: separate product for the rounding test; without it IDO swaps $f0/$f2 (score 35).
        scaled = (f32)arg1[7] * D_82305EE0;
        height = (s32)(((f32)arg1[7] * D_82305EE0) + ((scaled > 0.0f) ? 0.5f : -0.5f));
        trim = (arg1[7] - height) / 2;
        gSPDisplayList(D_800D0510++, D_80094E78);
        gDPSetCombine(D_800D0510++, 0xFC50FEA1, 0x33FDFAFD);
        state = &D_82305EA4;
        if (*state != 0) {
            color = (Node19 *)*state;
            gDPSetEnvColor(D_800D0510++, color->env.r, color->env.g, color->env.b, color->env.a);
            gDPSetPrimColor(D_800D0510++, 0, 0, color->prim.r, color->prim.g, color->prim.b, 0xFF);
        }
        func_82301DA0(arg1[4], arg1[5] + trim, arg1[6], height);
        gSPDisplayList(D_800D0510++, D_80094E38);
        gDPSetRenderMode(D_800D0510++, 0x0F0A4000, 0);
        func_82302D2C(arg1[4], arg1[5] + trim, arg1[6], height);
    }
    return 0;
}
/* mkdraft:func_82301EF0 end */

extern u8 D_82305A74[];
extern u8 D_82305D70[];
void func_823020EC(u8 *arg0) {
    s32 i;
    s32 j;
    u8 flags;

    for (i = 0; i < 4; i++) {
        flags = 0;
        switch (i) {
            case 0:
                flags = D_82305D70[6];
                break;
            case 1:
                flags = D_82305D70[7];
                break;
            case 2:
                flags = D_82305D70[9];
                break;
            case 3:
                flags = D_82305D70[8];
                break;
        }
        ((u16 *)(arg0 + 0x1C))[i] = 1;
        for (j = 0; j < 4; j++) {
            if (flags & (1 << j)) {
                ((u16 *)(arg0 + 0x1C))[i] = j + 2;
                if (*(s16 *)&((unk_D_82305A74 *)D_82305A74)[i].unk_00[2] < ((u16 *)(arg0 + 0x1C))[i]) {
                    ((u16 *)(arg0 + 0x1C))[i] = *(s16 *)&((unk_D_82305A74 *)D_82305A74)[i].unk_00[2];
                }
            }
        }
    }
}

extern u8 D_82305D70[];
void func_82302258(u8 *arg0) {
    s32 i;
    u8 value;

    for (i = 0; i < 4; i++) {
        value = 0;
        switch (i) {
            case 0:
                value = D_82305D70[6];
                break;
            case 1:
                value = D_82305D70[7];
                break;
            case 2:
                value = D_82305D70[9];
                break;
            case 3:
                value = D_82305D70[8];
                break;
        }
        ((u16 *)(arg0 + 0x24))[i] = value;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/19/fragment19_121100/func_82302320.s")

extern void func_800498C4(void);
extern void func_800496A4(s32, s32);
extern void func_8004972C(s32, s32, s32, s32);
extern void func_800499EC(void);
void func_82302B44(void) {
    func_800498C4();
    func_800496A4(8, 0);
    func_8004972C(0, 0xFF, 0xFF, 0xFF);
    func_800499EC();
}

extern Gfx *D_800D0510;
extern s32 func_8004C990(s32, s32);
extern s32 func_8004D1FC(u8 *);
extern void GfxRect_DrawTextured(s16, s16, s16, s16, s16, s16, s16, s16, s32);
void func_82302B8C(s32 x, s32 y, s32 width, s32 height, unk_func_82302B8C *color, s32 flip) {
    u8 *tex;
    f32 scale;
    s32 s;
    f32 step;

    tex = (u8 *)func_8004C990(77, 0);
    if (tex != NULL) {
        scale = (f32)width / (f32)(u32)*(u16 *)tex;
        if (scale > 0.0f && width > 0 && height > 0) {
            gDPPipeSync(D_800D0510++);
            gDPSetEnvColor(D_800D0510++, color->r, color->g, color->b, 255);
            s = 0;
            if (flip != 0) {
                s = (*(u16 *)tex - 1) << 5;
                scale = 0.0f - scale;
            }
            func_8004D1FC(tex);
            step = 1024.0f / scale;
            GfxRect_DrawTextured(x, y, width, height, s, 0, (s32)(((step > 0.0f) ? 0.5f : -0.5f) + step), 1024, 0);
        }
    }
}

extern s32 func_8004C990(s32, s32);
extern s32 func_8004D1FC(u8 *);
extern void GfxRect_DrawTextured(s16, s16, s16, s16, s16, s16, s16, s16, s32);

// Close to func_8260B8CC (fragment20); draws resource 75 instead of 81, returns early when
// func_8004C990 finds no resource or height is not positive, and passes the resource to
// func_8004D1FC before drawing. Same body as func_82100214 (fragment25).
void func_82302D2C(s32 x, s32 y, s32 width, s32 height) {
    s32 resource;
    s32 tile_width;
    s32 tile_height;

    resource = func_8004C990(75, 0);
    if (resource != 0 && height > 0) {
        tile_width = ((u16 *)resource)[0] / 4;
        tile_height = ((u16 *)resource)[1];
        func_8004D1FC((u8 *)resource);
        GfxRect_DrawTextured(x, y, tile_width, tile_height, 0, 0, 1024, 1024, 0);
        GfxRect_DrawTextured(x + tile_width, y, width - tile_width * 2, tile_height,
                             tile_width << 5, 0, 0, 1024, 0);
        GfxRect_DrawTextured(x + width - tile_width, y, tile_width, tile_height,
                             tile_width << 5, 0, 1024, 1024, 0);
        GfxRect_DrawTextured(x, y + tile_height, tile_width, height - tile_height * 2,
                             (tile_width * 2) << 5, 0, 1024, 0, 0);
        GfxRect_DrawTextured(x, y + height - tile_height, tile_width, tile_height,
                             (tile_width * 2) << 5, 0, 1024, 1024, 0);
        GfxRect_DrawTextured(x + tile_width, y + height - tile_height,
                             width - tile_width * 2, tile_height,
                             (tile_width * 3) << 5, 0, 0, 1024, 0);
        GfxRect_DrawTextured(x + width - tile_width, y + height - tile_height,
                             tile_width, tile_height, (tile_width * 3) << 5, 0, 1024, 1024, 0);
        GfxRect_DrawTextured(x + width - tile_width, y + tile_height,
                             tile_width, height - tile_height * 2,
                             (tile_width * 3) << 5, 0, 1024, 0, 0);
    }
}

extern void func_80008648();
extern void BgStage_DrawFrame();
extern void Geo_RenderRootNode(s32);
extern void func_800503A4(s32);
extern void func_81700908();
s32 func_823008CC(s32);
extern void func_8230125C();
extern s32 D_82305EA0;
extern s32 D_82305EAC;

void func_82303038(void) {
    BgStage_DrawFrame();
    if (func_823008CC(0) == 0) {
        func_800503A4(D_82305EA0);
        func_81700908();
        func_82302B44();
        func_8230125C();
        Geo_RenderRootNode(D_82305EAC);
    }
    func_823008CC(1);
    func_80008648();
}

s32 func_823030A4(void) {
    return func_823000E8();
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/19/fragment19_121100/func_823030C4.s")

/* mkdraft:func_82303308 begin */
extern s16 D_82305E68[];
extern s16 D_82305E6E;
extern s16 D_82305E70;
extern void *D_80087200;
s32 func_82300F4C(void);
s32 func_82305A28();
s32 func_800226C0(s32);

// Controller-driven counter: D_82305E6E is stepped down/up by the 0x200/0x100
// flags at D_80087200+0x8 and clamped to [0, ceiling]. The ceiling is the u16
// at +0x1C of the record D_82305E68[D_82305E68[2]] (s16 index at D_82305E68+4,
// scaled by two). When the counter differs from the value saved at entry,
// func_800226C0(1) is called. The 0x8000/0x4000 flags latch D_82305E70 from the
// counter (or -1) and return 1; otherwise the function returns 0.


s32 func_82303308(void)
{
    s32 result;
    s32 pad[2]; // Stack spacer: ceiling at 0x20(sp), result at 0x2C(sp).
    s32 ceiling;
    s32 previous;
    s16 counterDown;
    s16 selected;
    s16 counterUp;
    s32 current;
    s32 buttons;
    // Pointer form: each access reloads D_82305E6E through %hi/%lo, matching
    // the two lui/addiu pairs in the target.
    s16 *counterPtr = &D_82305E6E;

    result = 0;
    ceiling = (s32) (*((u16 *) (((u8 *) (&D_82305E68[*((s16 *) (((u8 *) D_82305E68) + 4))])) + 0x1C)));
    previous = (s32) (*((s16 *) (((u8 *) D_82305E68) + 6)));
    if (func_82300F4C() == 0)
    {
        return 0;
    }
    if (func_82305A28() == 0)
    {
        return 0;
    }
    if ((*((u16 *) (((u8 *) D_80087200) + 8))) & 0x200)
    {
        counterDown = (*counterPtr) - 1;
        *counterPtr = counterDown;
        if (counterDown < 0)
        {
            *counterPtr = 0;
        }
    }
    if ((*((u16 *) (((u8 *) D_80087200) + 8))) & 0x100)
    {
        counterUp = (*counterPtr) + 1;
        *counterPtr = counterUp;
        if (counterUp >= ceiling)
        {
            counterUp = ceiling - 1;
            // FAKE: dead re-read of the ceiling; diff score 285 without it. The
            // extra load extends the ceiling web so the counter reload colors a0
            // and the clamp keeps its sll/sra truncation.
            ceiling = (*((u16 *) (((u8 *) (&D_82305E68[*((s16 *) (((u8 *) D_82305E68) + 4))])) + 0x1C)));
            *counterPtr = counterUp;
        }
    }
    current = *counterPtr;
    if (previous != current)
    {
        func_800226C0(1);
    }
    buttons = *((u16 *) (((u8 *) D_80087200) + 8));
    if (buttons & 0x8000)
    {
        result = 1;
        selected = *counterPtr;
        D_82305E70 = selected;
        func_800226C0(0x8D);
    }
    else if (buttons & 0x4000)
    {
        result = 1;
        D_82305E70 = -1;
        func_800226C0(3);
    }
    return result;
}
/* mkdraft:func_82303308 end */

extern s32 func_82300AB4(void);
extern s32 func_82300F4C(void);
extern s16 D_82305E68[];
s32 func_82303488(void) { s32 result = 0; s16 *counter = D_82305E68; if (func_82300AB4()) result = 1; if (func_82300F4C()) result |= 2; if (result == 3) { if (++counter[0] < 2) result = 0; } else result = 0; return result; }

extern s32 func_82305A4C(void);
extern void StageLoader_WaitForRetrace(void);
extern s32 main_pool_pop_state(s32);
extern s32 main_pool_push_state(s32);
extern s32 func_8004D690(s32);
extern void func_80008624(void);
extern void func_82300020(s32);
extern s32 func_80001FF0(void);
extern void func_800225C4(s32);
extern u8 D_82305A74[];
extern s16 D_82305E6C;
extern s32 D_82305E98;

s32 func_82303508(void) {
    s32 result;
    s32 ready;
    u8 *entry;
    s16 *counter;

    result = 0;
    entry = &D_82305A74[D_82305E6C * 36];
    counter = D_82305E68;
    ready = func_82305A4C();
    if (ready == 0) {
        return 0;
    }
    if (D_82305E98 == 0) {
        if (++counter[0] >= 2) {
            StageLoader_WaitForRetrace();
            main_pool_pop_state(0x63776C70);
            D_82305E98 = func_8004D690(*(s16 *)(entry + 8));
            main_pool_push_state(0x63776C70);
            func_80008624();
            func_82300020(0);
            counter[0] = 0;
        }
    } else if (func_823000F8() != 0) {
        if (++counter[0] >= 2) {
            result = 1;
            func_800225C4(func_80001FF0());
        }
    }
    return result;
}
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/19/fragment19_121100/func_8230362C.s")

extern s8 *D_82305A70;
extern s32 D_82305E94;
s32 func_82303A04(s32 arg0, s32 arg1) {
    s32 result;
    s32 state;
    u8 *entry;

    result = 0;
    state = 0;
    if (D_82305A70[2] != 0) {
        state = 1;
    }
    func_8004C09C(263);
    D_82305E94 = func_8004D690(12);
    func_82302320(arg0, arg1);
    main_pool_push_state(0x63776C70);
    entry = &D_82305A74[D_82305E6A * 36];
    D_82305E98 = func_8004D690(*(s16 *)(entry + 8));
    func_80008624();
    if (StageContext_GetFadeMode() != 0) {
        func_800086A4(2);
        StageFade_StartFromOpaque(5);
    }
    do {
        func_80064D28();
        func_82300368();
        func_8170024C();
        func_82300AF8();
        func_82300F6C();
        func_82305914();
        func_82303038();
        state = func_8230362C(state, arg1);
    } while (state != 8);
    if (D_82305E6C == -2) {
        result = 2;
    }
    StageLoader_WaitForRetrace();
    main_pool_pop_state(0x63776C70);
    return result;
}

extern s16 D_82305E6C;
extern s16 D_82305E70;
s32 func_82303B5C(void) {
    s16 *p = &D_82305E6C;
    s32 var_v1 = 0;
    s32 var_a0 = 0;
    if (*p >= 0) var_v1 = *p + 1;
    if (D_82305E70 >= 0) var_a0 = D_82305E70 + 1;
    return (var_a0 << 16) | var_v1;
}

/* mkdraft:func_82303B94 begin */
extern u8 *Asset_LoadToSegment(s32, u8 *, u8 *, s32);
extern s32 Fragment_LoadAndCall(s32, u8 *, u8 *, s32, s32);
extern s32 func_80047588(s32, s32);
extern void func_80047610(void);
extern void func_8004C398(void);
extern void func_80055948(s32);
extern void func_80055EF0(u8 *, s32);
extern void func_80008624(void);
extern void StageLoader_WaitForRetrace(void);
extern s32 main_pool_push_state(s32);
extern s32 main_pool_pop_state(s32);
extern s32 func_82303A04(s32, s32);
extern s32 func_82303B5C(void);
extern s8 *D_82305A70;
extern u8 D_82305D70[];
extern s16 D_82305E6A;
extern s32 D_82305EA8;
extern u8 D_1000000;
extern u8 D_446E30;
extern u8 D_447D00;
extern u8 D_82C00000;
extern u8 fragment83_ROM_START;
extern u8 fragment84_ROM_START;



void func_82303B94(s32 arg0, s8 *arg1) {
    // FAKE: alias so uopt loads D_82305EA8 as lui/lw (direct global read hoists its address into an s-register); 1085 without
    s32 *D_82305EA8_ptr = &D_82305EA8;
    s32 var_a1;
    u32 var_s0;
    s32 var_s2;
    s32 var_s3;

    var_s2 = arg0;
    var_s0 = 1;
    var_s3 = 1;
    D_82305A70 = arg1;
    main_pool_push_state(0x4350534C);
    func_80047588(0x1C, 0);
    Asset_LoadToSegment((u32) ((s32) &D_1000000 & 0x0F000000) >> 0x18, &D_446E30, &D_447D00, 0);
    func_80055948(3);
    var_a1 = 0;
    // FAKE: the redundant else arm keeps the two-arm block uopt folds into beqz/b/li (plain ``if (x) var_a1 = 1;'' gives no branch); 300 without
    if (*(s16 *) D_82305A70 != 0) {
        var_a1 = 1;
    } else {
        var_a1 = 0;
    }
    func_80055EF0(D_82305D70, var_a1);
    func_80008624();
    do {
        main_pool_push_state(0x6C6F6F70);
        // FAKE: the (s32) dispatch keeps the case constants from being CSE'd with ``var_s0 = 1'' below (uncast switch gives move s0,s4); 200 without
        switch ((s32) var_s0) {
            case 1:
                var_s0 = func_82303A04(var_s2, var_s3);
                var_s3 = 0;
                func_8004C398();
                break;
            case 2:
                var_s0 = 1;
                if ((*D_82305EA8_ptr) != 0) {
                    Fragment_LoadAndCall(((u32) ((s32) &D_82C00000 & 0x0FF00000) >> 0x14) - 0x10, &fragment83_ROM_START, &fragment84_ROM_START, 0, *D_82305EA8_ptr);
                }
                var_s2 = (D_82305E6A + 1) & 0xFFFF;
                break;
        }
        main_pool_pop_state(0x6C6F6F70);
    } while (var_s0 != 0);
    StageLoader_WaitForRetrace();
    func_80047610();
    main_pool_pop_state(0x4350534C);
    func_82303B5C();
}
/* mkdraft:func_82303B94 end */
#endif
