#include "global.h"
#include "controller.h"


#ifdef VERSION_US
extern void Input_SetRepeatController(s32);
extern s32 D_880068B8;

void func_88229110(void) {
    Input_SetRepeatController(D_80087200);
    D_880068B8 = 0;
}

typedef struct {
    u8 unused[0x1AC];
    u8 selected;
    u8 padding[7];
    void (*callback)(void);
} Cleanup_88229138;
extern u32 D_882348B0;
extern s32 D_880068B4;
extern void func_88001900(void);
extern void Util_Free(s32);
void func_88229138(void) {
    Cleanup_88229138 *state = (Cleanup_88229138 *)D_882348B0;

    if (state->selected != 0) {
        state->callback();
    } else {
        Input_SetRepeatController(D_80087200);
        func_88001900();
        D_880068B4 = 1;
    }
    Util_Free((s32)D_882348B0);
}

/* mkdraft:func_882291A4 begin */
extern u32 D_882348B0;
extern s8 D_88006868;
extern s8 D_8800EF40;
extern s8 D_8800EF41;
extern s32 D_880068B8;
extern s32 func_8005A228(s8);
extern void func_800226C0(s32);
extern void func_88004990(u8, s32);
extern void func_88002720(void *, u16, void *);
extern s32 func_88201048(void);
extern s32 func_8004C8A0(void *, s32, s32, s32);
extern s32 func_8004C874(s32, s32);
extern s32 func_800472B8(s32);
extern s32 Envelope_Advance(void *);

typedef struct {
    /* 0x000 */ void *unk_00;
    /* 0x004 */ s16 unk_04;
    /* 0x006 */ s16 unk_06;
    /* 0x008 */ s32 unk_08;
    /* 0x00C */ s32 unk_0C;
    /* 0x010 */ s32 unk_10;
    /* 0x014 */ u8 unk_14[6];
    /* 0x01A */ s16 unk_1A;
    /* 0x01C */ u8 unk_1C[0x1AC - 0x1C];
    /* 0x1AC */ u8 unk_1AC;
    /* 0x1AD */ u8 unk_1AD;
    /* 0x1AE */ u8 unk_1AE;
    /* 0x1AF */ s8 unk_1AF;
    /* 0x1B0 */ s8 unk_1B0;
    /* 0x1B1 */ s8 unk_1B1;
} unk_D_882348B0;

// Every field access re-reads the global D_882348B0 rather than caching the
// pointer in a local: the calls in this function may replace the object.


void func_882291A4(void) {
    s32 pressed;
    u8 *p;

    if (((unk_D_882348B0 *)D_882348B0)->unk_1AE != 0) {
        if (((unk_D_882348B0 *)D_882348B0)->unk_1AE == (((unk_D_882348B0 *)D_882348B0)->unk_1AD + 2)) {
            if (((unk_D_882348B0 *)D_882348B0)->unk_1AF == 1) {
                switch (func_8005A228(D_88006868)) {
                case 1:
                    ((unk_D_882348B0 *)D_882348B0)->unk_1B1 = 1;
                    break;
                case 3:
                    ((unk_D_882348B0 *)D_882348B0)->unk_1B1 = 3;
                    break;
                case 2:
                    ((unk_D_882348B0 *)D_882348B0)->unk_1AF = 2;
                    ((unk_D_882348B0 *)D_882348B0)->unk_1B0 = 3;
                    ((unk_D_882348B0 *)D_882348B0)->unk_1B1 = 0;
                    break;
                }
            }
            if (((unk_D_882348B0 *)D_882348B0)->unk_1AF == 2) {
                ((unk_D_882348B0 *)D_882348B0)->unk_1B0 = ((unk_D_882348B0 *)D_882348B0)->unk_1B0 - 1;
                if (((unk_D_882348B0 *)D_882348B0)->unk_1B0 == 1) {
                    func_800226C0(0x12C);
                } else if (((unk_D_882348B0 *)D_882348B0)->unk_1B0 <= 0) {
                    ((unk_D_882348B0 *)D_882348B0)->unk_1AF = 0;
                    ((unk_D_882348B0 *)D_882348B0)->unk_1B0 = 0;
                }
            }
            if (((unk_D_882348B0 *)D_882348B0)->unk_1AF == 0) {
                if (func_88201048() != 0) {
                    func_800226C0(0x12D);
                    func_88004990(*(u8 *)((unk_D_882348B0 *)D_882348B0)->unk_00, 0);
                    D_880068B8 = 1;
                    ((unk_D_882348B0 *)D_882348B0)->unk_1AC = 1;
                    ((unk_D_882348B0 *)D_882348B0)->unk_1B1 = -1;
                } else {
                    ((unk_D_882348B0 *)D_882348B0)->unk_1AF = 1;
                    func_800226C0(0x61);
                    ((unk_D_882348B0 *)D_882348B0)->unk_1B1 = 2;
                    switch (func_8005A228(D_88006868)) {
                    case 1:
                        ((unk_D_882348B0 *)D_882348B0)->unk_1B1 = 1;
                        break;
                    case 3:
                        ((unk_D_882348B0 *)D_882348B0)->unk_1B1 = 3;
                        break;
                    }
                }
            }
        } else {
            ((unk_D_882348B0 *)D_882348B0)->unk_1AE = ((unk_D_882348B0 *)D_882348B0)->unk_1AE + 1;
        }
    } else {
        p = (u8 *)D_882348B0 + 0x20;
        sprintf((char *)((u8 *)D_882348B0 + 0x54), "<COL1,LOAD,240,120,30,%d>", Envelope_Advance((u8 *)D_882348B0 + 0x1A0));
        ((unk_D_882348B0 *)D_882348B0)->unk_0C = func_8004C8A0((u8 *)D_882348B0 + 0x94, 0x100, 0x27, 1);
        pressed = D_80087200->buttonsPressed;
        if (pressed & 0x4000) {
            func_800226C0(0x48);
            func_88004990(*(u8 *)((unk_D_882348B0 *)D_882348B0)->unk_00, 0);
            D_880068B8 = 1;
            ((unk_D_882348B0 *)D_882348B0)->unk_1AC = 0;
        } else if (pressed & 0x8000) {
            if (*(s16 *)(p + 0x28) == 0) {
                func_800226C0(0x12C);
                ((unk_D_882348B0 *)D_882348B0)->unk_10 = 0x10;
                ((unk_D_882348B0 *)D_882348B0)->unk_04 =
                    (*(u16 *)((u8 *)((unk_D_882348B0 *)D_882348B0)->unk_00 + 0x10) >> 1) +
                    *(s16 *)((u8 *)((unk_D_882348B0 *)D_882348B0)->unk_00 + 0xC);
                ((unk_D_882348B0 *)D_882348B0)->unk_06 =
                    ((unk_D_882348B0 *)D_882348B0)->unk_06 +
                    ((((unk_D_882348B0 *)D_882348B0)->unk_1A - ((unk_D_882348B0 *)D_882348B0)->unk_06 - 6) >> 1) -
                    (func_800472B8(((unk_D_882348B0 *)D_882348B0)->unk_10) >> 1);
                ((unk_D_882348B0 *)D_882348B0)->unk_08 = 1;
                ((unk_D_882348B0 *)D_882348B0)->unk_0C = func_8004C874(0x27, 3);
                *(s32 *)(p + 0x24) = 2;
                ((unk_D_882348B0 *)D_882348B0)->unk_1AE = 1;
            } else {
                func_88004990(*(u8 *)((unk_D_882348B0 *)D_882348B0)->unk_00, 0);
                D_880068B8 = 1;
                ((unk_D_882348B0 *)D_882348B0)->unk_1AC = 2 - *(s16 *)(p + 0x28);
                if (*(s16 *)(p + 0x28) == 1) {
                    func_800226C0(0x12E);
                } else {
                    func_800226C0(0x48);
                }
            }
        } else {
            func_88002720(p + 0x28, *(u16 *)(p + 0xC), p + 0x2C);
        }
    }
    D_8800EF40 = ((unk_D_882348B0 *)D_882348B0)->unk_1B1;
    if (((unk_D_882348B0 *)D_882348B0)->unk_1B1 != -1) {
        D_8800EF41 = D_88006868;
    }
}
/* mkdraft:func_882291A4 end */

extern u32 D_882348B0;
extern void func_8821D930(s32);
void func_882295BC(void) {
    func_8821D930((D_882348B0 + 4));
}

extern void *Util_Malloc(u32);
extern u8 D_88006020[];
extern u8 D_8800ED50[];
extern u32 Credits_RandomRange(u32);
extern s32 func_80001FF0(void);
extern s32 func_8004C54C(s32, s32);
extern s32 func_8004C874(s32, s32);
extern void func_88000288(void *, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_88002AA8(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, void *);
extern s32 func_88004804(void *, s32, s16, s16, s32, s32, s32, s32, s32, s32 *, s32 *, s32 *, s32 *, s32, s32);
extern int sprintf(char *, const char *, ...);

extern u32 D_882348B0;
extern s32 D_880068B4;

// Spawns the "<COL1,LOAD,240,120,30,%d>" load/credits object: allocates 0x1B8 bytes at
// D_882348B0 and fills a display-list head, four rounded random values, a formatted string at
// +0x54, a palette/sprite block via func_8004C8A0 at +0x94, and a callback record whose
// func_88004804 result indexes the 0x4C-stride table D_8800ED50. Each rounded value is
// (draw * K / 60) + bias, truncated to s32, where bias is +0.5 or -0.5 by the sign of a
// second draw, giving round-to-nearest for K = 19, 7, 3, 6 and 30 (the last one at +0x1AD
// goes through Credits_RandomRange).
//
// The format string is passed as a plain literal, not as a named array. Retail keeps two
// copies of it in this object's .rodata (0x882343E0 from the func_882291A4 chunk and
// 0x882343FC from this function, each 4-byte aligned, 0x1C bytes apart); a literal inside the
// function reproduces that whether func_882291A4 is GLOBAL_ASM or C. Once func_882291A4 is C,
// a `const char D_882343FC[] = ...` definition would duplicate its already-emitted literal
// and shift .rodata by 0x20.
//
// FAKE: the four live values use separate 8-byte structs named d, c, b, a, declared in that
// reverse order. IDO hands stack slots out by declaration order, so the order is what puts
// a.draw at 0x5c and leaves 0x58 untouched. Declaring them a, b, c, d scores 234 and moves
// both slots (lw t1,0x88(sp) becomes lw t1,0x78(sp)).
// FAKE: `struct { f32 x; } e;` is never read in the emitted code (no instruction touches
// 0x58); it exists to reserve the 0x58 slot at the arena bottom. Writing the a-term inline
// instead, with no e and no a-term new_var, shrinks the frame to 0x70 and scores 285.
// FAKE: `new_var` feeds the a-term product at 0x5c; writing `(19.0f * ((f32) a.raw))` inline
// scores 285 (same variant as above), and `(7.0f * ((f32) b.raw))` inline in the b-term
// scores 850.
// FAKE: the `* 1.0f` factors on b.spread, c.spread and d.spread fix IDO's operand order for
// add.s (retail emits `add.s $ft5,$ft2,$ft4`, bias first). Dropping one scores 100 (b, which
// is the pre-fix intermediate's score too), 650 (c), 40 (d, both uses: the 6/60 term and the
// 30/60 term handed to Credits_RandomRange), and 770 with all three dropped.
// The struct tag `_PermuterAnon1` is a placeholder name with no known meaning.


void func_882295E4(s16 arg0, s16 arg1, s32 arg2)
{
  u8 i;
  struct _PermuterAnon1
  {
    s32 raw;
    f32 spread;
  } d;
  struct _PermuterAnon1 c;
  struct _PermuterAnon1 b;
  struct _PermuterAnon1 a;
  struct { f32 x; } e;
  f32 new_var;
  D_882348B0 = (u32) Util_Malloc(0x1B8);
  for (i = 0; i < 3; i++)
  {
    ((s32 *) (((u8 *) D_882348B0) + 0x194))[i] = func_8004C874(0x27, i + 4);
  }

  func_88002AA8(((u8 *) D_882348B0) + 0x20, 0, ((u8 *) D_882348B0) + 0x194, 3, 8, 1, 6, 0, 0, 0, 0, 0, 0, D_88006020);
  a.raw = func_80001FF0();
  a.spread = (((((f32) func_80001FF0()) * 19.0f) / 60.0f) > 0.0f) ? (0.5f) : (-0.5f);
  b.raw = func_80001FF0();
  b.spread = (((((f32) func_80001FF0()) * 7.0f) / 60.0f) > 0.0f) ? (0.5f) : (-0.5f);
  new_var = (f32) a.raw;
  e.x = (19.0f * new_var) / 60.0f;
  c.raw = func_80001FF0();
  c.spread = (((((f32) func_80001FF0()) * 3.0f) / 60.0f) > 0.0f) ? (0.5f) : (-0.5f);
  d.raw = func_80001FF0();

  d.spread = (((((f32) func_80001FF0()) * 6.0f) / 60.0f) > 0.0f) ? (0.5f) : (-0.5f);

  new_var = (f32) b.raw;

  func_88000288(((u8 *) D_882348B0) + 0x1A0, 0, 0xFF, 0x1E, (s32) (a.spread + e.x), (s32) ((b.spread * 1.0f) + ((7.0f * new_var) / 60.0f)), (s32) ((c.spread * 1.0f) + ((3.0f * ((f32) c.raw)) / 60.0f)), (s32) ((d.spread * 1.0f) + ((6.0f * ((f32) d.raw)) / 60.0f)));

  sprintf((char *) (((u8 *) D_882348B0) + 0x54), "<COL1,LOAD,240,120,30,%d>", *((s16 *) (((u8 *) D_882348B0) + 0x1A2)));
  func_8004C54C(0x47, (s32) (((u8 *) D_882348B0) + 0x54));
  *((void **) (((u8 *) D_882348B0) + 0xC)) = func_8004C8A0(((u8 *) D_882348B0) + 0x94, 0x100, 0x27, 1);
  *((s32 *) (((u8 *) D_882348B0) + 8)) = 0;
  *((s32 *) (((u8 *) D_882348B0) + 0x10)) = 4;
  *((s16 *) (((u8 *) D_882348B0) + 0x14)) = 1;
  *((s16 *) (((u8 *) D_882348B0) + 0x16)) = 4;

  *((void **) (((u8 *) D_882348B0) + 0)) = (void *) ((func_88004804(((u8 *) D_882348B0) + 4, 2, arg0, arg1, 4, 1, 0xDC, 0xDC, 0xB4, &func_882291A4, (s32 *) func_882295BC, (s32 *) func_88229110, (s32 *) func_88229138, 0, 0) * 0x4C) + D_8800ED50);
  D_880068B4 = 0;
  *((s32 *) (((u8 *) D_882348B0) + 0x1B4)) = arg2;

  d.raw = func_80001FF0();
  d.spread = (((((f32) func_80001FF0()) * 30.0f) / 60.0f) > 0.0f) ? (0.5f) : (-0.5f);

  *((s8 *) (((u8 *) D_882348B0) + 0x1AD)) = Credits_RandomRange((u32) ((s32) ((d.spread * 1.0f) + ((30.0f * ((f32) d.raw)) / 60.0f))));

  *((s8 *) (((u8 *) D_882348B0) + 0x1AE)) = 0;
  *((s8 *) (((u8 *) D_882348B0) + 0x1AF)) = 0;
  *((s8 *) (((u8 *) D_882348B0) + 0x1B0)) = 0;
  *((s8 *) (((u8 *) D_882348B0) + 0x1B1)) = -1;
}
#endif
