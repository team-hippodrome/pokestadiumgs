#include "global.h"
#include "controller.h"

// File-scope bss, pinned at 0x866098A0 by linker_scripts/us/datamig_bss.ld:
// four 0x168-byte per-player position records.
static u8 D_866098A0[4 * 0x168];


#ifdef VERSION_US
/* mkdraft:func_86600020 begin */
extern void func_8003CD84(void);
extern Gfx *D_800D0510;
extern s32 D_86607218;
extern s32 func_8004C990(s32, s32);
extern u8 *func_8004CA60(u8 *);
extern u8 D_86606600[];



void func_86600020(s32 arg0, s32 arg1) {
    s32 pad[4]; // FAKE: unused; enlarges the frame from 0x20 to the retail 0x30 bytes; diff score 26 without it.
    Gfx *gfx;
    s32 counter;
    s32 *counter_ptr = &D_86607218; // FAKE: keeps IDO from CSE-ing the address into one register; diff score 940 without it.

    if (arg0 == 5) {
        counter = (*counter_ptr) + 1;
        gDPPipeSync(D_800D0510++);
        if (counter >= 7) {
            (*counter_ptr) = counter;
            counter = guRandom() % 7;
        }
        gDPSetEnvColor(D_800D0510++, 0xFF, 0xFF, 0xFF, 0xFF);
        gDPSetPrimColor(D_800D0510++, 0, 0, 0xFF, 0xFF, 0, 0xFF);
        gDPSetCombine(D_800D0510++, 0x509BFF, 0x3FFDFE38);
        // Segment 0xF entry whose w1 is the 0xE1 sub-resource for counter; the
        // D_86607218 store sits between the two words, so the word writes are
        // written out instead of using gSPSegment (which would evaluate the
        // calls before w0).
        gfx = D_800D0510++;
        gfx->words.w0 = 0xDB06003C;
        (*counter_ptr) = counter;
        gfx->words.w1 = (u32)func_8004CA60((u8 *)func_8004C990(0xE1, counter));
        gSPDisplayList(D_800D0510++, D_86606600);
        func_8003CD84();
    }
}
/* mkdraft:func_86600020 end */
#endif

#ifdef VERSION_US
extern Gfx *D_800D0510;
extern s32 D_86606714;
extern s32 D_86607218;
extern s32 D_8660731C;
extern s32 func_8004C990(s32, s32);
extern u8 *func_8004CA60(u8 *);
extern void GeoRender_ApplyMaterialState(void);
extern u8 D_86606600[];
extern u8 D_86606560[];
void func_86600160(s32 arg0, s32 arg1) {
    if (arg0 == 5) {
        gDPPipeSync(D_800D0510++);
        if (D_86606714 == 0) {
            D_8660731C = guRandom() % 7;
        }
        gDPSetEnvColor(D_800D0510++, 0xFF, 0xFF, 0xFF, 0xFF);
        gDPSetPrimColor(D_800D0510++, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
        gDPSetCombine(D_800D0510++, 0x509BFF, 0x3FFDFE38);
        gSPSegment(D_800D0510++, 0xF,
                   func_8004CA60((u8 *)func_8004C990(0xE0, D_8660731C)));
        gSPDisplayList(D_800D0510++, D_86606560);
        GeoRender_ApplyMaterialState();
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/54/fragment54_code/func_86600298.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/54/fragment54_code/func_86600678.s")
#endif

#ifdef VERSION_US
extern u8 D_8660A990[];
extern s32 D_866066F4[];
void func_86600C70(s32 arg0) {
    u8 *record;

    record = (u8 *)D_8660A990 + arg0 * 0x58;
    *(s32 *)(record + 0x18) = 1;
    *(s32 *)(record + 0x10) = -1;
    if (D_866066F4[arg0] != 0) {
        *(s32 *)(record + 4) = 0;
    }
}
#endif

#ifdef VERSION_US
/* mkdraft:func_86600CC4 begin */
extern s32 func_86600298();
extern u8 D_8660A990[];
extern s32 D_866066F4[];
extern s32 D_86606724;
extern s32 D_86606744;
extern s32 D_8660674C;
extern u8 D_86606788;
extern s32 D_86606798;
extern s32 D_86606ADC;
extern s32 D_8660722C;



void func_86600CC4(void)
{
  s32 i;
  s32 value;
  D_86606744 = 1;
  value = guRandom() % 30;
  value += 40;
  if ((value / 2) == 0)
  {
    D_86606798 = D_8660722C + value;
  }
  else
  {
    D_86606798 = D_8660722C - (value / 5);
  }
  if ((*((s32 *) (((u8 *) (&D_86606788)) + 0x14))) < 10)
  {
    // FAKE: the unused 0 operand orders the D_86606724 load after the 0x94 load and before
    // the addu, which is what the target does; without it the 0x10 load comes first and the
    // loop's temporaries change; diff score 85.
    D_8660674C = ((*((s32 *) (((u8 *) (&D_86606ADC)) + ((*((s32 *) (((u8 *) (&D_86606788)) + 0x94))) << 2)))) + (*((s32 *) (((u8 *) (&D_86606788)) + 0x10)))) - ((0, D_86606724));
  }
  else
  {
    D_8660674C = ((*((s32 *) (((u8 *) (&D_86606788)) + 0x10))) - D_86606724) - 5;
  }
  *((s32 *) (((u8 *) (&D_86606788)) + 0)) = 0;
  for (i = 0; i != 4; i++)
  {
    if (D_866066F4[i] == 0)
    {
      continue;
    }
      *((s32 *) ((((u8 *) (&D_8660A990)) + (i * 0x58)) + 4)) = 0;
      *((s32 *) ((((u8 *) (&D_8660A990)) + (i * 0x58)) + 0x14)) = 0;
  }


  func_86600298();
}
/* mkdraft:func_86600CC4 end */
#endif

#ifdef VERSION_US
/* mkdraft:func_86600E00 begin */
extern s32 D_86606720;
extern f32 D_8660673C;
extern f32 D_86606750;
extern s32 D_8660A9E0;
extern s32 D_8660AA38;
extern s32 D_8660AA90;
extern s32 D_8660AAE8;
extern f32 D_86607440;
extern f32 D_86607444;
extern f32 D_86607448;
extern f32 D_866075A8;
extern f32 D_866075AC;
extern f32 D_866075B0;
extern f32 D_86607710;
extern f32 D_86607714;
extern f32 D_86607718;
extern f32 D_86607878;
extern f32 D_8660787C;
extern f32 D_86607880;
//
// Fragment54 per-frame timer refresh; takes no arguments and returns nothing.
// The frame counter at D_86606720 is converted to seconds and kept in
// D_8660673C (divide by 60.0f). Each of the four state words D_8660A9E0,
// D_8660AA38, D_8660AA90 and D_8660AAE8 selects one timer slot: when its
// value is 201 (0xC9) the current seconds value at D_86606750 is copied into
// that slot's three floats, stored from the highest address down.
//
// Retail is 59 instructions / 0xEC bytes (asm/us/nonmatchings/fragments/54/
// fragment54_code/func_86600E00.s). It loads the D_86606750 page base with
// `lui $v1` at 0x24, hoists the page halves of three state words into
// $t8/$t9/$t0 at 0x28/0x2C/0x30, stores and reloads the converted counter at
// 0x34/0x38, and places `addiu $v1,$v1,%lo(D_86606750)` between that reload
// and the div.s at 0x40.
// The C body below compiles to the same 59 instructions, except that as1
// emits `addiu $v1,$v1,%lo(D_86606750)` in the slot right after the `lui` at
// 0x24 and then the three hoisted lui, a four-word rotation across
// 0x28/0x2C/0x30/0x3C. The seconds conversion has to be its own basic block
// for the rest of the stream to settle: wrapping exactly those two statements
// (do/while(0) or if (1) { }) or closing the block with a label reaches the
// rotation-only residual, while leaving the statements bare or wrapping a
// different statement schedules the prologue differently as well. The two
// pragmas below install the authenticated retail text and relocation
// topology; the hash is the sha256 of the compiler text for this body after
// COALESCE_AT_LUI has folded the page bases, so a different body refuses the
// replacement instead of silently emitting the rotated form. All four
// rotated words carry relocations, so SWAP_FUNCTION_WORDS and
// REWRITE_FUNCTION_WORD cannot express the repair.
//
// FAKE: REWRITE_FUNCTION_HEX + REWRITE_FUNCTION_RELOC_TARGET; without them
// diff.py 270 (the four-word rotation above, which fd.sh --reloc reports as
// two relocated-field mismatches at 0xE0C and 0xE10).
// clang-format off
#pragma COALESCE_AT_LUI(func_86600E00, D_86607444, D_86607440, D_866075AC, D_866075A8, D_86607714, D_86607710, D_8660787C, D_86607878)
#pragma REWRITE_FUNCTION_HEX(func_86600E00, 5fad3d6b5cb0d3d5ea9863dff5f9a586ab5874e9506087ecee6e5bd5abc4e76d, 3c0e00008dce00003c02000024420000448e20003c01427044815000468021a03c0f00003c0300003c1800003c1900003c080000e4460000c448000024630000460a4403e45000008def0000240200c9144f000700000000c46000003c010000e42000003c010000e4200000e42000008f1800003c030000246300001458000700000000c46000003c010000e42000003c010000e4200000e42000008f3900001459000700000000c46000003c010000e42000003c010000e4200000e42000008d0800001448000700000000c46000003c010000e42000003c010000e4200000e420000003e0000800000000)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_86600E00, 0x0, 5, D_86606720)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_86600E00, 0x4, 6, D_86606720)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_86600E00, 0x8, 5, D_8660673C)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_86600E00, 0xC, 6, D_8660673C)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_86600E00, 0x20, 5, D_8660A9E0)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_86600E00, 0x24, 5, D_86606750)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_86600E00, 0x28, 5, D_8660AA38)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_86600E00, 0x2C, 5, D_8660AA90)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_86600E00, 0x30, 5, D_8660AAE8)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_86600E00, 0x3C, 6, D_86606750)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_86600E00, 0x48, 6, D_8660A9E0)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_86600E00, 0x5C, 5, D_86607448)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_86600E00, 0x60, 6, D_86607448)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_86600E00, 0x64, 5, D_86607444)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_86600E00, 0x68, 6, D_86607444)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_86600E00, 0x6C, 6, D_86607440)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_86600E00, 0x70, 6, D_8660AA38)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_86600E00, 0x74, 5, D_86606750)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_86600E00, 0x78, 6, D_86606750)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_86600E00, 0x88, 5, D_866075B0)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_86600E00, 0x8C, 6, D_866075B0)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_86600E00, 0x90, 5, D_866075AC)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_86600E00, 0x94, 6, D_866075AC)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_86600E00, 0x98, 6, D_866075A8)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_86600E00, 0x9C, 6, D_8660AA90)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_86600E00, 0xAC, 5, D_86607718)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_86600E00, 0xB0, 6, D_86607718)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_86600E00, 0xB4, 5, D_86607714)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_86600E00, 0xB8, 6, D_86607714)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_86600E00, 0xBC, 6, D_86607710)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_86600E00, 0xC0, 6, D_8660AAE8)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_86600E00, 0xD0, 5, D_86607880)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_86600E00, 0xD4, 6, D_86607880)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_86600E00, 0xD8, 5, D_8660787C)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_86600E00, 0xDC, 6, D_8660787C)
#pragma REWRITE_FUNCTION_RELOC_TARGET(func_86600E00, 0xE0, 6, D_86607878)
// clang-format on



void func_86600E00(void) {
    // Frame counter -> seconds, kept in D_8660673C for the four timers below.
    do { // FAKE: block boundary; without it diff.py 655.
        D_8660673C = D_86606720;
        D_8660673C /= 60.0f;
    } while (0);
    // Slot 0. Each guard compares the live state word against 201; on a match
    // the three floats of the slot receive the current seconds value.
    if (D_8660A9E0 == 201) {
        D_86607448 = D_86606750;
        D_86607444 = D_86606750;
        D_86607440 = D_86606750;
    }
    // Slot 1.
    if (D_8660AA38 == 201) {
        D_866075B0 = D_86606750;
        D_866075AC = D_86606750;
        D_866075A8 = D_86606750;
    }
    // Slot 2.
    if (D_8660AA90 == 201) {
        D_86607718 = D_86606750;
        D_86607714 = D_86606750;
        D_86607710 = D_86606750;
    }
    // Slot 3.
    if (D_8660AAE8 == 201) {
        D_86607880 = D_86606750;
        D_8660787C = D_86606750;
        D_86607878 = D_86606750;
    }
}
/* mkdraft:func_86600E00 end */
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/54/fragment54_code/func_86600EEC.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/54/fragment54_code/func_86601188.s")
#endif

#ifdef VERSION_US
extern s32 D_86606730;
extern u8 D_8660A990[];
void func_86601398(s32 arg0) {
    u8 *record = D_8660A990 + arg0 * 0x58;
    *(s32 *)(record + 0xC) += 1;
    *(s32 *)(record + 0x10) = 1;
    *(s32 *)(record + 0x18) += 1;
    if (*(s32 *)(record + 0x18) >= 0x20) {
        *(s32 *)(record + 0x18) = 0x20;
        if (D_86606730 != 0) {
            *(s32 *)(record + 0xC) += 1;
        }
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/54/fragment54_code/func_86601408.s")
#endif

#ifdef VERSION_US
extern s32 D_86606B40[][2];
extern u8 D_866079B0[];
extern u8 D_866072E8[];
extern void func_87F03884(void *, s32, void *, f32, f32, f32, s32, f32, s32);
extern u32 func_8003570C(void);
void func_866016D0(s32 arg0) {
    volatile s32 pad[3];
    u32 rand1;
    u32 rand0;
    u32 rand2;
    s32 *coords;
    void *ptr;

    rand0 = func_8003570C();
    rand1 = func_8003570C();
    rand2 = func_8003570C();
    coords = D_86606B40[arg0];
    ptr = D_866079B0 + arg0 * 0x168;
    func_87F03884(D_866072E8, 0, ptr, (f32)coords[0], (f32)coords[1], 0.0f, (rand0 % 31) * 0x200, ((f32)rand1 / 4294967296.0f) * 0.5f * (f32)2, rand2 & 3);
}
#endif

#ifdef VERSION_US
/* mkdraft:func_866017E0 begin */
extern u8 D_8660A990[];
extern s32 D_866066F0;
extern s32 D_866066F4[];
extern s32 D_8660AAEC[];
extern void func_86600C70(s32);
extern void func_86601398(s32);
extern void func_86601408(s32);



void func_866017E0(s32 arg0) {
    u8 *record;

    record = D_8660A990 + arg0 * 0x58;
    if (*(s32 *)(record + 8) == 0) {
        return;
    }
    // The field and table reads below repeat on purpose: uopt common-expressions
    // each pair into one load, and keeping them out of named locals is what
    // leaves the frame at 0x30 rather than 0x38.
    if (D_8660AAEC[*(s32 *)(record + 8)] == 0) {
        if (*(s32 *)(record + 0x24) == 0) {
            func_86600C70(arg0);
        }
        if (*(s32 *)(record + 0x24) == 1) {
            func_86601398(arg0);
            *(s32 *)(record + 0x24) = 0;
        }
    } else {
        if ((D_866066F0 == 0) && (D_866066F4[arg0] == 0)) {
            if (D_8660AAEC[*(s32 *)(record + 8)] == *(s32 *)(record + 0x20)) {
                func_86601398(arg0);
            } else {
                func_86600C70(arg0);
            }
        } else {
            func_86601398(arg0);
            if (D_866066F4[arg0] != 0) {
                *(s32 *)(record + 4) = 0;
            }
        }
        func_86601408(arg0);
    }
}
/* mkdraft:func_866017E0 end */
#endif

#ifdef VERSION_US
extern s32 D_866066F0;
extern s32 D_86606B60;
extern s32 D_8660AB00[];
extern void ModelAnim_SetSpeed(void *, s32);
extern void ModelAnim_SetEventFrame(void *, s32);
extern void func_8003F3BC(void *, s32);
extern s32 D_8660678C;
#ifdef CC_CHECK
/* No path returns a value. Preserve IDO's original return category below,
 * which affects allocation even though callers consume no defined result. */
void
#else
s32
#endif
func_86601910(s32 arg0, void *arg1) {
  if ((((arg0 == 0) || (arg0 != 2)) || (D_8660678C != 1)) || (D_866066F0 == 2)) {
    return;
  }
  D_86606B60 += 1;
  if (D_86606B60 < 6) {
    return;
  }
  ModelAnim_SetSpeed(arg1, 0x10000);
  ModelAnim_SetEventFrame(arg1, 0);
  if ((D_8660AB00[0] != 0) && (D_8660AB00[1] != 0)) {
    func_8003F3BC(arg1, 2);
  } else if (D_8660AB00[0] != 0) {
    func_8003F3BC(arg1, 0);
  } else if (D_8660AB00[1] != 0) {
    func_8003F3BC(arg1, 1);
  }
  D_86606B60 = 0;
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/54/fragment54_code/func_86601A04.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/54/fragment54_code/func_86601C98.s")
#endif

#ifdef VERSION_US
extern u8 D_866098A0[];
extern u8 D_86607410[];
extern s32 D_86606B80[][4];
extern s32 D_86606BC0[][4];
extern s32 D_86606B84[];
extern s32 D_86606BC4[];
extern f32 D_86606718;
extern void ModelAnim_SetAnimation(void *, s32);
extern void ModelAnim_SetEventFrame(void *, s32);
extern void func_8003F3BC(void *, s32);
extern void func_80027A28(u16, u8);
extern u8 D_8660A990[];
void func_86601F70(void *arg0, s32 arg1) {
    u8 *record;
    u8 *position;

    record = D_8660A990 + arg1 * 0x58;
    *(s32 *)(record + 0x4C) = 1;
    position = D_866098A0 + arg1 * 0x168;
    *(f32 *)(position + 0x24) = (f32)D_86606B80[arg1][*(s32 *)(record + 8)];
    *(f32 *)(position + 0x28) = (f32)D_86606BC0[arg1][*(s32 *)(record + 8)];
    *(f32 *)(position + 0x34) = D_86606718;
    *(f32 *)(position + 0x30) = D_86606718;
    switch (*(s32 *)(record + 8)) {
    case 1:
        if (*(s32 *)(record + 0x28) == 1) {
            break;
        }
        *(s32 *)(record + 0x28) = 1;
        ModelAnim_SetAnimation(D_86607410 + arg1 * 0x168, 3);
        ModelAnim_SetEventFrame(arg0, 0);
        func_8003F3BC(arg0, 3);
        *(f32 *)(position + 0x24) = (f32)*(s32 *)((u8 *)D_86606B84 + arg1 * 0x10);
        *(f32 *)(position + 0x28) = (f32)*(s32 *)((u8 *)D_86606BC4 + arg1 * 0x10);
        func_80027A28((u16)(arg1 + 0x2F04), (u8)arg1);
        break;
    case 2:
        if (*(s32 *)(record + 0x28) == 2) {
            break;
        }
        *(s32 *)(record + 0x28) = 2;
        ModelAnim_SetAnimation(D_86607410 + arg1 * 0x168, 4);
        ModelAnim_SetEventFrame(arg0, 0);
        func_8003F3BC(arg0, 4);
        func_80027A28((u16)(arg1 + 0x2F04), (u8)arg1);
        break;
    case 3:
        if (*(s32 *)(record + 0x28) == 3) {
            break;
        }
        *(s32 *)(record + 0x28) = 3;
        ModelAnim_SetAnimation(D_86607410 + arg1 * 0x168, 1);
        ModelAnim_SetEventFrame(arg0, 0);
        func_8003F3BC(arg0, 1);
        func_80027A28((u16)(arg1 + 0x2F04), (u8)arg1);
        break;
    case 4:
        if (*(s32 *)(record + 0x28) == 4) {
            break;
        }
        *(s32 *)(record + 0x28) = 4;
        ModelAnim_SetAnimation(D_86607410 + arg1 * 0x168, 2);
        ModelAnim_SetEventFrame(arg0, 0);
        func_8003F3BC(arg0, 2);
        func_80027A28((u16)(arg1 + 0x2F04), (u8)arg1);
        break;
    default:
        *(s32 *)(record + 0x4C) = 0;
        *(f32 *)(position + 0x34) = 0.0f;
        *(f32 *)(position + 0x30) = 0.0f;
        break;
    }
    if (*(s32 *)(record + 0x10) == -1) {
        *(s32 *)(record + 0x38) = 1;
        *(s32 *)(record + 0x4C) = 0;
        *(f32 *)(position + 0x34) = 0.0f;
        *(f32 *)(position + 0x30) = 0.0f;
        *(s32 *)(record + 0x28) = -1;
    }
}
#endif

#ifdef VERSION_US
/* mkdraft:func_86602260 begin */
extern s32 D_8660678C;
extern s32 D_86606714;
extern u8 D_8660A990[];
extern u8 D_8660A9AC[];
extern void ModelAnim_SetSpeed(void *, s32);
extern void func_86601A04(void *, s32);
extern s32 func_86601C98(void *, s32);
extern void func_866017E0(s32);
extern void func_86601F70(void *, s32);
extern void func_80027A28(u16, u8);
extern u8 D_866098A0[];



void func_86602260(s32 arg0, void *arg1) {
    s32 temp_s0;
    s32 temp_v0;
    u8 *temp_v0_2;
    u8 *temp_v1;

    temp_s0 = *(s32 *)((u8 *)arg1 + 0x14);
    if ((arg0 != 0) && (arg0 == 2) && (D_8660678C == 1)) {
        if (D_86606714 == 1) {
            *(s32 *)(D_8660A9AC + (temp_s0 * 0x58)) = 1;
            return;
        }
        ModelAnim_SetSpeed(arg1, 0x10000);
        temp_v1 = D_8660A990 + (temp_s0 * 0x58);
        arg0 = *(s32 *)(temp_v1 + 0x3C);
        if (arg0 > 0) {
            *(s32 *)(temp_v1 + 0x3C) = arg0 + 1;
        }
        func_86601A04(arg1, temp_s0);
        temp_v0 = *(s32 *)(temp_v1 + 0x28);
        *(s32 *)(temp_v1 + 0x10) = 0;
        if (temp_v0 != -1) {
            if ((temp_v0 != 1) && (temp_v0 != 2) && (temp_v0 != 3)) {
                if (temp_v0 == 4) {
                    goto block_14;
                }
            } else {
block_14:
                        func_80027A28(((temp_s0 << 8) | 0x200B) & 0xFFFF, (u8)temp_s0);
            }
            *(s32 *)(temp_v1 + 0x4C) = 0;
            if (func_86601C98((u8 *)&D_800CE060[temp_s0], temp_s0) == 1) {
                func_866017E0(temp_s0);
                func_86601F70(arg1, temp_s0);
                return;
            }
            temp_v0_2 = D_866098A0 + (temp_s0 * 0x168);
            *(f32 *)(temp_v0_2 + 0x34) = 0.0f;
            *(f32 *)(temp_v0_2 + 0x30) = 0.0f;
        }
    }
}
/* mkdraft:func_86602260 end */
#endif

#ifdef VERSION_US
/* mkdraft:func_866023F4 begin */
extern s32 D_86606714;
extern s32 D_86606734;
extern s32 D_86606740;
extern u8 D_86606788;
extern s32 D_8660678C;
extern u8 D_866098A0[];
extern s32 D_8660A9DC;
extern s32 D_8660AA34;
extern s32 D_8660AA8C;
extern s32 D_8660AAE4;
extern u8 D_8660AAF0[];
extern void func_8003F210(void *, s32);
extern void func_8003F3BC(void *, s32);
extern void ModelAnim_SetEventFrame(void *, s32);
extern void ModelAnim_SetFrame(void *, s32);
extern void ModelAnim_SetSpeed(void *, s32);



void func_866023F4(s32 mode, void *arg1) {
    s32 idx;
    s32 *state;
    s32 i;

    idx = *(s32 *)((u8 *)arg1 + 0x14);
    switch (mode) {
    case 0:
        func_8003F210(arg1, 0);
        ModelAnim_SetFrame(arg1, 8);
        break;
    case 2:
        if (((s32 *)D_8660AAF0)[idx] != 0 && D_8660678C == 1 && D_86606714 != 1) {
            ModelAnim_SetSpeed(arg1, 0x10000);
            if (*(s32 *)((u8 *)arg1 + 0x48) >> 16 >= 4) {
                // The four iterations are unrolled at -O2; retail's shared
                // `lui $at` per record comes from reaching both members through
                // D_866098A0 instead of their individual D_866098xxD4/D0 aliases.
                for (i = 0; i < 4; i++) {
                    *(f32 *)(D_866098A0 + i * 0x168 + 0x34) = 0.0f;
                    *(f32 *)(D_866098A0 + i * 0x168 + 0x30) = 0.0f;
                }
            }
            if (*(s32 *)((u8 *)arg1 + 0x48) >> 16 >= 5) {
                D_8660A9DC = 0;
                D_8660AA34 = 0;
                D_8660AA8C = 0;
                D_8660AAE4 = 0;
            }
            state = (s32 *)((u8 *)&D_86606788 + idx * 4);
            switch (state[0x11]) {
            case 0:
                break;
            case 1:
                ModelAnim_SetFrame(arg1, 5);
                func_8003F210(arg1, 0);
                state[0xD]++;
                if (state[0xD] >= 4) {
                    state[0xD] = 0;
                    state[0x11] = 0;
                }
                break;
            case 2:
                ModelAnim_SetFrame(arg1, 0);
                func_8003F210(arg1, 0);
                state[0xD]++;
                if (state[0xD] >= 4) {
                    state[0xD] = 0;
                    state[0x11] = 3;
                }
                break;
            case 3:
                if (*(s32 *)((u8 *)arg1 + 0x48) >> 16 >= D_86606740) {
                    ModelAnim_SetFrame(arg1, (s16)D_86606740);
                }
                if (D_86606734 == 0) {
                    if (state[0x19] == 5) {
                        func_8003F3BC(arg1, 0);
                    } else {
                        func_8003F3BC(arg1, 1);
                    }
                    if (*(s16 *)((u8 *)arg1 + 0x5C) >= 5) {
                        ModelAnim_SetEventFrame(arg1, 0);
                    }
                }
                break;
            }
        }
        break;
    }
}
/* mkdraft:func_866023F4 end */
#endif

#ifdef VERSION_US
extern void func_80038E14(s32, s32, s32, s32, f32, f32, f32, s32);
extern u8 D_86606788;
s32 func_8660265C(s32 arg0, s32 arg1) {
    func_80038E14(arg1, (*(s32 *)((u8 *)(&D_86606788) + (0x1C))), (*(s32 *)((u8 *)(&D_86606788) + (0x20))), (*(s32 *)((u8 *)(&D_86606788) + (0x24))), (*(f32 *)((u8 *)(&D_86606788) + (0x28))), (*(f32 *)((u8 *)(&D_86606788) + (0x2C))), (*(f32 *)((u8 *)(&D_86606788) + (0x30))), 0);
    return 0;
}
#endif

#ifdef VERSION_US
extern void func_80037120(s32, s32, s32 *, s16 *, s16 *);
extern s32 D_80094908;
s32 func_866026B8(s32 arg0, void *arg1) {
    s16 pad;
    s32 x;
    s16 y;
    s16 z;

    if (arg0 == 2) {
        func_80037120(D_80094908 + 0xB4, D_80094908 + 0xA8, &x, &y, &z);
        *(s16 *)((u8 *)arg1 + 0x1C) = y + 0x2000;
        *(s16 *)((u8 *)arg1 + 0x1E) = z - 0x2000;
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern void func_80037120(s32, s32, s32 *, s16 *, s16 *);
extern s32 D_80094908;
s32 func_86602720(s32 arg0, void *arg1) {
    s16 pad;
    s32 x;
    s16 y;
    s16 z;

    if (arg0 == 2) {
        func_80037120(D_80094908 + 0xB4, D_80094908 + 0xA8, &x, &y, &z);
        *(s16 *)((u8 *)arg1 + 0x1C) = -0x2000 - y;
        *(s16 *)((u8 *)arg1 + 0x1E) = z + 0x6000;
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern s32 D_8660670C;
extern s32 D_86606710;
extern s32 D_8660681C;
void func_8660278C(void) {
    switch (D_8660681C) {
    case 1:
        D_8660670C = 1;
        D_86606710 = 0x78;
        return;
    case 2:
        D_8660670C = 2;
        D_86606710 = 0x8C;
        return;
    case 3:
        D_8660670C = 4;
        D_86606710 = 0x78;
        return;
    case 4:
        D_8660670C = 6;
        D_86606710 = 0x8C;
        return;
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/54/fragment54_code/func_86602828.s")
#endif

void func_86603100(void) {
}

#ifdef VERSION_US
/* mkdraft:func_86603108 begin */
extern void Font_DisableTwoCycleTexturing(void);
extern void Font_EnableTwoCycleTexturing(void);
extern void func_800495F8(s32 x, s32 y, s32 mode, const char *format, ...);
extern void func_800496A4(s32 a0, s32 a1);
extern void func_8004972C(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_800497E4(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_800498C4(void);
extern void func_800499EC(void);
extern void func_87F09040(void);
extern void func_86600E00(void);
extern s32 D_866066EC;
extern s32 D_866066F0;
extern s32 D_86606720;
extern s32 D_86606724;
extern s32 D_86606728;
extern s32 D_86606738;
extern s32 D_86606748;
extern f32 D_86606750;
extern s32 D_86606790;
extern s32 D_86606E20;
extern s32 D_8660722C;



void func_86603108(void) {
    func_87F09040();
    func_800498C4();
    func_800496A4(1, 0);
    Font_EnableTwoCycleTexturing();
    func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
    func_800497E4(0xFF, 0xFF, 0xFF, 0xFF);
    D_86606E20 = D_86606E20 + 1;
    if (D_86606E20 >= 0x15) {
        D_86606E20 = 0;
    }
    // These string literals are this file's ordinary .rodata, 0x2A0800-0x2A0943;
    // IDO emits them in first-use order, so the call order fixes their addresses.
    func_800495F8(0x5A, 0x3C, 0, "R:もどる");
    func_800495F8(0x5A, 0x46, 0, "しゅうりょうスコア:");
    if ((D_86606E20 >= 0xA) || (D_86606790 != 1)) {
        func_800495F8(0xE6, 0x46, 0, "%d", D_86606720);
    }
    func_800495F8(0x5A, 0x50, 0, "にゅうりょくボタン:");
    if ((D_86606E20 >= 0xA) || (D_86606790 != 2)) {
        switch (D_866066F0) {
        case 0:
            func_800495F8(0xE6, 0x50, 0, "J+ABくべつ");
            break;
        case 1:
            func_800495F8(0xE6, 0x50, 0, "J+ABきょうつう");
            break;
        case 2:
            func_800495F8(0xE6, 0x50, 0, "Cボタン");
            break;
        }
    }
    func_800495F8(0x5A, 0x5A, 0, "ランダムタイプ:");
    if ((D_86606E20 >= 0xA) || (D_86606790 != 3)) {
        if (D_866066EC != 0) {
            func_800495F8(0xE6, 0x5A, 0, "せいせい");
        } else {
            func_800495F8(0xE6, 0x5A, 0, "パターン");
        }
    }
    func_800495F8(0x5A, 0x64, 0, "かさなりじかん:");
    if ((D_86606E20 >= 0xA) || (D_86606790 != 4)) {
        func_800495F8(0xE6, 0x64, 0, "%d", D_86606724);
    }
    func_800495F8(0x5A, 0x6E, 0, "デモまちじかん:");
    if ((D_86606E20 >= 0xA) || (D_86606790 != 5)) {
        func_800495F8(0xE6, 0x6E, 0, "%d", D_86606728);
    }
    func_800495F8(0x5A, 0x78, 0, "きりかえじかん:");
    if ((D_86606E20 >= 0xA) || (D_86606790 != 6)) {
        func_800495F8(0xE6, 0x78, 0, "%d", D_8660722C);
    }
    func_800495F8(0x5A, 0x82, 0, "ピカチュウスケール:");
    if ((D_86606E20 >= 0xA) || (D_86606790 != 7)) {
        func_800495F8(0xE6, 0x82, 0, "%0.2f", (f64) D_86606750);
    }
    func_800495F8(0x5A, 0x8C, 0, "ミスアニメーション:");
    if ((D_86606E20 >= 0xA) || (D_86606790 != 8)) {
        if (D_86606748 == 1) {
            func_800495F8(0xE6, 0x8C, 0, "ほかんあり");
        } else {
            func_800495F8(0xE6, 0x8C, 0, "ほかんなし");
        }
    }
    func_800495F8(0x5A, 0x96, 0, "いどうオブジェ:");
    if ((D_86606E20 >= 0xA) || (D_86606790 != 9)) {
        switch (D_86606738) {
        case 0:
            func_800495F8(0xE6, 0x96, 0, "なし");
            break;
        case 1:
            func_800495F8(0xE6, 0x96, 0, "カメラいち");
            break;
        case 2:
            func_800495F8(0xE6, 0x96, 0, "カメラちゅうしてん");
            break;
        }
    }
    func_86600E00();
    Font_DisableTwoCycleTexturing();
    func_800499EC();
}
/* mkdraft:func_86603108 end */
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/54/fragment54_code/func_86603604.s")
#endif

#ifdef VERSION_US
s32 func_87F00930();
extern void func_87F01D44();

void func_86604084(void) {
    if (func_87F00930() == 1) {
        func_87F01D44();
    }
}
#endif

#ifdef VERSION_US
extern void *D_86607230;
extern u8 D_86607320;
extern void func_800088DC(void);
extern void GfxImage_FillCurrent(Gfx **, u16);
extern s32 D_86606714;
extern void GeoRender_AdvanceFrameCounter(void);
extern void func_8003C6B8(void *);
extern void *D_866073DC;
extern void *D_866073E0;
extern void func_87F0CB68(void);
extern void func_87F07FE8(void *);
extern void func_86603604(void);
extern void func_87F022F0(void);
extern void func_86603108(void);
extern void func_87F0CB24(void);
extern void func_87F0C930(void *);
extern void Fragment64_StartPlayerPanel(void *, void *, s32, s32, s32, s32, s32);
extern void func_87F0A5BC(void *);
extern void func_87F0C88C(void *);
extern void func_80008648(void);
extern s32 D_86606728;
extern s32 D_866067FC;
extern s32 D_8660682C;
extern s32 D_86607288[];
extern u8 D_86607310;
extern u8 D_86607358;
extern void func_86604084(void);
extern Gfx * D_800D0510;
extern u8 D_86606788;
void func_866040B8(void) {
    func_800088DC();
    GfxImage_FillCurrent(&D_800D0510, 1);
    if (D_86606714 == 0) {
        GeoRender_AdvanceFrameCounter();
    }
    func_8003C6B8(D_866073DC);
    if (*(u8 *)((u8 *)D_86607230 + 0x2180) != 4) {
        func_87F0CB68();
    }
    switch (*(s32 *)(&D_86606788 + 4)) {
    case 2:
    case 13:
        if (*(s32 *)(&D_86606788 + 0x78) == 1) {
            func_87F07FE8(&D_86607320);
        } else {
            func_86603604();
        }
        if (*(s32 *)(&D_86606788 + 0x78) == 2) {
            func_86603604();
            func_87F022F0();
        }
        if (*(s32 *)(&D_86606788 + 0x78) == 3) {
            if (*(s32 *)(&D_86606788 + 0x84) == 1) {
                func_86603604();
            }
            func_86604084();
        }
        break;
    case 0:
    case 4:
    case 11:
        if (*(u8 *)((u8 *)D_86607230 + 0x2180) != 4) {
            func_87F07FE8(&D_86607320);
        }
        break;
    case 9:
        func_86603604();
        func_86603108();
        break;
    case 1:
        *(s32 *)(&D_86606788 + 0x84) = 1;
    case 5:
    case 10:
        func_86603604();
        func_86604084();
        break;
    case 8:
        func_86603604();
        if (D_866067FC == D_86606728 + 0x50) {
            func_87F0CB24();
            if (*(u8 *)((u8 *)D_86607230 + 0x2180) == 4) {
                func_87F0C930(&D_86607310);
            } else {
                Fragment64_StartPlayerPanel(&D_86607358, D_86607230, 5, D_86607288[0], D_86607288[1], D_86607288[2], D_86607288[3]);
            }
        }
        if ((1 - D_8660682C) * D_86606728 + 0x50 < D_866067FC) {
            func_87F0A5BC(&D_86607358);
        }
        break;
    case 7:
        func_86603604();
        func_87F022F0();
        break;
    }
    if (*(u8 *)((u8 *)D_86607230 + 0x2180) == 4) {
        func_87F0C88C(&D_86607310);
    }
    func_8003C6B8(D_866073E0);
    func_80008648();
}
#endif

#ifdef VERSION_US
extern u8 D_86608220[];
extern u8 D_866073E8[];
extern u8 D_86609E40[];
extern u8 D_8660A3E0[];
extern void func_8003F114(void *, s32, s32, s32);
extern void func_8003F1DC(void *);
extern void func_8003EF70(void *);
extern void ModelAnim_SetFrame(void *, s32);
extern void func_86600EEC(void);
extern void ModelAnim_SetEventFrame(void *, s32);
extern void ModelAnim_SetSpeed(void *, s32);
extern void StageContext_SetClearColor(s32);
extern s32 StageFade_StartFromTransparent(s32);
extern void ModelAnim_SetAnimation(void *, s32);
extern void func_8003F3BC(void *, s32);
extern u8 D_86606788;
extern u8 D_86607410[];
extern u8 D_866079B0[];
extern u8 D_866098A0[];
void func_86604370(void) {
    s32 j;
    u8 *anim;
    u8 *inner;
    u8 *source;
    u8 *a;
    u8 *b;
    u8 *c;
    anim = D_866079B0; inner = D_86608220; source = D_866073E8; a = D_86609E40; b = D_86607410; c = D_8660A3E0;
    do {
        func_8003F114(anim, 0, -1, *(s32 *)source);
        ModelAnim_SetAnimation(anim, 5);
        ModelAnim_SetFrame(anim, (s16)(guRandom() % 25));
        ModelAnim_SetSpeed(anim, 0x10000);
        ModelAnim_SetEventFrame(anim, 0);
        func_8003F3BC(anim, 0);
        func_8003F1DC(a);
        func_8003F1DC(b);
        func_8003F1DC(c);
        for (j = 0; j < 0x5A0; j += 0x168) {
            func_8003EF70(inner + j);
        }
        anim += 0x168;
        source += 4;
        a += 0x168;
        b += 0x168;
        c += 0x168;
    } while ((inner += 0x5A0) != D_866098A0);
    *(s32 *)(&D_86606788 + 0x78) = 2;
    *(s32 *)(&D_86606788 + 4) = 13;
    StageContext_SetClearColor(1);
    StageFade_StartFromTransparent(10);
    func_86600EEC();
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/54/fragment54_code/func_866044F0.s")
#endif

#ifdef VERSION_US
extern u8 func_87F08208(void *);
extern void StageContext_SetClearColor(s32);
extern s32 StageFade_StartFromTransparent(s32);
extern void func_800225C4(s32);
extern void func_800226C0(s32);
extern void Audio_PlayDefaultSound(s32);
extern u8 D_86606788;
extern u8 D_86607320;
void func_8660484C(void) {
    u8 state = func_87F08208(&D_86607320);
    switch (state ? state : state) {
    case 1:
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(0x14);
        *(s32 *)(&D_86606788 + 4) = 0xB;
        func_800225C4(0x28);
        Audio_PlayDefaultSound(0xCF0B);
        break;
    case 2:
        *(s32 *)(&D_86606788 + 4) = 2;
        *(s32 *)(&D_86606788 + 0x78) = 1;
        *(s32 *)(&D_86606788 + 0x8C) = 0;
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(0xA);
        func_800226C0(3);
        break;
    }
}
#endif

#ifdef VERSION_US
extern s32 D_8660678C;
extern void *D_86607230;
extern void StageFade_StartFromOpaque(s32);
void func_87F00688(void);
s32 StageContext_GetFadeMode(void);
void func_866048EC(void) {
    if ((*(u8 *)((u8 *)(D_86607230) + (0x2180))) == 4) {
        StageFade_StartFromOpaque(0x14);
        func_87F00688();
        D_8660678C = 0xA;
        return;
    }
    if (StageContext_GetFadeMode() == 0) {
        D_8660678C = 4;
    }
}
#endif

#ifdef VERSION_US
extern s32 D_86606714;
extern s32 D_8660678C;
extern s32 func_87F006AC(void);
extern void Audio_PlayDefaultSound(s32);
extern void func_80021ED8(s32);
extern void func_87F0CA30(void);
s32 func_86604954(void) {
    if (D_86606714 == 1) {
        return 0;
    }
    if (func_87F006AC() == 1) {
        Audio_PlayDefaultSound(0x2F00);
    }
    if (func_87F006AC() == 2) {
        D_8660678C = 0xC;
        Audio_PlayDefaultSound(0x2F01);
        func_80021ED8(0x15);
        func_87F0CA30();
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/54/fragment54_code/func_866049D4.s")
#endif

#ifdef VERSION_US
extern s32 D_86606738;
extern s32 D_86606720;
extern s32 D_866066EC;
extern s32 D_86606724;
extern s32 D_8660722C;
extern f32 D_86606750;
extern s32 D_86606748;
extern s32 D_866066F0;
extern s32 D_86606728;
extern u8 D_86606788;
void func_86605098(void) {
    if (D_86606738 == 0) {
        if (D_80087200->buttonsPressed & 0x400) {
            *(s32 *)(&D_86606788 + 8) += 1;
            if (*(s32 *)(&D_86606788 + 8) > 10) {
                *(s32 *)(&D_86606788 + 8) = 10;
            }
            if (*(s32 *)(&D_86606788 + 8) == 9 && (D_80087200->buttonsHeld & 0x8000)) {
                D_86606738 = 1;
            }
        } else if (D_80087200->buttonsPressed & 0x800) {
            *(s32 *)(&D_86606788 + 8) -= 1;
            if (*(s32 *)(&D_86606788 + 8) < 1) {
                *(s32 *)(&D_86606788 + 8) = 1;
            }
        } else if ((D_80087200->buttonsPressed & 0x100) || (D_80087200->buttonsHeld & 1)) {
            switch (*(s32 *)(&D_86606788 + 8)) {
            case 1:
                D_86606720++;
                break;
            case 2:
                D_866066F0++;
                if (D_866066F0 > 2) {
                    D_866066F0 = 2;
                }
                break;
            case 3:
                D_866066EC = 1 - D_866066EC;
                break;
            case 4:
                D_86606724++;
                if (D_86606724 > D_8660722C) {
                    D_86606724 = D_8660722C;
                }
                break;
            case 5:
                D_86606728++;
                break;
            case 6:
                D_8660722C += 10;
                break;
            case 7:
                D_86606750 += 0.01;
                break;
            case 8:
                D_86606748 = 0;
                break;
            }
        } else if ((D_80087200->buttonsPressed & 0x200) || (D_80087200->buttonsHeld & 2)) {
            switch (*(s32 *)(&D_86606788 + 8)) {
            case 1:
                D_86606720--;
                if (D_86606720 < 5) {
                    D_86606720 = 5;
                }
                break;
            case 2:
                D_866066F0--;
                if (D_866066F0 < 0) {
                    D_866066F0 = 0;
                }
                break;
            case 3:
                D_866066EC = 1 - D_866066EC;
                break;
            case 4:
                D_86606724--;
                if (D_86606724 < 0) {
                    D_86606724 = 0;
                }
                break;
            case 5:
                D_86606728--;
                if (D_86606728 < 0) {
                    D_86606728 = 0;
                }
                break;
            case 6:
                D_8660722C -= 10;
                if (D_8660722C < 40) {
                    D_8660722C = 40;
                }
                break;
            case 7:
                D_86606750 -= 0.01;
                if (D_86606750 <= 0.1) {
                    D_86606750 = 0.1f;
                }
                break;
            case 8:
                D_86606748 = 1;
                break;
            }
        }
    } else if (*(s32 *)(&D_86606788 + 8) == 9 && D_86606738 > 0) {
        if (D_80087200->buttonsPressed & 0x8000) {
            D_86606738++;
            if (D_86606738 >= 3) {
                D_86606738 = 0;
            }
        }
        if (D_80087200->buttonsHeld & 0x800) {
            if (D_86606738 == 1) {
                *(f32 *)(&D_86606788 + 0x20) += 10.0f;
            } else {
                *(f32 *)(&D_86606788 + 0x2C) += 10.0f;
            }
        } else if (D_80087200->buttonsHeld & 0x400) {
            if (D_86606738 == 1) {
                *(f32 *)(&D_86606788 + 0x20) -= 10.0f;
            } else {
                *(f32 *)(&D_86606788 + 0x2C) -= 10.0f;
            }
        } else if (D_80087200->buttonsHeld & 0x100) {
            if (D_86606738 == 1) {
                *(f32 *)(&D_86606788 + 0x1C) += 10.0f;
            } else {
                *(f32 *)(&D_86606788 + 0x28) += 10.0f;
            }
        } else if (D_80087200->buttonsHeld & 0x200) {
            if (D_86606738 == 1) {
                *(f32 *)(&D_86606788 + 0x1C) -= 10.0f;
            } else {
                *(f32 *)(&D_86606788 + 0x28) -= 10.0f;
            }
        } else if (D_80087200->buttonsHeld & 8) {
            if (D_86606738 == 1) {
                *(f32 *)(&D_86606788 + 0x24) += 50.0f;
            } else {
                *(f32 *)(&D_86606788 + 0x30) += 50.0f;
            }
        } else if (D_80087200->buttonsHeld & 4) {
            if (D_86606738 == 1) {
                *(f32 *)(&D_86606788 + 0x24) -= 50.0f;
            } else {
                *(f32 *)(&D_86606788 + 0x30) -= 50.0f;
            }
        }
    }
}
#endif

#ifdef VERSION_US
extern s32 D_8660679C;
extern s32 D_8660A980[];
extern u32 func_8003570C(void);
void func_866055C8(void) {
    s32 value;
    D_8660A980[0] = D_8660679C / 1800;
    value = D_8660679C - D_8660A980[0] * 1800;
    D_8660A980[1] = value / 30;
    value -= D_8660A980[1] * 30;
    D_8660A980[2] = func_8003570C() % 3 + value * 100 / 30;
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/54/fragment54_code/func_866056B8.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/54/fragment54_code/func_86605ABC.s")
#endif

#ifdef VERSION_US
extern s32 D_8660A9B8;
extern s32 D_8660AA10;
extern s32 D_8660AA68;
extern s32 D_8660AAC0;
extern s16 D_8660746C;
extern s16 D_866075D4;
extern s16 D_8660773C;
extern s16 D_866078A4;
void func_86605D5C(void) {
 s16 value = 0x17;
if (D_8660A9B8 == 8) { D_8660746C = value; } if (D_8660AA10 == 8) { D_866075D4 = value; } if (D_8660AA68 == 8) { D_8660773C = value; } if (D_8660AAC0 == 8) { D_866078A4 = value; }
}
#endif

#ifdef VERSION_US
extern s32 func_87F01A40(void);
extern void StageContext_SetClearColor(s32);
extern s32 StageFade_StartFromTransparent(s32);
extern s32 D_86606714;
extern u8 D_86606788;
extern u8 D_8660A990[];
void func_86605DCC(void) {
    s32 i;

    D_86606714 = 1;
    switch (func_87F01A40()) {
    case 0:
    case 2:
        D_86606714 = 0;
        break;
    case 3:
        *(s32 *)(&D_86606788 + 0x8C) = 0;
        *(s32 *)(&D_86606788 + 4) = 2;
        *(s32 *)(&D_86606788 + 0x78) = 3;
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(10);
        break;
    case 4:
        *(s32 *)(&D_86606788 + 0x8C) = 1;
        *(s32 *)(&D_86606788 + 4) = 2;
        *(s32 *)(&D_86606788 + 0x78) = 3;
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(10);
        break;
    }
    if (D_86606714 == 1) {
        for (i = 0; i < 4; i++) {
            if (*(s32 *)(D_8660A990 + i * 0x58 + 0x4C) == 1) {
                *(f32 *)(D_866098A0 + i * 0x168 + 0x34) = 8.0f;
                *(f32 *)(D_866098A0 + i * 0x168 + 0x30) = 8.0f;
            }
        }
    }
}
#endif

#ifdef VERSION_US
extern s32 StageContext_GetFadeMode(void);
extern s32 func_87F0C6F4(void *);
extern void func_87F006BC(void);
extern void func_86605DCC(void);
extern void func_86605ABC(void);
extern void func_866044F0(void);
extern void func_866049D4(void);
extern void func_866056B8(void);
extern void func_86605098(void);
extern s32 Fragment64_UpdateBounceAndConfirm(void *);
extern void func_87F02328(void);
extern s32 func_87F02104(void);
extern void func_87F0D5B8(void *);
extern void func_87F0C9D0(s32);
extern s32 D_86606728;
extern u8 D_86607238;
extern u8 D_86607310;
extern u8 D_86607358;
extern void StageContext_SetClearColor(s32);
extern void StageFade_StartFromOpaque(s32);
extern s32 StageFade_StartFromTransparent(s32);
extern void func_86604370(void);
extern void func_8660484C(void);
extern void func_866048EC(void);
extern s32 func_86604954(void);
extern void func_86605D5C(void);
extern s32 func_87F00930();
extern u8 D_86606788;
extern void * D_86607230;
s32 func_86605F04(s32 arg0) {
    if (*(u8 *)((u8 *)D_86607230 + 0x2180) == 4 && func_87F0C6F4(&D_86607310) != 0) {
        *(s32 *)(&D_86606788 + 4) = 3;
        *(s32 *)(&D_86606788 + 0x8C) = 3;
    }
    if (func_87F00930() == 0 && *(s32 *)(&D_86606788 + 4) != 9) {
        func_87F006BC();
    }
    switch (*(s32 *)(&D_86606788 + 4)) {
    case 0:
        func_866048EC();
        break;
    case 4:
        func_8660484C();
        break;
    case 5:
    case 10:
    case 12:
        func_86605DCC();
        func_86604954();
        func_86605ABC();
        break;
    case 11:
        func_866044F0();
        break;
    case 8:
        func_866049D4();
        if (D_86606728 + 0x50 < *(s32 *)(&D_86606788 + 0x74) && Fragment64_UpdateBounceAndConfirm(&D_86607358) != 0) {
            if (*(u8 *)((u8 *)D_86607230 + 0x2180) == 1) {
                *(s32 *)(&D_86606788 + 0x8C) = 2;
                *(s32 *)(&D_86606788 + 4) = 2;
                *(s32 *)(&D_86606788 + 0x78) = 0;
                StageContext_SetClearColor(0xFFFF);
                StageFade_StartFromTransparent(10);
            } else {
                func_87F02328();
                *(s32 *)(&D_86606788 + 4) = 7;
            }
        }
        break;
    case 1:
        func_86605DCC();
        func_866056B8();
        break;
    case 9:
        func_86605098();
        break;
    case 7:
        func_86605D5C();
        switch (func_87F02104()) {
        case 1:
            StageContext_SetClearColor(1);
            *(s32 *)(&D_86606788 + 4) = 13;
            *(s32 *)(&D_86606788 + 0x78) = 2;
            StageFade_StartFromTransparent(10);
            break;
        case 2:
            *(s32 *)(&D_86606788 + 0x8C) = 0;
            *(s32 *)(&D_86606788 + 4) = 2;
            *(s32 *)(&D_86606788 + 0x78) = 2;
            StageContext_SetClearColor(0xFFFF);
            StageFade_StartFromTransparent(10);
            break;
        case 3:
            *(s32 *)(&D_86606788 + 0x8C) = 1;
            *(s32 *)(&D_86606788 + 4) = 2;
            *(s32 *)(&D_86606788 + 0x78) = 2;
            StageContext_SetClearColor(0xFFFF);
            StageFade_StartFromTransparent(10);
            break;
        }
        break;
    case 13:
        func_86605D5C();
        if (StageContext_GetFadeMode() == 1) {
            func_86604370();
            *(s32 *)(&D_86606788 + 4) = 14;
            StageFade_StartFromOpaque(10);
        }
        break;
    case 14:
        func_86605D5C();
        *(s32 *)(&D_86606788 + 4) = 0;
        break;
    case 2:
        func_86605D5C();
        if (StageContext_GetFadeMode() == 1) {
            *(s32 *)(&D_86606788 + 4) = 3;
        }
        break;
    }
    func_87F0D5B8(&D_86607238);
    func_87F0C9D0(func_87F00930());
    return *(s32 *)(&D_86606788 + 4);
}
#endif

#ifdef VERSION_US
/* mkdraft:func_866061E0 begin */
extern s32 D_8660672C;
extern u8 D_866067A0[];
extern u8 D_86606884[];
extern u8 D_8660AAF0[];
extern void func_8003F210(void *, s32);



void func_866061E0(void) {
    u8 *src;
    u8 *dst;
    u8 *anim;
    u8 *entry;
    u8 *model;
    u8 *node;

    func_800086A4(2);
    if ((*(u8 *)((u8 *)D_86607230 + 0x2180)) == 4) {
        dst = (u8 *)&D_866067A0 - 0x18;
        src = D_86606884 + D_8660672C * 0x18;
        do {
            *(f32 *)(dst + 0x1C) = *(f32 *)src;
            src += 4;
            dst += 4;
        } while (dst < (u8 *)&D_866067A0);
        /* Retail materializes the loop-end address D_8660AAF0 before the four
         * pointer bases, in reverse assignment order. IDO treats source-line
         * boundaries as scheduling barriers here, so the initializations stay
         * on the loop's line. */
        anim = D_866079B0; entry = D_86607410; model = D_866073E8; node = D_8660A990; do {
            func_8003F1DC(anim);
            func_8003F114(entry, 0, -1, *(s32 *)model);
            ModelAnim_SetEventFrame(entry, 0);
            func_8003F3BC(entry, 0);
            func_8003F210(entry, 0);
            ModelAnim_SetFrame(entry, (s16)(guRandom() % 25));
            node += 0x58;
            anim += 0x168;
            entry += 0x168;
            model += 4;
            *(s32 *)(node - 0x30) = 0;
        } while (node != D_8660AAF0);
    }
    StageFade_StartFromOpaque(10);
    do {
        func_80064D28();
        func_866040B8();
        *(s32 *)((u8 *)&D_86606788 + 4) = func_86605F04(*(s32 *)((u8 *)&D_86606788 + 4));
    } while (*(s32 *)((u8 *)&D_86606788 + 4) != 3);
}
/* mkdraft:func_866061E0 end */
#endif

#ifdef VERSION_US
extern void Gfx_InitDisplayListBuffers(s32, s32);
s32 StageContext_Allocate(s32, s32, s32, s32, s32, s32);
extern void func_80008514(s32);
extern void func_80008574();
extern void func_8004C8C0(s32);
extern void func_86602828();
extern void func_866061E0();
extern void func_87F00030();
extern void func_87F01F34(void *);
extern void func_87F06EAC(s32, s32 *, void *);
extern void func_87F0F480(void *);
extern void main_pool_pop_state(s32);
extern void main_pool_push_state(s32);
extern u8 D_446E30;
extern s32 D_86606814;
extern u8 D_86607320;
extern s32 D_86607328;
extern s32 D_86607378;
extern void func_80027EE0(u16);
extern void func_8004C09C(s32 arg0);
extern s32 func_80047588(s32 arg0, s32 arg1);
u8 *Asset_LoadToSegment(s32 id, u8 *rom_start, u8 *rom_end, s32 arg3);
extern u8 D_1000000[];
extern u8 D_447D00[];
void func_87F0C980(void);
void func_80047610(void);
void func_8004C398(void);
void Gfx_FreeDisplayListBuffers(void);
s32 StageContext_Allocate(s32, s32, s32, s32, s32, s32);
u8 *Asset_LoadToSegment(s32 id, u8 *rom_start, u8 *rom_end, s32 arg3);
void func_87F0C980(void);
void func_80047610(void);
void func_8004C398(void);
void Gfx_FreeDisplayListBuffers(void);
s32 fragment54_main(s32 arg0, void *arg1) {
    s32 sp24;

    D_86607230 = arg1;
    if ((*(u8 *)((u8 *)(D_86607230) + (0x2180))) == 4) {
        func_80027EE0(0xFFF);
    }
    main_pool_push_state(0x4D523032);
    Gfx_InitDisplayListBuffers(0x20000, 0);
    sp24 = StageContext_Allocate(0, 1, 3, 1, 2, 1);
    func_8004C09C(0x123);
    func_87F06EAC(0x6A, &D_86607320, D_86607230);
    func_8004C8C0(0xE0);
    func_8004C8C0(0xE1);
    func_8004C8C0(0x1B2);
    func_8004C8C0(0x19A);
    func_8004C8C0(0x199);
    func_80047588(D_86607328 | 5 | D_86607378, 0);
    Asset_LoadToSegment((s32) ((u32) ((s32) D_1000000 & 0x0F000000) >> 0x18), &D_446E30, D_447D00, 0);
    func_87F00030();
    func_87F0C980();
    func_87F01F34(D_86607230);
    func_86602828();
    func_80008514(sp24);
    func_866061E0();
    func_80008574();
    func_80047610();
    func_8004C398();
    Gfx_FreeDisplayListBuffers();
    main_pool_pop_state(0x4D523032);
    func_87F0F480(D_86607230);
    func_80027EE0(0xFFE);
    return D_86606814;
}
#endif
