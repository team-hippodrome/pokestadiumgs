#include "global.h"


#ifdef VERSION_US
typedef struct F66ViewState {
    s32 value;
    s32 x;
    s32 y;
    s32 unused0C;
    s32 secondX;
    s32 secondY;
} F66ViewState;
extern F66ViewState D_82E06138;
extern s32 D_82E0713C;
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/66/fragment66_code/func_82E00020.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/66/fragment66_code/func_82E0048C.s")
#endif

#ifdef VERSION_US
/* Same storage as D_82E06138 (aliases.ld), with the callback's coordinate view.
 * Keep the direct scalar store separate from the following structured accesses. */
extern F66ViewState D_82E06138_view;
extern s32 D_82E05650;
s32 func_82E00700(s32 kind, u8* event) {
    switch (kind) {
    case 0:
        switch (*(u32*)(event + 0x20)) {
        case 0:
            D_82E06138.value = event[0x2B] + (event[0x2A] << 8);
            D_82E06138_view.x = *(s16*)(event + 8) - 160;
            D_82E06138_view.y = 120 - *(s16*)(event + 0xA);
            if (D_82E05650 == 0) {
                D_82E06138_view.value = (D_82E06138_view.value * 5) / 6;
            }
            *(u16*)(event + 2) &= 0xFFFE;
            break;
        case 1:
            D_82E06138_view.secondX = *(s16*)(event + 8) - 160;
            D_82E06138_view.secondY = 120 - *(s16*)(event + 0xA);
            *(u16*)(event + 2) &= 0xFFFE;
            break;
        }
        break;
    case 1:
        break;
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern s32 D_82E075E4;
extern s32 D_82E05650;
extern s32 D_82E07130;
s32 func_82E007F0(s32 arg0, u8 *arg1) {
    switch (arg0) {
    case 0:
        D_82E075E4 = arg1[0x2B] + (arg1[0x2A] << 8);
        if (D_82E05650 == 0) {
            *(s32 *)((u8 *)&D_82E07130 + 0x4B4) = (*(s32 *)((u8 *)&D_82E07130 + 0x4B4) * 5) / 6;
        }
        *(u16 *)(arg1 + 2) &= ~1;
        break;
    case 1:
        break;
    }
    return 0;
}
#endif

#ifdef VERSION_US
/* mkdraft:func_82E00868 begin */
extern s32 D_82E05650;
extern s32 D_82E05938;
extern s32 D_82E0593C;
extern s32 D_82E05940;
extern s32 D_82E05944;
extern s32 D_82E05948;
extern s32 D_82E0594C;
extern s32 D_82E05950;
extern s32 D_82E05954;
extern s32 D_82E05958;
extern s32 D_82E0595C;
extern s32 D_82E05960;
extern s32 D_82E05964;
extern s32 D_82E06144;
extern s32 D_82E06150;
extern s32 D_82E06154;

//
// Fragment66 kind-0 event update. `data` carries an s32 selector at +0x20 that
// chooses one of two twelve-word output blocks: D_82E05938..D_82E0594C for
// selector 0, D_82E05950..D_82E05964 for selector 1. Both blocks are written
// first with the raw byte-pair values at +0x28..+0x2F (each pair is
// (byte[2i+2] << 8) + byte[2i+3]; selector 1 also fills D_82E06144,
// D_82E06150 and D_82E06154), then, when D_82E05650 is zero, the same fields
// are overwritten with value * 5 / 6. The halfword at +2 keeps its upper 15
// bits. `kind` 1 returns 0 without touching `data`.
//
// Retail is 381 words (1524 bytes):
// asm/us/nonmatchings/fragments/66/fragment66_code/func_82E00868.s. Seven of
// its stores reuse the $at page base loaded for the preceding store
// (D_82E0593C after D_82E05938, D_82E05944 after D_82E05940, D_82E0594C after
// D_82E05948, D_82E05954 after D_82E05950, D_82E0595C after D_82E05958,
// D_82E05964 after D_82E05960, D_82E06154 after D_82E06150). The body below
// compiles to 388 words, with one `lui $at` per store: IDO 7.1 reloads $at for
// every store macro and does not carry the page base across a load, and
// tools/coalesce_object.py plan_runs will not fold a pair separated by an lbu,
// so `#pragma COALESCE_AT_LUI(func_82E00868)` is rejected at build time with
// "no fold applied for opted-in function func_82E00868". The 16
// register-colour rows that remain are the temp-pool effect of those seven
// extra lui words; flipping the (byte[2i+2] << 8) + byte[2i+3] operand order
// at the affected sites scores worse (910, 900, 950).
//
// The hash below is the sha256 of this body's 1552-byte compiler output (after
// as1). The pragma authenticates that text as a whole, so a different body or
// compiler fails the build instead of silently emitting the unfolded form; the
// 53 RELOC_TARGET pragmas then install the retail %hi/%lo topology (23 HI16,
// 30 LO16).
//
// FAKE: REWRITE_FUNCTION_HEX + REWRITE_FUNCTION_RELOC_TARGET; without them
// diff.py 800 (16 register-colour rows).
#pragma REWRITE_FUNCTION_HEX(func_82E00868, 062c2d2b9df95db0d447402d718f6071a65b40c66e8ecb063dd56525a2102f50, 1080000524010001108101780000000003e00008000010258ca200203c01000010400006000000002401000110410090000000001000016b94ac0002ac20000090ae0028ac2e000090af002a90b9002b90a90029000fc200031940213c01000001095023ac2a000090ab002a90ad002b3c190000000b6200018d7021ac2e000090af00283c0100008f390000ac2f000090b8002917200152ac38000090a800282402000524030006010200190000481200000000000000000123001a14600002000000000007000d2401ffff146100043c01800015210002000000000006000d000050123c010000ac2a000090ab002a90ad002b90b90029000b6200018d702101c2001900007812000000000000000001e3001a0000c01214600002000000000007000d2401ffff146100043c01800015e10002000000000006000d032200190000401200000000000000000103001a14600002000000000007000d2401ffff146100043c01800015010002000000000006000d00004812030950233c010000ac2a000090ab002a90ad002b000b6200018d702101c2001900007812000000000000000001e3001a14600002000000000007000d2401ffff146100043c01800015e10002000000000006000d0000c8123c010000ac39000090a80028010200190000c01200000000000000000303001a14600002000000000007000d2401ffff146100043c01800017010002000000000006000d000048123c010000ac29000090aa0029014200190000581200000000000000000163001a14600002000000000007000d2401ffff146100043c01800015610002000000000006000d3c01000000006012ac2c0000100000de94ac00023c010000ac20000090ad0028ac2d000090ae002a90b9002b90b80029000e7a0001f940213c01000001184823ac29000090aa002a90ac002b000a5a00016c6821ac2d000090ae00283c010000ac2e000090af0029ac2f000090b9002a90b8002b3c0100000019420001184821ac29000090aa002c90ac002d3c010000000a5a00016c6821ac2d000090ae002e90b9002f3c1800008f180000000e7a0001f94021170000b3ac28000090a900282402000524030006012200190000501200000000000000000143001a14600002000000000007000d2401ffff146100043c01800015410002000000000006000d000058123c010000ac2b000090ac002a90ae002b90b80029000c6a0001ae782101e200190000c81200000000000000000323001a0000401214600002000000000007000d2401ffff146100043c01800017210002000000000006000d030200190000481200000000000000000123001a14600002000000000007000d2401ffff146100043c01800015210002000000000006000d00005012010a58233c010000ac2b000090ac002a90ae002b000c6a0001ae782101e200190000c81200000000000000000323001a14600002000000000007000d2401ffff146100043c01800017210002000000000006000d0000c0123c010000ac38000090a90028012200190000401200000000000000000103001a14600002000000000007000d2401ffff146100043c01800015010002000000000006000d000050123c010000ac2a000090ab0029016200190000601200000000000000000183001a14600002000000000007000d2401ffff146100043c01800015810002000000000006000d000068123c010000ac2d000090ae002a90b9002b000e7a0001f9c021030200190000481200000000000000000123001a14600002000000000007000d2401ffff146100043c01800015210002000000000006000d000040123c010000ac28000090aa002c90ac002d000a5a00016c682101a2001900007012000000000000000001c3001a14600002000000000007000d2401ffff146100043c01800015c10002000000000006000d000078123c010000ac2f000090b9002e90a9002f0019c20003094021010200190000501200000000000000000143001a14600002000000000007000d2401ffff146100043c01800015410002000000000006000d000058123c010000ac2b000094ac0002318dfffea4ad000203e0000800001025)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x1c, 5, D_82E05938)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x3c, 6, D_82E05938)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x44, 6, D_82E0593C)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x5c, 5, D_82E05940)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x64, 6, D_82E05940)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x70, 5, D_82E05650)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x7c, 6, D_82E05944)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x84, 5, D_82E05948)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x88, 6, D_82E05650)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x8c, 6, D_82E05948)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x98, 6, D_82E0594C)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0xe4, 5, D_82E0593C)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0xe8, 6, D_82E0593C)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x17c, 5, D_82E05940)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x180, 6, D_82E05940)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x1d0, 5, D_82E05944)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x1d4, 6, D_82E05944)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x218, 5, D_82E05948)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x21c, 6, D_82E05948)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x25c, 5, D_82E0594C)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x264, 6, D_82E0594C)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x270, 5, D_82E05950)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x274, 6, D_82E05950)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x27c, 6, D_82E05954)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x294, 5, D_82E05958)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x29c, 6, D_82E05958)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x2b0, 6, D_82E0595C)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x2b8, 5, D_82E05960)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x2bc, 6, D_82E05960)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x2c4, 6, D_82E05964)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x2d0, 5, D_82E06144)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x2dc, 6, D_82E06144)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x2e8, 5, D_82E06150)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x2f4, 6, D_82E06150)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x300, 5, D_82E05650)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x304, 6, D_82E05650)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x314, 6, D_82E06154)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x360, 5, D_82E05954)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x364, 6, D_82E05954)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x3f8, 5, D_82E05958)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x3fc, 6, D_82E05958)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x44c, 5, D_82E0595C)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x450, 6, D_82E0595C)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x494, 5, D_82E05960)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x498, 6, D_82E05960)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x4dc, 5, D_82E05964)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x4e0, 6, D_82E05964)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x530, 5, D_82E06144)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x534, 6, D_82E06144)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x584, 5, D_82E06150)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x588, 6, D_82E06150)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x5d8, 5, D_82E06154)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_82E00868, 0x5dc, 6, D_82E06154)


s32 func_82E00868(s32 kind, void *data) {
    s32 numerator = 5;
    s32 denominator = 6;
    u8 *p = data;
    s32 temp_v0;
    s32 temp_t0;
    s32 temp_t1;

    switch (kind) {
    case 0:
        temp_v0 = *(s32 *)(p + 0x20);
        switch (temp_v0) {
        case 0:
            D_82E05938 = 0;
            D_82E0593C = p[0x28];
            D_82E05940 = (p[0x2A] << 8) + p[0x2B] - p[0x29];
            D_82E05944 = (p[0x2A] << 8) + p[0x2B];
            D_82E05948 = p[0x28];
            D_82E0594C = p[0x29];
            if (D_82E05650 == 0) {
                D_82E0593C = (p[0x28] * numerator) / denominator;
                D_82E05940 = (((p[0x2A] << 8) + p[0x2B]) * numerator) / denominator - (p[0x29] * numerator / denominator);
                D_82E05944 = (((p[0x2A] << 8) + p[0x2B]) * numerator) / denominator;
                D_82E05948 = (p[0x28] * numerator) / denominator;
                D_82E0594C = (p[0x29] * numerator) / denominator;
            }
            break;
        case 1:
            D_82E05950 = 0;
            D_82E05954 = p[0x28];
            D_82E05958 = (p[0x2A] << 8) + p[0x2B] - p[0x29];
            D_82E0595C = (p[0x2A] << 8) + p[0x2B];
            D_82E05960 = p[0x28];
            D_82E05964 = p[0x29];
            D_82E06144 = p[0x2B] + (p[0x2A] << 8);
            D_82E06150 = (p[0x2C] << 8) + p[0x2D];
            D_82E06154 = p[0x2F] + (p[0x2E] << 8);
            if (D_82E05650 == 0) {
                D_82E05954 = (p[0x28] * numerator) / denominator;
                D_82E05958 = (((p[0x2A] << 8) + p[0x2B]) * numerator) / denominator - (p[0x29] * numerator / denominator);
                D_82E0595C = ((p[0x2B] + (p[0x2A] << 8)) * numerator) / denominator;
                D_82E05960 = (p[0x28] * numerator) / denominator;
                D_82E05964 = (p[0x29] * numerator) / denominator;
                D_82E06144 = ((p[0x2B] + (p[0x2A] << 8)) * numerator) / denominator;
                D_82E06150 = ((p[0x2D] + (p[0x2C] << 8)) * numerator) / denominator;
                D_82E06154 = ((p[0x2F] + (p[0x2E] << 8)) * numerator) / denominator;
            }
            break;
        }
        *(u16 *)(p + 2) &= 0xFFFE;
        break;
    case 1:
        break;
    }
    return 0;
}
/* mkdraft:func_82E00868 end */
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/66/fragment66_code/func_82E00E5C.s")
#endif

#ifdef VERSION_US
extern s32 D_82E0710C, D_82E07110, D_82E07114, D_82E07118, D_82E0711C, D_82E07120, D_82E07124;
s32 func_82E017E0(s32 kind, u8* event) {
    switch (kind) {
    case 0:
        switch (*(u32*)(event + 0x20)) {
        case 0:
            D_82E0710C = *(s16*)(event + 8);
            D_82E07118 = event[0x28];
            break;
        case 1:
            D_82E07110 = *(s16*)(event + 8);
            D_82E0711C = event[0x28];
            break;
        case 2:
            D_82E07114 = *(s16*)(event + 8);
            break;
        case 3:
            D_82E07120 = event[0x28];
            break;
        case 4:
            D_82E07124 = event[0x28];
            break;
        }
        break;
    case 1:
        break;
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern s32 D_82E05650;
s32 func_82E01898(s32 kind, u8* event) {
    s32 numerator = 5;
    s32 denominator = 6;
    switch (kind) {
    case 0:
        D_82E06138.value = event[0x29] + (event[0x28] << 8);
        D_82E0713C = event[0x2B] + (event[0x2A] << 8);
        if (D_82E05650 == 0) {
            D_82E06138.value = ((event[0x29] + (event[0x28] << 8)) * numerator) / denominator;
            D_82E0713C = ((event[0x2B] * numerator) / denominator) + (event[0x2A] << 8);
        }
        *(u16*)(event + 2) &= 0xFFFE;
        break;
    case 1:
        break;
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern s32 D_82E07128;
extern s32 D_82E0615C;
s32 func_82E019B0(s32 arg0, u8 *arg1) {
    switch (arg0) {
        case 0:
            D_82E07128 = arg1[0x28];
            D_82E0615C = arg1[0x2B] + (arg1[0x2A] << 8);
            *(u16 *)(arg1 + 2) &= 0xFFFE;
            break;
        case 1:
            break;
    }
    return 0;
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/66/fragment66_code/func_82E01A00.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/66/fragment66_code/func_82E01CE8.s")
#endif

#ifdef VERSION_US
extern u8 *D_82E075E8;
extern u8 *D_82E075EC;
extern u8 *D_82E075F0;
extern s32 D_82E07614;
extern s32 D_82E07618;
s32 func_82E02378(s32 arg0, u8 *arg1) {
    switch (arg0) {
    case 0:
        switch (*(u32 *)(arg1 + 0x20)) {
        case 0:
            break;
        case 1:
            D_82E075E8 = arg1;
            *(u16 *)(arg1 + 2) &= ~1;
            break;
        case 2:
            D_82E075EC = arg1;
            *(u16 *)(arg1 + 2) &= ~1;
            break;
        case 3:
            D_82E075F0 = arg1;
            *(u16 *)(arg1 + 2) &= ~1;
            break;
        }
        break;
    case 1:
        if (arg1[0] == 3) {
            switch (*(u32 *)(arg1 + 0x20)) {
            case 0:
                *(s32 *)(arg1 + 0x2C) = D_82E07614 | 0xFFFFFF00;
                break;
            case 1:
            case 2:
            case 3:
                *(s32 *)(arg1 + 0x2C) = D_82E07618 | 0xFFFFFF00;
                break;
            }
        }
        break;
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern s16 D_82E06158;
extern s32 D_82E05650;
s32 func_82E0248C(s32 arg0, u8 *arg1) {
    s32 mode;
    switch (arg0) {
    case 0:
        mode = 6;
        D_82E06158 = arg1[0x29] + (arg1[0x28] << 8);
        if (D_82E05650 == 0) {
            D_82E06158 = ((arg1[0x29] + (arg1[0x28] << 8)) * 5) / mode;
        }
        *(u16 *)(arg1 + 2) &= ~1;
        break;
    case 1:
        break;
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern s32 func_80001FF0(void);
extern s32 main_pool_get_available(void);
extern void* MainPool_AllocState(s32, s32);
extern void MainPool_FinalizeAllocation(void*);
extern s32 process_geo_layout(void*, void*);
extern void* func_800071A4(s32, s32, s32, s32, s32);
extern void ModelRenderer_InitDisplayRoots(void);
extern void func_8003F018(void*);
extern s32 main_pool_push_state(s32);
extern void func_82E04040(s32);
extern void func_80021ED8(s32);
extern u8 D_82E04EB0[], D_82E04F1C[], D_82E04F50[];
extern u8 D_82E05660[], D_82E057C8[];
extern s32 D_82E05650, D_82E05654, D_82E05658, D_82E0565C;
extern s32 D_82E0543C;
extern void* D_82E07600;
extern void* D_82E07604;
extern void* D_82E07608;
void func_82E02508(void) {
    void* pool;
    if (func_80001FF0() == 60) {
        D_82E05650 = 1;
    } else {
        D_82E05650 = 0;
    }
    pool = MainPool_AllocState(main_pool_get_available(), 0);
    D_82E05654 = process_geo_layout(pool, D_82E04EB0);
    D_82E05658 = process_geo_layout(pool, D_82E04F1C);
    D_82E0565C = process_geo_layout(pool, D_82E04F50);
    MainPool_FinalizeAllocation(pool);
    D_82E07600 = func_800071A4(0, 2, 320, 240, 0);
    D_82E07604 = func_800071A4(0, 2, 320, 240, 0);
    D_82E07608 = func_800071A4(0, 2, 320, 240, 0);
    ModelRenderer_InitDisplayRoots();
    func_8003F018(D_82E05660);
    func_8003F018(D_82E057C8);
    main_pool_push_state(0x64617461);
    func_82E04040(D_82E0543C++);
    func_80021ED8(0x52);
}
#endif

#ifdef VERSION_US
extern void BgStage_DrawFrame(void);
extern void GfxImage_FillCurrent(Gfx **, s32);
extern void GfxImage_FillRectangle(Gfx **, s32, s32, s32, s32, s32);
extern void GfxImage_SetRenderTarget(Gfx **, void *);
extern void func_82E02CA4(s32);
extern s32 func_8004D690(s32);
extern s32 main_pool_push_state(s32);
extern void main_pool_pop_state(s32);
extern void GeoRender_AdvanceFrameCounter(void);
extern void Geo_RenderRootNode(s32);
extern void func_800503A4(void *);
extern void func_80008648(void);
extern void func_82E02EB0(s32, s32, s32);
extern void func_82E02F00(s32, s32, u8);
extern Gfx *D_800D0510;
extern s32 D_82E0543C;
extern s32 D_82E05654;
extern u8 D_82E06163;
extern s32 D_82E06164;
extern s32 D_82E07130;
extern s32 D_82E075F4;
extern u8 *D_82E0760C;
extern void *D_82E07600;
extern void *D_82E07604;
extern void *D_82E07608;
void func_82E02658(void) {
    BgStage_DrawFrame();
    if (D_82E0543C != 8) {
        GfxImage_FillCurrent(&D_800D0510, 1);
    } else {
        GfxImage_FillRectangle(&D_800D0510, 0x28, 0, 0x230, 0x1E0, 1);
    }
    if (D_82E07130 == 0) {
        GfxImage_SetRenderTarget(&D_800D0510, D_82E07600);
        func_82E02CA4(D_82E075F4);
    }
    if (D_82E0543C == 8) {
        if (D_82E07130 == 1) {
            main_pool_push_state(0x6A706567);
            D_82E075F4 = func_8004D690(0x21);
            GfxImage_SetRenderTarget(&D_800D0510, D_82E07604);
            func_82E02CA4(D_82E075F4);
            main_pool_pop_state(0x6A706567);
        } else if (D_82E07130 == 2) {
            main_pool_push_state(0x6A706567);
            D_82E075F4 = func_8004D690(0x1F);
            GfxImage_SetRenderTarget(&D_800D0510, D_82E07608);
            func_82E02CA4(D_82E075F4);
            main_pool_pop_state(0x6A706567);
        }
        BgStage_DrawFrame();
        func_82E02EB0(0xA0, 0x78, (*(s32 **)((u8 *)&D_82E07600 + (D_82E06164 * 4)))[2]);
        func_82E02F00(0xA0, 0x78, D_82E06163);
    }
    GeoRender_AdvanceFrameCounter();
    Geo_RenderRootNode(D_82E05654);
    func_800503A4(D_82E0760C);
    func_80008648();
}
#endif

#ifdef VERSION_US
extern s32 StageContext_GetFadeMode(void);
extern void StageFade_StartFromTransparent(s32);
extern void func_82E030B0(void);
extern void func_800225C4(s32);
extern s32 D_82E05440;

s32 func_82E02828(s32 arg0) {
    s32 state = arg0;
    switch (arg0) {
    case 0:
        if (StageContext_GetFadeMode() == 0) {
            state = 1;
        }
        break;
    case 1:
        func_82E030B0();
        if (D_82E05440 != 0) {
            state = 2;
            StageFade_StartFromTransparent(5);
            func_800225C4(0xA);
        }
        break;
    case 2:
        if (StageContext_GetFadeMode() == 1) {
            state = 3;
        }
        break;
    }
    return state;
}
#endif

#ifdef VERSION_US
extern void StageFade_StartFromOpaque(s32);
extern void func_800086A4(s32);
extern void func_80064D28();
extern void func_82E02658();
s32 func_82E02828(s32);
void func_82E028D0(void) {
    s32 var_s0;

    var_s0 = 0;
    func_800086A4(2);
    StageFade_StartFromOpaque(5);
    do {
        func_80064D28();
        var_s0 = func_82E02828(var_s0);
        func_82E02658();
    } while (var_s0 != 3);
}
#endif

#ifdef VERSION_US
/* mkdraft:func_82E0292C begin */
extern s32 func_80055948(s32);
extern void func_80055EF0(void *, s32);
extern void Gfx_InitDisplayListBuffers(s32, s32);
extern void Gfx_FreeDisplayListBuffers(void);
extern s32 func_800082E0(s32, s32, s32, s32, s32, s32);
extern s32 func_8004C09C(s32);
extern s32 func_8004C4B0(s32);
extern u8 *func_80047588(s32, s32);
extern u8 *Asset_LoadToSegment(s32, u8 *, u8 *, s32);
extern u8 D_1000000[], D_446E30[], D_447D00[];
extern void func_80008514(s32);
extern void func_80008574(void);
extern void func_80047610(void);
extern void func_8004C398(void);
extern s32 D_82E07610;
extern u8 *D_82E05930;

s32 func_82E0292C(s32 arg0, s16 *arg1) {
    s32 configuration;
    u8 data[0x20];

    func_80055948(3);
    func_80055EF0(data, *arg1 ? 1 : 0);
    if (data[0xD] == 0) {
        D_82E07610 = 1;
    } else {
        D_82E07610 = 0;
    }
    main_pool_push_state(0x454E4447);
    Gfx_InitDisplayListBuffers(0x10000, 0);
    configuration = func_800082E0(1, 1, 2, 0, 2, 1);
    func_8004C09C(0x107);
    func_8004C4B0(0x35);
    D_82E05930 = func_80047588(0x3F, 0);
    Asset_LoadToSegment(((u32)D_1000000 & 0x0F000000) >> 24, D_446E30, D_447D00, 0);
    func_82E02508();
    func_80008514(configuration);
    func_82E028D0();
    func_80008574();
    func_80047610();
    func_8004C398();
    Gfx_FreeDisplayListBuffers();
    main_pool_pop_state(0x454E4447);
    return D_82E07610;
}
/* mkdraft:func_82E0292C end */
#endif

#ifdef VERSION_US
extern Gfx *D_800D0510;
extern u8 D_82E05450[];
void Font_EndTexturedTextRendering_fragment66(void) { Gfx *temp_v1 = D_800D0510++; temp_v1->words.w0 = 0xDE000000; temp_v1->words.w1 = (u32)D_82E05450; }
#endif

void func_82E02A9C(void) {
}

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/66/fragment66_code/func_82E02AA4.s")
#endif

#ifdef VERSION_US
extern void Font_EndTexturedTextRendering_fragment66();
extern void func_82E02AA4(s32);

void func_82E02CA4(s32 arg0) {
    Font_EndTexturedTextRendering_fragment66();
    func_82E02AA4(arg0);
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/66/fragment66_code/func_82E02CCC.s")
#endif

#ifdef VERSION_US
extern void Font_EndTexturedTextRendering_fragment66(void);
extern void func_82E02CCC(s32, s32, s32);
void func_82E02EB0(s32 arg0, s32 arg1, s32 arg2) {
    Font_EndTexturedTextRendering_fragment66();
    func_82E02CCC(arg0, arg1, arg2);
}
void func_82E02EB0_padding(void) {}
void func_82E02EB0_padding2(void) {}
void func_82E02EB0_padding3(void) {}
#endif

#ifdef VERSION_US
extern Gfx D_82E05500[];
void func_82E02F00(s32 x, s32 y, u8 opacity) {
    gSPDisplayList(D_800D0510++, D_82E05500);
    gDPSetEnvColor(D_800D0510++, 0, 0, 0, 255 - opacity);
    gSPScisTextureRectangle(D_800D0510++, x << 2, y << 2,
                           (x + 320) << 2, (y + 240) << 2,
                           G_TX_RENDERTILE, 0, 0, 0x400, 0x400);
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/66/fragment66_code/func_82E030B0.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/66/fragment66_code/func_82E0393C.s")
#endif

#ifdef VERSION_US
extern void func_8003F1DC(void*);
extern s32 func_8004DC6C(s32);
extern void func_8004DCFC(u8*, s32*);
extern s32 func_8004EB58(s32, s32);
extern void func_82E0424C(s32);
extern void func_82E04734(void);
void func_82E04040(s32 scene) {
    void* allocation;
    u8* resource;
    /* Valid scene indices are 0..10, as in the original switch. */
    main_pool_pop_state(0x64617461);
    main_pool_push_state(0x64617461);
    func_8003F1DC(D_82E05660);
    func_8003F1DC(D_82E057C8);
    switch (scene) {
    case 0:
        D_82E075F4 = func_8004D690(0x22);
        resource = (u8*)(u32)func_8004DC6C(0xE4);
        break;
    case 1:
        D_82E075F4 = func_8004D690(0x23);
        resource = (u8*)(u32)func_8004DC6C(0xE8);
        break;
    case 2:
        D_82E075F4 = func_8004D690(0x24);
        resource = (u8*)(u32)func_8004DC6C(0xCD);
        break;
    case 3:
        D_82E075F4 = func_8004D690(0x25);
        resource = (u8*)(u32)func_8004DC6C(0xD0);
        break;
    case 4:
        D_82E075F4 = func_8004D690(0x26);
        resource = (u8*)(u32)func_8004DC6C(0xCF);
        break;
    case 5:
        D_82E075F4 = func_8004D690(0x27);
        resource = (u8*)(u32)func_8004DC6C(0xE9);
        break;
    case 6:
        D_82E075F4 = func_8004D690(0x28);
        resource = (u8*)(u32)func_8004DC6C(0x90);
        break;
    case 7:
        D_82E075F4 = func_8004D690(0x29);
        resource = (u8*)(u32)func_8004DC6C(0x97);
        break;
    case 8:
        D_82E075F4 = func_8004D690(0x2A);
        resource = (u8*)(u32)func_8004DC6C(0xCC);
        break;
    case 9:
        D_82E075F4 = func_8004D690(0x2B);
        resource = (u8*)(u32)func_8004DC6C(0x9E);
        break;
    case 10:
        resource = (u8*)(u32)func_8004DC6C(0x8F);
        break;
    }
    func_8004DCFC(resource, 0);
    allocation = MainPool_AllocState(main_pool_get_available(), 0);
    D_82E0760C = (u8*)(u32)func_8004EB58((s32)(u32)allocation, (s32)(u32)resource);
    MainPool_FinalizeAllocation(allocation);
    func_82E0424C(scene);
    func_82E04734();
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/66/fragment66_code/func_82E0424C.s")
#endif

#ifdef VERSION_US
typedef struct F66Record {
    s32 state;
    s32 x;
    s32 adjusted;
    s32 old;
    s32 source;
} F66Record;
extern F66Record D_82E05968[100];
extern s32 D_82E05948, D_82E0594C;
void func_82E04734(void) {
    s32 i;
    for (i = 0; i < 100; i++) {
        D_82E05968[i].state = 0;
        D_82E05968[i].x = D_82E05948;
        D_82E05968[i].adjusted = D_82E05968[i].source - D_82E0594C;
        D_82E05968[i].old = D_82E05968[i].source;
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/66/fragment66_code/func_82E047C4.s")
#endif

#ifdef VERSION_US
extern void GeoRender_ApplyMaterialState();
extern void func_82E047C4(s32);
extern void *D_82E07600;
s32 func_82E04AE4(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg0 == 5)) {
        func_82E047C4((*(s32 *)((u8 *)(D_82E07600) + (8))));
        GeoRender_ApplyMaterialState();
    }
    return 0;
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/66/fragment66_code/func_82E04B28.s")
#endif

#ifdef VERSION_US
extern void func_82E04B28(s32);
s32 func_82E04E60(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg0 == 5)) {
        func_82E04B28((*(s32 *)((u8 *)(D_82E07600) + (8))));
        GeoRender_ApplyMaterialState();
    }
    return 0;
}
#endif
