#include "global.h"


#ifdef VERSION_US
/* mkdraft:func_82B00E10 begin */
extern u8 D_82B12450[0xFF8];

void func_82B00E10(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        *(s16 *)((u8 *)((s16 *)D_82B12450 + i) + 0xFF4) = 0;
    }
}
/* mkdraft:func_82B00E10 end */
#endif

#ifdef VERSION_US
extern void func_800226C0();
extern u8 D_82B12450[0xFF8];
s32 func_82B00E34(s32 arg0) {
    s16 *sp1C;
    s16 *temp_v1;
    s32 var_a1;
    s32 var_v0;
    var_a1 = 0;
    var_v0 = 0;
    if ((arg0 == 0xA6) || (arg0 == 0xA8)) var_v0 = 1;
    temp_v1 = &((s16 *)D_82B12450)[var_v0];
    if ((*(s16 *)((u8 *)(temp_v1) + (0xFF4))) == 0) {
        sp1C = temp_v1;
        func_800226C0();
        var_a1 = 1;
        (*(s16 *)((u8 *)(temp_v1) + (0xFF4))) = 1;
    }
    return var_a1;
}
#endif

#ifdef VERSION_US
extern s16 D_82B12458;
extern s16 D_82B13240;

void func_82B00EA4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s16 *count;
    u8 *entry;
    s32 bottom;

    // FAKE: reading D_82B13240 through a pointer, writing it back through
    // D_82B12458 + 0xDE8 (the same address), and keeping both statements on one
    // line reproduce the original allocation; diff score 345 with plain
    // accesses and 60 with the statements on separate lines.
    count = &D_82B13240;
    if (*(s16 *)((u8 *)&D_82B12450 + 0xDF0) < 32) {
        entry = (u8 *)&D_82B12450 + D_82B13240 * 16; *(s16 *)((u8 *)&D_82B12458 + 0xDE8) = *count + 1;
        *(s32 *)(entry + 0xDF4) = arg0;
        *(s16 *)(entry + 0xDF8) = arg1;
        *(s16 *)(entry + 0xDFC) = arg2;
        *(s16 *)(entry + 0xDFE) = arg2 + arg4 - 1;
        *(s16 *)(entry + 0xE02) = arg3;
        entry = entry + 0xDF4;
        bottom = arg3 + arg5 - 1;
        *(s16 *)(entry + 0xC) = bottom;
    }
}

#endif

#ifdef VERSION_US
void *func_82B00F14(s32 arg0) {
    s32 i;
    void *result = NULL;
    u8 *entry = (u8 *)&D_82B12450;
    for (i = 0; i < *(s16 *)(entry + 0xDF0); i++) {
        if (*(s32 *)(entry + 0xDF4 + i * 0x10) == arg0) {
            result = entry + 0xDF4 + i * 0x10;
            break;
        }
    }
    return result;
}
#endif

#ifdef VERSION_US
extern void *func_82B00F14(s32);
extern void Gfx_SetScissorRect();
extern Gfx * D_800D0510;
s32 func_82B00F68(s32 arg0)
{
    s32 result;
    s32 x0;
    s32 x1;
    s32 x2;
    s32 x3;
    void *p;
    s16 *base;
    result = 0;
    p = func_82B00F14(arg0);
    if (p != NULL) {
        if (*(s16 *)((u8 *)p + 4) > 0) {
            (*(s16 *)((u8 *)p + 4))--;
        }
        if (*(s16 *)((u8 *)p + 4) != 0) {
            x0 = *(s16 *)((u8 *)p + 8);
            x2 = *(s16 *)((u8 *)p + 10);
            x1 = *(s16 *)((u8 *)p + 14);
            x3 = *(s16 *)((u8 *)p + 12);
            result = 1;
            base = (s16 *)((u8 *)p + 8);
            if (x0 < 0) x0 = 0;
            if (base[1] >= 0x280) x2 = 0x27F;
            if (base[3] < 0) x1 = 0;
            if (base[2] >= 0x1E0) x3 = 0x1DF;
            if ((x2 >= x0) && (x3 >= x1)) {
                Gfx_SetScissorRect(&D_800D0510, (s16)x0, (s16)x1, (s16)(x2 - x0 + 1), x3 - x1 + 1);
            }
        }
    }
    return result;
}
#endif

#ifdef VERSION_US
void *func_82B00F14(s32);

void func_82B01054(s32 arg0) {
    void *temp_v0;

    temp_v0 = func_82B00F14(0x46554C4C);
    if (temp_v0 != NULL) {
        (*(s16 *)((u8 *)(temp_v0) + (4))) = (s16) arg0;
    }
}
#endif

#ifdef VERSION_US
void *func_82B00F14(s32);

s16 func_82B01088(void) {
    s16 var_v1;
    void *temp_v0;

    temp_v0 = func_82B00F14(0x46554C4C);
    var_v1 = 0;
    if (temp_v0 != NULL) {
        var_v1 = (*(s16 *)((u8 *)(temp_v0) + (4)));
    }
    return var_v1;
}
#endif

#ifdef VERSION_US
/* mkdraft:func_82B010BC begin */
extern s16 D_82B13008;
extern u16 D_82B12454;
extern void *func_82B02800(s32, s32);

s32 func_82B010BC(void) {
    s32 index;
    s32 var_a3;
    u16 *var_v1;
    u16 temp_v0_2;
    u8 *temp_v0;

    temp_v0 = func_82B02800(0xA, 0);
    var_a3 = 0;
    D_82B13008 = 0;
    index = 0;
    var_v1 = (u16 *)((u8 *)temp_v0 + 0x50); do {
        temp_v0_2 = *(u16 *)((u8 *)((s16 *)D_82B12450 + index) + 0xBDC);
        index++;
        if (temp_v0_2 == 2) {
            var_a3 = 1;
            *var_v1 = temp_v0_2;
        } else {
            *var_v1 = 0;
        }
        var_v1 += 1;
    } while ((u8 *)&D_82B12454 != (u8 *)((s16 *)D_82B12450 + index));
    return var_a3;
}
/* mkdraft:func_82B010BC end */
#endif

#ifdef VERSION_US
s32 func_82B01130(void) {
    s32 index;
    s32 result;
    u16 *dest;
    u8 *base;

    base = func_82B02800(10, 0);
    result = 0;
    D_82B13008 = 1;
    index = 0;
    // FAKE: the loop head shares a line with the dest initialization, as in
    // func_82B010BC; the assembler orders the address setup by source line.
    // Diff score 45 without it.
    dest = (u16 *)(base + 0x50); do {
        switch (*(u16 *)((u8 *)((s16 *)D_82B12450 + index) + 0xBDC)) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                result = 1;
                *dest = *(u16 *)((u8 *)((s16 *)D_82B12450 + index) + 0xBDC);
                break;
            default:
                *dest = 0;
                break;
        }
        index++;
        dest++;
    } while ((u8 *)&D_82B12454 != (u8 *)((s16 *)D_82B12450 + index));
    return result;
}
#endif

#ifdef VERSION_US
extern s32 D_82B12674;
s32 func_82B011C0(s32 arg0, s32 arg1) {
    s32 var_a2;
    s32 var_v1;
    var_a2 = -1;
    var_v1 = 0;
    switch (arg0) {
    case 0: var_a2 = 0xC; break;
    case 1: var_a2 = 0xA; break;
    case 2: var_a2 = 0; break;
    case 4: var_a2 = -2; break;
    }
    if (var_a2 >= 0) var_v1 = func_800718B8(var_a2);
    else if (var_a2 == -2) var_v1 = ((s32 *)&D_82B12674)[arg1];
    return var_v1;
}
#endif

#ifdef VERSION_US
s32 func_82B01254(void *arg0, s32 arg1) {
    s32 var_v1;

    if (arg0 != NULL) {
        var_v1 = arg1 >= (s32) (*(u8 *)((u8 *)(arg0) + (0x36)));
        if (var_v1 != 0) {
            var_v1 = (s32) (*(u8 *)((u8 *)(arg0) + (0x37))) >= arg1;
        }
        return var_v1;
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern s32 func_80071CD0(s32, s32);
extern s32 func_80071210(u8 *);
extern s32 func_80071230(u8 *);
extern s32 func_80071890(void *, s32);
extern s32 func_81601EAC(u8, u8);
extern s32 func_82B01254(void *, s32);
typedef struct RuleFlag82B0128C {
    u32 unk_high : 5;
    u32 item_check : 1;
    u32 unk_low : 26;
} RuleFlag82B0128C;
s32 TeamRules_ValidateSelection(s16 *per_mon, s16 *team_error, u8 *rules, s32 count, u8 *records) {
    s32 any;
    s16 species;
    u8 item;
    s32 total_level;
    s32 total_error;
    s16 flags;
    s32 i;
    s32 j;
    s32 rejected;
    u8 *record;
    s32 lowest[3];
    s32 result;
    s32 item_index;
    any = 0;
    for (i = 0; i < count; i++) {
        flags = 0;
        if (rules != NULL) {
            record = i * 88 + (u8 *)records;
            species = record[0];
            if (species != 0) {
                if (((record[30]) & 1) || func_80071CD0((s32)(rules + 0x14), species - 1) == 0) {
                    flags = 1;
                }
                if (func_82B01254(rules, (record[29])) == 0) flags |= 2;
                if (func_80071210(rules) == 0) {
                    for (j = 0; j < count; j++) {
                        if (i != j && (*(j * 88 + (u8 *)records)) == (record[0])) {
                            flags |= 4;
                            break;
                        }
                    }
                }
                if (((RuleFlag82B0128C *)(rules + 0x40))->item_check && func_80071230(rules) == 0) {
                    item = record[1];
                    if (item != 0 && func_81601EAC(item, (record[0])) != 0) {
                        for (item_index = 0; item_index < count; item_index++) {
                            if (i != item_index && (*(item_index * 88 + (u8 *)records + 1)) == (record[1])) {
                                flags |= 8;
                                break;
                            }
                        }
                    }
                }
            }
        }
        if (per_mon != NULL) per_mon[i] = flags;
        if (flags != 0) any = 1;
    }
    total_error = 0;
    rejected = any != 0;
    if (rejected == 0 && rules != NULL) {
        for (i = 0; i < 3; i++) lowest[i] = 999;
        for (i = 0; i < count; i++) {
            record = i * 88 + (u8 *)records;
            if (record[29] <= lowest[2]) lowest[2] = record[29];
            if (record[29] <= lowest[1]) {
                lowest[2] = lowest[1];
                lowest[1] = record[29];
            }
            if (record[29] <= lowest[0]) {
                lowest[1] = lowest[0];
                lowest[0] = record[29];
            }
        }
        total_level = lowest[0] + lowest[1] + lowest[2];
        if (func_80071890(rules, total_level) == 0) total_error = 1;
    }
    if (team_error != NULL) *team_error = total_error;
    result = rejected;
    if (result == 0) result = total_error != 0;
    return result;
}
#endif

#ifdef VERSION_US
extern void *func_8004C874(s32, s32);

s32 func_82B0173C(s32 arg0, s32 arg1) {
    s32 result = 0;

    switch (arg0) {
        case 1:
        case 2:
            result = func_8004C874(27, 59);
            break;
        case 3:
            result = func_8004C874(27, 65);
            break;
        case 4:
            result = func_8004C874(27, 63);
            break;
        case 5:
            result = func_8004C874(27, 64);
            break;
        case 6:
            switch (arg1) {
                case 0:
                    result = func_8004C874(27, 60);
                    break;
                case 1:
                    result = func_8004C874(27, 61);
                    break;
                case 2:
                    result = func_8004C874(27, 62);
                    break;
                case 3:
                    result = func_8004C874(27, 63);
                    break;
                case 4:
                    result = func_8004C874(27, 64);
                    break;
            }
            break;
    }
    return result;
}
#endif

#ifdef VERSION_US
extern s32 func_82B0173C(s32, s32);
void func_82B01850(s32 arg0, s32 arg1) {
    s32 mode;
    switch (arg1 & 0xFFFF0000) {
    case 0x10000:
        mode = 0;
        break;
    case 0x20000:
        mode = 1;
        break;
    case 0x30000:
        mode = 2;
        break;
    case 0x40000:
        mode = 3;
        break;
    case 0x50000:
        mode = 4;
        break;
    default:
        mode = 0;
        break;
    }
    func_82B0173C(arg0, mode);
}
#endif

#ifdef VERSION_US
/* mkdraft:func_82B018CC begin */
void *func_82B018CC(void *arg0, s32 arg1) {
    s32 i;
    u8 *ptr;
    void *result;
    void *base;

    result = NULL;
    i = 0;
    base = arg0;
    if (arg1 > 0) {
        ptr = base;
        do {
            i += 1;
            if (*(s16 *)ptr == 0) {
                result = ptr;
                break;
            }
            ptr += 0x70;
        } while (i != arg1);
    }
    return result;
}
/* mkdraft:func_82B018CC end */
#endif

#ifdef VERSION_US
extern u8 D_82B12450[0xFF8];
extern s16 D_82B12470;
extern s32 func_82B011C0(s32, s32);
extern s32 func_82B0128C(s16 *, s16 *, u8 *, s32, u8 *);
typedef struct CupPanelPoint { s16 x; s16 y; } CupPanelPoint;
typedef struct CupPanelFade { s16 active; s16 tick; } CupPanelFade;
typedef struct CupPanelInitState {
    s16 kind;
    s16 subtype;
    u16 flags;
    s16 state;
    u8 unknown_08[4];
    CupPanelPoint slide_delta;
    CupPanelPoint position;
    CupPanelPoint entry_offset;
    CupPanelPoint exit_offset;
    CupPanelPoint entry_offsets[4];
    CupPanelPoint exit_offsets[4];
    CupPanelPoint base_position;
    u8 unknown_40[8];
    s16 width;
    s16 height;
    u8 unknown_4C[4];
    CupPanelFade fade;
} CupPanelInitState;
void Panel_InitCupSelection(void *context) {
    CupPanelInitState *panel;
    s32 cup_index;
    s32 grid_cell[2];
    s32 slot_index;
    u8 *rules;
    u8 *selection_context;
    CupPanelPoint *entry_offset;
    CupPanelPoint *exit_offset;
    CupPanelFade *fade;
    panel = context;
    cup_index = panel->subtype;
    grid_cell[1] = (int)cup_index % 3;
    grid_cell[0] = (int)cup_index / 3;
    switch (cup_index) {
    case 0:
    case 1:
    case 2:
        rules = (u8 *)func_82B011C0(cup_index, -1);
        selection_context = D_82B12450;
        for (slot_index = 0; slot_index < 2; slot_index++) {
            if (((u16 *)(selection_context + 0xBDC))[slot_index] != 0 ||
                func_82B0128C(NULL, NULL, rules, ((s16 *)(selection_context + 0xBC8))[slot_index], ((u8 **)(selection_context + 0xBCC))[slot_index]) != 0) {
                panel->flags &= ~2;
            }
        }
        break;
    case 3:
        break;
    case 4:
        if (D_82B12470 <= 0) {
            panel->flags &= ~2;
        }
        break;
    default:
        break;
    }
    if (grid_cell[0] == 0) {
        panel->slide_delta.x = 640;
    } else {
        panel->slide_delta.x = -640;
    }
    panel->slide_delta.y = 0;
    panel->position.x = grid_cell[1] * 153 + 98;
    panel->position.y = grid_cell[0] * 138 + 82;
    panel->base_position = panel->position;
    entry_offset = (CupPanelPoint *)((u8 *)context + 0x14);
    *entry_offset = panel->slide_delta;
    exit_offset = (CupPanelPoint *)((u8 *)context + 0x18);
    exit_offset->x = -entry_offset->x;
    exit_offset->y = -entry_offset->y;
    fade = (CupPanelFade *)((u32)context + 0x50);
    for (slot_index = 0; slot_index < 4; slot_index++) {
        *(CupPanelPoint *)((u8 *)context + 0x1C + slot_index * 4) = *entry_offset;
        *(CupPanelPoint *)((u8 *)context + 0x2C + slot_index * 4) = *exit_offset;
    }
    panel->entry_offsets[1].x = -panel->entry_offset.x;
    panel->entry_offsets[1].y = -panel->entry_offset.y;
    panel->exit_offsets[1].x = 0;
    panel->exit_offsets[1].y = -480;
    panel->width = 141;
    panel->height = 130;
    fade->active = 0;
    fade->tick = 0;
}
#endif

#ifdef VERSION_US
#pragma pack(1)
struct PackedWord82B01BB8 { s32 value; };
#pragma pack(0)
struct Color82B01BB8 { u8 r, g, b; };
extern struct Color82B01BB8 D_82B085BC;
#pragma pack(1)
struct PackedUnsigned82B01BB8 { u32 value; };
#pragma pack(0)
void func_82B01BB8(void *arg0) {
    *(s16 *)((u8 *)arg0 + 0xC) = -0x280;
    *(s16 *)((u8 *)arg0 + 0xE) = 0;
    *(s16 *)((u8 *)arg0 + 0x10) = 0x1A7;
    *(s16 *)((u8 *)arg0 + 0x12) = 0xF0;
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x3C) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x10);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x14) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0xC);
    *(s16 *)((u8 *)arg0 + 0x18) = -*(s16 *)((u8 *)arg0 + 0x14);
    *(s16 *)((u8 *)arg0 + 0x1A) = -*(s16 *)((u8 *)arg0 + 0x16);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x1C) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x14);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x2C) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x18);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x20) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x14);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x30) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x18);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x24) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x14);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x34) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x18);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x28) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x14);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x38) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x18);
    *(s16 *)((u8 *)arg0 + 0x20) = -*(s16 *)((u8 *)arg0 + 0x14);
    *(s16 *)((u8 *)arg0 + 0x22) = -*(s16 *)((u8 *)arg0 + 0x16);
    *(s16 *)((u8 *)arg0 + 0x48) = 0x67;
    *(s16 *)((u8 *)arg0 + 0x4A) = 0x5A;
    *(struct Color82B01BB8 *)((u8 *)arg0 + 0x4C) = D_82B085BC;
}
#endif

#ifdef VERSION_US
extern struct Color82B01BB8 D_82B085D4;
extern s16 D_82B12458;
void func_82B01CE0(void *arg0)
{
  s16 *tail;
  struct PackedWord82B01BB8 *new_var;
  *((s16 *) (((u8 *) arg0) + 0xC)) = 0;
  *((s16 *) (((u8 *) arg0) + 0xE)) = 0x1E0;
  *((s16 *) (((u8 *) arg0) + 0x10)) = 0x4C;
  *((s16 *) (((u8 *) arg0) + 0x12)) = 0x166;
  *((struct PackedWord82B01BB8 *) (((u8 *) arg0) + 0x3C)) = *((struct PackedWord82B01BB8 *) (((u8 *) arg0) + 0x10));
  new_var = (struct PackedWord82B01BB8 *) (((u8 *) arg0) + 0x14);
  *new_var = *((struct PackedWord82B01BB8 *) (((u8 *) arg0) + 0xC));
  *((struct PackedWord82B01BB8 *) (((u8 *) arg0) + 0x18)) = *new_var;
  tail = ((u8 *) arg0) + 0x50;
  *((struct PackedWord82B01BB8 *) (((u8 *) arg0) + 0x1C)) = *new_var;
  *((struct PackedWord82B01BB8 *) (((u8 *) arg0) + 0x2C)) = *((struct PackedWord82B01BB8 *) (((u8 *) arg0) + 0x18));
  *((struct PackedWord82B01BB8 *) (((u8 *) arg0) + 0x20)) = *new_var;
  *((struct PackedWord82B01BB8 *) (((u8 *) arg0) + 0x30)) = *((struct PackedWord82B01BB8 *) (((u8 *) arg0) + 0x18));
  *((struct PackedWord82B01BB8 *) (((u8 *) arg0) + 0x24)) = *new_var;
  *((struct PackedWord82B01BB8 *) (((u8 *) arg0) + 0x34)) = *((struct PackedWord82B01BB8 *) (((u8 *) arg0) + 0x18));
  *((struct PackedWord82B01BB8 *) (((u8 *) arg0) + 0x28)) = *new_var;
  *((struct PackedWord82B01BB8 *) (((u8 *) arg0) + 0x38)) = *((struct PackedWord82B01BB8 *) (((u8 *) arg0) + 0x18));
  *((s16 *) (((u8 *) arg0) + 0x48)) = 0x1EB;
  *((s16 *) (((u8 *) arg0) + 0x4A)) = 0x58;
  *((struct Color82B01BB8 *) (((u8 *) arg0) + 0x4C)) = D_82B085D4;
  tail[0] = 0;
  tail[1] = 0;
  tail[3] = D_82B12458;
  tail[4] = 0;
  tail[2] = tail[3];
}
#endif

#ifdef VERSION_US
void func_82B01E0C(void *arg0) {
    *(s16 *)((u8 *)arg0 + 0xC) = 0;
    *(s16 *)((u8 *)arg0 + 0xE) = -480;
    *(s16 *)((u8 *)arg0 + 0x10) = 97;
    *(s16 *)((u8 *)arg0 + 0x12) = 139;
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x3C) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x10);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x14) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0xC);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x18) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x14);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x1C) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x14);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x2C) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x18);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x20) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x14);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x30) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x18);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x24) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x14);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x34) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x18);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x28) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x14);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x38) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x18);
    *(s16 *)((u8 *)arg0 + 0x48) = 449;
    *(s16 *)((u8 *)arg0 + 0x4A) = 46;
    *(struct Color82B01BB8 *)((u8 *)arg0 + 0x4C) = D_82B085BC;
}
#endif

#ifdef VERSION_US
void func_82B01F14(void *arg0) {
    *(s16 *)((u8 *)arg0 + 0xC) = 0;
    *(s16 *)((u8 *)arg0 + 0xE) = -480;
    *(s16 *)((u8 *)arg0 + 0x10) = 97;
    *(s16 *)((u8 *)arg0 + 0x12) = 180;
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x3C) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x10);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x14) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0xC);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x18) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x14);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x1C) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x14);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x2C) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x18);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x20) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x14);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x30) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x18);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x24) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x14);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x34) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x18);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x28) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x14);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x38) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x18);
    *(s16 *)((u8 *)arg0 + 0x48) = 449;
    *(s16 *)((u8 *)arg0 + 0x4A) = 166;
    *(struct Color82B01BB8 *)((u8 *)arg0 + 0x4C) = D_82B085BC;
}
#endif

#ifdef VERSION_US
extern s32 func_80049148(s32, s32, void *);
extern void *func_8004C874(s32, s32);
typedef struct Pair02198 { s16 x; s16 y; } Pair02198;
typedef struct State02198 {
    s16 unk_00;
    s16 unk_02;
    u16 flags;
    s16 unk_06;
    u8 pad08[4];
    Pair02198 delta;
    Pair02198 pos;
    Pair02198 a;
    Pair02198 b;
    Pair02198 a0[4];
    Pair02198 b0[4];
    Pair02198 poscopy;
    u8 pad40[8];
    s16 width;
    s16 height;
} State02198;

// Same code as func_82B02198, but GS takes the widest of the four strings
// func_8004C874(27, 34-37) instead of walking D_82B12472, uses height 124, and does
// not clear flag 2.
void func_82B0201C(void *arg0)
{
  State02198 *p;
  s32 maximum;
  s32 value;
  s32 i;
  p = arg0;
  maximum = 0;
  for (i = 0; i < 4; i++) {
    value = func_80049148(8, 0, (void *)func_8004C874(27, i + 34));
    if (maximum < value) {
      maximum = value;
    }
  }
  p->width = maximum + 22;
  p->height = 124;
  p->delta.x = 0;
  p->delta.y = -480;
  p->pos.x = 0xFF;
  p->pos.y = 216 - (p->height / 2);
  p->poscopy = p->pos;
  p->a = p->delta;
  p->b.x = -p->a.x;
  p->b.y = -p->a.y;
  for (i = 0; i < 4; i++)
  {
    p->a0[i] = p->a;
    p->b0[i] = p->b;
  }

  p->b0[1].x = 0;
  p->b0[1].y = -480;
}
#endif

#ifdef VERSION_US
extern s16 D_82B12470;
extern u8 D_82B12472[];
extern u8 D_82B12672[];
void func_82B02198(void *arg0)
{
  u8 *cursor;
  State02198 *p;
  s32 maximum;
  s32 value;
  s32 i;
  p = arg0;
  maximum = 0;
 if (D_82B12470 <= 0) { p->flags &= ~2; } cursor = D_82B12472; do { value = func_80049148(8, 0, cursor); if (maximum < value) {
      maximum = value;
    }
    cursor += 0x40;
  }
  while (cursor < D_82B12672);
  p->width = maximum + 0x16;
  p->height = 0xE4;
  p->delta.x = 0;
  p->delta.y = -0x1E0;
  p->pos.x = 0xFF;
  p->pos.y = 0xD8 - (p->height / 2);
  p->poscopy = p->pos;
  p->a = p->delta;
  p->b.x = -p->a.x;
  p->b.y = -p->a.y;
  for (i = 0; i < 4; i++)
  {
    p->a0[i] = p->a;
    p->b0[i] = p->b;
  }

  p->b0[1].x = 0;
  p->b0[1].y = -0x1E0;
}
#endif

#ifdef VERSION_US
extern struct Color82B01BB8 D_82B085C0;
extern struct Color82B01BB8 D_82B085C4;
void Panel_InitializeAlternatingSlide(void *context) {
    State02198 *p = context;
    s32 i;
    struct Color82B01BB8 *even_color;
    struct Color82B01BB8 *odd_color;
    Pair02198 *a;
    Pair02198 *b;
    even_color = &D_82B085C0;
    odd_color = &D_82B085C4;
    p->width = 515;
    p->height = 106;
    p->delta.y = 0;
    p->pos.x = 64;
    if ((p->unk_02 & 1) == 0) {
        p->delta.x = 640;
        p->pos.y = 87;
    } else {
        p->delta.x = -640;
        p->pos.y = 239;
    }
    p->poscopy = p->pos;
    a = (Pair02198 *)((u8 *)context + 0x14);
    *a = p->delta;
    b = (Pair02198 *)((u8 *)context + 0x18);
    b->x = -a->x;
    b->y = -a->y;
    for (i = 0; i < 4; i++) {
        *(Pair02198 *)((u8 *)context + 0x1C + i * 4) = *a;
        *(Pair02198 *)((u8 *)context + 0x2C + i * 4) = *b;
    }
    p->a0[1].x = -p->a.x;
    p->a0[1].y = p->a.y;
    p->b0[1].x = p->a.x;
    p->b0[1].y = p->a.y;
    if ((p->unk_02 & 1) == 0) {
        *(struct Color82B01BB8 *)((u8 *)p + 0x4C) = *even_color;
    } else {
        *(struct Color82B01BB8 *)((u8 *)p + 0x4C) = *odd_color;
    }
}
#endif

#ifdef VERSION_US
extern struct Color82B01BB8 D_82B085D8;

// Initializes a panel like func_82B01E0C, through func_82B02198's State02198 view:
// delta (0, 480); position (column * 171 + 70, 383), where column is the halfword at
// +2; a = b = delta, copied into a0[] and b0[]; size 161 x 54; color D_82B085D8
// (0xFF, 0xFF, 0xB4).
void func_82B024B4(State02198 *p) {
    s32 i;

    p->delta.x = 0;
    p->delta.y = 480;
    p->pos.x = *(s16 *)((u8 *)p + 2) * 171 + 70;
    p->pos.y = 383;
    p->poscopy = p->pos;
    p->a = p->delta;
    p->b = p->a;
    for (i = 0; i < 4; i++) {
        p->a0[i] = p->a;
        p->b0[i] = p->b;
    }
    p->width = 161;
    p->height = 54;
    *(struct Color82B01BB8 *)((u8 *)p + 0x4C) = D_82B085D8;
}
#endif

#ifdef VERSION_US
extern struct Color82B01BB8 D_82B085C8;
// Close to func_82B01F14; differs only in the halfwords stored at 0x10 (120), 0x48 (404) and
// 0x4A (160) and in copying color D_82B085C8.
void func_82B025E0(void *arg0) {
    *(s16 *)((u8 *)arg0 + 0xC) = 0;
    *(s16 *)((u8 *)arg0 + 0xE) = -480;
    *(s16 *)((u8 *)arg0 + 0x10) = 120;
    *(s16 *)((u8 *)arg0 + 0x12) = 180;
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x3C) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x10);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x14) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0xC);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x18) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x14);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x1C) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x14);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x2C) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x18);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x20) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x14);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x30) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x18);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x24) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x14);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x34) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x18);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x28) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x14);
    *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x38) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x18);
    *(s16 *)((u8 *)arg0 + 0x48) = 404;
    *(s16 *)((u8 *)arg0 + 0x4A) = 160;
    *(struct Color82B01BB8 *)((u8 *)arg0 + 0x4C) = D_82B085C8;
}
#endif

#ifdef VERSION_US
extern void _bzero(void *, s32);
void func_82B026E8(State02198 *arg0, s32 arg1, s32 arg2) {
    _bzero(arg0, 112);
    arg0->unk_00 = arg1;
    arg0->unk_02 = arg2;
    arg0->flags |= 1;
    arg0->flags |= 2;
    arg0->unk_06 = 0;
    switch (arg0->unk_00) {
        case 1:
            Panel_InitCupSelection(arg0);
            break;
        case 2:
            func_82B01BB8(arg0);
            break;
        case 3:
            func_82B01CE0(arg0);
            break;
        case 4:
            func_82B01E0C(arg0);
            break;
        case 5:
            func_82B01F14(arg0);
            break;
        case 6:
            func_82B0201C(arg0);
            break;
        case 7:
            func_82B02198(arg0);
            break;
        case 8:
            Panel_InitializeAlternatingSlide(arg0);
            break;
        case 9:
            func_82B024B4(arg0);
            break;
        case 10:
            func_82B025E0(arg0);
            break;
    }
}
#endif

#ifdef VERSION_US
typedef struct unk_D_82B126A8 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ u8 unk_04[0x6C];
} unk_D_82B126A8; // size = 0x70

extern unk_D_82B126A8 D_82B126A8[20];

// Returns the D_82B126A8 record whose two leading halfwords equal (arg0, arg1), or NULL.
void *func_82B02800(s32 arg0, s32 arg1) {
    s32 count = 20; // FAKE: a variable bound keeps the loop rolled; diff score 770 without it.
    s32 i;
    unk_D_82B126A8 *entry;
    unk_D_82B126A8 *result = NULL;

    for (i = 0, entry = D_82B126A8; i < count; i++, entry++) {
        if (entry->unk_00 == arg0) {
            if (entry->unk_02 == arg1) {
                result = entry;
                break;
            }
        }
    }
    return result;
}
#endif

#ifdef VERSION_US
void func_82B0284C(u8 *arg0, u8 *arg1) {
    *(s16 *)(arg1 + 0) = *(s16 *)(arg0 + 0x10) + *(s16 *)(arg0 + 0xC);
    *(s16 *)(arg1 + 2) = *(s16 *)(arg0 + 0x12) + *(s16 *)(arg0 + 0xE);
}
#endif

#ifdef VERSION_US
s32 func_82B02870(void) {
    s32 i;
    s32 result = 1;
    u8 *base = (u8 *)&D_82B12450;

    for (i = 0; i < *(s16 *)(base + 0x250); i++) {
        u8 *entry = ((u8 **)(base + 0xB18))[i];

        if (*(u16 *)(entry + 6) != 2) {
            result = 0;
            break;
        }
    }
    return result;
}
#endif

#ifdef VERSION_US
s32 func_82B028CC(void) {
    u8 *base = (u8 *)&D_82B12450;
    s32 result = 1;
    s32 i;
    u8 *entry;

    for (i = 0; i < *(s16 *)(base + 0x250); i++) {
        entry = ((u8 **)(base + 0xB18))[i];
        if (*(u16 *)(entry + 6) != 0) {
            result = 0;
            break;
        }
    }
    return result;
}
#endif

#ifdef VERSION_US
extern s32 func_82B00E34(s32);
#pragma pack(1)
struct PackedWord82B02924 { s32 value; };
#pragma pack(0)
void func_82B02924(void *arg0, s32 arg1) {
    struct PackedWord82B02924 *src;
    s32 mode;
    if (arg0 != NULL) {
        if (*(u16 *)((u8 *)arg0 + 6) == 0) {
            *(u16 *)((u8 *)arg0 + 6) = 1;
            *(u16 *)((u8 *)arg0 + 8) = 0;
            *(struct PackedWord82B02924 *)((u8 *)arg0 + 0x10) = *(struct PackedWord82B02924 *)((u8 *)arg0 + 0x3C);
            if (arg1 >= 0 && arg1 < 4) {
                src = (struct PackedWord82B02924 *)((u8 *)arg0 + (arg1 << 2) + 0x1C);
                *(struct PackedWord82B02924 *)((u8 *)arg0 + 0x14) = *src;
            }
            if (*(s16 *)((u8 *)arg0 + 0x16) == 0) {
                mode = 0xA5;
                if (*(s16 *)((u8 *)arg0 + 0x14) >= 0) {
                    mode = 0xA6;
                } else {
                    mode = 0xA5;
                }
                func_82B00E34(mode);
            }
        }
    }
}
#endif

#ifdef VERSION_US
extern Pair02198 D_82B085DC;
void func_82B029B8(u8 *arg0, s32 arg1) {
    if (arg0 != NULL && *(u16 *)(arg0 + 6) == 2) {
        *(u16 *)(arg0 + 6) = 3;
        *(s16 *)(arg0 + 8) = 0;
        if (arg1 >= 0) {
            *(Pair02198 *)(arg0 + 0x40) = *(Pair02198 *)(arg0 + 0x10);
            *(Pair02198 *)(arg0 + 0x44) = D_82B085DC;
        } else {
            *(Pair02198 *)(arg0 + 0x44) = *(Pair02198 *)(arg0 + 0x40);
            *(Pair02198 *)(arg0 + 0x40) = *(Pair02198 *)(arg0 + 0x10);
        }
    }
}
#endif

#ifdef VERSION_US
extern s32 func_82B00E34(s32 arg0);
#pragma pack(1)
struct PackedWord82B02A34 { s32 value; };
#pragma pack(0)
void func_82B02A34(void *arg0, s32 arg1) {
    struct PackedWord82B02A34 *src;
    s32 mode;
    if (arg0 != NULL) {
        if (*(u16 *)((u8 *)arg0 + 6) == 2) {
            *(u16 *)((u8 *)arg0 + 6) = 4;
            *(u16 *)((u8 *)arg0 + 8) = 0;
            if (arg1 >= 0 && arg1 < 4) {
                src = (struct PackedWord82B02A34 *)((u8 *)arg0 + (arg1 << 2) + 0x2C);
                *(struct PackedWord82B02A34 *)((u8 *)arg0 + 0x18) = *src;
            }
            if (*(s16 *)((u8 *)arg0 + 0x1A) == 0) {
                mode = 0xA7;
                if (*(s16 *)((u8 *)arg0 + 0x18) >= 0) {
                    mode = 0xA8;
                } else {
                    mode = 0xA7;
                }
                func_82B00E34(mode);
            }
        }
    }
}
#endif

#ifdef VERSION_US
extern s32 D_82B085E0;

/**
 * Per-frame animation stepper (fragment 24). Increments the counter at
 * offset 8; while counter < D_82B085E0 writes shrinking x/y offsets
 * (x - x*counter/limit to 0xC, y - y*counter/limit to 0xE from the base
 * values at 0x14/0x16). Once the counter reaches the limit, marks the
 * state byte at offset 6 as 2 and zeroes the counter and both offsets.
 *
 * The dead early `counter` read and the `if (0) { }` boundary below are
 * load-bearing for register coloring: they freeze counter's pseudo-
 * register numbering before dead-code elimination so the reload inherits
 * the earlier color slot. Removing either costs 12 words. Both are
 * semantically inert.
 */
void func_82B02ABC(void *arg0) {
    s32 result;
    s32 counter;
    s32 x;
    s32 y;
    s32 limit;

    result = 0;
    counter = *(s16 *)((u8 *)arg0 + 8);
    limit = D_82B085E0;
    *(s16 *)((u8 *)arg0 + 8) = *(s16 *)((u8 *)arg0 + 8) + 1;
    if (0) {
    }
    counter = *(s16 *)((u8 *)arg0 + 8);
    if (counter < limit) {
        x = *(s16 *)((u8 *)arg0 + 0x14);
        y = *(s16 *)((u8 *)arg0 + 0x16);
        *(s16 *)((u8 *)arg0 + 0xC) = x - (x * counter) / limit;
        *(s16 *)((u8 *)arg0 + 0xE) = y - (y * counter) / limit;
    } else {
        result = 1;
    }
    if (result != 0) {
        *(s16 *)((u8 *)arg0 + 6) = 2;
        *(s16 *)((u8 *)arg0 + 8) = 0;
        *(s16 *)((u8 *)arg0 + 0xC) = 0;
        *(s16 *)((u8 *)arg0 + 0xE) = 0;
    }
}
#endif

#ifdef VERSION_US
extern s32 D_82B085E4;
void func_82B02BA4(void *arg0) {
    s32 result;
    s32 counter;
    s32 x;
    s32 y;
    s32 limit;
    result = 0;
    counter = *(s16 *)((u8 *)arg0 + 8);
    limit = D_82B085E4;
    *(s16 *)((u8 *)arg0 + 8) = *(s16 *)((u8 *)arg0 + 8) + 1;
    if (0) { }
    counter = *(s16 *)((u8 *)arg0 + 8);
    if (counter < limit) {
        x = *(s16 *)((u8 *)arg0 + 0x40);
        y = *(s16 *)((u8 *)arg0 + 0x42);
        *(s16 *)((u8 *)arg0 + 0x10) = ((*(s16 *)((u8 *)arg0 + 0x44) - *(s16 *)((u8 *)arg0 + 0x40)) * counter) / limit + *(s16 *)((u8 *)arg0 + 0x40);
        *(s16 *)((u8 *)arg0 + 0x12) = ((*(s16 *)((u8 *)arg0 + 0x46) - *(s16 *)((u8 *)arg0 + 0x42)) * counter) / limit + *(s16 *)((u8 *)arg0 + 0x42);
    } else {
        result = 1;
    }
    if (result != 0) {
        *(s16 *)((u8 *)arg0 + 6) = 2;
        *(s16 *)((u8 *)arg0 + 8) = 0;
        *(s16 *)((u8 *)arg0 + 0x10) = *(s16 *)((u8 *)arg0 + 0x44);
        *(s16 *)((u8 *)arg0 + 0x12) = *(s16 *)((u8 *)arg0 + 0x46);
    }
}
#endif

#ifdef VERSION_US
extern s32 D_82B085E8;

// Same code as func_82B02ABC with limit D_82B085E8, but GS grows the offsets at
// 0xC/0xE from 0 toward the targets at 0x18/0x1A and, at the limit, clears the state
// at 0x6 and copies the pair at 0x14 to 0xC.
void func_82B02CA0(void *arg0) {
    s32 result;
    s32 counter;
    s32 limit;

    result = 0;
    // FAKE: the dead read of the counter and the empty if (0) below color the registers
    // like the original, as in func_82B02ABC; diff score 70 without either one.
    counter = *(s16 *)((u8 *)arg0 + 8);
    limit = D_82B085E8;
    *(s16 *)((u8 *)arg0 + 8) = *(s16 *)((u8 *)arg0 + 8) + 1;
    if (0) {
    }
    counter = *(s16 *)((u8 *)arg0 + 8);
    if (counter < limit) {
        *(s16 *)((u8 *)arg0 + 0xC) = (*(s16 *)((u8 *)arg0 + 0x18) * counter) / limit;
        *(s16 *)((u8 *)arg0 + 0xE) = (*(s16 *)((u8 *)arg0 + 0x1A) * counter) / limit;
    } else {
        result = 1;
    }
    if (result != 0) {
        *(s16 *)((u8 *)arg0 + 6) = 0;
        *(s16 *)((u8 *)arg0 + 8) = 0;
        *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0xC) = *(struct PackedWord82B01BB8 *)((u8 *)arg0 + 0x14);
    }
}
#endif

#ifdef VERSION_US
extern s32 D_82B085EC;
extern s16 D_82B12458;
void func_82B02D84(void *arg0) {
    s32 count;
    s32 limit;
    s16 mode;
    s16 *p;
    mode = *(s16 *)((u8 *)arg0 + 0x50);
    *(s16 *)((u8 *)arg0 + 0x54) = D_82B12458;
    p = (s16 *)((u8 *)arg0 + 0x50);
    switch (mode) {
    case 0:
        if (p[3] != p[2]) { p[0] = 1; p[1] = 0; }
        p[4] = 0;
        break;
    case 1:
        limit = D_82B085EC;
        p[1] = p[1] + 1;
        count = p[1];
        if (count < limit) p[4] = (s16)((count * 0xFF) / limit);
        else { p[0] = 0; p[4] = 0; p[3] = p[2]; }
        break;
    }
}
#endif

#ifdef VERSION_US
extern void func_82B02ABC(void *);
extern void func_82B02BA4(void *);
extern void func_82B02CA0(void *);
extern void func_82B02D84(void *);
void func_82B02E50(void *arg0) {
    u16 temp_v0;

    temp_v0 = (*(u16 *)((u8 *)(arg0) + (6)));
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_82B02ABC(arg0);
        break;
    case 3:
        func_82B02BA4(arg0);
        break;
    case 4:
        func_82B02CA0(arg0);
        break;
    }
    if ((*(s16 *)((u8 *)(arg0) + (0))) == 3) {
        func_82B02D84(arg0);
    }
}
#endif

#ifdef VERSION_US
extern struct Color82B01BB8 D_82B085F0;
extern struct Color82B01BB8 D_82B085F4;
void func_82B02EDC(void *arg0) {
    struct Color82B01BB8 saved_a;
    struct Color82B01BB8 saved_b;

    saved_a = D_82B085F0;
    saved_b = D_82B085F4;
    if (*(u16 *)((u8 *)arg0 + 4) & 1) {
        if (*(u16 *)((u8 *)arg0 + 4) & 2) {
            *(struct Color82B01BB8 *)((u8 *)arg0 + 0x4C) = saved_a;
        } else {
            *(struct Color82B01BB8 *)((u8 *)arg0 + 0x4C) = saved_b;
        }
    } else {
        *(struct Color82B01BB8 *)((u8 *)arg0 + 0x4C) = saved_b;
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/24/fragment24_150C10/func_82B02F78.s")
#endif

#ifdef VERSION_US
extern s16 *D_82B085FC[];
extern s32 D_82B085F8;
extern s32 func_8004C990(s32, s32);
extern s32 func_8004D19C(s32, s32, s32, s32, s32);
extern void func_82B0284C(u8 *arg0, u8 *arg1);
extern u8 D_80094E38[];
extern Gfx * D_800D0510;
void func_82B0341C(u8 *arg0, s32 arg1) {
    s16 *table;
    u8 *tail;
    s32 value;
    s16 coords[4];
    Gfx *gfx;
    func_82B0284C(arg0, (u8 *)coords);
    table = D_82B085FC[*(s16 *)(arg0 + 2)];
    tail = arg0 + 0x50;
    if (arg1 != 0) {
        *(u16 *)(tail + 2) = *(u16 *)(tail + 2) + 1;
        if ((u16)*(u16 *)(tail + 2) % 3 == 0) {
            *(s16 *)(tail + 0) = *(s16 *)(tail + 0) + 1;
            if (*(s16 *)(tail + 0) >= D_82B085F8) {
                *(s16 *)(tail + 0) = 0;
            }
        }
    }
    value = func_8004C990(0x4F, table[*(s16 *)(tail + 0)]);
    gSPDisplayList(D_800D0510++, D_80094E38);
    gDPSetRenderMode(D_800D0510++, 0x0F0A7008, 0);
    func_8004D19C(coords[0] + 6, coords[1] + 0xE, value, 0, 0);
}
#endif

#ifdef VERSION_US
extern s16 D_82B08610[];
extern s16 D_82B0861C[5][2];
extern void func_82B0284C(u8 *, u8 *);
extern void func_82B0341C(u8 *, s32);
extern void func_800498C4(void);
extern void func_800499EC(void);
extern void func_800496A4(s32, s32);
extern void func_8004972C(s32, s32, s32, s32);
extern void *func_8004C874(s32, s32);
extern void func_800495F8(s32, s32, s32, const char *, ...);
void Panel_DrawHeadingAndOptions(u8 *panel, s32 animate) {
    s32 i;
    s32 y;
    s16 *heading;
    s16 *entries;
    Pair02198 coords;
    s16 id;
    const char *text;
    func_82B0284C(panel, (u8 *)&coords);
    func_82B0341C(panel, animate);
    func_800498C4();
    func_8004972C(255, 255, 255, 255);
    heading = D_82B08610;
    if (heading[*(s16 *)(panel + 2)] >= 0) {
        func_800496A4(4, -1);
        text = func_8004C874(27, heading[*(s16 *)(panel + 2)]);
        func_800495F8(coords.x + 68, coords.y + 6, 1, text);
    }
    y = 0;
    func_800496A4(8, 0);
    entries = (s16 *)D_82B0861C;
    for (i = 0; i < 2; i++) {
        id = entries[*(s16 *)(panel + 2) * 2 + i];
        if (id >= 0) {
            text = func_8004C874(27, id);
            func_800495F8(coords.x + 68, coords.y + y + 77, 1, text);
            y += 23;
        }
    }
    func_800499EC();
}
#endif

#ifdef VERSION_US
extern s16 D_82B08630[];
extern void func_800498C4(void);
extern void func_8004972C(s32, s32, s32, s32);
extern void func_800496A4(s32, s32);
extern void func_800495F8(s32, s32, s32, const char *, ...);
extern void func_800499EC(void);
void func_82B03688(u8 *arg0) {
    s32 i;
    s32 y;
    s16 coords[8];

    func_82B0284C(arg0, (u8 *)coords);
    func_800498C4();
    func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
    func_800496A4(8, 0);
    y = 0;
    for (i = 0; D_82B08630[i] >= 0; i++) {
        func_800495F8(coords[0] + 0x31, coords[1] + y + 9, 1, func_8004C874(0x1B, D_82B08630[i]));
        y += 0x18;
    }
    func_800499EC();
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/24/fragment24_150C10/func_82B0373C.s")
#endif

#ifdef VERSION_US
extern void func_82B0284C(u8 *, u8 *);
extern void func_800498C4(void);
extern void func_800496A4(s32, s32);
extern void func_8004972C(s32, s32, s32, s32);
extern void *func_8004C874(s32, s32);
extern void func_800495F8(s32, s32, s32, const char *, ...);
extern void func_800499EC(void);
void func_82B038BC(void *arg0) {
    struct { s16 x; s16 y; s32 pad[2]; } pair;
    s32 color;
    func_82B0284C(arg0, (u8 *)&pair);
    func_800498C4();
    func_800496A4(0x10, 0);
    func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
    color = func_8004C874(0x1B, 0x17);
    func_800495F8(pair.x + 0xE3, pair.y + 9, 1, color);
    func_800499EC();
}
#endif

#ifdef VERSION_US
extern s32 func_8004C990(s32, s32);
extern void func_8004B35C(s32, s32, s32, s32, s32);
void func_82B03934(s32 arg0, s32 arg1) { s32 temp = func_8004C990(0x156, 0); func_8004B35C(arg0, arg1, 0x78, 0x20, temp); }
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/24/fragment24_150C10/func_82B03978.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/24/fragment24_150C10/func_82B03F38.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/24/fragment24_150C10/func_82B04008.s")
#endif

#ifdef VERSION_US
extern void func_8004D998(s32, s32, u8 *, s32, s32);
extern s32 func_8004D19C(s32, s32, s32, s32, s32);
extern s32 func_8004C990(s32, s32);
extern Gfx * D_800D0510;
void func_82B041C8(s32 arg0, s32 arg1, u8 *arg2, s32 arg3, s32 arg4) {
    s32 var_a1;
    var_a1 = (arg3 & 5) ? arg4 : 0xFF;
    gDPPipeSync(D_800D0510++);
    if (var_a1 == 0xFF) {
        gDPSetRenderMode(D_800D0510++, 0x0F0A7008, 0);
    } else {
        gDPSetRenderMode(D_800D0510++, 0x00504240, 0);
    }
    gDPSetEnvColor(D_800D0510++, 0xFF, 0xFF, 0xFF, var_a1);
    if (arg2 != NULL) {
        func_8004D998(arg0, arg1, arg2, 0, 0);
    } else {
        func_8004D19C(arg0, arg1, func_8004C990(0x50, 0), 0, 0);
    }
}
#endif

#ifdef VERSION_US
extern Gfx *D_800D0510;
extern void func_80044270(s16, s16, s16, s16, s32, s32, s32, s32, s32);
void func_82B042D8(s16 arg0, s16 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 var_a1; Gfx *gfx; s16 *coords;
    gfx = (Gfx *)func_8004C990(0x9A, 0);
    if (gfx != NULL && arg2 != 0) {
        var_a1 = (arg4 & 8) ? arg5 : 0xFF;
        gDPPipeSync(D_800D0510++);
        if (var_a1 == 0xFF) { gDPSetRenderMode(D_800D0510++, 0x0F0A7008, 0); } else { gDPSetRenderMode(D_800D0510++, 0x00504240, 0); }
        if (arg3 != 0) { gDPSetEnvColor(D_800D0510++, 0xFF, 0xAA, 0, var_a1); } else { gDPSetEnvColor(D_800D0510++, 0x82, 0x82, 0x82, var_a1); }
        coords = (s16 *)gfx;
        func_80044270(arg0, arg1, coords[0], coords[1], 0, 0, 0x400, 0x400, 0);
    }
}
#endif

#ifdef VERSION_US
extern void func_800496A4(s32, s32);
extern void func_8004972C(s32, s32, s32, s32);
extern void func_800495F8(s32, s32, s32, const char *, ...);
extern u8 D_82B085CC[];
extern u8 D_82B085D0[];
void func_82B04430(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 var_a3;
    u8 *var_v0;
    if (arg3 & 5) {
        var_a3 = arg4;
        var_v0 = &D_82B085D0;
    } else {
        var_a3 = 0xFF;
        var_v0 = &D_82B085CC;
    }
    func_800496A4(4, 0);
    func_8004972C(var_v0[0], var_v0[1], var_v0[2], var_a3);
    func_800495F8(arg0, arg1, 0, arg2);
}
#endif

#ifdef VERSION_US
extern void func_800496A4(s32, s32);
extern void func_8004972C(s32, s32, s32, s32);
extern void func_8004C594(s32, s32);
extern s32 func_8004C8A0(void *, s32, s32, s32);
extern void func_800495F8(s32, s32, s32, const char *, ...);
extern u8 D_82B085CC[];
extern u8 D_82B085D0[];
void func_82B044B8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 buffer[0x24];
    u8 *color;
    s32 alpha;
    func_800496A4(4, 0);
    alpha = 0xFF;
    color = D_82B085CC;
    if (arg3 & 2) {
        alpha = arg4;
        color = D_82B085D0;
    } else {
        alpha = 0xFF;
        color = D_82B085CC;
    }
    func_8004972C(color[0], color[1], color[2], alpha);
    func_8004C594(3, arg2);
    alpha = func_8004C8A0(buffer, 0x20, 0x1B, 0x2A);
    func_800495F8(arg0, arg1, 0, alpha);
}
#endif

#ifdef VERSION_US
extern u8 D_82B085CD;
extern u8 D_82B085CE;
extern void func_800496A4(s32, s32);
extern void func_8004972C(s32, s32, s32, s32);
extern void *func_8004C874(s32, s32);
extern void func_800495BC(s32, s32, s32);
void func_82B04558(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 alpha;
    alpha = 0xFF;
    if (arg3 & 5) {
        alpha = arg4;
    } else {
        alpha = 0xFF;
    }
    func_800496A4(4, 0);
    func_8004972C(D_82B085CC[0], D_82B085CD, D_82B085CE, alpha);
    switch (arg2) {
    case 0:
        return;
    case 1:
        func_800495BC(arg0, arg1, func_8004C874(0x1B, 0x2B));
        break;
    case 2:
        func_800495BC(arg0, arg1, func_8004C874(0x1B, 0x2C));
        break;
    }
}
#endif

#ifdef VERSION_US
extern Gfx D_80094DB8[];
extern void Gfx_FillRectRgba(s16, s16, s16, s16, s32, s32, s32, s32);
extern void func_8004989C(s32);
extern void func_800495F8(s32, s32, s32, const char *, ...);
extern void func_800496A4(s32, s32);
extern void func_8004972C(s32, s32, s32, s32);
extern void func_800498C4(void);
extern void func_800499EC(void);
extern void func_8004C594(s32, s32);
extern s32 func_8004C8A0(void *, s32, s32, s32);
extern Gfx * D_800D0510;
void func_82B04624(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4)
{
    u8 b[0x88];
    gSPDisplayList(D_800D0510++, D_80094DB8);
    Gfx_FillRectRgba((s16)a0, (s16)a1, 0x17F, 0x60, 0xFF, 0, 0x32, a3);
    func_800498C4();
    func_800496A4(0x10, 0);
    func_8004972C(0xFF, 0xFF, 0, a4);
    func_8004989C(0x20);
    func_8004C594(3, a2);
    func_800495F8(a0 + 0xBF, a1 + 0x14, 1, func_8004C8A0(b, 0x80, 0x1B, 0x38));
    func_800499EC();
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/24/fragment24_150C10/func_82B04718.s")
#endif

#ifdef VERSION_US
extern void func_82B0284C(u8 *, u8 *);
extern void func_800498C4(void);
extern void func_800496A4(s32, s32);
extern void func_8004972C(s32, s32, s32, s32);
extern void *func_8004C874(s32, s32);
extern void func_800495F8(s32, s32, s32, const char *, ...);
extern void func_800499EC(void);
extern s16 D_82B12696[];
void func_82B0504C(void *arg0) {
    struct { s16 x; s16 y; s32 pad[3]; } pair;
    s16 index;
    s32 color;
    func_82B0284C(arg0, (u8 *)&pair);
    func_800498C4();
    func_800496A4(0x10, 0);
    func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
    index = *(s16 *)((u8 *)arg0 + 2);
    if (D_82B12696[index] != 0) {
        color = func_8004C874(0x1B, index + 0x2D);
        func_800495F8(pair.x + 0x4E, pair.y + 0xD, 1, color);
    }
    func_800499EC();
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/24/fragment24_150C10/func_82B050E8.s")
#endif

#ifdef VERSION_US
extern void Panel_DrawHeadingAndOptions(u8 *, s32);
extern void func_82B03688(u8 *);
extern void func_82B0373C(void);
extern void func_82B03978(void);
extern void func_82B03F38(void);
extern void func_82B04008(void);
extern void func_82B04718(void);
extern void func_82B050E8(void);
void func_82B05494(void *arg0, s32 arg1) {
    switch (*(s16 *)arg0) {
    case 1: Panel_DrawHeadingAndOptions(arg0, arg1); break;
    case 2: func_82B03688(arg0); break;
    case 3: func_82B0373C(); break;
    case 4: func_82B038BC(arg0); break;
    case 5: func_82B03978(); break;
    case 6: func_82B03F38(); break;
    case 7: func_82B04008(); break;
    case 8: func_82B04718(); break;
    case 9: func_82B0504C(arg0); break;
    case 10: func_82B050E8(); break;
    }
}
#endif

#ifdef VERSION_US
extern void *D_82B126A4;
extern s16 D_82B12466;
extern s16 D_82B12468;
void func_82B0556C(void) {
    s32 result;
    result = 1;
    if (*(s16 *)((u8 *)D_82B126A4 + 4) == 0) {
        result = 0;
    } else {
        result = 1;
    }
    D_82B12466 = result;
    D_82B12468 = result;
}
#endif

#ifdef VERSION_US
/* mkdraft:func_82B055A0 begin */
extern u8 D_82B12450[0xFF8];
extern s16 D_82B12466;
extern s16 D_82B12464[4];
extern s16 D_82B12468;
extern s16 D_82B1246A;
extern void func_82B0556C(void);

// NON_MATCHING: Register allocation and instruction scheduling still differ from retail.
#ifdef NON_MATCHING
void func_82B055A0(void) {
    u8 *temp_v0;
    s32 i;
    temp_v0 = (*(u8 **)((u8 *)(&D_82B12450) + 0x254));
    (*(s16 *)((u8 *)(&D_82B12450) + 0xC)) = 0;
    (*(s16 *)((u8 *)(&D_82B12450) + 0xE)) = (*((s16 *)(((u8 *)(temp_v0)) + 4)));
    (*(s16 *)((u8 *)(&D_82B12450) + 0x10)) = (*((s16 *)(((u8 *)(temp_v0)) + 6)));
    (*(s16 *)((u8 *)(&D_82B12450) + 0x12)) = (*((s16 *)(((u8 *)(temp_v0)) + 8)));
    for (i = 0; i < 4; i++) {
        D_82B12464[i] = 1;
    }
    D_82B1246A = 1;
    func_82B0556C();
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/24/fragment24_150C10/func_82B055A0.s")
#endif
/* mkdraft:func_82B055A0 end */
#endif

#ifdef VERSION_US
extern u8 D_82B12450[0xFF8];
extern void func_82B0556C(void);
void func_82B0560C(void) {
    u8 *base;
    base = (u8 *)&D_82B12450;
    *(s16 *)((u8 *)(*(void **)(base + 0x254)) + 4) = *(s16 *)(base + 0xE);
    *(s16 *)((u8 *)(*(void **)(base + 0x254)) + 6) = *(s16 *)(base + 0x10);
    *(s16 *)((u8 *)(*(void **)(base + 0x254)) + 8) = *(s16 *)(base + 0x12);
    func_82B0556C();
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/24/fragment24_150C10/func_82B05654.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/24/fragment24_150C10/func_82B05920.s")
#endif

#ifdef VERSION_US
extern void func_82B06360(s32);
extern void func_82B060A0(s32);
void func_82B05E3C(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 2:
        func_82B060A0(1);
        return;
    case 6:
        func_82B06360(0);
        /* fallthrough */
    case 3:
    case 4:
        return;
    }
}
#endif

#ifdef VERSION_US
extern u8 D_82B12450[0xFF8];
void func_82B05E98(s32 arg0, s32 arg1, u16 arg2, s32 arg3, s32 arg4, s32 arg5, u8 arg6) {
    u8 *base;
    u8 *half;
    if (arg0 >= 0 && arg0 < 2) {
        base = (u8 *)&D_82B12450 + (arg0 << 2);
        *(s32 *)(base + 0xBBC) = arg1;
        half = (u8 *)&D_82B12450 + (arg0 << 1);
        *(s16 *)(half + 0xBC4) = arg2;
        *(s16 *)(half + 0xBC8) = arg3;
        *(s32 *)(base + 0xBCC) = arg4;
        *(s32 *)(base + 0xBD4) = arg5;
        *(s16 *)(half + 0xBDC) = arg6;
    }
}
#endif

#ifdef VERSION_US
void *func_82B02800(s32, s32);

void func_82B05EF0(s32 arg0, s32 arg1, u16 arg2, s32 arg3, s32 arg4, s32 arg5) {
    void *temp_v0;

    if ((arg0 >= 0) && (arg0 < 2)) {
        temp_v0 = func_82B02800(8, arg0);
        if (temp_v0 != NULL) {
            (*(s32 *)((u8 *)(temp_v0) + (0x50))) = arg1;
            (*(u16 *)((u8 *)(temp_v0) + (0x54))) = arg2;
            (*(s16 *)((u8 *)(temp_v0) + (0x56))) = (s16) arg3;
            (*(s32 *)((u8 *)(temp_v0) + (0x58))) = arg4;
            (*(s32 *)((u8 *)(temp_v0) + (0x5C))) = arg5;
        }
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/24/fragment24_150C10/func_82B05F60.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/24/fragment24_150C10/func_82B060A0.s")
#endif

#ifdef VERSION_US
extern s16 D_82B12456;

#pragma COALESCE_AT_LUI(func_82B062BC, D_82B12450, D_82B12456)

void func_82B062BC(void) {
    if (func_82B02870() != 0) {
        *(s16 *)D_82B12450 = 2;
        D_82B12456 = 0;
        func_82B01054(2);
    }
}

#endif

#ifdef VERSION_US
extern void _bzero(void *, s32);
extern void *func_8004C874(s32, s32);
extern void HAL_Strcpy(void *, s32);
extern s16 D_82B0865C[];
void func_82B062F8(void *arg0, s32 arg1) {
    _bzero(arg0, 0x58);
    if (arg1 < 4) {
        ((u8 *)arg0)[0x1D] = ((s16 *)&D_82B0865C)[arg1];
        HAL_Strcpy((u8 *)arg0 + 0x34, func_8004C874(0x1B, 0x30));
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/24/fragment24_150C10/func_82B06360.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/24/fragment24_150C10/func_82B0671C.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/24/fragment24_150C10/func_82B06C98.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/24/fragment24_150C10/func_82B070B8.s")
#endif

#ifdef VERSION_US
/* mkdraft:func_82B072DC begin */
extern s16 D_82B1246C;

extern void *D_80087200;

// Compares the D_82B1246C value from before the func_82B02870() gate with the
// value left by the two 0xC-button clamps, reports a change with
// func_800226C0(1), then dispatches the 0x8 word's 0x8000/0x4000 buttons.
// The address local and the compare read straight from memory are what give the
// target's frame (0x20 bytes, ra at 0x14, the saved value at 0x18): a named
// compare temporary scores 195, named clamp temporaries 250, and reading the
// extern directly instead of through the local scores 4588
// (matching_notes/try_candidate.py, IDO 7.1).
// Needs `extern void func_800226C0();` at file scope: the three calls pass
// arguments and the retail file declares that extern old-style.


void func_82B072DC(void) {
    s16 *D_82B1246C_ptr = &D_82B1246C;
    s32 sp18;
    s32 input;

    sp18 = (s32) (*D_82B1246C_ptr);
    if (func_82B02870() != 0) {
        if ((*(u16 *)((u8 *)D_80087200 + 0xC)) & 0x800) {
            (*D_82B1246C_ptr) = (*D_82B1246C_ptr) - 1;
            if ((*D_82B1246C_ptr) < 0) {
                (*D_82B1246C_ptr) = 0;
            }
        }
        if ((*(u16 *)((u8 *)D_80087200 + 0xC)) & 0x400) {
            (*D_82B1246C_ptr) = (*D_82B1246C_ptr) + 1;
            if ((*D_82B1246C_ptr) >= 4) {
                (*D_82B1246C_ptr) = 3;
            }
        }
        if (sp18 != (*D_82B1246C_ptr)) {
            func_800226C0(1);
        }
        input = *(u16 *)((u8 *)D_80087200 + 8);
        if (input & 0x8000) {
            func_82B02A34(func_82B02800(1, 3), 1);
            func_82B02A34(func_82B02800(6, 0), 0);
            func_82B06360(1);
            func_800226C0(0x8D);
            return;
        }
        if (input & 0x4000) {
            func_82B029B8(func_82B02800(1, 3), -1);
            func_82B02A34(func_82B02800(6, 0), 1);
            func_82B060A0(1);
            func_800226C0(3);
        }
    }
}
/* mkdraft:func_82B072DC end */
#endif

#ifdef VERSION_US
/* mkdraft:func_82B07454 begin */
extern s16 D_82B1246E;
extern s16 D_82B12470;
extern void *D_80087200;
extern void *func_82B02800(s32, s32);
extern void func_82B02A34(void *, s32);
extern void func_82B029B8(u8 *, s32);
extern void func_82B06360(s32);
extern void func_82B060A0(s32);
extern s32 func_82B02870(void);

// Moves the cup cursor D_82B1246E with the pad word at D_80087200+0xC: bit 0x800 decrements
// it (clamped at 0), bit 0x400 increments it (clamped at D_82B12470-1). A changed cursor
// reports func_800226C0(1). The pad word at D_80087200+0x8 then selects the confirm path
// (bit 0x8000: func_82B06360(1), then func_800226C0(0x8D) when the cursor is below
// D_82B12470, else func_800226C0(5)) or the cancel path (bit 0x4000:
// func_82B029B8(..., -1), func_82B02A34(..., 1), func_82B060A0(1), func_800226C0(3)).


void func_82B07454(void) {
    s16 *D_82B1246E_ptr = &D_82B1246E;
    s32 sp18;
    s32 temp_v0_2;
    s16 *D_82B12470_ptr = &D_82B12470;

    sp18 = (*D_82B1246E_ptr);
    if (func_82B02870() != 0) {
        if ((*D_82B12470_ptr) > 0) {
            if ((*(u16 *)((u8 *)D_80087200 + 0xC)) & 0x800) {
                if (--(*D_82B1246E_ptr) < 0) {
                    (*D_82B1246E_ptr) = 0;
                }
            }
            if ((*(u16 *)((u8 *)D_80087200 + 0xC)) & 0x400) {
                if (++(*D_82B1246E_ptr) > (*D_82B12470_ptr) - 1) {
                    (*D_82B1246E_ptr) = (*D_82B12470_ptr) - 1;
                }
            }
        }
        if (sp18 != (*D_82B1246E_ptr)) {
            func_800226C0(1);
        }
        temp_v0_2 = (*(u16 *)((u8 *)D_80087200 + 0x8));
        if (temp_v0_2 & 0x8000) {
            if ((*D_82B1246E_ptr) < (*D_82B12470_ptr)) {
                func_82B02A34(func_82B02800(1, 4), 1);
                func_82B02A34(func_82B02800(7, 0), 0);
                func_82B06360(1);
                func_800226C0(0x8D);
                return;
            }
            func_800226C0(5);
            return;
        }
        if (temp_v0_2 & 0x4000) {
            func_82B029B8(func_82B02800(1, 4), -1);
            func_82B02A34(func_82B02800(7, 0), 1);
            func_82B060A0(1);
            func_800226C0(3);
        }
    }
}
/* mkdraft:func_82B07454 end */
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/24/fragment24_150C10/func_82B0760C.s")
#endif

#ifdef VERSION_US
/* mkdraft:func_82B07960 begin */
extern u8 D_82B12450[4088];
extern u16 D_82B12454;
extern s16 D_82B12456;
extern s16 D_82B1245A;
extern s16 D_82B126A0;
extern s16 D_82B13008;
extern void func_800226C0();
extern void *D_80087200;
extern s32 func_82B02870(void);
extern void func_82B02A34(void *, s32);
extern void func_82B060A0(s32);
// Fragment24 handler: when func_82B02870 reports nonzero, it services the
// halfword flags at D_82B12450 and, if bit 0x4000 of the word D_80087200
// points at is set, dispatches on the s16 at D_82B13008.
//   case 0  D_82B12450 (s16 at +0x0) = 9
//           D_82B12456 (s16 at +0x6) = 0
//           D_82B1245A (s16 at +0xA) = -1
//   case 1  if D_82B126A0 (s16 at +0x250) > 0, call
//           func_82B02A34(*(void **)(entry + 0xB18), 0) for each of
//           D_82B126A0 entries walking 4 bytes at a time, then func_82B060A0(1)
// Both cases fall through to func_800226C0(3). Before the switch, a zero
// D_82B12456 is raised to 1 with func_800226C0(5).
//   82B079C8  lui  $at,%hi(D_82B12450)      <- loaded before the dispatch
//   82B079CC  beqz $v0,.L82B079E8
//   82B079E8  sh   $t1,%lo(D_82B12450)($at)
//   82B079EC  sh   $zero,%lo(D_82B12456)($at)   <- reuses that $at
//   82B079F0  lui  $at,%hi(D_82B1245A)

// NON_MATCHING: Register allocation and instruction scheduling still differ from retail.
#ifdef NON_MATCHING
void func_82B07960(void) {
    u8 *base = (u8 *)&D_82B12450;
    u8 *entry;
    s32 i = 0;

    if (func_82B02870() != 0) {
        if (*(s16 *)((u8 *)&D_82B12454 + 2) == 0) {
            D_82B12456 = 1;
            func_800226C0(5);
        }
        if (*(u16 *)((u8 *)D_80087200 + 8) & 0x4000) {
            switch (D_82B13008) {
            case 0:
                *(s16 *)D_82B12450 = 9;
                D_82B12456 = 0;
                D_82B1245A = -1;
                break;
            case 1:
                if (D_82B126A0 > 0) {
                    entry = (u8 *)&D_82B12450;
                    i = 0;
                    do {
                        func_82B02A34(*(void **)(entry + 0xB18), 0);
                        i++;
                        entry += 4;
                    } while (i < *(s16 *)(base + 0x250));
                }
                func_82B060A0(1);
                break;
            }
            func_800226C0(3);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/24/fragment24_150C10/func_82B07960.s")
#endif
/* mkdraft:func_82B07960 end */
#endif

#ifdef VERSION_US
extern u8 D_82B12450[0xFF8];
extern s16 D_82B12456;
extern s32 func_82B028CC(void);

/* Ground truth shares the D_82B12450 store's delay-slot `lui $at` with the
   D_82B12456 clear; IDO gives each extern its own lui, so the fold is required. */
#pragma COALESCE_AT_LUI(func_82B07A5C)
/* mkdraft:func_82B07A5C begin */
void func_82B07A5C(void) {
    s16 *counter = &D_82B12456;
    if (func_82B028CC() != 0) {
        if (++*counter >= 2) {
            *(s16 *)D_82B12450 = 9;
            *counter = 0;
        }
    }
}
/* mkdraft:func_82B07A5C end */
#endif

void func_82B07AB4(void) {
}

#ifdef VERSION_US
extern u16 D_82B12454;
extern u8 D_82B12450[0xFF8];
extern s16 D_82B12452;
extern s16 D_82B12D10;
extern void func_82B062BC(void);
extern void func_82B0671C(void);
extern void func_82B06C98(void);
extern void func_82B072DC(void);
extern void func_82B07454(void);
extern void func_82B0760C(void);
extern void func_82B07960(void);
extern void func_82B07A5C(void);
extern void func_82B07AB4(void);
extern void func_82B02E50(void *);
extern void func_82B00E10(void);

/* mkdraft:func_82B07ABC begin */
extern u16 D_82B12454;
extern u8 D_82B12450[0xFF8];
extern s16 D_82B12452;
extern s16 D_82B12D10;
extern void func_82B062BC(void);
extern void func_82B0671C(void);
extern void func_82B06C98(void);
extern void func_82B072DC(void);
extern void func_82B07454(void);
extern void func_82B0760C(void);
extern void func_82B07960(void);
extern void func_82B07A5C(void);
extern void func_82B07AB4(void);
extern void func_82B02E50(void *);
extern void func_82B00E10(void);

s32 func_82B07ABC(void) {
    u8 *var_s0;
    u8 *end;
    if (D_82B12454 & 1) {
        func_82B00E10();
        switch (*(s16 *)D_82B12450) {
        case 1:
            func_82B062BC();
            break;
        case 2:
            func_82B0671C();
            break;
        case 3:
            func_82B06C98();
            break;
        case 4:
            func_82B072DC();
            break;
        case 5:
            func_82B07454();
            break;
        case 6:
            func_82B0760C();
            break;
        case 7:
            func_82B07960();
            break;
        case 8:
            func_82B07A5C();
            break;
        case 9:
            func_82B07AB4();
            break;
        }
        var_s0 = (u8 *)&D_82B12452 - 2, end = (u8 *)&D_82B12D10;
        do {
            if (*(s16 *)(var_s0 + 0x258) != 0) {
                func_82B02E50(var_s0 + 0x258);
            }
            var_s0 += 0x70;
        } while (var_s0 != end);
    }
    return (*(u16 *)((u8 *)&D_82B12452 + 2) & 1) != 0;
}
/* mkdraft:func_82B07ABC end */
#endif

#ifdef VERSION_US
extern s16 D_82B12458;
extern s16 D_82B12694;
extern void func_8004B314(s32, s32, s32, s32);
extern u8 D_82B12450[0xFF8];
void func_82B07BEC(void) {
    void *var_s0;
    s16 sp24[4];
    var_s0 = NULL;
    switch (*(s16 *)D_82B12450) {
    case 2:
    {
        var_s0 = *(void **)((u8 *)&D_82B12450 + (D_82B12458 << 2) + 0xB68);
        break;
    }
    case 6:
    {
        var_s0 = func_82B02800(9, D_82B12694);
        break;
    }
    default:
        break;
    }
    if (var_s0 != NULL) {
        func_82B0284C((u8 *)var_s0, (u8 *)&sp24[0]);
        func_8004B314(sp24[0], sp24[1], *(s16 *)((u8 *)var_s0 + 0x48), *(s16 *)((u8 *)var_s0 + 0x4A));
    }
}
#endif

#ifdef VERSION_US
extern u8 D_80094E38[];
extern u8 *func_8004CA60(u8 *);
extern void func_800459AC(u8 *, u8, u8, u16, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_80044270(s16, s16, s16, s16, s32, s32, s32, s32, s32);
extern Gfx * D_800D0510;
void func_82B07C88(void) { s32 var_s0; s32 var_s5; s32 temp_v0; s32 var_s1; s32 var_s4; temp_v0 = func_8004C990(0x152, 0); gSPDisplayList(D_800D0510++, D_80094E38); gDPSetRenderMode(D_800D0510++, 0x0F0A4000, 0); gDPSetEnvColor(D_800D0510++, 0xC8, 0xBE, 0xA0, 0xFF); var_s4 = 0; var_s5 = 0; do { func_800459AC(((*(u16 *)((u8 *)temp_v0 + 0)) << 5) * var_s4 + func_8004CA60((u8 *)temp_v0), *(u8 *)((u8 *)temp_v0 + 4), *(u8 *)((u8 *)temp_v0 + 5), *(u16 *)((u8 *)temp_v0 + 0), 0x20, 1, 0, 0, 2, 7, 0, 0, 0); var_s1 = 0; var_s0 = var_s5; loop_2: if (var_s0 < 0x1E0) func_80044270(0, var_s0, 0x280, 0x20, 0, 0, 0x400, 0x400, 0); var_s1 += 0x80; var_s0 += 0x80; if (var_s1 != 0x200) goto loop_2; var_s4 += 1; var_s5 += 0x20; } while (var_s4 != 4); }
#endif

#ifdef VERSION_US
extern s16 D_82B1269C;
extern void func_80006F70(Gfx **, s16, s16, s16, s16);
extern s32 func_8004D19C(s32, s32, s32, s32, s32);
extern u16 D_82B12454;
// Advance archive image 333 opacity and draw it; zero also redraws the clipped background.
void ImageFade_UpdateAndDraw(s32 skip_background) {
    s16 alpha;
    u16 *image;
    s32 x;
    image = (u16 *)func_8004C990(333, 0);
    if (D_82B12454 & 2) {
        alpha = D_82B1269C;
        if (alpha < 255) {
            alpha += 25;
            if (alpha > 255) alpha = 255;
        }
    } else {
        alpha = D_82B1269C;
        if (alpha > 0) {
            alpha -= 25;
            if (alpha < 0) alpha = 0;
        }
    }
    D_82B1269C = alpha;
    if (alpha > 0) {
        x = 328 - (s32)image[0] / 2;
        if (skip_background == 0) {
            func_80006F70(&D_800D0510, x, 199, (s16)image[0], image[1]);
            func_82B07C88();
        }
        gSPDisplayList(D_800D0510++, D_80094E38);
        gDPSetEnvColor(D_800D0510++, 255, 255, 50, D_82B1269C);
        func_8004D19C(328, 199, (s32)image, 1, 0);
    }
}
#endif

#ifdef VERSION_US
/* mkdraft:func_82B07F84 begin */
extern void func_80006F70(Gfx **, s16, s16, s16, s16);
extern u16 D_82B12454;
extern s16 D_82B1269E;

void func_82B07F84(s32 arg0) {
    s16 timer;
    s32 str;
    s32 width;
    s32 pad1;
    s32 pad2;
    s32 x;

    if (D_82B12454 & 4) {
        timer = D_82B1269E;
        if (timer < 0xFF) {
            timer += 0x19;
            if (timer > 0xFF) {
                timer = 0xFF;
            }
        }
    } else {
        timer = D_82B1269E;
        if (timer > 0) {
            timer -= 0x19;
            if (timer < 0) {
                timer = 0;
            }
        }
    }
    D_82B1269E = timer;
    if (timer > 0) {
        str = func_8004C874(0x1B, 0x37);
        width = func_80049148(0x10, 0, (void *)str);
        x = 0x140 - width / 2;
        if (arg0 == 0) {
            func_80006F70(&D_800D0510, x, 0xCA, width, 0x18);
            func_82B07C88();
        }
        func_800498C4();
        func_800496A4(0x10, 0);
        timer = D_82B1269E;
        func_8004972C(0xFF, 0xFF, 0xFF, timer);
        func_800495BC(x, 0xCA, str);
        func_800499EC();
    }
}
/* mkdraft:func_82B07F84 end */
#endif

#ifdef VERSION_US
/* mkdraft:func_82B080D0 begin */
extern u8 D_82B12450[0xFF8];
extern u16 D_82B12454;
extern s16 D_82B12696[];
extern s16 D_82B12452;
extern s16 D_82B12D10;
extern Gfx *D_800D0510;
extern void func_80006F70(Gfx **, s16, s16, s16, s16);
extern void *func_82B00F14(s32);
extern s32 func_82B00F68(s32);
extern void func_82B0284C(u8 *, u8 *);
extern void func_82B02F78(u8 *);
extern void func_82B05494(void *, s32);
extern void func_82B07BEC(void);
extern void func_82B07C88(void);
extern void func_82B07F84(s32);
extern void ImageFade_UpdateAndDraw(s32);
extern s32 func_81700908(void);
extern s32 func_81700AF4(s32, void *);
extern s32 func_81700B2C(s32);
extern s32 func_81700B58(s32);

// Draws the panel labels of the active menu screen. When bit 0 of the mode word at
// D_82B12450+4 is set: switch to fullscreen when func_82B00F68("FULL") reports the
// fullscreen text, otherwise draw a strip per controller port (func_81700B2C returns
// the strip width, func_81700B58 whether it is centred) and clear the screen. Then walk
// the 20 panel entries at D_82B12450+0x258 (stride 0x70, ending at D_82B12D10) and
// position the label sprite of each entry that is present (entry[0] != 0 and the
// halfword at entry+6 != 0). The label id comes from entry[0]; entries of type 1 and 9
// first decide func_82B05494's flag/active argument from the cursor row (panelY) and
// from D_82B12696[entry[1]]. Returns bit 0 of D_82B12454.


s32 func_82B080D0(void) {
    // Declaration order fixes the home-slot offsets: cursor and string fill the two
    // words retail keeps above panelY, and panelY/fullscreen/pos/bounds follow in that
    // order down the frame.
    s16 *cursor;
    s32 string;
    s32 panelY;
    s32 fullscreen;
    s16 pos[2];
    s16 *panel;
    void *object;
    s32 active;
    s32 flag;
    s32 i;
    s32 count;
    s16 bounds[2];
    s32 pad[2]; // FAKE: retail's frame is 0x88, not 0x80; these two words stand in for
                // the two compiler-temp slots its frame has below bounds. Diff score 156
                // without them (frame 0x80, every slot below panelY moves down 8).

    fullscreen = 0;
    panelY = *(s16 *)(D_82B12450 + 8);
    if (*(u16 *)(D_82B12450 + 4) & 1) {
        if (func_82B00F68(0x46554C4C)) {
            func_82B07C88();
            fullscreen = 1;
        }
        if (!fullscreen) {
            for (i = 0; i < 2; i++) {
                func_81700AF4(i, pos);
                count = func_81700B2C(i);
                if (count > 0) {
                    if (func_81700B58(i)) {
                        func_80006F70(&D_800D0510, (s16)(pos[0] - count), (s16)(pos[1] - 10), (s16)count, 0x1C);
                    } else {
                        func_80006F70(&D_800D0510, pos[0], (s16)(pos[1] - 10), (s16)count, 0x1C);
                    }
                    func_82B07C88();
                }
            }
            func_80006F70(&D_800D0510, 0, 0, 0x280, 0x1E0);
        }
        func_81700908();
        // s16 cursor: +0x38 elements per entry is the entry stride 0x70, and
        // +0x12C elements is the 0x258-byte offset of the first entry.
        cursor = (s16 *)((u8 *)&D_82B12452 - 2);
        do {
            panel = cursor + 0x12C;
            if (*(s16 *)((u8 *)cursor + 0x258) != 0 && *(u16 *)((u8 *)panel + 6) != 0) {
                flag = 0;
                active = 1;
                switch (panel[0]) {
                case 1:
                    if (panelY == panel[1] && !(D_82B12454 & 0x10)) {
                        flag = 1;
                    }
                    break;
                case 9:
                    if (D_82B12696[panel[1]] == 0) {
                        active = 0;
                    }
                    break;
                }
                if (active) {
                    string = 0;
                    switch (panel[0]) {
                    case 1: string = panel[1] + 0x43555030; break;
                    case 2: string = 0x434E4647; break;
                    case 3: string = 0x4D535347; break;
                    case 4: string = 0x53504331; break;
                    case 5: string = 0x53504332; break;
                    case 6: string = 0x43484C47; break;
                    case 7: string = 0x45444954; break;
                    case 8: string = panel[1] + 0x504B4D30; break;
                    case 9: string = panel[1] + 0x42544C30; break;
                    case 10: string = 0x45524F52; break;
                    }
                    if (fullscreen == 0) {
                        object = func_82B00F14(string);
                        func_82B0284C((u8 *)panel, (u8 *)bounds);
                        if (object != NULL) {
                            *(s16 *)((u8 *)object + 4) = -1;
                            *(s16 *)((u8 *)object + 8) = bounds[0] - 2;
                            *(s16 *)((u8 *)object + 0xA) = *(s16 *)((u8 *)panel + 0x48) + bounds[0] + 5;
                            *(s16 *)((u8 *)object + 0xE) = bounds[1] - 2;
                            *(s16 *)((u8 *)object + 0xC) = *(s16 *)((u8 *)panel + 0x4A) + bounds[1] + 5;
                        }
                    } else {
                        object = func_82B00F14(string);
                        if (object != NULL) {
                            *(s16 *)((u8 *)object + 4) = 1;
                        }
                    }
                    if (func_82B00F68(string)) {
                        func_82B07C88();
                    }
                    func_82B02F78((u8 *)panel);
                    func_82B05494(panel, flag);
                }
            }
            cursor += 0x38;
        } while (cursor != &D_82B12D10);
        func_80006F70(&D_800D0510, 0, 0, 0x280, 0x1E0);
        func_82B07BEC();
        ImageFade_UpdateAndDraw(fullscreen);
        func_82B07F84(fullscreen);
    }
    return (D_82B12454 & 1) != 0;
}
/* mkdraft:func_82B080D0 end */
#endif

#ifdef VERSION_US
void func_82B084AC(void) {
    func_82B060A0(0);
}
#endif

#ifdef VERSION_US
s32 func_82B084CC(void) {
    return 0;
}
#endif

#ifdef VERSION_US
extern u8 D_82B12450[0xFF8];
extern s16 D_82B1245A;

s16 func_82B084D4(void) {
    s16 var_v1;

    var_v1 = -2;
    if (*(s16 *)D_82B12450 == 9) {
        var_v1 = D_82B1245A;
    }
    return var_v1;
}
#endif

#ifdef VERSION_US
extern s16 D_82B12452;
s32 func_82B084FC(void) {
    return D_82B12452;
}
#endif

#ifdef VERSION_US
extern s16 D_82B1246C;
s32 func_82B08508(void) {
    return D_82B1246C;
}
#endif

#ifdef VERSION_US
extern s16 D_82B1246E;
s32 func_82B08514(void) {
    return D_82B1246E;
}
#endif
