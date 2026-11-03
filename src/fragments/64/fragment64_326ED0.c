#include "global.h"


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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_326ED0/func_87F0455C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_326ED0/func_87F04894.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_326ED0/func_87F05204.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_326ED0/func_87F05D34.s")
#endif
