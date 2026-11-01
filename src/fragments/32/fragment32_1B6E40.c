#include "global.h"


#ifdef VERSION_US
typedef struct {
    s16 x;
    s16 y;
    u16 width;
    u16 height;
} Bounds_88305B30;

typedef struct {
    u8 unused[6];
    Bounds_88305B30 current;
    Bounds_88305B30 initial;
} State_88305B30;

void func_88305B30(State_88305B30 *arg0, s16 arg1, s16 arg2, u16 arg3, u16 arg4) {
    arg0->current.x = arg1;
    arg0->current.y = arg2;
    arg0->current.width = arg3;
    arg0->current.height = arg4;
    arg0->initial = arg0->current;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/32/fragment32_1B6E40/func_88305B84.s")

/* mkdraft:func_88305CA8 begin */
extern u8 D_88308E38;
extern s32 D_88308930;
extern u16 D_88308DF8;
extern u8 D_88308E09;
extern u8 D_88308E0B;
extern u8 D_88308E0C;
extern u8 D_88308E0D;
extern u8 D_88308E0E;
extern u8 D_88308E10;
extern s8 D_88308E30;
extern u8 *D_8860189C;
extern void func_800226C0(s32);
extern void func_80026068(u32);
extern void func_8830058C(u8);
extern void func_88307FB0(void *);

// One 0x18-byte element of D_88308E38, the array traversed by func_8830602C,
// func_8830609C, func_8830639C and func_88306404. Those functions only reach the
// 0x0 state word and the 0x4 byte; this one also uses the 0x5 progress byte and
// the two boxes that func_8830639C reads at 0x6 and func_88305B30 fills at 0x6
// and 0xE. The fields span 4 + 1 + 1 + 8 + 8 = 22 bytes, padded to the 0x18
// stride.
typedef struct {
    s32 state;
    u8 unk_04;
    s8 progress;
    Bounds_88305B30 current;
    Bounds_88305B30 initial;
} unk_func_88305CA8;



void func_88305CA8(void) {
    Bounds_88305B30 *cur;
    Bounds_88305B30 *init;
    f32 ratio;
    s32 half;
    s32 node_index;
    unk_func_88305CA8 *node;

    for (node_index = 0, node = (unk_func_88305CA8 *) &D_88308E38; node_index != 4;
            node_index++, node++) {
        switch (node->state) {
        case 0:
            // Wind up: advance progress until it reaches D_88308E30, then restart
            // this node's animation from its initial box.
            node->progress++;
            if (node->progress != D_88308E30) {
                break;
            }

            node->state = 1;
            node->current = node->initial;
            node->unk_04 = 2;

            if (node_index == 1) {
                // The second node synchronizes the shared banner bytes with the
                // current D_88308930 mode.
                D_88308E0C = 2;
                D_88308E0E = 2;
                D_88308E10 = 2;
                D_88308E09 = 2;

                switch (D_88308930) {
                case 0:
                case 1:
                case 2:
                    D_88308E0B = 2;
                    break;
                }

                switch (D_88308930) {
                case 0:
                case 2:
                case 3:
                    func_800226C0(74);
                    D_88308E0D = 2;
                    if (D_88308930 == 0) {
                        func_88307FB0(D_8860189C);
                    }
                    break;
                case 1:
                    func_8830058C(2);
                    func_80026068((D_88308DF8 >= 254) ? 201 : D_88308DF8);
                    break;
                }
            }
            continue;
        case 2:
            // Wind down: run progress back to -1 and release the node.
            node->progress--;
            if (node->progress == -1) {
                node->state = 0;
            }
            break;
        case 1:
            // Hold: count unk_04 down to zero.
            if (node->unk_04 != 0) {
                node->unk_04--;
            }
            continue;
        }

        // Progress rises 0..D_88308E30/2 while the node grows, then folds back
        // below the half point while it shrinks.
        half = D_88308E30 >> 1;
        if (half >= node->progress) {
            ratio = (f32) node->progress / (f32) half;
        } else {
            ratio = (f32) (node->progress - half) / (f32) half;
        }

        cur = &node->current;
        init = &node->initial;
        if (node->progress < 0) {
            // Collapsed: fixed 0x10 by 0x20 box.
            cur->width = 0x10;
            cur->height = 0x20;
        } else if (half >= node->progress) {
            // Growing: interpolate the width, hold the height.
            cur->width = (s32) ((f32) (init->width - 0x10) * ratio
                    + (((f32) (init->width - 0x10) * ratio) > 0.0f ? 0.5f : -0.5f)) + 0x10;
            cur->height = 0x10;
        } else {
            // Shrinking: hold the width, interpolate the height.
            cur->width = init->width;
            cur->height = (s32) ((f32) (init->height - 0x10) * ratio
                    + (((f32) (init->height - 0x10) * ratio) > 0.0f ? 0.5f : -0.5f)) + 0x10;
        }

        cur->x = init->x + (init->width >> 1) - (cur->width >> 1);
        cur->y = init->y + (init->height >> 1) - (cur->height >> 1);
    }
}
/* mkdraft:func_88305CA8 end */

typedef struct unk_D_88308E38 {
    s32 unk_00;
    u8 unk_04;
    u8 unk_05[19];
} unk_D_88308E38;

extern u8 D_88308E38;

s32 func_8830602C(void) {
    unk_D_88308E38* var_v0;
    s32 var_a0;

    for (var_v0 = (unk_D_88308E38*)&D_88308E38, var_a0 = 0; var_a0 < 4; var_a0++, var_v0++) {
        if (var_v0->unk_04 != 0) {
            return 1;
        }
    }
    return 0;
}

s32 func_8830609C(void) {
    unk_D_88308E38* var_v0;
    s32 var_a0;

    for (var_v0 = (unk_D_88308E38*)&D_88308E38, var_a0 = 0; var_a0 < 4; var_a0++, var_v0++) {
        if (var_v0->unk_00 != 1) {
            return 0;
        }
    }
    return 1;
}

/* mkdraft:func_8830610C begin */
extern void GfxRect_DrawTextured(s16, s16, s16, s16, s16, s16, s16, s16, s32);

// Draws the 8-pixel border of the width x height box at (x, y) from one texture.
// The four 8x8 corner tiles are drawn at full texture scale; each edge repeats the
// adjacent corner's first row or column (dsdx or dtdy 0). The interior is not drawn.
// Nothing is drawn for boxes narrower or shorter than 0x10 pixels.


void func_8830610C(s16 x, s16 y, u16 width, u16 height) {
    if ((width < 0x10) || (height < 0x10)) {
        return;
    }
    GfxRect_DrawTextured(x, y, 8, 8, -0x10, 0xF0, 0x400, 0x400, 0);
    GfxRect_DrawTextured(x + width - 8, y, 8, 8, 0xF0, 0xF0, 0x400, 0x400, 0);
    GfxRect_DrawTextured(x, y + height - 8, 8, 8, -0x10, -0x10, 0x400, 0x400, 0);
    GfxRect_DrawTextured(x + width - 8, y + height - 8, 8, 8, 0xF0, -0x10, 0x400, 0x400, 0);
    GfxRect_DrawTextured(x, y + 8, 8, height - 0x10, -0x10, -0x10, 0x400, 0, 0);
    GfxRect_DrawTextured(x + width - 8, y + 8, 8, height - 0x10, 0xF0, -0x10, 0x400, 0, 0);
    GfxRect_DrawTextured(x + 8, y, width - 0x10, 8, 0xD0, 0xF0, 0, 0x400, 0);
    GfxRect_DrawTextured(x + 8, y + height - 8, width - 0x10, 8, 0xD0, -0x10, 0, 0x400, 0);
}
/* mkdraft:func_8830610C end */

extern void func_8830610C(s16, s16, u16, u16);
extern u8 D_88308E38;
void func_8830639C(void) {
    s32 var_s1;
    u8 *var_s0;

    var_s0 = &D_88308E38;
    var_s1 = 0;
    do {
        if ((*(u8 *)((u8 *)(var_s0) + (4))) != 0) {
            func_8830610C((*(s16 *)((u8 *)(var_s0) + (6))), (*(s16 *)((u8 *)(var_s0) + (8))), (*(u16 *)((u8 *)(var_s0) + (0xA))), (*(u16 *)((u8 *)(var_s0) + (0xC))));
        }
        var_s1 += 1;
        var_s0 += 0x18;
    } while (var_s1 != 4);
}


void func_88306404(s32 arg0) {
    void *temp_v0;

    temp_v0 = (arg0 * 0x18) + &D_88308E38;
    (*(s32 *)((u8 *)(temp_v0) + (0))) = 2;
    (*(s8 *)((u8 *)(temp_v0) + (4))) = 1;
}

s32 func_800601A4(s8, s32);
extern s8 D_88006868;
extern u8 *D_88601890;
extern void **D_88601898;

void func_88306430(void)
{
  unsigned char new_var;
  s32 temp_t9;
  u32 var_s0;
  void **var_s1;
  var_s1 = D_88601898;
  var_s0 = 0;
  if ((*((u8 *) (((u8 *) D_88601890) + (((0x38E & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF)))) != 0)
  {
    do
    {
      temp_t9 = func_800601A4(D_88006868, var_s0 & (0xFF & 0xFF)) * 2;
      new_var = 4;
      new_var = 1;
      var_s0 += new_var;
      *var_s1 = (D_88601890 + temp_t9) - -0x20C;
      var_s1 += new_var;
    }
    while (var_s0 < ((u8) (*((u8 *) (((u8 *) D_88601890) + 0x38E)))));
  }
}
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/32/fragment32_1B6E40/func_883064C8.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/32/fragment32_1B6E40/func_883067C4.s")

extern u8 D_88006880[];
extern u8 *D_8860189C;
extern u8 D_88601896;
extern s8 D_88601894[];
extern s32 func_80001FF0(void);
extern void func_88001C6C(void *, u16, u8, s16, u8, s16, s16, s16, s16, s16, s32);
extern void *Util_Malloc(s32);
extern s32 func_80060110(s32);
extern s32 func_80064700(s32);
void func_883064C8(s32);
extern s8 D_88006868;
extern u8 * D_88601890;
extern void ** D_88601898;
void func_88306B24(void) {
    u32 i;
    u16 *p;

    D_8860189C = D_88006880;
    func_88001C6C(D_8860189C, D_88601896, 7, 0x40, 30, 15,
                  (s32)(720.0f / func_80001FF0() + ((720.0f / func_80001FF0() > 0.0f) ? 0.5f : -0.5f)),
                  42, 42, 0xF00, 70);
    D_88601898 = Util_Malloc(0x3EC);
    D_88601894[0] = D_88601894[1] = 0;
    *(s32 *)(D_88601890 + 0x244) = 0;
    p = (u16 *)(D_88601890 + 0x18);
    for (i = 1; i < 0xFC; i++, p++) {
        if (i == 0xC9) {
            *p = func_80064700((u8)func_80060110(D_88006868));
        } else {
            *p = i;
        }
    }
    p = (u16 *)(D_88601890 + 0x20E);
    *p++ = 0xC9;
    *p++ = 0xFE;
    for (i = 1; i < 0x19; i++, p++) {
        *p = i + 0xFE;
    }
    func_883064C8(*(s32 *)D_88601890);
}
#endif
