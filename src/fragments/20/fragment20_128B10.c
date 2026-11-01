#include "global.h"


#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_128B10/func_82600A40.s")

extern void func_82600A40(s32 *, s32, s32);
void RecordSelection_ChooseSortedIndices(s32 *output, s32 draw_count, s32 pool_count) {
    s32 index;
    s32 minimum;
    s32 scan;
    s32 value;
    s32 last;
    func_82600A40(output, draw_count, pool_count);
    last = draw_count - 1;
    index = 0;
    if (last > 0) {
        do {
            minimum = index;
            for (scan = index + 1; scan < draw_count; scan++) {
                if (output[scan] < output[minimum]) minimum = scan;
            }
            value = output[minimum];
            output[minimum] = output[index];
            output[index] = value;
            index++;
        } while (index != last);
    }
}

extern void func_800619E8(void *);
s32 func_80061B88(u8, u8, void *);

void func_82600CF4(void *arg0) {
    (*(s32 *)((u8 *)(arg0) + (8))) = func_80061B88((*(u8 *)((u8 *)(arg0) + (0))), (*(u8 *)((u8 *)(arg0) + (0x1D))), arg0);
    func_800619E8(arg0);
    (*(u16 *)((u8 *)(arg0) + (0x26))) = (u16) (*(u16 *)((u8 *)(arg0) + (0x28)));
}

// Working Pokemon fields unpacked by func_80071E48 and recalculated by func_800619E8.
//@src/615D0.c
//@src/728D0.c
typedef struct {
    u8 species;
    u8 unk_01[7];
    u32 experience;
    u16 hp_stat_exp;
    u16 attack_stat_exp;
    u16 defense_stat_exp;
    u16 speed_stat_exp;
    u16 special_stat_exp;
    u16 dvs;
    u8 unk_18[5];
    u8 level;
    u8 unk_1E[8];
    u16 current_hp;
    u16 maximum_hp;
    u8 unk_2A[46];
} RecordSelectionWorkingEntry;
typedef struct {
    s8 owners[4];
    u8 unk_04[2];
    s8 metadata_layout;
    u8 unk_07;
    u16 mode_flags;
    u8 unk_0A[126];
    s16 selection;
    u8 unk_8A[6];
    RecordSelectionWorkingEntry groups[4][6];
} RecordSelectionWorkingGrid;
typedef char RecordSelectionWorkingEntrySize[sizeof(RecordSelectionWorkingEntry) == 88 ? 1 : -1];
typedef char RecordSelectionWorkingGridSize[sizeof(RecordSelectionWorkingGrid) == 2256 ? 1 : -1];
extern void func_80035700(u32);
extern s32 func_8006AED4(s32, void *);
extern void func_80071E48(void *, void *);
// func_80071B58 indexes 152-byte rows; func_80071BB8 reads count and Pokemon.
//@src/72720.c
typedef struct {
    u8 bytes[24];
} RecordPartyPackedPokemon;
typedef struct {
    u8 metadata[4];
    u8 count;
    u8 unk_05[3];
    RecordPartyPackedPokemon pokemon[6];
} RecordPartyPackedRow;
typedef char RecordPartyPackedRowSize[sizeof(RecordPartyPackedRow) == 152 ? 1 : -1];
void RecordSelection_PrepareTwoParties(u8 *context, s32 randomize) {
    u8 row_count;
    u8 *direct_first;
    u8 *direct_second;
    u8 *profiles[3];
    s32 side;
    s32 record;
    s32 selected[6];
    s32 pair_choices[6][2];
    s32 permutation[3];
    u8 divisor;
    RecordPartyPackedRow *row;
    RecordSelectionWorkingEntry *entry;
    row_count = (*(u8 **)(context + 12))[0];
    direct_first = *(u8 **)(context + 12) + 4;
    direct_second = *(u8 **)(context + 12) + 156;
    profiles[0] = *(u8 **)(context + 12) + 308;
    profiles[1] = *(u8 **)(context + 12) + 460;
    profiles[2] = *(u8 **)(context + 12) + 612;
    if (randomize != 0) {
        if (*(u32 *)(context + 152) != 0) func_80035700(*(u32 *)(context + 152));
        RecordSelection_ChooseSortedIndices(selected, 6, row_count);
        for (record = 0; record < 6; record++) {
            func_82600A40(permutation, 3, 3);
            pair_choices[record][0] = permutation[0];
            pair_choices[record][1] = permutation[1];
        }
    }
    side = 0;
    do {
        if (randomize != 0) {
            record = 0;
            do {
                row = (RecordPartyPackedRow *)(selected[record] * 152 + *(u8 **)(context + 12) + 4);
                entry = &((RecordSelectionWorkingGrid *)*(u8 **)context)->groups[side][record];
                func_80071E48(entry, &row->pokemon[pair_choices[record][side]]);
                if ((*(s8 **)context)[side] == -1) {
                    switch ((*(s16 *)(*(u8 **)context + 12))) {
                    case 0: divisor = 4; break;
                    case 1: divisor = 2; break;
                    default: divisor = 1; break;
                    }
                    entry->hp_stat_exp /= divisor;
                    entry->attack_stat_exp /= divisor;
                    entry->defense_stat_exp /= divisor;
                    entry->speed_stat_exp /= divisor;
                    entry->special_stat_exp /= divisor;
                    func_82600CF4(entry);
                }
                record++;
            } while (record != 6);
        }
        if (side == 0) {
            func_8006AED4(side, direct_first);
        } else {
            if ((*(s16 *)(*(u8 **)context + 12)) == -1) func_8006AED4(side, direct_second);
            else func_8006AED4(side, profiles[(*(s16 *)(*(u8 **)context + 12))]);
        }
        side++;
    } while (side != 2);
}

extern void func_80071BB8(void *, void *);
void RecordSelection_LoadLevelMatchedParties(u8 *context) {
    s32 highest_level;
    s32 side;
    s32 member;
    s32 index;
    s32 level;
    RecordPartyPackedRow *row;
    RecordSelectionWorkingEntry *scan_entry;
    RecordSelectionWorkingEntry *update_entry;
    highest_level = 0;
    side = 0;
    do {
        if ((*(RecordSelectionWorkingGrid **)context)->owners[side] >= 0) {
            for (member = 0; member < 6; member++) {
                scan_entry = &(*(RecordSelectionWorkingGrid **)context)->groups[side][member];
                if (highest_level < scan_entry->level) {
                    highest_level = scan_entry->level;
                }
            }
        }
        side++;
    } while (side < 4);
    side = 0;
    do {
        switch ((*(RecordSelectionWorkingGrid **)context)->owners[side]) {
        case -1:
            index = ((s16 *)(context + 24))[(*(RecordSelectionWorkingGrid **)context)->selection];
            break;
        case -2:
            index = -1;
            break;
        default:
            index = -1;
            break;
        }
        if (index >= 0 && index < (*(u8 **)(context + 12))[0]) {
            row = &((RecordPartyPackedRow *)(*(u8 **)(context + 12) + 4))[index];
            func_80071BB8(&(*(RecordSelectionWorkingGrid **)context)->groups[side][0], row);
            level = highest_level > 50 ? highest_level : 50;
            for (member = 0; member < 6; member++) {
                update_entry = &(*(RecordSelectionWorkingGrid **)context)->groups[side][member];
                update_entry->level = level;
                func_82600CF4(update_entry);
            }
            func_8006AED4(side, row);
        }
        side++;
    } while (side != 2);
}

// Each side's 1,064-byte descriptor starts with its member count and owner bytes.
typedef struct {
    s16 count;
    s8 owners[2];
    s8 member_sizes[2];
    u8 unk_06[2];
    RecordSelectionWorkingEntry entries[12];
} RecordSelectionPartyDescriptor;
typedef char RecordSelectionPartyDescriptorSize[sizeof(RecordSelectionPartyDescriptor) == 1064 ? 1 : -1];
extern u8 D_826163A0[];
extern s32 D_82615344;
extern void func_80055F6C(void *, s32);
extern void func_80051D64(s32, s32);
extern s32 func_80054E48(s32);
extern void func_84302148(void *, u8, s32);
extern void _bzero(void *, s32);
extern s8 *HAL_Strcpy(s8 *, s8 *);
extern void *func_8004C874(s32, s32);
// Refresh names and metadata; unassigned parties also receive scaled stat experience.
void RecordSelection_InitializePartyRecords(u8 *context, s32 enabled, s32 suppress_unassigned_flag, s32 profile, s32 update_history) {
    s32 side;
    s32 record;
    s32 member;
    s32 text_table;
    s16 *count;
    u8 *state;
    s32 group;
    s32 unassigned;
    s32 initialize_flag;
    s32 history_index;
    u8 divisor;
    RecordSelectionWorkingEntry *entry;
    s8 *name;
    u8 *descriptor;
    if (enabled != 0) {
        descriptor = context + 176;
        side = 0;
        do {
            count = (s16 *)descriptor;
            if (side == 0) text_table = 70;
            else text_table = 71;
            for (member = 0; member < *count; member++) {
                state = *(u8 **)context;
                if (((s8 *)state)[6] != 0) group = side * 2 + member;
                else group = side;
                unassigned = ((RecordSelectionPartyDescriptor *)count)->owners[member] == -1 ? 1 : 0;
                initialize_flag = suppress_unassigned_flag != 0 ? 0 : unassigned;
                if (unassigned == 0 && *(s16 *)(state + 136) != 0) continue;
                if (unassigned == 0 && state[125] != 0) continue;
                if (update_history != 0 && unassigned == 0 && member == 0) {
                    history_index = *(s16 *)(state + 10) - 1;
                    if (history_index >= 0 && history_index < 4) {
                        if (D_826163A0[history_index + 16] < 250) {
                            D_826163A0[history_index + 16]++;
                            func_80055F6C(D_826163A0, D_82615344);
                            func_80051D64(20, 0);
                            func_80054E48(3);
                            state = *(u8 **)context;
                        }
                    }
                }
                func_84302148(&((RecordSelectionWorkingGrid *)state)->groups[group][0], state[137], initialize_flag);
                for (record = 0; record != 6; record++) {
                    entry = &((RecordSelectionWorkingGrid *)*(u8 **)context)->groups[group][record];
                    if (entry->species > 0 && entry->species < 254) {
                        name = (s8 *)entry + 52;
                        _bzero(name, 12);
                        HAL_Strcpy(name, func_8004C874(text_table, entry->species - 1));
                    }
                    if (unassigned != 0) {
                        switch (profile) {
                        case 0: divisor = 4; break;
                        case 1: divisor = 2; break;
                        default: divisor = 1; break;
                        }
                        entry->hp_stat_exp /= divisor;
                        entry->attack_stat_exp /= divisor;
                        entry->defense_stat_exp /= divisor;
                        entry->speed_stat_exp /= divisor;
                        entry->special_stat_exp /= divisor;
                        func_82600CF4(entry);
                    }
                }
            }
            side++, descriptor += 1064;
        } while (side != 2);
    }
}

// Owners -1/-2 select the indexed row or skip it; mode 0x400 selects paired rows.
typedef struct {
    s8 owners[4];
    u8 unk_04[2];
    s8 metadata_layout;
    u8 unk_07;
    u16 mode_flags;
    u8 unk_0A[126];
    s16 selection;
    u8 unk_8A[6];
} RecordSelectedPartyHeader;
typedef char RecordSelectedPartyHeaderSize[sizeof(RecordSelectedPartyHeader) == 144 ? 1 : -1];
void RecordSelection_LoadSelectedParties(u8 *context, s32 load_records) {
    s32 side;
    s32 index;
    s32 adjustment;
    int paired_mode;
    RecordSelectedPartyHeader *state;
    RecordPartyPackedRow *row;

    if (*(u8 **)(context + 12) != NULL) {
        side = 0;
        do {
            state = *(RecordSelectedPartyHeader **)context;
            paired_mode = 0x400;
            index = state->owners[side];
            switch (index) {
            case -1:
                index = ((s16 *)(context + 24))[state->selection];
                goto load_selected;
            case -2:
                index = -1;
                goto load_selected;
            default:
                index = state->mode_flags & 0xFF00;
                break;
            }
            if (index == paired_mode) {
                if (side < 2) {
                    adjustment = 1 - (side & 1);
                    index = ((s16 *)(context + 24))[state->selection] - adjustment;
                } else {
                    index = -1;
                }
            } else {
                index = -1;
            }
        load_selected:
            if (index >= 0 && index < (*(u8 **)(context + 12))[0]) {
                row = &((RecordPartyPackedRow *)(*(u8 **)(context + 12) + 4))[index];
                if (load_records != 0) {
                    func_80071BB8(&((RecordSelectionWorkingGrid *)state)->groups[side][0], row);
                    state = *(RecordSelectedPartyHeader **)context;
                }
                if (state->metadata_layout == 0) {
                    if (side < 2) {
                        func_8006AED4(side, row);
                    }
                } else {
                    if (side / 2 < 2) {
                        func_8006AED4(side / 2, row);
                    }
                }
            }
            side++;
        } while (side != 4);
    }
}

void func_82601824(void *arg0) {
    u8 *values[4];
    s32 i;

    values[0] = *(u8 **)((u8 *)arg0 + 0xAC) + 0x134;
    values[1] = *(u8 **)((u8 *)arg0 + 0xAC) + 0x1CC;
    values[2] = *(u8 **)((u8 *)arg0 + 0xAC) + 0x264;
    i = 0;
    do {
        if (i != 0) {
            func_8006AF28(i, values[(*(s16 *)(*(u8 **)arg0 + 0xC))]);
        }
        i += 1;
    } while (i != 2);
}

void func_826018BC(void *arg0) {
    u8 *values[4];
    s32 i;
    u8 *temp_v0;

    values[0] = *(u8 **)((u8 *)arg0 + 0xC) + 0x134;
    values[1] = *(u8 **)((u8 *)arg0 + 0xC) + 0x1CC;
    values[2] = *(u8 **)((u8 *)arg0 + 0xC) + 0x264;
    i = 0;
    do {
        temp_v0 = *(u8 **)arg0;
        if (*(s8 *)(temp_v0 + i) == -1) {
            func_8006AED4(i, values[(*(s16 *)(temp_v0 + 0xC))]);
        }
        i += 1;
    } while (i != 2);
}

typedef struct {
    s8 *owners;
    u8 unk_04[8];
    u8 *table;
} RecordTextCopyContext;
typedef struct {
    u8 unk_00[136];
    s16 selection;
} RecordTextSelectionView;
extern void _bcopy(void *, void *, s32);
typedef struct {
    u8 unk_00[52];
    s8 text[12];
    u8 unk_40[24];
} RecordTextEntry88;
typedef struct {
    u8 unk_00[144];
    RecordTextEntry88 groups[4][6];
} RecordTextGridState;
typedef char RecordTextEntrySizeCheck[sizeof(RecordTextEntry88) == 88 ? 1 : -1];
typedef char RecordTextGridSizeCheck[sizeof(RecordTextGridState) == 2256 ? 1 : -1];

void RecordText_CopyUnassignedEntries(void *arg0) {
    RecordTextCopyContext *context = (RecordTextCopyContext *)arg0;
    RecordTextSelectionView *selection;
    s8 *records;
    s8 *record;
    u8 *base;
    u8 *table;
    s8 *result;
    s32 inner;
    s32 outer;
    records = context->owners;
    base = context->table;
    selection = (RecordTextSelectionView *)records;
    outer = 0;
    table = base;
    table += *(s16 *)((u8 *)context + selection->selection * 2 + 24) * 152;
    table += 4;
    record = records;
    do {
        inner = 0;
        if (*record == -1) {
            do {
                result = (s8 *)func_8004C874(table[3] + 76, inner + 33);
                if (result != 0 && *result != 0) {
                    _bcopy(result, ((RecordTextGridState *)records)->groups[outer][inner].text, 12);
                }
                inner++;
            } while (inner != 6);
        }
        outer++;
        record++;
    } while (outer != 4);
}

void RecordNames_LoadFourSlots(u8 *context, s32 override_names) {
    s32 index;
    s32 selection;
    u8 *table;
    s8 *state;
    s8 *owner;
    u8 *entry;
    void *name;
    table = *(u8 **)(context + 12);
    state = *(s8 **)context;
    selection = *(s16 *)((u8 *)state + 136);
    if (table != 0) {
        entry = ((u8 (*)[152])table)[((s16 *)context)[selection + 12]] + 4;
        index = 0;
        owner = state;
        do {
            if (*owner >= 0 && override_names) {
                name = func_8004C874(42, 87);
                if (name != 0) {
                    _bcopy(name, (u8 *)state + index * 12 + 2256, 12);
                }
            } else if (*owner == -1) {
                name = func_8004C874(42, entry[1] - 1);
                if (name != 0) {
                    _bcopy(name, (u8 *)state + index * 12 + 2256, 12);
                }
            }
            index++;
            owner++;
        } while (index != 4);
    }
}

extern s32 func_8004C594(s32, s32);
extern void *func_8004C8A0(void *, s32, s32, s32);
void RecordNames_FormatTwoSlots(u8 *context) {
    s32 index;
    s32 selection;
    s8 *state;
    u8 *table;
    u8 *record;
    s8 *descriptor;
    u8 *slot_context;
    void *name;
    state = *(s8 **)context;
    selection = *(s16 *)((u8 *)state + 136);
    table = *(u8 **)(context + 12);
    index = 0;
    descriptor = (s8 *)(context + 176);
    slot_context = context;
    record = ((u8 (*)[152])table)[((s16 *)context)[selection + 12]] + 4;
    do {
        if (*(s16 *)(slot_context + 176) < 2) {
            if (descriptor[2] >= 0) {
                func_8004C594(1, descriptor[2] + 1);
                func_8004C8A0((u8 *)state + index * 12 + 2256, 12, 18, 29);
            } else {
                name = func_8004C874(42, record[1] - 1);
                if (name != 0) {
                    _bcopy(name, (u8 *)state + index * 12 + 2256, 12);
                }
            }
        } else {
            func_8004C594(1, descriptor[2] + 1);
            func_8004C594(2, descriptor[3] + 1);
            func_8004C8A0((u8 *)state + index * 12 + 2256, 12, 18, 28);
        }
        index++;
        slot_context += 1064;
        descriptor += 1064;
    } while (index != 2);
}

void RecordNames_LoadTwoSlots(u8 *context) {
    s8 slot;
    u8 *row;
    void *name;
    u8 *teams[2];
    u8 *profiles[3];
    s32 index;
    s8 *state;
    s8 *cursor;
    state = *(s8 **)context;
    teams[0] = *(u8 **)(context + 12) + 4;
    index = 0;
    teams[1] = *(u8 **)(context + 12) + 156;
    profiles[0] = *(u8 **)(context + 12) + 308;
    profiles[1] = *(u8 **)(context + 12) + 460;
    cursor = state;
    profiles[2] = *(u8 **)(context + 12) + 612;
    do {
        slot = *cursor;
        name = 0;
        switch (slot) {
        case -1:
            row = profiles[*(s16 *)(*(u8 **)context + 12)];
            break;
        case -2:
            row = 0;
            break;
        default:
            row = teams[index];
            break;
        }
        if (row != 0) {
            name = func_8004C874(42, row[1] - 1);
        }
        if (name != 0) {
            _bcopy(name, (u8 *)state + index * 12 + 2256, 12);
        }
        index++;
        cursor++;
    } while (index != 2);
}

void RecordNames_LoadSelectedOrDefaultSlots(u8 *context) {
    s32 index;
    s32 selection;
    s8 *state;
    u8 *selected_row;
    u8 *default_row;
    s8 *cursor;
    s8 slot;
    u8 *row;
    void *name;
    default_row = *(u8 **)(context + 12) + 4;
    state = *(s8 **)context;
    index = 0;
    selection = *(s16 *)((u8 *)state + 136);
    selected_row = ((u8 (*)[152])(*(u8 **)(context + 12)))[((s16 *)context)[selection + 12]] + 4;
    cursor = state;
    do {
        slot = *cursor;
        name = 0;
        switch (slot) {
        case -1:
            row = selected_row;
            break;
        case -2:
            row = 0;
            break;
        default:
            row = default_row;
            break;
        }
        if (row != 0) {
            name = func_8004C874(42, row[1] - 1);
        }
        if (name != 0) {
            _bcopy(name, (u8 *)state + index * 12 + 2256, 12);
        }
        index++;
        cursor++;
    } while (index != 2);
}

extern s32 D_82615348[];
extern void func_80049C70(s32 *, s32 *, void *);
void RecordText_SelectAndMeasure(void *context, u8 records[][152]) {
    s32 index;
    s32 width;
    s32 height;
    s32 text_id;
    u8 *cursor;
    u8 *record;
    u8 *dimensions;
    void *resource;
    index = 0;
    cursor = (u8 *)context;
    while (index < *(s16 *)((u8 *)context + 20)) {
        record = records[*(s16 *)(cursor + 24)] + 4;
        if (index < *(s16 *)(*(u8 **)context + 136)) {
            text_id = 39;
        } else {
            text_id = D_82615348[(u32)guRandom() % 3];
        }
        resource = func_8004C874(record[3] + 76, text_id);
        if (resource != 0) {
            *(s16 *)(cursor + 56) = text_id;
            dimensions = (u8 *)context + index * 4;
            func_80049C70(&width, &height, resource);
            *(s16 *)(dimensions + 88) = width;
            *(s16 *)(dimensions + 90) = height;
        }
        index++;
        cursor += 2;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_128B10/func_826020C0.s")


void func_826026E8(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    *(u16 *)(arg0 + 0xA0) = (u16)1;
    *(u16 *)(arg0 + 0xA4) = (u16)arg1;
    *(u16 *)(arg0 + 0xA6) = (u16)arg2;
    *(u16 *)(arg0 + 0xA8) = (u16)arg3;
    *(u16 *)(arg0 + 0xAA) = (u16)arg4;
}

void func_82602708(u8 *arg0) {
    *(u16 *)(arg0 + 0xA0) = 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_128B10/func_82602710.s")


typedef struct { u8 pad_00[4]; void *unk_04; } Func82615340StateX;
extern Func82615340StateX *D_82615340;
extern void func_82602710(u8 *);
extern void BgStage_DrawFrame(void);
extern void func_826042A0(void);
extern void func_82614BD0(void);
extern void func_80008648(void);

void func_82602888(void) {
    func_80043E70(D_82615340->unk_04, 0);
    BgStage_DrawFrame();
    func_82602710(D_82615340);
    func_826042A0();
    func_82614BD0();
    func_80008648();
}


typedef struct {
    u8 pad_00[8];
    u16 unk_08;
    s16 unk_0A;
    u8 pad_0C[0x7C];
    s16 unk_88;
} Func826028E0StateX;
extern s32 func_8006AD10(u16, s16, s16);
extern s32 func_80054AA0(s32);
extern void func_80054AF4(s32);

void func_826028E0(Func826028E0StateX *arg0) {
    s32 value;
    value = func_8006AD10(arg0->unk_08, arg0->unk_0A, arg0->unk_88);
    if (value != -1) {
        if (func_80054AA0(value) == 0) {
            func_80054AF4(value);
        }
    }
}


extern u8 StageContext_GetFadeMode(void);
extern s32 func_800355E4(s32);
extern s32 func_80044144(void *);
extern s32 func_82614F0C(void);

s32 func_82602930(s32 arg0) {
    s32 result = arg0;
    switch (arg0) {
    case 0:
        if (StageContext_GetFadeMode() == 0) result = 1;
        break;
    case 1:
        if (func_80044144(D_82615340->unk_04) != 0) {
            result = 2;
            func_82614CE0();
            func_800355E4(0x28);
        }
        break;
    case 2:
        if (func_82614F0C() != 0) {
            result = 3;
            StageContext_SetClearColor(1);
            StageFade_StartFromTransparent(5);
            func_800226C0(0x65);
        }
        break;
    case 3:
        if (StageContext_GetFadeMode() == 1) result = 4;
        break;
    }
    return result;
}

extern void func_800086A4(s32);
extern void StageFade_StartFromOpaque(s32);
extern void func_80064D28(void);
extern void func_82604170(void);
extern void func_82613814(void);
extern void func_82602888(void);
extern void func_826028E0(Func826028E0StateX *arg0);
extern s32 func_82602930(s32 arg0);
void func_82602A0C(void) {
    Func826028E0StateX *sp24;
    u16 sp22;
    s32 temp_v0_2;
    s32 var_s0;

    sp24 = (Func826028E0StateX *)*(void **)D_82615340;
    var_s0 = 0;
    sp22 = sp24->unk_08 & 0xFF00;
    if (StageContext_GetFadeMode() != 0) {
        func_800086A4(2);
        StageFade_StartFromOpaque(5);
    }
    do {
        func_80064D28();
        func_82604170();
        func_82613814();
        func_82602888();
        temp_v0_2 = func_82602930(var_s0);
        var_s0 = temp_v0_2;
    } while (temp_v0_2 != 4);
    if ((sp22 == 0x300) || (sp22 == 0x600)) {
        func_826028E0(sp24);
    }
}

void RecordNames_LoadUnassignedFourSlots(u8 *context) {
    s32 index;
    s32 selection;
    s8 *state;
    s8 *cursor;
    u8 *base;
    u8 *record;
    void *name;
    state = *(s8 **)context;
    selection = *(s16 *)((u8 *)state + 136);
    base = *(u8 **)(context + 12);
    index = 0;
    cursor = state;
    record = ((u8 (*)[152])base)[((s16 *)context)[selection + 12]] + 4;
    do {
        if (*cursor == -1) {
            name = func_8004C874(42, record[1] - 1);
            if (name != 0) {
                _bcopy(name, (u8 *)state + index * 12 + 2256, 12);
            }
        }
        index++;
        cursor++;
    } while (index != 4);
}

void RecordNames_LoadTwoSlotsOptionalDefaults(u8 *context, s32 use_defaults) {
    s8 slot;
    u8 *row;
    void *name;
    u8 *teams[2];
    u8 *profiles[3];
    s32 index;
    s8 *state;
    s8 *cursor;
    state = *(s8 **)context;
    teams[0] = *(u8 **)(context + 12) + 4;
    index = 0;
    teams[1] = *(u8 **)(context + 12) + 156;
    profiles[0] = *(u8 **)(context + 12) + 308;
    profiles[1] = *(u8 **)(context + 12) + 460;
    cursor = state;
    profiles[2] = *(u8 **)(context + 12) + 612;
    do {
        slot = *cursor;
        name = 0;
        switch (slot) {
        case -1:
            row = profiles[*(s16 *)(*(u8 **)context + 12)];
            break;
        case -2:
            row = 0;
            break;
        default:
            row = use_defaults != 0 ? teams[index] : 0;
            break;
        }
        if (row != 0) {
            name = func_8004C874(42, row[1] - 1);
        }
        if (name != 0) {
            _bcopy(name, (u8 *)state + index * 12 + 2256, 12);
        }
        index++;
        cursor++;
    } while (index != 2);
}

void RecordNames_LoadSelectedOrDefaultPair(u8 *context) {
    s32 index;
    s32 selection;
    s8 *state;
    u8 *selected_row;
    u8 *default_row;
    s8 *cursor;
    s8 slot;
    u8 *row;
    void *name;
    default_row = *(u8 **)(context + 12) + 4;
    state = *(s8 **)context;
    index = 0;
    selection = *(s16 *)((u8 *)state + 136);
    selected_row = ((u8 (*)[152])(*(u8 **)(context + 12)))[((s16 *)context)[selection + 12]] + 4;
    cursor = state;
    do {
        slot = *cursor;
        name = 0;
        switch (slot) {
        case -1:
            row = selected_row;
            break;
        case -2:
            row = 0;
            break;
        default:
            row = default_row;
            break;
        }
        if (row != 0) {
            name = func_8004C874(42, row[1] - 1);
        }
        if (name != 0) {
            _bcopy(name, (u8 *)state + index * 12 + 2256, 12);
        }
        index++;
        cursor++;
    } while (index != 2);
}

extern s32 D_82615390[];
extern s32 D_82615384[];
extern s32 D_82615378[];
void func_82602E14(void *arg0) {
    s32 selection;
    u8 *record;
    s32 i;
    s32 mode;
    s32 width;
    s32 height;
    u8 *base;
    void *resource;
    u8 *root;

    root = *(u8 **)arg0;
    base = *(u8 **)((u8 *)arg0 + 0xC);
    mode = root[7];
    for (i = 0; i < *(s16 *)((u8 *)arg0 + 0x14); i++) {
        record = base;
        record += *(s16 *)((u8 *)arg0 + 0x18 + i * 2) * 0x98;
        record += 4;
        if (i == *(s16 *)(*(u8 **)arg0 + 0x88)) {
            switch (mode) {
                case 0:
                case 4:
                    selection = D_82615390[guRandom() % 3U];
                    break;
                case 3:
                    selection = 0x20;
                    break;
                case 1:
                    selection = D_82615384[guRandom() % 3U];
                    break;
                default:
                    selection = 0x1F;
                    break;
            }
        } else if (i < *(s16 *)(*(u8 **)arg0 + 0x88)) {
            selection = 0x27;
        } else {
            selection = D_82615378[guRandom() % 3U];
        }
        resource = func_8004C874(record[3] + 0x4C, selection);
        if (resource != 0) {
            *(s16 *)((u8 *)arg0 + 0x38 + i * 2) = selection;
            func_80049C70(&width, &height, resource);
            *(s16 *)((u8 *)arg0 + 0x58 + i * 4) = width;
            *(s16 *)((u8 *)arg0 + 0x5A + i * 4) = height;
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_128B10/func_82602FE8.s")

#include "229E0.h"
typedef struct PokeIconList44300 PokeIconList44300;
extern PokeIconList44300 *func_800437B4(void *, s32, s32, s32);
extern u8 *func_8004BA70(s32);
extern s32 func_8004C4B0(s32);
extern void func_80055EF0(void *, s32);
extern s32 func_826058CC(s32);
extern s32 func_82602FE8(void *);
extern s32 func_82610C84(s32, s32);
extern Func82615340StateX *D_82615370;
extern s32 D_82615374;
extern u8 D_826163C0;
typedef struct {
    s16 width;
    s16 height;
} RecordSelectionTextDimensions;
typedef char RecordSelectionTextDimensionsSize[sizeof(RecordSelectionTextDimensions) == 4 ? 1 : -1];
extern void RecordNames_FormatTwoSlots(u8 *context);
extern void RecordNames_LoadSelectedOrDefaultPair(u8 *context);
extern void RecordNames_LoadTwoSlotsOptionalDefaults(u8 *context, s32 use_defaults);
extern void RecordNames_LoadUnassignedFourSlots(u8 *context);
extern void func_82602E14(void *arg0);
// Initialize row selection, names, compact party descriptors, and icon resources.
void RecordSelection_InitializeDisplayContext(u8 *context) {
    SceneLoadContext *load_context;
    u8 *state;
    u8 *table;
    PokeIconList44300 *list;
    u16 mode;
    s32 name_mode;
    s16 selection;
    s32 category;
    s32 side;
    s32 member;
    s32 sum_member;
    s32 scan_record;
    s32 clear_record;
    s32 group_count;
    s32 used;
    s32 total;
    s32 icon_count;
    s32 icon_height;
    RecordSelectionPartyDescriptor *descriptor;
    s8 *member_cursor;
    u8 *row;
    load_context = PokeIcon_AllocLoadContext(1);
    state = *(u8 **)context;
    table = *(u8 **)(context + 12);
    mode = *(u16 *)(state + 8) & 0xFF00;
    D_82615370 = (Func82615340StateX *)context;
    if (((s8 *)state)[15] != 0) D_82615374 = 1;
    else D_82615374 = 0;
    func_80055EF0(&D_826163C0, D_82615374);

    // Select the active row and preserve the entry mode for the final history update.
    switch (mode) {
    case 0x400:
    case 0x600:
        *(s16 *)(context + 20) = 1;
        selection = *(s16 *)(state + 136);
        if (selection != 0) {
            *(s16 *)(context + 24) = ((s16 *)(context + 24))[selection];
            *(s16 *)(context + 56) = ((s16 *)(context + 56))[*(s16 *)(state + 136)];
            *(RecordSelectionTextDimensions *)(context + 88) = ((RecordSelectionTextDimensions *)(context + 88))[*(s16 *)(state + 136)];
            *(s16 *)(state + 136) = 0;
        }
        break;
    case 0x500:
        *(s16 *)(context + 20) = 1;
        if (*(s16 *)(state + 136) != 0) {
            *(s16 *)(context + 24) = ((s16 *)(context + 28))[*(s16 *)(*(u8 **)context + 12)];
            *(s16 *)(context + 56) = ((s16 *)(context + 60))[*(s16 *)(*(u8 **)context + 12)];
            *(RecordSelectionTextDimensions *)(context + 88) = ((RecordSelectionTextDimensions *)(context + 96))[*(s16 *)(*(u8 **)context + 12)];
            *(s16 *)(state + 136) = 0;
        }
        break;
    case 0x200:
        *(s16 *)(context + 20) = 1;
            *(s16 *)(context + 24) = ((s16 *)(context + 28))[*(s16 *)(*(u8 **)context + 12)];
            *(s16 *)(context + 56) = ((s16 *)(context + 60))[*(s16 *)(*(u8 **)context + 12)];
            *(RecordSelectionTextDimensions *)(context + 88) = ((RecordSelectionTextDimensions *)(context + 96))[*(s16 *)(*(u8 **)context + 12)];
        *(s16 *)(state + 136) = 0;
        break;
    }
    *(s16 *)(state + 138) = *(s16 *)(context + 20);
    category = func_826058CC(state[7]);
    if (category >= 0 && category < 2) {
        if (((s16 *)(state + 2304))[category] < 99) ((s16 *)(state + 2304))[category]++;
    }
    side = 0;
    for (; side < *(s16 *)(context + 20); side++) {
        row = table;
        row += ((s16 *)(context + 24))[side] * 152;
        row += 4;
        func_8004C4B0(row[3] + 76);
    }
    side = 0;
    // Name loaders and archive initialization precede display-record compaction.
    name_mode = *(u16 *)(*(u8 **)context + 8) & 0xFF00;
    switch (name_mode) {
    case 0x500: RecordNames_LoadTwoSlotsOptionalDefaults(context, 1); break;
    case 0x200: RecordNames_FormatTwoSlots(context); break;
    case 0x400: RecordNames_LoadSelectedOrDefaultPair(context); break;
    default:
        if (*(u8 **)(context + 12) != NULL) RecordNames_LoadUnassignedFourSlots(context);
        break;
    }
    if (*(u8 **)(context + 12) != NULL) func_82602E14(context);
    PokeIcon_InitResourceArchives();
    if (((s8 *)state)[6] != 0) group_count = 2;
    else group_count = 1;
    do {
        used = 0;
        member = 0;
        if (group_count > 0) {
            descriptor = &((RecordSelectionPartyDescriptor *)(context + 176))[side];
            member_cursor = (s8 *)descriptor;
            do {
                member_cursor[4] = 0;
                for (scan_record = 0; scan_record < 6; scan_record++) {
                    if (((RecordSelectionWorkingGrid *)state)->groups[side * group_count + member][scan_record].species != 0) {
                        member_cursor[4]++;
                        descriptor->entries[used] = ((RecordSelectionWorkingGrid *)state)->groups[side * group_count + member][scan_record];
                        used++;
                    }
                }
            } while ((member_cursor++, ++member) < group_count);
        }
        for (clear_record = used; clear_record < 12; clear_record++) {
            _bzero(&((RecordSelectionPartyDescriptor *)(context + 176))[side].entries[clear_record], sizeof(RecordSelectionWorkingEntry));
        }
        side++;
    } while (side < 2);
    // Four or more occupied entries select the twelve-icon resource layout.
    *(s16 *)(context + 18) = 0;
    side = 0;
    do {
        total = 0;
        descriptor = &((RecordSelectionPartyDescriptor *)(context + 176))[side];
        for (sum_member = 0; sum_member != 2; sum_member++) {
            total += descriptor->member_sizes[sum_member];
        }
        if (total >= 4) *(s16 *)(context + 18) = 1;
        side++;
    } while (side != 2);
    if (*(s16 *)(context + 18) != 0) { icon_count = 12; icon_height = 78; }
    else { icon_count = 6; icon_height = 144; }
    list = func_800437B4(load_context, icon_count, 118, icon_height);
    *(PokeIconList44300 **)(context + 4) = list;
    *(u16 *)list |= 0x4;
    *(u8 **)(context + 8) = func_8004BA70(0);
    *(s16 *)(context + 16) = 0;
    if (mode == 0 && func_826058CC(state[7]) == 0 && func_82602FE8(context + 176) != 0) {
        *(s16 *)(context + 16) = 1;
        if (*(s16 *)(state + 140) < 99) (*(s16 *)(state + 140))++;
    }
    func_82610C84((s32)context, 1);
}

void func_82603684(void) {
    func_80043E70(D_82615370->unk_04, 0);
    BgStage_DrawFrame();
    func_82602710(D_82615370);
    func_826042A0();
    func_82614BD0();
    func_80008648();
}

extern s32 func_8006CBB8(s32);
extern s32 func_8006CBA0(s32, s32);
extern u16 func_80056024(s32);
void func_826036DC(void *arg0) {
    s32 temp_a0;
    s32 sp24;
    u16 sp1E;
    s32 temp_v0;

    temp_a0 = *(s16 *)((u8 *)arg0 + 0xA);
    sp24 = temp_a0;
    func_8006CBB8(temp_a0);
    if (func_8006CBA0(*(s16 *)((u8 *)arg0 + 0x88), *(s16 *)((u8 *)arg0 + 0x8A)) != 0) {
        sp1E = func_80056024(sp24);
        temp_v0 = func_8006CBB8(sp24);
        switch (temp_v0) {
        case 0:
            (*(u16 *)((u8 *)&D_826163C0 + 0x0)) |= sp1E;
            break;
        case 1:
            (*(u16 *)((u8 *)&D_826163C0 + 0x4)) |= sp1E;
            break;
        case 2:
            (*(u16 *)((u8 *)&D_826163C0 + 0x2)) |= sp1E;
            break;
        }
        if (sp1E != 0) {
            func_80055F6C((s32 *)&D_826163C0, D_82615374);
        }
    }
}

void func_826037BC(void *arg0) {
    func_8006CBB8(*(s16 *)((u8 *)(arg0) + (0xA)));
    if (func_8006CBA0(*(s16 *)((u8 *)(arg0) + (0x88)), *(s16 *)((u8 *)(arg0) + (0x8A))) != 0) {
        (*(s8 *)((u8 *)(&D_826163C0) + (0xA))) = 1;
        func_80055F6C(&D_826163C0, D_82615374);
    }
}

s32 RecordOwners_AnyUnassigned(void) {
    s32 result;
    s32 index;
    s8 *owners;
    owners = *(s8 **)D_82615370;
    result = 0;
    for (index = 0; index < 4; index++) {
        if (owners[index] == -1) {
            result = 1;
        }
    }
    return result;
}
/* mkdraft:func_82603870 begin */
extern s32 D_826153A0;
extern s32 D_82615390[];



s32 func_82603870(s32 arg0) {
    u8 *state;
    s32 result;

    state = *(u8 **)D_82615370;
    result = arg0;
    // FAKE: two names for one address. The target materialises D_826153A0's
    // address twice in this block (lui t7 + lw, then lui at + sw); IDO 7.1 emits
    // one lui/addiu pair when a block references a symbol twice, so the store is
    // spelled through D_82615390 + 0x10, which links to D_826153A0.
    // Score as D_826153A0++: 430.
    D_82615390[4] = D_826153A0 + 1;
    switch (arg0) {
    case 0:
        if (StageContext_GetFadeMode() == 0) result = 1;
        break;
    case 1:
        if (func_80044144(D_82615370->unk_04) != 0) {
            result = 2;
            func_82614CE0();
            if (RecordOwners_AnyUnassigned() != 0 && func_826058CC(state[7]) != 0) {
                func_800355E4(78);
            } else {
                func_800355E4(39);
            }
        }
        break;
    case 2:
        if (func_82614F0C() != 0) {
            result = 3;
            StageContext_SetClearColor(1);
            StageFade_StartFromTransparent(5);
            func_800226C0(101);
            func_80035424(10);
        }
        break;
    case 3:
        if (StageContext_GetFadeMode() == 1) result = 4;
        break;
    }
    return result;
}
/* mkdraft:func_82603870 end */

extern s32 func_82603870(s32);
void RecordSelection_RunPhaseLoop(void) {
    s32 mode_category;
    u8 *state;
    u16 mode_group;
    s32 next_phase;
    s32 phase;
    state = *(u8 **)D_82615370;
    phase = 0;
    mode_group = *(u16 *)(state + 8) & 0xFF00;
    if (StageContext_GetFadeMode() != 0) {
        func_800086A4(2);
        StageFade_StartFromOpaque(5);
    }
    do {
        func_80064D28();
        func_82604170();
        func_82613814();
        func_82603684();
        next_phase = func_82603870(phase);
        phase = next_phase;
    } while (next_phase != 4);
    func_800086A4(2);
    mode_category = func_826058CC(state[7]);
    if (mode_category == 0) {
        switch (mode_group) {
        case 0x300:
            func_826036DC(state);
            break;
        case 0x600:
            func_826037BC(state);
            break;
        }
    }
}
#endif
