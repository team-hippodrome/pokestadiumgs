#include "global.h"


#ifdef VERSION_US
s32 func_8130CE30(u8 *arg0) {
    return *(s32 *)(arg0 + 0x5C) != 0;
}

extern s32 func_81601FA0(u8);
extern s32 func_81601980(s32 *, s32);
extern void func_81601D24(s32, s32);
extern f32 func_816092FC(void);
extern s32 func_8130CE30(u8 *);
s32 func_8130CE3C(u8 *arg0) {
    s32 result;
    u8 selector;
    if (arg0[0x35] == 1) {
        return 0;
    }
    selector = arg0[0x39];
    if (selector == 0) {
        return 0;
    }
    result = func_81601FA0(selector) == 0;
    if (result == 0) {
        result = func_81601980((s32 *)(arg0 + 0x3C), arg0[0x39]) != 0;
    }
    return result;
}

extern s32 func_81601FA0(u8);
extern s32 func_81601980(s32 *, s32);
extern void func_81601D24(s32, s32);
extern f32 func_816092FC(void);
extern s32 func_8130CE30(u8 *);
s32 func_8130CEAC(u8 *arg0) {
    s32 result;
    if ((arg0[0x35] == 1) || (func_8130CE30(arg0) == 0)) {
        result = 2;
    } else {
        result = 3;
    }
    return result;
}

/* Overlay rectangle filled from an eased window-close progress: arg0 carries
 * the s16 origin (+8/+0xA) and the close progress at +0x2C, which the
 * func_8130F09C update in this file drives toward 1.0f. D_8160BD18 and
 * D_8160BD1C are the easing function-pointer tables shared with the matched
 * grid code (Fragment14_ComputeGridRectangles in fragment14_FF070.c); the
 * rectangle layout and the trailing func_816072FC finalize call match
 * func_8130D45C below, which fills the same struct without easing. */

extern f32 (*D_8160BD18)(f32);
extern f32 (*D_8160BD1C)(f32);
extern void func_816072FC(void *arg0);
typedef struct unk_func_8130D45C {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    s16 unk_06;
} unk_func_8130D45C;

/* mkdraft:func_8130CEF0 begin */
extern f32 (*D_8160BD18)(f32);
extern f32 (*D_8160BD1C)(f32);
extern void func_816072FC(void *arg0);


f32 func_8130CEF0(u8 *arg0, u8 *arg1) {
    f32 scale;
    f32 a;
    f32 b;
    u8 *ptr;

    scale = 1.0f;
    if (*(f32 *)(arg0 + 0x2C) < 1) {
        if (arg0[0x34] == 3 && *(s8 *)(arg0 + 0x36) == 0) {
            ptr = arg0 + 0x14;
        } else {
            ptr = arg0 + 0x1C;
        }
        scale = *(f32 *)(arg0 + 0x2C) / 1;
        a = D_8160BD18(scale);
        b = D_8160BD1C(scale);
        *(s16 *)(arg1 + 0) = *(s16 *)ptr + (*(s16 *)(arg0 + 8) - *(s16 *)ptr) * a;
        *(s16 *)(arg1 + 2) = *(s16 *)(ptr + 2) + (*(s16 *)(arg0 + 0xA) - *(s16 *)(ptr + 2)) * b;
        *(s16 *)(arg1 + 4) = *(s16 *)(ptr + 4) + (0x224 - *(s16 *)(ptr + 4)) * a;
        *(s16 *)(arg1 + 6) = *(s16 *)(ptr + 6) + (0xC7 - *(s16 *)(ptr + 6)) * b;
    } else {
        *(s16 *)(arg1 + 0) = *(s16 *)(arg0 + 8);
        *(s16 *)(arg1 + 2) = *(s16 *)(arg0 + 0xA);
        *(s16 *)(arg1 + 4) = 0x224;
        *(s16 *)(arg1 + 6) = 0xC7;
    }
    func_816072FC(arg1);
    return scale;
}
/* mkdraft:func_8130CEF0 end */

f32 func_8130D098(u8 *arg0, unk_func_8130D45C *arg1) {
    f32 progress;
    f32 scale;

    progress = *(f32 *)(arg0 + 0x2C);
    scale = 1.0f;
    /* FAKE: division by 1. Keep the divisor int-spelled: IDO lowers progress / 1.0f to a multiply
     * (same lowering as the / 16 in Fragment14_InterpolatePanelRectangle,
     * //@src/fragments/14/fragment14_FCD40.c). */
    if (progress < 1) {
        scale = progress / 1;
    }
    /* The double adds keep the integer base as the left operand; writing the
     * product first flips add.d's operands and rotates the FPU temp
     * assignment of every statement after these two. */
    arg1->unk_00 = (s16)(s32)(*(s16 *)(arg0 + 8) + 27 + (1.0f - D_8160BD18(scale)) * 36.5);
    arg1->unk_02 = (s16)(s32)(*(s16 *)(arg0 + 10) + 37 + (1.0f - D_8160BD1C(scale)) * 36.5);
    arg1->unk_04 = (s16)(s32)(D_8160BD18(scale) * 73.0f);
    arg1->unk_06 = (s16)(s32)(D_8160BD1C(scale) * 73.0f);
    func_816072FC(arg1);
    return scale;
}
extern void func_8160945C(void *, const s16 *, const s16 *, f32);
f32 func_8130D1FC(u8 *arg0, unk_func_8130D45C *arg1) {
    f32 t;
    const s16 colors[4][4] = {
        { 401, 0, 147, 146 },
        { 401, 0, 147, 49 },
        { 474, 73, 0, 0 },
        { 474, 24, 0, 0 },
    };
    s32 row;

    // Retail divides the progress by 1, like func_8130D098; a float 1.0f divisor becomes a multiply.
    t = *(f32 *)(arg0 + 0x2C) / 1;
    row = arg0[0x35] >= 2;
    func_8160945C(arg1, colors[row + 2], colors[row], t);
    arg1->unk_00 += *(s16 *)(arg0 + 8);
    arg1->unk_02 += *(s16 *)(arg0 + 0xA);
    if (arg0[0x35] < 2 && arg0[0x34] >= 5) {
        arg1->unk_06 += D_8160BD1C(*(f32 *)(arg0 + 0x30) / 12.0f) * 53.0f;
    }
    func_816072FC(arg1);
    return t;
}


extern void func_816072FC(void *arg0);
f32 func_8130D340(u8 *arg0, unk_func_8130D45C *arg1) {
    f32 t;
    f32 w;
    f32 h;

    if (*(f32 *)(arg0 + 0x30) < 12.0f) {
        t = *(f32 *)(arg0 + 0x30) / 12.0f;
    } else {
        t = 1.0f;
    }
    w = D_8160BD18(t);
    h = D_8160BD1C(t);
    arg1->unk_04 = 302.0f * w;
    arg1->unk_06 = 135.0f * h;
    arg1->unk_00 = *(s16 *)(arg0 + 8) + (302 - arg1->unk_04) / 2 + 246;
    arg1->unk_02 = *(s16 *)(arg0 + 0xA) + (135 - arg1->unk_06) / 2;
    func_816072FC(arg1);
    return t;
}


extern void func_8160732C(void* arg0, void* arg1);
extern void func_8160724C(s16* arg0, s16* arg1);
extern void func_816072FC(void* arg0);

void func_8130D45C(u8* arg0, unk_func_8130D45C* arg1, unk_func_8130D45C* arg2) {
    unk_func_8130D45C var_sp18;

    var_sp18 = *arg2;
    func_8160732C(&var_sp18, arg2);
    arg1->unk_00 = *(s16*)(arg0 + 8) + 157;
    arg1->unk_02 = *(s16*)(arg0 + 10) + 112;
    arg1->unk_04 = 72;
    arg1->unk_06 = 72;
    func_8160724C((s16*)arg1, (s16*)&var_sp18);
    func_816072FC(arg1);
}

// Tables func_8130D4E0 (still assembly) reads.
const s16 D_81312750[4] = { 24, 48, 24, 0 };
const s16 D_81312758[4] = { 0, 24, 48, 24 };
const u16 D_81312760[4] = { 6, 5, 3, 4 };
extern Gfx *D_800D0510;
extern Gfx D_80094E38[];
extern Gfx D_80094F50[];
extern f32 func_816092FC(void);
extern f32 func_8160BCB0(f32, f32);
extern s32 func_8004C990(s32, s32);
extern void func_8004D19C(s32, s32, s32, s32, s32);
void func_8130D4E0(u8 *arg0, s16 *pos) {
    static f32 D_813120B0 = 0.0f;
    s32 i;
    s32 blink;

    D_813120B0 += func_816092FC();
    gSPDisplayList(D_800D0510++, D_80094E38);
    for (i = 0; i < 4; i++) {
        blink = (i == *(s8 *)(arg0 + 0x38)) && (func_8160BCB0(D_813120B0, 32.0f) > 16.0f);
        if (blink) {
            gDPSetEnvColor(D_800D0510++, 0x80, 0x80, 0x80, 0xFF);
        }
        func_8004D19C(pos[0] + D_81312750[i], pos[1] + D_81312758[i], func_8004C990(51, D_81312760[i]), 1, 0);
        if (blink) {
            gDPSetEnvColor(D_800D0510++, 0xFF, 0xFF, 0xFF, 0xFF);
        }
    }
    gSPDisplayList(D_800D0510++, D_80094F50);
}


// The highlight color func_8130E99C packs and func_8130D6A4 (still assembly) reads, then the
// data of the still-assembly func_8130D6A4 and func_8130DEB8.
u8 D_813120B4[4] = { 0x64, 0x96, 0xFF, 0x00 };
s32 D_813120B8[3] = { 0x1C, 0x1E00, 0x9600 };
s32 D_813120C4 = 100;
s32 D_813120C8 = 100;
s32 D_813120CC = 100;
s32 D_813120D0 = 100;
s32 D_813120D4 = 100;

extern void Fragment11_DrawThickPanelFrame(s32, s32, s32, s32);
extern void func_81607B1C(s32, s32, s32, s32, f32, u8 *, u8 *);
extern void func_816073A0(void *);
extern void GfxRect_DrawTextured(s16, s16, s16, s16, s16, s16, s16, s16, s32);
extern void func_81607408(void);



void func_8130D6A4(u8 *arg0) {
    f32 opacity;
    unk_func_8130D45C rect;
    s32 start_y;
    s32 text_y;
    s32 i;
    s32 count;
    s32 *stride;
    start_y = *(s16 *)(arg0 + 8) + 0x1B;
    text_y = *(s16 *)(arg0 + 0xA) + 0x25;
    opacity = 1.0f - func_8130D098(arg0, &rect);
    Fragment11_DrawThickPanelFrame(rect.unk_00, rect.unk_02, rect.unk_04, rect.unk_06);
    func_81607B1C(rect.unk_00 + 8, rect.unk_02 + 8, rect.unk_04 - 0x13, rect.unk_06 - 0x13, opacity, D_813120B4,
                  D_813120B4);
    if (*(s32 *)(arg0 + 0x60) != 0 && opacity < 0.1f) {
        func_816073A0(&rect);
        gSPDisplayList(D_800D0510++, D_80094E38);
        gDPSetAlphaCompare(D_800D0510++, G_AC_NONE);
        gDPSetRenderMode(D_800D0510++, 0, 0x0F0A7008);
        /* Blit the 56-column texture at +0x60 one strip per step: strip i starts at
         * row i (0x70 bytes per row) and covers MIN(0x37 - i, stride) rows, drawn
         * 54 columns wide at (start_y + 8, text_y + i + 7). */
        stride = D_813120B8;
        for (i = 1; i < 0x37; i += stride[0]) {
            count = MIN(0x37 - i, stride[0]);
            gDPLoadTextureBlock(D_800D0510++, (u8 *)(*(u32 *)(arg0 + 0x60)) + (i * 0x70) + 2, G_IM_FMT_RGBA,
                                G_IM_SIZ_16b, 56, count, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                                G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            GfxRect_DrawTextured((s16)(start_y + 8), (s16)(text_y + i + 7), 0x36, (s16)count, 0x20, 0, 0x400, 0x400,
                                 0);
        }

        gSPDisplayList(D_800D0510++, D_80094F50);
        func_81607408();
    }
}

/* mkdraft:func_8130DA04 begin */
extern void func_816048E0(s32, s32, s32, s32, f32);

void func_8130DA04(u8 *arg0, void *arg1) {
    unk_func_8130D45C rectangle;
    f32 fade;
    s32 origin_x;
    s32 origin_y;
    // FAKE: never read. The extra stack slot moves the origin_y + lift temp that
    // func_8004D19C and the last func_800495BC share to the retail sp+0x3C; without
    // this declaration that temp is spilled at sp+0x40 (diff score 8).
    s32 lower_y;
    s32 index;
    s32 lift;
    void *label;

    fade = 1.0f - func_8130D1FC(arg0, &rectangle);
    origin_x = *(s16 *)(arg0 + 8) + 0x191;
    origin_y = *(s16 *)(arg0 + 0xA);
    if (func_81600DA8(arg1, arg0 + 1) != 0) {
        func_816048E0(rectangle.unk_00, rectangle.unk_02, rectangle.unk_04, rectangle.unk_06, fade);
        if (!(fade > 0.1f)) {
            func_816073A0(&rectangle);
            if (arg0[0x35] < 2) {
                lift = 0;
                if (arg0[0x34] >= 5) {
                    fade = D_8160BD18(*(f32 *)(arg0 + 0x30) / 12.0f);
                    lift = 28.0f * fade;
                }
                func_81608918(origin_x + 0x13, *(s8 *)(arg0 + 0x36) * 0x15 + origin_y + 0x26, (f32 *)(arg0 + 0x28));
                gSPDisplayList(D_800D0510++, D_80094E38);
                func_8004D19C(origin_x + 0xE, (origin_y + lift) + 0x6C, func_8004C990(0x33, 2), 0, 0);
                func_8004D19C(origin_x + 0xE, origin_y + 0xA2, func_8004C990(0x33, 1), 0, 0);
                gSPDisplayList(D_800D0510++, D_80094F50);
                func_800498C4();
                func_800496A4(4, 1);
                label = func_8004C874(0xF, arg0[0x35] + 1);
                func_800496A4(4, 1);
                func_800495BC(origin_x - func_80049148(4, 1, label) / 2 + 0x49, origin_y + 0xE, label);
                index = 0;
                if (func_8130CEAC(arg0) > 0) {
                    do {
                        if (index == *(s8 *)(arg0 + 0x36)) {
                            func_8004972C(0xFF, 0xFF, 0, 0xFF);
                        } else if (index == 0 && func_8130CE3C(arg0) != 0) {
                            func_8004972C(0x80, 0x80, 0x80, 0xFF);
                        } else {
                            func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
                        }
                        switch (index) {
                        case 0:
                            func_800495BC(origin_x + 0x45, origin_y + 0x26 + index * 0x15, func_8004C874(0xF, 4));
                            break;
                        case 1:
                            func_800495BC(origin_x + 0x45, origin_y + 0x26 + index * 0x15, func_8004C874(0xF, 5));
                            break;
                        case 2:
                            func_800495BC(origin_x + 0x45, origin_y + 0x26 + index * 0x15, func_8004C874(0xF, 6));
                            break;
                        }
                        index++;
                    } while (index < func_8130CEAC(arg0));
                }
                func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
                func_800495BC(origin_x + 0x27, (origin_y + lift) + 0x70, func_8004C874(0xF, 7));
                func_800495BC(origin_x + 0x27, origin_y + 0xA6, func_8004C874(0xF, 8));
                func_800499EC();
            } else {
                gSPDisplayList(D_800D0510++, D_80094E38);
                func_8004D19C(origin_x + 0xE, origin_y + 0xB, func_8004C990(0x33, 2), 0, 0);
                gSPDisplayList(D_800D0510++, D_80094F50);
                func_800498C4();
                func_800496A4(4, 1);
                func_800495BC(origin_x + 0x27, origin_y + 0xF, func_8004C874(0xF, 7));
                func_800499EC();
            }
            func_81607408();
        }
    }
}
/* mkdraft:func_8130DA04 end */

extern void func_80006F70(Gfx **, s16, s16, s16, s16);
extern void func_81605908(s32, s32, s32, s32, s32 *);
extern void func_81605950(void);
extern void func_816059CC(s32, s32, s32, s32, s32 *);
extern s32 *func_80062CE0(u8);
extern u8 func_80062D98(u8);
extern void func_81603C84(s32, s32, s32);
extern void func_800495F8(s32, s32, s32, const char *, ...);
extern s32 func_816087C8(u8 *);
extern void *func_8004B7A4(s32);
extern s32 func_8130CE3C(u8 *);
extern u8 func_8006397C(s32);
extern s32 func_80063270(u8);
extern u8 func_800639C0(s32);
extern void func_81607408(void);
extern void func_8130D4E0(u8 *, s16 *);
extern void func_8130D6A4(u8 *);
extern void func_8130DA04(u8 *, void *);
extern f32 func_8130D340(u8 *, unk_func_8130D45C *);
extern void func_81606304(s32, s32, s32, s32, s32);
extern void func_81602DA4(s32);
extern s32 D_813120C4, D_813120C8, D_813120CC, D_813120D0, D_813120D4;
extern Gfx D_80094E38[], D_80094F50[];
extern const s32 D_813127C0[4];
extern const s32 D_813127D0[];
void func_8130DEB8(u8 *arg0, void *arg1) {
    s32 flag;
    s32 i;
    s32 x;
    s32 y;
    u8 *data;
    void *lbl;
    unk_func_8130D45C rect;
    unk_func_8130D45C rect2;
    f32 fade;
    s32 w;
    s32 xo1;
    void *lbl2;
    void *name;
    s32 xo;

    flag = 0;
    x = *(s16 *)(arg0 + 8);
    y = *(s16 *)(arg0 + 0xA);
    data = *(u8 **)(arg0 + 0x6C);
    fade = 1.0f - func_8130CEF0(arg0, (u8 *)&rect);
    func_8130D45C(arg0, &rect2, &rect);
    if (arg0[0x34] == 0) {
        return;
    }
    if (func_81600DA8(arg1, arg0) != 0) {
        if (*(u8 **)(arg0 + 0x5C) != NULL) {
            if ((*(u8 **)(arg0 + 0x5C))[0x87] == 1 || (*(u8 **)(arg0 + 0x5C))[0x87] == 2 || (*(u8 **)(arg0 + 0x5C))[0x87] == 3) {
                flag = 1;
            }
        }
        func_816048E0(rect.unk_00, rect.unk_02, rect.unk_04, rect.unk_06, fade);
        func_80006F70(&D_800D0510, rect.unk_00 + 8, rect.unk_02 + 8, rect.unk_04 - 0x13, rect.unk_06 - 0x13);
        if (fade <= 0.1f && data[0] > 0 && data[0] < 0xFC) {
            func_81605908(x + 0x95, y + 0x74, 0x40, 0x40, &D_813120C4);
            func_81605950();
            if (func_8130CE30(arg0)) {
                func_816059CC(x + 0x192, y + 0x8B, 0x89, 0x33, &D_813120CC);
            }
            func_816059CC(x + 0x66, y + 0x24, 0x98, 0x4B, &D_813120C8);
            func_816059CC(x + 0x103, y + 0x20, 0x83, 0x6C, &D_813120D0);
            func_816059CC(x + 6, y + 0xA, 0x215, 0x20, &D_813120D4);
            gSPDisplayList(D_800D0510++, D_80094E38);
            for (i = 0; i < 4; i++) {
                xo1 = D_813127C0[i] - 10;
                if (data[2 + i] <= 0) {
                    break;
                }
                if (i == 0 || i == 3) {
                    xo1 -= func_80049148(4, 1, (const char *)func_80062CE0(data[2 + i]));
                }
                func_81603C84(x + xo1 - 0x17, D_813127D0[i] + y - 2, func_80062D98(data[2 + i]));
            }
            gSPDisplayList(D_800D0510++, D_80094F50);
            func_800498C4();
            func_800496A4(4, 1);
            for (i = 0; i < 4; i++) {
                xo = D_813127C0[i] - 10;
                if (data[2 + i] <= 0) {
                    break;
                }
                name = func_80062CE0(data[2 + i]);
                if (i == 0 || i == 3) {
                    xo -= func_80049148(4, 1, name);
                }
                func_81602DA4(func_80062D98(data[2 + i]));
                func_800495BC(x + xo, D_813127D0[i] + y, name);
            }
            func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
            func_800496A4(8, 1);
            func_800495BC(x + 0xE, y + 0xE, "%s%s", data + 0x34, func_816087C8(data));
            func_800496A4(4, 1);
            func_800495BC(x + 0x89, y + 0x12, func_8004C874(0xD, 0x15));
            func_800496A4(8, 1);
            func_800495BC(x + 0x98, y + 0xE, "%d", data[0x1D]);
            if (flag == 0) {
                func_800496A4(4, 1);
                func_800495BC(x + 0xE2, y + 0x12, "%s%03d", func_8004C874(0xD, 0x11), data[0]);
                func_800496A4(4, 1);
                func_800495BC(x + 0x13A, y + 0x12, func_8004B7A4(data[0]));
            }
            func_800496A4(4, 0);
            func_800495BC(x + 0x6E, y + 0x2C, "%s%s", func_8004C874(0xD, 2), func_8004C874(0xD, 0x1C));
            func_800496A4(8, 1);
            func_800495BC(x + 0x98, y + 0x28, "%d", *(u16 *)(data + 0x28));
            if (flag == 0) {
                func_800496A4(4, 2);
                func_800495BC(x + 0x10B, y + 0x28, func_8004C874(0xD, 3));
                func_800495BC(x + 0x10B, y + 0x3B, func_8004C874(0xD, 4));
                func_800495BC(x + 0x10B, y + 0x4E, func_8004C874(0xD, 6));
                func_800495BC(x + 0x10B, y + 0x61, func_8004C874(0xD, 7));
                func_800495BC(x + 0x10B, y + 0x74, func_8004C874(0xD, 5));
                func_800496A4(4, 1);
                func_800495F8(x + 0x17E, y + 0x28, 2, "%d", *(u16 *)(data + 0x2A));
                func_800495F8(x + 0x17E, y + 0x3B, 2, "%d", *(u16 *)(data + 0x2C));
                func_800495F8(x + 0x17E, y + 0x4E, 2, "%d", *(u16 *)(data + 0x30));
                func_800495F8(x + 0x17E, y + 0x61, 2, "%d", *(u16 *)(data + 0x32));
                func_800495F8(x + 0x17E, y + 0x74, 2, "%d", *(u16 *)(data + 0x2E));
            }
            if (func_8130CE30(arg0)) {
                lbl = (void *)func_8004C874(0xD, 8);
                lbl2 = "";
                if (arg0[0x39] != 0) {
                    lbl2 = (void *)func_8004C874(8, arg0[0x39] - 1);
                }
                func_800496A4(4, 1);
                func_800495F8(x + 0x1D9, y + 0x93, 1, lbl);
                if (func_8130CE3C(arg0)) {
                    func_8004972C(0x80, 0x80, 0x80, 0xFF);
                }
                func_800495F8(x + 0x1D8, y + 0xA5, 1, lbl2);
                func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
            }
            func_800496A4(4, 2);
            func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
            func_800495BC(x + 0x6E, y + 0x44, "%s%s", func_8004C874(0xD, 0x12), func_8004C874(0xD, 0x16));
            func_81602DA4(func_8006397C(data[0]));
            w = func_80049148(4, 2, "%s%s", func_8004C874(0xD, 0x12), func_8004C874(0xD, 0x16));
            func_800495BC(w + x + 0x6E, y + 0x44, func_80063270(func_8006397C(data[0])));
            func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
            if (func_8006397C(data[0]) != func_800639C0(data[0])) {
                func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
                func_800495BC(x + 0x6E, y + 0x57, "%s%s", func_8004C874(0xD, 0x13), func_8004C874(0xD, 0x16));
                func_81602DA4(func_800639C0(data[0]));
                w = func_80049148(4, 2, "%s%s", func_8004C874(0xD, 0x13), func_8004C874(0xD, 0x16));
                func_800495BC(w + x + 0x6E, y + 0x57, func_80063270(func_800639C0(data[0])));
                func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
            }
            func_800499EC();
        }
        func_81607408();
    }
    if (func_81600DA8(arg1, arg0 + 4) != 0 && fade <= 0.1f) {
        func_8130D4E0(arg0, (s16 *)&rect2);
    }
    if (func_81600DA8(arg1, arg0 + 3) != 0) {
        func_8130D6A4(arg0);
    }
    func_8130DA04(arg0, arg1);
    if (arg0[0x34] >= 5 && func_81600DA8(arg1, arg0 + 2) != 0) {
        unk_func_8130D45C rect3;
        s32 idx = *(s8 *)(arg0 + 0x38);
        f32 t; // FAKE: the result is unused, but retail's frame has this slot
        u8 *cnts;

        t = func_8130D340(arg0, &rect3);
        cnts = data + idx;
        func_81606304(rect3.unk_00, rect3.unk_02, rect3.unk_04, rect3.unk_06, cnts[2]);
    }
}

// Column offsets and row heights func_8130DEB8 walks. D_813127D0 and D_813127DC are one
// 4-entry table; IDO turns the 4-iteration loops into pointer compares against D_813127E0.
const s32 D_813127C0[4] = { 179, 254, 230, 155 };
const s32 D_813127D0[3] = { 116, 140, 164 };
const s32 D_813127DC[1] = { 140 };

extern u8 D_813120B4[];
extern s32 func_80042D54(u8 *, u16);
void func_8130E99C(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3) {
    u16 color;
    arg0[0x34] = 0;
    arg0[0x37] = 0;
    *(s32 *)(arg0 + 0x60) = 0;
    *(s32 *)(arg0 + 0x5C) = arg1;
    *(s32 *)(arg0 + 0x24) = 0;
    *(s32 *)(arg0 + 0x64) = arg2;
    *(u8 **)(arg0 + 0x68) = arg3;
    *(s32 *)(arg0 + 0x6C) = 0;
    *(u16 *)(arg0 + 0x12) = 0;
    *(u16 *)(arg0 + 0x10) = 0;
    *(u16 *)(arg0 + 0x0C) = 0x2F;
    *(u16 *)(arg0 + 0x0E) = 0xFF;
    *(u16 *)(arg0 + 0x08) = 0x2F;
    *(u16 *)(arg0 + 0x0A) = 0xFF;
    *(s32 *)(arg0 + 0x00) = 0;
    *(s32 *)(arg0 + 0x70) = 0;
    *(f32 *)(arg0 + 0x28) = 0.0f;
    *(f32 *)(arg0 + 0x30) = 0.0f;
    *(f32 *)(arg0 + 0x2C) = 1.0f;
    *(u16 *)arg3 &= 0xFFFD;
    *(u16 *)(*(u8 **)(arg0 + 0x68)) &= 0xFFFB;
    *(u16 *)(*(u8 **)(arg0 + 0x68)) |= 0x100;
    color = (((D_813120B4[2] >> 2) & 0x3E) |
             (((D_813120B4[1] * 8) & 0x7C0) |
              ((D_813120B4[0] << 8) & 0xF800)) | 1) & 0xFFFF;
    func_80042D54(*(u8 **)(arg0 + 0x68), color);
}

void func_8130EA8C(u8 *arg0, u8 *arg1) {
    if ((*(u8 **)(arg0 + 0x6C) != arg1) || (*(s32 *)(arg1 + 0x58) != *(s32 *)(arg0 + 0x24))) {
        *(u8 **)(arg0 + 0x6C) = arg1;
        *(s32 *)(arg0 + 0x24) = *(s32 *)(arg1 + 0x58);
        *(s32 *)(arg0 + 0x00) = 1;
        *(u8 *)(arg0 + 0x39) = arg1[1];
        func_81601D24((s32)(arg0 + 0x3C), arg1[0]);
        *(s32 *)(arg0 + 0x70) = 2;
        *(s32 *)(arg0 + 0x60) = 0;
    }
}
// The 0x20-byte record func_8130EB04 copies to +0x3C (func_81601A38 initializes it otherwise).
typedef struct unk_D_8130EB04 {
    /* 0x00 */ s32 unk_00[8];
} unk_D_8130EB04; // size = 0x20
extern void func_8130F5AC(u8 *arg0);
extern void func_81601A38(void *, s32);
extern s32 func_8130CE3C(u8 *arg0);
extern s32 func_8130CEAC(u8 *arg0);
extern void func_8130EA8C(u8 *arg0, u8 *arg1);
void func_8130EB04(u8 *arg0, s16 arg1, u8 *arg2, s16 arg3, unk_D_8130EB04 *arg4, unk_func_8130D45C *arg5,
                   unk_func_8130D45C *arg6, s32 arg7) {
    *(s32 *)(arg0 + 4) = arg7;
    if (arg2[0] == 0) {
        func_8130F5AC(arg0);
        *(s32 *)(arg0 + 0x6C) = 0;
        arg0[0x34] = 0;
        *(f32 *)(arg0 + 0x2C) = 0.0f;
        return;
    }
    switch (arg0[0x34]) {
        case 0:
            *(s8 *)(arg0 + 0x38) = -1;
            *(s16 *)(arg0 + 0x12) = 0;
            *(s16 *)(arg0 + 0x10) = 0;
            *(f32 *)(arg0 + 0x2C) = 0.0f;
        case 2:
        case 3:
            arg0[0x34] = 2;
            break;
        case 1:
        case 4:
        case 5:
        case 6:
        case 7:
            break;
    }
    arg0[0x35] = arg3;
    arg0[0x37] = arg1;
    *(unk_func_8130D45C *)(arg0 + 0x1C) = *arg5;
    *(unk_func_8130D45C *)(arg0 + 0x14) = *arg6;
    if (arg4 != NULL) {
        *(unk_D_8130EB04 *)(arg0 + 0x3C) = *arg4;
    } else {
        func_81601A38(arg0 + 0x3C, 0);
    }
    func_8130EA8C(arg0, arg2);
    if (func_8130CE3C(arg0)) {
        *(s8 *)(arg0 + 0x36) = func_8130CEAC(arg0) - 1;
    } else {
        arg0[0x36] = 0;
    }
}

void func_8130EC94(u8 *arg0) {
    *(u32 *)(arg0 + 0x6C) = 0;
}

/* mkdraft:func_8130EC9C begin */
extern void func_800226C0(s32);
extern void func_81306C18(void *, s32, s32 *, s32);
extern u8 D_800CE060[];

/* m2c field-access helper (see matching_notes/TECHNIQUES.md). */
#define M2C_FIELD(expr, type, offset) (*(type)((u8*)(expr) + (offset)))



void func_8130EC9C(u8 *arg0) {
    s32 sp34;
    void *temp_v1;
    s32 sp2C;
    s32 sp28;
    u16 sp26;
    u16 sp24;
    s32 sp20;
    void *sp30;
    s32 temp_v0;
    s32 var_v0;
    s8 temp_v0_2;
    u8 temp_v0_3;

    sp34 = 0;
    temp_v1 = (M2C_FIELD(arg0, u8 *, 0x37) * 0x28) + D_800CE060;
    sp2C = M2C_FIELD(arg0, s32 *, 0x6C);
    sp28 = -1;
    sp26 = M2C_FIELD(temp_v1, u16 *, 0xC);
    sp30 = temp_v1;
    sp24 = M2C_FIELD(temp_v1, u16 *, 8);
    temp_v0 = func_8130CE3C(arg0);
    sp20 = temp_v0;
    if ((s32) M2C_FIELD(arg0, u8 *, 0x35) < 2) {
        if (M2C_FIELD(temp_v1, u16 *, 0xC) & 0x8000) {
            temp_v0_2 = M2C_FIELD(arg0, s8 *, 0x36);
            if (temp_v0_2 == 2) {
                func_81306C18(M2C_FIELD(arg0, void **, 0x5C), (s32) M2C_FIELD(arg0, u8 *, 0x39), (s32 *) (arg0 + 0x3C), 0);
                temp_v0_3 = M2C_FIELD(arg0, u8 *, 0x35);
                M2C_FIELD(arg0, s8 *, 0x34) = 4;
                switch (temp_v0_3) {                /* irregular */
                case 1:
                    func_800226C0(0x96);
                    break;
                case 0:
                case 2:
                    func_800226C0(2);
                    break;
                }
            } else if (temp_v0_2 == 1) {
                func_800226C0(3);
                M2C_FIELD(arg0, s8 *, 0x34) = 3;
                M2C_FIELD(arg0, f32 *, 0x2C) = 1.0f;
            } else {
                func_800226C0(M2C_FIELD(arg0, s32 *, 4));
                M2C_FIELD(arg0, s8 *, 0x34) = 3;
                M2C_FIELD(arg0, f32 *, 0x2C) = 1.0f;
            }
        } else if (sp26 & 0x4000) {
            func_800226C0(3);
            M2C_FIELD(arg0, s8 *, 0x36) = 1;
            M2C_FIELD(arg0, s8 *, 0x34) = 3;
            M2C_FIELD(arg0, f32 *, 0x2C) = 1.0f;
        } else if (sp26 & 0x800) {
            if (temp_v0 != 0) {
                var_v0 = 1;
            } else {
                var_v0 = 0;
            }
            if (var_v0 < M2C_FIELD(arg0, s8 *, 0x36)) {
                func_800226C0(1);
                M2C_FIELD(arg0, s8 *, 0x36) = (s8) (M2C_FIELD(arg0, s8 *, 0x36) - 1);
            }
        } else if (sp26 & 0x400) {
            if (M2C_FIELD(arg0, s8 *, 0x36) < (func_8130CEAC(arg0) - 1)) {
                func_800226C0(1);
                M2C_FIELD(arg0, s8 *, 0x36) = (s8) (M2C_FIELD(arg0, s8 *, 0x36) + 1);
            }
        } else {
            sp34 = 1;
        }
    } else {
        sp34 = 1;
    }
    M2C_FIELD(arg0, s8 *, 0x38) = -1;
    if ((sp34 != 0) && (M2C_FIELD(arg0, u8 *, 0x35) != 3)) {
        if ((sp20 != 0) && (M2C_FIELD(arg0, s8 *, 0x36) == 0)) {
            M2C_FIELD(arg0, s8 *, 0x36) = 1;
        } else if (sp24 & 8) {
            sp28 = 0;
        } else if (sp24 & 1) {
            sp28 = 1;
        } else if (sp24 & 4) {
            sp28 = 2;
        } else if (sp24 & 2) {
            sp28 = 3;
        }
    }
    if (sp28 >= 0) {
        if ((s32) M2C_FIELD((sp2C + sp28), u8 *, 2) > 0) {
            func_800226C0(0x91);
            M2C_FIELD(arg0, s8 *, 0x38) = (s8) sp28;
            M2C_FIELD(arg0, s8 *, 0x34) = 5;
        } else {
            func_800226C0(5);
        }
    }
    M2C_FIELD(arg0, f32 *, 0x30) = 0.0f;
}
/* mkdraft:func_8130EC9C end */

extern u8 D_800CE060[];
extern void func_800226C0(s32);
void func_8130EF88(u8 *arg0) {
    u8 *input = D_800CE060 + arg0[0x37] * 40;
    u8 *counts = *(u8 **)(arg0 + 0x6C);
    s32 dir = -1;
    s32 cur;

    *(f32 *)(arg0 + 0x30) = 12.0f;
    cur = *(s8 *)(arg0 + 0x38);
    if ((counts + cur)[2] == 0 || (*(u16 *)(input + 8) & 0xC000)) {
        func_800226C0(3);
        arg0[0x34] = 7;
        return;
    }
    if (*(u16 *)(input + 8) & 8) {
        dir = 0;
    } else if (*(u16 *)(input + 8) & 1) {
        dir = 1;
    } else if (*(u16 *)(input + 8) & 4) {
        dir = 2;
    } else if (*(u16 *)(input + 8) & 2) {
        dir = 3;
    }
    if (dir >= 0) {
        if ((counts + dir)[2] > 0) {
            if (dir == cur) {
                func_800226C0(5);
            } else {
                func_800226C0(2);
                *(s8 *)(arg0 + 0x38) = dir;
            }
        } else {
            func_800226C0(5);
        }
    }
}

extern f32 func_816092FC(void);
extern s32 func_8130CE30(u8 *arg0);
void func_8130F09C(u8 *arg0) {
    f32 step = func_816092FC();
    *(f32 *)(arg0 + 0x2C) += step;
    if (*(f32 *)(arg0 + 0x2C) >= 1.0f) {
        *(f32 *)(arg0 + 0x2C) = 1.0f;
        arg0[0x34] = 1;
        *(s8 *)(arg0 + 0x38) = -1;
    }
}

extern s16 func_81306B0C(void *);
extern void func_800226C0(s32);
void func_8130F0FC(u8 *arg0) {
    s32 status;
    void *target;
    target = *(void **)(arg0 + 0x5C);
    if (target != NULL) {
        status = func_81306B0C(target);
        if (status != -1) {
            if (status == -2) {
                *(u8 *)(arg0 + 0x34) = 1;
            }
            if (status >= 0) {
                *(u8 *)(arg0 + 0x36) = 0;
                *(s8 *)(arg0 + 0x39) = status;
                *(u8 *)(arg0 + 0x34) = 3;
                *(f32 *)(arg0 + 0x2C) = 1.0f;
                func_800226C0(*(s32 *)(arg0 + 0x04));
            }
        }
    } else {
        *(u8 *)(arg0 + 0x34) = 3;
    }
}

extern f32 func_816092FC(void);
void func_8130F184(u8 *arg0) {
    s32 sp18;
    s32 speed;
    speed = ((arg0[0x34] == 3) && (*(s8 *)(arg0 + 0x36) == 0)) ? 0x32 : 1;
    sp18 = speed;
    *(f32 *)(arg0 + 0x2C) = *(f32 *)(arg0 + 0x2C) - (func_816092FC() * (f32)speed);
    if (*(f32 *)(arg0 + 0x2C) <= 0.0f) {
        arg0[0x34] = 0;
        *(f32 *)(arg0 + 0x2C) = 0.0f;
        *(s8 *)(arg0 + 0x38) = -1;
    }
}

void func_8130F218(u8 *arg0) {
    f32 step = func_816092FC();
    *(f32 *)(arg0 + 0x30) += step;
    if (*(f32 *)(arg0 + 0x30) >= 12.0f) {
        *(f32 *)(arg0 + 0x30) = 12.0f;
        arg0[0x34] = 6;
    }
}

void func_8130F270(u8 *arg0) {
    f32 step = func_816092FC();
    *(f32 *)(arg0 + 0x30) -= step;
    if (*(f32 *)(arg0 + 0x30) <= 0.0f) {
        arg0[0x34] = 1;
        *(f32 *)(arg0 + 0x30) = 0.0f;
    }
}

extern void func_81600A34(u8 *arg0, void *id, s32 arg2, s32 x, s32 y, s32 width, s32 height);
extern void func_8130EC9C(u8 *arg0);
extern s32 ModelAnim_SetSpeed(u8 *arg0, s32 arg1);
// FAKE: func_80042F94 is void at its definition (src/43700.c); an int return reserves v0
// across this call, and the countdown local read from arg0+0x70 then takes v1.
// Declaring the real void return gives diff score 35.
extern s32 func_80042F94();
extern s32 func_80043678(u8 *arg0);
extern f32 func_816092FC(void);



void func_8130F2C4(u8 *arg0, u8 *arg1) {
    s32 timer;
    s32 flag = 0;
    unk_func_8130D45C sp58;
    unk_func_8130D45C sp50;
    unk_func_8130D45C sp48;
    unk_func_8130D45C sp40;
    unk_func_8130D45C sp38;

    switch (arg0[0x34]) {
        case 0:
            func_8130EC94(arg0);
            return;
        case 1:
            func_8130EC9C(arg0);
            break;
        case 2:
            func_8130F09C(arg0);
            break;
        case 3:
            func_8130F184(arg0);
            break;
        case 4:
            func_8130F0FC(arg0);
            break;
        case 5:
            func_8130F218(arg0);
            break;
        case 7:
            func_8130F270(arg0);
            break;
        case 6:
            func_8130EF88(arg0);
            break;
    }
    if (*(s32 *)arg0 != 0) {
        flag = 1;
        *(s32 *)arg0 = 0;
    }
    func_8130CEF0(arg0, &sp58);
    func_81600A34(arg1, arg0, flag, sp58.unk_00, sp58.unk_02, sp58.unk_04, sp58.unk_06);
    func_8130D45C(arg0, &sp40, &sp58);
    func_81600A34(arg1, arg0 + 4, *(s8 *)(arg0 + 0x38) >= 0, sp40.unk_00, sp40.unk_02, sp40.unk_04, sp40.unk_06);
    func_8130D098(arg0, &sp48);
    func_81600A34(arg1, arg0 + 3, 1, sp48.unk_00, sp48.unk_02, sp48.unk_04, sp48.unk_06);
    func_8130D1FC(arg0, &sp50);
    func_81600A34(arg1, arg0 + 1, arg0[0x34] == 1, sp50.unk_00, sp50.unk_02, sp50.unk_04, sp50.unk_06);
    if (arg0[0x34] >= 5) {
        func_8130D340(arg0, &sp38);
        func_81600A34(arg1, arg0 + 2, 1, sp38.unk_00, sp38.unk_02, sp38.unk_04, sp38.unk_06);
    }
    timer = *(s32 *)(arg0 + 0x70);
    if (timer != 0) {
        *(s32 *)(arg0 + 0x70) -= 1;
        if (*(s32 *)(arg0 + 0x70) == 0) {
            func_80042F94(*(void **)(arg0 + 0x68), *(void **)(arg0 + 0x6C));
        }
        timer = *(s32 *)(arg0 + 0x70);
    }
    if (*(s32 *)(arg0 + 0x70) == 0) {
        switch (arg0[0x34]) {
            case 1:
            case 4:
            case 5:
            case 6:
            case 7:
                if (*(u8 **)(arg0 + 0x68) != NULL) {
                    ModelAnim_SetSpeed(*(u8 **)(*(u8 **)(arg0 + 0x68) + 0x1C), func_816092FC() * 32768.0f);
                    *(s32 *)(arg0 + 0x60) = func_80043678(*(u8 **)(arg0 + 0x68));
                }
                break;
        }
    }
}

s16 func_8130F578(u8 *arg0, s32 *arg1) {
    s16 result = 0;
    if (arg1 != NULL) {
        *arg1 = arg0[0x39];
    }
    if (arg0[0x34] == 0) {
        result = *(s8 *)(arg0 + 0x36) + 1;
    }
    return result;
}

extern void Fragment14_BeginGridClose(u8 *arg0);
void func_8130F5AC(u8 *arg0) {
    u8 *target;
    switch (arg0[0x34]) {
        case 4:
            target = *(u8 **)(arg0 + 0x5C);
            if (target != NULL) {
                Fragment14_BeginGridClose(target);
            }
        case 5:
        case 6:
        case 7:
            *(f32 *)(arg0 + 0x30) = 0.0f;
        case 1:
            *(f32 *)(arg0 + 0x2C) = 1.0f;
        case 2:
        case 3:
            arg0[0x34] = 3;
        case 0:
        default:
            break;
    }
}
#endif
