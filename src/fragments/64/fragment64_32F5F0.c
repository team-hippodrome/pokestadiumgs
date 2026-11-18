#include "global.h"


#ifdef VERSION_US
extern u8 *D_87F15B90;
extern u8 D_87F15B98[];
extern void func_8004C8C0(s32);
void func_87F0C980(void) {
    D_87F15B90 = D_87F15B98;
    *(s32 *)(D_87F15B90 + 0) = 0;
    *(s32 *)(D_87F15B90 + 4) = 0;
    *(s32 *)(D_87F15B90 + 0x10) = 0;
    *(s32 *)(D_87F15B90 + 0x14) = 0;
    func_8004C8C0(0x1B9);
}

extern u32 func_8003570C(void);
void func_87F0C9D0(s32 arg0) {
    if (*(s32 *)(D_87F15B90 + 0x10) != 0 && arg0 == 0) {
        (*(s32 *)(D_87F15B90 + 0))++;
        *(s32 *)(D_87F15B90 + 4) = func_8003570C() % 100;
    }
}

void func_87F0CA30(void) {
    *(s32 *)(D_87F15B90 + 0) = 0;
    *(s32 *)(D_87F15B90 + 4) = 0;
    *(s32 *)(D_87F15B90 + 0x10) = 1;
}

void func_87F0CA58(void) {
    *(s32 *)(D_87F15B90 + 0x10) = 0;
}

extern u8 D_87F112B0[];
void func_87F0CA68(s32 arg0, void *arg1, u8 *arg2) {
    if (arg0 >= 100) {
        arg0 %= 100;
    }
    func_8004D19C(arg1, arg2, func_8004C990(441, D_87F112B0[arg0 / 10]), 0, 0);
    func_8004D19C((u8 *)arg1 + 10, arg2, func_8004C990(441, D_87F112B0[arg0 % 10]), 0, 0);
}

void func_87F0CB24(void) {
    *(s32 *)(D_87F15B90 + 0x14) = 1;
    *(f32 *)(D_87F15B90 + 8) = 320.0f;
    *(f32 *)(D_87F15B90 + 0xC) = 0.0f;
}

void func_87F0CB58(void) {
    *(s32 *)(D_87F15B90 + 0x14) = 0;
}

extern f64 D_87F11730;

extern f64 D_87F11738;

extern Gfx D_80094E38[];

extern Gfx D_80094F50[];

extern Gfx *D_800D0510;

void func_87F0CB68(void) {
    f64 time;
    s32 pad[3]; // FAKE: preserves the renderer stack layout.
    f32 step;
    f32 magnitude;
    s32 icon_y;
    s32 icon_x;
    s32 pad2[1]; // FAKE: preserves the coordinate spill offsets.
    s32 x;
    s32 y;
    s32 seconds;
    if ((*( s32 *)(D_87F15B90 + 20))) {
        s32 rate=func_80001FF0();
        f64 maximum=D_87F11730;
        time=((f64)(*( u32 *)(D_87F15B90 + 4)) + (f64)(*( u32 *)(D_87F15B90 + 0))*100.0)/(rate*0.5);
        if (time>maximum) time=maximum;
        step=(0.0f-(*( f32 *)(D_87F15B90 + 8)))*0.25f;
        magnitude=step>0.0f ? step : -step;
        if(magnitude<0.5f) step=0.0f;
        (*( f32 *)(D_87F15B90 + 8))+=step;
        step=(0.0f-(*( f32 *)(D_87F15B90 + 12)))*0.25f;
        magnitude=step>0.0f ? step : -step;
        if(magnitude<0.5f) step=0.0f;
        (*( f32 *)(D_87F15B90 + 12))+=step;
        gSPDisplayList(D_800D0510++,D_80094E38);
        if ((*( f32 *)(D_87F15B90 + 8))>=0.0f) x=(s32)((*( f32 *)(D_87F15B90 + 8))+0.5f);
        else x=(s32)((*( f32 *)(D_87F15B90 + 8))-0.5f);
        if ((*( f32 *)(D_87F15B90 + 12))>=0.0f) y=(s32)((*( f32 *)(D_87F15B90 + 12))+0.5f);
        else y=(s32)((*( f32 *)(D_87F15B90 + 12))-0.5f);
        seconds=time*D_87F11738;
        func_87F0CA68(seconds/60,(void *)(x+121),(u8 *)(y+164));
        if ((*( f32 *)(D_87F15B90 + 8))>=0.0f) x=(s32)((*( f32 *)(D_87F15B90 + 8))+0.5f);
        else x=(s32)((*( f32 *)(D_87F15B90 + 8))-0.5f);
        if ((*( f32 *)(D_87F15B90 + 12))>=0.0f) y=(s32)((*( f32 *)(D_87F15B90 + 12))+0.5f);
        else y=(s32)((*( f32 *)(D_87F15B90 + 12))-0.5f);
        func_87F0CA68(seconds%60,(void *)(x+149),(u8 *)(y+164));
        if (time>=0.0f) icon_x=(s32)(time+(f64)0.5f);
        else icon_x=(s32)(time-(f64)0.5f);
        if ((*( f32 *)(D_87F15B90 + 8))>=0.0f) x=(s32)((*( f32 *)(D_87F15B90 + 8))+0.5f);
        else x=(s32)((*( f32 *)(D_87F15B90 + 8))-0.5f);
        if ((*( f32 *)(D_87F15B90 + 12))>=0.0f) y=(s32)((*( f32 *)(D_87F15B90 + 12))+0.5f);
        else y=(s32)((*( f32 *)(D_87F15B90 + 12))-0.5f);
        func_87F0CA68(icon_x%100,(void *)(x+178),(u8 *)(y+164));
        if ((*( f32 *)(D_87F15B90 + 8))>=0.0f) icon_x=(s32)((*( f32 *)(D_87F15B90 + 8))+0.5f);
        else icon_x=(s32)((*( f32 *)(D_87F15B90 + 8))-0.5f);
        if ((*( f32 *)(D_87F15B90 + 12))>=0.0f) icon_y=(s32)((*( f32 *)(D_87F15B90 + 12))+0.5f);
        else icon_y=(s32)((*( f32 *)(D_87F15B90 + 12))-0.5f);
        func_8004D19C(icon_x+142,icon_y+164,func_8004C990(441,10),0,0);
        if ((*( f32 *)(D_87F15B90 + 8))>=0.0f) icon_x=(s32)((*( f32 *)(D_87F15B90 + 8))+0.5f);
        else icon_x=(s32)((*( f32 *)(D_87F15B90 + 8))-0.5f);
        if ((*( f32 *)(D_87F15B90 + 12))>=0.0f) icon_y=(s32)((*( f32 *)(D_87F15B90 + 12))+0.5f);
        else icon_y=(s32)((*( f32 *)(D_87F15B90 + 12))-0.5f);
        func_8004D19C(icon_x+171,icon_y+164,func_8004C990(441,11),0,0);
        if ((*( f32 *)(D_87F15B90 + 8))>=0.0f) icon_x=(s32)((*( f32 *)(D_87F15B90 + 8))+0.5f);
        else icon_x=(s32)((*( f32 *)(D_87F15B90 + 8))-0.5f);
        if ((*( f32 *)(D_87F15B90 + 12))>=0.0f) icon_y=(s32)((*( f32 *)(D_87F15B90 + 12))+0.5f);
        else icon_y=(s32)((*( f32 *)(D_87F15B90 + 12))-0.5f);
        func_8004D19C(icon_x+96,icon_y+147,func_8004C990(441,12),0,0);
        gSPDisplayList(D_800D0510++,D_80094F50);
    }
}
#endif
