#include "global.h"


#ifdef VERSION_US
s32 func_8411DC80(u16 arg0, s32 *arg1, s32 arg2) {
    arg2 >>= 1;
    while (arg2--) {
        if (arg0 == *(u16 *)arg1) {
            return 1;
        }
        arg1 = (s32 *)((u8 *)arg1 + 2);
    }
    return 0;
}

extern u8 *D_84193DD0;
extern s32 func_8411E1F8(s32);
void func_8411DCCC(u8 *arg0, f32 *arg1) {
    s32 index;
    arg1[0] = *(f32 *)(arg0 + 0x24);
    arg1[2] = *(f32 *)(arg0 + 0x2C);
    index = func_8411E1F8((s32)arg0);
    if ((*(u16 *)((u8 *)(u32)D_84193DD0 + (index << 4) + 0x12) & 2) != 0) {
        arg1[1] = *(f32 *)(arg0 + 0x638) + 200.0f;
    } else {
        index = func_8411E1F8((s32)arg0);
        if ((*(u16 *)((u8 *)(u32)D_84193DD0 + (index << 4) + 0x12) & 4) != 0) {
            arg1[1] = 0.0f;
        } else {
            arg1[1] = *(f32 *)(arg0 + 0x638);
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_38D510/func_8411DD8C.s")

#ifdef CC_CHECK
extern void func_8411DD8C(void *, void *);
#else
extern void func_8411DD8C(void);
#endif
#ifdef CC_CHECK
void func_8411E084(void *arg0, void *arg1) {
    func_8411DD8C(arg0, arg1);
#else
void func_8411E084(void) {
    func_8411DD8C();
#endif
}

extern f32 D_80087E50[];
extern f32 D_80088E50[];
void func_8411E0A4(void *arg0, void *arg1, void *arg2) {
#ifndef CC_CHECK
    extern void func_8411DD8C();
#endif
    func_8411DD8C(arg0, arg1);
    *(f32 *)((u8 *)arg1 + 4) += *(f32 *)((u8 *)arg2 + 0x7C);
    *(f32 *)((u8 *)arg1 + 0) += *(f32 *)((u8 *)arg2 + 0x78) * D_80087E50[*(u16 *)((u8 *)arg0 + 0x20) >> 4];
    *(f32 *)((u8 *)arg1 + 8) += *(f32 *)((u8 *)arg2 + 0x78) * D_80088E50[*(u16 *)((u8 *)arg0 + 0x20) >> 4];
}

extern s32 D_84191208;
s32 func_8411E140(s32 arg0) {
    if (arg0 == D_84191208) return 0x4000;
    return -0x4000;
}

extern s32 D_84191208, D_8419120C;
s32 func_8411E164(s32 arg0) {
    if (arg0 == D_84191208) return D_8419120C;
    return D_84191208;
}

s32 func_8411E188(s8 arg0) {
    if (arg0 == 0) return D_84191208;
    return D_8419120C;
}

f32 func_8411E1B4(u8 *arg0) {
    return *(f32 *)(arg0 + 0x648);
}

f32 func_8411E1BC(u8 *arg0) {
    return *(f32 *)(arg0 + 0x648) - *(f32 *)(arg0 + 0x650);
}

f32 func_8411E1CC(u8 *arg0) {
    return *(f32 *)(arg0 + 0x64C);
}

s32 func_8411E1D4(s32 arg0) {
    if (arg0 == D_84191208) return 1;
    return -1;
}

s32 func_8411E1F8(s32 arg0) {
    if (arg0 == D_84191208) return 0;
    return 1;
}

s32 func_8411E21C(u8 *arg0) {
    return *(u8 *)(arg0 + 0x61C);
}

s32 func_8411E224(u8 *arg0) {
    return *(u8 *)(arg0 + 0x61D);
}

s32 func_8411E22C(u8 *arg0) {
    return *(u8 *)(*(u8 **)(arg0 + 0x2D4) + 0x13DA);
}

s32 func_8411E238(u8 *arg0) {
    return *(u8 *)(*(u8 **)(arg0 + 0x2D4) + 0x13DB);
}

u8 func_8411E244(void *arg0, s32 arg1) {
    switch (arg1) {
    case 276:
    case 277:
    case 278:
    case 279:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x45];
    case 280:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x40];
    case 274:
    case 290:
    case 292:
    case 298:
    case 299:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x4A];
    case 252:
    case 253:
    case 272:
    case 273:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[4];
    case 254:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[9];
    case 271:
    case 296:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0xE];
    case 255:
        return (*(u8 **)((u8 *)arg0 + 0x2D4))[0x13DA];
    case 281:
        return (*(u8 **)((u8 *)arg0 + 0x2D4))[0x13C7];
    case 282:
    case 283:
    case 294:
        return (*(u8 **)((u8 *)arg0 + 0x2D4))[0x13C6];
    case 256:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x13];
    case 257:
    case 258:
    case 259:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x18];
    case 260:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x1D];
    case 261:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x22];
    case 264:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x27];
    case 265:
    case 266:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x2C];
    case 267:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x31];
    case 268:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x36];
    case 269:
    case 270:
    case 295:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x3B];
    case 291:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x4F];
    default:
        return 0;
    }
}

u8 func_8411E358(void *arg0, s32 arg1) {
    switch (arg1) {
    case 276:
    case 277:
    case 278:
    case 279:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x44];
    case 280:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x3F];
    case 274:
    case 290:
    case 292:
    case 298:
    case 299:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x49];
    case 252:
    case 253:
    case 272:
    case 273:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[3];
    case 254:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[8];
    case 271:
    case 296:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0xD];
    case 255:
        return (*(u8 **)((u8 *)arg0 + 0x2D4))[0x67B];
    case 281:
        return (*(u8 **)((u8 *)arg0 + 0x2D4))[0x13D7];
    case 282:
    case 283:
    case 294:
        return (*(u8 **)((u8 *)arg0 + 0x2D4))[0x13D3];
    case 256:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x12];
    case 257:
    case 258:
    case 259:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x17];
    case 260:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x1C];
    case 261:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x21];
    case 264:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x26];
    case 265:
    case 266:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x2B];
    case 267:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x30];
    case 268:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x35];
    case 269:
    case 270:
    case 295:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x3A];
    case 291:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x4E];
    default:
        return 0;
    }
}

u8 func_8411E46C(void *arg0, s32 arg1) {
    switch (arg1) {
    case 276:
    case 277:
    case 278:
    case 279:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x41];
    case 280:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x3C];
    case 274:
    case 290:
    case 292:
    case 298:
    case 299:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x46];
    case 252:
    case 253:
    case 272:
    case 273:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0];
    case 254:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[5];
    case 271:
    case 296:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0xA];
    case 255:
        return (*(u8 **)((u8 *)arg0 + 0x2D4))[0x678];
    case 281:
        return (*(u8 **)((u8 *)arg0 + 0x2D4))[0x13D4];
    case 282:
    case 283:
    case 294:
        return (*(u8 **)((u8 *)arg0 + 0x2D4))[0x13D0];
    case 256:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0xF];
    case 257:
    case 258:
    case 259:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x14];
    case 260:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x19];
    case 261:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x1E];
    case 264:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x23];
    case 265:
    case 266:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x28];
    case 267:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x2D];
    case 268:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x32];
    case 269:
    case 270:
    case 295:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x37];
    case 291:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x4B];
    default:
        return 0;
    }
}

// 0x10-byte records at D_84193DD0. Record 0 is read directly at offsets 4 and 6 in
// fragment79_37A6E0.c; record (side + 1), where func_8411E1F8 returns side 0 or 1, holds
// per-side halfwords that other functions read at index * 16 + 0x10, 0x12 and 0x14.
//@src/fragments/79/fragment79_37A6E0.c
typedef struct unk_D_84193DD0 {
    /* 0x00 */ u8 unk_00[2];
    /* 0x02 */ u16 unk_02; // flags; mask 2 enables the arg0 + 0x1A comparisons in func_8411E580
    /* 0x04 */ u8 unk_04[12];
} unk_D_84193DD0; // size = 0x10

u8 func_8411E580(void *arg0, s32 arg1) {
    switch (arg1) {
    case 276:
    case 277:
    case 278:
    case 279:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x42];
    case 280:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x3D];
    case 274:
    case 290:
    case 292:
    case 298:
    case 299:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x47];
    case 252:
    case 253:
    case 272:
    case 273:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[1];
    case 254:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[6];
    case 271:
    case 296:
        if (((unk_D_84193DD0 *)D_84193DD0)[func_8411E1F8((s32)arg0) + 1].unk_02 & 2) {
            if (*(s16 *)((u8 *)arg0 + 0x1A) == 163) {
                return (u32)(*(u8 **)((u8 *)arg0 + 0x67C))[0xB] + 35.0f;
            } else if (*(s16 *)((u8 *)arg0 + 0x1A) == 84) {
                return (u32)(*(u8 **)((u8 *)arg0 + 0x67C))[0xB] + 45.0f;
            } else if (*(s16 *)((u8 *)arg0 + 0x1A) == 85) {
                return (u32)(*(u8 **)((u8 *)arg0 + 0x67C))[0xB] + 40.0f;
            } else {
                return (*(u8 **)((u8 *)arg0 + 0x67C))[0xB];
            }
        }
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0xB];
    case 255:
        return (*(u8 **)((u8 *)arg0 + 0x2D4))[0x679];
    case 281:
        return (*(u8 **)((u8 *)arg0 + 0x2D4))[0x13D5];
    case 282:
    case 283:
    case 294:
        return (*(u8 **)((u8 *)arg0 + 0x2D4))[0x13D1];
    case 256:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x10];
    case 257:
    case 258:
    case 259:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x15];
    case 260:
        if (((unk_D_84193DD0 *)D_84193DD0)[func_8411E1F8((s32)arg0) + 1].unk_02 & 2) {
            if (*(s16 *)((u8 *)arg0 + 0x1A) == 163) {
                return (u32)(*(u8 **)((u8 *)arg0 + 0x67C))[0x1A] + 30.0f;
            } else if (*(s16 *)((u8 *)arg0 + 0x1A) == 84) {
                return (u32)(*(u8 **)((u8 *)arg0 + 0x67C))[0x1A] + 45.0f;
            } else if (*(s16 *)((u8 *)arg0 + 0x1A) == 85) {
                return (u32)(*(u8 **)((u8 *)arg0 + 0x67C))[0x1A] + 40.0f;
            } else {
                return (*(u8 **)((u8 *)arg0 + 0x67C))[0x1A];
            }
        }
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x1A];
    case 261:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x1F];
    case 264:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x24];
    case 265:
    case 266:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x29];
    case 267:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x2E];
    case 268:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x33];
    case 269:
    case 270:
    case 295:
        if (((unk_D_84193DD0 *)D_84193DD0)[func_8411E1F8((s32)arg0) + 1].unk_02 & 2) {
            if (*(s16 *)((u8 *)arg0 + 0x1A) == 163) {
                return (u32)(*(u8 **)((u8 *)arg0 + 0x67C))[0x38] + 35.0f;
            } else {
                return (*(u8 **)((u8 *)arg0 + 0x67C))[0xB];
            }
        }
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x38];
    case 291:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x4C];
    default:
        return 0;
    }
}


u8 func_8411ED40(void *arg0, s32 arg1) {
    switch (arg1) {
    case 276:
    case 277:
    case 278:
    case 279:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x43];
    case 280:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x3E];
    case 274:
    case 290:
    case 292:
    case 298:
    case 299:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x48];
    case 252:
    case 253:
    case 272:
    case 273:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[2];
    case 271:
    case 296:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0xC];
    case 254:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[7];
    case 255:
        return (*(u8 **)((u8 *)arg0 + 0x2D4))[0x67A];
    case 281:
        return (*(u8 **)((u8 *)arg0 + 0x2D4))[0x13D6];
    case 282:
    case 283:
    case 294:
        return (*(u8 **)((u8 *)arg0 + 0x2D4))[0x13D2];
    case 256:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x11];
    case 257:
    case 258:
    case 259:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x16];
    case 260:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x1B];
    case 261:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x20];
    case 264:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x25];
    case 265:
    case 266:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x2A];
    case 267:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x2F];
    case 268:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x34];
    case 269:
    case 270:
    case 295:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x39];
    case 291:
        return (*(u8 **)((u8 *)arg0 + 0x67C))[0x4D];
    default:
        return 0;
    }
}

s32 func_8411EE54(u8 *arg0) {
    return *(u8 *)(arg0 + 0x661);
}

s32 func_8411EE5C(u8 *arg0) {
    return *(u8 *)(arg0 + 0x629);
}

s32 func_8411EE64(u8 *arg0) {
    return *(u8 *)(arg0 + 0x62B);
}

s32 func_8411EE6C(u8 *arg0) {
    return *(u8 *)(arg0 + 0x62D);
}

extern void func_84108E00(u8 *, s32);
void func_8411EE74(u8 *arg0) {
    s32 index;
    arg0[1] &= 0xFFFE;
    index = func_8411E1F8(arg0);
    if ((*(u16 *)((u8 *)(u32)D_84193DD0 + (index << 4) + 0x10) & 7) != 0) {
        func_84108E00(arg0, 2);
    }
    index = func_8411E1F8(arg0);
    if (*(u16 *)((u8 *)(u32)D_84193DD0 + (index << 4) + 0x10) == 0x20) {
        func_84108E00(arg0, 1);
    }
}

void func_8411EF08(u8 *arg0) {
    arg0[1] |= 1;
}

void func_8411EF18(u8 *arg0) {
    *(s16 *)(arg0 + 0x18) = 0;
}

void func_8411EF20(u8 *arg0) {
    *(s16 *)(arg0 + 0x18) = 3;
}

extern void func_8411EF08(u8 *);
extern s32 func_8411E164(s32);
extern void func_8411EE74(u8 *);
void func_8411EF2C(s32 arg0) {
    func_8411EF08((u8 *)arg0);
    func_8411EE74((u8 *)func_8411E164(arg0));
}

s32 func_8411EF5C(u8 *arg0) {
    return *(u16 *)(arg0 + 0x1A);
}

extern s32 D_84191208, D_84190414, D_84190418;
s32 func_8411EF64(s32 arg0) {
    if (arg0 == D_84191208) return D_84190414;
    return D_84190418;
}

#ifdef CC_CHECK
extern void func_8411E084(void *, void *);
#else
extern void func_8411E084(void);
#endif
extern f32 func_8411E1CC(u8 *arg0);
f32 func_8411EF90(u8 *arg0) {
#ifndef CC_CHECK
    extern void func_8411E084();
#endif
    f32 values[2];
    f32 temp_fv1;
    f32 var_fa0;
    func_8411E084(arg0, values - 1);
    temp_fv1 = func_8411E1CC(arg0) * 0.5f;
    var_fa0 = values[0] - temp_fv1;
    if (values[0] < temp_fv1) {
        var_fa0 = 0.0f;
    }
    return var_fa0;
}

void func_8411EFE4(void *arg0) {
    if ((s32)arg0 == D_84191208) {
        Vec3s_SetComponents((s16 *)((u8 *)arg0 + 0x1E), 0, 0x4000, 0);
        *(f32 *)((u8 *)arg0 + 0x28) = *(f32 *)((u8 *)arg0 + 0x650);
        if (*(s16 *)((u8 *)arg0 + 0x1A) == 0xD0) {
            *(f32 *)((u8 *)arg0 + 0x24) = -325.0f;
        } else if (*(s16 *)((u8 *)arg0 + 0x1A) == 0x5F) {
            *(f32 *)((u8 *)arg0 + 0x24) = -225.0f;
        } else if (*(s16 *)((u8 *)arg0 + 0x1A) == 0x82) {
            *(f32 *)((u8 *)arg0 + 0x24) = -200.0f;
        } else if (*(s16 *)((u8 *)arg0 + 0x1A) == 0xF9) {
            *(f32 *)((u8 *)arg0 + 0x24) = -200.0f;
        } else if (*(s16 *)((u8 *)arg0 + 0x1A) == 0xFA) {
            *(f32 *)((u8 *)arg0 + 0x24) = -185.0f;
        } else if (*(s16 *)((u8 *)arg0 + 0x1A) == 3) {
            *(f32 *)((u8 *)arg0 + 0x24) = -185.0f;
        } else {
            *(f32 *)((u8 *)arg0 + 0x24) = -150.0f;
        }
        *(f32 *)((u8 *)arg0 + 0x2C) = 0.0f;
    } else {
        Vec3s_SetComponents((s16 *)((u8 *)arg0 + 0x1E), 0, -0x4000, 0);
        *(f32 *)((u8 *)arg0 + 0x28) = *(f32 *)((u8 *)arg0 + 0x650);
        if (*(s16 *)((u8 *)arg0 + 0x1A) == 0xD0) {
            *(f32 *)((u8 *)arg0 + 0x24) = 325.0f;
        } else if (*(s16 *)((u8 *)arg0 + 0x1A) == 0x5F) {
            *(f32 *)((u8 *)arg0 + 0x24) = 225.0f;
        } else if (*(s16 *)((u8 *)arg0 + 0x1A) == 0x82) {
            *(f32 *)((u8 *)arg0 + 0x24) = 200.0f;
        } else if (*(s16 *)((u8 *)arg0 + 0x1A) == 0xF9) {
            *(f32 *)((u8 *)arg0 + 0x24) = 200.0f;
        } else if (*(s16 *)((u8 *)arg0 + 0x1A) == 0xFA) {
            *(f32 *)((u8 *)arg0 + 0x24) = 185.0f;
        } else if (*(s16 *)((u8 *)arg0 + 0x1A) == 3) {
            *(f32 *)((u8 *)arg0 + 0x24) = 185.0f;
        } else {
            *(f32 *)((u8 *)arg0 + 0x24) = 150.0f;
        }
        *(f32 *)((u8 *)arg0 + 0x2C) = 0.0f;
    }
}

/* mkdraft:func_8411F1AC begin */
extern s32 D_84191208;

// Writes an x offset to arg1[0] (negated when arg0 is D_84191208) chosen by the
// s16 at arg0+0x1A. Read as National Dex numbers, the special-cased values are
// 208 Steelix, 95 Onix, 130 Gyarados, 249 Lugia, 250 Ho-Oh and 3 Venusaur
// (inferred from the numbering; the field has no confirmed name).
void func_8411F1AC(u8 *arg0, f32 *arg1)
{
    s16 val;

    if (arg0 == (u8 *)D_84191208) {
        arg1[1] = *(f32 *)((u8 *)arg0 + 0x650);
        val = *(s16 *)((u8 *)arg0 + 0x1A);

        if (val == 208) {
            arg1[0] = -325.0f;
        } else if (val == 95) {
            arg1[0] = -225.0f;
        } else if (val == 130) {
            arg1[0] = -200.0f;
        } else if (val == 249) {
            arg1[0] = -200.0f;
        } else if (val == 250) {
            arg1[0] = -185.0f;
        } else if (val == 3) {
            arg1[0] = -185.0f;
        } else {
            arg1[0] = -150.0f;
        }
        arg1[2] = 0.0f;
    } else {
        arg1[1] = *(f32 *)((u8 *)arg0 + 0x650);
        val = *(s16 *)((u8 *)arg0 + 0x1A);

        if (val == 208) {
            arg1[0] = 325.0f;
        } else if (val == 95) {
            arg1[0] = 225.0f;
        } else if (val == 130) {
            arg1[0] = 200.0f;
        } else if (val == 249) {
            arg1[0] = 200.0f;
        } else if (val == 250) {
            arg1[0] = 185.0f;
        } else if (val == 3) {
            arg1[0] = 185.0f;
        } else {
            arg1[0] = 150.0f;
        }
        arg1[2] = 0.0f;
    }
}
/* mkdraft:func_8411F1AC end */
#endif
