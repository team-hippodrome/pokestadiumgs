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

extern s32 func_80063754(s32);
extern u8 *func_8820137C(u8 *);
extern void func_88203A58(u8 *);
extern void func_88203ED8(u8 *, s32);
extern void func_88A017B4(u8, s16);
extern u8 D_88A01C3F[];

void func_882026A4(u8 *arg0, s32 arg1) {
    u8 *obj = NULL;

    if (func_80063754(arg0[9])) {
        obj = func_8820137C(arg0);
        if (arg1 == 2 || arg1 == 3 || arg1 == 4) {
            func_88203A58(obj);
        }
    }
    switch (arg1) {
        case 0:
        case 1:
            if (obj != NULL) {
                if (!func_80063754(obj[0x75])) {
                    obj[0x75] = arg0[9];
                }
                func_88203ED8(obj, (arg1 == 0) ? 1 : 3);
            }
            break;
        case 2:
            func_88A017B4(arg0[9], 0);
            break;
        case 3:
            func_88A017B4(arg0[9], 1);
            break;
        case 4:
            func_88A017B4(arg0[9], 2);
            break;
    }
    if (arg0[0x27] != 0) {
        D_88A01C3F[arg0[0x27]] = 0;
        arg0[0x27] = 0;
    }
    arg0[9] = 0;
    *(s32 *)(*(u8 **)arg0 + 0xC) = 1;
}

/* mkdraft:func_882027F0 begin */
// Color triple consumed by func_88000510/func_880006E0; same layout and name as the
// Color88217F70 typedef used by matched fragment 31 code.
//@src/fragments/31/fragment31_189760.c
typedef struct Color88217F70 {
    u8 red;
    u8 green;
    u8 blue;
} Color88217F70;

extern u8 func_88201FE0(u8 *);
extern s32 func_88A008CC(u8 *);
extern void func_880006E0(Color88217F70 *);
extern Color88217F70 *func_88000510(Color88217F70 *, s8);
extern void *func_8004C874(s32, s32);
extern u8 func_80062D5C(u8);
extern u8 func_80062D98(u8);
extern u8 func_80062DD4(u8);
// The definition in 638E0.c returns u8, but declaring it u8 here makes IDO reserve
// an extra (unreferenced) stack word, pushing sp46's spill from 0x24 to 0x20 (score 8).
//@src/638E0.c
extern s32 func_80062E10(u8); // FAKE: declared s32 (real return type u8, //@src/638E0.c); diff score 8 with the u8 prototype.
extern s32 func_80062CE0(u8);
extern s32 func_80063270(u8);
extern s32 func_80048E30(u8 *, s32, s32, const char *, s32);
extern void func_800495F8(s32, s32, s32, const char *, ...);
extern Color88217F70 D_88005FA0;
extern s32 D_8800687C;

// Draws the three-part readout for one record `arg0`: its first byte is a species id,
// which func_88201FE0 resolves to the six-byte-stride table index used by the
// func_80062D5x accessors. Rows are "%s%d" at (arg5, arg1), "%s%s" or "%s%d" at
// (arg3, arg2), the 0-100 scaled func_80062DD4 byte at (arg6, arg2), then two icon
// strings via func_80048E30.
//@src/fragments/31/fragment31_175260.c


void func_882027F0(u8 *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6) {
    // Stack slots follow the target with locals declared in this order: named slots
    // fill downward from 0x47, and the first free word after sp2C is 0x24 (0x28 stays
    // a hole). Declaring any further local takes 0x24 and moves the sp46 spill (the
    // func_80062D5C result across the else-branch func_8004C874 call) to 0x20.
    u8 sp47;
    u8 sp46;
    s8 sp45;
    Color88217F70 sp40;
    f32 var_fv1;
    f32 var_fv0;
    u8 sp37;
    s32 sp30;
    s32 sp2C;

    sp47 = func_88201FE0(arg0);
    func_880006E0(&D_88005FA0);
    if (sp47 != 0) {
        sp46 = func_80062D5C(sp47);
        sp45 = func_80062D98(sp47);
        sp30 = (s32) func_8004C874(0x1F, 0xB);
        func_800495F8(arg5, arg1, 0, "%s%d", sp30, func_80062E10(sp47));
        if ((sp46 == 0) || (sp46 == 1)) {
            sp2C = (s32) func_8004C874(0x1F, 0xC);
            func_800495F8(arg3, arg2, 0, "%s%s", sp2C, func_8004C874(0x1F, 0xE));
        } else {
            func_800495F8(arg3, arg2, 0, "%s%d", func_8004C874(0x1F, 0xC), sp46);
        }
        sp30 = (s32) func_8004C874(0x1F, 0xD);
        sp37 = func_80062DD4(sp47);
        // Both rounding operands are named f32 locals. uopt commutes add.s only when
        // one side is an interior expression node; with two leaves source order decides,
        // giving the bias first (add.s $ft2,$fv0,$ft1) as in the target.
        if (((f32) (func_80062DD4(sp47) * 0x64) / 255.0f) > 0.0f) {
            var_fv0 = 0.5f;
        } else {
            var_fv0 = -0.5f;
        }
        var_fv1 = (f32) (sp37 * 0x64) / 255.0f;
        func_800495F8(arg6, arg2, 0, "%s%d", sp30, (s32) (var_fv0 + var_fv1));
        func_880006E0(func_88000510(&sp40, sp45));
        func_80048E30((u8 *) D_8800687C, arg3, arg1, (const char *) func_80062CE0(sp47), 1);
        func_80048E30((u8 *) D_8800687C, arg4, arg1, (const char *) func_80063270(sp45), 1);
        func_880006E0(&D_88005FA0);
        return;
    }
    // The mode select stays inline: naming it would take a stack slot and make the tail
    // call result spill instead of staying in $v0 for the beqz/or pair.
    sp30 = (s32) func_8004C874(func_88A008CC(arg0) != 0 ? 0xB : 9, *arg0 - 1);
    if (sp30 != 0) {
        func_80048E30((u8 *) D_8800687C, arg3, arg1, (const char *) sp30, 1);
    }
}
/* mkdraft:func_882027F0 end */

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
