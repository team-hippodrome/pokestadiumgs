#include "global.h"


#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_32AEF0/func_87F08280.s")

// Builds a vertex for texel (s, t) of an image whose u16 width and height are at
// image_size: position is the texel's offset from the image center, flipped in y,
// shifted by (x_offset, y_offset) and multiplied by scale; texture coordinates are
// s and t in 10.5 fixed point. The normal is (0, 0, 127) with alpha 0xFF; the signed
// reload of n[1] when copying it to n[0] matches the s8 Vtx_tn normal.
void func_87F088EC(Vtx *vtx, f32 s, f32 t, f32 x_offset, f32 y_offset, f32 scale, u16 *image_size) {
    f32 x;
    f32 y;

    x = ((s - image_size[0] * 0.5f) + x_offset) * scale;
    if (x >= 0.0f) {
        vtx->n.ob[0] = x + 0.5f;
    } else {
        vtx->n.ob[0] = x - 0.5f;
    }
    y = ((image_size[1] * 0.5f - t) + y_offset) * scale;
    if (y >= 0.0f) {
        vtx->n.ob[1] = y + 0.5f;
    } else {
        vtx->n.ob[1] = y - 0.5f;
    }
    vtx->n.ob[2] = 0;
    vtx->n.flag = 0;
    x = s * 32.0f;
    if (x >= 0.0f) {
        vtx->n.tc[0] = x + 0.5f;
    } else {
        vtx->n.tc[0] = x - 0.5f;
    }
    y = t * 32.0f;
    if (y >= 0.0f) {
        vtx->n.tc[1] = y + 0.5f;
    } else {
        vtx->n.tc[1] = y - 0.5f;
    }
    vtx->n.n[0] = vtx->n.n[1] = 0;
    vtx->n.n[2] = 127;
    vtx->n.a = 0xFF;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_32AEF0/func_87F08A94.s")

void func_87F08C08(s8 *arg0, void *arg1) {
    u8 temp_v0;

    temp_v0 = (*(u8 *)((u8 *)(arg1) + (5)));
    switch (temp_v0) {                              /* irregular */
    case 0:
        *arg0 = 1;
        return;
    case 1:
        *arg0 = 2;
        return;
    case 2:
        *arg0 = 4;
        return;
    case 3:
        *arg0 = 8;
        return;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_32AEF0/func_87F08C68.s")

extern void func_87F08C68(s8 *, void *);
extern s32 func_87F08A94(s8 *, void *);
extern s32 func_87F08280(s8 *, s32, void *, s32, s32, s32);
typedef struct {
    s8 record;
    u8 pad[7];
    f32 arg2;
    f32 arg3;
} Func87F08D6C_Local;
s32 func_87F08D6C(void *arg0, s32 arg1, f32 arg2, f32 arg3, s32 arg4, s32 arg5) {
    volatile Func87F08D6C_Local local;
    s32 result;

    if (arg0 == NULL) {
        result = 0;
    } else {
        local.arg2 = arg2;
        local.arg3 = arg3;
        func_87F08C08((s8 *)&local.record, arg0);
        func_87F08C68((s8 *)&local.record, arg0);
        result = func_87F08280((s8 *)&local.record, arg1, arg0, arg4, func_87F08A94((s8 *)&local.record, arg0), arg5);
    }
    return result;
}

extern s32 func_87F08D6C(void *, s32, f32, f32, s32, s32);
s32 func_87F08DF8(void *arg0, f32 arg1, f32 arg2, s32 arg3) {
    return func_87F08D6C(arg0, 0, arg1, arg2, arg3, 1);
}

s32 func_87F08E3C(void *arg0, s32 arg1) {
    return func_87F08D6C(arg0, 0, 0.0f, 0.0f, arg1, 1);
}

typedef struct {
    u16 first;
    u16 second;
    u8 third;
    u8 fourth;
} Func87F08E7C_Record;
s32 func_87F08E7C(u16 arg0, u16 arg1, u8 arg2, u8 arg3, s32 arg4) {
    Func87F08E7C_Record record;

    record.first = arg0;
    record.second = arg1;
    record.third = arg2;
    record.fourth = arg3;
    return func_87F08D6C(&record, 1, 0.0f, 0.0f, arg4, 1);
}

typedef struct {
    u16 first;
    u16 second;
    u8 third;
    u8 fourth;
} Func87F08EEC_Record;
void func_87F08EEC(u16 arg0, u16 arg1, u8 arg2, u8 arg3, f32 arg4, f32 arg5, s32 arg6) {
    Func87F08EEC_Record record;

    record.first = arg0;
    record.second = arg1;
    record.third = arg2;
    record.fourth = arg3;
    func_87F08D6C(&record, 1, arg4, arg5, arg6, 1);
}

s32 func_87F08F58(s32 arg0, s32 arg1) {
    return func_87F08D6C((void *)arg0, 0, 0.0f, 0.0f, arg1, 0);
}
#endif
