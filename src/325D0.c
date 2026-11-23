#include "229E0.h"

#ifdef VERSION_US

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

/* mkdraft:func_80031A6C begin */
extern u8 *D_800D2B24;
extern u8 *D_800D2B28;
extern u8 D_800D2B30[];
extern u8 D_800D27A0[];
extern u16 D_800D27C6;
extern f32 D_800D2B1C;
typedef struct {
    u32 time;
    u16 freq;
    u8 pad6[2];
    u32 sweepPeriod;
    u32 sweepNext;
    s16 volume;
    s16 step;
    u32 envPeriod;
    u32 envNext;
    u16 duty_ticks[2];
    s16 unk20;
    u8 phase;
    u8 pad23;
    u32 nextPhase;
    u32 period;
    u32 length;
    u8 enabled;
} GbPulse1State;
extern GbPulse1State D_800D26B0;
extern u8 D_800D2710[];
extern u8 D_800D2730[];



void func_80031A6C(s32 arg0, void *arg1)
{
  u32 i;
  if (arg1 == 0)
  {
    return;
  }
  D_800D2B24 = arg1;
  D_800D2B28 = ((u8 *) arg1) + 0x100;
  func_80035068(((u32) D_154F190) + 8, D_800D2B30, 8);
  *((u32 *) (&D_800D2B30[4])) += (u32) D_154F190;
  func_80035068(*((u32 *) (&D_800D2B30[4])), D_800D2B24, 0x100);
  for (i = 0; ((i - 1) + 1) <= (0x100 - 1); i += 8)
  {
    *((u32 *) (D_800D2B24 + i)) += *((u32 *) (&D_800D2B30[4]));
  }

  D_800D275C = ((u32) arg0) >> 1;
  D_800D2B1C = 1048576.0f / ((f32) D_800D275C);
  for (i = 0; i < 48; i++)
  {
    ((u8 *) (&D_800D2760))[(i * 2) + 1] = 1;
  }

  ((u8 *) (&D_800D2760))[0 * 2] = 8;
  ((u8 *) (&D_800D2760))[1 * 2] = 0;
  ((u8 *) (&D_800D2760))[2 * 2] = 0;
  ((u8 *) (&D_800D2760))[3 * 2] = 0;
  ((u8 *) (&D_800D2760))[4 * 2] = 0x40;
  ((u8 *) (&D_800D2760))[6 * 2] = 0;
  ((u8 *) (&D_800D2760))[7 * 2] = 0;
  ((u8 *) (&D_800D2760))[8 * 2] = 0;
  ((u8 *) (&D_800D2760))[9 * 2] = 0x40;
  ((u8 *) (&D_800D2760))[10 * 2] = 0;
  ((u8 *) (&D_800D2760))[11 * 2] = 0;
  ((u8 *) (&D_800D2760))[12 * 2] = 0;
  ((u8 *) (&D_800D2760))[13 * 2] = 0;
  ((u8 *) (&D_800D2760))[14 * 2] = 0x40;
  ((u8 *) (&D_800D2760))[16 * 2] = 0;
  ((u8 *) (&D_800D2760))[17 * 2] = 0;
  ((u8 *) (&D_800D2760))[18 * 2] = 0;
  ((u8 *) (&D_800D2760))[19 * 2] = 0x40;
  ((u8 *) (&D_800D2760))[20 * 2] = 0;
  ((u8 *) (&D_800D2760))[21 * 2] = 0;
  ((u8 *) (&D_800D2760))[22 * 2] = 0;
  // FAKE: empty condition, emits nothing; only splits the block so the D_800D275C
  // address web is assigned v1 rather than a0.  Without it the score is 34.
  if (i && i)
  {
  }
  for (i = 0; i < 16; i++)
  {
    ((u8 *) D_800D27A0)[i * 2] = 0;
  }

  D_800D2AE4 = 0;
  D_800D27C6 = 0;
  D_800D2AE0 = 0;
  D_800D26B0.time = 0;
  D_800D26B0.enabled = 0;
  D_800D26E8.unk0 = 0;
  D_800D26E8.unk24 = 0;
  *((u32 *) D_800D2710) = 0;
  D_800D2710[0x1C] = 0;
  *((u32 *) D_800D2730) = 0;
  D_800D2730[0x28] = 0;
  D_800D2730[4] = 0xFF;
}
/* mkdraft:func_80031A6C end */

/* mkdraft:func_80031C84 begin */
extern u8 D_800D2B18;
extern s8 D_800D2B19;
extern f32 D_800D2B1C;

s16 func_80031F00();                                /* extern */
s16 func_80032A28();                                /* extern */
void func_80031E6C(u16);                            /* extern */



s32 func_80031C84(s16 *arg0, s32 arg1) {
    s32 pad[3];
    s16 sp4C[4];
    f32 var_fs0;
    s16 temp_v0;
    s16 var_a0;
    u32 var_a1;
    s32 var_a2;
    s32 var_s1;
    s32 var_s2;
    s32 var_v1;

    var_fs0 = 0.0f;
    var_s2 = 1;
    if ((s8) D_80090B8C == 0) {
        return 0;
    }
    if (arg0 == NULL) {
        return 0;
    }
    var_s1 = 0;
    if (arg1 != 0) {
        do {
            if (var_fs0 <= (f32) (u32) var_s1) {
                func_80031E6C(var_s2);
            }
            if (D_800D2760.unk2C & 0x80) {
                if (D_800D2760.unk29 != 0) {
                    D_800D2760.unk29 = 0;
                    D_800D2B18 = D_800D2760.unk28 & 7;
                    D_800D2B19 = (s8) ((s32) (D_800D2760.unk28 & 0x70) >> 4);
                }
                sp4C[0] = func_80031F00();
                sp4C[1] = GbAudio_RenderPulse2();
                temp_v0 = func_80032A28();
                sp4C[3] = temp_v0;
                if (D_800D2760.unk2A & 2) {
                    var_a1 = -1;
                } else {
                    var_a1 = 0;
                }
                if (D_800D2760.unk2A & 1) {
                    var_a2 = -1;
                } else {
                    var_a2 = 0;
                }
                if (D_800D2760.unk2A & 8) {
                    var_v1 = -1;
                } else {
                    var_v1 = 0;
                }
                // FAKE: the discarded 0 operand gives the shift count its own vreg; without it
                // uopt emits the outer addu with the third masked term first.
                var_a0 = ((u32) ((var_v1 & temp_v0) + (sp4C[0] & var_a2) + (sp4C[1] & var_a1)) >> ((0, 5))) * (D_800D2B18 + 1);
            } else {
                var_a0 = 0;
            }
            *arg0 = var_a0;
            var_s1 += 1;
            arg0 += 1;
            var_s2 += 1;
            var_fs0 += D_800D2B1C;
        } while (var_s1 != arg1);
    }
    return arg1;
}
/* mkdraft:func_80031C84 end */

void func_80031E6C(u16 arg0) {
    while (D_800D27C0[D_800D2AE0].limit >= arg0) {
        D_800D27C0[D_800D2AE0].ptr[0] = D_800D27C0[D_800D2AE0].value;
        D_800D27C0[D_800D2AE0].ptr[1] = 1;
        D_800D2AE0++;
        if ((u32)D_800D2AE0 >= 100U) D_800D2AE0 -= 100;
    }
}

// Game Boy channel 1 (pulse with sweep) sample renderer; sibling of GbAudio_RenderPulse2.
#define P1 D_800D26B0
#define GB_REG(n) (((u8 *)&D_800D2760)[(n) * 2])
#define GB_DIRTY(n) (((u8 *)&D_800D2760)[(n) * 2 + 1])

s16 func_80031F00(void) {
    u32 i;
    s32 changed;
    s32 freqChanged;
    s32 nr11;
    u8 phase;
    u16 freq;
    s16 out;

    changed = 0;
    freqChanged = 0;
    for (i = 0; i < 5; i++) {
        if (GB_DIRTY(i) == 0) {
            continue;
        }
        changed = 1;
        if (i == 3 || i == 4) {
            freqChanged = 1;
        }
        GB_DIRTY(i) = 0;
    }

    if (changed) {
        if (freqChanged) {
            P1.freq = ((u16)(GB_REG(4) & 7) << 8) | GB_REG(3);
            P1.period = ((0x800 - P1.freq) * D_800D275C) >> 11;
        }
        switch ((GB_REG(1) & 0xC0) >> 6) {
            case 0:
                P1.duty_ticks[1] = P1.period >> 3;
                if (P1.duty_ticks[1] < 64) {
                    P1.duty_ticks[1] = 64;
                }
                phase = 1;
                P1.duty_ticks[0] = P1.period - P1.duty_ticks[1];
                goto duty_done;
            case 1:
                P1.duty_ticks[1] = P1.period >> 2;
                if (P1.duty_ticks[1] < 64) {
                    P1.duty_ticks[1] = 64;
                }
                phase = 0;
                P1.duty_ticks[0] = P1.period - P1.duty_ticks[1];
                goto duty_done;
            case 2:
                P1.duty_ticks[1] = P1.period >> 1;
                if (P1.duty_ticks[1] < 64) {
                    P1.duty_ticks[1] = 64;
                }
                phase = 0;
                P1.duty_ticks[0] = P1.period - P1.duty_ticks[1];
                goto duty_done;
            case 3:
                P1.duty_ticks[0] = P1.period >> 2;
                if (P1.duty_ticks[0] < 64) {
                    P1.duty_ticks[0] = 64;
                }
                phase = 1;
                P1.duty_ticks[1] = P1.period - P1.duty_ticks[0];
                goto duty_done;
        }
        P1.duty_ticks[1] = 0;
        phase = 1;
        P1.duty_ticks[0] = P1.period;
    duty_done:

        if (!(GB_REG(2) & 8) && !(GB_REG(2) & 0xF0)) {
            P1.enabled = 0;
            D_800D2760.unk2C &= 0xFFFE;
            return 0;
        }
        if ((GB_REG(2) & 8) && !(GB_REG(2) & 0xF0) && !(GB_REG(2) & 7)) {
            P1.enabled = 0;
            D_800D2760.unk2C &= 0xFFFE;
            return 0;
        }

        if (GB_REG(4) & 0x80) {
            P1.time = 0;
            P1.enabled = 1;
            P1.phase = phase;
            P1.unk20 = 0;
            P1.nextPhase = 0;
            P1.volume = (u8)(GB_REG(2) & 0xF0) << 7;
            if (GB_REG(2) & 7) {
                if (GB_REG(2) & 8) {
                    P1.step = 0x800;
                } else {
                    P1.step = -0x800;
                }
                P1.envNext = P1.envPeriod = (GB_REG(2) & 7) * D_800D275C;
            } else {
                P1.step = 0;
                P1.envPeriod = -1;
                P1.envNext = -1;
            }
            P1.sweepPeriod = (((GB_REG(0) & 0x70) >> 4) * D_800D275C) >> 1;
            P1.sweepNext = P1.time + P1.sweepPeriod;
            if (P1.sweepPeriod == 0) {
                P1.sweepPeriod = -1;
                P1.sweepNext = -1;
            }
            if (GB_REG(4) & 0x40) {
                P1.length = ((64 - (GB_REG(1) & 0x3F)) * D_800D275C) >> 2;
            } else {
                P1.length = -1;
            }
            GB_REG(4) &= ~0x80;
        }
        if (P1.enabled == 0) {
            return 0;
        }
    } else if (P1.enabled == 0) {
        return 0;
    }

    if (P1.length < P1.time) {
        P1.enabled = 0;
        D_800D2760.unk2C &= 0xFFFE;
        return 0;
    }

    if (P1.sweepNext <= P1.time) {
        P1.sweepNext += P1.sweepPeriod;
        if (!(GB_REG(0) & 8)) {
            freq = P1.freq + (P1.freq >> (GB_REG(0) & 7));
            if (freq >= 0x800) {
                P1.enabled = 0;
                D_800D2760.unk2C &= 0xFFFE;
                return 0;
            }
            P1.freq = freq;
        } else {
            freq = P1.freq - (P1.freq >> (GB_REG(0) & 7));
            if (freq >= 0x800 || freq < 0) {
                goto skip;
            }
            P1.freq = freq;
        }
        P1.period = ((0x800 - P1.freq) * D_800D275C) >> 11;
        switch ((GB_REG(1) & 0xC0) >> 6) {
            case 0:
                P1.duty_ticks[1] = P1.period >> 3;
                if (P1.duty_ticks[1] < 64) {
                    P1.duty_ticks[1] = 64;
                }
                P1.duty_ticks[0] = P1.period - P1.duty_ticks[1];
                break;
            case 1:
                P1.duty_ticks[1] = P1.period >> 2;
                if (P1.duty_ticks[1] < 64) {
                    P1.duty_ticks[1] = 64;
                }
                P1.duty_ticks[0] = P1.period - P1.duty_ticks[1];
                break;
            case 2:
                P1.duty_ticks[1] = P1.period >> 1;
                if (P1.duty_ticks[1] < 64) {
                    P1.duty_ticks[1] = 64;
                }
                P1.duty_ticks[0] = P1.period - P1.duty_ticks[1];
                break;
            case 3:
                P1.duty_ticks[0] = P1.period >> 2;
                if (P1.duty_ticks[0] < 64) {
                    P1.duty_ticks[0] = 64;
                }
                P1.duty_ticks[1] = P1.period - P1.duty_ticks[0];
                break;
            default:
                P1.duty_ticks[1] = 0;
                P1.duty_ticks[0] = P1.period;
        }
    }
skip:

    if (P1.envNext < P1.time) {
        P1.volume += P1.step;
        P1.envNext += P1.envPeriod;
    }
    while (P1.nextPhase < P1.time) {
        P1.phase ^= 1;
        P1.nextPhase += P1.duty_ticks[P1.phase];
    }

    if (!(GB_REG(2) & 8) && (P1.volume < 0)) {
        P1.enabled = 0;
        return 0;
    }
    if ((u16)P1.volume > 0x7800) {
        P1.volume = 0x7800;
        P1.step = 0;
        P1.envNext = -1;
    }
    out = P1.volume;
    if (P1.phase == 0) {
        out = -out;
    }
    P1.time += 64;
    return out;
}

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/325D0/func_80032A28.s")

#endif
