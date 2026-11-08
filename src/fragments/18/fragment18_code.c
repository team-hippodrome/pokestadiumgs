#include "global.h"
typedef struct unk_D_81700DB0 {
    s16 unk_00, unk_02, unk_04, font;
    const char *text;
    u16 flags;
    s16 unk_0E, unk_10, width, width_with_margin, unk_16, unk_18, unk_1A, unk_1C;
    u8 unk_1E[6];
} unk_D_81700DB0;


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

// IDO 7.1 puts the more complex operand subtree in src1 of addu. Writing the
// coordinate as a plain local in this arm makes the *mid load win src1 and the
// addu comes out as t9,t8,v0. Re-reading arg0[0] here keeps the load as the
// right-hand operand (tie -> right operand first), which reproduces retail's
// t9,v0,t8. Same value, CSE'd to the single lh v0.



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
            x = *(s16 *)arg0;
            if (mid == NULL) {
                textX = *(s16 *)arg0 + 0x37;
            } else {
                textX = *mid + *(s16 *)arg0 + 0x39;
            }
            innerX = *(s16 *)arg0 + 0x37;
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

/* mkdraft:func_81700974 begin */
extern u8 D_81700DB0[];
extern u16 *func_8004C990(s32, s32);
extern s32 func_80049148(s32, s32, const char *, ...);

// Fills in the 0x24-byte move record D_81700DB0[arg0] and returns 1, or returns 0
// when arg0 >= 4 or the record's s16 at +4 is already non-zero. Stores, in order:
// +0x00 arg1, +0x02 arg2, +0x06 arg3, +0x1C 0xFF (all s16), +0x08 arg4 (s32),
// then the three bytes of *arg5 at +0x1E and the three bytes of *arg6 at +0x21,
// each copied as a 3-byte struct (IDO emits the copy byte by byte and reuses the
// first byte register for the third, which is what the retail code does; six
// separate u8 stores give the same instructions but a different allocation).
// The s16 at +0x18 is 0 when arg7 == 0, else 2 for arg3 == 0x10 and 1 otherwise;
// the two non-zero arms call func_8004C990(0x11C, 1 or 0) and keep its result as a
// u16 pointer. When arg4 != 0, +0x12 is func_80049148(arg3, 0, arg4) and +0x14 is
// that value plus 0x4B, plus *lookup + 2 when lookup is non-NULL; when arg4 == 0,
// +0x14 is 0. Bit 0 of the u16 at +0x0C is always set, and bit 1 of it as well
// when arg0 is odd.
//
// Both the struct copy and the un-named *((s16 *) (entry + 4)) test are needed:
// naming that test in a local reserves a register for it and shifts the whole
// temporary allocation by one, and expanding the copies to six u8 stores loses
// the byte-register reuse.


s32 func_81700974(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 *arg5,
                  u8 *arg6, s32 arg7) {
    s32 result = 0;
    u16 *lookup = 0;
    u8 *new_var;
    u8 *entry;
    typedef struct { u8 a, b, c; } Color;

    if (arg0 < 4) {
        entry = D_81700DB0 + arg0 * 36;
        if (*((s16 *) (entry + 4)) == 0) {
            new_var = entry;
            result = 1;
            *((s16 *) (new_var + 0x00)) = arg1;
            *((s16 *) (new_var + 0x02)) = arg2;
            *((s32 *) (entry + 0x08)) = arg4;
            *((s16 *) (new_var + 0x06)) = arg3;
            *((s16 *) (new_var + 0x1C)) = 0xFF;
            *(Color *) (entry + 0x1E) = *(Color *) arg5;
            *(Color *) (entry + 0x21) = *(Color *) arg6;
            if (arg7 != 0) {
                if (arg3 == 0x10) {
                    *((s16 *) (new_var + 0x18)) = 2;
                    lookup = (u16 *) func_8004C990(0x11C, 1);
                } else {
                    *((s16 *) (new_var + 0x18)) = 1;
                    lookup = (u16 *) func_8004C990(0x11C, 0);
                }
            } else {
                *((s16 *) (entry + 0x18)) = 0;
            }
            if (arg4 != 0) {
                *((s16 *) (new_var + 0x12)) = func_80049148(arg3, 0, arg4);
                *((s16 *) (entry + 0x14)) = (*((s16 *) (entry + 0x12))) + 0x4B;
                if (lookup != 0) {
                    *((s16 *) (entry + 0x14)) += (*lookup) + 2;
                }
            } else {
                *((s16 *) (new_var + 0x14)) = 0;
            }
            *((u16 *) (new_var + 0x0C)) |= 1;
            if (arg0 & 1) {
                *((u16 *) (entry + 0x0C)) |= 2;
            }
        }
    }
    return result;
}
/* mkdraft:func_81700974 end */

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
extern s32 func_80049148(s32, s32, const char *, ...);
extern u8 D_81700DB0[];

s32 func_81700B8C(s32 arg0, const char *arg1) {
    unk_D_81700DB0 *entry;
    s32 result = 0;

    // Unsigned address arithmetic remains defined for indices skipped below.
    // Only the guarded path reads or writes the entry.
    entry = (unk_D_81700DB0 *)((u32)D_81700DB0 + (u32)arg0 * 36U);
    if (arg0 < 4 && arg1 != NULL) {
        if (entry->text != arg1) {
            entry->text = arg1;
            entry->width = func_80049148(entry->font, 0, arg1);
            entry->width_with_margin = entry->width + 75;
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
