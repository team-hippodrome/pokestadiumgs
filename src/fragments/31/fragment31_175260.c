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

/* mkdraft:func_88202158 begin */


s32 func_88202158(u8 *arg0, s32 arg1) {
    s32 var_v1;

    var_v1 = func_88A008CC(arg0);
    if ((arg1 & 1) && (((var_v1 == 1) && (func_88202098(*arg0) != 0)) || ((var_v1 == 0) && (func_88202104(*arg0) != 0)))) {
        return 1;
    }
    if (arg1 & 2) {
        if (func_88201FE0(arg0) != 0) {
            return 1;
        }
    }
    if ((arg1 & 4) && (var_v1 == 0)) {
        if (func_88202104(*arg0) == 0) {
            if ((*arg0 > 0) && (*arg0 < 251)) {
                return 1;
            }
        }
    }
    if ((arg1 & 8) && (((var_v1 == 1) && (*arg0 == 40)) || ((var_v1 == 0) && (*arg0 == 32)))) {
        return 1;
    }
    if ((arg1 & 0x10) && (((var_v1 == 1) && (*arg0 == 35)) || ((var_v1 == 0) && (*arg0 == 26)))) {
        return 1;
    }
    if ((arg1 & 0x20) && (((var_v1 == 1) && (*arg0 == 36)) || ((var_v1 == 0) && (*arg0 == 27)))) {
        return 1;
    }
    if ((arg1 & 0x40) && (((var_v1 == 1) && (*arg0 == 37)) || ((var_v1 == 0) && (*arg0 == 28)))) {
        return 1;
    }
    if ((arg1 & 0x80) && (((var_v1 == 1) && (*arg0 == 38)) || ((var_v1 == 0) && (*arg0 == 29)))) {
        return 1;
    }
    if ((arg1 & 0x100) && (((var_v1 == 1) && (*arg0 == 39)) || ((var_v1 == 0) && (*arg0 == 31)))) {
        return 1;
    }
    if ((arg1 & 0x200) && (((var_v1 == 1) && (*arg0 == 79)) || ((var_v1 == 0) && (*arg0 == 62)))) {
        return 1;
    }
    if ((arg1 & 0x400) && (((var_v1 == 1) && (*arg0 == 10)) || ((var_v1 == 0) && (*arg0 == 8)))) {
        return 1;
    }
    if ((arg1 & 0x800) && (((var_v1 == 1) && (*arg0 == 32)) || ((var_v1 == 0) && (*arg0 == 22)))) {
        return 1;
    }
    if ((arg1 & 0x1000) && (((var_v1 == 1) && (*arg0 == 33)) || ((var_v1 == 0) && (*arg0 == 23)))) {
        return 1;
    }
    if ((arg1 & 0x2000) && (((var_v1 == 1) && (*arg0 == 34)) || ((var_v1 == 0) && (*arg0 == 24)))) {
        return 1;
    }
    if ((arg1 & 0x4000) && (((var_v1 == 1) && (*arg0 == 47)) || ((var_v1 == 0) && (*arg0 == 34)))) {
        return 1;
    }
    if ((arg1 & 0x8000) && (var_v1 == 0) && (*arg0 == 169)) {
        return 1;
    }
    return 0;
}
/* mkdraft:func_88202158 end */

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

extern u8 *func_88A00710(s32 arg0, s16 arg1);
extern u8 func_88A007BC(s32 arg0);
extern void func_88A014C8(s32 arg0, u8 arg1, s8 arg2);
extern void func_88A015A0(s32 arg0);

typedef struct {
    u8 unk_00;
    u8 unk_01;
} BagEntry;



void func_88202AA0(u8 *arg0, s16 arg1) {
    u32 i;
    u16 total;
    BagEntry *first;
    BagEntry *second;
    u8 value;
    u32 count;
    s32 flag;
    u8 j;
    s32 found;
    BagEntry records[0x100];
    u8 stacks;
    u8 rem;
    u32 stacksTotal; // FAKE: layout-only temp; diff score 8 without it

    total = func_88A007BC((s32) arg0);
    first = (BagEntry *) func_88A00710((s32) arg0, 0);
    second = (BagEntry *) func_88A00710((s32) arg0, arg1);
    count = second->unk_01;
    value = second->unk_00;
    flag = 0;
    if (count != 0) {
        for (i = 0; i < total; i++) {
            if (first != second && first->unk_00 == second->unk_00) {
                flag = 1;
                count += first->unk_01;
                first->unk_01 = 0;
            }
            first++;
        }
    }
    func_88A015A0((s32) arg0);
    if (flag == 0) {
        return;
    }
    j = 0;
    found = 0;
    first = (BagEntry *) func_88A00710((s32) arg0, 0);
    total = func_88A007BC((s32) arg0);
    for (i = 0; i < total; i++) {
        if (found != 0) {
            records[j] = *first;
            j++;
        } else if (first->unk_00 == value) {
            found = 1;
            arg1 = i;
        }
        first++;
    }
    if (count < 100) {
        first = (BagEntry *) func_88A00710((s32) arg0, arg1);
        first->unk_01 = count;
        return;
    }
    stacksTotal = count / 99;
    stacks = stacksTotal;
    rem = count % 99;
    if (rem == 0) {
        rem = 99;
        stacks = stacks - 1;
    }
    first = (BagEntry *) func_88A00710((s32) arg0, arg1);
    first->unk_01 = 99;
    func_88A014C8((s32) arg0, first->unk_00, stacks);
    first++;
    for (i = 0; i < stacks; i++, first++) {
        first->unk_00 = value;
        if (i == stacks - 1) {
            first->unk_01 = rem;
        } else {
            first->unk_01 = 99;
        }
    }
    for (i = 0; i < j; i++, first++) {
        *first = records[i];
    }
}

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

extern u8 D_8800686C;
extern u8 LabPC_FindFireStoneEvolution(u8 species);
extern u8 LabPC_FindLeafStoneEvolution(u8 species);
extern u8 LabPC_FindWaterStoneEvolution(u8 species);
// FAKE: src/641E0.c defines these as void with a wider second parameter.
// They are declared s32 here because the target tail-returns their v0, and
// the second parameter must be u8 for the target's register allocation
// (declaring it s32 scores 505).
extern s32 func_80063C90(u8 arg0, u8 arg1);
extern s32 func_80063EE4(u8 arg0, u8 arg1);
extern s32 func_80063F18(u8 arg0, u8 arg1);
extern s32 func_88202158(u8 *, s32);
extern s32 func_88902BA0(void *arg0, u8 arg1);
extern u8 func_88903084(u8 arg0);
extern u8 func_8890311C(u8 arg0);
extern u8 func_889031EC(u8 arg0);



s32 func_88202FD4(u8 *arg0, u8 *arg1) {
    s32 i;
    u8 value;
    s32 result;
    u8 *p;
    u8 *q;

    p = arg0;

    if ((p[0x26] & 1) != 0 || p[8] == 0xFC) {
        return 0;
    }

    value = func_88201FE0(arg1);
    if (value != 0) {
        if (func_88902BA0(p + 8, value) != 0) {
            return 0;
        }
        switch (D_8800686C) {
        case 1:
        case 2:
        case 3:
            return func_80063EE4(p[8], value);
        case 4:
            return func_80063F18(p[8], value);
        default:
            return func_80063C90(p[8], value);
        }
    }

    result = 0;
    if (func_88202158(arg1, 8) != 0) {
        if (p[0x25] < 0x64) {
            result = 1;
        }
    } else if (func_88202158(arg1, 0x10) != 0) {
        if (*(u16 *)(p + 0x14) < 0x6400) {
            result = 1;
        }
    } else if (func_88202158(arg1, 0x20) != 0) {
        if (*(u16 *)(p + 0x16) < 0x6400) {
            result = 1;
        }
    } else if (func_88202158(arg1, 0x40) != 0) {
        if (*(u16 *)(p + 0x18) < 0x6400) {
            result = 1;
        }
    } else if (func_88202158(arg1, 0x80) != 0) {
        if (*(u16 *)(p + 0x1A) < 0x6400) {
            result = 1;
        }
    } else if (func_88202158(arg1, 0x100) != 0) {
        if (*(u16 *)(p + 0x1C) < 0x6400) {
            result = 1;
        }
    } else if (func_88202158(arg1, 0x200) != 0) {
        q = p;
        for (i = 0; i != 4u; i++, q++) {
            if (q[0xA] != 0 && q[0xA] != 0xFC &&
                q[0xA] != 0xA6 &&
                ((q[0x20] & 0xC0) >> 6) != 3) {
                result = 1;
                break;
            }
        }
    } else if (func_88202158(arg1, 0x400) != 0) {
        result = func_88903084(p[8]);
    } else if (func_88202158(arg1, 0x800) != 0) {
        result = LabPC_FindFireStoneEvolution(p[8]);
    } else if (func_88202158(arg1, 0x1000) != 0) {
        result = func_8890311C(p[8]);
    } else if (func_88202158(arg1, 0x2000) != 0) {
        result = LabPC_FindWaterStoneEvolution(p[8]);
    } else if (func_88202158(arg1, 0x4000) != 0) {
        result = LabPC_FindLeafStoneEvolution(p[8]);
    } else if (func_88202158(arg1, 0x8000) != 0) {
        result = func_889031EC(p[8]);
    }
    return result;
}

/* mkdraft:func_882033B0 begin */
extern u8 func_88201FE0(u8 *);
extern s32 func_88202158(u8 *, s32);
extern void func_88902BE0(u8 *, u8);
extern s32 func_80061B88(s32, u16);
extern u8 func_80062E4C(u8);
extern s32 func_8800005C(void);
extern void func_88202F0C(u8 *);
extern s8 D_889041A0;



void func_882033B0(u8 *arg0, u8 *arg1) {
    u16 value;
    /* Unused locals: retail addresses `type` at 0x22(sp), and this 3-byte
       pair ahead of it in declaration order reserves that slot. */
    u16 result;
    u8 max;
    u8 type = 0;
    u8 move = func_88201FE0(arg1);

    if (move != 0) {
        func_88902BE0(arg0 + 8, move);
        if (func_88202158(arg1, 1) == 0) {
            type = 1;
        }
    } else if (func_88202158(arg1, 8)) {
        arg0[0x25] += 1;
        *(s32 *)(arg0 + 0x10) = func_80061B88(arg0[8], arg0[0x25]);
        type = 2;
    } else if (func_88202158(arg1, 0x10)) {
        if ((*(u16 *)(arg0 + 0x14) += 0xA00) >= 0x6401) {
            *(u16 *)(arg0 + 0x14) = 0x6400;
        }
        type = 3;
    } else if (func_88202158(arg1, 0x20)) {
        if ((*(u16 *)(arg0 + 0x16) += 0xA00) >= 0x6401) {
            *(u16 *)(arg0 + 0x16) = 0x6400;
        }
        type = 3;
    } else if (func_88202158(arg1, 0x40)) {
        if ((*(u16 *)(arg0 + 0x18) += 0xA00) >= 0x6401) {
            *(u16 *)(arg0 + 0x18) = 0x6400;
        }
        type = 3;
    } else if (func_88202158(arg1, 0x80)) {
        if ((*(u16 *)(arg0 + 0x1A) += 0xA00) >= 0x6401) {
            *(u16 *)(arg0 + 0x1A) = 0x6400;
        }
        type = 3;
    } else if (func_88202158(arg1, 0x100)) {
        if ((*(u16 *)(arg0 + 0x1C) += 0xA00) >= 0x6401) {
            *(u16 *)(arg0 + 0x1C) = 0x6400;
        }
        type = 3;
    } else if (func_88202158(arg1, 0x200)) {
        *(u8 *)((u8 *)arg0 + D_889041A0 + 0x20) = func_80062E4C(*(u8 *)((u8 *)arg0 + D_889041A0 + 0xA)) + *(u8 *)((u8 *)arg0 + D_889041A0 + 0x20) + 0x40;
    }

    if (func_8800005C() == 0 && type) {
        value = arg0[0x24];
        switch (type) {
        case 1:
            if (value < 0xC8) {
                value++;
            }
            break;
        case 2:
        case 3:
            if (value < 0x64) {
                value = value + 5;
            } else if (value < 0xC8) {
                value = value + 3;
            } else {
                value = value + 2;
            }
            break;
        }
        if (value >= 0x100) {
            value = 0xFF;
        }
        arg0[0x24] = value;
    }

    *(s32 *)(*(u8 **)arg0 + 0xC) = 1;
    func_88202F0C(arg1);
}
/* mkdraft:func_882033B0 end */
#endif
