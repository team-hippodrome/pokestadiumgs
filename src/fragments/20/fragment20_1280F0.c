#include "global.h"


#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_1280F0/func_82600020.s")

typedef struct {
    u8 unk_00[0x74];
    s8 sides[4];
    s8 members[8];
    s16 pairs[2][2];
    s16 selection;
} Func826002BCState;
typedef struct {
    s16 count;
    s8 owners[2];
    u8 unk_04[2];
    u8 flag;
    u8 unk_07[0x421];
} Func826002BCDescriptor;
typedef struct {
    u8 unk_00[0x58];
    s16 defaults[22][2];
    Func826002BCDescriptor descs[2];
} Func826002BCContext;
extern Func826002BCState *D_82615324;
void func_826002BC(Func826002BCContext *arg0) {
    s16 *fallback;
    s32 i;
    s32 a;
    s32 b;
    s16 *out;
    Func826002BCDescriptor *desc;

    fallback = arg0->defaults[D_82615324->selection];
    for (i = 0; i < 2; i++) {
        a = D_82615324->sides[i];
        b = D_82615324->members[i];
        out = D_82615324->pairs[i];
        desc = &arg0->descs[i];
        if (a == -1) {
            if (desc->owners[0] >= 0) {
                if (desc->count == 1) {
                    out[0] = 0x40;
                    if (desc->flag != 0) {
                        out[1] = 0;
                    } else {
                        out[1] = 1;
                    }
                } else {
                    out[0] = 0x41;
                    out[1] = 0;
                }
            } else {
                out[0] = fallback[0];
                out[1] = fallback[1];
            }
        } else {
            out[0] = a;
            out[1] = b;
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_1280F0/func_826003BC.s")
#endif
