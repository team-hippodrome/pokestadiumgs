#include "global.h"


#ifdef VERSION_US
// Pointed to by D_8AB112F8 in .data; it opens this file's .rodata.
const char D_8AB11C90[] = "\n";
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/45/fragment45_2348E0/func_8AB0F760.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/45/fragment45_2348E0/func_8AB0F87C.s")
#endif

void func_8AB0FE08(void) {
}

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/45/fragment45_2348E0/func_8AB0FE10.s")
#endif

#ifdef VERSION_US
extern s32 D_8AB17408;
extern void *D_8AB11D08;
extern u8 *D_8AB17250;
extern void func_8AC00F04(void *);
extern void func_800503A4(u8 *);
extern s32 func_8AB1007C(s32);
extern s32 func_8AB100E0(s32);
extern s32 func_8AB10144(s32);
extern s32 func_8AB10248(s32);
extern s32 func_8AB103B0(s32);
extern s32 func_8AB104FC(s32);
extern s32 func_8AB1075C(s32);
extern s32 func_8AB10AD0(s32);
extern s32 func_8AB10D30(s32);
extern s32 func_8AB10DE4(s32);
extern s32 func_8AB10F14(s32);
// Declared without a prototype: func_8AB10D28 (defined below) takes no parameters, but this call
// site loads 2 into $a0 like the other state handlers.
extern s32 func_8AB10D28();
void func_8AB0FF40(s32 state) {
    D_8AB17408 = state;
    func_8AC00F04(D_8AB11D08);
    func_800503A4(D_8AB17250);
    switch (state) {
    case 61:
        func_8AB1007C(2);
        break;
    case 62:
        func_8AB100E0(2);
        break;
    case 63:
        func_8AB10144(2);
        break;
    case 64:
        func_8AB10248(2);
        break;
    case 65:
        func_8AB103B0(2);
        break;
    case 66:
        func_8AB104FC(2);
        break;
    case 67:
        func_8AB1075C(2);
        break;
    case 68:
        func_8AB10AD0(2);
        break;
    case 70:
        func_8AB10D30(2);
        break;
    case 69:
        func_8AB10D28(2);
        break;
    case 71:
        func_8AB10DE4(2);
        break;
    case 73:
        func_8AB10F14(2);
        break;
    }
}
#endif

#ifdef VERSION_US
extern s32 func_8AB1007C(s32);
s32 func_8AB1005C(void) {
    return func_8AB1007C(0);
}
#endif

#ifdef VERSION_US
extern void func_8AB04AE4(void);
extern u8 StageContext_GetFadeMode(void);
extern s32 func_8AB10144(s32);

s32 func_8AB1007C(s32 arg0) {
    s32 result = 0x3D;

    switch (arg0) {
    case 0:
        func_8AB04AE4();
        break;
    case 1:
        if (StageContext_GetFadeMode() == 0) {
            result = func_8AB10144(0);
        }
        break;
    }
    return result;
}
#endif

#ifdef VERSION_US
extern u8 StageContext_GetFadeMode(void);
extern void StageFade_StartFromTransparent(s32);
s32 func_8AB100E0(s32 arg0) {
    s32 result = 0x3E;

    switch (arg0) {
    case 0:
        StageFade_StartFromTransparent(5);
        break;
    case 1:
        if (StageContext_GetFadeMode() == 1) {
            result = 0;
        }
        break;
    }
    return result;
}
#endif

#ifdef VERSION_US
extern void *D_8AB11D00;
extern u8 D_8AB126A8[];
extern void *D_8AB17380;
extern u8 D_8AB17388[];
extern u16 D_8AB1268E;
extern void *D_80087200;
extern void *func_8004C8A0(void *, s32, s32, s32);
extern void func_8AC06400(void *, void *);
extern void func_8AC063AC(void *, u16);
extern void func_80021ED8(s32);
extern s32 func_8AB103B0(s32);
extern void func_8AB00B78(s32);
s32 func_8AB10144(s32 arg0) {
    s32 result = 63;
    s32 buttons;

    switch (arg0) {
    case 0:
        func_8004C8A0(D_8AB126A8, 256, 57, 652);
        *(u16 *)((u8 *)D_8AB11D00 + 2) |= 1;
        func_8AC06400(D_8AB17388, D_8AB17380);
        *(u16 *)((u8 *)D_8AB17380 + 2) |= 1;
        break;
    case 1:
        func_8AC063AC(D_8AB17388, D_8AB1268E);
        buttons = *(u16 *)((u8 *)D_80087200 + 8);
        if (buttons & 0x8000) {
            *(u16 *)((u8 *)D_8AB17380 + 2) &= ~1;
            func_80021ED8(20);
            result = func_8AB103B0(0);
        } else if (buttons & 0x4000) {
            result = func_8AB100E0(0);
            func_8AB00B78(3);
        }
        break;
    }
    return result;
}
#endif

#ifdef VERSION_US
extern void *D_8AB17410;
extern s16 D_8AB17400;
extern u8 *D_8AB17438;
extern void func_87F005F0(f32, f32);
extern void func_87F006BC(void);
extern u32 func_87F006AC(void);
extern void func_800225C4(s32);
extern void func_8AB00BA4(s32, s32, s32);
extern void func_8003C6B8(u8 *);
s32 func_8AB10248(s32 arg0) {
    s32 result = 64;

    switch (arg0) {
    case 0:
        func_87F005F0((f32)(*(s16 *)((u8 *)D_8AB17410 + 8) - 320),
                     (f32)(240 - *(s16 *)((u8 *)D_8AB17410 + 10)));
        func_8004C8A0(D_8AB126A8, 256, 57, 358);
        D_8AB17400 = 3;
        func_800225C4(90);
        break;
    case 1:
        func_87F006BC();
        switch ((s16)func_87F006AC()) {
        case 1:
            func_8AB00BA4(100, D_8AB17400, 0);
            D_8AB17400 -= 1;
            break;
        case 2:
            func_8AB00BA4(100, D_8AB17400, 0);
            D_8AB17400 -= 1;
            break;
        case 3:
            func_80021ED8(20);
            result = func_8AB103B0(0);
            break;
        }
        break;
    case 2:
        func_8003C6B8(D_8AB17438);
        break;
    }
    return result;
}
#endif

#ifdef VERSION_US
extern s16 D_8AB12694;
extern void *D_8AB1725C;
extern s16 D_8AB17440;
s32 func_8AB103B0(s32 arg0) {
    s32 result;
    s16 *counter;

    counter = &D_8AB17440;
    result = 65;
    switch (arg0) {
    case 0:
        func_8AB00BA4(0x10006, 0, 0);
        *counter = 0;
        if (D_8AB12694 > 0) {
            *(u16 *)((u8 *)D_8AB11D00 + 2) |= 1;
            func_8004C594(2, D_8AB12694 + 1);
            if (D_8AB12694 < 9) {
                func_8004C8A0(D_8AB126A8, 256, 57, func_8AB023EC(9) + 377);
            } else {
                func_8004C8A0(D_8AB126A8, 256, 57, 386);
            }
        } else {
            *(u16 *)((u8 *)D_8AB11D00 + 2) &= ~1;
        }
        func_8AB04AE4();
        *(u16 *)((u8 *)D_8AB1725C + 2) &= ~1;
        break;
    case 1:
        *counter += 1;
        if (*counter >= 45) {
            result = func_8AB104FC(0);
        }
        break;
    }
    return result;
}
#endif

#ifdef VERSION_US
extern u8 *D_8AB12678[];
extern s8 *D_8AB112F8;
extern u32 D_8AB1268C;
extern u8 D_8AB17260[];
extern s16 D_8AB17442;
extern s16 D_8AB17444;
s32 func_8AB104FC(s32 mode) {
    s32 id = 66;
    s32 i;
    u8 *p;
    u8 *q;

    switch (mode) {
        case 0:
            func_8AB03394();
            TextChoice_ShuffleAndRefresh();
            D_8AB17442 = 1;
            D_8AB17444 = 0;
            _bzero(D_8AB17260, 256);
            D_8AB12694++;
            if (D_8AB12694 >= 269) {
                D_8AB12694 = 0;
            }
            for (i = 0; i < 4; i++) {
                *(u16 *)(D_8AB12678[i] + 2) |= 1;
            }
            *(u16 *)((u8 *)D_8AB1725C + 2) |= 1;
            *(u16 *)((u8 *)D_8AB11D00 + 2) &= ~1;
            func_8AB04AE4();
            func_8004C594(2, D_8AB12694);
            break;
        case 1:
            func_8004C8A0(D_8AB17260, 256, *(u16 *)((u8 *)D_8AB11D00 + 0x30), *(u16 *)((u8 *)D_8AB11D00 + 0x32));
            // Walk D_8AB17442 characters (one byte for ASCII and '\n', two for a
            // high-bit lead byte) and cut the string after them.
            p = D_8AB17260;
            for (i = 0; i < D_8AB17442; i++) {
                q = p;
                if (*p == 0) {
                    D_8AB17444 = 1;
                    break;
                }
                if (*p == '\n') {
                    p++;
                } else if ((*p & 0x80) == 0) {
                    p++;
                } else {
                    p += 2;
                }
            }
            *p = 0;
            if ((D_8AB1268C & 1) == 0) {
                // q points at the last character examined; D_8AB112F8 points at "\n" (D_8AB11C90).
                if (HAL_Strcmp(q, D_8AB112F8) == 0) {
                    func_8AB00BA4(0x1000D, 0, 0);
                } else {
                    func_8AB00BA4(0x1000C, 0, 0);
                }
                D_8AB17442++;
            }
            if (D_8AB17444 == 1) {
                id = func_8AB1075C(0);
            }
            break;
        case 2:
            break;
    }
    return id;
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/45/fragment45_2348E0/func_8AB1075C.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/45/fragment45_2348E0/func_8AB10AD0.s")
#endif

#ifdef VERSION_US
s32 func_8AB10D28(void) {
    return 0x45;
}
#endif

#ifdef VERSION_US
extern s16 D_8AB1744E;
extern u8 *D_8AB12668[];
extern u8 *D_8AB12678[];
extern void func_8AB01FBC(void);
extern void TextHighlight_AnimateScales(void);
extern void func_8AB00B98(u8 *, u32);
extern s32 func_8AB10DE4(s32);
s32 func_8AB10D30(s32 arg0) {
    s32 result = 70;
    s16 *counter = &D_8AB1744E;
    u8 **panel;

    switch (arg0) {
    case 0:
        *counter = 0;
        func_8AB01FBC();
        break;
    case 1:
        *counter += 1;
        TextHighlight_AnimateScales();
        if (*counter >= 11) {
            panel = D_8AB12668;
            do {
                func_8AB00B98(*panel, -1U);
                panel++;
            } while (panel != D_8AB12678);
            result = func_8AB10DE4(0);
        }
        break;
    }
    return result;
}
#endif

#ifdef VERSION_US
extern s16 D_8AB17450;
extern void *D_8AB11D00;
extern u8 D_8AB126A8[];
extern void *D_8AB1725C;
extern void *func_8004C8A0(void *, s32, s32, s32);
extern void func_8AB00BA4(s32, s32, s32);
extern void func_800225C4(s32);
extern s32 func_8AB10F14(s32);
s32 func_8AB10DE4(s32 arg0) {
    s16 *counter = &D_8AB17450;
    s32 result = 71;
    s32 i;

    switch (arg0) {
    case 0:
        *counter = 0;
        *(u16 *)((u8 *)D_8AB11D00 + 2) |= 1;
        func_8AB04AE4();
        func_8004C8A0(D_8AB126A8, 256, 57, 389);
        *(u16 *)((u8 *)D_8AB1725C + 2) &= ~1;
        for (i = 0; i < 4; i++) {
            *(u16 *)(D_8AB12678[i] + 2) &= ~1;
        }
        func_8AB00BA4(65550, 0, 0);
        func_800225C4(40);
        break;
    case 1:
        *counter += 1;
        TextHighlight_AnimateScales();
        if (*counter >= 61) {
            result = func_8AB10F14(0);
        }
        break;
    }
    return result;
}
#endif

#ifdef VERSION_US
extern s16 D_8AB17452;
extern s16 D_8AB12CB4;
extern void *D_8AB17380;
extern u8 D_8AB17388[];
extern u16 D_8AB1268E;
extern void *D_80087200;
extern void func_80021ED8(s32);
extern void func_8AC06400(void *, void *);
extern void func_8AC063AC(void *, u16);
extern void func_8AB00B78(s32);
s32 func_8AB10F14(s32 arg0) {
    s32 result = 73;

    switch (arg0) {
    case 0:
        D_8AB17452 = 0;
        *(u16 *)((u8 *)D_8AB1725C + 2) &= ~1;
        if (D_8AB12CB4 == 1) {
            func_8004C8A0(D_8AB126A8, 256, 57, 16);
        } else {
            func_8004C8A0(D_8AB126A8, 256, 57, 17);
        }
        *(u16 *)((u8 *)D_8AB11D00 + 2) |= 1;
        func_8AB04AE4();
        func_80021ED8(7);
        *(u16 *)((u8 *)D_8AB17380 + 2) |= 1;
        func_8AC06400(D_8AB17388, D_8AB17380);
        break;
    case 1:
        func_8AC063AC(D_8AB17388, D_8AB1268E);
        if (*(u16 *)((u8 *)D_80087200 + 8) & 0x8000) {
            *(u16 *)((u8 *)D_8AB17380 + 2) &= ~1;
            result = func_8AB100E0(0);
            func_8AB00B78(194);
        }
        break;
    }
    return result;
}
#endif
