#include "global.h"


#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/1A360/func_80019760.s")

extern f32 D_800A1F68;
extern f32 D_800A1F6C;
extern f32 D_800A1F70;

// Two register-field rewrites (elsewhere routine closure class): IDO colors the
// then-arm's and-result one t-slot late because the ^ 0 promotion web claims the
// slot before it. The words carry no relocations.
#pragma REWRITE_FUNCTION_WORD(func_80019C08, 0x34, 0x31D8FFFD, 0x31CFFFFD)
#pragma REWRITE_FUNCTION_WORD(func_80019C08, 0x38, 0xA0580001, 0xA04F0001)

// arg1 is a playback speed multiplier: below 2.0 it is clamped to D_800A1F68
// (1.99998) and the double-speed flag at arg0[0xD1] is cleared; at 2.0 or above
// the flag is set, and the multiplier becomes D_800A1F70 (1.99998) when it
// exceeds D_800A1F6C (3.99996) or half of itself otherwise. The result is
// stored as 1.15 fixed point at arg0[0xDC] (speed * 32768.0f).
void func_80019C08(u8 *arg0, f32 arg1) {
    f32 var_fv0;
    f32 limit;
    u8 *temp_v0;
    u8 *temp_v0_2;

    temp_v0 = arg0 + 0xD0;
    var_fv0 = arg1; // FAKE: dead init, removed by uopt; anchors var_fv0 first in the FPR walk (f0) so limit takes f2
    if (arg1 < 2.0f) {
        // FAKE: the (s32 *) cast tree is not CSE-able with temp_v0, keeping this arm's own addiu v0,a0,0xD0
        temp_v0_2 = (u8 *)((s32 *)arg0 + 0x34);
        limit = D_800A1F68;
        if (limit == limit) {} // FAKE: empty if; splits the block so uopt cannot fold temp_v0_2's uses to direct 0xD1(arg0) addressing
        temp_v0_2[1] = (u8)(temp_v0_2[1] & 0xFFFD) ^ 0; // FAKE: ^ 0 survives cfe as a promotion web, claiming the t-slot that colors the else lbu t9/ori t0/mfc1 t2
        var_fv0 = (limit < arg1) ? limit : arg1;
    } else {
        temp_v0[1] |= 2;
        if (D_800A1F6C < arg1) {
            var_fv0 = D_800A1F70;
        } else {
            var_fv0 = arg1 * 0.5f;
        }
    }
    *(s16 *)(arg0 + 0xDC) = (s32)(var_fv0 * 32768.0f);
}
typedef struct Copy32_1A360 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
} Copy32_1A360;
extern Copy32_1A360 D_8008F1E4;
extern void func_8001BE1C(void *, s32, s32);
void func_80019CC0(void *arg0) {
    void *obj = *(void **)((u8 *)arg0 + 0x44);
    if (*(u8 *)((u8 *)obj + 0x28) == 0) {
        func_8001BE1C((u8 *)arg0 + 0x60,
            *(s32 *)((u8 *)(*(void **)((u8 *)obj + 0x60)) + 0x8C),
            (s32)((u8 *)arg0 + 0x36));
    } else {
        func_8001BE1C((u8 *)arg0 + 0x60,
            *(s32 *)((u8 *)obj + 0x2C),
            (s32)((u8 *)arg0 + 0x36));
    }
    *(u8 *)((u8 *)arg0 + 0x34) = 0;
    *(u8 *)((u8 *)arg0 + 0x60) =
        (*(u8 *)((u8 *)arg0 + 0x60) & 0xFFF0) | 1;
    *(Copy32_1A360 *)((u8 *)arg0 + 0xD0) = D_8008F1E4;
}

void func_80019D80(u8 *arg0) {
    if (((u32)(*(s32 *)(arg0 + 0xD0) << 1) >> 31) == 1) {
        *(volatile u8 *)(arg0 + 0xD0) &= 0xFFBF;
    }
    arg0[0x30] = 0;
    *(volatile u8 *)(arg0 + 0xD0) &= 0xFF7F;
    arg0[0x34] = 0;
    *(volatile u8 *)(arg0 + 0xD0) &= 0xFFDF;
    *(s32 *)(arg0 + 0x44) = -1;
    *(s32 *)(arg0 + 0x40) = -1;
    arg0[0x60] &= 0xFFF0;
    *(f32 *)(arg0 + 0x70) = 0.0f;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/1A360/func_80019DE4.s")

void *func_8001A2CC(void *arg0, s32 arg1) {
    u8 *p = (u8 *)arg0;
    void *result;

    if (arg1 < p[1]) {
        result = p + 8;
    } else if (p[2] >= arg1) {
        result = p + 0x10;
    } else {
        result = p + 0x18;
    }
    return result;
}

extern u8 D_8011BE90[];
extern s32 func_80014190();
s32 func_8001A308(s32 arg0, s32 arg1) {
    s32 result;
    u8 *entry;
    if (arg0 == 0xFF) return 0;
    if (func_80014190() == 0) {
        *(s32 *)(D_8011BE90 + 0x2D10) = arg0 + 0x10000000;
        return 0;
    }
    entry = *(u8 **)(D_8011BE90 + 0x2BD8) + arg0 * 0x14;
    if (arg1 >= entry[0]) {
        *(s32 *)(D_8011BE90 + 0x2D10) = (arg0 << 8) + arg1 + 0x03000000;
        return 0;
    }
    result = *(s32 *)(*(u8 **)(entry + 8) + arg1 * 4);
    if (result == 0) {
        *(s32 *)(D_8011BE90 + 0x2D10) = (arg0 << 8) + arg1 + 0x01000000;
        return result;
    }
    return result;
}

s32 func_8001A3DC(s32 arg0, s32 arg1) {
    s32 result;
    u8 *entry;
    s32 *table;
    if (arg0 == 0xFF) return 0;
    if (func_80014190() == 0) {
        *(s32 *)(D_8011BE90 + 0x2D10) = arg0 + 0x10000000;
        return 0;
    }
    entry = *(u8 **)(D_8011BE90 + 0x2BD8) + arg0 * 0x14;
    if (arg1 >= entry[1]) {
        *(s32 *)(D_8011BE90 + 0x2D10) = (arg0 << 8) + arg1 + 0x04000000;
        return 0;
    }
    table = *(s32 **)(entry + 0xC);
    if ((u32)table < 0x80000000U) return 0;
    result = table[arg1];
    if (result == 0)
        *(s32 *)(D_8011BE90 + 0x2D10) = (arg0 << 8) + arg1 + 0x05000000;
    return result;
}

s32 *func_8001A4C0(s32 arg0, s32 arg1) {
    s32 *result;
    u8 *entry;
    void *base;
    if (arg0 == 0xFF) return NULL;
    if (func_80014190() == 0) {
        *(s32 *)(D_8011BE90 + 0x2D10) = arg0 + 0x10000000;
        return NULL;
    }
    entry = *(u8 **)(D_8011BE90 + 0x2BD8) + arg0 * 0x14;
    if (arg1 >= *(u16 *)(entry + 4)) {
        *(s32 *)(D_8011BE90 + 0x2D10) = (arg0 << 8) + arg1 + 0x04000000;
        return NULL;
    }
    base = *(void **)(entry + 0x10);
    result = (s32 *)((u8 *)base + (arg1 << 3));
    if ((u32)base < 0x80000000U) return NULL;
    if (result == NULL)
        *(s32 *)(D_8011BE90 + 0x2D10) = (arg0 << 8) + arg1 + 0x05000000;
    if (*result == 0) return NULL;
    return result;
}

extern u8 *D_8011EA68;
extern s32 func_80014190(s32);
s32 ResourceCatalog_SetEntry(s32 kind, s32 catalog_id, s32 index, void *value) {
    typedef struct {
        u32 word0, word1;
    } ResourcePair;
    typedef struct {
        u8 resource_count, primary_count, pool_a, pool_b;
        u16 secondary_count, unknown_06;
        void **resources;
        void **primary;
        ResourcePair *secondary;
    } ResourceCatalog;
    ResourceCatalog *catalog;
    if (catalog_id == 0xFF) { return -1; }
    if (func_80014190(catalog_id) == 0) { return -2; }
    switch (kind) {
    case 0:
        catalog = &((ResourceCatalog *)D_8011EA68)[catalog_id];
        if (index >= catalog->primary_count) { return -3; }
        catalog->primary[index] = value;
        break;
    case 1:
        catalog = &((ResourceCatalog *)D_8011EA68)[catalog_id];
        if (index >= catalog->secondary_count) { return -3; }
        catalog->secondary[index] = *(ResourcePair *)value;
        break;
    default:
        catalog = &((ResourceCatalog *)D_8011EA68)[catalog_id];
        if (index >= catalog->resource_count) { return -3; }
        catalog->resources[index] = value;
        break;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/1A360/func_8001A6F8.s")

extern void func_8001A6F8(void *arg0, s32 arg1);
void func_8001A994(void *arg0) {
    func_8001A6F8(arg0, 6);
}

void func_8001A9B4(void *arg0) {
    func_8001A6F8(arg0, 7);
}

void func_8001A9D4(u32 *arg0) {
    arg0[0] = (u32)arg0;
    arg0[1] = (u32)arg0;
    arg0[2] = 0;
}

void func_8001A9E4(void *arg0) {
    func_8001A9D4(arg0);
    func_8001A9D4((u8 *)arg0 + 0x10);
    func_8001A9D4((u8 *)arg0 + 0x20);
    func_8001A9D4((u8 *)arg0 + 0x30);
    *(u32 *)((u8 *)arg0 + 0x0C) = (u32)arg0;
    *(u32 *)((u8 *)arg0 + 0x1C) = (u32)arg0;
    *(u32 *)((u8 *)arg0 + 0x2C) = (u32)arg0;
    *(u32 *)((u8 *)arg0 + 0x3C) = (u32)arg0;
}

extern u8 D_80121F04[];
extern void func_8001CB1C(void *, void *);
void ResourcePool_InitLists(void) {
    typedef struct PoolRecord { struct PoolRecord *next; struct PoolRecord *prev; u32 self; u8 unknown_0C[0xF4]; } PoolRecord;
    u32 index;
    PoolRecord *records;
    u32 node_address;
    func_8001A9E4(D_80121F04);
    for (index = 0; index < *(u32 *)(D_8011BE90 + 0x2C28); index++) {
        records = *(PoolRecord **)(D_8011BE90 + 0x3468);
        records[index].self = (u32)&records[index];
        (*(PoolRecord **)(D_8011BE90 + 0x3468))[index].next = NULL;
        node_address = (index * 0x100);
        node_address += *(u32 *)(D_8011BE90 + 0x3468);
        func_8001CB1C(D_80121F04, (void *)node_address);
    }
}

extern u8 D_80121F14[];
extern u8 D_80121F24[];
extern u8 D_80121F34[];
extern void func_8001ADB4(void *);
// Returns all four note lists to their corresponding shared free lists.
void AudioNotePool_Clear(void *arg0) {
    typedef struct PoolNode { struct PoolNode *prev; struct PoolNode *next; union { void *value; s32 count; } u; void *pool; } PoolNode;
    typedef struct PoolHeads { PoolNode disabled; PoolNode decaying; PoolNode releasing; PoolNode active; } PoolHeads;
    s32 group;
    PoolNode *source;
    PoolNode *entry;
    PoolNode *destination;
    PoolHeads *pool;
    pool = arg0;
    for (group = 0; group != 4; group++) {
        switch (group) {
        case 0:
            source = &pool->disabled;
            destination = (PoolNode *)D_80121F04;
            break;
        case 1:
            source = &pool->decaying;
            destination = (PoolNode *)D_80121F14;
            break;
        case 2:
            source = &pool->releasing;
            destination = (PoolNode *)D_80121F24;
            break;
        case 3:
            source = &pool->active;
            destination = (PoolNode *)D_80121F34;
            break;
        }
        for (;;) {
            entry = source->next;
            if (entry == source) { break; }
            if (entry == NULL) { break; }
            func_8001ADB4(entry);
            func_8001CB1C(destination, entry);
        }
    }
}

extern void AudioNotePool_Clear(void *);
extern s32 func_8001CB5C(void *);
// Returns existing entries before acquiring up to count entries from four shared lists.
void ResourcePool_AcquireEntries(u8 *pool, u32 count) {
    u32 total;
    s32 group;
    s32 entry;
    u8 *source;
    u8 *destination;
    AudioNotePool_Clear(pool);
    group = 0;
    total = 0;
    while (total < count) {
        if (group == 4) { break; }
        switch (group) {
        case 0:
            source = D_80121F04;
            destination = pool;
            break;
        case 1:
            source = D_80121F14;
            destination = pool + 16;
            break;
        case 2:
            source = D_80121F24;
            destination = pool + 32;
            break;
        case 3:
            source = D_80121F34;
            destination = pool + 48;
            break;
        }
        while (total < count) {
            entry = func_8001CB5C(source);
            if (entry == 0) { break; }
            func_8001CB1C(destination, (void *)entry);
            total++;
        }
        group++;
    }
}

void func_8001AD74(s32 *arg0, s32 *arg1) {
    if ((*(s32 **)((u8 *)(arg1) + (0))) == NULL) {
        (*(s32 **)((u8 *)(arg1) + (0))) = arg0;
        (*(s32 **)((u8 *)(arg1) + (4))) = (s32 *) (*(s32 **)((u8 *)(arg0) + (4)));
        *(*(s32 ***)((u8 *)(arg0) + (4))) = arg1;
        (*(s32 **)((u8 *)(arg0) + (4))) = arg1;
        (*(s32 *)((u8 *)(arg0) + (8))) = (s32) ((*(s32 *)((u8 *)(arg0) + (8))) + 1);
        (*(s32 *)((u8 *)(arg1) + (0xC))) = (s32) (*(s32 *)((u8 *)(arg0) + (0xC)));
    }
}

void func_8001ADB4(void *arg0) {
    void *temp_v0;

    temp_v0 = (*(void **)((u8 *)(arg0) + (0)));
    if (temp_v0 != NULL) {
        (*(void ***)((u8 *)(temp_v0) + (4))) = (void **) (*(void ***)((u8 *)(arg0) + (4)));
        *(*(void ***)((u8 *)(arg0) + (4))) = (*(void **)((u8 *)(arg0) + (0)));
        (*(void **)((u8 *)(arg0) + (0))) = NULL;
    }
}

typedef struct ListNode1A360 {
    void *unk0;
    struct ListNode1A360 *next;
    u8 *data;
} ListNode1A360;
void *func_8001ADE0(ListNode1A360 *arg0, s32 arg1) {
    ListNode1A360 *cur;
    ListNode1A360 *best;
    u8 *result;
    cur = arg0->next;
    if (cur == arg0) {
        return NULL;
    }
    best = cur;
    while (cur != arg0) {
        if (best->data[0x30] >= cur->data[0x30]) {
            best = cur;
        }
        cur = cur->next;
    }
    if (best == NULL) {
        return NULL;
    }
    result = best->data;
    if (result[0x30] >= arg1) {
        return NULL;
    }
    return result;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/1A360/func_8001AE60.s")

void func_8001AFAC(void *arg0, s32 arg1) {
    func_8001A9B4((*(void **)((u8 *)(arg0) + (0x44))));
    (*(s32 *)((u8 *)(arg0) + (0x48))) = arg1;
}

extern f32 D_8011EA88;
void AudioVoice_SetPendingRequest(void *voice, void *request) {
    typedef struct {
        u16 high : 3;
        u16 pending : 1;
        u16 low : 12;
    } PendingFlags;
    *(void **)((u8 *)voice + 0x48) = request;
    *((u8 *)voice + 0x30) = (*(u8 **)((u8 *)request + 0x60))[5];
    *(f32 *)((u8 *)voice + 0x6C) = D_8011EA88;
    ((PendingFlags *)((u8 *)voice + 0x60))->pending = 1;
}

s32 func_8001B00C(s32 *arg0, s32 arg1) {
    s32 v = func_8001CB5C(arg0);
    if (v) {
        func_8001AE60(v, arg1);
        func_8001AD74((u8 *)arg0 + 0x30, v);
    }
    return v;
}

extern void AudioVoice_SetPendingRequest(void *, void *);
void *func_8001B058(void *arg0, void *arg1) {
    void *result = func_8001ADE0((ListNode1A360 *)((u8 *)arg0 + 0x10),
        *(u8 *)((u8 *)(*(void **)((u8 *)arg1 + 0x60)) + 5));
    if (result != NULL) {
        AudioVoice_SetPendingRequest(result, arg1);
        func_8001CB1C((u8 *)arg0 + 0x20, result);
    }
    return result;
}

/* mkdraft:func_8001B0B0 begin */
void *func_8001B0B0(void *arg0, void *arg1) {
    void *result1;
    void *result2;
    s32 size1;
    s32 size2;

    size2 = 0x10, size1 = 0x10;
    result1 = func_8001ADE0((ListNode1A360 *)((u8 *)arg0 + 0x20),
        *(u8 *)((u8 *)(*(void **)((u8 *)arg1 + 0x60)) + 5));
    if (result1 != NULL) {
        size1 = *(u8 *)((u8 *)result1 + 0x30);
    }
    result2 = func_8001ADE0((ListNode1A360 *)((u8 *)arg0 + 0x30),
        *(u8 *)((u8 *)(*(void **)((u8 *)arg1 + 0x60)) + 5));
    if (result2 != NULL) {
        size2 = *(u8 *)((u8 *)result2 + 0x30);
    }
    if ((result1 == NULL) && (result2 == NULL)) {
        return NULL;
    }
    if (size2 < size1) {
        func_8001ADB4(result2);
        func_8001AFAC(result2, (s32)arg1);
        func_8001CB1C((u8 *)arg0 + 0x20, result2);
        *(u8 *)((u8 *)result2 + 0x30) =
            *(u8 *)((u8 *)(*(void **)((u8 *)arg1 + 0x60)) + 5);
        return result2;
    }
    *(void **)((u8 *)result1 + 0x48) = arg1;
    *(u8 *)((u8 *)result1 + 0x30) =
        *(u8 *)((u8 *)(*(void **)((u8 *)arg1 + 0x60)) + 5);
    return result1;
}
/* mkdraft:func_8001B0B0 end */

void *func_8001B1A8(void *arg0, void *arg1) {
    void *result = func_8001ADE0((ListNode1A360 *)((u8 *)arg0 + 0x30),
        *(u8 *)((u8 *)(*(void **)((u8 *)arg1 + 0x60)) + 5));
    if (result != NULL) {
        func_8001AFAC(result, (s32)arg1);
        func_8001CB1C((u8 *)arg0 + 0x20, result);
        *(u8 *)((u8 *)result + 0x30) =
            *(u8 *)((u8 *)(*(void **)((u8 *)arg1 + 0x60)) + 5);
    }
    return result;
}

void *AudioVoice_AcquireForRequest(u8 *request) {
    typedef struct { u8 high:4; u8 requested:1; u8 middle:2; u8 active:1; } RequestFlags;
    u8 *voice;
    if (((*(u8 **)(request + 0x60))[2] & 1) && (voice = *(u8 **)(request + 0x3C)) != NULL &&
        *(u8 **)(voice + 0x40) == request && *(s32 *)(voice + 0x48) == -1) {
        AudioVoice_SetPendingRequest(voice, request);
        func_8001ADB4(voice);
        func_8001CB1C(*(u8 **)(voice + 12) + 32, voice);
        return voice;
    }
    if (((*(u8 **)(request + 0x60))[2] & 2)) {
        if ((voice = (u8 *)func_8001B00C((s32 *)(*(u8 **)(request + 0x60) + 0x90), (s32)request)) != NULL ||
            (voice = func_8001B058((*(u8 **)(request + 0x60) + 0x90), request)) != NULL ||
            (voice = func_8001B0B0((*(u8 **)(request + 0x60) + 0x90), request)) != NULL ||
            (voice = func_8001B1A8((*(u8 **)(request + 0x60) + 0x90), request)) != NULL) {
            return voice;
        }
    } else if (((*(u8 **)(request + 0x60))[2] & 4)) {
        if ((voice = (u8 *)func_8001B00C((s32 *)(*(u8 **)(request + 0x60) + 0x90), (s32)request)) != NULL ||
            (voice = (u8 *)func_8001B00C((s32 *)(*(u8 **)(*(u8 **)(request + 0x60) + 0x50) + 0x9C), (s32)request)) != NULL ||
            (voice = func_8001B058((*(u8 **)(request + 0x60) + 0x90), request)) != NULL ||
            (voice = func_8001B058((*(u8 **)(*(u8 **)(request + 0x60) + 0x50) + 0x9C), request)) != NULL ||
            (voice = func_8001B0B0((*(u8 **)(request + 0x60) + 0x90), request)) != NULL ||
            (voice = func_8001B0B0((*(u8 **)(*(u8 **)(request + 0x60) + 0x50) + 0x9C), request)) != NULL ||
            (voice = func_8001B1A8((*(u8 **)(request + 0x60) + 0x90), request)) != NULL ||
            (voice = func_8001B1A8((*(u8 **)(*(u8 **)(request + 0x60) + 0x50) + 0x9C), request)) != NULL) {
            return voice;
        }
    } else if (((*(u8 **)(request + 0x60))[2] & 8)) {
        if ((voice = (u8 *)func_8001B00C((s32 *)D_80121F04, (s32)request)) != NULL ||
            (voice = func_8001B058(D_80121F04, request)) != NULL ||
            (voice = func_8001B0B0(D_80121F04, request)) != NULL ||
            (voice = func_8001B1A8(D_80121F04, request)) != NULL) {
            return voice;
        }
    } else {
        if ((voice = (u8 *)func_8001B00C((s32 *)(*(u8 **)(request + 0x60) + 0x90), (s32)request)) != NULL ||
            (voice = (u8 *)func_8001B00C((s32 *)(*(u8 **)(*(u8 **)(request + 0x60) + 0x50) + 0x9C), (s32)request)) != NULL ||
            (voice = (u8 *)func_8001B00C((s32 *)D_80121F04, (s32)request)) != NULL ||
            (voice = func_8001B058((*(u8 **)(request + 0x60) + 0x90), request)) != NULL ||
            (voice = func_8001B058((*(u8 **)(*(u8 **)(request + 0x60) + 0x50) + 0x9C), request)) != NULL ||
            (voice = func_8001B058(D_80121F04, request)) != NULL ||
            (voice = func_8001B0B0((*(u8 **)(request + 0x60) + 0x90), request)) != NULL ||
            (voice = func_8001B0B0((*(u8 **)(*(u8 **)(request + 0x60) + 0x50) + 0x9C), request)) != NULL ||
            (voice = func_8001B0B0(D_80121F04, request)) != NULL ||
            (voice = func_8001B1A8((*(u8 **)(request + 0x60) + 0x90), request)) != NULL ||
            (voice = func_8001B1A8((*(u8 **)(*(u8 **)(request + 0x60) + 0x50) + 0x9C), request)) != NULL ||
            (voice = func_8001B1A8(D_80121F04, request)) != NULL) {
            return voice;
        }
    }
    ((RequestFlags *)request)->requested = 1;
    return NULL;
}

extern u8 D_8011EBF0[];
extern Copy32_1A360 D_8008F1C4;
extern s32 func_800104A0(void *, s32);
// Initializes each 0x100-byte voice record and allocates its 480-byte buffer.
void AudioVoicePool_Init(void) {
    s32 index;
    u8 *voice;
    u32 voice_address;
    for (index = 0; index < *(s32 *)(D_8011BE90 + 0x2C28); index++) {
        voice_address = index * 0x100;
        voice_address += *(u32 *)(D_8011BE90 + 0x3468);
        voice = (u8 *)voice_address;
        *(Copy32_1A360 *)(voice + 0xD0) = D_8008F1C4;
        voice[0x30] = 0;
        voice[0x34] = 0;
        *(s32 *)(voice + 0x44) = -1;
        *(s32 *)(voice + 0x48) = -1;
        *(s32 *)(voice + 0x40) = -1;
        voice[0x31] = 0;
        *(f32 *)(voice + 0x58) = 0.0f;
        *(s16 *)(voice + 0x36) = 0;
        voice[0x60] = 0;
        voice[0xA0] = 0;
        *(s16 *)(voice + 0x82) = 0;
        *(s16 *)(voice + 0x84) = 0;
        voice[0x35] = 0;
        *(u32 *)(voice + 0xB0) = 0;
        *(s32 *)(voice + 0x20) = func_800104A0(D_8011EBF0, 480);
    }
}
// The retail owner ends with two alignment nops.
#pragma C_FUNCTION_PADDING(8)
#endif
