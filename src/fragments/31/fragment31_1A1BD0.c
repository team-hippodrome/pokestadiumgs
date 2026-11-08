#include "global.h"
#include "controller.h"


#ifdef VERSION_US
extern u8 **D_88234970;
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

s32 MainPool_AllocAligned(s32, s32, M2C_UNK);       /* extern */
s32 MainPool_AllocState(s32, M2C_UNK);              /* extern */
M2C_UNK MainPool_FinalizeAllocation(s32);           /* extern */
u8 **Util_Malloc(M2C_UNK);                          /* extern */
M2C_UNK func_8004C8C0(M2C_UNK);                     /* extern */
s32 func_8004C990(M2C_UNK, M2C_UNK);                /* extern */
s8 func_800532C4(M2C_UNK);                          /* extern */
s32 func_8005CAA4(M2C_UNK);                         /* extern */
s32 main_pool_get_available();                      /* extern */
M2C_UNK main_pool_push_state(M2C_UNK);              /* extern */

void func_8822E950(void) {
    s32 sp24;
    s32 sp20;
    s32 temp_v0;

    main_pool_push_state(0x50495550);
    D_88234970 = Util_Malloc(0x30);
    sp20 = func_8005CAA4(0x21);
    if (func_800532C4(0x11) < sp20) {
        M2C_FIELD(D_88234970, s8 *, 0x1C) = func_8005CAA4(0x21);
    } else {
        M2C_FIELD(D_88234970, s8 *, 0x1C) = func_800532C4(0x11);
    }
    temp_v0 = MainPool_AllocState(main_pool_get_available(), 0);
    sp24 = temp_v0;
    M2C_FIELD(D_88234970, s32 *, 0xC) = MainPool_AllocAligned(temp_v0, (u8) M2C_FIELD(D_88234970, s8 *, 0x1C) * 0xC80, 8);
    MainPool_FinalizeAllocation(sp24);
    func_8004C8C0(0x9A);
    M2C_FIELD(D_88234970, s32 *, 0x10) = func_8004C990(0x9A, 0);
    func_8004C8C0(0xF1);
    M2C_FIELD(D_88234970, s32 *, 0x14) = func_8004C990(0xF1, 0);
    func_8004C8C0(0xF3);
    M2C_FIELD(D_88234970, s32 *, 0x18) = func_8004C990(0xF3, 0);
}
extern void Util_Free(void *);
extern void main_pool_pop_state(s32);
extern u8 **D_88234970;
void func_8822EA80(void) {
    Util_Free(*(volatile void **)(&D_88234970));
    main_pool_pop_state(0x50495550);
}


void func_8822EAB0(void) {
    *(u32 *)(*D_88234970 + 0x30) = 0;
}


void func_8822EAC4(void) {
    *(u32 *)(*D_88234970 + 0x30) = 1;
}

extern void func_8000612C();

void func_8822EADC(void) {
    func_8000612C();
    (*(s32 *)((u8 *)(*D_88234970) + (0x2C))) = 1;
}

s32 func_88802DCC(s32, s32, void (*)(), void (*)(), void (*)(), s32 *, s32, s32);
extern u8 func_882313A4;

void func_8822EB10(s32 arg0) {
    func_88802DCC(0, arg0, func_8822EAB0, func_8822EADC, func_8822EAC4, &func_882313A4, 0, 1);
    (*(s32 *)((u8 *)(*D_88234970) + (0x2C))) = 0;
}

extern s32 D_880068B8;
extern s32 D_882345F4;
extern void func_800226C0(s32);
extern void func_88004990(u8, s32);

typedef struct GridData {
    /* 0x00 */ u8 unk00[0x10];
    /* 0x10 */ s32 *unk10;
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
} GridData;

typedef struct Grid {
    /* 0x00 */ u32 unk0;
    /* 0x04 */ s16 x;
    /* 0x06 */ s16 y;
    /* 0x08 */ GridData *unk8;
} Grid;



void func_8822EB78(void) {
    u8 index;
    s16 start[2];

    if (D_80087200->buttonsPressed & 0x4000) {
        func_800226C0(0x48);
        D_880068B8 = 1;
        func_88004990(**(u8 **)D_88234970, 0);
        return;
    }
    if (D_80087200->buttonsPressed & 0x8000) {
        index = ((Grid *)D_88234970)->x + ((Grid *)D_88234970)->y * 6;
        if (index >= ((Grid *)D_88234970)->unk8->unk15) {
            func_800226C0(0x49);
            return;
        }
        func_800226C0(0x47);
        D_882345F4 = ((Grid *)D_88234970)->unk8->unk10[index];
        func_8822EB10(D_882345F4 + 8);
        return;
    }
    start[0] = ((Grid *)D_88234970)->x;
    start[1] = ((Grid *)D_88234970)->y;
    if (D_80087200->buttonsRepeat & 0x800) {
        ((Grid *)D_88234970)->y--;
        if (((Grid *)D_88234970)->y < 0) {
            ((Grid *)D_88234970)->y = 4;
        }
    } else if (D_80087200->buttonsRepeat & 0x400) {
        ((Grid *)D_88234970)->y++;
        if (((Grid *)D_88234970)->y >= 5) {
            ((Grid *)D_88234970)->y = 0;
        }
    }
    if (D_80087200->buttonsRepeat & 0x200) {
        ((Grid *)D_88234970)->x--;
        if (((Grid *)D_88234970)->x < 0) {
            ((Grid *)D_88234970)->x = 5;
        }
    } else if (D_80087200->buttonsRepeat & 0x100) {
        ((Grid *)D_88234970)->x++;
        if (((Grid *)D_88234970)->x >= 6) {
            ((Grid *)D_88234970)->x = 0;
        }
    }
    // FAKE: these are the same x/y reads as the Grid fields above; written as byte
    // offsets because only this form makes IDO load start[] before the grid fields
    // in each compare (t3=start[0], t4=grid->x, t5=start[1], t6=grid->y). The typed
    // `((Grid *)D_88234970)->x/y` form scores 60.
    if (start[0] != (*(s16 *)((u8 *)D_88234970 + 4)) || start[1] != (*(s16 *)((u8 *)D_88234970 + 6))) {
        func_800226C0(0x46);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_1A1BD0/func_8822EDA8.s")

extern s32 D_880068B8;

void func_8822FA0C(void) {
    func_8000612C();
    D_880068B8 = 0;
}

extern void func_88001900();
extern s32 D_880068B4;

void func_8822FA30(void) {
    func_88001900();
    D_880068B4 = 1;
}

/* mkdraft:func_8822FA58 begin */
extern u8 D_8800ED50[];
extern u8 **D_88234970;
extern s32 D_880068B4;
void func_8822EB78(void);
extern s32 func_8822EDA8;
extern s32 func_80001FF0(void);
extern u8 *func_8004D878(u8 *destination, s32 id, u8 *mon);
extern s32 func_88004804(void *, s32, s16, s16, s32, s32, s32, s32, s32, s32 *, s32 *, s32 *, s32 *, s32, s32);
extern void func_88000288(void *arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7);

#define RAND_OFFSET(k) ((f32)(k) * func_80001FF0() / 60.0f + ((func_80001FF0() * (f32)(k) / 60.0f > 0.0f) ? 0.5f : -0.5f))



void func_8822FA58(void *arg0) {
    u32 i;
    u8 **src;
    u8 *node;

    src = *(u8 ***)((u8 *)arg0 + 0x10);
    node = D_8800ED50 + func_88004804(0, 3, 0x33, 0x49, 0, 2, 0xDC, 0xDC, 0xB4, &func_8822EB78, &func_8822EDA8, (s32 *)func_8822FA0C, (s32 *)func_8822FA30, 0, 0) * 0x4C;
    *(void **)((u8 *)D_88234970 + 0) = node;
    *(s16 *)((u8 *)*(void **)((u8 *)D_88234970 + 0) + 0x10) = 0x21C;
    *(s16 *)((u8 *)*(void **)((u8 *)D_88234970 + 0) + 0x12) = 0x17E;
    *(void **)((u8 *)D_88234970 + 8) = arg0;
    *(s16 *)((u8 *)D_88234970 + 6) = 0;
    *(s16 *)((u8 *)D_88234970 + 4) = *(s16 *)((u8 *)D_88234970 + 6);
    node = *(u8 **)((u8 *)D_88234970 + 0xC);
    for (i = 0; i < *(u8 *)((u8 *)arg0 + 0x15); i++) {
        u8 *obj = *src;
        func_8004D878(node, obj[8], obj + 8);
        node += 0xC80;
        src++;
    }
    func_88000288((u8 *)D_88234970 + 0x1E, (s16)((s32)RAND_OFFSET(5) + (s32)RAND_OFFSET(8) + (s32)RAND_OFFSET(30)), 0xFF, 0, (s32)RAND_OFFSET(5), (s32)RAND_OFFSET(8), (s32)RAND_OFFSET(30), (s32)RAND_OFFSET(8));
    D_880068B4 = 0;
}
/* mkdraft:func_8822FA58 end */

extern void Input_SetRepeatController(s32);

void func_8822FF80(void) {
    Input_SetRepeatController(D_80087200);
    D_880068B8 = 0;
}

extern void func_88211168(s32, s32);
extern u32 D_88234980;
void func_8822FFA8(void) {
    if ((*(s32 *)((u8 *)(D_88234980) + (0x5C))) != 0) {
        func_88001900();
    } else {
        func_88211168(1 - (*(s16 *)((u8 *)(D_88234980) + (0x48))), 0);
    }
    D_880068B4 = 1;
    Util_Free((void *) D_88234980);
}

extern void func_88004990(u8 arg0, s32 arg1);
void func_88230010(void) {
    func_88004990(**(u8 **)D_88234980, 0);
    D_880068B8 = 1;
}

extern s32 D_88234724;
void func_88230048(void) {
    u8 *temp_v0;

    temp_v0 = (u8 *)D_88234980 + 0x20;
    if (D_80087200->buttonsPressed & 0x4000) {
        func_800226C0(72);
        func_88230010();
        *(s32 *)((u8 *)D_88234980 + 0x5C) = 1;
        D_88234724 = 0;
        return;
    }
    if (D_80087200->buttonsPressed & 0x8000) {
        func_800226C0(93);
        func_88230010();
        *(s32 *)((u8 *)D_88234980 + 0x5C) = 0;
        return;
    }
    func_88002720(temp_v0 + 0x28, *(u16 *)(temp_v0 + 0xC), temp_v0 + 0x2C);
}

extern void func_8821D930(s32);
void func_882300E4(void) {
    func_8821D930(D_88234980 + 4);
}

/* mkdraft:func_8823010C begin */
extern u8 D_88006020[];
extern u8 D_8800ED50[];
extern u32 D_88234980;
extern void *func_8004C874(s32, s32);
extern u8 *func_88002AA8(u8 *, s32, u8 **, u16, s32, s16, s16, s16, s16, s16, s16, s32, s16, void *);
extern s32 func_88004804(void *, s32, s16, s16, s32, s32, s32, s32, s32, s32 *, s32 *, s32 *, s32 *, s32, s32);



void func_8823010C(s32 arg0) {
    s32 var_s0;
    u32 var_s1;
    void *temp_v0;

    D_88234980 = Util_Malloc(0x60);
    for (var_s0 = 0; var_s0 != 2; var_s0++) {
        temp_v0 = func_8004C874(0x22, var_s0 + 0x13);
        M2C_FIELD(D_88234980 + var_s0 * 4, void **, 0x54) = temp_v0;
    }
    func_88002AA8(D_88234980 + 0x20, 0, D_88234980 + 0x54, 2U, 8, 1, 6, 0, 0, 0, 0, 0, 0, D_88006020);
    M2C_FIELD(D_88234980, s32 *, 0xC) = arg0;
    M2C_FIELD(D_88234980, s32 *, 8) = 0;
    M2C_FIELD(D_88234980, s32 *, 0x10) = 4;
    M2C_FIELD(D_88234980, s16 *, 0x14) = 1;
    M2C_FIELD(D_88234980, s16 *, 0x16) = 4;
    M2C_FIELD(D_88234980, void **, 0) = (void *) ((func_88004804(D_88234980 + 4, 2, 0x140, 0xF0, 4, 1, 0xDC, 0xDC, 0xB4, (s32 *) func_88230048, (s32 *) func_882300E4, (s32 *) func_8822FF80, (s32 *) func_8822FFA8, 0, 0) * 0x4C) + D_8800ED50);
    D_880068B4 = 0;
    D_88234724 = 1;
}
/* mkdraft:func_8823010C end */
#endif
