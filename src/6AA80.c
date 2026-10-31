#include "global.h"


#ifdef VERSION_US
extern void main_pool_push_state(s32);
extern void main_pool_pop_state(s32);
extern void func_800355E4(s32);
extern void Fragment_Load(s32, void *, void *);
extern s32 Fragment_LoadAndCall(s32, void *, void *, u32, u32);
extern s32 Game_SetState(s32);
extern u8 D_88000000;
extern u8 D_88B00000;
extern u8 fragment29_ROM_START;
extern u8 fragment30_ROM_START;
extern u8 fragment40_ROM_START;
extern u8 fragment41_ROM_START;
void func_80069E80(void) {
    main_pool_push_state(0x70727374);
    func_800355E4(0x44);
    Fragment_Load(((u32) ((s32) &D_88000000 & 0x0FF00000) >> 20) - 0x10, &fragment29_ROM_START, &fragment30_ROM_START);
    Fragment_LoadAndCall(((u32) ((s32) &D_88B00000 & 0x0FF00000) >> 20) - 0x10, &fragment40_ROM_START, &fragment41_ROM_START, 0, 0);
    main_pool_pop_state(0x70727374);
    Game_SetState(2);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/6AA80/func_80069F20.s")

extern void *func_80069F20();
void *BattleScene_ResetParticipantModelFlags(s32 arg0) {
    return func_80069F20(arg0, 0, 0);
}

extern void *func_80069F20(void); void func_8006A160(void) { func_80069F20(); }

extern s32 D_8009DF70;
extern void _bzero(void *, s32);
void func_8006A180(void) {
    u8 *ptr;
    if (D_8009DF70 != 0) {
        ptr = *(u8 **)((u8 *)(u32)D_8009DF70 + 0x24);
        if (ptr != NULL) {
            _bzero(ptr, 0x958);
            *(s8 *)(*(u8 **)((u8 *)(u32)D_8009DF70 + 0x24) + 0x93C) = -1;
            *(s8 *)(*(u8 **)((u8 *)(u32)D_8009DF70 + 0x24) + 0x93D) = -1;
            *(s8 *)(*(u8 **)((u8 *)(u32)D_8009DF70 + 0x24) + 0x93E) = -1;
            *(s8 *)(*(u8 **)((u8 *)(u32)D_8009DF70 + 0x24) + 0x93F) = -1;
        }
    }
}

extern void *main_pool_alloc(s32, s32);
typedef struct NodeA1FC { s32 pad0; s32 next; s32 value; } NodeA1FC;
NodeA1FC *func_8006A1FC(s32 arg0) {
    NodeA1FC *result = NULL;
    if (D_8009DF70 != 0) {
        result = main_pool_alloc(0xC, 0);
        if (result != NULL) {
            _bzero(result, 0xC);
            result->next = *(s32 *)((u8 *)(u32)D_8009DF70 + 0x1C);
            result->value = arg0;
            *(NodeA1FC **)((u8 *)(u32)D_8009DF70 + 0x30) = result;
        }
    }
    return result;
}

typedef struct InitA278 { u8 pad0[4]; s16 value4; s16 value6; s16 value8; } InitA278;
InitA278 *func_8006A278(void) {
    InitA278 *result = NULL;
    if (D_8009DF70 != 0) {
        result = main_pool_alloc(0x50, 0);
        if (result != NULL) {
            *(InitA278 **)((u8 *)(u32)D_8009DF70 + 0x34) = result;
            _bzero(result, 0x50);
            result->value4 = 1;
            result->value6 = 0xF;
            result->value8 = 0x1E;
        }
    }
    return result;
}

extern s32 D_8009DF70; void func_8006A2EC(void) { D_8009DF70 = 0; }

extern s32 D_8009DF70; s32 func_8006A2F8(u16 value){s32 result=0; s32 ptr=D_8009DF70; if(ptr!=0){*(u16 *)((u8 *)(u32)ptr+4)|=value; result=1;} return result;}

extern s32 D_8009DF70; s32 func_8006A328(u16 value){s32 result=0; s32 ptr=D_8009DF70; if(ptr!=0){*(u16 *)((u8 *)(u32)ptr+4)&=~value; result=1;} return result;}

s32 func_8006A35C(u16 value) { s32 result = 0; if (D_8009DF70 != 0) result = ((*(u16 *)((u8 *)(u32)D_8009DF70 + 4) & value) != 0); return result; }

s32 func_8006A388(void) { s32 result = 0; if (D_8009DF70 != 0 && (*(u16 *)((u8 *)(u32)D_8009DF70 + 4) & 1) != 0) result = 1; return result; }

s32 func_8006A3B8(u16 arg0) { s32 result = 0; if (D_8009DF70 != 0) { *(u16 *)((u8 *)(u32)D_8009DF70) = arg0; result = 1; } return result; }

s32 func_8006A3E0(void) { s32 result = 0xFFFF; if (D_8009DF70 != 0) result = *(u16 *)((u8 *)(u32)D_8009DF70); return result; }

s32 func_8006A400(s32 value) { s32 result = 0; if (D_8009DF70 != 0) { *(s16 *)((u8 *)(u32)D_8009DF70 + 2) = value; result = 1; } return result; }

s32 func_8006A424(void) { s32 result = 0; s32 ptr = D_8009DF70; if (ptr != 0) result = *(s16 *)((u8 *)(u32)ptr + 2); return result; }

s32 func_8006A444(s32 value) { s32 result = 0; if (D_8009DF70 != 0) { *(s16 *)((u8 *)(u32)D_8009DF70 + 6) = value; _bzero((u8 *)(u32)D_8009DF70 + 0x3C, 0x44); result = 1; } return result; }

s32 func_8006A48C(void) { s32 result = -1; s32 ptr = D_8009DF70; if (ptr != 0) result = *(s16 *)((u8 *)(u32)ptr + 6); return result; }

typedef struct CopyA4AC { s32 words[17]; } CopyA4AC;
s32 func_8006A4AC(void *arg0) {
    s32 result = 0;
    if ((D_8009DF70 != 0) && (arg0 != NULL)) {
        *(s16 *)((u8 *)(u32)D_8009DF70 + 6) = 0xE;
        *(CopyA4AC *)((u8 *)(u32)D_8009DF70 + 0x3C) = *(CopyA4AC *)arg0;
        result = 1;
    }
    return result;
}

/* mkdraft:func_8006A51C begin */
s32 func_8006A51C(s32 arg0) {
    s32 result = 0;
    switch (arg0) {
    case 0:
        result = 9;
        break;
    case 1:
        result = 4;
        break;
    case 2:
        result = 5;
        break;
    case 3:
        result = 6;
        break;
    case 4:
        result = 7;
        break;
    case 5:
        result = 16;
        break;
    case 8:
        result = 1;
        break;
    case 9:
        result = 2;
        break;
    case 10:
        result = 3;
        break;
    case 11:
        result = 15;
        break;
    case 12:
        result = 8;
        break;
    case 13:
        result = 8;
        break;
    case 14:
        result = 17;
        break;
    }
    return result;
}
/* mkdraft:func_8006A51C end */

s32 func_8006A5AC(s32 arg0) {
    s32 result = -1;
    switch (arg0) {
    case 1: result = 0; break;
    case 2: result = 1; break;
    case 3: result = 2; break;
    case 4: result = 3; break;
    }
    return result;
}

extern s32 D_8009DF78[];
extern s32 D_8009DF88[];
extern s32 func_8006A5AC(s32);
s32 func_8006A600(u16 code, s32 arg1, s32 arg2) {
    s32 result = -1;
    s32 index;

    switch (code & 0xFF00) {
    case 0x000:
    case 0x100:
    case 0x200:
        switch (code & 0xFF) {
        case 0:
            result = 0;
            break;
        case 1:
            index = func_8006A5AC(arg1);
            if (index >= 0) {
                result = D_8009DF78[index];
            }
            break;
        case 2:
            index = func_8006A5AC(arg1);
            if (index >= 0) {
                result = D_8009DF88[index];
            }
            break;
        case 3:
            if (arg2 != 0) {
                result = 13;
            } else {
                result = 12;
            }
            break;
        case 32:
            result = 5;
            break;
        case 16:
            result = 14;
            break;
        }
        break;
    case 0x300:
        result = 6;
        break;
    case 0x400:
        result = 12;
        break;
    case 0x500:
        if (arg2 != 0) {
            result = 13;
        } else {
            result = 12;
        }
        break;
    case 0x600:
        result = 11;
        break;
    }
    return result;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/6AA80/func_8006A73C.s")

extern s32 func_8006A73C(u16, s32, s32);
void func_8006AB68(s32 arg0, s32 arg1, s32 arg2) { s32 *p = &arg0; func_8006A73C(arg0 & 0xFFFF, arg1, arg2); }

s32 func_8006AB8C(u16 arg0, s32 arg1, s32 arg2) {
    s32 result = 0;
    s32 value;
    if (D_8009DF70 != 0) {
        value = func_8006A73C(arg0, arg1, arg2);
        *(s16 *)((u8 *)(u32)D_8009DF70 + 0x10) = value;
        result = 1;
    }
    return result;
}

s32 func_8006ABD8(void *arg0) {
    s32 var_v1;

    var_v1 = 0;
    if (D_8009DF70 != 0) {
        var_v1 = 1;
        (*(s8 *)((u8 *)(D_8009DF70) + (8))) = (s8) (*(s32 *)((u8 *)(arg0) + (0)));
        (*(s8 *)((u8 *)(D_8009DF70) + (9))) = (s8) (*(s32 *)((u8 *)(arg0) + (4)));
        (*(s8 *)((u8 *)(D_8009DF70) + (0xA))) = (s8) (*(s32 *)((u8 *)(arg0) + (8)));
        (*(s8 *)((u8 *)(D_8009DF70) + (0xB))) = (s8) (*(s32 *)((u8 *)(arg0) + (0xC)));
    }
    return var_v1;
}

s32 func_8006AC28(s32 value) { s32 result = 0; if (D_8009DF70 != 0) { *(s32 *)((u8 *)(u32)D_8009DF70 + 0xC) = value; result = 1; } return result; }

s32 func_8006AC4C(s32 value) { s32 result = 0; if (D_8009DF70 != 0) { *(s16 *)((u8 *)(u32)D_8009DF70 + 0x12) = value; result = 1; } return result; }

s32 func_8006AC70(void) { s32 result = -1; s32 ptr = D_8009DF70; if (ptr != 0) result = *(s16 *)((u8 *)(u32)ptr + 0x12); return result; }

extern s32 func_8006CBA0(s32, s32);
s32 func_8006AC90(void) { s32 result = 0; s32 ptr = D_8009DF70; if (ptr != 0) result = func_8006CBA0(*(s16 *)((u8 *)(u32)ptr + 0x12), *(s16 *)((u8 *)(u32)ptr + 0x16)); return result; }

s32 func_8006ACCC(s32 value) { s32 result = 0; if (D_8009DF70 != 0) { *(s16 *)((u8 *)(u32)D_8009DF70 + 0x16) = value; result = 1; } return result; }

s32 func_8006ACF0(void) { s32 result = 0; s32 ptr = D_8009DF70; if (ptr != 0) result = *(s16 *)((u8 *)(u32)ptr + 0x16); return result; }

/* mkdraft:func_8006AD10 begin */


s32 func_8006AD10(u16 code, s32 kind, s32 level) {
    s32 result = -1;
    // FAKE: `code` is already u16, so this mask is an arithmetic nop; it keeps a
    // zero-extended copy of `code` alive in a second register for the default
    // path's low-byte read below. Score as `s32 value = code;`: 460.
    s32 value = code & 0xFFFF;
    u16 group = code & 0xFF00;

    switch (group) {
    case 0x300:
        switch (kind - 5) {
        case 0:
            result = 0;
            break;
        case 1:
            result = 1;
            break;
        case 2:
            result = 2;
            break;
        case 3:
            result = 3;
            break;
        case 4:
            result = 5;
            break;
        case 5:
            result = 4;
            break;
        case 6:
            result = 8;
            break;
        case 7:
            result = 6;
            break;
        case 8:
            result = 7;
            break;
        case 9:
            if ((level >= 0) && (level < 4)) {
                result = level + 9;
            } else {
                result = 9;
            }
            break;
        case 10:
            result = 13;
            break;
        case 11:
            result = 14;
            break;
        case 12:
            result = 15;
            break;
        case 13:
            result = 18;
            break;
        case 14:
            result = 16;
            break;
        case 15:
            result = 17;
            break;
        case 16:
            result = 19;
            break;
        case 17:
            result = 20;
            break;
        case 18:
            result = 21;
            break;
        case 19:
            result = 22;
            break;
        }
        break;
    case 0x400:
        result = 27;
        break;
    case 0x500:
        result = 28;
        break;
    case 0x600:
        result = 29;
        break;
    default:
        result = value & 0xFF;
        switch (result) {
        case 0:
            result = 23;
            break;
        case 1:
            result = 25;
            break;
        case 2:
            result = 24;
            break;
        case 3:
            result = 26;
            break;
        default:
            result = 28;
            break;
        }
        break;
    }
    return result;
}
/* mkdraft:func_8006AD10 end */

s32 func_8006AE90(s32 value) { s32 result = 0; if (D_8009DF70 != 0) { *(s16 *)((u8 *)(u32)D_8009DF70 + 0x14) = value; result = 1; } return result; }

s32 func_8006AEB4(void) { s32 result = -1; s32 ptr = D_8009DF70; if (ptr != 0) result = *(s16 *)((u8 *)(u32)ptr + 0x14); return result; }

typedef struct U4A { u8 bytes[4]; } U4A;
s32 func_8006AED4(s32 arg0, void *arg1) {
    s32 base;
    s32 result = 0;
    if (D_8009DF70 != 0) {
        base = (s32)*(s32 *)((u8 *)(u32)D_8009DF70 + 0x1C);
        if (base != 0) {
            *(U4A *)((u8 *)(u32)base + arg0 * 0x4E0 + 0x498) = *(U4A *)arg1;
            result = 1;
        }
    }
    return result;
}

typedef struct U4F { u8 bytes[4]; } U4F;
s32 func_8006AF28(s32 arg0, void *arg1) {
    s32 base;
    s32 result = 0;
    u8 *dst;
    if (D_8009DF70 != 0) {
        base = (s32)*(s32 *)((u8 *)(u32)D_8009DF70 + 0x1C);
        if (base != 0) {
            dst = (u8 *)(u32)base + arg0 * 0x4E0;
            *(U4F *)(dst + 0x498) = *(U4F *)arg1;
            dst[0x11] = 1;
            result = 1;
        }
    }
    return result;
}


s32 func_8006AF84(void) {
    return *(s32 *)((u8 *)(u32)D_8009DF70 + 0x1C);
}

s32 func_8006AF94(void) { s32 result = -1; s32 ptr = D_8009DF70; if (ptr != 0) result = *(s16 *)((u8 *)(u32)ptr + 0x10); return result; }

s32 func_8006AFB4(s32 arg0) {
    s32 result;
    s32 value = 1;
    if ((arg0 != 0x45) && (arg0 != 0x46) && (arg0 != 0x47)) {
        result = 0;
    } else {
        result = value;
    }
    return result;
}

void func_8006AFE4(s8 *arg0, s8 *arg1) {
    s32 found = 0;
    s32 i = 0;
    s8 *ptr = arg0;
    s8 value;
    do {
        i++;
        *ptr = -2;
        ptr++;
    } while (i < 4);
    i = 0;
    ptr = arg1;
    do {
        value = *ptr;
        i++;
        if (value >= 0) {
            arg0[value] = value;
        } else if (value == -1) {
            found = 1;
        }
        ptr++;
    } while (i < 4);
    i = 0;
    if (found != 0) {
        ptr = arg0;
loop:
        i++;
        if (*ptr == -2) {
            *ptr = -1;
            return;
        }
        ptr++;
        if (i != 4) goto loop;
    }
}

s32 func_8006B07C(s8 *arg0) {
    s32 result = -1;
    s32 sentinel = -1;
    s32 i = 0;
    for (i = 0; i < 4; i++) {
        if (*(s8 *)((u8 *)arg0 + i) == sentinel) {
            result = i;
            break;
        }
    }
    return result;
}

typedef struct unk_D_8009DF70_58 {
    s32 unk_00[22];
} unk_D_8009DF70_58;

typedef struct unk_D_8009DF70_60 {
    unk_D_8009DF70_58 unk_00;
    u8 unk_58[8];
} unk_D_8009DF70_60;

typedef struct unk_D_8009DF70_0C {
    s32 unk_00[3];
} unk_D_8009DF70_0C;

// Destination block: four slots of six entries, the slot map built by func_8006AFE4 and one
// 12-byte record per slot.
typedef struct unk_D_8009DF70_24 {
    unk_D_8009DF70_60 unk_000[4][6];
    s8 unk_900[4];
    unk_D_8009DF70_0C unk_904[4];
} unk_D_8009DF70_24;

// Source block: four groups of six entries and one 12-byte record per group, indexed like unk_08.
typedef struct unk_D_8009DF70_2C {
    u8 unk_00[144];
    unk_D_8009DF70_58 unk_90[4][6];
    unk_D_8009DF70_0C unk_8D0[4];
} unk_D_8009DF70_2C;

typedef struct unk_D_8009DF70 {
    u8 unk_00[8];
    s8 unk_08[4];
    u8 unk_0C[24];
    unk_D_8009DF70_24 *unk_24;
    u8 unk_28[4];
    unk_D_8009DF70_2C *unk_2C;
} unk_D_8009DF70;

extern void _bcopy(void *, void *, s32);

// For each of the four unk_08 entries, copies source group i (its 12-byte record and its six
// 0x58-byte entries) from unk_2C into the unk_24 slot that unk_08[i] names; -1 selects the slot
// func_8006B07C reports as free, and other negative values skip the group. Returns 1 when
// D_8009DF70 is set, else 0.
s32 func_8006B0B8(void) {
    s32 result = 0;
    s32 free_slot;
    s32 i;
    s32 j;
    s32 slot;

    // D_8009DF70 is declared s32 for this file's offset-based accessors. Comparing it as a
    // pointer is needed for the match (s32 compare: diff score 385).
    if ((unk_D_8009DF70 *)D_8009DF70 != NULL) {
        result = 1;
        func_8006AFE4(((unk_D_8009DF70 *)D_8009DF70)->unk_24->unk_900, ((unk_D_8009DF70 *)D_8009DF70)->unk_08);
        free_slot = func_8006B07C(((unk_D_8009DF70 *)D_8009DF70)->unk_24->unk_900);
        for (i = 0; i < 4; i++) {
            slot = ((unk_D_8009DF70 *)D_8009DF70)->unk_08[i];
            if (slot == -1) {
                slot = free_slot;
            }
            if (slot >= 0) {
                _bcopy(&((unk_D_8009DF70 *)D_8009DF70)->unk_2C->unk_8D0[i],
                       &((unk_D_8009DF70 *)D_8009DF70)->unk_24->unk_904[slot], 12);
                for (j = 0; j < 6; j++) {
                    ((unk_D_8009DF70 *)D_8009DF70)->unk_24->unk_000[slot][j].unk_00 =
                        ((unk_D_8009DF70 *)D_8009DF70)->unk_2C->unk_90[i][j];
                }
            }
        }
    }
    return result;
}


#pragma GLOBAL_ASM("asm/us/nonmatchings/6AA80/func_8006B428.s")

s32 func_8006B790(s32 value) { s32 result = 0; if (D_8009DF70 != 0) { *(u8 *)((u8 *)(u32)D_8009DF70 + 0x1A) = value; result = 1; } return result; }

s32 func_8006B7B4(s32 value) { s32 result = 0; if (D_8009DF70 != 0) { *(u8 *)((u8 *)(u32)D_8009DF70 + 0x1B) = value; result = 1; } return result; }

s32 func_8006B7D8(s32 value) { s32 result = 0; if (D_8009DF70 != 0) { *(s16 *)((u8 *)(u32)D_8009DF70 + 0x18) = value; result = 1; } return result; }

s32 func_8006B7FC(s32 arg0) {
    s32 var_v1;

    var_v1 = 0xFFFF;
    switch (arg0) {
        case 0:
            var_v1 = 544;
            break;
        case 1:
            var_v1 = 0;
            break;
        case 2:
            var_v1 = 1;
            break;
        case 3:
            var_v1 = 3;
            break;
        case 4:
            var_v1 = 768;
            break;
        case 5:
            var_v1 = 1536;
            break;
    }

    return var_v1;
}

s32 func_8006B854(s32 arg0, s32 arg1) {
    s32 high;
    s32 low;
    s32 result;

    high = arg0 & 0xFF00;
    result = -1;
    switch (high) {
    case 0x200:
        low = arg0 & 0xFF;
        if (arg1 == 5) {
            result = 0;
        } else {
            switch (low) {
            case 0:
                result = 1;
                break;
            case 1:
                result = 2;
                break;
            case 3:
                result = 3;
                break;
            }
        }
        break;
    case 0:
    case 0x100:
        low = arg0 & 0xFF;
        switch (low) {
        case 0:
            result = 1;
            break;
        case 1:
            result = 2;
            break;
        case 3:
            result = 3;
            break;
        }
        break;
    case 0x300:
        result = 4;
        break;
    case 0x600:
        result = 5;
        break;
    }
    return result;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/6AA80/func_8006B928.s")

void func_8006BA74(u8 *arg0) {
    s32 i;
    u8 *ptr;
    if (arg0 != NULL) {
        _bzero(arg0, 0x490);
        ptr = arg0;
        i = 0;
        do {
            i++;
            ptr += 0x1DC;
            ptr[-0x1DC] = 0x50;
            ptr[-0x1CF] = 0x50;
        } while (i != 2);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/6AA80/func_8006BAC4.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/6AA80/func_8006BF78.s")

extern void *func_8006BF78(s32); void *func_8006C58C(void) { return func_8006BF78(0); }

extern void _bcopy(void *, void *, s32);
void func_8006C5AC(s32 arg0, void *arg1, s32 arg2, s32 arg3)
{
  void *base;
  void *temp;
  if (D_8009DF70 != 0)
  {
    base = *((void **) (((u8 *) ((u32) D_8009DF70)) + 0x2C));
    temp = ((u8 *) base) + arg0;
    if (((base != 0) && (arg0 >= 0)) && (arg0 < 4))
    {
      _bcopy(arg1, (((u8 *) (*((void **) (((u8 *) ((u32) D_8009DF70)) + 0x2C)))) + (arg0 * 0x16)) + 0x1C, 0x16);
      temp = ((u8 *) base) + arg0;
      if (1)
      {
        *((s8 *) (((u8 *) temp) + 0x74)) = arg2;
      }
      *((s8 *) (((u8 *) temp) + 0x78)) = arg3;
    }
  }
}

extern void *func_8006BF78(s32); void *func_8006C644(void) { return func_8006BF78(1); }

extern s32 func_800718B8(s32);
extern void func_80073208(void *, s32);
void *func_8006C664(void) {
    u8 *result = NULL; volatile s32 *globalp = &D_8009DF70;
    s32 linked; s32 state;  s16 kind;
    state=*globalp;
    if(state!=0){
        result=*(u8 **)((u8 *)(u32)state+0x1C);
        result[0x9C2]=*(u8 *)((u8 *)(u32)state+0x1A);
        state=*globalp; linked=*(s32 *)((u8 *)(u32)state+0x20);
        if(linked!=0){*(s32 *)(result+0x9D8)=linked+0x3B8; state=*globalp;}
        kind=*(s16 *)((u8 *)(u32)state+6);
        if(kind!=0xE) *(s32 *)(result+0x9D4)=func_800718B8(kind);
        else *(s32 *)(result+0x9D4)=state+0x3C;
        if(result[0x9C2]==2){func_80073208(result, *(s32 *)((u8 *)(u32)*globalp + 0x20));}
    }
    return result;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/6AA80/func_8006C714.s")

extern void main_pool_try_free(void);
void func_8006C9C0(void) { main_pool_try_free(); if (D_8009DF70 != 0) *(s32 *)((u8 *)(u32)D_8009DF70 + 0x38) = 0; }

void *func_8006C9F4(void) { void *result = main_pool_alloc(0x440, 0); if (result != NULL) _bzero(result, 0x440); return result; }

extern void main_pool_try_free(void); void func_8006CA34(void) { main_pool_try_free(); }

typedef struct SmallCA54 { s16 flag; s8 value; u8 pad3; } SmallCA54;
SmallCA54 *func_8006CA54(s32 arg0) {
    SmallCA54 *result = main_pool_alloc(4, 0);
    if (result != NULL) {
        _bzero(result, 4);
        if (D_8009DF70 != 0) {
            result->flag = ((*(u16 *)((u8 *)(u32)D_8009DF70 + 4) & 1) != 0);
            result->value = arg0;
        }
    }
    return result;
}

extern void main_pool_try_free(void); void func_8006CAC0(void) { main_pool_try_free(); }

typedef struct InitCAE0 {
    s16 flag;
    s16 value4;
    u16 value5;
    u16 pad6;
    s16 value0;
    s16 value1;
    s16 value2;
    s16 value3;
} InitCAE0;
InitCAE0 *func_8006CAE0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u16 arg5) {
    InitCAE0 *result = main_pool_alloc(0x10, 0);
    if (result != NULL) {
        _bzero(result, 0x10);
        if (D_8009DF70 != 0) {
            result->flag = ((*(u16 *)((u8 *)(u32)D_8009DF70 + 4) & 1) != 0);
            result->value4 = (s16)arg4;
            result->value5 = (u16)arg5;
            result->value0 = (s16)arg0;
            result->value1 = (s16)arg1;
            result->value2 = (s16)arg2;
            result->value3 = (s16)arg3;
        }
    }
    return result;
}

extern void main_pool_try_free(void); void func_8006CB80(void) { main_pool_try_free(); }

s32 func_8006CBA0(s32 a,s32 b){s32 result=0; s32 next=a+1; if(b==next)result=1; return result;}

s32 func_8006CBB8(s32 arg0) {
    s32 var_v1;

    var_v1 = -1;
    switch (arg0) {
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
            var_v1 = 0;
            break;
        case 14:
        case 15:
            var_v1 = 1;
            break;
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
            var_v1 = 2;
            break;
    }

    return var_v1;
}

extern s16 D_8009DF74; void func_8006CBFC(void) { D_8009DF74 = 1; }

extern s16 D_8009DF74; void func_8006CC0C(void) { D_8009DF74 = 0; }

extern void *Util_Malloc(s32);
extern void Util_Free(void *);
extern void _bcopy(void *, void *, s32);
extern void func_80054B7C();
extern void func_80051D64(s32, s32);
typedef struct PacketCC18B {
    u16 value0;
    s16 value2;
    s8 flag4;
    s8 value5;
    s8 value6;
    s8 value7;
    u16 value8;
    u8 copyA[12];
    u8 tail16;
} PacketCC18B;
typedef struct CopyCC18Phase2B { s32 words[22]; } CopyCC18Phase2B;
s32 func_8006CC18(s32 arg0, s32 arg1) {
    s32 result;
    u8 pad[8];
    PacketCC18B packet;
    u8 *buffer;
    s32 count;
    s32 offset;
    u8 *src;
    result = 0;
    if (D_8009DF70 != 0) {
        buffer = Util_Malloc(0x210);
        result = 1;
        packet.value0 = *(u16 *)((u8 *)(u32)D_8009DF70);
        packet.value2 = *(s16 *)((u8 *)(u32)D_8009DF70 + 2);
        packet.flag4 = ((*(u16 *)((u8 *)(u32)D_8009DF70 + 4) & 1) != 0);
        if (arg0 != 0) packet.value5 = *(s16 *)((u8 *)(u32)D_8009DF70 + 0x12) + 1;
        else packet.value5 = *(s16 *)((u8 *)(u32)D_8009DF70 + 0x12);
        packet.value6 = arg1;
        packet.value7 = *(s16 *)((u8 *)(u32)D_8009DF70 + 0x16);
        packet.value8 = *(u16 *)(*(u8 **)((u8 *)(u32)D_8009DF70 + 0x24) + 0x934);
        _bcopy(*(u8 **)((u8 *)(u32)D_8009DF70 + 0x24) + 0x904, packet.copyA, 0xC);
        count = 0;
        offset = 0;
        packet.tail16 = *(u8 *)(*(u8 **)((u8 *)(u32)D_8009DF70 + 0x24) + 0x955);
        do {
            src = *(u8 **)((u8 *)(u32)D_8009DF70 + 0x24) + offset;
            offset += 0x60;
            if (*src != 0) {
                ((CopyCC18Phase2B *)buffer)[count] = *(CopyCC18Phase2B *)src;
                count++;
            }
        } while (offset != 0x240);
        func_80054B7C(&packet, buffer, count);
        func_80051D64(0x15, 0);
        Util_Free(buffer);
    }
    return result;
}

typedef struct CopyCDA0C { s32 words[22]; } CopyCDA0C;
s32 func_8006CDA0(u8 *arg0,u8 *arg1) {
 s32 result=0; s32 offset; u8 *src; u8 *dst;
 if(D_8009DF70!=0) {
  result=1; func_8006A3B8(*(u16 *)arg0); func_8006A400(*(s16 *)(arg0+2));
  if(arg0[4]!=0) func_8006A2F8(1); else func_8006A328(1);
  func_8006AC4C(arg0[5]); func_8006B7D8(arg0[6]);
  *(u16 *)(*(u8 **)((u8 *)(u32)D_8009DF70+0x24)+0x934)=*(u16 *)(arg0+8);
  _bcopy(arg0+0xA,*(u8 **)((u8 *)(u32)D_8009DF70+0x24)+0x904,0xC);
  *(u8 *)(*(u8 **)((u8 *)(u32)D_8009DF70+0x24)+0x955)=arg0[0x16];
  src=arg1;
  for(offset=0; offset!=0x240; offset+=0x60) {
            dst=*(u8 **)((u8 *)(u32)D_8009DF70+0x24)+offset;
            _bzero(dst,0x60);
            *(CopyCDA0C *)dst=*(CopyCDA0C *)src;
            src+=0x58;
        }
 }
 return result;
}

s32 func_8006CEE8(u16 arg0) {
 u16 high; s32 value; s32 low; s32 result; u16 *home=&arg0;
 high=arg0;
 value=high;
 result=-1;
 high&=0xFF00;
 switch(high){
 case 0:
  low=(u16)value; low&=0xFF;
  switch(low){case 0:result=0x55;break;case 1:result=0x53;break;case 2:result=0x54;break;case 3:result=0x56;break;}
  break;
 case 0x300:result=0x5E;break;
 }
 return result;
}

s32 func_8006CF70(s16 arg0) {
    s32 id = -1;

    switch (arg0) {
        case 1: id = 90; break;
        case 2: id = 91; break;
        case 3: id = 92; break;
        case 4: id = 93; break;
        case 5: id = 57; break;
        case 6: id = 58; break;
        case 7: id = 59; break;
        case 8: id = 60; break;
        case 9: id = 61; break;
        case 10: id = 62; break;
        case 11: id = 63; break;
        case 12: id = 64; break;
        case 13: id = 65; break;
        case 14: id = 66; break;
        case 15: id = 79; break;
        case 16: id = 69; break;
        case 17: id = 72; break;
        case 18: id = 68; break;
        case 19: id = 70; break;
        case 20: id = 71; break;
        case 21: id = 67; break;
        case 22: id = 73; break;
        case 23: id = 74; break;
        case 24: id = 82; break;
    }
    return id;
}

/* mkdraft:func_8006D068 begin */
extern s32 func_8004C594(s32, s32);
extern void func_8004C8A0(s8 *, s32, s32, s32);



void func_8006D068(s8 *arg0, s32 arg1, u16 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_a2;
    s32 temp_v0;
    s32 var_s0;

    // FAKE: never read -- temp_a2 is reassigned before its only use in case 0 --
    // but the extra web advances uopt's colour walk so arg5 takes $v0 at the
    // case-0 and default compares. diff score 70 without it.
    temp_a2 = arg5;

    temp_v0 = arg2 & 0xFF00;
    var_s0 = -1;
    *arg0 = 0;
    switch (temp_v0) {
    case 0x0:
        temp_a1 = arg4 + 1;
        if (arg5 == temp_a1) {
            var_s0 = 0x57;
        } else {
            temp_a2 = arg4 + 2;
            if (arg5 == temp_a2) {
                var_s0 = 0x58;
            } else {
                func_8004C594(1, arg4 + 1);
                var_s0 = 0x4B;
            }
        }
        break;
    case 0x300:
        switch (arg3) {
        case 15:
            var_s0 = 0x50;
            break;
        case 11:
            func_8004C594(1, arg4 + 1);
            var_s0 = 0x4B;
            break;
        case 14:
            func_8004C594(1, arg4 + 1);
            var_s0 = 0x4E;
            break;
        case 24:
            var_s0 = 0x51;
            break;
        default:
            temp_a1_2 = arg4 + 1;
            if (arg5 == temp_a1_2) {
                var_s0 = 0x4D;
            } else {
                func_8004C594(1, arg4 + 1);
                var_s0 = 0x4C;
            }
            break;
        }
        break;
    }
    if (var_s0 >= 0) {
        func_8004C8A0(arg0, arg1, 0x12, var_s0);
    }
}
/* mkdraft:func_8006D068 end */
#endif
