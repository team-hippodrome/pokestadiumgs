#include "global.h"
#include "controller.h"

// Shared fragment 16 state owned by fragment16_code.c and the fragment data.
extern Gfx *D_800D0510;
extern s16 D_82001D58;
extern s16 D_82001EA0;
extern u8 D_82001EB8;
extern s16 D_82001EBC;
extern s16 D_82001EBE;
extern s16 D_82001EC0;
extern s32 func_82000D10(s32 arg0, u8 *arg1);
extern s32 func_82000D24(s32 arg0, void *arg1);
extern s32 func_82000D64(s32 arg0, void *arg1);
extern s32 func_82000D80(s32 arg0, void *arg1);

void func_82000DE0(void) {
}

#ifdef VERSION_US
extern void *D_82001CD0;
extern s32 D_82001CD4;
extern s32 D_82001D50;
extern s32 D_82001EB0;
extern s32 D_82001EB4;
extern s32 D_82001EC4;
extern s32 D_82001EC8;
extern s32 D_82001EAC;
extern void *BinArchive_Open(s32, s32, s32, s32);
extern s32 MainPool_AllocState(s32, s32);
extern s32 MainPool_FinalizeAllocation(s32);
extern s32 func_80001FF0(void);
extern s32 func_800356CC(s32);
extern s32 func_8004DC6C(s32, s16 *);
extern s32 func_8004DCFC(s32, s32);
extern s32 func_8004E308(s32, s32 (*)(s32, u8 *), s32);
extern void *func_8004EB58(s32, s32);
extern s32 func_8005049C(void *, s32);
extern void Fragment16_InitGridState(void);
extern s32 func_8200070C(void);
extern s32 main_pool_get_available(void);

// Fragment 16 (title screen) setup. Resets the menu state words, sets the
// version-stamp delay D_82001D50 to half the current VI count plus 10, and
// zeroes the layout dims at D_82001EB8/D_82001EBC..D_82001EC0. Opens UI
// window config 0xA1; when that succeeds, func_82000DE8 stores its handle,
// finalizes a main-pool allocation for D_82001CD0, and registers the
// title/kuro/moji/EXPA archive callbacks func_82000D10/D24/D64/D80 through
// func_8004E308. Finishes by resetting the fade state (func_8200070C) and
// caching resource 0x10's word at offset 0xC in D_82001EB4.
void func_82000DE8(void) {
    s32 sp20;
    s32 temp_v0;
    s32 sp1C;
    s32 temp_v0_2;

    Fragment16_InitGridState();
    D_82001CD4 = 0;
    func_82000DE0();
    D_82001EC4 = 0;
    D_82001EC8 = 0;
    D_82001EAC = 0;
    D_82001EB0 = 0;
    D_82001D50 = (func_80001FF0() / 2) + 0xA;
    (*(s16 *)((u8 *)(&D_82001EB8) + (2))) = 0;
    D_82001EBE = 0;
    (*(s16 *)((u8 *)(&D_82001EB8) + (0))) = (s16) (*(s16 *)((u8 *)(&D_82001EB8) + (2)));
    D_82001EBC = D_82001EBE;
    D_82001EC0 = 0x170;
    D_82001CD0 = NULL;
    temp_v0 = func_8004DC6C(0xA1, &D_82001EBE);
    if (temp_v0 != 0) {
        sp20 = temp_v0;
        func_8004DCFC(temp_v0, 0);
        temp_v0_2 = MainPool_AllocState(main_pool_get_available(), 0);
        sp1C = temp_v0_2;
        D_82001CD0 = func_8004EB58(temp_v0_2, sp20);
        MainPool_FinalizeAllocation(sp1C);
        func_8004E308(func_8005049C(D_82001CD0, 0x7469746C), func_82000D10, 0);
        func_8004E308(func_8005049C(D_82001CD0, 0x6B75726F), (s32 (*)(s32, u8 *)) func_82000D24, 0);
        func_8004E308(func_8005049C(D_82001CD0, 0x6D6F6A69), (s32 (*)(s32, u8 *)) func_82000D64, 0);
        func_8004E308(func_8005049C(D_82001CD0, 0x45585041), (s32 (*)(s32, u8 *)) func_82000D80, 0);
    }
    func_8200070C();
    D_82001EB4 = (*(s32 *)((u8 *)(BinArchive_Open(func_800356CC(0x10), 0, 1, 1)) + (0xC)));
}
#endif

#ifdef VERSION_US
typedef struct {
    u8 r;
    u8 g;
    u8 b;
} Fragment16Color;
extern s32 D_82001EB0, D_82001EB4;
extern s32 D_82001EAC;
extern s32 D_82001CD4;
extern s16 D_82001C10[];
extern Fragment16Color D_82001CF0, D_82001CF4, D_82001CF8, D_82001CFC;
extern char D_82001D10[], D_82001D24[], D_82001D2C[];
extern void *func_8004C874(s32, s32);
extern void func_800496A4(s32, s32);
extern void func_8004972C(s32, s32, s32, s32);
extern void func_800495F8(s32, s32, s32, const char *, ...);
extern void func_800495BC(s32, s32, const char *, ...);
extern s32 func_80049148(s32, s32, const char *, ...);
extern void Ui_DrawGradientPanel(s32, s32, s32, s32, s32, s32);
extern void func_800498C4(void);
extern void func_800499EC(void);
extern void func_800226C0(s32);
extern void _bcopy(const void *, void *, s32);
void Fragment16_DrawVersionStamp(void) {
    s8 month[4];
    s8 day[4];
    s8 hour[4];
    s8 minute[4];

    _bcopy((u8 *)(u32)D_82001CD4, month, 2);
    if (month[0] == '0') {
        month[0] = month[1];
        month[1] = 0;
    }
    month[2] = 0;
    _bcopy((u8 *)(u32)D_82001CD4 + 2, day, 2);
    if (day[0] == '0') {
        day[0] = day[1];
        day[1] = 0;
    }
    day[2] = 0;
    _bcopy((u8 *)(u32)D_82001CD4 + 4, hour, 2);
    hour[2] = 0;
    _bcopy((u8 *)(u32)D_82001CD4 + 6, minute, 2);
    minute[2] = 0;
    func_800496A4(0x10, 0);
    func_8004972C(255, 255, 255, 255);
    func_800495F8(600, 50, 2, D_82001D10, month, day, hour, minute);
}
#endif

#ifdef VERSION_US
void Fragment16_DrawSelectionList(void) {
    s32 i;
    Fragment16Color top = D_82001CF0;
    Fragment16Color bottom = D_82001CF4;
    s16 *entry;
    s32 y;

    Ui_DrawGradientPanel(100, 30, 300, 420, (s32)&top, (s32)&bottom);
    func_800498C4();
    func_800496A4(8, 0);
    for (i = 0, entry = D_82001C10, y = 50; i < 19; i++, entry++, y += 20) {
        if (i == D_82001EAC) {
            func_8004972C(255, 255, 0, 255);
        } else {
            func_8004972C(255, 255, 255, 255);
        }
        func_800495BC(120, y, func_8004C874(0x42, *entry));
    }
    func_800499EC();
}
#endif

#ifdef VERSION_US
void Fragment16_DrawSelectionPopup(void) {
    char *name;
    char buffer[0x80];
    s32 width;

    name = func_8004C874(0x16, D_82001EB0 + 1);
    {
        Fragment16Color top = D_82001CF8;
        Fragment16Color bottom = D_82001CFC;
        if (name != NULL) {
            sprintf(buffer, D_82001D24, D_82001EB0, name);
        } else {
            sprintf(buffer, D_82001D2C, D_82001EB0);
        }
        width = func_80049148(8, 0, buffer);
        Ui_DrawGradientPanel(140, 140, width + 40, 60, (s32)&top, (s32)&bottom);
        func_800498C4();
        func_800496A4(8, 0);
        func_8004972C(255, 255, 255, 255);
        if (name != NULL) {
            func_800495BC(160, 160, buffer);
        } else {
            func_800495BC(160, 160, buffer);
        }
        func_800499EC();
    }
}
#endif

#ifdef VERSION_US
void func_82001304(void) {
    func_800498C4();
    if (D_82001CD4 != 0) {
        Fragment16_DrawVersionStamp();
    }
    func_800499EC();
}
#endif

#ifdef VERSION_US
extern void func_80007444(void *, s32, s32, s32, s32, s32);
extern void func_80006F70(void *, s32, s32, s32, s32);
// Scrolling ticker text: drawn twice side by side, moving left 2 px per frame
// and wrapping once a full copy has scrolled off.
void func_82001344(void) {
    static s32 sTickerX = 0xA0;
    char *text;
    s32 w;
    s32 x;
    s32 flag;

    if (func_800061EC() != 0) {
        return;
    }
    text = func_8004C874(0x16, 0);
    w = func_80049148(0x10, 0, text);
    x = sTickerX;
    flag = 0;
    if (D_82001EBC > 0 && D_82001EBE > 0) {
        func_80007444(&D_800D0510, *(s16 *)&D_82001EB8, *(s16 *)(&D_82001EB8 + 2), D_82001EBC, D_82001EBE, 1);
        flag = 1;
        func_80006F70(&D_800D0510, *(s16 *)&D_82001EB8, *(s16 *)(&D_82001EB8 + 2), D_82001EBC, D_82001EBE);
    }
    func_800498C4();
    func_800496A4(0x10, 0);
    func_800495BC(x, D_82001EC0, text);
    x += w + 0x78;
    func_800495BC(x, D_82001EC0, text);
    func_800499EC();
    sTickerX -= 2;
    if (sTickerX <= -w) {
        sTickerX += w + 0x78;
    }
    if (flag != 0) {
        func_80006F70(&D_800D0510, 0, 0, 0x280, 0x1E0);
    }
}
#endif

#ifdef VERSION_US
extern void *D_82001CD0;
extern s32 D_82001EC4;
extern s32 D_82001EC8;
extern s32 func_8006D268(s32);
extern void BgStage_DrawFrame(void);
extern void func_800503A4(void *);
extern void Fragment16_DrawFadingOverlay(void);
extern void func_82001344(void);
extern void Fragment16_DrawSelectionList(void);
extern void Fragment16_DrawSelectionPopup(void);
extern void func_82001304(void);
extern void func_80008648(void);
extern void func_820006B8(void);
void func_820014C4(void) {
    BgStage_DrawFrame();
    if (func_8006D268(0x202) != 0 && ((D_80087200->buttonsPressed) & 4) != 0) {
        (*(s16 *)((u8 *)&D_82001D58 + 4)) =
            (s16)((*(s16 *)((u8 *)&D_82001D58 + 4) + 1) % 3);
    }
    func_820006B8();
    func_800503A4(D_82001CD0);
    Fragment16_DrawFadingOverlay();
    func_82001344();
    if (D_82001EC4 != 0) {
        Fragment16_DrawSelectionList();
    }
    if (D_82001EC8 != 0) {
        Fragment16_DrawSelectionPopup();
    }
    func_82001304();
    func_80008648();
}
#endif

#ifdef VERSION_US
s32 Fragment16_HandleSelectionInput(void) {
    s32 result = 0;
    s32 previousSelection = D_82001EB0;
    if ((D_80087200->buttonsRepeat) & 0x200) {
        D_82001EB0--;
        if (D_82001EB0 < 0) {
            D_82001EB0 = D_82001EB4 - 1;
        }
    }
    if ((D_80087200->buttonsRepeat) & 0x100) {
        D_82001EB0++;
        if (D_82001EB0 >= D_82001EB4) {
            D_82001EB0 = 0;
        }
    }
    if (previousSelection != D_82001EB0) {
        func_800226C0(1);
    }
    if ((D_80087200->buttonsPressed) & 0x8000) {
        result = 1;
        func_800226C0(2);
    }
    if ((D_80087200->buttonsPressed) & 0x4000) {
        result = -1;
        func_800226C0(3);
    }
    return result;
}
#endif

#ifdef VERSION_US
extern s32 func_80025D44(void);
s32 func_82001688(void) {
    s32 result = 0;
    if (func_80025D44() == 0) {
        result = 1;
    } else if (func_8006D268(0x201) != 0 && ((D_80087200->buttonsPressed) & 2) != 0) {
        result = 1;
    }
    return result;
}
#endif

#ifdef VERSION_US
extern u16 D_82001EA2;
s32 Fragment16_HandleListInput(void) {
    s32 result = 0;
    s32 previousSelection;

    if ((D_82001EA2 & 2) || D_82001EC4 != 0) {
        if (D_82001EC4 != 0) {
            previousSelection = D_82001EAC;
            if ((D_80087200->buttonsRepeat) & 0x800) {
                if (--D_82001EAC < 0) {
                    D_82001EAC = 18;
                }
            }
            if ((D_80087200->buttonsRepeat) & 0x400) {
                if (++D_82001EAC >= 19) {
                    D_82001EAC = 0;
                }
            }
            if (previousSelection != D_82001EAC) {
                func_800226C0(1);
            }
        }
        if ((D_80087200->buttonsPressed) & 0x9000) {
            result = 1;
            func_800226C0(0x32);
        }
    }
    if (result == 0) {
        if (func_82001688() != 0) {
            result = -1;
            D_82001EAC = -1;
        }
    }
    return result;
}
#endif

#ifdef VERSION_US
s32 func_8200180C(void) {
    s32 result = 0;
    if (D_82001D58 == 0) result = 1;
    return result;
}
#endif

#ifdef VERSION_US
/* mkdraft:func_8200182C begin */
// Dispatches the fragment16 sequence: mode 0/1 run the intro handlers
// (func_82000098/func_8200180C, entering mode 2 on completion), mode 2 runs
// the list/selection input handlers (case 4's body sits before case 3's in the
// source because IDO lays case bodies out in source order and retail has
// func_82001590's body at 0x8200193C, before func_82001590-of-D_82001EA0's
// check at 0x82001988), and modes 3/5 finish the sequence through the fade.
// Case numbers are the jump-table targets of jtbl_82001D30.
// func_820016EC / func_82001590 are the linker aliases of
// Fragment16_HandleListInput / Fragment16_HandleSelectionInput
// (linker_scripts/us/aliases.ld); the alias spelling is used because the
// retail relocation symbols carry those names.
extern u8 D_82001C38[];
extern s32 D_82001EAC;
extern s32 func_820016EC();
extern s32 func_82001590();

s32 func_8200182C(s32 arg0) {
    s32 var_s0;
    u8 *temp_v0_3;
    s32 temp_v0;

    var_s0 = arg0;
    switch (arg0) {
        case 0:
            if (!StageContext_GetFadeMode()) {
                if (func_82000098()) {
                    var_s0 = 1;
                } else {
                    var_s0 = 2;
                    func_82000CB0();
                }
            }
            break;
        case 1:
            if (func_8200180C()) {
                var_s0 = 2;
                func_82000CB0();
            }
            break;
        case 2:
            switch (func_820016EC()) {
                case 1:
                    temp_v0_3 = (u8 *)(&D_82001C38) + (D_82001EAC << 3);
                    var_s0 = (*(s32 *)((u8 *)(temp_v0_3) + (4)));
                    switch (var_s0) {
                        case 5:
                            var_s0 = 3;
                            func_82000CE0();
                            break;
                        case 4:
                            D_82001EC8 = 1;
                            break;
                    }
                    break;
                case -1:
                    var_s0 = 5;
                    StageContext_SetClearColor(1);
                    StageFade_StartFromTransparent(5);
                    func_80035424(15);
                    break;
            }
            break;
        case 4:
            temp_v0 = func_82001590();
            if (temp_v0 == 1) {
                var_s0 = 5;
                StageContext_SetClearColor(1);
                StageFade_StartFromTransparent(5);
                func_80035424(15);
            } else if (temp_v0 == -1) {
                var_s0 = 2;
                D_82001EC8 = 0;
            }
            break;
        case 3:
            if (D_82001EA0 == 5) {
                var_s0 = 5;
                StageContext_SetClearColor(1);
                StageFade_StartFromTransparent(5);
                func_80035424(15);
            }
            break;
        case 5:
            if (StageContext_GetFadeMode() == 1) {
                var_s0 = 6;
            }
            break;
    }
    return var_s0;
}
/* mkdraft:func_8200182C end */
#endif

#ifdef VERSION_US
extern void Fragment16_UpdateGridFill();
extern void func_82000794();
extern void func_820014C4();
s32 func_8200182C(s32);
extern s32 D_82001D50;
void func_820019EC(void) {
    s32 temp_v0;
    s32 var_s1;

    var_s1 = 0;
    func_800086A4(2);
    StageFade_StartFromOpaque(0xA);
    do {
        func_80064D28();
        Fragment16_UpdateGridFill();
        func_82000794();
        func_820014C4();
        if (D_82001D50 != 0) {
            D_82001D50 -= 1;
        }
        temp_v0 = func_8200182C(var_s1);
        var_s1 = temp_v0;
    } while (temp_v0 != 6);
}
#endif

#ifdef VERSION_US
/* mkdraft:func_82001A78 begin */
extern s32 D_82001EAC;
extern s32 D_82001EB0;
extern s32 D_82001EC4;
s32 func_82001A78(void) {
    s32 result;

    if (D_82001EC4 != 0) {
        result = (D_82001EAC & 0xFF) << 8;
        result |= 2;
        result |= (D_82001EB0 & 0xFF) << 16;
    } else if (D_82001EAC == -1) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}
/* mkdraft:func_82001A78 end */
#endif

#ifdef VERSION_US
extern u8 D_82001ED0[];
extern u8 D_1000000[];
extern u8 D_446E30[], D_447D00[];
extern s32 func_82001A78(void);
extern void func_82000DE8(void);
extern s32 main_pool_push_state(s32);
extern s32 main_pool_pop_state(s32);
extern s32 func_80055948(s32);
extern void func_8005487C(void *);
extern void Gfx_InitDisplayListBuffers(s32, s32);
extern void Gfx_FreeDisplayListBuffers(void);
extern void *StageContext_Allocate(s8, s8, s8, s8, s8, s32);
extern s32 func_8004C09C(s32);
extern void func_8004C4B0(s32);
extern s32 func_8004C8C0(u16);
extern u8 *func_80047588(s32, s32);
extern u8 *Asset_LoadToSegment(s32, u8 *, u8 *, s32);
extern void func_80008514(s32);
extern void func_80008574(void);
extern void func_80047610(void);
extern void func_80051D64(s32, s32);
extern s32 func_80055028(void);
s32 fragment16_main(s32 arg0, s32 arg1) {
    s32 context;

    main_pool_push_state(0x5449544C);
    func_80055948(3);
    func_8005487C(D_82001ED0);
    Gfx_InitDisplayListBuffers(0x10000, 0);
    context = (s32)StageContext_Allocate(1, 0, 2, 0, 2, 1);
    func_8004C09C(0x107);
    func_8004C4B0(0x16);
    func_8004C4B0(0x41);
    func_8004C4B0(0x42);
    func_8004C8C0(0x13D);
    func_80047588(0x18, 0);
    Asset_LoadToSegment(((u32)D_1000000 & 0x0F000000) >> 24, D_446E30, D_447D00, 0);
    func_82000DE8();
    func_80008514(context);
    func_820019EC();
    func_80008574();
    func_80047610();
    Gfx_FreeDisplayListBuffers();
    func_80051D64(0x14, 0);
    func_80055028();
    main_pool_pop_state(0x5449544C);
    return func_82001A78();
}
#endif
