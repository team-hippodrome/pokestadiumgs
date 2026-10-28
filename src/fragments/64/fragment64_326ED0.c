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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_326ED0/func_87F04314.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_326ED0/func_87F05954.s")

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
