#include "global.h"


#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_279A20/func_86303C00.s")

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
