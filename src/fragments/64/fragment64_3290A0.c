#include "global.h"


#ifdef VERSION_US
/* mkdraft:func_87F06430 begin */
extern f32 D_80087E50[];
extern f32 D_80088E50[0x1000];

// Writes a three-component vector to arg0; callers copy the components in order into
// consecutive f64 fields of a position. x varies with the row index arg1, y is constant
// and z is zero. Both x and y are scaled by the sine/cosine ratio (a tangent) at table
// element 113, byte offset 0x1C4.


void func_87F06430(f32 *arg0, s32 arg1) {
    arg0[0] = D_80087E50[113] / D_80088E50[113] * 1000.0f * 1.3333334f * (2.0f * ((46.5f + (f32) arg1 * 39.0f) / 320.0f) - 1.0f);
    arg0[1] = D_80087E50[113] / D_80088E50[113] * 1000.0f * 0.45416665f;
    arg0[2] = 0.0f;
}
/* mkdraft:func_87F06430 end */

s32 func_87F064DC(s32 arg0, s32 arg1) {
    return 1;
}

s32 func_87F064EC(s32 arg0) {
    s32 result;

    switch (arg0) {
        case 97: result = 0; break;
        case 110: result = 10; break;
        case 106: result = 5; break;
        case 108: result = 8; break;
        case 103: result = 7; break;
        case 105: result = 11; break;
        case 100: result = 6; break;
        case 111: result = 9; break;
        case 107: result = 2; break;
        case 109: result = 1; break;
        case 153: result = 4; break;
        case 154: result = 3; break;
        default: result = 0; break;
    }
    return result;
}

s32 func_87F065B4(s32 move, s32 base, u8 *item) {
    s32 offset;

    switch (move) {
    case 97:
        offset = 0;
        break;
    case 110:
        offset = 4;
        break;
    case 106:
        switch (*item) {
        case 0xAC:
            offset = 0x8;
            break;
        case 0x19:
            offset = 0xC;
            break;
        }
        break;
    case 108:
        switch (*item) {
        case 0xAF:
            offset = 0x10;
            break;
        case 0x8A:
            offset = 0x14;
            break;
        }
        break;
    case 103:
        switch (*item) {
        case 0xAD:
            offset = 0x18;
            break;
        case 0xAE:
            offset = 0x1C;
            break;
        }
        break;
    case 105:
        offset = 0x20;
        break;
    case 100:
        offset = 0x24;
        break;
    case 111:
        offset = 0x28;
        break;
    case 107:
        switch (*item) {
        case 0x7F:
            offset = 0x2C;
            break;
        case 0x7B:
            offset = 0x30;
            break;
        case 0xD4:
            offset = 0x34;
            break;
        }
        break;
    case 109:
        offset = 0x38;
        break;
    case 0x99:
        offset = 0x3C;
        break;
    case 0x9A:
        offset = 0x40;
        break;
    default:
        offset = 0;
        break;
    }
    return offset + base;
}

/* mkdraft:func_87F06734 begin */
void func_87F06734(s32 a0, u8 *out_base, u8 *src_base)
{
  s32 i = 0;
  const s32 count;
  u8 *new_var;
  const s32 flag_one = 1;
  u8 *out_ptr = out_base;
  u8 *flag_ptr = out_base;
  u8 *src_ptr = src_base;
  while (i != 4)
  {
    s32 idx = func_87F064EC(a0);
    u8 *entry = *((u8 **) ((new_var = src_ptr) + (idx << 2)));
    if ((*((s8 *) entry)) == 0)
    {
      s32 tmp = func_87F065B4(a0, i, (s32) (entry + 4));
      s32 res = func_8004C874(0x44, tmp);
      *((s32 *) (out_ptr + 0x14)) = res;
      *((s8 *) (flag_ptr + 0x24)) = 0;
    }
    else
    {
      *((s32 *) (out_ptr + 0x14)) = (s32) (entry + 0x38);
      *((s8 *) (flag_ptr + 0x24)) = flag_one;
      do
      {
      }
      while (0);
    }
    i++;
    src_ptr += 0x6C0;
    out_ptr += 4;
    flag_ptr += 1;
    if (i)
    {
    }
  }

}
/* mkdraft:func_87F06734 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_3290A0/func_87F06804.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_3290A0/func_87F0691C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_3290A0/func_87F06AA8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_3290A0/func_87F06D24.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_3290A0/func_87F06EAC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_3290A0/func_87F0785C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/64/fragment64_3290A0/func_87F07FE8.s")

s32 func_87F08208(u8 *arg0) {
    s32 result = 0;
    u32 flags;

    flags = func_87F0E610(arg0 + 0x2C, func_80001FF0() * 2);
    if (flags & 0x1000) {
        result = 1;
    } else if (((*(u8 **)(arg0 + 0x30))[0x2180] == 0) &&
               (u16)(flags & 0x4000)) { // FAKE: u16 cast of the masked flags; diff score 10 without it.
        result = 2;
    }
    return result;
}
#endif
