#include "229E0.h"

#ifdef VERSION_US

extern s32 D_80090B94;
extern s32 D_80090B98;
extern s32 func_800265B0(u32 arg0, s32 arg1);

extern s8 D_800901BC[];
extern void func_80025294();
// Passes 0x66 or 0x65 to func_80025294 for arg0 0 or 1. For arg0 340 it reads
// entry arg1 (0-61) of the signed table D_800901BC and, when the entry is not
// negative, passes entry + 0x1000D.
void func_80023110(s32 arg0, s32 arg1) {
    s32 sound;

    switch (arg0) {
        case 0:
            func_80025294(0x66);
            return;
        case 1:
            func_80025294(0x65);
            return;
        case 340:
            if ((arg1 >= 0) && (arg1 < 62)) {
                sound = D_800901BC[arg1];
                if (sound >= 0) {
                    func_80025294(sound + 0x1000D, 0, 0);
                }
            }
            return;
    }
}

#endif
