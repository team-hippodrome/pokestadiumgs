#include "global.h"


#ifdef VERSION_US
void func_84100020(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x14) |= arg1;
}

void func_84100030(u8 *arg0, u32 arg1) {
    *(u32 *)(arg0 + 0x14) &= ~arg1;
}

void func_84100044(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x14) ^= arg1;
}

s32 func_84100054(u8 *arg0, s32 arg1) {
    s32 result = 0;
    if (*(s32 *)(arg0 + 0x14) & arg1) {
        result = 1;
    }
    return result;
}

s32 func_84100074(u8 *arg0, s32 arg1) {
    s32 result = 0;
    if ((*(s32 *)(arg0 + 0x14) & arg1) == 0) {
        result = 1;
    }
    return result;
}

void func_84100094(u8 *arg0) {
    arg0[0x92] = 0;
}

extern s32 func_84100054(u8 *arg0, s32 arg1);
extern s32 func_84100074(u8 *arg0, s32 arg1);
s32 func_8410009C(u8 *arg0) {
    s32 result;

    result = 0;
    if (arg0[0x92] == 0) {
        result = 1;
    }
    if (arg0[0x7F] == 0xFF) {
        if (func_84100074(arg0, 1) != 0) {
            result = 1;
        }
    }
    if ((func_84100054(arg0, 0x20000) != 0) && (*(f32 *)(arg0 + 0x24) <= 0.0f)) {
        result = 1;
    }
    return result;
}

extern u8 *D_8418C950;
extern s32 D_8418C954;
extern u8 *main_pool_alloc(s32 arg0, s32 arg1);
void func_84100134(void) {
    D_8418C950 = main_pool_alloc(0xB6D0, 0);
    _bzero(D_8418C950, 0xB6D0);
    D_8418C954 = 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_36F8B0/func_84100174.s")

extern void func_84100174(u8 *arg0);
extern u8 *D_8418C950;
extern s32 D_8418C954;

u8 *func_84100260(void) {
    s32 var_v1;
    s32 var_v0;
    u8 *var_a0_2;

    var_v0 = D_8418C954;
    var_v1 = 0;
    var_a0_2 = D_8418C950 + var_v0 * 0x9C;
loop_1:
    if (*(s8 *)(var_a0_2 + 0x98) != 0) {
        var_v0 += 1;
        var_v1 += 1;
        if (var_v0 >= 300) {
            var_v0 = 0;
            var_a0_2 = D_8418C950;
        } else {
            var_a0_2 += 0x9C;
        }
        if (var_v1 != 300) {
            goto loop_1;
        }
    }
    if (var_v1 == 300) {
        var_a0_2 = NULL;
    } else {
        *(s8 *)(var_a0_2 + 0x98) = 1;
        func_84100174(var_a0_2);
        D_8418C954 = var_v0 + 1;
        if (D_8418C954 >= 300) {
            D_8418C954 = 0;
        }
    }
    return var_a0_2;
}
extern u8 *func_84100260(void);
u8 *func_84100328(void) {
    return func_84100260();
}

void func_84100348(u8 *arg0) {
    arg0[0x92] = 0;
}

void func_84100350(u8 *arg0) {
    u8 *next;
    u8 *prev;
    *(u32 *)(arg0 + 0x14) = 0;
    func_84100348(arg0);
    next = *(u8 **)(arg0 + 0x4);
    if (next != NULL) {
        *(u8 **)(next + 0x0) = *(u8 **)(arg0 + 0x0);
    }
    prev = *(u8 **)(arg0 + 0x0);
    if (prev != NULL) {
        *(u8 **)(prev + 0x4) = *(u8 **)(arg0 + 0x4);
    }
    *(u32 *)(arg0 + 0x4) = 0;
    *(u32 *)(arg0 + 0x0) = 0;
    arg0[0x98] = 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_36F8B0/func_841003AC.s")

typedef struct Func8410056CParticleS8 {
    u8 pad[0x98];
    s8 active;
    u8 tail[3];
} Func8410056CParticleS8;
s32 Particle_CountActive(void) {
    s32 i;
    s32 var_v1 = 0;
    Func8410056CParticleS8 *ptr = (Func8410056CParticleS8 *)D_8418C950;
    for (i = 0; i < 0x12C; i++, ptr++) {
        if (ptr->active != 0) {
            var_v1++;
        }
    }
    return var_v1;
}

s16 func_841005E0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4)
{
  f32 temp_fa0;
  f32 temp_fv0;
  f32 new_var;
  f32 new_var2;
  f32 temp_fv1;
  new_var = (f32) arg2;
  temp_fv1 = (f32) arg0;
  new_var2 = (f32) arg4;
  temp_fa0 = new_var2;
 do { if (temp_fv1 == temp_fa0) { return arg2; } } while (0);
  temp_fv0 = new_var;
  return (s16) ((s32) ((((((f32) arg3) - new_var) / (((f32) arg1) - temp_fv1)) * (temp_fa0 - temp_fv1)) + temp_fv0));
}
typedef struct {
    u8 pad_00[1];
    u8 mode;
    u8 divisor;
    u8 count;
    s16 *values;
} Func84100688Table;

s16 func_84100688(Func84100688Table *arg0, u32 arg1) {
    s32 i;

    if (arg0->mode == 0) {
        arg1 %= arg0->divisor;
    }
    for (i = 0; i < arg0->count - 1; i++) {
        if (arg1 >= (u32)arg0->values[i] && arg1 < (u32)arg0->values[i + 1]) {
            return (s16)i;
        }
    }
    return arg0->count - 1;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_36F8B0/func_84100710.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_36F8B0/func_84100874.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_36F8B0/func_841009D8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_36F8B0/func_84100B3C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_36F8B0/func_84100C68.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_36F8B0/func_84100DE4.s")

extern s16 func_841005E0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void func_84101084(Func84100688Table **arg0, u8 *arg1) {
    Func84100688Table *table;
    s16 index;
    s16 *frames;

    table = arg0[0];
    if (table == NULL) {
        *(s16 *)(arg1 + 0x66) = ((s16 **)arg0)[1][0];
        return;
    }
    if (table->pad_00[0] == 0) {
        *(s16 *)(arg1 + 0x66) = ((s16 **)arg0)[1][arg1[0x7F] % table->divisor];
        return;
    }
    index = func_84100688(table, arg1[0x7F]);
    table = arg0[0];
    frames = table->values;
    if (index + 1 == table->divisor) {
        *(s16 *)(arg1 + 0x66) = ((s16 **)arg0)[1][index];
        return;
    }
    *(s16 *)(arg1 + 0x66) = func_841005E0(*(s16 *)(index * 2 + (u8 *)frames), *(s16 *)(index * 2 + (u8 *)frames + 2),
                                          ((s16 **)arg0)[1][index], ((s16 **)arg0)[1][index + 1], arg1[0x7F]);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_36F8B0/func_8410119C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_36F8B0/func_841013F4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_36F8B0/func_84101888.s")

void func_84101A08(f32 *arg0, u8 *arg1, u8 arg2) {
    f32 value;
    if (*(s16 *)(arg1 + 4) != 0 && arg2 >= *(s16 *)(arg1 + 4)) {
        return;
    }
    if (arg2 < *(s16 *)(arg1 + 2)) {
        return;
    }
    value = (f32)*(s16 *)(arg1 + 8);
    if (value == *arg0) {
        return;
    }
    if (value < *arg0) {
        *arg0 -= (f32)*(s16 *)(arg1 + 0xA);
        if (*arg0 < (f32)*(s16 *)(arg1 + 8)) {
            *arg0 = (f32)*(s16 *)(arg1 + 8);
        }
    } else {
        *arg0 += (f32)*(s16 *)(arg1 + 0xA);
        if ((f32)*(s16 *)(arg1 + 8) < *arg0) {
            *arg0 = (f32)*(s16 *)(arg1 + 8);
        }
    }
}

extern u32 func_8411E358(s32 arg0, s32 arg1);
extern u32 func_8411EE54(u8 *arg0);
extern s32 ParticleMath_LacksBits(void *arg0, s32 arg1);
void func_84101AF4(u8 *arg0, u8 *arg1) {
    f32 scale;

    scale = 1.0f;
    if (ParticleMath_LacksBits(arg0 + 0x14, 0x2000) && *(s32 *)(arg0 + 8) != 0 &&
        ParticleMath_LacksBits(arg1 + 4, 0x80) && ParticleMath_LacksBits(arg1 + 4, 0x40)) {
        if (*(s32 *)(arg1 + 4) & 8) {
            scale = func_8411E358(*(s32 *)(arg0 + 8), *(u16 *)(arg0 + 0x68)) * 0.01f;
        } else {
            scale = func_8411EE54(*(u8 **)(arg0 + 8)) * 0.01f;
        }
    }
    *(f32 *)(arg0 + 0x18) = *(f32 *)(arg0 + 0x1C) * scale;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_36F8B0/func_84101C00.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_36F8B0/func_84101D54.s")

extern u8 D_8418C958;
extern s32 GeoRender_FindAnchorPosition(s32, s16, s32);
void func_84102750(s32 arg0, void *arg1) {
    void *temp_v0;
    void *temp_v1;

    if (arg1 != NULL) {
        temp_v1 = *(void **)((u8 *)arg1 + 0x10);
        if (temp_v1 != NULL) {
            temp_v0 = *(void **)((u8 *)temp_v1 + 0x10);
            if ((temp_v0 != NULL) && (*(s16 *)temp_v0 == 0)) {
                GeoRender_FindAnchorPosition(arg0, 1, (s32)(u32)((u8 *)&D_8418C958 + *(s16 *)((u8 *)temp_v0 + 2) * 0xC));
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_36F8B0/func_841027B4.s")

extern s32 ParticleMath_LacksBits(void *arg0, s32 arg1);
extern s32 ParticleMath_HasBits(void *arg0, s32 arg1);
extern s32 ModelAnim_IsFinished(void *arg0);
extern void func_84100094(u8 *arg0);
void func_8410291C(u8 *arg0) {
    u8 *state = *(u8 **)(arg0 + 0x10);
    if (*(u8 **)(arg0 + 0xC) == NULL) return;
    if (state == NULL) return;
    if (*(u8 **)(*(u8 **)(arg0 + 0xC) + 0x44) == NULL) return;
    if ((*(s16 *)*(u8 **)(*(u8 **)(arg0 + 0xC) + 0x44) & 2) == 0) return;
    if (ParticleMath_LacksBits(state + 4, 0x2000) == 0) return;
    if (ParticleMath_HasBits(state + 4, 0x4000) != 0) {
        if (*(u8 **)(*(u8 **)(arg0 + 0xC) + 0x48) == NULL) func_84100094(arg0);
    } else if (ModelAnim_IsFinished(*(u8 **)(arg0 + 0xC)) != 0) func_84100094(arg0);
}

extern void func_841027B4(u8 *);
extern void func_84100B3C(u8 *);
extern void func_84100C68(u8 *);
extern void func_84100DE4(u8 *);
extern void func_8410488C(u8 *);
extern void BattleAnim_GetPointAlongCameraRay(u8 *, f32);

// Updates each active record (nonzero byte 0x98) of the 300 156-byte records at
// D_8418C950 according to its mode byte at offset 0x7C.
void func_841029DC(void) {
    s32 i;
    u8 *record = D_8418C950;

    for (i = 0; i < 300; i++, record += 156) {
        if (*(s8 *)(record + 0x98) == 0) {
            continue;
        }
        switch (record[0x7C]) {
            case 0:
                func_841027B4(record);
                func_8410291C(record);
                break;
            case 1:
                if (func_84100074(record, 0x800)) {
                    func_841027B4(record);
                }
                break;
            case 7:
                if (func_84100074(record, 0x800)) {
                    func_841027B4(record);
                }
                break;
            case 2:
                func_84100B3C(record);
                break;
            case 4:
                BattleAnim_GetPointAlongCameraRay(*(u8 **)(record + 0xC) + 0x24, 50.0f);
                func_84100B3C(record);
                break;
            case 8:
                func_84100B3C(record);
                break;
            case 5:
                func_84100C68(record);
                break;
            case 6:
                func_84100DE4(record);
                break;
            case 3:
                break;
        }
        if (func_8410009C(record)) {
            func_8410488C(record);
            func_84100350(record);
        }
    }
}

typedef struct S1_Vec3f {
    /* 0x0 */ f32 x;
    /* 0x4 */ f32 y;
    /* 0x8 */ f32 z;
} S1_Vec3f;
typedef struct S1_Vec3s {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ s16 z;
} S1_Vec3s;

extern void func_841039AC(s16, s16, s16, f32);
extern void func_841039F4(s16, s16, s16, f32);
extern void func_841043AC(S1_Vec3f, S1_Vec3s, f32);
extern void func_84104428(S1_Vec3f, S1_Vec3s, f32);
extern void func_84104528(void *, S1_Vec3f, f32);
extern void func_84104590(void *, S1_Vec3f, f32, s16);
extern void func_84104668(void *, S1_Vec3f, f32, s16);

// Passes the record's position (0x20), rotation (0x6A) and scale (0x18) to the
// handler for type, all defined in fragment79_372DE0.
//@src/fragments/79/fragment79_372DE0.c
void func_84102B3C(u8 *record, void *matrix, s32 type) {
    switch (type) {
        case 0:
            func_841043AC(*(S1_Vec3f *)(record + 0x20), *(S1_Vec3s *)(record + 0x6A), *(f32 *)(record + 0x18));
            break;
        case 1:
            func_84104528(matrix, *(S1_Vec3f *)(record + 0x20), *(f32 *)(record + 0x18));
            break;
        case 2:
            func_84104428(*(S1_Vec3f *)(record + 0x20), *(S1_Vec3s *)(record + 0x6A), *(f32 *)(record + 0x18));
            break;
        case 3:
            func_84104668(matrix, *(S1_Vec3f *)(record + 0x20), *(f32 *)(record + 0x18), *(s16 *)(record + 0x6E));
            break;
        case 4:
            func_84104590(matrix, *(S1_Vec3f *)(record + 0x20), *(f32 *)(record + 0x18), *(s16 *)(record + 0x6E));
            break;
        case 5:
            func_841039AC(*(f32 *)(record + 0x20), *(f32 *)(record + 0x24), *(s16 *)(record + 0x6E), *(f32 *)(record + 0x18));
            break;
        case 6:
            func_841039F4(*(f32 *)(record + 0x20), *(f32 *)(record + 0x24), *(s16 *)(record + 0x6E), *(f32 *)(record + 0x18));
            break;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_36F8B0/func_84102D38.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_36F8B0/func_84102E84.s")

extern Gfx *D_800D0510;
extern u8 *D_8418CA20[];
extern void *func_80003240();
extern void func_8100348C();
extern void func_84102E84(s32, u8 *);
void func_841031F4(u8 *record, void *arg1, s32 matrix) {
    s16 *id;
    u8 *entry;
    u8 *model;
    u16 type;
    u16 count;
    void (*draw)(u8 *, s32);
    s32 i;

    if (arg1 != NULL && (id = *(s16 **)((u8 *)arg1 + 0x14)) != NULL && *id != 0) {
        entry = D_8418CA20[*id];
        model = *(u8 **)(entry + 4);
        type = *(u16 *)entry;
        count = *(u16 *)(entry + 2);
        draw = (void (*)(u8 *, s32))func_80003240(func_8100348C);
        func_84102B3C(record, (void *)matrix, type);
        for (i = 0; i < count; i++) {
            draw(record, *(s32 *)model);
            func_84102E84(*(u16 *)(model + 6), record);
            gSPDisplayList(D_800D0510++, *(u32 *)(model + 8));
            model += 0x10;
        }
    }
}

extern Gfx *D_800D0510;
extern u8 *D_8418CB88;
extern void *func_80003240();
extern void func_8100348C();
extern void func_84102E84(s32, u8 *);
void func_841032F0(u8 *record, s32 matrix) {
    s32 pad[2]; // FAKE
    u8 *model;
    u16 type;
    void (*draw)(u8 *, s32);

    model = *(u8 **)(D_8418CB88 + 4);
    type = *(u16 *)D_8418CB88;
    draw = (void (*)(u8 *, s32))func_80003240(func_8100348C);
    func_84102B3C(record, (void *)matrix, type);
    draw(record, *(s32 *)model);
    func_84102E84(*(u16 *)(model + 6), record);
    gSPDisplayList(D_800D0510++, *(u32 *)(model + 8));
}

extern u8 *D_80094910;
extern void func_841031F4(u8 *, void *, s32);
extern s32 func_84100054(u8 *arg0, s32 arg1);
extern s32 func_84100074(u8 *arg0, s32 arg1);
void func_84103394(s32 arg0) {
    s32 i;
    s32 result;
    u8 *record;
    void *child;

    record = D_8418C950;
    for (i = 0; i < 0x12C; i++, record += 0x9C) {
        if (*(s8 *)(record + 0x98) != 0) {
            if (func_84100074(record, 0x102800) != 0) {
                if (func_84100054(record, 0x1000) != 0) {
                    child = *(void **)(record + 0x10);
                    result = 0;
                    if ((child != NULL) && ((*(u32 *)((u8 *)child + 8) & 2) != 0)) {
                        result = 3;
                    }
                    if (result == *(s16 *)(D_80094910 + 0x18)) {
                        func_841031F4(record, child, arg0);
                    }
                }
            }
        }
    }
}

extern void func_841032F0(u8 *, s32);
extern void func_841031F4(u8 *, void *, s32);
extern s32 func_84100054(u8 *arg0, s32 arg1);
extern s32 func_84100074(u8 *arg0, s32 arg1);
void func_84103478(s32 arg0) {
    s32 mask = 0x100800;
    s32 i;
    u8 *record;

    record = D_8418C950;
    for (i = 0; i < 0x12C; i++, record += 0x9C) {
        if ((*(s8 *)(record + 0x98) != 0) && (func_84100074(record, mask) != 0) && (func_84100054(record, 0x1000) != 0) && (func_84100054(record, 0x2000) != 0)) {
            if (func_84100074(record, 0x4000) != 0) {
                u8 *child = *(u8 **)(record + 0x10);
                func_841031F4(record, child, arg0);
            } else {
                func_841032F0(record, arg0);
            }
        }
    }
}
#endif
