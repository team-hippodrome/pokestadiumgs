#include "global.h"


#ifdef VERSION_US
void func_8160A270(u8 *arg0) {
    s32 i;

    for (i = 0; i < 6; i++) {
        *(u8 *)((u8 *)arg0 + i * 0xCE8 + 0x3E) &= 0xFFFD;
    }
}
s32 func_8160A2E8(s32 arg0) {
    return ((arg0 % 3) * 0x9A) + 0xC;
}

s32 func_8160A31C(s32 arg0) {
    s32 quotient = arg0 / 3;
    return quotient * 65 + 9;
}

void *func_8160A33C(void *arg0, s32 arg1) {
    while (arg1-- > 0) {
        arg0 = *(void **)((u8 *)arg0 + 0x4D98);
    }
    return arg0;
}

void *func_8160A360(void *arg0, s32 arg1) {
    while (arg1-- > 0) {
        arg0 = *(void **)((u8 *)arg0 + 0x4D94);
    }
    return arg0;
}

void func_8160A384(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 pad[4];
    u8 buffer[0x180];
    u8 *src;
    u8 *dst;
    u8 *end;

    func_80055A74(arg1);
    _bzero(buffer, 0x180);
    src = (u8 *)arg0 + 0x20;
    dst = buffer + 0x10;
    end = buffer + 0x178;
    while (dst != end) {
        func_80051864(src, dst);
        dst += 0x3C;
        src += 0xCE8;
    }
    buffer[0x178] = (u8)arg3;
    func_80055B14(buffer, arg2);
    func_800535D4(0x10, arg2, (u8 *)arg0 + 0x11, (u8 *)arg0 + 0x11,
                  *(u16 *)((u8 *)arg0 + 0x4D90));
    func_80051D64(0x10, arg2);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/11/fragment11_E1E10/func_8160A438.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/11/fragment11_E1E10/func_8160A50C.s")

// Clears bytes 0x0B-0x10 of arg0.
void func_8160A6AC(void *arg0) {
    s32 i;

    for (i = 0; i < 6; i++) {
        ((u8 *)arg0)[i + 0xB] = 0;
    }
}

extern void func_8004D878(s32, s32, s32);
void func_8160A6D0(s32 arg0, s32 arg1) {
    s32 offset = arg1 * 0xCE8;
    u8 *temp_v0 = (u8 *)((u32)arg0 + offset);
    if (temp_v0[0x20] != 0) {
        func_8004D878((s32)(temp_v0 + 0x80), 0x84, 0);
    }
}

extern void func_8004D878(s32, s32, s32);
void func_8160A72C(s32 arg0) {
    s32 var_s0;
    s32 var_s1;

    var_s0 = 0;
    var_s1 = arg0 + 0x80;
    do {
        func_8004D878(var_s1, 0x84, 0);
        var_s0 += 0xCE8;
        var_s1 += 0xCE8;
    } while (var_s0 != 0x4D70);
}

s32 func_8160A780(s32 arg0, s32 slot) {
    s32 i;
    s32 count;
    s32 removed;
    u8 buffer[384];

    removed = 0;
    count = Deck_FindFirstFreeTeamSlot();
    func_80055A74(arg0);
    for (i = slot; i < count; i++) {
        removed = 1;
        _bzero(buffer, sizeof(buffer));
        if (i + 1 < count) {
            func_80055A9C(buffer, i + 1);
        }
        func_80055B14(buffer, i);
        func_80051D64(0x10, i);
    }
    if (removed) {
        func_80055028();
    }
    return removed;
}

s32 func_8160A844(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 pad[4];
    u8 buffer[0x180];
    u8 *src;
    u8 *dst;
    u8 *zero_dst;

    func_80055A74(arg2);
    func_80055A9C(buffer, arg3);
    func_80053440(0x10, arg3, arg1);
    src = arg0;
    zero_dst = arg0;
    arg0 = buffer + 0x178;
    dst = buffer + 0x10;
    while (dst != arg0) {
        func_80051830(src, dst);
        dst += 0x3C;
        src += 0x60;
        zero_dst += 0x60;
        *(s32 *)(zero_dst - 8) = 0;
    }
    return buffer[0x178];
}

s32 func_8160A8DC(arg0)
u8 *arg0;
{
    s32 i = 0;
    s32 stride = 0xCE8;
    if (arg0[0x20] != 0) {
        do {
            i++;
            if (i >= 6) {
                break;
            }
        } while (*(u8 *)((u32)arg0 + i * stride + 0x20) != 0);
    }
    return i;
}

s32 func_8160A920(u8 *arg0) {
    return *(s8 *)(arg0 + 8);
}

void func_8160A928(u8 *arg0, s32 arg1) {
    arg1 += 6;
    arg1 %= 6;
    arg0[9] = arg1;
    arg0[8] = arg1;
    *(f32 *)(arg0 + 4) = 0.0f;
}

void func_8160A94C(void* arg0) {
    s32 var_v0;

    for (var_v0 = 0; var_v0 < 6; var_v0++) {
        *((u8*)arg0 + var_v0 * 3304 + 0x20) = 0;
    }
}

extern void func_8160A94C(void *);
extern volatile u8 D_8160C2E0;
void func_8160A994(u8 *arg0)
{
  func_8160A94C(arg0);
  *((u16 *) (arg0 + 0x4D90)) = 0;
  arg0[0x11] = D_8160C2E0 & 0xFFFFu;
}

#ifdef CC_CHECK
s32 func_8160A8DC(u8 *);
#else
s32 func_8160A8DC();
#endif

s32 func_8160A9CC(void) {
#ifdef CC_CHECK
    return func_8160A8DC((u8 *)0) >= 6;
#else
    return func_8160A8DC() >= 6;
#endif
}

/* mkdraft:func_8160A9F0 begin */


s32 func_8160A9F0(u8 *arg0) {
    typedef struct { u8 bytes[0xCE8]; } Record;
    s32 limit = func_8160A8DC(arg0);
    s32 best_sum = 0x258;
    s32 i, j, k;

    for (i = 0; i < limit; i++) {
        for (j = i + 1; j < limit; j++) {
            for (k = j + 1; k < limit; k++) {
                s32 sum = ((Record *)arg0)[i].bytes[0x3D] +
                          ((Record *)arg0)[j].bytes[0x3D] +
                          ((Record *)arg0)[k].bytes[0x3D];
                if (best_sum >= sum) {
                    best_sum = sum;
                }
            }
        }
    }
    return best_sum;
}
/* mkdraft:func_8160A9F0 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/11/fragment11_E1E10/func_8160ABF0.s")

/* mkdraft:func_8160B128 begin */
extern void func_81607360(s32);
extern void func_81607408();
extern void func_81605D24(s32, s32, s32, s32, u8 *);
extern void func_8160615C(s32, s32, s32, f32);
extern void func_81605F94(s32, s32, s32, u8 *, f32);
extern void func_800498C4(void);
extern void func_800496A4(s32, s32);
extern void func_8004972C(s32, s32, s32, s32);
extern s32 func_8004C990(s32, s32);
extern s32 func_8004D19C(s32, s32, s32, s32, s32);
extern void *func_8004C874(s32, s32);
extern void func_800495BC(s32, s32, const char *, ...);
extern void func_800499EC(void);
extern u32 D_800D0510;
extern u8 D_80094E38[];
extern u8 D_80094F50[];
extern u8 D_8160BF20[3];
extern u8 D_8160BF24[][3];
extern char D_8160C2F8[];



void func_8160B128(s32 x, s32 y, s32 arg2, s32 arg3, s32 arg4, s8 *arg5, u16 arg6, s32 arg7, f32 scale, s32 rect) {
    s32 valid;
    s32 cond;

    cond = arg7 > 0 && arg7 < 6;
    if (rect != 0) {
        func_81607360(rect);
    }
    valid = arg2 >= 0;
    func_81605D24(x - 6, y - 9, (cond ? 0xB1 : 0) + 0x121, 0x28, D_8160BF24[valid ? 4 : arg4]);
    if (valid) {
        func_8160615C(x, y, arg2 + 1, 1.0f);
    } else {
        func_81605F94(x - 1, y - 0x12, arg3, D_8160BF20, 1.0f);
    }
    if (cond) {
        gSPDisplayList((*(Gfx **)&D_800D0510)++, D_80094E38);
        gDPSetEnvColor((*(Gfx **)&D_800D0510)++, 0xFF, 0x6E, 0x3C, 0xFF);
        func_8004D19C(x + 0x12E, y - 0x11, func_8004C990(0x30, 0), 0, 0);
        gSPDisplayList((*(Gfx **)&D_800D0510)++, D_80094F50);
    }
    func_800498C4();
    func_8004972C(0xFF, 0xFF, 0xFF, (s32)(255.0f * scale));
    if (arg5[0] != 0) {
        func_800496A4(8, 1);
        func_800495BC(x + 0x34, y - 0x11, (char *)arg5);
        func_800496A4(4, 0);
        func_800495BC(x + 0x9F, y - 0xD, D_8160C2F8, func_8004C874(0xD, 9), arg6);
    }
    if (cond) {
        func_800496A4(4, 0);
        func_800495BC(x + 0x142, y - 0xF, func_8004C874(0xF, arg7 + 0x3A));
    }
    func_800499EC();
    if (rect != 0) {
        func_81607408();
    }
}
/* mkdraft:func_8160B128 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/11/fragment11_E1E10/func_8160B3E0.s")

extern void func_81604944(s32, s32, s32, s32, s32 *, s32 *);
extern void func_81607360(s32);
extern void func_81607408();
extern void func_81608A38(s32, s32, s32, s32);
extern u8 D_8160BF10;
extern u8 D_8160BF18;
void func_8160B54C(s32 arg0, s32 arg1, s32 arg2) {
    func_81607360(arg2);
    func_81604944(arg0, arg1, 0x1D9, 0x8F, &D_8160BF18, &D_8160BF10);
    func_81608A38(arg0, arg1, 7, 0x3F800000);
    func_81607408();
}

void func_8160B5BC(u8 *arg0, u8 *arg1) {
    f32 ratio;
    f32 inv_ratio;

    *(s16 *)(arg1 + 4) = 140;
    *(s16 *)(arg1 + 6) = 57;
    if (*(s8 *)(arg0 + 8) == *(s8 *)(arg0 + 9)) {
        *(s16 *)(arg1 + 0) = func_8160A2E8(*(s8 *)(arg0 + 8));
        *(s16 *)(arg1 + 2) = func_8160A31C(*(s8 *)(arg0 + 8));
        return;
    }
    ratio = *(f32 *)(arg0 + 4) / 4;
    inv_ratio = 1.0f - ratio;
    *(s16 *)(arg1 + 0) = (s16)((func_8160A2E8(*(s8 *)(arg0 + 8)) * ratio) + (func_8160A2E8(*(s8 *)(arg0 + 9)) * inv_ratio));
    *(s16 *)(arg1 + 2) = (s16)((func_8160A31C(*(s8 *)(arg0 + 8)) * ratio) + (func_8160A31C(*(s8 *)(arg0 + 9)) * inv_ratio));
}

extern u8 D_800CE060[];
s32 func_8160B6E4(void *arg0) {
    s8 a3;
    s8 v1;
    u16 a2;
    u8 *entry;

    a3 = ((s8 *)arg0)[9];
    v1 = ((s8 *)arg0)[8];
    if (v1 == a3) {
        entry = D_800CE060 + ((u8 *)arg0)[0xA] * 40;
        a2 = *(u16 *)(entry + 0xC);
        if ((a2 & 0x800) && (v1 >= 3)) {
            func_800226C0(1);
            a3 = ((s8 *)arg0)[9];
            ((s8 *)arg0)[8] = ((s8 *)arg0)[8] - 3;
            v1 = ((s8 *)arg0)[8];
        } else if ((a2 & 0x400) && (v1 < 3)) {
            func_800226C0(1);
            a3 = ((s8 *)arg0)[9];
            ((s8 *)arg0)[8] = ((s8 *)arg0)[8] + 3;
            v1 = ((s8 *)arg0)[8];
        } else if ((a2 & 0x100) && (v1 % 3 != 2)) {
            func_800226C0(1);
            a3 = ((s8 *)arg0)[9];
            ((s8 *)arg0)[8] = ((s8 *)arg0)[8] + 1;
            v1 = ((s8 *)arg0)[8];
        } else if ((a2 & 0x200) && (v1 % 3 != 0)) {
            func_800226C0(1);
            a3 = ((s8 *)arg0)[9];
            ((s8 *)arg0)[8] = ((s8 *)arg0)[8] - 1;
            v1 = ((s8 *)arg0)[8];
        }
    }
    return v1 != a3;
}

f32 func_816092FC();

s32 func_8160B828(void *arg0)
{
  if ((*((s8 *) (((u8 *) arg0) + 8))) != (*((s8 *) (((u8 *) arg0) + 9))))
  {
    *((f32 *) (((u8 *) arg0) + 4)) = (f32) (func_816092FC() + (*((f32 *) (((u8 *) arg0) + 4))));
    if ((*((f32 *) (((u8 *) arg0) + 4))) >= 4.0f)
    {
      *((s8 *) (((u8 *) arg0) + 9)) = (s8) (*((s8 *) (((u8 *) arg0) + 8)));
      *((f32 *) (((u8 *) arg0) + 4)) = 0.0f;
    }
    return 1;
  }
  *((f32 *) (((u8 *) arg0) + 4)) = 0.0f;
  return 0;
}
extern void func_8160A6AC(void *);
void func_8160B8A8(u8 *arg0, s32 arg1, s32 arg2) {
    arg0[9] = 0;
    arg0[10] = arg1;
    *(s32 *)arg0 = arg2;
    ((s8 *)arg0)[8] = ((s8 *)arg0)[9];
    *(f32 *)(arg0 + 4) = 0.0f;
    func_8160A6AC(arg0);
}

s32 func_8160B8E0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3) {
    struct Record { u32 words[826]; };
    u8 *entry;

    entry = (u8 *)((u32)arg0 + arg2 * 0xCE8);
    if (*(s32 *)(entry + 0x78) == 0 ||
        *(s32 *)(arg1 + 0x58) != *(s32 *)(entry + 0x78) ||
        arg1[0] != entry[0x20]) {
        *(struct Record *)(entry + 0x20) = *(struct Record *)arg1;
        arg0[arg2 + 0xB] = 1;
        if (arg3 != 0) {
            func_800226C0(0x98);
        }
        return 1;
    }
    return 0;
}

s32 func_8160B9A0(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *entry = (u8 *)((u32)arg0 + arg1 * 0xCE8);
    if (entry[0x20] != 0) {
        entry[0x20] = 0;
        *(s32 *)(entry + 0x78) = 0;
        arg0[arg1 + 0xB] = 1;
        if (arg2 != 0) {
            func_800226C0(0x98);
        }
        return 1;
    }
    return 0;
}
#endif
