#include "global.h"


#ifdef VERSION_US
int ListSlots_FindSelectedRecord(void *context) {
    typedef struct { s32 count; u8 unk_04[16]; u32 upper : 16; u32 selected : 1; u32 lower : 15; } SlotSelectionRecord;
    typedef struct { u8 unk_0000[8592]; SlotSelectionRecord records[4]; } SlotSelectionData;
    SlotSelectionRecord *record;
    s32 result;
    s32 i;
    result = -1;
    record = (*(SlotSelectionData **)((u8 *)context + 4))->records;
    for (i = 0; i != 4; i++, record++) {
        if (record->selected) {
            result = i;
            break;
        }
    }
    return result;
}

extern void *D_87F119DC;
extern void func_87F0B4AC(void *, f32 *, f32 *, s16 *);
void func_87E0C93C(void) {
    void *state = D_87F119DC;
    func_87F0B4AC(
        *(void **)((u8 *)*(void **)((u8 *)state + 0x38) + 0x0C),
        (f32 *)((u8 *)state + 0x48),
        (f32 *)((u8 *)state + 0x54),
        (s16 *)((u8 *)state + 0x42));
}

extern Gfx *D_800D0510;
extern void *D_8009491C;
extern void GeoRender_ApplyMaterialState();
void func_87E0C974(s32 arg0, s32 arg1) {
    void *context;

    if (arg0 == 5) {
        gDPPipeSync(D_800D0510++);
        gDPSetCombine(D_800D0510++, 0xFFFFFF, 0xFFFCF238);
        context = *(void **)((u8 *)D_8009491C + 0x14);
        gSPSegment(D_800D0510++, 0xF,
                   *(void **)((u8 *)*(void **)((u8 *)context + 4) + 8));
        gSPDisplayList(D_800D0510++, *(void **)context);
        GeoRender_ApplyMaterialState();
    }
}

extern void func_87F0BD30(void *, s32, s32, s32);
extern void ListSlots_ResetEntryState(void *, s32);
void func_87E0CA2C(void *arg0, s32 arg1) {
    u8 *entry;
    s32 color1;

    entry = (u8 *)arg0 + 0x28 + arg1 * 0xEC;
    entry[0xE8] = arg1;
    *(void **)(entry + 0x88) = (u8 *)*(void **)((u8 *)arg0 + 4) + 0x2190 + arg1 * 0x18;

    *(s32 *)(entry + 0xD4) = (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 4) + 0x2182) & (1 << arg1)) ? arg1 + 6 : arg1 + 2;

    *(s32 *)(entry + 0xD8) = 0;
    entry[0xE9] &= ~0x80;

    switch (arg1) {
        case 0:
            color1 = 0xC8D2FFFF;
            *(s32 *)(entry + 0xE4) = 0x32325AFF;
            break;
        case 1:
            color1 = 0xC3FFC3FF;
            *(s32 *)(entry + 0xE4) = 0x324632FF;
            break;
        case 2:
            color1 = 0xFFCDCDFF;
            *(s32 *)(entry + 0xE4) = 0x5A3232FF;
            break;
        case 3:
            color1 = 0xFFF5A5FF;
            *(s32 *)(entry + 0xE4) = 0x5A3C28FF;
            break;
    }

    func_87F0BD30(entry + 0xDC, 0x140, 0x24, color1);
    ListSlots_ResetEntryState(arg0, arg1);
}

extern void func_8004C8C0(s32);

void func_87E0CB88(void) {
    func_8004C8C0(0x1B2);
    func_8004C8C0(0x160);
    func_8004C8C0(0x1B4);
    func_8004C8C0(0x161);
    func_8004C8C0(0x19F);
}

extern u8 D_87E1A400[];
extern s32 main_pool_get_available(void);
extern s32 MainPool_AllocState(s32, s32);
extern s32 process_geo_layout(s32, void *);
extern void MainPool_FinalizeAllocation(s32);
void func_87E0CBC8(void *arg0) {
    s32 temp = MainPool_AllocState(main_pool_get_available(), 0);
    *(s32 *)((u8 *)arg0 + 8) = process_geo_layout(temp, D_87E1A400);
    MainPool_FinalizeAllocation(temp);
}

extern void ListSlots_DrawPanel(void *);
extern f32 D_87E1A434[][3];
void func_87E0CC18(void *arg0) {
    u8 *node;
    s32 i;
    f32 scale;

    func_87F0ADE0((u8 *)arg0 + 0x10, 4);
    scale = 0.7f;
    for (i = 0; i < 4; i++) {
        func_87E0CA2C(arg0, i);
        node = func_87F0AEC0((u8 *)arg0 + 0x10, func_87E0C93C, (void *)0x0F000000, 320, 36, ListSlots_DrawPanel,
                             (u8 *)arg0 + 0x28 + i * 0xEC);
        if (node != NULL) {
            func_8003F1DC(node + 0x24);
            func_8003F114(node + 0x24, 0, -1, *(void **)((u8 *)arg0 + 8));
            *(f32 *)(node + 0x5C) = scale;
            *(f32 *)(node + 0x58) = scale;
            *(f32 *)(node + 0x54) = scale;
            *(f32 *)(node + 0x48) = D_87E1A434[i][0];
            *(f32 *)(node + 0x4C) = D_87E1A434[i][1];
            *(f32 *)(node + 0x50) = D_87E1A434[i][2];
            func_87F0AFD0((u8 *)arg0 + 0x28 + i * 0xEC, node + 0x48, node + 0x54, node + 0x42);
            node[0x25] &= ~1;
        }
    }
    func_87E11E18((u8 *)arg0 + 0x3D8, 3);
}

extern void func_87F02684(s32);
extern void func_87E134C0(void);
void func_87E0CD84(s32 arg0) {
    func_87F02684(arg0 + 0x10);
    func_87E134C0();
}

void func_87E0CDAC(void *arg0) {
    void *var_v0;

    var_v0 = (*(void **)((u8 *)(arg0) + (0x1C)));
    if (var_v0 != NULL) {
        do {
            (*(u8 *)((u8 *)(var_v0) + (0x25))) = (u8) ((*(u8 *)((u8 *)(var_v0) + (0x25))) & ~1);
            var_v0 = (*(void **)((u8 *)(var_v0) + (4)));
        } while (var_v0 != NULL);
    }
}

void func_87E0CDDC(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *entry;
    u8 *temp_v1;
    u8 *flags;
    s32 start;
    s32 end;
    s32 i;

    // FAKE: the s32 round trip puts arg0 second in the addu; diff score 10 without it.
    entry = (u8 *)((s32)arg0 + arg1 * 0xEC);
    *(s32 *)(entry + 0x100) = 0;
    temp_v1 = entry + 0x28;
    flags = entry + 0xB4;
    for (i = 0; i < *(s32 *)(*(u8 **)(arg0 + 4) + 0x2188); i++) {
        start = **(s32 **)(temp_v1 + 0x88);
        end = **(s32 **)(temp_v1 + 0x88) + arg2;
        if (start <= i && i < end) {
            *flags |= 3;
        }
        flags += 8;
    }
}

void func_87E0CE60(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *temp_a3;
    u8 *temp_v0;
    s32 i;
    s32 value;

    *(s32 *)(arg0 + arg1 * 0xEC + 0x100) = 0;
    temp_v0 = arg0 + arg1 * 0xEC + 0x28;
    temp_a3 = arg0 + arg1 * 0xEC + 0xB4;
    for (i = 0; i < *(s32 *)(*(u8 **)(arg0 + 4) + 0x2188); i++) {
        value = **(s32 **)(temp_v0 + 0x88);
        if (i >= value - arg2 && i < value) {
            *temp_a3 |= 5;
        }
        temp_a3 += 8;
    }
}

// Refresh nine slot flags and clear each slot value to -1.
void ListSlots_ResetEntryState(void *arg0, s32 arg1) {
    u8 *entry;
    u8 *slot;
    s32 i;
    entry = (u8 *)arg0 + arg1 * 236 + 40;
    slot = (u8 *)arg0 + arg1 * 236 + 180;
    for (i = 0; i < 9; i++) {
        if (i < **(s32 **)(entry + 136)) {
            *slot = 1;
        } else {
            *slot = 0;
        }
        if (i < *(s32 *)(*(u8 **)((u8 *)arg0 + 4) + 8584)) {
            *slot |= 8;
        }
        *(s32 *)(slot + 4) = -1;
        slot += 8;
    }
}

extern f32 D_87E1A464[][3];
extern void func_87F0B1A4(u8 *, f32 *, f32, f32, f32, s32, s32);
extern void func_87F0B2F4(u8 *, s16 *, f32, f32, f32, s32, s32);
extern void func_87F0B24C(u8 *, u8 *, f32, f32, f32, s32, s32);
void func_87E0D0A0(u8 *arg0) {
    u8 *node;
    s32 i;
    u8 *object;

    i = 0;
    for (node = *(u8 **)(arg0 + 0x1C); node != NULL; node = *(u8 **)(node + 4)) {
        object = *(u8 **)(*(u8 **)(node + 0x38) + 0xC);
        func_87F0B1A4(object, (f32 *)(node + 0x48), D_87E1A464[i][0], D_87E1A464[i][1], D_87E1A464[i][2], i * 5 + 10, 0x5000);
        func_87F0B2F4(object, (s16 *)(node + 0x42), 0.0f, 0.0f, 0.0f, i * 5 + 10, 0x8000);
        func_87F0B24C(object, node + 0x54, 0.7f, 0.7f, 0.7f, i * 5 + 10, 0);
        i++;
    }
}

extern f32 D_87E1A464[][3];
extern void func_87F0B1A4(u8 *, f32 *, f32, f32, f32, s32, s32);
extern void func_87F0B24C(u8 *, u8 *, f32, f32, f32, s32, s32);
extern void func_87F0B2F4(u8 *, s16 *, f32, f32, f32, s32, s32);
void func_87E0D18C(u8 *arg0) {
    u8 *node;
    s32 i;
    u8 *object;

    i = 0;
    for (node = *(u8 **)(arg0 + 0x1C); node != NULL; node = *(u8 **)(node + 4)) {
        object = *(u8 **)(*(u8 **)(node + 0x38) + 0xC);
        func_87F0B1A4(object, (f32 *)(node + 0x48), D_87E1A464[i][0], D_87E1A464[i][1], D_87E1A464[i][2], i * 5 + 5, 0x5000);
        func_87F0B2F4(object, (s16 *)(node + 0x42), 0.0f, 0.0f, 0.0f, i * 5 + 5, 0x8000);
        func_87F0B24C(object, node + 0x54, 0.7f, 0.7f, 0.7f, i * 5 + 5, 0);
        i++;
    }
}

extern void func_87F0B2F4(u8 *, s16 *, f32, f32, f32, s32, s32);
extern void func_87F0B1A4(u8 *, f32 *, f32, f32, f32, s32, s32);
extern f32 D_87E1A434[][3];
void ListSlots_StartAlternatingAnimations(u8 *state) {
    u8 *node;
    s32 i;
    u8 *object;
    f32 angle;
    s32 duration;
    f32 *position;
    i = 0;
    for (node = *(u8 **)(state + 28); node != NULL; node = *(u8 **)(node + 4)) {
        position = D_87E1A434[i];
        object = *(u8 **)(*(u8 **)(node + 56) + 12);
        angle = (i % 2) ? -360.0f : 360.0f;
        duration = (i % 2) * 5 + 10;
        func_87F0B1A4(object, (f32 *)(node + 72), position[0], position[1], position[2], duration, 0x2000);
        func_87F0B2F4(object, (s16 *)(node + 66), 0.0f, angle, 0.0f, duration, 0);
        i++;
    }
}

extern void func_87E0D18C(u8 *);
void func_87E0D3A0(u8 *arg0) {
    func_87E0D18C(arg0);
}

void func_87E0D3C0(u8 *arg0) {
    *(s32 *)(arg0 + 0x3F4) = 3;
    *(s32 *)(arg0 + 0x3FC) = 0;
    *(s32 *)(arg0 + 0x3F8) = *(s8 *)(*(u8 **)(arg0 + 4) + 0x218D);
    func_87E0D18C(arg0);
}

void func_87E0D3F4(u8 *arg0) {
    *(s32 *)(arg0 + 0x3F4) = 4;
    *(s32 *)(arg0 + 0x3FC) = 0;
    func_87E0D18C(arg0);
}

void func_87E0D41C(u8 *arg0) {
    func_87E0D18C(arg0);
}

extern void func_87F0B1A4(u8 *, f32 *, f32, f32, f32, s32, s32);
extern void Audio_PlayDefaultSound(u16);
void func_87E0D43C(void *arg0) {
    u8 *node;
    s32 offset;
    s32 found;
    u8 *model;

    node = *(u8 **)((u8 *)arg0 + 0x1C);
    found = 0;
    if (node != NULL) {
        offset = 0;
        do {
            model = *(u8 **)(*(u8 **)(node + 0x38) + 0xC);
            if (((u32)*(s32 *)(*(u8 **)((u8 *)arg0 + 4) + offset + 0x21A4) << 18) >> 31) {
                func_87F0B1A4(model, (f32 *)(node + 0x48), *(f32 *)(node + 0x48),
                              *(f32 *)(node + 0x4C), *(f32 *)(node + 0x50) + 20.0f, 10, 0x1000);
                found = 1;
            }
            node = *(u8 **)(node + 4);
            offset += 0x18;
        } while (node != NULL);
    }
    if (found) {
        Audio_PlayDefaultSound(0xCF16);
    }
}

extern void ListSlots_StartAlternatingAnimations(u8 *);
void func_87E0D500(u8 *arg0) {
    ListSlots_StartAlternatingAnimations(arg0);
}

extern void func_87F0B1A4(u8 *, f32 *, f32, f32, f32, s32, s32);
extern void func_87F0B2F4(u8 *, s16 *, f32, f32, f32, s32, s32);
extern f32 D_87E1A434[][3];
void ListSlots_UpdateAlternatingAnimations(u8 *state) {
    u8 *node;
    s32 i;
    u8 *object;
    f32 angle;
    s32 duration;
    f32 *position;
    i = 0;
    for (node = *(u8 **)(state + 28); node != NULL; node = *(u8 **)(node + 4)) {
        position = D_87E1A434[i];
        object = *(u8 **)(*(u8 **)(node + 56) + 12);
        if (**(s32 **)(object + 136) < *(s32 *)(*(u8 **)(state + 4) + 8584)) {
            angle = (i % 2) ? -360.0f : 360.0f;
            duration = (i % 2) * 5 + 10;
            func_87F0B1A4(object, (f32 *)(node + 72), position[0], position[1], position[2], duration, 0x2000);
            func_87F0B2F4(object, (s16 *)(node + 66), 0.0f, angle, 0.0f, duration, 0);
        } else {
            func_87F0B1A4(object, (f32 *)(node + 72), 0, 90.0f, *(f32 *)(node + 80), 20, 0x4000);
        }
        i++;
    }
}

extern void func_87F0B1A4(u8 *, f32 *, f32, f32, f32, s32, s32);
typedef struct D6BCNode {
    u8 pad0[4];
    struct D6BCNode *next;
    u8 pad1[0x30];
    u8 *child;
    u8 pad2[0xC];
    f32 values[3];
} D6BCNode;
void func_87E0D6BC(void *arg0) {
    D6BCNode *var_s0;
    var_s0 = *(D6BCNode **)((u8 *)arg0 + 0x1C);
    if (var_s0 != NULL) {
        do {
            func_87F0B1A4(*(u8 **)(var_s0->child + 0xC), (f32 *)((u8 *)var_s0 + 0x48),
                var_s0->values[0], var_s0->values[1] - -120.0f, var_s0->values[2], 30, 0x3000);
            var_s0 = var_s0->next;
        } while (var_s0 != NULL);
    }
}

void func_87E0D73C(u8 *arg0) {
    ListSlots_StartAlternatingAnimations(arg0);
}

void func_87E0D75C(u8 *arg0) {
    u8 *data;
    s32 index;

    *(s32 *)(arg0 + 0x3F4) = 2;
    *(s32 *)(arg0 + 0x3FC) = 0;
    *(s32 *)(arg0 + 0x3F8) = 0;
    index = ListSlots_FindSelectedRecord(arg0);
    if (index == -1) {
        *(s8 *)(*(u8 **)(arg0 + 4) + 0x218D) = 0;
        return;
    }
    data = *(u8 **)(arg0 + 4);
    if (*(s32 *)(data + 0x2190 + index * 24) + *(s8 *)(data + 0x218D) > *(s32 *)(data + 0x2188)) {
        *(s8 *)(data + 0x218D) = *(s32 *)(data + 0x2188) - *(s32 *)(data + 0x2190 + index * 24);
    }
}

extern u32 func_8003570C(void);
extern void func_87E0D18C(u8 *);
s32 func_87E0D7D8(u8 *arg0) {
    s32 i;
    s32 selected;
    s32 max;
    s32 count;
    s32 ret;
    u8 *entry;

    max = 0;
    count = 0;
    func_87E0D18C(arg0);
    entry = arg0 + 0x28;
    for (i = 0; i < 4; i++, entry += 0xEC) {
        if (i == 0 || max < *(s32 *)*(void **)(entry + 0x88)) {
            max = *(s32 *)*(void **)(entry + 0x88);
        }
    }
    selected = max;
    ((s8 *)arg0)[0x408] = -1;
    entry = arg0 + 0x28;
    for (i = 0; i != 4; i++, entry += 0xEC) {
        if (selected - *(s32 *)*(void **)(entry + 0x88) == 0) {
            entry[0xE9] |= 0x80;
            count++;
            if ((s8)((s8 *)arg0)[0x408] == -1) {
                ((s8 *)arg0)[0x408] = i;
            }
        }
    }
    if (count == 1) {
        *(s32 *)(arg0 + 0x3F4) = 1;
        ret = 0;
    } else {
        *(s32 *)(arg0 + 0x3F4) = 0;
        ret = 1;
    }
    *(s32 *)(arg0 + 0x400) = 0;
    *(s32 *)(arg0 + 0x3FC) = 0;
    *(s32 *)(arg0 + 0x404) = (func_8003570C() % 9) + 8;
    return ret;
}

extern void func_87E0D0A0(u8 *);
extern void func_87E13558(u8 *, f32, f32, f32, s32);
extern u32 func_8003570C(void);
void func_87E0D8EC(u8 *arg0) {
    s32 selected;
    s32 i;
    s32 min;
    s32 count;
    u8 *entry;

    min = 0;
    count = 0;
    func_87E0D0A0(arg0);
    entry = arg0 + 0x28;
    for (i = 0; i < 4; i++, entry += 0xEC) {
        if (i == 0 || *(s32 *)*(void **)(entry + 0x88) < min) {
            min = *(s32 *)*(void **)(entry + 0x88);
        }
    }
    selected = min;
    ((s8 *)arg0)[0x408] = -1;
    entry = arg0 + 0x28;
    for (i = 0; i != 4; i++, entry += 0xEC) {
        if (selected - *(s32 *)*(void **)(entry + 0x88) == 0) {
            entry[0xE9] |= 0x80;
            count++;
            if ((s8)((s8 *)arg0)[0x408] == -1) {
                ((s8 *)arg0)[0x408] = i;
            }
        } else {
            entry[0xE9] &= 0xFF7F;
        }
    }
    if (count == 1) {
        *(s32 *)(arg0 + 0x3F4) = 0;
        *(s32 *)(arg0 + 0x3FC) = 0;
        *(s32 *)(arg0 + 0x400) = 0x3C;
        func_87E13558(((s8 *)arg0)[0x408] * 0x18C + *(u8 **)(arg0 + 0x18), -123.0f, -2.0f, 0.0f, 1);
    } else {
        *(s32 *)(arg0 + 0x3F4) = 0;
        *(s32 *)(arg0 + 0x400) = 0;
        *(s32 *)(arg0 + 0x3FC) = 0;
    }
    *(s32 *)(arg0 + 0x404) = (func_8003570C() % 9) + 4;
}

extern void ListSlots_ResetEntryState(void *, s32);
extern void func_87E134C0(void);
extern void func_87E13490(void);
extern void func_87E13480(void *);
extern void func_87E1366C(void);
void func_87E0DA4C(void *arg0) {
    s32 i;
    u8 *node;

    node = *(u8 **)((u8 *)arg0 + 0x1C);
    *(s32 *)((u8 *)arg0 + 0x3F4) = 4;
    if (node != NULL) {
        do {
            *(u8 *)(node + 0x25) |= 1;
            node = *(u8 **)(node + 4);
        } while (node != NULL);
    }
    i = 0;
    do {
        ListSlots_ResetEntryState(arg0, i);
        i += 1;
    } while (i != 4);
    func_87E134C0();
    func_87E13490();
    func_87E13480(NULL);
    func_87E1366C();
}

extern void func_87E0CC18(void *);
extern void func_87F0BD10();
void func_87E0DAE0(void *arg0, s32 arg1) {
    (*(s32 *)((u8 *)(arg0) + (0))) = 1;
    (*(s32 *)((u8 *)(arg0) + (4))) = arg1;
    (*(s32 *)((u8 *)(arg0) + (0x3F4))) = 4;
    (*(s32 *)((u8 *)(arg0) + (0x3FC))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x408))) = -1;
    func_87F0BD10();
    func_87E0CB88();
    func_87E0CBC8(arg0);
    func_87E0CC18(arg0);
}

extern void func_87E13654(void);
typedef struct { u8 unk_00[233]; s8 unk_E9; u8 unk_EA[2]; } SlotCycleEntry;
typedef u8 SlotCycleItem[396];
typedef struct {
    u8 unk_00[24];
    SlotCycleItem *unk_18;
    u8 unk_1C[12];
    SlotCycleEntry unk_28[4];
    u8 unk_3D8[28];
    s32 unk_3F4;
    u8 unk_3F8[4];
    s32 unk_3FC;
    s32 unk_400;
    s32 unk_404;
    s8 unk_408;
} SlotCycleState;

extern void func_87E13558(u8 *, f32, f32, f32, s32);
extern void Audio_PlayDefaultSound(u16);
void ListSlots_UpdateEntryCycling(u8 *context) {
    typedef struct { u8 unk_00[232]; u32 upper:8; u32 selected:1; u32 lower:23; } SlotCycleEntryFlags;
    s32 previous;
    if (((SlotCycleState *)context)->unk_3FC > ((SlotCycleState *)context)->unk_400) {
        previous = ((SlotCycleState *)context)->unk_408;
        do {
            (((SlotCycleState *)context)->unk_408)++;
            if (((SlotCycleState *)context)->unk_408 >= 4) {
                ((SlotCycleState *)context)->unk_408 = 0;
            }
        } while (!((SlotCycleEntryFlags *)(context + 40))[((SlotCycleState *)context)->unk_408].selected);
        ((SlotCycleState *)context)->unk_3FC = 0;
        (((SlotCycleState *)context)->unk_400)++;
        func_87E13558((u8 *)&(*(SlotCycleItem **)(context + 24))[((SlotCycleState *)context)->unk_408], -123.0f, -2.0f, 0.0f, 1);
        if (previous == ((SlotCycleState *)context)->unk_408) {
            if (((SlotCycleState *)context)->unk_400 <= ((SlotCycleState *)context)->unk_404) {
                ((SlotCycleState *)context)->unk_400 = ((SlotCycleState *)context)->unk_404;
            } else {
                Audio_PlayDefaultSound(0xCF01);
            }
        } else {
            Audio_PlayDefaultSound(0xCF01);
        }
    }
    if (((SlotCycleState *)context)->unk_404 < ((SlotCycleState *)context)->unk_400) {
        ((SlotCycleState *)context)->unk_3F4 = 1;
        ((SlotCycleState *)context)->unk_3FC = 0;
        func_87E13654();
        Audio_PlayDefaultSound(0xCF02);
    }
}

s32 func_87E0DC78(u8 *arg0) {
    s32 result = 0;
    if (*(s32 *)(arg0 + 0x3FC) >= 0x29) {
        result = 1;
    }
    return result;
}

extern void *D_87F119D8;
extern void func_87F026E8(void *, void *);
extern f32 D_80087E50[];
extern int ListSlots_FindSelectedRecord(void *);
extern void Audio_PlayDefaultSound(u16);
extern void ListSlots_ResetEntryState(void *arg0, s32 arg1);
extern void func_87F0B4AC(void *, f32 *, f32 *, s16 *);
extern void * D_87F119DC;
void ListSlots_UpdateTransferAnimation(void) {
    u8 *state;
    u8 *context;
    u8 *model;
    f32 angle;
    f32 scale;
    f32 sine;
    s32 rounded;
    s32 selected;
    context = *(u8 **)((u8 *)D_87F119DC + 32);
    state = D_87F119DC;
    model = *(u8 **)(state + 56) + 4;
    func_87F0B4AC(model, (f32 *)(state + 72), (f32 *)(state + 84), (s16 *)(state + 66));
    if (*(s32 *)(model + 132) != 0) {
        angle = ((f32)*(s32 *)(model + 108) / (f32)*(s32 *)(model + 112)) * 180.0f * 182.04167f;
        if (angle >= 0.0f) {
            rounded = (s32)(angle + 0.5f);
        } else {
            rounded = (s32)(angle - 0.5f);
        }
        sine = D_80087E50[(u16)rounded >> 4];
        scale = 0.5f * sine + 1.0f;
        *(f32 *)((u8 *)D_87F119DC + 92) = scale;
        *(f32 *)((u8 *)D_87F119DC + 88) = scale;
        *(f32 *)((u8 *)D_87F119DC + 84) = scale;
        Audio_PlayDefaultSound(0xCE0E);
    }
    if (*(s32 *)(*(u8 **)((u8 *)D_87F119DC + 56) + 136) == 0) {
        selected = ListSlots_FindSelectedRecord(context);
        if (selected != -1) {
            (*(s32 *)(*(u8 **)(context + 4) + selected * 24 + 8592))++;
            ListSlots_ResetEntryState(context, selected);
        }
        func_87F026E8(D_87F119D8, D_87F119DC);
        Audio_PlayDefaultSound(0xCF0C);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_310270/func_87E0DE34.s")

extern s32 func_80001FF0(void);
extern void func_87E0DE34(void *);

typedef struct {
    u8 pad[0x88];
    s32 *val;
    u8 pad2[0x60];
} Fragment63_SubStruct;
extern void ListSlots_ResetEntryState(void *, s32);
s32 func_87E0E110(void *arg0) {
    s32 sp24 = 0;
    s32 *sp20;
    s32 temp;

    sp20 = ((Fragment63_SubStruct *)((u8 *)arg0 + 0x28))[(s8)((u8 *)arg0)[0x408]].val;
    if ((*(s8 *)(*(u8 **)((u8 *)arg0 + 4) + 0x218D) == *(s32 *)((u8 *)arg0 + 0x3F8)) && (*(s32 *)((u8 *)arg0 + 0x3DC) == 0)) {
        sp24 = 1;
    } else {
        if ((((f32)func_80001FF0() / 60.0f) * 20.0f) >= 0.0f) {
            temp = (s32)((((f32)func_80001FF0() / 60.0f) * 20.0f) + 0.5f);
        } else {
            temp = (s32)((((f32)func_80001FF0() / 60.0f) * 20.0f) - 0.5f);
        }

        if (temp + 1 < *(s32 *)((u8 *)arg0 + 0x3FC)) {
            if (*sp20 == 0) {
                *(s8 *)(*(u8 **)((u8 *)arg0 + 4) + 0x218D) = *(s32 *)((u8 *)arg0 + 0x3F8);
            } else if (*(s32 *)((u8 *)arg0 + 0x3F8) < *(s8 *)(*(u8 **)((u8 *)arg0 + 4) + 0x218D)) {
                func_87E0DE34(arg0);
                *(s32 *)((u8 *)arg0 + 0x3FC) = 0;
                (*sp20)--;
                ListSlots_ResetEntryState(arg0, ((s8 *)arg0)[0x408]);
                (*(s32 *)((u8 *)arg0 + 0x3F8))++;
            }
        }
    }

    return sp24;
}

typedef struct unk_func_87E0E2C8_2190 {
    s32 unk_00;
    u8 unk_04[20];
} unk_func_87E0E2C8_2190;

typedef struct unk_func_87E0E2C8 {
    u8 unk_0000[8584];
    s32 unk_2188;
    u8 unk_218C[4];
    unk_func_87E0E2C8_2190 unk_2190[4];
} unk_func_87E0E2C8;

void func_87E0E2C8(void *arg0) {
    s32 *var_v1 = *(s32 **)((u8 *)arg0 + 56);
    u8 *var_a2 = *(u8 **)((u8 *)arg0 + 32);
    unk_func_87E0E2C8 *var_v0 = *(unk_func_87E0E2C8 **)(var_a2 + 4);
    s32 *var_a3 = &var_v0->unk_2190[*var_v1].unk_00;

    if (*var_a3 < var_v0->unk_2188) {
        (*var_a3)++;
        ListSlots_ResetEntryState(var_a2, *var_v1);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_310270/func_87E0E32C.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_310270/func_87E0E3EC.s")

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

M2C_UNK func_87E0E3EC(u8 *);                      /* extern */

s32 func_87E0E714(u8 *arg0) {
    s32 sp24;
    s32 temp_v0;
    s32 var_v1;

    sp24 = 0;
    if ((M2C_FIELD(arg0, s32 *, 0x3F8) == 0) && (M2C_FIELD(arg0, s32 *, 0x3DC) == 0)) {
        sp24 = 1;
    } else {
        if ((((f32) func_80001FF0() / 60.0f) * 20.0f) >= 0.0f) {
            var_v1 = (s32) ((((f32) func_80001FF0() / 60.0f) * 20.0f) + 0.5f);
        } else {
            var_v1 = (s32) ((((f32) func_80001FF0() / 60.0f) * 20.0f) - 0.5f);
        }
        if ((var_v1 + 1) < M2C_FIELD(arg0, s32 *, 0x3FC)) {
            temp_v0 = M2C_FIELD(arg0, s32 *, 0x3F8);
            if (temp_v0 > 0) {
                M2C_FIELD(arg0, s32 *, 0x3F8) = (s32) (temp_v0 - 1);
                func_87E0E3EC(arg0);
                M2C_FIELD(arg0, s32 *, 0x3FC) = 0;
            }
        }
    }
    return sp24;
}
s32 func_87E0E850(void *arg0)
{
  s32 var_v1;
  void *var_v0;
  u8 *new_var;
  var_v0 = *((void **) (((u8 *) arg0) + 0x1C));
  var_v1 = 1;
  if (var_v0 != 0)
  {
    do
    {
      new_var = (u8 *) (*((void **) (((u8 *) (*((void **) (((u8 *) var_v0) + 0x38)))) + 0xC)));
      if ((*((s32 *) (new_var + 0x84))) != 0)
      {
        var_v1 = 0;
      }
      var_v0 = *((void **) (((u8 *) var_v0) + 4));
    }
    while (var_v0 != 0);
  }
  return var_v1;
}

extern void ListSlots_UpdateEntryCycling(u8 *);
extern void func_87E120F8(void *);
extern void func_87F0277C(void *);
extern s32 func_87E0DC78(u8 *arg0);
extern s32 func_87E0E110(void *arg0);
extern s32 func_87E0E850(void *arg0);
s32 ListSlots_UpdateState(u8 *state) {
    s32 i;
    s32 result;
    u8 *entry;
    result = 1;
    if (func_87E0E850(state)) {
        *(s32 *)state = 1;
    } else {
        *(s32 *)state = 0;
    }
    if (*(s32 *)state == 1) {
        switch (*(u32 *)(state + 1012)) {
            case 3:
                if (func_87E0E714(state)) result = 0;
                break;
            case 2:
                if (func_87E0E110(state)) result = 0;
                break;
            case 0:
                ListSlots_UpdateEntryCycling(state);
                break;
            case 1:
                if (func_87E0DC78(state)) result = 0;
                break;
            case 4:
                result = 0;
                break;
        }
    }
    entry = state + 40;
    for (i = 0; i < 4; i++) {
        (*(s32 *)(entry + 216))++;
        entry += 236;
    }
    func_87E120F8(state + 984);
    func_87F0277C(state + 16);
    (*(s32 *)(state + 1020))++;
    return result;
}

extern void func_80007444(Gfx **, s32, s32, s32, s32, u16);
extern s32 func_8004C990(s32, s32);
extern s32 func_8004D19C(s32, s32, s32, s32, s32);
extern s32 func_8004D1FC(u8 *);
extern void GfxRect_DrawTextured(s16, s16, s16, s16, s16, s16, s16, s16, s32);
extern u8 *func_87E0167C(void);
extern void func_87F0BD48(void *);
extern void func_87F0D600(void *, s32, s32, s32, f32, f32);
extern f32 D_80088E50[];
extern Gfx D_80094E38[];
extern Gfx D_80094F50[];
extern s32 D_87E1A494[];
extern Gfx * D_800D0510;
void ListSlots_DrawPanel(void *context) {
    typedef union { struct { u8 r, g, b, a; } channels; u32 packed; } SlotPanelColor;
    typedef struct { u8 flags; u8 unk_01[3]; SlotPanelColor color; } SlotPanelIcon;
    typedef struct { s32 count; u8 unk_04[16]; u32 flags; } SlotPanelRecord;
    typedef struct { u16 width, height; SlotPanelColor color; } SlotPanelBackground;
    typedef struct {
        u8 unk_00[136];
        SlotPanelRecord *record;
        SlotPanelIcon slots[9];
        s32 resource;
        u32 tick;
        SlotPanelBackground background;
        SlotPanelColor color;
        u8 index;
        u8 flags;
        u8 unk_EA[2];
    } SlotPanelEntry;
    f32 angle;
    f32 pulse;
    s32 rounded;
    SlotPanelEntry *entry;
    SlotPanelIcon *slot;
    s32 frame;
    s32 i;

    entry = *(SlotPanelEntry **)((u8 *)context + 12);
    angle = (f32)(entry->tick % 360U) * 15.0f * 182.04167f;
    if (angle >= 0.0f) {
        rounded = (s32)(angle + 0.5f);
    } else {
        rounded = (s32)(angle - 0.5f);
    }
    pulse = 1.0f - D_80088E50[(u16)rounded >> 4];
    func_80007444(&D_800D0510, 0, 0, 320, 36, 0xFFFE);
    func_87F0BD48(&entry->background);
    gSPDisplayList(D_800D0510++, D_80094E38);
    gDPSetTextureFilter(D_800D0510++, G_TF_POINT);
    gDPSetRenderMode(D_800D0510++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
    gDPSetCombine(D_800D0510++, 0x377E6E, 0x11FCF279);
    gDPSetPrimColor(D_800D0510++, 0, 0, 0, 0, 0, 0);
    func_8004D19C(5, 5, func_8004C990(434, entry->resource), 0, 0);
    func_87F0D600(func_87E0167C(), entry->index, 5, 5, 1.0f, 1.0f);
    gSPDisplayList(D_800D0510++, D_80094E38);
    gDPSetTextureFilter(D_800D0510++, G_TF_POINT);
    gDPSetRenderMode(D_800D0510++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
    if ((entry->record->flags << 17) >> 31) {
        func_8004D19C(13, 0, func_8004C990(436, 0), 0, 0);
    }
    gDPPipeSync(D_800D0510++);
    slot = entry->slots;
    for (i = 0; i < 9; i++, slot++) {
        if (slot->flags & 8) {
            func_8004D1FC((u8 *)func_8004C990(352, D_87E1A494[5]));
            gDPSetCombine(D_800D0510++, 0xFFD3FF, 0xFFA6FF7F);
            gDPSetEnvColor(D_800D0510++, 0, 0, 0, 64);
            GfxRect_DrawTextured((s16)(i * 27 + 43), 6, 24, 24, 0, 0, 1024, 1024, 0);
        }
        if (slot->flags & 2) {
            slot->color.channels.a = 64.0f * pulse;
            slot->color.channels.r = slot->color.channels.g = slot->color.channels.b = 255;
            frame = 5;
        } else if (slot->flags & 4) {
            slot->color.channels.r = slot->color.channels.g = slot->color.channels.b = 64;
            frame = ((s32)entry->tick % 14) / 2;
        } else {
            slot->color.channels.r = slot->color.channels.g = slot->color.channels.b = 255;
            frame = ((s32)entry->tick % 14) / 2;
        }
        if (slot->flags & 1) {
            if (slot->color.channels.a < 245) {
                slot->color.channels.a += 10;
            } else {
                slot->color.channels.a = 255;
            }
            func_8004D1FC((u8 *)func_8004C990(352, D_87E1A494[frame]));
            gDPSetCombine(D_800D0510++, 0x50D2A1, 0xFFA7FFFF);
            gDPSetEnvColor(D_800D0510++, slot->color.channels.r, slot->color.channels.g, slot->color.channels.b, slot->color.channels.a);
            GfxRect_DrawTextured((s16)(i * 27 + 43), 6, 24, 24, 0, 0, 1024, 1024, 0);
        }
    }
    gDPPipeSync(D_800D0510++);
    gDPSetRenderMode(D_800D0510++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
    gDPSetCombine(D_800D0510++, 0xFFFFFF, 0xFFFEF379);
    gDPSetEnvColor(D_800D0510++, entry->color.channels.r, entry->color.channels.g, entry->color.channels.b, entry->color.channels.a);
    func_8004D19C(286, 6, func_8004C990(353, 0), 0, 0);
    gDPPipeSync(D_800D0510++);
    gDPSetCombine(D_800D0510++, 0xFFFFFF, 0xFFFCF279);
    func_8004D19C(294, 10, func_8004C990(415, entry->record->count), 0, 0);
    gSPDisplayList(D_800D0510++, D_80094F50);
}

extern void func_87F0AF4C(s32);
void func_87E0F124(s32 arg0) {
    func_87F0AF4C(arg0 + 16);
}

s32 func_87E0F144(void *arg0, s32 arg1) {
    s32 new_var;
    new_var = *((s32 *) (((u8 *) arg0) + 0x18));
    return (arg1 * 0x18C) + new_var;
}
#endif
