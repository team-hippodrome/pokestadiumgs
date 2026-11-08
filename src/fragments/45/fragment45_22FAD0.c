#include "global.h"


#ifdef VERSION_US
// Pointed to by D_8AB112BC in .data; it opens this file's .rodata.
const char D_8AB11A80[] = "\n";
extern s16 D_8AB12690;
extern s16 D_8AB16F6C;
extern s16 D_8AB16F60;
extern s16 D_8AB16F74;
extern s32 D_8AB16F68;
extern u8 *D_8AB11D0C;
extern void *D_8AB11D00;
extern void *D_8AB12688;
extern void *D_8AB16D08;
extern void *D_8AB16E4C;
extern void *D_8AB16F64;
extern u8 *D_8AB16E40;
extern u8 *D_8AB16E44;
extern u8 *D_8AB16E48;
extern s32 D_8AB16E50;
extern s32 D_8AB12BA8;
extern u8 D_8AB16D10[];
extern u8 D_8AB126A8[];
extern void _bzero(void *, s32);
extern u8 D_8AB12CB0[];
extern s16 D_8AB12CB2;
extern s16 D_8AB12D46;
extern s16 D_8AB12DDA;
extern s16 D_8AB12E6E;
extern u8 D_8AB16508;
extern u8 D_8AB112A4;
extern void *D_8AB16CF0;
extern void *D_8AB16CF8[4];
extern void *D_8AB16F48[];
extern void *D_8AB16ED0[4];
extern void *D_8AB16EE0;
extern void *D_8AB16EE4;
extern u8 D_8AB16EE8;
extern u8 D_8AB16F18;
extern void *D_8AB16E10;
extern void *D_8AB16E14;
extern void *D_8AB16E18;
extern void *D_8AB16E1C;
extern void *D_8AB16E20[4];
extern void *D_8AB16E2C;
extern void *D_8AB16E24;
extern void *D_8AB16E28;
extern void *D_8AB16E30;
extern void *D_8AB16E34;
extern void *D_8AB16E38;
extern void *D_8AB16E3C;
extern void *D_8AB16F58;
extern void *D_8AB16F5C;
extern s32 D_8AB16F70;
extern s32 D_8AB16F78;

extern s32 func_8004C8C0(s32);
extern s32 func_8004DC6C(s32);
extern void func_8004DCFC(s32, s32);
extern s32 main_pool_get_available(void);
extern s32 MainPool_AllocState(s32, s32);
extern void MainPool_FinalizeAllocation(s32);
extern void *func_8004EB58(s32, s32);
extern s32 func_80040E80(s32, void *);
extern void func_8AC06E98(void *);
extern void *func_8AC06D8C();
extern void func_8AB01378(s32, void *, s16);
extern s32 func_8AB00548(void);
extern void func_8004E308(void *, void *, void *);
extern void func_8AC02C80(void *, s32, s32, void *);
extern void func_8AC05E40(void *, s32, s32);
extern void func_8AC06400(void *, void *);
extern void func_8AC033B8();
extern s32 TextLabel_DrawCallback(s32, void *);
extern s32 TextNumber_DrawCallback(s32, void *);
extern s32 func_8AB01C04(s32, void *);

// func_8AB0A950: VS-mode player/options menu setup.
//
// Flow:
// 1. Zero D_8AB12690 and set the countdown D_8AB16F6C = 100.
// 2. For each of the four 0x94-byte slot records at D_8AB12CB0: bzero it, and
//    when bit i of D_8AB11D0C[0xE] is set mark the record active (*(s16 *)slot
//    = 1) and bump D_8AB12690.
// 3. Allocate the menu object (D_8AB16CF0) from the main pool via
//    func_8004EB58, stash func_80040E80's result in D_8AB16F78, and mark the
//    object with bits 0x1/0x2 of its 16-bit header field at +2.
// 4. Create the four per-player children ("pli1".."pli4",
//    D_8AB16CF8[0..3]) and for each one clear header bit 0, set it back when
//    the matching slot record is active, and register func_8AB01378 with the
//    slot number.
// 5. Create the remaining tagged children ("who1".."who4", "rea1".."rea4",
//    "qwfi", "efct", "mond", "mess", "rule", "timw", "atim", "qwu1/qws1"
//    groups, "pic1".."pic4", "fin1".."fin3", "qit1".."qit4", "nok1".."nok4",
//    "gooo", "abu1"), clear header bit 1 on the display ones and attach their
//    draw callbacks with func_8004E308.
// 6. Reset the frame/pause counters (D_8AB16F70, D_8AB16F74, D_8AB16F68,
//    D_8AB11D0C[0x10] = 0, D_8AB16F60 = -1) and return the menu object.
//
// Codegen notes that the match depends on (see func_8AB0A950.report.md):
// - bit 0/1 clears are spelled `&= ~2` (constant folded once, so IDO keeps
//   `andi` in the first block and hoists `li -3` for the later ones) except the
//   nine sites that must stay literal `&= 0xFFFE`;
// - the second slot loop indexes the globals directly (D_8AB16CF8[var_s1] and a
//   `slot` pointer) and its increments live in the for-update list as
//   `slot += 0x94, var_s1++`, which is what makes IDO emit
//   `addiu s0(D_8AB16CF8) ; addiu s2(slot)` in the preheader and put the
//   `addiu s0,s0,4` in the branch delay slot;
// - D_8AB16F48[1]/[2] and D_8AB16ED0[1]/[2] masks go through the `node`/`node2`
//   locals so the following four-argument func_8AC06D8C calls reuse a2/a3;
// - `func_8004C8C0` returns s32, which puts both D_8AB12690 address temps in v1.



void *func_8AB0A950(void) {
    u8 *slot;
    s32 temp_s0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s1;
    void *node;
    void *node2;

    func_8004C8C0(0x99);
    D_8AB12690 = 0;
    D_8AB16F6C = 0x64;
    slot = D_8AB12CB0;
    for (var_s1 = 0; var_s1 < 4; var_s1++) {
        temp_s0 = (D_8AB11D0C[14] >> var_s1) & 0xFF;
        _bzero(slot, 0x94);
        if (temp_s0 & 1) {
            *(s16 *)slot = 1;
            D_8AB12690 += 1;
        }
        slot += 0x94;
    }
    temp_v0 = func_8004DC6C(0xE1);
    func_8004DCFC(temp_v0, 0);
    temp_v0_2 = MainPool_AllocState(main_pool_get_available(), 0);
    D_8AB16CF0 = func_8004EB58(temp_v0_2, temp_v0);
    D_8AB16F78 = func_80040E80(temp_v0_2, &D_8AB112A4);
    MainPool_FinalizeAllocation(temp_v0_2);
    func_8AC06E98(D_8AB16CF0);
    *(u16 *)((u8 *)D_8AB16CF0 + 2) |= 1;
    *(u16 *)((u8 *)D_8AB16CF0 + 2) |= 2;
    D_8AB16CF8[0] = func_8AC06D8C(D_8AB16CF0, 0x706C6931);
    D_8AB16CF8[1] = func_8AC06D8C(D_8AB16CF0, 0x706C6932);
    D_8AB16CF8[2] = func_8AC06D8C(D_8AB16CF0, 0x706C6933);
    D_8AB16CF8[3] = func_8AC06D8C(D_8AB16CF0, 0x706C6934);
    for (var_s1 = 0, slot = D_8AB12CB0; var_s1 < 4; slot += 0x94, var_s1++) {
        *(u16 *)((u8 *)D_8AB16CF8[var_s1] + 2) &= 0xFFFE;
        if (*(s16 *)slot != 0) {
            *(u16 *)((u8 *)D_8AB16CF8[var_s1] + 2) |= 1;
        }
        func_8AB01378((s32)D_8AB16CF0, D_8AB16CF8[var_s1], (s16)var_s1);
    }
    D_8AB16F48[0] = func_8AC06D8C(D_8AB16CF0, 0x77686F31);
    D_8AB16F48[1] = func_8AC06D8C(D_8AB16CF0, 0x77686F32);
    D_8AB16F48[2] = func_8AC06D8C(D_8AB16CF0, 0x77686F33);
    D_8AB16F48[3] = func_8AC06D8C(D_8AB16CF0, 0x77686F34);
    *(u16 *)((u8 *)D_8AB16F48[0] + 2) &= ~2;
    node = D_8AB16F48[1];
    *(u16 *)((u8 *)node + 2) &= ~2;
    node2 = D_8AB16F48[2];
    *(u16 *)((u8 *)node2 + 2) &= ~2;
    *(u16 *)((u8 *)D_8AB16F48[3] + 2) &= ~2;
    D_8AB16ED0[0] = func_8AC06D8C(D_8AB16CF0, 0x72656131, node, node2);
    D_8AB16ED0[1] = func_8AC06D8C(D_8AB16CF0, 0x72656132);
    D_8AB16ED0[2] = func_8AC06D8C(D_8AB16CF0, 0x72656133);
    D_8AB16ED0[3] = func_8AC06D8C(D_8AB16CF0, 0x72656134);
    *(u16 *)((u8 *)D_8AB16ED0[0] + 2) &= ~2;
    node = D_8AB16ED0[1];
    *(u16 *)((u8 *)node + 2) &= ~2;
    node2 = D_8AB16ED0[2];
    *(u16 *)((u8 *)node2 + 2) &= ~2;
    *(u16 *)((u8 *)D_8AB16ED0[3] + 2) &= ~2;
    D_8AB16EE0 = func_8AC06D8C(D_8AB16CF0, 0x71776669, node, node2);
    *(u16 *)((u8 *)D_8AB16EE0 + 2) &= 0xFFFE;
    D_8AB16EE4 = func_8AC06D8C(D_8AB16CF0, 0x65666374, &D_8AB16EE0);
    func_8AB00548();
    func_8004E308(D_8AB16EE4, func_8AC033B8, &D_8AB16508);
    D_8AB16D08 = func_8AC06D8C(D_8AB16CF0, 0x6D6F6E64);
    func_8004E308(D_8AB16D08, TextLabel_DrawCallback, D_8AB16D10);
    D_8AB11D00 = func_8AC06D8C(D_8AB16CF0, 0x6D657373);
    *(u16 *)((u8 *)D_8AB11D00 + 2) &= 0xFFFE;
    func_8004E308(D_8AB11D00, TextLabel_DrawCallback, D_8AB126A8);
    D_8AB12688 = func_8AC06D8C(D_8AB16CF0, 0x72756C65);
    *(u16 *)((u8 *)D_8AB12688 + 2) &= 0xFFFE;
    func_8004E308(D_8AB12688, TextLabel_DrawCallback, &D_8AB12BA8);
    D_8AB16F58 = func_8AC06D8C(D_8AB16CF0, 0x74696D77);
    *(u16 *)((u8 *)D_8AB16F58 + 2) |= 1;
    D_8AB16F5C = func_8AC06D8C(D_8AB16CF0, 0x6174696D, &D_8AB16F58);
    func_8004E308(D_8AB16F5C, TextNumber_DrawCallback, &D_8AB16F6C);
    func_8AC02C80(D_8AB16CF0, 0x71777531, 0x71777532, &D_8AB16EE8);
    func_8AC02C80(D_8AB16CF0, 0x71777331, 0x71777332, &D_8AB16F18);
    D_8AB16E10 = func_8AC06D8C(D_8AB16CF0, 0x70696331);
    D_8AB16E14 = func_8AC06D8C(D_8AB16CF0, 0x70696332);
    D_8AB16E18 = func_8AC06D8C(D_8AB16CF0, 0x70696333);
    D_8AB16E1C = func_8AC06D8C(D_8AB16CF0, 0x70696334);
    D_8AB16E30 = func_8AC06D8C(D_8AB16CF0, 0x66696E31);
    D_8AB16E34 = func_8AC06D8C(D_8AB16CF0, 0x66696E32);
    D_8AB16E38 = func_8AC06D8C(D_8AB16CF0, 0x66696E33);
    func_8004E308(D_8AB16E30, func_8AB01C04, NULL);
    func_8004E308(D_8AB16E34, func_8AB01C04, NULL);
    func_8004E308(D_8AB16E38, func_8AB01C04, NULL);
    D_8AB16E3C = func_8AC06D8C(D_8AB16CF0, 0x71697431);
    D_8AB16E40 = func_8AC06D8C(D_8AB16CF0, 0x71697432);
    D_8AB16E44 = func_8AC06D8C(D_8AB16CF0, 0x71697433);
    D_8AB16E48 = func_8AC06D8C(D_8AB16CF0, 0x71697434);
    D_8AB16E20[0] = func_8AC06D8C(D_8AB16CF0, 0x6E6F6B31);
    D_8AB16E24 = func_8AC06D8C(D_8AB16CF0, 0x6E6F6B32);
    D_8AB16E28 = func_8AC06D8C(D_8AB16CF0, 0x6E6F6B33);
    D_8AB16E20[3] = func_8AC06D8C(D_8AB16CF0, 0x6E6F6B34);
    func_8004E308(D_8AB16E20[0], TextNumber_DrawCallback, &D_8AB12CB2);
    func_8004E308(D_8AB16E24, TextNumber_DrawCallback, &D_8AB12D46);
    func_8004E308(D_8AB16E28, TextNumber_DrawCallback, &D_8AB12DDA);
    func_8004E308(D_8AB16E2C, TextNumber_DrawCallback, &D_8AB12E6E);
    D_8AB16F64 = func_8AC06D8C(D_8AB16CF0, 0x676F6F6F);
    D_8AB16E4C = func_8AC06D8C(D_8AB16CF0, 0x61627531);
    func_8AC05E40(D_8AB16CF0, 0x61627531, &D_8AB16E50);
    func_8AC06400(&D_8AB16E50, D_8AB16E4C);
    *(u16 *)((u8 *)D_8AB16E10 + 2) &= ~2;
    *(u16 *)((u8 *)D_8AB16E14 + 2) &= ~2;
    *(u16 *)((u8 *)D_8AB16E18 + 2) &= ~2;
    *(u16 *)((u8 *)D_8AB16E1C + 2) &= ~2;
    *(u16 *)((u8 *)D_8AB16E20[0] + 2) &= ~2;
    *(u16 *)((u8 *)D_8AB16E24 + 2) &= ~2;
    *(u16 *)((u8 *)D_8AB16E28 + 2) &= ~2;
    *(u16 *)((u8 *)D_8AB16E2C + 2) &= ~2;
    *(u16 *)((u8 *)D_8AB16E30 + 2) &= 0xFFFE;
    *(u16 *)((u8 *)D_8AB16E34 + 2) &= 0xFFFE;
    *(u16 *)((u8 *)D_8AB16E38 + 2) &= 0xFFFE;
    *(u16 *)((u8 *)D_8AB16E3C + 2) &= ~2;
    *(u16 *)((u8 *)D_8AB16E40 + 2) &= ~2;
    node = D_8AB16E44;
    *(u16 *)((u8 *)D_8AB16E44 + 2) &= ~2;
    node = D_8AB16E48;
    *(u16 *)((u8 *)D_8AB16E48 + 2) &= ~2;
    *(u16 *)((u8 *)D_8AB16D08 + 2) &= 0xFFFE;
    *(u16 *)((u8 *)D_8AB16D08 + 2) &= ~2;
    *(u16 *)((u8 *)D_8AB11D00 + 2) &= 0xFFFE;
    D_8AB16F70 = 0;
    D_8AB16F74 = 0;
    D_8AB16F68 = 0;
    *(s32 *)(D_8AB11D0C + 0x10) = 0;
    D_8AB16F60 = -1;
    return D_8AB16CF0;
}

extern void *D_8AB13F28;
extern void func_8AB0148C(s16);
extern s32 func_8AB0B67C(s32);
extern s32 func_8AB0B74C(s32);
extern s32 func_8AB0B6E0(s32);
extern s32 func_8AB0B7CC(s32);
extern s32 func_8AB0B96C(s32);
extern s32 func_8AB0BACC(s32);
extern s32 func_8AB0C414(s32);
extern s32 func_8AB0C5CC(s32);
extern s32 func_8AB0C7FC(s32);
extern s32 func_8AB0C9B8(s32);
// FAKE: the file also defines `s32 func_8AB0C9B0(void)`, so a `(s32)` prototype
// conflicts; retail still passes 1 in a0, which a `(void)` prototype cannot express
// (relocation score 1790 without this line's empty parameter list, 1590 with it).
extern s32 func_8AB0C9B0();
extern s32 func_8AB0CA58(s32);
extern s32 func_8AB0CD00(s32);
extern s32 func_8AB0D08C(s32);
extern s32 func_8AB0D20C(s32);
extern s32 func_800279C4(s32);



s32 func_8AB0B24C(s32 arg0) {
    s32 index;

    switch (arg0) {
    case 46: arg0 = func_8AB0B67C(1); break;
    case 47: arg0 = func_8AB0B74C(1); break;
    case 48: arg0 = func_8AB0B6E0(1); break;
    case 49: arg0 = func_8AB0B7CC(1); break;
    case 50: arg0 = func_8AB0B96C(1); break;
    case 51: arg0 = func_8AB0BACC(1); break;
    case 52: arg0 = func_8AB0C414(1); break;
    case 53: arg0 = func_8AB0C5CC(1); break;
    case 54: arg0 = func_8AB0C7FC(1); break;
    case 56: arg0 = func_8AB0C9B8(1); break;
    case 55: arg0 = func_8AB0C9B0(1); break;
    case 57: arg0 = func_8AB0CA58(1); break;
    case 58: arg0 = func_8AB0CD00(1); break;
    case 59: arg0 = func_8AB0D08C(1); break;
    case 60: arg0 = func_8AB0D20C(1); break;
    }
    if (arg0 != 46) {
        if ((arg0 == 51) || (arg0 == 52) || (arg0 == 53)) {
            if (((*(u16 *)((u8 *)D_8AB13F28 + 8)) & 0x1000) != 0) {
                func_800279C4(0xCF07);
                arg0 = func_8AB0CD00(0);
            }
        }
    }
    for (index = 0; index < 4; index++) {
        func_8AB0148C(index);
    }
    return arg0;
}

extern void *D_8AB16CF0;
extern s32 func_8AB0B67C(s32);
extern s32 func_8AB0B74C(s32);
extern s32 func_8AB0B6E0(s32);
extern s32 func_8AB0B7CC(s32);
extern s32 func_8AB0B96C(s32);
extern s32 func_8AB0BACC(s32);
extern s32 func_8AB0C414(s32);
extern s32 func_8AB0C5CC(s32);
extern s32 func_8AB0C7FC(s32);
extern s32 func_8AB0C9B8(s32);
// Unprototyped on purpose: retail's call site passes 2 to a callee that ignores it.
// The definition further down this file (matched, untouchable) is s32 func_8AB0C9B0(void).
// A (s32) prototype here fails the host check with "conflicting types"; the old-style ()
// declaration is compatible with both and emits the li a0,2 delay slot. Diff score
// without it (call spelled func_8AB0C9B0()): 1700.
extern s32 func_8AB0C9B0();
extern s32 func_8AB0CA58(s32);
extern s32 func_8AB0CD00(s32);
extern s32 func_8AB0D08C(s32);
extern s32 func_8AB0D20C(s32);



void func_8AB0B3F4(s32 arg0) {
    func_800503A4((s32) D_8AB16CF0);
    switch (arg0) {
    case 46:
        func_8AB0B67C(2);
        return;
    case 47:
        func_8AB0B74C(2);
        return;
    case 48:
        func_8AB0B6E0(2);
        return;
    case 49:
        func_8AB0B7CC(2);
        return;
    case 50:
        func_8AB0B96C(2);
        return;
    case 51:
        func_8AB0BACC(2);
        return;
    case 52:
        func_8AB0C414(2);
        return;
    case 53:
        func_8AB0C5CC(2);
        return;
    case 54:
        func_8AB0C7FC(2);
        return;
    // Cases 56 and 55 are deliberately out of order: retail's jump table
    // (jtbl_8AB11AC0) has idx 9 (case 55) -> 0x8AB0B4D4 (func_8AB0C9B0) and
    // idx 10 (case 56) -> 0x8AB0B4C4 (func_8AB0C9B8). IDO emits case bodies in
    // source order, so case 56 must be written first or the two table slots swap.
    case 56:
        func_8AB0C9B8(2);
        return;
    case 55:
        func_8AB0C9B0(2);
        return;
    case 57:
        func_8AB0CA58(2);
        return;
    case 58:
        func_8AB0CD00(2);
        return;
    case 59:
        func_8AB0D08C(2);
        return;
    case 60:
        func_8AB0D20C(2);
        return;
    }
}

extern s32 func_8AB0B67C(s32);
s32 func_8AB0B52C(void) {
    return func_8AB0B67C(0);
}

extern s16 D_8AB16F6C;
extern s16 D_8AB16F7C;
extern s16 D_8AB16F60;
extern u8 *D_8AB11D0C;
extern s32 func_8AB0CA58(s32);
extern void Audio_PlayDefaultSound(u16);
s32 func_8AB0B54C(s32 arg0) {
    if (D_8AB16F6C <= 0) {
        D_8AB16F6C = 0;
        arg0 = func_8AB0CA58(0);
        D_8AB16F60 = 0;
        D_8AB11D0C[15] = 0;
    } else if ((D_8AB16F6C < 4) && (D_8AB16F6C != D_8AB16F7C)) {
        Audio_PlayDefaultSound(52992);
    }
    D_8AB16F7C = D_8AB16F6C;
    return arg0;
}

extern s32 func_8AB0B54C(s32);
extern s32 func_80001FF0(void);
extern s16 D_8AB16F6C;
extern u32 D_8AB1268C;
s32 func_8AB0B5E0(s32 arg0) {
    if ((D_8AB16F6C >= 0) && (((u32) D_8AB1268C % (u32) (func_80001FF0() / 2)) == 0)) {
        D_8AB16F6C -= 1;
        if (D_8AB16F6C < 0) {
            D_8AB16F6C = 0;
        }
        arg0 = func_8AB0B54C(arg0);
    }
    return arg0;
}

extern void func_8AB04AE4(void);
extern s32 func_8AB0B7CC(s32);
extern s32 StageContext_GetFadeMode(void);
s32 func_8AB0B67C(s32 arg0) {
    s32 result = 0x2E;

    switch (arg0) {
    case 0:
        func_8AB04AE4();
        break;
    case 1:
        if (StageContext_GetFadeMode() == 0) {
            result = func_8AB0B7CC(0);
        }
        break;
    }
    return result;
}

extern s32 func_8AB0B74C(s32);
extern s16 D_8AB16F7E;
s32 func_8AB0B6E0(s32 arg0) {
    s32 result = 0x30;
    s16 *p;

    p = &D_8AB16F7E;
    switch (arg0) {
    case 0:
        *p = 0;
        break;
    case 1:
        if (*p >= 0xA) {
            func_8AB0B74C(0);
        }
        *p += 1;
        break;
    }
    return result;
}

extern void StageFade_StartFromTransparent(s32);
s32 StageContext_GetFadeMode();
extern void func_800225C4(s32);
s32 func_8002806C();

s32 func_8AB0B74C(s32 arg0) {
    s32 sp1C;

    sp1C = 0x2F;
    switch (arg0) {                                 /* irregular */
    case 0:
        StageFade_StartFromTransparent(5);
        if (func_8002806C() != 0x48) {
            func_800225C4(5);
        }
        break;
    case 1:
        if (StageContext_GetFadeMode() == 1) {
            sp1C = 0;
        }
        break;
    }
    return sp1C;
}

extern void *func_8004C8A0(void *, s32, s32, s32);
extern void func_8AB00B98(u8 *, u32);
extern s32 func_800279C4(s32);
extern s32 func_8AB00548(void);
extern s32 func_8AB00B78(s32);
extern s32 func_8AB0B96C(s32);
extern void func_8AC063AC(void *, u16);
extern void func_8AC06400(void *, void *);
extern u8 D_8AB126A8[];
extern void *D_8AB11D00;
extern void *D_8AB12688;
extern u16 D_8AB1268E;
extern s16 D_8AB1269C;
extern s32 D_8AB12BA8;
extern s32 D_8AB12CBC;
extern s32 D_8AB12D50;
extern s32 D_8AB12DE4;
extern s32 D_8AB12E78;
extern void *D_8AB13F28;
extern void *D_8AB16E4C;
extern s32 D_8AB16E50;
extern s16 D_8AB16F6C;

s32 func_8AB0B7CC(s32 arg0) {
    u16 temp_v0; /* unused; its 0x1C home slot places result at 0x18 as in the original frame */
    s32 result;

    result = 0x31;
    switch (arg0) {
    case 0:
        func_8004C8A0(D_8AB126A8, 0x100, 0x39, 0x276);
        *(u16 *)((u8 *)D_8AB11D00 + 2) = (u16)(*(u16 *)((u8 *)D_8AB11D00 + 2) | 1);
        func_8004C8A0(&D_8AB12BA8, 0x100, 0x39, 0x277);
        *(u16 *)((u8 *)D_8AB12688 + 2) = (u16)(*(u16 *)((u8 *)D_8AB12688 + 2) | 1);
        func_8AB00B98(D_8AB12688, -1U);
        func_8AB04AE4();
        D_8AB16F6C = 0x64;
        func_8AC06400(&D_8AB16E50, D_8AB16E4C);
        *(u16 *)((u8 *)D_8AB16E4C + 2) = (u16)(*(u16 *)((u8 *)D_8AB16E4C + 2) | 1);
        D_8AB12CBC = 0;
        D_8AB12D50 = 0;
        D_8AB12DE4 = 0;
        D_8AB12E78 = 0;
        D_8AB1269C = 0x14;
        func_8AB00548();
        break;
    case 1:
        func_8AC063AC(&D_8AB16E50, D_8AB1268E);
        if (*(u16 *)((u8 *)D_8AB13F28 + 8) & 0x8000) {
            *(u16 *)((u8 *)D_8AB16E4C + 2) = (u16)(*(u16 *)((u8 *)D_8AB16E4C + 2) & 0xFFFE);
            *(u16 *)((u8 *)D_8AB12688 + 2) = (u16)(*(u16 *)((u8 *)D_8AB12688 + 2) & 0xFFFE);
            func_800279C4(0xCF0B);
            result = func_8AB0B96C(0);
        } else if (*(u16 *)((u8 *)D_8AB13F28 + 8) & 0x4000) {
            result = func_8AB0B74C(0);
            func_8AB00B78(3);
        }
        break;
    }
    return result;
}
typedef struct {
    u8 pad[8];
    s16 x;
    s16 y;
} Fragment45B96CState;
extern s16 D_8AB16EC8;
extern void *D_8AB16F64;
extern s32 D_8AB16F78;
extern u8 D_8AB126A8[];
extern void func_87F005F0(f32, f32);
extern void func_87F006BC(void);
extern u32 func_87F006AC(void);
extern void *func_8004C8A0(void *, s32, s32, s32);
extern void func_800225C4(s32);
extern void func_8AB00BA4();
extern void func_80021ED8(s32);
extern s32 func_8AB0BACC(s32);
extern void Geo_RenderRootNode(s32);
s32 func_8AB0B96C(s32 arg0) {
    s32 result = 0x32;
    s16 temp_v0;

    switch (arg0) {
    case 0:
        func_87F005F0((f32)(*(s16 *)((u8 *)D_8AB16F64 + 8) - 0x140),
                      (f32)(0xF0 - *(s16 *)((u8 *)D_8AB16F64 + 0xA)));
        func_8004C8A0(D_8AB126A8, 0x100, 0x3A, 0x183);
        D_8AB16EC8 = 3;
        func_800225C4(0x5A);
        break;
    case 1:
        func_87F006BC();
        temp_v0 = func_87F006AC();
        switch (temp_v0) {
        case 1:
            func_8AB00BA4(0x64, D_8AB16EC8, 0);
            D_8AB16EC8 -= 1;
            break;
        case 2:
            func_8AB00BA4(0x64, D_8AB16EC8, 0);
            func_80021ED8(0x4C);
            D_8AB16EC8 -= 1;
            break;
        case 3:
            result = func_8AB0BACC(0);
            break;
        }
        break;
    case 2:
        Geo_RenderRootNode(D_8AB16F78);
        break;
    }
    return result;
}

extern void func_8AB00BA4();
extern void func_8AB04AE4(void);
extern void func_8AB00478(void);
extern s32 func_8AB023EC(s32);
extern s32 func_8AB0B54C(s32);
extern s32 func_8AB0C414(s32);
extern void func_8004C594(s32, s32);
extern void *func_8004C8A0(void *, s32, s32, s32);
extern u8 D_8AB126A8[];
extern s16 D_8AB12CB2;
extern void *D_8AB11D00;
extern void *D_8AB16D08;
extern void *D_8AB16F48[];
extern void *D_8AB16F4C;
extern void *D_8AB16F50;
extern void *D_8AB16F54;
extern s16 D_8AB12692;
extern s16 D_8AB12694;
extern s16 D_8AB12698;
extern s16 D_8AB13F2C;
extern s16 D_8AB16F6C;
extern s32 D_8AB16F68;
extern s32 D_8AB16F70;
extern s16 D_8AB16F74;
extern s16 D_8AB16F80;



s32 func_8AB0BACC(s32 arg0) {
    s16 *D_8AB16F80_ptr = &D_8AB16F80;
    s32 sp18;
    s16 temp_v0;
    s32 var_v0;
    void **D_8AB16F48_ptr = D_8AB16F48;
    void **D_8AB16F4C_ptr = &D_8AB16F4C;
    void **D_8AB16F54_ptr = &D_8AB16F54;
    void **D_8AB16F50_ptr = &D_8AB16F50;

    sp18 = 0x33;
    switch (arg0) {
    case 0:
        func_8AB00BA4(0x10006, 0, 0);
        (*D_8AB16F80_ptr) = 0;
        if ((D_8AB12694 + D_8AB12698) > 0) {
            *(u16 *)((u8 *)D_8AB11D00 + 2) = (u16)(*(u16 *)((u8 *)D_8AB11D00 + 2) | 1);
            func_8004C594(2, D_8AB12692 + 1);
            if (D_8AB16F68 != 0) {
                func_8004C8A0(D_8AB126A8, 0x100, 0x39, 0x283);
            } else {
                /* D_8AB13F2C indexes a 148-byte record; the switch subject is
                   the s16 at that record's offset 0.  The non-default cases are
                   the values 5, 10, ... 50 selecting message ids 0x285..0x28B. */
                switch (*(s16 *)((u8 *)&D_8AB12CB2 + D_8AB13F2C * 0x94)) {
                case 5:
                    func_8004C8A0(D_8AB126A8, 0x100, 0x39, 0x285);
                    break;
                case 10:
                    func_8004C8A0(D_8AB126A8, 0x100, 0x39, 0x286);
                    break;
                case 15:
                    func_8004C8A0(D_8AB126A8, 0x100, 0x39, 0x287);
                    break;
                case 20:
                    func_8004C8A0(D_8AB126A8, 0x100, 0x39, 0x288);
                    break;
                case 30:
                    func_8004C8A0(D_8AB126A8, 0x100, 0x39, 0x289);
                    break;
                case 40:
                    func_8004C8A0(D_8AB126A8, 0x100, 0x39, 0x28A);
                    break;
                case 50:
                    func_8004C8A0(D_8AB126A8, 0x100, 0x39, 0x28B);
                    break;
                default:
                    func_8004C8A0(D_8AB126A8, 0x100, 0x3A, func_8AB023EC(9) + 0x184);
                    break;
                }
            }
        } else {
            *(u16 *)((u8 *)D_8AB11D00 + 2) = (u16)(*(u16 *)((u8 *)D_8AB11D00 + 2) & 0xFFFE);
        }
        func_8AB04AE4();
        *(u16 *)((u8 *)D_8AB16D08 + 2) = (u16)(*(u16 *)((u8 *)D_8AB16D08 + 2) & 0xFFFE);
        *(u16 *)((u8 *)(*D_8AB16F48_ptr) + 2) = (u16)(*(u16 *)((u8 *)(*D_8AB16F48_ptr) + 2) & 0xFFFD);
        *(u16 *)((u8 *)(*D_8AB16F4C_ptr) + 2) = (u16)(*(u16 *)((u8 *)(*D_8AB16F4C_ptr) + 2) & 0xFFFD);
        *(u16 *)((u8 *)(*D_8AB16F50_ptr) + 2) = (u16)(*(u16 *)((u8 *)(*D_8AB16F50_ptr) + 2) & 0xFFFD);
        *(u16 *)((u8 *)(*D_8AB16F54_ptr) + 2) = (u16)(*(u16 *)((u8 *)(*D_8AB16F54_ptr) + 2) & 0xFFFD);
        func_8AB00478();
        break;
    case 1:
        temp_v0 = (*D_8AB16F80_ptr) + 1;
        if (D_8AB16F68 != 0) {
            if (temp_v0 >= 0x3C) {
                (*D_8AB16F80_ptr) = temp_v0;
                var_v0 = func_8AB0C414(0);
                goto block_31;
            }
            (*D_8AB16F80_ptr) = temp_v0;
            if ((temp_v0 >= 0x14) && (D_8AB16F70 != 0) && (D_8AB16F74 > 0)) {
                D_8AB16F6C -= 1;
                if (D_8AB16F6C < 0) {
                    D_8AB16F6C = 0;
                }
                D_8AB16F74 -= 1;
                if (D_8AB16F74 <= 0) {
                    D_8AB16F70 = 0;
                }
                var_v0 = func_8AB0B54C(0x33);
                goto block_31;
            }
        } else {
            (*D_8AB16F80_ptr) = temp_v0;
            if (temp_v0 >= 0x2D) {
                var_v0 = func_8AB0C414(0);
block_31:
                sp18 = var_v0;
            }
        }
        break;
    }
    return sp18;
}

extern u8 D_8AB16D10[];
extern s16 D_8AB16F82;
extern s16 D_8AB16F84;
extern s8 *D_8AB112BC;
extern s32 HAL_Strcmp(const s8 *, const s8 *);
s32 func_8AB0BE4C(void) {
    u8 *node;
    u8 *cursor;
    u8 *last;
    s32 i;

    node = D_8AB11D00;
    func_8004C8A0(D_8AB16D10, 256, *(u16 *)(node + 48), *(u16 *)(node + 50));
    cursor = D_8AB16D10;
    for (i = 0; i < D_8AB16F82; i++) {
        last = cursor;
        if (*cursor == 0) {
            D_8AB16F84 = 1;
            return 0;
        }
        if (*cursor == 10) {
            cursor++;
        } else if ((*cursor & 0x80) == 0) {
            cursor++;
        } else {
            cursor += 2;
        }
    }
    *cursor = 0;
    if ((D_8AB1268C & 1) == 0) {
        if (HAL_Strcmp((s8 *)last, D_8AB112BC) == 0) {
            func_8AB00BA4(65549, 0, 0);
        } else {
            func_8AB00BA4(65548, 0, 0);
        }
        D_8AB16F82++;
    }
    return 1;
}

void func_8AB0BF70(u8 *arg0) {
    *(s32 *)(arg0 + 0xC) = 1;
    *(s16 *)(arg0 + 0x10) = 1;
}

extern u8 D_8AB12CB0[];
extern s16 D_8AB1269A;
extern void *D_8AB16F48[];
extern u8 *D_8AB12668[];
extern s16 D_8AB16F86;
extern s16 D_8AB16F88;
extern s32 D_8AB112A0;
extern void *D_80087200;
extern void *D_80087204;
extern void *D_80087208;
extern void *D_8008720C;
extern void TextRow_SetOrangeState(s16);
extern void func_8AB01414(s16);
extern void func_8AB01454(s16);
extern void func_8AB03DFC(s16, s16);
extern void func_8AB0BF70(u8 *);
extern void func_8AB00B98(u8 *, u32);
extern void TextHighlight_AnimateScales(void);
extern void func_8AB04038(void);



void func_8AB0BF80(void) {
    s32 i;
    u16 buttons;
    u8 *row;
    u8 *panel;

    D_8AB16F86 = 0;
    D_8AB16F88 = 0;
    for (i = 0, row = D_8AB12CB0; i < 4; i++) {
        if (*(s16 *)(row + 4) == 0 && *(s32 *)(row + 12) == 0 && *(s16 *)row != 0) {
            D_8AB16F88++;
            switch (i) {
            case 0:
                buttons = *(u16 *)((u8 *)D_80087200 + 8);
                break;
            case 1:
                buttons = *(u16 *)((u8 *)D_80087204 + 8);
                break;
            case 2:
                buttons = *(u16 *)((u8 *)D_80087208 + 8);
                break;
            case 3:
                buttons = *(u16 *)((u8 *)D_8008720C + 8);
                break;
            }
            if ((*(u16 *)((u8 *)D_8AB16F48[0] + 2) & 2) == 0 && (buttons & 8)) {
                if (D_8AB1269A == 0) {
                    TextRow_SetOrangeState(i);
                    func_8AB01414(i);
                } else {
                    func_8AB03DFC(i, 0);
                    func_8AB01454(i);
                    func_8AB0BF70(row);
                }
                panel = (u8 *)D_8AB16F48[0];
                D_8AB16F86 = 1;
                // Each mask store below records a source line far beneath the
                // D_8AB16F86 store that precedes it; as1 then hoists the mask's
                // `li` above the flag store, which is retail's addiu/sh/sh order.
#line 314
                *(s16 *)(row + 6) = 8;
#line 316
                *(u16 *)(panel + 2) |= 2;
                *(s16 *)((u8 *)D_8AB16F48[0] + 0x26) = i + 6;
                func_8AB00B98(D_8AB12668[0], 0xFFFF00FFU);
            } else if ((*(u16 *)((u8 *)D_8AB16F48[1] + 2) & 2) == 0 && (buttons & 1)) {
                if (D_8AB1269A == 1) {
                    TextRow_SetOrangeState(i);
                    func_8AB01414(i);
                } else {
                    func_8AB03DFC(i, 1);
                    func_8AB01454(i);
                    func_8AB0BF70(row);
                }
                panel = (u8 *)D_8AB16F48[1];
                D_8AB16F86 = 1;
                *(s16 *)(row + 6) = 1;
                *(u16 *)(panel + 2) |= 2;
                *(s16 *)((u8 *)D_8AB16F48[1] + 0x26) = i + 6;
                func_8AB00B98(D_8AB12668[1], 0xFFFF00FFU);
            } else if ((*(u16 *)((u8 *)D_8AB16F48[2] + 2) & 2) == 0 && (buttons & 4)) {
                if (D_8AB1269A == 2) {
                    TextRow_SetOrangeState(i);
                    func_8AB01414(i);
                } else {
                    func_8AB03DFC(i, 2);
                    func_8AB01454(i);
                    func_8AB0BF70(row);
                }
                panel = (u8 *)D_8AB16F48[2];
                D_8AB16F86 = 1;
#line 100
                *(s16 *)(row + 6) = 4;
#line 350
                *(u16 *)(panel + 2) |= 2;
                *(s16 *)((u8 *)D_8AB16F48[2] + 0x26) = i + 6;
                func_8AB00B98(D_8AB12668[2], 0xFFFF00FFU);
            } else if ((*(u16 *)((u8 *)D_8AB16F48[3] + 2) & 2) == 0 && (buttons & 2)) {
                if (D_8AB1269A == 3) {
                    TextRow_SetOrangeState(i);
                    func_8AB01414(i);
                } else {
                    func_8AB03DFC(i, 3);
                    func_8AB01454(i);
                    func_8AB0BF70(row);
                }
                panel = (u8 *)D_8AB16F48[3];
                D_8AB16F86 = 1;
#line 100
                *(s16 *)(row + 6) = 2;
#line 367
                *(u16 *)(panel + 2) |= 2;
                *(s16 *)((u8 *)D_8AB16F48[3] + 0x26) = i + 6;
                func_8AB00B98(D_8AB12668[3], 0xFFFF00FFU);
            }
            if (*(s32 *)(row + 12) == 0 && *(s16 *)(row + 2) >= 0x8D) {
                D_8AB112A0 = 1;
                *(s32 *)(row + 8) = 1;
            }
        }
        row += 148;
    }
    TextHighlight_AnimateScales();
    func_8AB04038();
}

extern void func_8AB03394(void);
extern void TextChoice_ShuffleAndRefresh(void);
extern void TextPanels_UpdateVisibility(void);
extern void _bzero(void *, s32);
extern void func_8004C594(s32, s32);
extern void *D_8AB16D08;
extern u8 *D_8AB12668[];
extern u8 *D_8AB12678[];
extern s16 D_8AB12692;
extern s32 D_8AB112A0;
extern s32 D_8AB16F68;
extern s16 D_8AB16F86;
extern void func_8AB0BF80(void);
extern s32 func_8AB0C5CC(s32);
extern s32 func_8AB0C7FC(s32);

// Close to func_8AB09A28 (fragment45_22AB80.c) with this file's state flags, buffers and
// handlers; returns state 52 and also clears D_8AB112A0 when entering.
//@src/fragments/45/fragment45_22AB80.c
s32 func_8AB0C414(s32 arg0) {
    s32 result;
    s32 new_var;
    u8 **ptr;
    u8 **end;
    u8 **ptr2;
    u8 **end2;
    u8 *temp;

    new_var = 1;
    result = 52;
    switch (arg0) {
        case 0:
            func_8AB03394();
            TextChoice_ShuffleAndRefresh();
            new_var = 1;
            D_8AB16F82 = new_var;
            D_8AB16F84 = 0;
            _bzero(&D_8AB16D10, 0x100);
            *(u16 *)((u8 *)D_8AB16D08 + 2) = (u16)(*(u16 *)((u8 *)D_8AB16D08 + 2) | 1);
            *(u16 *)((u8 *)D_8AB11D00 + 2) &= 0xFFFE;
            TextPanels_UpdateVisibility();
            // FAKE: &D_8AB12668[4] is the address of D_8AB12678; spelling it through D_8AB12668
            // keeps uopt from sharing one D_8AB12678 address register between the two loops,
            // as in func_8AB09A28; diff score 620 without it.
            // FAKE: the comma expressions keep the lui/addiu order of both loop-preheader
            // pairs; diff score 65 with separate statements.
            ptr2 = &D_8AB12668[4], end2 = (u8 **)&D_8AB12688;
            do {
                temp = *ptr2;
                ptr2++;
                *(u16 *)((u8 *)temp + 2) = (u16)(*(u16 *)((u8 *)temp + 2) | 1);
            } while (ptr2 < end2);
            ptr = D_8AB12668, end = D_8AB12678;
            do {
                func_8AB00B98(*ptr, -1U);
                ptr++;
            } while (ptr != end);
            func_8004C594(2, D_8AB12692 + 1);
            D_8AB112A0 = 0;
            D_8AB16F68 = 0;
            func_8AB00548();
            break;
        case 1:
            func_8AB0BF80();
            func_8AB0BE4C();
            if (D_8AB16F84 == new_var) {
                result = func_8AB0C5CC(0);
            }
            if (new_var == D_8AB16F86) {
                result = func_8AB0C7FC(0);
                if (D_8AB16F84 == 0) {
                    func_8004C8A0(D_8AB16D10, 0x100, *(u16 *)((u8 *)D_8AB11D00 + 0x30), *(u16 *)((u8 *)D_8AB11D00 + 0x32));
                }
            }
            result = func_8AB0B5E0(result);
            break;
        case 2:
            break;
    }
    return result;
}

/* mkdraft:func_8AB0C5CC begin */
extern s16 D_8AB1269C;
extern s16 D_8AB16F86;
extern s16 D_8AB16F88;
extern s32 D_8AB16F8C;
extern void func_8AB01728(void);
extern void func_8AB0BF80(void);
extern s32 func_8AB0C7FC(s32);

s32 func_8AB0C5CC(s32 arg0) {
    s16 n;
    s32 result;
    result = 0x35;
    switch (arg0) {
    case 0:
        D_8AB1269C = 0x14;
        D_8AB16F8C = 0;
        break;
    case 1:
        func_8AB01728();
        func_8AB0BF80();
        if (D_8AB16F8C % (func_80001FF0() / 4) == 0) {
            D_8AB1269C--;
            if (D_8AB1269C < 0) {
                D_8AB1269C = 0;
                if (D_8AB16F86 == 0) {
                    func_8AB00BA4(0x65, 0, 0);
                }
                D_8AB16F86 = 1;
            }
        }
        if (D_8AB16F8C % ((func_80001FF0() / 4) * 2) == 0) {
            n = D_8AB1269C / 2 + 1;
            if (D_8AB16F86 == 0) {
                func_8AB00BA4(0x65, n, 0);
            }
        }
        if (D_8AB16F88 == 0 || D_8AB16F86 == 1) {
            result = func_8AB0C7FC(0);
        }
        result = func_8AB0B5E0(result);
        D_8AB16F8C++;
        break;
    case 2:
        break;
    }
    return result;
}
/* mkdraft:func_8AB0C5CC end */

void func_8AB0C7C0(void *arg0, s32 arg1) {
    if ((*(s32 *)((u8 *)(arg0) + (0xC))) == 1) {
        (*(s16 *)((u8 *)(arg0) + (0x10))) = (s16) ((*(s16 *)((u8 *)(arg0) + (0x10))) - 1);
        if ((*(s16 *)((u8 *)(arg0) + (0x10))) <= 0) {
            (*(s16 *)((u8 *)(arg0) + (0x10))) = 0;
            (*(s32 *)((u8 *)(arg0) + (0xC))) = 0;
        }
    }
}

/* mkdraft:func_8AB0C7FC begin */
extern u8 D_8AB12CB0[];
extern void TextHighlight_AnimateScales(void);
extern s32 func_8AB0C9B8(s32 arg0);
extern s32 D_8AB16F70;
extern s16 D_8AB16F74;
extern s32 D_8AB16F68;
extern s16 D_8AB16F90;
extern s32 func_80001FF0(void);
extern void func_8AB00BA4();
extern s32 func_8AB0B54C(s32 arg0);
extern void func_8AB0C7C0(void *arg0, s32 arg1);

// Same state machine shape as func_8AB09E28 (fragment45_22AB80.c) over this file's
// row table and counters: D_8AB12CB0 holds four 148-byte rows, ending at D_8AB12F00.
//@src/fragments/45/fragment45_22AB80.c


s32 func_8AB0C7FC(s32 arg0) {
    s32 result;
    s16 *counter = &D_8AB16F90;
    s32 i;
    s32 all_wrong;
    u8 *row;

    result = 0x36;
    switch (arg0) {
    case 2:
        break;
    case 0:
        *counter = 0;
        all_wrong = 1;
        for (i = 0; i < 4; i++) {
            row = D_8AB12CB0 + i * 148;
            if (*(s16 *)row != 0 && *(s16 *)(row + 4) != 2) {
                all_wrong = 0;
            }
        }
        if (all_wrong) {
            for (i = 0; i < 4; i++) {
                row = D_8AB12CB0 + i * 148;
                func_8AB0C7C0(row, i);
            }
            D_8AB16F70 = 1;
            D_8AB16F74 = 10;
            D_8AB16F68 = 1;
        } else {
            for (i = 0; i < 4; i++) {
                row = D_8AB12CB0 + i * 148;
                if (*(s16 *)row != 0 && *(s16 *)(row + 4) == 0) {
                    func_8AB0C7C0(row, i);
                }
            }
        }
        break;
    case 1:
        *counter += 1;
        TextHighlight_AnimateScales();
        if (*counter == func_80001FF0() / 4) {
            func_8AB00BA4(0x66, 0, 0);
        }
        if (*counter >= 0x1F) {
            result = func_8AB0C9B8(0);
        }
        result = func_8AB0B54C(result);
        break;
    }
    return result;
}
/* mkdraft:func_8AB0C7FC end */

s32 func_8AB0C9B0(void) {
    return 0x37;
}

extern void func_8AB01FBC(void);
extern void func_8AB03ED4(void);
extern void func_8AB012A4(void);
extern s32 func_8AB0BACC(s32);
extern s32 func_8AB0B5E0(s32);
extern s16 D_8AB16F92;
s32 func_8AB0C9B8(s32 arg0) {
    s32 result = 0x38;
    s16 *p;

    p = &D_8AB16F92;
    switch (arg0) {
    case 0:
        *p = 0;
        func_8AB01FBC();
        break;
    case 1:
        *p += 1;
        func_8AB03ED4();
        if (*p >= 0xB) {
            func_8AB012A4();
            result = func_8AB0BACC(0);
        }
        result = func_8AB0B5E0(result);
        break;
    }
    return result;
}

/* mkdraft:func_8AB0CA58 begin */
extern void *D_8AB16F48[];
extern void *D_8AB16F58;
extern void *D_8AB1267C;
extern void *D_8AB12680;
extern void *D_8AB12684;
extern s32 D_8AB16F70;
extern s16 D_8AB16F74;
extern s16 D_8AB16F94;
extern s32 func_8AB0D08C(s32);
extern void TextHighlight_AnimateScales(void);

// Per-call handler for the highlighted-text state that func_8AB0B54C enters with
// func_8AB0CA58(0). Case 0 arms the state: it clears bit 0 of the status halfword of
// D_8AB16D08, D_8AB12678, D_8AB1267C, D_8AB12680 and D_8AB12684, clears bit 1 of the
// status halfword of the four pointers at D_8AB16F48, loads the panel resources and
// zeroes D_8AB16F70/D_8AB16F74. Case 1 animates the highlight and counts D_8AB16F94;
// after 0x3D calls func_8AB0D08C supplies the next state id. Until then the function
// keeps returning state id 0x39.


s32 func_8AB0CA58(s32 arg0) {
    s16 *state_frames = &D_8AB16F94;
    s32 result;
    void **node_ptr;
    void **end;
    void *node;
    // FAKE: four copies of the addresses of D_8AB1267C/D_8AB12678/D_8AB12680/D_8AB12684
    // push the five status-halfword clears below into the register set the retail code
    // uses (v1/t3/t6/t9/t2 instead of v0/v1/...); each one is required - the clears
    // read straight from the globals score 185, 230, 140 and 350 respectively, and 355
    // with all four replaced.
    void **D_8AB1267C_ptr = &D_8AB1267C;
    u8 **D_8AB12678_ptr = D_8AB12678;
    void **D_8AB12684_ptr = &D_8AB12684;
    void **D_8AB12680_ptr = &D_8AB12680;

    result = 0x39;
    switch (arg0) {
    case 0:
        *state_frames = 0;
        node_ptr = &D_8AB16F48, end = &D_8AB16F58;
        *(u16 *)((u8 *)D_8AB11D00 + 2) = (u16)(*(u16 *)((u8 *)D_8AB11D00 + 2) | 1);
        do {
            node = *node_ptr;
            node_ptr++;
            *(u16 *)((u8 *)node + 2) = (u16)(*(u16 *)((u8 *)node + 2) & ~2);
        } while (node_ptr < end);
        func_8004C8A0(D_8AB126A8, 0x100, 0x39, 0x185);
        func_8AB04AE4();
        *(u16 *)((u8 *)D_8AB16D08 + 2) = (u16)(*(u16 *)((u8 *)D_8AB16D08 + 2) & ~1);
        *(u16 *)((u8 *)*D_8AB12678_ptr + 2) = (u16)(*(u16 *)((u8 *)*D_8AB12678_ptr + 2) & ~1);
        *(u16 *)((u8 *)(*D_8AB1267C_ptr) + 2) = (u16)(*(u16 *)((u8 *)(*D_8AB1267C_ptr) + 2) & ~1);
        *(u16 *)((u8 *)(*D_8AB12680_ptr) + 2) = (u16)(*(u16 *)((u8 *)(*D_8AB12680_ptr) + 2) & ~1);
        *(u16 *)((u8 *)(*D_8AB12684_ptr) + 2) = (u16)(*(u16 *)((u8 *)(*D_8AB12684_ptr) + 2) & ~1);
        func_8AB00BA4(0x66, 0, 0);
        func_800279C4(0xCF06);
        func_800225C4(0x28);
        D_8AB16F70 = 0;
        D_8AB16F74 = 0;
        break;
    case 1:
        *state_frames += 1;
        TextHighlight_AnimateScales();
        if (*state_frames >= 0x3D) {
            result = func_8AB0D08C(0);
        }
        break;
    }
    return result;
}
/* mkdraft:func_8AB0CA58 end */

extern void *D_8AB16E30;
extern void *D_8AB16E34;
extern void *D_8AB16E38;
extern u8 *D_8AB16E40;
extern u8 *D_8AB16E44;
extern u8 *D_8AB16E48;
extern s16 D_8AB16F96;
void func_8AB0CBCC(void) {
    (*(u16 *)((u8 *)(D_8AB16E30) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AB16E30) + (2))) & 0xFFFE);
    (*(u16 *)((u8 *)(D_8AB16E34) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AB16E34) + (2))) & 0xFFFE);
    (*(u16 *)((u8 *)(D_8AB16E38) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AB16E38) + (2))) & 0xFFFE);
    func_8AB00B98(D_8AB16E40, -1U);
    func_8AB00B98(D_8AB16E44, -1U);
    func_8AB00B98(D_8AB16E48, -1U);
    switch (D_8AB16F96) {                           /* irregular */
    case 0:
        (*(u16 *)((u8 *)(D_8AB16E30) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AB16E30) + (2))) | 1);
        func_8AB00B98(D_8AB16E40, 0xFFFF00FFU);
        return;
    case 1:
        (*(u16 *)((u8 *)(D_8AB16E34) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AB16E34) + (2))) | 1);
        func_8AB00B98(D_8AB16E44, 0xFFFF00FFU);
        return;
    case 2:
        (*(u16 *)((u8 *)(D_8AB16E38) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AB16E38) + (2))) | 1);
        func_8AB00B98(D_8AB16E48, 0xFFFF00FFU);
        return;
    }
}

/* mkdraft:func_8AB0CD00 begin */
extern s16 D_8AB126A0;
extern s16 D_8AB12CB4;
extern s16 D_8AB12CB2;
extern s32 D_8AB12CB8;
extern s16 D_8AB12CC0;
extern s16 D_8AB12D46;
extern s16 D_8AB12D48;
extern s32 D_8AB12D4C;
extern s16 D_8AB12D54;
extern s16 D_8AB12DDA;
extern s16 D_8AB12DDC;
extern s32 D_8AB12DE0;
extern s16 D_8AB12DE8;
extern s16 D_8AB12E6E;
extern s16 D_8AB12E70;
extern s32 D_8AB12E74;
extern s16 D_8AB12E7C;
extern void *D_8AB16E3C;
extern void *D_8AB16F48[];
extern void *D_8AB16F4C;
extern void *D_8AB16F50;
extern void *D_8AB16F54;
extern s32 D_8AB16F70;
extern s16 D_8AB16F74;
extern s32 D_8AB16F98;
extern void TextReference_BuildModeSelection(void);
extern void func_8AB005B0(void);
extern void func_8AB01288(void);


s32 func_8AB0CD00(s32 arg0)
{
    s32 temp_v0; /* Declaration order places result at 0x18 in the 0x20-byte frame. */
    s32 result;
    void *new_var; /* FAKE: dead store; splits the two loads of D_8AB16F50. Without it: 860. */
    void **p_f48 = &D_8AB16F48; /* FAKE: address-of-extern indirection; direct use: 835. */
    void **p_f4c = &D_8AB16F4C; /* FAKE: address-of-extern indirection; direct use: 825. */
    void **p_f50 = &D_8AB16F50; /* FAKE: address-of-extern indirection; direct use: 990. */
    void **p_f54 = &D_8AB16F54; /* FAKE: address-of-extern indirection; direct use: 990. */
    if (result != 0x3A)
    {
        D_8AB16F98 = result;
        result = 0x3A;
    }
    switch (arg0)
    {
        case 0:
            D_8AB16F96 = 0;
            *((u16 *) (((u8 *) D_8AB16D08) + 2)) = (u16) ((*((u16 *) (((u8 *) D_8AB16D08) + 2))) & 0xFFFE);
            *((u16 *) (((u8 *) D_8AB11D00) + 2)) = (u16) ((*((u16 *) (((u8 *) D_8AB11D00) + 2))) & 0xFFFE);
            *((u16 *) (((u8 *) D_8AB16E3C) + 2)) = (u16) ((*((u16 *) (((u8 *) D_8AB16E3C) + 2))) | 2);
            *((u16 *) (((u8 *) D_8AB16E40) + 2)) = (u16) ((*((u16 *) (((u8 *) D_8AB16E40) + 2))) | 2);
            *((u16 *) (((u8 *) D_8AB16E44) + 2)) = (u16) ((*((u16 *) (((u8 *) D_8AB16E44) + 2))) | 2);
            *((u16 *) (((u8 *) D_8AB16E48) + 2)) = (u16) ((*((u16 *) (((u8 *) D_8AB16E48) + 2))) | 2);
            *((u16 *) (((u8 *) (*p_f48)) + 2)) = (u16) ((*((u16 *) (((u8 *) (*p_f48)) + 2))) & 0xFFFD);
            *((u16 *) (((u8 *) (*p_f4c)) + 2)) = (u16) ((*((u16 *) (((u8 *) (*p_f4c)) + 2))) & 0xFFFD);
            *((u16 *) (((u8 *) (*p_f50)) + 2)) = (u16) ((*((u16 *) (((u8 *) (new_var = *p_f50)) + 2))) & 0xFFFD);
            *((u16 *) (((u8 *) (*p_f54)) + 2)) = (u16) ((*((u16 *) (((u8 *) (*p_f54)) + 2))) & 0xFFFD);
            func_8AB04AE4();
            D_8AB126A0 = 0;
            func_8AB00BA4(0x66, 0, 0);
            func_80021ED8(0x50);
            D_8AB1269C = 0x14;
            func_8AB005B0();
            D_8AB16F70 = 0;
            D_8AB16F74 = 0;
            break;

        case 1:
            temp_v0 = *((u16 *) (((u8 *) D_8AB13F28) + 8));
            if (temp_v0 & 0x800)
        {
            D_8AB16F96 = D_8AB16F96 - 1;
            if (D_8AB16F96 < 0)
            {
                D_8AB16F96 = 2;
            }
            func_800279C4(0xCF01);
        }
        else
            if (temp_v0 & 0x400)
        {
            D_8AB16F96 += 1;
            if (D_8AB16F96 >= 3)
            {
                D_8AB16F96 = 0;
            }
            func_800279C4(0xCF01);
        }
        else
            if (temp_v0 & 0x8000)
        {
            switch (D_8AB16F96)
            {
                case 0:
                    func_800279C4(0xCF02);
                    *((u16 *) (((u8 *) D_8AB16E3C) + 2)) = (u16) ((*((u16 *) (((u8 *) D_8AB16E3C) + 2))) & 0xFFFD);
                    *((u16 *) (((u8 *) D_8AB16E40) + 2)) = (u16) ((*((u16 *) (((u8 *) D_8AB16E40) + 2))) & 0xFFFD);
                    *((u16 *) (((u8 *) D_8AB16E44) + 2)) = (u16) ((*((u16 *) (((u8 *) D_8AB16E44) + 2))) & 0xFFFD);
                    *((u16 *) (((u8 *) D_8AB16E48) + 2)) = (u16) ((*((u16 *) (((u8 *) D_8AB16E48) + 2))) & 0xFFFD);
                    D_8AB16F96 = -1;
                    func_8AB01288();
                    D_8AB12CB2 = 0;
                    D_8AB12CB4 = 0;
                    D_8AB12CB8 = 0;
                    D_8AB12CBC = 0;
                    D_8AB12CC0 = 0;
                    D_8AB12D46 = 0;
                    D_8AB12D48 = 0;
                    D_8AB12D4C = 0;
                    D_8AB12D50 = 0;
                    D_8AB12D54 = 0;
                    D_8AB12DDA = 0;
                    D_8AB12DDC = 0;
                    D_8AB12DE0 = 0;
                    D_8AB12DE4 = 0;
                    D_8AB12DE8 = 0;
                    D_8AB12E6E = 0;
                    D_8AB12E70 = 0;
                    D_8AB12E74 = 0;
                    D_8AB12E78 = 0;
                    D_8AB12E7C = 0;
                    TextReference_BuildModeSelection();
                    result = func_8AB0B7CC(0);
                    break;

                case 1:
                    func_800279C4(0xCF02);
                    *((s32 *) (((u8 *) D_8AB11D0C) + 0x10)) = 1;
                    result = func_8AB0B74C(0);
                    break;

                case 2:
                    func_8AB00B78(3);
                    result = func_8AB0B74C(0);
                    break;

            }

        }
            func_8AB0CBCC();
            break;

    }

    return result;
}
/* mkdraft:func_8AB0CD00 end */

/* mkdraft:func_8AB0D08C begin */
extern s16 D_8AB126A0;
extern s16 D_8AB12CB2;
extern s16 D_8AB13F2C;
extern s16 D_8AB16F9C;
extern void TextHighlight_AnimateScales(void);
extern u8 func_80054668(s32 arg0);
extern s32 func_8AB0CD00();
extern s32 func_8AB0D20C();



s32 func_8AB0D08C(s32 arg0) {
    s32 result;
    s16 *timer;
    s32 selection;

    timer = &D_8AB16F9C;
    result = 0x3B;
    switch (arg0) {
    case 0:
        *timer = 0;
        *(u16 *)((u8 *)D_8AB16D08 + 2) &= ~1;
        func_8AB04AE4();
        func_8004C594(3,
                     *(s16 *)((u8 *)&D_8AB12CB2 +
                              D_8AB13F2C * 0x94));
        func_8004C8A0(D_8AB126A8, 0x100, 0x39, 4);
        *(u16 *)((u8 *)D_8AB11D00 + 2) |= 1;
        func_80021ED8(0x37);
        func_80027774(0xCA0F, 0x24);
        D_8AB126A0 = 0;
        break;
    case 1:
        *timer += 1;
        TextHighlight_AnimateScales();
        if ((u32)func_80025D44() < 2U && *timer >= 0x3D) {
            selection = func_80054668(*((u8 *)D_8AB11D0C + 2) - 1);
            *timer = 0x78;
            if (selection < *(s16 *)((u8 *)&D_8AB12CB2 +
                                     D_8AB13F2C * 0x94)) {
                result = func_8AB0D20C(0);
            } else {
                result = func_8AB0CD00(0);
            }
        }
        break;
    }
    return result;
}
/* mkdraft:func_8AB0D08C end */

/* mkdraft:func_8AB0D20C begin */
extern u8 D_8AB12CB3[];
extern s16 D_8AB13F2C;
extern s16 D_8AB16F9E;
extern s32 func_800546E0(s32, u8);
extern s32 func_80051D64(s32, s32);
extern s32 func_80054E48(s32);
extern s32 func_8AB007E0(void);
extern s32 func_8AB00618(void);
extern s32 func_8AB0CD00(s32);



s32 func_8AB0D20C(s32 arg0) {
    s32 result;
    s16 timer_value;
    s32 selection;
    s16 *timer = &D_8AB16F9E;

    result = 0x3C;
    switch (arg0) {
    case 0:
        selection = D_8AB11D0C[2] - 1;
        (*timer) = 0, func_800546E0(selection, D_8AB12CB3[D_8AB13F2C * 0x94]);
        func_80051D64(0x13, 0);
        func_80054E48(3);
        func_8004C8A0(D_8AB126A8, 0x100, 0x39, 7);
        *(u16 *)((u8 *)D_8AB11D00 + 2) = *(u16 *)((u8 *)D_8AB11D00 + 2) | 1;
        func_8AB007E0();
        func_80021ED8(0x39);
        func_80027774(0xCA0F, 0x24);
        break;
    case 1:
        timer_value = (*timer) + 1;
        (*timer) = timer_value;
        if (timer_value >= 0x97) {
            result = func_8AB0CD00(0);
        }
        func_8AB00618();
        break;
    }
    return result;
}
/* mkdraft:func_8AB0D20C end */
#endif
