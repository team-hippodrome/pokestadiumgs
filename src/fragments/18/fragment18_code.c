#include "global.h"


#ifdef VERSION_US
extern void _bzero(void *, s32);
extern s32 func_8004C8C0(s32);
extern void fragment18_main(u8 *);
extern s32 func_8170031C(u8 *);
extern s32 D_81700DA0;
extern u8 D_81700DB0[];
extern u8 D_81700E40[];
void fragment18_main(u8 *arg0) {
    _bzero(arg0, 0x24);
    *(s16 *)(arg0 + 0x00) = -1;
    *(s16 *)(arg0 + 0x02) = -1;
    *(s16 *)(arg0 + 0x04) = 0;
    *(s16 *)(arg0 + 0x06) = 0;
    *(s32 *)(arg0 + 0x08) = 0;
    *(s16 *)(arg0 + 0x0C) = 0;
    *(s16 *)(arg0 + 0x0E) = 0;
    *(s16 *)(arg0 + 0x10) = 0;
    *(s16 *)(arg0 + 0x12) = 0;
    *(s16 *)(arg0 + 0x14) = 0;
    *(s16 *)(arg0 + 0x16) = 0;
    *(s16 *)(arg0 + 0x18) = 0;
    *(s16 *)(arg0 + 0x1A) = 0xFF;
    *(s16 *)(arg0 + 0x1C) = 0;
    arg0[0x1E] = 0xFF;
    arg0[0x1F] = 0xFF;
    arg0[0x20] = 0xFF;
    arg0[0x21] = 0xFF;
    arg0[0x22] = 0xFF;
    arg0[0x23] = 0xFF;
}

s32 func_817000A4(void) {
    s32 i;

    D_81700DA0 = 0;
    D_81700DA0 = func_8004C8C0(0x13F);
    if (D_81700DA0 != 0) {
        func_8004C8C0(0x11C);
        for (i = 0; i < 4; i++) {
            fragment18_main(D_81700DB0 + i * 0x24);
        }
    }
    return D_81700DA0;
}

void func_81700120(void *arg0)
{
  s16 temp_v0;
  s16 temp_v1;
  *((s16 *) (((u8 *) arg0) + 0xE)) = (s16) ((*((s16 *) (((u8 *) arg0) + 0xE))) + 1);
  ;
  if ((*((s16 *) (((u8 *) arg0) + 0xE))) < 5)
  {
    temp_v1 = *((s16 *) (((u8 *) arg0) + 0x16));
    *((s16 *) (((u8 *) arg0) + 0x10)) = (s16) ((((s32) (((*((s16 *) (((u8 *) arg0) + 0x14))) - temp_v1) * (*((s16 *) (((u8 *) arg0) + 0xE))))) / 5) + (*((s16 *) (((u8 *) arg0) + 0x16))));
    return;
  }
  *((s16 *) (((u8 *) arg0) + 4)) = 2;
  *((s16 *) (((u8 *) arg0) + 0xE)) = 0;
  *((s16 *) (((u8 *) arg0) + 0x1C)) = 0;
  *((s16 *) (((u8 *) arg0) + 0x10)) = (s16) (*((s16 *) (((u8 *) arg0) + 0x14)));
}
void func_81700190(void *arg0) {
    s16 temp_v0;

    (*(s16 *)((u8 *)(arg0) + (0xE))) = (s16) ((*(s16 *)((u8 *)(arg0) + (0xE))) + 1);
    temp_v0 = (*(s16 *)((u8 *)(arg0) + (0xE)));
    if (temp_v0 < 0xA) {
        (*(s16 *)((u8 *)(arg0) + (0x1C))) = (s16) ((s32) (temp_v0 * 0xFF) / 10);
        return;
    }
    (*(s16 *)((u8 *)(arg0) + (0xE))) = 0xA;
    (*(s16 *)((u8 *)(arg0) + (0x1C))) = 0xFF;
}

void func_817001E0(void *arg0)
{
  s16 temp_v0;
  s16 temp_v1;
  *((s16 *) (((u8 *) arg0) + 0xE)) = (s16) ((*((s16 *) (((u8 *) arg0) + 0xE))) + 1);
  temp_v0 = *((s16 *) (((u8 *) arg0) + 0xE));
  if (temp_v0 < 5)
  {
    temp_v1 = 0xFF - (((s32) (temp_v0 * 0xFF)) / 5);
    if (1)
    {
      *((s16 *) (((u8 *) arg0) + 0x1C)) = temp_v1;
      *((s16 *) (((u8 *) arg0) + 0x1A)) = temp_v1;
    }
    return;
  }
  *((s16 *) (((u8 *) arg0) + 4)) = 0;
  *((s16 *) (((u8 *) arg0) + 0xE)) = 0;
  *((s16 *) (((u8 *) arg0) + 0x1A)) = 0;
  *((s16 *) (((u8 *) arg0) + 0x1C)) = 0;
}

/* mkdraft:func_8170024C begin */
s32 func_8170024C(void)
{
  s32 temp_v1;
  u8 *var_s0;
 do { temp_v1 = D_81700DA0; if (temp_v1 != 0) { var_s0 = D_81700DB0; do { s16 temp_v0; temp_v0 = (*((s16 *) (var_s0 + 4))); if (temp_v0 != 0) { switch (temp_v0) { case 1: func_81700120(var_s0); break; case 2: func_81700190(var_s0); break; case 3: func_817001E0(var_s0); break; } } var_s0 += 0x24; } while (var_s0 != D_81700E40); temp_v1 = D_81700DA0; } return temp_v1; } while (0);
}
/* mkdraft:func_8170024C end */

/* mkdraft:func_8170031C begin */
extern Gfx *D_800D0510;
extern u8 D_80094E38[];
extern u16 *func_8004C990(s32, s32);
extern s32 func_8004D1FC(u8 *);
extern s32 func_8004D19C(s32, s32, u16 *, s32, s32);
extern void func_800498C4(void);
extern void func_800496A4(s32, s32);
extern void func_8004972C(s32, s32, s32, s32);
extern void func_800495F8(s32, s32, s32, s32);
extern void func_800499EC(void);
extern s32 func_800472B8(s32);
extern void GfxRect_DrawTextured(s16, s16, s16, s16, s16, s16, s16, s16, s32);

// FAKE: IDO colors this addu with the freshly loaded mid[0] as the first operand;
// retail lists the coordinate x first. Without this rewrite the function scores 10:
// the only difference is the operand order of the addu at +0x18C.
#pragma REWRITE_FUNCTION_WORD(func_8170031C, 0x18C, 0x0302C821, 0x0058C821)



s32 func_8170031C(u8 *arg0) {
    s32 x;
    s32 textX;
    s32 innerX;
    s32 tile;
    s32 step;
    s32 alignment;
    u16 *capLeft;
    u16 *capRight;
    u16 *mid;
    u8 *env;
    s32 unused2;
    f32 scale;

    innerX = 0;
    capLeft = func_8004C990(0x13F, 0);
    capRight = func_8004C990(0x13F, 1);
    mid = NULL;
    if (*(s16 *)(arg0 + 0x10) > 0) {
        switch (*(s16 *)(arg0 + 0x18)) {
        case 1:
            mid = func_8004C990(0x11C, 0);
            break;
        case 2:
            mid = func_8004C990(0x11C, 1);
            break;
        }
        scale = (f32)*(s16 *)(arg0 + 0x10) / (f32)(u32)*capLeft;
        env = arg0 + 0x1E;
        if (*(u16 *)(arg0 + 0xC) & 2) {
            textX = *(s16 *)arg0 - 0x38;
            x = *(s16 *)arg0 - *(s16 *)(arg0 + 0x10);
            if (mid != NULL) {
                innerX = textX - *(s16 *)(arg0 + 0x12) - *mid - 2;
            }
            tile = (*capLeft - 1) << 5;
            step = (s32)((-1024.0f / scale) + (((-1024.0f / scale) > 0.0f) ? 0.5f : -0.5f));
            alignment = 2;
        } else {
            unused2 = *(s16 *)arg0;
            tile = unused2;
            x = tile;
            if (mid == NULL) {
                textX = x + 0x37;
            } else {
                textX = x + *mid + 0x39;
            }
            innerX = x + 0x37;
            tile = 0;
            step = (s32)((1024.0f / scale) + (((1024.0f / scale) > 0.0f) ? 0.5f : -0.5f));
            alignment = 0;
        }
        gSPDisplayList(D_800D0510++, D_80094E38);
        gDPSetColor(D_800D0510++, G_SETENVCOLOR, _SHIFTL(env[1], 16, 8) | _SHIFTL(env[2], 8, 8) | _SHIFTL(*(s16 *)(arg0 + 0x1A), 0, 8) | _SHIFTL(env[0], 24, 8));
        func_8004D1FC((u8 *)capLeft);
        GfxRect_DrawTextured(x, *(s16 *)(arg0 + 2), *(s16 *)(arg0 + 0x10), 2, tile, 0, step, 0x400, 0);
        GfxRect_DrawTextured(x, *(s16 *)(arg0 + 2) + 0x10, *(s16 *)(arg0 + 0x10), 2, tile, 0, step, 0x400, 0);
        scale = (f32)*(s16 *)(arg0 + 0x10) / (f32)(u32)*capRight;
        env = arg0 + 0x21;
        if (*(u16 *)(arg0 + 0xC) & 2) {
            tile = (*capRight - 1) << 5;
            step = (s32)((-1024.0f / scale) + (((-1024.0f / scale) > 0.0f) ? 0.5f : -0.5f));
        } else {
            tile = 0;
            step = (s32)((1024.0f / scale) + (((1024.0f / scale) > 0.0f) ? 0.5f : -0.5f));
        }
        gDPPipeSync(D_800D0510++);
        gDPSetColor(D_800D0510++, G_SETENVCOLOR, _SHIFTL(env[1], 16, 8) | _SHIFTL(env[2], 8, 8) | _SHIFTL(*(s16 *)(arg0 + 0x1A), 0, 8) | _SHIFTL(env[0], 24, 8));
        func_8004D1FC((u8 *)capRight);
        GfxRect_DrawTextured(x, *(s16 *)(arg0 + 2) + 2, *(s16 *)(arg0 + 0x10), 0xE, tile, 0, step, 0x400, 0);
        if (*(s16 *)(arg0 + 0x14) == *(s16 *)(arg0 + 0x10)) {
            s32 offset = 0xC - func_800472B8(*(s16 *)(arg0 + 6));

            if (mid != NULL) {
                s32 unused1 = 0xE - mid[1];

                gSPDisplayList(D_800D0510++, D_80094E38);
                gDPSetEnvColor(D_800D0510++, 0xFF, 0xFF, 0xFF, *(s16 *)(arg0 + 0x1C));
                func_8004D19C(innerX, *(s16 *)(arg0 + 2) + unused1, mid, 0, 0);
            }
            func_800498C4();
            func_800496A4(*(s16 *)(arg0 + 6), 0);
            func_8004972C(0, 0, 0, *(s16 *)(arg0 + 0x1C));
            func_800495F8(textX + 2, *(s16 *)(arg0 + 2) + offset + 2, alignment, *(s32 *)(arg0 + 8));
            func_8004972C(0xFF, 0xFF, 0xFF, *(s16 *)(arg0 + 0x1C));
            func_800495F8(textX, *(s16 *)(arg0 + 2) + offset, alignment, *(s32 *)(arg0 + 8));
            func_800499EC();
        }
    }
}
/* mkdraft:func_8170031C end */

extern void _bzero(void *, s32);
extern s32 func_8004C8C0(s32);
extern void func_81700020(u8 *);
extern s32 func_8170031C(u8 *);
extern s32 D_81700DA0;
extern u8 D_81700DB0[];
extern u8 D_81700E40[];
s32 func_81700908(void)
{
  s32 temp_v1;
  u8 *var_s0;
 do { temp_v1 = D_81700DA0; if (temp_v1 != 0) { var_s0 = D_81700DB0; do { if ((*((s16 *) (var_s0 + 4))) != 0) { func_8170031C(var_s0); } var_s0 += 0x24; } while (var_s0 != D_81700E40); temp_v1 = D_81700DA0; } return temp_v1; } while (0);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/18/fragment18_code/func_81700974.s")

s32 func_81700AF4(s32 arg0, void *arg1) {
    typedef struct { u8 bytes[4]; } Copy4;
    if (arg0 < 4) {
        *(Copy4 *)arg1 = *(Copy4 *)(D_81700DB0 + arg0 * 0x24);
    }
    return 0;
}

extern u8 D_81700DC0[];
s32 func_81700B2C(s32 arg0) { s32 result = 0; if (arg0 < 4) result = *(s16 *)((u8 *)D_81700DC0 + arg0 * 36); return result; }

extern u8 D_81700DBC[];
s32 func_81700B58(s32 arg0) { s32 result = 0; if (arg0 < 4) result = (*(u16 *)((u8 *)D_81700DBC + arg0 * 36) & 2) != 0; return result; }

/* mkdraft:func_81700B8C begin */
extern s16 func_80049148(s32, s32, s32);
extern u8 D_81700DB0[];
#pragma REWRITE_FUNCTION_WORD(func_81700B8C, 0x44, 0x00002825, 0x84640006)
#pragma REWRITE_FUNCTION_WORD(func_81700B8C, 0x48, 0x84640006, 0xAFA3001C)
#pragma REWRITE_FUNCTION_WORD(func_81700B8C, 0x50, 0xAFA3001C, 0x00002825)

s32 func_81700B8C(s32 arg0, s32 arg1) {
    u8 *entry;
    s32 result = 0;

    if (arg0 < 4 && arg1 != 0) {
        entry = D_81700DB0 + arg0 * 0x24;
        if (*(s32 *)(entry + 8) != arg1) {
            *(s32 *)(entry + 8) = arg1;
            *(s16 *)(entry + 0x12) = func_80049148(*(s16 *)(entry + 6), 0, arg1);
            *(s16 *)(entry + 0x14) = *(s16 *)(entry + 0x12) + 0x4B;
            result = 1;
        }
    }
    return result;
}
/* mkdraft:func_81700B8C end */

extern u8 D_81700DB0[];
s32 func_81700C0C(s32 arg0) { s32 result = 0; if (arg0 < 4) { u8 *ptr = D_81700DB0 + arg0 * 36; if ((*(u16 *)(ptr + 0xC) & 1) && *(s16 *)(ptr + 4) == 0) { result = 1; *(s16 *)(ptr + 4) = 1; *(s16 *)(ptr + 0xE) = 0; *(s16 *)(ptr + 0x16) = 0; *(s16 *)(ptr + 0x1A) = 0xFF; } } return result; }

s32 func_81700C70(s32 arg0) { s32 result = 0; if (arg0 < 4) { u8 *ptr = D_81700DB0 + arg0 * 36; if ((*(u16 *)(ptr + 0xC) & 1) && *(s16 *)(ptr + 4) == 0) { result = 1; *(s16 *)(ptr + 4) = 2; *(s16 *)(ptr + 0xE) = 10; *(s16 *)(ptr + 0x1A) = 0xFF; *(s16 *)(ptr + 0x1C) = 0xFF; *(s16 *)(ptr + 0x10) = *(s16 *)(ptr + 0x14); } } return result; }

s32 func_81700CDC(s32 arg0) { s32 result=0; if(arg0<4) { u8 *ptr=D_81700DB0+arg0*36; if((*(u16 *)(ptr+12)&1)!=0 && *(s16 *)(ptr+4)==2) { result=1; *(s16 *)(ptr+4)=1; *(s16 *)(ptr+14)=0; *(s16 *)(ptr+28)=0; *(s16 *)(ptr+22)=*(s16 *)(ptr+16); } } return result; }

s32 func_81700D44(s32 arg0) { s32 result=0; if(arg0<4) { u8 *ptr=&D_81700DB0[arg0*36]; if((*(u16 *)(ptr+12)&1)!=0 && *(s16 *)(ptr+4)==2) { result=1; *(s16 *)(ptr+4)=3; *(s16 *)(ptr+14)=0; } } return result; }
#pragma C_FUNCTION_PADDING(16)
#endif
