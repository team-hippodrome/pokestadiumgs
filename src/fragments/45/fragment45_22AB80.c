#include "global.h"

extern void *D_80087200;
extern u16 D_8AB1268E;
extern void func_8AB00B78(s32);


#ifdef VERSION_US
// Quiz debug strings. No retail code references them.
const char D_8AB11810[] = "Clear ReTest_koumoku[] !!!!!!!!!!!!!\n";
const char D_8AB11838[] = "InitQuizKentei() start\n";
const char D_8AB11850[] = "InitQuizKentei() end\n";
const char D_8AB11868[] = "\n";
const char D_8AB1186C[] = "func_QUIZ_SEQ_MONDAI() INIT    QUIZ_TOTAL_NUM_MAX = %d\n";
const char D_8AB118A4[] = "func_QUIZ_SEQ_KAITOU()\n";
const char D_8AB118BC[] = "kaitou_rireki[%d] = %d\n";
const char D_8AB118D4[] = "RESULT[%2d]  ReTest_koumoku = %d\n";
const char D_8AB118F8[] = "QuizInfo->mode = %d\n";
const char D_8AB11910[] = "QUIZ_MODE_KENTEI_1 Clear!!!\n";
const char D_8AB11930[] = "QUIZ_MODE_KENTEI_2 Clear!!!\n";
const char D_8AB11950[] = "QUIZ_MODE_KENTEI_3 Clear!!!\n";

extern u8 *D_8AB11D0C;
void func_8AB05A00(void) { s32 i; s32 value; value = -1; i = 2; *(u8 *)(D_8AB11D0C + 0x16) = value; *(u8 *)(D_8AB11D0C + 4) = value; *(u8 *)(D_8AB11D0C + 5) = value; do { *(u8 *)(D_8AB11D0C + i + 4) = value; *(u8 *)(D_8AB11D0C + i + 5) = value; *(u8 *)(D_8AB11D0C + i + 6) = value; *(u8 *)(D_8AB11D0C + i + 7) = value; i += 4; } while (i != 0xA); }

extern s16 D_8AB1269C;
extern s32 D_8AB16958;
extern void *D_8AB11D08;
extern void func_8AC00F04(void *);
extern void func_800503A4(u8 *);
extern s32 func_8AB06650(s32);
extern s32 func_8AB066B4(s32);
extern s32 func_8AB06718(s32);
extern s32 func_8AB0683C(s32);
extern s32 func_8AB0699C(s32);
extern int func_8AB06AE8(s32);
extern s32 func_8AB06D78(s32);
extern s32 func_8AB07128(s32);
extern s32 func_8AB072EC(s32);
extern s32 func_8AB072E4();
extern s32 func_8AB073F4(s32);
extern s32 func_8AB07538(s32);
extern s32 func_8AB07A34(s32);
extern s32 func_8AB07C34(s32);
extern s32 func_8AB07DC4(s32);
extern s32 func_8AB07E6C(s32);
extern s32 func_8AB07F80(s32);
extern void *D_8AB1695C;
extern u8 D_8AB16A18[];
extern void func_800504BC(s16 *);
extern void func_8AB00BC4(s16, s16, s16, u8, u8, u8);
s32 func_8AB05A6C(s32 arg0, u8 *arg1) {
    s16 offset[2];
    s16 x;
    s16 y;
    u8 *color;

    color = D_8AB16A18;
    switch (arg0) {
    case 0:
        *(u16 *)(arg1 + 2) &= 0xFFFD;
        color[0] = 0xFF;
        color[1] = 0xFF;
        color[2] = 0;
        break;
    case 1:
        if (D_8AB16958 == 8) {
            func_800504BC(offset);
            x = *(s16 *)(arg1 + 8) + offset[0];
            y = *(s16 *)(arg1 + 0xA) + offset[1];
            func_8AB00BC4(x, y, D_8AB1269C / 2 + 1, color[0], color[1], color[2]);
            *(u16 *)((u8 *)D_8AB1695C + 2) |= 2;
        } else {
            *(u16 *)((u8 *)D_8AB1695C + 2) &= 0xFFFD;
        }
        break;
    }
    return 0;
}

extern void _bzero(void *, s32);
extern void *D_8AB11D00;
extern u8 *D_8AB11D0C;
extern u8 D_8AB126A8[];
extern u8 D_8AB12CB0[];
extern void *D_8AB167A0;
extern void *D_8AB167A4;
extern void *D_8AB167A8;
extern void *D_8AB167AC;
extern u8 D_8AB167B0[];
extern void *D_8AB168B0;
extern void *D_8AB168B4;
extern void *D_8AB168B8;
extern void *D_8AB168BC;
extern void *D_8AB168C0;
extern void *D_8AB168C4;
extern void *D_8AB168C8;
extern void *D_8AB168CC;
extern void *D_8AB168D0;
extern u8 D_8AB168D8[];
extern void *D_8AB16954;
extern void *D_8AB1695C;
extern void *D_8AB16960;
extern void *D_8AB16964;
extern void *D_8AB16968;
extern void *D_8AB1696C;
extern void *D_8AB16970;
extern void *D_8AB16974;
extern void *D_8AB16978;
extern u8 D_8AB16980[];
extern s32 D_8AB169EC;
extern void *D_8AB169F8;
extern void *D_8AB169FC;
extern void *D_8AB16A00;
extern void *D_8AB16A04;
extern void *D_8AB16A08;
extern void *D_8AB16A0C;
extern void *D_8AB16A10;
extern s32 D_8AB16A14;
extern s16 D_8AB12690;
extern u8 D_8AB1124C;

extern void func_8AB00B98(u8 *, u32);
extern void func_8AC06400(void *, void *);
extern void func_8004E308(void *, s32 (*)(s32, u8 *), u8 *);
extern void func_8AC05E40(void *, u32, u8 *);
extern void func_8AC00DF4(void *);
extern void func_8AC06E98(void *);
extern void *func_8AC06D8C(void *, u32, ...);
extern void MainPool_FinalizeAllocation(s32);
extern s32 MainPool_AllocState(s32, s32);
extern s32 main_pool_get_available();
extern s32 func_8004DC6C(s32);
extern s32 func_8004DCFC(s32, s32);
extern void *func_8004EB58(s32, s32);
extern s32 func_80040E80(s32, void *);
extern s32 TextLabel_DrawCallback(s32, u8 *);
extern s32 func_8AC00270(s32, u8 *);
extern s32 func_8AC0444C(s32, u8 *);
extern s32 func_8AC0456C(s32, u8 *);
extern s32 func_8AB05A6C(s32, u8 *);
extern s32 func_8AC03D24(s32, u8 *);



void *func_8AB05B88(void) {
    s32 temp_v0;
    void **var_s0;
    void *a2;
    void *a3;
    void **ap = &D_8AB167AC;
    u8 *p;

    _bzero(D_8AB12CB0, 0x250);
    temp_v0 = func_8004DC6C(0xE0);
    func_8004DCFC(temp_v0, 0);
    var_s0 = (void **)MainPool_AllocState(main_pool_get_available(), 0);
    D_8AB167A0 = func_8004EB58((s32)var_s0, temp_v0);
    D_8AB16A14 = func_80040E80((s32)var_s0, &D_8AB1124C);
    MainPool_FinalizeAllocation((s32)var_s0);
    func_8AC06E98(D_8AB167A0);
    *(u16 *)((u8 *)D_8AB167A0 + 2) |= 1;
    *(u16 *)((u8 *)D_8AB167A0 + 2) |= 2;
    D_8AB167A4 = func_8AC06D8C(D_8AB167A0, 0x6A6F6231);
    D_8AB167A8 = func_8AC06D8C(D_8AB167A0, 0x6A6F6232);
    func_8004E308(func_8AC06D8C(D_8AB167A0, 0x6579655F), func_8AC00270, NULL);
    D_8AB167AC = func_8AC06D8C(D_8AB167A0, 0x6D6F6E64);
    func_8004E308(D_8AB167AC, TextLabel_DrawCallback, &D_8AB167B0);
    func_8AB00B98((u8 *)D_8AB167AC, -1U);
    D_8AB11D00 = func_8AC06D8C(D_8AB167A0, 0x6D657373);
    *(u16 *)((u8 *)D_8AB11D00 + 2) &= 0xFFFE;
    func_8004E308(D_8AB11D00, TextLabel_DrawCallback, D_8AB126A8);
    func_8AB00B98((u8 *)D_8AB11D00, -1U);
    D_8AB168B0 = func_8AC06D8C(D_8AB167A0, 0x70696331);
    D_8AB168B4 = func_8AC06D8C(D_8AB167A0, 0x70696332);
    D_8AB168B8 = func_8AC06D8C(D_8AB167A0, 0x70696333);
    D_8AB168BC = func_8AC06D8C(D_8AB167A0, 0x70696334);
    D_8AB168C0 = func_8AC06D8C(D_8AB167A0, 0x70636E31);
    D_8AB168C4 = func_8AC06D8C(D_8AB167A0, 0x70636E32);
    D_8AB168C8 = func_8AC06D8C(D_8AB167A0, 0x70636E33);
    D_8AB168CC = func_8AC06D8C(D_8AB167A0, 0x70636E34);
    D_8AB16964 = func_8AC06D8C(D_8AB167A0, 0x676F6F6F);
    D_8AB16954 = func_8AC06D8C(D_8AB167A0, 0x63646E62);
    func_8004E308(D_8AB16954, func_8AB05A6C, NULL);
    D_8AB1695C = func_8AC06D8C(D_8AB167A0, 0x666B6931);
    *(u16 *)((u8 *)D_8AB1695C + 2) &= 0xFFFD;
    D_8AB16960 = func_8AC06D8C(D_8AB167A0, 0x666B6932, &D_8AB1695C);
    D_8AB16A08 = func_8AC06D8C(D_8AB167A0, 0x57503030);
    D_8AB16A0C = func_8AC06D8C(D_8AB167A0, 0x57503031);
    D_8AB16A10 = func_8AC06D8C(D_8AB167A0, 0x57503032);
    *(u16 *)((u8 *)D_8AB16960 + 2) |= 2;
    a2 = D_8AB16A0C;
    *(u16 *)((u8 *)a2 + 2) |= 2;
    a3 = D_8AB16A10;
    *(u16 *)((u8 *)a3 + 2) |= 2;
    D_8AB16968 = func_8AC06D8C(D_8AB167A0, 0x7175736E, a2, a3);
    *(u16 *)((u8 *)D_8AB16968 + 2) &= 0xFFFD;
    D_8AB169F8 = func_8AC06D8C(D_8AB167A0, 0x73656E31, &D_8AB16968);
    func_8004E308(D_8AB169F8, func_8AC0444C, NULL);
    D_8AB169FC = func_8AC06D8C(D_8AB167A0, 0x73656E32);
    D_8AB16A00 = func_8AC06D8C(D_8AB167A0, 0x73656E33);
    D_8AB16A04 = func_8AC06D8C(D_8AB167A0, 0x73656E34);
    var_s0 = &D_8AB169FC; do {
        func_8004E308(*var_s0, func_8AC0456C, NULL);
        var_s0++;
    } while (var_s0 != &D_8AB16A08);
    D_8AB16970 = func_8AC06D8C(D_8AB167A0, 0x6D6F6A30);
    *(s32 *)((u8 *)D_8AB16970 + 0x2C) = 0xFF;
    *(s32 *)((u8 *)D_8AB16970 + 0x30) = 0xFF;
    D_8AB16974 = func_8AC06D8C(D_8AB167A0, 0x6D6F6A31);
    *(s32 *)((u8 *)D_8AB16974 + 0x2C) = 0xFF;
    *(s32 *)((u8 *)D_8AB16974 + 0x30) = 0xFF;
    switch ((u32)(*(u16 *)D_8AB11D0C)) {
    case 1:
        *(s16 *)((u8 *)D_8AB16974 + 0x26) = 1;
        break;
    case 2:
        *(s16 *)((u8 *)D_8AB16974 + 0x26) = 2;
        break;
    case 3:
        *(s16 *)((u8 *)D_8AB16974 + 0x26) = 3;
        break;
    }
    D_8AB168D0 = func_8AC06D8C(D_8AB167A0, 0x61627531);
    func_8AC05E40(D_8AB167A0, 0x61627531, D_8AB168D8);
    func_8AC06400(D_8AB168D8, D_8AB168D0);
    func_8AC00DF4(D_8AB167A0);
    D_8AB1696C = func_8AC06D8C(D_8AB167A0, 0x70617070);
    func_8004E308(D_8AB1696C, func_8AC03D24, NULL);
    *(s32 *)((u8 *)D_8AB1696C + 0x2C) = -0x2301;
    *(s32 *)((u8 *)D_8AB1696C + 0x30) = 0xFF;
    D_8AB16978 = func_8AC06D8C(D_8AB167A0, 0x73636F72);
    func_8AC05E40(D_8AB167A0, 0x73636F72, D_8AB16980);
    func_8AC06400(D_8AB16980, D_8AB16978);
    D_8AB169EC = 0xFF0000C8;
    *(u16 *)((u8 *)D_8AB16978 + 2) &= 0xFFFE;
    *(u16 *)((u8 *)D_8AB168B0 + 2) &= 0xFFFD;
    *(u16 *)((u8 *)D_8AB168B4 + 2) &= 0xFFFD;
    *(u16 *)((u8 *)D_8AB168B8 + 2) &= 0xFFFD;
    *(u16 *)((u8 *)D_8AB168BC + 2) &= 0xFFFD;
    *(u16 *)((u8 *)D_8AB168C0 + 2) &= 0xFFFD;
    *(u16 *)((u8 *)D_8AB168C4 + 2) &= 0xFFFD;
    *(u16 *)((u8 *)D_8AB168C8 + 2) &= 0xFFFD;
    *(u16 *)((u8 *)D_8AB168CC + 2) &= 0xFFFD;
    p = (u8 *)*ap;
    *(u16 *)(p + 2) &= 0xFFFE;
    p = (u8 *)*ap;
    *(u16 *)(p + 2) &= 0xFFFD;
    *(u16 *)((u8 *)D_8AB11D00 + 2) &= 0xFFFE;
    D_8AB12690 = 1;
    return D_8AB167A0;
}

extern u8 D_80088E50[];
void func_8AB06270(void *arg0, u16 arg1) {
    f32 *temp;
    f32 scale;
    f32 offset;
    arg1 <<= 12;
    temp = (f32 *)D_80088E50 + (arg1 >> 4);
    scale = 0.1f;
    offset = 1.4f;
    *(f32 *)((u8 *)arg0 + 0x40) = *temp * scale + offset;
    *(f32 *)((u8 *)arg0 + 0x44) = *temp * scale + offset;
}

s32 func_8AB062C4(s32 arg0) {
 switch (arg0) {
case 2: arg0 = func_8AB06650(1); break;
case 3: arg0 = func_8AB066B4(1); break;
case 4: arg0 = func_8AB06718(1); break;
case 5: arg0 = func_8AB0683C(1); break;
case 6: arg0 = func_8AB0699C(1); break;
case 7: arg0 = func_8AB06AE8(1); break;
case 8: arg0 = func_8AB06D78(1); break;
case 9: arg0 = func_8AB07128(1); break;
case 11: arg0 = func_8AB072EC(1); break;
case 10: arg0 = func_8AB072E4(1); break;
case 12: arg0 = func_8AB073F4(1); break;
case 13: arg0 = func_8AB07538(1); break;
case 14: arg0 = func_8AB07A34(1); break;
case 15: arg0 = func_8AB07C34(1); break;
case 16: arg0 = func_8AB07DC4(1); break;
case 17: arg0 = func_8AB07E6C(1); break;
case 18: arg0 = func_8AB07F80(1); break;
 }
 switch (arg0) {
 case 4:
   if (*(u16 *)((u8 *)D_80087200 + 8) & 0x4000) {
      func_8AB05A00();
      arg0 = func_8AB066B4(0);
      func_8AB00B78(3);
   }
   break;
 case 7: case 8:
   if (*(u16 *)((u8 *)D_80087200 + 8) & 0x4000) {
      func_8AB05A00();
      arg0 = func_8AB07F80(0);
      func_8AB00B78(3);
   }
   break;
 }
 func_8AB06270(D_8AB16980, D_8AB1268E);
 return arg0;
}

void func_8AB064C4(s32 arg0) {
    D_8AB16958 = arg0;
    func_8AC00F04(D_8AB11D08);
    func_800503A4(D_8AB167A0);
    switch (arg0) {
    case 2:
        func_8AB06650(2);
        return;
    case 3:
        func_8AB066B4(2);
        return;
    case 4:
        func_8AB06718(2);
        return;
    case 5:
        func_8AB0683C(2);
        return;
    case 6:
        func_8AB0699C(2);
        return;
    case 7:
        func_8AB06AE8(2);
        return;
    case 8:
        func_8AB06D78(2);
        return;
    case 9:
        func_8AB07128(2);
        return;
    case 11:
        func_8AB072EC(2);
        return;
    case 10:
        func_8AB072E4(2);
        return;
    case 12:
        func_8AB073F4(2);
        return;
    case 13:
        func_8AB07538(2);
        return;
    case 14:
        func_8AB07A34(2);
        return;
    case 15:
        func_8AB07C34(2);
        return;
    case 16:
        func_8AB07DC4(2);
        return;
    case 17:
        func_8AB07E6C(2);
        return;
    case 18:
        func_8AB07F80(2);
        return;
    }
}
extern s32 func_8AB06650(s32);
s32 func_8AB06630(void) {
    return func_8AB06650(0);
}

extern s32 StageContext_GetFadeMode(void);
extern void func_8AB04AE4(void);
extern s32 func_8AB06718(s32);
s32 func_8AB06650(s32 arg0) { s32 result = 2; switch (arg0) { case 0: func_8AB04AE4(); break; case 1: if (StageContext_GetFadeMode() == 0) result = func_8AB06718(0); break; } return result; }

extern s32 StageContext_GetFadeMode(void);
extern void StageFade_StartFromTransparent(s32);
s32 func_8AB066B4(s32 arg0) { s32 result = 3; switch (arg0) { case 0: StageFade_StartFromTransparent(5); break; case 1: if (StageContext_GetFadeMode() == 1) result = 0; break; } return result; }

extern void *D_8AB11D00;
extern u8 D_8AB126A8[];
extern void *D_8AB168D0;
extern u8 D_8AB168D8[];
extern void *D_8AB16978;
extern u8 D_8AB16980[];
extern u16 D_8AB1268E;
extern void *D_80087200;
extern void *func_8004C8A0(void *, s32, s32, s32);
extern void func_8AC06400(void *, void *);
extern void func_8AC063AC(void *, u16);
extern s32 func_8AB0683C(s32);
extern void func_8AB00B78(s32);
s32 func_8AB06718(s32 arg0) {
    s32 result = 4;
    s32 buttons;

    switch (arg0) {
    case 0:
        func_8004C8A0(D_8AB126A8, 256, 57, 361);
        *(u16 *)((u8 *)D_8AB11D00 + 2) |= 1;
        func_8AC06400(D_8AB168D8, D_8AB168D0);
        func_8AC06400(D_8AB16980, D_8AB16978);
        *(u16 *)((u8 *)D_8AB168D0 + 2) |= 1;
        break;
    case 1:
        func_8AC063AC(D_8AB168D8, D_8AB1268E);
        buttons = *(u16 *)((u8 *)D_80087200 + 8);
        if (buttons & 0x8000) {
            *(u16 *)((u8 *)D_8AB168D0 + 2) &= ~1;
            result = func_8AB0683C(0);
            func_8AB00B78(194);
        } else if (buttons & 0x4000) {
            func_8AB05A00();
            result = func_8AB066B4(0);
            func_8AB00B78(3);
        }
        break;
    }
    return result;
}

extern void *D_8AB16964;
extern u8 D_8AB126A8[];
extern s16 D_8AB16950;
extern s32 D_8AB16A14;
extern void func_87F005F0(f32, f32);
extern void *func_8004C8A0(void *, s32, s32, s32);
extern void func_87F006BC(void);
extern u32 func_87F006AC(void);
extern void func_8AB00BA4();
extern void func_80021ED8(s32);
extern s32 func_8AB0699C(s32);
extern void Geo_RenderRootNode(s32);
extern void func_800225C4(s32);
s32 func_8AB0683C(s32 arg0) {
    s32 result = 5;
    s16 temp_v0;
    switch (arg0) {
    case 0:
        func_87F005F0((f32)(*(s16 *)((u8 *)D_8AB16964 + 8) - 0x140), (f32)(0xF0 - *(s16 *)((u8 *)D_8AB16964 + 0xA)));
        func_8004C8A0(D_8AB126A8, 0x100, 0x39, 0x166);
        D_8AB16950 = 3;
        func_800225C4(0x5A);
        break;
    case 1:
        func_87F006BC();
        temp_v0 = func_87F006AC();
        switch (temp_v0) {
        case 1:
            func_8AB00BA4(0x64, D_8AB16950, 0);
            D_8AB16950 -= 1;
            break;
        case 2:
            func_8AB00BA4(0x64, D_8AB16950, 0);
            func_80021ED8(0x14);
            D_8AB16950 -= 1;
            break;
        case 3:
            result = func_8AB0699C(0);
            break;
        }
        break;
    case 2:
        Geo_RenderRootNode(D_8AB16A14);
        break;
    }
    return result;
}

extern s16 D_8AB12694;
extern void *D_8AB167AC;
extern s16 D_8AB16A1C;
extern void func_8004C594(s32, s32);
s32 func_8AB0699C(s32 arg0) {
    s32 result;
    s16 *counter;

    counter = &D_8AB16A1C;
    result = 6;
    switch (arg0) {
    case 0:
        func_8AB00BA4(0x10006, 0, 0);
        *counter = 0;
        if (D_8AB12694 > 0) {
            *(u16 *)((u8 *)D_8AB11D00 + 2) |= 1;
            func_8004C594(2, D_8AB12694 + 1);
            if (D_8AB12694 < 9) {
                func_8004C8A0(D_8AB126A8, 256, 57, func_8AB023EC(9) + 377);
            } else {
                func_8004C8A0(D_8AB126A8, 256, 57, 386);
            }
        } else {
            *(u16 *)((u8 *)D_8AB11D00 + 2) &= ~1;
        }
        func_8AB04AE4();
        *(u16 *)((u8 *)D_8AB167AC + 2) &= ~1;
        break;
    case 1:
        *counter += 1;
        if (*counter >= 45) {
            result = func_8AB06AE8(0);
        }
        break;
    }
    return result;
}

extern s16 D_8AB16A1E;
extern s16 D_8AB16A20;
extern u8 D_8AB167B0[];
extern void *D_8AB16968;
extern u8 *D_8AB12678[];
extern void *D_8AB167AC;
extern void *D_8AB11D00;
extern s16 D_8AB12694;
extern u32 D_8AB1268C;
extern s8 *D_8AB11264;
extern void *D_8AB16960;
extern void *D_8AB16A0C;
extern void *D_8AB16A10;
extern s32 HAL_Strcmp(const s8 *, const s8 *);
extern void TextChoice_ShuffleAndRefresh(void);
extern void _bzero(void *, s32);
extern void func_8004C594(s32, s32);
extern void func_8AB03394(void);
extern void func_8AB04AE4(void);
extern void func_8AB00BA4(s32, s32, s32);
extern s32 func_8AB06D78(s32);

// The walker's register colour depends on this fragment file's
// `extern void *func_8004C8A0(void *, s32, s32, s32);` declaration at line 86.
// With a void return type, func_8004C8A0's result temp does not occupy v0 and
// the case 1 walker's cursor and byte registers swap (13 rows).
// The return type is int, not s32, to agree with the implicit int prototype the
// caller func_8AB0699C uses at line 199 of the fragment file.


int func_8AB06AE8(s32 arg0) {
    s32 result = 7;
    s32 i;
    u8 *cursor;
    u8 *last;
    s16 *counter;
    s16 t;

    counter = &D_8AB16A1E;
    switch (arg0) {
    case 0:
        func_8AB03394();
        TextChoice_ShuffleAndRefresh();
        D_8AB16A20 = 0;
        // Line count reset: retail stores it as `addiu a2,zero,1` + `sh a2,%lo(D_8AB16A1E)`.
        // The value goes through the same s16 local as the case 1 loop bound, so one
        // register (a2) holds the count in both cases.
        t = D_8AB16A20 + 1;
        // The store sits in the argument list: as a separate statement IDO emits the
        // `sh` after `addiu a0,%lo(D_8AB167B0)`, the reverse of retail's order.
        _bzero(&D_8AB167B0, (D_8AB16A1E = t, 0x100));
        *(u16 *)((u8 *)D_8AB16968 + 2) |= 2;
        // D_8AB1267C/680/684 are the four consecutive slot pointers starting at
        // D_8AB12678; the loop keeps them in one ring in ugen.
        for (i = 0; i < 4; i++) {
            *(u16 *)(D_8AB12678[i] + 2) |= 1;
        }
        *(u16 *)((u8 *)D_8AB167AC + 2) |= 1;
        *(u16 *)((u8 *)D_8AB11D00 + 2) &= ~1;
        func_8AB04AE4();
        *(u16 *)((u8 *)D_8AB16960 + 2) |= 2;
        *(u16 *)((u8 *)D_8AB16A0C + 2) |= 2;
        *(u16 *)((u8 *)D_8AB16A10 + 2) |= 2;
        func_8004C594(2, D_8AB12694 + 1);
        break;
    case 1:
        func_8004C8A0(D_8AB167B0, 256, *(u16 *)((u8 *)D_8AB11D00 + 48), *(u16 *)((u8 *)D_8AB11D00 + 50));
        cursor = D_8AB167B0;
        t = D_8AB16A1E;
        for (i = 0; i < t; i++) {
            last = cursor;
            if (*cursor == 0) {
                D_8AB16A20 = 1;
                break;
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
            if (HAL_Strcmp((s8 *)last, D_8AB11264) == 0) {
                func_8AB00BA4(0x1000D, 0, 0);
            } else {
                func_8AB00BA4(0x1000C, 0, 0);
            }
            // Through the s16 local so the store keeps retail's `sll a2,a2,16` /
            // `sra a2,a2,16` truncation pair.
            t = *counter + 1;
            *counter = t;
        }
        if (D_8AB16A20 == 1) {
            result = func_8AB06D78(0);
        }
        break;
    case 2:
        break;
    }
    return result;
}

/* mkdraft:func_8AB06D78 begin */
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
/* mkdraft:func_8AB07F80 end */
#endif
extern u8 *D_8AB12668[];
extern s16 D_8AB1269A;
extern u8 D_8AB12CB0[];
extern u8 D_8AB12F00[];
extern void TextHighlight_AnimateScales(void);
extern void TextPanels_UpdateVisibility(void);
extern void TextRow_SetOrangeState(s16 row_index);
extern s32 func_80001FF0(void);
extern void func_8AB00B98(u8 *, u32);
extern void func_8AB01728(void);
extern void func_8AB03DFC(s16, s16);
extern void func_8AB04038(void);

s32 func_8AB07128(M2C_UNK);                         /* extern */
extern u8 *D_8AB1266C;
extern u8 *D_8AB12670;
extern u8 *D_8AB12674;
extern void *D_8AB16960;
extern void *D_8AB16A0C;
extern void *D_8AB16A10;
extern s32 D_8AB16A24;



s32 func_8AB06D78(s32 arg0) {
    u16 temp_v0;
    s32 sp20;
    s16 sp1E_arr[2];
    u8 *var_v0;
    u8 *end;
    s16 level;
    s32 changed;

    sp20 = 8;
    switch (arg0) {                                 /* irregular */
    case 2:
        break;
    case 0:
        TextPanels_UpdateVisibility();
        D_8AB1269C = 0x14;
        D_8AB16A24 = 0;
        M2C_FIELD(D_8AB16960, u16 *, 2) = (u16) (M2C_FIELD(D_8AB16960, u16 *, 2) & 0xFFFD);
        M2C_FIELD(D_8AB16A0C, u16 *, 2) = (u16) (M2C_FIELD(D_8AB16A0C, u16 *, 2) & 0xFFFD);
        M2C_FIELD(D_8AB16A10, u16 *, 2) = (u16) (M2C_FIELD(D_8AB16A10, u16 *, 2) & 0xFFFD);
        break;
    case 1:
        sp1E_arr[1] = 0;
        func_8AB01728();
        temp_v0 = M2C_FIELD(D_80087200, u16 *, 8);
        if (temp_v0 & 8) {
            if (D_8AB1269A == 0) {
                TextRow_SetOrangeState(0);
            } else {
                func_8AB03DFC(0, 0);
            }
            sp1E_arr[1] = 1;
            func_8AB00B98(*D_8AB12668, 0xFFFF00FFU);
        } else if (temp_v0 & 1) {
            if (D_8AB1269A == 1) {
                TextRow_SetOrangeState(0);
            } else {
                func_8AB03DFC(0, 1);
            }
            sp1E_arr[1] = 1;
            func_8AB00B98(D_8AB1266C, 0xFFFF00FFU);
        } else if (temp_v0 & 4) {
            if (D_8AB1269A == 2) {
                TextRow_SetOrangeState(0);
            } else {
                func_8AB03DFC(0, 2);
            }
            sp1E_arr[1] = 1;
            func_8AB00B98(D_8AB12670, 0xFFFF00FFU);
        } else if (temp_v0 & 2) {
            if (D_8AB1269A == 3) {
                TextRow_SetOrangeState(0);
            } else {
                func_8AB03DFC(0, 3);
            }
            sp1E_arr[1] = 1;
            func_8AB00B98(D_8AB12674, 0xFFFF00FFU);
        }
        TextHighlight_AnimateScales();
        func_8AB04038();
        if (((s32) D_8AB16A24 % (s32) (func_80001FF0() / 4)) == 0) {
            D_8AB1269C -= 1;
            if (D_8AB1269C < 0) {
                D_8AB1269C = 0;
                // FAKE: both assignments must share one source line, which ties the two
                // loop-preheader address chains in as1's line-number ordering; diff score 30
                // without it.
                var_v0 = D_8AB12CB0, end = D_8AB12F00;
                do {
                    if (M2C_FIELD(var_v0, s16 *, 4) == 0) {
                        M2C_FIELD(var_v0, s16 *, 4) = 2;
                    }
                    var_v0 += 148;
                } while (var_v0 != end);
                changed = (sp1E_arr[1] == 0);
                sp1E_arr[1] = 1;
                if (changed) {
                    func_8AB00BA4(0x65, 0, 0);
                }
            }
        }
        if (((s32) D_8AB16A24 % (s32) ((func_80001FF0() / 4) * 2)) == 0) {
            level = D_8AB1269C / 2 + 1;
            if (sp1E_arr[1] == 0) {
                func_8AB00BA4(0x65, level, 0);
            }
        }
        if (sp1E_arr[1] == 1) {
            sp20 = func_8AB07128(0);
        }
        D_8AB16A24 += 1;
        break;
    }
    return sp20;
}
/* mkdraft:func_8AB06D78 end */

/* mkdraft:func_8AB07128 begin */
extern s16 D_8AB11210[][3];
extern u8 D_8AB12CB0[];
extern u8 *D_8AB12CC4;
extern u8 *D_8AB12D58;
extern u8 *D_8AB12DEC;
extern u8 *D_8AB12E80;
extern void *D_8AB16960;
extern void *D_8AB16A0C;
extern void *D_8AB16A10;
extern s16 D_8AB16A28;
extern s16 D_8AB12694;
extern void func_8AB00BA4();
extern s32 func_8AB072EC(s32 arg0);
extern void TextHighlight_AnimateScales(void);


s32 func_8AB07128(s32 arg0) {
    s16 *counter = &D_8AB16A28;
    s32 result = 9;
    u8 **ptr;

    switch (arg0) {
    case 0:
        *counter = 0;
        ptr = &D_8AB12CC4;
        if (*ptr != NULL) {
            *(u16 *)(*ptr + 2) |= 1;
        }
        ptr = &D_8AB12D58;
        if (*ptr != NULL) {
            *(u16 *)(*ptr + 2) |= 1;
        }
        ptr = &D_8AB12DEC;
        if (*ptr != NULL) {
            *(u16 *)(*ptr + 2) |= 1;
        }
        ptr = &D_8AB12E80;
        if (*ptr != NULL) {
            *(u16 *)(*ptr + 2) |= 1;
        }
        if (*(s16 *)(D_8AB12CB0 + 4) == 1U) {
            *(s32 *)(D_8AB12CB0 + 0x84) = 0xFF500080;
            *(s16 *)(D_8AB12CB0 + 0x3E) = 0;
        } else {
            *(s32 *)(D_8AB12CB0 + 0x84) = 0x1E82FF80;
            *(s16 *)(D_8AB12CB0 + 0x3E) = 1;
        }
        // 10-row history of 6-byte rows; each row's first field stores the mode read above.
        D_8AB11210[D_8AB12694 % 10][0] = *(s16 *)(D_8AB12CB0 + 4);
        *(u16 *)((u8 *)D_8AB16960 + 2) |= 2;
        ptr = &D_8AB16A0C;
        *(u16 *)(*ptr + 2) |= 2;
        ptr = &D_8AB16A10;
        *(u16 *)(*ptr + 2) |= 2;
        break;
    case 1:
        *counter += 1;
        TextHighlight_AnimateScales();
        if (*counter == 15) {
            func_8AB00BA4(102, 0, 0);
        }
        if (*counter >= 31) {
            result = func_8AB072EC(0);
        }
        break;
    case 2:
        break;
    }
    return result;
}
/* mkdraft:func_8AB07128 end */

s32 func_8AB072E4(void) {
    return 0xA;
}

extern s16 D_8AB16A2A;
extern u8 *D_8AB12668[];
extern u8 *D_8AB12678[];
extern u16 D_8AB1269E;
extern s16 D_8AB12694;
extern s32 func_8AB073F4(s32);
extern void func_8AB00B98(u8 *, u32);
extern void func_8AB01FBC(void);
extern void func_8AB03ED4(void);
extern s32 func_8AB0699C(s32);
s32 func_8AB072EC(s32 arg0)
{
    s32 result;
    u8 **ptr;
    u8 **end;
    s16 step;

    step = 1;
    result = 0xB;
    switch (arg0) {
        case 0:
            D_8AB16A2A = 0;
            func_8AB01FBC();
            break;
        case 1:
            D_8AB16A2A += step;
            func_8AB03ED4();
            end = D_8AB12678;
            if (D_8AB16A2A >= 0xB) {
                ptr = D_8AB12668;
                do {
                    func_8AB00B98(*ptr, -1U);
                    ptr++;
                } while (ptr != end);
                if (D_8AB1269E == 0) {
                    result = func_8AB0699C(0);
                } else {
                    D_8AB12694 += 1;
                    if (D_8AB12694 >= 0xA) {
                        result = func_8AB073F4(0);
                    } else {
                        result = func_8AB0699C(0);
                    }
                }
            }
            break;
    }
    return result;
}

extern s16 D_8AB16A2C;
extern void *D_8AB167AC;
extern void *D_8AB16968;
extern void TextHighlight_AnimateScales(void);
extern s32 func_8AB07538(s32);
s32 func_8AB073F4(s32 arg0) {
    s16 *counter = &D_8AB16A2C;
    s32 result = 12;
    s32 i;

    switch (arg0) {
    case 0:
        *counter = 0;
        *(u16 *)((u8 *)D_8AB11D00 + 2) |= 1;
        func_8AB04AE4();
        func_8004C8A0(D_8AB126A8, 256, 57, 389);
        *(u16 *)((u8 *)D_8AB167AC + 2) &= ~1;
        for (i = 0; i < 4; i++) {
            *(u16 *)(D_8AB12678[i] + 2) &= ~1;
        }
        *(u16 *)((u8 *)D_8AB16968 + 2) &= ~2;
        func_8AB00BA4(65550, 0, 0);
        func_800225C4(40);
        break;
    case 1:
        *counter += 1;
        TextHighlight_AnimateScales();
        if (*counter >= 61) {
            result = func_8AB07538(0);
        }
        break;
    }
    return result;
}

extern s16 D_8AB11210[][3];
extern void func_8AB00FF8(s16, s16);
extern void func_8AB01140(s16, s16);
s32 func_8AB07538(s32 arg0) {
    static s16 D_8AB169A6;
    // Loader-cleared state that other functions use by address (D_8AB16A1E,
    // D_8AB16A2A), kept so the two counters below stay at 0x8AB16A2E/30.
    // Split up because IDO 8-aligns .bss arrays of 8 bytes or more.
    static s16 D_8AB169A8;
    static s16 D_8AB169AA;
    static s16 D_8AB169AC;
    static u8 D_8AB169AE[0x80];
    static s16 D_8AB16A2E;
    static s16 D_8AB16A30;
    s32 i;
    s32 result;
    s32 val;

    result = 0xD;
    val = *(s16 *)(D_8AB12CB0 + 2);
    switch (arg0) {
    case 0:
        D_8AB16A2E = 0;
        D_8AB16A30 = 0;
        func_8AB00BA4(0x1000F, 0, 0);
        func_8004C8A0(D_8AB126A8, 0x100, 0x39, 0x184);
        switch (val) {
        case 0:
            D_8AB169A6 = 0;
            break;
        case 10:
            D_8AB169A6 = 1;
            break;
        default:
            D_8AB169A6 = val + 1;
            break;
        }
        if (*(s16 *)(D_8AB12CB0 + 2) >= 8) {
            for (i = 0; i < 10; i++) {
                ((s8 *)D_8AB11D0C)[i + 4] = -1;
            }
        } else {
            D_8AB11D0C[0x16] = D_8AB11D0C[3];
            for (i = 0; i < 10; i++) {
                if (D_8AB11210[i % 10][0] == 1) {
                    ((s8 *)D_8AB11D0C)[i + 4] = -1;
                }
            }
        }
        break;
    case 1:
        D_8AB16A2E++;
        if (D_8AB16A2E % 15 == 0) {
            D_8AB16A30 = D_8AB16A2E / 15;
            if (D_8AB16A30 < 10) {
                func_8AB00BA4(0x10011, 0, 0);
            } else if (D_8AB16A30 == 10) {
                func_8AB00BA4(0x10010, 0, 0);
                *(u16 *)((u8 *)D_8AB16978 + 2) |= 1;
            }
            if (D_8AB16A30 > 10) {
                D_8AB16A30 = 10;
            }
        }
        if (D_8AB16A2E > 0xB4) {
            if (*(s16 *)(D_8AB12CB0 + 2) >= 8) {
                result = func_8AB07A34(0);
            } else {
                result = func_8AB07DC4(0);
            }
        }
        break;
    case 2:
        for (i = 0; i < D_8AB16A30; i++) {
            if (D_8AB11210[i % 10][0] == 1) {
                func_8AB00FF8(D_8AB11210[i % 10][1], D_8AB11210[i % 10][2]);
            } else {
                func_8AB01140(D_8AB11210[i % 10][1], D_8AB11210[i % 10][2]);
            }
        }
        break;
    }
    return result;
}

/* mkdraft:func_8AB07A34 begin */
extern u8 D_8AB11268[];
extern u8 D_8AB1126C[];
extern u8 D_8AB126A8[];
extern int func_8AB023EC();
extern void func_80021ED8(s32);
extern void func_800226C0(s32);
extern void *func_8004C8A0(void *, s32, s32, s32);
extern void func_800545B4(s32, s32);
extern s32 func_8AB07C34(s32);
extern s32 func_8AC07AF4(s32, s32, u8 *, u8 *);
extern void func_8AC075A8(void);



s32 func_8AB07A34(s32 arg0) {
    static s16 D_8AB16A32;
    s32 result = 0xE;
    s16 x;
    s16 value;
    s16 *counter = &D_8AB16A32;
    u8 color[3];
    s32 count = 3;
    typedef struct { u8 a, b, c; } Color;

    switch (arg0) {
    case 0:
        func_8004C8A0(D_8AB126A8, (*(volatile s16 *)counter = 0) + 0x100, 0x39, 9); // FAKE: volatile store-in-argument reproduces retail's lui a0 / lui at / sh / addiu a0 order
        func_80021ED8(0x4A);
        switch (*(u16 *)D_8AB11D0C) {
        case 1:
            func_800545B4(3, 1);
            break;
        case 2:
            func_800545B4(4, 1);
            break;
        case 3:
            func_800545B4(5, 1);
            break;
        }
        break;
    case 1:
        value = *counter + 1;
        *counter = value;
        if (value >= 0x97) {
            result = func_8AB07C34(0);
        }
        value = *counter;
        if (value % 5 == 0) {
            *counter = value;
            if (value < 0x78) {
                *(Color *)color = *(Color *)(D_8AB1126C + (guRandom() % count) * count);
                x = func_8AB023EC(0x50) - 0x28;
                if (func_8AC07AF4(x + 0x122, (s16)(func_8AB023EC(0x3C) - 0x1E) + 0xD2, D_8AB11268, color) != 0) {
                    func_800226C0(0xCF);
                }
            }
        }
        break;
    case 2:
        func_8AC075A8();
        break;
    }
    return result;
}
/* mkdraft:func_8AB07A34 end */

/* mkdraft:func_8AB07C34 begin */
s32 func_8AB066B4(s32 arg0);
u8 func_8005453C(s32);
extern u8 D_8AB126A8[];
extern void *D_8AB168D0;
extern u8 D_8AB168D8[];
extern u16 D_8AB1268E;
extern void *D_80087200;
extern void *func_8004C8A0(void *, s32, s32, s32);
extern void func_8AC06400(void *, void *);
extern void func_8AC063AC(void *, u16);
extern void func_8AB00B78(s32);
extern void func_80021ED8(s32);
s32 func_8AB07C34(s32 arg0) {
    static s16 timer;
    s32 result = 0xF;
    s32 elapsed;
    s32 message;
    void *node;

    switch (arg0) {
    case 0:
        timer = 0;
        if (func_8005453C(2) == 1 && func_8005453C(5) == 1) {
            message = 0xE;
        } else if (func_8005453C(5) == 1) {
            message = 0xD;
        } else if (func_8005453C(1) == 1 && func_8005453C(4) == 1) {
            message = 0xC;
        } else {
            message = 0xB;
        }
        func_8004C8A0(D_8AB126A8, 0x100, 0x39, message);
        func_8AC06400(D_8AB168D8, D_8AB168D0);
        func_80021ED8(7);
        break;
    case 1:
        timer += 1;
        elapsed = timer;
        if (elapsed >= 31) {
            *(u16 *)((u8 *)D_8AB168D0 + 2) |= 1;
            timer = 30;
            func_8AC063AC(D_8AB168D8, D_8AB1268E);
            if (*(u16 *)((u8 *)D_80087200 + 8) & 0x8000) {
                node = D_8AB168D0;
                *(u16 *)((u8 *)node + 2) &= 0xFFFE;
                result = func_8AB066B4(0);
                func_8AB00B78(0xC2);
            }
        }
        break;
    }
    return result;
}
/* mkdraft:func_8AB07C34 end */

extern s32 func_80025D44(void);
extern s32 func_8AB07E6C(s32);
extern void func_80021ED8(s32);
extern void *func_8004C8A0(void *, s32, s32, s32);
extern u8 D_8AB126A8[];
s32 func_8AB07DC4(s32 arg0)
{
    static s16 timer;
    s32 result;
    int new_var;
    new_var = 1;
    result = 0x10;
    switch (arg0)
    {
        case 0:
            timer = 0;
            func_8004C8A0(D_8AB126A8, 0x100, 0x39, 0x183);
            func_80021ED8(0x4B);
            break;
        case 1:
            timer += new_var;
            if ((((u32) func_80025D44()) < 2U) && (timer >= 0x3D))
            {
                result = func_8AB07E6C(0);
            }
            break;
    }
    return result;
}

/* mkdraft:func_8AB07E6C begin */
extern u8 D_8AB126A8[];
extern void *D_8AB168D0;
extern u8 D_8AB168D8[];
extern u16 D_8AB1268E;
extern void *D_80087200;
extern void *func_8004C8A0(void *, s32, s32, s32);
extern void func_8AC06400(void *, void *);
extern void func_8AC063AC(void *, u16);
extern void func_8AB00B78(s32);
extern void func_80021ED8(s32);

s32 func_8AB066B4(s32 arg0);
s32 func_8AB07E6C(s32 arg0) {
    static s16 timer;
    s32 result = 0x11;
    s32 elapsed;
    void *node;

    switch (arg0) {
    case 0:
        timer = 0;
        func_8004C8A0(D_8AB126A8, 0x100, 0x39, 6);
        func_8AC06400(D_8AB168D8, D_8AB168D0);
        func_80021ED8(7);
        break;
    case 1:
        timer += 1;
        elapsed = timer;
        if (elapsed >= 31) {
            *(u16 *)((u8 *)D_8AB168D0 + 2) |= 1;
            timer = 30;
            func_8AC063AC(D_8AB168D8, D_8AB1268E);
            if (*(u16 *)((u8 *)D_80087200 + 8) & 0x8000) {
                node = D_8AB168D0;
                *(u16 *)((u8 *)node + 2) &= 0xFFFE;
                result = func_8AB066B4(0);
                func_8AB00B78(0xC2);
            }
        }
        break;
    }
    return result;
}
/* mkdraft:func_8AB07E6C end */

/* mkdraft:func_8AB07F80 begin */
extern void *D_8AB16960;
extern void *D_8AB16A0C;
extern void *D_8AB16A10;
extern s16 D_8AB16A3A;
extern void func_8AB00BA4(s32, s32, s32);



s32 func_8AB07F80(s32 arg0) {
    s16 *D_8AB16A3A_ptr = &D_8AB16A3A;
    s32 result;
    void *ptr;

    result = 0x12;
    switch (arg0) {
    case 0:
        (*D_8AB16A3A_ptr) = 0;
        func_8AB05A00();
        *(u16 *)((u8 *)D_8AB167AC + 2) &= 0xFFFE;
        func_8004C8A0(D_8AB126A8, 0x100, 0x3A, 0x24);
        *(u16 *)((u8 *)D_8AB11D00 + 2) |= 1;
        func_8AB04AE4();
        *(u16 *)((u8 *)D_8AB16960 + 2) |= 2;
        *(u16 *)((u8 *)D_8AB16A0C + 2) |= 2;
        ptr = D_8AB16A10;
        *(u16 *)((u8 *)ptr + 2) |= 2;
        func_8AB00BA4(0x66, 0, 0);
        func_80021ED8(7);
        break;
    case 1:
        (*D_8AB16A3A_ptr) += 1;
        if ((*D_8AB16A3A_ptr) >= 0x1F) {
            (*D_8AB16A3A_ptr) = 0x1E;
            result = func_8AB066B4(0);
        }
        break;
    }
    return result;
}
/* mkdraft:func_8AB07F80 end */
#endif
