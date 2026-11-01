#include "global.h"
#include "controller.h"


#ifdef VERSION_US
extern void Util_Free(s32);
extern s32 D_880068B4;
extern s32 D_88523010;

void func_88506990(void) {
    D_880068B4 = 1;
    Util_Free(D_88523010);
}

extern void func_800226C0(s32);
extern void func_8850A0A0(s32, s32, s32, s32);
void func_885069C0(void) {
    if ((*(s32 *)((u8 *)(D_88523010) + (0x18))) != 0) {
        func_8850A0A0(0, 0x11F, 0x280, 0x65);
        func_800226C0(0x14D);
        return;
    }
    func_8850A0A0(0x28, 0x14, 0x230, 0x100);
}

extern void func_88004990(s32,s32);
void func_88506A20(void){func_8850A0A0(0,0,0x280,0x1E0);func_88004990(0,0);func_88004990(1,0);func_88004990(2,0);if(*(s32 *)((u8 *)D_88523010+0x18)!=0)func_88004990(3,0);func_88004990(4,0);func_88004990(5,0);}

extern s8 D_8800EF41;
extern u8 D_8850D6D8;
extern s8 D_8800EF40;
void func_88506AA8(void) {
    s16 temp_v1;
    s8 *var_a0;

    D_8800EF40 = (s8) (*(s16 *)((u8 *)(D_88523010) + (0x2C)));
    if ((*(s16 *)((u8 *)(D_88523010) + (0x2C))) != -1) {
        temp_v1 = (*(s16 *)((u8 *)(D_88523010) + (0x24)));
        if (temp_v1 < 2) {
            var_a0 = (temp_v1 * 0xA960) + &D_8850D6D8;
        } else {
            var_a0 = ((*(s16 *)((u8 *)(D_88523010) + (0x26))) * 0xA960) + &D_8850D6D8;
        }
        D_8800EF41 = *var_a0;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/34/fragment34_1C3FA0/func_88506B2C.s")

/* mkdraft:func_8850716C begin */
extern s32 D_88523018;

s32 func_8005A228(s8);
s32 func_88506B2C();



void func_8850716C(void) {
    s16 temp_v1;
    s32 temp_v0;

    *(s16 *)((u8 *)(D_88523010) + (0x1E)) = (s16) (*(s16 *)((u8 *)(D_88523010) + (0x1E)) - 1);
    if (*(s16 *)((u8 *)(D_88523010) + (0x1E)) <= 0) {
        *(s16 *)((u8 *)(D_88523010) + (0x1E)) = 0;
        if (*(s16 *)((u8 *)(D_88523010) + (0x28)) == 1) {
            temp_v0 = func_8005A228(*(s8 *)((u8 *)&D_8850D6D8 + (*(s16 *)((u8 *)(D_88523010) + (0x26)) * 0xA960)));
            if (temp_v0 == 1) {
                *(s16 *)((u8 *)(D_88523010) + (0x2C)) = 1;
            }
            if (temp_v0 == 3) {
                *(s16 *)((u8 *)(D_88523010) + (0x2C)) = 3;
            }
            if (temp_v0 == 2) {
                *(s16 *)((u8 *)(D_88523010) + (0x28)) = 2;
                *(s16 *)((u8 *)(D_88523010) + (0x2A)) = 3;
                *(s16 *)((u8 *)(D_88523010) + (0x2C)) = 0;
            }
        }
        if (*(s16 *)((u8 *)(D_88523010) + (0x28)) == 2) {
            *(s16 *)((u8 *)(D_88523010) + (0x2A)) = (s16) (*(s16 *)((u8 *)(D_88523010) + (0x2A)) - 1);
            temp_v1 = *(s16 *)((u8 *)(D_88523010) + (0x2A));
            if (temp_v1 == 1) {
                if (*(s8 *)((u8 *)(D_88523010) + (0x1C)) == 0) {
                    func_800226C0(0x14A);
                } else {
                    func_800226C0(0x14B);
                }
            } else if (temp_v1 <= 0) {
                *(s16 *)((u8 *)(D_88523010) + (0x28)) = 0;
                *(s16 *)((u8 *)(D_88523010) + (0x2A)) = 0;
            }
        }
        if (*(s16 *)((u8 *)(D_88523010) + (0x28)) == 0) {
            if (func_88506B2C() != 0) {
                D_88523018 = 0;
                func_88506A20();
                *(s16 *)((u8 *)(D_88523010) + (0x2C)) = -1;
                func_800226C0(0x11);
                return;
            }
            *(s16 *)((u8 *)(D_88523010) + (0x28)) = 1;
            func_800226C0(5);
            *(s16 *)((u8 *)(D_88523010) + (0x2C)) = 2;
            temp_v0 = func_8005A228(*(s8 *)((u8 *)&D_8850D6D8 + (*(s16 *)((u8 *)(D_88523010) + (0x26)) * 0xA960)));
            if (temp_v0 == 1) {
                *(s16 *)((u8 *)(D_88523010) + (0x2C)) = 1;
                return;
            }
            if (temp_v0 == 3) {
                *(s16 *)((u8 *)(D_88523010) + (0x2C)) = 3;
            }
        }
    }
}
/* mkdraft:func_8850716C end */

/* mkdraft:func_88507370 begin */
extern s32 D_88523018;
#ifndef M2C_FIELD /* mkdraft: m2c --valid-syntax helpers */
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

// NON_MATCHING: The global-store delay slot still has different address-load placement.
#ifdef NON_MATCHING
void func_88507370(void) {
    s32 var_a3;
    s32 sp1C;
    s32 temp_a1;
    s32 var_a1;
    s8 temp_t0;
    s8 temp_v0;
    s8 var_v0;
    u16 temp_a0;

    var_a3 = 0;
    if (M2C_FIELD(M2C_FIELD(D_88523010, void **, 8), s32 *, 0x20) == 2) {
        temp_a0 = D_80087200->buttonsPressed;
        if (temp_a0 & 0x8000) {
            var_a3 = 1;
        } else {
            temp_a1 = M2C_FIELD(D_88523010, s32 *, 0x18);
            if ((temp_a1 == 0) && (temp_a0 & 0x4000)) {
                var_a3 = 1;
                M2C_FIELD(D_88523010, s8 *, 0x1C) = 1;
            } else {
                var_v0 = M2C_FIELD(D_88523010, s8 *, 0x1C);
                temp_t0 = var_v0;
                if (temp_a1 != 0) {
                    var_a1 = 3;
                } else {
                    var_a1 = 2;
                }
                if (temp_a0 & 0x800) {
                    if (var_v0 > 0) {
                        M2C_FIELD(D_88523010, s8 *, 0x1C) = (s8) (var_v0 - 1);
                        var_v0 = M2C_FIELD(D_88523010, s8 *, 0x1C);
                    }
                } else if ((temp_a0 & 0x400) && (var_v0 < (var_a1 - 1))) {
                    M2C_FIELD(D_88523010, s8 *, 0x1C) = (s8) (var_v0 + 1);
                    var_v0 = M2C_FIELD(D_88523010, s8 *, 0x1C);
                }
                if (temp_t0 != var_v0) {
                    sp1C = 0;
                    func_800226C0(1);
                    var_a3 = 0;
                }
            }
        }
        if (var_a3 != 0) {
            if (M2C_FIELD(D_88523010, s32 *, 0x18) != 0) {
                temp_v0 = M2C_FIELD(D_88523010, s8 *, 0x1C);
                if (temp_v0 == 2) {
                    func_800226C0(0x14);
                    M2C_FIELD(&D_88523018, s32 *, 8) = 0;
                    M2C_FIELD(&D_88523018, s32 *, 0) = 0;
                    func_88506A20();
                    return;
                }
                if (temp_v0 == 0) {
                    func_800226C0(0x14A);
                    M2C_FIELD(&D_88523018, s32 *, 8) = 0;
                } else {
                    func_800226C0(0x14B);
                    M2C_FIELD(&D_88523018, s32 *, 8) = 1;
                }
                M2C_FIELD(&D_88523018, s32 *, 0) = 3;
                M2C_FIELD(D_88523010, s16 *, 0x1E) = 2;
                M2C_FIELD(D_88523010, s32 *, 0x20) = 1;
                M2C_FIELD(D_88523010, s16 *, 0x24) = 0;
                M2C_FIELD(D_88523010, s16 *, 0x26) = 0;
                M2C_FIELD(D_88523010, s16 *, 0x28) = 0;
                M2C_FIELD(D_88523010, s16 *, 0x2A) = 0;
                M2C_FIELD(D_88523010, s16 *, 0x2C) = -1;
                return;
            }
            M2C_FIELD(&D_88523018, s32 *, 0) = 0;
            if (M2C_FIELD(D_88523010, s8 *, 0x1C) == 0) {
                func_800226C0(0x14C);
                M2C_FIELD(&D_88523018, s32 *, 4) = 1;
            } else {
                func_800226C0(3);
                M2C_FIELD(&D_88523018, s32 *, 4) = 0;
            }
            func_88506A20();
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/34/fragment34_1C3FA0/func_88507370.s")
#endif
/* mkdraft:func_88507370 end */

extern s32 func_8004C874(s32, s32);
extern s32 func_88002958(s32 *, s32, s32, s32);
extern u16 *func_8004C990(s32, s32);
extern void func_880048D4(s32, s32, s16, s32, s32, s32, s32, s32, s32,
                           s32 *, s32 *, s32 *, s32 *, s32, s32, s32);
extern s32 D_88000E4C;
extern s32 D_8800EDE8;
extern s32 D_88523018;
void func_885075A8(void) {
    s8 pad;
    s32 sp68[3];
    s32 var_s1;
    s32 var_s0;

    var_s0 = 0;
    *(s16 *)((u8 *)D_88523010 + 0x1E) = *(s16 *)((u8 *)D_88523010 + 0x1E) - 1;
    var_s1 = (s32)sp68;
    if (D_80087200->buttonsPressed & 0x8000) {
        *(s16 *)((u8 *)D_88523010 + 0x1E) = 0;
    }
    if (*(s16 *)((u8 *)D_88523010 + 0x1E) <= 0) {
        for (; var_s0 != 3; var_s0 += 1, var_s1 += 4) {
            *(s32 *)var_s1 = func_8004C874(0x34, var_s0 + 0x14);
        }
        var_s1 = func_88002958(sp68, 3, 8, 1) & 0xFFFF;
        var_s0 = ((s32)*(u16 *)((u8 *)func_8004C990(0x79, 0)) + var_s1 + 0x35) & 0xFFFF;
        func_880048D4(0, 3, 0x13F - (var_s0 >> 1), 0x11F, 0, 1, 0xE6, 0xFF, 0xF0,
                      &D_88000E4C, &D_88000E4C, &D_88000E4C, &D_88000E4C, 0, 0, 2);
        *(s32 *)((u8 *)D_88523010 + 8) = (s32)&D_8800EDE8;
        *(s16 *)((u8 *)(*(s32 *)((u8 *)D_88523010 + 8)) + 0x10) = (s16)var_s0;
        *(s16 *)((u8 *)(*(s32 *)((u8 *)D_88523010 + 8)) + 0x12) = 0x65;
        D_88523018 = 1;
    }
}

extern void func_88506AA8();
extern void func_8850716C();
extern void func_88507370();
extern void func_885075A8();
extern s32 D_88523018;
void func_88507724(void) {
    switch (D_88523018) {                           /* irregular */
    case 0:
        break;
    case 1:
        func_88507370();
        break;
    case 2:
        func_885075A8();
        break;
    case 3:
        func_8850716C();
        break;
    }
    func_88506AA8();
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/34/fragment34_1C3FA0/func_8850779C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/34/fragment34_1C3FA0/func_88507FA8.s")
#endif
