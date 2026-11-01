#include "global.h"


#ifdef VERSION_US
extern void func_81600A34(void *, void *, s32, s32, s32, s32, s32);
extern u8 *D_81407BB0;
void func_81400020(s32 arg0) {
    func_81600A34((void *)arg0, D_81407BB0, 0, 0, 0, 0x280, 0x1E0);
    func_81600A34((void *)arg0, D_81407BB0 + 1, 1, 0, 0x1A1, 0x230, 0x3F);
}

extern u8 *D_814077AC;
extern s32 func_81600DA8(void *, void *);
extern void func_81600F0C(void *, s32, s32, s32, s32);
extern void func_814025E8(s32, s32);
void func_81400098(s32 arg0) {
    if (func_81600DA8((void *)arg0, D_81407BB0) != 0) {
        func_81600F0C(D_81407BB0, 0, 0, 0x280, 0x1E0);
    } else {
        func_81600F0C(D_81407BB0, 0, 0x1A1, 0x230, 0x3F);
    }
    func_814025E8(
        ((u32)*(s32 *)(*(u8 **)((u8 *)(u32)D_814077AC + 0x844) + 0x40)) >> 31,
        *(s32 *)((u8 *)(u32)D_814077AC + 0x888)
    );
}

s32 main_pool_get_available();
s32 MainPool_AllocState(s32, s32);
extern void MainPool_FinalizeAllocation(s32);
extern void func_81406AAC(s32 *, s32);
extern void func_81406EA8(s32 *);
s32 func_81600E28(s32, s32, s32);
extern s32 D_814077A0;
extern u8 D_81407BB8;
void func_81400124(void) {
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = MainPool_AllocState(main_pool_get_available(), 0);
    sp1C = temp_v0;
    D_814077A0 = func_81600E28(temp_v0, 1, 0x12);
    MainPool_FinalizeAllocation(sp1C);
    func_81406AAC(&D_81407BB8, D_814077AC);
    func_81406EA8(&D_81407BB8);
}

extern void func_80008648();
extern void BgStage_DrawFrame();
extern void func_81400098(s32);
extern void func_81407118(u8 *, s32);
extern s32 D_814077B4;
extern s32 D_814077B8;
void func_81400194(void) {
    s32 temp_v0;

    BgStage_DrawFrame();
    temp_v0 = func_8000731C();
    D_814077B4 = D_814077B8;
    if (temp_v0 != 0) {
        D_814077B8 = (*(s32 *)((u8 *)(temp_v0) + (8)));
    } else {
        D_814077B8 = D_814077B4;
    }
    func_81400098(D_814077A0);
    func_81407118(&D_81407BB8, D_814077A0);
    func_80008648();
}

extern s32 D_814077A8;
extern s32 StageContext_GetFadeMode(void);
extern void StageFade_StartFromTransparent(s32);
extern s32 func_81407258(u8 *);
extern void func_80025CBC(s32);
s32 func_81400218(s32 arg0) {
    s32 result = arg0;
    s32 temp_v0;
    s32 temp_v1;
    switch (arg0) {
    case 0:
        if (StageContext_GetFadeMode() == 0) {
            result = 1;
        }
        break;
    case 1:
        temp_v0 = func_81407258(&D_81407BB8);
        if (temp_v0 != 0) {
            result = 2;
            StageFade_StartFromTransparent(5);
            temp_v1 = temp_v0;
            if (temp_v1 < 0) {
                func_80025CBC(5);
            }
            if (temp_v1 > 0) {
                D_814077A8 = 1;
            } else {
                D_814077A8 = 0;
            }
        }
        break;
    case 2:
        if (StageContext_GetFadeMode() == 1) {
            result = 3;
        }
        break;
    }
    return result;
}

extern void func_81400020(s32);
extern void func_81400194();
s32 func_81400218(s32);
extern void func_81406F44(u8 *, s32);
extern void func_81600954(void *);
extern void func_81600B30(s32);
extern void func_816018CC(s32);
void func_814002E8(void) {
    s32 temp_v0;
    s32 var_s1;

    var_s1 = 0;
    func_800086A4(2);
    StageFade_StartFromOpaque(3);
    func_80021ED8(0x1C);
    do {
        func_80064D28();
        func_816018CC(1);
        func_81600954((void *)D_814077A0);
        func_81400020(D_814077A0);
        func_81406F44(&D_81407BB8, D_814077A0);
        func_81600B30(D_814077A0);
        func_81400194();
        temp_v0 = func_81400218(var_s1);
        var_s1 = temp_v0;
    } while (temp_v0 != 3);
}

extern s32 func_8006CBB8(s32);
extern s32 func_8004D690(s32);
s32 func_81400398(void *arg0) {
    typedef struct { u8 pad_0034[0x34]; s16 kind; u8 pad_0036[4]; u16 value; } Header;
    typedef struct { u8 pad_0000[0x844]; Header *header; u8 pad_0848[0x54]; s16 value_89C; s16 value_89E; } State;
    u16 var_a1;
    s32 temp_v1;
    s32 temp_v0_2;
    Header *temp_v0;
    temp_v0 = ((State *)arg0)->header;
    temp_v1 = temp_v0->kind;
    var_a1 = temp_v0->value;
    switch (temp_v1) {
    case 6: {
        temp_v0_2 = func_8006CBB8(((State *)arg0)->value_89E);
        switch (temp_v0_2) {
        case 0: var_a1 = 0x1A; break;
        case 1: var_a1 = 0x1B; break;
        case 2: var_a1 = 0xD; break;
        }
        break;
    }
    case 0xE:
        var_a1 = 0x17;
        break;
    }
    temp_v1 = ((State *)arg0)->value_89C & 0xFF00;
    switch (temp_v1) {
    case 0x400: var_a1 = 0xE; break;
    case 0x500: var_a1 = 0x2E; break;
    }
    return func_8004D690(var_a1);
}

extern void main_pool_push_state(s32);
extern void main_pool_pop_state(s32);
extern void Gfx_InitDisplayListBuffers(s32, s32);
extern s32 StageContext_Allocate(s32, s32, s32, s32, s32, s32);
extern void func_8004C09C(s32);
extern void func_80047588(s32, s32);
extern void func_8004C8C0(s32);
extern void func_8160317C(void);
extern void func_814005B0(void);
extern void Asset_LoadToSegment(s32, u8 *, u8 *, s32);
extern void func_81400124(void);
extern void func_80008514(s32);
extern void func_814002E8(void);
extern void func_81407310(u8 *);
extern void func_80008574(void);
extern void func_8004C398(void);
extern void Gfx_FreeDisplayListBuffers(void);
extern u8 D_1000000[];
extern u8 D_446E30[];
extern u8 D_447D00[];
extern s32 D_814077A4;
extern s32 func_81400398(void *);
s32 fragment12_main(s32 arg0, s32 arg1) {
    s32 sp24;

    D_814077AC = (u8 *)(u32)arg1;
    D_814077A4 = *(s32 *)(D_814077AC + 0x840);
    main_pool_push_state(0x4F474E5A);
    Gfx_InitDisplayListBuffers(0x50000, 0);
    sp24 = StageContext_Allocate(1, 0, 2, 0, 2, 1);
    func_8004C09C(0x4F);
    D_81407BB0 = (u8 *)(u32)func_81400398(D_814077AC);
    func_80047588(0x1C, 0);
    func_8004C8C0(0x79);
    func_8160317C();
    func_814005B0();
    Asset_LoadToSegment(((u32)&D_1000000 & 0x0F000000) >> 24, &D_446E30, D_447D00, 0);
    func_81400124();
    func_80008514(sp24);
    func_814002E8();
    func_800086A4(3);
    if (D_814077A8 == 1) {
        func_81407310(&D_81407BB8);
    }
    func_80008574();
    func_8004C398();
    Gfx_FreeDisplayListBuffers();
    main_pool_pop_state(0x4F474E5A);
    return D_814077A8;
}

extern u8 *D_814077C0;
extern u8 *D_814077D0[];
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

M2C_UNK func_800476A0(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_800476FC(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_80047738(M2C_UNK, u8 *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8004C4B0(M2C_UNK);                     /* extern */
u8 *func_8004C990(M2C_UNK, M2C_UNK);                /* extern */
extern u8 *D_814077C4;
extern u8 *D_814077C8;
extern u8 *D_814077CC;
extern u8 *D_814077D4;
extern u8 *D_814077D8;
extern u8 *D_814077DC;
extern u8 *D_814077E0;
extern u8 *D_814077E4;
extern u8 *D_814077E8;
extern u8 *D_814077EC;
extern u8 *D_814077F0;
extern u8 *D_814077F4;
extern u8 *D_814077F8;
extern u8 *D_814077FC;
extern u8 *D_81407800;
extern u8 *D_81407804;
extern u8 *D_81407808;
extern u8 *D_8140780C;
extern u8 *D_81407810;
extern u8 *D_81407814;
extern u8 *D_81407818;
extern u8 *D_8140781C;
extern u8 *D_81407820;
extern u8 *D_81407824;
extern u8 *D_81407828;
extern M2C_UNK D_81420B20;

void func_814005B0(void) {
    func_8004C8C0(0x31);
    func_8004C4B0(0x11);
    func_8004C4B0(8);
    func_8004C4B0(0xC);
    func_8004C4B0(0xD);
    func_8004C4B0(6);
    func_8004C8C0(0x32);
    func_8004C8C0(0x3D);
    func_8004C8C0(0x3F);
    func_8004C8C0(0x3E);
    func_8004C8C0(0x40);
    func_8004C8C0(0x33);
    D_814077C0 = func_8004C990(0x3F, 0);
    D_814077C4 = func_8004C990(0x40, 0);
    D_814077C8 = func_8004C990(0x3E, 0);
    D_814077CC = func_8004C990(0x3E, 1);
    *D_814077D0 = func_8004C990(0x3D, 0);
    D_814077D4 = func_8004C990(0x3D, 1);
    D_814077D8 = func_8004C990(0x3D, 2);
    D_814077DC = func_8004C990(0x3D, 3);
    D_814077E8 = func_8004C990(0x3F, 4);
    D_814077EC = func_8004C990(0x3F, 7);
    D_814077F0 = func_8004C990(0x3F, 9);
    D_814077F4 = func_8004C990(0x3F, 0xA);
    D_814077F8 = func_8004C990(0x3F, 1);
    D_814077FC = func_8004C990(0x3F, 2);
    D_81407800 = func_8004C990(0x3F, 3);
    D_81407804 = func_8004C990(0x3F, 5);
    D_81407808 = func_8004C990(0x3F, 6);
    D_8140780C = func_8004C990(0x3F, 8);
    D_81407810 = func_8004C990(0x3F, 0xB);
    D_81407814 = func_8004C990(0x33, 1);
    D_81407818 = func_8004C990(0x33, 4);
    D_8140781C = func_8004C990(0x33, 6);
    D_81407820 = func_8004C990(0x33, 0);
    D_81407824 = func_8004C990(0x33, 3);
    D_81407828 = func_8004C990(0x33, 5);
    D_814077E0 = func_8004C990(0x32, 0);
    D_814077E4 = func_8004C990(0x32, 1);
    func_800476A0(&D_81420B20, 1);
    func_800476FC(&D_81420B20, 1);
    func_80047738(0, func_8004C990(0x31, 0), 0, 0);
}
extern Gfx *D_800D0510;
void Fragment11_DrawThickPanelFrame(s32, s32, s32, s32);
void func_81607B1C(s32, s32, s32, s32, f32, u8 *, u8 *);
void func_81607DB0(s32, s32, s32, s32, f32, u8 *, u8 *);
void func_81608918(s32, s32, f32 *);
void func_80006F70(Gfx **, s16, s16, s16, s16);
void func_800498C4(void);
void func_800499EC(void);
void func_800496A4(s32, s32);
void func_800495BC(s32, s32, const char *, ...);
void func_800495F8(s32, s32, s32, const char *, ...);
void *func_8004C874(s32, s32);
extern u8 D_8140782C[];
extern u8 D_81407830[];
extern u8 D_81407834[];
extern u8 D_81407837[];
extern u8 D_8140783C[];
extern u8 D_81407840[];
extern u8 D_81407844[];
extern u8 D_81407847[];

// Draw two choice rows and their heading with the large font.
// The caller supplies panel bounds and a transition fraction; the cursor updates its phase.
//@src/fragments/12/fragment12_E7C00.c
//@src/fragments/11/fragment11_D9DE0.c
void Fragment12_DrawChoicePanel(s32 x, s32 y, s32 width, s32 height, f32 transition, s32 translucent, s32 selected_row, f32 *cursor_phase) {
    const char *label_text;
    s32 inner_x;
    s32 inner_y;
    s32 inner_width;
    s32 inner_height;

    Fragment11_DrawThickPanelFrame(x, y, width, height);
    if (translucent != 0) {
        func_81607DB0(inner_x = x + 8, inner_y = y + 8, inner_width = width - 19, inner_height = height - 19,
                         transition, D_8140782C, D_81407830);
    } else {
        func_81607B1C(inner_x = x + 8, inner_y = y + 8, inner_width = width - 19, inner_height = height - 19,
                         transition, D_81407834, D_81407837);
    }
    if (!(transition > 0.1f)) {
        func_80006F70(&D_800D0510, (s16) inner_x, (s16) inner_y, (s16) inner_width, (s16) inner_height);
        func_800498C4();
        func_800496A4(16, 1);
        label_text = func_8004C874(17, 5);
        // The clipping bounds are no longer needed; reuse X for the label column.
        inner_x = x + 81;
        func_800495BC(inner_x, y + 48, label_text);
        func_800495BC(inner_x, y + 78, func_8004C874(17, 6));
        func_800495F8(x + 129, y + 16, 3, func_8004C874(17, 4));
        func_800499EC();
        // Reuse Y for the selected row offset before advancing the cursor phase.
        inner_y = selected_row * 30;
        func_81608918(x + 31, y + inner_y + 48, cursor_phase);
        func_80006F70(&D_800D0510, 0, 0, 640, 480);
    }
}

// Draw two choice rows and their heading with the compact font.
// The caller supplies panel bounds and a transition fraction; the cursor updates its phase.
//@src/fragments/12/fragment12_E7C00.c
//@src/fragments/11/fragment11_D9DE0.c
void Fragment12_DrawCompactChoicePanel(s32 x, s32 y, s32 width, s32 height, f32 transition, s32 translucent, s32 selected_row, f32 *cursor_phase) {
    const char *label_text;
    s32 inner_x;
    s32 inner_y;
    s32 inner_width;
    s32 inner_height;

    Fragment11_DrawThickPanelFrame(x, y, width, height);
    if (translucent != 0) {
        func_81607DB0(inner_x = x + 8, inner_y = y + 8, inner_width = width - 19, inner_height = height - 19,
                         transition, D_8140783C, D_81407840);
    } else {
        func_81607B1C(inner_x = x + 8, inner_y = y + 8, inner_width = width - 19, inner_height = height - 19,
                         transition, D_81407844, D_81407847);
    }
    if (!(transition > 0.1f)) {
        func_80006F70(&D_800D0510, (s16) inner_x, (s16) inner_y, (s16) inner_width, (s16) inner_height);
        func_800498C4();
        func_800496A4(8, 1);
        label_text = func_8004C874(17, 5);
        // The clipping bounds are no longer needed; reuse X for the label column.
        inner_x = x + 81;
        func_800495BC(inner_x, y + 40, label_text);
        func_800495BC(inner_x, y + 66, func_8004C874(17, 6));
        func_800495F8(x + 14, y + 14, 0, func_8004C874(17, 4));
        func_800499EC();
        // Reuse Y for the selected row offset before advancing the cursor phase.
        inner_y = selected_row * 26;
        func_81608918(x + 31, y + inner_y + 40, cursor_phase);
        func_80006F70(&D_800D0510, 0, 0, 640, 480);
    }
}

void func_8004989C(s32);
s32 func_800472E0(u8 *);
s32 func_8004C594(s32, s32);
void *func_8004C8A0(void *, s32, s32, s32);
extern u8 D_8140784C[];
extern u8 D_81407850[];
extern u8 D_81407854[];
extern u8 D_81407857[];
extern u8 D_8140785C[];
extern u8 D_81407860[];
extern u8 D_81407864[];
extern u8 D_81407867[];
extern u8 D_8140786C[];
extern u8 D_81407870[];
extern u8 D_81407874[];
extern u8 D_81407877[];
// Draw table 17 message 8; messages shorter than two lines start 15 pixels lower.
//@src/fragments/12/fragment12_E7C00.c
//@src/fragments/11/fragment11_D9DE0.c
void Fragment12_DrawMessagePanel(s32 x, s32 y, s32 width, s32 height, f32 transition, s32 translucent) {
    u8 *message;
    s32 line_offset;

    message = func_8004C874(17, 8);
    if (func_800472E0(message) >= 2) {
        line_offset = 0;
    } else {
        line_offset = 15;
    }
    Fragment11_DrawThickPanelFrame(x, y, width, height);
    if (translucent != 0) {
        func_81607DB0(x + 8, y + 8, width - 19, height - 19,
                         transition, D_8140784C, D_81407850);
    } else {
        func_81607B1C(x + 8, y + 8, width - 19, height - 19,
                         transition, D_81407854, D_81407857);
    }
    if (!(transition > 0.1f)) {
        func_80006F70(&D_800D0510, (s16)(x + 8), (s16)(y + 8), (s16)(width - 19), (s16)(height - 19));
        func_800498C4();
        func_800496A4(16, 1);
        func_8004989C(30);
        func_800495F8(x + 85, y + line_offset + 16, 3, (const char *)message);
        func_800499EC();
        func_80006F70(&D_800D0510, 0, 0, 640, 480);
    }
}

// Format value slot 3 into table 17 message 7, then draw it inside the panel.
//@src/fragments/12/fragment12_E7C00.c
//@src/fragments/11/fragment11_D9DE0.c
void Fragment12_DrawValueMessagePanel(s32 x, s32 y, s32 width, s32 height, s32 value, f32 transition, s32 translucent) {
    char formatted_text[128];

    Fragment11_DrawThickPanelFrame(x, y, width, height);
    if (translucent != 0) {
        func_81607DB0(x + 8, y + 8, width - 19, height - 19,
                         transition, D_8140785C, D_81407860);
    } else {
        func_81607B1C(x + 8, y + 8, width - 19, height - 19,
                         transition, D_81407864, D_81407867);
    }
    if (!(transition > 0.1f)) {
        func_8004C594(3, value);
        func_8004C8A0(formatted_text, 128, 17, 7);
        func_80006F70(&D_800D0510, (s16)(x + 8), (s16)(y + 8), (s16)(width - 19), (s16)(height - 19));
        func_800498C4();
        func_800496A4(16, 1);
        func_8004989C(30);
        func_800495F8(x + 129, y + 16, 3, formatted_text);
        func_800499EC();
        func_80006F70(&D_800D0510, 0, 0, 640, 480);
    }
}

// Format value slot 3 into table 17 message 7, then draw it inside the panel.
//@src/fragments/12/fragment12_E7C00.c
//@src/fragments/11/fragment11_D9DE0.c
void Fragment12_DrawCompactValueMessagePanel(s32 x, s32 y, s32 width, s32 height, s32 value, f32 transition, s32 translucent) {
    char formatted_text[128];

    Fragment11_DrawThickPanelFrame(x, y, width, height);
    if (translucent != 0) {
        func_81607DB0(x + 8, y + 8, width - 19, height - 19,
                         transition, D_8140786C, D_81407870);
    } else {
        func_81607B1C(x + 8, y + 8, width - 19, height - 19,
                         transition, D_81407874, D_81407877);
    }
    if (!(transition > 0.1f)) {
        func_8004C594(3, value);
        func_8004C8A0(formatted_text, 128, 17, 7);
        func_80006F70(&D_800D0510, (s16)(x + 8), (s16)(y + 8), (s16)(width - 19), (s16)(height - 19));
        func_800498C4();
        func_800496A4(8, 1);
        func_8004989C(26);
        func_800495F8((width / 2) + x, y + 14, 3, formatted_text);
        func_800499EC();
        func_80006F70(&D_800D0510, 0, 0, 640, 480);
    }
}

extern u8 *D_814077D0[];
extern s32 func_8004D1FC(u8 *);
void func_81401178(s32 arg0) {
    s32 var_v0;
    if (arg0 >= 0) {
        var_v0 = arg0;
    } else {
        var_v0 = 0;
    }
    func_8004D1FC(D_814077D0[var_v0]);
}

/* mkdraft:func_814011B4 begin */
extern u8 *D_814077D0[];
extern Gfx *D_800D0510;
extern void func_81602240(f32, f32, f32, f32, s32, s32, f32, f32);



void func_814011B4(s32 arg0, s32 arg1, f32 arg2, f32 arg3) {
    f32 d;
    f32 w;
    f32 s;
    s32 pad[2]; // FAKE: reserves the target's 0x40-byte frame; diff score 50 without it.
    volatile f32 sp28; // FAKE: forces arg1 to stay in memory across the bounds tests; diff score 395 without the volatility.

    d = ((f32) * (u16 *)(D_814077D0[0] + 2) * arg2 * 0.5f) + 1.0f;
    if (!((f32) arg0 < -d)) {
        sp28 = (f32) arg1;
        if (!(sp28 < -d) && !((640.0f + d) < (f32) arg0) && !((480.0f + d) < sp28)) {
            {
                Gfx *_g = D_800D0510++;
                _g->words.w0 = 0xFB000000;
                _g->words.w1 = ((u32) (255.0f * arg3) & 0xFF) | ~0xFF;
            }
            s = 1.0f / arg2;
            w = 2.0f * d;
            func_81602240((f32) arg0 - d, sp28 - d, w, w, 0, 0, s, s);
        }
    }
}
/* mkdraft:func_814011B4 end */

extern Gfx *D_800D0510;
extern u8 *D_814077C0;
extern u8 D_80094E38[];
void func_81401394(void) {
    func_8004D1FC(D_814077C0);
    gSPDisplayList(D_800D0510++, D_80094E38);
    gDPSetCombine(D_800D0510++, 0xFFB3FF, 0xFF65FEFF);
}

extern void func_81602240(f32, f32, f32, f32, s32, s32, f32, f32);
// Eight-byte header at the start of a texture returned by func_8004C990; same
// layout as TextureRenderHeader in src/4CC20.c.
//@src/4CC20.c
typedef struct TextureRenderHeader {
    u16 width;
    u16 height;
    u8 format;
    u8 size;
    u16 unk_06;
} TextureRenderHeader;

void func_81401404(s32 arg0, s32 arg1, f32 arg2) {
    TextureRenderHeader *texture;
    f32 width;
    f32 height;

    texture = (TextureRenderHeader *)D_814077C0;
    width = texture->width * arg2;
    height = texture->height * arg2;
    func_81602240(arg0 - width * 0.5f, arg1 - height * 0.5f, width, height, 0, 0, 1.0f / arg2, 1.0f / arg2);
}

/* mkdraft:func_814014C8 begin */
extern Gfx *D_800D0510;
extern Gfx *Gfx_AllocDisplayList(s32);
extern void Gfx_SetVertexAttributes(Vtx *, s16, s16, s16, s16, s16, u8, u8, u8, u8);
extern void func_816083A4(void);



void func_814014C8(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, u8 *arg6, u8 *arg7) {
    Vtx *vtx;

    vtx = Gfx_AllocDisplayList(sizeof(Vtx) * 4);
    func_816083A4();
    if (arg5 != 0) {
        Gfx_SetVertexAttributes(&vtx[0], (s16)arg1, (s16)arg2, -1, 0, ((u16 *)arg0)[1] << 5, arg6[0], arg6[1], arg6[2], 0xFF);
        Gfx_SetVertexAttributes(&vtx[1], (s16)(arg1 + arg3), (s16)arg2, -1, ((u16 *)arg0)[0] << 5, ((u16 *)arg0)[1] << 5, arg6[0], arg6[1], arg6[2], 0xFF);
        Gfx_SetVertexAttributes(&vtx[2], (s16)arg1, (s16)(arg2 + arg4), -1, 0, 0, arg7[0], arg7[1], arg7[2], 0xFF);
        Gfx_SetVertexAttributes(&vtx[3], (s16)(arg1 + arg3), (s16)(arg2 + arg4), -1, ((u16 *)arg0)[0] << 5, 0, arg7[0], arg7[1], arg7[2], 0xFF);
    } else {
        Gfx_SetVertexAttributes(&vtx[0], (s16)arg1, (s16)arg2, -1, 0, 0, arg6[0], arg6[1], arg6[2], 0xFF);
        Gfx_SetVertexAttributes(&vtx[1], (s16)(arg1 + arg3), (s16)arg2, -1, ((u16 *)arg0)[0] << 5, 0, arg6[0], arg6[1], arg6[2], 0xFF);
        Gfx_SetVertexAttributes(&vtx[2], (s16)arg1, (s16)(arg2 + arg4), -1, 0, ((u16 *)arg0)[1] << 5, arg7[0], arg7[1], arg7[2], 0xFF);
        Gfx_SetVertexAttributes(&vtx[3], (s16)(arg1 + arg3), (s16)(arg2 + arg4), -1, ((u16 *)arg0)[0] << 5, ((u16 *)arg0)[1] << 5, arg7[0], arg7[1], arg7[2], 0xFF);
    }
    gDPPipeSync(D_800D0510++);
    gSPTexture(D_800D0510++, 0xFFFF, 0xFFFF, 0, 0, 1);
    gDPSetCycleType(D_800D0510++, G_CYC_1CYCLE);
    gSPClearGeometryMode(D_800D0510++, G_ZBUFFER | G_LIGHTING);
    gDPSetCombine(D_800D0510++, 0xFC40C281, 0xFF87FFFF);
    gDPSetRenderMode(D_800D0510++, 0x0F0A4000, 0);
    gSPVertex(D_800D0510++, (u32)vtx & 0x1FFFFFFF, 4, 0);
    gSP2Triangles(D_800D0510++, 0, 2, 3, 0, 0, 3, 1, 0);
}
/* mkdraft:func_814014C8 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/12/fragment12_E5330/func_814018F4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/12/fragment12_E5330/func_81401DB0.s")

extern u8 D_80094F50[];
void func_8140225C(s32 x, s32 y, s32 mode, u8 type) {
    u8 *image;

    image = D_81407810;
    switch (type) {
        case 1: image = D_814077E8; break;
        case 2: image = D_814077EC; break;
        case 4: image = D_814077F0; break;
        case 8: image = D_814077F4; break;
        case 3: image = D_814077F8; break;
        case 5: image = D_814077FC; break;
        case 9: image = D_81407800; break;
        case 6: image = D_81407804; break;
        case 10: image = D_81407808; break;
        case 12: image = D_8140780C; break;
    }
    gSPDisplayList(D_800D0510++, D_80094E38);
    func_8004D1FC(image);
    gDPSetEnvColor(D_800D0510++, 0, 0, 0, 255);
    if (mode != 0) {
        func_81602240(x, y,
            *(u16 *)(image + 0),
            *(u16 *)(image + 2),
            *(u16 *)(image + 0),
            *(u16 *)(image + 2),
            -1.0f, -1.0f);
    } else {
        func_81602240(x, y,
            *(u16 *)(image + 0),
            *(u16 *)(image + 2),
            0, 0,
            1.0f, 1.0f);
    }
    gSPDisplayList(D_800D0510++, D_80094F50);
}

extern u8 D_80094F50[];

// Draws texture `index` of the consecutive pointers D_81407814..D_81407828, which
// func_814005B0 fills from func_8004C990(0x33, n), at (x, y) using the width and
// height in the texture header's first two u16 fields. func_8004D1FC loads it:
//@src/4CC20.c
void func_814024B4(s32 x, s32 y, s32 index) {
    gSPDisplayList(D_800D0510++, D_80094E38);
    gDPSetRenderMode(D_800D0510++, 0x0F0A7008, 0);
    func_8004D1FC((&D_81407814)[index]);
    func_81602240(x, y, *(u16 *)(&D_81407814)[index], *(u16 *)((&D_81407814)[index] + 2), 0, 0, 1.0f, 1.0f);
    gSPDisplayList(D_800D0510++, D_80094F50);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/12/fragment12_E5330/func_814025E8.s")

s32 func_814028A0(s32 arg0) {
    return (s32) (((((f32) arg0 + 0.5f) * 22.0f) + 17.0f) - 6.0f);
}
#endif
