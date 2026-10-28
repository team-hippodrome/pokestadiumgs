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

#pragma GLOBAL_ASM("asm/us/nonmatchings/340C0/func_80033B04.s")

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

#pragma GLOBAL_ASM("asm/us/nonmatchings/340C0/func_80034838.s")

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

#pragma C_FUNCTION_PADDING(12)

void func_80034FE0(void) {
    if ((s8) D_80090B8C != 0) {
        func_80034DF0();
    }
    D_80094570 += 1;
}

void func_80035020(s32 arg0) {
    if (arg0 != 1) {
        D_800D2D78 = osCartRomInit();
    }
    osCreateMesgQueue(&D_800D2D60, &D_800D2D7C, 1);
}

void Audio_ReadRomBlocking(u32 rom, u8 *destination, u32 remaining) {
    OSIoMesg message;
    u32 currentRom = rom;
    u8 *currentDestination = destination;
    u32 chunk;
    while (remaining != 0) {
        if (remaining > 0x4000) chunk = 0x4000;
        else chunk = remaining;
        message.hdr.pri = OS_MESG_PRI_NORMAL;
        message.hdr.retQueue = &D_800D2D60;
        message.dramAddr = currentDestination;
        message.devAddr = currentRom;
        message.size = chunk;
        osInvalDCache(currentDestination, chunk);
        osEPiStartDma(D_800D2D78, &message, OS_READ);
        osRecvMesg(&D_800D2D60, NULL, OS_MESG_BLOCK);
        remaining -= chunk;
        currentRom += chunk;
        currentDestination += chunk;
    }
}

#pragma C_FUNCTION_PADDING(4)

 void func_80035140(s32 value) { D_80094850 = value; }

s32 func_8003514C(void) { return (s32)D_80094850; }

#pragma C_FUNCTION_PADDING(8)

s32 func_80035160(s32 index) { return D_80094870[index]; }

void Audio_ThreadMain(void *unused) {
    OSTask *task;
    s32 tick;
    __osSetFpcCsr(0x01000C01);
    Sched_InitClientQueue(&D_80122B20, 1, 1);
    func_80005568(&D_80122B20);
    D_80122A40 = 1;
    D_80122B18 = 0;
    osCreateMesgQueue(&D_80122A4C, &D_80122A48[0].message, 1);
    osCreateMesgQueue(&D_80122AB4, &D_80122AB0, 1);
    osSendMesg(&D_80122A4C, (OSMesg)0x444F4E45, OS_MESG_NOBLOCK);
    osSendMesg(&D_80122AB4, (OSMesg)0x444F4E45, OS_MESG_NOBLOCK);
    Audio_InitializeTaskState();
    func_80025C50(2);
    while (1) {
        func_80004F34((u8 *)&D_80122B20);
        profiler_log_thread4_time();
        if (D_80122A40 != 0 && *(s16 *)((u8 *)D_800CD020 + 0xA38) < 21) {
            task = (OSTask *)Audio_BuildSchedulerTask();
            if (task != NULL) {
                D_80122A48[D_80122B18].task = *task;
                Sched_SubmitTask(&D_80122A48[D_80122B18], 0);
            }
        }
        D_80122B18 ^= 1;
        profiler_log_thread4_time();
        tick = D_8009486C;
        D_8009486C = tick + 1;
    }
}

void Thread4_CreateThread(void) {
    osCreateThread(&D_80122B20, 4, Audio_ThreadMain, NULL, D_80124D00, 0x50);
    osStartThread(&D_80122B20);
}

void func_8003539C(void) {
    func_80021BBC();
}

s32 Audio_StopProcessing(void) {
    func_80025C9C();
    D_80122A40 = 0;
    return 0;
}

s32 Audio_WaitForPendingTasks(void) {
    s32 completed = 0;

    while (func_80025D44() != 0) {
        completed++;
    }
    return completed;
}

void func_80035424(s32 arg0) {
    s32 value = arg0;
    void *entry = func_80008494();
    if (entry != 0) {
        value = arg0;
        value *= *(s8 *)((u8 *)entry + 0x10);
    }
    func_80025CBC(value);
}

void Audio_SetProcessingEnabled(s32 enabled) { D_80122A40 = enabled ? 0 : 1; }

void Audio_ResetModeSelector(void) {
    D_80094860 = -1;
}

void Audio_EnableModeFlag(void) {
    D_80094868 = 1;
}

s32 Audio_SetModeBlocking(s32 mode, s32 arg1, s32 arg2) {
    s32 changed = 0;
    s32 tick;
    s32 readyTick;
    if (mode == 2) {
        if (D_80094868 != 0) {
            D_80094868 = 0;
            mode = 11;
        }
    }
    if (mode != D_80094860) {
        D_80094860 = mode;
        changed = 1;
        do {
            tick = *(volatile s32 *)&D_8009486C;
            func_8003539C();
            while (tick == *(volatile s32 *)&D_8009486C) {
            }
        } while (func_80025D44() != 0);
        func_800260C0(mode, arg1, arg2);
        while (func_80026298() == 0) {
            readyTick = *(volatile s32 *)&D_8009486C;
            while (readyTick == *(volatile s32 *)&D_8009486C) {
            }
        }
        func_800262F0();
        if (D_80094860 == 11) {
            D_80094860 = 2;
        }
    }
    return changed;
}

void Audio_ResetRequestId(void) {
    D_80094864 = -1;
}

s32 Audio_RequestIfChanged(s32 requestId) {
    if (requestId != D_80094864) {
        D_80094864 = requestId;
        func_80021ED8(requestId);
    }
    return 0;
}

#pragma C_FUNCTION_PADDING(4)

s32 D_80124D00[19];

extern u8 D_437620[];
extern u8 D_437670[];
void func_80035620(void) {
    s32 *src;
    s32 i;

    main_pool_push_state('ROMT');
    src = func_800042C0(D_437620, D_437670, 0, 0);
    for (i = 0; i < 19; i++) {
        D_80124D00[i] = src[i];
    }
    main_pool_pop_state('ROMT');
}

s32 func_800356CC(s32 arg0) { s32 result = 0; if (arg0 >= 0 && arg0 < 19) result = *((s32 *)((u8 *)D_80124D00 + arg0 * 4)); return result; }

#pragma C_FUNCTION_PADDING(12)

void func_80035700(u32 seed) {
    D_80124D50 = seed;
}

u32 func_8003570C(void) {
    D_80124D50 = D_80124D50 * 0x0019660D + 0x3C6EF35F;
    return D_80124D50;
}

Color3573C *Color_SetRGB(Color3573C *arg0, u8 r, u8 g, u8 b) {
    arg0->r = r;
    arg0->g = g;
    arg0->b = b;
    return arg0;
}

Color3575C *Color_SetRGBA(Color3575C *arg0, u8 r, u8 g, u8 b, u8 a) {
    arg0->r = r;
    arg0->g = g;
    arg0->b = b;
    arg0->a = a;
    return arg0;
}

Vec3f35784 *Vec3f_SetComponents(Vec3f35784 *arg0, f32 x, f32 y, f32 z) {
    arg0->x = x;
    arg0->y = y;
    arg0->z = z;
    return arg0;
}

Vec3f357A8 *Vec3f_SetComponentsDuplicate(Vec3f357A8 *arg0, f32 x, f32 y, f32 z) {
    arg0->x = x;
    arg0->y = y;
    arg0->z = z;
    return arg0;
}

Vec3f357CC *Vec3f_AddInPlace(Vec3f357CC *arg0, Vec3f357CC *arg1) {
    arg0->x += arg1->x;
    arg0->y += arg1->y;
    arg0->z += arg1->z;
    return arg0;
}

Vec3f35804 *Vec3f_Add(Vec3f35804 *arg0, Vec3f35804 *arg1, Vec3f35804 *arg2) {
    arg0->x = arg1->x + arg2->x;
    arg0->y = arg1->y + arg2->y;
    arg0->z = arg1->z + arg2->z;
    return arg0;
}

Vec3f3583C *Vec3f_SubtractInPlace(Vec3f3583C *arg0, Vec3f3583C *arg1) {
    arg0->x -= arg1->x;
    arg0->y -= arg1->y;
    arg0->z -= arg1->z;
    return arg0;
}

Vec3f35874 *Vec3f_Subtract(Vec3f35874 *arg0, Vec3f35874 *arg1, Vec3f35874 *arg2) {
    arg0->x = arg1->x - arg2->x;
    arg0->y = arg1->y - arg2->y;
    arg0->z = arg1->z - arg2->z;
    return arg0;
}

Vec3f358AC *Vec3f_FromVec3s(Vec3f358AC *arg0, Vec3s358AC *arg1) {
    arg0->x = arg1->x;
    arg0->y = arg1->y;
    arg0->z = arg1->z;
    return arg0;
}

Vec3f358F0 *Vec3f_CrossProductFromPoints(Vec3f358F0 *arg0, Vec3f358F0 *arg1, Vec3f358F0 *arg2, Vec3f358F0 *arg3) {
    arg0->x = ((arg2->y - arg1->y) * (arg3->z - arg2->z)) - ((arg3->y - arg2->y) * (arg2->z - arg1->z));
    arg0->y = ((arg2->z - arg1->z) * (arg3->x - arg2->x)) - ((arg3->z - arg2->z) * (arg2->x - arg1->x));
    arg0->z = ((arg2->x - arg1->x) * (arg3->y - arg2->y)) - ((arg3->x - arg2->x) * (arg2->y - arg1->y));
    return arg0;
}

Vec3f359A0 *Vec3f_CrossProduct(Vec3f359A0 *out, Vec3f359A0 *a, Vec3f359A0 *b) {
    out->x = (a->y * b->z) - (b->y * a->z);
    out->y = (a->z * b->x) - (b->z * a->x);
    out->z = (a->x * b->y) - (b->x * a->y);
    return out;
}

Vec3f35A10 *func_80035A10(Vec3f35A10 *arg0) {
    f32 scale = 1.0f / sqrtf((arg0->x * arg0->x) + (arg0->y * arg0->y) + (arg0->z * arg0->z));
    arg0->x *= scale; arg0->y *= scale; arg0->z *= scale; return arg0;
}

void *Vec3s_SetComponents(void *arg0, s16 arg1, s16 arg2, s16 arg3) {
    (*(s16 *)((u8 *)(arg0) + (0))) = arg1;
    (*(s16 *)((u8 *)(arg0) + (2))) = arg2;
    (*(s16 *)((u8 *)(arg0) + (4))) = arg3;
    return arg0;
}

Vec3s35AA0 *Vec3s_AddInPlace(Vec3s35AA0 *arg0, Vec3s35AA0 *arg1) {
    arg0->x += arg1->x; arg0->y += arg1->y; arg0->z += arg1->z; return arg0;
}

Vec3s35AD8 *Vec3s_Add(Vec3s35AD8 *arg0, Vec3s35AD8 *arg1, Vec3s35AD8 *arg2) {
    arg0->x = arg1->x + arg2->x; arg0->y = arg1->y + arg2->y; arg0->z = arg1->z + arg2->z; return arg0;
}

Vec3s35B10 *Vec3s_SubtractInPlace(Vec3s35B10 *arg0, Vec3s35B10 *arg1) {
    arg0->x -= arg1->x; arg0->y -= arg1->y; arg0->z -= arg1->z; return arg0;
}

Vec3s35B48 *Vec3s_Subtract(Vec3s35B48 *arg0, Vec3s35B48 *arg1, Vec3s35B48 *arg2) {
    arg0->x = arg1->x - arg2->x; arg0->y = arg1->y - arg2->y; arg0->z = arg1->z - arg2->z; return arg0;
}

Vec3s35B80 *Vec3s_FromVec3f(Vec3s35B80 *arg0, Vec3f35B80 *arg1) {
    arg0->x = ROUND_MAX(arg1->x); arg0->y = ROUND_MAX(arg1->y); arg0->z = ROUND_MAX(arg1->z); return arg0;
}

void MtxF_Copy(u32 *dest, u32 *src) {
    if (dest != src) {
        s32 i; u32 *d = dest; u32 *s = src;
        for (i = 0; i < 16; i++) { *d++ = *s++; }
    }
}

void MtxF_Identity(f32 *arg0) {
    s32 i;
    f32 *dest;
    for (dest = arg0 + 1, i = 0; i < 14; dest++, i++) { *dest = 0.0f; }
    for (dest = arg0, i = 0; i < 4; dest += 5, i++) { *dest = 1.0f; }
}

void MtxF_SetTranslation(f32 *dest, f32 *source) {
    MtxF_Identity(dest);
    dest[12] = source[0];
    dest[13] = source[1];
    dest[14] = source[2];
}

void MtxF_SetLookAt(S1_MtxF *matrix, S1_Vec3f *from, S1_Vec3f *to, s16 view_angle) {
    f32 inverse_length;
    f32 dx;
    f32 dz;
    f32 x_col_y;
    f32 y_col_y;
    f32 z_col_y;
    f32 x_col_z;
    f32 y_col_z;
    f32 z_col_z;
    f32 x_col_x;
    f32 y_col_x;
    f32 z_col_x;

    dx = to->x - from->x;
    dz = to->z - from->z;

    inverse_length = -1.0 / sqrtf(dx * dx + dz * dz);
    dx *= inverse_length;
    dz *= inverse_length;

    y_col_y = D_80088E50[(u16)(view_angle) >> 4];
    x_col_y = D_80087E50[(u16)(view_angle) >> 4] * dz;
    z_col_y = -D_80087E50[(u16)(view_angle) >> 4] * dx;

    x_col_z = to->x - from->x;
    y_col_z = to->y - from->y;
    z_col_z = to->z - from->z;

    inverse_length = -1.0 / sqrtf(x_col_z * x_col_z + y_col_z * y_col_z + z_col_z * z_col_z);
    x_col_z *= inverse_length;
    y_col_z *= inverse_length;
    z_col_z *= inverse_length;

    x_col_x = y_col_y * z_col_z - z_col_y * y_col_z;
    y_col_x = z_col_y * x_col_z - x_col_y * z_col_z;
    z_col_x = x_col_y * y_col_z - y_col_y * x_col_z;

    inverse_length = 1.0 / sqrtf(x_col_x * x_col_x + y_col_x * y_col_x + z_col_x * z_col_x);

    x_col_x *= inverse_length;
    y_col_x *= inverse_length;
    z_col_x *= inverse_length;

    x_col_y = y_col_z * z_col_x - z_col_z * y_col_x;
    y_col_y = z_col_z * x_col_x - x_col_z * z_col_x;
    z_col_y = x_col_z * y_col_x - y_col_z * x_col_x;

    inverse_length = 1.0 / sqrtf(x_col_y * x_col_y + y_col_y * y_col_y + z_col_y * z_col_y);
    x_col_y *= inverse_length;
    y_col_y *= inverse_length;
    z_col_y *= inverse_length;

    matrix->mf[0][0] = x_col_x;
    matrix->mf[1][0] = y_col_x;
    matrix->mf[2][0] = z_col_x;
    matrix->mf[3][0] = -(from->x * x_col_x + from->y * y_col_x + from->z * z_col_x);

    matrix->mf[0][1] = x_col_y;
    matrix->mf[1][1] = y_col_y;
    matrix->mf[2][1] = z_col_y;
    matrix->mf[3][1] = -(from->x * x_col_y + from->y * y_col_y + from->z * z_col_y);

    matrix->mf[0][2] = x_col_z;
    matrix->mf[1][2] = y_col_z;
    matrix->mf[2][2] = z_col_z;
    matrix->mf[3][2] = -(from->x * x_col_z + from->y * y_col_z + from->z * z_col_z);

    matrix->mf[0][3] = 0.0f;
    matrix->mf[1][3] = 0.0f;
    matrix->mf[2][3] = 0.0f;
    matrix->mf[3][3] = 1.0f;
}

void MtxF_SetRotationTranslation(f32 matrix[4][4], Vec3s35AA0 *position, Vec3s35AA0 *rotation) {
    f32 sin_x;
    f32 cos_x;
    f32 sin_y;
    f32 cos_y;
    f32 sin_z;
    f32 cos_z;

    sin_x = D_80087E50[(u16)(rotation->x) >> 4];
    cos_x = D_80088E50[(u16)(rotation->x) >> 4];

    sin_y = D_80087E50[(u16)(rotation->y) >> 4];
    cos_y = D_80088E50[(u16)(rotation->y) >> 4];

    sin_z = D_80087E50[(u16)(rotation->z) >> 4];
    cos_z = D_80088E50[(u16)(rotation->z) >> 4];

    matrix[0][0] = cos_y * cos_z + (sin_x * sin_y) * sin_z;
    matrix[0][1] = -cos_y * sin_z + (sin_x * sin_y) * cos_z;
    matrix[0][2] = cos_x * sin_y;
    matrix[0][3] = position->x;

    matrix[1][0] = cos_x * sin_z;
    matrix[1][1] = cos_x * cos_z;
    matrix[1][2] = -sin_x;
    matrix[1][3] = position->y;

    matrix[2][0] = -sin_y * cos_z + (sin_x * cos_y) * sin_z;
    matrix[2][1] = sin_y * sin_z + (sin_x * cos_y) * cos_z;
    matrix[2][2] = cos_x * cos_y;
    matrix[2][3] = position->z;

    matrix[3][0] = 0.0f;
    matrix[3][1] = 0.0f;
    matrix[3][2] = 0.0f;
    matrix[3][3] = 1.0f;
}

void MtxF_SetRotationTranslationF(f32 matrix[4][4], Vec3f35784 *position, Vec3s35AA0 *rotation) {
    f32 sin_y;
    f32 cos_y;
    f32 sin_z;
    f32 cos_z;
    f32 sin_x;
    f32 cos_x;
    f32 product;

    sin_x = D_80087E50[(u16)(rotation->x) >> 4];
    cos_x = D_80088E50[(u16)(rotation->x) >> 4];

    sin_y = D_80087E50[(u16)(rotation->y) >> 4];
    cos_y = D_80088E50[(u16)(rotation->y) >> 4];

    sin_z = D_80087E50[(u16)(rotation->z) >> 4];
    cos_z = D_80088E50[(u16)(rotation->z) >> 4];

    product = sin_x * sin_y;
    matrix[0][0] = (cos_y * cos_z) + (product * sin_z);
    matrix[1][0] = (-cos_y * sin_z) + (product * cos_z);
    matrix[2][0] = cos_x * sin_y;
    matrix[3][0] = position->x;

    matrix[0][1] = cos_x * sin_z;
    matrix[1][1] = cos_x * cos_z;
    matrix[2][1] = -sin_x;
    matrix[3][1] = position->y;

    product = sin_x * cos_y;
    matrix[0][2] = (-sin_y * cos_z) + (product * sin_z);
    matrix[1][2] = (sin_y * sin_z) + (product * cos_z);
    matrix[2][2] = cos_x * cos_y;
    matrix[3][2] = position->z;

    matrix[0][3] = 0.0f;
    matrix[1][3] = 0.0f;
    matrix[2][3] = 0.0f;
    matrix[3][3] = 1.0f;
}

void MtxF_SetRotationAndTransformTranslation(f32 matrix[4][4], Vec3f35784 *position, Vec3s35AA0 *rotation) {
    f32 sin_x;
    f32 cos_x;
    f32 sin_y;
    f32 cos_y;
    f32 sin_z;
    f32 cos_z;

    sin_x = D_80087E50[(u16)(rotation->x) >> 4];
    cos_x = D_80088E50[(u16)(rotation->x) >> 4];
    sin_y = D_80087E50[(u16)(rotation->y) >> 4];
    cos_y = D_80088E50[(u16)(rotation->y) >> 4];
    sin_z = D_80087E50[(u16)(rotation->z) >> 4];
    cos_z = D_80088E50[(u16)(rotation->z) >> 4];

    matrix[0][0] = (cos_y * cos_z) + ((sin_x * sin_y) * sin_z);
    matrix[0][1] = (-cos_y * sin_z) + ((sin_x * sin_y) * cos_z);
    matrix[0][2] = cos_x * sin_y;

    matrix[1][0] = cos_x * sin_z;
    matrix[1][1] = cos_x * cos_z;
    matrix[1][2] = -sin_x;

    matrix[2][0] = (-sin_y * cos_z) + ((sin_x * cos_y) * sin_z);
    matrix[2][1] = (sin_y * sin_z) + ((sin_x * cos_y) * cos_z);
    matrix[2][2] = cos_x * cos_y;

    matrix[3][0] = (matrix[0][0] * position->x) + (matrix[1][0] * position->y) + (matrix[2][0] * position->z);
    matrix[3][1] = (matrix[0][1] * position->x) + (matrix[1][1] * position->y) + (matrix[2][1] * position->z);
    matrix[3][2] = (matrix[0][2] * position->x) + (matrix[1][2] * position->y) + (matrix[2][2] * position->z);

    matrix[0][3] = matrix[1][3] = matrix[2][3] = 0.0f;
    matrix[3][3] = 1.0f;
}

void MtxF_SetRotationScaleTranslation(S1_MtxF *matrix, S1_Vec3f *position, S1_Vec3s *rotation, S1_Vec3f *scale) {
    f32 sin_x;
    f32 cos_x;
    f32 sin_y;
    f32 cos_y;
    f32 sin_z;
    f32 cos_z;

    sin_x = D_80087E50[(u16)(rotation->x) >> 4];
    cos_x = D_80088E50[(u16)(rotation->x) >> 4];

    sin_y = D_80087E50[(u16)(rotation->y) >> 4];
    cos_y = D_80088E50[(u16)(rotation->y) >> 4];

    sin_z = D_80087E50[(u16)(rotation->z) >> 4];
    cos_z = D_80088E50[(u16)(rotation->z) >> 4];

    matrix->mf[0][0] = (cos_y * cos_z) * scale->x;
    matrix->mf[0][1] = (cos_y * sin_z) * scale->x;
    matrix->mf[0][2] = (-sin_y) * scale->x;
    matrix->mf[0][3] = 0.0f;

    matrix->mf[1][0] = (sin_x * sin_y * cos_z - cos_x * sin_z) * scale->y;
    matrix->mf[1][1] = (sin_x * sin_y * sin_z + cos_x * cos_z) * scale->y;
    matrix->mf[1][2] = (sin_x * cos_y) * scale->y;
    matrix->mf[1][3] = 0.0f;

    matrix->mf[2][0] = (cos_x * sin_y * cos_z + sin_x * sin_z) * scale->z;
    matrix->mf[2][1] = (cos_x * sin_y * sin_z - sin_x * cos_z) * scale->z;
    matrix->mf[2][2] = (cos_x * cos_y) * scale->z;
    matrix->mf[2][3] = 0.0f;

    matrix->mf[3][0] = position->x;
    matrix->mf[3][1] = position->y;
    matrix->mf[3][2] = position->z;
    matrix->mf[3][3] = 1.0f;
}

void MtxF_SetRotationAndScaledTranslation(S1_MtxF *matrix, S1_Vec3f *position, S1_Vec3s *rotation, S1_Vec3f *scale) {
    f32 sin_x;
    f32 cos_x;
    f32 sin_y;
    f32 cos_y;
    f32 sin_z;
    f32 cos_z;

    sin_x = D_80087E50[(u16)(rotation->x) >> 4];
    cos_x = D_80088E50[(u16)(rotation->x) >> 4];

    sin_y = D_80087E50[(u16)(rotation->y) >> 4];
    cos_y = D_80088E50[(u16)(rotation->y) >> 4];

    sin_z = D_80087E50[(u16)(rotation->z) >> 4];
    cos_z = D_80088E50[(u16)(rotation->z) >> 4];

    matrix->mf[0][0] = cos_y * cos_z;
    matrix->mf[0][1] = cos_y * sin_z;
    matrix->mf[0][2] = -sin_y;
    matrix->mf[0][3] = 0.0f;

    matrix->mf[1][0] = sin_x * sin_y * cos_z - cos_x * sin_z;
    matrix->mf[1][1] = sin_x * sin_y * sin_z + cos_x * cos_z;
    matrix->mf[1][2] = sin_x * cos_y;
    matrix->mf[1][3] = 0.0f;

    matrix->mf[2][0] = cos_x * sin_y * cos_z + sin_x * sin_z;
    matrix->mf[2][1] = cos_x * sin_y * sin_z - sin_x * cos_z;
    matrix->mf[2][2] = cos_x * cos_y;
    matrix->mf[2][3] = 0.0f;

    matrix->mf[3][0] = position->x * scale->x;
    matrix->mf[3][1] = position->y * scale->y;
    matrix->mf[3][2] = position->z * scale->z;
    matrix->mf[3][3] = 1.0f;
}

void func_80036714(void *a0,s32 a1,s32 a2,s32 a3,f32 a4){f32 r0,r1,r2; r0=sqrtf(((f32*)a2)[0]*((f32*)a2)[0]+((f32*)a2)[1]*((f32*)a2)[1]+((f32*)a2)[2]*((f32*)a2)[2])*a4;r1=sqrtf(((f32*)a2)[4]*((f32*)a2)[4]+((f32*)a2)[5]*((f32*)a2)[5]+((f32*)a2)[6]*((f32*)a2)[6])*a4;r2=sqrtf(((f32*)a2)[8]*((f32*)a2)[8]+((f32*)a2)[9]*((f32*)a2)[9]+((f32*)a2)[10]*((f32*)a2)[10])*a4;((f32*)a0)[0]=((f32*)a1)[0]*r0;((f32*)a0)[1]=((f32*)a1)[4]*r0;((f32*)a0)[2]=((f32*)a1)[8]*r0;((f32*)a0)[3]=0;((f32*)a0)[4]=((f32*)a1)[1]*r1;((f32*)a0)[5]=((f32*)a1)[5]*r1;((f32*)a0)[6]=((f32*)a1)[9]*r1;((f32*)a0)[7]=0;((f32*)a0)[8]=((f32*)a1)[2]*r2;((f32*)a0)[9]=((f32*)a1)[6]*r2;((f32*)a0)[10]=((f32*)a1)[10]*r2;((f32*)a0)[11]=0;((f32*)a0)[12]=((f32*)a2)[0]*((f32*)a3)[0]+((f32*)a2)[4]*((f32*)a3)[1]+((f32*)a2)[8]*((f32*)a3)[2]+((f32*)a2)[12];((f32*)a0)[13]=((f32*)a2)[1]*((f32*)a3)[0]+((f32*)a2)[5]*((f32*)a3)[1]+((f32*)a2)[9]*((f32*)a3)[2]+((f32*)a2)[13];((f32*)a0)[14]=((f32*)a2)[2]*((f32*)a3)[0]+((f32*)a2)[6]*((f32*)a3)[1]+((f32*)a2)[10]*((f32*)a3)[2]+((f32*)a2)[14];((f32*)a0)[15]=1;}

void MtxF_SetOrthonormalBasis(f32 matrix[4][4], Vec3f35784 *up_direction, Vec3f35784 *position, s32 rotation_y) {
    Vec3f35784 reference;
    Vec3f35784 lateral;
    Vec3f35784 forward;
    Vec3f_SetComponentsDuplicate(&reference, D_80087E50[(u16)rotation_y >> 4], 0.0f, D_80088E50[(u16)rotation_y >> 4]);
    func_80035A10(up_direction);
    Vec3f_CrossProduct(&lateral, up_direction, &reference);
    func_80035A10(&lateral);
    Vec3f_CrossProduct(&forward, &lateral, up_direction);
    func_80035A10(&forward);
    matrix[0][0] = lateral.x;
    matrix[0][1] = lateral.y;
    matrix[0][2] = lateral.z;
    matrix[3][0] = position->x;
    matrix[1][0] = up_direction->x;
    matrix[1][1] = up_direction->y;
    matrix[1][2] = up_direction->z;
    matrix[3][1] = position->y;
    matrix[2][0] = forward.x;
    matrix[2][1] = forward.y;
    matrix[2][2] = forward.z;
    matrix[3][2] = position->z;
    matrix[0][3] = 0.0f;
    matrix[1][3] = 0.0f;
    matrix[2][3] = 0.0f;
    matrix[3][3] = 1.0f;
}

void MtxF_Multiply(S1_MtxF* arg0, S1_MtxF* arg1, S1_MtxF* arg2) {
    f32 entry0;
    f32 entry1;
    f32 entry2;

    entry0 = arg1->mf[0][0];
    entry1 = arg1->mf[0][1];
    entry2 = arg1->mf[0][2];

    arg0->mf[0][0] = (entry0 * arg2->mf[0][0]) + (entry1 * arg2->mf[1][0]) + (entry2 * arg2->mf[2][0]);
    arg0->mf[0][1] = (entry0 * arg2->mf[0][1]) + (entry1 * arg2->mf[1][1]) + (entry2 * arg2->mf[2][1]);
    arg0->mf[0][2] = (entry0 * arg2->mf[0][2]) + (entry1 * arg2->mf[1][2]) + (entry2 * arg2->mf[2][2]);

    entry0 = arg1->mf[1][0];
    entry1 = arg1->mf[1][1];
    entry2 = arg1->mf[1][2];

    arg0->mf[1][0] = (entry0 * arg2->mf[0][0]) + (entry1 * arg2->mf[1][0]) + (entry2 * arg2->mf[2][0]);
    arg0->mf[1][1] = (entry0 * arg2->mf[0][1]) + (entry1 * arg2->mf[1][1]) + (entry2 * arg2->mf[2][1]);
    arg0->mf[1][2] = (entry0 * arg2->mf[0][2]) + (entry1 * arg2->mf[1][2]) + (entry2 * arg2->mf[2][2]);

    entry0 = arg1->mf[2][0];
    entry1 = arg1->mf[2][1];
    entry2 = arg1->mf[2][2];

    arg0->mf[2][0] = (entry0 * arg2->mf[0][0]) + (entry1 * arg2->mf[1][0]) + (entry2 * arg2->mf[2][0]);
    arg0->mf[2][1] = (entry0 * arg2->mf[0][1]) + (entry1 * arg2->mf[1][1]) + (entry2 * arg2->mf[2][1]);
    arg0->mf[2][2] = (entry0 * arg2->mf[0][2]) + (entry1 * arg2->mf[1][2]) + (entry2 * arg2->mf[2][2]);

    entry0 = arg1->mf[3][0];
    entry1 = arg1->mf[3][1];
    entry2 = arg1->mf[3][2];

    arg0->mf[3][0] = (entry0 * arg2->mf[0][0]) + (entry1 * arg2->mf[1][0]) + (entry2 * arg2->mf[2][0]) + arg2->mf[3][0];
    arg0->mf[3][1] = (entry0 * arg2->mf[0][1]) + (entry1 * arg2->mf[1][1]) + (entry2 * arg2->mf[2][1]) + arg2->mf[3][1];
    arg0->mf[3][2] = (entry0 * arg2->mf[0][2]) + (entry1 * arg2->mf[1][2]) + (entry2 * arg2->mf[2][2]) + arg2->mf[3][2];

    arg0->mf[0][3] = arg0->mf[1][3] = arg0->mf[2][3] = 0.0f;
    arg0->mf[3][3] = 1.0f;
}

void MtxF_ScaleRows(S1_MtxF* dest, S1_MtxF* mtx, S1_Vec3f* s) {
    s32 i;

    for (i = 0; i < 4; i++) {
        dest->mf[0][i] = mtx->mf[0][i] * s->x;
        dest->mf[1][i] = mtx->mf[1][i] * s->y;
        dest->mf[2][i] = mtx->mf[2][i] * s->z;
        dest->mf[3][i] = mtx->mf[3][i];
    }
}

void func_80036D8C(f32 *arg0, f32 *arg1) {
    arg1[0] = sqrtf(arg0[0] * arg0[0] + arg0[1] * arg0[1] + arg0[2] * arg0[2]);
    arg1[1] = sqrtf(arg0[4] * arg0[4] + arg0[5] * arg0[5] + arg0[6] * arg0[6]);
    arg1[2] = sqrtf(arg0[8] * arg0[8] + arg0[9] * arg0[9] + arg0[10] * arg0[10]);
}

void MtxF_TransformVec3s(S1_MtxF* arg0, S1_Vec3s* arg1) {
    f32 entry0 = arg1->x;
    f32 entry1 = arg1->y;
    f32 entry2 = arg1->z;

    arg1->x = ((entry0 * arg0->mf[0][0]) + (entry1 * arg0->mf[1][0]) + (entry2 * arg0->mf[2][0])) + arg0->mf[3][0];
    arg1->y = ((entry0 * arg0->mf[0][1]) + (entry1 * arg0->mf[1][1]) + (entry2 * arg0->mf[2][1])) + arg0->mf[3][1];
    arg1->z = ((entry0 * arg0->mf[0][2]) + (entry1 * arg0->mf[1][2]) + (entry2 * arg0->mf[2][2])) + arg0->mf[3][2];
}

void MtxF_ToFixed(void *destination, S1_MtxF *source) {
    s32 converted;
    s32 i;
    // N64 matrices store integer halves before fractional halves.
    s16 *integer = destination;
    s16 *fraction = (s16 *)destination + 16;
    f32 *input = (f32 *)source;
    for (i = 0; i < 16; i++) {
        converted = *input++ * 65536.0f;
        *integer++ = ((s16 *)&converted)[0];
        *fraction++ = ((s16 *)&converted)[1];
    }
}

void MtxF_BuildTransform(S1_MtxF *arg0, S1_Vec3f *arg1, S1_Vec3s *arg2, S1_Vec3f *arg3, S1_MtxF *arg4, S1_MtxF *arg5) {
    S1_MtxF sp60;
    S1_MtxF sp20;

    func_80036714(&sp60, (s32)arg4, (s32)arg5, (s32)arg1, 1.0f);
    MtxF_SetRotationTranslationF(sp20.mf, (void *)&D_800948D0, (void *)arg2);
    MtxF_Multiply(&sp20, &sp20, &sp60);
    MtxF_ScaleRows(arg0, &sp20, arg3);
}

void func_80037120(S1_Vec3f *arg0, S1_Vec3f *arg1, f32 *arg2, s16 *arg3, s16 *arg4) {
    f32 dx; f32 dy; f32 dz;
    dx = arg1->x - arg0->x; dy = arg1->y - arg0->y; dz = arg1->z - arg0->z;
    *arg2 = sqrtf(dx * dx + dy * dy + dz * dz);
    *arg3 = MathUtil_Atan2s(sqrtf(dx * dx + dz * dz), dy);
    *arg4 = MathUtil_Atan2s(dz, dx);
}

void Camera_ComputeEyeFromAngles(S1_Vec3f *from, S1_Vec3f *to, f32 dist, s16 pitch, s16 yaw) {
    to->x = from->x + (dist * D_80088E50[((u16)pitch >> 4)] * D_80087E50[((u16)yaw >> 4)]);
    to->y = from->y + (dist * D_80087E50[((u16)pitch >> 4)]);
    to->z = from->z + (dist * D_80088E50[((u16)pitch >> 4)] * D_80088E50[((u16)yaw >> 4)]);
}

s16 Math_StepToS(s16 current, s16 target, s16 inc) {
    s16 temp_v0 = target - current;

    if (temp_v0 < 0) {
        temp_v0 += inc;
        if (temp_v0 > 0) {
            temp_v0 = 0;
        }
    } else {
        temp_v0 -= inc;
        if (temp_v0 < 0) {
            temp_v0 = 0;
        }
    }

    return target - temp_v0;
}

s32 Math_StepToS32(s32 current, s32 target, s32 inc, s32 dec) {
    if (current < target) {
        current += inc;
        if (current > target) {
            current = target;
        }
    } else {
        current -= dec;
        if (current < target) {
            current = target;
        }
    }
    return current;
}

f32 Math_StepToF(f32 current, f32 target, f32 inc, f32 dec) {
    if (current < target) {
        current += inc;
        if (current > target) {
            current = target;
        }
    } else {
        current -= dec;
        if (current < target) {
            current = target;
        }
    }
    return current;
}

s16 func_80037360(s16* arg0, s32 arg1, s32 arg2) {
    S1_Vec2s_s32 spC;
    s16* temp_a3 = &arg0[(arg1 * arg2) / 16];
    s16* p_spC = &spC.x;

    p_spC[0] = temp_a3[0];
    p_spC[1] = temp_a3[1];

    spC.xy <<= ((arg1 * arg2) % 16);
    spC.xy >>= -arg2;
    return spC.y;
}

void Color_RGBToHSV(f32 arg0, f32 arg1, f32 arg2, S1_Vec3f* arg3) {
    f32 temp_ft4;
    f32 var_ft5;
    f32 var_fv0;
    f32 var_fv1;
    s32 var_v0;

    var_v0 = 0x47;
    if (arg1 <= arg0) {
        var_fv0 = arg0;
        var_v0 = 0x52;
    } else {
        var_fv0 = arg1;
    }

    if (var_fv0 < arg2) {
        var_fv0 = arg2;
        var_v0 = 0x42;
    }

    if (arg0 <= arg1) {
        var_fv1 = arg0;
    } else {
        var_fv1 = arg1;
    }

    if (arg2 < var_fv1) {
        var_fv1 = arg2;
    }

    temp_ft4 = var_fv0 + var_fv1;
    arg3->z = temp_ft4 - 1.0f;
    if (var_fv0 == var_fv1) {
        arg3->y = 0.0f;
        arg3->x = 0.0f;
        return;
    }

    if (arg3->z <= 0.0f) {
        var_ft5 = var_fv0 - var_fv1;
        arg3->y = var_ft5 / temp_ft4;
    } else {
        var_ft5 = var_fv0 - var_fv1;
        arg3->y = var_ft5 / (2.0 - temp_ft4);
    }

    if (var_v0 == 0x52) {
        arg3->x = (arg1 - arg2) / var_ft5;
    } else if (var_v0 == 0x47) {
        arg3->x = ((arg2 - arg0) / var_ft5) + 2.0;
    } else {
        arg3->x = ((arg0 - arg1) / var_ft5) + 4.0;
    }

    arg3->x *= 60.0f;
    if (arg3->x < 0.0f) {
        arg3->x += 360.0f;
    }
}

void Color_RGBA8ToHSV(S1_Color_RGBA8_u32 arg0, S1_Vec3f* arg1) {
    Color_RGBToHSV((s32)arg0.r / 255.0f, (s32)arg0.g / 255.0f, (s32)arg0.b / 255.0f, arg1);
}

void Color_RGB5551ToHSV(u16 arg0, S1_Vec3f* arg1) {
    Color_RGBToHSV(((arg0 & 0xF800) >> 0xB) / 31.0f, ((arg0 & 0x7C0) >> 6) / 31.0f, ((arg0 & 0x3E) >> 1) / 31.0f, arg1);
}

f32 Color_HSVInterpolate(f32 arg0, f32 arg1, f32 arg2) {
    f32 ret;

    if (arg0 < 0.0f) {
        arg0 += 360.0f;
    } else {
        while (arg0 >= 360.0f) {
            arg0 -= 360.0f;
        }
    }

    if (arg0 < 60.0f) {
        ret = (((arg2 - arg1) * arg0) / 60.0f) + arg1;
    } else if ((arg0 >= 60.0f) && (arg0 < 180.0f)) {
        ret = arg2;
    } else if ((arg0 >= 180.0f) && (arg0 < 240.0f)) {
        ret = arg1 + (((arg2 - arg1) * (240.0 - arg0)) / 60.0);
    } else {
        ret = arg1;
    }

    return ret;
}

void Color_HSVToRGB(f32* arg0, f32* arg1, f32* arg2, S1_Vec3f* arg3) {
    f32 sp24;
    f32 sp20;
    f32 temp_ft4;

    if (arg3->z < -1.0f) {
        arg3->z = -1.0f;
    } else if (arg3->z > 1.0f) {
        arg3->z = 1.0f;
    }

    if (arg3->y < 0.0f) {
        arg3->y = 0.0f;
    } else {
        sp24 = 1.0f;
        if (arg3->y > 1.0f) {
            arg3->y = 1.0f;
        }
    }

    if (arg3->x < 0.0f) {
        arg3->x += 360.0f;
    } else {
        while (arg3->x >= 360.0f) {
            arg3->x -= 360.0f;
        }
    }

    if (arg3->z <= 0.0f) {
        temp_ft4 = arg3->z + 1.0f;
        sp24 = temp_ft4 * 0.5f * (1.0f - arg3->y);
        sp20 = temp_ft4 - sp24;
    } else {
        temp_ft4 = arg3->z + 1.0f;
        sp20 = (temp_ft4 * 0.5 * (1.0f - arg3->y)) + arg3->y;
        sp24 = temp_ft4 - sp20;
    }

    *arg0 = Color_HSVInterpolate(arg3->x + 120.0f, sp24, sp20);
    *arg1 = Color_HSVInterpolate(arg3->x, sp24, sp20);
    *arg2 = Color_HSVInterpolate(arg3->x - 120.0f, sp24, sp20);
}

u16 Color_HSVToRGB5551(S1_Vec3f* arg0) {
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    s32 var_a0;
    s32 var_a1;
    s32 var_v1;

    Color_HSVToRGB(&sp2C, &sp28, &sp24, arg0);

    var_a1 = (sp2C * 31.0f) + 0.5f;
    if (var_a1 >= 0x20) {
        var_a1 = 0x1F;
    }

    var_v1 = (sp28 * 31.0f) + 0.5f;
    if (var_v1 >= 0x20) {
        var_v1 = 0x1F;
    }

    var_a0 = (sp24 * 31.0f) + 0.5f;
    if (var_a0 >= 0x20) {
        var_a0 = 0x1F;
    }

    return (var_a1 << 0xB) | (var_v1 << 6) | (var_a0 * 2) | 1;
}

S1_Color_RGBA8_u32* Color_HSVToRGBA8(S1_Color_RGBA8_u32* arg0, S1_Vec3f* arg1, s32 arg2) {
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    s32 var_a0;
    s32 var_a1;
    s32 var_v1;
    S1_Color_RGBA8_u32 sp1C;

    Color_HSVToRGB(&sp34, &sp30, &sp2C, arg1);

    var_a1 = (sp34 * 255.0f) + 0.5f;
    if (var_a1 >= 0x100) {
        var_a1 = 0xFF;
    }

    var_v1 = (sp30 * 255.0f) + 0.5f;
    if (var_v1 >= 0x100) {
        var_v1 = 0xFF;
    }

    var_a0 = (sp2C * 255.0f) + 0.5f;
    if (var_a0 >= 0x100) {
        var_a0 = 0xFF;
    }

    sp1C.r = var_a1;
    sp1C.g = var_v1;
    sp1C.b = var_a0;
    sp1C.a = arg2;

    *arg0 = sp1C;

    return arg0;
}

u16 Color_AdjustRGB5551(u16 color, S1_arg1_func_80010CA8 adjustment) {
    S1_Vec3f hsv;
    s32 column;
    s32 row;
    if (color & 1) {
        Color_RGB5551ToHSV(color, &hsv);
        if (adjustment.unk_00 != 0) {
            hsv.x += adjustment.unk_00 * 0.015625f;
        }
        if (adjustment.unk_02 != 0) {
            if (adjustment.unk_02 > 0) {
                hsv.y += (1.0f - hsv.y) * adjustment.unk_02 * 0.125f;
            } else {
                hsv.y += hsv.y * adjustment.unk_02 * 0.125f;
            }
        }
        if (adjustment.unk_03 != 0) {
            column = (hsv.z + 1.0f) * 0.5f * 255.0f;
            if (adjustment.unk_03 > 0) {
                row = adjustment.unk_03 + 7;
            } else {
                row = adjustment.unk_03 + 8;
            }
            hsv.z = (2.0f * (D_80095120[row][column] / D_800A42B0)) - 1.0f;
        }
        color = Color_HSVToRGB5551(&hsv);
    }
    return color;
}

u32 Color_AdjustRGBA8(u32 word, S1_arg1_func_80010CA8 adjustment) {
    S1_Vec3f hsv;
    S1_Color_RGBA8_u32 color;
    s32 column;
    s32 row;
    u16 *brightness;
    color.rgba = word;
    if (color.a > 0) {
        Color_RGBA8ToHSV(color, &hsv);
        if (adjustment.unk_00 != 0) {
            hsv.x += adjustment.unk_00 * 0.015625f;
        }
        if (adjustment.unk_02 != 0) {
            if (adjustment.unk_02 > 0) {
                hsv.y += (1.0f - hsv.y) * adjustment.unk_02 * 0.125f;
            } else {
                hsv.y += hsv.y * adjustment.unk_02 * 0.125f;
            }
        }
        if (adjustment.unk_03 != 0) {
            column = (hsv.z + 1.0f) * 0.5f * 255.0f;
            if (adjustment.unk_03 > 0) {
                row = adjustment.unk_03 + 7;
            } else {
                row = adjustment.unk_03 + 8;
            }
            brightness = D_80095120[row];
            hsv.z = (2.0f * (brightness[column] / D_800A42B4)) - 1.0f;
        }
        Color_HSVToRGBA8(&color, &hsv, color.a);
    }
    return color.rgba;
}

#pragma C_FUNCTION_PADDING(4)

void GeoNode_Init(S1_GraphNode* arg0, u8 arg1) {
    if (arg0 != NULL) {
        arg0->unk_00 = arg1;
        arg0->unk_01 = 0x11;
        arg0->unk_02 = 0;
        arg0->unk_03 = 0;
        arg0->unk_04 = arg0;
        arg0->unk_08 = arg0;
        arg0->unk_0C = NULL;
        arg0->unk_10 = NULL;
        arg0->unk_14 = NULL;
    }
}

void func_80037E3C(S1_GraphNode* arg0, S1_func_D_86002F34_000_010 arg1, void* arg2) {
    if (arg1 != NULL) {
        arg1 = func_80003240(arg1);
    }

    if (arg0 != NULL) {
        arg0->unk_14 = arg2;
        arg0->unk_10 = arg1;
        if (arg1 != NULL) {
            arg1(0, arg0);
        }
    }
}

S1_GraphNode* GeoNode_CreateContainer(S1_MainPoolState* arg0, S1_GraphNode* arg1) { if (arg0 != NULL) { arg1 = MainPool_AllocAligned(arg0, sizeof(S1_GraphNode), 4); } if (arg1 != NULL) { GeoNode_Init(arg1, 0); } return arg1; }

S1_unk_D_86002F34_alt2* GeoNode_CreateWithReference(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt2* arg1, S1_GraphNode* arg2) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(S1_unk_D_86002F34_alt2), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = arg2;
        GeoNode_Init(arg1, 1);
    }

    return arg1;
}

S1_unk_D_86002F34_00C *GeoNode_CreateCamera(S1_MainPoolState *pool, S1_unk_D_86002F34_00C *node, s16 x, s16 y, s16 width, s16 height) {
    if (pool != NULL) {
        node = MainPool_AllocAligned(pool, sizeof(S1_unk_D_86002F34_00C), 4);
    }
    if (node != NULL) {
        GeoCamera_SetViewport(node, x, y, width, height);
        GeoCamera_SetPerspective(node, 30.0f, 100.0f, 12800.0f);
        func_80038E14(node, 0.0f, 512.0f, 4096.0f, 0.0f, 0.0f, 0.0f, 0);
        GeoCamera_SetBackground(node, 2, 0, 0, 0, 0);
        GeoNode_Init((void *)node, 2);
    }
    return node;
}

S1_unk_D_86002F34_alt13* GeoNode_CreateType3(S1_MemoryBlock* arg0, S1_unk_D_86002F34_alt13* arg1, s16 arg2) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(S1_unk_D_86002F34_alt13), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = arg2;
        GeoNode_Init(arg1, 3);
    }

    return arg1;
}

S1_unk_D_86002F34_alt1* GeoNode_CreateType4(S1_MemoryBlock* arg0, S1_unk_D_86002F34_alt1* arg1, s16 arg2) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(S1_unk_D_86002F34_alt1), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = arg2;
        arg1->unk_1A = 0;
        GeoNode_Init(arg1, 4);
    }

    return arg1;
}

void *func_800380B8(S1_MainPoolState *arg0, s32 arg1, s16 arg2) {
    if (arg0 != NULL) {
        arg1 = (s32)(u32)MainPool_AllocAligned(arg0, 0x18, 4);
    }
    if (arg1 != 0) {
        GeoNode_Init((S1_GraphNode *)arg1, 5U);
        *(u8 *)(arg1 + 2) = *(u8 *)(arg1 + 2) | (arg2 & 7);
    }
    return (void *)arg1;
}

void *func_8003811C(S1_MainPoolState *arg0, s32 arg1, s16 arg2) {
    if (arg0 != NULL) {
        arg1 = (s32)(u32)MainPool_AllocAligned(arg0, 0x18, 4);
    }
    if (arg1 != 0) {
        GeoNode_Init((S1_GraphNode *)arg1, 6);
        *(u8 *)(arg1 + 2) = *(u8 *)(arg1 + 2) | (arg2 & 7);
    }
    return (void *)arg1;
}

S1_unk_D_86002F34_alt16* GeoNode_CreateBackground(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt16* arg1, u8 arg2, u8 arg3, u8 arg4) {
    u32 temp_v0;

    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(S1_unk_D_86002F34_alt16), 4);
    }

    if (arg1 != NULL) {
        temp_v0 = ((arg2 >> 3) << 0xB) | ((arg3 >> 3) << 6) | ((arg4 >> 3) << 1) | 1;
        arg1->unk_18 = (temp_v0 << 0x10) | temp_v0;
        GeoNode_Init(arg1, 7);
    }
    return arg1;
}

s32 func_8003820C(s32 arg0, s32 arg1) {
    s32 var_a2;

    var_a2 = arg1;
    if (arg0 != 0) {
        var_a2 = (s32)(u32)MainPool_AllocAligned((void *)(u32)arg0, 0x18, 4);
    }
    if (var_a2 != 0) {
        arg1 = var_a2;
        GeoNode_Init((S1_GraphNode *) var_a2, 8U);
        var_a2 = arg1;
    }
    return var_a2;
}

S1_unk_D_8690A610* GeoNode_CreateFog(s32 arg0, S1_unk_D_8690A610* arg1, s16 arg2, s16 arg3, u8 r, u8 g, u8 b, u8 a) {
    if (arg0 != 0) {
        arg1 = MainPool_AllocAligned((void *)(u32)arg0, sizeof(S1_unk_D_8690A610), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18.fogNear = arg2;
        arg1->unk_18.fogFar = arg3;
        arg1->unk_18.fogColor.rgba = (r << 0x18) | (g << 0x10) | (b << 8) | a;
        GeoNode_Init(arg1, 0xA);
    }

    return arg1;
}

void *GeoNode_CreateLight(S1_MainPoolState *pool, void *storage, s16 pitch, s16 yaw, u8 red, u8 green, u8 blue, u8 alpha) {
    SceneDirectionalLight *light;
    if (pool != NULL) {
        storage = MainPool_AllocAligned(pool, sizeof(SceneDirectionalLight), 4);
    }
    light = storage;
    if (light != NULL) {
        light->color.r = red;
        light->color.g = green;
        light->color.b = blue;
        light->color.a = alpha;
        light->pitch = pitch;
        light->yaw = yaw;
        light->direction = D_800948DC;
        light->red = 0;
        light->green = 0;
        light->blue = 0;
        light->overrideDirection = 0;
        GeoNode_Init((S1_GraphNode *)light, 0xB);
    }
    return light;
}

void func_80038390(void *arg0, S1_Vec3s *arg1, u8 arg2, u8 arg3, u8 arg4) {
    if (arg0 != NULL) {
        *(S1_Vec3s *)((u8 *)arg0 + 0x20) = *arg1;
        ((u8 *)arg0)[0x28] = arg2;
        ((u8 *)arg0)[0x29] = arg3;
        ((u8 *)arg0)[0x2A] = arg4;
        ((u8 *)arg0)[0x2B] = 1;
    }
}

void func_800383DC(void *arg0, s16 arg1, s16 arg2) {
    if (arg0 != NULL) {
        (*(s16 *)((u8 *)(arg0) + (0x1C))) = arg1;
        (*(s16 *)((u8 *)(arg0) + (0x1E))) = arg2;
        (*(s8 *)((u8 *)(arg0) + (0x2B))) = 0;
    }
}

S1_unk_D_86002F34_alt19* GeoNode_CreateAmbientLight(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt19* arg1, u8 r, u8 g, u8 b) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(S1_unk_D_86002F34_alt19), 4);
    }

    if (arg1 != NULL) {
        arg1->r = r;
        arg1->g = g;
        arg1->b = b;
        GeoNode_Init(arg1, 0xD);
    }

    return arg1;
}

s32 func_80038474(s32 arg0, s32 arg1) {
    s32 var_a2;

    var_a2 = arg1;
    if (arg0 != 0) {
        var_a2 = (s32)(u32)MainPool_AllocAligned((void *)(u32)arg0, 0x18, 4);
    }
    if (var_a2 != 0) {
        arg1 = var_a2;
        GeoNode_Init((S1_GraphNode *) var_a2, 0x1DU);
        var_a2 = arg1;
    }
    return var_a2;
}

S1_GraphNode *func_800384C0(void *arg0, S1_GraphNode *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, u16 arg8) {
    S1_GraphNode *new_var;
    u8 *new_var2;
    if (arg0 != 0) {
        arg1 = MainPool_AllocAligned(arg0, 0x30, 4);
    }
    if (arg1 != 0) {
        ((s32 *)(((u8 *)arg1) + 0x18))[0] = arg3;
        ((s32 *)(((u8 *)arg1) + 0x1C))[0] = arg5;
        ((s32 *)(((u8 *)arg1) + 0x20))[0] = arg7;
        ((u8 *)arg1)[0x24] = (u8)arg2;
        ((u8 *)arg1)[0x25] = (u8)arg4;
        ((u16 *)(((u8 *)arg1) + 0x26))[0] = (u16)arg6;
        new_var2 = (u8 *)arg1;
        ((u16 *)(((u8 *)arg1) + 0x28))[0] = arg8;
        ((s32 *)(new_var2 + 0x2C))[0] = 0;
        GeoNode_Init(arg1, 0xE);
    }
    if (1) {
        new_var = arg1;
    }
    return new_var;
}

S1_unk_D_86002F34_alt12* GeoNode_CreateShadow(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt12* arg1, s16 arg2, s16 arg3, s16 arg4,
                                    s16 arg5) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(S1_unk_D_86002F34_alt12), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = arg2;
        arg1->unk_1A = arg3;
        arg1->unk_1C = arg4;
        arg1->unk_1E = arg5;
        GeoNode_Init(arg1, 0xF);
    }

    return arg1;
}

S1_unk_D_86002F34_alt20* GeoNode_CreateCullDistance(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt20* arg1, s16 arg2, s16 arg3) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(S1_unk_D_86002F34_alt20), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = arg2;
        arg1->unk_1A = arg3;
        GeoNode_Init(arg1, 0x10);
    }

    return arg1;
}

S1_unk_D_86002F34_alt21* GeoNode_CreateSwitchCase(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt21* arg1, s16 arg2, s16 arg3) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(S1_unk_D_86002F34_alt21), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = arg2;
        arg1->unk_1A = arg3;
        GeoNode_Init(arg1, 0x11);
    }

    return arg1;
}

S1_unk_D_86002F34_alt5* GeoNode_CreateTranslateRotate(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt5* arg1, S1_Vec3f* arg2, S1_Vec3s* arg3) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(S1_unk_D_86002F34_alt5), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = *arg2;
        arg1->unk_24 = *arg3;
        GeoNode_Init(arg1, 0x12);
    }

    return arg1;
}

S1_unk_D_86002F34_alt22* GeoNode_CreateTranslate(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt22* arg1, S1_Vec3f* arg2) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(S1_unk_D_86002F34_alt22), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = *arg2;
        GeoNode_Init(arg1, 0x13);
    }

    return arg1;
}

S1_unk_D_86002F34_alt6* GeoNode_CreateAnimatedPart(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt6* arg1, s16 arg2, s16 arg3, s16 arg4,
                                   S1_Vec3s* arg5, S1_Vec3s* arg6, S1_Vec3f* arg7) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(S1_unk_D_86002F34_alt6), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = *arg5;
        arg1->unk_1E = *arg6;
        arg1->unk_24 = *arg7;
        arg1->unk_30 = arg2;
        arg1->unk_31 = arg3;
        arg1->unk_32 = arg4;
        GeoNode_Init(arg1, 0x14);
    }

    return arg1;
}

S1_unk_D_86002F34_alt7* GeoNode_CreateDisplayListPart(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt7* arg1, s32 arg2, Gfx* arg3, s16 arg4) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(S1_unk_D_86002F34_alt7), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = arg3;
        arg1->unk_1C = arg4;
        GeoNode_Init(arg1, 0x15);
        arg1->unk_00.unk_03 = arg2;
    }

    return arg1;
}

S1_unk_D_86002F58_004_000 *GeoNode_CreateModelPart(S1_MainPoolState *pool, void *storage, s16 model, S1_Vec3f *position, S1_Vec3s *rotation, S1_Vec3f *scale) {
    if (pool != NULL) storage = MainPool_AllocAligned(pool, 0x168, 4);
    if (storage != NULL) {
        S1_unk_D_86002F58_004_000 *node = storage;
        node->animType = 0;
        node->modelId = model;
        node->unk_024 = *position;
        node->unk_030 = *scale;
        node->unk_01E = *rotation;
        node->materialAlpha = 0xFF;
        node->textureMode = 0;
        node->unk_0A0.rgba = 0xFFFFFF00U;
        node->unk_03C.rgba = 0xFFFFFF00U;
        node->poolIndex = 0;
        node->unk_040.unk_00 = 0;
        node->unk_040.unk_04 = NULL;
        node->unk_040.unk_08 = 0;
        node->unk_040.unk_0C = 0x10000;
        node->unk_040.unk_12 = 0;
        node->unk_054.unk_00 = 0;
        *(s16 *)((u8 *)node + 0x56) = 0;
        node->unk_054.unk_04 = NULL;
        node->unk_054.unk_08 = 0;
        node->unk_054.unk_0A = 0;
        GeoNode_Init((S1_GraphNode *)node, 0x16);
        node->unk_000.unk_02 |= 0x60;
    }
    return storage;
}

void *func_8003899C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4) {
    if (arg0 != 0) {
        arg1 = (s32) MainPool_AllocAligned((void *) arg0, sizeof(S1_unk_D_86002F34_alt8), 4);
    }
    if (arg1 != 0) {
        ((S1_unk_D_86002F34_alt8 *) arg1)->unk_18 = (Gfx *) arg3;
        if (arg4 == NULL) {
            MtxF_Identity((f32 *) &((S1_unk_D_86002F34_alt8 *) arg1)->unk_1C);
        } else {
            MtxF_Copy((u32 *) &((S1_unk_D_86002F34_alt8 *) arg1)->unk_1C, (u32 *) arg4);
        }
        GeoNode_Init((S1_GraphNode *) arg1, 0x17);
        ((S1_unk_D_86002F34_alt8 *) arg1)->unk_00.unk_03 = (u8) arg2;
    }
    return (void *) arg1;
}

void *GeoNode_CreateDisplayListMatrixFromTransform(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    f32 temp[4][4];
    MtxF_SetRotationTranslationF(temp, (Vec3f35784 *)arg4, (Vec3s35AA0 *)arg5);
    func_8003899C(arg0, arg1, arg2, arg3, temp);
}

S1_unk_D_86002F34_alt9* GeoNode_CreateScale(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt9* arg1, s32 arg2, Gfx* arg3, S1_Vec3f* arg4,
                                   f32 arg5) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(S1_unk_D_86002F34_alt9), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_1C = *arg4;
        arg1->unk_28 = arg5;
        arg1->unk_18 = arg3;
        GeoNode_Init(arg1, 0x18);
        arg1->unk_00.unk_03 = arg2;
    }

    return arg1;
}

S1_unk_func_80011B94* GeoNode_CreateDisplayList(S1_MainPoolState* arg0, S1_unk_func_80011B94* arg1, s32 arg2, Gfx* arg3) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(S1_unk_func_80011B94), 4);
    }

    if (arg1 != NULL) {
        arg1->displayList = arg3;
        GeoNode_Init(arg1, 0x19);
        arg1->unk_00.unk_03 = arg2;
    }

    return arg1;
}

S1_unk_D_86002F34_alt10* GeoNode_CreateShadowTexture(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt10* arg1, s16 arg2, s16 arg3, Gfx* arg4,
                                    s16 arg5, s16 arg6, u8 r, u8 g, u8 b, u8 a) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(S1_unk_D_86002F34_alt10), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_22 = arg2;
        arg1->unk_20 = arg3;
        arg1->unk_18 = arg4;
        arg1->unk_1C = arg5;
        arg1->unk_1E = arg6;
        arg1->unk_24.rgba = (r << 0x18) | (g << 0x10) | (b << 8) | a;
        GeoNode_Init(arg1, 0x1A);
    }

    return arg1;
}

S1_unk_D_86002F34_alt23* GeoNode_CreateAnchor(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt23* arg1, s16 arg2) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(S1_unk_D_86002F34_alt23), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_18 = arg2;
        GeoNode_Init(arg1, 0x1B);
    }

    return arg1;
}

S1_unk_D_86002F34_alt24* GeoNode_CreateGroup(S1_MainPoolState* arg0, S1_unk_D_86002F34_alt24* arg1, s32 arg2, s16 arg3, s16 arg4,
                                    s16 arg5, s16 arg6, s16 arg7, s16 arg8, s32 arg9, u8 r, u8 g, u8 b, u8 a) {
    if (arg0 != NULL) {
        arg1 = MainPool_AllocAligned(arg0, sizeof(S1_unk_D_86002F34_alt24), 4);
    }

    if (arg1 != NULL) {
        arg1->unk_1C = arg3;
        arg1->unk_1E = arg4;
        arg1->unk_20 = arg5;
        arg1->unk_22 = arg6;
        arg1->unk_18 = arg7;
        arg1->unk_1A = arg8;
        arg1->unk_24 = arg9;
        arg1->unk_28.rgba = (r << 0x18) | (g << 0x10) | (b << 8) | a;
        GeoNode_Init(arg1, 0x1C);
        arg1->unk_00.unk_03 = arg2;
    }

    return arg1;
}

void GeoCamera_SetViewport(S1_unk_D_86002F34_00C* arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    arg0->unk_18.x = arg1;
    arg0->unk_18.y = arg2;
    arg0->unk_18.width = arg3;
    arg0->unk_18.height = arg4;

    arg0->unk_40.l = -arg3 * 0.5f;
    arg0->unk_40.r = arg3 * 0.5f;
    arg0->unk_40.t = arg4 * 0.5f;
    arg0->unk_40.b = -arg4 * 0.5f;
    arg0->unk_40.n = -2.0f;
    arg0->unk_40.f = 2.0f;
    arg0->unk_40.scale = 1.0f;
}

void GeoCamera_SetPerspective(S1_unk_D_86002F34_00C* arg0, f32 arg1, f32 arg2, f32 arg3) {
    arg0->unk_24.aspect = (f32)arg0->unk_18.width / arg0->unk_18.height;
    arg0->unk_24.fovy = arg1;
    arg0->unk_24.near = arg2;
    arg0->unk_24.far = arg3;
    arg0->unk_24.scale = 1.0f;
}

void func_80038E14(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, u16 arg7) {
    f32 inv = (f32)(-1.0 / sqrtf((arg4 - arg1) * (arg4 - arg1) + (arg6 - arg3) * (arg6 - arg3)));
    f32 sx = (arg4 - arg1) * inv;
    f32 sz = (arg6 - arg3) * inv;
    u8 *ptr = (u8 *)arg0 + 0x60;
    Vec3f_SetComponentsDuplicate((void *)((u8 *)arg0 + 0xA8), arg1, arg2, arg3);
    Vec3f_SetComponentsDuplicate((void *)(ptr + 0x54), arg4, arg5, arg6);
    Vec3f_SetComponentsDuplicate((void *)(ptr + 0x60), D_80087E50[arg7 >> 4] * sz, D_80088E50[arg7 >> 4], -D_80087E50[arg7 >> 4] * sx);
}

void GeoCamera_SetBackground(S1_unk_D_86002F34_00C* arg0, s16 arg1, s16 arg2, u8 arg3, u8 arg4, u8 arg5) {
    S1_unk_D_86002F34_00C_0CC* ptr = &arg0->unk_CC;

    if (arg2 < 2) {
        if ((arg1 == 2) || (arg1 == 4)) {
            ptr->unk_00 = 0;
        } else {
            ptr->unk_00 = 1;
        }
    } else {
        ptr->unk_00 = arg1;
        ptr->unk_08 = arg2;
        ptr->unk_0A = 1;
        ptr->color.r = arg3;
        ptr->color.g = arg4;
        ptr->color.b = arg5;
    }
}

void func_80038F8C(void *arg0, void *arg1) {
    void *temp_v0;
    void *temp_v1;

    if ((arg0 != NULL) && (arg1 != NULL)) {
        temp_v0 = (*(void **)((u8 *)(arg0) + (0xC)));
        if (temp_v0 == NULL) {
            (*(void **)((u8 *)(arg0) + (0xC))) = arg1;
            (*(void **)((u8 *)(arg1) + (4))) = arg1;
            (*(void **)((u8 *)(arg1) + (8))) = arg1;
            return;
        }
        temp_v1 = (*(void **)((u8 *)(temp_v0) + (4)));
        (*(void **)((u8 *)(arg1) + (8))) = temp_v0;
        (*(void **)((u8 *)(arg1) + (4))) = temp_v1;
        (*(void **)((u8 *)(temp_v0) + (4))) = arg1;
        (*(void **)((u8 *)(temp_v1) + (8))) = arg1;
    }
}

void GraphNode_RemoveChild(GraphNode38FD4 *root, GraphNodeLink *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    if (node == root->child) {
        if (node == node->next) {
            root->child = NULL;
        } else {
            root->child = node->next;
        }
    }
}

unk_func_80039018 *func_80039018(unk_func_80039018 *arg0, s32 arg1) {
    unk_func_80039018 *var_v1 = arg0->unk_0C;
    s32 var_v0;

    if (var_v1 != NULL) {
        for (var_v0 = 0; var_v0 < arg1; var_v0++) {
            var_v1 = var_v1->unk_08;
        }
    }
    return var_v1;
}

#pragma C_FUNCTION_PADDING(4)

void func_80039070(s32 arg0) { *(s32 *)((u8 *)&D_80124F68 + 0x10A0) = 0; *((u8 *)&D_80124F68 + 0x1080) = 0; MtxF_Identity((f32 *)&D_80124F68); if (arg0 == 0) { *(s32 *)((u8 *)&D_80124F68 + 0x1000) = (s32)Gfx_AllocDisplayList(0x40); } else { *(s32 *)((u8 *)&D_80124F68 + 0x1000) = arg0; } MtxF_ToFixed((void *)*(s32 *)((u8 *)&D_80124F68 + 0x1000), (S1_MtxF *)&D_80124F68); }

void GeoRender_CommitMatrix(Mtx *fixed) {
    ((SceneTransformPool *)&D_80124F68)->flags[((SceneTransformPool *)&D_80124F68)->top] = 0;
    if (fixed == NULL) {
        ((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top] = (Mtx *)Gfx_AllocDisplayList(0x40);
    } else {
        ((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top] = fixed;
    }
    MtxF_ToFixed(((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top], &((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top]);
}

Mtx *GeoRender_SetMatrix(S1_MtxF *matrix, Mtx *fixed) {
    MtxF_Copy((u32 *)(&((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top]), (u32 *)matrix);
    ((SceneTransformPool *)&D_80124F68)->flags[((SceneTransformPool *)&D_80124F68)->top] = 0;
    if (fixed == NULL) {
        ((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top] = (Mtx *)Gfx_AllocDisplayList(0x40);
    } else {
        ((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top] = fixed;
    }
    MtxF_ToFixed(((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top], &((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top]);
    return ((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top];
}

void GeoRender_PushMultipliedMatrix(S1_MtxF *matrix, Mtx *fixed) {
    ((SceneTransformPool *)&D_80124F68)->top++;
    MtxF_Multiply(&((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top], matrix, &((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top - 1]);
    ((SceneTransformPool *)&D_80124F68)->flags[((SceneTransformPool *)&D_80124F68)->top] = 0;
    if (fixed == NULL) {
        ((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top] = (Mtx *)Gfx_AllocDisplayList(0x40);
    } else {
        ((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top] = fixed;
    }
    MtxF_ToFixed(((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top], &((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top]);
}

Mtx *GeoRender_PushScaledMatrix(S1_Vec3f *scale, Mtx *fixed) {
    ((SceneTransformPool *)&D_80124F68)->top++;
    MtxF_ScaleRows(&((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top], &((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top - 1], scale);
    ((SceneTransformPool *)&D_80124F68)->flags[((SceneTransformPool *)&D_80124F68)->top] = 0;
    if (fixed == NULL) {
        ((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top] = (Mtx *)Gfx_AllocDisplayList(0x40);
    } else {
        ((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top] = fixed;
    }
    MtxF_ToFixed(((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top], &((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top]);
    return ((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top];
}

void *func_8003936C(s32 arg0) {
    void *var_v1;
    struct PoolBase {
        u8 pad[0x10A0];
        s32 count;
    };

    var_v1 = NULL;
    if (arg0 <= 0) {
        var_v1 = (void *)((u8 *)&D_80124F68 + (((struct PoolBase *)&D_80124F68)->count << 6) + (arg0 << 6));
    }
    return var_v1;
}

void *GeoRender_GetMatrix(s32 arg0) {
    void *var_v1;

    var_v1 = NULL;
    if ((arg0 >= 0) && (arg0 < 0x20)) {
        var_v1 = (arg0 << 6) + &D_80124F68;
    }
    return var_v1;
}

void GeoRender_ResetTransformStack(void) {
    struct Vec3Words {
        s32 x;
        s32 y;
        s32 z;
    };
    struct State {
        struct Vec3Words value;
        u8 pad[0x174];
        s32 flag;
    };

    ((struct State *)&D_80126010)->flag = 0;
    ((struct State *)&D_80126010)->value = *(struct Vec3Words *)D_800948E4;
}

void func_800393F0(S1_Vec3f *arg0) {
    S1_Vec3f *vec = (S1_Vec3f *)&D_80126010;
    s32 *counter = (s32 *)((u8 *)&D_80126010 + 0x180);
    vec[*counter + 1].x = vec[*counter].x * arg0->x;
    vec[*counter + 1].y = vec[*counter].y * arg0->y;
    vec[*counter + 1].z = vec[*counter].z * arg0->z;
    (*counter)++;
}

Vtx *GeoOverlay_BuildFadeQuad(S1_unk_D_86002F34_00C_0CC *overlay, S1_unk_D_86002F34_00C_040 *projection) {
    u8 alpha;
    Vtx *vertices;

    vertices = Gfx_AllocDisplayList(4 * sizeof(Vtx));
    if (vertices != NULL) {
        switch (overlay->unk_00) {
        case 1:
            alpha = 255;
            break;
        case 2:
            alpha = 255 - (overlay->unk_0A * 255) / overlay->unk_08;
            break;
        case 3:
            alpha = (overlay->unk_0A * 255) / overlay->unk_08;
            break;
        }
        Gfx_SetVertexAttributes(&vertices[0], (s16)projection->l, (s16)projection->t, -1, 0, 0, overlay->color.r, overlay->color.g, overlay->color.b, alpha);
        Gfx_SetVertexAttributes(&vertices[1], (s16)projection->l, (s16)projection->b, -1, 0, 0, overlay->color.r, overlay->color.g, overlay->color.b, alpha);
        Gfx_SetVertexAttributes(&vertices[2], (s16)projection->r, (s16)projection->b, -1, 0, 0, overlay->color.r, overlay->color.g, overlay->color.b, alpha);
        Gfx_SetVertexAttributes(&vertices[3], (s16)projection->r, (s16)projection->t, -1, 0, 0, overlay->color.r, overlay->color.g, overlay->color.b, alpha);
    }
    return vertices;
}

void GeoOverlay_DrawFadeQuad(S1_unk_D_86002F34_00C_0CC* arg0, S1_unk_D_86002F34_00C_040* arg1) {
    Vtx* temp_v0 = GeoOverlay_BuildFadeQuad(arg0, arg1);

    if (temp_v0 != NULL) {
        gDPSetCombineMode(D_800D0510++, G_CC_SHADE, G_CC_SHADE);
        gDPSetRenderMode(D_800D0510++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);

        gSPVertex(D_800D0510++, (u32)temp_v0 & 0x1FFFFFFF, 4, 0);
        gSP2Triangles(D_800D0510++, 0, 1, 2, 0, 0, 2, 3, 0);
    }

    if (arg0->unk_00 != 1) {
        arg0->unk_0A++;
        if (arg0->unk_0A == arg0->unk_08) {
            if (arg0->unk_00 == 2) {
                arg0->unk_00 = 0;
            } else {
                arg0->unk_00 = 1;
            }
        }
    }
}

#pragma SWAP_FUNCTION_WORDS(func_80039808, 0xD0, 0xAFB80024, 0x00063403)

void func_80039808(Vtx* arg0, S1_unk_D_86002F34_00C_0CC* arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6, s16 arg7) {
    f32 temp_fa0;
    f32 temp_fv1;
    u16 idx = arg1->unk_18;
    f32 a4;
    f32 a5;
    s16 tmp1;
    s16 tmp2;

    a4 = arg4;
    temp_fv1 = COSS(idx);
    temp_fa0 = SINS(idx);
    a5 = arg5;

    tmp1 = ((a4 * temp_fv1) - (temp_fa0 * a5));
    tmp2 = ((temp_fv1 * a5) + (a4 * temp_fa0));

    Gfx_SetVertexAttributes(arg0, tmp1 + arg2, tmp2 + arg3, -1, arg6 * 32, arg7 * 32, arg1->color.r, arg1->color.g, arg1->color.b, ((u8)(arg2 - arg2) + 0xFF));
}

Vtx *func_800398F8(S1_unk_D_86002F34_00C_0CC *arg0) {
    Vtx *out = (Vtx *)Gfx_AllocDisplayList(0x80); Vtx *p; s16 x,y,z,nz;
    if (out) {
        x=arg0->unk_10+((arg0->unk_14-arg0->unk_10)*arg0->unk_0A)/arg0->unk_08; y=arg0->unk_12+((arg0->unk_16-arg0->unk_12)*arg0->unk_0A)/arg0->unk_08; z=arg0->unk_0C+((arg0->unk_0E-arg0->unk_0C)*arg0->unk_0A)/arg0->unk_08; nz=-z; p=out;
        if(arg0->unk_00==2){func_80039808(p++,arg0,x,y,nz,nz,-31,63);func_80039808(p++,arg0,x,y,z,nz,31,63);func_80039808(p++,arg0,x,y,z,z,31,0);func_80039808(p++,arg0,x,y,nz,z,-31,0);}else{func_80039808(p++,arg0,x,y,nz,nz,0,63);func_80039808(p++,arg0,x,y,z,nz,63,63);func_80039808(p++,arg0,x,y,z,z,63,0);func_80039808(p++,arg0,x,y,nz,z,0,0);}
        func_80039808(p++,arg0,x,y,-2000,-2000,0,0);func_80039808(p++,arg0,x,y,2000,-2000,0,0);func_80039808(p++,arg0,x,y,2000,2000,0,0);func_80039808(p,arg0,x,y,-2000,2000,0,0);
    } arg0->unk_18+=arg0->unk_1A; return out;
}

void GeoOverlay_DrawRotatingQuad(S1_unk_D_86002F34_00C_0CC* arg0, UNUSED S1_unk_D_86002F34_00C_040* arg1) {
    Vtx* temp_v0 = func_800398F8(arg0);

    if (temp_v0 != 0) {
        gDPSetCombineMode(D_800D0510++, G_CC_SHADE, G_CC_SHADE);
        gDPSetRenderMode(D_800D0510++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);

        gSPVertex(D_800D0510++, (u32)temp_v0 & 0x1FFFFFFF, 8, 0);
        gSP2Triangles(D_800D0510++, 0, 4, 1, 0, 1, 4, 5, 0);
        gSP2Triangles(D_800D0510++, 1, 5, 2, 0, 2, 5, 6, 0);
        gSP2Triangles(D_800D0510++, 2, 6, 7, 0, 2, 7, 3, 0);
        gSP2Triangles(D_800D0510++, 3, 4, 0, 0, 3, 7, 4, 0);

        gDPPipeSync(D_800D0510++);

        gDPSetCombineMode(D_800D0510++, G_CC_MODULATEIDECALA, G_CC_MODULATEIDECALA);
        gDPSetRenderMode(D_800D0510++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
        gDPSetTextureFilter(D_800D0510++, G_TF_BILERP);

        if (arg0->unk_02 == 0) {
            gDPLoadTextureBlock(D_800D0510++, arg0->texture, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 64, 0,
                                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, 6, 6, G_TX_NOLOD, G_TX_NOLOD);
        } else {
            gDPLoadTextureBlock(D_800D0510++, arg0->texture, G_IM_FMT_IA, G_IM_SIZ_8b, 32, 64, 0,
                                G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 5, 6, G_TX_NOLOD, G_TX_NOLOD);
        }

        gSPTexture(D_800D0510++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);

        gSPVertex(D_800D0510++, (u32)temp_v0 & 0x1FFFFFFF, 4, 0);
        gSP2Triangles(D_800D0510++, 0, 1, 2, 0, 0, 2, 3, 0);

        gSPTexture(D_800D0510++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
        gDPSetTextureFilter(D_800D0510++, G_TF_BILERP);
    }

    arg0->unk_0A++;
    if (arg0->unk_0A == arg0->unk_08) {
        if (arg0->unk_00 == 4) {
            arg0->unk_00 = 0;
        } else {
            arg0->unk_00 = 1;
        }
    }
}

void GeoOverlay_Draw(S1_unk_D_86002F34_00C_0CC* arg0, S1_unk_D_86002F34_00C_040* arg1) {
    if (arg0->unk_00 != 0) {
        gDPPipeSync(D_800D0510++);

        gDPSetCycleType(D_800D0510++, G_CYC_1CYCLE);
        gSPClearGeometryMode(D_800D0510++, G_ZBUFFER | G_LIGHTING);
        gSPPerspNormalize(D_800D0510++, 0xFFFF);
        gSPMatrix(D_800D0510++, (u32)arg1->mtx & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
        gSPMatrix(D_800D0510++, (u32)&D_80094890 & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

        if ((arg0->unk_00 == 1) || (arg0->unk_00 == 2) || (arg0->unk_00 == 3)) {
            GeoOverlay_DrawFadeQuad(arg0, arg1);
        } else {
            GeoOverlay_DrawRotatingQuad(arg0, arg1);
        }

        gDPPipeSync(D_800D0510++);
        gDPSetCycleType(D_800D0510++, G_CYC_2CYCLE);
    }
}

void Geo_ProcessNodeChildren(void *root) {
    S1_GraphNode *first;
    S1_GraphNode *child;
    first = (S1_GraphNode *)((S1_GraphNode *)root)->unk_0C;
    child = first;
    if (first != NULL) {
        do {
            if (child->unk_01 & 1) {
                D_80124D60 = 0;
                if (child->unk_10 != NULL) {
                    D_80124D60 = child->unk_10(2, child);
                }
                ((void (*)(S1_GraphNode *))D_80094924[child->unk_00])(child);
            }
            child = child->unk_08;
        } while (child != first);
    }
}

void Geo_PrepareShadowChildren(s32 root) {
    S1_GraphNode *first = (S1_GraphNode *)((S1_GraphNode *)root)->unk_0C;
    S1_GraphNode *node = first;
    if (first != NULL) {
        do {
            if (node->unk_01 & 1) {
                D_80124D60 = 0;
                if (node->unk_10 != NULL) {
                    D_80124D60 = node->unk_10(6, node);
                }
                switch (node->unk_00) {
                default:
                    Geo_PrepareShadowChildren((s32)node);
                    break;
                case 0x13:
                    func_8003B690((s32)node);
                    break;
                case 0x14:
                    Geo_PrepareAnimatedPart((s32)node);
                    break;
                }
            }
            node = node->unk_08;
        } while (node != first);
    }
}

void Geo_NodeReference(void *arg0) {
    s32 (*callback)(s32, void *);
    void *child;
    callback = 0;
    child = *(void **)((u8 *)arg0 + 0x18);
    if (child != 0 && (*(u8 *)((u8 *)child + 1) & 1) != 0) {
        D_80124D60 = 0;
        callback = *(s32 (**)(s32, void *))((u8 *)child + 0x10);
        if (callback != 0) {
            D_80124D60 = callback(2, child);
        }
        ((void (*)(void *))((void **)D_80094924)[*(u8 *)child])(child);
    }
    Geo_ProcessNodeChildren(arg0);
}

void func_8003A4CC(S1_GraphNode *arg0) {
    UNUSED S1_MtxF pad_mtx;
    S1_unk_D_86002F34_00C *arg = (S1_unk_D_86002F34_00C *)arg0;
    S1_unk_D_86002F34_00C_040 *temp_s2 = &arg->unk_40;
    S1_unk_D_86002F34_00C_060 *temp_s1 = &arg->unk_60;
    S1_unk_D_86002F34_00C_024 *sp48 = &arg->unk_24;
    S1_unk_D_86002F34_00C_018 *temp_s0 = &arg->unk_18;

    temp_s0->vp = Gfx_AllocDisplayList(sizeof(Vp) * 1);
    temp_s2->mtx = Gfx_AllocDisplayList(sizeof(Mtx) * 1);
    sp48->mtx = Gfx_AllocDisplayList(sizeof(S1_MtxF) * 1);
    temp_s1->p_mtxf = Gfx_AllocDisplayList(sizeof(S1_MtxF) * 1);
    temp_s1->lookat = Gfx_AllocDisplayList(sizeof(LookAt) * 1);

    temp_s0->vp->vp.vtrans[0] = (temp_s0->x * 4) + (temp_s0->width * 2);
    temp_s0->vp->vp.vtrans[1] = (temp_s0->y * 4) + (temp_s0->height * 2);
    temp_s0->vp->vp.vtrans[2] = 0x1FF;

    temp_s0->vp->vp.vscale[0] = temp_s0->width * 2;
    temp_s0->vp->vp.vscale[1] = temp_s0->height * 2;
    temp_s0->vp->vp.vscale[2] = 0x1FF;

    gSPViewport(D_800D0510++, (u32)temp_s0->vp & 0x1FFFFFFF);
    gDPSetScissorFrac(D_800D0510++, G_SC_NON_INTERLACE, temp_s0->x * 4.0f, temp_s0->y * 4.0f,
                      (temp_s0->x + temp_s0->width) * 4.0f, (temp_s0->y + temp_s0->height) * 4.0f);

    guOrtho(temp_s2->mtx, temp_s2->l, temp_s2->r, temp_s2->b, temp_s2->t, temp_s2->n, temp_s2->f, temp_s2->scale);
    func_80077DC0(sp48->mtx, &sp48->perspNorm, sp48->fovy, sp48->aspect, sp48->near, sp48->far, sp48->scale);
    guLookAtReflectF(&temp_s1->mtxf, temp_s1->lookat, temp_s1->eye.x, temp_s1->eye.y, temp_s1->eye.z, temp_s1->at.x,
                     temp_s1->at.y, temp_s1->at.z, temp_s1->up.x, temp_s1->up.y, temp_s1->up.z);
    MtxF_ToFixed(temp_s1->p_mtxf, &temp_s1->mtxf);

    D_80094908 = arg;
    if ((arg->unk_CC.unk_00 != 1) && (arg->unk_00.unk_0C != NULL)) {
        func_8003A2C8(&arg->unk_00);
    }
    GeoOverlay_Draw(&arg->unk_CC, temp_s2);
    Gfx_ApplyScissorRect(&D_800D0510);
    D_80094908 = NULL;
}

void Geo_NodeType3Pass(s32 arg0) {
    D_8009490C = arg0;
    Geo_ProcessNodeChildren((void *)arg0);
    D_8009490C = 0;
}

void Geo_NodeModelRoot(void *root) {
    ModelFrame *node = (ModelFrame *)root;
    if (((S1_GraphNode *)root)->unk_0C != NULL) {
        node->unknown1D = 0;
        node->unknown20 = -1;
        node->lights = (Lights7 *)Gfx_AllocDisplayList(sizeof(Lights7));
        node->lightCount = 0;
        node->activeLights = 0;
        node->extraGeometryMode = 0;
        node->lights->a.l.col[0] = 0;
        node->lights->a.l.col[1] = 0;
        node->lights->a.l.col[2] = 0;
        // Geo_NodeAmbientLight conditionally enables the unnamed 0x00400000 bit.
        gSPClearGeometryMode(D_800D0510++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | 0x00400000);
        gSPSetGeometryMode(D_800D0510++, G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
        gSPTexture(D_800D0510++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
        gDPSetCycleType(D_800D0510++, G_CYC_2CYCLE);
        ModelAnim_ResetCurveContext();
        ModelAnim_ResetEventContext();
        func_80039070(0);
        GeoRender_ResetTransformStack();
        gSPMatrix(D_800D0510++, (u32)((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top] & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        D_80094910 = node;
        Geo_ProcessNodeChildren(root);
        D_80094910 = NULL;
    }
    node->unk_1A = D_80094904;
}

void Geo_NodeModelPartRoot(void *root) {
    void *node;
    node = root;
    if (D_80094914 == NULL && ((S1_GraphNode *)node)->unk_0C != NULL) {
        D_80094914 = (S1_unk_D_86002F34_00C *)node;
        GeoRender_InitMaterialState(((S1_GraphNode *)node)->unk_02 & 7, D_80094900);
        Geo_ProcessNodeChildren(root);
        GeoRender_FlushMaterialSlots();
        D_80094914 = NULL;
    }
}

void Geo_NodeOrtho(void *root) {
    if (D_80094914 == NULL && ((S1_GraphNode *)root)->unk_0C != NULL) {
        gSPPerspNormalize(D_800D0510++, 0xFFFF);
        gSPMatrix(D_800D0510++, (u32)((S1_unk_D_86002F34_00C *)D_80094908)->unk_40.mtx & 0x1FFFFFFF,
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
        Geo_NodeModelPartRoot(root);
    }
}

void Geo_NodePerspective(void *root) {
    if (D_80094914 == NULL && ((S1_GraphNode *)root)->unk_0C != NULL) {
        gSPLookAt(D_800D0510++, (u32)(((S1_unk_D_86002F34_00C *)D_80094908)->unk_60.lookat) & 0x1FFFFFFF);
        gSPPerspNormalize(D_800D0510++, ((S1_unk_D_86002F34_00C *)D_80094908)->unk_24.perspNorm);
        gSPMatrix(D_800D0510++, (u32)((S1_unk_D_86002F34_00C *)D_80094908)->unk_24.mtx & 0x1FFFFFFF,
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
        gSPMatrix(D_800D0510++, (u32)((S1_unk_D_86002F34_00C *)D_80094908)->unk_60.p_mtxf & 0x1FFFFFFF,
                  G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
        Geo_NodeModelPartRoot(root);
    }
}

void Geo_NodeBackground(u8 *arg0) { u8 *state = (u8 *)D_80094908 + 0x18; GfxImage_FillRectangle(&D_800D0510, *(s16 *)(state + 4), *(s16 *)(state + 6), *(s16 *)(state + 8), *(s16 *)(state + 10), *(s32 *)(arg0 + 0x18)); gDPPipeSync(D_800D0510++); gSPSetOtherMode(D_800D0510++, G_SETOTHERMODE_H, 20, 2, 0x100000); }

void Geo_NodeClearDepth(s32 arg0) {
    void *state = (u8 *)D_80094908 + 0x18;
    GfxImage_ClearDepthRectangle(&D_800D0510, *(s16 *)((u8 *)state + 4), *(s16 *)((u8 *)state + 6), *(s16 *)((u8 *)state + 8), *(s16 *)((u8 *)state + 10));
    gDPPipeSync(D_800D0510++);
    gDPSetCycleType(D_800D0510++, G_CYC_2CYCLE);
}

void func_8003AC84(s32 arg0) {}

void Geo_NodeFog(S1_GraphNode *root) {
    S1_unk_D_86002F34_alt3 *node = (S1_unk_D_86002F34_alt3 *)root;
    D_80094910->unknown1D = 1;
    D_80094910->unknown20 = node->unk_1C;
    gSPFogPosition(D_800D0510++, node->unk_18, node->unk_1A);
    gSPSetGeometryMode(D_800D0510++, G_FOG);
    gDPSetColor(D_800D0510++, G_SETFOGCOLOR, node->unk_1C);
}

void Geo_NodeLight(S1_GraphNode *root) {
    SceneDirectionalLight *node = (SceneDirectionalLight *)root;
    SceneLightRecord *light;
    s32 index;
    if (D_80094910->lightCount >= 7) {
        return;
    }
    light = (SceneLightRecord *)&D_80094910->lights->l[D_80094910->lightCount];
    if (node->overrideDirection == 0) {
        light->directional.l.pad1 = 0;
        *(u32 *)light->directional.l.col = node->color.rgba;
        *(u32 *)light->directional.l.colc = node->color.rgba;
        light->directional.l.dir[0] = (120.0f * D_80088E50[((u16)node->pitch >> 4)]) * D_80087E50[((u16)node->yaw >> 4)];
        light->directional.l.dir[1] = 120.0f * D_80087E50[((u16)node->pitch >> 4)];
        light->directional.l.dir[2] = (120.0f * D_80088E50[((u16)node->pitch >> 4)]) * D_80088E50[((u16)node->yaw >> 4)];
    } else {
        light->point.color = node->color.rgba;
        light->point.colorCopy = node->color.rgba;
        light->point.position.x = node->direction.x;
        light->point.position.y = node->direction.y;
        light->point.position.z = node->direction.z;
        light->directional.l.pad1 = node->red;
        light->directional.l.pad2 = node->green;
        light->point.quadratic = node->blue;
        D_80094910->extraGeometryMode++;
    }
    D_80094910->lightCount++;
    if (node->node.unk_02 & 1) {
        gMoveWd(D_800D0510++, G_MW_NUMLIGHT, 0, D_80094910->lightCount * 0x18);
        for (index = D_80094910->activeLights; index < D_80094910->lightCount; index++) {
            gSPLight(D_800D0510++, &D_80094910->lights->l[index], index + 1);
        }
        gSPLight(D_800D0510++, D_80094910->lights, index + 1);
    }
}

void func_8003B03C(s32 arg0) {}

void Geo_NodeAmbientLight(void *root) {
    SceneAmbientLightNode *node = root;
    s32 i;
    Lights7 *lights;
    lights = D_80094910->lights;
    if (node->color.r == 0xFF && node->color.g == 0xFF && node->color.b == 0xFF) {
        lights->a.l.colc[0] = lights->a.l.col[0];
        lights->a.l.colc[1] = lights->a.l.col[1];
        lights->a.l.colc[2] = lights->a.l.col[2];
    } else {
        lights->a.l.colc[0] = lights->a.l.col[0] = node->color.r;
        lights->a.l.colc[1] = lights->a.l.col[1] = node->color.g;
        lights->a.l.colc[2] = lights->a.l.col[2] = node->color.b;
    }
    D_80094910->activeLights = D_80094910->lightCount;
    gSPSetGeometryMode(D_800D0510++, G_LIGHTING);
    if (D_80094910->extraGeometryMode > 0) {
        gSPSetGeometryMode(D_800D0510++, 0x00400000);
    }
    gMoveWd(D_800D0510++, G_MW_NUMLIGHT, 0, D_80094910->lightCount * 0x18);
    for (i = 0; i < D_80094910->lightCount; i++) {
        gSPLight(D_800D0510++, &D_80094910->lights->l[i], i + 1);
    }
    gSPLight(D_800D0510++, D_80094910->lights, i + 1);
}

void Geo_NodeUpdateLights(S1_GraphNode *root) {
    s32 index;
    if (D_80094910->activeLights != D_80094910->lightCount) {
        D_80094910->lightCount = D_80094910->activeLights;
        gMoveWd(D_800D0510++, G_MW_NUMLIGHT, 0, D_80094910->lightCount * 0x18);
        for (index = 0; index < D_80094910->lightCount; index++) {
            gSPLight(D_800D0510++, &D_80094910->lights->l[index], index + 1);
        }
        gSPLight(D_800D0510++, D_80094910->lights, index + 1);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/340C0/func_8003B350.s")

void Geo_NodeCullDistance(S1_GraphNode *root) {
    S1_unk_D_86002F34_alt3 *range = (S1_unk_D_86002F34_alt3 *)root;
    S1_MtxF *view = &((S1_unk_D_86002F34_00C *)D_80094908)->unk_60.mtxf;
    f32 x = ((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top].mf[3][0];
    f32 y = ((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top].mf[3][1];
    f32 z = ((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top].mf[3][2];
    s16 depth = ((x * view->mf[0][2]) + (y * view->mf[1][2]) + (z * view->mf[2][2])) + view->mf[3][2];
    if ((depth >= range->unk_18) && (depth < range->unk_1A)) {
        Geo_ProcessNodeChildren(root);
    }
}

void Geo_NodeSwitchCase(S1_GraphNode *root) {
    S1_unk_D_86002F34_alt3 *selection = (S1_unk_D_86002F34_alt3 *)root;
    s32 index;
    S1_GraphNode *child = (S1_GraphNode *)selection->unk_00.unk_0C;
    if (child != NULL) {
        for (index = 0; index < selection->unk_1A; index++) {
            child = child->unk_08;
        }
    }
    if (child->unk_01 & 1) {
        ((void (*)(S1_GraphNode *))D_80094924[child->unk_00])(child);
    }
}

void func_8003B5AC(u8 *arg0) {
    struct {
        u8 unused[8];
        f32 matrix[4][4];
    } scratch;

    MtxF_SetRotationTranslationF(scratch.matrix, (Vec3f35784 *)(arg0 + 0x18), (Vec3s35AA0 *)(arg0 + 0x24));
    GeoRender_PushMultipliedMatrix((S1_MtxF *)scratch.matrix, NULL);
    Geo_ProcessNodeChildren(arg0);
    *(s32 *)((u8 *)&D_80124F68 + 0x10A0) -= 1;
}

void func_8003B600(u8 *arg0) {
    s32 status = 0;
    if (D_80094920 != NULL && (*(u16 *)(D_80094920 + 0x28) & 1) != 0) {
        status = 1;
    }
    if (status != 0) {
        GeoRender_PushScaledMatrix((S1_Vec3f *)(arg0 + 0x18), (Mtx *)D_8009499C);
    } else {
        D_8009499C = (s32)GeoRender_PushScaledMatrix((S1_Vec3f *)(arg0 + 0x18), NULL);
    }
    Geo_ProcessNodeChildren(arg0);
    (*(s32 *)((u8 *)&D_80124F68 + 0x10A0))--;
}

void func_8003B690(s32 arg0) {
    D_8009499C = (s32)GeoRender_PushScaledMatrix((S1_Vec3f *)(arg0 + 0x18), NULL);
    Geo_PrepareShadowChildren(arg0);
    (*(s32 *)((u8 *)(&D_80124F68) + (0x10A0))) = (s32) ((*(s32 *)((u8 *)(&D_80124F68) + (0x10A0))) - 1);
}

void Geo_NodeAnimatedPart(s32 root) {
    S1_Vec3s rotation;
    S1_Vec3f position;
    S1_Vec3f scaling;
    S1_MtxF matrix;
    S1_unk_D_86002F34_alt6 *node = (S1_unk_D_86002F34_alt6 *)root;
    s32 pushed;
    s32 reuse;
    pushed = 0;
    reuse = 0;
    if (D_80094920 != NULL && (*(u16 *)(D_80094920 + 0x28) & 1) != 0) {
        reuse = 1;
    }
    rotation = node->unk_1E;
    scaling = node->unk_24;
    Vec3f_FromVec3s((Vec3f358AC *)&position, (Vec3s358AC *)&node->unk_18);
    func_8003E8C8(&position, &rotation, &scaling, node->unk_32 * 3);
    if (node->unk_31 & 2) {
        MtxF_BuildTransform(&matrix, &position, &rotation, &scaling, &((S1_unk_D_86002F34_00C *)D_80094908)->unk_60.mtxf, &((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top]);
        ((SceneTransformPool *)&D_80124F68)->top++;
        if (reuse != 0) {
            GeoRender_SetMatrix(&matrix, (Mtx *)D_80124D68[node->unk_30]);
        } else {
            GeoRender_SetMatrix(&matrix, NULL);
        }
    } else if (node->unk_31 & 1) {
        MtxF_SetRotationScaleTranslation(&matrix, &position, &rotation, &scaling);
        if (reuse != 0) {
            GeoRender_PushMultipliedMatrix(&matrix, (Mtx *)D_80124D68[node->unk_30]);
        } else {
            GeoRender_PushMultipliedMatrix(&matrix, NULL);
        }
    } else {
        MtxF_SetRotationAndScaledTranslation(&matrix, &position, &rotation, &((SceneScaleStack *)&D_80126010)->vectors[((SceneScaleStack *)&D_80126010)->top]);
        ((SceneTransformPool *)&D_80124F68)->top++;
        func_800393F0(&scaling);
        if (((SceneTransformPool *)&D_80124F68)->flags[((SceneTransformPool *)&D_80124F68)->top - 1] == 1) {
            MtxF_Multiply(&((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top + 32], &matrix, &((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top + 31]);
        } else {
            MtxF_Multiply(&((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top + 32], &matrix, &((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top - 1]);
        }
        MtxF_ScaleRows(&((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top], &((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top + 32], &((SceneScaleStack *)&D_80126010)->vectors[((SceneScaleStack *)&D_80126010)->top]);
        if (reuse != 0) {
            GeoRender_CommitMatrix((Mtx *)D_80124D68[node->unk_30]);
        } else {
            GeoRender_CommitMatrix(NULL);
        }
        ((SceneTransformPool *)&D_80124F68)->flags[((SceneTransformPool *)&D_80124F68)->top] = 1;
        pushed = 1;
    }
    if (reuse == 0) {
        D_80124D68[node->unk_30] = (s32)((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top];
    }
    Geo_ProcessNodeChildren((void *)root);
    ((SceneTransformPool *)&D_80124F68)->top--;
    if (pushed != 0) {
        ((SceneScaleStack *)&D_80126010)->top--;
    }
}

void Geo_PrepareAnimatedPart(s32 root) {
    S1_Vec3s rotation;
    S1_Vec3f position;
    S1_Vec3f scaling;
    S1_MtxF matrix;
    S1_unk_D_86002F34_alt6 *node = (S1_unk_D_86002F34_alt6 *)root;
    s32 pushed;
    pushed = 0;
    rotation = node->unk_1E;
    scaling = node->unk_24;
    Vec3f_FromVec3s((Vec3f358AC *)&position, (Vec3s358AC *)&node->unk_18);
    func_8003E8C8(&position, &rotation, &scaling, node->unk_32 * 3);
    if (node->unk_31 & 2) {
        MtxF_BuildTransform(&matrix, &position, &rotation, &scaling, &((S1_unk_D_86002F34_00C *)D_80094908)->unk_60.mtxf, &((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top]);
        ((SceneTransformPool *)&D_80124F68)->top++;
        GeoRender_SetMatrix(&matrix, NULL);
    } else if (node->unk_31 & 1) {
        MtxF_SetRotationScaleTranslation(&matrix, &position, &rotation, &scaling);
        GeoRender_PushMultipliedMatrix(&matrix, NULL);
    } else {
        MtxF_SetRotationAndScaledTranslation(&matrix, &position, &rotation, &((SceneScaleStack *)&D_80126010)->vectors[((SceneScaleStack *)&D_80126010)->top]);
        ((SceneTransformPool *)&D_80124F68)->top++;
        func_800393F0(&scaling);
        if (((SceneTransformPool *)&D_80124F68)->flags[((SceneTransformPool *)&D_80124F68)->top - 1] == 1) {
            MtxF_Multiply(&((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top + 32], &matrix, &((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top + 31]);
        } else {
            MtxF_Multiply(&((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top + 32], &matrix, &((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top - 1]);
        }
        MtxF_ScaleRows(&((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top], &((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top + 32], &((SceneScaleStack *)&D_80126010)->vectors[((SceneScaleStack *)&D_80126010)->top]);
        GeoRender_CommitMatrix(NULL);
        ((SceneTransformPool *)&D_80124F68)->flags[((SceneTransformPool *)&D_80124F68)->top] = 1;
        pushed = 1;
    }
    D_80124D68[node->unk_30] = (s32)((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top];
    Geo_PrepareShadowChildren(root);
    ((SceneTransformPool *)&D_80124F68)->top--;
    if (pushed != 0) {
        ((SceneScaleStack *)&D_80126010)->top--;
    }
}

void func_8003BC48(void *arg0) {
    if (*(s32 *)((u8 *)arg0 + 0x18) != 0) {
        GeoRender_SubmitMaterial(*((u8 *)arg0 + 3), D_80124D68[*(s16 *)((u8 *)arg0 + 0x1C)]);
        func_8003DA20(*(s32 *)((u8 *)arg0 + 0x18), (*((u8 *)arg0 + 2) & 4) != 0);
    }
    Geo_ProcessNodeChildren(arg0);
}

void Geo_NodeModelPart(void *root) {
    S1_MtxF matrix;
    S1_Color_RGBA8_u32 reset_color;
    S1_unk_D_86002F58_004_000 *node = (S1_unk_D_86002F58_004_000 *)root;
    if (node->animType == *(s16 *)((u8 *)D_80094910 + 0x18) || node->animType == 10) {
        node->anchorCount = 0;
        func_8003E7B0((S1_unk_D_86002F58_004_000_040_raw *)&node->unk_040, D_80094904, (node->unk_000.unk_02 & 0x20) != 0);
        ModelAnim_BeginEventContext(&node->unk_054, D_80094904, (node->unk_000.unk_02 & 0x20) != 0);
        if (node->unk_000.unk_02 & 0x10) {
            MtxF_Multiply(&matrix, &node->unk_060, &((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top]);
        } else if (node->unk_000.unk_02 & 8) {
            func_80036714(&matrix, (s32)&((S1_unk_D_86002F34_00C *)D_80094908)->unk_60.mtxf, (s32)&((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top], (s32)&node->unk_024, 1.0f);
        } else if (node->unk_000.unk_02 & 0x80) {
            MtxF_SetRotationAndTransformTranslation(matrix.mf, (Vec3f35784 *)&node->unk_024, (Vec3s35AA0 *)&node->unk_01E);
            MtxF_Multiply(&matrix, &matrix, &((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top]);
        } else {
            MtxF_SetRotationTranslationF(matrix.mf, (Vec3f35784 *)&node->unk_024, (Vec3s35AA0 *)&node->unk_01E);
            MtxF_Multiply(&matrix, &matrix, &((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top]);
        }
        MtxF_ScaleRows(&((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top + 1], &matrix, &node->unk_030);
        if (!(node->unk_000.unk_02 & 4)) {
            ((SceneTransformPool *)&D_80124F68)->top++;
            GeoRender_CommitMatrix(NULL);
            D_8009491C = node;
            GeoRender_SetMaterialParams(node->unk_0A0, node->materialAlpha, node->textureMode);
            if (node->modelId >= 0) {
                func_800707D0(node);
            }
            Geo_ProcessNodeChildren(root);
            if (node->modelId >= 0) {
                func_80070860((s32)node);
            }
            reset_color.rgba = 0xFFFFFF00;
            GeoRender_SetMaterialParams(reset_color, 0xFF, 0);
            D_8009491C = NULL;
        }
        ModelAnim_EndCurveContext();
        ModelAnim_EndEventContext();
        ((SceneTransformPool *)&D_80124F68)->top--;
    }
}

void func_8003BEF0(void *arg0) { s32 *counter = &D_80126008; GeoRender_PushMultipliedMatrix((u8 *)arg0 + 0x1C, 0); if (*(s32 *)((u8 *)arg0 + 0x18) != 0 || *(s32 *)((u8 *)arg0 + 0x10) != 0) { GeoRender_SubmitMaterial(*((u8 *)arg0 + 3), ((s32 *)&D_80124F68)[*(s32 *)((u8 *)&D_80124F68 + 0x10A0) + 0x400]); if (*(void **)((u8 *)arg0 + 0x10) != 0) ((void (*)(s32, void *))(*(void **)((u8 *)arg0 + 0x10)))(5, arg0); func_8003DA20(*(s32 *)((u8 *)arg0 + 0x18), (*((u8 *)arg0 + 2) & 4) != 0); } Geo_ProcessNodeChildren(arg0); *counter = *counter - 1; }

void func_8003BF9C(void *arg0) {
    S1_MtxF sp30;
    u8 (*pool)[0x40] = (u8 (*)[0x40])(void *)&D_80124F68;
    func_80036714(&sp30, (s32)((u8 *)D_80094908 + 0x64), (s32)pool[*(s32 *)((u8 *)&D_80124F68 + 0x10A0)], (s32)((u8 *)arg0 + 0x1C), *(f32 *)((u8 *)arg0 + 0x28));
    (*(s32 *)((u8 *)&D_80124F68 + 0x10A0))++;
    GeoRender_SetMatrix(&sp30, 0);
    if (*(s32 *)((u8 *)arg0 + 0x18) != 0 || *(s32 *)((u8 *)arg0 + 0x10) != 0) {
        GeoRender_SubmitMaterial(*((u8 *)arg0 + 3), ((s32 *)&D_80124F68)[*(s32 *)((u8 *)&D_80124F68 + 0x10A0) + 0x400]);
        if (*(void **)((u8 *)arg0 + 0x10) != 0) ((void (*)(s32, void *))(*(void **)((u8 *)arg0 + 0x10)))(5, arg0);
        func_8003DA20(*(s32 *)((u8 *)arg0 + 0x18), (*((u8 *)arg0 + 2) & 4) != 0);
    }
    Geo_ProcessNodeChildren(arg0);
    (*(s32 *)((u8 *)&D_80124F68 + 0x10A0))--;
}

void Geo_NodeDisplayList(void *arg0) {
    void *root = arg0;
    s32 callback;
    if (*(s32 *)((u8 *)root + 0x18) != 0 || *(s32 *)((u8 *)root + 0x10) != 0) {
        GeoRender_SubmitMaterial(*(u8 *)((u8 *)root + 3), ((s32 *)((u8 *)&D_80124F68 + 0x1000))[*(s32 *)((u8 *)&D_80124F68 + 0x10A0)]);
        callback = *(s32 *)((u8 *)root + 0x10);
        if (callback != 0) ((void (*)(s32, void *))callback)(5, root);
        func_8003DA20(*(s32 *)((u8 *)root + 0x18), (*(u8 *)((u8 *)root + 2) & 4) != 0);
    }
    Geo_ProcessNodeChildren(root);
}

void Geo_NodeShadowTexture(void *root) {
    CandidateColor color;
    S1_unk_D_86002F34_alt10 *node = (S1_unk_D_86002F34_alt10 *)root;
    s32 texture;
    s32 material;
    s32 display_list;
    texture = 0;
    material = 0;
    display_list = (s32)node->unk_18;
    if (node->unk_22 == 1) {
        color.rgba = 0xFFFFFFFF;
    } else {
        color.rgba = node->unk_24.rgba;
    }
    if (node->unk_1C >= 0) {
        texture = *(s32 *)(D_80094920 + 0x18) + node->unk_1C * 12;
    }
    if (node->unk_1E >= 0) {
        material = *(s32 *)(D_80094920 + 0x1C) + node->unk_1E * 12;
    }
    if (D_8009491C != NULL) {
        color.r = (color.r * ((S1_unk_D_86002F58_004_000 *)D_8009491C)->unk_03C.r) / 255;
        color.g = (color.g * ((S1_unk_D_86002F58_004_000 *)D_8009491C)->unk_03C.g) / 255;
        color.b = (color.b * ((S1_unk_D_86002F58_004_000 *)D_8009491C)->unk_03C.b) / 255;
    }
    func_8003EE20(&texture, *(s32 *)(D_80094920 + 0x18), node->unk_20);
    GeoRender_SetMaterialTexture(node->unk_22, color, (void *)texture, (void *)material, display_list);
    Geo_ProcessNodeChildren(root);
}

void func_8003C2D8(s32 id) {
    S1_MtxF *matrix;
    SceneAnchorPosition *anchor;
    if (((SceneDisplayObjectAnchors *)D_8009491C) != NULL) {
        if (((SceneDisplayObjectAnchors *)D_8009491C)->anchorCount < 12) {
            anchor = &((SceneDisplayObjectAnchors *)D_8009491C)->anchors[
                ((SceneDisplayObjectAnchors *)D_8009491C)->anchorCount++];
            matrix = &((SceneTransformPool *)&D_80124F68)->matrices[
                ((SceneTransformPool *)&D_80124F68)->top];
            anchor->id = id;
            anchor->position.x = matrix->mf[3][0];
            anchor->position.y = matrix->mf[3][1];
            anchor->position.z = matrix->mf[3][2];
        }
    }
}

void Geo_NodeAnchor(void *arg0) {
    func_8003C2D8(*(s16 *)((u8 *)arg0 + 0x18));
    Geo_ProcessNodeChildren(arg0);
}

 void Geo_NodeGroup(void *arg0) { Geo_ProcessNodeChildren(arg0); }

void Geo_NodeShadow(S1_unk_D_86002F34_alt12 *node) {
    Vec3f35784 position;
    Vec3f35784 up;
    S1_Vec3f scale;
    f32 height_scale;
    S1_MtxF basis;
    S1_MtxF *current;
    Gfx *commands;

    current = &((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top];
    commands = Gfx_AllocDisplayList(2 * sizeof(Gfx));
    if (GeoRender_FindAnchorPosition(D_8009491C, 100, NULL) == NULL) {
        func_8003C2D8(100);
    }
    Vec3f_SetComponentsDuplicate(&position, current->mf[3][0], current->mf[3][1] + node->unk_1E, current->mf[3][2]);
    position.y = 0.0f;
    if (((S1_unk_D_86002F58_004_000 *)D_8009491C)->unk_000.unk_02 & 0x40) {
        Vec3f_SetComponentsDuplicate(&up, 0.0f, 1.0f, 0.0f);
        func_80036D8C(&current->mf[0][0], &scale.x);
        height_scale = 1.0f - ((current->mf[3][1] - position.y) / 1000.0f);
        if (height_scale < 0.5f) {
            height_scale = 0.5f;
        }
        if (height_scale > 1.0f) {
            height_scale = 1.0f;
        }
        scale.x *= (node->unk_1A / 100.0f) * height_scale;
        scale.z *= (node->unk_1C / 100.0f) * height_scale;
        MtxF_SetOrthonormalBasis(basis.mf, &up, &position, ((S1_unk_D_86002F58_004_000 *)D_8009491C)->unk_01E.y);
        MtxF_ScaleRows(&((SceneTransformPool *)&D_80124F68)->matrices[((SceneTransformPool *)&D_80124F68)->top + 1], &basis, &scale);
        ((SceneTransformPool *)&D_80124F68)->top++;
        GeoRender_CommitMatrix(NULL);
        if (node->unk_18 == 0) {
            gSPBranchList(&commands[1], func_80003240(D_1000C80));
        } else {
            gSPBranchList(&commands[1], func_80003240(D_1000D08));
        }
        gDPSetEnvColor(&commands[0], 0, 0, 0, (s32)(120.0f * height_scale));
        if (((S1_unk_D_86002F58_004_000 *)D_8009491C)->unk_000.unk_02 & 2) {
            GeoRender_SubmitMaterial(7, ((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top]);
        } else {
            GeoRender_SubmitMaterial(6, ((SceneTransformPool *)&D_80124F68)->stack[((SceneTransformPool *)&D_80124F68)->top]);
        }
        gDPSetFogColor(D_800D0510++, 255, 255, 255, 0);
        gDPSetPrimColor(D_800D0510++, 0, ((S1_unk_D_86002F58_004_000 *)D_8009491C)->materialAlpha, 255, 255, 255, 255);
        func_8003DA20((u32)commands & 0x1FFFFFFF, 1);
        Geo_ProcessNodeChildren(node);
        ((SceneTransformPool *)&D_80124F68)->top--;
    }
}

void Geo_RenderRootNode(u8 *node) {
    if (node[1] & 1) {
        gDPPipeSync(D_800D0510++);
        gDPSetTextureLOD(D_800D0510++, G_TL_TILE);
        gDPSetTextureLUT(D_800D0510++, G_TT_NONE);
        gDPSetTextureDetail(D_800D0510++, G_TD_CLAMP);
        gDPSetTexturePersp(D_800D0510++, G_TP_PERSP);
        gDPSetTextureFilter(D_800D0510++, G_TF_BILERP);
        gDPSetTextureConvert(D_800D0510++, G_TC_FILT);
        gDPSetCombineKey(D_800D0510++, G_CK_NONE);
        gDPSetAlphaCompare(D_800D0510++, G_AC_NONE);
        gDPSetColorDither(D_800D0510++, G_CD_MAGICSQ);
        gDPSetAlphaDither(D_800D0510++, G_AD_PATTERN);
        func_8006D2C0();
        D_8009490C = (s32)node;
        Geo_ProcessNodeChildren(node);
        D_8009490C = 0;
    }
    D_80094900 = 0;
}

void Geo_ProcessCallbacks(S1_GraphNode *root, s32 event) {
    S1_GraphNode *node = root;
    S1_GraphNode **slot;
    do {
        if (node->unk_10 != NULL) {
            node->unk_10(event, node);
        }
        if (node->unk_0C != NULL) {
            switch (node->unk_00) {
            default:
                slot = NULL;
                break;
            case 2:
                slot = (S1_GraphNode **)&D_80094908;
                break;
            case 4:
                slot = (S1_GraphNode **)&D_80094910;
                break;
            case 6:
                slot = (S1_GraphNode **)&D_80094918;
                break;
            case 22:
                slot = (S1_GraphNode **)&D_8009491C;
                break;
            }
            if (slot != NULL) {
                *slot = node;
            }
            Geo_ProcessCallbacks((S1_GraphNode *)node->unk_0C, event);
            if (slot != NULL) {
                *slot = NULL;
            }
        }
        node = node->unk_08;
    } while (node != root);
}

void func_8003C964(s32 value) { D_80094900 = value; }

void GeoRender_AdvanceFrameCounter(void) { D_80094904++; }

s32 GeoRender_IsModelFrameCurrent(void) { s32 var_v1 = 1; if (D_80094910 != NULL) { var_v1 = D_80094910->unk_1A == D_80094904; } return var_v1; }

S1_Vec3f *GeoRender_FindAnchorPosition(u8 *object, s16 id, S1_Vec3f *out) {
    s32 i;
    for (i = 0; i < object[0xA7]; i++) {
        if (id == *(u16 *)(object + i * 0x10 + 0xA8)) {
            if (out != NULL) {
                *out = *(S1_Vec3f *)(object + i * 0x10 + 0xAC);
            }
            return (S1_Vec3f *)(object + i * 0x10 + 0xAC);
        }
    }
    return NULL;
}

#pragma C_FUNCTION_PADDING(8)

void func_8003CA30(Gfx* arg0, S1_arg1_func_81407874_014_000_010* arg1) {
    gDPSetCombine(arg0++,
                  GCCc0w0(arg1->unk_00, arg1->unk_02, arg1->unk_04, arg1->unk_06) | GCCc1w0(arg1->unk_08, arg1->unk_0A),

                  GCCc0w1(arg1->unk_01, arg1->unk_03, arg1->unk_05, arg1->unk_07) |
                      GCCc1w1(arg1->unk_09, arg1->unk_0C, arg1->unk_0E, arg1->unk_0B, arg1->unk_0D, arg1->unk_0F));
}

void func_8003CB3C(Gfx *arg0, u8 arg1, u8 arg2) {
    S1_arg1_func_81407874_014_000_010 local;
    local = D_80094AAC[arg1];
    if (arg2 == 0xFF) {
        local.unk_0C = 7; local.unk_0D = 7; local.unk_0E = 7; local.unk_0F = 0;
    }
    func_8003CA30(arg0, &local);
}

void func_8003CBD4(void) {
    Gfx *command;
    if (D_801261A8 == 0) {
        D_801261A8 = 1;
        command = D_800D0510++;
        command->words.w1 = 0;
        command->words.w0 = 0xE7000000;
    }
}

void GeoRender_SetRenderMode(void) {
    s32 mode = D_800949A4[D_801261A0][((SceneMaterialState *)D_801263A8)->unknown24];
    D_801261A8 = 1;
    gDPPipeSync(D_800D0510++);
    ((SceneMaterialState *)D_801263A8)->fogColor.rgba = 0;
    gDPSetColor(D_800D0510++, G_SETFOGCOLOR, D_80094910->unknown20);
    if ((D_801261A4 & 1) && D_801261A0 == 1 && (((SceneMaterialState *)D_801263A8)->unknown24 == 6 || ((SceneMaterialState *)D_801263A8)->unknown24 == 8)) {
        mode = 0x107A58;
    }
    if (D_80094910->unknown1D != 0) {
        gDPSetRenderMode(D_800D0510++, mode, 0xC8000000);
    } else {
        gDPSetRenderMode(D_800D0510++, mode, 0x0C080000);
    }
}

s32 func_8003CD58(s32 arg0) { s32 var_v1; if ((arg0 != 0) && (arg0 != 5) && (arg0 != 0xA)) { var_v1 = 0; } else { var_v1 = 1; } return var_v1; }

void GeoRender_ApplyMaterialState(void) {
    S1_Color_RGBA8_u32 color;
    color.rgba = ((SceneMaterialState *)D_801263A8)->primitiveColor.rgba;
    ((SceneMaterialState *)D_801263A8)->unknown18 = NULL;
    ((SceneMaterialState *)D_801263A8)->unknown1C = NULL;
    ((SceneMaterialState *)D_801263A8)->unknown0C = NULL;
    ((SceneMaterialState *)D_801263A8)->unknown27 = 0;
    D_801261A8 = 1;
    gDPPipeSync(D_800D0510++);
    gDPSetPrimColor(D_800D0510++, 0, ((SceneMaterialState *)D_801263A8)->primitiveLevel, color.r, color.g, color.b, color.a);
    gDPSetTextureLUT(D_800D0510++, G_TT_NONE);
    if (func_8003CD58(((SceneMaterialState *)D_801263A8)->combineMode) != 0) {
        gSPTexture(D_800D0510++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF);
    } else {
        gSPTexture(D_800D0510++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    }
    func_8003CB3C(D_800D0510++, ((SceneMaterialState *)D_801263A8)->combineMode, ((SceneMaterialState *)D_801263A8)->primitiveLevel);
    gSPSetGeometryMode(D_800D0510++, G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
    gSPClearGeometryMode(D_800D0510++, G_FOG | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
    gSPLookAt(D_800D0510++, (u32)((S1_unk_D_86002F34_00C *)D_80094908)->unk_60.lookat & 0x1FFFFFFF);
    if (D_80094910->unknown1D != 0) {
        gSPSetGeometryMode(D_800D0510++, G_FOG);
    }
}

void GeoRender_SetFogColor(SceneMaterialParameters *node) {
    if (node->fogColor.rgba != ((SceneMaterialState *)D_801263A8)->fogColor.rgba) {
        func_8003CBD4();
        gDPSetColor(D_800D0510++, G_SETFOGCOLOR, node->fogColor.rgba);
        gDPSetRenderMode(D_800D0510++, D_800949A4[D_801261A0][((SceneMaterialState *)D_801263A8)->unknown24], 0xC4000000);
        ((SceneMaterialState *)D_801263A8)->fogColor.rgba = node->fogColor.rgba;
    }
}

void GeoRender_RestoreRenderMode(s32 arg0) {
    if ((*(s32 *)((u8 *)(D_801263A8) + (0x14))) & 0xFF) {
        GeoRender_SetRenderMode();
    }
}

void GeoRender_SetPrimitiveColor(ScenePrimitiveColor *node) {
    if (node->color.rgba != ((SceneMaterialState *)D_801263A8)->primitiveColor.rgba ||
        node->level != ((SceneMaterialState *)D_801263A8)->primitiveLevel) {
        func_8003CBD4();
        gDPSetPrimColor(D_800D0510++, 0, node->level, node->color.r, node->color.g,
                       node->color.b, node->color.a);
        ((SceneMaterialState *)D_801263A8)->primitiveColor.rgba = node->color.rgba;
        ((SceneMaterialState *)D_801263A8)->primitiveLevel = node->level;
    }
}

void func_8003D188(u8 *arg0) {
    if (((u8 *)D_801263A8)[0x25] != arg0[0]) {
        func_8003CBD4();
        func_8003CB3C(D_800D0510++, arg0[0], arg0[1]);
        ((u8 *)D_801263A8)[0x25] = arg0[0];
    }
}

void func_8003D1F8(s32 arg0) { if (func_8003CD58(((u8 *)D_801263A8)[0x25]) == 0) { Gfx *command = D_800D0510++; command->words.w0 = 0xD7000000; command->words.w1 = 0xFFFFFFFF; } *(s32 *)((u8 *)D_801263A8 + 0x18) = 0; *(s32 *)((u8 *)D_801263A8 + 0x1C) = 0; *(s32 *)((u8 *)D_801263A8 + 0x20) = 0; }

void GeoRender_BindTexture(SceneMaterialParameters *node) {
    SceneBoundTexture *texture;
    s32 imageSize;
    if (func_8003CD58(((SceneMaterialState *)D_801263A8)->combineMode)) {
        gSPTexture(D_800D0510++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    }
    if (node->texture != NULL && node->displayList != NULL) {
        if (node->texture != ((SceneMaterialState *)D_801263A8)->unknown18 || node->displayList != ((SceneMaterialState *)D_801263A8)->unknown20) {
            texture = node->texture;
            if (node->material != NULL) {
                gSPDisplayList(D_800D0510++, ((SceneBoundPalette *)node->material)->displayList);
            } else {
                gDPSetTextureLUT(D_800D0510++, G_TT_NONE);
            }
            if (texture->size == 0) {
                if ((texture->width % D_80094B9C[0]) == 0) {
                    gDPSetTextureImage(D_800D0510++, texture->format, G_IM_SIZ_16b, 1, texture->image);
                } else {
                    gDPSetTextureImage(D_800D0510++, texture->format, G_IM_SIZ_8b, texture->width >> 1, texture->image);
                }
            } else if ((texture->width % D_80094B9C[texture->size]) == 0) {
                if (texture->size == 3) {
                    imageSize = 3;
                } else {
                    imageSize = 2;
                }
                gDPSetTextureImage(D_800D0510++, texture->format, imageSize, 1, texture->image);
            } else {
                gDPSetTextureImage(D_800D0510++, texture->format, texture->size, texture->width, texture->image);
            }
            gSPDisplayList(D_800D0510++, node->displayList);
        }
        ((SceneMaterialState *)D_801263A8)->unknown18 = node->texture;
        ((SceneMaterialState *)D_801263A8)->unknown1C = node->material;
        ((SceneMaterialState *)D_801263A8)->unknown20 = node->displayList;
    }
}

void GeoRender_EnableTextureGeneration(SceneMaterialParameters *node) {
    void *texture;
    if (((SceneMaterialState *)D_801263A8)->unknown27 == 0) {
        texture = D_1000000;
        switch (node->textureVariant) {
        case 1:
            break;
        case 2:
            texture = D_10019D0;
            break;
        }
        gDPLoadTextureBlock(D_800D0510++, texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 5, 5, 1, 1);
        gSPTexture(D_800D0510++, 0x1194, 0x1194, 0, G_TX_RENDERTILE, G_ON);
        gSPSetGeometryMode(D_800D0510++, G_TEXTURE_GEN);
        gSPClearGeometryMode(D_800D0510++, G_TEXTURE_GEN_LINEAR);
        gDPSetCombineMode(D_800D0510++, G_CC_MODULATEIDECALA, G_CC_PASS2);
        ((SceneMaterialState *)D_801263A8)->unknown27 = 1;
    }
}

void GeoRender_SelectMaterialSlot(s16 slot) {
    if (slot == D_801263AC) {
        return;
    }
    ((SceneMaterialState *)D_801263A8)->unknown08 = D_800D0510;
    gSPBranchList(D_800D0510++, NULL);
    D_801263AC = slot;
    D_801263A8 = &D_801261C8[D_801263AC];
    if (((SceneMaterialState *)D_801263A8)->unknown04 == NULL) {
        ((SceneMaterialState *)D_801263A8)->unknown04 = D_800D0510;
    } else if (((SceneMaterialState *)D_801263A8)->unknown08 != NULL) {
        gSPBranchList((Gfx *)((SceneMaterialState *)D_801263A8)->unknown08, D_800D0510);
    }
}

void func_8003D7B8(s16 arg0) {
    if (((arg0 > 0) && (arg0 < 4)) || (arg0 == 0x84) || (arg0 == 7)) {
        D_801261B0.textureVariant = D_801261B0.unknown02;
        return;
    }
    D_801261B0.textureVariant = 0;
}

s16 func_8003D808(s16 arg0) {
    s16 value = arg0 & 0xF;
    s16 result = value;
    if (D_801261B1 < 0xFF) {
        switch (value) {
        case 1: result = 5; break;
        case 2: result = 7; break;
        case 3: result = 8; break;
        case 4: result = 6; break;
        }
    }
    return result;
}

void GeoRender_SubmitMaterial(s16 format, Mtx *matrix) {
    if (D_800949A0 != 0 && !(D_801261A4 & 2) && D_801261B0.level > 0) {
        func_8003D7B8(format);
        GeoRender_SelectMaterialSlot(func_8003D808(format));
        D_801261A8 = 0;
        if (((SceneMaterialState *)D_801263A8)->unknown00 == 0) {
            GeoRender_SetRenderMode();
            GeoRender_ApplyMaterialState();
            ((SceneMaterialState *)D_801263A8)->unknown00 = 1;
        }
        if (D_801261B0.fogColor.rgba & 0xFF) {
            GeoRender_SetFogColor((&D_801261B0));
        } else {
            GeoRender_RestoreRenderMode((s32)(&D_801261B0));
        }
        if (D_801261B0.textureVariant != 0) {
            GeoRender_EnableTextureGeneration((&D_801261B0));
        } else {
            if (((SceneMaterialState *)D_801263A8)->unknown27 == 1) {
                GeoRender_ApplyMaterialState();
            }
            if (func_8003CD58(D_801261B0.mode)) {
                func_8003D1F8((s32)(&D_801261B0));
            } else {
                GeoRender_BindTexture((&D_801261B0));
            }
            GeoRender_SetPrimitiveColor((ScenePrimitiveColor *)(&D_801261B0));
            func_8003D188((u8 *)(&D_801261B0));
        }
        if (matrix != ((SceneMaterialState *)D_801263A8)->unknown0C) {
            ((SceneMaterialState *)D_801263A8)->unknown0C = matrix;
            gSPMatrix(D_800D0510++, (u32)matrix & 0x1FFFFFFF, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        }
    }
}

void func_8003DA20(s32 arg0, s32 arg1) {
    if (D_800949A0 != 0 && !(D_801261A4 & 2) && D_801261B1 > 0) {
        if (arg0 != 0) {
            if ((u32)arg0 >= 0x81000000U && (u32)arg0 < 0x90000000U) {
                Gfx *command = D_800D0510++;
                command->words.w0 = 0xDE000000;
                command->words.w1 = Memmap_GetFragmentVaddr((Gfx **)arg0);
            } else {
                Gfx *command = D_800D0510++;
                command->words.w1 = arg0;
                command->words.w0 = 0xDE000000;
            }
        }
        if (arg1 != 0) GeoRender_ApplyMaterialState();
    }
}

void GeoRender_SetMaterialParams(S1_Color_RGBA8_u32 color, u8 level, u32 flags) {
    D_801261B0.fogColor.rgba = color.rgba;
    D_801261B0.level = level;
    D_801261B0.unknown02 = flags;
}

void GeoRender_SetMaterialTexture(s32 arg0, CandidateColor arg1, void *arg2, void *arg3, s32 arg4) {
    D_801261B0.mode = arg0;
    D_801261B0.primitiveColor.rgba = arg1.rgba;
    D_801261B0.texture = arg2;
    D_801261B0.material = arg3;
    D_801261B0.displayList = arg4;
}

void GeoRender_InitMaterialState(s32 mode, s32 flags) {
    s32 index;
    SceneMaterialState *entry = D_801261C8;
    gDPPipeSync(D_800D0510++);
    gDPSetCycleType(D_800D0510++, G_CYC_2CYCLE);
    if (mode & 1) {
        gSPSetGeometryMode(D_800D0510++, G_ZBUFFER);
    } else {
        gSPClearGeometryMode(D_800D0510++, G_ZBUFFER);
    }
    for (index = 0; index < 12; index++, entry++) {
        entry->unknown04 = NULL;
        entry->unknown08 = NULL;
        entry->unknown00 = 0;
        entry->unknown0C = NULL;
        entry->primitiveColor.rgba = 0xFFFFFFFF;
        entry->fogColor.rgba = 0xFFFFFF00;
        entry->unknown18 = NULL;
        entry->unknown1C = NULL;
        entry->unknown20 = NULL;
        entry->unknown24 = index;
        entry->combineMode = 0;
        entry->unknown27 = 0;
        entry->primitiveLevel = 0xFF;
    }
    D_801261B0.mode = 0;
    D_801261B0.level = 0xFF;
    D_801261B0.unknown02 = 0;
    D_801261B0.textureVariant = 0;
    D_801261B0.primitiveColor.rgba = 0xFFFFFFFF;
    D_801261B0.fogColor.rgba = 0xFFFFFF00;
    D_801261B0.texture = NULL;
    D_801261B0.material = NULL;
    D_801261B0.displayList = NULL;
    D_801261A0 = mode;
    D_801261A4 = flags;
    D_801261C8[0].unknown04 = D_800D0510;
    D_801263AC = 0;
    D_801263A8 = D_801261C8;
    D_800949A0 = 1;
}

void GeoRender_FlushMaterialSlots(void) {
    s32 slot = 0;
    Gfx *branch;
    s32 next;
    GeoRender_SelectMaterialSlot(11);
    if (D_801261C8[0].unknown08 != NULL) {
        while (slot < 11) {
            next = slot + 1;
            branch = D_801261C8[slot].unknown08;
            slot++;
            while (D_801261C8[next].unknown04 == NULL) {
                next = slot + 1;
                slot++;
            }
            gSPBranchList(branch, D_801261C8[slot].unknown04);
        }
    }
    GeoRender_ApplyMaterialState();
    if (D_801261A0 & 1) {
        gSPClearGeometryMode(D_800D0510++, G_ZBUFFER);
    }
    D_800949A0 = 0;
}

#pragma C_FUNCTION_PADDING(4)

f32 ModelAnim_EvaluateTranslationChannel(S1_unk_D_800ABCC0* arg0, s32 arg1) {
    f32 ret;
    s32 var_a2;
    S1_unk_D_800ABCC0_008* temp_v0 = &arg0->channels[arg1];

    if (temp_v0->translationKeyCount == 1) {
        ret = temp_v0->translationBaseIndex / 1000.0f;
    } else {
        if (arg0->currentFrame < temp_v0->translationKeyCount) {
            var_a2 = temp_v0->translationBaseIndex + arg0->currentFrame;
        } else {
            var_a2 = (temp_v0->translationBaseIndex + temp_v0->translationKeyCount) - 1;
        }

        ret = arg0->translationValues[var_a2] / 1000.0f;
    }

    return ret;
}

s16 ModelAnim_EvaluateRotationChannel(S1_unk_D_800ABCC0* arg0, s32 arg1) {
    s32 var_a1;
    s16 var_v1;
    S1_unk_D_800ABCC0_008* temp_v0 = &arg0->channels[arg1];

    if (temp_v0->rotationKeyCount == 1) {
        var_v1 = temp_v0->rotationBaseIndex * 0x10;
    } else {
        if (arg0->currentFrame < temp_v0->rotationKeyCount) {
            var_a1 = temp_v0->rotationBaseIndex + arg0->currentFrame;
        } else {
            var_a1 = (temp_v0->rotationBaseIndex + temp_v0->rotationKeyCount) - 1;
        }
        var_v1 = func_80037360(arg0->rotationValues, var_a1, 0xC) * 0x10;
    }
    return var_v1;
}

f32 ModelAnim_EvaluateScaleChannel(S1_unk_D_800ABCC0* arg0, s32 arg1) {
    f32 var_fv1;
    s16 var_a2;
    s32 var_a1;
    S1_unk_D_800ABCC0_008* temp_v0 = &arg0->channels[arg1];

    if (temp_v0->scaleKeyCount == 1) {
        if (arg0->flags & 4) {
            var_fv1 = (s16)temp_v0->scaleBaseIndex;
        } else {
            var_a2 = temp_v0->scaleBaseIndex * 0x10;
            var_fv1 = var_a2 >> 4;
        }
    } else {
        if (arg0->currentFrame < temp_v0->scaleKeyCount) {
            var_a1 = temp_v0->scaleBaseIndex + arg0->currentFrame;
        } else {
            var_a1 = (temp_v0->scaleBaseIndex + temp_v0->scaleKeyCount) - 1;
        }

        if (arg0->flags & 4) {
            var_fv1 = func_80037360(arg0->scaleValues, var_a1, 0x10);
        } else {
            var_fv1 = func_80037360(arg0->scaleValues, var_a1, 0xC);
        }
    }

    return var_fv1;
}

f32 ModelAnim_InterpolateKeyframe(S1_Vec3s* arg0, s16 arg1, s16 arg2) {
    f32 y;
    s32 i;
    f32 x;
    f32 var_fv1;

    if (arg0->x >= arg2) {
        var_fv1 = arg0->y;
    } else {
        if (arg2 >= arg0[arg1 - 1].x) {
            var_fv1 = arg0[arg1 - 1].y;
        } else {
            for (i = 0; i < arg1 - 2; i++) {
                if (arg2 < arg0[i + 1].x) {
                    break;
                }
            }

            x = (arg2 - arg0[i].x) / 30.0f;
            y = 30.0f / (arg0[i + 1].x - arg0[i].x);

            var_fv1 = (arg0[i].y * (((2.0f * x * x * x * y * y * y) - 3.0f * x * x * y * y) + 1.0f))
                    + (arg0[i + 1].y * ((-2.0f * x * x * x * y * y * y) + 3.0f * x * x * y * y))
                    + (arg0[i].z * ((x * x * x * y * y - (2.0f * x * x * y)) + x))
                    + (arg0[i + 1].z * (x * x * x * y * y - (x * x * y)));
        }
    }
    return var_fv1;
}

f32 ModelAnim_InterpolateKeyframeTangent(S1_unk_func_80016B30_arg0* arg0, s16 arg1, s16 arg2) {
    f32 y;
    s32 i;
    f32 x;
    f32 var_fv1;

    if (arg0->vec.x >= arg2) {
        var_fv1 = arg0->vec.y;
    } else {
        if (arg2 >= arg0[arg1 - 1].vec.x) {
            var_fv1 = arg0[arg1 - 1].vec.y;
        } else {
            for (i = 0; i < arg1 - 2; i++) {
                if (arg2 < arg0[i + 1].vec.x) {
                    break;
                }
            }

            x = (arg2 - arg0[i].vec.x) / 30.0f;
            y = 30.0f / (arg0[i + 1].vec.x - arg0[i].vec.x);

            var_fv1 = (arg0[i].vec.y * (((2.0f * x * x * x * y * y * y) - 3.0f * x * x * y * y) + 1.0f))
                    + (arg0[i + 1].vec.y * ((-2.0f * x * x * x * y * y * y) + 3.0f * x * x * y * y))
                    + (arg0[i].unk_06 * ((x * x * x * y * y - (2.0f * x * x * y)) + x))
                    + (arg0[i + 1].vec.z * (x * x * x * y * y - (x * x * y)));
        }
    }
    return var_fv1;
}

f32 ModelAnim_EvaluateTranslationCurve(S1_unk_D_800ABCC0* arg0, s32 arg1) {
    f32 var_fv1;
    S1_unk_D_800ABCC0_008* temp_v0 = &arg0->channels[arg1];
    s16* tmp;

    if (temp_v0->translationKeyCount < 2) {
        var_fv1 = (s16)temp_v0->translationBaseIndex / 100.0f;
    } else {
        tmp = &arg0->translationValues[temp_v0->translationBaseIndex];
        if (temp_v0->unk_03 & 4) {
            var_fv1 = ModelAnim_InterpolateKeyframeTangent(tmp, temp_v0->translationKeyCount, arg0->currentFrame) / 100.0f;
        } else {
            var_fv1 = ModelAnim_InterpolateKeyframe(tmp, temp_v0->translationKeyCount, arg0->currentFrame) / 100.0f;
        }
    }
    return var_fv1;
}

s16 ModelAnim_EvaluateRotationCurve(S1_unk_D_800ABCC0* arg0, s32 arg1) {
    f32 var_fv1;
    s16* temp_a0;
    S1_unk_D_800ABCC0_008* temp_v0 = &arg0->channels[arg1];

    if (temp_v0->rotationKeyCount < 2) {
        var_fv1 = (s16)temp_v0->rotationBaseIndex / 10.0f;
    } else {
        temp_a0 = &arg0->rotationValues[temp_v0->rotationBaseIndex];
        if (temp_v0->unk_03 & 2) {
            var_fv1 = ModelAnim_InterpolateKeyframeTangent(temp_a0, temp_v0->rotationKeyCount, arg0->currentFrame) / 10.0f;
        } else {
            var_fv1 = ModelAnim_InterpolateKeyframe(temp_a0, temp_v0->rotationKeyCount, arg0->currentFrame) / 10.0f;
        }
    }

    while (var_fv1 < 0.0f) {
        var_fv1 += 360.0f;
    }

    while (var_fv1 >= 360.0f) {
        var_fv1 -= 360.0f;
    }

    return (var_fv1 / 360.0f) * 65536.0f;
}

f32 ModelAnim_EvaluateScaleCurve(S1_unk_D_800ABCC0* arg0, s32 arg1) {
    s16* temp_a0;
    f32 var_fv0;
    f32 var_fv1;
    S1_unk_D_800ABCC0_008* temp_v0 = &arg0->channels[arg1];

    if (temp_v0->scaleKeyCount < 2) {
        var_fv1 = (s16)temp_v0->scaleBaseIndex;
    } else {
        temp_a0 = &arg0->scaleValues[temp_v0->scaleBaseIndex];
        if (temp_v0->unk_03 & 1) {
            var_fv0 = ModelAnim_InterpolateKeyframeTangent(temp_a0, temp_v0->scaleKeyCount, arg0->currentFrame);
        } else {
            var_fv0 = ModelAnim_InterpolateKeyframe(temp_a0, temp_v0->scaleKeyCount, arg0->currentFrame);
        }
        var_fv1 = var_fv0;
    }
    return var_fv1;
}

s32 ModelAnim_AdvanceCurveFrame(S1_unk_D_86002F58_004_000_040_raw* arg0, u16 arg1) {
    S1_unk_D_86002F58_004_000_040_raw_08 spC;
    S1_unk_D_86002F58_004_000_040_raw_08* ptr;
    S1_unk_D_86002F58_004_000_040_004* temp_v0;

    ptr = &spC;
    temp_v0 = arg0->unk_04;
    spC.raw = arg0->unk_08.raw;
    if (arg0->unk_12 != arg1) {
        spC.raw += arg0->unk_0C;
        if (arg0->unk_0C >= 0) {
            if (ptr->unk_00 >= temp_v0->unk_0A) {
                if (temp_v0->unk_00 & 2) {
                    ptr->unk_00 = temp_v0->unk_0A - 1;
                } else {
                    ptr->unk_00 = temp_v0->unk_06;
                }
            }
        } else {
            if (ptr->unk_00 < temp_v0->unk_06) {
                if (temp_v0->unk_00 & 2) {
                    ptr->unk_00 = temp_v0->unk_06;
                } else {
                    ptr->unk_00 = temp_v0->unk_0A - 1;
                }
            }
        }
    }

    return spC.raw;
}

 void ModelAnim_ResetCurveContext(void) { D_801263E0 = -1; }

void func_8003E7B0(S1_unk_D_86002F58_004_000_040_raw *arg0, u16 arg1, s32 arg2) {
    extern S1_unk_D_800ABCC0 D_801263B0[2];
    S1_unk_D_800ABCC0 *ctx;
    S1_unk_D_86002F58_004_000_040_004 *data;
    data = arg0->unk_04;
    ++D_801263E0;
    if (D_801263E0 < 2) {
        ctx = &D_801263B0[D_801263E0];
        if (arg0->unk_04 != 0) {
            if (arg2 != 0) {
                arg0->unk_08.raw = ModelAnim_AdvanceCurveFrame(arg0, arg1);
            }
            arg0->unk_12 = arg1;
            ctx->isActive = 1;
            ctx->flags = arg0->unk_04->unk_00;
            ctx->currentFrame = arg0->unk_08.raw >> 16;
            ctx->curveData = data;
            ctx->channels = func_80003240(data->unk_0C);
            ctx->translationValues = func_80003240(data->unk_10);
            ctx->rotationValues = func_80003240(data->unk_14);
            ctx->scaleValues = func_80003240(data->unk_18);
            if (ctx->currentFrame < 0) {
                ctx->currentFrame = 0;
            }
        } else {
            ctx->isActive = 0;
        }
    }
}

 void ModelAnim_EndCurveContext(void) { if (D_801263E0 >= 0) { D_801263E0--; } }

void func_8003E8C8(S1_Vec3f *arg0, S1_Vec3s *arg1, S1_Vec3f *arg2, s32 arg3) {
    if (D_801263E0 >= 0 && D_801263E0 < 2) {
        S1_unk_D_800ABCC0 *ctx = &D_801263B0[D_801263E0];
        if (ctx->isActive == 1 && arg3 >= 0 && arg3 + 2 < ctx->curveData->unk_08) {
            if (ctx->flags & 8) {
                arg0->x = ModelAnim_EvaluateScaleCurve(ctx, arg3);
                arg0->y = ModelAnim_EvaluateScaleCurve(ctx, arg3 + 1);
                arg0->z = ModelAnim_EvaluateScaleCurve(ctx, arg3 + 2);
                arg1->x = ModelAnim_EvaluateRotationCurve(ctx, arg3);
                arg1->y = ModelAnim_EvaluateRotationCurve(ctx, arg3 + 1);
                arg1->z = ModelAnim_EvaluateRotationCurve(ctx, arg3 + 2);
                arg2->x = ModelAnim_EvaluateTranslationCurve(ctx, arg3);
                arg2->y = ModelAnim_EvaluateTranslationCurve(ctx, arg3 + 1);
                arg2->z = ModelAnim_EvaluateTranslationCurve(ctx, arg3 + 2);
            } else {
                arg0->x = ModelAnim_EvaluateScaleChannel(ctx, arg3);
                arg0->y = ModelAnim_EvaluateScaleChannel(ctx, arg3 + 1);
                arg0->z = ModelAnim_EvaluateScaleChannel(ctx, arg3 + 2);
                arg1->x = ModelAnim_EvaluateRotationChannel(ctx, arg3);
                arg1->y = ModelAnim_EvaluateRotationChannel(ctx, arg3 + 1);
                arg1->z = ModelAnim_EvaluateRotationChannel(ctx, arg3 + 2);
                arg2->x = ModelAnim_EvaluateTranslationChannel(ctx, arg3);
                arg2->y = ModelAnim_EvaluateTranslationChannel(ctx, arg3 + 1);
                arg2->z = ModelAnim_EvaluateTranslationChannel(ctx, arg3 + 2);
            }
        }
    }
}

void ModelAnim_ClearTransformChannel(u8 *arg0) { *(s16 *)(arg0 + 0x40) = -1; *(s32 *)(arg0 + 0x44) = 0; }

s32 ModelAnim_BindTransformCurve(S1_unk_D_86002F58_004_000* arg0, s16 arg1, void* arg2, s32 arg3) {
    S1_unk_D_86002F58_004_000_040_004* temp_v0 = func_80003240(arg2);
    S1_unk_D_86002F58_004_000_040* ptr = &arg0->unk_040;

    if ((temp_v0 != ptr->unk_04) || (arg1 != ptr->unk_00)) {
        ptr->unk_00 = arg1;
        ptr->unk_04 = temp_v0;
        ptr->unk_08 = (temp_v0->unk_04 << 0x10) - arg3;
    }

    ptr->unk_0C = arg3;
    return ptr->unk_08 >> 0x10;
}

s32 ModelAnim_SetSpeed(u8 *arg0, s32 arg1) { *(s32 *)(arg0 + 0x4C) = arg1; return *(s32 *)(arg0 + 0x48) >> 16; }

void ModelAnim_SetFrame(u8 *arg0, s16 value) { *(s32 *)(arg0 + 0x48) = ((s32)value << 16) - *(s32 *)(arg0 + 0x4C); }

s32 ModelAnim_HasCrossedFrame(ModelAnim *arg0, s16 arg1) { struct { s16 pad0; void *data; s32 frame; s32 speed; } *ptr = &arg0->curve; s32 temp_v0 = ptr->frame + ptr->speed; s32 arg = arg1 << 16; s32 var_a2; s32 v = ptr->speed; if (v >= 0) { var_a2 = ptr->frame < arg; if (var_a2 != 0) var_a2 = temp_v0 >= arg; } else { var_a2 = arg < ptr->frame; if (var_a2 != 0) var_a2 = arg >= temp_v0; } return var_a2; }

s32 ModelAnim_IsAnimationDone(ModelAnim *arg0) { return ModelAnim_HasCrossedFrame(arg0, ((EventData *)arg0->curve.data)->frameCount - 1); }

s32 ModelAnim_IsFinished(Func3EC34 *arg0) { return arg0->value48 >= ((*(u16 *)(arg0->value44 + 0xA) - 1) << 16); }

s32 func_8003EC54(Func3EC54 *arg0) { s32 value = arg0->value48 + arg0->value4C; return (s16)(value >> 16); }

s32 ModelAnim_ResolveEventIndex(s32 arg0, EventIndex* arg1, s32 arg2) { EventIndex* temp_v0 = &arg1[arg2]; s32 ret; if (arg0 < temp_v0->keyCount) { ret = arg0 + temp_v0->baseIndex; } else { ret = (temp_v0->baseIndex + temp_v0->keyCount) - 1; } return ret; }

s16 ModelAnim_AdvanceEventFrame(S1_unk_D_86002F58_004_000_054* arg0, u16 arg1) {
    s16 var_v1;
    S1_unk_D_86002F58_004_000_054_004* temp_v0;

    var_v1 = arg0->unk_08;
    temp_v0 = arg0->unk_04;

    if (arg0->unk_0A != arg1) {
        var_v1 += 1;
        if (var_v1 >= temp_v0->unk_0A) {
            if (temp_v0->unk_00 & 2) {
                var_v1 = temp_v0->unk_0A - 1;
            } else {
                var_v1 = temp_v0->unk_06;
            }
        }
    }
    return var_v1;
}

 void ModelAnim_ResetEventContext(void) { D_80126410 = -1; }

void ModelAnim_BeginEventContext(S1_unk_D_86002F58_004_000_054 *state, u16 renderFrame, s32 advance) {
    S1_unk_D_86002F58_004_000_054_004 *data;
    SceneEventContext *context;
    data = state->unk_04;
    D_80126410++;
    if (D_80126410 < 2) {
        context = &((SceneEventContext *)D_801263F0)[D_80126410];
        if (state->unk_04 != NULL) {
            if (advance != 0 && (*(u16 *)((u8 *)state + 2) & 1) == 0) {
                state->unk_08 = ModelAnim_AdvanceEventFrame(state, renderFrame);
            }
            state->unk_0A = renderFrame;
            context->active = 1;
            context->frame = state->unk_08;
            context->data = data;
            context->indices = func_80003240(data->unk_0C);
            context->values = func_80003240(data->unk_10);
            if (context->frame < 0) {
                context->frame = 0;
            }
        } else {
            context->active = 0;
        }
    }
}

 void ModelAnim_EndEventContext(void) { if (D_80126410 >= 0) { D_80126410--; } }

void func_8003EE20(s32 *arg0, s32 arg1, s32 arg2) {
    u8 *record;
    s32 index;
    if (D_80126410 < 0) { return; }
    if (D_80126410 >= 2) { return; }
    record = D_801263F0 + (D_80126410 * 0x10);
    if (record[0] != 1) { return; }
    if (arg2 < 0) { return; }
    if (arg2 >= (*((u16 *) ((*((u32 *) (record + 4))) + 8)))) { return; }
    ;
    *arg0 = ((*((u8 *) ((*((u32 *) (record + 0xC))) + ModelAnim_ResolveEventIndex(*((s16 *) (record + 2)), (void *) (*((u32 *) (record + 8))), arg2)))) * 12) + arg1;
}

void ModelAnim_ClearEventTrack(u8 *arg0) { *(s16 *)(arg0 + 0x54) = -1; *(s32 *)(arg0 + 0x58) = 0; }

s16 ModelAnim_BindEventTrack(S1_unk_D_86002F58_004_000* arg0, s16 arg1, s32 arg2) {
    S1_unk_D_86002F58_004_000_054_004* temp_v0 = func_80003240(arg2);
    S1_unk_D_86002F58_004_000_054* ptr = &arg0->unk_054;

    if ((temp_v0 != ptr->unk_04) || (arg1 != ptr->unk_00)) {
        ptr->unk_00 = arg1;
        ptr->unk_04 = temp_v0;
        ptr->unk_08 = temp_v0->unk_04 - 1;
    }

    return ptr->unk_08;
}

void ModelAnim_SetEventFrame(u8 *arg0, s16 value) { *(s16 *)(arg0 + 0x5C) = value - 1; }

void func_8003EF60(u8 *arg0) { *(u16 *)(arg0 + 0x56) |= 1; }

void func_8003EF70(u8 *arg0) { *(u16 *)(arg0 + 0x56) &= (u16)~1; }

s32 ModelAnim_IsEventFrame(u8 *arg0, s16 value) { return value == *(s16 *)(arg0 + 0x5C) + 1; }

s32 ModelAnim_IsEventTrackNearEnd(u8 *arg0) { return *(u16 *)(*(s32 *)(arg0 + 0x58) + 0xA) == *(s16 *)(arg0 + 0x5C) + 2; }

s32 ModelAnim_IsEventTrackDone(u8 *arg0) { return *(u16 *)(*(s32 *)(arg0 + 0x58) + 0xA) == *(s16 *)(arg0 + 0x5C) + 1; }

#pragma C_FUNCTION_PADDING(8)

void ModelRenderer_InitDisplayRoots(void) {
    GeoNode_CreateContainer(0, D_80126420);
    GeoNode_CreateContainer(0, D_80126438);
}

void func_8003F018(s32 arg0) {
    func_8003F03C(arg0, D_80126420);
}

void func_8003F03C(s32 arg0, void *arg1) {
    GeoNode_CreateModelPart(NULL, (void *) arg0, -1, &D_800948D0, &D_800948DC, (S1_Vec3f *) D_800948E4);
    func_80038F8C(arg1, (void *) arg0);
    (*(u8 *)((u8 *)(arg0) + (1))) = (u8) ((*(u8 *)((u8 *)(arg0) + (1))) & 0xFFFE);
}

void ModelRenderer_AttachSecondaryDisplayObject(void *arg0) {
    GeoNode_CreateModelPart(NULL, arg0, 0, &D_800948D0, &D_800948DC, (S1_Vec3f *) D_800948E4);
    func_80038F8C(D_80126438, arg0);
    (*(u8 *)((u8 *)(arg0) + (1))) = (u8) ((*(u8 *)((u8 *)(arg0) + (1))) & 0xFFFE);
}

void func_8003F114(u8 *node, s16 animation, s16 model, void *data) {
    func_80038F8C(node, data);
    MtxF_Identity((f32 *)(node + 0x60));
    *(s16 *)(node + 0x18) = animation;
    *(s16 *)(node + 0x1A) = model;
    node[0x1D] = 0xFF;
    node[0x1C] = 0;
    node[1] |= 1;
    node[2] &= ~4;
    node[2] |= 0x20;
    node[2] |= 0x40;
    node[2] &= ~2;
    *(u32 *)(node + 0xA0) = 0xFFFFFF00U;
    *(u32 *)(node + 0x3C) = 0xFFFFFF00U;
    node[0xA6] = 0;
    *(s16 *)(node + 0x40) = -1;
    *(void **)(node + 0x44) = NULL;
    *(s16 *)(node + 0x54) = -1;
    *(void **)(node + 0x58) = NULL;
    node[2] &= ~8;
    if (model >= 0) func_8007074C(node);
    func_8006D430((s32)node);
}

void func_8003F1DC(void *arg0) {
    func_8006D438();
    (*(s32 *)((u8 *)(arg0) + (0xC))) = 0;
    (*(u8 *)((u8 *)(arg0) + (1))) = (u8) ((*(u8 *)((u8 *)(arg0) + (1))) & 0xFFFE);
}

s32 ModelAnim_SetAnimation(S1_unk_D_86002F58_004_000 *object, s32 animation) {
    s32 result = 0;
    SceneAnimationBank *bank;
    if (object->unk_000.unk_0C != NULL) {
        if (((SceneAnimationAsset *)object->unk_000.unk_0C)->getAnimationBank != NULL) {
            bank = ((SceneAnimationAsset *)object->unk_000.unk_0C)->getAnimationBank(0, 0);
            if (bank != NULL) {
                if (animation == -1) {
                    ModelAnim_ClearTransformChannel((u8 *)object);
                } else if (animation < bank->transformCount) {
                    ModelAnim_BindTransformCurve(object, (s16)animation, bank->transformTracks[animation], 0x10000);
                    result = 1;
                }
            }
        }
    }
    return result;
}

s32 ModelAnim_SetResourceAnimation(SceneAnimationResource *resource, u8 *object, s32 animation) {
    s32 result = 0;
    SceneAnimationAsset *asset;
    SceneAnimationBank *bank;
    S1_unk_D_86002F58_004_000_040 *channel;
    asset = (SceneAnimationAsset *)((S1_unk_D_86002F58_004_000 *)object)->unk_000.unk_0C;
    bank = asset->getAnimationBank(0, 0);
    channel = &((S1_unk_D_86002F58_004_000 *)object)->unk_040;
    if (animation == -1) {
        ModelAnim_ClearTransformChannel((u8 *)object);
    } else if (animation < bank->transformCount) {
        if (channel->unk_04 != resource->loadedCurve || animation != channel->unk_00) {
            s32 format;
            format = func_80042ADC((u8 *)bank);
            if (format >= 0) {
                func_800422B4((u8 *)resource, format, *(u16 *)bank, ((SceneAnimationTransfer *)bank->transformTracks)[animation].second);
                func_80042968((s32)resource);
            }
        }
        ModelAnim_BindTransformCurve(object, (s16)animation, resource->loadedCurve, 0x10000);
        result = 1;
    }
    return result;
}

s32 ModelAnim_SetEventTrack(void *arg0, s32 arg1) { struct CallbackData { char pad[0x2C]; void *(*callback)(s32, s32); } *data; void *result; data = *(struct CallbackData **)((u8 *)arg0 + 0x0C); result = data->callback(0, 0); if (arg1 == -1) { ModelAnim_ClearEventTrack(arg0); } else if (arg1 < *(u8 *)((u8 *)result + 5)) { ModelAnim_BindEventTrack(arg0, (s16)arg1, ((s32 *)*(void **)((u8 *)result + 0x10))[arg1]); return 1; } return 0; }

void func_8003F454(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4) {
    Color_SetRGBA((Color3575C *)(u32)(arg0 + 0xA0), arg1 & 0xFF, arg2 & 0xFF, arg3 & 0xFF, (u8) (s32) arg4);
}

void func_8003F498(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4) {
    Color_SetRGBA((Color3575C *)(u32)(arg0 + 0xA0), arg1 & 0xFF, arg2 & 0xFF, arg3 & 0xFF, (u8) (s32) arg4);
}

void func_8003F4DC(u8 *arg0, u8 value) { arg0[0x1D] = value; }

void func_8003F4E8(u8 *arg0, u8 value) { arg0[0x1C] = value; }

s32 func_8003F4F4(void *arg0, s32 arg1) {
    s32 result = 0;
    void *entry;
    if (arg0 == NULL) arg0 = D_8009491C;
    if (arg0 != NULL) {
        entry = *(void **)((u8 *)arg0 + 0xC);
        result = (*(s32 (**)())((u8 *)entry + 0x2C))(arg1, 0);
    }
    return result;
}

void *func_8003F54C(void *arg0) {
    void *result = NULL;
    void *entry;
    void *value;

    entry = *(void **)((u8 *)arg0 + 0xC);
    if (entry != NULL) {
        value = (*(void *(**)(s32, s32))((u8 *)entry + 0x2C))(0, 0);
        if (*(void **)((u8 *)value + 0x18) != NULL) {
            result = func_80003240(*(void **)((u8 *)value + 0x18));
        }
    }
    return result;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/340C0/func_8003F5AC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/340C0/func_8003F6E0.s")

void func_8003F818(s32 *arg0, s32 arg1) {
    _bzero(arg0, 0x10);
    *arg0 = arg1;
}

void func_8003F84C(u8 *arg0, u32 value1, u32 value2) { arg0[4] |= 0x80; *(u32 *)(arg0 + 8) = value1; *(u32 *)(arg0 + 0xC) = value2; }

void func_8003F864(u8 *arg0) { arg0[4] = (u8)(arg0[4] & ~0x10); }

void PokeIcon_RequestBackgroundForObject(SceneBackgroundRequest *request) {
    if (!(request->flags & 0x40) && (request->flags & 0x80)) {
        func_800421E0(request->context, request->source, request->background);
        request->flags |= 0x40;
        request->flags &= ~0x10;
        if (request->flags & 0x20) {
            PokeIcon_WaitBackgroundLoad((s32)request->context);
            request->background = *(s32 *)(request->context + 0x3C);
            request->flags &= ~0xE0;
        }
    }
}

void func_8003F904(u8 *arg0) {
    if (func_80042808(*(s32 *)arg0)) {
        *(s32 *)(arg0 + 0xC) = *(s32 *)(*(s32 *)arg0 + 0x3C), arg0[4] = (arg0[4] & ~0xE0), arg0[4] |= 0x10;
    }
}

s32 func_8003F954(u16 value) { return value % 9; }

s32 func_8003F970(s32 arg0, u16 arg1) {
    s32 result = 0;
    if (arg0 == 0xEB) {
        result = func_8003F954(arg1);
    }
    return result;
}

s32 SceneObject_SetModelVariant(u8 *object, s32 kind, u16 value) {
    s32 result = 0;
    if (object != NULL) {
        object[0xA6] = func_8003F970(kind, value);
        result = 1;
    }
    return result;
}

#pragma C_FUNCTION_PADDING(4)

void geo_layout_cmd_branch_and_link(void)
{
  s32 p = D_80126520;
  s32 i = D_8012651A;
  if (D_8012651A)
  {
  }
  D_80126458[i] = p + 8;
  D_8012651A = i + 1;
  D_80126458[D_8012651A] = (D_80126518 << 16) + D_8012651E;
  D_8012651A = D_8012651A + 1;
  D_8012651E = D_8012651A;
  D_80126520 = (s32) func_80003240(*((s32 *) (((u8 *) p) + 4)));
}

void geo_layout_cmd_2A(void) {
    s32 new_var;
    s32 p = D_80126520;
    s32 i = D_8012651A;
    if (D_8012651A)
    {
    }
    new_var = p;
    D_80126458[i] = p + 8;
    D_8012651A = i + 1;
    D_80126458[D_8012651A] = (D_80126518 << 16) + D_8012651E;
    D_8012651A = D_8012651A + 1;
    D_8012651E = D_8012651A;
    D_80126520 = (s32)func_80003240(*((s32 *) (*((s32 **) (new_var + 4)))));
}

void func_8003FB2C(void) {
    s16 temp_v0;
    D_8012651A = D_8012651E;
    temp_v0 = D_8012651A - 1;
    D_8012651A = temp_v0;
    D_8012651E = D_80126458[temp_v0] & 0xFFFF;
    D_80126518 = (u32)D_80126458[D_8012651A] >> 16;
    temp_v0 = D_8012651A - 1;
    D_8012651A = temp_v0;
    D_80126520 = D_80126458[temp_v0];
}

void geo_layout_cmd_jump(void) {
    void *p = (void *)(u32)D_80126520;
    D_80126520 = (s32)func_80003240(*(s32 *)((u8 *)p + 4));
}

void func_8003FBE0(void) {
    s32 (*command)[2] = (s32 (*)[2])D_80126520;
    D_80126458[D_8012651A] = D_80126520 + 8;
    D_8012651A++;
    D_80126520 = (s32)func_80003240((*command)[1]);
}

void geo_layout_cmd_27(void)
{
    s32 new_var;
    s32 i = D_8012651A;
    s32 p = D_80126520;
    new_var = p;
    D_80126458[i] = p + 8;
    if (D_80126520)
    {
    }
    D_8012651A = i + 1;
    D_80126520 = (s32)func_80003240(*((s32 *) (*((s32 **) (new_var + 4)))));
}

void geo_layout_cmd_return(void) { s16 temp_v0; temp_v0 = D_8012651A - 1; D_8012651A = temp_v0; D_80126520 = D_80126458[temp_v0]; }

void geo_layout_cmd_open_node(void) {
    s32 i = D_80126518;
    s32 *table = D_80126498;
    table[i + 1] = table[i];
    D_80126518 = i + 1;
    D_80126520 += 4;
}

void geo_layout_cmd_close_node(void) {
    D_80126518--;
    D_80126520 += 4;
}

void func_8003FD34(void *arg0) {
    s32 *entry;
    s16 index;
    if (arg0 != NULL) {
        index = D_80126518;
        entry = &D_80126498[index];
        *entry = (s32)arg0;
        if (index == 0) {
            if (D_80126454 == NULL) {
                D_80126454 = arg0;
            }
        } else {
            func_80038F8C(entry[-1], arg0);
        }
    }
}

void geo_layout_cmd_attach_node(void) {
    struct Cmd {
        u8 pad[4];
        void *child;
    } *cmd;

    cmd = (struct Cmd *)(u32)D_80126520;
    func_8003FD34(cmd->child);
    D_80126520 += 8;
}

void func_8003FDD0(void) {
    S1_unk_D_800ABE00_cmd8 *cmd = (S1_unk_D_800ABE00_cmd8 *)(u32)D_80126520;
    S1_GraphNode *node = (S1_GraphNode *)D_80126498[D_80126518];
    if (node != NULL) {
        func_80037E3C(node, cmd->callback, cmd->callbackData);
    }
    D_80126520 += sizeof(S1_unk_D_800ABE00_cmd8);
}

void func_8003FE2C(void) {
    func_8003FD34(GeoNode_CreateContainer(D_80126450, NULL));
    D_80126520 += 4;
}

void geo_layout_cmd_create_reference(void) {
    struct Cmd {
        u8 pad[4];
        S1_GraphNode *reference;
    } *cmd;

    cmd = (struct Cmd *)(u32)D_80126520;
    func_8003FD34(GeoNode_CreateWithReference(D_80126450, NULL, cmd->reference));
    D_80126520 += 8;
}

void func_8003FEB8(void) {
    S1_unk_D_800ABE00_cmdB *cmd = (S1_unk_D_800ABE00_cmdB *)(u32)D_80126520;
    S1_unk_D_86002F34_00C *node = GeoNode_CreateCamera(D_80126450, NULL, (s16)cmd->viewportX, (s16)cmd->viewportY, cmd->viewportWidth, cmd->viewportHeight);
    if (node != NULL) {
        node->unk_24.fovy = (f32)cmd->fovy;
        Vec3f_FromVec3s(&node->unk_60.at, &cmd->lookAt);
        Camera_ComputeEyeFromAngles(&node->unk_60.at, &node->unk_60.eye, (f32)cmd->eyeDistance, (cmd->yaw << 15) / 180, (cmd->pitch << 15) / 180);
    }
    func_8003FD34(node);
    D_80126520 += 0x18;
}

void geo_layout_cmd_create_type3(void) {
    struct Cmd {
        u8 command;
        u8 pad;
        s16 value;
    } *cmd;

    cmd = (struct Cmd *)(u32)D_80126520;
    func_8003FD34(GeoNode_CreateType3((S1_MemoryBlock *)D_80126450, NULL, cmd->value));
    D_80126520 += 4;
}

void geo_layout_cmd_create_type4(void) {
    struct Cmd {
        u8 command;
        u8 pad;
        s16 value;
    } *cmd;

    cmd = (struct Cmd *)(u32)D_80126520;
    func_8003FD34(GeoNode_CreateType4((S1_MemoryBlock *)D_80126450, NULL, cmd->value));
    D_80126520 += 4;
}

void geo_layout_cmd_create_ortho(void) {
    struct Cmd {
        u8 command;
        u8 pad;
        s16 value;
    } *cmd;

    cmd = (struct Cmd *)(u32)D_80126520;
    func_8003FD34(func_800380B8(D_80126450, 0, cmd->value));
    D_80126520 += 4;
}

void geo_layout_cmd_create_perspective(void) {
    struct Cmd {
        u8 command;
        u8 pad;
        s16 value;
    } *cmd;

    cmd = (struct Cmd *)(u32)D_80126520;
    func_8003FD34(func_8003811C(D_80126450, 0, cmd->value));
    D_80126520 += 4;
}

void geo_layout_cmd_create_background(void) {
    struct TargetCmd16 { u8 cmd; u8 r; u8 g; u8 b; } *cmd;
    cmd = (struct TargetCmd16 *)(u32)D_80126520;
    func_8003FD34(GeoNode_CreateBackground(D_80126450, NULL, cmd->r, cmd->g, cmd->b));
    D_80126520 += sizeof(struct TargetCmd16);
}

void geo_layout_cmd_create_clear_depth(void) {
    func_8003FD34((void *)(S1_uintptr_t)func_8003820C((s32)(S1_uintptr_t)D_80126450, 0));
    D_80126520 += 4;
}

void geo_layout_cmd_noop(void) {
}

void geo_layout_cmd_create_fog(void) {
    S1_unk_D_800ABE00_cmd13* cmd = (S1_unk_D_800ABE00_cmd13*)D_80126520;

    func_8003FD34(GeoNode_CreateFog((s32)(S1_uintptr_t)D_80126450, NULL, cmd->fogNear, cmd->fogFar, cmd->r, cmd->g, cmd->b, 0xFF));

    D_80126520 += sizeof(S1_unk_D_800ABE00_cmd13);
}

void geo_layout_cmd_create_light(void) {
    S1_unk_D_800ABE00_cmd14 *cmd = (S1_unk_D_800ABE00_cmd14 *)(u32)D_80126520;
    func_8003FD34(GeoNode_CreateLight(D_80126450, NULL, (cmd->pitch << 15) / 180, (cmd->yaw << 15) / 180, cmd->r, cmd->g, cmd->b, cmd->a));
    D_80126520 += 12;
}

void geo_layout_cmd_28(void) {
    s32 *node = (s32 *)D_80126498[D_80126518];
    if (node != NULL) {
        *((u8 *)node + 2) |= 1;
    }
    D_80126520 += 4;
}

void geo_layout_cmd_29(void) {
    func_8003FD34((void *)(S1_uintptr_t)func_80038474((s32)(S1_uintptr_t)D_80126450, 0));
    D_80126520 += 4;
}

 void geo_layout_cmd_skip(void) { D_80126520 += 0xC; }

void geo_layout_cmd_create_ambient_light(void) {
    S1_unk_D_800ABE00_cmd16* cmd = (S1_unk_D_800ABE00_cmd16*)D_80126520;

    func_8003FD34(GeoNode_CreateAmbientLight(D_80126450, NULL, cmd->r, cmd->g, cmd->b));

    D_80126520 += sizeof(S1_unk_D_800ABE00_cmd16);
}

void geo_layout_cmd_17(void) {
    s32 var_v1;

    var_v1 = 0;
    if ((*(u8 *)((u8 *)(D_80126520) + (1))) & 1) {
        var_v1 = 1;
    }
    func_8003FD34(func_800384C0(D_80126450, 0, (*(s16 *)((u8 *)(D_80126520) + (2))), (*(s32 *)((u8 *)(D_80126520) + (8))), (s32) (*(s16 *)((u8 *)(D_80126520) + (4))), (*(s32 *)((u8 *)(D_80126520) + (0xC))), (s32) (*(s16 *)((u8 *)(D_80126520) + (6))), (*(s32 *)((u8 *)(D_80126520) + (0x10))), var_v1));
    D_80126520 += 0x14;
}

void geo_layout_cmd_create_shadow(void) {
    S1_unk_D_800ABE00_cmd18* cmd = (S1_unk_D_800ABE00_cmd18*)D_80126520;

    func_8003FD34(GeoNode_CreateShadow(D_80126450, NULL, cmd->unk_01, cmd->unk_04, cmd->unk_06, cmd->unk_02));

    D_80126520 += sizeof(S1_unk_D_800ABE00_cmd18);
}

void geo_layout_cmd_create_cull_distance(void) {
    S1_unk_D_800ABE00_cmd19* cmd = (S1_unk_D_800ABE00_cmd19*)D_80126520;

    func_8003FD34(GeoNode_CreateCullDistance(D_80126450, NULL, cmd->nearDistance, cmd->farDistance));

    D_80126520 += sizeof(S1_unk_D_800ABE00_cmd19);
}

void geo_layout_cmd_create_switch_case(void) {
    S1_unk_D_800ABE00_cmd1A* cmd = (S1_unk_D_800ABE00_cmd1A*)D_80126520;

    func_8003FD34(GeoNode_CreateSwitchCase(D_80126450, NULL, cmd->unk_01, cmd->caseIndex));

    D_80126520 += sizeof(S1_unk_D_800ABE00_cmd1A);
}

void geo_layout_cmd_create_translate_rotate(void) {
    S1_Vec3s sp30;
    S1_Vec3f sp24;
    UNUSED s32 pad;
    S1_unk_D_800ABE00_cmd1B* cmd = (S1_unk_D_800ABE00_cmd1B*)D_80126520;

    Vec3f_FromVec3s(&sp24, &cmd->translation);
    Vec3s_SetComponents(&sp30, (cmd->rotX << 0xF) / 180, (cmd->rotY << 0xF) / 180, (cmd->rotZ << 0xF) / 180);
    func_8003FD34(GeoNode_CreateTranslateRotate(D_80126450, NULL, &sp24, &sp30));

    D_80126520 += sizeof(S1_unk_D_800ABE00_cmd1B);
}

void geo_layout_cmd_create_translate(void) {
    S1_Vec3f sp24;
    S1_unk_D_800ABE00_cmd1C* cmd = (S1_unk_D_800ABE00_cmd1C*)D_80126520;

    sp24.x = cmd->translateX / 65536.0f;
    sp24.y = cmd->translateY / 65536.0f;
    sp24.z = cmd->translateZ / 65536.0f;
    func_8003FD34(GeoNode_CreateTranslate(D_80126450, NULL, &sp24));

    D_80126520 += sizeof(S1_unk_D_800ABE00_cmd1C);
}

void geo_layout_cmd_create_animated_part(void) {
    S1_Vec3f sp3C;
    s16 var_a3 = 1;
    S1_unk_D_800ABE00_cmd1D* cmd = (S1_unk_D_800ABE00_cmd1D*)D_80126520;

    sp3C.x = cmd->translateX / 65536.0f;
    sp3C.y = cmd->translateY / 65536.0f;
    sp3C.z = cmd->translateZ / 65536.0f;

    if (cmd->flags & 1) {
        var_a3 = 0;
    }

    if (cmd->flags & 2) {
        var_a3 |= 2;
    }

    func_8003FD34(
        GeoNode_CreateAnimatedPart(D_80126450, NULL, cmd->partIndex, var_a3, cmd->animIndex, &cmd->rotationA, &cmd->rotationB, &sp3C));

    D_80126520 += sizeof(S1_unk_D_800ABE00_cmd1D);
}

void geo_layout_cmd_create_display_list_part(void) {
    S1_unk_D_800ABE00_cmd1E* cmd = (S1_unk_D_800ABE00_cmd1E*)D_80126520;

    func_8003FD34(GeoNode_CreateDisplayListPart(D_80126450, NULL, cmd->partIndex, cmd->displayList, cmd->unk_02));

    D_80126520 += sizeof(S1_unk_D_800ABE00_cmd1E);
}

void geo_layout_cmd_create_model_part(void) {
    S1_Vec3s sp40;
    S1_Vec3f sp34;
    S1_Vec3f sp28;
    S1_unk_D_86002F58_004_000* tmp;
    S1_unk_D_800ABE00_cmd1F* cmd = (S1_unk_D_800ABE00_cmd1F*)D_80126520;

    Vec3f_FromVec3s(&sp34, &cmd->position);

    sp28.x = cmd->scaleX / 100.0f;
    sp28.y = cmd->scaleY / 100.0f;
    sp28.z = cmd->scaleZ / 100.0f;

    Vec3s_SetComponents(&sp40, (cmd->rotX << 0xF) / 180, (cmd->rotY << 0xF) / 180, (cmd->rotZ << 0xF) / 180);
    tmp = GeoNode_CreateModelPart(D_80126450, NULL, cmd->modelIndex, &sp34, &sp40, &sp28);
    func_8003FD34(tmp);

    D_80126520 += sizeof(S1_unk_D_800ABE00_cmd1F);
}

void geo_layout_cmd_create_display_list_matrix(void) {
    S1_Vec3f sp34;
    S1_Vec3s sp2C;
    void *node;
    S1_unk_D_800ABE00_cmd20 *cmd = (S1_unk_D_800ABE00_cmd20 *)D_80126520;
    Vec3f_FromVec3s(&sp34, &cmd->position);
    Vec3s_SetComponents(&sp2C, (cmd->rotX << 15) / 180, (cmd->rotY << 15) / 180, (cmd->rotZ << 15) / 180);
    node = GeoNode_CreateDisplayListMatrixFromTransform((s32)D_80126450, 0, cmd->partIndex, (s32)cmd->displayList, (s32)&sp34, (s32)&sp2C);
    func_8003FD34(node);
    D_80126520 += sizeof(S1_unk_D_800ABE00_cmd20);
}

void geo_layout_cmd_create_scale(void) {
    S1_Vec3f sp2C;
    S1_unk_D_86002F34_alt9* tmp;
    S1_unk_D_800ABE00_cmd21* cmd = (S1_unk_D_800ABE00_cmd21*)D_80126520;

    Vec3f_FromVec3s(&sp2C, &cmd->position);
    tmp = GeoNode_CreateScale(D_80126450, NULL, cmd->partIndex, cmd->displayList, &sp2C, cmd->scale / 65536.0f);
    func_8003FD34(tmp);

    D_80126520 += sizeof(S1_unk_D_800ABE00_cmd21);
}

void geo_layout_cmd_create_display_list(void) {
    S1_unk_D_800ABE00_cmd22* cmd = (S1_unk_D_800ABE00_cmd22*)D_80126520;

    func_8003FD34(GeoNode_CreateDisplayList(D_80126450, NULL, cmd->partIndex, cmd->displayList));

    D_80126520 += sizeof(S1_unk_D_800ABE00_cmd22);
}

void geo_layout_cmd_create_shadow_texture(void) {
    S1_unk_D_800ABE00_cmd23* cmd = (S1_unk_D_800ABE00_cmd23*)D_80126520;

    func_8003FD34(GeoNode_CreateShadowTexture(D_80126450, NULL, cmd->colorOverrideFlag, cmd->eventFrame, cmd->displayList, cmd->textureIndex1, cmd->textureIndex2,
                                cmd->r, cmd->g, cmd->b, cmd->a));

    D_80126520 += sizeof(S1_unk_D_800ABE00_cmd23);
}

void geo_layout_cmd_create_anchor(void) {
    S1_unk_D_800ABE00_cmd24* cmd = (S1_unk_D_800ABE00_cmd24*)D_80126520;

    func_8003FD34(GeoNode_CreateAnchor(D_80126450, NULL, cmd->anchorId));

    D_80126520 += sizeof(S1_unk_D_800ABE00_cmd24);
}

void geo_layout_cmd_set_node_flag4(void) {
    u8 *entry = (u8 *)D_80126498[D_80126518];
    if (entry != 0) { entry[2] |= 4; }
    D_80126520 += 4;
}

void geo_layout_cmd_create_group(void) {
    S1_unk_D_800ABE00_cmd26* cmd = (S1_unk_D_800ABE00_cmd26*)D_80126520;

    func_8003FD34(GeoNode_CreateGroup(D_80126450, NULL, cmd->unk_01, cmd->unk_04, cmd->unk_06, cmd->unk_08, cmd->unk_0A,
                                cmd->unk_02, cmd->unk_03, cmd->unk_0C, cmd->r, cmd->g, cmd->b, cmd->a));

    D_80126520 += sizeof(S1_unk_D_800ABE00_cmd26);
}

void *process_geo_layout(S1_MemoryBlock *pool, void *script) {
    D_80126454 = NULL;
    D_80126518 = 0;
    D_8012651A = 2;
    D_8012651E = 2;
    D_80126520 = (s32)func_80003240(script);
    D_80126450 = (S1_MainPoolState *)pool;
    D_80094BB0 = 0;
    D_80126498[0] = 0;
    D_80126458[0] = 0;
    D_80126458[1] = 0;
    while (D_80126520 != 0) {
        D_80094BB4[*((u8 *)(u32)D_80126520)]();
    }
    return D_80126454;
}

#pragma C_FUNCTION_PADDING(20)

void Model_AdjustTextureColors(SceneTextureModel *model, S1_arg1_func_80010CA8 adjustment) {
    s32 i;
    s32 j;
    SceneTextureData *texture = model->textures;
    ScenePaletteData *palette = model->palettes;
    for (i = 0; i < model->textureCount; i++, texture++) {
        if (texture != NULL && texture->texture != NULL && texture->mode == 0) {
            if (texture->type == 2) {
                u16 *pixel = texture->texture;
                for (j = 0; j < texture->numTexels; j++, pixel++) {
                    *pixel = Color_AdjustRGB5551(*pixel, adjustment);
                }
            } else if (texture->type == 3) {
                u32 *pixel = texture->texture;
                for (j = 0; j < texture->numTexels; j++, pixel++) {
                    *pixel = Color_AdjustRGBA8(*pixel, adjustment);
                }
            }
        }
    }
    for (i = 0; i < model->paletteCount; i++, palette++) {
        if (palette != NULL && palette->colors != NULL) {
            u16 *pixel = palette->colors;
            for (j = 0; j < palette->count; j++, pixel++) {
                *pixel = Color_AdjustRGB5551(*pixel, adjustment);
            }
        }
    }
}

void *func_80041130(void *arg0, void *arg1, s32 arg2, CandidateJpegHeader *arg3) {
    void *sp1C;
    s32 sp18;
    s32 result;
    sp18 = 0;
    if (arg1 == NULL) {
        sp18 = ((s32 *)arg0)[1];
        sp1C = MainPool_AllocAligned(arg0, arg3->size + 0x100, 0x10);
    } else {
        sp1C = arg1;
    }
    if (sp1C != NULL) {
            result = Jpeg_DecodeImage((u32)sp1C, arg3->size + 0x100, (u8 *)arg3 + arg3->offset);
        if (arg1 == NULL) {
            if (result == 0) {
                MainPool_ResetStateToOffset(arg0, sp18);
                sp1C = NULL;
            } else {
                MainPool_ResetStateToOffset(arg0, sp18 + result);
            }
        }
    }
    return sp1C;
}

u8 *func_800411F0(void *arg0, u8 *arg1, s32 arg2, u8 *arg3) {
    u8 *var_a1;
    u8 *sp1C;

    if (arg1 == NULL) {
        var_a1 = MainPool_AllocAligned(arg0, *(u32 *)((u8 *)arg3 + 0x10), 0x10);
    } else {
        var_a1 = arg1;
    }
    if (var_a1 != NULL) {
        sp1C = var_a1;
        Yay0_DecompressAndRelocate(arg3, var_a1);
    }
    return var_a1;
}

void *func_8004124C(void *arg0, void *arg1, s32 arg2, s32 arg3, u32 arg4) {
    void *var_a0;
    void *sp1C;

    if (arg1 == NULL) {
        var_a0 = MainPool_AllocAligned(arg0, arg4, 0x10);
    } else {
        var_a0 = arg1;
    }
    if (var_a0 != NULL) {
        sp1C = var_a0;
        Util_Memcpy(var_a0, arg2 + arg3, arg4 >> 2);
    }
    return var_a0;
}

s32 Fragment_LoadResourceFromRomRange(s32 pool, s32 destination, s32 start, s32 end, s32 buffer, s32 capacity) {
    u32 size = (end - start + 0xF) & ~0xF;
    s32 result = 0;
    u32 *header;
    if ((u32)capacity >= size) {
        header = (u32 *)buffer;
        func_80003F74((u8 *)buffer, (u8 *)start, (u8 *)end, 0);
        if (header[0] == 0x50455253 && header[1] == 0x2D535A50) {
            result = (s32)func_800411F0((void *)pool, (u8 *)destination, buffer, (u8 *)buffer);
        } else if (header[0] == 0x50524553 && header[1] == 0x4A504547) {
            result = (s32)func_80041130((void *)pool, (void *)destination, buffer, (CandidateJpegHeader *)buffer);
        } else {
            result = (s32)func_8004124C((void *)pool, (void *)destination, buffer, 0, size);
        }
    }
    return result;
}

void func_800413A0(S1_MainPoolState* arg0, u32 arg1, S1_Fragment* arg2) {
    Memmap_RelocateFragment(arg1, arg2);
    MainPool_ResetStateToOffset(arg0, ((u32)arg2 + arg2->sizeInRam) - (u32)arg0->listHeadR);
}

s32 func_800413E8(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3, s32 arg4, s32 arg5) {
    s32 sum1 = arg3[0] + arg2[1];
    s32 sum2 = sum1 + arg3[1];
    return Fragment_LoadResourceFromRomRange(arg0, arg1, sum1, sum2, arg4, arg5);
}

s32 func_80041430(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 base = arg2;
    s32 result = 0;
    s32 *entry;
    if ((u32)arg3 < *(u32 *)((u8 *)base + 0xC)) {
        if (*(u16 *)base & 1) {
            result = (arg2 += *(s32 *)((u8 *)base + arg3 * 0x10 + 0x10));
        } else {
            if (!(*(u16 *)base & 4)) {
                if (*(s32 *)((u8 *)base + arg3 * 0x10 + 0x18) != 0) {
                    result = *(s32 *)((u8 *)base + arg3 * 0x10 + 0x18);
                    goto done;
                }
            }
            entry = (s32 *)((u8 *)base + arg3 * 0x10 + 0x10);
            result = func_800413E8(arg0, arg1, (s32 *)base, entry, arg4, arg5);
            if (result != 0 && arg1 == 0) {
                if (*(s32 *)(result + 8) == 0x46524147 && *(s32 *)(result + 12) == 0x4D454E54) {
                    func_800413A0((S1_MainPoolState *)arg0, *(u16 *)((u8 *)base + 2), (S1_Fragment *)result);
                }
                entry[2] = result;
            }
        }
    }
done:
    return result;
}

SceneProcessedModel *Fragment_ProcessGeoLayout(pool, entry, adjustment, format, special)
S1_MemoryBlock *pool;
SceneModelEntry entry;
S1_arg1_func_80010CA8 adjustment;
u8 format;
s32 special;
{
    SceneProcessedModel *model;
    s32 i;
    model = entry(0, 0);
    model->entry = entry;
    for (i = 0; i < model->geometryCount; i++) {
        SceneGeometryNode *node;
        node = process_geo_layout(pool, model->geometry[i]);
        if (node->node.unk_00 == 14) {
            node->entry = entry;
            if (adjustment.raw != 0) {
                Model_AdjustTextureColors((SceneTextureModel *)node, adjustment);
            }
        }
        model->geometry[i] = node;
    }
    model->format = format & 0xF;
    if (special != 0) {
        model->format |= 0x80;
    }
    return model;
}

void Fragment_ProcessGeoLayoutList(S1_MemoryBlock* arg0, S1_arg1_func_80019420* arg1) {
    while (arg1->unk_00) {
        if (arg1->unk_00 == 3) {
            arg1->unk_04 = process_geo_layout(arg0, arg1->unk_04);
        }

        arg1++;
    }
}

void func_800416C8(SceneWorkerMessageLoad *message) {
    s32 fragment;
    s32 buffer;
    S1_MemoryBlock *pool;
    s32 used;

    buffer = message->buffer;
    pool = (S1_MemoryBlock *)MainPool_InitState(message->destination, message->size);
    fragment = func_80041430((s32)pool, 0, *(s32 *)((u8 *)&D_80126530 + 0x9E8), message->id,
                             *(s32 *)((u8 *)&D_80126530 + 0x9FC), 0xF000);
    if (fragment != 0) {
        message->data = Fragment_ProcessGeoLayout(pool, fragment, message->adjustment, buffer, message->variant);
    } else {
        message->data = NULL;
    }
    used = pool->size;
    message->size = (used + 1039) & ~0x3FF;
    MainPool_FinalizeAllocation(pool);
}

void PokeIcon_LoadResourceList(SceneWorkerMessage *message) {
    s32 fragment;
    S1_MemoryBlock *pool;
    s32 count = 0;
    S1_arg1_func_80019420 **output = message->data;
    s16 *ids;
    pool = (S1_MemoryBlock *)MainPool_InitState(message->destination, message->size);
    ids = (s16 *)message->source;
    while (*ids != -1) {
        fragment = func_80041430((s32)pool, 0, *(s32 *)((u8 *)&D_80126530 + 0x9F4), *ids,
                                 *(s32 *)((u8 *)&D_80126530 + 0x9FC), 0xF000);
        if (fragment == 0) {
            break;
        }
        output[count] = (S1_arg1_func_80019420 *)(fragment + 0x20);
        Fragment_ProcessGeoLayoutList(pool, (S1_arg1_func_80019420 *)(fragment + 0x20));
        ids++;
        count++;
    }
    output[count] = NULL;
    message->size = pool->size + 0x10;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/340C0/func_8004186C.s")

void func_80041A18(void *arg0) {
    s32 temp_v0;

    temp_v0 = func_80041430(0, (*(s32 *)((u8 *)(arg0) + (0x14))), (*(s32 *)((u8 *)(&D_80126530) + (0x9F8))), (*(s16 *)((u8 *)(arg0) + (2))), (*(s32 *)((u8 *)(&D_80126530) + (0x9FC))), 0xF000);
    if (temp_v0 != 0) {
        (*(s32 *)((u8 *)(arg0) + (0xC))) = temp_v0;
        return;
    }
    (*(s32 *)((u8 *)(arg0) + (0xC))) = 0;
}

void func_80041A78(void *arg0) {
    OSMesg msg;
    OSMesgQueue *queue;
    queue = &D_80126F00;
    __osSetFpcCsr(0x1000C01);
    for (;;) {
        osRecvMesg(queue, &msg, 1);
        switch (*(s16 *)msg) {
        case 1: func_800416C8(msg); break;
        case 2: PokeIcon_LoadResourceList(msg); break;
        case 4: func_8004186C(msg); break;
        case 8: func_80041A18(msg); break;
        }
        if (*(OSMesgQueue **)((u8 *)msg + 8) != NULL) {
            osSendMesg(*(OSMesgQueue **)((u8 *)msg + 8), msg, 1);
        }
    }
}

void func_80041B84(void) {
    osCreateMesgQueue(&D_80126F00, &D_80126EE0, 8);
    osCreateThread(&D_80126530, 7, func_80041A78, NULL, &D_80126EE0, 0xA);
    osStartThread(&D_80126530);
}

void PokeIcon_InitLoadContext(SceneLoadContext *context, s32 flags, s32 modelBufferSize) {
    context->flags = flags;
    context->pending = 0;
    context->variant = 0;
    context->bufferCount = 0;
    context->loadedModel = NULL;
    context->modelBuffers[0] = NULL;
    context->modelBuffers[1] = NULL;
    context->backgroundBuffer = NULL;
    context->animationBuffers[0] = NULL;
    context->animationBuffers[1] = NULL;
    context->modelBufferSize = modelBufferSize;
    context->animationBufferSizes[0] = 0;
    context->animationBufferSizes[1] = 0;
    context->colorAdjust.raw = 0;
    context->species = 0;
    osCreateMesgQueue(&context->queues[0].queue, context->queues[0].messages, 2);
    osCreateMesgQueue(&context->queues[1].queue, context->queues[1].messages, 2);
    osCreateMesgQueue(&context->queues[2].queue, context->queues[2].messages, 2);
    osCreateMesgQueue(&context->queues[3].queue, context->queues[3].messages, 2);
}

SceneLoadContext *PokeIcon_AllocLoadContext(u32 flags) {
    SceneLoadContext *context = (SceneLoadContext *)main_pool_alloc(sizeof(SceneLoadContext), 1);
    s32 doubleBuffered;
    if (context != NULL) {
        PokeIcon_InitLoadContext(context, flags, 0x26000);
        if (flags & 1) {
            context->modelBuffers[0] = (void *)main_pool_alloc(0x26000, 1);
            if (flags & 4) {
                context->modelBuffers[1] = (void *)main_pool_alloc(0x26000, 1);
            }
        }
        if (flags & 2) {
            context->backgroundBuffer = (void *)main_pool_alloc(0x18000, 1);
        }
        if (flags & 0x10) {
            doubleBuffered = flags & 4;
            context->imageBuffers[0] = (void *)main_pool_alloc(0x25C00, 1);
            if (doubleBuffered) {
                context->imageBuffers[1] = (void *)main_pool_alloc(0x25C00, 1);
            }
        }
    }
    return context;
}

SceneLoadContext *PokeIcon_AllocSpecialModelContext(u16 modelId) {
    SceneLoadContext *context = NULL;
    s32 capacity = 0;
    switch (modelId) {
    case 0xFC:
        capacity = 0xF000;
        break;
    case 0x118:
        capacity = 0x4C00;
        break;
    }
    if (capacity != 0) {
        context = (SceneLoadContext *)main_pool_alloc(sizeof(SceneLoadContext), 1);
    }
    if (context != NULL) {
        PokeIcon_InitLoadContext(context, 1, capacity);
        context->bufferCount = 1;
        context->modelBuffers[0] = (void *)main_pool_alloc(capacity, 1);
    }
    return context;
}

void PokeIcon_InitResourceArchives(void) {
    *(s32 *)((u8 *)&D_80126530 + 0x9e8) = BinArchive_Open(func_800356CC(6), 0, 1, 1);
    *(s32 *)((u8 *)&D_80126530 + 0x9f4) = BinArchive_Open(func_800356CC(5), 0, 1, 1);
    *(s32 *)((u8 *)&D_80126530 + 0x9ec) = BinArchive_Open(func_800356CC(7), 0, 1, 1);
    *(s32 *)((u8 *)&D_80126530 + 0x9f0) = BinArchive_Open(func_800356CC(14), 0, 1, 1);
    *(s32 *)((u8 *)&D_80126530 + 0x9F8) = 0;
    *(s32 *)((u8 *)&D_80126530 + 0x9FC) = main_pool_alloc(0xF000, 1);
    Fragment_Load(((((u32)D_81000000 & 0x0FF00000) >> 20) - 0x10), fragment26_ROM_START, fragment27_ROM_START);
}

void func_80041F14(void) {
    D_80126F28 = BinArchive_Open(func_800356CC(8), 0, 1, 1);
    D_80126F2C = main_pool_alloc(0xF000, 1);
}

s32 func_80041F60(s16 *arg0) {
    s16 *ptr = D_8009F428;
    s32 result = 0;
    while (*ptr != -1) {
        if (ptr == arg0) {
            result = 1;
        }
        ptr++;
    }
    return result;
}

void func_80041FA0(s32 arg0, u16 arg1, Func80041FA0State arg2) {
    func_80041FD0(arg0, arg1, arg2, 0);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/340C0/func_80041FD0.s")

s32 func_800421E0(u8 *arg0, s32 arg1, s32 arg2) {
    s32 result = 0;
    u8 *msg;
    if ((arg0[0] & 2) != 0) {
        if ((arg0[1] & 2) == 0) {
            msg = Util_Malloc(0x20);
            if (msg != NULL) {
                *(s16 *)(msg + 0) = 2;
                *(s16 *)(msg + 2) = 0;
                *(s16 *)(msg + 4) = 0;
                msg[6] = 0;
                *(void **)(msg + 8) = arg0 + 0x70;
                *(s32 *)(msg + 0xC) = arg2;
                *(s32 *)(msg + 0x10) = arg1;
                *(s32 *)(msg + 0x14) = *(s32 *)(arg0 + 0xC);
                *(s32 *)(msg + 0x18) = 0x18000;
                osSendMesg(&D_80126F00, (OSMesg)msg, 1);
                arg0[1] |= 2;
                result = 1;
            }
        }
    }
    return result;
}

s32 func_800422B4(u8 *arg0, s32 arg1, u16 arg2, u16 arg3) {
    s32 result = 0;
    u8 *msg;
    if ((arg0[0] & 1) && !(arg0[1] & 4) && arg1 < 2 && *(s32 *)(((u8 (*)[4])arg0)[arg1] + 0x10)) {
        msg = Util_Malloc(0x20);
        if (msg != NULL) {
            *(u16 *)(msg + 0) = 4;
            *(u16 *)(msg + 2) = arg2;
            *(u16 *)(msg + 4) = arg3;
            msg[6] = 0;
            *(void **)(msg + 8) = arg0 + 0x90;
            *(s32 *)(msg + 0xC) = 0;
            *(s32 *)(msg + 0x10) = 0;
            *(s32 *)(msg + 0x14) = *(s32 *)(((u8 (*)[4])arg0)[arg1] + 0x10);
            *(s32 *)(msg + 0x18) = *(s32 *)(((u8 (*)[4])arg0)[arg1] + 0x24);
            osSendMesg(&D_80126F00, msg, 1);
            arg0[1] |= 4;
            result = 1;
        }
    }
    return result;
}

s32 func_8004239C(u8 *arg0, s32 arg1) {
    s32 result = 0;
    u8 *msg;
    s32 index;
    u32 base;
    if ((arg0[0] & 0x10) && !(arg0[1] & 8)) {
        msg = Util_Malloc(0x20);
        if (msg != NULL) {
            index = arg0[2];
            if (arg0[0] & 4) { index ^= 1; }
            *(u16 *)(msg + 0) = 8;
            *(u16 *)(msg + 2) = arg1;
            *(u16 *)(msg + 4) = index;
            msg[6] = 0;
            base = (u32)arg0 + 0xB0;
            *(void **)(msg + 8) = (void *)base;
            *(s32 *)(msg + 0xC) = 0;
            *(s32 *)(msg + 0x10) = 0;
            *(s32 *)(msg + 0x14) = *(s32 *)((u8 *)arg0 + (index << 2) + 0x18);
            *(s32 *)(msg + 0x18) = 0x25C00;
            osSendMesg(&D_80126F00, msg, 1);
            arg0[1] |= 8;
            result = 1;
        }
    }
    return result;
}

u32 Model_FindLowestTextureAddress(SceneTextureModel *model) {
    u32 result = 0;
    s32 count;
    u32 minimum;
    s32 i;
    SceneTextureData *entry;
    if (model->node.unk_00 == 14) {
        count = model->textureCount;
        minimum = 0xFFFFFFFF;
        for (i = 0; i < count; i++) {
            entry = &model->textures[i];
            if (entry->texture != NULL) {
                if ((u32)entry->texture < minimum) {
                    minimum = (u32)entry->texture;
                }
            }
        }
        if (minimum != 0xFFFFFFFF) {
            result = minimum;
        }
    }
    return result;
}

s32 PokeIcon_ApplyResourceLoadResult(SceneLoadContext *context, SceneLoadResult *message) {
    s32 result = 0;
    switch (message->kind) {
    case 1:
        context->pending &= ~1;
        if (message->data != NULL) {
            s32 buffer;
            buffer = message->buffer;
            if (context->flags & 4) {
                context->variant ^= 1;
            }
            context->loadedModel = message->data;
            context->modelSize = message->size;
            context->colorAdjust = message->adjustment;
            context->species = message->variant;
            if (message->variant == 1) {
                u32 address;
                address = Model_FindLowestTextureAddress(((SceneProcessedModel *)context->loadedModel)->geometry[0]);
                if (address != 0) {
                    func_80041430(0, address, *(s32 *)((u8 *)&D_80126530 + 0x9F0), message->id,
                                  *(s32 *)((u8 *)&D_80126530 + 0x9FC), 0xF000);
                }
            }
            context->animationBuffers[buffer] = (u8 *)context->modelBuffers[buffer] + context->modelSize;
            if ((u32)context->animationBuffers[buffer] < (u32)context->modelBuffers[buffer] + context->modelBufferSize) {
                context->animationBufferSizes[buffer] = context->modelBufferSize - context->modelSize;
                result = 1;
                break;
            } else {
                context->animationBuffers[buffer] = NULL;
                context->animationBufferSizes[buffer] = 0;
            }
        }
        result = 1;
        break;
    case 2:
        context->pending &= ~2;
        context->loadedBackground = message->data;
        context->backgroundSize = message->size;
        result = 1;
        break;
    case 4:
        context->pending &= ~4;
        if (message->data != NULL) {
            context->loadedCurve = message->data;
            context->curveSize = message->size;
        }
        result = 1;
        break;
    case 8:
        context->pending &= ~8;
        if (message->data != NULL) {
            if (context->flags & 4) {
                context->variant ^= 1;
            }
            context->unknown44 = (u32)message->data;
        }
        result = 1;
        break;
    }
    Util_Free(message);
    return result;
}

s32 func_800427B8(s32 arg0) {
    void *sp1C;
    s32 sp18 = 0;

    if (osRecvMesg((OSMesgQueue *)(u32)(arg0 + 0x50), &sp1C, 0) != -1) {
        sp18 = PokeIcon_ApplyResourceLoadResult(arg0, sp1C);
    }
    return sp18;
}

s32 func_80042808(s32 arg0) {
    void *sp1C;
    s32 sp18 = 0;

    if (osRecvMesg((OSMesgQueue *)(u32)(arg0 + 0x70), &sp1C, 0) != -1) {
        sp18 = PokeIcon_ApplyResourceLoadResult(arg0, sp1C);
    }
    return sp18;
}

s32 func_80042858(s32 arg0) {
    void *sp1C;
    s32 sp18 = 0;

    if (osRecvMesg((OSMesgQueue *)(u32)(arg0 + 0x90), &sp1C, 0) != -1) {
        sp18 = PokeIcon_ApplyResourceLoadResult(arg0, sp1C);
    }
    return sp18;
}

s32 func_800428A8(s32 arg0) {
    void *sp1C;
    s32 sp18 = 0;

    if (osRecvMesg((OSMesgQueue *)(u32)(arg0 + 0xB0), &sp1C, 0) != -1) {
        sp18 = PokeIcon_ApplyResourceLoadResult(arg0, sp1C);
    }
    return sp18;
}

void func_800428F8(s32 arg0) {
    void *sp1C;

    osRecvMesg((OSMesgQueue *)(u32)(arg0 + 0x50), &sp1C, 1);
    PokeIcon_ApplyResourceLoadResult(arg0, sp1C);
}

void PokeIcon_WaitBackgroundLoad(s32 arg0) {
    void *sp1C;

    osRecvMesg((OSMesgQueue *)(u32)(arg0 + 0x70), &sp1C, 1);
    PokeIcon_ApplyResourceLoadResult(arg0, sp1C);
}

void func_80042968(s32 arg0) {
    void *sp1C;

    osRecvMesg((OSMesgQueue *)(u32)(arg0 + 0x90), &sp1C, 1);
    PokeIcon_ApplyResourceLoadResult(arg0, sp1C);
}

void func_800429A0(s32 arg0) {
    void *sp1C;

    osRecvMesg((OSMesgQueue *)(u32)(arg0 + 0xB0), &sp1C, 1);
    PokeIcon_ApplyResourceLoadResult(arg0, sp1C);
}

extern void func_80041FA0(s32 arg0, u16 arg1, Func80041FA0State arg2);
extern s32 func_800422B4(u8 *arg0, s32 arg1, u16 arg2, u16 arg3);
extern void func_800428F8(s32 arg0);
extern void func_80042968(s32 arg0);
extern s32 func_80042ADC(u8 *arg0);
u8 *func_800429D8(s32 arg0, s32 arg1) {
    u8 *bank;
    Func80041FA0State state;
    s32 resource;
    s32 format;
    u16 id;

    resource = arg0;
    id = arg1;
    state.word = 0;
    if (!arg0) {} // FAKE
    func_80041FA0(resource, id, state);
    func_800428F8(resource);
    bank = *(u8 **)(resource + 0x38);
    if (bank != NULL && bank[4] > 0) {
        format = func_80042ADC(bank);
        if (format >= 0) {
            func_800422B4((u8 *)resource, format, id, 0);
            func_80042968(resource);
        }
    }
    return bank;
}

s32 func_80042A64(s32 arg0) { return 0; }

S1_arg1_func_80019420 *BattleAnim_LoadResourceTable(s32 arg0) {
    s32 sp24;
    S1_arg1_func_80019420 *sp20;
    S1_MemoryBlock *sp1C;
    sp20 = NULL;
    sp24 = (s32)func_80004B4C(D_80126F24, arg0);
    if (sp24 != 0) {
        sp1C = MainPool_AllocState(main_pool_get_available(), 0);
        sp20 = (S1_arg1_func_80019420 *)(sp24 + 0x20);
        Fragment_ProcessGeoLayoutList(sp1C, sp20);
        MainPool_FinalizeAllocation(sp1C);
    }
    return sp20;
}

s32 func_80042ADC(u8 *arg0) { s32 result = -1; if (arg0 != NULL) result = arg0[2] & 0xF; return result; }

#endif
