#include "global.h"


#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_279D70/func_86303F50.s")

/* mkdraft:func_863040C4 begin */
extern Gfx *D_800D0510;
extern u8 *D_8009491C;
extern u8 *D_863075D8;
extern s32 func_8004C990(s32, s32, Gfx **, u8 *);
extern s32 func_8004CA60(s32);
extern void func_8003CD84(void);



void func_863040C4(s32 arg0, s32 arg1) {
    u8 *node;

    if (arg0 == 5) {
        node = D_8009491C;
        gSPSegment(D_800D0510++, 0xF, func_8004CA60(func_8004C990(0x97, 0, &D_800D0510, node)));
        gDPPipeSync(D_800D0510++);
        gDPSetCombine(D_800D0510++, 0x371BFF, 0x5FFEFE38);
        {
            Gfx *_g = D_800D0510++;
            _g->words.w0 = 0xFA000000 | node[0x1D] | (node[0x1D] << 8);
            // FAKE: gDPSetPrimColor's w1 channels ORed green, blue, alpha, red;
            // diff score 575 with the macro's red, green, blue, alpha order.
            _g->words.w1 = _SHIFTL(node[0xA1], 16, 8) | _SHIFTL(node[0xA2], 8, 8) | _SHIFTL(node[0xA3], 0, 8) | _SHIFTL(node[0xA0], 24, 8);
        }
        gDPSetEnvColor(D_800D0510++, 0xFF, 0xFF, 0xFF, node[0x1D]);
        gSPDisplayList(D_800D0510++, *(s32 *)(D_863075D8 + 0x8F20));
        func_8003CD84();
    }
}
/* mkdraft:func_863040C4 end */

s32 func_87F026E8(s32, void *);
extern s32 D_87F119D8;
extern void *D_87F119DC;

void func_8630421C(void)
{
  s32 temp_v0;
  float new_var;
  ;
  if ((*((s32 *) (0x1C + ((u8 *) D_87F119DC)))) >= 8)
  {
    func_87F026E8(D_87F119D8, D_87F119DC);
    return;
  }
 dummy_label_621702: ;
  new_var = 1.0f - (((f32) (*((s32 *) (0x1C + ((u8 *) D_87F119DC))))) / 7.0f);
  temp_v0 = (s8) ((u32) (200.0f * new_var));
  *((s8 *) (((u8 *) D_87F119DC) + 0x41)) = temp_v0;
}
extern u8 *D_863075D8;
extern s32 D_86306FB8[][2];
extern void *func_87F025B8(void *, void *);
extern void func_8003F1DC(void *);
extern void func_8003F114(void *, s32, s32, s32);
void func_86304318(f32 x, f32 y, f32 z, f32 scale, u8 kind) {
    u8 *object;
    u8 *base;

    object = func_87F025B8(D_863075D8 + 0x1F84, func_8630421C);
    if (object != NULL) {
        base = object + 0x24;
        func_8003F1DC(base);
        func_8003F114(base, 0, -1, *(s32 *)(D_863075D8 + 0x128));
        *(f32 *)(object + 0x48) = x;
        *(f32 *)(object + 0x4C) = y;
        *(f32 *)(object + 0x50) = z;
        *(f32 *)(object + 0x54) = scale;
        *(f32 *)(object + 0x58) = scale;
        *(f32 *)(object + 0x5C) = scale;
        *(s32 *)(object + 0x60) = D_86306FB8[kind][1];
        *(s32 *)(object + 0xC4) = D_86306FB8[kind][0];
        object[0x26] |= 8;
    }
}

/* mkdraft:func_863043E4 begin */
extern f32 D_86307540;
extern f32 D_86307544;
extern s32 D_87F119D8;
extern void *D_87F119DC;
extern u8 *D_863075D8;
extern s32 D_86306FB8[][2];
extern s32 func_87F026E8(s32, void *);
extern void func_86304318(f32, f32, f32, f32, u8);

typedef struct unk_func_863043E4 {
    f32 x;
    f32 y;
    f32 z;
} unk_func_863043E4;



void func_863043E4(void)
{
    void *parent;
    void *owner;
    f32 scale;

    parent = *((void **) (((u8 *) D_87F119DC) + 0x38));
    if (!(*((s32 *) (((u8 *) parent) + 0xC)) & 1))
    {
        func_87F026E8(D_87F119D8, D_87F119DC);
    }
    else
    {
        // 0x38 of D_87F119DC is the object the callback was created with
        // (func_86304544 stores the owner there); its 0x20 pointer is the
        // record whose 0x20 kind byte selects the D_86306FB8 entry.
        //@src/fragments/51/fragment51_279D70.c
        scale = D_86307540;
        owner = *((void **) (((u8 *) parent) + 0x20));
        *((unk_func_863043E4 *) (((u8 *) D_87F119DC) + 0x48)) =
            *((unk_func_863043E4 *) (((u8 *) parent) + 0x48));
        *((unk_func_863043E4 *) (((u8 *) D_87F119DC) + 0x54)) =
            *((unk_func_863043E4 *) (((u8 *) parent) + 0x54));
        *((f32 *) (((u8 *) D_87F119DC) + 0x54)) *= scale;
        *((f32 *) (((u8 *) D_87F119DC) + 0x58)) *= scale;
        *((f32 *) (((u8 *) D_87F119DC) + 0x5C)) *= scale;
        *((s32 *) (((u8 *) D_87F119DC) + 0x60)) =
            D_86306FB8[*((s8 *) (((u8 *) owner) + 0x20)) + 1][1];
        *((s32 *) (((u8 *) D_87F119DC) + 0xC4)) =
            D_86306FB8[*((s8 *) (((u8 *) owner) + 0x20)) + 1][0];
        func_86304318(*((f32 *) (((u8 *) D_87F119DC) + 0x48)),
                      *((f32 *) (((u8 *) D_87F119DC) + 0x4C)),
                      *((f32 *) (((u8 *) D_87F119DC) + 0x50)),
                      *((f32 *) (((u8 *) D_87F119DC) + 0x5C)) * D_86307544,
                      *((s8 *) (((u8 *) owner) + 0x20)) + 1);
    }
    if (*((s32 *) D_863075D8) == 5)
    {
        func_87F026E8(D_87F119D8, D_87F119DC);
    }
}
/* mkdraft:func_863043E4 end */

extern f32 D_86307548;
extern void func_863043E4(void);
void func_86304544(u8 *parent) {
    u8 *object;

    object = func_87F025B8(D_863075D8 + 0x8298, func_863043E4);
    if (object != NULL) {
        f32 scale;
        u8 *owner;

        func_8003F1DC(object + 0x24);
        func_8003F114(object + 0x24, 0, -1, *(s32 *)(D_863075D8 + 0x124));
        scale = D_86307548;
        owner = *(u8 **)(parent + 0x20);
        *(u8 **)(object + 0x38) = parent;
        *(f32 *)(object + 0x54) = scale;
        *(f32 *)(object + 0x58) = scale;
        *(f32 *)(object + 0x5C) = scale;
        *(s32 *)(object + 0x60) = D_86306FB8[*(s8 *)(owner + 0x20) + 1][1];
        *(s32 *)(object + 0xC4) = D_86306FB8[*(s8 *)(owner + 0x20) + 1][0];
        object[0x41] = 255;
        object[0x26] |= 8;
    }
}
#endif
