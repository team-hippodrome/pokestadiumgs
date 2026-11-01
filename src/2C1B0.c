// include/229E0.h declares these four audio register wrappers with s32 formals
// (a spelling that exists so the `s32 *p = &arg0;` masks in src/340C0.c compile).
// The retail wrappers take u8: func_800333CC's switch passes a u8 local and the
// targets mask with `andi a0,a1,0xFF` only under a u8 formal. Renaming the four
// identifiers during the include keeps the header's s32 declarations out of
// this TU; nothing else in this file calls them.
#define func_8003364C func_8003364C_s32decl
#define func_800337D8 func_800337D8_s32decl
#define func_80033864 func_80033864_s32decl
#define func_8003386C func_8003386C_s32decl
#include "229E0.h"
#undef func_8003364C
#undef func_800337D8
#undef func_80033864
#undef func_8003386C

#ifdef VERSION_US

s32 gAudioCommandQueue[10];
AudioQueuedState gAudioQueuedState;

typedef struct {
    u32 words[21];
} BattleMetadata84;
extern BattleMetadata84 D_800D1B98[];
extern u8 D_80091A38, D_80091AEC, D_80091AD0, D_80091A44, D_80091A84, D_80091A88, D_80091AF4;
extern u8 D_800D2680[2][12], D_800D1B38[], D_800D2648[], D_800D1B3A;
extern u8 D_800D2698[], D_800D269A[], D_800D269C[];
extern u8 D_800D1B5E[], D_800D1B60[], D_800D1B62[], D_800D1B66[], D_800D1B68[], D_800D1B6A[];
extern u8 D_800D1B6C[], D_800D1B6E[], D_800D1ACC[], D_800D1ACE[], D_800D1AD0[];
extern u8 D_800D26A0[], D_800D26A2[], D_800D26A4[], D_800D26A6[], D_800D26A8[], D_800D26AA[];
extern u32 D_800D2638;
extern u8 *D_800D2608[];
extern u8 D_80091F08[], D_80091F18[], D_80091F20[], D_80091F28[], D_80091F30[], D_80091F38[], D_80091F40[];
extern u8 D_80091F48[], D_80091F50[], D_80091F58[], D_80091F6C[];
// This file defines the BSS run 0x800D1A90..0x800D2630. func_8002C2E0 shares one `lui`
// between constant-index accesses to D_800D1B64 ([0] and [1]), D_800D2610 ([0] and [1])
// and D_800D2620 ([0][0], [0][1] and [1][0]); IDO emits that only for symbols defined in
// the same file. The other arrays below cover the bytes between them, so the individual
// sizes and types of those variables are not established; labels inside the spans are
// aliases in linker_scripts/us/aliases.ld. IDO places a BSS array of 8 bytes or more on
// an 8-byte boundary, which leaves 0x800D1B3C..0x800D1B3F unused and is why 0x800D1B66
// is a separate 2-byte array.
//@linker_scripts/us/aliases.ld
u8 D_800D1B40[36];
u8 D_800D1B64[2];
u8 D_800D1B66[2];
u8 D_800D1B68[2728];
s32 D_800D2610[2];
s32 D_800D2618[2];
u8 D_800D2620[2][7];
u8 D_800D262E[2];
u32 func_800194A0(void);

void func_8002B5B0(u8 arg0, u32 arg1) {
    u8 first_visit;
    u8 roster_kind;
    u8 active_index;
    u8 roster_changed;
    s32 i;

    first_visit = 0;
    roster_changed = 0;
    if (arg0 < 2) {
        if (arg1 == 300 || arg1 == 279) {
            arg1 = 25;
        }
        if (arg1 >= 254 && arg1 < 279) {
            arg1 = 201;
        }
        D_800D2640[arg0] = 0;
        if (D_800D2680[arg0][D_800D1B78[arg0][10]] == 0) {
            first_visit = 1;
            D_800D2680[arg0][D_800D1B78[arg0][10]] = 1;
        }
        active_index = D_800D1B78[arg0][10];
        D_800D1B38[arg0] = active_index;
        D_800D1B88[arg0] = (unk_D_800D1B88 *)(D_800D1B78[arg0] + active_index * 88 + 24);
        D_800D1B98[arg0] = *(BattleMetadata84 *)(D_800D1B78[arg0] + 1080);
        if (D_800D1B78[arg0][10] < D_800D1B78[arg0][3]) {
            roster_kind = 0;
        } else {
            roster_kind = 1;
        }
        if (roster_kind != D_800D2648[arg0] && D_800D2638 != 0) {
            roster_changed = 1;
        }
        D_800D2648[arg0] = roster_kind;
        for (i = 0; i < 7; i++) {
            D_800D2620[arg0][i] = D_800D1B80[arg0][i + 30];
        }
        if (D_800D2638 != 0) {
            D_800D2618[arg0] = D_800D1B88[arg0]->unk26;
            D_800D2610[arg0] = D_800D1B88[arg0]->unk26;
            D_80091A38 = 0;
            D_800D1B66[arg0] = 0;
            D_800D1B68[arg0] = 0;
            arg1--;
            if (first_visit != 0) {
                D_800D1B3A = 1;
                func_800314D4(arg1 + 12608);
                if ((f32)(u32)D_800D1B88[arg0]->unk00[29] <= (f32)(u32)D_800D1B88[arg0 ^ 1]->unk00[29] * 1.2f) {
                    D_800D2698[arg0] = 0;
                }
            } else {
                if (D_80091AEC != 0) {
                    func_80028CA8(D_80091F18);
                } else {
                    if ((D_800D1B88[arg0]->unk00[36] & 0x20) || (D_800D1B88[arg0]->unk00[36] & 7)) {
                        func_80028CA8(D_80091F6C);
                    } else {
                        func_80028CA8(D_80091F58);
                    }
                }
            }
            if (roster_changed != 0) {
                func_80031530(5);
                func_80028CA8(D_80091F08);
            }
            func_80031530(5);
            if (D_800D2608[arg0][9] == 1 && (u8)D_80091A18 == 0) {
                func_80028CA8(D_80091F20);
            } else {
                if (D_800D1B88[arg0]->unk00[36] & 0x20) {
                    func_80028CA8(D_80091F28);
                } else if (D_800D1B88[arg0]->unk00[36] & 7) {
                    func_80028CA8(D_80091F30);
                    D_800D1B66[arg0] = 1;
                } else if (D_800D1B88[arg0]->unk00[36] & 8) {
                    func_800314D4(8368);
                } else if (D_800D1B88[arg0]->unk00[36] & 0x10) {
                    func_800314D4(8369);
                } else {
                    if ((f32)(u32)D_800D1B88[arg0]->unk26 <
                        ((f32)(u32)*(u16 *)((u8 *)D_800D1B88[arg0] + 40)) * 0.2f) {
                        func_80028CA8(D_80091F38);
                    } else if (!(D_800D1B88[arg0]->unk00[36] & 0x7F)) {
                        if (D_800D1B6C[arg0] != 0 && D_800D1B6C[arg0 ^ 1] == 0 && D_80091A44 == 0) {
                            func_800314D4(8687);
                        } else {
                            if (D_800D1B3A != 0 &&
                                (f32)(u32)D_800D1B88[arg0 ^ 1]->unk00[29] * 1.2f <
                                (f32)(u32)D_800D1B88[arg0]->unk00[29]) {
                                if (D_800D2698[arg0] == 0) {
                                    func_800314D4(8374);
                                    D_800D2698[arg0] = 1;
                                } else {
                                    func_80028CA8(D_80091F48);
                                }
                            } else {
                                if (D_80091AEC != 0) {
                                    if (!(func_800194A0() & 1)) {
                                        func_800314D4(8388);
                                    }
                                } else {
                                    if (D_800D269A[arg0] != 0) {
                                        func_80028CA8(D_80091F50);
                                    } else {
                                        if (D_800D1B78[arg0][9] + 2 == D_800D1B78[arg0 ^ 1][9] &&
                                            D_800D1B3A != 0 &&
                                            D_800D269C[arg0] == 0 &&
                                            (u8)D_80091A18 == 0 &&
                                            D_800D1B78[arg0][8] == D_800D1B78[arg0 ^ 1][8]) {
                                            func_800314D4(8377);
                                            D_800D269C[arg0] = 1;
                                        } else {
                                            if ((f32)(u32)D_800D1B88[arg0 ^ 1]->unk26 <
                                                ((f32)(u32)*(u16 *)((u8 *)D_800D1B88[arg0] + 40)) * 0.1f &&
                                                D_800D1B88[arg0 ^ 1]->unk26 > 0) {
                                                func_80028CA8(D_80091F40);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            D_800D269A[arg0] = 0;
            D_800D1B5E[arg0] = 0;
            D_800D1B60[arg0] = 0;
            D_800D1B62[arg0] = 0;
            D_800D1B64[arg0] = 0;
            D_800D1ACE[arg0] = 0;
            D_800D1AD0[arg0] = 0;
            D_800D26A0[arg0] = 0;
            D_800D26A2[arg0] = 0;
            D_800D26A4[arg0] = 0;
            D_800D26A6[arg0] = 0;
            D_800D26A8[arg0] = 0;
            D_800D26AA[arg0] = 0;
            D_800D1B6A[arg0] = 0;
            if (D_80091A44 == 0) {
                D_800D1B6C[arg0] = 0;
            }
            D_800D1B6E[arg0] = 0;
            D_800D1ACC[arg0] = 0;
            D_800D262E[arg0] = D_800D1B88[arg0]->unk00[1];
            D_80091AEC = 0;
            D_80091AD0 = 0;
            D_80091A44 = 0;
            D_80091A84 = 0;
            D_80091A88 = 0;
            D_80091AF4 = 0;
        }
    }
}

extern u8 D_80091AD0, D_80091AD4, D_80091AD8, D_80091ADC, D_80091AE0, D_80091AE8;
extern u8 D_800D1ACC[], D_800D1B6A[], D_800D1B6C[], D_800D269A[];
extern s32 D_800D2618[];
extern u32 D_800D2638;
extern u8 D_80091EA8[], D_80091EB8[], D_80091EC4[], D_80091ECC[], D_80091ED4[], D_80091EDC[], D_80091EE4[];
s32 Party_CountLivingGroupMembers(u8 *);
void func_8002BE44(u8 arg0) {
    D_800D1B3B = 1;
    D_800D1B6C[arg0] = 0;
    if (D_80091AD4 != 0) {
        if (D_80091AD0 == 0) {
            func_80028CA8(D_80091EA8);
        } else {
            func_800314D4(8414);
        }
    } else if (D_80091AD0 != 0) {
        if (D_80091AD8 != 0) {
            func_800314D4(8412);
        } else {
            func_80028CA8(D_80091EDC);
        }
    } else if (D_80091ADC != 0) {
        func_800314D4(8411);
    } else if (D_800D2638 < 2U &&
            arg0 + 1 != D_80091AE8 &&
            D_800D1B78[arg0][1] != 174 &&
            D_800D1B80[arg0][1] != 8 &&
            D_800D1B80[arg0][2] != 8) {
        func_80028CA8(D_80091ECC);
    } else {
        if ((u8)D_80091A18 == 0 &&
            D_800D1B78[arg0][9] == 0 &&
            D_800D1B78[arg0][8] >= 2 &&
            D_800D1B78[arg0 ^ 1][9] != 0 &&
            D_800D1ACC[arg0] == 0 &&
            D_80091AE8 == 0) {
            func_80031530(70);
            func_80028CA8(D_80091EE4);
        } else if ((u8)D_80091A18 != 0 &&
            Party_CountLivingGroupMembers(D_800D1B78[arg0]) == 0 &&
            Party_CountLivingGroupMembers(D_800D1B78[arg0 ^ 1]) > 0 &&
            D_800D1ACC[arg0] == 0 &&
            D_80091AE8 == 0) {
            func_80031530(70);
            func_800314D4(8417);
        } else {
            if (D_800D2618[arg0] >= (s32)*(u16 *)((u8 *)D_800D1B88[arg0] + 40)) {
                if (D_80091AE8 == 0 &&
                    D_800D1B6A[arg0] == 0 &&
                    D_800D1B78[arg0][1] != 174 &&
                    D_800D1B80[arg0][1] != 8 &&
                    D_800D1B80[arg0][2] != 8) {
                    D_800D269A[arg0] = 1;
                    if ((f32)(u32)D_800D1B88[arg0]->unk00[29] * 1.2f < (f32)(u32)D_800D1B88[arg0 ^ 1]->unk00[29]) {
                        func_80028CA8(D_80091EC4);
                    } else {
                        func_80028CA8(D_80091EB8);
                    }
                } else {
                    func_80028CA8(D_80091EA8);
                }
            } else if ((u32)D_800D2640[arg0] >= 13U) {
                if (D_80091AE8 == 0) {
                    if (D_80091AE0 != 0) {
                        func_800314D4(8408);
                    } else {
                        func_80028CA8(D_80091ED4);
                    }
                } else {
                    func_80028CA8(D_80091EA8);
                }
            } else {
                func_80028CA8(D_80091EA8);
            }
        }
    }
    D_80091AD0++;
}

void func_8002C2A0(unsigned short arg0)
{
  gAudioQueuedState.event_queue[D_80091A2C] = arg0;
  D_80091A2C = D_80091A2C + 1;
  if (((u32) D_80091A2C) >= 10U)
  {
    D_80091A2C = D_80091A2C - 1;
  }
}

extern u8 D_80091A48, D_80091A4C, D_80091A50, D_80091A54, D_80091A58, D_80091A5C, D_80091A60;
extern u8 D_80091A64, D_80091A68, D_80091A6C, D_80091A80, D_80091A8C, D_80091A90, D_80091A94;
extern u8 D_80091A98, D_80091A9C, D_80091AA0, D_80091AA4, D_80091AAC, D_80091ACC, D_80091AE4;
extern u8 D_80091AF0, D_80091AF8, D_80091AFC, D_80091B00, D_80091B04, D_800D1AD2;
extern s32 D_800D1AD4;
extern u8 *D_800D1C40[];
// Commentary candidate lists passed to func_80028CA8.
extern u8 D_80091D68[], D_80091D78[], D_80091D80[], D_80091D88[], D_80091D98[], D_80091DA8[];
extern u8 D_80091DC4[], D_80091DD0[], D_80091DDC[], D_80091DE4[], D_80091DF4[], D_80091DFC[];
extern u8 D_80091E04[], D_80091E0C[], D_80091E18[], D_80091E20[], D_80091E28[], D_80091E30[];
extern u8 D_80091E38[], D_80091E40[], D_80091E48[], D_80091E50[], D_80091E58[], D_80091E60[];
extern u8 D_80091E68[], D_80091E70[], D_80091E78[], D_80091E80[], D_80091E88[], D_80091E90[];
extern u8 D_80091E98[], D_80091F64[], D_80091F78[], D_80091F80[], D_80091F88[], D_80091F90[];
extern u8 D_80091F98[], D_80091FA0[], D_80091FA8[], D_80091FB0[], D_80091FB8[], D_80091FC0[];
extern u8 D_80091FC8[], D_80091FD0[], D_80091FD8[], D_80091FE0[], D_80091FE8[], D_80091FF0[];
extern u8 D_80091FF8[], D_80092000[], D_80092008[], D_80092010[], D_80092018[], D_80092020[];
extern u8 D_80092028[], D_80092030[], D_80092038[], D_80092040[], D_80092048[], D_80092050[];
extern u8 D_80092058[], D_80092060[], D_80092068[], D_80092070[], D_80092078[], D_80092080[];
extern u8 D_80092088[], D_80092090[], D_80092098[], D_800920A0[], D_800920A8[], D_800920B0[];
extern u8 D_800920B8[], D_800920C0[], D_800920C8[], D_800920D0[], D_800920D8[], D_800920E0[];
extern u8 D_800920E8[], D_800920F0[], D_800920F8[], D_80092100[];
void func_80031564(void);

void func_8002C2E0(u8 arg0) {
    u32 i;
    u32 j;
    u8 raised_count;
    u8 lowered_count;
    u8 seen_event_41;
    u8 seen_event_37;
    u8 seen_event_68;
    u8 unused_62;
    u8 followup_kind;
    u8 check_stat_drops;
    s32 percent;

    seen_event_41 = 0;
    seen_event_37 = 0;
    seen_event_68 = 0;
    followup_kind = 0;
    check_stat_drops = 0;
    if (arg0 >= 2) {
        D_80091A2C = 0;
        return;
    }
    for (i = 0; i < D_80091A2C; i++) {
        switch (gAudioQueuedState.event_queue[i]) {
        case 30:
            func_800314D4(8649);
            func_80023A3C(2, 0, 0);
            break;
        case 31:
            D_800D2610[arg0] = (D_800D1B88[arg0])->unk26;
            func_80028CA8(D_80091F78);
            break;
        case 32:
            if (D_800D26A6[arg0] == 0) {
                func_80028CA8(D_80091E80);
            } else {
                func_80028CA8(D_80091E88);
            }
            D_800D26A6[arg0] = 2;
            break;
        case 33:
            func_800314D4(8671);
            D_80091AF8 = 1;
            break;
        case 34:
            if ((D_80091A90 == 0) && (D_80091A94 == 0) && !(func_800194A0() & 1)) {
                func_80028CA8(D_80091F88);
            }
            D_80091A94 = 1;
            break;
        case 35:
            func_80028CA8(D_80091F80);
            func_80023A3C(2, 0, 0);
            D_80091A90 = 1;
            break;
        case 36:
            if (D_800D1B5E[arg0] == 0) {
                func_800314D4(8636);
                D_800D1B5E[arg0] = 3;
            } else {
                func_80028CA8(D_80092020);
                D_800D1B5E[arg0] = 3;
            }
            D_80091A4C = 1;
            func_80023A3C(2, 0, 0);
            break;
        case 37:
            seen_event_37 = 1;
            continue;
        case 38:
            D_80091AF0 = 1;
            D_800D2610[arg0] = D_800D1B88[arg0]->unk26;
            continue;
        case 40:
            if (D_80091A50 == 0) {
                switch (D_800D1C40[arg0][23]) {
                case 1:
                    func_800314D4(8685);
                    D_80091A50 = 1;
                    break;
                case 0:
                    if (D_80091A50 != 2) {
                        func_800314D4(8686);
                    }
                    D_80091A50 = 2;
                    D_80091AD4 = 1;
                    break;
                }
            }
            if (D_800D1B80[arg0][23] == 0) {
                func_80023A3C(2, 0, 0);
            }
            break;
        case 41:
            seen_event_41 = 1;
            continue;
        case 42:
            func_800314D4(8608);
            break;
        case 44:
            D_800D2610[arg0] = D_800D1B88[arg0]->unk26;
            if ((f32) D_800D1B88[arg0]->unk26 < ((f32) D_800D1B88[arg0]->unk28 * 0.2f)) {
                func_80028CA8(D_80092018);
            }
            break;
        case 45:
            func_800314D4(8661);
            D_800D262E[0] = D_800D1B88[0]->unk00[1];
            D_800D262E[1] = D_800D1B88[1]->unk00[1];
            func_80023A3C(2, 0, 0);
            break;
        case 46:
            func_800314D4(8735);
            break;
        case 47:
            func_800314D4(8736);
            break;
        case 49:
            func_800314D4(8653);
            break;
        case 50:
            func_800314D4(8652);
            break;
        case 51:
            func_80028CA8(D_80091F90);
            func_80023A3C(2, 0, 0);
            break;
        case 53:
            func_80028CA8(D_80092028);
            D_80091A48 = 1;
            break;
        case 54:
            func_800314D4(8643);
            D_80091A48 = 1;
            break;
        case 55:
            func_800314D4(8640);
            break;
        case 56:
            D_80091AF0 = 1;
            D_800D2610[arg0] = (D_800D1B88[arg0])->unk26;
            func_80031564();
            break;
        case 57:
            func_800314D4(8666);
            func_80023A3C(2, 0, 0);
            break;
        case 58:
            func_800314D4(8674);
            D_80091AF8 = 3;
            break;
        case 59:
            if ((D_80091A90 == 0) && (D_80091A98 == 0) && !(func_800194A0() & 1)) {
                func_80028CA8(D_800920A0);
            }
            D_80091A98 = 1;
            break;
        case 60:
            func_800314D4(8683);
            break;
        case 61:
            func_800314D4(8631);
            func_80023A3C(2, 0, 0);
            break;
        case 62:
            func_80028CA8(D_80091DF4);
            func_80023A3C(2, 0, 0);
            break;
        case 63:
            func_800314D4(8684);
            func_80023A3C(2, 0, 0);
            D_800D1B6C[0] = 1;
            D_800D1B6C[1] = 1;
            break;
        case 64:
            if (D_800D1ACE[arg0] == 0) {
                func_800314D4(8732);
                D_800D1ACE[arg0] = 1;
            }
            D_800D1B6A[arg0] = 1;
            D_800D2610[arg0] = D_800D1B88[arg0]->unk26;
            break;
        case 65:
            D_80091AA4 = 1;
            followup_kind = 5;
            break;
        case 66:
            if (D_80091ACC != 0) {
                func_80028CA8(D_80092098);
            } else if ((D_800D1B78[0][9] < 2) && (D_800D1B78[1][9] < 2) && (((f32) D_800D1B88[0]->unk26 / (f32) D_800D1B88[0]->unk28) < 0.1f) && (((f32) D_800D1B88[1]->unk26 / (f32) D_800D1B88[1]->unk28) < 0.1f)) {
                func_800314D4(8622);
            } else if (D_800D26A2[arg0] == 0) {
                func_80028CA8(D_80091FE0);
            } else {
                func_80028CA8(D_80091FE8);
            }
            D_800D26A2[arg0] = 1;
            D_80091ACC = 1;
            break;
        case 67:
            func_800314D4(8639);
            break;
        case 68:
            seen_event_68 = 1;
            continue;
        case 70:
            func_800314D4(8654);
            func_80023A3C(2, 0, 0);
            D_800D2610[0] = D_800D1B88[0]->unk26;
            D_800D2610[1] = D_800D1B88[1]->unk26;
            break;
        case 71:
            func_800314D4(8737);
            break;
        case 72:
            switch (D_800D262E[arg0]) {
            case 74:
                func_80028CA8(D_80092030);
                break;
            case 78:
                func_80028CA8(D_80092038);
                break;
            case 79:
                func_80028CA8(D_80092040);
                D_80091AA4 = 0;
                break;
            case 80:
                func_80028CA8(D_80092048);
                break;
            case 83:
                func_80028CA8(D_80092050);
                break;
            case 84:
                func_80028CA8(D_80092058);
                D_80091AA0 = 0;
                break;
            case 109:
                func_80028CA8(D_80092060);
                D_80091AA0 = 0;
                D_80091AA4 = 0;
                break;
            case 139:
                func_80028CA8(D_80092068);
                D_800D1B6A[arg0] = 1;
                D_800D2610[arg0] = D_800D1B88[arg0]->unk26;
                break;
            case 173:
                func_80028CA8(D_80092070);
                D_800D1B6A[arg0] = 1;
                D_800D2610[arg0] = D_800D1B88[arg0]->unk26;
                break;
            case 174:
                func_80028CA8(D_80092078);
                D_800D1B6A[arg0] = 1;
                D_800D2610[arg0] = D_800D1B88[arg0]->unk26;
                break;
            case 150:
                func_80028CA8(D_80092080);
                break;
            default:
                func_800314D4(8689);
                break;
            }
            break;
        case 73:
            func_800314D4(8682);
            break;
        case 74:
            if (D_80091A88 == 0) {
                func_800314D4(8591);
                D_80091A88 = 1;
            }
            break;
        case 75:
            func_800314D4(8589);
            break;
        case 76:
            func_800314D4(8590);
            break;
        case 77:
            func_800314D4(8571);
            D_800D26A2[arg0] = 0;
            D_80091AA4 = 0;
            func_80023A3C(2, 0, 0);
            continue;
        case 78:
        case 79:
            func_800314D4(8573);
            D_800D1B66[arg0] = 1;
            D_800D1B6A[arg0] = 1;
            D_800D2610[arg0] = D_800D1B88[arg0]->unk26;
            break;
        case 80:
            if (D_80091A80 != 0) {
                func_800314D4(8720);
            } else {
                func_800314D4(8572);
            }
            D_800D1B6A[arg0] = 1;
            D_800D2610[arg0] = D_800D1B88[arg0]->unk26;
            break;
        case 81:
            func_800314D4(8640);
            break;
        case 82:
            func_800314D4(8607);
            break;
        case 83:
            D_80091A8C = 1;
            continue;
        case 84:
            if (D_80091ACC != 0) {
                func_80028CA8(D_80092098);
            } else if ((D_800D1B78[0][9] < 2) && (D_800D1B78[1][9] < 2) && (((f32) D_800D1B88[0]->unk26 / (f32) D_800D1B88[0]->unk28) < 0.1f) && (((f32) D_800D1B88[1]->unk26 / (f32) D_800D1B88[1]->unk28) < 0.1f)) {
                func_800314D4(8622);
            } else if (D_800D26A4[arg0] == 0) {
                func_800314D4(8617);
            } else {
                func_80028CA8(D_80091FC8);
            }
            D_800D26A4[arg0] = 1;
            D_80091ACC = 1;
            continue;
        case 85:
        case 86:
            if (D_800D26A8[arg0] == 0) {
                if (D_800D1AD2 == 15) {
                    func_80028CA8(D_80091E40);
                } else {
                    func_80028CA8(D_80091E30);
                }
            } else {
                if (D_800D1AD2 == 15) {
                    func_80028CA8(D_80091E48);
                } else {
                    func_80028CA8(D_80091E38);
                }
                D_800D26AA[arg0] = 1;
            }
            D_800D26A8[arg0] = 2;
            break;
        case 87:
            if (D_800D26A8[arg0] == 0) {
                // FAKE: 15U on the three compares below lets IDO hold 15 in a register for this case; diff score 115 without it.
                if (D_800D1AD2 == 15U) {
                    func_80028CA8(D_80091E40);
                    D_800D26A8[arg0] = 2;
                } else if (D_800D1B78[arg0 ^ 1][1] == 73) {
                    // FAKE: the multiply by 0 keeps 15 in $a1 for the D_800D1AD2 compares in this case; diff score 71 without it.
                    if (D_800D26A8[arg0] == (D_800D1B62[arg0] * 0)) {
                        if (D_800D1AD2 == 15U) {
                            func_80028CA8(D_80091E40);
                        } else {
                            func_80028CA8(D_80091E30);
                        }
                    } else {
                        if (D_800D1AD2 == 15U) {
                            func_80028CA8(D_80091E48);
                        } else {
                            func_80028CA8(D_80091E38);
                        }
                        D_800D26AA[arg0] = 1;
                    }
                    D_800D26A8[arg0] = 2;
                } else {
                    func_80028CA8(D_80091E70);
                    D_800D26A8[arg0] = 2;
                }
            } else {
                if (D_800D1AD2 == 15) {
                    func_80028CA8(D_80091E48);
                } else {
                    func_80028CA8(D_80091E38);
                }
                D_800D26AA[arg0] = 1;
                D_800D26A8[arg0] = 2;
            }
            break;
        case 88:
            func_800314D4(8644);
            break;
        case 89:
            func_800314D4(8692);
            break;
        case 90:
            if (D_80091ACC != 0) {
                func_80028CA8(D_80092098);
            } else if ((D_800D1B78[0][9] < 2) && (D_800D1B78[1][9] < 2) && (((f32) D_800D1B88[0]->unk26 / (f32) D_800D1B88[0]->unk28) < 0.1f) && (((f32) D_800D1B88[1]->unk26 / (f32) D_800D1B88[1]->unk28) < 0.1f)) {
                func_800314D4(8622);
            } else if (D_800D26A4[arg0] == 0) {
                func_800314D4(8655);
            } else {
                func_80028CA8(D_80091FC8);
            }
            D_800D26A4[arg0] = 1;
            D_80091ACC = 1;
            break;
        case 92:
            if (D_800D26A0[arg0] == 0) {
                func_80028CA8(D_80091FA8);
                D_800D26A0[arg0] = 1;
            } else {
                func_80028CA8(D_80091FB0);
            }
            D_80091AF0 = 1;
            D_80091ADC = 1;
            D_800D2610[arg0] = (D_800D1B88[arg0])->unk26;
            func_80023A3C(2, 0, 0);
            break;
        case 93:
            func_800314D4(8629);
            D_800D26A0[arg0] = 0;
            continue;
        case 94:
            followup_kind = 1;
            continue;
        case 95:
            if (D_800D262E[arg0] == 83) {
                func_80028CA8(D_80092050);
            } else if (D_800D262E[arg0] == 109) {
                func_80028CA8(D_80092060);
            } else {
                func_800314D4(8689);
            }
            break;
        case 96:
            if (D_800D26A8[arg0] == 0) {
                func_80028CA8(D_80091E18);
            } else {
                func_80028CA8(D_80091E78);
                D_800D26AA[arg0] = 1;
            }
            D_800D26A8[arg0] = 2;
            break;
        case 97:
            func_80028CA8(D_800920B8);
            break;
        case 98:
            func_80028CA8(D_800920C0);
            break;
        case 99:
            if (D_800D26A6[arg0] == 0) {
                func_80028CA8(D_80091E80);
            } else {
                func_80028CA8(D_80091E88);
            }
            D_800D26A6[arg0] = 2;
            break;
        case 100:
            if (D_800D26A8[arg0] == 0) {
                func_80028CA8(D_80091E18);
            } else {
                func_80028CA8(D_80091E78);
                D_800D26AA[arg0] = 1;
            }
            D_800D26A8[arg0] = 2;
            break;
        case 102:
            if ((D_800D1B80[arg0 ^ 1][1] == 8) || (D_800D1B80[arg0 ^ 1][2] == 8)) {
                func_80028CA8(D_80091E58);
            } else {
                func_80028CA8(D_80091E50);
            }
            break;
        case 104:
            func_800314D4(8648);
            func_80023A3C(2, 0, 0);
            D_800D1B64[1] = D_800D1B64[0] = 0;
            for (j = 0; j < 7; j++) {
                D_800D2620[0][j] = D_800D1B80[0][j + 30];
                D_800D2620[1][j] = D_800D1B80[1][j + 30];
            }
            break;
        case 105:
            if (D_800D1B60[arg0] == 0) {
                func_800314D4(8633);
                D_800D1B60[arg0] = 3;
            } else {
                func_80028CA8(D_80092088);
                D_800D1B60[arg0] = 3;
            }
            D_80091A4C = 1;
            func_80023A3C(2, 0, 0);
            break;
        case 106:
            func_80028CA8(D_80091FB8);
            break;
        case 108:
            followup_kind = 6;
            continue;
        case 109:
            if (D_80091ACC != 0) {
                func_80028CA8(D_80092098);
            } else if ((D_800D1B78[0][9] < 2) && (D_800D1B78[1][9] < 2) && (((f32) D_800D1B88[0]->unk26 / (f32) D_800D1B88[0]->unk28) < 0.1f) && (((f32) D_800D1B88[1]->unk26 / (f32) D_800D1B88[1]->unk28) < 0.1f)) {
                func_800314D4(8622);
            } else if (D_800D26A4[arg0] == 0) {
                func_80028CA8(D_80091FC0);
            } else {
                func_80028CA8(D_80091FC8);
            }
            D_800D26A4[arg0] = 1;
            D_80091ACC = 1;
            break;
        case 110:
            if (D_800D26A8[arg0] == 0) {
                func_80028CA8(D_80091E18);
            } else {
                func_80028CA8(D_80091E78);
                D_800D26AA[arg0] = 1;
            }
            D_800D26A8[arg0] = 2;
            break;
        case 112:
            func_800314D4(8699);
            break;
        case 113:
            func_80028CA8(D_80091F64);
            func_80023A3C(2, 0, 0);
            break;
        case 114:
            D_80091A8C = 1;
            continue;
        case 115:
            if (D_800D1AD0[arg0] == 0) {
                func_800314D4(8691);
                D_800D1AD0[arg0] = 1;
            } else {
                if (D_800D26A8[arg0] == 0) {
                    func_80028CA8(D_80091E18);
                } else {
                    func_80028CA8(D_80091E78);
                    D_800D26AA[arg0] = 1;
                }
                D_800D26A8[arg0] = 2;
            }
            break;
        case 116:
            func_800314D4(8700);
            break;
        case 117:
            func_80028CA8(D_80091E68);
            break;
        case 118:
            if (D_800D26A6[arg0] == 0) {
                func_80028CA8(D_80091E80);
            } else {
                func_80028CA8(D_80091E88);
            }
            D_800D26A6[arg0] = 2;
            break;
        case 119:
            func_800314D4(8571);
            D_800D26A2[arg0] = 0;
            D_80091AA4 = 0;
            func_80023A3C(2, 0, 0);
            break;
        case 121:
            func_80028CA8(D_80091FF0);
            break;
        case 122:
            func_800314D4(8701);
            break;
        case 123:
            D_800D1B6E[arg0] = 0;
            func_80028CA8(D_80091FF8);
            break;
        case 124:
            D_800D1B6E[arg0] = 1;
            func_800314D4(8632);
            func_80023A3C(2, 0, 0);
            break;
        case 125:
            if (1) {} // karodo
            seen_event_41 = 0;
            seen_event_37 = 0;
            seen_event_68 = 0;
            func_80031564();
            func_80031530(25);
            func_80028CA8(D_80091E28);
            break;
        case 126:
            if (D_800D26A6[arg0] == 0) {
                func_80028CA8(D_80091E80);
            } else {
                func_80028CA8(D_80091E88);
            }
            D_800D26A6[arg0] = 2;
            break;
        case 127:
            if (D_800D26A6[arg0] == 0) {
                func_80028CA8(D_80091E80);
            } else {
                func_80028CA8(D_80091E88);
            }
            D_800D26A6[arg0] = 2;
            break;
        case 128:
            func_800314D4(8704);
            break;
        case 129:
            if (D_80091AAC == 248) {
                func_800314D4(8705);
                func_80023A3C(2, 0, 0);
                D_80091AAC = 0;
            break;
            }
            continue;
        case 130:
            func_800314D4(8706);
            break;
        case 131:
            func_800314D4(8707);
            func_80023A3C(2, 0, 0);
            D_80091AD8 = 1;
            break;
        case 132:
            func_800314D4(8708);
            break;
        case 133:
            func_800314D4(8645);
            break;
        case 134:
            func_800314D4(8709);
            break;
        case 135:
            if ((D_80091AFC == arg0) && (D_800D1B78[arg0][1] == 150)) {
                func_80028CA8(D_80092000);
            } else {
                if (D_800D26A6[arg0] == 0) {
                    func_80028CA8(D_80091E80);
                } else {
                    func_80028CA8(D_80091E88);
                }
                D_800D26A6[arg0] = 2;
            }
            break;
        case 137:
            func_80028CA8(D_80092010);
            func_80023A3C(2, 0, 0);
            break;
        case 138:
            func_800314D4(8672);
            func_80023A3C(2, 0, 0);
            D_80091A90 = 1;
            break;
        case 139:
            func_80028CA8(D_80092008);
            D_800D2610[arg0] = D_800D1B88[arg0]->unk26;
            break;
        case 140:
            if (D_800D26A6[arg0] == 0) {
                func_80028CA8(D_80091E80);
            } else {
                func_80028CA8(D_80091E88);
            }
            D_800D26A6[arg0] = 2;
            break;
        case 141:
        case 142:
            if ((D_800D1B78[arg0][1] == 174) && (D_80091B00 == arg0)) {
                if (D_800D1B62[arg0] == 0) {
                    func_800314D4(8665);
                } else {
                    func_80028CA8(D_80092090);
                }
                for (j = 0; j < 7; j++) {
                    D_800D2620[arg0][j] = D_800D1B80[arg0][j + 30];
                }
                D_80091AF4 = 1;
                D_800D1B62[arg0] = 3;
                break;
            }
            check_stat_drops = 1;
            continue;
        case 143:
        case 144:
            if ((D_800D1B78[arg0 ^ 1][1] == 207) && (D_80091AFC != arg0) && (D_800D1B6E[arg0] == 0)) {
                if (gAudioQueuedState.event_queue[i + 1] == 94) {
                    func_800314D4(8738);
                } else {
                    func_800314D4(8582);
                }
                for (j = 0; j < 7; j++) {
                    D_800D2620[arg0][j] = D_800D1B80[arg0][j + 30];
                }
            } else if ((D_800D1B62[arg0 ^ 1] >= 3) && (D_800D1B62[arg0] == 0)) {
                func_800314D4(8594);
                D_800D1B62[arg0] = 3;
            } else if (D_800D1B62[arg0] >= 4) {
                if (D_800D1B62[arg0] == 4) {
                    func_800314D4(8595);
                } else if (D_800D1B62[arg0] == 8) {
                    func_800314D4(8660);
                }
                D_800D1B62[arg0]++;
            } else if (D_800D1B62[arg0] == 1) {
                func_80028CA8(D_80092090);
                D_800D1B62[arg0] = 3;
            } else {
                if (D_800D1B62[arg0] < 3) {
                    D_800D1B62[arg0] = 3;
                } else {
                    D_800D1B62[arg0]++;
                }
                if ((D_800D1B78[arg0][1] == 174) && (D_80091B00 == arg0)) {
                    func_800314D4(8596);
                    break;
                }
                raised_count = 0;
                for (j = 0; j < 7; j++) {
                    if (D_800D2620[arg0][j] < D_800D1B80[arg0][j + 30]) {
                        raised_count++;
                    }
                }
                if (raised_count >= 2) {
                    if (raised_count == 7) {
                        func_800314D4(8660);
                    } else {
                        func_800314D4(8596);
                    }
                } else {
                    for (j = 0; j < 7; j++) {
                        if (D_800D2620[arg0][j] < D_800D1B80[arg0][j + 30]) {
                            switch (j) {
                            case 0:
                                func_80028CA8(D_800920C8);
                                break;
                            case 1:
                                func_80028CA8(D_800920D0);
                                break;
                            case 2:
                                func_80028CA8(D_800920D8);
                                break;
                            case 3:
                                func_80028CA8(D_800920E0);
                                break;
                            case 4:
                                func_80028CA8(D_800920E8);
                                break;
                            case 5:
                                func_80028CA8(D_800920F0);
                                break;
                            case 6:
                                func_80028CA8(D_800920F8);
                                break;
                            }
                            D_800D2620[arg0][j] = D_800D1B80[arg0][j + 30];
                            break;
                        }
                    }
                }
            }
            break;
        case 145:
            func_800314D4(8733);
            break;
        case 146:
        case 147:
            func_800314D4(8734);
            break;
        case 148:
            followup_kind = 3;
            continue;
        case 149:
            func_80028CA8(D_80091E60);
            break;
        case 150:
            if (D_800D26A8[arg0] == 0) {
                func_80028CA8(D_80091E18);
            } else {
                func_80028CA8(D_80091E78);
                D_800D26AA[arg0] = 1;
            }
            D_800D26A8[arg0] = 2;
            break;
        case 151:
            func_800314D4(8713);
            break;
        case 152:
            func_800314D4(8719);
            break;
        case 153:
            func_80028CA8(D_80092080);
            break;
        case 154:
            if (D_800D26A8[arg0] == 0) {
                func_800314D4(8715);
            } else {
                func_80028CA8(D_80091E78);
                D_800D26AA[arg0] = 1;
            }
            D_800D26A8[arg0] = 2;
            break;
        case 155:
            if (D_80091A84 == 0) {
                func_800314D4(8592);
                D_80091A84 = 1;
            }
            break;
        case 157:
            func_800314D4(8712);
            func_80023A3C(2, 0, 0);
            break;
        case 158:
            func_800314D4(8640);
            break;
        case 159:
            func_800314D4(8609);
            continue;
        case 160:
            D_80091A8C = 1;
            continue;
        case 161:
            if (D_80091A8C == 0) {
                func_80028CA8(D_80092100);
            }
            D_800D2610[arg0] = D_800D1B88[arg0]->unk26;
            break;
        case 162:
            // FAKE: an empty test of D_80091E98; diff score 10 without it.
            if (!D_80091E98) {}
            func_800314D4(8606);
            break;
        case 163:
            func_800314D4(8690);
            break;
        case 164:
        case 165:
            if (D_800D26A8[arg0] == 0) {
                func_80028CA8(D_80091E18);
            } else {
                func_80028CA8(D_80091E78);
                D_800D26AA[arg0] = 1;
            }
            D_800D26A8[arg0] = 2;
            break;
        case 167:
            if (D_800D1B68[arg0] != 0) {
                func_800314D4(8318);
            } else {
                func_800314D4(8317);
                D_80091AA0 = 1;
            }
            func_80023A3C(2, 0, 0);
            D_800D1B66[arg0] = 1;
            break;
        case 168:
            if (D_800D1B90[arg0] != 214) {
                if (D_80091ACC != 0) {
                    func_80028CA8(D_80092098);
                } else if ((D_800D1B78[0][9] < 2) && (D_800D1B78[1][9] < 2) && (((f32) D_800D1B88[0]->unk26 / (f32) D_800D1B88[0]->unk28) < 0.1f) && (((f32) D_800D1B88[1]->unk26 / (f32) D_800D1B88[1]->unk28) < 0.1f)) {
                    func_800314D4(8622);
                } else if (D_800D1B66[arg0] >= 3) {
                    func_80028CA8(D_80091FD8);
                } else {
                    func_80028CA8(D_80091FD0);
                }
                D_80091ACC = 1;
            }
            break;
        case 169:
            if (D_800D1B66[arg0] == 1) {
                func_800314D4(8570);
            } else if (D_800D1B66[arg0] >= 5) {
                func_800314D4(8569);
            } else {
                func_800314D4(8568);
            }
            D_800D1B66[arg0] = 0;
            D_800D1B68[arg0] = 3;
            func_80023A3C(2, 0, 0);
            break;
        case 170:
            func_800314D4(8640);
            break;
        case 171:
            func_800314D4(8606);
            break;
        case 172:
            func_800314D4(8716);
            func_80023A3C(2, 0, 0);
            break;
        case 173:
            func_800314D4(8717);
            func_80023A3C(2, 0, 0);
            break;
        case 174:
            func_80028CA8(D_80091F98);
            break;
        case 175:
            D_800D1B6A[arg0] = 1;
            D_800D2610[arg0] = D_800D1B88[arg0]->unk26;
            continue;
        case 176:
            func_800314D4(8679);
            D_80091AF8 = 2;
            break;
        case 177:
            if ((D_80091A90 == 0) && (D_80091A9C == 0) && !(func_800194A0() & 1)) {
                func_80028CA8(D_800920A8);
            }
            D_80091A9C = 1;
            break;
        case 178:
            func_800314D4(8676);
            func_80023A3C(2, 0, 0);
            D_80091A90 = 1;
            break;
        case 179:
            func_80028CA8(D_800920B0);
            D_800D1ACC[arg0] = 1;
            D_800D2610[arg0] = D_800D1B88[arg0]->unk26;
            break;
        case 180:
            func_80028CA8(D_80091FA0);
            break;
        case 181:
        case 182:
            if (D_800D26A6[arg0] == 0) {
                func_80028CA8(D_80091E80);
            } else {
                func_80028CA8(D_80091E88);
            }
            D_800D26A6[arg0] = 2;
            break;
        case 183:
            func_800314D4(8718);
            func_80023A3C(2, 0, 0);
            D_80091A8C = 1;
            break;
        case 186:
            func_800314D4(8312);
            break;
        case 187:
            D_800D1B6A[arg0 ^ 1] = 1;
            D_800D2610[arg0] = D_800D1B88[arg0]->unk26;
            continue;
        case 188:
            followup_kind = 4;
            continue;
        case 189:
            D_800D2610[arg0] = D_800D1B88[arg0]->unk26;
            continue;
        case 190:
            D_800D1B6A[arg0] = 1;
            D_800D2610[arg0] = D_800D1B88[arg0]->unk26;
            continue;
        case 191:
            func_80028CA8(D_80091E50);
            break;
        case 43:
        case 101:
        case 166:
        case 184:
        case 185:
            D_80091B00 = arg0;
            D_80091B04 = D_800D1B78[arg0][1];
            D_80091A2C = 0;
            return;
        default:
            continue;
        }
        goto tail;
    }
tail:
    D_80091A2C = 0;
    for (i = 0; i < 10; i++) {
        gAudioQueuedState.event_queue[i] = 0;
    }
    if (D_800D1B88[arg0]->unk28 != 0) {
        percent = D_800D1AD4 * 100 / D_800D1B88[arg0]->unk28;
        if (percent == 0 && D_800D1AD4 > 0) {
            percent = 1;
        }
    } else {
        percent = 100;
    }
    if (seen_event_41 != 0) {
        func_80031564();
        if (D_800D1AD2 == 15) {
            if (D_800D1B88[arg0]->unk26 != 0) {
                func_80028CA8(D_80091E90);
            } else {
                func_80028CA8(D_80091DFC);
            }
            func_80023A3C(2, 0, 0);
        } else if (seen_event_37 != 0) {
            if (percent < 30) {
                if (D_800D1B88[arg0]->unk26 != 0) {
                    func_80028CA8(D_80091DDC);
                } else {
                    func_80028CA8(D_80091E04);
                }
            } else {
                if (D_800D2638 < 2) {
                    func_80028CA8(D_80091D80);
                } else if (D_800D2640[arg0] < 2) {
                    func_80028CA8(D_80091D78);
                } else {
                    func_80028CA8(D_80091D68);
                }
                D_80091AE4 = 1;
            }
            D_80091A4C = 1;
            if ((f32)D_800D1B88[arg0]->unk26 / (f32)D_800D1B88[arg0]->unk28 < 0.05f &&
                D_800D1B88[arg0]->unk26 != 0 && D_800D1B78[arg0][1] != 203) {
                func_80031530(13);
                func_80028CA8(D_80091E98);
            }
            func_80023A3C(2, 0, 0);
        } else {
            if (percent < 31) {
                if (D_800D1B88[arg0]->unk26 != 0) {
                    func_80028CA8(D_80091DD0);
                } else {
                    func_80028CA8(D_80091E04);
                    func_80023A3C(2, 0, 0);
                }
            } else {
                func_80028CA8(D_80091D88);
                D_80091AE4 = 1;
                func_80023A3C(2, 0, 0);
            }
            D_80091A4C = 1;
            if ((f32)D_800D1B88[arg0]->unk26 / (f32)D_800D1B88[arg0]->unk28 < 0.05f &&
                D_800D1B88[arg0]->unk26 != 0 && D_800D1B78[arg0][1] != 203) {
                func_80031530(13);
                func_80028CA8(D_80091E98);
            }
        }
    } else if (seen_event_37 != 0) {
        func_80031564();
        if (D_800D1AD2 == 15) {
            if (D_800D1B88[arg0]->unk26 != 0) {
                func_80028CA8(D_80091E90);
            } else {
                func_80028CA8(D_80091DFC);
            }
        } else if (percent < 31) {
            if (D_800D1B88[arg0]->unk26 != 0) {
                func_80028CA8(D_80091DDC);
            } else {
                func_80028CA8(D_80091E04);
            }
        } else {
            func_80028CA8(D_80091D98);
            D_80091AE4 = 1;
        }
        if ((f32)D_800D1B88[arg0]->unk26 / (f32)D_800D1B88[arg0]->unk28 < 0.05f &&
            D_800D1B88[arg0]->unk26 != 0 && D_800D1B78[arg0][1] != 203) {
            func_80031530(13);
            func_80028CA8(D_80091E98);
        }
        func_80023A3C(2, 0, 0);
        D_80091A4C = 1;
    } else if (seen_event_68 != 0) {
        if (percent >= 30) {
            func_80031564();
            if (D_800D1AD2 == 15) {
                if (D_800D1B88[arg0]->unk26 != 0) {
                    func_80028CA8(D_80091E90);
                } else {
                    func_80028CA8(D_80091DFC);
                }
                func_80023A3C(2, 0, 0);
            } else if (percent >= 71) {
                func_80028CA8(D_80091DE4);
                D_80091AE4 = 1;
                func_80023A3C(2, 0, 0);
            } else if (D_800D1B88[arg0]->unk26 != 0) {
                func_80028CA8(D_80091DA8);
            } else {
                func_80028CA8(D_80091DC4);
            }
            if ((f32)D_800D1B88[arg0]->unk26 / (f32)D_800D1B88[arg0]->unk28 < 0.05f &&
                D_800D1B88[arg0]->unk26 != 0 && D_800D1B78[arg0][1] != 203) {
                func_80031530(13);
                func_80028CA8(D_80091E98);
            }
            D_80091A4C = 1;
        } else {
            switch (followup_kind) {
            case 1:
                func_800314D4(8321);
                D_80091A4C = 1;
                func_80023A3C(2, 0, 0);
                break;
            case 3:
                func_800314D4(8322);
                D_80091A4C = 1;
                func_80023A3C(2, 0, 0);
                break;
            case 4:
                func_800314D4(8323);
                D_80091A4C = 1;
                func_80023A3C(2, 0, 0);
                break;
            case 6:
                func_800314D4(8320);
                D_80091A4C = 1;
                func_80023A3C(2, 0, 0);
                break;
            case 5:
                func_800314D4(8319);
                D_80091A4C = 1;
                func_80023A3C(2, 0, 0);
                break;
            default:
                if (D_800D1B88[arg0]->unk26 != 0) {
                    func_80028CA8(D_80091DA8);
                } else {
                    func_80028CA8(D_80091E04);
                }
                break;
            }
            D_80091A4C = 1;
        }
    } else if (percent < 30) {
        switch (followup_kind) {
        case 1:
            func_800314D4(8321);
            D_80091A4C = 1;
            func_80023A3C(2, 0, 0);
            break;
        case 3:
            func_800314D4(8322);
            D_80091A4C = 1;
            func_80023A3C(2, 0, 0);
            break;
        case 4:
            func_800314D4(8323);
            D_80091A4C = 1;
            func_80023A3C(2, 0, 0);
            break;
        case 6:
            func_800314D4(8320);
            D_80091A4C = 1;
            func_80023A3C(2, 0, 0);
            break;
        case 5:
            func_800314D4(8319);
            D_80091A4C = 1;
            func_80023A3C(2, 0, 0);
            break;
        }
    }
    if (check_stat_drops != 0) {
        if (D_800D1B64[arg0] != 0) {
            func_80028CA8(D_80091E20);
        } else {
            lowered_count = 0;
            for (j = 0; j < 7; j++) {
                if (D_800D1B80[arg0][j + 30] < D_800D2620[arg0][j]) {
                    lowered_count++;
                }
            }
            if (lowered_count >= 2) {
                func_800314D4(8352);
            } else if (D_80091AF4 != 0) {
                func_80028CA8(D_80091E0C);
            } else {
                for (j = 0; j < 7; j++) {
                    if (D_800D1B80[arg0][j + 30] < D_800D2620[arg0][j]) {
                        switch (j) {
                        case 0:
                            if (D_80091A54 == 0) {
                                func_800314D4(8344);
                                D_80091A54 = 1;
                            } else {
                                func_80028CA8(D_80091E0C);
                            }
                            break;
                        case 1:
                            if (D_80091A58 == 0) {
                                func_800314D4(8345);
                                D_80091A58 = 1;
                            } else {
                                func_80028CA8(D_80091E0C);
                            }
                            break;
                        case 2:
                            if (D_80091A5C == 0) {
                                func_800314D4(8350);
                                D_80091A5C = 1;
                            } else {
                                func_80028CA8(D_80091E0C);
                            }
                            break;
                        case 3:
                            if (D_80091A60 == 0) {
                                func_800314D4(8346);
                                D_80091A60 = 1;
                            } else {
                                func_80028CA8(D_80091E0C);
                            }
                            break;
                        case 4:
                            if (D_80091A64 == 0) {
                                func_800314D4(8347);
                                D_80091A64 = 1;
                            } else {
                                func_80028CA8(D_80091E0C);
                            }
                            break;
                        case 5:
                            if (D_80091A68 == 0) {
                                func_800314D4(8348);
                                D_80091A68 = 1;
                            } else {
                                func_80028CA8(D_80091E0C);
                            }
                            break;
                        case 6:
                            if (D_80091A6C == 0) {
                                func_800314D4(8349);
                                D_80091A6C = 1;
                            } else {
                                func_80028CA8(D_80091E0C);
                            }
                            break;
                        }
                        D_800D2620[arg0][j] = D_800D1B80[arg0][j + 30];
                        break;
                    }
                }
            }
        }
        D_80091A4C = 1;
        D_800D1B64[arg0] = 2;
        for (j = 0; j < 7; j++) {
            D_800D2620[arg0][j] = D_800D1B80[arg0][j + 30];
        }
    }
}


#pragma GLOBAL_ASM("asm/us/nonmatchings/2C1B0/func_80030420.s")

extern u8 D_80091A40, D_80091AFC, D_80091A4C, D_80091AF0, D_80091A80, D_80091A7C, D_80091A48, D_800D1AD2;
extern s32 D_80091AA8, D_800D1AD4;
extern u8 D_800D269E[], D_800D26AC[], D_800D26AE[];
void func_800231A0(s32, u32, s32, u8);
u32 func_80028540(u8, u32);
extern s8 D_80091AB4;

void func_80030AD4(u8 arg0, u32 arg1, u32 arg2) {
    u32 amount;
    u32 percent;
    s32 old_hp[2];

    D_80091A40 = arg0;
    D_80091AFC = arg0;
    D_80091A4C = 0;
    D_80091ADC = 0;
    D_80091AE0 = 0;
    D_80091AF0 = 0;
    D_80091A80 = 0;
    if (D_800D1B38[arg0] == D_800D1B78[arg0][10]) {
        D_800D1B88[arg0] = (unk_D_800D1B88 *)(D_800D1B78[arg0][10] * 88 + D_800D1B78[arg0] + 24);
        D_800D1B98[arg0] = *(BattleMetadata84 *)(D_800D1B78[arg0] + 1080);
    }
    if (D_800D1B38[arg0 ^ 1] == D_800D1B78[arg0 ^ 1][10]) {
        D_800D1B88[arg0 ^ 1] = (unk_D_800D1B88 *)(D_800D1B78[arg0 ^ 1][10] * 88 + D_800D1B78[arg0 ^ 1] + 24);
        D_800D1B98[arg0 ^ 1] = *(BattleMetadata84 *)(D_800D1B78[arg0 ^ 1] + 1080);
    }
    if (D_80091AB4 != arg0) {
        D_80091AB4 = arg0;
        D_80091A7C = 0;
    }
    if (arg1 == 185) {
        func_800231A0(185, arg2, 10, arg0);
    }
    if (D_80091A48 == 0) {
        Audio_ClearCommandQueue();
    }
    D_80091A48 = 0;
    D_800D269E[arg0] = 0;
    D_800D26A4[arg0] = 0;
    if (D_80091A7C == 0) {
        D_80091AA8 = D_800D1AD4 = D_800D2610[arg0 ^ 1] - D_800D1B88[arg0 ^ 1]->unk26;
    } else {
        D_800D1AD4 = D_80091AA8;
    }
    old_hp[0] = D_800D2610[0];
    old_hp[1] = D_800D2610[1];
    D_800D2610[0] = D_800D1B88[0]->unk26;
    D_800D2610[1] = D_800D1B88[1]->unk26;
    amount = func_80028540(arg0, arg1);
    switch (amount) {
    case (u32)-1:
        D_800D1B62[arg0] = 0;
        if (func_80028E60(arg1) == 0) {
            D_800D1AD2 = 14;
        } else {
            D_800D1AD2 = 4;
        }
        return;
    case (u32)-2:
        D_800D1B62[arg0] = 0;
        if (func_80028E60(arg1) == 0) {
            D_800D1AD2 = 14;
        } else {
            D_800D1AD2 = 5;
        }
        return;
    case (u32)-3:
        D_800D1B62[arg0] = 0;
        D_80091AE8 = arg0 + 1;
        if (func_80028E60(arg1) == 0) {
            D_800D1AD2 = 14;
        } else {
            D_800D1AD2 = 6;
        }
        return;
    case (u32)-4:
        D_800D1B62[arg0] = 0;
        if (func_80028E60(arg1) == 0) {
            D_800D1AD2 = 14;
        } else {
            D_800D1AD2 = 7;
        }
        return;
    case (u32)-5:
        D_800D1AD2 = 8;
        return;
    case (u32)-6:
        D_800D1B62[arg0] = 0;
        if (func_80028E60(arg1) == 0) {
            D_800D1AD2 = 14;
        } else if (D_800D26AC[arg0] == 1) {
            D_800D1AD2 = 14;
        } else {
            D_800D1AD2 = 9;
        }
        return;
    case (u32)-7:
        D_800D1B62[arg0] = 0;
        if (func_80028E60(arg1) == 0) {
            D_800D1AD2 = 14;
        } else {
            D_800D1AD2 = 10;
        }
        return;
    case (u32)-8:
        D_800D1B62[arg0] = 0;
        D_800D1AD2 = 11;
        return;
    case (u32)-9:
        D_800D1B62[arg0] = 0;
        if (func_80028E60(arg1) == 0) {
            D_800D1AD2 = 14;
        } else {
            D_800D1AD2 = 12;
        }
        return;
    case (u32)-10:
        D_800D1B62[arg0] = 0;
        if (func_80028E60(arg1) == 0) {
            D_800D1AD2 = 14;
        } else {
            D_800D1AD2 = 13;
        }
        return;
    case (u32)-11:
        D_800D1B62[arg0] = 0;
        D_800D1AD2 = 14;
        return;
    default:
        D_800D1B62[arg0] = 0;
        if (amount >= (u32)old_hp[arg0 ^ 1]) {
            if (func_80028E60(arg1) == 0) {
                D_800D1AD2 = 14;
                return;
            }
            if ((u8)D_80091A18 == 0 && D_800D26AC[arg0 ^ 1] < 2) {
                if ((f32)(s32)old_hp[arg0 ^ 1] * 1.3f < (f32)amount) {
                    D_800D1AD2 = 15;
                    return;
                }
            }
            if ((u8)D_80091A18 != 0 && D_800D26AE[arg0 ^ 1] < 2) {
                if ((f32)(s32)old_hp[arg0 ^ 1] * 1.3f < (f32)amount) {
                    D_800D1AD2 = 15;
                    return;
                }
            }
        }
        if ((*(u16 *)((u8 *)D_800D1B88[arg0 ^ 1] + 40)) != 0) {
            percent = amount * 100 / (*(u16 *)((u8 *)D_800D1B88[arg0 ^ 1] + 40));
        } else {
            percent = 0;
        }
        if (percent >= 91) {
            D_800D1AD2 = 1;
        } else if (percent >= 41) {
            D_800D1AD2 = 2;
        } else if (percent != 0) {
            D_800D1AD2 = 3;
        } else {
            D_800D1AD2 = 16;
        }
        return;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/2C1B0/func_8003121C.s")

void func_800314D4(s32 arg0) {
    if ((u8)D_80091A0C != 0) {
        if ((u8)D_80091A10 != 0) {
            if (arg0 != 0) {
                D_800D1A90[D_80091A24 % 10] = arg0;
                D_80091A24++;
            }
        }
    }
}

void func_80031530(u16 a) {
    func_800314D4(a | 0x10000000);
}

void func_80031530_padding(void) {}

void Audio_ClearCommandQueue(void) {
    s32 i;

    if ((u8)D_80091A0C != 0 && (u8)D_80091A10 != 0) {
        for (i = 0; i < 10; i++) {
            gAudioCommandQueue[i] = 0;
        }
        D_80091A24 = 0;
        D_80091A28 = 0;
        if (D_80091A30 != 0) {
            D_80091A30 = 1;
        }
    }
}

void Audio_DisableCommandQueue(void) {
    s32 i;

    D_80091A10 = 0;
    for (i = 0; i < 10; i++) {
        gAudioCommandQueue[i] = 0;
    }
    D_80091A24 = 0;
    D_80091A28 = 0;
}

void Audio_UpdateCommandQueue(void) {
    u32 command;

    if ((u8)D_80091A0C && (u8)D_80091A10 && D_80091A28 < D_80091A24) {
        if (D_80091A30 != 0) {
            D_80091A30--;
        } else if (func_80019230(4, 1, 0) == 0) {
            command = D_800D1A90[D_80091A28 % 10];
            if (command >= 0x10000) {
                switch (command & 0xFFFF0000) {
                    case 0x10000000:
                        D_80091A30 = command & 0xFFFF;
                        break;
                    case 0x20000000:
                        D_80091A34 = 1;
                        break;
                }
            } else if (command != 0) {
                Audio_QueueDeferredSound(command, 0, 127);
            }
            D_80091A28++;
        }
    }
    if (D_80091A1C && D_80091A34) {
        if (D_80091A20 == 0) {
            if (D_800D1B88[0]->unk26 == 0 || D_800D1B88[1]->unk26 == 0 || D_80091A44 != 0) {
                D_80091A20 = 598;
            }
        }
        if (D_80091A20 == 1) {
            func_800314D4(0x20E2);
        } else if (D_80091A20 == 600) {
            func_800314D4(0x20E3);
        } else if (D_80091A20 == 1200) {
            func_800314D4(0x20E4);
            D_80091A20 = 2;
        }
        D_80091A20++;
    }
}

void func_80031844(s32 arg0, s32 arg1) { s32 *p0 = &arg0; *p0 = arg0; arg0 &= 0xFF; if (arg0 < 2) { if (arg1 <= 0) D_800D1B90[arg0] = 0; else D_800D1B90[arg0] = arg1; } }

void func_80031880(s32 arg0, s32 arg1) {
    switch (arg1) {
        case 1:
            arg0 |= 0x3000;
            break;
        case 2:
            arg0 |= 0x2000;
            break;
        case 0:
            break;
        default:
            return;
    }
    func_800314D4(arg0);
}

s32 func_800318C8(void) {
    if (func_80019230(4, 1, 0) != 0) {
        return 1;
    }
    return 0;
}

typedef struct { u8 unk00[38]; u16 hp; u8 unk28[48]; } PartyCountMember;
s32 Party_CountLivingGroupMembers(u8 *party) {
    u32 i;
    u8 first_count;
    s32 same_group;
    u8 count;

    count = 0;
    if (party[0x12] != 0) {
        first_count = party[3];
        if (party[0xA] < first_count) {
            same_group = 0;
        } else {
            same_group = 1;
        }
        if (same_group == 0) {
            s32 prefix_limit;
            i = 0;
            prefix_limit = first_count;
            if (first_count != 0) {
                do {
                    if (((PartyCountMember *)(party + 24))[i].hp > 0) {
                        count++;
                    }
                    i++;
                } while (i < prefix_limit);
            }
        } else {
            for (i = first_count; i < party[7]; i++) {
                if (((PartyCountMember *)(party + 24))[i].hp > 0) {
                    count++;
                }
            }
        }
    } else {
        count = party[9];
    }
    return count;
}

void GbAudio_QueueRegisterWrite(u16 address, u8 value, u16 delay) {
    u8 index = address;
    D_800D27C0[D_800D2AE4].ptr = (u8 *)&D_800D2760 + index * 2 - 0x20;
    D_800D27C0[D_800D2AE4].value = value;
    D_800D27C0[D_800D2AE4].limit = delay + 1;
    D_800D2AD8[index] = value;
    D_800D2AE4++;
    D_800D2AE4 %= 100;
    D_800D27C0[D_800D2AE4].limit = 0;
}

u8 GbAudio_GetRegisterValue(u16 arg0)
{
  return D_800D2AD8[arg0 & 0xFF];
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/2C1B0/func_80031A6C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2C1B0/func_80031C84.s")

void func_80031E6C(u16 arg0) {
    while (D_800D27C0[D_800D2AE0].limit >= arg0) {
        D_800D27C0[D_800D2AE0].ptr[0] = D_800D27C0[D_800D2AE0].value;
        D_800D27C0[D_800D2AE0].ptr[1] = 1;
        D_800D2AE0++;
        if ((u32)D_800D2AE0 >= 100U) D_800D2AE0 -= 100;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/2C1B0/func_80031F00.s")

s16 GbAudio_RenderPulse2(void) {
    s32 i;
    s32 changed;
    s32 nr24;
    u8 phase;
    s16 out;

    changed = 0;
    for (i = 6; i < 10; i++) {
        if (GB_PULSE2_DIRTY(i) != 0) {
            changed = 1;
            GB_PULSE2_DIRTY(i) = 0;
        }
    }

    if (changed) {
        nr24 = GB_PULSE2_REG(9);
        D_800D26E8.unk1C = ((0x800 - (GB_PULSE2_REG(8) | (((u8)nr24 & 7) << 8))) * D_800D275C) >> 11;
        switch ((GB_PULSE2_REG(6) & 0xC0) >> 6) {
            case 0:
                D_800D26E8.duty_ticks[1] = D_800D26E8.unk1C >> 3;
                if (D_800D26E8.duty_ticks[1] < 64) {
                    D_800D26E8.duty_ticks[1] = 64;
                }
                phase = 1;
                D_800D26E8.duty_ticks[0] = D_800D26E8.unk1C - D_800D26E8.duty_ticks[1];
                goto duty_done;
            case 1:
                D_800D26E8.duty_ticks[1] = D_800D26E8.unk1C >> 2;
                if (D_800D26E8.duty_ticks[1] < 64) {
                    D_800D26E8.duty_ticks[1] = 64;
                }
                phase = 0;
                D_800D26E8.duty_ticks[0] = D_800D26E8.unk1C - D_800D26E8.duty_ticks[1];
                goto duty_done;
            case 2:
                D_800D26E8.duty_ticks[1] = D_800D26E8.unk1C >> 1;
                if (D_800D26E8.duty_ticks[1] < 64) {
                    D_800D26E8.duty_ticks[1] = 64;
                }
                phase = 0;
                D_800D26E8.duty_ticks[0] = D_800D26E8.unk1C - D_800D26E8.duty_ticks[1];
                goto duty_done;
            case 3:
                D_800D26E8.duty_ticks[0] = D_800D26E8.unk1C >> 2;
                if (D_800D26E8.duty_ticks[0] < 64) {
                    D_800D26E8.duty_ticks[0] = 64;
                }
                phase = 1;
                D_800D26E8.duty_ticks[1] = D_800D26E8.unk1C - D_800D26E8.duty_ticks[0];
                goto duty_done;
        }
        D_800D26E8.duty_ticks[1] = 0;
        phase = 1;
        D_800D26E8.duty_ticks[0] = D_800D26E8.unk1C;
    duty_done:

        if (!(GB_PULSE2_REG(7) & 8) && !(GB_PULSE2_REG(7) & 0xF0)) {
            D_800D26E8.unk24 = 0;
            D_800D2760.unk2C &= 0xFFFD;
            return 0;
        }
        if ((GB_PULSE2_REG(7) & 8) && !(GB_PULSE2_REG(7) & 0xF0) && !(GB_PULSE2_REG(7) & 7)) {
            D_800D26E8.unk24 = 0;
            D_800D2760.unk2C &= 0xFFFD;
            return 0;
        }

        if (nr24 & 0x80) {
            D_800D26E8.unk0 = 0;
            D_800D26E8.unk24 = 1;
            D_800D26E8.unk16 = phase;
            D_800D26E8.unk14 = 0;
            D_800D26E8.unk18 = 0;
            D_800D26E8.unk4 = ((GB_PULSE2_REG(7) & 0xF0) << 3) << 4;
            if (GB_PULSE2_REG(7) & 7) {
                if (GB_PULSE2_REG(7) & 8) {
                    D_800D26E8.unk6 = 0x800;
                } else {
                    D_800D26E8.unk6 = -0x800;
                }
                D_800D26E8.unkC = D_800D26E8.unk8 = (GB_PULSE2_REG(7) & 7) * D_800D275C;
            } else {
                D_800D26E8.unk6 = 0;
                D_800D26E8.unk8 = -1;
                D_800D26E8.unkC = -1;
            }
            if (nr24 & 0x40) {
                D_800D26E8.unk20 = ((64 - (GB_PULSE2_REG(6) & 0x3F)) * D_800D275C) >> 2;
            } else {
                D_800D26E8.unk20 = -1;
            }
            GB_PULSE2_REG(9) = nr24 & ~0x80;
        }
        if (D_800D26E8.unk24 == 0) {
            return 0;
        }
    } else if (D_800D26E8.unk24 == 0) {
        return 0;
    }

    if (D_800D26E8.unk20 < D_800D26E8.unk0) {
        D_800D26E8.unk24 = 0;
        D_800D2760.unk2C &= 0xFFFD;
        return 0;
    }

    if (D_800D26E8.unkC < D_800D26E8.unk0) {
        D_800D26E8.unk4 += D_800D26E8.unk6;
        D_800D26E8.unkC += D_800D26E8.unk8;
    }
    while (D_800D26E8.unk18 <= D_800D26E8.unk0) {
        D_800D26E8.unk16 ^= 1;
        D_800D26E8.unk18 += D_800D26E8.duty_ticks[D_800D26E8.unk16];
    }

    if (!(GB_PULSE2_REG(7) & 8) && (D_800D26E8.unk4 < 0)) {
        D_800D26E8.unk24 = 0;
        return 0;
    }
    if ((u16)D_800D26E8.unk4 > 30720) {
        D_800D26E8.unk4 = 30720;
        D_800D26E8.unk6 = 0;
        D_800D26E8.unkC = -1;
    }
    out = D_800D26E8.unk4;
    if (D_800D26E8.unk16 == 0) {
        out = -out;
    }
    D_800D26E8.unk0 += 64;
    return out;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/2C1B0/func_80032A28.s")

void func_80032E40(u8 arg0) {
    u8 *p = &D_800D2B78 + (arg0 * 3 * 4 * 5);
    *(u16 *)(p + 0) = 0; p[2] = 0; p[3] = 0; p[4] = 0; p[5] = 0;
    *(s32 *)(p + 8) = 0; *(s32 *)(p + 12) = 0; *(s32 *)(p + 16) = 0;
    p[20] = 0; p[21] = 0; p[22] = 0; p[23] = 0; *(u16 *)(p + 24) = 0;
    p[26] = 0; p[27] = 0; p[28] = 0; p[29] = 0; p[30] = 0; p[31] = 0; p[32] = 0; *(u16 *)(p + 34) = 0;
    p[36] = 0; p[37] = 0; p[38] = 0; p[39] = 0; p[40] = 0; p[41] = 0; p[42] = 0; p[43] = 0; p[44] = 0; p[45] = 0; p[46] = 0; p[47] = 0;
    *(u16 *)(p + 48) = 0; p[50] = 0; p[51] = 0; p[52] = 0; p[53] = 0; p[54] = 0; p[55] = 0; p[56] = 0; p[57] = 0;
}

void GbAudio_ResetState(void) {
    OSIntMask saved_mask;
    u32 index;

    saved_mask = osSetIntMask(OS_IM_NONE);
    func_800331C8();
    osSetIntMask(saved_mask);
    for (index = 0; index < 4; index++) {
        GbAudio_QueueRegisterWrite(index * 5 + 0xFF10, 0, 0);
        GbAudio_QueueRegisterWrite(index * 5 + 0xFF11, 0, 0);
        GbAudio_QueueRegisterWrite(index * 5 + 0xFF12, 8, 0);
        GbAudio_QueueRegisterWrite(index * 5 + 0xFF13, 0, 0);
        GbAudio_QueueRegisterWrite(index * 5 + 0xFF14, 0x80, 0);
    }
    GbAudio_QueueRegisterWrite(0xFF24, 0, 0);
    GbAudio_QueueRegisterWrite(0xFF25, 0, 0);
    GbAudio_QueueRegisterWrite(0xFF26, 0x80, 0);
    for (index = 0; index != 8; index++) {
        func_80032E40(index);
    }
    D_800D2B40 = 0;
    D_800D2B42 = 0;
    D_800D2B43 = 0;
    D_800D2B44 = 0;
    D_800D2B46 = 0;
    D_800D2B47 = 0;
    D_800D2B48 = 0;
    D_800D2B4A = 0;
    D_800D2B4B = 0;
    D_800D2B4C = 0;
    D_800D2B4E = 0;
    D_800D2B50 = 0;
    D_800D2B54 = 0;
    D_800D2B55 = 0;
    D_800D2B56 = 0;
    D_800D2B57 = 0;
    D_800D2B58 = 0;
    D_800D2B59 = 0;
    D_800D2B5A = 0;
    D_800D2B5C = 0;
    D_800D2B5E = 0;
    D_800D2B5F = 0;
    D_800D2B60 = 0;
    D_800D2B62 = 0;
    D_800D2B64 = 0;
    D_800D2B66 = 0;
    D_800D2B68 = 0;
    D_800D2B69 = 0;
    D_800D2B6A = 0;
    D_800D2B6B = 0;
    D_800D2B6C = 0;
    D_800D2B6D = 0;
    D_800D2B6E = 0;
    D_800D2B6F = 0;
    D_800D2B70[0] = 0;
    D_800D2B70[1] = 0;
    D_800D2B70[2] = 0;
    D_800D2B73 = 0;
    D_800D2B49 = 0x77;
    saved_mask = osSetIntMask(OS_IM_NONE);
    func_800331B8();
    osSetIntMask(saved_mask);
}

void func_80033188(void) {
    u16 sp1E;

    sp1E = D_800D2B5C;
    GbAudio_ResetState();
    D_800D2B5C = sp1E;
}

 void func_800331B8(void) { D_800D2B41 = 1; }

 void func_800331C8(void) { D_800D2B41 = 0; }

/* mkdraft:func_800331D4 begin */
void func_800333CC(u8 arg0);

// D_800D2B78 holds eight 0x3C-byte GbAudioStreamRecord entries; the record
// checks below address them through this base.
#define REC(i) (((GbAudioStreamRecord *)&D_800D2B78)[i])



void func_800331D4(void) {
    u32 i;
    u8 channel;

    if (D_800D2B41 != 0) {
        D_800D2B4A = 0;
        for (i = 0; i != 8; i++) {
            if (REC(i).flags_03 & 1) {
                channel = i;
                if (REC(i).unk_1D < 2) {
                    REC(i).unk_26 = REC(i).unk_27;
                    REC(i).flags_04 &= ~2;
                    GbAudio_ProcessChannelStream(channel);
                } else {
                    REC(i).unk_1D--;
                }
                func_80033BF4(channel);
                D_800D2B42 = REC(i).unk_16;
                D_800D2B43 = REC(i).unk_17;
                D_800D2B44 = REC(i).unk_18;
                func_800339EC(channel);
                func_80033C48(channel & 0xFF);
                if (D_800D2B6A != 0 && i < 4 &&
                        ((REC(4).flags_03 & 1) || (REC(5).flags_03 & 1) ||
                         (REC(6).flags_03 & 1) || (REC(7).flags_03 & 1))) {
                    REC(i).flags_14 |= 0x20;
                }
                if (i >= 4 || !(REC(4).flags_03 & 1)) {
                    func_800333CC(channel);
                    D_800D2B4A |= REC(i).unk_24;
                }
                REC(i).flags_14 = 0;
            }
        }
        func_800319D0(0xFF24, D_800D2B49, 0);
        func_800319D0(0xFF25, D_800D2B4A, 0);
    }
}
/* mkdraft:func_800331D4 end */

/* mkdraft:func_800333CC begin */
extern void func_80033488(u8 arg0);
extern void func_800334C0(u8 arg0);
extern void func_80033670(u8 arg0);
extern void func_80033890(u8 arg0);
extern void func_8003364C(u8 arg0);
extern void func_800337D8(u8 arg0);
extern void func_80033864(u8 arg0);
extern void func_8003386C(u8 arg0);
// No FAKE construct in this body. The u8 formals above are the real types: every
// callee masks its own argument (andi a0,a0,0xff in its jal delay slot), and a
// u8-parameter definition of the wrappers reproduces retail 9/9 (t36.py), while
// the s32 spelling declared in include/229E0.h needs an "s32 *p = &arg0;" hack
// to get there. The header types are the artifact, not this code.
// TU consequence: include/229E0.h declares func_8003364C/337D8/33864/3386C with
// s32, so these u8 externs conflict with it (hard cfe error) unless the TU hides
// those four names with a #define/#undef pair around the #include -- which is
// what src/2C1B0.c does. No other function in that file calls them.



void func_800333CC(u8 arg0) {
    u8 v;
    v = arg0 & 7;
    switch (v) {
    case 0: func_80033488(v); break;
    case 1: func_8003364C(v); break;
    case 2: func_800337D8(v); break;
    case 3: func_8003386C(v); break;
    case 4: func_800334C0(v); break;
    case 5: func_80033670(v); break;
    case 6: func_80033864(v); break;
    case 7: func_80033890(v); break;
    }
}
/* mkdraft:func_800333CC end */

void GbAudio_UpdateChannelIfEnabled(u8 channel) {
    if (!(D_800D2B58 & 0x80)) {
        GbAudio_UpdateSquare1Registers(channel);
    }
}

#endif
