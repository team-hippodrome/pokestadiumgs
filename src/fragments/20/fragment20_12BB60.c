#include "global.h"


#ifdef VERSION_US
typedef struct {
    f32 x;
    f32 y;
} RecordTrailPoint;

// The free-slot scan advances by 2068 bytes; update wraps the point index at 256.
typedef struct {
    s16 index;
    s16 unk_02;
    s16 count;
    s16 unk_06;
    f32 step;
    RecordTrailPoint velocity;
    RecordTrailPoint points[256];
} RecordTrail;
typedef char RecordTrailSize[sizeof(RecordTrail) == 2068 ? 1 : -1];
extern void func_82603D70(RecordTrail *, s32, s32);
extern s32 func_8004C990(s32, s32);
extern s32 func_8004D1FC(u8 *);
extern Gfx *D_800D0510;
extern Gfx D_80094E78[];
extern Gfx D_80094F50[];

void func_82603A90(s16 *arg0) {
    *arg0 = -1;
}

s16 *func_82603A9C(s16 *arg0, s32 arg1) {
    s16 *new_var;
    s16 *current;
    s16 *result;
    s32 index;

    result = 0;
    index = 0;
    if (arg1 > 0) {
        current = (new_var = arg0);
        do {
            index += 1;
            if ((*current) == -1) {
                result = current;
                break;
            }
            current += 0x40A;
        } while (index != arg1);
    }
    return result;
}
void func_82603AD8(RecordTrail *arg0, f32 arg1,
                  RecordTrailPoint *arg2, RecordTrailPoint *arg3) {
    arg0->index = 0;
    arg0->unk_02 = 0;
    arg0->count = 1;
    arg0->step = arg1;
    arg0->velocity = *arg2;
    arg0->points[arg0->index] = *arg3;
}

void TrailEffect_Advance(RecordTrail *arg0, s32 arg1) {
    s32 index;
    RecordTrailPoint origin;
    s32 next_index;

    if (arg0->index != -1) {
        origin = arg0->points[arg0->index];
        for (index = 0; index < arg1; index++) {
            next_index = (arg0->index + index + 1) % 256;
            arg0->points[next_index].x = origin.x + arg0->velocity.x * arg0->step * (index + 1);
            arg0->points[next_index].y = origin.y + arg0->velocity.y * arg0->step * (index + 1);
            if (arg0->count < 256) {
                arg0->count++;
            }
        }
        arg0->index = (arg0->index + arg1) % 256;
        if (arg0->points[arg0->index].x < -640.0f) {
            arg0->index = -1;
        } else if (arg0->points[arg0->index].x > 1280.0f) {
            arg0->index = -1;
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/20/fragment20_12BB60/func_82603D70.s")

extern u8 D_826163E0[];
extern RecordTrail D_826163E8[8];
extern void func_800226C0(s32);
extern s32 func_8004C8C0(u16);

s32 TrailEffect_Initialize(void) {
    s32 index;

    func_800226C0(100);
    _bzero(D_826163E0, 16552);
    if (func_8004C8C0(307) != 0) {
        ((u16 *)D_826163E0)[0] |= 1;
        ((u16 *)D_826163E0)[1] = 32;
        for (index = 0; index < 8; index++) {
            func_82603A90(&D_826163E8[index].index);
        }
    }
    return (((u16 *)D_826163E0)[0] & 1) != 0;
}

/* mkdraft:func_82604170 begin */
extern f32 D_80087E50[];
extern RecordTrailPoint D_826153B0;
extern RecordTrailPoint D_826153B8;
extern RecordTrail D_8261A488;

// Advances all eight trail records by the step count in D_826163E0[2]. While the effect is
// enabled, the first frame after enabling (flag bit 0 of D_826163E0[4] clear) also starts a
// new trail in the first free slot, with a randomized vertical start point. Returns the
// enable flag.


s32 func_82604170(void) {
    s32 result;
    RecordTrail *trail;
    RecordTrailPoint velocity;
    RecordTrailPoint point;

    result = (*(u16 *)D_826163E0 & 1) != 0;
    if (result != 0) {
        result = (*(u16 *)(D_826163E0 + 4) & 1) == 0;
        (*(u16 *)(D_826163E0 + 4))++;
        if (result != 0) {
            trail = (RecordTrail *)func_82603A9C((s16 *)D_826163E8, 8);
            velocity = D_826153B0;
            point = D_826153B8;
            if (trail != NULL) {
                // The 16-bit mask is redundant after the cast; it puts the index temporaries
                // one register above the point-copy ones (t5-t7, not t4-t6).
                point.y = D_80087E50[((u16)guRandom() & 0xFFFF) >> 4] * 240.0f + 240.0f;
                func_82603AD8(trail, 0.5f, &velocity, &point);
            }
        }
        // Init and loop head share a line: as1 orders the two address loads by source line
        // here, and writing them on separate lines reverses the addiu pair.
        trail = D_826163E8; do {
            TrailEffect_Advance(trail, *(s16 *)(D_826163E0 + 2));
            trail++;
        } while (trail != &D_8261A488);
    }
    result = (*(u16 *)D_826163E0 & 1) != 0;
    return result;
}
/* mkdraft:func_82604170 end */

s32 TrailEffect_DrawAll(void) {
    u16 *texture;
    s32 index;

    if ((((u16 *)D_826163E0)[0] & 1) != 0) {
        texture = (u16 *)func_8004C990(307, 2);
        if (func_8004D1FC((u8 *)texture) != 0) {
            gSPDisplayList(D_800D0510++, D_80094E78);
            for (index = 0; index < 8; index++) {
                func_82603D70(&D_826163E8[index], texture[0], texture[1]);
            }
            gSPDisplayList(D_800D0510++, D_80094F50);
        }
    }
    return (((u16 *)D_826163E0)[0] & 1) != 0;
}
#endif
