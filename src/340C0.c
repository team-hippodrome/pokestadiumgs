#include "229E0.h"

#ifdef VERSION_US

void GbAudio_UpdateSquare1Registers(u8 channel) {
    if ((&D_800D2B78 + channel * 0x3C)[0x14] & 8) {
        GbAudio_QueueRegisterWrite(0xFF10, (u8)D_800D2B4B, 0);
    }
    if ((&D_800D2B78 + channel * 0x3C)[0x14] & 0x20) {
        u8 value;
        value = GbAudio_GetRegisterValue(0xFF26);
        value &= 0x8E;
        GbAudio_QueueRegisterWrite(0xFF26, value, 0);
        GbAudio_QueueChannelReset(0xFF10);
    } else if ((&D_800D2B78 + channel * 0x3C)[0x14] & 0x10) {
        GbAudio_QueueRegisterWrite(0xFF11, ((u8)D_800D2B42 | 0x3F) & 0xFF, 0);
        GbAudio_QueueRegisterWrite(0xFF12, D_800D2B43, 0);
        GbAudio_QueueRegisterWrite(0xFF13, D_800D2B44 & 0xFF, 0);
        GbAudio_QueueRegisterWrite(0xFF14, ((D_800D2B44 >> 8) | 0x80) & 0xFF, 0);
    } else {
        if ((&D_800D2B78 + channel * 0x3C)[0x14] & 2) {
            u8 lowByte = D_800D2B44 & 0xFF;
            GbAudio_QueueRegisterWrite(0xFF13, lowByte, 0);
            GbAudio_QueueRegisterWrite(0xFF14, (D_800D2B44 >> 8) & 0xFF, 0);
        }
        if ((&D_800D2B78 + channel * 0x3C)[0x14] & 1) {
            u8 value;
            value = GbAudio_GetRegisterValue(0xFF11);
            value &= 0x3F;
            value |= (u8)D_800D2B42;
            GbAudio_QueueRegisterWrite(0xFF11, value & 0xFF, 0);
        }
    }
}

void func_8003364C(s32 arg0) { s32 *p = &arg0; GbAudio_UpdateSquare2Registers(arg0 & 0xFF); }

void GbAudio_UpdateSquare2Registers(u8 channel)
{
  s32 flags = (&D_800D2B8C)[channel * 0x3C];
  if (flags & 0x20)
  {
    s32 value;
    value = GbAudio_GetRegisterValue(0xFF26);
    value &= 0x8D;
    GbAudio_QueueRegisterWrite(0xFF26, value, 0);
    GbAudio_QueueChannelReset(0xFF15);
  }
  else
    if (flags & 0x10)
  {
    GbAudio_QueueRegisterWrite(0xFF16, (((u8) D_800D2B42) | 0x3F) & 0xFF, 0);
    GbAudio_QueueRegisterWrite(0xFF17, D_800D2B43, 0);
    GbAudio_QueueRegisterWrite(0xFF18, D_800D2B44 & 0xFF, 0);
    GbAudio_QueueRegisterWrite(0xFF19, ((D_800D2B44 >> 8) | 0x80) & 0xFF, 0);
  }
  else
    if (flags & 0x40)
  {
    u8 lowByte;
    u8 value;
    value = GbAudio_GetRegisterValue(0xFF16);
    value = value & 0x3F;
    value = value | ((u8) D_800D2B42);
    GbAudio_QueueRegisterWrite(0xFF16, value & 0xFF, 0);
    lowByte = D_800D2B44 & 0xFF;
    GbAudio_QueueRegisterWrite(0xFF18, lowByte, 0);
  }
  else
    if (flags & 1)
  {
    u8 value;
    value = GbAudio_GetRegisterValue(0xFF16);
    value &= 0x3F;
    value |= (u8)D_800D2B42;
    GbAudio_QueueRegisterWrite(0xFF16, value & 0xFF, 0);
  }
}

void func_800337D8(s32 arg0) { s32 *p = &arg0; func_80033864(arg0 & 0xFF); }

void func_800337FC(void) {
    s32 var_s0;

    var_s0 = 0x20;
    do {
        GbAudio_QueueRegisterWrite(var_s0, 0, 0);
        var_s0 += 1;
    } while (var_s0 != 0x30);
    GbAudio_QueueRegisterWrite(0xFF1C, ((D_800D2B43 & 0xF0) * 2) & 0xFF, 0);
}

void func_80033864(s32 arg0) {}

void func_8003386C(s32 arg0) { s32 *p = &arg0; GbAudio_UpdateNoiseRegisters(arg0 & 0xFF); }

void GbAudio_UpdateNoiseRegisters(u8 channel) {
    s32 flags = (&D_800D2B8C)[channel * 0x3C];
    if (flags & 0x20) {
        s32 value;
        value = GbAudio_GetRegisterValue(0xFF26);
        value &= 0x87;
        GbAudio_QueueRegisterWrite(0xFF26, value, 0);
        GbAudio_QueueChannelReset(0xFF1F);
    } else if (flags & 0x10) {
        GbAudio_QueueRegisterWrite(0xFF20, 0x3F, 0);
        GbAudio_QueueRegisterWrite(0xFF21, D_800D2B43, 0);
        GbAudio_QueueRegisterWrite(0xFF22, D_800D2B44 & 0xFF, 0);
        GbAudio_QueueRegisterWrite(0xFF23, 0x80, 0);
    }
}

extern u8 D_800D2C6B;
extern u8 D_800D2CA7;
extern u8 D_800D2CE3;
extern u8 D_800D2D1F;
s32 func_80033950(void) {
    if (D_800D2C6B & 1) {
        return 1;
    }
    if (D_800D2CA7 & 1) {
        return 1;
    }
    if (D_800D2CE3 & 1) {
        return 1;
    }
    if (D_800D2D1F & 1) {
        return 1;
    }
    return 0;
}

void func_800339CC(void) {
}

void func_800339D4(void) {
}

void func_800339DC(u8 arg0) {}

void func_800339E4(void) {
}

void func_800339EC(u8 arg0) { if ((s32)(&D_800D2B78 + arg0 * 0x3C)[4] & 4) { func_80033A78(arg0); } if ((s32)(&D_800D2B78 + arg0 * 0x3C)[4] & 0x10) { func_80033ACC(arg0); } if ((s32)(&D_800D2B78 + arg0 * 0x3C)[4] & 1) { func_80033B04(arg0); } }

void func_80033A78(u8 arg0) {
    s32 value;
    s32 offset;
    s32 high;

    offset = arg0 * 0x3C;
    value = (&D_800D2B78)[offset + 0x25];
    high = (value & 0xC0) >> 6;
    value <<= 2;
    value |= high;
    (&D_800D2B78)[offset + 0x25] = value;
    value &= 0xC0;
    D_800D2B42 = value;
    (&D_800D2B78)[offset + 0x14] |= 1;
}

void func_80033ACC(u8 arg0) {
    D_800D2B44 += *(s16 *)((u8 *)&D_800D2BA8 + (arg0 * 0x3C));
}


/* mkdraft:func_80033B04 begin */
extern u8 D_800D2B78;
extern u16 D_800D2B44;



void func_80033B04(u8 arg0) {
    u8 period;
    s32 step;
    u8 sweep;
    s32 limit;
    u8 direction;

    if ((&D_800D2B78 + arg0 * 0x3C)[0x26] != 0) {
        (&D_800D2B78 + arg0 * 0x3C)[0x26]--;
        return;
    }
    step = (&D_800D2B78 + arg0 * 0x3C)[0x28];
    if (step == 0) {
        return;
    }
    sweep = (&D_800D2B78 + arg0 * 0x3C)[0x29];
    period = sweep >> 4;
    if ((sweep & 0xF) != 0) {
        (&D_800D2B78 + arg0 * 0x3C)[0x29]--;
        return;
    }
    (&D_800D2B78 + arg0 * 0x3C)[0x29] = period | sweep;
    limit = (s32)((u8 *)&D_800D2B44)[1];
    direction = (&D_800D2B78 + arg0 * 0x3C)[5];
    if ((&D_800D2B78 + arg0 * 0x3C)[5] & 1) {
        (&D_800D2B78 + arg0 * 0x3C)[5] = direction & (~1);
        step = (u8)(step & 0xF);
        if (step < limit) {
            limit = (limit - step) & 0xFF;
        } else {
            limit = 0;
        }
    } else {
        (&D_800D2B78 + arg0 * 0x3C)[5] = direction | 1;
        step = (((u32)((step & 0xF0) & 0xFF)) >> 4) & 0xFF;
        if (step >= 0x100) {
            limit = 0xFF;
        } else {
            limit = step & 0xFF;
        }
    }
    D_800D2B44 = limit;
    (&D_800D2B78 + arg0 * 0x3C)[0x14] |= 0x40;
}
/* mkdraft:func_80033B04 end */

void func_80033BF4(u8 index) {
    if ((&D_800D2B78 + index * 0x3C)[4] & 2) {
        func_80033C40(index);
    }
}

void func_80033C40(s32 arg0) {}

void func_80033C48(s32 arg0) {}

void func_80033C50(s32 arg0) {}

void func_80033C58(u8 arg0) {
    if (arg0 != 4) return;
    *(s16 *)((u8 *)&D_800D2B78 + 0x15C) = 0;
    *(s16 *)((u8 *)&D_800D2B78 + 0x1D4) = 0;
    D_800D2B49 = D_800D2B68;
    D_800D2B68 = 0;
    D_800D2B6A = 0;
}

void GbAudio_ProcessChannelStream(u8 channel) {
    GbAudioStreamRecord *record = (GbAudioStreamRecord *)&D_800D2B78 + channel;
    s32 value;
    u8 command;
    u8 high;
    while (1) {
        value = (command = func_800347E8(channel));
        if (value == 0xFF) {
            if (record->flags_03 & 2) {
                goto dispatch_command;
            }
            if (!(channel < 4 && (D_800D2C6B & 1))) {
                if (record->flags_03 & 0x20) {
                    func_80033C58(channel);
                }
                if (channel == 4) {
                    GbAudio_QueueRegisterWrite(0xFF10, 0, 0);
                }
            }
            record->flags_03 &= 0xFFFE;
            record->flags_14 |= 0x20;
            record->unk_00 = 0;
            record->unk_02 = 0;
            return;
        }
        if (value >= 208) {
        dispatch_command:
            func_80033ED8(channel, command);
            continue;
        }
        if ((record->flags_03 & 8) || (record->flags_03 & 0x20)) {
            GbAudio_ReadChannelParameters(channel, command);
        } else if (record->flags_03 & 0x10) {
            func_80033ED0();
        } else {
            func_800348C4(channel, command & 0xF);
            high = (command >> 4) & 0xF;
            if (high == 0) {
                record->flags_14 |= 0x20;
            } else {
                record->unk_1A = high;
                record->unk_18 = func_80034838(channel, high, record->unk_1B);
                record->flags_14 |= 0x10;
                func_800339DC(channel);
            }
        }
        return;
    }
}

void GbAudio_ReadChannelParameters(u8 channel, u8 value) {
    u8 high;
    u8 *record = &D_800D2B78 + channel * 0x3C;
    record[0x14] |= 0x10;
    func_800348C4(channel, value);
    record[0x17] = func_800347E8(channel);
    *(u16 *)(record + 0x18) = func_800347E8(channel);
    if (((u32)channel & 3) != 3) {
        high = func_800347E8(channel);
        *(u16 *)(record + 0x18) = *(u16 *)(record + 0x18) + (high << 8);
    }
}

void func_80033ED0(void) {
}

void func_80033ED8(u8 a, u8 b) {
    D_800921E4[b](a, b);
}

void func_80033F14(s32 arg0, s32 arg1) {}

void func_80033F20(u8 arg0, u8 arg1) {
    u8 *entry;

    entry = &D_800D2B78 + (arg0 * 0x3C);
    entry[3] &= 0xFFFD;
    *(s32 *)(entry + 8) = *(s32 *)(entry + 0xC);
}

void func_80033F5C(s32 arg0, s32 arg1) {}

void func_80033F68(s32 arg0, s32 arg1) {}

extern u8 func_800347E8(u8 arg0);
void func_80033F74(u8 channel, u8 arg1) {
    u8 *entry;

    arg1 = func_800347E8(channel);
    entry = &D_800D2B78 + (channel * 0x3C);
    if (!(entry[3] & 4)) {
        if (arg1 != 0) {
            arg1--;
            entry[3] |= 4;
            entry[0x20] = arg1;
        } else {
            *(s32 *)(entry + 8) = *(s32 *)(entry + 8) - func_800347E8(channel) - 1;
            return;
        }
    }
    if (entry[0x20] == 0) {
        entry[3] &= 0xFFFB;
        *(s32 *)(entry + 8) += 1;
    } else {
        entry[0x20]--;
        *(s32 *)(entry + 8) = *(s32 *)(entry + 8) - func_800347E8(channel) - 1;
    }
}

void func_80034058(u8 arg0, s32 arg1) {
    *(&D_800D2B8D + (arg0 * 0x3C)) = func_800347E8(arg0);
}

void func_80034098(s32 arg0, s32 arg1) {}

void func_800340A4(s32 arg0, s32 arg1) {}

void func_800340B0(s32 arg0, s32 arg1) {
    D_800D2B69 = 1;
}

void func_800340C8(u8 arg0, s32 arg1) {
    s32 result;
    u8 *record;

    result = func_800347E8(arg0);
    record = &D_800D2B78 + arg0 * 0x3C;
    record[0x35] = result;
    record[4] |= 8;
}

void GbAudio_ReadPackedChannelParameters(u8 channel, u8 high) {
    u8 value;
    (&D_800D2B78 + channel * 0x3C)[4] |= 1;
    (&D_800D2B78 + channel * 0x3C)[5] &= ~1;
    value = func_800347E8(channel);
    (&D_800D2B78 + channel * 0x3C)[0x27] = value;
    (&D_800D2B78 + channel * 0x3C)[0x26] = value;
    value = func_800347E8(channel);
    high = (u8)((value & 0xF0U) >> 4);
    value &= 0xF;
    {
        u8 shifted = (u32)high >> 1;
        u8 wrapped = high & 1;
        wrapped <<= 4;
        (&D_800D2B78 + channel * 0x3C)[0x28] = shifted | wrapped;
    }
    {
        u8 repeated;
        repeated = value << 4;
        (&D_800D2B78 + channel * 0x3C)[0x29] = value | repeated;
    }
}

void func_800341BC(s32 arg0, s32 arg1) {}

void AudioSeq_ReadWordParameter(u8 channel, s32 unused) {
    u8 high;
    u8 low;
    ((ChannelWordRecord *)(&D_800D2B78 + channel * 0x3C))->flags |= 0x10;
    high = func_800347E8(channel);
    low = func_800347E8(channel);
    ((ChannelWordRecord *)(&D_800D2B78 + channel * 0x3C))->value = (high << 8) + low;
}

void func_80034238(unsigned char arg0, s32 arg1)
{
  arg0 &= 0xFF;
  ((u8 *)&D_800D2B78 + (arg0 * 0x3C))[4] |= 0x40;
  ((u8 *)&D_800D2B78 + (arg0 * 0x3C))[0x32] = func_800347E8(arg0);
}

void func_8003428C(u8 index, s32 unused) {
    u8 result;
    (&D_800D2B78 + index * 0x3C)[4] |= 4;
    result = func_800347E8(index);
    result = (u8)((u32)result >> 2) | (u8)((result << 1) << 5);
    (&D_800D2B78 + index * 0x3C)[0x25] = result;
    (&D_800D2B78 + index * 0x3C)[0x16] = result & 0xC0;
}

void func_800342F4(char arg0, s32 arg1)
{
  arg0 &= 0xFF;
  ((u8 *)&D_800D2B78 + (arg0 * 0x3C))[4] |= 0x20;
  ((u8 *)&D_800D2B78 + (arg0 * 0x3C))[0x33] = func_800347E8(arg0);
}

void func_80034348(u8 arg0, s32 arg1) {
    u8 *ptr;
    s32 value;

    ptr = &D_800D2B78 + arg0 * 0x3C;
    value = ptr[3];
    if (value & 8) {
        ptr[3] = value & ~8;
        return;
    }
    ptr[3] = value | 8;
}

void func_80034394(u8 arg0, s32 arg1) {
    u8 *entry;

    entry = &D_800D2B78 + (arg0 * 0x3C);
    if (entry[3] & 0x10) {
        entry[3] = entry[3] & 0xFFEF;
    } else {
        entry[3] = entry[3] & 0xFFEF;
        D_800D2B56 = func_800347E8(arg0);
    }
}

void func_800343FC(u8 arg0, s32 arg1) {
    u8 *entry;

    entry = &D_800D2B78 + (arg0 * 0x3C);
    if (entry[3] & 0x10) {
        entry[3] = entry[3] & 0xFFEF;
    } else {
        entry[3] = entry[3] & 0xFFEF;
        D_800D2B57 = func_800347E8(arg0);
    }
}

void func_80034464(u8 arg0, u8 arg1) {
    s8 result = func_800347E8(arg0);
    D_800D2BAE[arg0 * 0x3C] = result;
    if ((arg0 & 3) != 3) {
        func_8003455C(arg0, arg1);
    }
}

void func_800344C4(u8 arg0, s32 arg1) {
    void *temp_v1;

    D_800D2B4B = func_800347E8(arg0);
    temp_v1 = (arg0 * 0x3C) + &D_800D2B78;
    (*(u8 *)((u8 *)(temp_v1) + (0x14))) = (u8) ((*(u8 *)((u8 *)(temp_v1) + (0x14))) | 8);
}

void func_80034518(u8 arg0, s32 arg1)
{
  unsigned char new_var;
  new_var = (s8)func_800347E8(arg0);
  (&D_800D2B8E)[0x3C * arg0] = (new_var << 1) << 5;
}

void func_8003455C(u8 arg0, s32 arg1) {
    *(&D_800D2B8F + (arg0 * 0x3C)) = func_800347E8(arg0);
}

void func_8003459C(u8 arg0, s32 arg1) {
    struct { u8 pad[7]; u8 hi; } temp;
    s32 low;
    temp.hi = func_800347E8(arg0);
    low = func_800347E8(arg0);
    func_8003492C(arg0, (u16)((temp.hi << 8) + low));
}

void func_800345E8(s32 arg0, s32 arg1) {
    s32 *p0 = &arg0;
    s32 *p1 = &arg1;
    arg0 = *p0 & 0xFF;
    *(u8 *)(D_800D2B93 + (arg0 * 0x3C)) = *p1 & 7;
}

void func_80034614(u8 arg0, s32 arg1) {
    *(&D_800D2B94 + (arg0 * 0x3C)) = func_800347E8(arg0);
}

void func_80034654(u8 arg0, u8 arg1) {
    if (D_80092520 & 0x20) {
        func_800346A4(arg0, arg1);
    } else {
        func_800347E8(arg0);
    }
}

void func_800346A4(u8 arg0, u8 arg1) {
    extern void func_80034A50(u8);
    func_80034A50(arg0);
    (&D_800D2B78 + arg0 * 0x3C)[0x24] &= func_800347E8(arg0);
}

void func_800346F8(u8 arg0, s32 arg1) {
    s8 result = func_800347E8(arg0);
    if (D_800D2B59 == 0) D_800D2B49 = result;
}

void func_80034738(u8 arg0, s32 arg1) {
    s32 result = func_800347E8(arg0);
    u16 value = result;
    if (result >= 0x80) value = result + 0xFF00;
    value += *(u16 *)((u8 *)&D_800D2B9A + arg0 * 0x3C);
    func_8003492C(arg0, value);
}

void func_800347A4(s32 arg0, s32 arg1) {
    D_800D2B6A = 1;
}

void func_800347BC(s32 arg0, s32 arg1) {
    D_800D2B6A = 0;
}

void func_800347D0(s32 arg0, s32 arg1) { }

void func_800347DC(s32 arg0, s32 arg1) { }

u8 func_800347E8(u8 arg0) {
    u8 *entry = &D_800D2B78 + arg0 * 0x3C;
    u8 result = func_80034D98(*(const u8 **)(entry + 8));
    *(u8 **)(entry + 8) += 1;
    return result;
}

/* mkdraft:func_80034838 begin */
extern u16 D_800925EC[];



s32 func_80034838(u8 arg0, u8 arg1, u8 arg2)
{
  u8 shift;
  u16 index;
  u16 value;
  u32 i;
  u16 bit;
  shift = ((u32) ((&D_800D2B94)[arg0 * 0x3C] & 0xFF)) >> 4;
  shift = shift + arg2;
  index = (&D_800D2B94)[arg0 * 0x3C] & 0xF;
  index = index + arg1;
  value = D_800925EC[index];
  for (i = shift; i < 7U; i++)
  {
    bit = value;
    bit = bit & 0x8000;
    value = ((u32) value) >> 1;
    value = value | bit;
  }
}
/* mkdraft:func_80034838 end */

void func_800348C4(u8 arg0, u8 arg1)
{
  u8 product;
  u32 value;
  u8 *entry;
  arg1++;
  product = (*(((&D_800D2B78) + (arg0 * 0x3C)) + 0x36)) * arg1;
  entry = (&D_800D2B78) + (arg0 * 0x3C);
  value = (product * (*((u16 *) (entry + 0x22)))) + entry[0x1E];
  entry[0x1E] = value;
  entry[0x1D] = (((unsigned short) value) & 0xFF00) >> 8;
}

void func_8003492C(u8 arg0, u16 arg1) {
    u32 first;
    u32 last;
    u32 i;
    u8 *record;

    if (arg0 >= 4) {
        first = 4;
        last = 7;
    } else {
        first = 0;
        last = 3;
    }
    for (i = first; i <= last; i++) {
        record = (u8 *)&D_800D2B78 + i * 0x3C;
        *(u16 *)(record + 0x22) = arg1;
        record[0x1E] = 0;
    }
}

void func_80034A08(u8 arg0) {
    void *temp_v0;

    func_80034A50(arg0);
    temp_v0 = (arg0 * 0x3C) + &D_800D2B78;
    (*(u8 *)((u8 *)(temp_v0) + (3))) = (u8) ((*(u8 *)((u8 *)(temp_v0) + (3))) | 1);
}

void func_80034A50(u8 arg0) {
    u8 *table;
    u8 offset;

    table = func_80034DA0();
    offset = arg0 & 3;
    D_800D2B9C[arg0 * 0x3C] = *(offset + table);
}

void func_80034A94(u16 arg0) {
    func_800331C8();
    D_800D2B4C = arg0;
}

void GbAudio_StartSequence(u16 sequence, u16 parameter, u16 volume)
{
  OSIntMask saved;
  const u8 *header;
  const u8 *entry;
  u8 count;
  u32 i;
  saved = osSetIntMask(0x00000001);
  func_800331C8();
  osSetIntMask(saved);
  GbAudio_QueueRegisterWrite(0xFF26, 0x8F, 0);
  header = D_80094454[sequence];
  count = ((func_80034CF8(header) >> 6) & 3) + 1;
  i = 0;
  if (count != 0)
  {
    entry = header;
    do
    {
      u8 channel = GbAudio_StartSequenceChannel(entry);
      u8 *record = (&D_800D2B78) + (channel * 0x3C);
      *((u16 *) (record + 0x30)) = parameter;
      saved = channel;
      record[3] |= 0x20;
      record[4] |= 0x10;
      if ((s32)(saved & 3) < 3)
      {
        *((u16 *) (((&D_800D2B78) + (channel * 0x3C)) + 0x22)) = volume;
      }
      func_80034A08(channel);
      entry += 8;
      i++;
    }
    while (i < count);
  }
  if (D_800D2B68 == 0)
  {
    D_800D2B68 = D_800D2B49;
    D_800D2B49 = 0x77;
  }
  D_800D2B6A = 1;
  saved = osSetIntMask(0x00000001);
  func_800331B8();
  osSetIntMask(saved);
}

void func_80034C48(s32 arg0) { }

void func_80034C50(s32 arg0) { }

u8 GbAudio_StartSequenceChannel(const u8 *command) {
    u8 value;
    u8 channel;
    u8 *record;
    value = func_80034CF8(command);
    channel = value & 7;
    record = &D_800D2B78 + channel * 0x3C;
    record[3] &= ~1;
    func_80032E40(channel);
    record = &D_800D2B78 + channel * 0x3C;
    *(u16 *)(record + 0x22) = 0x100;
    record[0x36] = 1;
    *(u32 *)(record + 8) = *(const u32 *)(command + 4);
    *(u16 *)record = D_800D2B4C;
    record[2] = D_800D2B4E;
    return channel;
}

u8 func_80034CF8(const u8 *arg0) { return arg0[0]; }

void GbAudio_QueueChannelReset(u16 address) {
    GbAudio_QueueRegisterWrite(address++, 0, 0);
    GbAudio_QueueRegisterWrite(address++, 0, 0);
    GbAudio_QueueRegisterWrite(address++, 8, 0);
    GbAudio_QueueRegisterWrite(address++, 0, 0);
    GbAudio_QueueRegisterWrite(address, 128, 0);
}

u8 func_80034D98(const u8 *arg0) { return arg0[0]; }

 u8 *func_80034DA0(void) { if (D_80092520 & 0x20) return D_800925E8; return D_800925E4; }

 void func_80034DD0(void) { GbAudio_ResetState(); }

 void func_80034DF0(void) { func_800331D4(); }

u8 func_80034E10(const u8 *arg0, s32 unused) { return arg0[0]; }

void func_80034E1C(u16 arg0) {
    if (arg0 & 0xFF) {
        func_80034A94(arg0);
    } else {
        GbAudio_ResetState();
    }
}

void func_80034E5C(s32 arg0, s32 arg1)
{
    s32 *input;
    Func80034E5CRecord *record;
    input = &arg0;
    arg1 = *input & 0xFFFF;
    record = &D_80092620[arg1];
    GbAudio_StartSequence(record->unk0, record->unk2, record->unk4);
}

void func_80034EA4(void) { D_800D2B49 = 0x77; }

void func_80034EB4(void) { D_800D2B49 = 0x33; }

 void func_80034EC4(void) { D_800D2B49 = 0; }

void func_80034ED0(void) { D_800D2B59 = 4; }

void func_80034EE0(void) { D_800D2B59 = 0x84; }

void func_80034EF0(s32 arg0)
{
  s32 var_s0;
  var_s0 = arg0 & 0xFF;
  if (var_s0 != 0)
  {
    do
    {
      var_s0 = ((unsigned long) (var_s0 - 1)) & 0xFF;
      func_80034DF0();
    }
    while (var_s0 != 0);
    if (arg0)
    {
    }
  }
}

u8 GbAudio_GetActiveChannelMask(void) {
    u8 mask = 0;
    s32 channel;
    for (channel = 0; channel < 8; channel++) {
        if ((&D_800D2B78 + channel * 0x3C)[3] & 1) {
            mask |= 1 << channel;
        }
    }
    return mask;
}

#endif
