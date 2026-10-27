#include "global.h"


#ifdef VERSION_US
/* mkdraft:func_88201FE0 begin */
u8 func_80062F68(u8);
u8 func_80063014(u8);
s32 func_88A008CC(u8 *);
extern u8 D_88A01B80[];

u8 func_88201FE0(u8 *arg0) {
    s32 i;

    if (func_88A008CC(arg0) != 0) {
        if (arg0[0] >= 0xC9 && arg0[0] < 0xFB) {
            return func_80063014(arg0[0] - 0xC8);
        }
        if (arg0[0] >= 0xC4 && arg0[0] < 0xC9) {
            return func_80063014(arg0[0] - 0x91);
        }
    } else {
        for (i = 0; i != 0x39; i++) {
            if (arg0[0] == D_88A01B80[i]) {
                return func_80062F68(i + 1);
            }
        }
    }
    return 0;
}
/* mkdraft:func_88201FE0 end */

s32 func_88202098(u8 arg0) {
    s32 result = 0;

    switch (arg0) {
        case 5:
        case 6:
        case 8:
        case 9:
        case 31:
        case 41:
        case 42:
        case 43:
        case 45:
        case 48:
        case 63:
        case 64:
        case 69:
        case 70:
        case 71:
        case 72:
        case 73:
        case 74:
        case 76:
        case 77:
        case 78:
        case 196:
        case 197:
        case 198:
        case 199:
        case 200:
            result = 1;
            break;
    }
    return result;
}

extern u8 func_8006378C(u8);
s32 func_88202104(u8 arg0) {
    s32 result = 0;

    if (func_8006378C(arg0) == 2 || (arg0 >= 0xF3 && arg0 < 0xFA)) {
        result = 1;
    }
    return result;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_175260/func_88202158.s")

// Same 12-byte layout as LabPCStorageList in
//@src/fragments/31/fragment31_1736F0.c
typedef struct LabPCStorageList {
    u8 count;
    u8 capacity;
    void *entries;
    s32 changed;
} LabPCStorageList;

extern LabPCStorageList D_88234630[];
extern s32 func_88A01074(u8, s32, s32);

s32 func_882025B4(u32 mode, u8 slot) {
    s32 result = 0;

    switch (mode) {
        case 0:
            if (D_88234630[1].count == D_88234630[1].capacity) {
                result = 1;
            }
            break;
        case 1:
            if (D_88234630[3].count == D_88234630[3].capacity) {
                result = 1;
            }
            break;
        case 2:
            if (func_88A01074(slot, 1, 0) == 0) {
                result = 1;
            }
            break;
        case 3:
            if (func_88A01074(slot, 1, 1) == 0) {
                result = 1;
            }
            break;
        case 4:
            if (func_88A01074(slot, 1, 2) == 0) {
                result = 1;
            }
            break;
    }
    return result;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_175260/func_882026A4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_175260/func_882027F0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_175260/func_88202AA0.s")

extern s32 func_88202098(u8);
extern s32 func_88A008CC(u8 *);
extern s32 func_88A0083C(u8 *);
extern void func_88A015A0(s32);
extern u8 *D_88A01C64;

void func_88202F0C(u8 *arg0) {
    s32 var_v0;

    if (func_88A008CC(arg0) != 0) {
        var_v0 = func_88202098(arg0[0]) == 0;
    } else {
        var_v0 = func_88202104(arg0[0]) == 0;
    }
    if (var_v0 != 0) {
        var_v0 = func_88A0083C(arg0);
        *(s32 *)(D_88A01C64 + var_v0 * 4 + 260) = 1;
        if (--arg0[1] == 0) {
            func_88A015A0(var_v0);
        }
    }
}

extern void func_88202F0C(u8 *);
void func_88202FA0(void *a0, u8 *a1) {
    *(u8 *)((u8 *)a0 + 9) = *(u8 *)a1;
    *(s32 *)((u8 *)*(void **)a0 + 0xC) = 1;
    func_88202F0C(a1);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_175260/func_88202FD4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/31/fragment31_175260/func_882033B0.s")
#endif
