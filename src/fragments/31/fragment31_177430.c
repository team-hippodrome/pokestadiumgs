#include "global.h"


#ifdef VERSION_US
typedef struct {
    s16 x;
    s16 unk_02;
    s16 y;
    s16 unk_06;
    s16 unk_08;
    s16 unk_0A;
    struct {
        s32 enabled;
    } mask;
    u8 unk_10[0xA];
    s16 width;
    u8 unk_1C[8];
    s32 unk_24;
    s32 unk_28;
    s32 state;
} F31Panel;

extern void func_800226C0(s32);
extern F31Panel D_88234680[];

void func_882041B0(void) {
    (*(s32 *)((u8 *)(&D_88234680) + (0x2C))) = (s32) (*(s32 *)((u8 *)(&D_88234680) + (0x28)));
    func_800226C0(0x132);
}

extern s32 D_882346AC;
void func_882041E0(void) {
    D_882346AC = 2;
}

typedef struct { s32 a, b; } Pair8_882041F0;
typedef struct {
    s16 x, y, w, h;
    s16 unk8;
    s16 unkA;
    s32 unkC;
    u8 *unk10;
    u8 unk14[4];
    u8 unk18;
    u8 pad19;
    s16 unk1A;
    u8 pad1C[0xC];
    s32 unk28;
    s32 unk2C;
} F31Menu;
extern s32 func_80001FF0(void);
extern s32 func_8800005C(void);
extern u8 D_88006020[];
extern u8 D_8823468C;
extern u8 *D_88234568[];
extern u8 *D_882346D0[];
extern s16 D_882346C8;
extern u16 D_882346CA;
extern s32 func_88002958(u8 **, u16, s32, s16);
extern s32 func_8004C874(s32, s32);

void func_882041F0(void) {
    // Four bytes at 0x88234694 that menu->unk10 points at; as a function-scope
    // static the four clears share one lui.
    static struct { u8 r, g, b, a; } D_88234694;
    s32 pad; // FAKE: count spills at 0x28
    s32 count;
    s32 i;

    ((F31Menu *)&D_88234680)->unk2C = 0;
    ((F31Menu *)&D_88234680)->unk8 = 0;
    ((F31Menu *)&D_88234680)->x = 0x44;
    ((F31Menu *)&D_88234680)->w = 0x138;
    ((F31Menu *)&D_88234680)->y = (600.0f / func_80001FF0()) + ((600.0f / func_80001FF0()) > 0.0f ? 0.5f : -0.5f);
    ((F31Menu *)&D_88234680)->h = (3000.0f / func_80001FF0()) + ((3000.0f / func_80001FF0()) > 0.0f ? 0.5f : -0.5f);
    if (func_8800005C() != 0) {
        D_88234694.g = 0;
        D_88234694.b = 0;
        D_88234694.a = 0;
        D_88234694.r = 0;
        ((F31Menu *)&D_88234680)->unk18 = 1;
        ((F31Menu *)&D_88234680)->unkC = 1;
        ((F31Menu *)&D_88234680)->unk10 = (u8 *)&D_88234694;
        count = 4;
    } else {
        *(Pair8_882041F0 *)&D_8823468C = *(Pair8_882041F0 *)D_88006020;
        count = 5;
    }
    ((F31Menu *)&D_88234680)->unk1A = func_88002958(D_88234568, 5, 0x10, 1);
    for (i = 0; i < 5; i++) {
        D_882346D0[i] = (u8 *)func_8004C874(0x1F, i + 6);
    }
    D_882346CA = func_88002958(D_882346D0, count, 8, 1) + 0x21;
    D_882346C8 = 0x24C - D_882346CA;
}

extern void func_88000288(void *, s16, s16, s16, u8, u8, u8, u8);
extern s32 func_80001FF0(void);
extern void func_88200134();
extern void func_88002720(void *, u16, void *);
extern void func_88003A00(s32);
extern void func_882000AC(u8, s16, s16, u16, u16, s32, s32, u8);
extern void D_88000E4C(void);
extern void func_88216544(void);
extern void func_88208174(void);
extern void func_882105B0(void);
extern void func_8820C258(void);
extern void func_88213530(void);
extern void func_882041E0(void);
extern void Input_SetRepeatController(s32);
extern void Util_Free(void *);
extern void main_pool_pop_state(s32);
extern s32 D_80087200;
extern s32 D_88234560;
extern s32 D_88234564;
extern u8 D_882346B0;
extern u8 D_882346BC;
extern s16 D_882346C8;
extern u16 D_882346CA;
extern u8 D_88234688;
extern u8 D_8823468C;

// k frames at 60 fps, scaled to the current frame rate and rounded half away from zero.
#define FPS_ROUND(k) ((f32)(k) * func_80001FF0() / 60.0f + ((func_80001FF0() * (f32)(k) / 60.0f > 0.0f) ? 0.5f : -0.5f))
#define P ((u8 *)&D_88234680)
#define S16(o) (*(s16 *)(P + (o)))
#define S32(o) (*(s32 *)(P + (o)))

void func_88204400(void) {
    switch (S32(0x2C)) {
    case 0:
        S32(0x2C) = 1;
        S16(0) = S16(0) - S16(0) % S16(2);
        func_800226C0(0x12F);
        break;
    case 1:
        S16(0) = S16(0) - S16(2);
        if (S16(0) <= 0) {
            S16(0) = 0;
            S32(0x2C) = 2;
            S16(4) = S16(4) - S16(4) % S16(6);
            func_800226C0(0x130);
        }
        break;
    case 2:
        S16(4) = S16(4) - S16(6);
        if (S16(4) <= 0) {
            S16(4) = 0;
            S32(0x2C) = 3;
            Input_SetRepeatController(D_80087200);
            func_882000AC(0, D_882346C8, 0x141, D_882346CA, 0x60, (s32)D_88000E4C, (s32)func_882041B0, 0);
            func_88000288(&D_882346B0,
                          (s16)((s32)FPS_ROUND(13) + (s32)FPS_ROUND(10) + (s32)FPS_ROUND(5)), 0xFF, 0,
                          (s32)FPS_ROUND(13), (s32)FPS_ROUND(10), (s32)FPS_ROUND(5), (s32)FPS_ROUND(7));
            func_88000288(&D_882346BC,
                          (s16)((s32)FPS_ROUND(20) + (s32)FPS_ROUND(15) + (s32)FPS_ROUND(8)), 0x96, 0x32,
                          (s32)FPS_ROUND(20), (s32)FPS_ROUND(15), (s32)FPS_ROUND(8), (s32)FPS_ROUND(11));
        }
        break;
    case 3: {
        if (((s32 *)D_88234564)[7] == 2) {
            if (*(u16 *)((u8 *)D_80087200 + 8) & 0x8000) {
                func_800226C0(0x133);
                switch (*(u16 *)(P + 8)) {
                case 0:
                    S32(0x24) = 0;
                    S32(0x1C) = (s32)func_88216544;
                    break;
                case 1:
                    S32(0x24) = 1;
                    S32(0x1C) = (s32)func_88208174;
                    break;
                case 2:
                    S32(0x24) = 2;
                    S32(0x1C) = (s32)func_882105B0;
                    break;
                case 3:
                    S32(0x24) = 3;
                    S32(0x1C) = (s32)func_8820C258;
                    break;
                case 4:
                    S32(0x24) = 4;
                    S32(0x1C) = (s32)func_88213530;
                    break;
                }
                S32(0x28) = 6;
                func_88200134(0, 0);
            } else if (*(u16 *)((u8 *)D_80087200 + 8) & 0x4000) {
                func_800226C0(0x56);
                S32(0x24) = 6;
                S32(0x1C) = (s32)D_88000E4C;
                S32(0x28) = 7;
                func_88200134(0, 0);
                S16(6) = (s32)(2880.0f / func_80001FF0() + ((2880.0f / func_80001FF0() > 0.0f) ? 0.5f : -0.5f));
            } else {
                func_88002720(&D_88234688, 5, &D_8823468C);
            }
        }
        func_88003A00(D_88234564);
        break;
    }
    case 4:
        *(u8 *)(P + 0x20) -= 1;
        if (*(u8 *)(P + 0x20) == 0) {
            D_88234560 = S32(0x24);
            Util_Free((void *)D_88234564);
            main_pool_pop_state(0x50435345);
            ((void (*)(void))S32(0x1C))();
            S32(0x2C) = 5;
        }
        break;
    case 5:
        func_882041E0();
        break;
    case 6:
        S16(4) = S16(6) + S16(4);
        if (S16(4) >= 0xF5) {
            S16(4) = 0xF5;
            S32(0x2C) = 4;
            *(u8 *)(P + 0x20) = 2;
        }
        break;
    case 7:
        S16(4) = S16(6) + S16(4);
        if (S16(4) >= 0x138) {
            S16(4) = 0x138;
            S32(0x2C) = 8;
            func_800226C0(0x131);
        }
        break;
    case 8:
        S16(0) = S16(2) + S16(0);
        if (S16(0) >= 0x44) {
            S16(0) = 0x44;
            Util_Free((void *)D_88234564);
            main_pool_pop_state(0x50435345);
            D_88234560 = S32(0x24);
            ((void (*)(void))S32(0x1C))();
            S32(0x2C) = 0;
        }
        break;
    }
}
#undef FPS_ROUND
#undef P
#undef S16
#undef S32

extern void func_80044424(s16, s16, s16, s16, s16, s16, s16, s16, s32, s32);



void func_88205114(s32 arg0, s32 arg1) {
    func_80044424((s16)(arg0 - 7), 0, 8, (s16)(arg1 - 7), 0x100, 0xA0, 0x400, 0, 0, 1);
    func_80044424((s16)(arg0 - 7), (s16)(arg1 - 7), 8, 8, 0x300, 0, 0x400, 0x400, 0, 1);
    func_80044424(0, (s16)(arg1 - 7), (s16)(arg0 - 7), 8, 0x2E0, 0, 0, 0x400, 0, 1);
}

/* mkdraft:func_88205200 begin */
extern void func_80044424(s16 x, s16 y, s16 width, s16 height, s16 s, s16 t, s16 dsdx, s16 dtdy, s32 cycle, s32 tile);

// Both parameters are s32: the target loads arg1 from its incoming-argument home
// slot as a word (lw 0x3c(sp)) and narrows the result with sll/sra, and it also
// reloads arg0 as a word (lw 0x38(sp)) for the last quad's x/width arithmetic.
// Declaring either parameter s16 turns that reload into lh from the home word.


void func_88205200(s32 arg0, s32 arg1) {
    func_80044424((s16)arg0, 0, 5, (s16)(arg1 - 7), 0, 160, 1024, 0, 0, 1);
    func_80044424((s16)arg0, (s16)(arg1 - 7), 5, 8, 512, 0, 1024, 1024, 0, 1);
    func_80044424((s16)(arg0 + 5), (s16)(arg1 - 7), (s16)(0x27B - arg0), 8, 736, 0, 0, 1024, 0, 1);
}
/* mkdraft:func_88205200 end */

extern Gfx *D_800D0510;
extern Gfx D_80094E38[];
extern Gfx D_80094E00[];
extern Gfx D_80094F50[];
extern Gfx D_88233790[];
extern void *D_8800ECC4;
extern void *D_8800ECC0;
extern u8 D_8800686C;
extern u8 D_8800686D[];
extern u16 D_8800686A;
extern void *D_8800687C;
extern u16 D_88233770[];
extern u8 D_88233780[];
extern void *D_88234588[];
extern s32 func_8004D1FC(void *);
extern s32 func_8004D27C(void *, s32, s32);
extern void *func_88000578(void *, u8);
extern void func_88002C2C(u8, u8, u8);
extern s32 func_8004CA10(void *);
extern void GfxRect_DrawTextured(s16, s16, s16, s16, s32, s32, s32, s32, s32);
extern void func_88002BA0(u8, u8, u8);
extern void func_88200180(u8);
extern void func_88000808(u8, s16, s16, s32, s32);
extern void func_800498C4(void);
extern void func_800496A4(s32, s32);
extern s32 func_80048E30(void *, s32, s32, void *, s32);
extern s32 func_80049668(s32);
extern void func_8004989C(s32);
extern void func_8004972C(s32, s32, s32, s32);
extern void func_800495F8(s32, s32, s32, const char *, ...);
extern s16 Envelope_Advance(void *);
extern void func_80049064(s32, s32, s32, s32);
extern void func_800499EC(void);
extern void func_8004B314(s32, s32, s32, s32);
void func_882052F8(void) {
    s32 i,y;
    struct {u8 r,g,b;} color;
    s32 alpha;
    if(D_88234680[0].state==0) return;
    gSPDisplayList(D_800D0510++,D_80094E38);
    gDPSetAlphaCompare(D_800D0510++,G_AC_NONE);
    func_8004D1FC(D_8800ECC4);
    func_8004D27C(D_8800ECC0,128,1);
    func_88000578(&color,D_8800686C);
    func_88002C2C(color.r,color.g,color.b);
    if(D_88234680[0].state!=3) {
        GfxRect_DrawTextured(0,0,385,60-D_88234680[0].x,0,0,
            (s32)((1024.0f*func_8004CA10(D_8800ECC4)/385.0f)+(1024.0f*func_8004CA10(D_8800ECC4)/385.0f>0.0f?0.5f:-0.5f)),0,0);
    }
    gDPPipeSync(D_800D0510++);
    gDPSetEnvColor(D_800D0510++,220,150,255,255);
    GfxRect_DrawTextured(393,0,247,304-D_88234680[0].y,0,0,
        (s32)((1024.0f*func_8004CA10(D_8800ECC4)/247.0f)+(1024.0f*func_8004CA10(D_8800ECC4)/247.0f>0.0f?0.5f:-0.5f)),0,0);
    if(D_88234680[0].state==3 && *(s32 *)(D_88234564+28)==2) {
        gDPPipeSync(D_800D0510++);
        gDPSetEnvColor(D_800D0510++,220,220,180,255);
        GfxRect_DrawTextured(D_882346C8+5,326,(u16)D_882346CA-13,83,0,0,
            (s32)((1024.0f*func_8004CA10(D_8800ECC4)/((u16)D_882346CA-13))+(1024.0f*func_8004CA10(D_8800ECC4)/((u16)D_882346CA-13)>0.0f?0.5f:-0.5f)),0,0);
    }
    func_88002BA0(220,220,180);
    func_88200180(0);
    if(D_88234680[0].state!=3) {
        gDPPipeSync(D_800D0510++);
        gDPSetEnvColor(D_800D0510++,color.r,color.g,color.b,255);
        func_88205114(392,67-D_88234680[0].x);
    }
    gDPPipeSync(D_800D0510++);
    gDPSetEnvColor(D_800D0510++,220,150,255,255);
    func_88205200(388,311-D_88234680[0].y);
    if(D_88234680[0].state!=3) {
        gSPDisplayList(D_800D0510++,D_80094E00);
        func_88000808(D_8800686D[-1],54,34-D_88234680[0].x,0,0x200000);
    }
    gSPDisplayList(D_800D0510++,D_80094F50);
    func_800498C4();
    func_800496A4(8,2);
    if(D_88234680[0].state!=3) func_80048E30(D_8800687C,82,35-D_88234680[0].x,D_8800686D,1);
    if(D_88234680[0].state==3 && *(s32 *)(D_88234564+28)==2) {
        func_80049668(1);
        func_8004989C(26);
        func_80048E30(D_8800687C,D_882346C8+15,332,D_882346D0[D_88234680[0].unk_08],1);
    }
    switch(D_88234680[0].state) {
    case 4:
        switch(D_88234680[0].unk_24) {
        case 0:case 1:case 2:case 3:case 4:
            func_80049668(1);
            func_80048E30(D_8800687C,403,35,D_88234568[D_88234680[0].unk_24],1);break;
        }
        break;
    case 5:
        switch(D_88234560) {
        case 0:case 1:case 2:case 3:case 4:
            func_80049668(1);
            func_80048E30(D_8800687C,403,35,D_88234568[D_88234560],1);break;
        }
        break;
    case 2:case 3:case 6:case 7:
        func_800496A4(16,1);
        for(i=0,y=141-D_88234680[0].y;i!=5;i++,y+=32) {
            if(i==4 && D_88234680[0].mask.enabled==1) func_8004972C(255,255,255,100);
            if(D_88234680[0].y<245 && (i==D_88234680[0].unk_08 || (D_88234680[0].state!=6 &&
                !(D_88234680[0].state==3 && D_88234680[0].unk_28==6 && *(s32 *)(D_88234564+28)==3)))) {
                if(y<35) func_80048E30(D_8800687C,403,35,D_88234568[i],1);
                else func_80048E30(D_8800687C,403,y,D_88234568[i],1);
            }
            if(i==4 && D_88234680[0].mask.enabled==1) func_8004972C(255,255,255,255);
        }
        break;
    }
    if(D_88234680[0].state!=3) {
        func_800496A4(4,2);
        func_800495F8(374,39-D_88234680[0].x,2,"%s %05d",func_8004C874(13,9),D_8800686A);
    }
    if(D_88234680[0].state==3 && *(s32 *)(D_88234564+28)==2) {
        func_800496A4(8,2);
        func_8004972C(255,255,255,Envelope_Advance(&D_882346B0));
        func_80049064(382,207,2,func_8004C874(31,0));
    }
    func_800499EC();
    if(D_88234680[0].state==3 && *(s32 *)(D_88234564+28)==2) {
        alpha=Envelope_Advance(&D_882346BC);
        gSPDisplayList(D_800D0510++,D_88233790);
        for(i=0;i<4;i++) {
            func_8004D1FC(D_88234588[i]);
            gDPPipeSync(D_800D0510++);
            gDPSetEnvColor(D_800D0510++,0,0,0,alpha);
            GfxRect_DrawTextured(D_88233770[i*2]+2,D_88233770[i*2+1]+2,((s16 *)D_88234588[i])[0],((s16 *)D_88234588[i])[1],-16,-16,1024,1024,0);
            gDPPipeSync(D_800D0510++);
            gDPSetEnvColor(D_800D0510++,D_88233780[i*3],D_88233780[i*3+1],D_88233780[i*3+2],alpha);
            GfxRect_DrawTextured(((s16 *)D_88233770)[i*2],((s16 *)D_88233770)[i*2+1],((s16 *)D_88234588[i])[0],((s16 *)D_88234588[i])[1],-16,-16,1024,1024,0);
        }
        func_8004B314(395,D_88234680[0].unk_08*32-D_88234680[0].y+135,(u16)D_88234680[0].width+16,36);
    }
}
s32 func_88205D7C(void) {
    return (D_882346AC == 3) ? 1 : 0;
}
#endif
