#include "229E0.h"

#ifdef VERSION_US

#pragma GLOBAL_ASM("asm/us/nonmatchings/2C1B0/func_8002B5B0.s")

extern u8 D_80091AD0, D_80091AD4, D_80091AD8, D_80091ADC, D_80091AE0, D_80091AE8;
extern u8 D_800D1ACC[], D_800D1B6A[], D_800D1B6C[], D_800D269A[];
extern s32 D_800D2618[];
extern u32 D_800D2638;
extern u8 D_80091EA8[], D_80091EB8[], D_80091EC4[], D_80091ECC[], D_80091ED4[], D_80091EDC[], D_80091EE4[];
s32 func_800318FC(u8 *);
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
            func_800318FC(D_800D1B78[arg0]) == 0 &&
            func_800318FC(D_800D1B78[arg0 ^ 1]) > 0 &&
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
  D_800D1AB8[D_80091A2C] = arg0;
  D_80091A2C = D_80091A2C + 1;
  if (((u32) D_80091A2C) >= 10U)
  {
    D_80091A2C = D_80091A2C - 1;
  }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/2C1B0/func_8002C2E0.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2C1B0/func_80030420.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2C1B0/func_80030AD4.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/2C1B0/func_80031564.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2C1B0/func_800315E8.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/2C1B0/func_800318FC.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/2C1B0/func_800331D4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/2C1B0/func_800333CC.s")

void GbAudio_UpdateChannelIfEnabled(u8 channel) {
    if (!(D_800D2B58 & 0x80)) {
        GbAudio_UpdateSquare1Registers(channel);
    }
}

#endif
