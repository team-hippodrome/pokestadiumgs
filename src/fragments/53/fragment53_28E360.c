#include "global.h"
#include "controller.h"

typedef struct { s32 f00; s32 f04; s32 f08; s32 f0C; s32 f10; s32 f14; s32 f18; s32 f1C; s32 f20; s32 f24; s32 f28; s32 f2C; s32 f30; s32 f34; s32 f38; s32 f3C; s32 f40; s32 f44; s32 f48; s32 f4C; s32 f50; s32 f54; s32 f58; s32 f5C; } Ctrl5E0;

#ifdef VERSION_US
struct Fragment53ActorState {
    u8 prefix[0xC];
    s32 animation;
    s32 pending;
    u8 middle14[4];
    s32 score;
    u8 middle1C[0x68];
    s32 result;
    s32 kind;
    u8 tail[0xC];
};
struct Fragment53Model { u8 opaque[0x168]; };
extern struct Fragment53ActorState D_86511698[];
extern struct Fragment53Model D_8650E120[];
extern s32 D_8650C4AC;
extern s32 D_8650C4B0;
extern f32 D_8650C4B8;
extern s32 D_8650C4D4;
extern s32 D_8650C5EC;
extern s32 D_8650D9D4;
#endif

#ifdef VERSION_US
extern s32 D_8650C4F0;
extern f32 D_8650C4FC;
extern s32 D_8650C610;
extern f32 D_8650F22C[];
extern f32 D_865119A0[];
extern f64 D_8650D800;
extern s32 D_8650C494;
extern f32 D_8650C508;
extern u8 D_865105B0[];
extern struct Fragment53ActorState D_86511698[];





void func_86504EB0(s32 arg0, void *arg1) {
    s32 pad[6]; // FAKE: unused; 24 bytes set the 0x20 stack frame. diff score 10 without it.
    f32 *temp_a1;
    f32 temp_ft2;
    f32 temp_ft5;
    f32 temp_fv0;
    f32 temp_fv1;
    f64 temp_fa0;
    f32 temp_fa1;
    f64 temp_ft4;
    f64 temp_ft3;
    f64 temp_ft0;
    s32 temp_v0;
    s32 temp_t5;
    struct Fragment53ActorState *temp_a0;
    u8 *temp_v1;

    temp_v0 = *(s32 *)((u8 *)arg1 + 0x14);
    switch (arg0) {
    case 0:
        temp_v1 = (u8 *)D_865105B0 + temp_v0 * 0x2D0;
        *(s16 *)(temp_v1 + 0x18A) = 0;
        *(s16 *)(temp_v1 + 0x186) = 0;
        break;
    case 2:
        if (D_8650C494 == 0) {
            temp_v1 = (u8 *)D_865105B0 + temp_v0 * 0x2D0;
            temp_a0 = &D_86511698[temp_v0];
            temp_fv0 = *(f32 *)((u8 *)temp_a0 + 0x70);
            if (*(f32 *)(temp_v1 + 0x28) > -3000.0f) {
                temp_a1 = (f32 *)((u8 *)D_865119A0 + temp_v0 * 4);
                *temp_a1 = (f32)((f64)*temp_a1 + 0.6);
            }
            temp_t5 = D_8650C610;
            if (temp_t5 == 0) {
                temp_fv1 = *(f32 *)((u8 *)D_865119A0 + temp_v0 * 4);
                temp_fa0 = (f64)temp_fv1;
                temp_fa1 = D_8650C508;
                temp_ft3 = (f64)temp_fa1;
                temp_ft0 = 4.9 * temp_ft3 * temp_fa0;
                temp_ft4 = temp_fa0 * temp_ft0;
                temp_ft5 = temp_fv1 - temp_fv0;
                *(f32 *)(temp_v1 + 0x28) = (f32)((f64)*(s32 *)((u8 *)temp_a0 + 0x30) - temp_ft4);
                *(f32 *)(temp_v1 + 0x194) = (f32)((f64)*(f32 *)((u8 *)D_8650F22C + temp_v0 * 0x168) +
                    (temp_ft4 / (f64)*(f32 *)((u8 *)temp_a0 + 0x74)));
                *(f32 *)(temp_v1 + 0x190) = ((f32)*(s32 *)((u8 *)temp_a0 + 0x34) +
                    (5.0f * temp_fv0 * temp_fv0)) - (temp_ft5 * (5.0f * temp_fa1 * temp_ft5));
                temp_ft2 = 256.0f;
                temp_ft2 *= *(f32 *)((u8 *)temp_a0 + 0x68);
                *(s16 *)(temp_v1 + 0x186) = (s16)((f32)*(s16 *)(temp_v1 + 0x186) + (temp_ft2 / 2));
                if (D_8650C4F0 == 1) {
                    *(s16 *)(temp_v1 + 0x18A) = (s16)((temp_ft2 * (f32)*(s32 *)((u8 *)temp_a0 + 0x78) * D_8650C4FC) +
                        (f32)*(s16 *)(temp_v1 + 0x18A));
                } else {
                    *(s16 *)(temp_v1 + 0x18A) = (s16)((temp_ft2 * (f32)*(s32 *)((u8 *)temp_a0 + 0x78)) +
                        (f32)*(s16 *)(temp_v1 + 0x18A));
                }
            }
        }
        // FAKE (FAKE): empty body; keeps the case-2 literal live into a block
        // where the state pointer holds $v1, so the dispatch compares $a2.
        if (temp_v0 == 2) {
        }
        break;
    case 5:
        break;
    }
}
#endif

#ifdef VERSION_US
s32 D_8650D1B0 = 0;
extern Ctrl5E0 D_8650C5E0;
extern s32 D_8650C4CC;
extern u8 D_865110F0[];
extern u8 D_8650F200[];
extern void func_80021ED8(s32);

/* Records are 0x168 bytes (Fragment53Model); the actor-pair records at
 * D_865105B0 are 0x2D0. */
#define F53_MODEL(base, i) ((u8 *)&((struct Fragment53Model *)(base))[i])
typedef struct { u8 opaque[0x2D0]; } Fragment53ModelPair;
#define F53_PAIR(base, i) ((u8 *)&((Fragment53ModelPair *)(base))[i])
#define XF(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define XI(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define XH(p, o) (*(s16 *)((u8 *)(p) + (o)))

void func_8650515C(s32 arg0, void *arg1) {
    static f32 D_8650D1DC = 0.0f;
    static s32 D_8650D9D0;
    s32 i;
    s32 pad; // FAKE: unused; a second home above tbl puts it at sp+0x58.
    s32 tbl[10] = { -99, -95, -90, -86, -83, -83, -86, -90, -99, 0 };

    switch (arg0) {
    case 0:
        break;
    case 2:
        if (D_8650C494 == 0) {
            switch (XI(&D_8650C5E0, 0x30)) {
            case 0:
                break;
            case 1:
                for (i = 0; i < 4; i++) {
                    XF(F53_MODEL(D_865110F0, i), 0x28) = -1500.0f;
                    XI(&D_86511698[i], 0x20) = 0;
                    XI(&D_86511698[i], 0x3C) = 0;
                    XH(F53_MODEL(D_8650F200, i), 0x22) = 0;
                    XH(F53_MODEL(D_8650F200, i), 0x1E) = 0;
                    XF(F53_MODEL(D_8650F200, i), 0x2C) = 40.0f;
                    XF(F53_MODEL(D_8650F200, i), 0x24) = XF(&D_8650E120[i], 0x24);
                    XH(F53_PAIR(D_865105B0, i), 0x18A) = 0;
                    XH(F53_PAIR(D_865105B0, i), 0x186) = 0;
                    XF(F53_PAIR(D_865105B0, i), 0x194) = 40.0f;
                    XI(&D_86511698[i], 0x44) = 0xB2 - (s32)((u32)XI(&D_86511698[i], 0x38) * 0x92) / D_8650C4CC;
                    if (XI(&D_86511698[i], 8) == 0 && XI(&D_86511698[i], 0x80) == 0) {
                        XI(&D_86511698[i], 0x44) = 0xB4;
                    }
                }
                D_8650D1B0 = 0;
                XI(&D_8650C5E0, 0x30) = 2;
                func_80021ED8(0x13);
                break;
            case 2:
                for (i = 0; i < 4; i++) {
                    if (XF(F53_MODEL(D_865110F0, i), 0x28) + (f32)(s32)((f64)((0.0 < (f64)D_8650C508 * 20.0) ? 0.5f : -0.5f) + (f64)D_8650C508 * 20.0) <= -120.0f) {
                        XF(F53_MODEL(D_865110F0, i), 0x28) = (f32)(s32)((f64)D_8650C508 * 20.0 + (f64)((0.0 < (f64)D_8650C508 * 20.0) ? 0.5f : -0.5f)) + XF(F53_MODEL(D_865110F0, i), 0x28);
                    } else {
                        XF(F53_MODEL(D_865110F0, i), 0x28) = 120.0f;
                        if (i == 0) {
                            D_8650D9D0++;
                        }
                        XF(F53_MODEL(D_865110F0, i), 0x28) = (f32)tbl[D_8650D9D0];
                    }
                    if (D_8650D9D0 >= 9) {
                        if (i == 3) {
                            D_8650D9D0 = 0;
                            XI(&D_8650C5E0, 0x30) = 3;
                        }
                        XF(F53_MODEL(D_865110F0, i), 0x28) = -100.0f;
                    }
                }
                break;
            case 3:
                D_8650D1B0++;
                if (D_8650D1B0 >= 0x47) {
                    D_8650D1B0 = 0;
                    XI(&D_8650C5E0, 0x30) = 6;
                    D_8650D1DC = 0.0f;
                }
                break;
            case 4:
                for (i = 0; i < 4; i++) {
                    if (-1500.0f < XF(F53_MODEL(D_865110F0, i), 0x28)) {
                        D_8650D1DC = (f32)((f64)D_8650D1DC + 0.15);
                        XF(F53_MODEL(D_865110F0, i), 0x28) = (f32)(-100.0 - ((f64)D_8650C508 * 4.9) * (f64)D_8650D1DC * (f64)D_8650D1DC);
                    } else {
                        XI(&D_8650C5E0, 0x30) = 5;
                    }
                    if (XF(F53_MODEL(D_865110F0, i), 0x28) < -200.0f) {
                        XI(&D_8650C5E0, 0x3C) = 0;
                    }
                }
                break;
            }
        }
        if (XI(&D_8650C5E0, 0x30) == 2 || XI(&D_8650C5E0, 0x30) == 4) {
            for (i = 0; i < 4; i++) {
                XF(F53_MODEL(D_8650F200, i), 0x28) = XF(F53_MODEL(D_865110F0, i), 0x28) + (f32)(D_8650C4CC / 2) + 25.0f + 2.0f;
                XF(F53_PAIR(D_865105B0, i), 0x28) = XF(F53_MODEL(D_865110F0, i), 0x28) + (f32)(XI(&D_86511698[i], 0x38) / 2) + 25.0f + 2.0f;
                XF(F53_PAIR(D_865105B0, i), 0x190) = XF(F53_PAIR(D_865105B0, i), 0x28) + (f32)(D_8650C4CC / 2) - 5.0f;
                XF(F53_PAIR(D_865105B0, i), 0x18C) = XF(&D_8650E120[i], 0x24) - 20.0f;
            }
        }
        break;
    case 5:
        break;
    }
}
#endif

#ifdef VERSION_US
extern void GeoCamera_SetPerspective(void *, f32, f32, f32);
extern void func_80038E14(s32, s32, f32, s32, f32, f32, f32, s32);
extern f32 D_8650C47C;
extern f32 D_8650D1E0;
s32 func_86505858(s32 arg0, s32 arg1) {
    extern Ctrl5E0 D_8650C5E0;
    GeoCamera_SetPerspective((void *)(u32)arg1, D_8650D1E0, 100.0f, 12800.0f);
    func_80038E14(arg1,
        *(s32 *)((u8 *)(&D_8650C5E0) + 0x24),
        D_8650C47C,
        *(s32 *)((u8 *)(&D_8650C5E0) + 0x2C),
        0.0f, D_8650C47C, 0.0f, 0);
    return 0;
}
#endif

#ifdef VERSION_US
extern void func_80037120(s32, s32, s32 *, s16 *, s16 *);
extern s32 D_80094908;
s32 func_865058CC(s32 arg0, void *arg1) {
    s16 pad;
    s32 sp28;
    s16 sp26;
    s16 sp24;
    if (arg0 == 2) {
        func_80037120(D_80094908 + 0xB4, D_80094908 + 0xA8, &sp28, &sp26, &sp24);
        *(s16 *)((u8 *)arg1 + 0x1C) = (s16)(sp26 + 0x2000);
        *(s16 *)((u8 *)arg1 + 0x1E) = (s16)(sp24 - 0x2000);
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern void func_80037120(s32, s32, s32 *, s16 *, s16 *);
extern s32 D_80094908;
s32 func_86505934(s32 arg0, void *arg1) {
    s16 pad;
    s32 sp28;
    s16 sp26;
    s16 sp24;
    if (arg0 == 2) {
        func_80037120(D_80094908 + 0xB4, D_80094908 + 0xA8, &sp28, &sp26, &sp24);
        *(s16 *)((u8 *)arg1 + 0x1C) = (s16)(-0x2000 - sp26);
        *(s16 *)((u8 *)arg1 + 0x1E) = (s16)(sp24 + 0x6000);
    }
    return 0;
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/53/fragment53_28E360/func_865059A0.s")
#endif

#ifdef VERSION_US
typedef struct F53Obj {
    /* 0x000 */ u8 unk_000[0x24];
    /* 0x024 */ f32 x;
    /* 0x028 */ f32 y;
    /* 0x02C */ f32 z;
    /* 0x030 */ f32 sx;
    /* 0x034 */ f32 sy;
    /* 0x038 */ f32 sz;
    /* 0x03C */ u8 unk_03C[0x168 - 0x3C];
} F53Obj;
#define OBJ(sym) (*(F53Obj (*)[])(sym))
#define OBJ2(sym) (*(F53Obj (*)[][2])(sym))
extern u8 D_8650DB80[];
extern u8 D_8650F7A0[];
extern u8 D_86510010[];
extern struct Fragment53Model D_8650E6C0[];
extern u8 D_8650F200[];
extern u8 D_865110F0[];
extern u8 D_8650EC60[];
extern u8 D_8650E6E4[];
extern F53Obj D_8650FD40;
extern u8 D_865105B0[];
extern s32 D_8650DB28[];
extern s32 D_8650DB40[];
extern s32 D_8650C4E0[];
extern s32 D_8650C474;
extern f32 D_8650C4D0;
extern f32 D_8650C4F4;
extern u8 D_8650D9A0[];
extern u8 D_8650D9B8[];
extern u8 D_8650D9F8[];
extern u8 D_8650DA18[];
extern u8 D_8650DA38[];
extern u8 D_87F15B70[];
extern void *D_8650DB10;
extern void func_865059A0(void);
extern void func_80037E9C(s32, void *);
extern void func_87F0D48C(void *, void *, s32);
extern void func_87F02CE0(void *, void *, s32);
extern void func_87F03BB0(void *, s32);
extern void func_8003F018(void *);
extern void func_8003F03C(void *, void *);
extern void func_87F06430(void *, s32);
extern void func_8003F114(void *, s32, s32, s32);
extern void func_8003F210(void *, s32);
extern s32 ModelAnim_SetSpeed(u8 *, s32);
extern void ModelAnim_SetFrame(u8 *, s16);
extern void ModelAnim_SetEventFrame(u8 *, s16);
extern void func_8003F3BC(void *, s32);
extern void func_80037E3C(void *, void *, s32);
extern void func_86502958(void);
extern void func_86503B98(s32, void *);
extern void func_8650455C(s32, void *);
extern void func_86504740(s32, void *);

void func_86505EA8(void) {
    s32 count;
    s32 i;
    s32 j;
    f32 pad; // FAKE: unused local keeps the frame layout
    f32 x;

    func_865059A0();
    count = 4;
    func_80037E9C(0, D_8650D9A0);
    func_80037E9C(0, D_8650D9B8);
    func_87F0D48C(D_8650DA38, D_8650DB10, 0);
    func_87F02CE0(D_8650D9A0, D_8650D9F8, 150);
    func_87F03BB0(D_8650DA18, 50);

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 2; j++) {
            func_8003F018(&OBJ2(D_865105B0)[i][j]);
        }
    }

    for (i = 0; i < count; i++) {
        func_8003F018(&OBJ(D_8650E120)[i]);
        func_8003F018(&OBJ(D_8650DB80)[i]);
        func_8003F018(&OBJ(D_8650F7A0)[i]);
        func_8003F03C(&OBJ(D_86510010)[i], D_8650D9A0);
        func_8003F03C(&OBJ(D_8650E6C0)[i], D_87F15B70);
        func_87F06430(&OBJ(D_8650E6E4)[i], i);
        OBJ(D_8650E6C0)[i].sz = 0.095f;
        OBJ(D_8650E6C0)[i].sy = 0.095f;
        OBJ(D_8650E6C0)[i].sx = 0.095f;
        OBJ(D_8650E6C0)[i].y = 55.0f;
        func_8003F114(&OBJ(D_8650E6C0)[i], 0, -1, D_8650DB28[i]);
        func_8003F210(&OBJ(D_8650E6C0)[i], 0);
        ModelAnim_SetSpeed((u8 *)&OBJ(D_8650E6C0)[i], 0x10000);
        ModelAnim_SetFrame((u8 *)&OBJ(D_8650E6C0)[i], guRandom() % 15 + 15);
        ModelAnim_SetEventFrame((u8 *)&OBJ(D_8650E6C0)[i], 0);
        func_8003F3BC(&OBJ(D_8650E6C0)[i], 0);
        D_86511698[i].animation = 0;
        func_8003F03C(&OBJ(D_8650F200)[i], D_8650D9A0);
        func_8003F018(&OBJ(D_865110F0)[i]);

        OBJ(D_8650E120)[i].z = -35.0f;
        OBJ(D_8650E120)[i].x = (i * 120.0f + -180.0f) * D_8650C4D0;
        OBJ(D_8650E120)[i].y = D_8650C474;
        OBJ(D_8650E120)[i].sx = 0.25f;
        OBJ(D_8650E120)[i].sz = 0.25f;
        OBJ(D_8650E120)[i].sy = 0.25f;
        func_8003F018(&OBJ(D_8650EC60)[i]);

        OBJ(D_8650DB80)[i].z = 48.0f;
        x = D_8650C4E0[i] + (i * 120.0f + -180.0f) * D_8650C4D0;
        OBJ(D_8650DB80)[i].y = -400.0f;
        OBJ(D_8650F7A0)[i].y = -400.0f;
        OBJ(D_8650DB80)[i].sx = 2.4f;
        OBJ(D_8650DB80)[i].sz = 2.4f;
        OBJ(D_8650DB80)[i].sy = 2.4f;
        OBJ(D_8650F7A0)[i].sy = 1.0f;
        OBJ(D_8650F7A0)[i].sz = 1.0f;
        OBJ(D_8650F7A0)[i].z = 45.0f;
        OBJ(D_8650F7A0)[i].x = OBJ(D_8650DB80)[i].x = x;
        OBJ(D_8650F7A0)[i].sx = 0.1f;
        OBJ(D_86510010)[i].x = OBJ(D_8650E120)[i].x;
        OBJ(D_86510010)[i].z = 50.0f;
        OBJ(D_86510010)[i].y = 92.0f;
        OBJ(D_86510010)[i].sz = D_8650C4F4;
        OBJ(D_86510010)[i].sy = D_8650C4F4;
        OBJ(D_8650F200)[i].y = -400.0f;
        OBJ(D_86510010)[i].sx = D_8650C4F4;
        OBJ(D_8650F200)[i].sx = 0.3f;
        OBJ(D_8650F200)[i].sz = 0.3f;
        OBJ(D_8650F200)[i].x = (i * 120.0f + -180.0f) * D_8650C4D0;
        OBJ(D_8650F200)[i].z = 40.0f;
        OBJ(D_8650F200)[i].sy = 0.17f;
        for (j = 0; j < 2; j++) {
            OBJ2(D_865105B0)[i][j].x = OBJ(D_8650F200)[i].x;
            OBJ2(D_865105B0)[i][j].z = OBJ(D_8650F200)[i].z;
            OBJ2(D_865105B0)[i][j].sx = 0.3f;
            OBJ2(D_865105B0)[i][j].sz = 0.3f;
            OBJ2(D_865105B0)[i][j].sy = 0.17f;
        }
        OBJ(D_865110F0)[i].x = OBJ(D_8650E120)[i].x;
        OBJ(D_865110F0)[i].sx = 0.6f;
        OBJ(D_865110F0)[i].sy = 0.6f;
        OBJ(D_865110F0)[i].sz = 0.6f;
        OBJ(D_865110F0)[i].y = 0.0f;
        OBJ(D_865110F0)[i].z = 100.0f;
        func_80037E3C(&OBJ(D_8650E120)[i], func_86503B98, i);
        func_80037E3C(&OBJ(D_8650DB80)[i], func_8650455C, i);
        func_80037E3C(&OBJ(D_8650F200)[i], func_86504740, i);
        func_80037E3C(OBJ2(D_865105B0)[i], func_86504EB0, i);
        func_8003F114(&OBJ(D_8650DB80)[i], 0, -1, D_8650DB40[i]);
    }
    func_80037E3C(OBJ(D_865110F0), func_8650515C, 0);
    func_8003F018(&D_8650FD40);
    D_8650FD40.z = 40.0f;
    D_8650FD40.x = 0.0f;
    D_8650FD40.y = 335.0f;
    D_8650FD40.sz = 1.0f;
    D_8650FD40.sx = 0.1f;
    D_8650FD40.sy = 0.5f;
    func_86502958();
}
#endif

#ifdef VERSION_US
/* mkdraft:func_865064B0 begin */
extern void Font_DisableTwoCycleTexturing(void);
extern void Font_EnableTwoCycleTexturing(void);
extern void func_800495F8(s32 x, s32 y, s32 mode, const char *format, ...);
extern void func_800496A4(s32 a0, s32 a1);
extern void func_8004972C(s32 a0,s32 a1,s32 a2,s32 a3);
extern void func_800497E4(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_800498C4(void);
extern void func_800499EC(void);
extern void func_87F09040(void);
extern s32 D_8650C470;
extern s32 D_8650C4BC;
extern s32 D_8650C4C0;
extern s32 D_8650C4F0;
extern f32 D_8650C4F4;
extern f32 D_8650C4F8;
extern f32 D_8650C4FC;
extern s32 D_8650C500;
extern s32 D_8650C504;
extern s32 D_8650C5FC;
extern s32 D_8650D2E8;
extern s8 D_8650D490;
extern s8 D_8650D49C;
extern s8 D_8650D4A8;
extern s8 D_8650D4B4;
extern s8 D_8650D4B8;
extern s8 D_8650D4C8;
extern s8 D_8650D4CC;
extern s8 D_8650D4DC;
extern s8 D_8650D4E4;
extern s8 D_8650D4F4;
extern s8 D_8650D4F8;
extern s8 D_8650D508;
extern s8 D_8650D50C;
extern s8 D_8650D520;
extern s8 D_8650D528;
extern s8 D_8650D530;
extern s8 D_8650D540;
extern s8 D_8650D554;
extern s8 D_8650D55C;
extern s8 D_8650D56C;
extern s8 D_8650D578;
extern s8 D_8650D588;
extern s8 D_8650D594;
extern s8 D_8650D5A0;
extern s8 D_8650D5B0;
extern s8 D_8650D5BC;
extern s8 D_8650D5C8;
extern s8 D_8650D5DC;
extern s8 D_8650D5E8;
extern s8 D_8650D5F8;
extern s8 D_8650D60C;
extern s8 D_8650D618;
extern s8 D_8650D624;
extern s8 D_8650D634;



void func_865064B0(void) {
    func_87F09040();
    func_800498C4();
    func_800496A4(1, 0);
    Font_EnableTwoCycleTexturing();
    func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
    func_800497E4(0xFF, 0xFF, 0xFF, 0xFF);
    D_8650D2E8++;
    if (D_8650D2E8 >= 0x15) {
        D_8650D2E8 = 0;
    }
    func_800495F8(0x78, 0x32, 0, &D_8650D490);
    func_800495F8(0x78, 0x3C, 0, &D_8650D49C, D_8650D9D4);
    func_800495F8(0x78, 0x46, 0, &D_8650D4A8);
    if ((D_8650D2E8 >= 0xA) || (D_8650C5FC != 1)) {
        func_800495F8(0xE6, 0x46, 0, &D_8650D4B4, D_8650C4AC);
    }
    func_800495F8(0x78, 0x50, 0, &D_8650D4B8);
    if ((D_8650D2E8 >= 0xA) || (D_8650C5FC != 2)) {
        func_800495F8(0xE6, 0x50, 0, &D_8650D4C8, D_8650C4CC);
    }
    func_800495F8(0x78, 0x5A, 0, &D_8650D4CC);
    if ((D_8650D2E8 >= 0xA) || (D_8650C5FC != 3)) {
        func_800495F8(0xE6, 0x5A, 0, &D_8650D4DC, (f64) D_8650C4B8);
    }
    func_800495F8(0x78, 0x64, 0, &D_8650D4E4);
    if ((D_8650D2E8 >= 0xA) || (D_8650C5FC != 4)) {
        func_800495F8(0xE6, 0x64, 0, &D_8650D4F4, D_8650C4BC);
    }
    func_800495F8(0x78, 0x6E, 0, &D_8650D4F8);
    if ((D_8650D2E8 >= 0xA) || (D_8650C5FC != 5)) {
        func_800495F8(0xE6, 0x6E, 0, &D_8650D508, D_8650C4B0);
    }
    func_800495F8(0x78, 0x78, 0, &D_8650D50C);
    if ((D_8650D2E8 >= 0xA) || (D_8650C5FC != 6)) {
        switch (D_8650C4C0) {                       /* switch 1; irregular */
        case 0:                                     /* switch 1 */
            func_800495F8(0xE6, 0x78, 0, &D_8650D520);
            break;
        case 1:                                     /* switch 1 */
            func_800495F8(0xE6, 0x78, 0, &D_8650D528);
            break;
        case 2:                                     /* switch 1 */
            func_800495F8(0xE6, 0x78, 0, &D_8650D530);
            break;
        }
    }
    func_800495F8(0x78, 0x82, 0, &D_8650D540);
    if ((D_8650D2E8 >= 0xA) || (D_8650C5FC != 7)) {
        func_800495F8(0xE6, 0x82, 0, &D_8650D554, (f64) D_8650C4F4);
    }
    func_800495F8(0x78, 0x8C, 0, &D_8650D55C);
    if ((D_8650D2E8 >= 0xA) || (D_8650C5FC != 8)) {
        switch (D_8650C470) {                       /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            func_800495F8(0xE6, 0x8C, 0, &D_8650D56C);
            break;
        case 1:                                     /* switch 2 */
            func_800495F8(0xE6, 0x8C, 0, &D_8650D578);
            break;
        case 2:                                     /* switch 2 */
            func_800495F8(0xE6, 0x8C, 0, &D_8650D588);
            break;
        case 3:                                     /* switch 2 */
            func_800495F8(0xE6, 0x8C, 0, &D_8650D594);
            break;
        }
    }
    func_800495F8(0x78, 0x96, 0, &D_8650D5A0);
    if ((D_8650D2E8 >= 0xA) || (D_8650C5FC != 9)) {
        if (D_8650C4F0 == 1) {
            func_800495F8(0xE6, 0x96, 0, &D_8650D5B0);
        } else {
            func_800495F8(0xE6, 0x96, 0, &D_8650D5BC);
        }
    }
    func_800495F8(0x78, 0xA0, 0, &D_8650D5C8);
    if ((D_8650D2E8 >= 0xA) || (D_8650C5FC != 0xA)) {
        if (D_8650C500 == 0) {
            func_800495F8(0xE6, 0xA0, 0, &D_8650D5DC, (f64) D_8650C4F8);
        } else {
            func_800495F8(0xE6, 0xA0, 0, &D_8650D5E8, (f64) D_8650C4FC);
        }
    }
    func_800495F8(0x78, 0xAA, 0, &D_8650D5F8);
    if ((D_8650D2E8 >= 0xA) || (D_8650C5FC != 0xB)) {
        if (D_8650C504 == 0) {
            func_800495F8(0xE6, 0xAA, 0, &D_8650D60C);
        } else {
            func_800495F8(0xE6, 0xAA, 0, &D_8650D618);
        }
    }
    func_800495F8(0x78, 0xB4, 0, &D_8650D624);
    func_800495F8(0xE6, 0xB4, 0, &D_8650D634, D_8650C4D4);
    Font_DisableTwoCycleTexturing();
    func_800499EC();
}
/* mkdraft:func_865064B0 end */
#endif

#ifdef VERSION_US
void func_86506B2C(s32 arg0) {
    extern f32 D_8650D320[];
    extern s32 D_8650D348[37];
    extern s32 D_8650D2FC[];
    extern s32 D_8650D2EC[];
    extern Gfx *D_800D0510;
    extern s32 func_8004D1FC(u8 *);
    extern void GfxRect_DrawTextured(s16, s16, s16, s16, s16, s16, s16, s16, s32);
    u16 *texture;
    f32 scale;
    s32 saved_frame[1];
    int frame;

    if (D_8650C494 == 0) {
        *(s32 *)((u8 *)&D_86511698[arg0] + 0x8C) += 1;
    }
    frame = *(s32 *)((u8 *)&D_86511698[arg0] + 0x8C);
    if (frame >= 10) {
        *(s32 *)((u8 *)&D_86511698[arg0] + 0x8C) = 0;
        frame = 0;
    }
    scale = D_8650D320[frame];
    saved_frame[0] = frame;
    texture = (u16 *)func_8004C990(398, 0);
    func_8004D1FC((u8 *)texture);
    {
        Gfx *gfx = D_800D0510++;
        s32 *color;
        gfx->words.w0 = 0xFA000000;
        color = ((s32 (*)[3])D_8650D348)[saved_frame[0]];
        gfx->words.w1 = _SHIFTL(color[0], 24, 8) | _SHIFTL(color[1], 16, 8) | _SHIFTL(color[2], 8, 8) | 255;
    }
    gDPSetEnvColor(D_800D0510++, 255, 255, 255, 255);
    GfxRect_DrawTextured((s16)(D_8650D2EC[arg0] + D_8650D2FC[4] + (s32)(((1.2 - scale) / 2) * 56.0) - 19),
                        (s16)(*(s32 *)((u8 *)&D_86511698[arg0] + 0x44) + (s32)(((1.2 - scale) / 2) * 42.0) - 16),
                        (s16)(s32)((f32)(u32)texture[0] * scale + ((f32)(u32)texture[0] * scale > 0.0f ? 0.5f : -0.5f)),
                        (s16)(s32)((f32)(u32)texture[1] * scale + ((f32)(u32)texture[1] * scale > 0.0f ? 0.5f : -0.5f)),
                        0, 0,
                        (s32)(1024.0f / scale + (1024.0f / scale > 0.0f ? 0.5f : -0.5f)),
                        (s32)(1024.0f / scale + (1024.0f / scale > 0.0f ? 0.5f : -0.5f)), 0);
}
#endif

#ifdef VERSION_US
extern Gfx *D_800D0510;
extern void *D_8650DB10;
extern s32 D_8650C404[];
extern s32 D_8650C408;
extern s32 D_8650C42C;
extern s32 D_8650D2EC[];
extern s32 D_8650D2FC[];
extern s32 func_8004D1FC(u8 *);
extern void GfxRect_DrawTextured(s16, s16, s16, s16, s16, s16, s16, s16, s32);

typedef struct Fragment53FlashColor {
    s32 prim_r;
    s32 prim_g;
    s32 prim_b;
    s32 prim_a;
    s32 env_r;
    s32 env_g;
    s32 env_b;
} Fragment53FlashColor;
extern Fragment53FlashColor D_8650C680[];

#ifndef ROUND_MAX
#define ROUND_MAX(x) ((x) + ((x) > 0.0f ? 0.5f : -0.5f))
#endif
#define TEX_WIDTH(tex) ((s16)(s32)ROUND_MAX((f32)*(u16 *)((u8 *)(tex) + 0) * 0.57f))
#define TEX_HEIGHT(tex) ((s16)(s32)ROUND_MAX((f32)*(u16 *)((u8 *)(tex) + 2) * 0.57f))



void func_86506E78(s32 arg0, s32 arg1) {
    struct Fragment53ActorState *state;
    u8 *tex;
    s32 value;
    s32 divisor;
    s32 first_digit;
    s32 digit;
    s32 digit_index;
    s32 y;

    first_digit = -1;
    divisor = 100;
    if (*(u8 *)((u8 *)D_8650DB10 + 0x2180) != 4) {
        gDPSetPrimColor(D_800D0510++, 0, 0, D_8650C680[arg0].prim_r, D_8650C680[arg0].prim_g,
                        D_8650C680[arg0].prim_b, D_8650C680[arg0].prim_a);
        gDPSetEnvColor(D_800D0510++, D_8650C680[arg0].env_r, D_8650C680[arg0].env_g,
                       D_8650C680[arg0].env_b, 0xFF);
        digit_index = 0;
        if (arg1 == 0) {
            state = &D_86511698[arg0];
            value = state->score;
        } else {
            state = &D_86511698[arg0];
            value = *(s32 *)((u8 *)state + 8);
        }
        if ((*(s32 *)((u8 *)state + 0x80) < 0) && (arg1 == 1)) {
            gDPSetPrimColor(D_800D0510++, 0, 0, D_8650C680[4].prim_r, D_8650C680[4].prim_g,
                            D_8650C680[4].prim_b, D_8650C680[4].prim_a);
            gDPSetEnvColor(D_800D0510++, D_8650C680[4].env_r, D_8650C680[4].env_g, D_8650C680[4].env_b,
                           0xFF);
            y = *(s32 *)((u8 *)state + 0x44);
            if (*(s32 *)((u8 *)state + 0x80) < -5) {
                tex = func_8004C990(0x1AD, D_8650C42C);
                func_8004D1FC(tex);
                GfxRect_DrawTextured((s16)(D_8650D2EC[arg0] + D_8650D2FC[0]), (s16)y, TEX_WIDTH(tex), TEX_HEIGHT(tex),
                                     0, 0, 1796, 1796, 0);
                tex = func_8004C990(0x1AD, D_8650C408);
                func_8004D1FC(tex);
                GfxRect_DrawTextured((s16)(D_8650D2EC[arg0] + D_8650D2FC[1]), (s16)y, TEX_WIDTH(tex), TEX_HEIGHT(tex),
                                     0, 0, 1796, 1796, 0);
                tex = func_8004C990(0x1AD, D_8650C404[0]);
                func_8004D1FC(tex);
                GfxRect_DrawTextured((s16)(D_8650D2EC[arg0] + D_8650D2FC[2]), (s16)y, TEX_WIDTH(tex), TEX_HEIGHT(tex),
                                     0, 0, 1796, 1796, 0);
                return;
            }
            tex = func_8004C990(0x1AD, D_8650C42C);
            func_8004D1FC(tex);
            GfxRect_DrawTextured((s16)(D_8650D2EC[arg0] + D_8650D2FC[4]), (s16)y, TEX_WIDTH(tex), TEX_HEIGHT(tex),
                                 0, 0, 1796, 1796, 0);
            tex = func_8004C990(0x1AD, D_8650C404[-*(s32 *)((u8 *)state + 0x80)]);
            func_8004D1FC(tex);
            GfxRect_DrawTextured((s16)(D_8650D2EC[arg0] + D_8650D2FC[5]), (s16)y, TEX_WIDTH(tex), TEX_HEIGHT(tex),
                                 0, 0, 1796, 1796, 0);
            return;
        }
        do {
            if ((*(s32 *)((u8 *)state + 8) == 0x14) && (arg1 == 1)) {
                gDPSetPrimColor(D_800D0510++, 0, 0, D_8650C680[5].prim_r, D_8650C680[5].prim_g,
                                D_8650C680[5].prim_b, D_8650C680[5].prim_a);
                gDPSetEnvColor(D_800D0510++, D_8650C680[5].env_r, D_8650C680[5].env_g,
                               D_8650C680[5].env_b, 0xFF);
            }
            if (value >= divisor) {
                if (first_digit == -1) {
                    first_digit = digit_index;
                }
                digit = value / divisor;
                value -= digit * divisor;
                divisor /= 10;
                y = 0xCC;
                if (arg1 == 1) {
                    y = *(s32 *)((u8 *)state + 0x44);
                }
                tex = func_8004C990(0x1AD, D_8650C404[digit]);
                func_8004D1FC(tex);
                GfxRect_DrawTextured((s16)(D_8650D2EC[arg0] + *(s32 *)((u8 *)D_8650D2FC + first_digit * 12 + digit_index * 4)),
                                     (s16)y, TEX_WIDTH(tex), TEX_HEIGHT(tex), 0, 0, 1796, 1796, 0);
            } else {
                divisor /= 10;
                if ((first_digit != -1) || (digit_index == 2)) {
                    if ((digit_index == 2) && (first_digit == -1)) {
                        first_digit = 2;
                    }
                    y = 0xCC;
                    if (arg1 == 1) {
                        y = *(s32 *)((u8 *)state + 0x44);
                    }
                    tex = func_8004C990(0x1AD, D_8650C404[0]);
                    func_8004D1FC(tex);
                    GfxRect_DrawTextured((s16)(D_8650D2EC[arg0] + *(s32 *)((u8 *)D_8650D2FC + first_digit * 12 + digit_index * 4)), (s16)y,
                                         TEX_WIDTH(tex), TEX_HEIGHT(tex), 0, 0, 1796, 1796, 0);
                }
            }
            digit_index++;
        } while (digit_index != 3);
    }
}
#endif

#ifdef VERSION_US
// The fragment's .data tables from D_8650D1E0 up to func_86507AFC's statics live in
// this file so that the function-scope statics D_8650D3DC/D_8650D3E0 keep their
// retail addresses (IDO addresses statics section-relative, unlike externs).
extern u8 D_80126420[];
extern u8 D_81900DE0[];
extern u8 D_8650D9A0[];
extern u8 D_8650D9B8[];
extern u8 D_87F0F530[];
extern u8 D_87F0F620[];
f32 D_8650D1E0 = 45.0f;
s32 D_8650D1E4 = 0;
u32 D_8650D1E8[64] = {
    0x0C00FFFF, 0x05000000, 0x0B00001E, 0x00000000,
    0x014000F0, 0x0000000F, 0x00000000, 0x000003E8,
    0x08000000, (u32)func_86505858, 0x00000000, 0x05000000,
    0x0D000000, 0x05000000, 0x14000000, 0x002D0019,
    0xFFFFFF28, 0x08000000, (u32)func_865058CC, 0x00000000,
    0x14000000, 0x002D0019, 0x80808028, 0x08000000,
    (u32)func_86505934, 0x00000000, 0x16646464, 0x0F000003,
    0x05000000, 0x1F00FFFF, 0x00000000, 0x00000000,
    0xFFFF0000, 0x00640064, 0x00640000, 0x06000000,
    0x05000000, 0x0A000000, (u32)D_80126420, 0x06000000,
    0x0F000000, 0x05000000, 0x0A000000, (u32)D_8650D9A0,
    0x0A000000, (u32)D_81900DE0, 0x06000000, 0x0F000001,
    0x05000000, 0x0A000000, (u32)D_8650D9B8, 0x06000000,
    0x0F000000, 0x05000000, 0x03000000, (u32)D_87F0F620,
    0x06000000, 0x06000000, 0x06000000, 0x03000000,
    (u32)D_87F0F530, 0x06000000, 0x01000000, 0x00000000,
};
s32 D_8650D2E8 = 0;
s32 D_8650D2EC[4] = {
    29, 107, 185, 263,
};
s32 D_8650D2FC[4] = {
    -6, 5, 18, 0,
};
s32 D_8650D30C[5] = {
    1, 14, 0, 0, 7,
};
f32 D_8650D320[10] = {
    1.2f, 1.15f, 1.1f, 1.05f, 1.0f, 0.95f, 0.9f, 1.0f, 1.1f, 1.2f,
};

s32 D_8650D348[37] = {
    200, 100, 155, 209, 108, 171, 218, 116,
    187, 227, 124, 203, 236, 132, 219, 245,
    140, 235, 255, 150, 255, 237, 134, 222,
    219, 118, 189, 200, 100, 155, 10, 10,
    15, 15, 100, 60, 60,
};

extern Gfx D_80094E38[];
extern Gfx D_80094E78[];
extern Gfx D_80094F50[];
extern s32 D_8650C434[];
extern s32 D_8650C494;
extern s32 D_8650C4B0;
extern Ctrl5E0 D_8650C5E0;
extern s32 D_8650CFB0[];
extern s32 D_8650D0A4;
extern s32 D_8650D3E4[];
extern char D_8650D638[];
extern u8 *D_8650D9D8;
extern u8 D_8650DA38[];
extern s32 D_86511900[];
extern s32 D_86511910[];
extern void func_87F0D600(u8 *, s32, s32, s32, f32, f32);
extern s32 func_8004D19C(s32, u8 *, void *, s32, s32);
extern void func_87F061F0(void);
extern void func_86502D80(s32);
extern void func_86506B2C(s32);
extern void func_86506E78(s32, s32);
extern void func_80027A28(u16, u8);

#define F53_CTRL(off) (*(s32 *)((u8 *)&D_8650C5E0 + (off)))
#define F53_ACTOR(i, off) (*(s32 *)((u8 *)&D_86511698[i] + (off)))
#define F53_ROUND(x) ((s16)(s32)((x) + ((x) > 0.0f ? 0.5f : -0.5f)))

void func_86507AFC(void) {
    static s32 D_8650D3DC = 0;
    static s32 D_8650D3E0 = 4;
    s32 i;
    Gfx *g;
    s32 saved;
    u8 *tex;

    saved = F53_CTRL(0);
    if (saved == 0) {
        D_8650D3E0 = D_8650D0A4;
    }
    gSPDisplayList(D_800D0510++, D_80094E38);
    for (i = 0; i < 4; i++) {
        tex = func_8004C990(0x1B2, D_8650C434[F53_ACTOR(i, 0x4C)]);
        func_8004D1FC(tex);
        if (*((u8 *)D_8650DB10 + 0x2180) != 4) {
            GfxRect_DrawTextured(D_8650D2EC[i], 0xB6, F53_ROUND(*(u16 *)tex * 0.8f),
                                 F53_ROUND(*(u16 *)(tex + 2) * 0.8f), 0, 0, 0x500, 0x500, 0);
        }
    }
    for (i = 0; i < 4; i++) {
        if (*((u8 *)D_8650DB10 + 0x2180) != 4) {
            func_87F0D600(D_8650DA38, i, D_8650D2EC[i], 0xB6, 0.8f, 0.8f);
        }
    }
    gSPDisplayList(D_800D0510++, D_80094F50);
    gSPDisplayList(D_800D0510++, D_80094E38);
    func_8004D19C(0x8C, D_8650D9D8, func_8004C990(0x18D, D_8650CFB0[F53_ACTOR(0, 0x58) / 6]), 0, 0);
    gSPDisplayList(D_800D0510++, D_80094E78);
    gDPSetPrimColor(D_800D0510++, 0, 0, 255, 255, 255, 255);
    gDPSetEnvColor(D_800D0510++, 0x28, 0x6E, 0x00, 0xFF);
    gDPSetCombine(D_800D0510++, 0x30B261, 0x5566FF7F);
    func_8004D19C(0x78, D_8650D9D8 + 0x1F, func_8004C990(0x18F, D_8650D3E4[F53_CTRL(0)]), 0, 0);
    gSPDisplayList(D_800D0510++, D_80094F50);
    g = D_800D0510++;
    g->words.w0 = 0xDE000000;
    g->words.w1 = (u32)D_80094E38;
    for (i = 0; i < 4; i++) {
        func_87F061F0();
        gDPSetPrimColor(D_800D0510++, 0, 0, D_8650C680[i].prim_r, D_8650C680[i].prim_g, D_8650C680[i].prim_b,
                        D_8650C680[i].prim_a);
        gDPSetEnvColor(D_800D0510++, D_8650C680[i].env_r, D_8650C680[i].env_g, D_8650C680[i].env_b, 0xFF);
        if (F53_CTRL(0xC) == 9) {
            F53_ACTOR(i, 0x44) = 200;
            func_86506E78(i, 0);
        }
        func_86506E78(i, 0);
        if (F53_CTRL(0x30) == 2) {
            D_86511900[i] = F53_ACTOR(i, 0x8);
            if (F53_ACTOR(i, 0x80) < 0) {
                D_86511900[i] = -F53_ACTOR(i, 0x80);
            }
            D_86511910[i] = F53_ACTOR(i, 0x80);
        }
        if (F53_CTRL(0x30) == 3) {
            if (F53_ACTOR(i, 0x40) == 0) {
                if (D_8650D1B0 >= 0x10 && D_8650C494 == 0) {
                    F53_ACTOR(i, 0x44) += 10;
                }
                if (F53_ACTOR(i, 0x44) + 10 >= 200) {
                    F53_ACTOR(i, 0x40) = 1;
                    F53_ACTOR(i, 0x44) = 200;
                    func_80027A28(0x1F0B, i);
                } else {
                    if (D_8650C4B0 < 5 || F53_ACTOR(i, 0x8) == 0x14) {
                        if (*((u8 *)D_8650DB10 + 0x2180) != 4) {
                            func_86502D80(i);
                            func_86506B2C(i);
                        }
                    }
                    func_86506E78(i, 1);
                }
            }
            if (F53_ACTOR(i, 0x44) > 0xA0 && D_8650D1B0 >= 0x15 && D_8650C494 == 0 && D_86511900[i] > 0) {
                D_86511900[i]--;
                if (F53_ACTOR(i, 0x80) < 0) {
                    if (D_86511910[i] == 0 || F53_ACTOR(i, 0x18) <= 0) {
                        D_86511900[i] = 0;
                    } else {
                        F53_ACTOR(i, 0x18)--;
                    }
                    D_86511910[i]++;
                } else {
                    F53_ACTOR(i, 0x18)++;
                }
            }
        }
    }
    gSPDisplayList(D_800D0510++, D_80094F50);
    func_800498C4();
    func_800496A4(4, 0);
    Font_EnableTwoCycleTexturing();
    func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
    func_800497E4(0, 0, 0xFF, 0xFF);
    if (D_8650D0A4 != D_8650D3E0 && F53_CTRL(0x54) == 0 && saved < D_8650C4B0) {
        D_8650D3E0 = D_8650D0A4;
        D_8650D3DC = 30;
    }
    if (D_8650D3DC > 0) {
        D_8650D3DC--;
        func_800495F8(0xA0, 0x64, 1, D_8650D638);
    }
    Font_DisableTwoCycleTexturing();
    func_800499EC();
}

s32 D_8650D3E4[5] = { 0, 1, 2, 3, 4 };
s16 D_8650D3F8 = 0x600;
f32 D_8650D3FC = 0.15f;
s32 D_8650D400 = -16;
s32 D_8650D404 = 0x6C;
s32 D_8650D408[4] = { -10, 0, 0, 0 };
#endif

#ifdef VERSION_US
s32 func_87F00930();
extern void func_87F01D44();

void func_86508294(void) {
    if (func_87F00930() == 1) {
        func_87F01D44();
    }
}
#endif

#ifdef VERSION_US
extern Gfx *D_800D0510;
extern void *D_8650DB1C;
extern void *D_8650DB20;
extern u8 D_8650DA70[];
extern u8 D_8650DA60[];
extern s32 D_8650C62C;
extern s32 D_8650DAD8;
extern Ctrl5E0 D_8650C5E0;
extern void *D_8650DB10;
extern void func_800088DC(void);
extern void func_8000766C(Gfx **, s32, s32, s32, s32);
extern void func_800468A0(void *);
extern void GeoRender_AdvanceFrameCounter(void);
extern void Geo_RenderRootNode(void *);
extern void func_87F07FE8(void *);
extern void func_86507AFC(void);
extern void func_87F022F0(void);
extern void func_865064B0(void);
extern void func_87F0A5BC(void *);
extern void func_87F0C88C(void *);
extern void func_80008648(void);
void Fragment53_DrawSceneFrame(void) {
    func_800088DC();
    func_8000766C(&D_800D0510, 0, 0, 320, 240);
    func_800468A0(D_8650DB1C);
    if (D_8650C494 == 0) {
        GeoRender_AdvanceFrameCounter();
    }
    Geo_RenderRootNode(D_8650DB20);
    switch (*(s32 *)((u8 *)&D_8650C5E0 + 0xC)) {
        case 2:
        case 12:
            if (*(s32 *)((u8 *)&D_8650C5E0 + 0x4C) == 1) {
                func_87F07FE8(&D_8650DAD8);
            } else {
                func_86507AFC();
            }
            if (D_8650C62C == 2) {
                func_86507AFC();
                func_87F022F0();
            }
            if (D_8650C62C == 3) {
                func_86507AFC();
                func_86508294();
            }
            break;
        case 0:
        case 4:
        case 5:
            if (*(u8 *)((u8 *)D_8650DB10 + 0x2180) != 4) {
                func_87F07FE8(&D_8650DAD8);
            }
            break;
        case 10:
            func_865064B0(); /* fall through */
        case 1:
        case 6:
            func_86507AFC();
            func_86508294();
            break;
        case 9:
            func_86507AFC();
            func_87F0A5BC(D_8650DA70);
            break;
        case 8:
            func_86507AFC();
            func_87F022F0();
            break;
    }
    if (*(u8 *)((u8 *)D_8650DB10 + 0x2180) == 4) {
        func_87F0C88C(D_8650DA60);
    }
    func_80008648();
}
#endif

#ifdef VERSION_US
extern struct Fragment53Model D_8650E6C0[];
extern s32 D_8650DB28[];
extern u8 D_8650E6E4[];
extern u8 D_8650EC60[];
extern u8 D_8650DB80[];
extern u8 D_8650F7A0[];
extern u8 D_865118F8[];
extern void func_8003F114(void *, s32, s32, s32);
extern void ModelAnim_SetEventFrame(u8 *, s16);
extern void func_8003F3BC(void *, s32);
extern void func_87F06430(void *, s32);
extern void func_8003F1DC(void *);
extern s32 ModelAnim_SetSpeed(u8 *, s32);
extern void func_819006A0(void *);
extern void Fragment53_InitActorStateAndOrder(void);
void Fragment53_InitActorModels(void) {
    s32 index;

    for (index = 0; index < 4; index++) {
        func_8003F114((u8 *)&D_8650E6C0[index], 0, -1, D_8650DB28[index]);
        ModelAnim_SetAnimation((u8 *)&D_8650E6C0[index], 0);
        ModelAnim_SetSpeed((u8 *)&D_8650E6C0[index], 0x20000);
        ModelAnim_SetFrame((u8 *)&D_8650E6C0[index], (s16)(guRandom() % 15 + 15));
        ModelAnim_SetEventFrame((u8 *)&D_8650E6C0[index], 0);
        func_8003F3BC((u8 *)&D_8650E6C0[index], 0);
        func_87F06430(D_8650E6E4 + index * 0x168, index);
        *(f32 *)((u8 *)&D_8650E6C0[index] + 0x38) = 0.095f;
        *(f32 *)((u8 *)&D_8650E6C0[index] + 0x34) = 0.095f;
        *(f32 *)((u8 *)&D_8650E6C0[index] + 0x30) = 0.095f;
        *(f32 *)((u8 *)&D_8650E6C0[index] + 0x28) = 55.0f;
        *(s16 *)((u8 *)&D_8650E6C0[index] + 0x1E) = 0;
        D_86511698[index].animation = 0;
        D_86511698[index].pending = 0;
        func_8003F1DC(D_8650EC60 + index * 0x168);
        func_8003F1DC((u8 *)&D_8650E120[index]);
        *(s16 *)((u8 *)&D_8650E6C0[index] + 0x20) = 0;
        func_8003F1DC(D_8650DB80 + index * 0x168);
        func_8003F1DC(D_8650F7A0 + index * 0x168);
    }
    func_819006A0(*(void **)D_865118F8);
    Fragment53_InitActorStateAndOrder();
}
#endif

#ifdef VERSION_US
extern s32 ModelAnim_IsFinished(void *);
extern void func_80027A28(u16, u8);
void Fragment53_UpdateTimedSecondaryAnimation(s32 arg0) {
    s32 index;
    u8 *model;

    index = arg0;
    switch (D_86511698[index].animation) {
    case 0:
        model = (u8 *)&D_8650E6C0[index];
        if ((*(s32 *)(model + 0x48) >> 16) >= 6) {
            ModelAnim_SetAnimation(model, 2);
            ModelAnim_SetFrame(model, 0);
            ModelAnim_SetSpeed(model, 0x30000);
            D_86511698[index].animation = 2;
        }
        break;
    case 2:
        model = (u8 *)&D_8650E6C0[index];
        if (ModelAnim_IsFinished(model) == 1) {
            func_80027A28(0x1F04, (u8)index);
            ModelAnim_SetAnimation(model, 1);
            ModelAnim_SetSpeed(model, 0x20000);
            D_86511698[index].animation = 1;
        }
        break;
    }
}
#endif

void func_86508778(void) {
}

#ifdef VERSION_US
void Fragment53_UpdateSecondaryAnimation(s32 arg0) {
    s32 index;

    index = arg0;
    switch (D_86511698[index].animation) {
    case 0:
        ModelAnim_SetAnimation((u8 *)&D_8650E6C0[index], 2);
        ModelAnim_SetSpeed((u8 *)&D_8650E6C0[index], 0x30000);
        D_86511698[index].animation = 2;
        D_86511698[index].pending = 1;
        break;
    case 2:
        if (ModelAnim_IsFinished((u8 *)&D_8650E6C0[index]) == 1) {
            ModelAnim_SetAnimation((u8 *)&D_8650E6C0[index], 1);
            D_86511698[index].pending = 0;
        }
        break;
    }
}
#endif

#ifdef VERSION_US
void func_86508890(void) {
    s32 i;

    if (StageContext_GetFadeMode() == 1) {
        for (i = 0; i < 4; i++) {
            func_8003F1DC(&D_8650E6C0[i]);
            func_8003F114(&D_8650E120[i], 0, -1, D_8650DB28[i]);
            ModelAnim_SetEventFrame((u8 *)&D_8650E120[i], 0);
            func_8003F3BC(&D_8650E120[i], 0);
            func_8003F210(&D_8650E120[i], 0);
            ModelAnim_SetFrame((u8 *)&D_8650E120[i], (s16)(guRandom() % 15 + 15));
            D_86511698[i].animation = 0;
        }
        StageFade_StartFromOpaque(20);
        func_87F00688();
        D_8650C5EC = 6;
        return;
    }
    for (i = 0; i < 4; i++) {
        if (D_86511698[i].kind == 55) {
            Fragment53_UpdateTimedSecondaryAnimation(i);
        } else {
            Fragment53_UpdateSecondaryAnimation(i);
        }
    }
}
#endif

#ifdef VERSION_US
extern s32 StageFade_StartFromTransparent(s32);
extern s32 func_800226C0(s32);
extern s32 func_86501280();
s32 func_87F08208(s32 *);
extern Ctrl5E0 D_8650C5E0;
extern s32 D_8650DAD8;
extern void Audio_PlayDefaultSound(s32);
void func_86508A14(void) {
    s32 temp_v0;

    temp_v0 = func_87F08208(&D_8650DAD8);
    switch (temp_v0) {                              /* irregular */
    case 1:
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(0x14);
        func_86501280();
        (*(s32 *)((u8 *)(&D_8650C5E0) + (0xC))) = 5;
        func_800225C4(0x28);
        Audio_PlayDefaultSound(0xCF0B);
        return;
    case 2:
        (*(s32 *)((u8 *)(&D_8650C5E0) + (0xC))) = 2;
        (*(s32 *)((u8 *)(&D_8650C5E0) + (0x4C))) = 1;
        (*(s32 *)((u8 *)(&D_8650C5E0) + (0x58))) = 0;
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(0xA);
        func_800226C0(3);
        return;
    }
}
#endif

#ifdef VERSION_US
extern s32 D_8650C5EC;
extern void *D_8650DB10;
void func_86508ABC(void) {
    if (StageContext_GetFadeMode() == 0) {
        if ((*(u8 *)((u8 *)(D_8650DB10) + (0x2180))) == 4) {
            StageFade_StartFromOpaque(0x14);
            func_87F00688();
            D_8650C5EC = 6;
            return;
        }
        D_8650C5EC = 4;
    }
}
#endif

#ifdef VERSION_US
extern s32 D_8650DB40[];
extern s32 D_8650DB70[];
extern u32 func_87F006AC(void);
extern void func_80027774(u16, u8);
/* The caller discards this value; only the paused path specifies a result. */
s32 Fragment53_UpdateStartState(void) {
    s32 i;

    if (D_8650C494 == 1) {
        return 0;
    }
    if ((s32)func_87F006AC() == 1) {
        Audio_PlayDefaultSound(0x1F0D);
    }
    if ((s32)func_87F006AC() == 2) {
        Audio_PlayDefaultSound(0x1F0E);
        *(s32 *)((u8 *)&D_8650C5E0 + 0xC) = 1;
        *(s32 *)((u8 *)&D_8650C5E0 + 8) = -2;
        func_80027774(0x1B06, 140);
        *(s32 *)((u8 *)&D_8650C5E0 + 0x38) = 1;
        for (i = 0; i < 4; i++) {
            func_8003F114(D_8650DB80 + i * 0x168, 0, -1, D_8650DB40[i]);
            func_8003F114(D_8650F7A0 + i * 0x168, 0, -1, D_8650DB70[0]);
        }
    }
}
#endif

#ifdef VERSION_US
extern s32 D_8650C4AC;
extern s32 D_8650C4CC;
extern f32 D_8650C4B8;
extern s32 D_8650C4BC;
extern s32 D_8650C4B0;
extern s32 D_8650C4C0;
extern f32 D_8650C4F4;
extern f32 D_8650C4F8;
extern f32 D_8650C4FC;
extern s32 D_8650C470;
extern s32 D_8650C4F0;
extern s32 D_8650C500;
extern s32 D_8650C504;
extern f32 D_8650C47C;
extern f32 D_8650C4D0;
extern f32 D_8650F230;
extern s32 D_8650D9D4;
extern u8 D_8650D648[];
extern u8 D_86510010[];
extern void func_86502524(void);
extern void osSyncPrintf(const char *, ...);
#define C5E0F(o) (*(f32 *)((u8 *)&D_8650C5E0 + (o)))
#define C5E0I(o) (*(s32 *)((u8 *)&D_8650C5E0 + (o)))

void func_86508C2C(void) {
    s32 changed;
    ControllerState *pad;
    u16 held;

    changed = 0;
    ModelAnim_SetFrame(D_86510010, 4);
    pad = D_80087200;
    if (pad->buttonsPressed & 0x400) {
        changed = 1;
        C5E0I(0x1C)++;
        if (C5E0I(0x1C) > 12) {
            C5E0I(0x1C) = 12;
        }
    } else if (pad->buttonsPressed & 0x800) {
        changed = 1;
        C5E0I(0x1C)--;
        if (C5E0I(0x1C) <= 0) {
            C5E0I(0x1C) = 1;
        }
    } else if ((pad->buttonsPressed & 0x100) || ((held = pad->buttonsHeld) & 1)) {
        if ((D_8650C4C0 > 0) && (pad->buttonsHeld & 1)) {
        } else {
            changed = 1;
            switch (C5E0I(0x1C)) {
                case 1:
                    D_8650C4AC++;
                    break;
                case 2:
                    D_8650C4CC++;
                    break;
                case 3:
                    D_8650C4B8 += 0.01f;
                    break;
                case 4:
                    D_8650C4BC *= 2;
                    if (D_8650C4BC >= 0x10) {
                        D_8650C4BC = 0x10;
                    }
                    break;
                case 5:
                    D_8650C4B0++;
                    if (D_8650C4B0 >= 0xA) {
                        D_8650C4B0 = 0xA;
                    }
                    break;
                case 6:
                    D_8650C4C0++;
                    if (D_8650C4C0 > 0) {
                        D_8650C4C0 = 1;
                    }
                    break;
                case 7:
                    D_8650C4F4 = D_8650C4F4 + 0.01;
                    break;
                case 8:
                    D_8650C470 = 1;
                    break;
                case 9:
                    D_8650C4F0 = 1;
                    break;
                case 10:
                    D_8650C500 = 1;
                    break;
                case 11:
                    D_8650C504 = 1;
                    break;
            }
        }
    } else if ((pad->buttonsPressed & 0x200) || (held & 2)) {
        if ((D_8650C4C0 > 0) && (held & 2)) {
        } else {
            changed = 1;
            switch (C5E0I(0x1C)) {
                case 1:
                    D_8650C4AC--;
                    if (D_8650D9D4 < 2) {
                        D_8650C4AC++;
                    }
                    break;
                case 2:
                    D_8650C4CC--;
                    break;
                case 3:
                    D_8650C4B8 -= 0.01f;
                    if (D_8650C4B8 <= 0.2f) {
                        D_8650C4B8 = 0.2;
                    }
                    break;
                case 4:
                    D_8650C4BC /= 2;
                    if (D_8650C4BC < 2) {
                        D_8650C4BC = 1;
                    }
                    break;
                case 5:
                    D_8650C4B0--;
                    if (D_8650C4B0 < 2) {
                        D_8650C4B0 = 1;
                    }
                    break;
                case 6:
                    D_8650C4C0--;
                    if (D_8650C4C0 <= 0) {
                        D_8650C4C0 = 0;
                    }
                    break;
                case 7:
                    D_8650C4F4 = D_8650C4F4 - 0.01;
                    if (D_8650C4F4 < 0.0f) {
                        D_8650C4F4 = 0.0f;
                    }
                    break;
                case 8:
                    D_8650C470 = 3;
                    break;
                case 9:
                    D_8650C4F0 = 0;
                    break;
                case 10:
                    D_8650C500 = 0;
                    break;
                case 11:
                    D_8650C504 = 0;
                    break;
            }
        }
    }
    if (C5E0I(0x1C) == 10) {
        if (pad->buttonsHeld & 0x8000) {
            if (D_8650C500 == 0) {
                D_8650C4F8 = D_8650C4F8 + 0.1;
            } else {
                D_8650C4FC = D_8650C4FC + 0.1;
            }
        }
        if (pad->buttonsHeld & 0x4000) {
            if (D_8650C500 == 0) {
                D_8650C4F8 = D_8650C4F8 - 0.1;
            } else {
                D_8650C4FC = D_8650C4FC - 0.1;
            }
        }
    }
    if (D_8650C4C0 > 0) {
        held = pad->buttonsHeld;
        changed = 1;
        if (held & 8) {
            D_8650C47C += 5.0f;
            if (D_8650D9D4 < 2) {
                D_8650C47C -= 5.0f;
            }
        } else if (held & 4) {
            D_8650C47C -= 5.0f;
            if (D_8650C47C < -500.0f) {
                D_8650C47C = -500.0f;
            }
        } else if (held & 0x8000) {
            C5E0F(0x2C) -= 10.0f;
            if (C5E0F(0x2C) < -2000.0f) {
                C5E0F(0x2C) = -2000.0f;
            }
        } else if (held & 0x4000) {
            C5E0F(0x2C) += 10.0f;
            if (C5E0F(0x2C) > 3000.0f) {
                C5E0F(0x2C) = 3000.0f;
            }
        } else if (held & 1) {
            D_8650C4D0 += 0.1f;
        } else if (held & 2) {
            D_8650C4D0 -= 0.1f;
        } else if (pad->buttonsPressed & 0x2000) {
            osSyncPrintf(D_8650D648, (f64)D_8650C4D0, (f64)C5E0F(0x2C), (f64)D_8650C47C, (f64)D_8650F230);
        }
    }
    if (changed != 0) {
        func_86502524();
    }
}
#endif

#ifdef VERSION_US
extern s16 D_8650D3F8;
extern f32 D_8650D3FC;
extern s32 D_8650D404;
extern s32 D_8650DB7C;


void func_86509318(void)
{
  /* D_8650E120 is the 0x168-stride model array (fields named at 0x28/0xAC/0xB4);
     D_8650EC60 is the matching node array (fields named at 0x24/0x28/0x2C and the
     three 0.0f stores at 0x30/0x34/0x38). */
  struct F53ModelF {
    u8 pad00[0x28];
    f32 h;
    u8 pad2C[0x80];
    f32 z;
    u8 padB0[4];
    f32 x;
    u8 tail[0xB0];
  };
  struct F53NodeF {
    u8 pad00[0x1D];
    u8 u;
    u8 pad1E[6];
    f32 z;
    f32 h;
    f32 x;
    f32 b30, b34, b38;
    u8 tail[0x12C];
  };
  s32 temp_v0;
  s32 var_s2;
  u8 *var_s3;
  struct F53ModelF *temp_s1;
  struct F53NodeF *temp_s0;
  f32 zero;
  f32 dy;
  f32 *sc;
  sc = &D_8650D3FC;
 zero = *sc; var_s2 = 0; var_s3 = (u8 *) D_86511698; do { if ((*((s32 *) (var_s3 + 0xC))) == 6) {
      temp_s1 = (struct F53ModelF *)&D_8650E120[var_s2];
      if (((*((s32 *) (((u8 *) temp_s1) + 0x48))) >> 0x10) >= 0x3C)
      {
        temp_s0 = (struct F53NodeF *)&D_8650EC60[var_s2 * 0x168];
        if (((*((s32 *) (((u8 *) temp_s1) + 0x48))) >> 0x10) == 0x3C)
        {
          func_8003F114((u8 *) temp_s0, 0, -1, D_8650DB7C);
          func_8003F210((u8 *) temp_s0, 0);
          /* Same address as temp_s0, but written out again: uopt gives this
             recomputed node pointer an alias class relative to temp_s1, so as1
             can move the three model loads ahead of the three zero stores in the
             block below. Reusing temp_s0 here leaves the pointer unclassified and
             the loads stay under the stores. */
          *((u8 *) (((u8 *) &D_8650EC60[var_s2 * 0x168]) + 0x1D)) = 0;
          dy = *sc;
          zero = dy;
        }
        dy = (f32) D_8650D404;
        temp_v0 = temp_s0->u + 5;
        if (temp_v0 < 0xFF)
        {
          temp_s0->u = temp_v0;
        }
        else
        {
          temp_s0->u = 0xFF;
        }
        temp_s0->b38 = zero;
        temp_s0->b34 = zero;
        temp_s0->b30 = zero;
        temp_s0->x = temp_s1->x;
        temp_s0->z = temp_s1->z;
        temp_s0->h = temp_s1->h + dy;
        *((s16 *) (((u8 *) temp_s0) + 0x1E)) = D_8650D3F8;
      }
    }
    var_s2 += 1;
    var_s3 += 0x98;
  }
  while (var_s2 != 4);
}
#endif

#ifdef VERSION_US
s32 func_87F01A40();
extern s32 D_8650C494;
void func_86509480(void) {
    s32 temp_v0;

    D_8650C494 = 1;
    temp_v0 = func_87F01A40();
    switch (temp_v0) {                              /* irregular */
    case 0:
    case 2:
        D_8650C494 = 0;
        return;
    case 3:
        (*(s32 *)((u8 *)(&D_8650C5E0) + (0x58))) = 0;
        (*(s32 *)((u8 *)(&D_8650C5E0) + (0xC))) = 2;
        (*(s32 *)((u8 *)(&D_8650C5E0) + (0x4C))) = 3;
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(0xA);
        return;
    case 4:
        (*(s32 *)((u8 *)(&D_8650C5E0) + (0x58))) = 1;
        (*(s32 *)((u8 *)(&D_8650C5E0) + (0xC))) = 2;
        (*(s32 *)((u8 *)(&D_8650C5E0) + (0x4C))) = 3;
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(0xA);
        return;
    }
}
#endif

#ifdef VERSION_US
extern s32 D_8650C494;
extern f32 D_8650C508;
extern f32 D_8650D12C;
extern f32 D_86511690;
extern f32 D_8650C4B8;
extern s32 D_8650C4AC;
extern s32 D_8650C4B0;
extern s32 D_8650C4C8;
extern s32 D_8650DB38[];
extern s32 D_8650DB40[];
extern u8 D_865110F0[];
extern u8 D_865118F8[];
extern u8 D_8650DB80[];
extern u8 D_8650F7A0[];
extern u8 D_8650F200[];
extern u8 D_865105B0[];
extern f32 D_865119A0[];
extern s32 D_865116A0, D_865116A4, D_865116A8;
extern s32 D_86511718, D_86511738, D_8651173C, D_86511740;
extern s32 D_865117B0, D_865117D0, D_865117D4, D_865117D8;
extern s32 D_86511848, D_86511868, D_8651186C, D_86511870;
extern s32 D_865118E0;
extern f32 D_8650E150, D_8650E154, D_8650E158;
extern f32 D_8650E2B8, D_8650E2BC, D_8650E2C0;
extern f32 D_8650E420, D_8650E424, D_8650E428;
extern f32 D_8650E588, D_8650E58C, D_8650E590;
extern void func_800279C4(s32);
extern void func_80021ED8(s32);
extern void func_8003F114(void *, s32, s32, s32);
extern void func_8003F1DC(void *);
extern u32 func_8003570C(void);
extern void func_86502720(void);
extern void func_86502B88(void);
#define D9D8 (*(s32 *)&D_8650D9D8)
#define ROUND_MAX(x) ((x) + ((x) > 0.0f ? 0.5f : -0.5f))
void func_8650952C(void) {
    static s32 D_8650D418 = 0;
    static s32 D_8650D41C = 0;
    s32 best = 0;
    s32 i;
    s32 r;
    s32 limit;
    u8 *st;
    if (D_86511690) {} // FAKE
    if (D_8650C4C8) {} // FAKE
    if (D_8650C4B0) {} // FAKE

    if ((*(s32 *)(u8 *)&D_8650C494 == 0) && (D_8650C5E0.f34 == 1)) {
        func_800279C4(0x1005);
    }
    if ((D_8650C5E0.f08 == -2) && (*(s32 *)(u8 *)&D_8650C494 == 0)) {
        switch (D_8650C5E0.f48) {
        case 5:
            D_8650C5E0.f48 = 0;
            D_8650D41C = 0;
            break;
        case 0:
            D_8650D41C++;
            if (D_8650D41C == 30) {
                func_80021ED8(0x12);
            }
            if (D9D8 < 20) {
                D9D8 += (s32)ROUND_MAX(2 * D_8650C508);
            } else {
                D_8650C5E0.f48 = 1;
            }
            if (D9D8 == 0) {
                func_8003F114((u8 *)&D_8650FD40, 0, -1, D_8650DB70[0]);
            }
            break;
        case 2:
            if (D9D8 >= -0x45) {
                D9D8 -= (s32)ROUND_MAX(4 * D_8650C508);
            }
            if (D9D8 <= 0) {
                func_8003F1DC((u8 *)&D_8650FD40);
            }
            break;
        case 1:
            D_8650D418++;
            if (D_8650D418 >= 0x10) {
                D_8650C5E0.f48 = 2;
                D_8650D418 = 0;
            }
            break;
        }
    }
    if ((D_8650C5E0.f08 == 1) && (*(s32 *)(u8 *)&D_8650C494 == 0)) {
        D_8650C5E0.f04++;
        if (D_86511690 > -3000.0f) {
            D_8650D12C += D_8650C4B8;
        }
        D_86511690 = D_8650C4AC - 4.9 * D_8650D12C * D_8650D12C;
        D_8650C5E0.f14 = (s32)D_86511690;
        if (D_8650C5E0.f04 == 0x32) {
            D_8650C5E0.f34 = 0;
            D_8650C5E0.f50 = 0;
            st = (u8 *)D_86511698; do {
                r = *(s32 *)(st + 8);
                st += 0x98;
                if ((r > 0) && (D_8650C5E0.f50 <= 0)) {
                    D_8650C5E0.f50 = 1;
                }
                if ((r >= 0xE) && (D_8650C5E0.f50 < 2)) {
                    D_8650C5E0.f50 = 2;
                }
                if ((r | 0) == 0x14) {
                    D_8650C5E0.f50 = 3;
                }
            } while (st != D_865118F8);
            if (best) {} // FAKE
            limit = D_8650C5E0.f50;
            switch (limit) {
            case 3:
                func_80027774(0x1C07, 0x8C);
                break;
            case 2:
                func_80027774(0x1D08, 0x8C);
                break;
            case 1:
                func_80027774(0x1E09, 0x8C);
                break;
            case 0:
                break;
            }
        }
    }
    if (D_8650C5E0.f04 == 0x50) {
        D_8650C5E0.f30 = 1;
        for (i = 0; i < 4; i++) {
            if (*(s32 *)((u8 *)&D_86511698[i] + 8) == 0) {
                *(s32 *)((u8 *)&D_86511698[i] + 0x80) = -10;
            }
            *(f32 *)((u8 *)&D_8650E120[i] + 0x30) = 0.25f;
            *(f32 *)((u8 *)&D_8650E120[i] + 0x38) = 0.25f;
            *(f32 *)((u8 *)&D_8650E120[i] + 0x34) = 0.25f;
        }
    }
    limit = 10000;
    switch (D_8650C5E0.f30) {
    case 1:
        st = D_865110F0; do {
            func_8003F114(st, 0, -1, D_8650DB38[0]);
            st += 0x168;
        } while (st != (u8 *)&D_86511690);
        break;
    case 6:
        st = (u8 *)D_86511698;
        if (D_8650C4C8 == 1) {
            do {
                r = *(s32 *)(st + 8);
                st += 0x98;
                if (best < r) {
                    best = r;
                }
            } while (st < (u8 *)&D_86511698[4]);
            for (i = 0; i < 4; i++) {
                *(s32 *)((u8 *)&D_86511698[i] + 0x10) = 1;
                *(s32 *)((u8 *)&D_86511698[i] + 0xC) = 6;
            }
        }
        D_8650C5E0.f30 = 4;
        break;
    case 5:
        best = (s32)(D_865110F0 + 0x5A0);
        st = D_865110F0;
        do {
            func_8003F1DC(st);
            st += 0x168;
        } while ((s32)st != best);
        D_8650C5E0.f50 = 0;
        limit = 0;
        break;
    }
    if (limit + 0x50 < D_8650C5E0.f04) {
        D_86511690 = (f32)D_8650C4AC;
        D_8650D12C = 0;
        D_8650C5E0.f08 = -2;
        D_8650C5E0.f00++;
        for (i = 0; i < 4; i++) {
            D_865119A0[i] = 0.0f;
            r = func_8003570C() % 11;
            if (r >= 6) {
                *(s16 *)(D_8650F200 + i * 0x168 + 0x1E) = (r * 256) / 2;
            } else {
                *(s16 *)(D_8650F200 + i * 0x168 + 0x1E) = (r * -256) / 2;
            }
            if ((r & 1) == 0) {
                *(s16 *)(D_8650F200 + i * 0x168 + 0x22) = r * 32;
            } else {
                *(s16 *)(D_8650F200 + i * 0x168 + 0x22) = r * -32;
            }
            *(f32 *)(D_865105B0 + i * 0x2D0 + 0x18C) = *(f32 *)((u8 *)&D_8650E120[i] + 0x24);
            *(f32 *)(D_865105B0 + i * 0x2D0 + 0x194) = 40.0f;
            *(f32 *)(D_865105B0 + i * 0x2D0 + 0x198) = *(f32 *)(D_8650F200 + i * 0x168 + 0x30);
            *(f32 *)(D_865105B0 + i * 0x2D0 + 0x19C) = *(f32 *)(D_8650F200 + i * 0x168 + 0x34);
            *(f32 *)(D_865105B0 + i * 0x2D0 + 0x1A0) = *(f32 *)(D_8650F200 + i * 0x168 + 0x38);
            *(s32 *)((u8 *)&D_86511698[i] + 0x34) = 0;
            *(s32 *)((u8 *)&D_86511698[i] + 0x30) = 0;
            *(s16 *)(D_865105B0 + i * 0x2D0 + 0x18A) = 0;
            *(s16 *)(D_865105B0 + i * 0x2D0 + 0x186) = 0;
            if (*(s32 *)&D_86511698[i] != -1) {
                *(s32 *)&D_86511698[i] = -1;
            }
            if (*(s32 *)((u8 *)&D_86511698[i] + 0x40) == 0) {
                *(s32 *)((u8 *)&D_86511698[i] + 0x18) += *(s32 *)((u8 *)&D_86511698[i] + 8);
            }
            if (D_8650C5E0.f00 != D_8650C4B0) {
                func_8003F114(D_8650DB80 + i * 0x168, 0, -1, D_8650DB40[i]);
                func_8003F114(D_8650F7A0 + i * 0x168, 0, -1, D_8650DB70[0]);
            }
        }
        func_86502720();
        if (D_8650C5E0.f00 == D_8650C4B0) {
            func_86502B88();
            D_86511690 = -800.0f;
            D_8650C5E0.f0C = 9;
            D_8650C5E0.f08 = -3;
        } else {
            D_8650C5E0.f38 = 1;
            func_80027774(0x1B06, 0x8C);
        }
    }
}

// The .data words after func_8650952C's function statics (D_8650D418/D_8650D41C).
s32 D_8650D420 = 0;
s32 D_8650D424 = 0x50;
s32 D_8650D428 = 0;
s32 D_8650D42C = 0;

#endif

#ifdef VERSION_US
extern s32 func_87F02104(void);
void func_86509D8C(void) {
    s32 temp_v0;

    temp_v0 = func_87F02104();
    switch (temp_v0) {
    case 1:
        StageContext_SetClearColor(1);
        *(s32 *)((u8 *)&D_8650C5E0 + 0xC) = 0xC;
        *(s32 *)((u8 *)&D_8650C5E0 + 0x4C) = 2;
        StageFade_StartFromTransparent(0xA);
        *(s32 *)((u8 *)&D_8650C5E0 + 0x8) = 0;
        return;
    case 2:
        *(s32 *)((u8 *)&D_8650C5E0 + 0x58) = 0;
        *(s32 *)((u8 *)&D_8650C5E0 + 0xC) = 2;
        *(s32 *)((u8 *)&D_8650C5E0 + 0x4C) = 2;
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(0xA);
        return;
    case 3:
        *(s32 *)((u8 *)&D_8650C5E0 + 0x58) = 1;
        *(s32 *)((u8 *)&D_8650C5E0 + 0xC) = 2;
        *(s32 *)((u8 *)&D_8650C5E0 + 0x4C) = 2;
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(0xA);
        return;
    }
}
#endif

#ifdef VERSION_US
extern u8 D_8650DA38[];
extern s32 D_8650C638;
extern s32 func_87F0C6F4(u8 *);
extern s32 func_87F00930(void);
extern void func_87F006BC(void);
extern void func_81900214(s32);
extern s32 Fragment64_UpdateBounceAndConfirm(u8 *);
extern void func_87F02328(void);
extern void func_87F0D5B8(u8 *);

// Per-frame scene state dispatcher. Fragment53_RunScene passes the current state
// (D_8650C5EC) as arg0, but the dispatch reads the global directly; the state left
// in D_8650C5EC is returned to the caller.
s32 func_86509E54(s32 arg0) {
    // FAKE: returning through a u32 local reproduces the original's return-value registers.
    u32 state;

    if ((((u8 *)D_8650DB10)[0x2180] == 4) && (func_87F0C6F4(D_8650DA60) != 0)) {
        D_8650C5EC = 3;
        D_8650C638 = 3;
    }
    if ((func_87F00930() == 0) && (D_8650C5EC != 10)) {
        func_87F006BC();
    }
    switch (D_8650C5EC) {
        case 0:
            func_86508ABC();
            break;
        case 4:
            func_86508A14();
            break;
        case 5:
            func_86508890();
            break;
        case 6:
            func_86509480();
            func_86508B20();
            break;
        case 9:
            func_81900214(*(s32 *)D_865118F8);
            func_86509318();
            if (Fragment64_UpdateBounceAndConfirm(D_8650DA70) != 0) {
                if (((u8 *)D_8650DB10)[0x2180] == 1) {
                    StageContext_SetClearColor(0xFFFF);
                    StageFade_StartFromTransparent(10);
                    D_8650C638 = 2;
                    D_8650C5EC = 2;
                    D_8650C62C = 0;
                } else {
                    func_87F02328();
                    D_8650C5EC = 8;
                }
            }
            break;
        case 1:
            func_86509480();
            func_8650952C();
            break;
        case 8:
            func_86509D8C();
            break;
        case 12:
            if (StageContext_GetFadeMode() == 1) {
                func_86508484();
                D_8650C5EC = 11;
                StageFade_StartFromOpaque(10);
            }
            break;
        case 11:
            D_8650C5EC = 0;
            break;
        case 10:
            func_86508C2C();
            break;
        case 2:
            if (StageContext_GetFadeMode() == 1) {
                D_8650C5EC = 3;
            }
            break;
    }
    func_87F0D5B8(D_8650DA38);
    state = D_8650C5EC;
    return state;
}
#endif

#ifdef VERSION_US
extern s32 D_8650C4B0;
extern s32 D_8650C46C;
extern s32 D_8650C480[];
extern s32 D_8650C494;
extern s32 D_8650C504;
extern f32 D_8650C508;
extern Ctrl5E0 D_8650C5E0;
extern u8 D_865118F8[];
extern f32 D_8650D12C;
extern s32 D_8650D428;
extern s32 D_8650D42C;
extern s32 D_8650D9E0[];
extern u32 func_8003570C(void);


void func_8650A074(void) {
    s32 busy;
    s32 mode;
    s32 offset;
    struct Fragment53ActorState *state;

    s32 *p;
    s32 *q;

    p = &D_8650D42C;
    q = &D_8650D428;

    mode = *(s32 *)((u8 *)&D_8650C5E0 + 8);
    // FAKE: no-op kept only to steer uopt's register assignment; without it mode/offset
    // land in v1/v0 and the function scores 45 instead of 0 (80 without both no-ops).
    if (mode) {}
    if (mode == 0) {
        *(s32 *)((u8 *)&D_8650C5E0 + 0x18) += 1;
        if (*(s32 *)((u8 *)&D_8650C5E0 + 0x18) >= 21) {
            *(s32 *)((u8 *)&D_8650C5E0 + 0x18) = 0;
        }
        if (*(s32 *)((u8 *)&D_8650C5E0 + 0) == 0) {
            *q = 3;
            *p = 0;
        }
    }
    offset = D_8650D42C;
    if (mode == -1 && D_8650C494 == 0 &&
        *(s32 *)((u8 *)&D_8650C5E0 + 0xC) == 1) {
        D_8650C46C += 1;
    }
    if (D_8650C504 == 1) {
        *q = D_8650D9E0[*(s32 *)((u8 *)&D_8650C5E0 + 0)];
        offset = 0;
    }
    *p = offset;
    if ((f32)(D_8650C480[D_8650D428] + offset) < (f32)D_8650C46C * D_8650C508) {
        if (D_8650C494 == 0) {
            busy = 0;
            state = D_86511698;
            do {
                if (state->animation != 1) {
                    busy = 1;
                }
                state++;
            } while (state != (struct Fragment53ActorState *)D_865118F8);
            if (busy == 0) {
                D_8650C46C = 0;
                // FAKE: no-op kept only to steer uopt's register assignment; without it busy
                // and the loop-end pointer land in v1/a0 and the function scores 35 instead of 0.
                if (busy) {}
                offset = func_8003570C() % 51;
                *p = offset;
                if (offset < 15) {
                    *p = 0;
                }
                D_8650D12C = 0.0f;
                *q = func_8003570C() % 5;
                *(s32 *)((u8 *)&D_8650C5E0 + 8) = 1;
                D_8650D12C = 0.0f;
            }
            if (D_8650C4B0 < *(s32 *)((u8 *)&D_8650C5E0 + 0)) {
                *(s32 *)((u8 *)&D_8650C5E0 + 0xC) = 9;
                D_8650C494 = 1;
            }
        }
    }
}
#endif

#ifdef VERSION_US
extern void func_800086A4(s32);
extern void func_80064D28(void);
extern void func_8650A074(void);
extern void Fragment53_DrawSceneFrame(void);
extern s32 func_86509E54(s32);
void Fragment53_RunSceneTransition(void) {
    u8 *model;
    struct Fragment53ActorState *state;
    u8 *secondary;
    s32 *resource;
    s32 result;

    func_800086A4(2);
    if (*(u8 *)((u8 *)D_8650DB10 + 0x2180) == 4) {
        secondary = (u8 *)D_8650E6C0; model = (u8 *)D_8650E120;
        resource = D_8650DB28; state = D_86511698; do {
            func_8003F1DC(secondary);
            func_8003F114(model, 0, -1, *resource);
            ModelAnim_SetEventFrame(model, 0);
            func_8003F3BC(model, 0);
            ModelAnim_SetAnimation(model, 0);
            ModelAnim_SetFrame(model, (s16)(guRandom() % 15 + 15));
            state++;
            secondary += 0x168;
            model += 0x168;
            resource++;
            state[-1].animation = 0;
        } while ((struct Fragment53ActorState *)D_865118F8 != state);
    }
    StageFade_StartFromOpaque(10);
    do {
        func_8650A074();
        func_80064D28();
        Fragment53_DrawSceneFrame();
        result = func_86509E54(*(s32 *)((u8 *)&D_8650C5E0 + 0xC));
        *(s32 *)((u8 *)&D_8650C5E0 + 0xC) = result;
    } while (*(s32 *)((u8 *)&D_8650C5E0 + 0xC) != 3);
}
#endif

#ifdef VERSION_US
extern s32 D_8650DB18;
extern u32 D_8650DAE0;
extern u32 D_8650DA90;
extern s32 D_8650C638;
extern u8 D_1000000[];
extern u8 D_446E30[];
extern u8 D_447D00[];
extern s32 func_80001FF0(void);
extern void func_80027EE0(s32);
extern void main_pool_push_state(s32);
extern void Gfx_InitDisplayListBuffers(s32, s32);
extern s32 func_800082E0(s32, s32, s32, s32, s32, s32);
extern void func_8004C09C(s32);
extern void func_87F06EAC(s32, void *, void *);
extern s32 func_8004DDF4(s32);
extern void func_8004C8C0(s32);
extern s32 func_8004DEF8(s32);
extern s32 func_8004D690(s32);
extern void func_80047588(u32, s32);
extern u8 *Asset_LoadToSegment(s32, u8 *, u8 *, s32);
extern void func_87F00030(void);
extern void func_87F01F34(void *);
extern void func_86505EA8(void);
extern void func_80008514(s32);
extern void func_80008574(void);
extern void func_80047610(void);
extern void func_8004C398(void);
extern void Gfx_FreeDisplayListBuffers(void);
extern void main_pool_pop_state(s32);
extern void func_87F0F480(void *);
s32 Fragment53_RunScene(s32 arg0, void *context) {
    s32 handle;

    if (func_80001FF0() == 60) {
        D_8650C508 = 1.0f;
    } else {
        D_8650C508 = 1.2f;
    }
    D_8650DB10 = context;
    if (*(u8 *)((u8 *)D_8650DB10 + 0x2180) == 4) {
        func_80027EE0(0xFFF);
    }
    main_pool_push_state(0x4D523031);
    Gfx_InitDisplayListBuffers(0x20000, 0);
    handle = func_800082E0(0, 1, 3, 1, 2, 1);
    func_8004C09C(0x127);
    func_87F06EAC(0x6B, &D_8650DAD8, D_8650DB10);
    func_8004DDF4(0x51);
    func_8004DDF4(0x6F);
    func_8004DDF4(0x70);
    func_8004DDF4(0x3B);
    func_8004C8C0(0x1B2);
    func_8004C8C0(0x1AD);
    func_8004C8C0(0x18D);
    func_8004C8C0(0x18F);
    func_8004C8C0(0x18E);
    D_8650DB18 = func_8004DEF8(0x3B);
    D_8650DB1C = (void *)func_8004D690(15);
    func_80047588(D_8650DAE0 | 5 | D_8650DA90, 0);
    Asset_LoadToSegment(((u32)D_1000000 & 0x0F000000) >> 24, D_446E30, D_447D00, 0);
    func_87F00030();
    func_87F01F34(D_8650DB10);
    func_86505EA8();
    func_80008514(handle);
    Fragment53_RunSceneTransition();
    func_80008574();
    func_80047610();
    func_8004C398();
    Gfx_FreeDisplayListBuffers();
    main_pool_pop_state(0x4D523031);
    func_87F0F480(D_8650DB10);
    func_80027EE0(0xFFE);
    return D_8650C638;
}
#endif
