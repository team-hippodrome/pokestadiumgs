#include "global.h"

/* Exact declarations visible before this split in the original translation unit. */
extern u8 *D_84195200[];
extern void func_84134CBC(u8, u8);
extern void func_84134F78(u8, u8);
extern void func_84134DD8(u8 arg0);
extern void func_84134E30(s32 arg0);
extern void func_84134E7C(u8 arg0, u8 arg1);
extern void func_84136678(u8, s16);
extern void func_84135B00(u16);
extern void func_84136218(u8, u8);
extern s32 func_841360C0(u8, s16, u16, u8, u8);
extern void func_84136D40(u8);
extern void func_84136CA8(void);
extern void func_84136A9C(u8 arg0, s16 arg1, s16 arg2, u8 arg3);
extern u8 * D_84195208[];
extern void *D_841951F8[];
extern void BattleRecord_AdvanceWriteSlot(void);
extern s32 D_841951C8;
extern void *D_841951F0;
extern void func_84136B9C(u8, s16, u16);
extern s32 D_84187020;
extern void func_84136BEC(u8, u16, u16);
extern void func_84135B40(u16 arg0);
extern s32 func_84136124(u8 arg0, s16 arg1, u16 arg2, u8 arg3, u8 arg4);
extern void func_841366C4(u8 arg0, s16 arg1);
extern void func_84134D28(u8 arg0, u8 arg1);
extern void func_84135068(u8 arg0, u8 arg1);
extern void func_841350AC(u8 arg0, u8 arg1, u8 arg2);
extern u8 D_8418548C[];
extern void func_84134EC8(u8 arg0);
extern void func_84136AF8(u8 arg0, s16 arg1, s16 arg2, u8 arg3);
extern void func_84135B8C(u8 arg0, u16 arg1);
extern void func_84136720(u8 arg0, u8 arg1, s16 arg2);
extern void func_84134E00(u8 arg0);
extern void func_8413523C(u8, u8);
extern void (*D_84185EB0[])(void);
extern void func_84136D84(void);
extern void *func_8004C874(s32, s32);
extern void *D_84195204;
extern void func_84135C78(u8 arg0, s16 arg1, u16 arg2, u16 arg3);
extern void func_84137DB8(void);
extern void func_841383B4(u8, u8, u8);
extern void func_84131760(void);
extern void func_84133440(void);
extern u8 func_84134098(u8 arg0);
extern void func_8413425C(void);

#ifdef VERSION_US
extern void func_8413425C(void);
extern void func_84131760(void);
extern void func_841383B4(u8,u8,u8);
extern void func_84126CD0(void);
extern void func_841343FC(void);
extern s32 D_841951DC;
extern void func_84133440(void);
extern u8 func_84134098(u8 arg0);
extern void func_84134CBC(u8 arg0, u8 arg1);
extern void func_841362C8(u8 arg0);
extern void func_84136CA8(void);
extern s32 D_841951C8;
extern void * D_841951F0;
extern void * D_841951F8[];
extern u8 * D_84195208[];
void func_84137DB8(void);
void func_841347A0(void *arg0){u8 v;func_8413425C();func_84137DB8();((u8*)D_841951F0)[0x9C7]=(u8)0;do{((u8*)D_84195208[0])[0x28]=(u8)0;((u8*)D_84195208[1])[0x28]=(u8)0;((u8*)D_841951F8[0])[0x10]=(u8)0;((u8*)D_841951F8[1])[0x10]=(u8)0;D_841951C8=0;func_841362C8((u8)0);func_841362C8((u8)1);func_84131760();func_84137DB8();v=(u8)func_84134098((u8)0);func_841383B4((u8)v,(u8)func_84134098((u8)1),(u8)0);func_84126CD0();func_84134CBC((u8)0,(u8)0x5A);func_84136CA8();func_841343FC();func_84133440();func_84137DB8();}while(D_841951DC==0);}
#endif

#ifdef VERSION_US
extern void func_841347A0(void *);
extern OSThread D_84193FB0;
extern OSMesgQueue D_84195164;
extern OSMesg D_84195160;
void func_841348C0(void) {
    osCreateMesgQueue(&D_84195164, &D_84195160, 1);
    osCreateThread(&D_84193FB0, 0xC, func_841347A0, NULL, &D_84195160, 0x19);
}
#endif

#ifdef VERSION_US
void func_84134920(void) { extern OSThread D_84193FB0; osStartThread(&D_84193FB0); }
#endif

#ifdef VERSION_US
void func_84134944(void) { extern OSThread D_84193FB0; osDestroyThread(&D_84193FB0); }
#endif

#ifdef VERSION_US
s32 func_84134968(void) { extern OSMesgQueue D_84195164; return osRecvMesg(&D_84195164, NULL, 1); }
#endif

#ifdef VERSION_US
void Display_QueueFramebufferRequest_fragment79(OSMesg arg0) {
    osSendMesg(&D_84195164, arg0, 0);
}
#endif

#ifdef VERSION_US
s32 func_841349C0(f32 arg0) { s32 value = (s32)arg0; f64 fraction = (f64)(arg0 - (f32)value); return fraction >= 0.5 ? value + 1 : value; }
#endif

#ifdef VERSION_US
s32 func_84134A10(u16 arg0, s16 *arg1, u16 *arg2) {
    if (arg0 == 0xFFFF) {
        return 0;
    }
    if (*arg2 > 0) {
        if (*arg1 == 0) {
            *arg2 = *arg2 - 1;
            return 1;
        }
        if (*arg1 > 0) {
            *arg1 = *arg1 - 1;
        }
    }
    return 0;
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_3A4030/func_84134A6C.s")
#endif

#ifdef VERSION_US
extern void func_84134A6C(u8 *, u8, u8);
extern void BattleSnapshot_SetPartyMember(u8 *, u8, u8);
extern u8 D_84195280[];
void func_84134CBC(u8 arg0, u8 arg1) {
    func_84134A6C(&D_84195280[D_84195280[0x4D81] * 0x280], arg0, arg1);
}
#endif

#ifdef VERSION_US
extern u8 D_84195280[];
s32 func_84134D04(void) {
    return *(u16 *)(&D_84195280[D_84195280[0x4D81] * 0x280 + 4]);
}
#endif

#ifdef VERSION_US
extern u8 D_84195280[];
void func_84134D28(u8 arg0, u8 arg1) {
    s32 idx = D_84195280[0x4D81] - 1;
    if (idx < 0) {
        idx = 0x1D;
    }
    func_84134A6C(D_84195280 + idx * 0x280, arg0, arg1);
}
#endif

#ifdef VERSION_US
extern u8 *D_84186160[];
extern void func_84134A6C(u8 *, u8, u8);
void func_84134D80(u8 arg0, u8 arg1, u8 arg2) {
    if (arg0 < 4) {
        u8 *ptr = D_84186160[arg0];
        if (ptr != NULL) {
            func_84134A6C(ptr, arg1, arg2);
        }
    }
}
#endif

#ifdef VERSION_US
void func_84134DD8(u8 arg0) {
    D_84195280[D_84195280[0x4D81] * 0x280 + 8] = arg0;
}
#endif

#ifdef VERSION_US
void func_84134E00(u8 arg0) {
    D_84195280[D_84195280[0x4D81] * 0x280 + 9] |= arg0;
}
#endif

#ifdef VERSION_US
extern u8 D_84195280[];
void func_84134E30(s32 arg0) {
    s32 *home;
    home = &arg0;
    D_84195280[D_84195280[0x4D81] * 0x280 + 9] &= 0xFFF8;
    D_84195280[D_84195280[0x4D81] * 0x280 + 9] |= arg0;
}
#endif

#ifdef VERSION_US
extern u8 * D_84186160[];
void func_84134E7C(u8 arg0, u8 arg1) {
    if (arg0 < 4) {
        u8 *ptr = D_84186160[arg0];
        u8 *field = ptr + 8;
        if (ptr) {
            field[1] &= 0xFFF8;
            field[1] |= arg1;
        }
    }
}
#endif

#ifdef VERSION_US
void func_84134EC8(u8 arg0) {
    s32 index;
    u8 *record;
    index = D_84195280[0x4D81] - 1;
    if (index < 0) {
        index = 0x1D;
    }
    record = D_84195280 + index * 0x280;
    record[9] |= arg0;
}
#endif

#ifdef VERSION_US
extern u8 *D_84186160[];
void func_84134F0C(u8 arg0, u8 arg1) {
    if (arg0 < 4) {
        u8 *ptr = D_84186160[arg0];
        u8 *base = ptr + 8;
        if (ptr != NULL) base[1] |= arg1;
    }
}
#endif

#ifdef VERSION_US
void func_84134F50(u8 *arg0, u8 arg1, u8 arg2) {
    *(u16 *)((u8 *)arg0 + ((u32)arg1 << 4) + 0x12) |= (u16)(u8)arg2;
}
#endif

#ifdef VERSION_US
void func_84134F78(u8 arg0, u8 arg1) {
    func_84134F50(&D_84195280[D_84195280[0x4D81] * 0x280], arg0, arg1);
}
#endif

#ifdef VERSION_US
void func_84134FC0(u8 *arg0, u8 arg1, u8 arg2) {
    *(u16 *)((u8 *)arg0 + (arg1 << 4) + 0x12) = *(u16 *)((u8 *)arg0 + (arg1 << 4) + 0x12) & ~(u16)(u8)arg2;
}
#endif

#ifdef VERSION_US
void func_84134FEC(u8 arg0, u8 arg1) {
    func_84134FC0(&D_84195280[D_84195280[0x4D81] * 0x280], arg0, arg1);
}
#endif

#ifdef VERSION_US
void func_84135034(u8 arg0, u8 arg1) {
    u8 *ptr = &D_84195280[D_84195280[0x4D81] * 0x280];
    ptr += 8;
    ptr[2] = arg0;
    ptr[3] = arg1;
}
#endif

#ifdef VERSION_US
extern u8 D_84195280[];
void func_84135068(u8 arg0, u8 arg1) {
    s32 idx = D_84195280[0x4D81] - 1;
    if (idx < 0) {
        idx = 0x1D;
    }
    D_84195280[idx * 0x280 + 0xA] = arg0;
    D_84195280[idx * 0x280 + 0xB] = arg1;
}
#endif

#ifdef VERSION_US
void func_841350AC(u8 arg0, u8 arg1, u8 arg2) {
    if (arg0 < 4) {
        u8 *ptr = D_84186160[arg0];
        u8 *base = ptr + 8;
        if (ptr != NULL) {
            base[2] = arg1;
            base[3] = arg2;
        }
    }
}
#endif

#ifdef VERSION_US
#include "color_adjustment.h"
extern ColorAdjustment func_8003F5AC(u8 *);
extern void * D_841951F8[];
extern u8 * D_84195200[];
extern u8 * D_84195208[];
void BattleSnapshot_SetPartyMember(u8 *snapshot, u8 side, u8 index) {
    u8 *party;
    u8 *dst = (u8 *)&((u8(*)[16])snapshot)[side];
    party = (u8 *)D_841951F8[side] + index * 88 + 24;
    if (index == ((u8 *)D_841951F8[side])[10]) {
        *(u16 *)(dst + 12) = *(u16 *)(D_84195208[side] + 44);
        *(u16 *)(dst + 20) = *(u16 *)(D_84195200[side] + 22);
        *(ColorAdjustment *)(dst + 24) = *(ColorAdjustment *)(D_84195208[side] + 80);
    } else {
        *(u16 *)(dst + 12) = Pokemon_GetDisplaySpecies(party);
        *(u16 *)(dst + 20) = *(u16 *)(party + 22);
        *(ColorAdjustment *)(dst + 24) = func_8003F5AC(party);
    }
    *(u16 *)(dst + 14) = *(u16 *)(party + 38);
    *(u16 *)(dst + 16) = party[36];
}
#endif

#ifdef VERSION_US
extern u8 * D_84195200[];
extern u8 * D_84195208[];
void func_841351EC(void *arg0, u8 arg1) {
    struct WordCopy { s32 value; };
    u8 *dst;

    dst = (u8 *)arg0 + arg1 * 0x10;
    *(u16 *)(dst + 0xC) = *(u16 *)(D_84195208[arg1] + 0x2C);
    *(u16 *)(dst + 0x14) = *(u16 *)(D_84195200[arg1] + 0x16);
    *(struct WordCopy *)(dst + 0x18) = *(struct WordCopy *)(D_84195208[arg1] + 0x50);
}
#endif

#ifdef VERSION_US
void func_8413523C(u8 arg0, u8 arg1) {
    BattleSnapshot_SetPartyMember(&D_84195280[D_84195280[0x4D81] * 0x280], arg0, arg1);
}
#endif

#ifdef VERSION_US
extern void BattleSnapshot_SetPartyMember(u8 *, u8, u8);
extern u8 D_84195280[];
void func_84135284(u8 arg0, u8 arg1) {
    s32 idx = D_84195280[0x4D81] - 1;
    if (idx < 0) {
        idx = 0x1D;
    }
    BattleSnapshot_SetPartyMember(D_84195280 + idx * 0x280, arg0, arg1);
}
#endif

#ifdef VERSION_US
extern u8 D_84195280[];
extern void func_841351EC(void *, u8);
void func_841352DC(u8 arg0) {
    s32 idx = D_84195280[0x4D81] - 1;
    if (idx < 0) {
        idx = 0x1D;
    }
    func_841351EC(D_84195280 + idx * 0x280, arg0);
}
void func_841352DC_padding1(void) {}
void func_841352DC_padding2(void) {}
#endif

#ifdef VERSION_US
extern void func_84147228(u8, u8, u8, u8, s32);
void func_84135338(u8 arg0) {
    func_84147228(0, arg0, 0, 0xB, 3);
    func_84147228(1, arg0, 0, 0xB, 2);
    func_84147228(2, arg0, 0, 0xB, 1);
    func_84147228(3, arg0, 0, 0xB, 0);
    func_84147228(0, arg0, 0, 4, 4);
    func_84147228(1, arg0, 0, 4, 4);
    func_84147228(2, arg0, 0, 4, 4);
    func_84147228(3, arg0, 0, 4, 4);
}
#endif

#ifdef VERSION_US
extern u16 D_84199D86;
extern u8 D_8418615C, D_8419A006, D_8419A007, D_84199D82;
extern u8 D_84199D80[];
extern void _bzero(void *, s32);
extern void func_84134A6C(u8 *, u8, u8);
extern u8 * D_84195200[];
extern void * D_84195204;
extern s8 D_8419A005;
void func_8413543C(void){if(D_84199D86==0&&D_8418615C==0){_bzero(D_84199D80,0x280);if(D_8419A006==0&&(D_84195200[0][0x24]&0x27))D_8419A006++;if(D_8419A006==1&&(*(u8*)((u8*)D_84195204+0x24)&0x27))D_8419A006++;switch(D_8419A006){case 0:func_84134A6C(D_84199D80,0,0x62);break;case 1:func_84134A6C(D_84199D80,1,0x62);break;case 2:func_84134A6C(D_84199D80,0,0x5C);break;case 3:func_84134A6C(D_84199D80,0,0x5D);break;case 4:func_84134A6C(D_84199D80,0,0x60);break;case 5:func_84134A6C(D_84199D80,0,0x61);break;case 6:func_84134A6C(D_84199D80,1,0x60);break;case 7:func_84134A6C(D_84199D80,1,0x61);break;case 8:func_84134A6C(D_84199D80,0,0x5E);break;case 9:func_84134A6C(D_84199D80,0,0x64);break;case 10:func_84134A6C(D_84199D80,0,D_8419A007?0x63:0x5F);break;case 11:func_84134A6C(D_84199D80,1,D_8419A007?0x63:0x5F);break;}D_8419A006++;if(D_8419A006>=0xC){D_8419A007=0;D_8419A006=2;}D_84199D82=1;}D_8419A005=1;}
#endif

#ifdef VERSION_US
s32 func_84135700(void) {
    if (*(u16 *)(D_84195280 + 0x4B36) != 0) {
        return 0;
    }
    if (*(u16 *)(D_84195280 + 0x4B4E) != 0) {
        return 0;
    }
    return 1;
}
#endif

#ifdef VERSION_US
extern u8 D_8419A004;
extern u16 D_84199FFC;
s32 func_8413573C(void) {
    if (D_8419A004 != 0) {
        if (D_84199FFC != 0) return 0;
        D_8419A004 = 0;
    }
    return 1;
}
#endif

#ifdef VERSION_US
extern s32 func_8413573C(void);
extern u8 D_84195280[];
extern s8 D_8419A005;
s32 func_84135778(void) {
    if ((u8)D_8419A005 != 0) {
        return 1;
    }
    if (*(u16 *)(D_84195280 + 0x4B06) != 0) {
        return 0;
    }
    if (D_84195280[0x4B02] != 0) {
        return 0;
    }
    if (func_84135700() == 0) {
        return 0;
    }
    if (func_8413573C() == 0) {
        return 0;
    }
    return 1;
}
#endif

#ifdef VERSION_US
extern u8 D_8419A006;
void func_84135808(u8 *arg0) { if (arg0[2] != 0) { switch (*(u16 *)(arg0 + 4)) { case 0x21: case 0x23: case 0x24: case 0x29: case 0x2A: case 0x2B: case 0x2D: case 0x2E: case 0x2F: D_8419A006 = 0; break; } } }
#endif

#ifdef VERSION_US
extern void StageFade_StartFromTransparent(u8);
extern void func_84147228(u8, u8, u8, u8, s32);
extern u8 D_84195278;
void func_8413584C(u8 arg0) {
    StageFade_StartFromTransparent(arg0);
    func_84147228(0x1D, 0U, 0, 0xA, (s32) arg0);
    func_84147228(0x1D, 0U, 0, 4, 4);
    D_84195278 = 7;
}
#endif

#ifdef VERSION_US
typedef struct {
    u32 data[160];
} unk_D_84195280;
extern s32 D_84186174;

// D_84195280 starts with 0x280-byte records. func_84134CBC and its siblings fill the record at
// byte 0x4D81's index; this copies the record at byte 0x4D80's index to D_84199D80 and advances
// that index, wrapping at 30. When the two indexes are equal there is nothing to copy.
void func_841358B0(void) {
    if (D_84195280[0x4D81] == D_84195280[0x4D80]) {
        if (D_84195278 != 6) {
            Display_QueueFramebufferRequest_fragment79((OSMesg)0x4D564544);
        } else {
            D_84186174 = 0;
            func_8413584C(20);
        }
    } else {
        *(unk_D_84195280 *)D_84199D80 = ((unk_D_84195280 *)D_84195280)[D_84195280[0x4D80]];
        func_84135808(D_84199D80);
        D_84195280[0x4D80]++;
        if (D_84195280[0x4D80] >= 30) {
            D_84195280[0x4D80] = 0;
        }
        D_8419A004 = 0;
    }
}
#endif

#ifdef VERSION_US
s32 func_84135778();
extern void func_841358B0();
extern s8 D_8419A005;

void func_84135998(void) {
    if (func_84135778() != 0) {
        func_841358B0();
        D_8419A005 = 0;
    }
}
#endif

#ifdef VERSION_US
extern void func_8413543C();
void func_841359D0(void) {
    switch (D_84195278) {                           /* irregular */
    case 1:
        func_8413543C();
        return;
    case 2:
    case 6:
        func_84135998();
        return;
    }
}
#endif

#ifdef VERSION_US
extern s32 func_800472E0(u8 *);
extern void *func_8004C8A0(void *, s32, s32, s32);
void BattleSnapshot_AppendText(u8 *snapshot, u16 text_id) {
    u8 *part;
    s32 lines;
    u8 *text;
    part = snapshot + 0x68;
    if (snapshot[0x1EA] + 1 < 4) {
        text = func_8004C874(0x10, text_id);

        if (part[0x183] + (lines = func_800472E0(text)) < 4) {
            *(u16 *)(part + 0x184 + part[0x182] * 2) = text_id;
            func_8004C8A0(((u8 (*)[0x80])part)[part[0x182]], 0x80, 0x10, text_id);
            part[0x182]++;
            part[0x183] += lines;
            *(s16 *)(part + 0x18C) = 30 + 10 * part[0x183];
        }
    }
}
#endif

#ifdef VERSION_US
extern void BattleSnapshot_AppendText(u8 *, u16);
void func_84135B00(u16 arg0) {
    BattleSnapshot_AppendText(&D_84195280[D_84195280[0x4D81] * 0x280], arg0);
}
#endif

#ifdef VERSION_US
void func_84135B40(u16 arg0) {
    s32 index = D_84195280[0x4D81] - 1;
    if (index < 0) {
        index = 0x1D;
    }
    BattleSnapshot_AppendText(D_84195280 + index * 0x280, arg0);
}
#endif

#ifdef VERSION_US
extern u8 *D_84186160[];
extern void BattleSnapshot_AppendText(u8 *, u16);
void func_84135B8C(u8 arg0, u16 arg1) {
    if (arg0 < 4) {
        u8 *ptr = D_84186160[arg0];
        if (ptr != NULL) {
            BattleSnapshot_AppendText(ptr, arg1);
        }
    }
}
#endif

#ifdef VERSION_US
extern void * D_841951F8[];
void func_84135BDC(void *arg0, u8 arg1, s16 arg2, u16 arg3, u16 arg4) {
    s32 sp2C;
    s32 sp28;
    u8 *s0 = (u8 *)arg0 + 0x1F6;

    func_8004C8A0(s0, 0x80, ((u8 *)D_841951F8[arg1])[0x49B] + 0x4C, arg4);
    func_80049C70(&sp2C, &sp28, s0);
    s0[0x80] = arg1;
    s0[0x81] = arg1;
    s0[0x82] = sp2C;
    s0[0x83] = sp28;
    *(s16 *)&s0[0x84] = arg2;
    *(u16 *)&s0[0x86] = arg3;
}
#endif

#ifdef VERSION_US
extern u8 D_84195280[];
extern void func_84135BDC(void *, u8, s16, u16, u16);
void func_84135C78(u8 arg0, s16 arg1, u16 arg2, u16 arg3) {
    func_84135BDC(&D_84195280[D_84195280[0x4D81] * 0x280], arg0, arg1, arg2, arg3);
}
#endif

#ifdef VERSION_US
extern void func_84135BDC(void *, u8, s16, u16, u16);
void func_84135CD4(u8 arg0, s16 arg1, u16 arg2, u16 arg3) {
    s32 var_v0;

    var_v0 = (*(u8 *)((u8 *)(D_84195280) + (0x4D81))) - 1;
    if (var_v0 < 0) {
        var_v0 = 0x1D;
    }
    func_84135BDC(D_84195280 + (var_v0 * 0x280), arg0, arg1, arg2, (s32) arg3);
}
#endif

#ifdef VERSION_US
extern u32 func_8003570C(void);
s32 func_84135D3C(u8 *arg0, u8 *arg1) {
    if ((arg0[2] == 0) && (arg1[2] != 0)) {
        return 1;
    }
    if ((arg0[2] != 0) && (arg1[2] == 0)) {
        return -1;
    }
    if (arg0[1] < arg1[1]) {
        return 1;
    }
    if (arg1[1] < arg0[1]) {
        return -1;
    }
    return 1 - ((func_8003570C() & 1) * 2);
}
#endif

#ifdef VERSION_US
s32 func_84135DD8(u8 arg0, u8 arg1, u8 arg2) {
    u8 *p = &arg0;
    s32 result = 0;
    if (arg0 == 6) {
        if (arg1 == 0) {
            if (arg2 != 0xE && arg2 != 0xF && arg2 != 0x10) result = 1;
        } else if (arg1 == arg2) result = 1;
    } else if (arg1 == arg2) result = 1;
    return result;
}
#endif

#ifdef VERSION_US
extern s32 func_84135D3C(u8 *arg0, u8 *arg1);
extern s32 func_84135DD8(u8 arg0, u8 arg1, u8 arg2);
extern u32 D_8419A020[];
u8 *func_84135E4C(u8 arg0, u8 arg1, u8 arg2) {
    typedef struct {
        u32 unk00;
        u32 flags;
        u8 count;
        u8 entries[13][4];
        u8 padding[3];
    } Record;
    s32 i = 0;
    u8 *best = 0;
    u8 *entry;

    if (((Record *)D_8419A020)[arg0].flags & (1 << arg1)) {
        for (; i < 13 && i < ((Record *)D_8419A020)[arg0].count; i++) {
            entry = ((Record *)D_8419A020)[arg0].entries[i];
            if (entry[0] == arg1 && entry[1] != 0 && func_84135DD8(arg1, entry[2], arg2)) {
                if (best == 0) {
                    best = entry;
                } else if (func_84135D3C(best, entry) > 0) {
                    best = entry;
                }
            }
        }
        ((Record *)D_8419A020)[arg0].flags &= ~(1 << arg1);
    }
    return best;
}
#endif

#ifdef VERSION_US
extern u32 func_8003570C(void);
s32 func_84135F94(u8 *arg0) {
    s32 result;

    result = 0;
    switch (arg0[1]) {
    case 1:
        result = 1;
        break;
    case 2:
        result = 1;
        arg0[1] = 0;
        break;
    case 4:
        result = func_8003570C() & 1;
        break;
    case 3:
        result = 1;
        arg0[1] = 4;
        break;
    }
    return result;
}
#endif

#ifdef VERSION_US
extern void func_84135BDC(void *arg0, u8 arg1, s16 arg2, u16 arg3, u16 arg4);
extern s32 func_84135F94(u8 *arg0);
extern void * D_841951F8[];
s32 func_84136014(void *arg0, u8 arg1, s16 arg2, u16 arg3, s32 arg4, s32 arg5) {
    s32 result = 0;
    u8 *ptr;

    if (((u8 *)D_841951F8[arg1])[0x49A] == 0) {
        return result;
    }
    ptr = func_84135E4C(arg1, (u8)arg4, (u8)arg5);
    if (ptr != NULL) {
        if (func_84135F94(ptr) != 0) {
            func_84135BDC(arg0, arg1, arg2, arg3, ptr[3]);
            result = 1;
        }
    }
    return result;
}
#endif

#ifdef VERSION_US
extern u8 D_84195280[];
extern s32 func_84136014(void *, u8, s16, u16, s32, s32);
s32 func_841360C0(u8 arg0, s16 arg1, u16 arg2, u8 arg3, u8 arg4) {
    return func_84136014(&D_84195280[D_84195280[0x4D81] * 0x280], arg0, arg1, arg2, arg3, arg4);
}
#endif

#ifdef VERSION_US
extern s32 func_84136014(void *, u8, s16, u16, s32, s32);
s32 func_84136124(u8 arg0, s16 arg1, u16 arg2, u8 arg3, u8 arg4) {
    s32 var_v0;

    var_v0 = (*(u8 *)((u8 *)(D_84195280) + (0x4D81))) - 1;
    if (var_v0 < 0) {
        var_v0 = 0x1D;
    }
    return func_84136014(D_84195280 + (var_v0 * 0x280), arg0, arg1, arg2, (s32) arg3, (s32) arg4);
}
#endif

#ifdef VERSION_US
extern s32 func_84136014(void *, u8, s16, u16, s32, s32);
extern u8 * D_84186160[];
s32 func_84136194(u8 arg0, u8 arg1, s16 arg2, u16 arg3, u8 arg4, u8 arg5) {
    u8 *ptr;
    if (arg0 >= 4) return 0;
    ptr = D_84186160[arg0];
    if (ptr == 0) return 0;
    func_84136014(ptr, arg1, arg2, arg3, arg4, arg5);
}
#endif

#ifdef VERSION_US
extern void * D_841951F8[];
extern u32 D_8419A020[];
void func_84136218(u8 arg0, u8 arg1) {
    u8 *ptr = (u8 *)D_841951F8[arg0];
    u32 *base = D_8419A020 + arg0 * 0x10;
    u32 mask = 1 << arg1;
    if (ptr[0x49A] != 0 && ptr[0x49A] != 0xFF && ptr[0x11] == 0 && (base[0] & mask) != 0) {
        base[1] |= mask;
    }
}
#endif

#ifdef VERSION_US
extern u32 D_8419A020[];
s32 func_84136294(u8 arg0, u8 arg1) {
    u8 *p = (u8 *)(u32)D_8419A020 + (arg0 << 6);
    return (*(u32 *)p & (1 << arg1)) != 0;
}
#endif

#ifdef VERSION_US
extern u8 D_8419A024[];
void func_841362C8(u8 arg0) {
    *(u32 *)(D_8419A024 + ((u32)arg0 << 6)) = 0;
}
#endif

#ifdef VERSION_US
extern u32 D_8419A020[];
void func_841362E4(u8 arg0, u8 arg1, u8 arg2, u8 arg3, s32 arg4) {
    u8 *p = (u8 *)D_8419A020 + (arg0 << 6);
    u8 *entry = p;
    entry += p[8] << 2;
    *(u32 *)p |= 1 << arg1;
    entry[9] = arg1;
    entry[10] = arg2;
    entry[11] = arg3;
    entry += 9;
    entry[3] = ((u8 *)&arg4)[3];
    p[8] = p[8] + 1;
}
#endif

#ifdef VERSION_US
extern void func_841362E4(u8, u8, u8, u8, s32);
void func_84136354(u8 arg0) {
    func_841362E4(arg0, 1, 1, 0, 0xC);
    func_841362E4(arg0, 2, 1, 0, 0xD);
    func_841362E4(arg0, 3, 3, 0, 0xE);
    func_841362E4(arg0, 4, 3, 0, 0xF);
    func_841362E4(arg0, 5, 4, 0, 0x10);
    func_841362E4(arg0, 6, 4, 0, 0x11);
    func_841362E4(arg0, 7, 3, 0, 0x12);
}
#endif

#ifdef VERSION_US
extern void func_80049D9C(u8 *, u8 *, u8 *, u8 *);
typedef struct { u32 mask; u32 other; u8 count; u8 entries[13][4]; } BattleTextRecord;
void BattleText_CollectEntriesForSide(u8 side) {
    s32 text_id;
    u8 code;
    u8 parameter0;
    u8 parameter1;
    u8 *entry;

    for (text_id = 21; text_id != 25; text_id++) {
        parameter1 = 0;
        parameter0 = 0;
        code = 0;
        func_80049D9C(&code, &parameter0, &parameter1, func_8004C874(((u8 *)D_841951F8[side])[1179] + 76, text_id));
        if (code > 0) {
            ((BattleTextRecord *)D_8419A020)[side].mask |= 1 << code;
            entry = ((BattleTextRecord *)D_8419A020)[side].entries[((BattleTextRecord *)D_8419A020)[side].count];
            entry[0] = code;
            entry[1] = parameter0;
            entry[2] = parameter1;
            entry[3] = text_id;
            ((BattleTextRecord *)D_8419A020)[side].count++;
        }
    }
}
#endif

#ifdef VERSION_US
extern void BattleText_CollectEntriesForSide(u8);
extern void func_84136354(u8 arg0);
extern void * D_841951F8[];
extern u32 D_8419A020[];
void func_84136564(void) {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (((u8 *)D_841951F8[i])[0x49A] != 0) {
            *(u32 *)((u8 *)D_8419A020 + i * 0x40) = 0;
            func_84136354((u8)i);
            BattleText_CollectEntriesForSide((u8)i);
        }
    }
}
#endif

#ifdef VERSION_US
extern u8 D_84195252[];
extern u8 D_84195253[];
void func_841365F4(u8 *arg0, u8 arg1, s16 arg2) {
    u8 *base;
    base = arg0 + 0x68;
    arg0[0x1E8] = arg1;
    if (*(u8 *)((u8 *)D_841951F8[arg1] + 0xA) < *(u8 *)((u8 *)D_841951F8[arg1] + 3)) {
        base[0x181] = D_84195252[arg1 * 0x18];
    } else {
        base[0x181] = D_84195253[arg1 * 0x18];
    }
    *(s16 *)(base + 0x18A) = arg2;
}

#endif

#ifdef VERSION_US
extern void func_841365F4(u8 *, u8, s16);
extern u8 D_84195280[];
void func_84136678(u8 arg0, s16 arg1) {
    func_841365F4(&D_84195280[D_84195280[0x4D81] * 0x280], arg0, arg1);
}
#endif

#ifdef VERSION_US
void func_841366C4(u8 arg0, s16 arg1) {
    s32 var_v0;

    var_v0 = D_84195280[19841] - 1;
    if (var_v0 < 0) {
        var_v0 = 29;
    }
    func_841365F4(D_84195280 + (var_v0 * 640), arg0, arg1);
}
#endif

#ifdef VERSION_US
extern void func_841365F4(u8 *, u8, s16);
extern u8 * D_84186160[];
void func_84136720(u8 arg0, u8 arg1, s16 arg2) {
    if (arg0 < 4) {
        u8 *ptr = D_84186160[arg0];
        if (ptr != NULL) {
            func_841365F4(ptr, arg1, arg2);
        }
    }
}
#endif

#ifdef VERSION_US
extern f32 func_8000B770(f32);
struct Change { s16 kindValue; u16 value, maximum, status, dvs, timer; f32 delta; u8 *name; u8 species, level, kind, pad; };
    struct Snapshot { u8 prefix[44]; struct Change changes[2]; };
void BattleSnapshot_SetSideChange(void *arg0, u8 arg1, s16 arg2, s16 arg3, u8 arg4) {
    struct Change *change;
    ((struct Snapshot *)arg0)->changes[arg1].kindValue = arg2;
    ((struct Snapshot *)arg0)->changes[arg1].kind = (u8)arg4;
    change = &((struct Snapshot *)arg0)->changes[arg1];
    switch (arg4) {
    case 0:
        ((struct Snapshot *)arg0)->changes[arg1].timer = 0;
        break;

    case 1:

    case 2:
        change->delta = (f32)arg3;
        change->timer = (u16)((90.0f * func_8000B770((f32)arg3)) / ((f32)(*((u16 *)(D_84195200[arg1] + 40)))));
        if (arg3 && (change->timer == 0)) {
            change->timer++;
        }
        break;

    case 3:
        change->delta = (f32)arg3;
        change->timer = (u16)((20.0f * func_8000B770((f32)arg3)) / ((f32)(*((u16 *)(D_84195200[arg1] + 40)))));
        if (arg3 && (change->timer == 0)) {
            change->timer++;
        }
        break;

    case 4:
        change->delta = (f32)arg3;
        change->value = *((u16 *)(D_84195200[arg1] + 38));
        change->maximum = *((u16 *)(D_84195200[arg1] + 40));
        change->status = *((u8 *)(D_84195200[arg1] + 36));
        change->name = D_84195200[arg1] + 52;
        change->dvs = *((u16 *)(D_84195200[arg1] + 22));
        change->species = *((u8 *)D_84195200[arg1]);
        change->level = *((u8 *)(D_84195200[arg1] + 29));
        change->timer = 1;
        break;

    case 5:

    case 6:
        ((struct Snapshot *)arg0)->changes[arg1].timer = 1;
        break;
    }
}
#endif

#ifdef VERSION_US
extern u8 D_84195280[];
extern void BattleSnapshot_SetSideChange(void *, u8, s16, s16, u8);
void func_84136A9C(u8 arg0, s16 arg1, s16 arg2, u8 arg3) {
    BattleSnapshot_SetSideChange(&D_84195280[D_84195280[0x4D81] * 0x280], arg0, arg1, arg2, arg3);
}
#endif

#ifdef VERSION_US
extern void BattleSnapshot_SetSideChange(void *, u8, s16, s16, u8);
void func_84136AF8(u8 arg0, s16 arg1, s16 arg2, u8 arg3) {
    s32 var_v0;

    var_v0 = (*(u8 *)((u8 *)(D_84195280) + (0x4D81))) - 1;
    if (var_v0 < 0) {
        var_v0 = 0x1D;
    }
    BattleSnapshot_SetSideChange(D_84195280 + (var_v0 * 0x280), arg0, arg1, arg2, (s32) arg3);
}
#endif

#ifdef VERSION_US
void func_84136B60(void *arg0, u8 arg1, s16 arg2, u16 arg3) {
    u8 *ptr = (u8 *)arg0 + arg1 * 6;
    *(s16 *)(ptr + 0x5C) = arg2;
    *(u16 *)(ptr + 0x60) = arg3;
    *(u16 *)(ptr + 0x5E) = 1;
}
#endif

#ifdef VERSION_US
extern u8 D_84195280[];
extern void func_84136B60(void *, u8, s16, u16);
void func_84136B9C(u8 arg0, s16 arg1, u16 arg2) {
    func_84136B60(&D_84195280[D_84195280[0x4D81] * 0x280], arg0, arg1, arg2);
}
#endif

#ifdef VERSION_US
extern u8 D_84195280[];
extern void func_84136B60(void *, u8, s16, u16);
void func_84136BEC(u8 arg0, u16 arg1, u16 arg2) {
    s32 idx = D_84195280[0x4D81] - 1;
    if (idx < 0) {
        idx = 0x1D;
    }
    func_84136B60(D_84195280 + idx * 0x280, arg0, arg1, arg2);
}
#endif

#ifdef VERSION_US
extern void func_84136B60(void *, u8, s16, u16);
extern u8 * D_84186160[];
void func_84136C48(u8 arg0, u8 arg1, s32 arg2, u16 arg3) {
    u8 *ptr;

    if (arg0 >= 4) {
        return;
    }
    ptr = D_84186160[arg0];
    if (ptr != NULL) {
        func_84136B60(ptr, arg1, arg2, arg3);
    }
}
#endif

#ifdef VERSION_US
extern u8 D_84195280[];
void BattleRecord_AdvanceWriteSlot(void) {
    D_84195280[19841] += 1;
    if (D_84195280[19841] >= 30) {
        D_84195280[19841] = 0;
    }
    _bzero(&D_84195280[D_84195280[19841] * 640], 640);
}
#endif

#ifdef VERSION_US
extern u8 D_84195280[]; u8 *func_84136D00(void) { return &D_84195280[D_84195280[0x4D80] * 0x280]; }
#endif

#ifdef VERSION_US
extern u8 D_84195280[]; u8 *func_84136D20(void) { return &D_84195280[D_84195280[0x4D81] * 0x280]; }
#endif

#ifdef VERSION_US
void func_84136D40(u8 arg0) {
    extern u8 *D_84186160[];
    if (arg0 < 4) {
        D_84186160[arg0] = &D_84195280[D_84195280[0x4D81] * 0x280];
    }
}
#endif

#ifdef VERSION_US
extern u8 *D_84186164, *D_84186168, *D_8418616C;
extern u8 * D_84186160[];
#pragma COALESCE_AT_LUI(func_84136D84)
void func_84136D84(void) {
    extern u8 *D_84186160[];
    D_84186160[0] = 0;
    D_84186164 = 0;
    D_84186168 = 0;
    D_8418616C = 0;
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_3A4030/func_84136D9C.s")
#endif

#ifdef VERSION_US
extern void func_8002B5B0(u8, u32);
extern void func_8002B490(u8);
extern void func_8002BE44(u8);
extern void func_8002C2A0(u16);

void func_84137404(u8 arg0, u16 arg1) {
    switch (arg1) {
        case 0:
            break;
        case 16:
        case 18:
        case 22:
        case 39:
        case 69:
            func_8002B5B0(arg0, D_84195208[arg0][0]);
            break;
        case 17:
        case 19:
        case 20:
        case 21:
            func_8002B490(arg0);
            break;
        case 111:
            func_8002BE44(arg0);
            break;
        default:
            func_8002C2A0(arg1);
            break;
    }
}
#endif

#ifdef VERSION_US
extern void func_84137404(u8, u16); extern void func_8002C2E0(u8);
void func_841374D0(void *arg0) {
    s32 i;

    for (i = 0; i < *(u8 *)((u8 *)arg0 + 0x182); i++) {
        func_84137404(*(u8 *)((u8 *)arg0 + 0x180), *(u16 *)((u8 *)arg0 + 0x184 + i * 2));
    }
    func_8002C2E0(*(u8 *)((u8 *)arg0 + 0x180));
}
#endif

#ifdef VERSION_US
void func_8413753C(void *arg0) {
    func_84147228(0x11, 0U, 0, 6, (s32) (*(u8 *)((u8 *)(arg0) + (0x80))));
    func_84147228(0x11, 0U, 0, 8, (s32) (*(u8 *)((u8 *)(arg0) + (0x81))));
    func_84147228(0x11, 0U, 0, 3, 0);
    func_84147228(0x11, 0U, 0, 0xA, 0);
    func_84147228(0x12, 0U, 0, 6, (s32) (*(u8 *)((u8 *)(arg0) + (0x80))));
    func_84147228(0x12, 0U, 0, 3, 0);
    func_84147228(0x12, 0U, 0, 1, 0);
    func_84147228(0x12, 0U, 0, 0xF, 0);
    func_84147228(0x12, 0U, 0, 0xA, 0);
}
#endif

#ifdef VERSION_US
extern s32 func_841484CC(u8, u8, u8, u8);
void func_84137648(void) {
    if (func_841484CC(0x11, 0, 0, 1) == 0) {
        func_84147228(0x11, 0U, 0, 4, 3);
        func_84147228(0x12, 0U, 0, 4, 3);
    }
}
#endif

#ifdef VERSION_US
void func_841376B0(void *arg0) {
    func_84147228(0x10, 0U, 0, 8, (s32) (*(u8 *)((u8 *)(arg0) + (0x181))));
    func_84147228(0x10, 0U, 0, 3, 0);
    func_84147228(0x10, 0U, 0, 0xA, 0);
}
#endif

#ifdef VERSION_US
extern void func_84147228(u8, u8, u8, u8, s32);
s32 func_8413771C(void) {
    s32 result = 0;
    if (func_841484CC(0x10, 0, 0, 1) == 0) {
        func_84147228(0x10, 0U, 0, 4, 3);
        result = 1;
    }
    return result;
}
#endif

#ifdef VERSION_US
extern s16 D_84199F72;
extern s16 D_84199FFA;
extern u8 D_84199F6A;
extern u8 D_84199D81;
extern u8 D_84199F74[];
extern u8 D_84199DE8[];
void BattleSnapshot_UpdateDisplay(void);
extern u8 D_84199D80[];
extern s32 func_84134A10(u16 arg0, s16 *arg1, u16 *arg2);
extern void func_841374D0(void *arg0);
extern void func_8413753C(void *arg0);
extern void func_84137648(void);
extern void func_841376B0(void *arg0);
extern s32 func_8413771C(void);
void BattleSnapshot_UpdateDisplay(void) {
    if (D_84199D81 & 1) {
        if (D_84199F72 == -1)
            *(s16 *)(D_84199D80 + 498) = 0;
        if (D_84199FFA == -1)
            *(s16 *)(D_84199D80 + 634) = 0;
    }
    if (D_84199FFC != 0 && D_84199F6A < 2 && D_84199FFA != -2) {
        if (func_84134A10(D_84199D86, (s16 *)(D_84199D80 + 634), (u16 *)(D_84199D80 + 636))) {
            if (func_841484CC(17, 0, 0, 1)) {
                func_8413753C(D_84199F74 + 2);
                func_841374D0(D_84199DE8);
                *(u16 *)D_84199F74 = 0;
            }
        } else {
            func_84137648();
        }
        func_8413771C();
        return;
    }
    if (*(u16 *)D_84199F74) {
        if (func_84134A10(D_84199D86, (s16 *)(D_84199DE8 + 394), (u16 *)(D_84199D80 + 500))) {
            if (func_841484CC(16, 0, 0, 1)) {
                func_841376B0(D_84199DE8);
                func_841374D0(D_84199DE8);
                if (D_84199FFA >= -1)
                    D_84199FFC = 0;
                else
                    D_8419A004 = 1;
            }
        } else {
            func_8413771C();
        }
        func_84137648();
        return;
    }
    if (func_8413771C() && D_84199FFA == -2) {
        *(s16 *)(D_84199D80 + 634) = 0;
        D_84199F6A = 0;
    }
    func_84137648();
}
#endif

#ifdef VERSION_US
extern u8 D_84195218[];
void BattleSnapshot_ApplySideChanges(u8 *arg0) {
    struct Change { u16 unk00, value, maximum, status, dvs, active; f32 delta; void *name; u8 unk14, unk15, kind, unk17; };
    struct State { void *name; f32 value; u16 maximum, status, dvs; u8 unk0E, species; u8 unk10[8]; };
    u8 i;
    struct Change *change;
    struct State *state;
    u8 *status;
    u8 *events = arg0 + 104;

    for (i = 0; i < 2; i++) {
        change = (struct Change *)(arg0 + 44 + (u32)i * 24);
        if (change->active != 0) {
            state = (struct State *)(D_84195218 + (u32)i * 24);
            switch (change->kind) {
            case 1:
            case 2:
            case 3:
                state->value += change->delta;
                change->delta = 0.0f;
                if (change->delta == 0.0) {
                    state->value = (f32)func_841349C0(state->value);
                }
                break;
            case 4:
                D_84195200[i] = (u8 *)D_841951F8[i] + (u16)change->delta * 88 + 24;
                state->name = change->name;
                state->value = change->value;
                state->dvs = change->dvs;
                state->species = change->unk14;
                state->maximum = change->maximum;
                state->status = change->status;
                break;
            }
            change->active = 0;
        }
        status = arg0 + 92;
        status += (u32)i * 6;
        if ((*(u16 *)(status + 2)) != 0) {
            ((struct State *)(D_84195218 + (u32)i * 24))->status = (*(u16 *)(status + 4));
        }
    }
    if (*(u16 *)(events + 396) > 0) {
        func_841374D0(events);
    }
    *(u16 *)(arg0 + 6) = 0;
}
#endif

#ifdef VERSION_US
typedef struct { u32 words[0xA0]; } Copy84137BD4;
extern void BattleSnapshot_ApplySideChanges(u8 *);
extern u8 D_84195280[];
extern u8 D_84199D80[];
void func_84137BD4(void) {
    u8 *destination = D_84199D80;
    while (D_84195280[0x4D81] != D_84195280[0x4D80]) {
        BattleSnapshot_ApplySideChanges(destination);
        D_84195280[0x4D80]++;
        if (D_84195280[0x4D80] >= 0x1E) {
            D_84195280[0x4D80] = 0;
        }
        *(Copy84137BD4 *)destination = *(Copy84137BD4 *)&D_84195280[D_84195280[0x4D80] * 0x280];
    }
    BattleSnapshot_ApplySideChanges(destination);
}
#endif

#ifdef VERSION_US
extern void func_84134E30(s32); extern u8 D_84199D81; extern u8 D_8418548C[];
void func_84137CA4(void) {
    u8 *addr = &D_84199D81;
    u8 flags;

    flags = *addr;
    if (flags & 1) {
        flags = *addr;
        flags &= 0xFFFE;
        *addr = flags;
    }
    flags = *addr;
    if (flags & 2) {
        flags &= 0xFFFD;
    }
    *addr = flags;
    if (flags & 4) {
        flags &= 0xFFFB;
        *addr = flags;
    }
}
#endif

#ifdef VERSION_US
extern u8 D_84195256[];
extern void func_84147228(u8, u8, u8, u8, s32);
extern u8 D_8419521C[];
void func_84137D04(u8 arg0) {
    if (*(f32 *)(D_8419521C + arg0 * 24) > 0.0f) {
        func_84147228(1, arg0, 0, 2, 0);
        func_84147228(1, arg0, 0, 0xF, 0);
        if (D_8418615C == 0 || D_84195256[arg0 * 24] != 5) {
            func_84147228(1, arg0, 0, 0xA, 0);
        }
    }
}
#endif

#ifdef VERSION_US
void func_80023A3C(s32, s32, s32);
struct unk_D_84195248 {
    u8 *inputs[2];
    u8 unk08, selected, input0, input1, active, phase, kind, unk0F;
    u8 unk10[8];
};
extern struct unk_D_84195248 D_84195248[2];
#ifndef M2C_FIELD /* sweep: m2c --valid-syntax helpers (mirrors mkdraft.py) */
#define M2C_UNK s32
#define M2C_UNK8 s8
#define M2C_UNK16 s16
#define M2C_UNK32 s32
#define M2C_UNK64 s64
#define M2C_FIELD(expr, type, offset) (*(type)((u8*)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) 0
#define M2C_TRAP_IF(cond) ((void)0)
#define M2C_BREAK() ((void)0)
#define M2C_SYNC() ((void)0)
#define M2C_CARRY 0
#define M2C_STRUCT_COPY(dst, src) ((dst) = (src))
#endif

void func_84137DB8(void) {
    if (M2C_FIELD(D_84195280, u8 *, 0x4D80) != M2C_FIELD(D_84195280, u8 *, 0x4D81)) {
        if (D_84195278 == 3) {
            func_84137D04(0U);
            func_84137D04(1U);
            if ((M2C_FIELD(((u8 *)D_84195248), u8 *, 0xE) == 5) || (M2C_FIELD(((u8 *)D_84195248), u8 *, 0x26) == 5)) {
                func_84147228(0x17, 0U, 0, 7, 1);
                func_84147228(0x17, 0U, 0, 0xB, 4);
            } else {
                func_84147228(0x17, 0U, 0, 7, 0);
                func_84147228(0x17, 0U, 0, 0xB, 2);
            }
            func_84147228(0x17, 0U, 0, 4, 4);
            func_80023A3C(0x27, 0, 0);
        }
        D_84195278 = 2;
        func_84134968();
    }
}
#endif

#ifdef VERSION_US
extern void func_84147228(u8, u8, u8, u8, s32);
extern u8 D_8419521C[];
extern struct unk_D_84195248 D_84195248[2];
void func_84137ED4(u8 arg0) {
    func_84147228(0, arg0, 0, 1, 0);
    func_84147228(1, arg0, 0, 1, 0);
    func_84147228(2, arg0, 0, 1, 0);
    func_84147228(3, arg0, 0, 1, 0);
    func_84147228(4, arg0, 0, 1, 0);
    func_84147228(5, arg0, 0, 1, 0);
    func_84147228(6, arg0, 0, 1, 0);
    func_84147228(7, arg0, 0, 1, 0);
    func_84147228(8, arg0, 0, 1, ((u8 *)D_84195248)[(arg0 * 24) + 0xE] != 1);
    func_84147228(0, arg0, 0, 0xF, 0);
    func_84147228(1, arg0, 0, 0xF, 0);
    func_84147228(2, arg0, 0, 0xF, 0);
    func_84147228(3, arg0, 0, 0xF, 0);
    func_84147228(4, arg0, 0, 0xF, 0);
    func_84147228(5, arg0, 0, 0xF, 0);
    func_84147228(6, arg0, 0, 0xF, 0);
    func_84147228(7, arg0, 0, 0xF, 0);
    func_84147228(8, arg0, 0, 0xF, 0);
    func_84147228(0, arg0, 0, 0xA, 0);
    func_84147228(1, arg0, 0, 0xA, 1);
    func_84147228(2, arg0, 0, 0xA, 2);
    func_84147228(3, arg0, 0, 0xA, 3);
    func_84147228(0, arg0, 0, 4, 4);
    func_84147228(1, arg0, 0, 4, 4);
    func_84147228(2, arg0, 0, 4, 4);
    func_84147228(3, arg0, 0, 4, 4);
    switch (((u8 *)D_84195248)[(arg0 * 24) + 0xE]) {
    case 1:
        func_84147228(4, arg0, 0, 0xA, 0);
        func_84147228(5, arg0, 0, 0xA, 0);
        func_84147228(6, arg0, 0, 0xA, 0);
        func_84147228(4, arg0, 0, 4, 4);
        func_84147228(5, arg0, 0, 4, 4);
        func_84147228(6, arg0, 0, 4, 4);
        break;
    case 2:
    case 5:
        func_84147228(7, arg0, 0, 0xB, 0);
        func_84147228(8, arg0, 0, 0xA, 0);
        func_84147228(8, arg0, 0, 4, 4);
        break;
    }
    if (*(f32 *)(D_8419521C + (arg0 * 24)) > 0.0f) {
        func_84147228(1, arg0, 0, 5, 0x10);
        func_84147228(2, arg0, 0, 5, 0x10);
    } else {
        func_84147228(1, arg0, 0, 4, 0x10);
        func_84147228(2, arg0, 0, 4, 0x10);
    }
}
#endif

#ifdef VERSION_US
void func_84138364(u8 arg0) {
    func_84147228(1, arg0, 0, 0xB, 0);
    func_84147228(1, arg0, 0, 4, 4);
}
#endif

#ifdef VERSION_US
struct unk_D_8419A008 {
    s32 unk00, unk04;
    u32 elapsed;
    s16 fraction, unk0E, unk10;
    u8 flags;
};
extern struct unk_D_8419A008 D_8419A008[];
extern s32 D_84186170;
extern void func_8002B47C(u16, u16);
extern void func_8002AAFC(s32);
extern void func_80023A3C(s32, s32, s32);
extern u8 D_8419A0A1;
extern s32 func_84134968(void);
extern void func_84138364(u8 arg0);
extern void func_84147228(u8, u8, u8, u8, s32);
extern struct unk_D_84195248 D_84195248[2];
extern u8 D_84195278;
extern u8 D_8419A0A0[];
void func_841383B4(u8 arg0, u8 arg1, u8 arg2) {
    s32 i;
    ((u8 *)D_84195248)[0xD] = arg0; ((u8 *)D_84195248)[0xE] = arg0;
    ((u8 *)D_84195248)[0x25] = arg1; ((u8 *)D_84195248)[0x26] = arg1;
    D_8418615C = arg2; D_84195278 = 4;
    func_8002B47C(*(u16 *)(((u8 *)&D_8419A008) + 0xE), *(u16 *)(((u8 *)&D_8419A008) + 0x10));
    if (D_84186170 != 0) func_8002AAFC(1);
    i = 0;
    do { func_84138364((u8)i); i++; } while (i != 2);
    if ((D_8419A0A0[0] == 0 || D_8419A0A1 != 0) && arg2 == 0) {
        if (((u8 *)D_84195248)[0xE] == 5 || ((u8 *)D_84195248)[0x26] == 5) func_84147228(0x17, 0, 0, 7, 2);
        else func_84147228(0x17, 0, 0, 7, 0);
        func_84147228(0x17, 0, 0, 10, 0);
        func_84147228(0x17, 0, 0, 4, 4);
        func_80023A3C(0x26, 0, 0);
    }
    func_84134968();
}
#endif

#ifdef VERSION_US
extern u8 D_84195218[];
void func_84138530(u8 arg0, u8 *arg1) { struct Record { void *ptr; f32 value; u16 field8; u16 fieldA; u16 fieldC; u8 fieldE; u8 fieldF; u8 pad[8]; }; struct Record *record = (struct Record *)D_84195218 + arg0; record->ptr = arg1 + 0x34; record->value = *(u16 *)(arg1 + 0x26); record->field8 = *(u16 *)(arg1 + 0x28); record->fieldA = arg1[0x24]; record->fieldC = *(u16 *)(arg1 + 0x16); record->fieldF = arg1[0]; record->fieldE = arg1[0x1D]; }
#endif

#ifdef VERSION_US
extern s32 D_8419527C;
extern void * D_841951F0;
void func_841385A8(u8 arg0, u8 arg1) {
    struct State { u8 pad[0x9D8]; u8 *items; };
    if (D_8419527C < 0x67) {
        u8 field = (((struct State *)D_841951F0)->items + D_8419527C)[4];
        u8 high = arg1 << 4;
        (((struct State *)D_841951F0)->items + D_8419527C)[4] = arg0 ? ((field & 0xF0) | (arg1 & 0xF)) : ((field & 0xF) | high);
    }
}
#endif

#ifdef VERSION_US
extern void * D_841951F0;
extern s32 D_8419527C;
s32 func_8413860C(u8 arg0) {
    s32 selected;
    s32 result;
    u8 packed;
    result = D_8419527C;
    if (result < 0x67) {
        packed = (*((u8 **) (((u8 *) D_841951F0) + 0x9D8)))[result + 4];
        if (arg0) {
            selected = (unsigned int) (packed & 0xF);
        } else {
            selected = (packed & 0xF0) >> 4;
        }
        result = selected & 0xFF;
        return result;
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_3A4030/func_84138658.s")
#endif

#ifdef VERSION_US
extern void * D_841951F8[];
s32 func_8413882C(u8 arg0, u8 arg1) {
    u8 *ptr = D_841951F8[arg0];

    if (ptr[0x12] != 0) {
        if (ptr[0xA] < ptr[3]) {
            return arg1 >= ptr[3];
        }
        return arg1 < ptr[3];
    }
    return 1;
}
#endif

#ifdef VERSION_US
extern u8 * D_84195208[];
s32 func_8413888C(u8 arg0) {
    u8 *ptr = D_84195208[arg0];

    if (ptr[5] == 0) {
        return 0;
    }
    if ((ptr[9] & 0x3F) > 0) {
        return 1;
    }
    if (ptr[6] == 0) {
        return 0;
    }
    if ((ptr[0xA] & 0x3F) > 0) {
        return 1;
    }
    if (ptr[7] == 0) {
        return 0;
    }
    if ((ptr[0xB] & 0x3F) > 0) {
        return 1;
    }
    if (ptr[8] == 0) {
        return 0;
    }
    if ((ptr[0xC] & 0x3F) > 0) {
        return 1;
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern u8 * D_84195208[];
s32 func_84138960(u8 arg0) {
    s32 result = 0;
    u8 *base = D_84195208[arg0];
    u8 *ptr = base;
    while (result != 4) {
        if (ptr[5] == 0) return 0;
        if ((ptr[9] & 0x3F) > 0 && ptr[5] != base[0x25]) return 1;
        result += 2;
        if (ptr[6] == 0) return 0;
        if ((ptr[0xA] & 0x3F) > 0 && ptr[6] != base[0x25]) return 1;
        ptr += 2;
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern void BattleSelection_ShowChoiceError(u8, u8);
extern void func_800226C0(s32);
extern void * D_841951F8[];
extern struct unk_D_84195248 D_84195248[2];
void BattleSelection_ShowChoiceError(u8 arg0, u8 arg1) {
    switch (((u8 *)D_84195248)[arg0 * 24 + 13]) {
    case 2:
    case 5:
        func_84147228(7, arg0, 0, 11, 0);
        func_84147228(8, arg0, 0, 11, 0);
        func_84147228(7, arg0, 0, 4, 4);
        func_84147228(8, arg0, 0, 4, 4);
        break;
    case 3:
        func_84147228(9, arg0, 0, 11, 0);
        func_84147228(19, arg0, 0, 11, 0);
        func_84147228(9, arg0, 0, 4, 4);
        func_84147228(19, arg0, 0, 4, 4);
        break;
    case 4:
        func_84147228(10, arg0, 0, 11, 0);
        func_84147228(10, arg0, 0, 4, 4);
        break;
    case 6:
        if (((u8 *)D_841951F8[arg0])[2] == 1) {
            if (((u8 *)D_841951F8[arg0])[8] >= 4) {
                func_84147228(12, arg0, 0, 11, 0);
                func_84147228(12, arg0, 0, 4, 4);
            } else {
                func_84147228(11, arg0, 0, 11, 0);
                func_84147228(11, arg0, 0, 4, 4);
            }
        } else {
            func_84147228(11, arg0, 0, 11, 0);
            func_84147228(11, arg0, 0, 4, 4);
            func_84147228(11, arg0, 1, 11, 0);
            func_84147228(11, arg0, 1, 4, 4);
        }
        func_84147228(20, arg0, 0, 11, 0);
        func_84147228(20, arg0, 0, 4, 4);
        break;
    case 7:
        func_84147228(13, arg0, 0, 11, 0);
        func_84147228(13, arg0, 0, 4, 4);
        break;
    }
    func_84147228(15, arg0, 0, 7, arg1);
    func_84147228(15, arg0, 0, 10, 0);
    func_84147228(15, arg0, 0, 4, 4);
    func_800226C0(5);
    ((u8 *)D_84195248)[arg0 * 24 + 13] = 9;
}
#endif

#ifdef VERSION_US
extern u8 D_84195255[];
extern s32 func_84148494(u8, u8, u8);
extern void func_84147228(u8, u8, u8, u8, s32);
void func_84138D74(u8 arg0) {
    func_84147228(7, arg0, 0, 10, 0);
    func_84147228(8, arg0, 0, 10, 0);
    func_84147228(7, arg0, 0, 4, 4);
    func_84147228(8, arg0, 0, 4, 4);
    func_84147228(0xF, arg0, 0, 0xB, 0);
    func_84147228(0xF, arg0, 0, 4, 4);
    switch (func_84148494(0xF, arg0, 0)) {
    case 0:
    case 1:
        D_84195255[(arg0 * 3) * 8] = 2;
        break;
    case 2:
    case 4:
    case 5:
    case 6:
        D_84195255[(arg0 * 3) * 8] = 5;
        break;
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_3A4030/func_84138EA4.s")
#endif

#ifdef VERSION_US
extern void func_84138EA4(u8, u8);
extern u8 * D_84195208[];
void func_84139244(u8 arg0) {
    s32 i;
    u8 *p;

    for (i = 0; i != 4; i++) {
        p = D_84195208[arg0] + i;
        if ((p[5] != 0) && ((p[9] & 0x3F) == 0)) {
            func_84138EA4(arg0, i);
        }
    }
    func_84138EA4(arg0, 0);
}
#endif

#ifdef VERSION_US
extern void func_84138EA4(u8, u8);
extern u8 * D_84195208[];
void func_841392E0(u8 arg0) {
    u8 index = arg0;
    u8 *base = D_84195208[index];
    s32 i;
    for (i = 0; i < 4; i++) {
        u8 *ptr = base + i;
        if (ptr[5] != 0 && ptr[5] != base[0x25] && (ptr[9] & 0x3F) > 0) {
            func_84138EA4(index, i);
            return;
        }
    }
}
#endif

#ifdef VERSION_US
extern void func_800226C0(s32);
extern u8 D_8419A01A;

void func_84139364(u8 arg0) {
    switch (((u8 *)D_84195248)[(u32)arg0 * 24 + 14]) {
        case 1:
            func_84147228(4, arg0, 0, 13, 0);
            func_84147228(5, arg0, 0, 13, 0);
            func_84147228(6, arg0, 0, 13, 0);
            func_84147228(4, arg0, 0, 4, 4);
            func_84147228(5, arg0, 0, 4, 4);
            func_84147228(6, arg0, 0, 4, 4);
            func_84147228(7, arg0, 0, 1, 0);
            func_84147228(8, arg0, 0, 1, 0);
            func_84147228(7, arg0, 0, 15, 0);
            func_84147228(8, arg0, 0, 15, 0);
            break;
        default:
            func_84147228(8, arg0, 0, 10, 0);
            break;
    }
    if (D_8419A01A & 2) {
        func_84147228(22, arg0, 0, 10, 0);
        func_84147228(22, arg0, 0, 4, 4);
    }
    ((u8 *)D_84195248)[(u32)arg0 * 24 + 13] = ((u8 *)D_84195248)[(u32)arg0 * 24 + 14];
    func_800226C0(3);
}
#endif

#ifdef VERSION_US
extern void BattleSelection_ShowChoiceError(u8, u8);
extern void func_800226C0(s32);
extern s32 func_84138960(u8 arg0);
extern void func_84138EA4(u8, u8);
extern void func_84139244(u8);
extern u8 * D_84195208[];
void func_84139528(u8 arg0, u8 arg1) {
    if (func_84138960(arg0) != 0) {
        if (D_84195208[arg0][arg1 + 5] == 0) {
            func_800226C0(5);
        } else if ((D_84195208[arg0][arg1 + 9] & 0x3F) == 0) {
            BattleSelection_ShowChoiceError(arg0, 0);
        } else if (D_84195208[arg0][arg1 + 5] == D_84195208[arg0][0x25]) {
            BattleSelection_ShowChoiceError(arg0, 1);
        } else {
            func_84138EA4(arg0, arg1);
        }
    } else {
        if (D_84195208[arg0][arg1 + 5] == 0) {
            func_800226C0(5);
        } else {
            func_84139244(arg0);
        }
    }
}
#endif

#ifdef VERSION_US
extern u8 * D_8419520C[];
void BattleSelection_HandlePartyChoice(u8 arg0, u8 arg1) {
    if (arg1 >= ((u8 *)D_841951F8[arg0])[8]) {
        func_800226C0(5);
        return;
    }
    if (*(u16 *)((u8 *)D_841951F8[arg0] + (u32)arg1 * 88 + 62) == 0) {
        BattleSelection_ShowChoiceError(arg0, 2);
        return;
    }
    if (arg1 == ((u8 *)D_841951F8[arg0])[10]) {
        BattleSelection_ShowChoiceError(arg0, 5);
        return;
    }
    /* D_8419520C names slot 1 of the two-pointer record table. */
    if (D_84195256[(u32)arg0 * 24] != 5 && ((*(u8 **)((u8 *)D_8419520C + -((s32)arg0 * (s32)sizeof(D_8419520C[0]))))[17] & 0x80) != 0) {
        BattleSelection_ShowChoiceError(arg0, 4);
        return;
    }
    if (D_84195256[(u32)arg0 * 24] != 5 && D_84195208[arg0][27] > 0) {
        BattleSelection_ShowChoiceError(arg0, 4);
        return;
    }
    if (func_8413882C(arg0, arg1) == 0) {
        BattleSelection_ShowChoiceError(arg0, 6);
    } else {
        func_84138EA4(arg0, arg1 + 4);
    }
}
#endif

#ifdef VERSION_US
extern void * D_841951F8[];
void func_84139770(u8 arg0) {
    u8 *base = D_841951F8[arg0];
    s32 i;
    for (i = 0; i < base[8]; i++) {
        u8 *ptr = base + i * 0x58;
        if (ptr[0x18] != 0 && *(u16 *)(ptr + 0x3E) > 0 && i != base[0xA]) {
            func_84138EA4(arg0, (u8)(i + 4));
            return;
        }
    }
}
#endif

#ifdef VERSION_US
extern void func_800226C0(s32);
extern void func_84147228(u8, u8, u8, u8, s32);
extern u8 D_84195255[];
void func_841397FC(u8 arg0, u8 arg1) {
    u8 index = arg0;
    func_800226C0(2);
    D_84195255[index * 24] = arg1;
    func_84147228(4, index, 0, 0xC, 0);
    func_84147228(5, index, 0, 0xC, 0);
    func_84147228(6, index, 0, 0xC, 0);
    func_84147228(7, index, 0, 0xA, 2);
    func_84147228(8, index, 0, 0xA, 2);
    func_84147228(4, index, 0, 4, 4);
    func_84147228(5, index, 0, 4, 4);
    func_84147228(6, index, 0, 4, 4);
    func_84147228(7, index, 0, 4, 4);
    func_84147228(8, index, 0, 4, 4);
}
#endif

#ifdef VERSION_US
void func_84139958(u8 arg0, u8 arg1) {
    switch (((u8 *)D_84195248)[arg0 * 24 + 13]) {
        case 2:
        case 5:
            func_84147228(7, arg0, 0, 11, 0);
            func_84147228(8, arg0, 0, 11, 0);
            func_84147228(7, arg0, 0, 4, 4);
            func_84147228(8, arg0, 0, 4, 4);
            break;
        case 3:
            func_84147228(9, arg0, 0, 11, 0);
            func_84147228(9, arg0, 0, 4, 4);
            func_84147228(19, arg0, 0, 11, 0);
            break;
        case 4:
            func_84147228(10, arg0, 0, 11, 0);
            func_84147228(10, arg0, 0, 4, 4);
            break;
        case 6:
            if (((u8 *)D_841951F8[arg0])[2] == 1) {
                if (((u8 *)D_841951F8[arg0])[8] >= 4) {
                    func_84147228(12, arg0, 0, 11, 0);
                } else {
                    func_84147228(11, arg0, 0, 11, 0);
                }
            } else {
                func_84147228(11, arg0, 0, 11, 0);
                func_84147228(11, arg0, 1, 11, 0);
            }
            func_84147228(20, arg0, 0, 11, 0);
            break;
        case 7:
            func_84147228(13, arg0, 0, 11, 0);
            break;
    }
    func_84147228(4, arg0, 0, 13, 2);
    func_84147228(5, arg0, 0, 13, 2);
    func_84147228(6, arg0, 0, 13, 2);
    func_84147228(4, arg0, 0, 4, 4);
    func_84147228(5, arg0, 0, 4, 4);
    func_84147228(6, arg0, 0, 4, 4);
    func_800226C0(3);
    ((u8 *)D_84195248)[arg0 * 24 + 13] = arg1;
}
#endif

#ifdef VERSION_US
extern u8 D_8419526D;
extern void func_800226C0(s32);
extern void func_84147228(u8, u8, u8, u8, s32);
extern u8 D_84195255[];
void func_84139C54(u8 arg0) {
    if (*(&D_8419526D + -(arg0 * 24)) != 8) {
        D_84195255[(u32)arg0 * 24] = 8;
        func_800226C0(2);
        func_84147228(4, arg0, 0, 0xB, 0);
        func_84147228(5, arg0, 0, 0xB, 0);
        func_84147228(6, arg0, 0, 0xB, 0);
        func_84147228(4, arg0, 0, 4, 4);
        func_84147228(5, arg0, 0, 4, 4);
        func_84147228(6, arg0, 0, 4, 4);
        func_84147228(0xE, arg0, 0, 0xA, 0);
        func_84147228(0xE, arg0, 0, 4, 4);
    }
}
#endif

#ifdef VERSION_US
extern void func_800226C0(s32);
extern void func_84147228(u8, u8, u8, u8, s32);
extern u8 D_84195255[];
void func_84139D94(u8 arg0) {
    u8 index = arg0;
    D_84195255[index * 24] = 1;
    func_800226C0(3);
    func_84147228(4, index, 0, 0xA, 0);
    func_84147228(5, index, 0, 0xA, 0);
    func_84147228(6, index, 0, 0xA, 0);
    func_84147228(4, index, 0, 4, 4);
    func_84147228(5, index, 0, 4, 4);
    func_84147228(6, index, 0, 4, 4);
    func_84147228(0xE, index, 0, 0xB, 0);
    func_84147228(0xE, index, 0, 4, 4);
}
#endif

#ifdef VERSION_US
extern void func_84139C54(u8);
extern void func_841397FC(u8,u8);
extern struct unk_D_84195248 D_84195248[2];
void func_84139EB0(s32 arg0) {
    u8 *record; u8 *data; s32 flags;
    record = ((u8 *)D_84195248) + arg0 * 24; data = ((u8 **)record)[record[9]]; flags = *(u16 *)(data + 8);
    if (flags & 0x8000) func_841397FC(arg0, 2); else if (flags & 0x4000) func_841397FC(arg0, 5); else if (flags & 0x1000) func_84139C54(arg0);
}
#endif

#ifdef VERSION_US
extern void func_800226C0(s32);
extern void func_84147228(u8, u8, u8, u8, s32);
extern struct unk_D_84195248 D_84195248[2];
void func_84139F44(u8 arg0) {
    switch (((u8 *)D_84195248)[arg0 * 24 + 0xD]) {
        case 2:
            func_84147228(7, arg0, 0, 11, 0);
            func_84147228(8, arg0, 0, 11, 0);
            func_84147228(7, arg0, 0, 5, 4);
            func_84147228(8, arg0, 0, 5, 4);
            func_84147228(9, arg0, 0, 10, 0);
            func_84147228(9, arg0, 0, 5, 6);
            func_84147228(19, arg0, 0, 10, 0);
            func_84147228(19, arg0, 0, 5, 6);
            func_800226C0(8);
            break;
        case 4:
            func_84147228(10, arg0, 0, 4, 1);
            func_84147228(9, arg0, 0, 1, 0);
            func_84147228(9, arg0, 0, 3, 0);
            func_84147228(9, arg0, 0, 5, 3);
            func_84147228(19, arg0, 0, 3, 0);
            func_84147228(19, arg0, 0, 5, 3);
            break;
    }
    ((u8 *)D_84195248)[arg0 * 24 + 0xD] = 3;
}
#endif

#ifdef VERSION_US
void func_8413A12C(u8 arg0, u8 arg1) {
    if (((u8 *)D_84195208[(u32)arg0])[(u32)arg1 + 5] == 0) {
        return;
    }
    switch (((u8 *)D_84195248)[arg0 * 24 + 13]) {
        case 2:
            func_84147228(7, arg0, 0, 11, 0);
            func_84147228(8, arg0, 0, 11, 0);
            func_84147228(7, arg0, 0, 4, 4);
            func_84147228(8, arg0, 0, 4, 4);
            func_84147228(10, arg0, 0, 10, 0);
            func_84147228(10, arg0, 0, 4, 6);
            func_800226C0(8);
            break;
        case 3:
            func_84147228(9, arg0, 0, 4, 3);
            func_84147228(9, arg0, 0, 9, 0);
            func_84147228(19, arg0, 0, 4, 3);
            func_84147228(19, arg0, 0, 9, 0);
            func_84147228(10, arg0, 0, 1, 0);
            func_84147228(10, arg0, 0, 3, 0);
            func_84147228(10, arg0, 0, 5, 3);
            func_800226C0(8);
            break;
    }
    ((u8 *)D_84195248)[arg0 * 24 + 13] = 4;
    func_84147228(10, arg0, 0, 7, arg1);
}
#endif

#ifdef VERSION_US
extern struct unk_D_84195248 D_84195248[2];
void func_8413A340(u8 arg0) {
    switch (((u8 *)D_84195248)[arg0 * 24 + 0xD]) {
    case 3:
        func_84147228(7,arg0,0,10,0);
        func_84147228(8,arg0,0,10,0);
        func_84147228(7,arg0,0,5,4);
        func_84147228(8,arg0,0,5,4);
        func_84147228(9,arg0,0,11,0);
        func_84147228(9,arg0,0,5,4);
        func_84147228(9,arg0,0,4,2);
        func_84147228(19,arg0,0,11,0);
        func_84147228(19,arg0,0,5,4);
        break;
    case 4:
        func_84147228(7,arg0,0,10,0);
        func_84147228(8,arg0,0,10,0);
        func_84147228(7,arg0,0,4,4);
        func_84147228(8,arg0,0,4,4);
        func_84147228(10,arg0,0,11,0);
        func_84147228(10,arg0,0,4,4);
        break;
    }
    ((u8 *)D_84195248)[arg0 * 24 + 0xD] = 2;
}
#endif

#ifdef VERSION_US
extern void func_8413A12C(u8, u8);
extern void func_84139F44(u8);
extern void func_84139528(u8 arg0, u8 arg1);
extern void func_84139958(u8, u8);
extern void func_8413A340(u8 arg0);
extern struct unk_D_84195248 D_84195248[2];
void func_8413A53C(u8 arg0) {
    u8 *data = ((u8 **)(((u8 *)D_84195248) + arg0 * 24))[(((u8 *)D_84195248) + arg0 * 24)[9]];
    if (*(u16 *)(data + 6) & 0x800) func_8413A12C(arg0, 0);
    else if (*(u16 *)(data + 6) & 0x100) func_8413A12C(arg0, 1);
    else if (*(u16 *)(data + 6) & 0x400) func_8413A12C(arg0, 2);
    else if (*(u16 *)(data + 6) & 0x200) func_8413A12C(arg0, 3);
    else if (*(u16 *)(data + 6) & 0x10) func_84139F44(arg0);
    else func_8413A340(arg0);
    if (*(u16 *)(data + 8) & 0x20) {
        if ((((u8 *)D_84195248) + arg0 * 24)[0xE] < 2) func_84139958(arg0, 1);
    } else if (*(u16 *)(data + 8) & 8) func_84139528(arg0, 0);
    else if (*(u16 *)(data + 8) & 1) func_84139528(arg0, 1);
    else if (*(u16 *)(data + 8) & 4) func_84139528(arg0, 2);
    else if (*(u16 *)(data + 8) & 2) func_84139528(arg0, 3);
}
#endif

#ifdef VERSION_US
void BattleSelection_EnterRosterSelection(u8 side, u8 partition, u8 element) {
    switch (D_84195248[side].phase) {
    case 5:
        func_84147228(7, side, 0, 11, 0);
        func_84147228(8, side, 0, 11, 0);
        func_84147228(7, side, 0, 5, 4);
        func_84147228(8, side, 0, 5, 4);
        func_84147228(element, side, partition, 10, 0);
        func_84147228(element, side, partition, 5, 6);
        func_84147228(20, side, 0, 10, 0);
        func_84147228(20, side, 0, 5, 6);
        func_800226C0(8);
        break;
    case 7:
        func_84147228(13, side, partition, 4, 1);
        func_84147228(element, side, partition, 1, 0);
        func_84147228(element, side, partition, 3, 0);
        func_84147228(element, side, partition, 5, 3);
        func_84147228(20, side, 0, 5, 3);
        func_84147228(20, side, 0, 3, 0);
        break;
    }
    D_84195248[side].phase = 6;
}
#endif

#ifdef VERSION_US
void func_8413A8C4(u8 arg0) {
    switch (((u8 *)D_84195248)[(u32)arg0 * 24 + 13]) {
        case 5:
            func_84147228(7, arg0, 0, 11, 0);
            func_84147228(8, arg0, 0, 11, 0);
            func_84147228(7, arg0, 0, 5, 4);
            func_84147228(8, arg0, 0, 5, 4);
            func_84147228(11, arg0, 0, 10, 0);
            func_84147228(11, arg0, 0, 5, 6);
            func_84147228(11, arg0, 1, 10, 0);
            func_84147228(11, arg0, 1, 5, 6);
            func_84147228(20, arg0, 0, 10, 0);
            func_84147228(20, arg0, 0, 5, 6);
            func_800226C0(8);
            break;
        case 7:
            func_84147228(13, arg0, 0, 4, 1);
            func_84147228(11, arg0, 0, 1, 0);
            func_84147228(11, arg0, 0, 3, 0);
            func_84147228(11, arg0, 0, 5, 3);
            func_84147228(11, arg0, 1, 1, 0);
            func_84147228(11, arg0, 1, 3, 0);
            func_84147228(11, arg0, 1, 5, 3);
            func_84147228(20, arg0, 0, 5, 3);
            func_84147228(20, arg0, 0, 3, 0);
            break;
    }
    ((u8 *)D_84195248)[(u32)arg0 * 24 + 13] = 6;
}
#endif

#ifdef VERSION_US
extern void func_800226C0(s32);
extern void func_84147228(u8, u8, u8, u8, s32);
extern void * D_841951F8[];
extern struct unk_D_84195248 D_84195248[2];
// Close to func_8413AD98; gated on arg2 being below byte 8 of D_841951F8[arg0] instead of a
// per-slot flag, has no case 7, and case 6 starts with two calls whose first argument is arg3.
void func_8413AB2C(u8 arg0, u8 arg1, s8 arg2, u8 arg3) {
    if ((u8)arg2 < ((u8 *)D_841951F8[arg0])[8]) {
        switch (((u8 *)D_84195248)[arg0 * 24 + 0xD]) {
        case 5:
            func_84147228(7, arg0, 0, 11, 0);
            func_84147228(8, arg0, 0, 11, 0);
            func_84147228(7, arg0, 0, 4, 4);
            func_84147228(8, arg0, 0, 4, 4);
            func_84147228(13, arg0, 0, 8, arg1);
            func_84147228(13, arg0, 0, 3, 0);
            func_84147228(13, arg0, 0, 10, 0);
            func_84147228(13, arg0, 0, 4, 6);
            func_800226C0(8);
            break;
        case 6:
            // FAKE: reading arg3 through its address reloads it from its stack slot for each
            // call; diff score 474 with plain arg3.
            func_84147228(*(u8 *)&arg3, arg0, 0, 4, 1);
            func_84147228(*(u8 *)&arg3, arg0, 0, 9, 0);
            func_84147228(20, arg0, 0, 4, 3);
            func_84147228(20, arg0, 0, 9, 0);
            func_84147228(13, arg0, 0, 8, arg1);
            func_84147228(13, arg0, 0, 1, 0);
            func_84147228(13, arg0, 0, 3, 0);
            func_84147228(13, arg0, 0, 5, 3);
            func_800226C0(8);
            break;
        }
        ((u8 *)D_84195248)[arg0 * 24 + 0xD] = 7;
        func_84147228(13, arg0, 0, 7, *(u8 *)&arg2);
    }
}
#endif

#ifdef VERSION_US
extern void func_800226C0(s32);
extern void func_84147228(u8, u8, u8, u8, s32);
extern void * D_841951F8[];
extern struct unk_D_84195248 D_84195248[2];
void func_8413AD98(u8 arg0, u8 arg1, u8 arg2) {
    /* Party records use an unsigned byte index and an 88-byte stride. */
    if (((u8 *)D_841951F8[arg0])[(u32)arg2 * 88 + 24] != 0) {
        switch (((u8 *)D_84195248)[arg0 * 24 + 0xD]) {
        case 5:
            func_84147228(7, arg0, 0, 11, 0);
            func_84147228(8, arg0, 0, 11, 0);
            func_84147228(7, arg0, 0, 4, 4);
            func_84147228(8, arg0, 0, 4, 4);
            func_84147228(13, arg0, 0, 8, arg1);
            func_84147228(13, arg0, 0, 3, 0);
            func_84147228(13, arg0, 0, 10, 0);
            func_84147228(13, arg0, 0, 4, 6);
            func_800226C0(8);
            break;
        case 6:
            func_84147228(11, arg0, 0, 4, 1);
            func_84147228(11, arg0, 1, 4, 1);
            func_84147228(11, arg0, 0, 9, 0);
            func_84147228(11, arg0, 1, 9, 0);
            func_84147228(20, arg0, 0, 4, 3);
            func_84147228(20, arg0, 0, 9, 0);
            func_84147228(13, arg0, 0, 8, arg1);
            func_84147228(13, arg0, 0, 1, 0);
            func_84147228(13, arg0, 0, 3, 0);
            func_84147228(13, arg0, 0, 5, 3);
            func_800226C0(8);
            break;
        case 7:
            func_84147228(13, arg0, 0, 8, arg1);
            func_84147228(13, arg0, 0, 3, 0);
            break;
        }
        ((u8 *)D_84195248)[arg0 * 24 + 0xD] = 7;
        func_84147228(13, arg0, 0, 7, arg2);
    }
}
#endif

#ifdef VERSION_US
// FAKE: volatile makes each use of arg1 reload it from its stack home; diff score 784 without it.
void func_8413B08C(u8 arg0, volatile u8 arg1) {
    switch (((u8 *)D_84195248)[(u32)arg0 * 24 + 13]) {
        case 6:
            func_84147228(7, arg0, 0, 10, 0);
            func_84147228(8, arg0, 0, 10, 0);
            func_84147228(7, arg0, 0, 5, 4);
            func_84147228(8, arg0, 0, 5, 4);
            func_84147228(arg1, arg0, 0, 11, 0);
            func_84147228(arg1, arg0, 0, 5, 4);
            func_84147228(arg1, arg0, 0, 4, 2);
            func_84147228(20, arg0, 0, 11, 0);
            func_84147228(20, arg0, 0, 5, 4);
            func_84147228(20, arg0, 0, 4, 2);
            break;
        case 7:
            func_84147228(7, arg0, 0, 10, 0);
            func_84147228(8, arg0, 0, 10, 0);
            func_84147228(13, arg0, 0, 11, 0);
            break;
    }
    ((u8 *)D_84195248)[(u32)arg0 * 24 + 13] = 5;
}
#endif

#ifdef VERSION_US
extern void func_84147228(u8, u8, u8, u8, s32);
extern struct unk_D_84195248 D_84195248[2];
void func_8413B254(u8 arg0) {
    switch (((u8 *)D_84195248)[(u32)arg0 * 24 + 0xD]) {
    case 6:
        func_84147228(7, arg0, 0, 0xA, 0);
        func_84147228(8, arg0, 0, 0xA, 0);
        func_84147228(7, arg0, 0, 5, 4);
        func_84147228(8, arg0, 0, 5, 4);
        func_84147228(0xB, arg0, 0, 0xB, 0);
        func_84147228(0xB, arg0, 0, 5, 4);
        func_84147228(0xB, arg0, 0, 4, 2);
        func_84147228(0xB, arg0, 1, 0xB, 0);
        func_84147228(0xB, arg0, 1, 5, 4);
        func_84147228(0xB, arg0, 1, 4, 2);
        func_84147228(0x14, arg0, 0, 0xB, 0);
        func_84147228(0x14, arg0, 0, 5, 4);
        func_84147228(0x14, arg0, 0, 4, 2);
        break;
    case 7:
        func_84147228(7, arg0, 0, 0xA, 0);
        func_84147228(8, arg0, 0, 0xA, 0);
        func_84147228(0xD, arg0, 0, 0xB, 0);
        break;
    }
    ((u8 *)D_84195248)[(u32)arg0 * 24 + 0xD] = 5;
}
#endif

#ifdef VERSION_US
extern void BattleSelection_EnterRosterSelection(u8, u8, u8);
void BattleSelection_HandleSmallRosterInput(u8 side) {
    u8 *record;
    record = D_84195248[side].inputs[0];
    if (*(u16 *)(record + 6) & 0x200)
        func_8413AB2C(side, 0, 0, 11);
    else if (*(u16 *)(record + 6) & 0x100)
        func_8413AB2C(side, 0, 2, 11);
    else if (*(u16 *)(record + 6) & 0x800)
        func_8413AB2C(side, 0, 1, 11);
    else if (*(u16 *)(record + 6) & 0x10)
        BattleSelection_EnterRosterSelection(side, 0, 11);
    else
        func_8413B08C(side, 11);
    if (*(u16 *)(record + 8) & 0x20) {
        if (D_84195248[side].kind < 2)
            func_84139958(side, 1);
    } else if (*(u16 *)(record + 8) & 2)
        BattleSelection_HandlePartyChoice(side, 0);
    else if (*(u16 *)(record + 8) & 8)
        BattleSelection_HandlePartyChoice(side, 1);
    else if (*(u16 *)(record + 8) & 1)
        BattleSelection_HandlePartyChoice(side, 2);
}
#endif

#ifdef VERSION_US
void BattleSelection_HandleLargeRosterInput(u8 side) {
    u8 *record = D_84195248[side].inputs[0];
    if (*(u16 *)(record + 6) & 0x800) {
        D_84195248[side].unk08 = 1;
    } else if (*(u16 *)(record + 6) & 0x400) {
        D_84195248[side].unk08 = 2;
    } else if (!(*(u16 *)(record + 6) & 0x300)) {
        D_84195248[side].unk08 = 0;
    }
    if (D_84195248[side].unk08 == 1) {
        if (*(u16 *)(record + 6) & 0x200)
            func_8413AB2C(side, 0, 0, 12);
        else if (*(u16 *)(record + 6) & 0x100)
            func_8413AB2C(side, 0, 2, 12);
        else if (*(u16 *)(record + 6) & 0x800)
            func_8413AB2C(side, 0, 1, 12);
    } else if (D_84195248[side].unk08 == 2) {
        if (*(u16 *)(record + 6) & 0x200)
            func_8413AB2C(side, 0, 3, 12);
        else if (*(u16 *)(record + 6) & 0x100)
            func_8413AB2C(side, 0, 5, 12);
        else if (*(u16 *)(record + 6) & 0x400)
            func_8413AB2C(side, 0, 4, 12);
    } else if (*(u16 *)(record + 6) & 0x10)
        BattleSelection_EnterRosterSelection(side, 0, 12);
    else
        func_8413B08C(side, 12);
    if (*(u16 *)(record + 8) & 0x20) {
        if (D_84195248[side].kind < 2)
            func_84139958(side, 1);
    } else if (*(u16 *)(record + 8) & 0x4000)
        BattleSelection_HandlePartyChoice(side, 0);
    else if (*(u16 *)(record + 8) & 2)
        BattleSelection_HandlePartyChoice(side, 1);
    else if (*(u16 *)(record + 8) & 8)
        BattleSelection_HandlePartyChoice(side, 2);
    else if (*(u16 *)(record + 8) & 0x8000)
        BattleSelection_HandlePartyChoice(side, 3);
    else if (*(u16 *)(record + 8) & 4)
        BattleSelection_HandlePartyChoice(side, 4);
    else if (*(u16 *)(record + 8) & 1)
        BattleSelection_HandlePartyChoice(side, 5);
}
#endif

#ifdef VERSION_US
extern u8 func_84148470(u8);
void BattleSelection_ProcessControllerPartitions(u8 arg0) {
    /* The 24-byte state stores controller pointers at offsets 0 and 4. */
    struct BattleSelectionInputState {
        u8 *primary;
        u8 *secondary;
        u8 unk08, unk09, unk0A, unk0B, unk0C, mode, activity;
        u8 unk0F, unk10, unk11, unk12, unk13, unk14, unk15, unk16, unk17;
    };
    u8 *records[2];
    u8 counts[2];
    u8 offsets[2];
    u8 index;

    index = func_84148470(arg0);
    records[index] = ((struct BattleSelectionInputState *)((u8 *)D_84195248))[arg0].primary;
    records[(1 - index)] = ((struct BattleSelectionInputState *)((u8 *)D_84195248))[arg0].secondary;
    offsets[index] = 0;
    offsets[(1 - index)] = ((u8 *)D_841951F8[arg0])[3];
    counts[index] = ((u8 *)D_841951F8[arg0])[3];
    counts[(1 - index)] = ((u8 *)D_841951F8[arg0])[8] - ((u8 *)D_841951F8[arg0])[3];
    if ((*(u16 *)(records[0] + 6) & 0x200) != 0 && counts[0] > 0) {
        func_8413AD98(arg0, index, offsets[0]);
    } else if ((*(u16 *)(records[0] + 6) & 0x100) != 0 && counts[0] >= 3) {
        func_8413AD98(arg0, index, offsets[0] + 2);
    } else if ((*(u16 *)(records[0] + 6) & 0x800) != 0 && counts[0] >= 2) {
        func_8413AD98(arg0, index, offsets[0] + 1);
    } else if ((*(u16 *)(records[1] + 6) & 0x200) != 0 && counts[1] > 0) {
        func_8413AD98(arg0, (1 - index), offsets[1]);
    } else if ((*(u16 *)(records[1] + 6) & 0x100) != 0 && counts[1] >= 3) {
        func_8413AD98(arg0, (1 - index), offsets[1] + 2);
    } else if ((*(u16 *)(records[1] + 6) & 0x800) != 0 && counts[1] >= 2) {
        func_8413AD98(arg0, (1 - index), offsets[1] + 1);
    } else if (((*(u16 *)(records[0] + 6)) | (*(u16 *)(records[1] + 6))) & 0x10) {
        func_8413A8C4(arg0);
    } else {
        func_8413B254(arg0);
    }
    if (((*(u16 *)(records[0] + 8)) | (*(u16 *)(records[1] + 8))) & 0x20) {
        if (((struct BattleSelectionInputState *)((u8 *)D_84195248))[arg0].activity < 2) {
            func_800226C0(3);
            func_84139958(arg0, 1);
        }
    } else if ((*(u16 *)(records[0] + 8) & 0x2) != 0 && counts[0] > 0) {
        BattleSelection_HandlePartyChoice(arg0, offsets[0]);
    } else if ((*(u16 *)(records[0] + 8) & 0x8) != 0 && counts[0] >= 2) {
        BattleSelection_HandlePartyChoice(arg0, offsets[0] + 1);
    } else if ((*(u16 *)(records[0] + 8) & 0x1) != 0 && counts[0] >= 3) {
        BattleSelection_HandlePartyChoice(arg0, offsets[0] + 2);
    } else if ((*(u16 *)(records[1] + 8) & 0x2) != 0 && counts[1] > 0) {
        BattleSelection_HandlePartyChoice(arg0, offsets[1]);
    } else if ((*(u16 *)(records[1] + 8) & 0x8) != 0 && counts[1] >= 2) {
        BattleSelection_HandlePartyChoice(arg0, offsets[1] + 1);
    } else if ((*(u16 *)(records[1] + 8) & 0x1) != 0 && counts[1] >= 3) {
        BattleSelection_HandlePartyChoice(arg0, offsets[1] + 2);
    }
}
#endif

#ifdef VERSION_US
extern void BattleSelection_HandleSmallRosterInput(u8);
extern void BattleSelection_HandleLargeRosterInput(u8);
extern void BattleSelection_ProcessControllerPartitions(u8);
extern void * D_841951F8[];
void func_8413BBEC(s32 arg0) {
    s32 *home = &arg0;
    u8 index = (u8)(*home & 0xFF);
    u8 *ptr = (u8 *)D_841951F8[index];
    if (ptr[2] == 1) {
        if (ptr[8] >= 4) BattleSelection_HandleLargeRosterInput(index);
        else BattleSelection_HandleSmallRosterInput(index);
    } else {
        BattleSelection_ProcessControllerPartitions(index);
    }
}
#endif

#ifdef VERSION_US
void Battle_HandleConfirmChoiceInput(u8 arg0) {
    u8 *controller;
    u8 current;
    controller = ((u8 **)(((u8 (*)[24])((u8 *)D_84195248))[arg0]))[((u8 (*)[24])((u8 *)D_84195248))[arg0][9]];
    current = func_84148494(14, arg0, 0);
    if (*(u16 *)(controller + 8) & 0x8000) {
        if (current != 0) {
            func_800226C0(9);
            ((u8 *)D_841951F0)[2502] = arg0 + 3;
            if (((u8 *)D_841951F0)[2498] == 1 && D_8419527C < 104) {
                (*(u8 **)((u8 *)D_841951F0 + 2520))[107] = D_8419527C;
            }
            func_8413584C(20);
        } else {
            func_84139D94(arg0);
        }
    } else if (*(u16 *)(controller + 8) & 0x300) {
        func_800226C0(1);
        current = (current + 1) & 0x1;
        func_84147228(14, arg0, 0, 7, current);
    }
}
#endif

#ifdef VERSION_US
extern struct unk_D_84195248 D_84195248[2];
extern void *D_841951F8[];
extern void func_84139364(u8);
void func_8413BD94(u8 arg0) {
    u8 **entry = (u8 **)((u8 *)((u8 *)D_84195248) + arg0 * 24);
    if (((*(u16 *)(entry[0] + 8) & 0x20) != 0) || (((u8 *)D_841951F8[arg0])[2] == 2 && ((*(u16 *)(entry[1] + 8) & 0x20) != 0))) {
        func_84139364(arg0);
    }
}
#endif

#ifdef VERSION_US
extern void func_84138D74(u8 arg0);
extern struct unk_D_84195248 D_84195248[2];
void func_8413BE1C(u8 arg0) {
    u8 **entry = (u8 **)(((u8 *)D_84195248) + arg0 * 24);
    if (*(u16 *)(entry[0] + 8) != 0 || (entry[1] != NULL && *(u16 *)(entry[1] + 8) != 0)) {
        func_84138D74(arg0);
    }
}
#endif

#ifdef VERSION_US
extern u8 D_84195255[];
extern u8 D_84195210[];
extern void func_84139EB0(s32);
extern void func_8413A53C(u8);
extern void Battle_HandleConfirmChoiceInput(u8);
extern void func_8413BE1C(u8);
extern u8 func_84148510(u8);
extern void func_8413BBEC(s32 arg0);
extern void func_8413BD94(u8 arg0);
void func_8413BE84(s32 arg0) {
    switch (D_84195255[arg0 * 24] - 1) {
    case 0:
        func_84139EB0(arg0);
        break;
    case 1:
    case 2:
    case 3:
        func_8413A53C((u8)arg0);
        break;
    case 4:
    case 5:
    case 6:
        func_8413BBEC((u8)arg0);
        break;
    case 7:
        Battle_HandleConfirmChoiceInput((u8)arg0);
        break;
    case 8:
        func_8413BE1C((u8)arg0);
        break;
    case 10:
        func_8413BD94((u8)arg0);
        break;
    case 9:
        D_84195210[arg0] = func_84148510((u8)arg0);
        break;
    }
}
#endif

#ifdef VERSION_US
extern void func_841397FC(u8,u8);
extern void func_84139528(u8,u8);
extern void BattleSelection_HandlePartyChoice(u8,u8);
extern struct unk_D_84195248 D_84195248[2];
void func_8413BF58(s32 arg0){u8 *ptr=((u8 *)D_84195248)+arg0*24;switch(ptr[0xD]){case 1:if(ptr[0xF]==0)ptr[0xF]=(ptr[0x12]&0xF)*3+3;else if(--ptr[0xF]==0)func_841397FC(arg0,(ptr[0x12]&0xF0)>>4);break;case 2:if(ptr[0xF]==0)ptr[0xF]=(ptr[0x13]&0xF)*3+3;else if(--ptr[0xF]==0)func_84139528(arg0,(ptr[0x13]&0xF0)>>4);break;case 5:if(ptr[0xF]==0)ptr[0xF]=(ptr[0x13]&0xF)*4+4;else if(--ptr[0xF]==0)BattleSelection_HandlePartyChoice(arg0,(ptr[0x13]&0xF0)>>4);break;}}
#endif

#ifdef VERSION_US
extern s32 func_84138960(u8);
extern void func_841392E0(u8);
extern void func_84139244(u8);
extern void func_84139958(u8, u8);
extern void func_84139770(u8);
extern void func_84139D94(u8);
extern void func_84138D74(u8);
void func_8413C0A4(u8 arg0) {
    switch (((u8 *)D_84195248)[arg0 * 24 + 0xD] - 1) {
    case 0:
        func_841397FC(arg0, 2);
        break;
    case 1:
    case 2:
    case 3:
        if (func_84138960(arg0)) func_841392E0(arg0);
        else func_84139244(arg0);
        break;
    case 4:
    case 5:
    case 6:
        if (((u8 *)D_84195248)[arg0 * 24 + 0xE] < 5) func_84139958(arg0, 1);
        else func_84139770(arg0);
        break;
    case 7:
        func_84139D94(arg0);
        break;
    case 8:
        func_84138D74(arg0);
        break;
    }
}
#endif

#ifdef VERSION_US
extern s32 func_8413860C(u8);
extern struct unk_D_84195248 D_84195248[2];
void func_8413C18C(u8 arg0) { u8 *ptr = ((u8 *)D_84195248) + arg0 * 24; switch (ptr[0xD]) { case 1: if (ptr[0xF] == 0) ptr[0xF] = (func_8003570C() & 0xF) * 3 + 3; else if (--ptr[0xF] == 0) { if (func_8413860C(arg0) < 4) func_841397FC(arg0, 2); else if (func_8413860C(arg0) < 10) func_841397FC(arg0, 5); } break; case 2: case 5: if (ptr[0xF] == 0) ptr[0xF] = (func_8003570C() & 0xF) * 3 + 3; else if (--ptr[0xF] == 0) func_84138EA4(arg0, (u8)func_8413860C(arg0)); break; } }
#endif

#ifdef VERSION_US
extern void func_8413584C(u8 arg0);
extern void func_84138EA4(u8, u8);
extern s32 D_84186154;
extern u8 * D_84195200[];
extern u8 * D_84195208[];
extern u8 D_84195255[];
extern u8 D_8419A0A1;
void func_8413C2C0(u8 arg0) {
    s32 index = D_8419A0A1 & 0xFF;

    if (D_84186154 != 0) {
        if (D_8419A0A1 < 2) {
            if (D_84195255[arg0 * 24] < 11) {
                if (*(u16 *)(D_84195200[arg0] + 0x26) > 0) {
                    if (D_84195208[arg0][0x11] & 8) {
                        index = (u8)(index + 1);
                    }
                    if (D_84195208[arg0][index + 5] == 0) {
                        index = 0;
                    }
                    func_84138EA4(arg0, index);
                } else {
                    func_84138EA4(arg0, index + 4);
                }
            }
        } else {
            func_8413584C(20);
        }
    }
}
#endif

#ifdef VERSION_US
extern s32 D_84186154;
extern u8 D_8419A0A0[];
extern void func_8413C2C0(u8);
extern void func_8413BE84(s32 arg0);
extern void func_8413BF58(s32 arg0);
extern void func_8413C0A4(u8 arg0);
extern void func_8413C18C(u8 arg0);
extern void * D_841951F0;
extern void * D_841951F8[];
extern u8 D_84195210[];
extern struct unk_D_84195248 D_84195248[2];
extern u8 D_84195278;
void func_8413C3A8(void) {
    s32 mode;
    s32 i;
    s32 active;
    mode = ((u8 *)D_841951F0)[0x9C2] == 2;
    if (D_84195278 == 1) {
        for (i = 0; i < 2; i++) {
            if (((u8 *)D_84195248)[i * 24 + 0xC] != 0) {
                active = D_84195210[i] != 0;
                if (active) active = ((u8 **)D_841951F8)[i][0x49A] != 0;
                if (mode) func_8413C18C((u8)i);
                else if (D_8419A0A0[0] != 0) func_8413C2C0((u8)i);
                else if (D_84186154 != 0) func_8413C0A4((u8)i);
                else if (active) func_8413BF58(i);
                else func_8413BE84(i);
            }
        }
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_3A4030/func_8413C500.s")
#endif

#ifdef VERSION_US
extern void func_84148410(void);
void func_8413C6AC(u8 arg0, u16 arg1) {
    func_84148410();
    switch (arg0) {
        case 0:
            func_84134CBC(0, arg1);
            break;
        case 1:
            func_84134CBC(1, arg1);
            break;
        case 2:
            func_84134CBC(0, arg1);
            break;
    }
    BattleRecord_AdvanceWriteSlot();
    func_84147228(1, 0, 0, 4, 1);
    func_84147228(1, 1, 0, 4, 1);
    D_84195278 = 6;
    if ((((u8 *)D_841951F0)[0x9C2] == 1) && (D_8419527C < 104)) {
        (*(u8 **)((u8 *)D_841951F0 + 0x9D8))[0x6B] = D_8419527C;
    }
    func_84147228(24, 0, 0, 10, 0);
}
#endif

#ifdef VERSION_US
extern void GfxImage_FillCurrent(s32 *, s32);
extern u8 D_800D0510;
void func_8413C7C0(void) {
    GfxImage_FillCurrent(&D_800D0510, 1);
    if ((*(u8 *)((u8 *)(D_84195280) + (0x4B02))) != 0) {
        (*(u16 *)((u8 *)(D_84195280) + (0x4B06))) = 0x2DU;
        (*(u8 *)((u8 *)(D_84195280) + (0x4B02))) = 0U;
        (*(s8 *)((u8 *)(D_84195280) + (0x4B01))) = 5;
    }
    if ((s32) (*(u16 *)((u8 *)(D_84195280) + (0x4B06))) > 0) {
        (*(u16 *)((u8 *)(D_84195280) + (0x4B06))) = (u16) ((*(u16 *)((u8 *)(D_84195280) + (0x4B06))) - 1);
    }
}
#endif

#ifdef VERSION_US
extern s32 D_84186150, D_84186154, D_84186158;
extern struct unk_D_8419A008 D_8419A008[];
extern void func_8413C500(void);
extern void func_84148650(u8);
extern void func_8410A6A4(void);
extern s32 func_80001FF0(void);
extern struct unk_D_84195248 D_84195248[2];
void Battle_UpdatePhase(void) {
    s32 i;

    switch (D_84195278) {
    case 1:
        if (D_84195248[0].phase >= 11 && D_84195248[1].phase >= 11) {
            if (D_84195248[0].active == 0 || D_84195248[1].active == 0) break;
            func_84135338(0);
            func_84135338(1);
            if (D_8419A008[0].flags & 1) {
                func_84147228(21, 0, 0, 11, 0);
                func_84147228(21, 0, 0, 4, 4);
            }
            if (((u8 *)D_841951F0)[2498] == 1) {
                if (D_84195248[0].kind != 12) func_841385A8(0, ((u8 *)D_841951F8[0])[0]);
                if (D_84195248[1].kind != 12) func_841385A8(1, ((u8 *)D_841951F8[1])[0]);
            }
            if (D_8419527C + 1 >= 256) D_8419527C = 254;
            D_8419527C++;
            if (((u8 *)D_841951F0)[2498] == 2 && D_8419527C >= (*(u8 **)((u8 *)D_841951F0 + 2520))[107]) {
                D_84186158 = 1;
            }
            if (D_84195248[0].kind == 5 || D_84195248[1].kind == 5) {
                func_84147228(23, 0, 0, 7, 2);
            } else {
                func_84147228(23, 0, 0, 7, 0);
            }
            func_84147228(23, 0, 0, 10, 0);
            func_84147228(23, 0, 0, 4, 4);
            func_80023A3C(38, 0, 0);
            D_84195278 = 3;
        } else {
            if ((D_8419A008[0].flags & 3) && (D_8419A008[0].flags & 4)) {
                D_8419A008[0].flags = D_8419A008[0].flags & ~4;
                D_8419A008[0].elapsed = 0;
            }
            func_8413C3A8();
        }
        break;
    case 4:
        if (D_84195248[0].active == 0 || D_84195248[1].active == 0) break;
        func_84137ED4(0);
        func_84137ED4(1);
        D_8419A007 = 1;
        if (func_841484CC(23, 0, 0, 1) == 0) {
            if (D_84195248[0].kind == 5 || D_84195248[1].kind == 5) {
                func_84147228(23, 0, 0, 7, 1);
                func_84147228(23, 0, 0, 11, 4);
            } else {
                func_84147228(23, 0, 0, 7, 0);
                func_84147228(23, 0, 0, 11, 2);
            }
            func_84147228(23, 0, 0, 4, 4);
        }
        if (D_84186158 != 0) {
            func_8002AAFC(0);
            func_8413C500();
            func_80023A3C(52, 0, 0);
            func_8413C6AC(((u8 *)D_841951F0)[2502], 104);
        } else {
            if (D_84195248[0].phase == 12 && D_84195248[1].phase == 12) {
                func_84147228(29, 0, 0, 10, 120);
                func_84147228(29, 0, 0, 4, 4);
            }
            D_84195278 = 5;
        }
        break;
    case 3:
        if (D_84195248[0].active == 0 || D_84195248[1].active == 0) break;
        D_8419A0A1++;
        func_8002AAFC(0);
        *(u16 *)(D_84195280 + 19206) = 0;
        D_84195280[19202] = 0;
        if (D_8419A006 < 2) D_8419A006 = 2;
        Display_QueueFramebufferRequest_fragment79((OSMesg)0x4B495054);
        break;
    case 5:
        if (D_84195248[0].phase < 11 && ((u8 *)D_841951F8[0])[1178] != 0 && D_84195210[0] != 0) func_84148650(0);
        if (D_84195248[1].phase < 11 && ((u8 *)D_841951F8[1])[1178] != 0 && D_84195210[1] != 0) func_84148650(1);
        if (D_8419A008[0].flags & 2) {
            D_84186154 = 0;
            D_8419A008[0].fraction = D_8419A008[0].elapsed % func_80001FF0();
            for (i = 0; i != 2; i++) {
                if (D_84195248[i].phase < 11) {
                    func_84147228(22, (u8)i, 0, 10, 0);
                    func_84147228(22, (u8)i, 0, 4, 4);
                }
            }
        }
        if (D_8419A008[0].flags & 1) {
            func_84147228(21, 0, 0, 10, 0);
            func_84147228(21, 0, 0, 4, 4);
        }
        func_80023A3C(39, 0, 0);
        D_84195278 = 1;
        break;
    case 7:
        if (D_84195248[0].active != 0 && D_84195248[1].active != 0) D_84186150 = 0;
        break;
    case 8:
        func_8410A6A4();
        break;
    }
}
#endif

#ifdef VERSION_US
extern s32 func_80001FF0(void);
extern u8 func_80002014(void);
extern s32 D_84186158;
extern u32 D_8419A00C;
extern u32 D_8419A010;
extern s16 D_8419A016;
extern u8 D_8419A01A;

s32 func_8413CE84(void) {
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;

    if ((D_8419A01A & 3) && !(D_8419A01A & 4)) {
        *(s32 *)(((u8 *)&D_8419A008) + 8) = func_80002014() + *(s32 *)(((u8 *)&D_8419A008) + 8);
        *(s16 *)(((u8 *)&D_8419A008) + 0xC) = func_80002014() + *(s16 *)(((u8 *)&D_8419A008) + 0xC);
        sp2C = *(s32 *)(((u8 *)&D_8419A008) + 0) - *(s32 *)(((u8 *)&D_8419A008) + 8);
        sp28 = *(s32 *)(((u8 *)&D_8419A008) + 4) - *(s16 *)(((u8 *)&D_8419A008) + 0xC);
        if (sp2C < 0) {
            sp2C = 0;
            D_84186158 = 1;
        }
        if ((func_80001FF0() * 0xA) < sp28) {
            func_84147228(0x16, 0U, 0, 3, 0);
            func_84147228(0x16, 1U, 0, 3, 0);
        } else if ((func_80001FF0() * 3) < sp28) {
            func_84147228(0x16, 0U, 0, 3, 1);
            func_84147228(0x16, 1U, 0, 3, 1);
        } else {
            func_84147228(0x16, 0U, 0, 3, 2);
            func_84147228(0x16, 1U, 0, 3, 2);
        }
        if (sp28 < 0) {
            sp28 = 0;
            D_84186154 = 1;
        }
        if ((u32) D_8419A00C < (u32) sp28) {
            sp28 = D_8419A00C;
        }
        sp24 = ((s32) (sp2C * 0x64) / func_80001FF0()) + 0x63;
        sp20 = ((s32) (sp28 * 0x64) / func_80001FF0()) + 0x63;
        if (*D_8419A0A0 == 0) {
            if ((func_841484CC(0x15, 0, 0, 1) == 0) && ((sp24 / 100) != (func_84148494(0x15, 0, 0) / 100U))) {
                func_80023A3C(0x32, 0, 0);
            }
            if (((func_841484CC(0x16, 0, 0, 1) == 0) || (func_841484CC(0x16, 1, 0, 1) == 0)) && (func_84148494(0x16, 0, 0) != 0)) {
                if ((sp20 / 100) != (func_84148494(0x16, 0, 0) / 100U)) {
                    func_80023A3C(0x33, sp20 / 100, 0);
                }
            }
        }
        D_8419A016 = (s16) ((u32) D_8419A010 / func_80001FF0());
        func_84147228(0x15, 0U, 0, 7, sp24);
        func_84147228(0x16, 0U, 0, 7, sp20);
        func_84147228(0x16, 1U, 0, 7, sp20);
    }
}
#endif

#ifdef VERSION_US
extern u8 D_84199DE8[];
u8 *func_8413D254(void) {
    return D_84199DE8;
}
#endif

#ifdef VERSION_US
extern u8 D_84199F74[];
u8 *func_8413D260(void) {
    return &D_84199F74[2];
}
#endif

#ifdef VERSION_US
extern u8 D_84195252[];
u8 func_8413D26C(u8 arg0, u8 arg1) {
    return D_84195252[arg0 * 24 + arg1];
}
#endif

#ifdef VERSION_US
extern u8 D_84195218[];
u8 *func_8413D29C(u8 arg0) {
    return D_84195218 + arg0 * 24;
}
#endif

#ifdef VERSION_US
extern u8 D_84195254[];
void func_8413D2C0(u8 arg0, s32 arg1) {
    D_84195254[arg0 * 24] = arg1;
}
#endif

#ifdef VERSION_US
extern void func_8413C6AC(u8, u16);
extern void * D_841951F0;
extern u8 * D_84195200[];
void func_8413D2E4(u8 arg0) {
    (*(u8 *)((u8 *) D_841951F0 + 0x9C6)) = arg0;
    if ((*(u16 *)((u8 *) D_84195200[0] + 0x26)) != 0 ||
        (*(u16 *)((u8 *) D_84195200[1] + 0x26)) != 0) {
        func_8413C6AC(arg0, 0x67);
    } else {
        func_8413C6AC(arg0, 0x69);
    }
    func_84134968();
}
#endif

#ifdef VERSION_US
extern u8 D_8419521C[];
f32 func_8413D358(u8 arg0) {
    return *(f32 *)(D_8419521C + arg0 * 24);
}
#endif

#ifdef VERSION_US
#ifndef M2C_FIELD /* sweep: m2c --valid-syntax helpers (mirrors mkdraft.py) */
#define M2C_UNK s32
#define M2C_UNK8 s8
#define M2C_UNK16 s16
#define M2C_UNK32 s32
#define M2C_UNK64 s64
#define M2C_FIELD(expr, type, offset) (*(type)((u8*)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) 0
#define M2C_TRAP_IF(cond) ((void)0)
#define M2C_BREAK() ((void)0)
#define M2C_SYNC() ((void)0)
#define M2C_CARRY 0
#define M2C_STRUCT_COPY(dst, src) ((dst) = (src))
#endif

M2C_UNK func_80008648();                            /* extern */
M2C_UNK func_800088DC();                            /* extern */
M2C_UNK func_8002B1CC();                            /* extern */
M2C_UNK func_80064D28();                            /* extern */
M2C_UNK func_8410A608();                            /* extern */
M2C_UNK func_8410A884();                            /* extern */
M2C_UNK func_8410A9B4();                            /* extern */
M2C_UNK func_84136D9C();                            /* extern */
void BattleSnapshot_UpdateDisplay(void);
void Battle_UpdatePhase(void);                            /* extern */
M2C_UNK func_8413CE84();                            /* extern */
M2C_UNK func_84145BA0(u8);                          /* extern */
M2C_UNK func_8414605C();                            /* extern */
M2C_UNK func_841482BC();                            /* extern */
extern u8 *D_80087200;
extern s32 D_84186150;
extern s32 D_84186174;
extern u8 D_8419A0A2;
extern u8 D_8419A0A3;

void func_8413D37C(void) {
    s32 var_s7;

    var_s7 = 0;
    if (M2C_FIELD(D_841951F0, u8 *, 0x9C2) == 2) {
        func_84147228(0x19, 0U, 0, 5, 3);
    }
    if (*D_8419A0A0 != 0) {
        func_84147228(0x1A, 0U, 0, 5, 3);
    } else {
        func_84134CBC(0U, 0x65U);
        func_84136CA8();
    }
    func_84147228(0x18, 0U, 0, 7, 1);
    func_84134920();
    if (*D_8419A0A0 != 0) {
        D_84195278 = 1;
    } else {
        M2C_FIELD((D_84195280 + (M2C_FIELD(D_84195280, u8 *, 0x4D81) * 0x280)), s8 *, -0x27E) = 0;
    }
    func_84147228(1, 0U, 0, 0xF, 0);
    func_84147228(1, 1U, 0, 0xF, 0);
    do {
        func_80064D28();
        func_8413CE84();
        if ((s32) D_8419A0A3 > 0) {
            D_8419A0A3 -= 1;
        }
        func_841482BC();
        Battle_UpdatePhase();
        if (var_s7 == 0) {
            var_s7 = 1;
            func_8002B1CC();
        }
        if ((D_84195278 != 8) && (D_84186170 != 0)) {
            func_8410A608();
        }
        if (D_84195278 != 8) {
            func_841359D0();
        }
        BattleSnapshot_UpdateDisplay();
        func_84136D9C();
        func_84137CA4();
        func_800088DC();
        if (D_84186170 != 0) {
            func_8410A884();
        } else {
            func_8413C7C0();
        }
        switch (D_84195278) {
        case 8:
            func_8410A9B4();
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 7:
            if (D_84186174 != 0) {
                func_84145BA0(*D_8419A0A0);
            }
            break;
        case 6:
            func_8414605C();
            break;
        }
        func_80008648();
        if ((*D_8419A0A0 != 0) && (D_8419A0A3 == 0) && (D_84195278 != 7) && (M2C_FIELD(D_80087200, u16 *, 8) & 0xD000)) {
            func_8413584C(0x14U);
        }
        if ((M2C_FIELD(D_841951F0, u8 *, 0x9C2) == 2) && (D_8419A0A3 == 0) && (D_84195278 != 7) && (M2C_FIELD(D_80087200, u16 *, 8) & 0x1000)) {
            func_8413584C(0x14U);
            D_8419A0A2 = 1;
        }
    } while (D_84186150 != 0);
    func_84134944();
}
#endif

#ifdef VERSION_US
extern void _bcopy(void *, void *, s32);
extern s32 func_80064728(void *);
extern u8 func_8006397C(u8);
extern u8 func_800639C0(u8);
extern ColorAdjustment func_8003F5AC(u8 *);
extern void _bzero(void *, s32);
void func_8413D6D4(u8 *arg0, u8 *arg1) { u8 i; _bzero(arg0, 0x54); arg0[0] = arg1[0]; *(u16 *)(arg0 + 0x2C) = func_80064728(arg1); arg0[1] = func_8006397C(arg0[0]); arg0[2] = func_800639C0(arg0[0]); _bcopy(arg1 + 2, arg0 + 5, 4); _bcopy(arg1 + 0x18, arg0 + 9, 4); *(u16 *)(arg0 + 0x2E) = *(u16 *)(arg1 + 0x16); _bcopy(arg1 + 0x2A, arg0 + 0x32, 0xA); _bcopy(arg1 + 0x2A, arg0 + 0x3C, 0xA); for (i = 0; i < 7; ++i) *(arg0 + i + 0x1E) = 7; *(ColorAdjustment *)(arg0 + 0x50) = func_8003F5AC(arg1); }
#endif

#ifdef VERSION_US
extern u8 func_80062E10(u8);
extern s32 func_80061B88(s32, u16);
extern s32 func_800647C8(u8);
extern s8 *HAL_Strcpy(s8 *, s8 *);
extern void func_800619E8(u8 *);
extern u8 D_8418AF68[];
void BattleParty_InitializeFallbackTeam(u8 arg0) {
    struct Label7 { u8 bytes[7]; };
    u8 *data;
    s32 i;
    s32 j;

    D_841951F8[arg0] = ((u8 (*)[1248])D_841951F0)[arg0];
    ((u8 *)D_841951F8[arg0])[2] = 1;
    ((u8 *)D_841951F8[arg0])[7] = 6;
    ((u8 *)D_841951F8[arg0])[8] = 3;
    ((u8 *)D_841951F8[arg0])[9] = 3;
    ((u8 *)D_841951F8[arg0])[3] = 3;
    for (i = 0; i < 6; i++) {
        D_84195200[arg0] = (u8 *)D_841951F8[arg0] + i * 88 + 24;
        D_84195200[arg0][0] = arg0 * 3 + i + 6;
        for (j = 0; j < 4; j++) {
            D_84195200[arg0][j + 2] = 251 - arg0 * 24 - i * 4 - j;
            D_84195200[arg0][j + 24] = func_80062E10(D_84195200[arg0][j + 2]);
        }
        D_84195200[arg0][29] = 100;
        *(s32 *)(D_84195200[arg0] + 8) = func_80061B88(D_84195200[arg0][0], D_84195200[arg0][29]);
        *(u16 *)(D_84195200[arg0] + 12) = 0xFFFF;
        *(u16 *)(D_84195200[arg0] + 14) = 0xFFFF;
        *(u16 *)(D_84195200[arg0] + 16) = 0xFFFF;
        *(u16 *)(D_84195200[arg0] + 18) = 0xFFFF;
        *(u16 *)(D_84195200[arg0] + 20) = 0xFFFF;
        *(u16 *)(D_84195200[arg0] + 22) = func_8003570C() & 0xFFFF;
        D_84195200[arg0][28] = 255;
        data = (u8 *)func_800647C8(D_84195200[arg0][0]);
        HAL_Strcpy((s8 *)(D_84195200[arg0] + 52), (s8 *)data);
        *(struct Label7 *)(D_84195200[arg0] + 64) = *(struct Label7 *)D_8418AF68;
        func_800619E8(D_84195200[arg0]);
        *(u16 *)(D_84195200[arg0] + 38) = *(u16 *)(D_84195200[arg0] + 40);
    }
    data = (u8 *)D_841951F8[arg0];
    D_84195200[arg0] = data + 24;
    D_84195208[arg0] = data + 1080;
}
#endif

#ifdef VERSION_US
extern void func_8005A014(s32);
extern u8 *func_8006218C(s32, s32, s32, s32);
extern s32 Deck_ReadEntries(u8 *, s32, u8 *);
extern s32 func_80062304(u8 *);
extern void BattleParty_InitializeFallbackTeam(u8);
extern void *D_841951F0;
extern void *D_841951F8[];
extern u8 *D_84195200[];
extern u8 *D_84195208[];
void Battle_LoadPlayerDeck(u8 arg0) {
    struct Team { u8 bytes[1248]; };
    u8 *handle;
    s32 value;

    value = arg0;
    D_841951F8[arg0] = ((struct Team *)D_841951F0)[arg0].bytes;
    D_84195200[arg0] = (u8 *)D_841951F8[arg0] + 24;
    D_84195208[arg0] = (u8 *)D_841951F8[arg0] + 1080;
    func_8005A014(value);
    handle = func_8006218C(32, value, 0, 0);
    ((u8 *)D_841951F8[arg0])[2] = 1;
    value = Deck_ReadEntries((u8 *)D_841951F8[arg0] + 24, 6, handle);
    ((u8 *)D_841951F8[arg0])[7] = value;
    if (((u8 *)D_841951F8[arg0])[7] == 0) {
        BattleParty_InitializeFallbackTeam(arg0);
    } else {
        ((u8 *)D_841951F8[arg0])[8] = ((u8 *)D_841951F8[arg0])[7];
        ((u8 *)D_841951F8[arg0])[9] = ((u8 *)D_841951F8[arg0])[8];
        ((u8 *)D_841951F8[arg0])[3] = ((u8 *)D_841951F8[arg0])[8];
    }
    func_80062304(handle);
}
#endif

#ifdef VERSION_US
extern u8 D_800CE060[];
void Battle_InitializeSideDisplayStates(void) {
    s32 i;
    u8 side;
    u8 *state;
    u8 *team;
    u8 (*inputs)[40];
    for (inputs = (u8 (*)[40])D_800CE060, i = 0; i < 2; i++) {
        state = ((u8 *)D_84195248) + i * 24;
        team = (u8 *)D_841951F8[i];
        *(void **)(state + 0) = inputs[state[10]];
        *(void **)(state + 4) = inputs[state[11]];
        state[13] = 1;
        state[14] = 1;
        state[15] = 10;
        state[8] = 0;
        state[12] = 1;
        if (team[2] == 2 && team[10] >= team[3]) {
            state[9] = 1;
        } else {
            state[9] = 0;
        }
        side = i;
        func_84147228(1, side, 0, 8, state[9]);
        func_84147228(1, side, 0, 3, 0);
        func_84147228(0, side, 0, 8, state[9]);
        func_84147228(0, side, 0, 3, 0);
        func_84147228(2, side, 0, 8, state[9]);
        func_84147228(2, side, 0, 3, 0);
        func_84147228(10, side, 0, 8, state[9]);
        func_84147228(10, side, 0, 3, 0);
        func_84147228(14, side, 0, 8, state[9]);
        func_84147228(14, side, 0, 3, 0);
        func_84147228(15, side, 0, 8, state[9]);
        func_84147228(15, side, 0, 3, 0);
        func_84147228(28, side, 0, 8, state[9]);
        func_84147228(28, side, 0, 3, 0);
    }
}
#endif

#ifdef VERSION_US
#include "color_adjustment.h"
extern u8 D_84199D98[];
extern u8 D_84199DB8[];
void BattleSnapshot_InitializeBuffer(void) {
    s32 i;

    _bzero(D_84195280, 0x4D84);
    for (i = 0; i < 2; i++) {
        u8 **left = &D_84195208[i];
        u8 **right = &D_84195200[i];
        u8 *fields = D_84199D80 + i * 16;
        u8 *colors = D_84199D98 + i * 16;
        *(u16 *)(fields + 0xC) = *(u16 *)(*(u8 **)left + 0x2C);
        *(u16 *)(fields + 0xE) = 1;
        *(u16 *)(fields + 0x10) = 0;
        *(u16 *)(fields + 0x14) = *(u16 *)(*(u8 **)right + 0x16);
        *(ColorAdjustment *)(colors) = *((ColorAdjustment *)((u8 *)*(u32 *)left + 0x50));
    }
}
#endif

#ifdef VERSION_US
extern u8 D_84195279;
extern s32 D_84187020;
extern u8 D_8419A0A2;
extern u8 D_8419A0A0[];
extern u8 D_8419A0A1;
extern struct unk_D_84195248 D_84195248[2];
extern u8 D_84195210[];
extern s8 D_8419A005;
extern struct unk_D_8419A008 D_8419A008[];
extern u8 D_8418AF70[];
extern u8 D_8418AF78[];
extern void Teams_GenerateLevel100_fragment86(u8 *, u32);
extern s32 func_8005D8C0(void);
extern void Battle_LoadPlayerDeck(u8);
extern void BattleParty_InitializeFallbackTeam(u8);
extern void func_8413D6D4(u8 *, u8 *);
extern void func_84138530(u8, u8 *);
extern void Battle_InitializeSideDisplayStates(void);
extern void BattleSnapshot_InitializeBuffer(void);
extern void func_84138658(void);
extern void func_8002A830(void *);
extern void func_84148680(void);
extern s32 func_80001FF0(void);
extern void func_841348C0(void);
extern s32 main_pool_push_state(s32);
extern s32 main_pool_pop_state(s32);
extern void * D_841951F0;
extern void * D_841951F8[];
extern u8 * D_84195200[];
extern u8 * D_84195208[];
extern u8 D_84195278;
extern s32 D_8419527C;
extern u8 D_8419A006;
void Battle_InitState(s32 arg0, u8 *arg1) {
    u8 i;
    u8 j;
    struct BattleName { u8 bytes[8]; };
    struct PartyRow { u8 bytes[88]; };
    struct Team { u8 header[24]; struct PartyRow rows[12]; u8 tail[168]; };

    D_84195278 = 2;
    D_84195279 = 2;
    D_8419A006 = 2;
    D_8419527C = 0;
    D_84187020 = 0;
    D_8419A0A2 = 0;
    D_841951F0 = (void *)arg1;
    if (D_841951F0 != NULL) {
        D_8419A0A0[0] = ((u8 *)D_841951F0)[2499];
        D_8419A0A1 = 0;
        if (((u8 *)D_841951F0)[2] == 0) {
            if (D_8419A0A0[0] != 0) {
                Teams_GenerateLevel100_fragment86(D_841951F0, arg0);
                D_84187020 = 1;
            } else {
                main_pool_push_state(0x504D4C44);
                for (i = 0; i < 2; i++) {
                    if (func_8005D8C0() & (1 << i)) {
                        Battle_LoadPlayerDeck(i);
                    } else {
                        BattleParty_InitializeFallbackTeam(i);
                    }
                }
                main_pool_pop_state(0x504D4C44);
            }
            for (i = 0; i < 2; i++) {
                D_841951F8[i] = &((struct Team *)D_841951F0)[i];
                ((u8 *)D_841951F8[i])[10] = 0;
                D_84195200[i] = (u8 *)D_841951F8[i] + 24;
                D_84195208[i] = (u8 *)D_841951F8[i] + 1080;
                ((u8 *)D_841951F8[i])[1178] = 0;
            }
            *(struct BattleName *)((u8 *)D_841951F8[0] + 1164) = *(struct BattleName *)D_8418AF70;
            *(struct BattleName *)((u8 *)D_841951F8[1] + 1164) = *(struct BattleName *)D_8418AF78;
            ((u8 *)D_84195248)[10] = 0;
            ((u8 *)D_84195248)[34] = 1;
            ((u8 *)D_84195248)[11] = 2;
            ((u8 *)D_84195248)[35] = 3;
        } else {
            D_841951F8[0] = D_841951F0;
            D_841951F8[1] = &((struct Team *)D_841951F0)[1];
            D_84195200[0] = ((struct Team *)D_841951F8[0])->rows[((u8 *)D_841951F8[0])[10]].bytes;
            D_84195200[1] = ((struct Team *)D_841951F8[1])->rows[((u8 *)D_841951F8[1])[10]].bytes;
            D_84195208[0] = (u8 *)D_841951F8[0] + 1080;
            D_84195208[1] = (u8 *)D_841951F8[1] + 1080;
            ((u8 *)D_84195248)[10] = ((u8 *)D_841951F8[0])[4];
            ((u8 *)D_84195248)[11] = ((u8 *)D_841951F8[0])[5];
            ((u8 *)D_84195248)[34] = ((u8 *)D_841951F8[1])[4];
            ((u8 *)D_84195248)[35] = ((u8 *)D_841951F8[1])[5];
        }
        for (i = 0; i < 2; i++) {
            for (j = 0; j < ((u8 *)D_841951F8[i])[7]; j++) {
                ((struct Team *)D_841951F8[i])->rows[j].bytes[36] = 0;
            }
        }
        func_8413D6D4(D_84195208[0], D_84195200[0]);
        func_8413D6D4(D_84195208[1], D_84195200[1]);
        func_84138530(0, D_84195200[0]);
        func_84138530(1, D_84195200[1]);
        Battle_InitializeSideDisplayStates();
        BattleSnapshot_InitializeBuffer();
        func_84138658();
        func_8002A830(D_841951F0);
        D_84195210[0] = 1;
        D_84195210[1] = 1;
        D_8419A005 = 0;
        func_84148680();
        if (D_8419A0A0[0] != 0) {
            ((u8 *)D_841951F0)[2496] = 7;
            ((u8 *)D_841951F0)[2497] = 7;
        }
        if (((u8 *)D_841951F0)[2496] != 0) {
            ((u8 *)&D_8419A008)[18] |= 1;
        }
        if (((u8 *)D_841951F0)[2497] != 0) {
            ((u8 *)&D_8419A008)[18] |= 2;
        }
        ((u8 *)&D_8419A008)[18] |= 4;
        *(s32 *)(((u8 *)&D_8419A008) + 0) = ((u8 *)D_841951F0)[2496] * func_80001FF0() * 60;
        *(s32 *)(((u8 *)&D_8419A008) + 4) = ((u8 *)D_841951F0)[2497] * func_80001FF0();
        *(s32 *)(((u8 *)&D_8419A008) + 8) = 0;
        *(s16 *)(((u8 *)&D_8419A008) + 12) = 0;
        *(s16 *)(((u8 *)&D_8419A008) + 16) = ((u8 *)D_841951F0)[2496] * 60;
        if (((u8 *)D_841951F0)[2498] != 2) {
            **(u32 **)((u8 *)D_841951F0 + 2520) = osGetCount();
        }
        if (((u8 *)D_841951F0)[2498] == 1) {
            HAL_Memset(*(u8 **)((u8 *)D_841951F0 + 2520) + 4, 0xFF, 103);
        }
        func_841348C0();
    }
}
#endif

#ifdef VERSION_US
#ifndef M2C_FIELD /* sweep: m2c --valid-syntax helpers (mirrors mkdraft.py) */
#define M2C_UNK s32
#define M2C_UNK8 s8
#define M2C_UNK16 s16
#define M2C_UNK32 s32
#define M2C_UNK64 s64
#define M2C_FIELD(expr, type, offset) (*(type)((u8*)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) 0
#define M2C_TRAP_IF(cond) ((void)0)
#define M2C_BREAK() ((void)0)
#define M2C_SYNC() ((void)0)
#define M2C_CARRY 0
#define M2C_STRUCT_COPY(dst, src) ((dst) = (src))
#endif

M2C_UNK Asset_LoadToSegment(u32, M2C_UNK *, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK Gfx_FreeDisplayListBuffers();               /* extern */
M2C_UNK Gfx_InitDisplayListBuffers(M2C_UNK, M2C_UNK); /* extern */
M2C_UNK StageFade_StartFromOpaque(M2C_UNK);         /* extern */
s32 func_800082E0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_80008514(s32);                         /* extern */
M2C_UNK func_80008574();                            /* extern */
M2C_UNK func_80035424(M2C_UNK);                     /* extern */
M2C_UNK func_80047610();                            /* extern */
M2C_UNK func_8004C09C(M2C_UNK);                     /* extern */
M2C_UNK func_8004C398();                            /* extern */
M2C_UNK func_8410AA18(s32, s32, u8 *);              /* extern */
void func_8413D37C(void);
void Battle_InitState(s32, u8 *);                    /* extern */
M2C_UNK func_8414831C(u8);                          /* extern */
M2C_UNK main_pool_pop_state(M2C_UNK);               /* extern */
M2C_UNK main_pool_push_state(M2C_UNK);              /* extern */
extern M2C_UNK D_1000000;
extern M2C_UNK D_446E30;
extern M2C_UNK D_447D00;
extern u8 D_8419A0A2;
extern u8 D_8419A0A3;

u8 func_8413E2EC(s32 arg0, s32 arg1) {
    s32 sp24;

    main_pool_push_state(0x504D4254);
    Gfx_InitDisplayListBuffers(0x20000, 0);
    sp24 = func_800082E0(0, 1, 3, 1, 2, 1);
    Asset_LoadToSegment((u32) ((s32) &D_1000000 & 0x0F000000) >> 0x18, &D_446E30, &D_447D00, 0);
    func_8004C09C(0x43);
    Battle_InitState(arg0, arg1);
    func_8410AA18(sp24, arg0, D_84199D80);
    func_8414831C(*D_8419A0A0);
    func_84136564();
    func_80008514(sp24);
    StageFade_StartFromOpaque(0xA);
    D_8419A0A3 = 0xA;
    func_8413D37C();
    func_80008574();
    func_80035424(4);
    func_80047610();
    func_8004C398();
    Gfx_FreeDisplayListBuffers();
    main_pool_pop_state(0x504D4254);
    return D_8419A0A2;
}
#endif
