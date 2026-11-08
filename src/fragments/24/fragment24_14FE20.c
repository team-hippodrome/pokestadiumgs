#include "global.h"


#ifdef VERSION_US
s32 func_82B00020(u8 *arg0) {
    s32 result;

    if (arg0[1] != 0) {
        if (arg0[0] == 0) {
            if (arg0[2] < 6) {
                result = 5;
            } else {
                result = 0;
            }
        } else {
            result = 3;
        }
    } else if (arg0[0] == 2) {
        result = 4;
    } else if (arg0[4] != 0) {
        result = 1;
    } else {
        result = 2;
    }
    return result;
}

/* mkdraft:func_82B00098 begin */
typedef struct F82B00098_Entry {
    /* 0x0000 */ u8 unk_00; /* func_8005D8CC(port) */
    /* 0x0001 */ u8 unk_01; /* func_8005D92C(port) */
    /* 0x0002 */ u8 unk_02; /* func_8005D948(port); count of the 0x58-byte entries at 0x1C */
    /* 0x0003 */ u8 unk_03; /* func_8005DDD4(port) */
    /* 0x0004 */ u8 connected; /* bit `port` of func_800060E8's controller bits */
    /* 0x0005 */ u8 status; /* func_82B00020(entry) */
    /* 0x0006 */ u8 unk_06; /* func_800606F4(port) */
    /* 0x0007 */ u8 unk_07; /* never written by this function */
    /* 0x0008 */ u16 unk_08; /* first halfword of func_8005D9E0's buffer */
    /* 0x000A */ s8 name[0x12]; /* name string after that halfword, or a status message */
    /* 0x001C */ u8 unk_1C[0x214]; /* deck entries, 0x58 bytes each, filled by Deck_ReadEntries */
    /* 0x0230 */ u8 unk_230[0x4B00]; /* per-deck copies, 0xC80 bytes each, filled by func_8004D878 */
} F82B00098_Entry;
extern F82B00098_Entry D_82B087C0[];
extern s8 D_82B087CA[]; /* name field of port 0's record */
extern u8 func_800060E8(void);
extern void func_80057908(u8);
extern void func_8005D9E0(s32, void *);
extern u8 func_8005D8CC(s32);
extern u8 func_8005D92C(s32);
extern u8 func_8005D948(s32);
extern s32 func_8005DDD4(s32);
extern u8 func_800606F4(s32);
extern u8 *func_8006218C(s32, s32, s32, s32);
extern s32 Deck_ReadEntries(u8 *, s32, u8 *);
extern void func_80061F44(u8 *);
extern s32 func_80062304(u8 *);
extern u8 *func_8004D878(u8 *, s32, u8 *);
extern void *func_8004C874(s32, s32);
extern s8 *HAL_Strcpy(s8 *, s8 *);

// Refreshes both controller-port records (0x4D30 bytes each) at D_82B087C0, then
// loads each present Transfer Pak's deck list and copies the decks it selects.


void func_82B00098(void) {
    struct {
        u16 id;
        s8 name[0x1E];
    } buffer;
    F82B00098_Entry *entry;
    u8 controller_bits;
    u8 *handle;
    s32 i;
    s32 j;
    s32 k;

    controller_bits = func_800060E8();
    for (i = 0; i < 2; i++) {
        func_80057908(i);
    }
    for (i = 0; i < 2; i++) {
        // FAKE: `j` only moves the connectivity bit ahead of the entry pointer,
        // which fixes the loop prologue's register order; inline, this scores 90.
        j = (controller_bits & (1 << i)) != 0;
        entry = &D_82B087C0[i];
        func_8005D9E0(i, &buffer);
        entry->unk_00 = func_8005D8CC(i);
        entry->unk_01 = func_8005D92C(i);
        entry->unk_02 = func_8005D948(i);
        entry->unk_03 = func_8005DDD4(i);
        entry->connected = j;
        entry->unk_08 = buffer.id;
        HAL_Strcpy(D_82B087CA + i * 0x4D30, buffer.name);
        entry->status = func_82B00020((u8 *)entry);
        entry->unk_06 = func_800606F4(i);
    }
    for (i = 0; i < 2; i++) {
        entry = &D_82B087C0[i];
        if (entry->status == 0) {
            handle = func_8006218C(0x20, i, 0, 0);
            Deck_ReadEntries(entry->unk_1C, entry->unk_02, handle);
            for (j = 0; j < entry->unk_02; j++) {
                func_80061F44(entry->unk_1C + j * 0x58);
            }
            func_80062304(handle);
            for (k = 0; k < entry->unk_02; k++) {
                func_8004D878(entry->unk_230 + k * 0xC80, 0,
                              entry->unk_1C + k * 0x58);
            }
        }
        switch (entry->status) {
        case 0:
        case 5:
            break;
        default:
            handle = (u8 *)func_8004C874(0x2A, i + 0x54);
            HAL_Strcpy(entry->name, (s8 *)handle);
            break;
        }
    }
}
/* mkdraft:func_82B00098 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/24/fragment24_14FE20/func_82B002B8.s")

extern void BgStage_DrawFrame();
extern void func_82B080D0();
extern void func_80008648();
void func_82B004FC(s32 arg0) {
    BgStage_DrawFrame();
    func_82B080D0();
    func_80008648();
}

extern s32 D_82B08524;
extern s32 D_82B08528;
extern s32 D_82B0852C;
extern u16 D_82B08530[];
extern s16 D_82B12222;
extern u8 *D_82B12448;
s32 func_8006A600(u16, s32, s32);
void *func_800718B8(s32);
s32 func_82B084D4(void);
s32 func_82B084FC(void);
s32 func_82B08508(void);
s32 func_82B08514(void);



s32 func_82B0052C(void) {
    s32 result = 0;
    s32 index;
    u32 mode;
    u16 id;

    mode = func_82B084D4();
    if (mode == -2) goto out;
    if (mode == -1) {
        result = -1;
        D_82B08524 = result;
        D_82B08528 = result;
        D_82B12448 = NULL;
        goto out;
    }
    index = mode & 0xF;
    D_82B08524 = index;
    switch (index) {
    case 3: D_82B08528 = func_82B08508(); break;
    case 4: D_82B08528 = func_82B08514(); break;
    default: D_82B08528 = 0; break;
    }
    id = D_82B08530[index];
    if (id != 0x110) {
        D_82B12448 = func_800718B8(func_8006A600(id, 1, 0));
    } else {
        D_82B12448 = (u8 *)(D_82B08528 * 0x44 + 0x9A68 + (s32)&D_82B087C0);
    }
    if (mode & 0x100) {
        D_82B0852C = func_82B084FC();
        D_82B12222 = 1;
        result = 2;
    } else {
        D_82B0852C = -1;
        D_82B12222 = 0;
        result = 1;
    }
out:
    return result;
}

typedef struct Target82BState Target82BState;
struct Target82BState { u8 pad_0000[0x1A60]; s16 value; };
extern Target82BState D_82B107C0;
extern s16 D_82B12220;
s32 func_82B0069C(void) {
    s32 result = 1;
    volatile Target82BState *state = &D_82B107C0;
    D_82B12220 = state->value + 1;
    if (state->value < 2) {
        result = 0;
    } else {
        result = 1;
    }
    return result;
}

/* mkdraft:func_82B006D8 begin */
extern s16 D_82B12220;
extern s32 D_82B08524;
extern s32 D_82B08528;
extern s32 func_82B0052C(void);
extern void func_82B084AC(void);
extern s32 func_82B084CC(void);
extern s32 func_82B08508(void);
extern s32 func_82B08514(void);
extern u8 StageContext_GetFadeMode(void);
extern s32 StageFade_StartFromTransparent(s32 duration);
extern s32 func_81700C0C(s32 arg0);
// FAKE: func_80035424 returns void (include/229E0.h:961, src/340C0.c:811); the s32
// return only re-colors the case-3 tail. Score without it: 110.
extern s32 func_80035424(s32 arg0);
// func_82B0069C is defined above this function in src/fragments/24/fragment24_14FE20.c.



s32 func_82B006D8(s32 arg0, s32 arg1) {
    // FAKE: result[0] is the only element read. Taking the address of a two-element
    // array is what homes the return value in the 0x18/0x1C stack slots and yields the
    // 0x20 frame. Score with a plain s32 return local: 32.
    s32 result[2];
    s16 var_v1;
    s32 temp_v0;
    // FAKE: reading D_82B12220 directly makes IDO emit the load with a different
    // register; the retail read is `lui v1,%hi` + `lh v1,%lo(v1)`. Score without this
    // local pointer: 545.
    s16 *D_82B12220_ptr = &D_82B12220;

    result[0] = arg0;
    switch (arg0) {
    case 0:
        if (StageContext_GetFadeMode() == 0) {
            result[0] = 1;
            if (arg1 != 0) {
                func_82B084AC();
                func_81700C0C(0);
                func_81700C0C(1);
            } else {
                func_82B084CC();
            }
        }
        break;
    case 1:
        temp_v0 = func_82B0052C();
        if (temp_v0 != 0) {
            switch (temp_v0) {
            case -1:
                D_82B08524 = -1;
                D_82B08528 = -1;
                result[0] = 3;
                D_82B12220 = 0;
                StageFade_StartFromTransparent(5);
                break;
            case 1:
                switch (D_82B08524) {
                case 3:
                    D_82B08528 = func_82B08508();
                    break;
                case 4:
                    D_82B08528 = func_82B08514();
                    break;
                default:
                    D_82B08528 = 0;
                    break;
                }
                result[0] = 3;
                // FAKE: separates `result[0] = 3` from the fade store so IDO schedules
                // `addiu t9,zero,3` ahead of `addiu v1,zero,15`; the label is the only
                // reason the store is not emitted in the other order. Score without it: 20.
                goto Lfade;
            Lfade:
                // FAKE: the pair is a dead compare that leaves the 15 in v1 instead of
                // v0; one compare gives 10, none gives 40. The mask keeps the compare's
                // operand a full register read of arg1.
                if ((arg1 & 0xF) == 0xF) {
                }
                if ((arg1 & 0xF) == 0xF) {
                }
                D_82B12220 = 15;
                StageFade_StartFromTransparent(5);
                break;
            case 2:
                switch (D_82B08524) {
                case 3:
                    D_82B08528 = func_82B08508();
                    break;
                case 4:
                    D_82B08528 = func_82B08514();
                    break;
                default:
                    D_82B08528 = 0;
                    break;
                }
                result[0] = 2;
                D_82B12220 = 0;
                break;
            }
        }
        break;
    case 2:
        if (func_82B0069C() != 0) {
            result[0] = 5;
        }
        break;
    case 3:
        var_v1 = *D_82B12220_ptr;
        if (var_v1 > 0) {
            var_v1 -= 1;
        }
        if (var_v1 == 0) {
            // FAKE: duplicate of the store below (var_v1 is 0 here); it keeps the
            // D_82B12220 store inside the branch. Score without it: 260.
            D_82B12220 = var_v1;
            func_80035424(10);
            var_v1 = -1;
        }
        D_82B12220 = var_v1;
        // FAKE: `^ 0` is a no-op that flips the bne operand order to retail's
        // `bne a1,v1`. Score without it: 10.
        if (((var_v1 ^ 0) == -1) && (StageContext_GetFadeMode() == 1)) {
            result[0] = 5;
        }
        break;
    }
    return result[0];
}
/* mkdraft:func_82B006D8 end */

extern s32 D_82B08520;
extern void _bcopy(const void *, void *, s32);

typedef struct StagePhotoBlob StagePhotoBlob;
typedef struct StageUploadEntry StageUploadEntry;
typedef struct StageUploadChunk StageUploadChunk;
typedef struct StagePhotoFlags StagePhotoFlags;

// One 0x58-byte photo record. unk_00 is a byte view because the upload clears
// its second byte in place: the target writes sb $zero, 0x11(%v0) while %v0
// runs from the entry base, landing on byte 1 of the current record.
struct StagePhotoBlob {
    u8 unk_00[4];
    u32 unk_04[21];
};

// One upload destination: 0x10 of header then six records, for 0x220 bytes.
// count is s8 because the target loads it with lb and guards the copy loop with
// blezl, and because only one signed guard appears around the whole loop nest.
struct StageUploadEntry {
    s8 count;
    u8 unk_01;
    u16 unk_02;
    u8 unk_04[12];
    StagePhotoBlob photos[6];
};

// The 68-byte block that sub-mode 4 copies over the descriptor at D_82B08520,
// from the table at ((u8 *) D_82B087C0) + 39528, indexed by D_82B08528.
struct StageUploadChunk {
    u32 data[17];
};

// Fade state consulted once per copied photo. unk_40_005 is the signed one-bit
// field that IDO places at bit 26, which is what the target reads: lw of the
// word at +0x40, sll by 5 to put that bit in the sign position, then bltzl.
struct StagePhotoFlags {
    u32 unk_00[16];
    u32 unk_40_000 : 5;
    s32 unk_40_005 : 1;
    u32 unk_40_006 : 26;
};

// Waits out the stage fade, runs the photo-upload scheduler to state 5, then
// copies both staged sets into the upload buffer. Returns the mode: 2 after a
// copy, 1 when D_82B12222 suppresses it. The staged sets are F82B00098_Entry
// records (0x4D30 each, photo block at 0x1C) and D_82B12448 is the u8 * the
// surrounding file declares, so both are reused with casts rather than
// redeclared.


s32 func_82B00914(s32 arg0)
{
    s32 mode = 2;
    // Re-read through the pointer so the load stays inside the photo loop.
    StagePhotoFlags **pp = (StagePhotoFlags **) &D_82B12448;
    s32 off;
    s32 state = 0;
    s32 i;
    s32 j;
    F82B00098_Entry *set;
    u8 *header;
    StageUploadEntry *entry;

    // A fade already running is restarted from opaque over five steps.
    if (StageContext_GetFadeMode() != 0) {
        func_800086A4(2);
        StageFade_StartFromOpaque(5);
    }
    do {
        func_80064D28();
        func_8170024C();
        func_82B07ABC();
        func_82B004FC(state);
        state = func_82B006D8(state, arg0);
    } while (state != 5);

    if (D_82B12222 != 0) {
        mode = 1;
    }

    // The two loops below carry their line breaks as the match requires: the for
    // header shares a line with header's assignment (splitting it scores 152 of
    // 153 instructions) and the photo copy keeps its body on one line (151).
    if (mode == 2) {
        i = 0;
        set = D_82B087C0;
        off = 0;
        header = (u8 *) D_82B087CA; for (; i != 2; i++) {
            entry = (StageUploadEntry *) ((*((u8 **) D_82B08520)) + off);
            entry->unk_01 = set->unk_06;
            _bcopy(header, entry->unk_04, 12);
            entry->unk_02 = set->unk_08;
            entry->count = set->unk_02;
            for (j = 0; j < entry->count; j++) { entry->photos[j] = ((StagePhotoBlob *) D_82B087C0[i].unk_1C)[j]; if (((*pp) != 0) && (!(*pp)->unk_40_005)) { entry->photos[j].unk_00[1] = 0; } } set++; off += 544;
            header += 19760;
        }
        // Sub-mode 4 also overwrites the descriptor's first 68 bytes.
        if (D_82B08524 == 4) {
            *((StageUploadChunk *) (D_82B08520 + 12)) = *((StageUploadChunk *) ((((u8 *) D_82B087C0) + 39528) + (D_82B08528 * 68)));
        }
    }

    return mode;
}

extern s32 D_82B08524;
extern s32 D_82B08528;

// Packs D_82B08524 + 1 (only for 0-4; other non-negative values give 1) into the
// upper halfword and the low halfword of D_82B08528 into the lower one; returns 0
// while D_82B08524 is negative.
u32 func_82B00B78(void) {
    u32 result = 0;
    u32 high;

    if (D_82B08524 >= 0) {
        high = 0x10000;
        switch (D_82B08524) {
            case 0:
                break;
            case 1:
                high = 0x20000;
                break;
            case 2:
                high = 0x30000;
                break;
            case 3:
                high = 0x40000;
                break;
            case 4:
                high = 0x50000;
                break;
        }
        result = (D_82B08528 & 0xFFFF) | high;
    }
    return result;
}

/* mkdraft:func_82B00BE0 begin */
extern s32 main_pool_push_state(s32);
extern s32 main_pool_pop_state(s32);
extern void Gfx_InitDisplayListBuffers(s32, s32);
extern void Gfx_FreeDisplayListBuffers(void);
extern s32 func_800082E0(s32, s32, s32, s32, s32, s32);
extern void func_80008514(s32);
extern void func_80008574(void);
extern void func_80008624(void);
extern void func_8004C398(void);
extern void func_80047610(void);
extern u8 *func_80047588(s32, s32);
extern s32 func_80055948(s32);
extern void func_8005A014(s32);
extern u8 *Asset_LoadToSegment(s32, u8 *, u8 *, s32);
extern s32 Fragment_LoadAndCall(s32, u8 *, u8 *, u32, u32);
extern void StageLoader_WaitForRetrace(void);
extern void func_82B002B8(u32, s32, s32, s32);
extern s32 func_82B00914(s32);
extern s32 func_82B08508(void);
extern s32 func_82B08514(void);
extern u8 D_1000000[], D_446E30[], D_447D00[];
extern u8 D_82C00000[], fragment83_ROM_START[], fragment84_ROM_START[];
extern s32 D_82B08520;
extern s32 D_82B0852C;
extern u8 *D_82B12448;



u32 func_82B00BE0(u32 arg0, s32 arg1) {
    // FAKE: unused frame padding. Without it the frame is 0x50 instead of 0x60 and
    // only the prologue/epilogue stack adjust differs (diff score 10).
    s32 pad[4];
    // Packed value returned to the caller, kept from the last stage frame.
    u32 result;
    // Request slot for the next fragment. Held in a local because reading the global
    // directly costs the D_82C00000 base its $fp home (diff score 635).
    s32 *request = &D_82B12448;
    // 1 on the first pass only; func_82B002B8 skips its setup while this is nonzero.
    s32 first_frame;
    // func_800082E0 result, handed to func_80008514.
    s32 configuration;
    // Loop state: 0 draws a stage frame, 1 loads and runs the requested fragment, 2 exits.
    s32 state;
    s32 var_s3;
    s32 var_s4;

    state = 0;
    first_frame = 1;
    result = 0;
    var_s3 = 0;
    var_s4 = 0;
    main_pool_push_state(0x4556534C);
    D_82B08520 = arg1;
    Gfx_InitDisplayListBuffers(0x10000, 0);
    configuration = func_800082E0(1, 0, 2, 0, 2, 1);
    func_80047588(0x1C, 0);
    Asset_LoadToSegment((u32) ((s32) &D_1000000 & 0x0F000000) >> 0x18, &D_446E30, &D_447D00, 0);
    func_80055948(3);
    func_8005A014(0);
    func_8005A014(1);
    D_82B0852C = -1;
    func_80008514(configuration);
    do {
        main_pool_push_state(0x6C6F6F70);
        switch (state) {
        case 0:
            func_80008624();
            func_82B002B8(arg0, first_frame, var_s3, var_s4);
            state = func_82B00914(first_frame);
            first_frame = 0;
            StageLoader_WaitForRetrace();
            func_8004C398();
            result = func_82B00B78();
            arg0 = result;
            var_s3 = func_82B08508();
            var_s4 = func_82B08514();
            break;
        case 1:
            state = 0;
            if (*request != 0) {
                Fragment_LoadAndCall(((u32) ((s32) &D_82C00000 & 0x0FF00000) >> 0x14) - 0x10, &fragment83_ROM_START, &fragment84_ROM_START, 0x100, *request);
            }
            break;
        }
        main_pool_pop_state(0x6C6F6F70);
    } while (state != 2);
    func_80008574();
    func_80047610();
    Gfx_FreeDisplayListBuffers();
    main_pool_pop_state(0x4556534C);
    return result;
}
/* mkdraft:func_82B00BE0 end */
#endif
