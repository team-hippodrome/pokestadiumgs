#include "global.h"
#include "controller.h"

#ifdef VERSION_US
extern s32 D_83503BB4;
extern void func_83503048(void);
extern void func_83503188(void);
extern void func_83503324(void);
extern void func_835034A8(void);
extern void func_83503548(void);
void func_835035F0(void) {
    switch (D_83503BB4) {
        case 0:
            func_83503048();
            break;
        case 1:
            func_83503188();
            break;
        case 2:
            func_83503324();
            break;
        case 3:
            func_835034A8();
            break;
        case 4:
            func_83503548();
            break;
    }
}

extern s32 D_83503BA8;
extern void func_800226C0(s32, s32);
s32 func_83503678(s32 arg0) {
    s32 result = arg0;
    if (*(s32 *)((u8 *)&D_83503BA8 + 4) == 2) {
        result = arg0 + 1;
    }
    if (((D_80087200->buttonsPressed & 0x8000) != 0) &&
        (*(s32 *)((u8 *)&D_83503BA8 + 0x14) == 1) &&
        (*(s32 *)((u8 *)&D_83503BA8 + 0x30) == 0xFF)) {
        *(s32 *)((u8 *)&D_83503BA8 + 0x2C) = -1;
        arg0 = result;
        func_800226C0(2, result);
        result = arg0;
        if (*(s32 *)((u8 *)&D_83503BA8 + 4) >= 2) {
            *(s32 *)((u8 *)&D_83503BA8 + 4) = 2;
            return 0x1770;
        }
    }
    return result;
}

/* Keep jtbl_83503E64's first three words in the late-rodata block so the
 * compiler-generated jtbl_83503E50 precedes them at the retail boundary. */
#pragma GLOBAL_ASM("hand_asm/fragments/1/func_83503720_manual.s")

extern void func_83502EF0();
s32 func_83503720(s32);
extern void func_800086A4(s32);
extern void StageFade_StartFromOpaque(s32);
void func_80064D28(void);
void func_835038BC(void) {
    s32 temp_v0;
    s32 var_s0;

    var_s0 = 0;
    func_800086A4(2);
    StageFade_StartFromOpaque(0x1E);
    do {
        func_80064D28();
        func_83502EF0();
        temp_v0 = func_83503720(var_s0);
        var_s0 = temp_v0;
    } while (temp_v0 != 5);
}

/* mkdraft:func_83503918 begin */
extern u8 D_1000000[];
extern u8 D_446E30[];
extern u8 D_447D00[];
extern u8 D_83503F58[];
extern s16 D_83503E84;
extern s32 D_83503F50;
extern s32 D_835040D8;

typedef struct {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
} unk_D_83503E80;

extern unk_D_83503E80 D_83503E80;

extern void main_pool_push_state(s32);
extern void main_pool_pop_state(s32);
extern void Gfx_InitDisplayListBuffers(s32, s32);
extern void Gfx_FreeDisplayListBuffers(void);
extern s32 func_800082E0(s32, s32, s32, s32, s32, s32);
extern void func_8004C09C(s32);
extern s32 func_8004D690(s32);
extern void func_8004C4B0(s32);
extern void func_8004C8C0(s32);
extern s32 func_8004C990(s32, s32);
extern s32 func_87F08E3C(s32, s32);
extern void func_80047588(s32, s32);
extern void Asset_LoadToSegment(u32, u8 *, u8 *, s32);
extern void func_8350026C(void);
extern void func_87F0DBE0(u8 *, s32);
extern void func_80008514(s32);
extern void func_835038BC(void);
extern void func_800086A4(s32);
extern void func_80008574(void);
extern void func_80047610(void);
extern void func_8004C398(void);



s32 func_83503918(s32 arg0, void *arg1) {
    s32 sp24;

    D_83503E80 = *(unk_D_83503E80 *)arg1;
    main_pool_push_state(0x474C4344);
    Gfx_InitDisplayListBuffers(0x20000, 0);
    sp24 = func_800082E0(1, 1, 2, 0, 2, 1);
    func_8004C09C(7);
    if (D_83503E84 == 0) {
        D_83503F50 = func_8004D690(0x1A);
    } else {
        D_83503F50 = func_8004D690(0xD);
    }
    func_8004C4B0(0x49);
    func_8004C8C0(0x136);
    func_8004C8C0(0x102);
    func_8004C8C0(0x101);
    func_8004C8C0(0x44);
    func_8004C8C0(0x35);
    D_835040D8 = func_87F08E3C(func_8004C990(0x136, 0), 0x0F000000);
    func_80047588(0x10, 0);
    Asset_LoadToSegment(((u32)D_1000000 & 0x0F000000) >> 24, D_446E30, D_447D00, 0);
    func_8350026C();
    func_87F0DBE0(D_83503F58, sp24);
    func_80008514(sp24);
    func_835038BC();
    func_800086A4(2);
    func_80008574();
    func_80047610();
    func_8004C398();
    Gfx_FreeDisplayListBuffers();
    main_pool_pop_state(0x474C4344);
    return 0;
}
/* mkdraft:func_83503918 end */
#endif
