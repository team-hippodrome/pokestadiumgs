#include "global.h"


#ifdef VERSION_US
extern void func_800476A0(void *, s32);
extern void func_800476FC(void *, s32);
extern s32 func_8004C990(s32, s32);
extern void func_80047738(s32, s32, s32, s32);
extern void func_80054210(void *);
extern void func_8005487C(void *);
extern void func_8005493C(void *);
extern void func_80055EF0(void *, s32);
extern u8 D_8F300E10[];
extern u8 D_8F300E14[];
extern u8 D_8F300F20[];
extern u8 D_8F300F28[];
extern u8 D_8F300F30[];
extern u8 D_8F300F40[];
extern u8 D_8F300F48[];
extern u8 D_8F300F60[];
extern u8 D_8F300F78[];
void func_8F300020(void) {
    *(s16 *)D_8F300F20 = 0;
    *(s16 *)(D_8F300F20 + 2) = 0;
    *(s32 *)(D_8F300F20 + 4) = 0;
    func_800476A0(D_8F300F78, 0x10);
    func_800476FC(D_8F300F78, 0x10);
    func_80047738(0, func_8004C990(0x33, 5), 0, 0);
    *(s32 *)D_8F300E10 = 0;
    *(s32 *)D_8F300E14 = 0;
    func_80054210(D_8F300F28);
    func_8005487C(D_8F300F30);
    func_8005493C(D_8F300F40);
    func_80055EF0(D_8F300F48, 0);
    func_80055EF0(D_8F300F60, 1);
}
void func_8F300020_padding(void) {}

/* mkdraft:func_8F3000E8 begin */
extern void Font_DisableTwoCycleTexturing(void);
extern void Font_EnableTwoCycleTexturing(void);
extern void func_800495F8(s32 x, s32 y, s32 mode, const char *format, ...);
extern void func_800496A4(s32 a0, s32 a1);
extern void func_8004972C(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_800497E4(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_800498C4(void);
extern void func_800499EC(void);
extern void *func_8004C874(s32 arg0, s32 arg1);

extern s8 D_8F300E3C;
extern s8 D_8F300E44;
extern s8 D_8F300E4C;
extern s8 D_8F300E54;
extern s8 D_8F300E5C;
extern s8 D_8F300E64;
extern s8 D_8F300E6C;
extern s8 D_8F300E74;
extern s8 D_8F300E7C;
extern s8 D_8F300E84;
extern s8 D_8F300E8C;
extern s8 D_8F300E94;
extern s8 D_8F300E9C;
extern s8 D_8F300EA4;
// Two-element halfword table at 0x8F300EAC (0x4E, 0x4F), indexed by the record
// selector D_8F300E14; provides string id 0x4E or 0x4F for the header line.
//@asm/us/data/fragments/71/fragment71_data.data.s
extern s16 D_8F300EAC[];
// Bytes 1-2 of the D_8F300F28 statistics block: the two per-record counters that
// rows 0 and 1 print. D_8F300F28 itself is declared as u8[] at the top of this file.
extern u8 D_8F300F29;
// Second halfword of the D_8F300F30 pair; bit 2 is the row-13 flag.
extern u16 D_8F300F32;

// Draws the 14-row statistics page: header strings, then one line per row at
// x = 320, y = 120 + 20 * row, each with a right-aligned label (format string
// D_8F300E3C and friends) and a value at the same position. The row selected by
// D_8F300E10 is drawn in yellow, the rest in white. Values come from the two
// counters at D_8F300F28, flag bit 2 of D_8F300F40 / D_8F300F32, and the 24-byte
// record at D_8F300F48 picked by D_8F300E14.
//@src/fragments/71/fragment71_code.c


void func_8F3000E8(void) {
    s32 i;
    s32 y;
    u8 *record;

    func_800498C4();
    Font_EnableTwoCycleTexturing();
    func_8004972C(0, 0, 0xFF, 0xFF);
    func_800497E4(0xFF, 0xFF, 0xFF, 0xFF);
    func_800496A4(8, 0);
    func_800495F8(0x140, 0x28, 1, func_8004C874(0x42, 0x4B));
    func_800495F8(0x3C, 0x3C, 0, func_8004C874(0x42, 0x5C));
    Font_DisableTwoCycleTexturing();
    func_800496A4(4, 0);
    func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
    func_800495F8(0x140, 0x64, 0, func_8004C874(0x42, D_8F300EAC[*(s32 *)D_8F300E14]));
    i = 0;
    do {
        record = D_8F300F48 + *(s32 *)D_8F300E14 * 0x18;
        if (i == *(s32 *)D_8F300E10) {
            func_8004972C(0xFF, 0xFF, 0, 0xFF);
        } else {
            func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
        }
        switch (i) {
        case 0:
            y = (i * 0x14) + 0x78;
            func_800495F8(0x140, y, 2, func_8004C874(0x42, 0x4C));
            func_800495F8(0x140, y, 0, &D_8F300E3C, D_8F300F28[0]);
            break;
        case 1:
            y = (i * 0x14) + 0x78;
            func_800495F8(0x140, y, 2, func_8004C874(0x42, 0x4D));
            func_800495F8(0x140, y, 0, &D_8F300E44, D_8F300F29);
            break;
        case 2:
            y = (i * 0x14) + 0x78;
            func_800495F8(0x140, y, 2, func_8004C874(0x42, 0x5B));
            func_800495F8(0x140, y, 0, &D_8F300E4C, (*(u16 *)D_8F300F40 & 4) != 0);
            break;
        case 3:
            y = (i * 0x14) + 0x78;
            func_800495F8(0x140, y, 2, func_8004C874(0x42, 0x50));
            func_800495F8(0x140, y, 0, &D_8F300E54, record[0xB]);
            break;
        case 4:
            y = (i * 0x14) + 0x78;
            func_800495F8(0x140, y, 2, func_8004C874(0x42, 0x51));
            func_800495F8(0x140, y, 0, &D_8F300E5C, record[0xA]);
            break;
        case 5:
            y = (i * 0x14) + 0x78;
            func_800495F8(0x140, y, 2, func_8004C874(0x42, 0x52));
            func_800495F8(0x140, y, 0, &D_8F300E64, record[6]);
            break;
        case 6:
            y = (i * 0x14) + 0x78;
            func_800495F8(0x140, y, 2, func_8004C874(0x42, 0x53));
            func_800495F8(0x140, y, 0, &D_8F300E6C, record[7]);
            break;
        case 7:
            y = (i * 0x14) + 0x78;
            func_800495F8(0x140, y, 2, func_8004C874(0x42, 0x54));
            func_800495F8(0x140, y, 0, &D_8F300E74, record[8]);
            break;
        case 8:
            y = (i * 0x14) + 0x78;
            func_800495F8(0x140, y, 2, func_8004C874(0x42, 0x55));
            func_800495F8(0x140, y, 0, &D_8F300E7C, record[9]);
            break;
        case 9:
            y = (i * 0x14) + 0x78;
            func_800495F8(0x140, y, 2, func_8004C874(0x42, 0x56));
            func_800495F8(0x140, y, 0, &D_8F300E84, *(u16 *)record);
            break;
        case 10:
            y = (i * 0x14) + 0x78;
            func_800495F8(0x140, y, 2, func_8004C874(0x42, 0x57));
            func_800495F8(0x140, y, 0, &D_8F300E8C, *(u16 *)(record + 2));
            break;
        case 11:
            y = (i * 0x14) + 0x78;
            func_800495F8(0x140, y, 2, func_8004C874(0x42, 0x58));
            func_800495F8(0x140, y, 0, &D_8F300E94, *(u16 *)(record + 4));
            break;
        case 12:
            y = (i * 0x14) + 0x78;
            func_800495F8(0x140, y, 2, func_8004C874(0x42, 0x59));
            func_800495F8(0x140, y, 0, &D_8F300E9C, record[0xC]);
            break;
        case 13:
            y = (i * 0x14) + 0x78;
            func_800495F8(0x140, y, 2, func_8004C874(0x42, 0x5A));
            func_800495F8(0x140, y, 0, &D_8F300EA4, (D_8F300F32 & 4) != 0);
            break;
        }
        i += 1;
    } while (i != 0xE);
    func_800499EC();
}
/* mkdraft:func_8F3000E8 end */

extern void GfxImage_FillCurrent(s32 *, s32);
extern void func_80008648();
extern void BgStage_DrawFrame();
extern void func_8F3000E8();
extern u8 D_800D0510;

void func_8F300770(void) {
    BgStage_DrawFrame();
    GfxImage_FillCurrent(&D_800D0510, 1);
    func_8F3000E8();
    func_80008648();
}

extern u8 *D_80087200;
extern void func_80054248(void *);
extern void func_800548C4(void *);
extern void func_80054974(void *);
extern void func_80055F6C(void *, s32);
extern void func_80051D64(s32, s32);

// Bits 0x800/0x400 of the halfword at D_80087200 + 0xC move the cursor D_8F300E10
// over items 0-13; in the halfword at D_80087200 + 8, bit 1 switches between the two
// 24-byte records at D_8F300F48, 0x8000 toggles the item under the cursor, and 0x4000
// passes D_8F300F28-D_8F300F60 to func_80054248 through func_80055F6C and returns 1.
s32 func_8F3007B0(void) {
    s32 result = 0;
    u8 *record;
    u8 *counter;

    if (*(u16 *)(D_80087200 + 0xC) & 0x800) {
        if (--*(s32 *)D_8F300E10 < 0) {
            *(s32 *)D_8F300E10 = 0;
        }
    }
    if (*(u16 *)(D_80087200 + 0xC) & 0x400) {
        if (++*(s32 *)D_8F300E10 >= 14) {
            *(s32 *)D_8F300E10 = 13;
        }
    }
    if (*(u16 *)(D_80087200 + 8) & 1) {
        *(s32 *)D_8F300E14 ^= 1;
    }
    record = D_8F300F48 + *(s32 *)D_8F300E14 * 24;
    counter = (*(s32 *)D_8F300E10 == 0) ? D_8F300F28 : D_8F300F28 + 1;
    if (*(u16 *)(D_80087200 + 8) & 0x8000) {
        switch (*(s32 *)D_8F300E10) {
            case 0:
            case 1:
                if (++*counter >= 3) {
                    *counter = 0;
                }
                break;
            case 2:
                if (*(u16 *)D_8F300F40 & 4) {
                    *(u16 *)D_8F300F40 &= ~4;
                } else {
                    *(u16 *)D_8F300F40 |= 4;
                }
                break;
            case 3:
                if (record[0xB] == 0) {
                    record[0xB] = 1;
                } else {
                    record[0xB] = 0;
                }
                break;
            case 4:
                if (record[0xA] == 0) {
                    record[0xA] = 1;
                } else {
                    record[0xA] = 0;
                }
                break;
            case 5:
                if (record[6] == 0) {
                    record[6] = 15;
                } else {
                    record[6] = 0;
                }
                break;
            case 6:
                if (record[7] == 0) {
                    record[7] = 15;
                } else {
                    record[7] = 0;
                }
                break;
            case 7:
                if (record[8] == 0) {
                    record[8] = 15;
                } else {
                    record[8] = 0;
                }
                break;
            case 8:
                if (record[9] == 0) {
                    record[9] = 15;
                } else {
                    record[9] = 0;
                }
                break;
            case 9:
                if (*(u16 *)(record + 0) == 0) {
                    *(u16 *)(record + 0) = 0xFFFF;
                } else {
                    *(u16 *)(record + 0) = 0;
                }
                break;
            case 10:
                if (*(u16 *)(record + 2) == 0) {
                    *(u16 *)(record + 2) = 0xFF;
                } else {
                    *(u16 *)(record + 2) = 0;
                }
                break;
            case 11:
                if (*(u16 *)(record + 4) == 0) {
                    *(u16 *)(record + 4) = 0xFFFF;
                } else {
                    *(u16 *)(record + 4) = 0;
                }
                break;
            case 12:
                if (record[0xC] == 0) {
                    record[0xC] = 0xFF;
                } else {
                    record[0xC] = 0;
                }
                break;
            case 13:
                if (*(u16 *)(D_8F300F30 + 2) & 4) {
                    *(u16 *)(D_8F300F30 + 2) &= ~4;
                } else {
                    *(u16 *)(D_8F300F30 + 2) |= 4;
                }
                break;
        }
    } else if (*(u16 *)(D_80087200 + 8) & 0x4000) {
        func_80054248(D_8F300F28);
        func_800548C4(D_8F300F30);
        func_80054974(D_8F300F40);
        func_80055F6C(D_8F300F48, 0);
        func_80055F6C(D_8F300F60, 1);
        func_80051D64(20, 0);
        result = 1;
    }
    return result;
}

/* mkdraft:func_8F300AD0 begin */
extern s32 D_8F300F24;
extern u8 StageContext_GetFadeMode(void);
extern s32 StageFade_StartFromTransparent(s32);

// Stage-1 update: 0 waits for the fade mode, 1 applies the controller-driven fade
// value, 2 waits for func_8F3007B0, 3 advances once the fade mode reaches 1.


s32 func_8F300AD0(s32 arg0)
{
  u8 *var_v1;
  s32 var_v0;
  s16 *counter;
  u8 **base;
  s32 *D_8F300F24_ptr;

  counter = (s16 *)D_8F300F20;
  var_v0 = arg0;
  base = &D_80087200;
  D_8F300F24_ptr = &D_8F300F24;
  switch (var_v0)
  {
    case 0:
      if (!StageContext_GetFadeMode())
      {
        var_v0 = 2;
      }
      break;

    case 1:
      // D_80087200 holds the controller state pointer. Retail keeps it in a local
      // that is re-read from the global after every store, which is what the
      // lui/lw relocations in front of each lhu 0xC test show; writing the
      // dereference inline at every use instead folds the address into a
      // lui/addiu pair and does not reproduce those loads.
      var_v1 = *base;
      if (*(u16 *)(var_v1 + 0xC) & 0x800)
      {
        if ((*D_8F300F24_ptr) != 0)
        {
          (*D_8F300F24_ptr) -= 8;
          var_v1 = *base;
        }
      }
      if (*(u16 *)(var_v1 + 0xC) & 0x400)
      {
        (*D_8F300F24_ptr) += 8;
        var_v1 = *base;
      }
      if (*(u16 *)(var_v1 + 0xC) & 8)
      {
        if ((*D_8F300F24_ptr) != 0)
        {
          (*D_8F300F24_ptr) -= 0x1000;
          var_v1 = *base;
        }
      }
      if (*(u16 *)(var_v1 + 0xC) & 4)
      {
        (*D_8F300F24_ptr) += 0x1000;
        var_v1 = *base;
      }
      // 0x200 steps D_8F300F20 (an s16 counter, clamped to [0, 3)) down; 0x100
      // steps it up. The pointer is re-read inside each clamp arm, not after it:
      // the retail lui v0,%hi(D_80087200) lands between the clamp add and the
      // sh, and the lw follows the sh.
      if (*(u16 *)(var_v1 + 0xC) & 0x200)
      {
        if ((*counter) > 0)
        {
          (*counter)--;
          var_v1 = *base;
        }
      }
      if (*(u16 *)(var_v1 + 0xC) & 0x100)
      {
        if ((*counter) < 3)
        {
          (*counter)++;
          var_v1 = *base;
        }
      }
      // 0x4000 of the halfword at +0x8 (buttonsPressed) starts the fade-out and
      // advances to state 3.
      if (*(u16 *)(var_v1 + 8) & 0x4000)
      {
        var_v0 = 3;
        StageFade_StartFromTransparent(5);
      }
      break;

    case 2:
      if (func_8F3007B0())
      {
        var_v0 = 3;
        StageFade_StartFromTransparent(5);
      }
      break;

    case 3:
      if (StageContext_GetFadeMode() == 1)
      {
        var_v0 = 4;
      }
      break;

  }

  return var_v0;
}
/* mkdraft:func_8F300AD0 end */

extern void StageFade_StartFromOpaque(s32);
extern void func_800086A4(s32);
extern void func_80064D28();
s32 func_8F300AD0(s32);
void func_8F300CAC(void) {
    s32 temp_v0;
    s32 var_s0;

    var_s0 = 0;
    func_800086A4(2);
    StageFade_StartFromOpaque(5);
    do {
        func_80064D28();
        func_8F300770();
        temp_v0 = func_8F300AD0(var_s0);
        var_s0 = temp_v0;
    } while (temp_v0 != 4);
}

extern void main_pool_push_state(s32);
extern void main_pool_pop_state(s32);
extern void Gfx_InitDisplayListBuffers(s32, s32);
extern s32 StageContext_Allocate(s32, s32, s32, s32, s32, s32);
extern void func_8004C09C(s32);
extern void func_8004C4B0(s32);
extern void func_8004C8C0(s32);
extern void func_80047588(s32, s32);
extern void Asset_LoadToSegment(s32, u8 *, u8 *, s32);
extern void func_80055A34(void);
extern void func_8F300020(void);
extern void func_80008514(s32);
extern void func_8F300CAC(void);
extern void func_80008574(void);
extern void func_80055028(void);
extern void func_80047610(void);
extern void func_8004C398(void);
extern void Gfx_FreeDisplayListBuffers(void);
extern u8 D_1000000[];
extern u8 D_446E30[];
extern u8 D_447D00[];
s32 fragment71_main(s32 arg0, s32 arg1) {
    s32 sp24;
    main_pool_push_state(0x424B4544);
    Gfx_InitDisplayListBuffers(0x10000, 0);
    sp24 = StageContext_Allocate(1, 0, 2, 0, 2, 1);
    func_8004C09C(3);
    func_8004C4B0(0x42);
    func_8004C8C0(0x33);
    func_80047588(0xD, 0);
    Asset_LoadToSegment(((u32)&D_1000000 & 0x0F000000) >> 24, &D_446E30, D_447D00, 0);
    func_80055A34();
    func_8F300020();
    func_80008514(sp24);
    func_8F300CAC();
    func_80008574();
    func_80055028();
    func_80047610();
    func_8004C398();
    Gfx_FreeDisplayListBuffers();
    main_pool_pop_state(0x424B4544);
    return 0;
}
#endif
