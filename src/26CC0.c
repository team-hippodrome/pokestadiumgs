#include "229E0.h"

#ifdef VERSION_US

extern s32 D_80090B94;
extern s32 D_80090B98;
extern s32 func_800265B0(u32 arg0, s32 arg1);

extern s32 D_80090B5C;
extern s32 func_80018B78(s32 arg0);
extern void func_8002AAFC(s32);
void func_800260C0(s32 kind, s32 category, s32 request) {
    s32 group;
    s32 index;
    u8 force;
    Color_80026938 *entry;

    force = 0;
    func_8002AAFC(0);
    D_80090220 = 0;
    D_80090A54 = 0;
    func_80018728(0x83040000, 0);
    if (kind == 11) {
        kind = 2;
        force = 1;
    }
    switch (kind) {
        case 1:
        case 2:
        case 5:
        case 7:
        case 9:
        case 10:
            group = 1;
            break;
        case 0:
            group = 0;
            break;
        case 3:
        case 4:
            group = 5;
            break;
        case 6:
            group = 6;
            break;
        case 13:
            group = 8;
            break;
        case 12:
            group = 7;
            break;
        case 8:
            index = Audio_GetEventConfigIndex(category, request);
            if (index < 0) {
                index = 0;
            }
            if (D_80090B70 == -1) {
                entry = &D_80090AD0[index];
                group = entry->first;
            } else {
                group = D_80090B70;
                entry = &D_80090AD0[index];
            }
            if (D_80090B6C == -1) {
                D_80090BA0 = entry->second;
            } else {
                D_80090BA0 = D_80090B6C;
            }
            func_8002A80C(entry->third);
            func_8002A7A8(category, request);
            D_80090B94 = category;
            D_80090B98 = request;
            break;
        case 30:
            group = 2;
            break;
        default:
            return;
    }
    D_80090B60 = kind;
    if (force == 0 && group == D_80090B5C) {
        D_80090B64 = 0;
    } else {
        D_80090B5C = group;
        D_80090B64 = 1;
        D_80090B68 = 1;
        D_80090B9C = 0;
        func_80018B78(group);
    }
}

s32 func_80026298(void) {
    func_80018810();
    if (D_80090B64 != 0) {
        if (func_80018ACC() == 0) {
            return 0;
        }
        D_80090B64 = 0;
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return 1;
    }
    return 1;
}

void Audio_ResetCategoryState(void) {
    D_80090B64 = 0;
    D_80090B6C = -1;
    D_80090B70 = -1;
    func_80018728(0x82010000U, 0);
    func_80018704(0x41010000, 0.63f);
    D_80090B80 = 1;
    switch (D_80090B60) {
    case 2:
    case 3:
    case 5:
    case 7:
    case 9:
    case 10:
        func_80018728(0x82040500U, 0);
        func_80018704(0x41040000, 0.63f);
    case 1:
    case 4:
        if (D_80090B9C == 0) {
            func_80018728(0x82020400U, 0);
            func_80018704(0x41020000, 0.63f);
            D_80090B9C = 1;
        }
        break;
    case 12:
        func_80018728(0x82030800U, 0);
        func_80018704(0x41030000, 0.72f);
        break;
    case 0:
        func_80018728(0x82020600U, 0);
        func_80018704(0x41020000, 0.648f);
        break;
    }
    if (D_80090B60 == 3 || D_80090B60 == 4 || D_80090B60 == 6) {
        func_80018728(0x82030300U, 0);
        func_80018704(0x41030000, 0.765f);
        func_800187AC();
        func_80025E7C();
    }
    if (D_80090B68 != 0) {
        D_80090B68 = 0;
        switch (D_80090B60) {
        case 0:
            func_80018728(0x82020600U, 0);
            break;
        case 12:
            func_80018728(0x82040200U, 0);
            func_80018704(0x41020000, 1.0f);
            break;
        case 8:
            func_80018728(0x82040200U, 0);
            func_80018704(0x41020000, 1.0f);
            func_80018728(0x82020100U, 0);
            func_80018704(0x41020000, 0.63f);
            func_80018728(0x82010A00U, 0);
            func_80018728(0x82010000U, 0);
            func_80018704(0x41010000, 0.63f);
            D_80090B80 = 1;
            func_80024D44();
            func_80018728(0x82032300U, 0);
            D_80090A50 = 35;
            break;
        case 30:
            func_80024D44();
            func_80018728(0x82032300U, 0);
            D_80090A50 = 35;
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 9:
        case 10:
        case 11:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
        case 29:
            break;
        }
    }
}

/* mkdraft:func_800265B0 begin */

// Case 18's body is emitted before the -1 and -2 bodies: jump-table entries 16, 17 and 18
// point at 0x80026658, 0x80026660 and 0x80026650, so the case labels appear in that order.


s32 func_800265B0(u32 arg0, s32 arg1) {
    s32 result;

    switch (arg0) {
    case 0: result = 0; break;
    case 1: result = 9; break;
    case 2: result = 18; break;
    case 3: result = 27; break;
    case 4: result = 36; break;
    case 5: result = 45; break;
    case 6: result = 54; break;
    case 7: result = 63; break;
    case 8: result = 72; break;
    case 9: result = 81; break;
    case 10: result = 90; break;
    case 11: result = 113; break;
    case 12: return 118;
    case 13: result = 119; break;
    case 14: return 127;
    case 15: return 128;
    case 18: return 131;
    case 16: result = -1; break;
    case 17: result = -2; break;
    default: return 132;
    }
    switch (arg1) {
    case 10:
        if (D_80090B94 >= 10 && D_80090B94 < 16) {
            result += arg1;
        }
        break;
    case 11:
        if (D_80090B94 >= 10 && D_80090B94 < 16) {
            result += arg1;
            break;
        }
        return -2;
    case 40:
        return -3;
    default:
        // No break: the add falls out of the switch into `return result`, which schedules it
        // into the delay slot of the 40 comparison.
        result += arg1;
    }
    return result;
}
/* mkdraft:func_800265B0 end */

s32 Audio_GetEventConfigIndex(s32 category, u32 request) {
    switch (request) {
    case 10: return 31;
    case 11: return 32;
    case 40: return 33;
    }
    switch (category) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    case 4: return 4;
    case 5: return 5;
    case 6: return 6;
    case 7: return 7;
    case 8: return 8;
    case 9: return 9;
    case 10:
        if (request < 2) return 10;
        if (request >= 2 && request < 5) return 11;
        if (request >= 5 && request < 8) return 12;
        if (request >= 8 && request < 11) return 13;
        if (request >= 11 && request < 13) return 14;
        if (request >= 13 && request < 14) return 15;
        if (request >= 14 && request < 18) return 16;
        if (request >= 18 && request < 21) return 17;
        if (request >= 21 && request < 24) return 18;
        return -1;
    case 11: return 19;
    case 12: return 20;
    case 13:
        switch (request) {
        case 0: return 21;
        case 1: return 22;
        case 2: return 23;
        case 3: return 24;
        case 4: return 25;
        case 5: return 26;
        case 6: return 27;
        case 7: return 28;
        default: return -1;
        }
    case 14: return 29;
    case 15: return 30;
    case 18: return 34;
    case 19: return 35;
    }
    return -1;
}

void func_80026938(u16 arg0) {
    s32 index;
    Color_80026938 *entry;

    if (arg0 >= 0x1E) {
        arg0 = 0xE;
    }
    index = D_80090B3C[arg0];
    entry = &D_80090AD0[index];
    D_80090B6C = entry->second;
    D_80090B70 = entry->first;
}

#endif
