#include "global.h"


#ifdef VERSION_US
extern u8 **D_87F11768;
void fragment64_main(s32 value) {
    *(s32 *)D_87F11768 = value;
}

extern u8 D_87F11770[];
extern u8 D_87F0F5B8[];
extern u8 D_87F11750[];
extern s32 main_pool_get_available(void);
extern u8 *MainPool_AllocState(s32, s32);
extern void MainPool_FinalizeAllocation(void *);
extern void *process_geo_layout(void *, void *);
extern s32 func_8004C8C0(u16);
extern s32 func_8004C990(s32, s32);
extern s32 func_87F08E3C(void *, s32);
extern void *func_80037E9C(void *, void *);
extern void func_87F0252C(void *, void *, u8 *, s32);

void func_87F00030(void) {
    u8 *var_v0;

    D_87F11768 = (u8 **)D_87F11770;
    *(s32 *)D_87F11768 = 20;
    *(s32 *)((u8 *)D_87F11768 + 4) = *(s32 *)D_87F11768 * 5;
    *(s32 *)((u8 *)D_87F11768 + 8) = 0;
    *(s32 *)((u8 *)D_87F11768 + 12) = 0;
    var_v0 = MainPool_AllocState(main_pool_get_available(), 0);
    *(void **)((u8 *)D_87F11768 + 448) = process_geo_layout(var_v0, D_87F0F5B8);
    MainPool_FinalizeAllocation(var_v0);
    func_8004C8C0(360);
    *(s32 *)((u8 *)D_87F11768 + 24) = func_87F08E3C((void *)func_8004C990(360, 0), 0x0F000000);
    *(s32 *)((u8 *)D_87F11768 + 28) = func_87F08E3C((void *)func_8004C990(360, 3), 0x0F000000);
    func_80037E9C(NULL, D_87F11750);
    func_87F0252C(D_87F11750, (u8 *)D_87F11768 + 32, (u8 *)D_87F11768 + 52, 1);
}

extern void func_87F026E8(void *, void *);
extern u8 **D_87F11768;
extern void *D_87F119DC;
extern f32 D_80087E50[];
extern f32 D_80088E50[];
extern f32 D_87F11438;
extern f32 D_87F1143C;
extern f32 D_87F11440;
extern f32 D_87F11444;
extern f32 D_87F11448;
extern f32 D_87F1144C;
extern f32 D_87F11450;




void func_87F00138(void) {
    f32 temp_fa0;
    f32 sp18;
    f32 temp_fa0_2;
    f32 temp_fa1;
    f32 temp_ft5;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 temp_fv1;
    f32 var_fv0;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;

    if (*(s32 *)((u8 *)D_87F119DC + 0xC) & 0x10000000) {
        *(f32 *)((u8 *)D_87F119DC + 0x54) = (f32)(D_87F11438 * *(f32 *)((u8 *)D_87F119DC + 0x54) + *(f32 *)((u8 *)D_87F119DC + 0x54));
        *(f32 *)((u8 *)D_87F119DC + 0x58) = (f32)(*(f32 *)((u8 *)D_87F119DC + 0x58) + D_87F1143C);
        if (*(f32 *)((u8 *)D_87F119DC + 0x54) < D_87F11440) {
            func_87F026E8((u8 *)D_87F11768 + 0x20, (u8 *)D_87F11768 + 0x34);
        }
    } else {
        var_fv0 = (1.0f - *(f32 *)((u8 *)D_87F11768 + 0x14)) * 560.0f;
        if (var_fv0 > 90.0f) {
            var_fv0 = 90.0f;
        }
        temp_fv1 = var_fv0 * D_87F11444;
        // FAKE: scores 60 when these statements are spread over separate lines.
        // IDO 7.1 orders the table base load (lui/addiu) against the index shift
        // (sra) differently depending on which source line the statements share;
        // one shared line is the layout that puts sra first, as the target does.
        // The rounding and the sine-table read are one step of the same angle.
        { if (temp_fv1 >= 0.0f) { var_v0 = (s32)(temp_fv1 + 0.5f); } else { var_v0 = (s32)(temp_fv1 - 0.5f); } temp_ft5 = D_80087E50[((s32)(var_v0 & 0xFFFF)) >> 4]; }
        temp_fa0 = (1.0f - *(f32 *)((u8 *)D_87F11768 + 0x14)) * 1080.0f;
        temp_fv0_2 = (1.0f - *(f32 *)((u8 *)D_87F11768 + 0x14)) * 90.0f * D_87F11448;
        if (temp_fv0_2 >= 0.0f) {
            var_v0_2 = (s32)(temp_fv0_2 + 0.5f);
        } else {
            var_v0_2 = (s32)(temp_fv0_2 - 0.5f);
        }
        sp18 = 1.0f - D_80087E50[((s32)(var_v0_2 & 0xFFFF)) >> 4];
        temp_fa0_2 = temp_fa0 * D_87F1144C;
        if (temp_fa0_2 >= 0.0f) {
            var_v0_3 = (s32)(temp_fa0_2 + 0.5f);
        } else {
            var_v0_3 = (s32)(temp_fa0_2 - 0.5f);
        }
        temp_fa1 = temp_ft5 * D_87F11450;
        temp_fv0_3 = 2.0f * ((D_80087E50[((s32)(var_v0_3 & 0xFFFF)) >> 4] * temp_fa1 * sp18) + temp_ft5);
        *(f32 *)((u8 *)D_87F119DC + 0x58) = temp_fv0_3;
        *(f32 *)((u8 *)D_87F119DC + 0x54) = temp_fv0_3;
        if (temp_fa0_2 >= 0.0f) {
            var_v0_3 = (s32)(temp_fa0_2 + 0.5f);
        } else {
            var_v0_3 = (s32)(temp_fa0_2 - 0.5f);
        }
        *(f32 *)((u8 *)D_87F119DC + 0x58) = (f32)(2.0f * ((D_80088E50[((s32)(var_v0_3 & 0xFFFF)) >> 4] * temp_fa1 * sp18) + temp_ft5));
    }
}

/* mkdraft:func_87F003F8 begin */
extern Gfx *D_800D0510;
extern s32 D_87F0F5EC[];
extern u8 *func_8004CA60(u8 *);
extern void func_8003CD84(void);



void func_87F003F8(s32 arg0, s32 arg1) {
    u8 *state;
    s32 handle;
    u8 *display_list;

    if (arg0 == 5) {
        state = (u8 *)D_87F11768;
        if (*(s32 *)(state + 0x10) < 4) {
            if (*(s32 *)(state + 0x10) == 0) {
                display_list = *(u8 **)(state + 0x1C);
            } else {
                display_list = *(u8 **)(state + 0x18);
            }
            handle = func_8004C990(360, D_87F0F5EC[*(s32 *)(state + 0x10)]);
            gDPPipeSync(D_800D0510++);
            gDPSetPrimColor(D_800D0510++, 0, 0, 255, 150, 240, 255);
            gDPSetEnvColor(D_800D0510++, 30, 0, 25, 255);
            gDPSetCombine(D_800D0510++, 0x30FFFF, 0x5FFEF238);
            gSPSegment(D_800D0510++, 15, func_8004CA60((u8 *)handle));
            gSPDisplayList(D_800D0510++, display_list);
            func_8003CD84();
        }
    }
}
/* mkdraft:func_87F003F8 end */

void func_87F00138(void);
extern void func_87F026E8(void *, void *);
extern u8 *func_87F025B8(void *, void *);
extern void func_80037E3C(void *, void *, void *);
extern void func_8003F1DC(void *);
extern void func_8003F114(u8 *, s16, s16, void *);
void func_87F00534(f32 arg0, f32 arg1) {
    u8 *obj;

    func_87F026E8((u8 *)D_87F11768 + 0x20, (u8 *)D_87F11768 + 0x34);
    obj = func_87F025B8((u8 *)D_87F11768 + 0x20, func_87F00138);
    if (obj != NULL) {
        func_80037E3C(obj + 0x24, NULL, obj);
        func_8003F1DC(obj + 0x24);
        func_8003F114(obj + 0x24, 0, -1, *(void **)((u8 *)D_87F11768 + 0x1C0));
        *(f32 *)(obj + 0x48) = arg0;
        *(f32 *)(obj + 0x4C) = arg1;
        *(f32 *)(obj + 0x54) = 0.0f;
        *(f32 *)(obj + 0x58) = 0.0f;
        *(f32 *)(obj + 0x5C) = 1.0f;
    }
}

void func_87F00534(f32 arg0, f32 arg1);
void func_87F005F0(f32 arg0, f32 arg1) {
    *(s32 *)((u8 *)D_87F11768 + 4) = *(s32 *)D_87F11768 * 5;
    *(s32 *)((u8 *)D_87F11768 + 8) = 2;
    *(s32 *)((u8 *)D_87F11768 + 12) = 0;
    *(s32 *)((u8 *)D_87F11768 + 16) = *(s32 *)((u8 *)D_87F11768 + 4) / *(s32 *)D_87F11768;
    *(f32 *)((u8 *)D_87F11768 + 20) = 0.0f;
    func_87F00534(arg0, arg1);
}

extern void func_87F005F0(f32, f32);
void func_87F00688(void) {
    func_87F005F0(0.0f, 0.0f);
}

u32 func_87F006AC(void) {
    return *(u32 *)((u8 *)D_87F11768 + 0xC);
}

extern void func_87F0277C(void *);

s32 func_87F006BC(void) {
    *(s32 *)((u8 *)D_87F11768 + 12) = 0;
    if (*(s32 *)((u8 *)D_87F11768 + 8) & 1) {
        *(s32 *)((u8 *)D_87F11768 + 12) = 3;
    } else if (*(s32 *)((u8 *)D_87F11768 + 8) & 2) {
        *(s32 *)((u8 *)D_87F11768 + 4) -= 1;
        *(s32 *)((u8 *)D_87F11768 + 16) = *(s32 *)((u8 *)D_87F11768 + 4) / *(s32 *)D_87F11768;
        *(f32 *)((u8 *)D_87F11768 + 20) = (f32)(*(s32 *)((u8 *)D_87F11768 + 4) % *(s32 *)D_87F11768) / *(s32 *)D_87F11768;
        if (*(s32 *)((u8 *)D_87F11768 + 4) % *(s32 *)D_87F11768 == 0) {
            switch (*(s32 *)((u8 *)D_87F11768 + 16)) {
            case 0:
                *(s32 *)((u8 *)D_87F11768 + 12) = 3;
                *(s32 *)((u8 *)D_87F11768 + 8) |= 1;
                *(s32 *)((u8 *)D_87F11768 + 64) |= 0x10000000;
                break;
            case 1:
                *(s32 *)((u8 *)D_87F11768 + 12) = 2;
                break;
            default:
                *(s32 *)((u8 *)D_87F11768 + 12) = 1;
                break;
            }
        }
    }
    func_87F0277C((u8 *)D_87F11768 + 32);
    return *(s32 *)((u8 *)D_87F11768 + 12);
}

#ifndef M2C_FIELD /* sweep: m2c --valid-syntax helpers (mirrors mkdraft.py) */
#define M2C_UNK s32
#define M2C_UNK8 s8
#define M2C_UNK16 s16
#define M2C_UNK32 s32
#define M2C_UNK64 s64
#define M2C_FIELD(expr, type, offset) (*(type)((u8*)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) 0
#define M2C_TRAP_IF(cond) ((void)0)
#define M2C_BREAK() ((void)0)
#define M2C_SYNC() ((void)0)
#define M2C_CARRY 0
#define M2C_STRUCT_COPY(dst, src) ((dst) = (src))
#endif

M2C_UNK func_800495BC(M2C_UNK, M2C_UNK, M2C_UNK *, s32); /* extern */
M2C_UNK func_800496A4(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_8004972C(M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_800498C4();                            /* extern */
extern M2C_UNK D_87F11430;
extern M2C_UNK D_87F11434;

void func_87F0085C(void) {
    s32 temp_a3;

    if (!(M2C_FIELD(D_87F11768, s32 *, 8) & 1) && (M2C_FIELD(D_87F11768, s32 *, 0x10) < 4)) {
        func_800498C4();
        func_800496A4(8, 0);
        func_8004972C(0xFF, 0xFF, 0, (s32) (M2C_FIELD(D_87F11768, f32 *, 0x14) * 255.0f));
        temp_a3 = M2C_FIELD(D_87F11768, s32 *, 0x10);
        if (temp_a3 == 0) {
            func_800495BC(0x80, 0x6E, &D_87F11430, temp_a3);
            return;
        }
        func_800495BC(0x90, 0x6E, &D_87F11434, temp_a3);
    }
}
#endif
