#include "global.h"


#ifdef VERSION_US
typedef struct {
    s32 words[3];
} Fragment51Vec3;
extern u8 *D_863075D8;
extern s32 func_80001FF0(void);
extern void func_87F0455C(void);
extern void func_87F04314(s32, s32, s32, void *, s32, s32, s32, s32, s32, void *, void *, void *);
extern char D_86307510[];
extern char D_8630751C[];
extern char D_86307528[];
extern char D_86307534[];
extern u8 D_86306F28[];
extern u8 D_86306F2C[];
extern u8 D_86306F38[];
extern u8 D_86306F3C[];
extern u8 D_86306F40[];
extern u8 D_86306F44[];
typedef struct {
    /* 0x0000 */ u8 unk_0000[0x8F34];
    /* 0x8F34 */ f32 ballSpeed;
    /* 0x8F38 */ f32 smashDecay;
    /* 0x8F3C */ Fragment51Vec3 unk_8F3C;
    /* 0x8F48 */ s32 goalScore;
    /* 0x8F4C */ s32 time;
    /* 0x8F50 */ u8 unk_8F50;
} Fragment51SettingsState;
void func_86303C00(Fragment51Vec3 *arg0) {
    ((Fragment51SettingsState *)D_863075D8)->ballSpeed = 4.0f;
    ((Fragment51SettingsState *)D_863075D8)->smashDecay = 1.0f;
    ((Fragment51SettingsState *)D_863075D8)->goalScore = 5;
    ((Fragment51SettingsState *)D_863075D8)->unk_8F3C = *arg0;
    ((Fragment51SettingsState *)D_863075D8)->unk_8F50 = 2;
    ((Fragment51SettingsState *)D_863075D8)->time = (func_80001FF0() >> 1) * 60;
    func_87F0455C();
    func_87F04314(0, 0, 0, D_86307510, 12, 0, 6, 5, 0, &((Fragment51SettingsState *)D_863075D8)->time, D_86306F28, D_86306F2C);
    func_87F04314(0, 0, 1, D_8630751C, 12, 1, 6, 2, 0, &((Fragment51SettingsState *)D_863075D8)->goalScore, D_86306F28, D_86306F2C);
    func_87F04314(0, 0, 2, D_86307528, 12, 2, 10, 2, 4, &((Fragment51SettingsState *)D_863075D8)->ballSpeed, D_86306F3C, D_86306F38);
    func_87F04314(0, 0, 3, D_86307534, 12, 3, 10, 1, 4, &((Fragment51SettingsState *)D_863075D8)->smashDecay, D_86306F44, D_86306F40);
}

extern u8 *D_863075D8;
typedef struct unk_func_86303E54 {
    u8 unk_00[0x8F51];
    u8 unk_8F51_flag : 1;
} unk_func_86303E54;

extern void *D_80087208;
extern void func_87F04894(void);
void func_86303E54(void) {
    if (*(u16 *)((u8 *)D_80087208 + 8) & 0x10) {
        // karodo: both arms clear the same controller bit.
        if (((unk_func_86303E54 *)D_863075D8)->unk_8F51_flag ^= 1) {
            *(u16 *)((u8 *)D_80087208 + 0x10) &= 0xFFFE;
        } else {
            *(u16 *)((u8 *)D_80087208 + 0x10) &= 0xFFFE;
        }
    }
    if (((unk_func_86303E54 *)D_863075D8)->unk_8F51_flag) {
        func_87F04894();
    }
}

extern u8 *D_863075D8;
extern Gfx *D_800D0510;
extern void func_87F05204(Gfx **);
extern void func_87F09040(void);
void func_86303F00(void) {
    if ((u32)D_863075D8[0x8F51] >> 7) {
        func_87F05204(&D_800D0510);
        func_87F09040();
    }
}
#pragma C_FUNCTION_PADDING(8)
#endif
