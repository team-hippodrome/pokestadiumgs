#include "global.h"


#ifdef VERSION_US
u8 *func_87F0D1A0(u8 *arg0) {
    return arg0 + 8;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_32FE10/func_87F0D1A8.s")

typedef struct { u8 *value; } Func87F0D44CArg;
extern u8 D_87F112F4[];extern void func_87F0D1A8(void *, void *, s32, s32, s32);
// Plain-pointer signature: retail's call sites pass a0 raw (no struct-by-value
// outgoing-area copy); see the meta for func_87F0D5B8.
void func_87F0D44C(u8 *arg0) {
    func_87F0D1A8(arg0 + 8, D_87F112F4, 0x20, *(s32 *)(arg0 + 4), 8);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_32FE10/func_87F0D48C.s")

extern u32 func_87F00930(void);
extern void func_87F0277C(void *);

void func_87F0D5B8(u8 *arg0) {
    if (func_87F00930() == 0) {
        *(s32 *)(arg0 + 4) += 1;
    }
    func_87F0D44C(arg0);
    func_87F0277C(arg0 + 0xC);
}
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_32FE10/func_87F0D600.s")

// Prefix views for the callback's model node and its three-word callback data.
// GeoNode_CreateModelPart initializes the same vector and color field layouts.
//@src/229E0.c
typedef struct {
    f32 unk_00;
    f32 unk_04;
    f32 unk_08;
} unk_func_87F0D96C_024;

typedef struct {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
} unk_func_87F0D96C_01E;

typedef union {
    u8 rgba[4];
    u32 word;
} unk_func_87F0D96C_03C;

typedef struct unk_func_87F0D96C {
    u8 unk_00[20];
    struct unk_func_87F0D96C_014 *unk_14;
    u8 unk_18[6];
    unk_func_87F0D96C_01E unk_1E;
    unk_func_87F0D96C_024 unk_24;
    unk_func_87F0D96C_024 unk_30;
    unk_func_87F0D96C_03C unk_3C;
} unk_func_87F0D96C;

typedef struct unk_func_87F0D96C_014 {
    s32 unk_00;
    unk_func_87F0D96C *unk_04;
    u8 *unk_08;
} unk_func_87F0D96C_014;

s32 func_87F0D96C(s32 arg0, unk_func_87F0D96C *arg1) {
    unk_func_87F0D96C_014 *var_v0;

    if (arg0 == 2) {
        var_v0 = arg1->unk_14;
        if (var_v0->unk_04 != NULL) {
            arg1->unk_24 = var_v0->unk_04->unk_24;
            arg1->unk_30 = var_v0->unk_04->unk_30;
            arg1->unk_1E = var_v0->unk_04->unk_1E;
            arg1->unk_3C = *(unk_func_87F0D96C_03C *)func_87F0D1A0(var_v0->unk_08);
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_32FE10/func_87F0DA08.s")

extern void *func_87F025B8(void *, void *);
extern void func_8003F1DC(void *);
extern void func_8003F114(u8 *, s16, s16, void *);
extern void func_80037E3C(void *, s32 (*)(s32, unk_func_87F0D96C *), void *);

// When arg0 + 0x20 holds model data, takes a free 0x18C-byte object from the pool
// at arg0 + 0xC with func_87F025B8, initializes the object's model node at +0x24 with
// that data and installs func_87F0D96C as the node callback. The callback data
// (object + 0x38, the node's unk_14) receives arg1 and `source`, the node whose
// unk_1E/unk_24/unk_30 fields func_87F0D96C copies into this node. func_867068EC
// passes another pool object's model node as `source`. Pool functions:
//@src/fragments/64/fragment64_324FB0.c
void func_87F0DB3C(u8 *arg0, s32 arg1, unk_func_87F0D96C *source) {
    u8 *object;
    unk_func_87F0D96C_014 *data;

    if (*(void **)(arg0 + 0x20) != NULL) {
        object = func_87F025B8(arg0 + 0xC, NULL);
        if (object != NULL) {
            data = *(unk_func_87F0D96C_014 **)(object + 0x38);
            func_8003F1DC(object + 0x24);
            func_8003F114(object + 0x24, 0, -1, *(void **)(arg0 + 0x20));
            func_80037E3C(object + 0x24, func_87F0D96C, data);
            data->unk_00 = arg1;
            data->unk_04 = source;
        }
    }
}
#endif
