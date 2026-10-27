#include "global.h"


#ifdef VERSION_US
extern void Util_Free(s32);
extern void func_888002DC(void);
extern void main_pool_pop_state(s32);
extern void func_8821CE40(s32);
extern s32 D_88234560;
extern s32 D_88234564;
void func_88207ED0(void) {
    Util_Free(D_88234564);
    func_888002DC();
    main_pool_pop_state(0x4152524D);
    func_8821CE40(1);
    D_88234560 = 5;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_17B150/func_88207F18.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_17B150/func_88208010.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_17B150/func_88208174.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_17B150/func_882089E4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_17B150/func_88208B38.s")

// 8-byte record allocated by func_88208FF0 and published through D_8800EF54.
typedef struct {
    s32 unk_00; // func_88207F18(1, index) result
    s8 delta;   // records[index].unk_10 - records[index].unk_12
    u8 index;
} unk_func_88208FF0;

typedef struct {
    u8 unk_00[0x10];
    s16 unk_10;
    s16 unk_12;
    u8 unk_14[0x18];
} unk_D_88234700_Record;

typedef struct {
    u8 index; // selects the entry of records read by func_88208FF0
    u8 unk_01[7];
    unk_D_88234700_Record records[2];
} unk_D_88234700;

extern void *Util_Malloc(s32);
extern void func_800226C0(s32);
extern s32 func_88207F18(s32, s32);
extern void func_882322B8(void);
extern void *D_8800EF54;
extern unk_D_88234700 *D_88234700;
void func_88208FF0(void) {
    unk_func_88208FF0 *record;

    record = Util_Malloc(sizeof(unk_func_88208FF0));
    record->unk_00 = func_88207F18(1, D_88234700->index);
    record->delta = D_88234700->records[D_88234700->index].unk_10 - D_88234700->records[D_88234700->index].unk_12;
    record->index = D_88234700->index;
    D_8800EF54 = record;
    func_800226C0(99);
    func_882322B8();
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_17B150/func_8820908C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_17B150/func_88209278.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_17B150/func_8820A56C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_17B150/func_8820A638.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_17B150/func_8820AAD0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_17B150/func_8820ACD0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_17B150/func_8820AF54.s")

extern void func_80049064(s32, s32, s32, s32);
extern void func_800496A4(s32, s32);
s32 func_8004C874(s32, s32);
extern unk_D_88234700 *D_88234700;

void func_8820B020(void) {
    func_800496A4(4, 2);
    func_80049064(0x140, 0x198, 1, func_8004C874(0x20, 7));
    func_800496A4(0x10, 2);
    func_80049064(0x140, 0x15F, 1, func_8004C874(0x20, (*(s16 *)((u8 *)(D_88234700) + (8))) + 1));
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_17B150/func_8820B09C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_17B150/func_8820B124.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_17B150/func_8820B6C8.s")
#endif
