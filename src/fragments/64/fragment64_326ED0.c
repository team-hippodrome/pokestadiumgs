#include "global.h"
#include "controller.h"
extern s32 D_87F0FAE4;
extern u8 D_87F114A4[];
extern u8 D_87F114A8[];
extern u8 D_87F114AC[];
void func_87F05930(Gfx **);
void func_87F05954(s32, s32, s32, s32);
void func_87F05CE0(s32, s32, s32, s32);
void func_87F05D34(s32, s32, s32, f32, s32);


#ifdef VERSION_US
s32 func_87F04260(s32 arg0, s32 arg1) {
    arg0++;
    arg1++;
    if ((arg0 < 0x1D) || (arg0 >= 0x127) || (arg1 < 0x1A) || (arg1 >= 0xD8)) {
        return -1;
    }
    return ((arg0 - 0x1D) / 7) + (((arg1 - 0x1A) / 10) * 0x26);
}

s32 func_87F042D0(s32 arg0, s32 arg1) {
    if ((arg0 < 0) || (arg0 >= 0x26) || (arg1 < 0) || (arg1 >= 0x13)) {
        return -1;
    }
    return (arg1 * 0x26) + arg0;
}

/* mkdraft:func_87F04314 begin */
extern u8 D_87F11A00[];
extern u8 D_87F13BD8[];

typedef struct {
    s8 unk0;
    s8 unk1;
    u8 unk2[2];
    s32 unk4;
    s8 unk8;
    s8 unk9;
    s8 unkA;
    s8 unkB;
    s8 unkC;
    u8 unkD[3];
    s32 unk10;
    s32 unk14;
    s32 unk18;
} Entry;



s32 func_87F04314(s16 arg0, s8 arg1, s8 arg2, s32 arg3, s8 arg4, s8 arg5, s8 arg6, s8 arg7, s8 arg8,
                  s32 arg9, s32 arg10, s32 arg11) {
    Entry *entry;
    s32 start;
    s32 end;
    s32 i;
    s32 idx;

    if (arg0 < 0 || arg0 >= 3) {
        return -4;
    }
    if (arg6 != 1) {
        if (arg8 > 0) {
            end = arg4 + arg8 + 1;
        } else {
            end = arg4 + arg8;
        }
        for (; end >= arg4 - arg7 + 1; end--) {
            idx = func_87F042D0(end, arg5);
            if (idx < 0) {
                return -1;
            }
            if (*(s32 *)(D_87F11A00 + arg0 * 0xB48 + idx * 4) >= 0) {
                return -2;
            }
        }
    }
    entry = (Entry *)(D_87F13BD8 + arg0 * 0xA80);
    for (i = 0; i < 0x60; i++) {
        if (entry->unkA == 0) {
            break;
        }
        entry++;
    }
    if (i >= 0x60) {
        return -3;
    }
    if (arg8 > 0) {
        end = arg4 + arg8 + 1;
    } else {
        end = arg4 + arg8;
    }
    for (; end >= arg4 - arg7 + 1; end--) {
        idx = func_87F042D0(end, arg5);
        *(s32 *)(D_87F11A00 + arg0 * 0xB48 + idx * 4) = i;
    }
    entry->unk0 = arg1;
    entry->unk1 = arg2;
    entry->unk4 = arg3;
    entry->unk8 = arg4;
    entry->unk9 = arg5;
    entry->unkA = arg6;
    entry->unkB = arg7;
    entry->unkC = arg8;
    entry->unk10 = arg9;
    entry->unk14 = arg10;
    entry->unk18 = arg11;
    return 0;
}
/* mkdraft:func_87F04314 end */

extern f32 D_87F119E8;
extern f32 D_87F119EC;
extern s32 D_87F119F8;
extern s32 D_87F119F0;
extern s32 D_87F119F4;
extern u8 D_87F119E0[];
extern u8 D_87F119E4[];
const u8 D_87F11490[4] = { 0 };
const u8 D_87F11494[4] = { 0 };
const u8 D_87F11498[4] = { 0 };
const u8 D_87F1149C[4] = { 0 };
const u8 D_87F114A0[4] = { 0 };
extern s32 D_87F0FAE0;
extern const u8 D_87F0FB30[];
extern const u8 D_87F0FB74[];
void func_87F0455C(void) {
    u8 *end;
    Entry *entry;
    s32 *grid;
    s32 i;
    void *v1;
    void *v2;
    void *v3;
    void *v4;
    void *v5;
    void *v6;
    void *v7;
    void *p3;
    void *p4;
    void *p5;
    void *p6;
    void *p7;

    D_87F119E8 = 160.0f;
    D_87F119EC = 120.0f;
    D_87F119F0 = (D_87F119F8 = func_87F04260((s32)D_87F119E8, (s32)D_87F119EC)) % 38;
    D_87F119F4 = D_87F119F8 / 38;

    for (entry = (Entry *)D_87F13BD8, grid = (s32 *)D_87F11A00, end = D_87F11A00 + 0x21D8; (u8 *)grid < end;
         entry = (Entry *)((u8 *)entry + 0xA80), grid = (s32 *)((u8 *)grid + 0xB48)) {
        for (i = 0; i < 0x60; i++) {
            entry[i].unkA = 0;
        }

        for (i = 0; i < 0x2D2; i++) {
            grid[i] = -1;
        }
    }

    v1 = (void *)D_87F1149C;
    v2 = (void *)D_87F11498;
    v3 = (void *)D_87F11494;
    v4 = &D_87F0FAE0;
    v5 = (void *)D_87F11490;
    v6 = (void *)D_87F0FB74;
    v7 = (void *)D_87F0FB30;

    p3 = &D_87F119F0;
    p4 = &D_87F119F4;
    p5 = (void *)D_87F119E0;
    p6 = (void *)D_87F114A0;
    p7 = (void *)D_87F119E4;

    for (i = 0; i < 3; i++) {
        func_87F04314(i, 0, 0, (s32)v5, 0x25, 0x10, 6, 1, 0, (s32)v4, (s32)v7, (s32)v7);
        func_87F04314(i, 0, 0, (s32)v3, 0x21, 0x11, 6, 2, 0, (s32)p3, (s32)v7, (s32)v7);
        func_87F04314(i, 0, 0, (s32)v2, 0x25, 0x11, 6, 2, 0, (s32)p4, (s32)v7, (s32)v7);
        func_87F04314(i, 0, 0, (s32)v1, 0x21, 0x12, 10, 3, 0, (s32)p5, (s32)v6, (s32)v6);
        func_87F04314(i, 0, 0, (s32)p6, 0x25, 0x12, 10, 3, 0, (s32)p7, (s32)v6, (s32)v6);
    }
}

void func_87F04894(void) {
    s32 pad[4];
    Entry *entries;
    s32 *grid;
    Entry *entry;
    s32 index;
    s32 column;
    f32 step;
    f32 direction;
    if ((D_80087208->buttonsPressed & 0x100) == 0x100) {
        if (D_87F0FAE0 < 0) D_87F0FAE0 = D_87F0FAE4;
        else {
            D_87F0FAE0 += 1;
            if (D_87F0FAE0 == 3) D_87F0FAE0 = 0;
        }
    } else if ((D_80087208->buttonsPressed & 0x200) == 0x200) {
        if (D_87F0FAE0 < 0) D_87F0FAE0 = D_87F0FAE4;
        else {
            D_87F0FAE0 -= 1;
            if (D_87F0FAE0 < 0) D_87F0FAE0 = 2;
        }
    } else if ((D_80087208->buttonsPressed & 0x400) == 0x400) {
        if (D_87F0FAE0 >= 0) {
            D_87F0FAE4 = D_87F0FAE0;
            D_87F0FAE0 = -1;
        }
    }
    if (D_87F0FAE0 >= 0 && D_87F0FAE0 < 3) {
        entries = (Entry *)(D_87F13BD8 + D_87F0FAE0 * 2688);
        grid = (s32 *)(D_87F11A00 + D_87F0FAE0 * 2888);
        step = (f32)D_80087208->stickX * 0.03;
        step *= step;
        if (step < 0.1) step = 0;
        if (D_80087208->stickX < 0) {
            D_87F119E8 -= step;
            if (D_87F119E8 < 22.0f) D_87F119E8 = 297.0f;
        } else {
            D_87F119E8 += step;
            if (297.0f < D_87F119E8) D_87F119E8 = 22.0f;
        }
        step = (f32)D_80087208->stickY * 0.03;
        step *= step;
        if (step < 0.1) step = 0;
        if (D_80087208->stickY >= 0) {
            D_87F119EC -= step;
            if (D_87F119EC < 20.0f) D_87F119EC = 215.0f;
        } else {
            D_87F119EC += step;
            if (D_87F119EC > 215.0f) D_87F119EC = 20.0f;
        }
        D_87F119F8 = func_87F04260((s32)D_87F119E8, (s32)D_87F119EC);
        if (D_87F119F8 < 0) {
            D_87F119F0 = D_87F119F4 = -1;
        } else {
            column = D_87F119F8 % 38;
            D_87F119F0 = column;
            D_87F119F4 = D_87F119F8 / 38;
            do {
            } while (0);
            index = grid[D_87F119F8];
            if (index >= 0) {
                entry = &entries[index];
                if (entry->unkA == 1) return;
                if ((D_80087208->buttonsRepeat & 0x8000) == 0x8000) direction = 1.0f;
                else if ((D_80087208->buttonsRepeat & 0x4000) == 0x4000) direction = -1.0f;
                else return;
                index = entry->unk8 - column;
                if (index >= 0) {
                    step = 1.0f;
                    while (index--) step *= 10.0;
                } else if (index < -1) {
                    index = -2 - index;
                    step = 0.1f;
                    while (index--) step *= 0.1;
                } else return;
                switch (entry->unkA) {
                case 2:
                    if (*(s8 *)entry->unk14 != *(s8 *)entry->unk18) {
                        *(s8 *)entry->unk10 += (s8)(direction * step);
                        if (*(s8 *)entry->unk10 < *(s8 *)entry->unk14)
                            *(s8 *)entry->unk10 = *(s8 *)entry->unk14;
                        else if (*(s8 *)entry->unk10 > *(s8 *)entry->unk18)
                            *(s8 *)entry->unk10 = *(s8 *)entry->unk18;
                    }
                    break;
                case 3:
                    if (*(u8 *)entry->unk14 != *(u8 *)entry->unk18) {
                        *(u8 *)entry->unk10 += (u8)(s32)(direction * step);
                        if (*(u8 *)entry->unk10 < *(u8 *)entry->unk14)
                            *(u8 *)entry->unk10 = *(u8 *)entry->unk14;
                        else if (*(u8 *)entry->unk10 > *(u8 *)entry->unk18)
                            *(u8 *)entry->unk10 = *(u8 *)entry->unk18;
                    }
                    break;
                case 4:
                    if (*(s16 *)entry->unk14 != *(s16 *)entry->unk18) {
                        *(s16 *)entry->unk10 += (s16)(direction * step);
                        if (*(s16 *)entry->unk10 < *(s16 *)entry->unk14)
                            *(s16 *)entry->unk10 = *(s16 *)entry->unk14;
                        else if (*(s16 *)entry->unk10 > *(s16 *)entry->unk18)
                            *(s16 *)entry->unk10 = *(s16 *)entry->unk18;
                    }
                    break;
                case 5:
                    if (*(u16 *)entry->unk14 != *(u16 *)entry->unk18) {
                        *(u16 *)entry->unk10 += (u16)(direction * step);
                        if (*(u16 *)entry->unk10 < *(u16 *)entry->unk14)
                            *(u16 *)entry->unk10 = *(u16 *)entry->unk14;
                        else if (*(u16 *)entry->unk10 > *(u16 *)entry->unk18)
                            *(u16 *)entry->unk10 = *(u16 *)entry->unk18;
                    }
                    break;
                case 6: case 8:
                    if (*(s32 *)entry->unk14 != *(s32 *)entry->unk18) {
                        *(s32 *)entry->unk10 += (s32)(direction * step);
                        if (*(s32 *)entry->unk10 < *(s32 *)entry->unk14)
                            *(s32 *)entry->unk10 = *(s32 *)entry->unk14;
                        else if (*(s32 *)entry->unk10 > *(s32 *)entry->unk18)
                            *(s32 *)entry->unk10 = *(s32 *)entry->unk18;
                    }
                    break;
                case 7: case 9:
                    if (*(u32 *)entry->unk14 != *(u32 *)entry->unk18) {
                        *(u32 *)entry->unk10 += (u32)(direction * step);
                        if (*(u32 *)entry->unk10 < *(u32 *)entry->unk14)
                            *(u32 *)entry->unk10 = *(u32 *)entry->unk14;
                        else if (*(u32 *)entry->unk10 > *(u32 *)entry->unk18)
                            *(u32 *)entry->unk10 = *(u32 *)entry->unk18;
                    }
                    break;
                case 10:
                    if (*(f32 *)entry->unk14 != *(f32 *)entry->unk18) {
                        *(f32 *)entry->unk10 += (f32)(direction * step);
                        if (*(f32 *)entry->unk10 < *(f32 *)entry->unk14)
                            *(f32 *)entry->unk10 = *(f32 *)entry->unk14;
                        else if (*(f32 *)entry->unk10 > *(f32 *)entry->unk18)
                            *(f32 *)entry->unk10 = *(f32 *)entry->unk18;
                    }
                    break;
                case 11:
                    if (*(f64 *)entry->unk14 != *(f64 *)entry->unk18) {
                        *(f64 *)entry->unk10 += (f64)(direction * step);
                        if (*(f64 *)entry->unk10 < *(f64 *)entry->unk14)
                            *(f64 *)entry->unk10 = *(f64 *)entry->unk14;
                        else if (*(f64 *)entry->unk10 > *(f64 *)entry->unk18)
                            *(f64 *)entry->unk10 = *(f64 *)entry->unk18;
                    }
                    break;
                }
            }
        }
    }
}
void func_87F05204(Gfx **arg0) {
    Gfx *dl;
    Entry *entry;
    Entry *start;
    s32 *out;
    dl = *arg0;
    out = (s32 *)&dl;
    if (D_87F0FAE0 >= 0 && D_87F0FAE0 < 3) {
        start = (Entry *)(D_87F13BD8 + D_87F0FAE0 * 2688);
        func_87F05930((Gfx **)out);
        for (entry = start + 95; entry >= start; entry--) {
            if (entry->unkA == 0) continue;
            if (entry->unk4 != 0) {
                func_87F05954((s32)out, entry->unk0 * 7 + 29, entry->unk1 * 10 + 26, entry->unk4);
            }
            if (entry->unkA == 1) continue;
            switch (entry->unkA) {
            case 2:
                func_87F05CE0((s32)out, entry->unk8 * 7 + 29, entry->unk9 * 10 + 26, *(s8 *)entry->unk10);
                break;
            case 3:
                func_87F05CE0((s32)out, entry->unk8 * 7 + 29, entry->unk9 * 10 + 26, *(u8 *)entry->unk10);
                break;
            case 4:
                func_87F05CE0((s32)out, entry->unk8 * 7 + 29, entry->unk9 * 10 + 26, *(s16 *)entry->unk10);
                break;
            case 5:
                func_87F05CE0((s32)out, entry->unk8 * 7 + 29, entry->unk9 * 10 + 26, *(u16 *)entry->unk10);
                break;
            case 6: case 8:
                func_87F05CE0((s32)out, entry->unk8 * 7 + 29, entry->unk9 * 10 + 26, *(s32 *)entry->unk10);
                break;
            case 7: case 9:
                func_87F05CE0((s32)out, entry->unk8 * 7 + 29, entry->unk9 * 10 + 26, *(u32 *)entry->unk10);
                break;
            case 10:
                func_87F05D34((s32)out, entry->unk8 * 7 + 29, entry->unk9 * 10 + 26, *(f32 *)entry->unk10, entry->unkC);
                break;
            case 11:
                func_87F05D34((s32)out, entry->unk8 * 7 + 29, entry->unk9 * 10 + 26, (f32)*(f64 *)entry->unk10, entry->unkC);
                break;
            }
        }
        if (D_87F119F8 >= 0) {
            func_87F05954((s32)out, (D_87F119F8 % 38) * 7 + 27, (D_87F119F8 / 38) * 10 + 28, (s32)"L");
            func_87F05954((s32)out, (D_87F119F8 % 38) * 7 + 31, (D_87F119F8 / 38) * 10 + 24, (s32)"]");
        }
        *(f32 *)D_87F119E0 = D_87F119E8;
        *(f32 *)D_87F119E4 = D_87F119EC + 8.0f;
        func_87F05954((s32)out, (s32)*(f32 *)D_87F119E0, (s32)*(f32 *)D_87F119E4, (s32)"^");
        *arg0 = dl;
    }
}
s32 func_87F056E0(void *arg0, s32 arg1) {
    s32 count;
    s32 negative;
    s32 i;
    s8 buffer[16];

    count = 0;
    negative = 0;
    if (arg1 < 0) {
        //!bug: negating the minimum signed word overflows, as in retail.
        arg1 = -arg1;
        negative = 1;
    }
    do {
        buffer[count] = arg1 % 10 + '0';
        count++;
        arg1 /= 10;
    } while (arg1 > 0);
    if (negative) {
        buffer[count] = '-';
        count++;
    }
    for (i = 0; i < count; i++) {
        ((s8 *)arg0)[i] = buffer[count - i - 1];
    }
    ((s8 *)arg0)[i] = 0;
    return count;
}

void func_87F057EC(void *arg0, s32 arg1, s32 arg2) {
    s32 count;
    s32 negative;
    s32 i;
    s32 missing;
    s8 buffer[16];

    count = 0;
    negative = 0;
    if (arg1 < 0) {
        //!bug: negating the minimum signed word overflows, as in retail.
        arg1 = -arg1;
        negative = 1;
    }
    do {
        buffer[count] = arg1 % 10 + '0';
        count++;
        arg1 /= 10;
    } while (arg1 > 0);
    if (negative) {
        buffer[count] = '-';
        count++;
    }
    if (count < arg2) {
        missing = arg2 - count;
        for (i = 0; i < missing; i++) {
            //!bug: a requested width above 16 exceeds the scratch buffer.
            buffer[count] = ' ';
            count++;
        }
    }
    for (i = 0; i < count; i++) {
        ((s8 *)arg0)[i] = buffer[count - i - 1];
    }
    ((s8 *)arg0)[i] = 0;
}

extern Gfx D_87F0FBC8[];

void func_87F05930(Gfx **arg0) {
    Gfx *gfx = *arg0;

    gSPDisplayList(gfx++, D_87F0FBC8);
    *arg0 = gfx;
}

/* mkdraft:func_87F05954 begin */


void func_87F05954(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 count;
    s32 x;
    s8 c;
    Gfx *state;

    c = *(s8 *)arg3;
    x = arg1;
    state = *(Gfx **)arg0;
    if (c != 0) {
        do {
            if (c >= 0x30 && c < 0x3A) {
                count = c - 0x30;
            } else if (c >= 0x41 && c < 0x5B) {
                count = c - 0x37;
            } else {
                switch (c) {
                    case 0x2B: count = 0x24; break;
                    case 0x2D: count = 0x25; break;
                    case 0x3A: count = 0x26; break;
                    case 0x5D: count = 0x27; break;
                    case 0x2E: count = 0x28; break;
                    case 0x5E: count = 0x29; break;
                    default: count = -1; break;
                }
            }
            if (count >= 0) {
                gSPTextureRectangle(state++, x << 2, arg2 << 2, (x + 5) << 2, (arg2 + 7) << 2,
                                    G_TX_RENDERTILE, ((count % 21) * 6) << 5,
                                    ((count / 21) * 8) << 5, 0x1000, 0x400);
            }
            arg3++;
            x += 7;
            c = *(s8 *)arg3;
        } while (c != 0);
    }
    *(Gfx **)arg0 = state;
}
/* mkdraft:func_87F05954 end */

extern void func_87F05954(s32, s32, s32, s32);

void func_87F05B88(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_87F05930((Gfx **)arg0);
    func_87F05954(arg0, arg1, arg2, arg3);
}

extern s32 func_87F056E0(void *, s32);
extern void func_87F05B88(s32, s32, s32, s32);
void func_87F05BC8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp[16];
    func_87F056E0(temp, arg3);
    func_87F05B88(arg0, arg1, arg2, (s32)temp);
}

void func_87F05C0C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp[16];
    func_87F056E0(temp, arg3);
    func_87F05954(arg0, arg1, arg2, (s32)temp);
}

extern void func_87F057EC(void *, s32, s32);
void func_87F05C50(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) { s32 temp[16]; func_87F057EC(temp, arg3, arg4); func_87F05B88(arg0, arg1, arg2, (s32)temp); }

void func_87F05C98(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) { s32 temp[16]; func_87F057EC(temp, arg3, arg4); func_87F05954(arg0, arg1, arg2, (s32)temp); }

extern s32 func_87F056E0(void *, s32);
extern void func_87F05954(s32, s32, s32, s32);
void func_87F05CE0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 pad[4];
    s32 temp[16];
    s32 result = func_87F056E0(temp, arg3);
    func_87F05954(arg0, arg1 - (result * 7) + 7, arg2, (s32)temp);
}

extern u8 D_87F11530[];
extern u8 D_87F11534[];

// Draws arg3 as decimal text with arg4 fractional digits. The fraction is
// reduced to one integer remainder, written right to left into buffer, then
// func_87F056E0 overwrites it with the integer part and returns that part's
// character count; each character occupies seven pixels left of arg1.
// buffer is passed to the drawer through buffer_ptr and the two digit walks
// keep separate counters so the buffer address is rematerialized per call and
// each walk gets its own induction register.


void func_87F05D34(s32 arg0, s32 arg1, s32 arg2, f32 arg3, s32 arg4) {
    u8 *buffer_ptr;
    s32 digits;
    s32 exponent;
    s32 index;
    s32 count;
    s32 remainder;
    s32 sign;
    u8 buffer[64];

    sign = 0;
    if (arg3 < 0.0f) {
        arg3 = -arg3;
        sign = 1;
    } else {
        sign = 0;
    }
    exponent = 1;
    for (digits = arg4; digits > 0; digits--) {
        exponent *= 10;
    }
    buffer_ptr = buffer;
    if (arg4 > 0) {
        remainder = (s32)(exponent * arg3) % exponent;
        for (index = arg4 - 1; index >= 0; index--) {
            buffer[index] = remainder % 10 + '0';
            remainder /= 10;
        }
        buffer[arg4] = 0;
        func_87F05954(arg0, arg1 + 14, arg2, (s32)buffer_ptr);
        func_87F05954(arg0, arg1 + 7, arg2, (s32)D_87F11530);
    }
    count = func_87F056E0(buffer_ptr, (s32)(exponent * arg3) / exponent);
    func_87F05954(arg0, arg1 - count * 7 + 7, arg2, (s32)buffer_ptr);
    if (sign != 0) {
        func_87F05954(arg0, arg1 - count * 7, arg2, (s32)D_87F11534);
    }
}
#endif
