#include "global.h"


#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_279D70/func_86303F50.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_279D70/func_863040C4.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_279D70/func_863043E4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_279D70/func_86304544.s")
#endif
