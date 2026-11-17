#include "global.h"

extern void *D_80087200;
extern u16 D_8AB1268E;
extern void func_8AB00B78(s32);

#ifdef VERSION_US
extern s32 TextLabel_DrawCallback(s32, u8 *);
extern void *func_8004C8A0(void *, s32, s32, s32);
extern u8 *D_8AB12668[];
extern u8 *D_8AB12678[];
extern void TextHighlight_AnimateScales(void);
extern s32 func_8004DCFC(s32, s32);
extern void func_8004E308(void *, s32 (*)(s32, u8 *), u8 *);
extern void func_8AB00B98(u8 *, u32);
extern int func_8AB023EC();
extern void func_8AC05E40(void *, u32, u8 *);
extern void *func_8AC06D8C(void *, u32, ...);

// Pointed to by D_8AB1129C in .data; it opens this file's .rodata.
const char D_8AB11A00[] = "\n";

extern s32 func_8004C8C0(s32);
extern void _bzero(void *, s32);
extern s32 func_8004DC6C(s32);
extern s32 main_pool_get_available(void);
extern s32 MainPool_AllocState(s32, s32);
extern void *func_8004EB58(s32, s32);
extern s32 func_80040E80(s32, void *);
extern void MainPool_FinalizeAllocation(s32);
extern void func_8AC06E98(void *);
extern void func_8AB01378(void *, u16 *, s16);
extern s32 func_8AB00548(void);
extern void func_8AC02C80(void *, s32, s32, void *);
extern void func_8AC06400(void *, void *);
extern void func_8AC00DF4(void *);
extern void func_8AB01C04(void);
extern s32 TextNumber_DrawCallback(void *);
extern void func_8AC033B8(void);

extern void *D_8AB16A40;
extern u16 *D_8AB16A48[4];
extern u8 *D_8AB16C98[];
extern u16 *D_8AB16C20[];
extern u16 *D_8AB16C30;
extern void *D_8AB16CB8;
extern void *D_8AB16A58;
extern void *D_8AB11D00;
extern void *D_8AB12688;
extern void *D_8AB16CA8;
extern u8 D_8AB16C38[];
extern u8 D_8AB16C68[];
extern u8 *D_8AB16B60;
extern u8 *D_8AB16B64;
extern u8 *D_8AB16B68;
extern u8 *D_8AB16B6C;
extern u8 *D_8AB16B70[4];
extern u8 *D_8AB16B74;
extern u8 *D_8AB16B78;
extern u8 *D_8AB16B7C;
extern void *D_8AB16B8C;
extern u8 *D_8AB16CB0;
extern void *D_8AB16B9C;
extern s32 D_8AB16BA0;
extern s16 D_8AB12690;
extern s32 D_8AB16CB4;
extern s32 D_8AB16CBC;
extern s32 D_8AB16CC4;
extern s16 D_8AB16CAC;
extern u8 D_8AB11284[];
extern u8 D_8AB16508[];
extern u8 D_8AB12CB0[];
extern u8 *D_8AB11D0C;
extern s16 D_8AB12CB2;
extern s16 D_8AB12D46;
extern s16 D_8AB12DDA;
extern s16 D_8AB12E6E;
extern s32 D_8AB12BA8;
extern u8 D_8AB126A8[];
extern u8 D_8AB16A60[];
extern u8 *D_8AB16B80;
extern u8 *D_8AB16B84;
extern u8 *D_8AB16B88;
extern u8 *D_8AB16B90;
extern u8 *D_8AB16B94;
extern u8 *D_8AB16B98;



void *func_8AB080A0(void) {
    s32 i;
    s32 bit;
    s32 handle;
    s32 pool;
    u8 *temp;
    u8 *p;
    s32 m1 = ~1;
    s32 m2 = ~2;

    func_8004C8C0(0x99);
    D_8AB16CBC = 0;
    D_8AB12690 = 0;
    for (i = 0; i < 4; i++) {
        bit = (*(u8 *)(D_8AB11D0C + 0xE) >> i) & 0xFF;
        _bzero(D_8AB12CB0 + i * 0x94, 0x94);
        p = D_8AB12CB0 + i * 0x94;
        if (bit & 1) {
            *(s16 *)p = 1;
            D_8AB12690 += 1;
        }
    }
    handle = func_8004DC6C(0xE1);
    func_8004DCFC(handle, 0);
    i = main_pool_get_available();
    pool = MainPool_AllocState(i, 0);
    D_8AB16A40 = func_8004EB58(pool, handle);
    D_8AB16CC4 = func_80040E80(pool, D_8AB11284);
    MainPool_FinalizeAllocation(pool);
    func_8AC06E98(D_8AB16A40);
    *(u16 *)((u8 *)D_8AB16A40 + 2) |= 1;
    *(u16 *)((u8 *)D_8AB16A40 + 2) |= 2;
    D_8AB16A48[0] = func_8AC06D8C(D_8AB16A40, 0x706C6931);
    D_8AB16A48[1] = func_8AC06D8C(D_8AB16A40, 0x706C6932);
    D_8AB16A48[2] = func_8AC06D8C(D_8AB16A40, 0x706C6933);
    D_8AB16A48[3] = func_8AC06D8C(D_8AB16A40, 0x706C6934);
    for (i = 0; i != 4; i++) {
        D_8AB16A48[i][1] &= m1;
        if (*(s16 *)(D_8AB12CB0 + i * 0x94) != 0) {
            D_8AB16A48[i][1] |= 1;
        }
        func_8AB01378(D_8AB16A40, D_8AB16A48[i], i);
    }
    D_8AB16C98[0] = func_8AC06D8C(D_8AB16A40, 0x77686F31);
    D_8AB16C98[1] = func_8AC06D8C(D_8AB16A40, 0x77686F32);
    D_8AB16C98[2] = func_8AC06D8C(D_8AB16A40, 0x77686F33);
    D_8AB16C98[3] = func_8AC06D8C(D_8AB16A40, 0x77686F34);
    *(u16 *)(D_8AB16C98[0] + 2) &= m2;
    *(u16 *)(D_8AB16C98[1] + 2) &= m2;
    *(u16 *)(D_8AB16C98[2] + 2) &= m2;
    *(u16 *)(D_8AB16C98[3] + 2) &= m2;
    D_8AB16C20[0] = func_8AC06D8C(D_8AB16A40, 0x72656131);
    D_8AB16C20[1] = func_8AC06D8C(D_8AB16A40, 0x72656132);
    D_8AB16C20[2] = func_8AC06D8C(D_8AB16A40, 0x72656133);
    D_8AB16C20[3] = func_8AC06D8C(D_8AB16A40, 0x72656134);
    D_8AB16C20[0][1] &= m2;
    D_8AB16C20[1][1] &= m2;
    D_8AB16C20[2][1] &= m2;
    D_8AB16C20[3][1] &= m2;
    D_8AB16C30 = func_8AC06D8C(D_8AB16A40, 0x71776669);
    *(u16 *)((u8 *)D_8AB16C30 + 2) &= m1;
    D_8AB16CB8 = func_8AC06D8C(D_8AB16A40, 0x65666374);
    func_8AB00548();
    func_8004E308(D_8AB16CB8, &func_8AC033B8, D_8AB16508);
    temp = func_8AC06D8C(D_8AB16A40, 0x6D6F6E64);
    D_8AB16A58 = temp;
    func_8004E308(D_8AB16A58, &TextLabel_DrawCallback, D_8AB16A60);
    temp = func_8AC06D8C(D_8AB16A40, 0x6D657373);
    D_8AB11D00 = temp;
    *(u16 *)((u8 *)D_8AB11D00 + 2) &= m1;
    func_8004E308(D_8AB11D00, &TextLabel_DrawCallback, D_8AB126A8);
    temp = func_8AC06D8C(D_8AB16A40, 0x72756C65);
    D_8AB12688 = temp;
    *(u16 *)((u8 *)D_8AB12688 + 2) &= m1;
    func_8004E308(D_8AB12688, &TextLabel_DrawCallback, &D_8AB12BA8);
    temp = func_8AC06D8C(D_8AB16A40, 0x74696D77);
    D_8AB16CA8 = temp;
    *(u16 *)((u8 *)D_8AB16CA8 + 2) &= m1;
    func_8AC02C80(D_8AB16A40, 0x71777531, 0x71777532, &D_8AB16C38);
    func_8AC02C80(D_8AB16A40, 0x71777331, 0x71777332, &D_8AB16C68);
    D_8AB16B60 = func_8AC06D8C(D_8AB16A40, 0x70696331);
    D_8AB16B64 = func_8AC06D8C(D_8AB16A40, 0x70696332);
    D_8AB16B68 = func_8AC06D8C(D_8AB16A40, 0x70696333);
    D_8AB16B6C = func_8AC06D8C(D_8AB16A40, 0x70696334);
    D_8AB16B80 = func_8AC06D8C(D_8AB16A40, 0x66696E31);
    D_8AB16B84 = func_8AC06D8C(D_8AB16A40, 0x66696E32);
    D_8AB16B88 = func_8AC06D8C(D_8AB16A40, 0x66696E33);
    func_8004E308(D_8AB16B80, &func_8AB01C04, NULL);
    func_8004E308(D_8AB16B84, &func_8AB01C04, NULL);
    func_8004E308(D_8AB16B88, &func_8AB01C04, NULL);
    D_8AB16B8C = func_8AC06D8C(D_8AB16A40, 0x71697431);
    D_8AB16B90 = func_8AC06D8C(D_8AB16A40, 0x71697432);
    D_8AB16B94 = func_8AC06D8C(D_8AB16A40, 0x71697433);
    D_8AB16B98 = func_8AC06D8C(D_8AB16A40, 0x71697434);
    D_8AB16B70[0] = func_8AC06D8C(D_8AB16A40, 0x6E6F6B31);
    D_8AB16B74 = func_8AC06D8C(D_8AB16A40, 0x6E6F6B32);
    D_8AB16B78 = func_8AC06D8C(D_8AB16A40, 0x6E6F6B33);
    D_8AB16B70[3] = func_8AC06D8C(D_8AB16A40, 0x6E6F6B34);
    func_8004E308(D_8AB16B70[0], &TextNumber_DrawCallback, &D_8AB12CB2);
    func_8004E308(D_8AB16B74, &TextNumber_DrawCallback, &D_8AB12D46);
    func_8004E308(D_8AB16B78, &TextNumber_DrawCallback, &D_8AB12DDA);
    func_8004E308(D_8AB16B7C, &TextNumber_DrawCallback, &D_8AB12E6E);
    D_8AB16CB0 = func_8AC06D8C(D_8AB16A40, 0x676F6F6F);
    D_8AB16B9C = func_8AC06D8C(D_8AB16A40, 0x61627531);
    func_8AC05E40(D_8AB16A40, 0x61627531, &D_8AB16BA0);
    func_8AC06400(&D_8AB16BA0, D_8AB16B9C);
    func_8AC00DF4(D_8AB16A40);
    *(u16 *)(D_8AB16B60 + 2) &= m2;
    *(u16 *)(D_8AB16B64 + 2) &= m2;
    *(u16 *)(D_8AB16B68 + 2) &= m2;
    *(u16 *)(D_8AB16B6C + 2) &= m2;
    *(u16 *)(D_8AB16B70[0] + 2) &= m2;
    *(u16 *)(D_8AB16B74 + 2) &= m2;
    *(u16 *)(D_8AB16B78 + 2) &= m2;
    *(u16 *)(D_8AB16B7C + 2) &= m2;
    *(u16 *)(D_8AB16B80 + 2) &= m1;
    *(u16 *)(D_8AB16B84 + 2) &= m1;
    *(u16 *)(D_8AB16B88 + 2) &= m1;
    *(u16 *)((u8 *)D_8AB16B8C + 2) &= m2;
    *(u16 *)(D_8AB16B90 + 2) &= m2;
    *(u16 *)(D_8AB16B94 + 2) &= m2;
    *(u16 *)(D_8AB16B98 + 2) &= m2;
    *(u16 *)((u8 *)D_8AB16A58 + 2) &= m1;
    *(u16 *)((u8 *)D_8AB16A58 + 2) &= m2;
    *(u16 *)((u8 *)D_8AB11D00 + 2) &= m1;
    D_8AB16CB4 = 0;
    *(s32 *)(D_8AB11D0C + 0x10) = 0;
    D_8AB16CAC = -1;
    return D_8AB16A40;
}



s32 func_8AB0896C(s32 arg0) {
    extern s32 func_8AB08C6C(s32);
    extern s32 func_8AB08D3C(s32);
    extern s32 func_8AB08CD0(s32);
    extern s32 func_8AB08DBC(s32);
    extern s32 func_8AB08F58(s32);
    extern s32 func_8AB090B8(s32);
    extern s32 func_8AB09A28(s32);
    extern s32 func_8AB09BD8(s32);
    extern s32 func_8AB09E28(s32);
    extern s32 func_8AB09FC4(s32);
    extern s32 func_8AB09FBC();
    extern s32 func_8AB0A074(s32);
    extern s32 func_8AB0A2D8(s32);
    extern s32 func_8AB0A720(s32);
    extern s32 func_8AB0A8D4(s32);
    extern s32 func_8AB0148C(s16);
    extern void *D_80087200;
    extern s32 func_800279C4(s32);

    s32 i;

    switch (arg0) {
    case 19: arg0 = func_8AB08C6C(1); break;
    case 20: arg0 = func_8AB08D3C(1); break;
    case 21: arg0 = func_8AB08CD0(1); break;
    case 22: arg0 = func_8AB08DBC(1); break;
    case 23: arg0 = func_8AB08F58(1); break;
    case 24: arg0 = func_8AB090B8(1); break;
    case 25: arg0 = func_8AB09A28(1); break;
    case 26: arg0 = func_8AB09BD8(1); break;
    case 27: arg0 = func_8AB09E28(1); break;
    case 29: arg0 = func_8AB09FC4(1); break;
    case 28: arg0 = func_8AB09FBC(1); break;
    case 30: arg0 = func_8AB0A074(1); break;
    case 31: arg0 = func_8AB0A2D8(1); break;
    case 32: arg0 = func_8AB0A720(1); break;
    case 33: arg0 = func_8AB0A8D4(1); break;
    }
    switch (arg0) {
    case 19:
        break;
    case 24:
    case 25:
    case 26:
        if ((*(u16 *)((u8 *)D_80087200 + 8) & 0x1000) != 0) {
            func_800279C4(0xCF07);
            arg0 = func_8AB0A2D8(0);
        }
        break;
    }
    for (i = 0; i < 4; i++) {
        func_8AB0148C(i);
    }
    return arg0;
}

extern void *D_8AB16A40;
extern void func_800503A4(u8 *arg0);
extern s32 func_8AB09A28(s32 arg0);
// Unprototyped on purpose: the file's own matched definition is
// `s32 func_8AB09FBC(void)` (it returns 0x1C and ignores $a0), but the retail
// caller still puts 2 in $a0 before the jal. A (s32) prototype clashes with
// that definition; an unprototyped declaration is compatible with it and
// still lets the constant be passed.
extern s32 func_8AB09FBC();
extern s32 func_8AB08C6C(s32);
extern s32 func_8AB08D3C(s32);
extern s32 func_8AB08DBC(s32);
extern s32 func_8AB08F58(s32);
extern s32 func_8AB090B8(s32);
extern s32 func_8AB09BD8(s32);
extern s32 func_8AB09E28(s32);
extern s32 func_8AB09FC4(s32);
extern s32 func_8AB0A074(s32);
extern s32 func_8AB0A2D8(s32);
extern s32 func_8AB0A720(s32);


void func_8AB08B14(s32 arg0) {
    extern s32 func_8AB08C6C(s32);
    extern s32 func_8AB08D3C(s32);
    extern s32 func_8AB08CD0(s32);
    extern s32 func_8AB08DBC(s32);
    extern s32 func_8AB08F58(s32);
    extern s32 func_8AB090B8(s32);
    extern s32 func_8AB09A28(s32);
    extern s32 func_8AB09BD8(s32);
    extern s32 func_8AB09E28(s32);
    extern s32 func_8AB09FC4(s32);
    extern s32 func_8AB09FBC();
    extern s32 func_8AB0A074(s32);
    extern s32 func_8AB0A2D8(s32);
    extern s32 func_8AB0A720(s32);
    extern s32 func_8AB0A8D4(s32);

    func_800503A4((s32)D_8AB16A40);
    switch (arg0) {
        case 19:
            func_8AB08C6C(2);
            return;
        case 20:
            func_8AB08D3C(2);
            return;
        case 21:
            func_8AB08CD0(2);
            return;
        case 22:
            func_8AB08DBC(2);
            return;
        case 23:
            func_8AB08F58(2);
            return;
        case 24:
            func_8AB090B8(2);
            return;
        case 25:
            func_8AB09A28(2);
            return;
        case 26:
            func_8AB09BD8(2);
            return;
        case 27:
            func_8AB09E28(2);
            return;
        /* 29 is deliberately written before 28: the retail jump table
         * (jtbl_8AB11A44) sends case 28 to func_8AB09FBC and case 29 to
         * func_8AB09FC4, while IDO lays case bodies out in SOURCE order and
         * retail has the 9FC4 body first (0x8AB08BE4) and the 9FBC body
         * second (0x8AB08BF4). Ascending case order puts them the other way
         * round (two jal relocation diffs, score 1510). */
        case 29:
            func_8AB09FC4(2);
            return;
        case 28:
            func_8AB09FBC(2);
            return;
        case 30:
            func_8AB0A074(2);
            return;
        case 31:
            func_8AB0A2D8(2);
            return;
        case 32:
            func_8AB0A720(2);
            return;
        case 33:
            func_8AB0A8D4(2);
            return;
    }
}

extern s32 func_8AB08C6C(s32);
s32 func_8AB08C4C(void) {
    return func_8AB08C6C(0);
}

extern s32 StageContext_GetFadeMode(void);
extern void func_8AB04AE4(void);
extern s32 func_8AB08DBC(s32);
s32 func_8AB08C6C(s32 arg0) { s32 result = 0x13; switch (arg0) { case 0: func_8AB04AE4(); break; case 1: if (StageContext_GetFadeMode() == 0) result = func_8AB08DBC(0); break; } return result; }

extern s16 D_8AB16CC8;
extern s32 func_8AB08D3C(s32);
s32 func_8AB08CD0(s32 arg0) { s32 result = 0x15; s16 *p; p = &D_8AB16CC8; switch (arg0) { case 0: *p = 0; break; case 1: if (*p >= 0xA) func_8AB08D3C(0); *p += 1; break; } return result; }

extern void StageFade_StartFromTransparent(s32);
s32 StageContext_GetFadeMode();
extern void func_800225C4(s32);
s32 func_8002806C();

s32 func_8AB08D3C(s32 arg0) {
    s32 sp1C;

    sp1C = 0x14;
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

extern void *D_80087200;
extern s32 func_800279C4(s32);
extern s32 func_8AB00548(void);
extern void func_8AB00B78(s32);
extern s32 func_8AB08F58(s32);
extern void func_8AC063AC(void *, u16);
extern void func_8AC06400(void *, void *);
extern s32 D_8AB11280;
extern void *D_8AB11D00;
extern void *D_8AB12688;
extern u16 D_8AB1268E;
extern s16 D_8AB1269C;
extern s32 D_8AB12BA8;
extern s32 D_8AB12CBC;
extern s32 D_8AB12D50;
extern s32 D_8AB12DE4;
extern s32 D_8AB12E78;
extern void *D_8AB16B9C;
extern s32 D_8AB16BA0;

s32 func_8AB08DBC(s32 arg0) {
    u16 temp_v0; /* unused; its 0x1C home slot places result at 0x18 as in the original frame */
    s32 result;

    result = 0x16;
    switch (arg0) {
    case 0:
        func_8004C8A0(D_8AB126A8, 0x100, 0x3A, 3);
        *(u16 *)((u8 *)D_8AB11D00 + 2) = (u16)(*(u16 *)((u8 *)D_8AB11D00 + 2) | 1);
        func_8004C8A0(&D_8AB12BA8, 0x100, 0x39, 8);
        *(u16 *)((u8 *)D_8AB12688 + 2) = (u16)(*(u16 *)((u8 *)D_8AB12688 + 2) | 1);
        func_8AB00B98(D_8AB12688, -1U);
        func_8AB04AE4();
        func_8AC06400(&D_8AB16BA0, D_8AB16B9C);
        *(u16 *)((u8 *)D_8AB16B9C + 2) = (u16)(*(u16 *)((u8 *)D_8AB16B9C + 2) | 1);
        D_8AB12CBC = 0;
        D_8AB12D50 = 0;
        D_8AB12DE4 = 0;
        D_8AB12E78 = 0;
        D_8AB11280 = 0;
        D_8AB1269C = 0x14;
        func_8AB00548();
        break;
    case 1:
        func_8AC063AC(&D_8AB16BA0, D_8AB1268E);
        if (*(u16 *)((u8 *)D_80087200 + 8) & 0x8000) {
            *(u16 *)((u8 *)D_8AB16B9C + 2) = (u16)(*(u16 *)((u8 *)D_8AB16B9C + 2) & 0xFFFE);
            *(u16 *)((u8 *)D_8AB12688 + 2) = (u16)(*(u16 *)((u8 *)D_8AB12688 + 2) & 0xFFFE);
            func_800279C4(0xCF0B);
            result = func_8AB08F58(0);
        } else if (*(u16 *)((u8 *)D_80087200 + 8) & 0x4000) {
            result = func_8AB08D3C(0);
            func_8AB00B78(3);
        }
        break;
    }
    return result;
}
extern u8 *D_8AB16CB0;
extern s16 D_8AB16C18;
extern s32 D_8AB16CC4;
extern s32 func_8AB090B8(s32);
extern void func_80021ED8(s32);
extern void func_800225C4(s32);
extern void Geo_RenderRootNode(s32);
extern void *func_8004C8A0(void *, s32, s32, s32);
extern void func_87F005F0(f32, f32);
extern u32 func_87F006AC(void);
extern void func_87F006BC(void);
extern void func_8AB00BA4();
extern u8 D_8AB126A8[];
s32 func_8AB08F58(s32 arg0) {
    s32 result = 0x17;
    s16 temp_v0;
    switch (arg0) {
    case 0:
        func_87F005F0((f32)(*(s16 *)(D_8AB16CB0 + 8) - 0x140), (f32)(0xF0 - *(s16 *)(D_8AB16CB0 + 0xA)));
        func_8004C8A0(D_8AB126A8, 0x100, 0x3A, 0x183);
        D_8AB16C18 = 3;
        func_800225C4(0x5A);
        break;
    case 1:
        func_87F006BC();
        temp_v0 = func_87F006AC();
        switch (temp_v0) {
        case 1:
            func_8AB00BA4(0x64, D_8AB16C18, 0);
            D_8AB16C18 -= 1;
            break;
        case 2:
            func_8AB00BA4(0x64, D_8AB16C18, 0);
            func_80021ED8(0x4C);
            D_8AB16C18 -= 1;
            break;
        case 3:
            result = func_8AB090B8(0);
            break;
        }
        break;
    case 2:
        Geo_RenderRootNode(D_8AB16CC4);
        break;
    }
    return result;
}

extern void func_8004C594(s32, s32);
extern void func_8AB00478(void);
extern void func_8AB04AE4(void);
extern void *func_8004C8A0(void *, s32, s32, s32);
extern void func_8AB00BA4();
extern u8 D_8AB126A8[];
extern void *D_8AB11D00;
extern s16 D_8AB12694;
extern s16 D_8AB12698;
extern s32 D_8AB11280;
extern s32 D_8AB16CC0;
extern s16 D_8AB16CCA;
extern s32 D_8AB16CB4;
extern s32 D_8AB16CBC;
extern void *D_8AB16A58;
extern u8 *D_8AB16C98[];
extern s32 func_8AB09A28(s32);



s32 func_8AB090B8(s32 mode) {
    s16 *timer = &D_8AB16CCA;
    s32 delay = 24;
    s16 elapsed;
    s32 i;

    switch (mode) {
    case 0:
        func_8AB00BA4(0x10006, 0, 0);
        D_8AB16CC0 = 0;
        *timer = 0;
        if (D_8AB12694 + D_8AB12698 > 0) {
            *(u16 *)((u8 *)D_8AB11D00 + 2) |= 1;
            func_8004C594(2, D_8AB12694 + 1);
            if (D_8AB16CB4 != 0) {
                func_8004C8A0(D_8AB126A8, 256, 58, 398);
            } else if (D_8AB11280 != 0) {
                func_8004C8A0(D_8AB126A8, 256, 58, 397);
            } else if (D_8AB16CBC != 0) {
                func_8004C8A0(D_8AB126A8, 256, 57, 754);
            } else {
                func_8004C8A0(D_8AB126A8, 256, 58, func_8AB023EC(9) + 388);
            }
        } else {
            *(u16 *)((u8 *)D_8AB11D00 + 2) &= ~1;
        }
        func_8AB04AE4();
        *(u16 *)((u8 *)D_8AB16A58 + 2) &= ~1;
        // D_8AB16C98 is the first of four consecutive pointer globals
        // (0x8AB16C98..0x8AB16CA4). Indexing one array lets ugen unroll the loop
        // into the four clears; func_8AB0A074 above uses the same array-loop form
        // on D_8AB16C20.
        for (i = 0; i < 4; i++) {
            *(u16 *)(D_8AB16C98[i] + 2) &= ~2;
        }
        func_8AB00478();
        break;
    case 1:
        elapsed = *timer + 1;
        if (D_8AB16CB4 != 0) {
            *timer = elapsed;
            if (elapsed >= 60) {
                delay = func_8AB09A28(0);
            }
        } else {
            *timer = elapsed;
            if (elapsed >= 45) {
                delay = func_8AB09A28(0);
            }
        }
        break;
    }
    return delay;
}

extern u8 D_8AB16A60[];
extern s16 D_8AB16CCC;
extern s16 D_8AB16CCE;
extern u32 D_8AB1268C;
extern s8 *D_8AB1129C;
extern s32 HAL_Strcmp(const s8 *, const s8 *);
extern void func_8AB00BA4(s32, s32, s32);
s32 func_8AB092F4(void) {
    u8 *node;
    u8 *cursor;
    u8 *last;
    s32 i;

    node = D_8AB11D00;
    func_8004C8A0(D_8AB16A60, 256, *(u16 *)(node + 48), *(u16 *)(node + 50));
    cursor = D_8AB16A60;
    for (i = 0; i < D_8AB16CCC; i++) {
        last = cursor;
        if (*cursor == 0) {
            D_8AB16CCE = 1;
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
        if (HAL_Strcmp((s8 *)last, D_8AB1129C) == 0) {
            func_8AB00BA4(65549, 0, 0);
        } else {
            func_8AB00BA4(65548, 0, 0);
        }
        D_8AB16CCC++;
    }
    return 1;
}

void func_8AB09418(u8 *arg0) {
    *(s32 *)(arg0 + 0xC) = 1;
    *(s16 *)(arg0 + 0x10) = 1;
}

extern u8 D_8AB12CB0[];
extern u16 *D_8AB16C20[];
extern u8 *D_8AB16C98[];
extern s16 D_8AB16CD0;
extern s16 D_8AB16CD2;
extern s16 D_8AB1269A;
extern void *D_80087204;
extern void *D_80087208;
extern void *D_8008720C;
extern u8 *D_8AB1266C;
extern u8 *D_8AB12670;
extern u8 *D_8AB12674;
extern void TextRow_SetOrangeState(s16);
extern void func_8AB01414(s16);
extern void func_8AB01454(s16);
extern void func_8AB03DFC(s16, s16);
extern void func_8AB04038(void);
extern void func_8AB00B98(u8 *, u32);



void func_8AB09428(void) {
    u32 row_address;
    s32 i;
    u16 buttons;
    s32 player;
    s32 animation;
    u16 **player_slot;

    D_8AB16CD0 = 0;
    D_8AB16CD2 = 0;
    for (i = 0; i < 4; i++) {
        player = (i + D_8AB1268C) & 3;
        row_address = (u32)(D_8AB12CB0 + player * 148);
        animation = player + 6;
        if (*(s16 *)(row_address + 4) == 0 && *(s32 *)(row_address + 12) == 0 && *(s16 *)row_address != 0) {
            D_8AB16CD2++;
            player_slot = &D_8AB16C20[player];
            switch (player) {
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
            if ((*(u16 *)(D_8AB16C98[0] + 2) & 2) == 0 && (buttons & 8)) {
                if (D_8AB1269A == 0) {
                    TextRow_SetOrangeState(player);
                    func_8AB01414(player);
                    D_8AB16CD0 = 1;
                } else {
                    func_8AB03DFC(player, 0);
                    func_8AB01454(player);
                    func_8AB09418((u8 *)row_address);
                    *(u16 *)((u8 *)*player_slot + 2) |= 2;
                    *(s16 *)((u8 *)*player_slot + 38) = 6;
                }
                *(s16 *)(row_address + 6) = 8;
                *(u16 *)(D_8AB16C98[0] + 2) |= 2;
                *(s16 *)(D_8AB16C98[0] + 38) = animation;
                func_8AB00B98(D_8AB12668[0], 0xFFFF00FF);
            } else if ((*(u16 *)(D_8AB16C98[1] + 2) & 2) == 0 && (buttons & 1)) {
                if (D_8AB1269A == 1) {
                    TextRow_SetOrangeState(player);
                    func_8AB01414(player);
                    D_8AB16CD0 = 1;
                } else {
                    func_8AB03DFC(player, 1);
                    func_8AB01454(player);
                    func_8AB09418((u8 *)row_address);
                    *(u16 *)((u8 *)*player_slot + 2) |= 2;
                    *(s16 *)((u8 *)*player_slot + 38) = 6;
                }
                *(s16 *)(row_address + 6) = 1;
                *(u16 *)(D_8AB16C98[1] + 2) |= 2;
                *(s16 *)(D_8AB16C98[1] + 38) = animation;
                func_8AB00B98(D_8AB1266C, 0xFFFF00FF);
            } else if ((*(u16 *)(D_8AB16C98[2] + 2) & 2) == 0 && (buttons & 4)) {
                if (D_8AB1269A == 2) {
                    TextRow_SetOrangeState(player);
                    func_8AB01414(player);
                    D_8AB16CD0 = 1;
                } else {
                    func_8AB03DFC(player, 2);
                    func_8AB01454(player);
                    func_8AB09418((u8 *)row_address);
                    *(u16 *)((u8 *)*player_slot + 2) |= 2;
                    *(s16 *)((u8 *)*player_slot + 38) = 6;
                }
                *(s16 *)(row_address + 6) = 4;
                *(u16 *)(D_8AB16C98[2] + 2) |= 2;
                *(s16 *)(D_8AB16C98[2] + 38) = animation;
                func_8AB00B98(D_8AB12670, 0xFFFF00FF);
            } else if ((*(u16 *)(D_8AB16C98[3] + 2) & 2) == 0 && (buttons & 2)) {
                if (D_8AB1269A == 3) {
                    TextRow_SetOrangeState(player);
                    func_8AB01414(player);
                    D_8AB16CD0 = 1;
                } else {
                    func_8AB03DFC(player, 3);
                    func_8AB01454(player);
                    func_8AB09418((u8 *)row_address);
                    *(u16 *)((u8 *)*player_slot + 2) |= 2;
                    *(s16 *)((u8 *)*player_slot + 38) = 6;
                }
                *(s16 *)(row_address + 6) = 2;
                *(u16 *)(D_8AB16C98[3] + 2) |= 2;
                *(s16 *)(D_8AB16C98[3] + 38) = animation;
                func_8AB00B98(D_8AB12674, 0xFFFF00FF);
            }
            if (*(s32 *)(row_address + 12) == 0 && *(s16 *)(row_address + 2) >= 9) {
                player_slot = &D_8AB16C20[player];
                if (D_8AB11280 == 0) {
                    func_80021ED8(0x68);
                    D_8AB11280 = 1;
                }
                if (*(s32 *)(row_address + 8) == 0) {
                    func_8AB00BA4(65554, 0, 0);
                }
                *(s32 *)(row_address + 8) = 1;
                *(u16 *)((u8 *)*player_slot + 2) |= 2;
                *(s16 *)((u8 *)*player_slot + 38) = 5;
            }
        }
    }
    TextHighlight_AnimateScales();
    func_8AB04038();
}

extern u8 D_8AB12CB0[];
extern s16 D_8AB16CAC;
extern s32 func_8AB0A074(s32);
extern u8 * D_8AB11D0C;
s32 func_8AB099BC(s32 arg0) {
    s32 i;
    u8 *ptr;

    ptr = D_8AB12CB0;
    for (i = 0; i != 4; i++, ptr += 0x94) {
        if (*(s16 *)(ptr + 2) == 10) {
            D_8AB16CAC = i;
            D_8AB11D0C[0xF] = i;
            arg0 = func_8AB0A074(0);
            break;
        }
    }
    return arg0;
}

/* mkdraft:func_8AB09A28 begin */
extern void func_8AB03394(void);
extern void func_8AB02438(void);
extern void func_8AB04BD4(void);
extern s32 func_8AB092F4(void);
extern void func_8AB09428(void);
extern s32 func_8AB00548(void);
extern void _bzero(void *, s32);
extern void func_8004C594(s32, s32);
extern s32 func_8AB09BD8(s32);
extern s32 func_8AB09E28(s32);
extern s32 func_8AB099BC(s32);
extern s16 D_8AB16CCC;
extern s16 D_8AB16CCE;
extern s16 D_8AB16CD0;
extern s32 D_8AB16CB4;
extern void *D_8AB16A58;
extern u8 D_8AB16A60[];

s32 func_8AB09A28(s32 arg0) {
    s32 result;
    s32 new_var;
    u8 **ptr;
    u8 **end;
    u8 **ptr2;
    u8 **end2;
    u8 *temp;

    new_var = 1;
    result = 0x19;
    switch (arg0) {
        case 0:
            func_8AB03394();
            func_8AB02438();
            new_var = 1;
            D_8AB16CCC = new_var;
            D_8AB16CCE = 0;
            _bzero(&D_8AB16A60, 0x100);
            *(u16 *)((u8 *)D_8AB16A58 + 2) = (u16)(*(u16 *)((u8 *)D_8AB16A58 + 2) | 1);
            *(u16 *)((u8 *)D_8AB11D00 + 2) &= 0xFFFE;
            func_8AB04BD4();
            // &D_8AB12668[4] is D_8AB12678 spelled through a different symbol: uopt CSE-merges
            // two D_8AB12678 address loads into one shared register here, which the retail
            // code does not do. The linked address is identical either way.
            // The comma expressions keep as1's lui/addiu ordering of both loop-preheader pairs.
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
            func_8004C594(2, D_8AB12694 + 1);
            D_8AB16CB4 = 0;
            func_8AB00548();
            break;
        case 1:
            func_8AB09428();
            func_8AB092F4();
            if (D_8AB16CCE == new_var) {
                result = func_8AB09BD8(0);
            }
            if (new_var == D_8AB16CD0) {
                result = func_8AB09E28(0);
                if (D_8AB16CCE == 0) {
                    func_8004C8A0(D_8AB16A60, 0x100, *(u16 *)((u8 *)D_8AB11D00 + 0x30), *(u16 *)((u8 *)D_8AB11D00 + 0x32));
                }
            }
            result = func_8AB099BC(result);
            break;
        case 2:
            break;
    }
    return result;
}
/* mkdraft:func_8AB09A28 end */

extern s16 D_8AB1269C;
extern s16 D_8AB16CD0;
extern s16 D_8AB16CD2;
extern s32 D_8AB16CD4;
extern void func_8AB01728(void);
extern void func_8AB09428(void);
extern s32 func_80001FF0(void);
extern s32 func_8AB09E28(s32);
extern void func_8AB00BA4();
extern s32 func_8AB099BC(s32 arg0);
s32 func_8AB09BD8(s32 arg0) {
    s16 n;
    s32 result;
    result = 0x1A;
    switch (arg0) {
    case 0:
        D_8AB1269C = 0x14;
        D_8AB16CD4 = 0;
        break;
    case 1:
        func_8AB01728();
        func_8AB09428();
        if (D_8AB16CD4 % (func_80001FF0() / 4) == 0) {
            D_8AB1269C--;
            if (D_8AB1269C < 0) {
                D_8AB1269C = 0;
                if (D_8AB16CD0 == 0) {
                    func_8AB00BA4(0x65, 0, 0);
                }
                D_8AB16CD0 = 1;
            }
        }
        if (D_8AB16CD4 % ((func_80001FF0() / 4) * 2) == 0) {
            n = D_8AB1269C / 2 + 1;
            if (D_8AB16CD0 == 0) {
                func_8AB00BA4(0x65, n, 0);
            }
        }
        if (D_8AB16CD2 == 0 || D_8AB16CD0 == 1) {
            result = func_8AB09E28(0);
        }
        result = func_8AB099BC(result);
        D_8AB16CD4++;
        break;
    case 2:
        break;
    }
    return result;
}

extern u8 D_80088E50[];
extern u16 *D_8AB16C20[];
extern s32 StageContext_GetFadeMode(void);
extern void func_8AB04AE4(void);
extern s32 func_8AB06718(s32);
extern s32 func_8AB08DBC(s32);
void func_8AB09DCC(void *arg0, s32 arg1) {
    u16 *p;
    if (*(s32 *)((u8 *)arg0 + 0xC) == 1) {
        *(s16 *)((u8 *)arg0 + 0x10) -= 1;
        if (*(s16 *)((u8 *)arg0 + 0x10) <= 0) {
            *(s16 *)((u8 *)arg0 + 0x10) = 0;
            *(s32 *)((u8 *)arg0 + 0xC) = 0;
            if (*(s32 *)((u8 *)arg0 + 8) == 0) {
                p = D_8AB16C20[arg1];
                p[1] &= 0xFFFD;
            }
        }
    }
}

extern s16 D_8AB16CD8;
extern s32 func_8AB09FC4(s32);
// Close to TextMode8_HandleRowCleanupState (fragment45_2324B0.c); returns state 27, counts in
// D_8AB16CD8, updates rows with func_8AB09DCC, sets D_8AB16CB4, and returns
// func_8AB09FC4(0) once the counter reaches 31.
//@src/fragments/45/fragment45_2324B0.c
s32 func_8AB09E28(s32 phase) {
    s32 result = 27;
    s16 *counter = &D_8AB16CD8;
    s32 i;
    s32 all_wrong;
    u8 *row;

    switch (phase) {
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
                func_8AB09DCC(row, i);
            }
            D_8AB16CB4 = 1;
        } else {
            for (i = 0; i < 4; i++) {
                row = D_8AB12CB0 + i * 148;
                if (*(s16 *)row != 0 && *(s16 *)(row + 4) == 0) {
                    func_8AB09DCC(row, i);
                }
            }
        }
        break;
    case 1:
        *counter += 1;
        TextHighlight_AnimateScales();
        if (*counter == func_80001FF0() / 4) {
            func_8AB00BA4(102, 0, 0);
        }
        if (*counter >= 31) {
            result = func_8AB09FC4(0);
        }
        break;
    case 2:
        break;
    }
    return result;
}

s32 func_8AB09FBC(void) {
    return 0x1C;
}

extern s16 D_8AB16CDA;
extern s16 D_8AB12698;
extern s32 D_8AB16CBC;
extern void func_8AB01FBC(void);
extern void func_8AB03ED4(void);
extern void func_8AB012A4(void);
extern s32 func_8AB090B8(s32);
s32 func_8AB09FC4(s32 arg0)
{
    s32 result;
    int new_var;

    new_var = 1;
    result = 0x1D;
    switch (arg0) {
        case 0:
            D_8AB16CDA = 0;
            func_8AB01FBC();
            break;
        case 1:
            D_8AB16CDA += new_var;
            func_8AB03ED4();
            if (D_8AB16CDA >= 0xB) {
                func_8AB012A4();
                if (D_8AB12698 > 0) {
                    D_8AB16CBC = 1;
                }
                result = func_8AB090B8(0);
            }
            break;
    }
    return result;
}

extern s16 D_8AB16CDC;
extern void Audio_PlayDefaultSound(u16);
extern s32 func_8AB0A720(s32);
s32 func_8AB0A074(s32 arg0) {
    s16 *counter = &D_8AB16CDC;
    s32 result = 30;
    s32 i;

    switch (arg0) {
    case 0:
        *counter = 0;
        *(u16 *)((u8 *)D_8AB11D00 + 2) |= 1;
        for (i = 0; i < 4; i++) {
            D_8AB16C20[i][1] &= ~2;
        }
        func_8004C8A0(D_8AB126A8, 256, 57, 389);
        *(u16 *)((u8 *)D_8AB16A58 + 2) &= ~1;
        func_8AB00BA4(102, 0, 0);
        Audio_PlayDefaultSound(52998);
        func_800225C4(40);
        break;
    case 1:
        *counter += 1;
        TextHighlight_AnimateScales();
        if (*counter >= 61) {
            result = func_8AB0A720(0);
        }
        break;
    }
    return result;
}

extern u8 *D_8AB16B80;
extern u8 *D_8AB16B84;
extern u8 *D_8AB16B88;
extern u8 *D_8AB16B90;
extern u8 *D_8AB16B94;
extern u8 *D_8AB16B98;
extern s16 D_8AB16CDE;
extern void func_8AB00B98(u8 *, u32);
void func_8AB0A1A4(void) {
    (*(u16 *)((u8 *)(D_8AB16B80) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AB16B80) + (2))) & 0xFFFE);
    (*(u16 *)((u8 *)(D_8AB16B84) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AB16B84) + (2))) & 0xFFFE);
    (*(u16 *)((u8 *)(D_8AB16B88) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AB16B88) + (2))) & 0xFFFE);
    func_8AB00B98(D_8AB16B90, -1U);
    func_8AB00B98(D_8AB16B94, -1U);
    func_8AB00B98(D_8AB16B98, -1U);
    switch (D_8AB16CDE) {
    case 0:
        (*(u16 *)((u8 *)(D_8AB16B80) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AB16B80) + (2))) | 1);
        func_8AB00B98(D_8AB16B90, 0xFFFF00FFU);
        return;
    case 1:
        (*(u16 *)((u8 *)(D_8AB16B84) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AB16B84) + (2))) | 1);
        func_8AB00B98(D_8AB16B94, 0xFFFF00FFU);
        return;
    case 2:
        (*(u16 *)((u8 *)(D_8AB16B88) + (2))) = (u16) ((*(u16 *)((u8 *)(D_8AB16B88) + (2))) | 1);
        func_8AB00B98(D_8AB16B98, 0xFFFF00FFU);
        return;
    }
}

/* mkdraft:func_8AB0A2D8 begin */
extern s16 D_8AB126A0;
extern s16 D_8AB12CB4;
extern s32 D_8AB13F28;
extern void TextReference_BuildModeSelection(void);
extern void func_800226C0(s32);
extern void func_8AB005B0(void);
extern void func_8AB01288(void);

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
extern void *D_8AB16B8C;
extern void *D_8AB16C24;
extern void *D_8AB16C28;
extern void *D_8AB16C2C;
extern u8 *D_8AB16C98[];
extern void *D_8AB16C9C;
extern void *D_8AB16CA0;
extern void *D_8AB16CA4;
extern s32 D_8AB16CC0;
extern s32 D_8AB16CE0;

#ifndef M2C_FIELD /* mkdraft: m2c --valid-syntax helpers */
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



s32 func_8AB0A2D8(s32 arg0) {
    s32 temp_v0;
    s32 var_sp18;
    u16 **D_8AB16C20_ptr = D_8AB16C20;
    void **D_8AB16CA4_ptr = &D_8AB16CA4;
    void **D_8AB16C28_ptr = &D_8AB16C28;
    void **D_8AB16CA0_ptr = &D_8AB16CA0;
    void **D_8AB16C9C_ptr = &D_8AB16C9C;
    void **D_8AB16C98_ptr = &D_8AB16C98;
    void **D_8AB16C24_ptr = &D_8AB16C24;
    void **D_8AB16C2C_ptr = &D_8AB16C2C;

    if (var_sp18 != 0x1F) {
        D_8AB16CE0 = var_sp18;
        var_sp18 = 0x1F;
    }
    switch (arg0) {                                 /* switch 1; irregular */
    case 0:                                         /* switch 1 */
        D_8AB16CDE = 0;
        *(u16 *)((u8 *)D_8AB16A58 + 2) &= ~1;
        if (D_8AB16CC0 == 0) {
            *(u16 *)((u8 *)D_8AB11D00 + 2) &= ~1;
            func_8AB005B0();
        }
        M2C_FIELD(D_8AB16B8C, u16 *, 2) = (u16) (M2C_FIELD(D_8AB16B8C, u16 *, 2) | 2);
        M2C_FIELD(D_8AB16B90, u16 *, 2) = (u16) (M2C_FIELD(D_8AB16B90, u16 *, 2) | 2);
        M2C_FIELD(D_8AB16B94, u16 *, 2) = (u16) (M2C_FIELD(D_8AB16B94, u16 *, 2) | 2);
        M2C_FIELD(D_8AB16B98, u16 *, 2) = (u16) (M2C_FIELD(D_8AB16B98, u16 *, 2) | 2);
        M2C_FIELD((*D_8AB16C98_ptr), u16 *, 2) = (u16) (M2C_FIELD((*D_8AB16C98_ptr), u16 *, 2) & 0xFFFD);
        M2C_FIELD(*D_8AB16C20_ptr, u16 *, 2) = (u16) (M2C_FIELD(*D_8AB16C20_ptr, u16 *, 2) & 0xFFFD);
        M2C_FIELD((*D_8AB16C9C_ptr), u16 *, 2) = (u16) (M2C_FIELD((*D_8AB16C9C_ptr), u16 *, 2) & 0xFFFD);
        M2C_FIELD((*D_8AB16C24_ptr), u16 *, 2) = (u16) (M2C_FIELD((*D_8AB16C24_ptr), u16 *, 2) & 0xFFFD);
        M2C_FIELD((*D_8AB16CA0_ptr), u16 *, 2) = (u16) (M2C_FIELD((*D_8AB16CA0_ptr), u16 *, 2) & 0xFFFD);
        M2C_FIELD((*D_8AB16C28_ptr), u16 *, 2) = (u16) (M2C_FIELD((*D_8AB16C28_ptr), u16 *, 2) & 0xFFFD);
        M2C_FIELD((*D_8AB16CA4_ptr), u16 *, 2) = (u16) (M2C_FIELD((*D_8AB16CA4_ptr), u16 *, 2) & 0xFFFD);
        M2C_FIELD((*D_8AB16C2C_ptr), u16 *, 2) = (u16) (M2C_FIELD((*D_8AB16C2C_ptr), u16 *, 2) & 0xFFFD);
        func_8AB04AE4();
        D_8AB126A0 = 0;
        func_8AB00BA4(0x66, 0, 0);
        func_80021ED8(0x50);
        D_8AB1269C = 0x14;
        break;
    case 1:                                         /* switch 1 */
        temp_v0 = M2C_FIELD(D_8AB13F28, u16 *, 8);
        if (temp_v0 & 0x800) {
            D_8AB16CDE -= 1;
            if (D_8AB16CDE < 0) {
                D_8AB16CDE = 2;
            }
            func_800279C4(0xCF01);
        } else if (temp_v0 & 0x400) {
            D_8AB16CDE += 1;
            if (D_8AB16CDE >= 3) {
                D_8AB16CDE = 0;
            }
            func_800279C4(0xCF01);
        } else if (M2C_FIELD(D_80087200, u16 *, 8) & 0x8000) {
            switch (D_8AB16CDE) {                   /* switch 2; irregular */
            case 0:                                 /* switch 2 */
                func_800279C4(0xCF02);
                M2C_FIELD(D_8AB16B8C, u16 *, 2) = (u16) (M2C_FIELD(D_8AB16B8C, u16 *, 2) & 0xFFFD);
                M2C_FIELD(D_8AB16B90, u16 *, 2) = (u16) (M2C_FIELD(D_8AB16B90, u16 *, 2) & 0xFFFD);
                M2C_FIELD(D_8AB16B94, u16 *, 2) = (u16) (M2C_FIELD(D_8AB16B94, u16 *, 2) & 0xFFFD);
                M2C_FIELD(D_8AB16B98, u16 *, 2) = (u16) (M2C_FIELD(D_8AB16B98, u16 *, 2) & 0xFFFD);
                D_8AB16CDE = -1;
                func_8AB01288();
                M2C_FIELD(*D_8AB16C20_ptr, u16 *, 2) = (u16) (M2C_FIELD(*D_8AB16C20_ptr, u16 *, 2) & 0xFFFD);
                D_8AB12CB2 = 0;
                D_8AB12CB4 = 0;
                D_8AB12CB8 = 0;
                D_8AB12CBC = 0;
                D_8AB12CC0 = 0;
                M2C_FIELD((*D_8AB16C24_ptr), u16 *, 2) = (u16) (M2C_FIELD((*D_8AB16C24_ptr), u16 *, 2) & 0xFFFD);
                D_8AB12D46 = 0;
                D_8AB12D48 = 0;
                D_8AB12D4C = 0;
                D_8AB12D50 = 0;
                D_8AB12D54 = 0;
                M2C_FIELD((*D_8AB16C28_ptr), u16 *, 2) = (u16) (M2C_FIELD((*D_8AB16C28_ptr), u16 *, 2) & 0xFFFD);
                D_8AB12DDA = 0;
                D_8AB12DDC = 0;
                D_8AB12DE0 = 0;
                D_8AB12DE4 = 0;
                D_8AB12DE8 = 0;
                M2C_FIELD((*D_8AB16C2C_ptr), u16 *, 2) = (u16) (M2C_FIELD((*D_8AB16C2C_ptr), u16 *, 2) & 0xFFFD);
                D_8AB12E6E = 0;
                D_8AB12E70 = 0;
                D_8AB12E74 = 0;
                D_8AB12E78 = 0;
                D_8AB12E7C = 0;
                D_8AB16CBC = 0;
                TextReference_BuildModeSelection();
                var_sp18 = func_8AB08DBC(0);
                break;
            case 1:                                 /* switch 2 */
                func_800279C4(0xCF02);
                M2C_FIELD(D_8AB11D0C, s32 *, 0x10) = 1;
                var_sp18 = func_8AB08D3C(0);
                break;
            case 2:                                 /* switch 2 */
                func_800226C0(3);
                var_sp18 = func_8AB08D3C(0);
                break;
            }
        }
        func_8AB0A1A4();
        break;
    }
    return var_sp18;
}
/* mkdraft:func_8AB0A2D8 end */

/* mkdraft:func_8AB0A720 begin */
extern void *D_8AB11D00;
extern void *D_8AB16A58;
extern u8 *D_8AB16C98[];
extern void *D_8AB16C9C;
extern void *D_8AB16CA0;
extern void *D_8AB16CA4;
extern s16 D_8AB16CAC;
extern u16 *D_8AB16C20[];
extern s32 D_8AB16CC0;
extern s16 D_8AB16CE4;
extern u8 D_8AB126A8[];
extern s16 D_8AB126A0;
extern void func_8004C54C(s32, s32);
extern void func_80021ED8(s32);
extern s32 func_8AB00618(void);
extern void func_8AB007E0(void);
extern void func_80027774(s32, s32);
extern s32 func_8AB0A8D4(s32);
extern void func_8AB04AE4(void);
extern void TextHighlight_AnimateScales(void);

s32 func_8AB0A720(s32 arg0) {
    s32 result = 0x20;
    s16 *counter = &D_8AB16CE4;
    void **p_c98 = &D_8AB16C98;
    void **p_c9c = &D_8AB16C9C;
    void **p_ca0 = &D_8AB16CA0;
    void **p_ca4 = &D_8AB16CA4;
    void *dummy1, *dummy2, *dummy3; // FAKE: register-allocation helpers

    switch (arg0) {
    case 0:
        *counter = 0;
        *(u16 *)((u8 *)D_8AB16A58 + 2) = (u16)(*(u16 *)((u8 *)D_8AB16A58 + 2) & 0xFFFE);
        func_8AB04AE4();
        *((u16 *)((u8 *)(*p_c98) + 2)) = (u16)(*((u16 *)((u8 *)(*p_c98) + 2)) & 0xFFFD);
        *((u16 *)((u8 *)(*p_c9c) + 2)) = (u16)(*((u16 *)((u8 *)(*p_c9c) + 2)) & 0xFFFD);
        *((u16 *)((u8 *)(*p_ca0) + 2)) = (u16)(*((u16 *)((u8 *)(*p_ca0) + 2)) & 0xFFFD);
        *((u16 *)((u8 *)(*p_ca4) + 2)) = (u16)(*((u16 *)((u8 *)(*p_ca4) + 2)) & 0xFFFD);
        func_8004C54C(0xF, (s32)"");
        func_8004C8A0(D_8AB126A8, 0x100, 0x39, D_8AB16CAC + 0x224);
        dummy2 = D_8AB11D00; if (dummy2 == 0) {} // FAKE
        *(u16 *)((u8 *)D_8AB11D00 + 2) = (u16)(*(u16 *)((u8 *)D_8AB11D00 + 2) | 1);
        D_8AB16CC0 = 1;
        func_80021ED8(0x37);
        dummy3 = D_8AB16C20[1]; if (dummy3 == 0) {} // FAKE
        dummy2 = D_8AB16C20[1]; if (dummy2 == 0) {} // FAKE
        func_80027774(0xCA0F, 0x24);
        func_8AB007E0();
        D_8AB126A0 = 0;
        *(u16 *)((u8 *)(*(u16 **)((u8 *)D_8AB16C20 + 0)) + 2) = (u16)(*(u16 *)((u8 *)(*(u16 **)((u8 *)D_8AB16C20 + 0)) + 2) & 0xFFFD);
        *(u16 *)((u8 *)(*(u16 **)((u8 *)D_8AB16C20 + 4)) + 2) = (u16)(*(u16 *)((u8 *)(*(u16 **)((u8 *)D_8AB16C20 + 4)) + 2) & 0xFFFD);
        *(u16 *)((u8 *)(*(u16 **)((u8 *)D_8AB16C20 + 8)) + 2) = (u16)(*(u16 *)((u8 *)(*(u16 **)((u8 *)D_8AB16C20 + 8)) + 2) & 0xFFFD);
        *(u16 *)((u8 *)(*(u16 **)((u8 *)D_8AB16C20 + 12)) + 2) = (u16)(*(u16 *)((u8 *)(*(u16 **)((u8 *)D_8AB16C20 + 12)) + 2) & 0xFFFD);
        break;
    case 1:
        dummy3 = *p_ca4; if (dummy3 == 0) {} // FAKE
        dummy2 = D_8AB16C20[2]; if (dummy2 == 0) {} // FAKE
        dummy3 = D_8AB16C20[2]; if (dummy3 == 0) {} // FAKE
        *counter += 1;
        TextHighlight_AnimateScales();
        dummy2 = D_8AB16C20[3]; if (dummy2 == 0) {} // FAKE
        dummy1 = D_8AB16C20[3]; if (dummy1 == 0) {} // FAKE
        func_8AB00618();
        if (*counter >= 0x79) {
            *counter = 0x78;
            result = func_8AB0A8D4(0);
        }
        break;
    }
    return result;
}
/* mkdraft:func_8AB0A720 end */

extern s16 D_8AB16CE6;
extern s32 func_8AB0A2D8(s32);
s32 func_8AB0A8D4(s32 arg0) { s32 result = 0x21; s16 *count = &D_8AB16CE6; switch (arg0) { case 0: *count = 0; break; case 1: if (*count >= 0x1F) result = func_8AB0A2D8(0); *count = *count + 1; break; } return result; }
#endif
