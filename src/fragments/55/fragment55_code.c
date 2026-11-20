#include "global.h"

typedef struct {
    s32 mode;
    u8 unk04[0xC];
    s32 time;
    u8 unk14[8];
    f32 unk1C;
    u8 unk20[4];
    f32 unk24;
    u8 unk28[8];
    s32 transition_mode;
    u8 unk34[8];
    s32 animation_frame;
    u8 unk40[8];
    s32 exit_result;
} Stage55MainState;
extern Stage55MainState gStage55MainState;

typedef struct {
    s32 resource_index;
    s32 unk04[3];
} Stage55Slot;

struct Stage55FadeModel {
    u8 unk00[0x1D];
    u8 alpha;
    u8 unk1E[0x1A];
    f32 scale_z;
    u8 unk3C[0x12C];
};

typedef struct {
    u8 pad00[0x14];
    s32 unk14;
    u8 pad18[6];
    s16 unk1E;
    s16 unk20;
    u8 pad22[2];
    f32 x;
    f32 y;
    f32 z;
    f32 scale[3];
    u8 tail[0x12C];
} Row86706A30;

typedef struct State86703DF4 {
    u8 pad00[8];
    s32 unk08;
    u8 pad0C[4];
    f32 unk10;
    s32 unk14;
    s32 unk18;
    f32 unk1C;
    s32 unk20;
    u8 pad24[8];
    s32 unk2C;
    u8 pad30[8];
    s32 unk38;
    u8 pad3C[12];
    s32 unk48;
    s32 unk4C;
    u8 pad50[4];
    s32 unk54;
    f32 unk58;
    f32 unk5C;
    s32 unk60;
    s32 unk64;
    s32 unk68;
    s32 unk6C;
    u8 pad70[4];
    s32 unk74;
    u8 pad78[4];
    s32 unk7C;
    u8 pad80[4];
    f32 unk84;
    u8 pad88[12];
    s32 unk94;
    u8 pad98[4];
    s32 unk9C;
    s32 unkA0;
    s32 unkA4;
    u8 padA8[4];
} State86703DF4;


#ifdef VERSION_US
extern Gfx *D_800D0510;
extern s32 func_8004C990(s32, s32);
extern u8 *func_8004CA60(u8 *);
extern void GeoRender_ApplyMaterialState(void);
extern u8 D_8670BA40[];
extern u8 D_8670B660[];
extern void func_8003F114(u8 *, s16, s16, void *);
void func_86700020(s32 arg0, s32 arg1) {
    if (arg0 == 5) {
        gDPPipeSync(D_800D0510++);
        gSPSegment(D_800D0510++, 0xF, func_8004CA60((u8 *)func_8004C990(0x133, 1)));
        gSPDisplayList(D_800D0510++, D_8670BA40);
        GeoRender_ApplyMaterialState();
    }
}
#endif

#ifdef VERSION_US
extern Gfx *D_800D0510;
extern s32 func_8004C990(s32, s32);
extern u8 *func_8004CA60(u8 *);
extern void GeoRender_ApplyMaterialState(void);
extern u8 D_8670BA40[];
extern u8 D_8670B660[];
void func_867000C8(s32 arg0, s32 arg1) {
    if (arg0 == 5) {
        gDPPipeSync(D_800D0510++);
        gSPSegment(D_800D0510++, 0xF, func_8004CA60((u8 *)func_8004C990(0x3E, 1)));
        gDPSetEnvColor(D_800D0510++, 0, 0, 0xFF, 0xFF);
        gSPDisplayList(D_800D0510++, D_8670B660);
        GeoRender_ApplyMaterialState();
    }
}
#endif

#ifdef VERSION_US
extern void *D_8009491C;
extern s32 D_8670B394;
extern s32 D_8670C958;
extern u32 func_8003570C(void);
extern void GeoRender_ApplyMaterialState(void);
extern s32 func_8004C990(s32, s32);
extern u8 * func_8004CA60(u8 *);
extern Gfx * D_800D0510;
void Stage55_DrawAnimatedResource(s32 arg0, s32 arg1) {
    u32 advance;
    s32 frame;
    s32 resource;
    u8 *context;
    if (arg0 == 0) {
        func_8004C990(205, 0);
    }
    if (arg0 == 5) {
        context = D_8009491C;
        if (*(u32 *)(context + 0x14) >= 72) {
            *(u32 *)(context + 0x14) = 0;
        }
        frame = (*(u32 *)(context + 0x14)) / 3;
        if (frame >= 12) {
            frame = 0;
            if (D_8670B394 == 0) {
                advance = func_8003570C() & 1;
                (*(u32 *)(context + 0x14)) += advance;
            }
        } else if (frame >= 6) {
            frame = 11 - frame;
        }
        resource = func_8004C990(205, frame);
        gDPPipeSync(D_800D0510++);
        gDPSetCombine(D_800D0510++, 0xFFFFFF, 0xFFFCF238);
        gSPSegment(D_800D0510++, 15, func_8004CA60((u8 *)resource));
        gSPDisplayList(D_800D0510++, D_8670C958);
        GeoRender_ApplyMaterialState();
        if (D_8670B394 == 0) {
            (*(u32 *)(context + 0x14))++;
        }
    }
}
#endif

#ifdef VERSION_US
extern s32 D_8670C970;
extern s32 D_8670BB84;
extern s32 D_8670C96C;
extern void GeoRender_ApplyMaterialState(void);
extern s32 func_8004C990(s32, s32);
extern u8 * func_8004CA60(u8 *);
extern Gfx * D_800D0510;
void func_86700318(s32 arg0, s32 arg1) {
    s32 temp_v0;
    if (arg0 == 0) { D_8670C970 = func_8004C990(0xE3, 0); }
    if (arg0 == 5) {
        temp_v0 = func_8004C990(0xE3, D_8670BB84); D_8670C970 = temp_v0;
        gDPPipeSync(D_800D0510++); gDPSetCombine(D_800D0510++, 0xFCFFFFFF, 0xFFFCF238);
        gSPSegment(D_800D0510++, 0xF, func_8004CA60((u8 *)D_8670C970)); gSPDisplayList(D_800D0510++, D_8670C96C); GeoRender_ApplyMaterialState();
    }
}
#endif

#ifdef VERSION_US
/* mkdraft:func_86700418 begin */
extern Gfx *D_800D0510;
extern void *D_8009491C;
extern s32 D_8670BBA4;
extern s32 D_8670BD38[];
extern s32 D_8670AB90[];
extern State86703DF4 D_86728408[];
extern s32 D_8670C968;
extern void *D_8670C964;
extern s32 func_8004C990(s32, s32);
extern u8 *func_8004CA60(u8 *);
extern void func_8003CD84(void);

/* function: func_86700418 */


void func_86700418(s32 arg0, s32 arg1) {
    void *context;
    s32 index;
    s32 spare; // FAKE: declared-only local; its home slot makes the frame 0x38 bytes and
               // moves the context spill to 0x34(sp). Without it the frame is 0x30 bytes
               // and the diff score is 52.

    if (arg0 == 5) {
        context = D_8009491C;
        index = *(s32 *)((u8 *)context + 0x14);
        // FAKE: the 3-way read of context makes IDO place the context spill after the
        // li a0,0x1B2. Without the statement the spill moves earlier and the reloc-aware
        // diff score is 240.
        if ((context && context) && context) {
        }
        // D_86728458[i] is the word at &D_86728408[i] + 0x50. This file declares
        // D_86728458 itself (as Stage55VariantIndex[]) only after this function, and a
        // second declaration of it here conflicts with that one.
        D_8670C968 = func_8004C990(0x1B2,
                                   D_8670AB90[*(s32 *)((u8 *)&D_86728408[D_8670BD38[index]] + 0x50)]);
        if (D_8670BBA4 == 1) {
            gDPPipeSync(D_800D0510++);
            gDPSetPrimColor(D_800D0510++, 0, 0, 255, 255, 255, 100);
            gDPSetCombine(D_800D0510++, 0xFCFF97FF, 0xFFFCFE38);
            gSPSegment(D_800D0510++, 0xF, func_8004CA60((u8 *)D_8670C968));
            gSPDisplayList(D_800D0510++, D_8670C964);
            func_8003CD84();
        } else {
            *(f32 *)((u8 *)context + 0x2C) = -5000.0f;
        }
    }
}
/* mkdraft:func_86700418 end */
#endif

#ifdef VERSION_US
extern void *D_8009491C;
extern s32 D_8670BBA4;
extern s32 D_8670BD64[];
// 0xAC-byte records; func_86700588 reads the word at 0x0 as an index into D_8670BD64.
extern struct { s32 unk_00; u8 unk_04[0xA8]; } D_8672843C[];
extern s32 D_8670C960;
extern void *D_8670C95C;

// Same code as func_867006C4 with resource 387, its frame taken from
// D_8670BD64[D_8672843C[index].unk_00], and display list D_8670C95C; GS draws only
// while D_8670BBA4 is 1 and otherwise stores -5000.0f at 0x2C of the context.
void func_86700588(s32 arg0, s32 arg1) {
    void *context;
    s32 index;

    if (arg0 == 5) {
        context = D_8009491C;
        index = *(s32 *)((u8 *)context + 0x14);
        if (D_8670BBA4 == 1) {
            D_8670C960 = func_8004C990(387, D_8670BD64[D_8672843C[index].unk_00]);
            gDPPipeSync(D_800D0510++);
            gDPSetCombine(D_800D0510++, 0xFFFFFF, 0xFFFCF238);
            gSPSegment(D_800D0510++, 0xF,
                       func_8004CA60((u8 *)D_8670C960));
            gSPDisplayList(D_800D0510++, D_8670C95C);
            GeoRender_ApplyMaterialState();
        } else {
            *(f32 *)((u8 *)context + 0x2C) = -5000.0f;
        }
    }
}
#endif

#ifdef VERSION_US
extern Gfx *D_800D0510;
extern void *D_8009491C;
extern s32 func_8004C990(s32, s32);
extern u8 *func_8004CA60(u8 *);
extern void GeoRender_ApplyMaterialState(void);
extern s32 D_8670AB90[];
extern s32 D_8670C97C;
extern void *D_8670C978;
/* function: func_867006C4 */
void func_867006C4(s32 arg0, s32 arg1) {
    void *context;
    s32 index;

    if (arg0 == 5) {
        context = D_8009491C;
        index = *(s32 *)((u8 *)context + 0x14);
        D_8670C97C = func_8004C990(0x1B2, D_8670AB90[index]);
        gDPPipeSync(D_800D0510++);
        gDPSetCombine(D_800D0510++, 0xFFFFFF, 0xFFFCF238);
        gSPSegment(D_800D0510++, 0xF,
                   func_8004CA60((u8 *)D_8670C97C));
        gSPDisplayList(D_800D0510++, D_8670C978);
        GeoRender_ApplyMaterialState();
    }
}
#endif

#ifdef VERSION_US
/* mkdraft:func_867007B4 begin */
typedef struct {
    u8 unk00[0x24];
    s32 count;
    f32 offset;
    u8 unk2C[0x80];
} Stage55ScrollState;

extern State86703DF4 D_86728408[];
extern Vtx D_8670B850[];
extern f32 D_8670B810[];
extern u8 D_8670B950[];
extern s32 D_8670B35C;
extern f32 D_8670B360;
extern Gfx *Gfx_AllocDisplayList(s32);



void func_867007B4(s32 arg0, u8 *arg1) {
    s32 index = *(s32 *)(arg1 + 0x14);
    s32 i;

    if (arg0 == 5) {
        Stage55ScrollState *state = (Stage55ScrollState *)&D_86728408[index];
        Vtx *vtx = (Vtx *)Gfx_AllocDisplayList(16 * sizeof(Vtx));
        u8 *texture;

        gSPDisplayList(D_800D0510++, D_8670B950);
        gDPPipeSync(D_800D0510++);
        gDPSetCombine(D_800D0510++, 0xFFFFFF, 0xFFFCF238);
        gSPSegment(D_800D0510++, 0xF, func_8004CA60((u8 *)func_8004C990(0xE2, 0)));
        texture = func_8004CA60((u8 *)func_8004C990(0xE2, 0));

        if (state->offset >= 32.0f) {
            state->offset = state->offset - (f32)32;
            state->count++;
            if (state->count >= D_8670B35C && state->offset >= D_8670B360) {
                state->offset = D_8670B360 + 1.0f;
            }
            if (state->count >= 62) {
                state->count = 0;
            }
        }

        for (i = 0; i < 16; i++) {
            vtx[i] = D_8670B850[i];
            // FAKE: the byte-cast offset read is what makes IDO load the scroll offset before
            // the table entry, and keeps the table in f16 as the add destination.
            *(s16 *)((u8 *)vtx + i * 0x10 + 0xA) =
                (s16)((D_8670B810[i] + *(f32 *)((u8 *)state + 0x28)) * 32.0f);
        }

        gDPLoadTextureBlockS(D_800D0510++, texture + state->count * 0x800, G_IM_FMT_RGBA,
                             G_IM_SIZ_16b, 32, 64, 0, G_TX_NOMIRROR | G_TX_WRAP,
                             G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                             G_TX_NOLOD, G_TX_NOLOD);
        gSPVertex(D_800D0510++, vtx, 16, 0);
        gSP2Triangles(D_800D0510++, 0, 1, 2, 0, 0, 2, 3, 0);
        gDPLoadTextureBlockS(D_800D0510++, texture + state->count * 0x800 + 0x800, G_IM_FMT_RGBA,
                             G_IM_SIZ_16b, 32, 64, 0, G_TX_NOMIRROR | G_TX_WRAP,
                             G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                             G_TX_NOLOD, G_TX_NOLOD);
        gSP2Triangles(D_800D0510++, 4, 5, 6, 0, 4, 6, 7, 0);
        gDPLoadTextureBlockS(D_800D0510++, texture + state->count * 0x800 + 0x1000, G_IM_FMT_RGBA,
                             G_IM_SIZ_16b, 32, 64, 0, G_TX_NOMIRROR | G_TX_WRAP,
                             G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                             G_TX_NOLOD, G_TX_NOLOD);
        gSP2Triangles(D_800D0510++, 8, 9, 10, 0, 8, 10, 11, 0);
        gDPLoadTextureBlockS(D_800D0510++, texture + state->count * 0x800 + 0x1800, G_IM_FMT_RGBA,
                             G_IM_SIZ_16b, 32, 64, 0, G_TX_NOMIRROR | G_TX_WRAP,
                             G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                             G_TX_NOLOD, G_TX_NOLOD);
        gSP2Triangles(D_800D0510++, 12, 13, 14, 0, 12, 14, 15, 0);
        func_8003CD84();
    }
}
/* mkdraft:func_867007B4 end */
#endif

#ifdef VERSION_US
extern Stage55Slot D_8670C980[4][60];
extern Row86706A30 D_86710C20[];
extern Row86706A30 D_86711760[4][60];
extern f32 D_8670C890;
extern u8 D_86728348[];

// Scans the 60 slots of row arg0 in groups of four and keeps the highest index whose z
// is not above the running limit, not below the row z, and whose unk04[0] flag word is
// not negative. arg1 != 0 uses a 1000.0f limit and returns the plain index; arg1 == 0
// starts the limit 30.0f * D_8670C890 above the row z and returns D_86728348[arg0 * 0x38]
// when no slot qualified (best_i still the 0x3E8 sentinel).
s32 func_86700FD4(s32 arg0, s32 arg1) {
    Row86706A30 *row;
    f32 z0;
    f32 z1;
    f32 z2;
    f32 z3;
    f32 limit;
    s32 i;
    s32 best_i;
    s32 result;

    limit = 1000.0f;
    best_i = 0x3E8;
    if (arg1 == 0) {
        limit = D_86710C20[arg0].z + (30.0f * D_8670C890);
    }
    for (i = 0, row = D_86711760[arg0]; i != 0x3C; i += 4, row += 4) {
        z0 = row->z;
        if (((row->z) <= limit) && (D_86710C20[arg0].z <= z0) && (D_8670C980[arg0][i].unk04[0] >= 0)) {
            best_i = i;
            limit = z0;
        }
        z1 = row[1].z;
        if ((z1 <= limit) && (D_86710C20[arg0].z <= z1) && (D_8670C980[arg0][i + 1].unk04[0] >= 0)) {
            best_i = i + 1;
            limit = z1;
        }
        z2 = row[2].z;
        if ((z2 <= limit) && (D_86710C20[arg0].z <= z2) && (D_8670C980[arg0][i + 2].unk04[0] >= 0)) {
            best_i = i + 2;
            limit = z2;
        }
        z3 = row[3].z;
        if ((z3 <= limit) && (D_86710C20[arg0].z <= z3) && (D_8670C980[arg0][i + 3].unk04[0] >= 0)) {
            best_i = i + 3;
            limit = z3;
        }
    }
    if ((arg1 == 0) && (best_i == 0x3E8)) {
        result = *(s32 *)((u8 *)D_86728348 + arg0 * 0x38);
        return result;
    }
    return best_i;
}

// Bytes at the retail stub address between the two functions: an
// unreferenced empty function compiles to the retail jr ra/nop pair
// there and keeps the fragment layout.
void func_86701224_padding(void) {}
#endif

#ifdef VERSION_US
extern u32 func_8003570C(void);
extern State86703DF4 D_86728408[];
extern Row86706A30 D_86710C20[];
extern Row86706A30 D_86711760[4][60];
extern s32 D_8670C984[4][60][4];
extern s32 D_8670BD74[];
extern s32 D_8670BD84[];
extern s32 D_8670BB8C;
extern s32 D_8670B374;
extern s32 D_86728328;

typedef struct {
    f32 unk00;
    u8 pad04[0x10];
    s32 unk14;
    u8 pad18[0x08];
    s32 unk20;
    u8 pad24[0x14];
} Stage55RankCtx;



s32 func_8670122C(s32 arg0) {
    State86703DF4 *state;
    Stage55RankCtx *ctx;
    Row86706A30 *row;
    Row86706A30 *cur;
    s32 *flag_ptr;
    s32 flag;
    s32 slot_id;
    s32 found;
    s32 index;
    s32 chance;
    s32 st;
    s32 one = 1;
    f32 z;
    f32 limit;

    state = &D_86728408[arg0];
    flag = 0;
    if (one == *(s32 *) ((u8 *) state + 0x34)) {
        flag = one;
    }
    ctx = (Stage55RankCtx *) ((u8 *) &D_86728328 + arg0 * 0x38);
    cur = &D_86710C20[arg0];
    limit = (ctx->unk00 + cur->z) - (f32) (flag * 0x96);
    found = 0x3E8;
    row = D_86711760[arg0];
    for (index = 0; index < 0x3C; index++) {
        z = row->z;
        if (z <= limit) {
            if (cur->z <= z) {
                slot_id = D_8670C984[arg0][index][0];
                if (slot_id >= 0) {
                    flag_ptr = &D_8670B374 + arg0;
                    if (*flag_ptr == 4) {
                        return index;
                    }
                    if (slot_id == 0xA) {
                        chance = func_8003570C() % 101;
                        if ((ctx->unk14 != 0) && (*(f32 *) ((u8 *) state + 0x10)) > 50.0f) {
                            chance = 0x64;
                        }
                        st = *(s32 *) ((u8 *) state + 0x34);
                        if ((D_8670BD74[*flag_ptr] + D_8670BD84[st]) < chance
                            || D_8670BB8C != 0) {
                            found = index;
                            limit = z;
                        }
                    } else {
                        found = index;
                        limit = z;
                    }
                }
            }
        }
        if (one == index) {}
        row++;
    }
    if (found == 0x3E8) {
        found = ctx->unk20;
    }
    return found;
}
#endif

#ifdef VERSION_US
// Steering context handed to func_867014C0 / func_86701874; they set done when the target slot is reached.
typedef struct { f32 x; f32 z; f32 tx; f32 spd; s32 slot; s32 done; } Ctx86701C6C;
// One 0x38-byte record of D_86728328 per player.
typedef struct {
    f32 unk00; f32 unk04; f32 unk08; u8 pad0C[4]; s32 unk10; u8 pad14[4];
    s32 unk18; s32 unk1C; s32 unk20; s32 unk24; u8 pad28[4]; s32 unk2C; s32 unk30; s32 unk34;
} Ent86728328;
#define ENT_86701C6C(i) (((Ent86728328 *)&D_86728328)[i])
extern f32 D_8670C894;

// Steers player idx left/right around rows ahead of it (unk18 = -1/1), then sets unk1C/unk24 toward tx.
// scale = 0 is assigned after the unk18 store so IDO schedules the -1 constant first, as in retail.
void func_867014C0(s32 idx, Ctx86701C6C *ctx) {
    f32 x = ctx->x;
    f32 tx = ctx->tx;
    f32 z = ctx->z;
    f32 spd = ctx->spd;
    s32 slot = ctx->slot;
    Row86706A30 *row;
    s32 left;
    s32 right;
    s32 i;
    s32 j;
    s32 type;
    s32 scale;
    f32 base;
    f32 target;
    f32 dist;

    if (x <= tx) {
        ENT_86701C6C(idx).unk18 = 1;
    }
    if (tx < x) {
        ENT_86701C6C(idx).unk18 = -1;
    }
    left = 0;
    right = 0;
    for (i = 1; i <= ENT_86701C6C(idx).unk10; i++) {
        j = slot + i;
        if (j >= 60) {
            j -= 60;
        }
        row = &D_86711760[idx][j];
        if (row->z < z + 80.0f) {
            if (row->x < tx) {
                left++;
            } else {
                right++;
            }
        }
    }
    if (right >= left) {
        ENT_86701C6C(idx).unk18 = -1;
    } else if (right < left) {
        ENT_86701C6C(idx).unk18 = 1;
    }
    if (tx + 100.0f <= x) {
        ENT_86701C6C(idx).unk18 = 1;
    }
    if (x < tx - 100.0f) {
        ENT_86701C6C(idx).unk18 = -1;
    }
    if (*(f32 *)((u8 *)&D_86728408[idx] + 0x1C) + D_8670C894 - 40.0f <= x + spd) {
        ENT_86701C6C(idx).unk18 = -1;
    }
    if (x - spd < *(f32 *)((u8 *)&D_86728408[idx] + 0x1C) + 40.0f) {
        ENT_86701C6C(idx).unk18 = 1;
    }
    scale = 1;
    if (10 == D_8670C984[idx][slot][0]) {
        if (tx < x) {
            ENT_86701C6C(idx).unk18 = 1;
        } else {
            ENT_86701C6C(idx).unk18 = -1;
        }
        scale = 0;
    }
    if (ENT_86701C6C(idx).unk18 == -1) {
        target = (-spd - ENT_86701C6C(idx).unk04) * (f32)scale + x;
        if (target < tx) {
            dist = -(target - tx);
        } else {
            dist = target - tx;
        }
        ENT_86701C6C(idx).unk1C = ENT_86701C6C(idx).unk08 * -dist;
    } else {
        target = (ENT_86701C6C(idx).unk04 + spd) * (f32)scale + x;
        if (tx < target) {
            dist = -(tx - target);
        } else {
            dist = tx - target;
        }
        ENT_86701C6C(idx).unk1C = ENT_86701C6C(idx).unk08 * dist;
    }
    ENT_86701C6C(idx).unk24 = ENT_86701C6C(idx).unk18;
    if (ENT_86701C6C(idx).unk18 == 1) {
        if (10 == D_8670C984[idx][slot][0]) {
            if (x + 10.0f < tx) {
                ctx->done = 1;
            } else if (ENT_86701C6C(idx).unk04 + (x + spd) < tx) {
                ctx->done = 1;
            }
        }
    } else if (10 == D_8670C984[idx][slot][0]) {
        if (tx < x - 10.0f) {
            ctx->done = 1;
        } else if (tx < (x - spd) - ENT_86701C6C(idx).unk04) {
            ctx->done = 1;
        }
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/55/fragment55_code/func_86701874.s")
#endif

#ifdef VERSION_US
extern Ctx86701C6C D_8670C838;
extern f32 D_8670BAE8[];
extern f32 D_8670B3CC;
extern f32 D_86710C08[];
extern s32 D_8670BAD8;
extern s32 D_8670BB48;
extern s32 func_8670122C(s32);
extern void func_867014C0(s32, Ctx86701C6C *);
extern void func_86701874(s32, Ctx86701C6C *);
extern s32 func_86700FD4(s32, s32);
// Picks the player's target slot (unk20) and steers toward it through D_8670C838.
// sCurCtx is retail's D_8670C850; as a function static IDO keeps it in a register and stores it back
// before each call.
void func_86701C6C(s32 idx) {
    static Ctx86701C6C *sCurCtx;
    s32 rnd;

    sCurCtx = &D_8670C838;
    sCurCtx->done = 0;
    if (D_8670BB48 != 1) {
        return;
    }
    if (D_86728408[idx].unk38 > 0 && ENT_86701C6C(idx).unk2C < 2) {
        ENT_86701C6C(idx).unk20 = func_8670122C(idx);
    }
    sCurCtx->slot = ENT_86701C6C(idx).unk20;
    if (sCurCtx->slot == 0x3E8 || D_8670C984[idx][sCurCtx->slot][0] < 0) {
        if (D_86728408[idx].unk38 == 0) {
            ENT_86701C6C(idx).unk20 = func_86700FD4(idx, 0);
            sCurCtx->slot = ENT_86701C6C(idx).unk20;
        }
    }
    if (sCurCtx->slot == 0x3E8 || D_8670C980[idx][sCurCtx->slot].unk04[0] < 0) {
        ENT_86701C6C(idx).unk1C = 0;
        return;
    }
    ENT_86701C6C(idx).unk1C = 0;
    sCurCtx->x = D_86711760[idx][sCurCtx->slot].x;
    sCurCtx->z = D_86711760[idx][sCurCtx->slot].z;
    sCurCtx->tx = D_86710C20[idx].x;
    if (sCurCtx->z < D_86710C20[idx].z + ENT_86701C6C(idx).unk00) {
        rnd = guRandom() % 100;
        if (rnd >= 51) {
            ENT_86701C6C(idx).unk34 = 1;
        } else {
            ENT_86701C6C(idx).unk34 = -1;
        }
        rnd = D_8670C980[idx][sCurCtx->slot].unk04[0];
        sCurCtx->spd = D_8670BAE8[rnd * 2] * D_8670C890;
        ENT_86701C6C(idx).unk18 = 0;
        if (ENT_86701C6C(idx).unk2C >= 2) {
            func_867014C0(idx, sCurCtx);
        } else {
            func_86701874(idx, sCurCtx);
        }
        if (sCurCtx->done == 1) {
            ENT_86701C6C(idx).unk20 = func_86700FD4(idx, 0);
            ENT_86701C6C(idx).unk18 = 0;
            ENT_86701C6C(idx).unk1C = 0;
        }
    } else {
        if (sCurCtx->tx < D_86710C08[idx] + D_8670B3CC + (f32)((3 - ENT_86701C6C(idx).unk2C) * 10)) {
            ENT_86701C6C(idx).unk34 = 1;
        }
        if (D_86710C08[idx + 1] - D_8670B3CC - (f32)((3 - ENT_86701C6C(idx).unk2C) * 10) < sCurCtx->tx) {
            ENT_86701C6C(idx).unk34 = -1;
        }
        ENT_86701C6C(idx).unk1C = ENT_86701C6C(idx).unk34 * (ENT_86701C6C(idx).unk2C + 1) * 10;
    }
    if (D_86711760[idx][ENT_86701C6C(idx).unk20].z < D_86710C20[idx].z) {
        ENT_86701C6C(idx).unk1C = 0;
        if (D_86728408[idx].unk38 == 0 || D_86710C20[idx].z < D_8670BAD8) {
            ENT_86701C6C(idx).unk20 = func_86700FD4(idx, 1);
        }
    }
}
#endif

#ifdef VERSION_US
extern s32 D_8670B3AC[];
extern s32 D_8670BDB4[];
void func_8670211C(void) {
    s32 i;
    s32 j;
    s32 count;
    s32 rnd;
    s32 unused[2]; // never referenced; the original frame reserves these 8 bytes

    for (i = 0; i < 5; i++) {
        count = 0;
        j = 0;
        rnd = guRandom() % 100;
        if (rnd > 50) {
            D_8670BDB4[i] = 1;
        } else {
            D_8670BDB4[i] = 0;
        }
        while (1) {
            switch (i) {
            case 0:
                D_8670B3AC[i] = guRandom() % 5;
                break;
            case 1:
                D_8670B3AC[i] = guRandom() % 15;
                break;
            case 2:
                D_8670B3AC[i] = guRandom() % 10 + 5;
                break;
            case 3:
                D_8670B3AC[i] = guRandom() % 15 + 5;
                break;
            case 4:
                D_8670B3AC[i] = guRandom() % 5 + 15;
                break;
            }
            for (j = 0; j < i; j++) {
                if (D_8670B3AC[i] == D_8670B3AC[j]) {
                    count++;
                }
            }
            if (count == 0) {
                break;
            }
            count = 0;
        }
    }
}
#endif

#ifdef VERSION_US

/* mkdraft:func_86702434 begin */
#ifndef M2C_FIELD /* mkdraft: m2c --valid-syntax helpers */
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
extern s32 D_8670BB48;

extern s32 D_8670B374;
extern M2C_UNK D_8670BDC8;
extern f64 D_8670C358;
extern f64 D_8670C360;
extern f64 D_8670C368;
extern f32 D_8670C370;
extern M2C_UNK D_86728328;


void func_86702434(void)
{
  f32 temp_ft1;
  f32 temp_ft3;
  f32 temp_ft3_2;
  f32 temp_ft4;
  f32 var_ft0;
  f32 var_ft1;
  f32 var_ft1_2;
  f32 var_ft1_3;
  f32 var_ft1_4;
  f32 var_ft2;
  f32 var_ft5;
  f32 var_ft5_2;
  f32 var_ft5_3;
  s32 *var_s4;
  s32 temp_v0;
  s32 temp_v0_2;
  s32 temp_v0_3;
  s32 temp_v0_4;
  s32 temp_v0_5;
  s32 var_s3;
  u32 temp_v0_6;
  u32 temp_v0_7;
  u32 temp_v0_8;
  u32 temp_v0_9;
  void *temp_s0;
  for (var_s3 = 0, var_s4 = &D_8670B374; var_s3 != 4; var_s3++, var_s4++)
  {
    if ((*var_s4) != 0)
    {
      temp_s0 = ((u8 *) (&D_86728328)) + (var_s3 * 0x38);
      *((s32 *) (((u8 *) (((u8 *) (&D_86728328)) + (var_s3 * 0x38))) + 0x30)) = (s32) (guRandom() % 4);
      *((s32 *) (((u8 *) (&D_8670BB48)) + 0x58)) += 1;
      if (*((s32 *) (((u8 *) (&D_8670BB48)) + 0x58)) >= 3)
      {
        *((s32 *) (((u8 *) (&D_8670BB48)) + 0x58)) = 0;
      }
      temp_v0_5 = func_8003570C();
      *((s32 *) (((u8 *) (((u8 *) (&D_86728328)) + (var_s3 * 0x38))) + 0x2C)) = 0;
      *((s32 *) (((u8 *) temp_s0) + 0x14)) = 1;
      if ((((s32) temp_v0_5) & 3) < 3)
      {
        *((s32 *) (((u8 *) temp_s0) + 0x14)) = 0;
      }
      temp_v0 = *var_s4;
      switch (temp_v0)
      {
        case 1:
          *((f32 *) (((u8 *) temp_s0) + 0)) = (f32) ((guRandom() % 50) + 0xFA);
          temp_ft3 = (f32) (0x19 - (guRandom() % 10));
          *((f32 *) (((u8 *) temp_s0) + 4)) = temp_ft3;
          *((s32 *) (((u8 *) temp_s0) + (0x10 & 0xFFFFFFFF))) = 4;
          *((f32 *) (((u8 *) temp_s0) + 8)) = (f32) (((f64) (((((f32) func_8003570C()) / 4294967296.0f) * 0.3f) * ((f32) (*((&D_8670BDC8) + (*((s32 *) (((u8 *) temp_s0) + 0x30)))))))) + 1.5);
          *((f32 *) (((u8 *) temp_s0) + 0xC)) = (f32) (((f64) (((((f32) func_8003570C()) / 4294967296.0f) * 0.5f) * ((f32) (*((&D_8670BDC8) + (*((s32 *) (((u8 *) temp_s0) + 0x30)))))))) + 4.0);

          break;

        case 2:
          *((f32 *) (((u8 *) temp_s0) + 0)) = (f32) ((guRandom() % 50) + 0xC8);
          temp_ft4 = (f32) (0x19 - (guRandom() % 10));
          *((f32 *) (((u8 *) temp_s0) + 4)) = temp_ft4;
          *((s32 *) (((u8 *) temp_s0) + 0x10)) = 3;
          *((f32 *) (((u8 *) temp_s0) + 8)) = (f32) (((f64) (((((f32) func_8003570C()) / 4294967296.0f) * 0.2f * ((f32) (*((&D_8670BDC8) + (*((s32 *) (((u8 *) temp_s0) + 0x30))))))))) + 1.3);
          *((f32 *) (((u8 *) temp_s0) + 0xC)) = (f32) (((f64) (((((f32) func_8003570C()) / 4294967296.0f) * 0.2f * ((f32) (*((&D_8670BDC8) + (*((s32 *) (((u8 *) temp_s0) + 0x30))))))))) + 3.5);
          break;

        case 3:
          *((f32 *) (((u8 *) temp_s0) + 0)) = (f32) (((guRandom() % 10) * 5) + 0x96);
          temp_ft3_2 = (f32) (0x1E - (guRandom() % 10));
          *((f32 *) (((u8 *) (((u8 *) (&D_86728328)) + (var_s3 * 0x38))) + 4)) = temp_ft3_2;
          *((s32 *) (((u8 *) temp_s0) + 0x10)) = 2;
          temp_v0_6 = func_8003570C();
          var_ft1_4 = (f32) ((u32) temp_v0_6);
          *((f32 *) (((u8 *) (((u8 *) (&D_86728328)) + (var_s3 * 0x38))) + 8)) = (f32) (((f64) (((f32) (*((&D_8670BDC8) + (*((s32 *) (((u8 *) (((u8 *) (&D_86728328)) + (var_s3 * 0x38))) + 0x30)))))) * ((var_ft1_4 / 4294967296.0f) * 0.15f))) + 1.15);
          temp_v0_7 = func_8003570C();
          var_ft2 = (f32) ((u32) temp_v0_7);
          *((f32 *) (((u8 *) (((u8 *) (&D_86728328)) + (var_s3 * 0x38))) + 0xC)) = (f32) (((f64) (((f32) (*((&D_8670BDC8) + (*((s32 *) (((u8 *) (((u8 *) (&D_86728328)) + (var_s3 * 0x38))) + 0x30)))))) * ((var_ft2 / 4294967296.0f) * 0.15f))) + 2.8);
          break;

        case 4:
          *((f32 *) (((u8 *) (((u8 *) (&D_86728328)) + (var_s3 * 0x38))) + 0)) = (f32) (((guRandom() % 10) * 5) + 0x78);
          temp_ft1 = (f32) (0x1E - (guRandom() % 10));
          *((f32 *) (((u8 *) (((u8 *) (&D_86728328)) + (var_s3 * 0x38))) + 4)) = temp_ft1;
          *((s32 *) (((u8 *) (((u8 *) (&D_86728328)) + (var_s3 * 0x38))) + 0x10)) = 1;
          temp_v0_8 = func_8003570C();
          var_ft5_3 = (f32) ((u32) temp_v0_8);
          *((f32 *) (((u8 *) (((u8 *) (&D_86728328)) + (var_s3 * 0x38))) + 8)) = (f32) (((f64) (((f32) (*((&D_8670BDC8) + (*((s32 *) (((u8 *) (((u8 *) (&D_86728328)) + (var_s3 * 0x38))) + 0x30)))))) * ((var_ft5_3 / 4294967296.0f) * 0.15f))) + 1.0);
          temp_v0_9 = func_8003570C();
          var_ft0 = (f32) ((u32) temp_v0_9);
          *((f32 *) (((u8 *) temp_s0) + 0xC)) = (f32) (((f64) (((f32) (*((&D_8670BDC8) + (*((s32 *) (((u8 *) temp_s0) + 0x30)))))) * ((var_ft0 / 4294967296.0f) * 0.15f))) + 2.2);

      }

      *((s32 *) (((u8 *) (((u8 *) (&D_86728328)) + (var_s3 * 0x38))) + 0x20)) = 0;
      if ((guRandom() % 100) >= 0x33)
      {
        *((s32 *) (((u8 *) (((u8 *) (&D_86728328)) + (var_s3 * 0x38))) + 0x34)) = 1;
      }
      else
      {
        *((s32 *) (((u8 *) (((u8 *) (&D_86728328)) + (var_s3 * 0x38))) + 0x34)) = -1;
      }
      *((s32 *) (((u8 *) (((u8 *) (&D_86728328)) + (var_s3 * 0x38))) + 0x1C)) = 0;
      *((s32 *) (((u8 *) (((u8 *) (&D_86728328)) + (var_s3 * 0x38))) + 0x24)) = 0;
      *((s32 *) (((u8 *) (((u8 *) (&D_86728328)) + (var_s3 * 0x38))) + 0x28)) = 0;
    }
  }
}
/* mkdraft:func_86702434 end */
#endif

#ifdef VERSION_US
extern f32 D_8670B3C4;
extern f32 D_8670B3C8;
extern f32 D_8670B3CC;
extern s32 D_8670B3D0;
extern s32 D_8670B38C;
extern s32 D_8670BB48;
extern f32 D_8670BB80;
extern f32 D_8670C890;
extern f32 D_8670C894;
extern f32 D_8670C89C;
extern f32 D_8670C8A0;
extern f32 D_8670BD9C;
extern f32 D_86710C4C;
extern Stage55Slot D_8670C980[4][60];
extern Row86706A30 D_867100C8[];
extern Row86706A30 D_86710C20[];
extern Row86706A30 D_86711760[4][60];
extern State86703DF4 D_86728408[];
extern u32 D_86727CE8[];
extern void func_8670211C(void);
extern void func_86702434(void);
extern void func_87F0CB58(void);
extern int guRandom(void);



void func_86702B28(void)
{
  u32 *fill;
  u32 *base;
  u32 *end;
  s32 neg;
  f32 scale;
  f32 value;
  s32 i;
  s32 j;
  func_8670211C();
  func_86702434();
  scale = D_8670B3C4;
  D_8670C890 = 6.0f * scale;
  D_8670C894 = D_8670C890 * 16.0f;
  D_8670B3C8 = 18.0f;
  D_8670C8A0 = D_8670B3C8 * 39.0f;
  D_8670C89C = (f32)D_86710C4C + 5.0f * D_8670B3C8;
  neg = -1;
  base = D_86727CE8;
  for (i = 0; i < 400; i++)
  {
    base[i] = neg;
  }
  value = D_8670BB80;
  for (i = 0; i < 4; i++)
  {
    *((f32 *) (((u8 *) (&D_86710C20[i])) + 0x2C)) = -280.0f;
    *((f32 *) (((u8 *) (&D_867100C8[i])) + 0x2C)) = -280.0f;
    *((f32 *) (((u8 *) (&D_86728408[i])) + 0x1C)) = ((((f32) i) * 120.0f) + (-240.0f)) * scale;
    *((s16 *) (((u8 *) (&D_86710C20[i])) + 0x20)) = 0;
    *((f32 *) (((u8 *) (&D_86710C20[i])) + 0x38)) = value;
    *((f32 *) (((u8 *) (&D_86710C20[i])) + 0x34)) = value;
    *((f32 *) (((u8 *) (&D_86710C20[i])) + 0x30)) = value;
    *((s32 *) (((u8 *) (&D_86728408[i])) + 0x00)) = 0;
    *((s32 *) (((u8 *) (&D_86728408[i])) + 0x08)) = 0;
    *((s32 *) (((u8 *) (&D_86728408[i])) + 0x04)) = 0;
    *((f32 *) (((u8 *) (&D_86728408[i])) + 0x10)) = 0.0f;
    *((s32 *) (((u8 *) (&D_86728408[i])) + 0x14)) = 0;
    *((s32 *) (((u8 *) (&D_86728408[i])) + 0x18)) = 0;
    *((s32 *) (((u8 *) (&D_86728408[i])) + 0x0C)) = D_8670B38C;
    *((s32 *) (((u8 *) (&D_86728408[i])) + 0x20)) = 0;
    *((s32 *) (((u8 *) (&D_86728408[i])) + 0x24)) = 1;
    *((f32 *) (((u8 *) (&D_86728408[i])) + 0x28)) = 2.0f;
    *((s32 *) (((u8 *) (&D_86728408[i])) + 0x2C)) = 0;
    *((s32 *) (((u8 *) (&D_86728408[i])) + 0x30)) = 0;
    *((s32 *) (((u8 *) (&D_86728408[i])) + 0x34)) = i + 1;
    *((s32 *) (((u8 *) (&D_86728408[i])) + 0x38)) = 0;
    *((s32 *) (((u8 *) (&D_86728408[i])) + 0x48)) = 0;
    *((s32 *) (((u8 *) (&D_86728408[i])) + 0x44)) = -1;
    *((s32 *) (((u8 *) (&D_86728408[i])) + 0x54)) = 0;
    *((f32 *) (((u8 *) (&D_86728408[i])) + 0x58)) = 0.0f;
    *((f32 *) (((u8 *) (&D_86728408[i])) + 0x5C)) = 0.0f;
    *((s32 *) (((u8 *) (&D_86728408[i])) + 0x60)) = 0;
    *((s32 *) (((u8 *) (&D_86728408[i])) + 0x64)) = 0;
    *((s32 *) (((u8 *) (&D_86728408[i])) + 0x68)) = 0;
    *((s32 *) (((u8 *) (&D_86728408[i])) + 0x7C)) = 0;
    *((s32 *) (((u8 *) (&D_86728408[i])) + 0x6C)) = 0;
    *((f32 *) (((u8 *) (&D_86728408[i])) + 0x70)) = 0.0f;
    *((s32 *) (((u8 *) (&D_86728408[i])) + 0x74)) = 0;
    *((f32 *) (((u8 *) (&D_86728408[i])) + 0x78)) = 0.0f;
    *((f32 *) (((u8 *) (&D_86728408[i])) + 0x84)) = 0.0f;
    *((f32 *) (((u8 *) (&D_86728408[i])) + 0x80)) = 1.0f;
    *((s32 *) (((u8 *) (&D_86728408[i])) + 0x88)) = 0;
    *((s32 *) (((u8 *) (&D_86728408[i])) + 0x8C)) = 0;
    *((s32 *) (((u8 *) (&D_86728408[i])) + 0x90)) = 0;
    *((s32 *) (((u8 *) (&D_86728408[i])) + 0x94)) = 0;
    *((s32 *) (((u8 *) (&D_86728408[i])) + 0x9C)) = 0;
    *((s32 *) (((u8 *) (&D_86728408[i])) + 0xA0)) = 0;
    *((s32 *) (((u8 *) (&D_86728408[i])) + 0xA8)) = 0;
    for (j = 0; j < 0x3C; j++)
    {
      D_8670C980[i][j].resource_index = -1;
      D_8670C980[i][j].unk04[0] = -1;
      *((s32 *) (((u8 *) (&D_86711760[i][j])) + 0x14)) = 0;
    }

  }

  D_8670B3CC = 85.0f * value;
  *((s32 *) (((u8 *) (&D_8670BB48)) + 0x10)) = 0;
  *((s32 *) (((u8 *) (&D_8670BB48)) + 0x30)) = 0;
  *((s32 *) (((u8 *) (&D_8670BB48)) + 0x34)) = 1;
  *((s32 *) (((u8 *) (&D_8670BB48)) + 0x3C)) = 0;
  *((s32 *) (((u8 *) (&D_8670BB48)) + 0x08)) = -1;
  *((s32 *) (((u8 *) (&D_8670BB48)) + 0x40)) = 0;
  *((s32 *) (((u8 *) (&D_8670BB48)) + 0x44)) = 0;
  D_8670B3C8 = D_8670B3C8;
  *((s32 *) (((u8 *) (&D_8670BB48)) + 0x48)) = 0;
  *((s32 *) (((u8 *) (&D_8670BB48)) + 0x4C)) = -1;
  *((s32 *) (((u8 *) (&D_8670BB48)) + 0x50)) = 0;
  *((s32 *) (((u8 *) (&D_8670BB48)) + 0x54)) = 0;
  *((s32 *) (((u8 *) (&D_8670BB48)) + 0x5C)) = 1;
  *((f32 *) (((u8 *) (&D_8670BB48)) + 0x38)) = 0.75f;
  *((s32 *) (((u8 *) (&D_8670BB48)) + 0x58)) = guRandom() % 4;
  *((s32 *) (((u8 *) (&D_8670BB48)) + 0x64)) = 0;
  if (D_8670B3D0 >= 2)
  {
    D_8670BD9C = 0.3f;
  }
  func_87F0CB58();
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/55/fragment55_code/func_86702E50.s")
#endif

#ifdef VERSION_US
extern f32 D_8670B3CC;
extern f32 D_8670B3C8;
extern s32 D_8670B3D0;
extern f32 D_8670C8A0;
extern f32 D_8670C89C;
extern f32 D_8670BD9C;
extern u8 D_800CE060[];
extern Row86706A30 D_86710C20[];
extern State86703DF4 D_86728408[];
extern s32 D_8670BB48;
void func_867035A8(void) {
    f32 scale;
    s32 i;

    scale = *(f32 *)((u8 *)&D_8670BB48 + 0x38); D_8670B3CC = 85.0f * scale; // FAKE: one source line
    D_8670C8A0 = D_8670B3C8 * 40.0f;
    D_8670C89C = D_86710C20[0].z + 8.0f * D_8670B3C8;
    for (i = 0; i < 4; i++) {
        *(f32 *)(D_800CE060 + i * 0x28 + 0x1C) = 0.0f;
        *(f32 *)((u8 *)&D_86710C20[i] + 0x38) = scale;
        *(f32 *)((u8 *)&D_86710C20[i] + 0x34) = scale;
        *(f32 *)((u8 *)&D_86710C20[i] + 0x30) = scale;
        if (*(s32 *)((u8 *)&D_86728408[i] + 0x98) == 0xCE) {
            *(f32 *)((u8 *)&D_86710C20[i] + 0x38) = *(f32 *)((u8 *)&D_8670BB48 + 0x60);
            *(f32 *)((u8 *)&D_86710C20[i] + 0x34) = *(f32 *)((u8 *)&D_8670BB48 + 0x60);
            *(f32 *)((u8 *)&D_86710C20[i] + 0x30) = *(f32 *)((u8 *)&D_8670BB48 + 0x60);
        }
    }
    if (D_8670B3D0 >= 2) {
        D_8670BD9C = 0.3f;
    }
}
#endif

#ifdef VERSION_US
extern Stage55Slot D_8670C980[4][60];
extern Row86706A30 D_86711760[4][60];
extern void func_8003F1DC(void *);




void func_867036B4(s32 arg0) {
    s32 i;
    Row86706A30 *row;

    for (i = 0, row = D_86711760[arg0]; i < 60; i++, row++) {
        if (row->z < -600.0f) {
            func_8003F1DC(row);
            D_8670C980[arg0][i].resource_index = -1;
            D_8670C980[arg0][i].unk04[0] = -1;
            row->z = 3000.0f;
            row->y = 90.0f;
        }
    }
}
#endif

#ifdef VERSION_US
s32 func_867037B8(s32 arg0, f32 arg1, f32 arg2) {
    extern struct Stage55FadeModel D_86710668[];
    extern f32 D_8670BAE8[], D_8670B350, D_8670B354;
    extern s32 D_8670B3D8;
    extern void func_80027A28(u16, u8);
    enum { TWO = 2 };

    s32 one = 1;
    f32 z;
    f32 *extent;
    s32 i;
    f32 x;

    if (D_86728408[arg0].unk68 > 0) {
        return 1;
    }
    if (D_86728408[arg0].unk2C != 10) {
        D_86728408[arg0].unk2C = 0;
    }
    D_86728408[arg0].unk7C = 0;
    D_8670C89C = D_86710C20[arg0].z + 8.0f * D_8670B3C8;
    for (i = 0; i != 60; i++) {
        register s32 contact = 0;
        if (D_8670C980[arg0][i].unk04[0] == -1) {
            continue;
        }
        if (D_8670C89C < D_86711760[arg0][i].z) {
            continue;
        }
        z = D_86710C20[arg0].z - arg2 * (f32)TWO;
        x = D_86710C20[arg0].x + arg1 * (f32)TWO;
        extent = ((f32 (*)[2])D_8670BAE8)[D_8670C980[arg0][i].unk04[0]];
        if (z < D_86711760[arg0][i].z + extent[1] * D_8670C890 &&
            D_86711760[arg0][i].z - extent[1] * D_8670C890 < z &&
            x < D_86711760[arg0][i].x + extent[0] * D_8670C890 &&
            D_86711760[arg0][i].x - extent[0] * D_8670C890 < x) {
            contact = 2;
        }
        if (contact != 2) {
            continue;
        }
        if (D_86728408[arg0].unk38 > 0) {
            if (D_8670C980[arg0][i].unk04[0] == 10) {
                D_86728408[arg0].unk84 = D_86728408[arg0].unk10 + (5.6 * D_8670B3C8) / 18.0;
                D_86710668[arg0].alpha = 255;
                D_86728408[arg0].unk94 = one;
                D_86728408[arg0].unk74 = one;
                D_86710668[arg0].scale_z *= 1.5;
                if (D_86728408[arg0].unk5C + D_8670BD9C < 0.75) {
                    D_86728408[arg0].unk9C += 1;
                    D_86728408[arg0].unk5C += D_8670B350;
                }
                if (D_86728408[arg0].unk5C + D_8670BD9C > 0.75) {
                    D_86728408[arg0].unk5C = 0.3f;
                } else {
                    D_86728408[arg0].unk58 += D_8670B354;
                }
            } else {
                switch (D_8670C980[arg0][i].unk04[0]) {
                case 11:
                    if ((u32)D_86711760[arg0][i].unk14 < 7 || (u32)D_86711760[arg0][i].unk14 >= 27) {
                        return 1;
                    }
                    if ((u32)D_86711760[arg0][i].unk14 >= 6 && (u32)D_86711760[arg0][i].unk14 < 13) {
                        func_80027A28(0x9F00, arg0);
                        D_86728408[arg0].unk68 = one;
                        break;
                    }
                case 1:
                case 2:
                    D_86728408[arg0].unk2C = 4;
                    D_86728408[arg0].unk38 = 0;
                    D_86728408[arg0].unk94 = -1;
                    D_86728408[arg0].unk5C = 0.0f;
                    D_86728408[arg0].unk58 = 0.0f;
                    break;
                case 3:
                case 4:
                case 5:
                    func_80027A28(0x9F00, arg0);
                    D_86728408[arg0].unk68 = one;
                    break;
                case 0:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                    break;
                }
            }
            if (D_8670C980[arg0][i].unk04[0] != 0) {
                D_8670C980[arg0][i].resource_index = -1;
                D_8670C980[arg0][i].unk04[0] = -1;
            } else {
                D_86728408[arg0].unk7C = one;
            }
            D_86710C20[arg0].y = 80.0f;
            return 1;
        }
        switch (D_8670C980[arg0][i].unk04[0]) {
        case 0:
            do {
                if (D_86728408[arg0].unk2C == 10) {
                    break;
                }
                D_86728408[arg0].unk2C = one;
            } while (0);
            break;
        case 1:
            D_86728408[arg0].unk2C = 3;
            break;
        case 11:
            if ((u32)D_86711760[arg0][i].unk14 < 7 || (u32)D_86711760[arg0][i].unk14 >= 27) {
                return 1;
            }
            if ((u32)D_86711760[arg0][i].unk14 >= 6 && (u32)D_86711760[arg0][i].unk14 < 13) {
                func_80027A28(0x9F00, arg0);
                D_86728408[arg0].unk68 = one;
                break;
            }
        case 2:
            D_86728408[arg0].unk2C = 4;
            break;
        case 3:
        case 4:
        case 5:
            D_86728408[arg0].unk2C = 2;
            break;
        case 10:
            D_86728408[arg0].unk64 = one;
            break;
        case 6:
        case 7:
        case 8:
            if (D_86710C20[arg0].z < D_86711760[arg0][i].z - extent[1] * D_8670C890) {
                D_86728408[arg0].unk4C = 0;
            } else {
                D_86728408[arg0].unk4C = one;
            }
            D_86728408[arg0].unk2C = 6;
            break;
        case 9:
            D_86728408[arg0].unk2C = 5;
            break;
        }
        if (one == D_86728408[arg0].unk2C) {
            return 1;
        }
        if (D_86728408[arg0].unk2C != 6) {
            if (D_8670B3D0 >= 2) {
                D_86728408[arg0].unk54 = 0;
                D_86728408[arg0].unk5C = 0.0f;
                D_86728408[arg0].unk58 = 0.0f;
            }
            if (one == D_8670B3D8) {
                D_86727CE8[D_8670C980[arg0][i].unk04[2]] = one;
            }
            if (D_8670C980[arg0][i].unk04[0] != 11) {
                D_8670C980[arg0][i].resource_index = -1;
                D_8670C980[arg0][i].unk04[0] = -1;
            }
            *(s32 *)(D_86728348 + arg0 * 56) = func_86700FD4(arg0, 1);
        }
        return -1;
    }
    return 1;
}
#endif

#ifdef VERSION_US
extern s16 MathUtil_Atan2s(f32, f32);
s16 func_86703D98(s8 arg0, s8 arg1) {
    if (arg1 > 0) {
        arg1 = 0;
    }
    return MathUtil_Atan2s(arg0, arg1) - 0xC000;
}
#endif

#ifdef VERSION_US
extern State86703DF4 D_86728408[];
extern s16 D_86710C40[][0xB4];
void func_86703DF4(s32 arg0) {
    s32 count;
    s32 limit;

    limit = 0;
    if (D_86728408[arg0].unk38 != 0) {
        D_86728408[arg0].unk48 = 1;
        limit = 0x20;
    }
    count = ++D_86728408[arg0].unk08;
    if (limit < count) {
        D_86728408[arg0].unk08 = 0;
        D_86728408[arg0].unk2C = 0;
        D_86728408[arg0].unk38 = 0;
        D_86728408[arg0].unk48 = 0;
        return;
    }
    D_86710C40[arg0][0] = count << 12;
}

void func_86703DF4_padding(void) {
}
#endif

#ifdef VERSION_US
extern Row86706A30 D_86710C20[];
extern void func_87F03884(void *, s32, void *, f32, f32, f32, s32, f32, s32);
extern u8 D_86727CB0[];
extern u32 func_8003570C(void);
void func_86703E9C(s32 arg0) {
    u32 rand2;
    s32 pad; // FAKE
    u32 rand1;
    u32 rand0;

    rand0 = func_8003570C();
    rand1 = func_8003570C();
    rand2 = func_8003570C();
    func_87F03884(D_86727CB0, 0, &D_86710C20[arg0], 10.0f, 90.0f, -20.0f, (rand0 % 31) * 0x200,
                  ((f32)rand1 / 4294967296.0f) * 1.5f * 5.0f, (rand2 % 3) + 2);
}
#endif

#ifdef VERSION_US
/* mkdraft:func_86703F9C begin */
extern s32 D_8670BB58;
extern s32 D_86727CD8[];
extern u32 func_8003570C(void);

void func_86703F9C(void) {
    s32 value;
    D_86727CD8[0] = D_8670BB58 / 1800;
    value = D_8670BB58 - D_86727CD8[0] * 1800;
    D_86727CD8[1] = value / 30;
    value -= D_86727CD8[1] * 30;
    D_86727CD8[2] = func_8003570C() % 3 + value * 100 / 30;
}
/* mkdraft:func_86703F9C end */
#endif

#ifdef VERSION_US
typedef struct { u8 unk00[0x10]; f32 score; u8 unk14[0x10]; s32 whole; f32 fraction; s32 mode; u8 unk30[0x58]; s32 sound14; s32 sound32; u8 unk90[0x1C]; } Stage55SoundState;
typedef struct { u8 unk00[0x48]; s32 frame; u8 unk4C[0x11C]; } Stage55SoundModel;
extern void func_80027A28(u16, u8);
void Stage55_UpdateModelSounds(s32 arg0) {
    Stage55SoundModel *model;
    model = (Stage55SoundModel *)&D_86710C20[arg0];
    if (((Stage55SoundState *)D_86728408)[arg0].mode == 0) {
        if ((model->frame >> 16) < 10) {
            ((Stage55SoundState *)D_86728408)[arg0].sound14 = 0;
            ((Stage55SoundState *)D_86728408)[arg0].sound32 = 0;
        }
        if ((model->frame >> 16) >= 14 && ((Stage55SoundState *)D_86728408)[arg0].sound14 == 0) {
            func_80027A28(0x9F03, arg0);
            ((Stage55SoundState *)D_86728408)[arg0].sound14 = 1;
        }
        if ((model->frame >> 16) >= 32 && ((Stage55SoundState *)D_86728408)[arg0].sound32 == 0) {
            func_80027A28(0x9F03, arg0);
            ((Stage55SoundState *)D_86728408)[arg0].sound32 = 1;
        }
    } else if (((Stage55SoundState *)D_86728408)[arg0].mode == 1) {
        if ((model->frame >> 16) < 10) {
            ((Stage55SoundState *)D_86728408)[arg0].sound14 = 0;
            ((Stage55SoundState *)D_86728408)[arg0].sound32 = 0;
        }
        if ((model->frame >> 16) >= 14 && ((Stage55SoundState *)D_86728408)[arg0].sound14 == 0) {
            func_80027A28(0x9F04, arg0);
            ((Stage55SoundState *)D_86728408)[arg0].sound14 = 1;
        }
        if ((model->frame >> 16) >= 32 && ((Stage55SoundState *)D_86728408)[arg0].sound32 == 0) {
            func_80027A28(0x9F04, arg0);
            ((Stage55SoundState *)D_86728408)[arg0].sound32 = 1;
        }
    }
}
#endif

#ifdef VERSION_US
typedef struct { u8 unk00[0x94]; s32 mode; u8 unk98[0x14]; } Stage55FadeState;
typedef struct Stage55FadeModel Stage55FadeModel;
extern Stage55FadeModel D_86710668[];
extern State86703DF4 D_86728408[];
extern void func_8003F1DC(void *);
void Stage55_UpdateModelFade(s32 arg0) {

    if (((Stage55FadeState *)D_86728408)[arg0].mode == 1) {
        D_86710668[arg0].alpha -= 10;
        if (D_86710668[arg0].alpha <= 70) {
            D_86710668[arg0].alpha = 70;
            D_86710668[arg0].scale_z = 0.55f;
            ((Stage55FadeState *)D_86728408)[arg0].mode = 0;
        }
    }

    if (((Stage55FadeState *)D_86728408)[arg0].mode == -1) {
        D_86710668[arg0].alpha -= 10;
        if (D_86710668[arg0].alpha <= 20) {
            D_86710668[arg0].alpha = 0;
            ((Stage55FadeState *)D_86728408)[arg0].mode = 0;
            func_8003F1DC(&D_86710668[arg0]);

        }
    }
    if (D_86710668[arg0].alpha > 200) {
        D_86710668[arg0].alpha = 200;
    }
    if (D_86710668[arg0].alpha < 5) {
        D_86710668[arg0].alpha = 0;
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/55/fragment55_code/func_867043AC.s")
#endif

#ifdef VERSION_US
extern f32 D_8670BE7C;
extern s16 D_8670BE80;
extern s16 D_8670BE84;
extern s16 D_8670BE88;
extern f32 D_8670C8A8;
extern f32 D_80087E50[];
extern f32 D_80088E50[];
extern void GeoCamera_SetPerspective(void *, f32, f32, f32);
extern void func_80038E14(void *, f32, f32, f32, f32, f32, f32, s32);



s32 func_8670675C(s32 arg0, s32 arg1) {
    s16 shift;
    f32 d;
    f32 t;
    f32 s;

    shift = 4;

    d = sqrtf(*(f32 *)((u8 *)&D_8670BB48 + 0x18) * *(f32 *)((u8 *)&D_8670BB48 + 0x18) + *(f32 *)((u8 *)&D_8670BB48 + 0x1C) * *(f32 *)((u8 *)&D_8670BB48 + 0x1C));
    // FAKE: this unused ternary is load-bearing. Without it the sqrt result stays an
    // expression temp in f14, as in retail; without it the result lands in f0 and the
    // register walk after the call shifts by one slot. It emits no code.
    s = d ? d : d;
    D_8670C8A8 = d; GeoCamera_SetPerspective(arg1, D_8670BE7C, 100.0f, 12800.0f);
    d = D_8670C8A8;
    t = d;
    t *= D_80088E50[(u16)D_8670BE84 >> shift];
    func_80038E14(arg1,
        D_80088E50[(u16)D_8670BE80 >> 4] * t + 1.0f,
        D_80087E50[(u16)D_8670BE84 >> shift] * d,
        D_80087E50[(u16)D_8670BE80 >> 4] * t,
        *(f32 *)((u8 *)&D_8670BB48 + 0x20),
        *(f32 *)((u8 *)&D_8670BB48 + 0x24),
        *(f32 *)((u8 *)&D_8670BB48 + 0x28),
        D_8670BE88);
    return 0;
}
#endif

#ifdef VERSION_US
extern void func_80037120(s32, s32, s32 *, s16 *, s16 *);
extern s32 D_80094908;
s32 GeoCallback_OrientToCamera(s32 arg0, void *arg1) {
    s16 pad;
    s32 x;
    s16 y;
    s16 z;

    if (arg0 == 2) {
        func_80037120(D_80094908 + 0xB4, D_80094908 + 0xA8, &x, &y, &z);
        *(s16 *)((u8 *)arg1 + 0x1C) = y + 0x2000;
        *(s16 *)((u8 *)arg1 + 0x1E) = z - 0x2000;
    }
    return 0;
}

void func_867068DC(void) {
}

void D_867068E4(void) {
}
#endif

#ifdef VERSION_US
typedef struct { s32 index; u8 unk04[0xA8]; } Stage55VariantIndex;
extern Stage55VariantIndex D_86728458[];
extern f32 D_8670C04C[];
extern f32 D_8670C05C;
extern f32 D_8670C060[];
extern u8 D_8670D948[];
extern u8 D_8670D920[];
extern void *D_8670FF54;
extern void *func_87F025B8(void *, void *);
extern void func_87F0DB3C(u8 *, s32, void *);
extern void func_8003F114(u8 *, s16, s16, void *);
void Stage55_SpawnVariantEffect(s32 arg0) {
    u8 *entry;
    f32 *z;
    s32 side;
    f32 size;
    side = 0;
    if (arg0 % 2 == 1) {
        side = 1;
    }
    entry = func_87F025B8(D_8670D948, D_867068E4);
    if (entry != NULL) {
        size = 4.2f;
        *(f32 *)(entry + 0x48) = D_8670C04C[(arg0 / 2)];
        z = &D_8670C060[side];
        *(f32 *)(entry + 0x4C) = D_8670C05C;
        *(f32 *)(entry + 0x50) = *z;
        *(s16 *)(entry + 0x42) = -0x4000;
        *(f32 *)(entry + 0x54) = size;
        *(f32 *)(entry + 0x58) = size;
        *(f32 *)(entry + 0x5C) = size;
        *(s32 *)(entry + 0x38) = D_86728458[(arg0 / 2)].index;
        func_8003F114(entry + 0x24, 0, -1, D_8670FF54);
        if (z == D_8670C060) {
            func_87F0DB3C(D_8670D920, (arg0 / 2), entry + 0x24);
        }
    }
}
#endif

#ifdef VERSION_US
typedef struct { u8 pad38[0x38]; s32 index; u8 pad3C[0x0C]; f32 out48; f32 out4C; f32 out50; f32 in54; f32 out58; } State86706A30;
extern State86706A30 *D_87F119DC;
extern f32 D_8670C974;
extern Row86706A30 D_86710C20[];
void func_86706A30(void) { f32 temp_fv0; temp_fv0 = D_87F119DC->in54; D_87F119DC->out58 = temp_fv0; D_8670C974 = temp_fv0; D_87F119DC->out48 = D_86710C20[D_87F119DC->index].x; D_87F119DC->out4C = D_86710C20[D_87F119DC->index].y + 120.0f; D_87F119DC->out50 = D_86710C20[D_87F119DC->index].z - 50.0f; }
#endif

#ifdef VERSION_US
extern u8 D_8670F868[];
extern s32 D_8670FF4C;
void func_86706AC8(s32 arg0) {
    u8 *entry;

    entry = func_87F025B8(D_8670F868, func_86706A30);
    if (entry != NULL) {
        *(f32 *)(entry + 0x48) = *(f32 *)((u8 *)&D_86710C20[arg0] + 0x24);
        *(f32 *)(entry + 0x4C) = *(f32 *)((u8 *)&D_86710C20[arg0] + 0x28);
        *(f32 *)(entry + 0x50) = *(f32 *)((u8 *)&D_86710C20[arg0] + 0x2C) - 5000.0f;
        *(s16 *)(entry + 0x42) = -0x4000;
        *(s32 *)(entry + 0x38) = arg0;
        *(f32 *)(entry + 0x54) = 7.0f;
        *(f32 *)(entry + 0x58) = 7.0f;
        *(f32 *)(entry + 0x5C) = 7.0f;
        func_8003F114(entry + 0x24, 0, -1, D_8670FF4C);
    }
}
#endif

#ifdef VERSION_US
/* mkdraft:func_86706B88 begin */
extern State86706A30 *D_87F119DC;
extern State86703DF4 D_86728408[];
extern Row86706A30 D_86710C20[];
extern s32 D_8670BD38[];
extern f32 D_8670B3C4;
extern f32 D_8670C068;
extern s32 D_8670C06C;



void func_86706B88(void) {
    f32 *camera_depth = &D_8670C068;
    State86703DF4 *from_variant;
    State86703DF4 *to_variant;
    f32 variant_z;
    f32 spawn_z;
    s32 target_variant;
    s32 index;
    s32 tier;

    // FAKE: empty body. The comparison's mention of D_87F119DC is load-bearing: uopt
    // colors the pointer web at the end of its walk with the guard present (v0, matching
    // retail) and one slot later without it (v1, diff 60). It emits no instructions.
    if (D_87F119DC == NULL) {
    }
    index = D_87F119DC->index;
    if ((u32) index < 3U) {
        tier = 0;
    } else if ((u32) index < 6U) {
        tier = 1;
    } else if ((u32) index < 9U) {
        tier = 2;
    } else {
        tier = 3;
    }
    target_variant = D_8670BD38[index];
    D_87F119DC->pad3C[5] = 0x8C;
    from_variant = &D_86728408[target_variant];
    D_87F119DC->out48 = *(f32 *)((u8 *)from_variant + 0x78) + ((-180.0f + (120 * (f32)tier)) * D_8670B3C4);
    D_87F119DC->out4C = 120.0f;
    *(s16 *)((u8 *)D_87F119DC + 0x42) = (s16)(D_8670C06C << 8);
    variant_z = D_86710C20[tier].z;
    to_variant = &D_86728408[tier];
    D_87F119DC->out50 = (variant_z + (D_86710C20[target_variant].z - variant_z)) - ((((f32)(*(s32 *)((u8 *)to_variant + 0x24) << 5) + *(f32 *)((u8 *)to_variant + 0x28)) - (*(f32 *)((u8 *)from_variant + 0x28) + (f32)(*(s32 *)((u8 *)from_variant + 0x24) << 5))) / *camera_depth);
    spawn_z = D_87F119DC->out50;
    if ((spawn_z > 600.0f) || (spawn_z < -600.0f)) {
        D_87F119DC->out50 = -5000.0f;
    }
}
/* mkdraft:func_86706B88 end */
#endif

#ifdef VERSION_US
extern void func_86706B88();
extern u8 D_8670E5C0[];
extern s32 D_8670FF50;
void func_86706D3C(s32 arg0) {
    u8 *entry;
    s32 tier;
    f32 size;

    if (arg0 < 3) {
        tier = 0;
    } else if (arg0 < 6) {
        tier = 1;
    } else if (arg0 < 9) {
        tier = 2;
    } else {
        tier = 3;
    }
    entry = (u8 *)func_87F025B8(D_8670E5C0, func_86706B88);
    if (entry != NULL) {
        size = 3.2f;
        *(f32 *)(entry + 0x50) = D_86710C20[tier].z - 5000.0f;
        *(s16 *)(entry + 0x42) = 0;
        *(f32 *)(entry + 0x54) = size;
        *(f32 *)(entry + 0x58) = size;
        *(f32 *)(entry + 0x5C) = size;
        *(s32 *)(entry + 0x38) = arg0;
        func_8003F114(entry + 0x24, 0, -1, D_8670FF50);
        entry[0x41] = 0x8C;
    }
}
#endif

#ifdef VERSION_US
typedef union S1_arg1_func_80010CA8 { struct { s16 unk_00; s8 unk_02; s8 unk_03; }; u32 raw; } ColorAdjustment;
extern void *D_8670FEB0;
extern u8 D_8670FEB8[];
extern void func_87F0C650(void *);
extern void func_87F0C694(void *, s32);
extern s32 func_8004DDF4(s32);
extern s32 main_pool_get_available(void);
extern s32 MainPool_AllocState(s32, s32);
extern s32 WidgetTree_RunMessagePanelSilent(s32, s32);
extern void MainPool_FinalizeAllocation(s32);
extern s32 func_80040E80(s32, void *);
extern ColorAdjustment func_87F0AD50(s32, s32, s32);
extern s32 func_8004DFEC(s32, s32, ColorAdjustment);
extern void ModelRenderer_InitDisplayRoots(void);
extern void func_87F024CC(void);
extern void func_87F01870(void *);
extern void func_87F09EBC(void *, void *);
extern void func_80041E2C(void);
extern void func_80037E9C(s32, void *);
extern void func_87F03BB0(void *, s32);
extern void func_87F03700(void *, s32);
extern s32 func_87F08E3C(s32, s32);
extern void func_87F0252C(void *, void *, void *, s32);
extern void func_87F0D48C(void *, void *, void *);
extern void func_8003F03C(void *, void *);
extern void func_8003F3BC(void *, s32);
extern void func_8003EF60(void *);
extern void func_80037E3C(void *, void *, s32);
extern void func_86702B28(void);
extern void func_867043AC(void);
extern void func_86706AC8(s32);
extern void func_86706D3C(s32);
extern void Stage55_SpawnVariantEffect(s32);
extern void func_87F06430(void *, s32);
extern void func_8003F114(u8 *, s16, s16, void *);
extern s32 func_8003F210(void *, s32);
extern void ModelAnim_SetEventFrame(u8 *, s16);
extern void ModelAnim_SetFrame(u8 *, s16);
extern u32 func_8003570C(void);
extern int guRandom(void);

extern u8 D_8670BE8C[];
extern u8 D_8670B7A8[];
extern u8 D_8670B70C[];
extern u8 D_8670B7DC[];
extern u8 D_8670B740[];
extern u8 D_8670B774[];
extern u8 D_8670B5E8[];
extern u8 D_8670B970[];
extern u8 D_8670B9A4[];
extern u8 D_8670B9D8[];
extern u8 D_8670BA0C[];
extern void *D_8670FEC4;
extern s32 D_8670FED8;
extern s32 D_8670FF08[12];
extern s32 D_8670FEDC;
extern s32 D_8670FEE0;
extern s32 D_8670FEE4;
extern s32 D_8670FEE8;
extern s32 D_8670FEEC;
extern s32 D_8670FEF0;
extern s32 D_8670FEF4;
extern s32 D_8670FEF8;
extern s32 D_8670FEFC;
extern s32 D_8670FF58;
extern void *D_8670FF54;
extern s32 D_8670FF4C;
extern s32 D_8670FF50;
extern s32 D_8670FF00;
extern s32 D_8670FF38[];
extern s32 D_8670FEC8[];
extern u8 D_86728358[];
extern s32 D_8670BB74;
extern s32 D_8670BB48;
extern State86703DF4 D_86728408[];
extern u8 D_8670D8B8[];
extern u8 D_8670C7C0[];
extern u8 D_8670C7F0[];
extern u8 D_8670C808[];
extern u8 D_8670C7A8[];
extern u8 D_8670C7D8[];
extern u8 D_8670C820[];
extern u8 D_8670C790[];
extern u8 D_8670C778[];
extern u8 D_8670C760[];
extern u8 D_8670C6D0[];
extern u8 D_8670C6E8[];
extern u8 D_8670C700[];
extern u8 D_8670C718[];
extern u8 D_8670C730[];
extern u8 D_8670C748[];
extern u8 D_86727C90[];
extern u8 D_86727CB0[];
extern void *D_8670C978;
extern void *D_8670C95C;
extern void *D_8670C964;
extern u8 D_8670D948[];
extern u8 D_8670D960[];
extern u8 D_8670D920[];
extern u8 D_8670F868[];
extern u8 D_8670F880[];
extern u8 D_8670E5C0[];
extern u8 D_8670E5D8[];
extern f32 D_8670C504;
extern f32 D_8670C508;
extern f32 D_8670C50C;
extern f32 D_8670B3C4;
extern f32 D_86710C08[];
extern Row86706A30 D_86711760[4][60];
extern Row86706A30 D_86710C20[];
extern Row86706A30 D_867111C0[];
extern Row86706A30 D_867111E4[];
extern Row86706A30 D_867100C8[];
extern Row86706A30 D_867276F0[];
extern Stage55FadeModel D_86710668[];
typedef struct { u8 pad00[0x30]; f32 sx; f32 sy; f32 sz; u8 tail[0x12C]; } Model86726A48;
extern Model86726A48 D_86726A48;
extern Model86726A48 D_86726BB0;
extern Model86726A48 D_86726D18;
extern Model86726A48 D_86726E80;
extern Model86726A48 D_86726FE8;
extern Model86726A48 D_86727150;
extern Model86726A48 D_86727420;
extern Model86726A48 D_86727588;
extern Model86726A48 D_867272B8;
extern Model86726A48 D_867268E0;
extern u8 D_87F15B70[];
extern s32 D_8670C070[];
extern s32 D_8670C084[];

#define F32AT(base, off) (*(f32 *)((u8 *)(base) + (off)))

M2C_UNK func_86706E34() {
    s32 pool;
    s32 i;
    s32 n;
    f32 w;
    s32 j;
    ColorAdjustment tint;

    if (*(u8 *)((u8 *)D_8670FEB0 + 0x2180) == 4) {
        func_87F0C650(D_8670FEB8);
        func_87F0C694(D_8670FEB8, 0x14);
    }
    func_8004DDF4(0x3C);
    func_8004DDF4(0xBC);
    func_8004DDF4(0xCA);
    func_8004DDF4(0x84);
    func_8004DDF4(0x86);
    func_8004DDF4(0x85);
    func_8004DDF4(0x87);
    func_8004DDF4(0x88);
    func_8004DDF4(0x89);
    func_8004DDF4(0x8A);
    func_8004DDF4(0x8B);
    func_8004DDF4(0x8C);
    func_8004DDF4(0x3E);
    func_8004DDF4(0x44);
    func_8004DDF4(0x45);
    func_8004DDF4(0x46);
    func_8004DDF4(0x3F);
    func_8004DDF4(0x40);
    func_8004DDF4(0x41);
    func_8004DDF4(0x42);
    func_8004DDF4(0x43);
    pool = MainPool_AllocState(main_pool_get_available(), 0);
    D_8670FEC4 = (void *)func_80040E80(pool, D_8670BE8C);
    D_8670FED8 = WidgetTree_RunMessagePanelSilent(pool, 0x3C);
    D_8670FF08[0] = WidgetTree_RunMessagePanelSilent(pool, 0x3E);
    D_8670FF08[1] = WidgetTree_RunMessagePanelSilent(pool, 0x3F);
    D_8670FF08[2] = WidgetTree_RunMessagePanelSilent(pool, 0x40);
    D_8670FF08[3] = WidgetTree_RunMessagePanelSilent(pool, 0x41);
    D_8670FF08[4] = WidgetTree_RunMessagePanelSilent(pool, 0x42);
    D_8670FF08[5] = WidgetTree_RunMessagePanelSilent(pool, 0x43);
    D_8670FF08[6] = WidgetTree_RunMessagePanelSilent(pool, 0x44);
    D_8670FF08[7] = WidgetTree_RunMessagePanelSilent(pool, 0x45);
    D_8670FF08[8] = WidgetTree_RunMessagePanelSilent(pool, 0x46);
    D_8670FF08[9] = func_80040E80(pool, D_8670B7A8);
    D_8670FF08[10] = WidgetTree_RunMessagePanelSilent(pool, 0xCA);
    D_8670FF08[11] = func_80040E80(pool, D_8670B70C);
    D_8670FEDC = WidgetTree_RunMessagePanelSilent(pool, 0x84);
    D_8670FEE4 = WidgetTree_RunMessagePanelSilent(pool, 0x86);
    D_8670FEE0 = WidgetTree_RunMessagePanelSilent(pool, 0x85);
    D_8670FEE8 = WidgetTree_RunMessagePanelSilent(pool, 0x87);
    D_8670FEEC = WidgetTree_RunMessagePanelSilent(pool, 0x88);
    D_8670FEF0 = WidgetTree_RunMessagePanelSilent(pool, 0x89);
    D_8670FEF4 = WidgetTree_RunMessagePanelSilent(pool, 0x8A);
    D_8670FEF8 = WidgetTree_RunMessagePanelSilent(pool, 0x8B);
    D_8670FEFC = WidgetTree_RunMessagePanelSilent(pool, 0x8C);
    D_8670FF58 = WidgetTree_RunMessagePanelSilent(pool, 0xBC);
    D_8670FF54 = (void *)func_80040E80(pool, D_8670B7DC);
    D_8670FF4C = func_80040E80(pool, D_8670B740);
    D_8670FF50 = func_80040E80(pool, D_8670B774);
    D_8670FF00 = func_80040E80(pool, D_8670B5E8);
    for (i = 0; i < 4; i++) {
        switch (i) {
        case 0:
            D_8670FF38[i] = func_80040E80(pool, D_8670B970);
            break;
        case 1:
            D_8670FF38[i] = func_80040E80(pool, D_8670B9A4);
            break;
        case 2:
            D_8670FF38[i] = func_80040E80(pool, D_8670B9D8);
            break;
        case 3:
            D_8670FF38[i] = func_80040E80(pool, D_8670BA0C);
            break;
        }
        if (*(u8 *)((u8 *)D_8670FEB0 + 0x2182) & (1 << i)) {
            (&D_8670B374)[i] = 0; *(s32 *)((u8 *)&D_86728408[i] + 0x50) = i + 5;
            *(s32 *)(D_86728358 + i * 0x38) = -1;
        } else {
            (&D_8670B374)[i] = 4 - *(s8 *)((u8 *)D_8670FEB0 + 0x2181);
            *(s32 *)((u8 *)&D_86728408[i] + 0x50) = i + 1;
        }
        if (*(u8 *)((u8 *)D_8670FEB0 + 0x2180) == 4) {
            (&D_8670B374)[i] = 4 - *(s8 *)((u8 *)D_8670FEB0 + 0x2181);
        }
    }
    D_8670BB74 = 0x10 - *(u8 *)((u8 *)D_8670FEB0 + 0x2182);
    MainPool_FinalizeAllocation(pool);
    for (i = 0; i < 4; i++) {
        *(s32 *)((u8 *)&D_86728408[i] + 0x98) = *(u8 *)(*(u8 **)((u8 *)D_8670FEB0 + i * 0x6C0 + 0x20) + 4);
        if (*(s32 *)((u8 *)&D_86728408[i] + 0x98) == 0xAF) {
            *(s32 *)((u8 *)&D_86728408[i] + 0x98) = 0x6D;
        } else {
            *(s32 *)((u8 *)&D_86728408[i] + 0x98) = 0xCE;
        }
        func_8004DDF4(*(s32 *)((u8 *)&D_86728408[i] + 0x98));
        pool = MainPool_AllocState(main_pool_get_available(), 0);
        tint = func_87F0AD50((s32)D_8670FEB0, 8, i);
        D_8670FEC8[i] = func_8004DFEC(pool, *(s32 *)((u8 *)&D_86728408[i] + 0x98), tint);
        MainPool_FinalizeAllocation(pool);
    }
    ModelRenderer_InitDisplayRoots();
    func_87F024CC();
    func_87F01870(D_8670FEB0);
    func_87F09EBC(D_8670D8B8, D_8670FEB0);
    func_80041E2C();
    n = 4;
    func_80037E9C(0, D_8670C7C0);
    func_80037E9C(0, D_8670C7F0);
    func_80037E9C(0, D_8670C808);
    func_80037E9C(0, D_8670C7A8);
    func_80037E9C(0, D_8670C7D8);
    func_80037E9C(0, D_8670C820);
    func_80037E9C(0, D_8670C790);
    func_80037E9C(0, D_8670C778);
    func_80037E9C(0, D_8670C760);
    func_80037E9C(0, D_8670C6D0);
    func_80037E9C(0, D_8670C6E8);
    func_80037E9C(0, D_8670C700);
    func_80037E9C(0, D_8670C718);
    func_80037E9C(0, D_8670C730);
    func_80037E9C(0, D_8670C748);
    func_87F03BB0(D_86727C90, 0x32);
    func_87F03700(D_86727CB0, 0x28);
    D_8670C978 = (void *)func_87F08E3C(func_8004C990(0x1B2, 0), 0x0F000000);
    D_8670C95C = (void *)func_87F08E3C(func_8004C990(0x183, 0), 0x0F000000);
    D_8670C964 = (void *)func_87F08E3C(func_8004C990(0x1B2, 0), 0x0F000000);
    func_87F0252C(D_8670C7D8, D_8670D948, D_8670D960, 8);
    func_87F0D48C(D_8670D920, D_8670FEB0, D_8670C7D8);
    for (i = 0; i < 8; i++) {
        Stage55_SpawnVariantEffect(i);
    }
    func_87F0252C(D_8670C820, D_8670F868, D_8670F880, 4);
    for (i = 0; i < 4; i++) {
        func_86706AC8(i);
    }
    func_87F0252C(D_8670C7A8, D_8670E5C0, D_8670E5D8, 0xC);
    for (i = 0; i < 12; i++) {
        func_86706D3C(i);
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 60; j++) {
            func_8003F03C(&D_86711760[i][j], D_8670C790);
            F32AT(&D_86711760[i][j], 0x24) = F32AT(&D_86728408[i], 0x1C);
            F32AT(&D_86711760[i][j], 0x2C) = 3000.0f;
            F32AT(&D_86711760[i][j], 0x28) = 90.0f;
            F32AT(&D_86711760[i][j], 0x30) = 0.5f;
            F32AT(&D_86711760[i][j], 0x38) = 0.5f;
            F32AT(&D_86711760[i][j], 0x34) = 0.5f;
        }
    }
    func_8003F03C(&D_86726A48, D_8670C6D0);
    func_8003F03C(&D_86726BB0, D_8670C6E8);
    func_8003F03C(&D_86726D18, D_8670C700);
    func_8003F03C(&D_86726E80, D_8670C718);
    func_8003F03C(&D_86726FE8, D_8670C730);
    func_8003F03C(&D_86727150, D_8670C748);
    func_8003F03C(&D_86727420, D_8670C760);
    func_8003F03C(&D_86727588, D_8670C760);
    func_8003F03C(&D_867272B8, D_8670C760);
    D_86726A48.sx = D_86726BB0.sx = D_86726D18.sx = D_86726E80.sx =
        D_86726FE8.sx = D_86727150.sx = D_867272B8.sx = D_86727420.sx =
        D_86727588.sx = 0.8f;
    D_86726A48.sy = D_86726BB0.sy = D_86726D18.sy = D_86726E80.sy =
        D_86726FE8.sy = D_86727150.sy = D_867272B8.sy = D_86727420.sy =
        D_86727588.sy = 0.8f;
    D_86726A48.sz = D_86726BB0.sz = D_86726D18.sz = D_86726E80.sz =
        D_86726FE8.sz = D_86727150.sz = D_867272B8.sz = D_86727420.sz =
        D_86727588.sz = 0.8f;
    func_8003F114(&D_86727420, 0, -1, (void *)D_8670FEF8);
    func_8003F114(&D_86727588, 0, -1, (void *)D_8670FEFC);
    func_8003F03C(&D_867268E0, D_8670C7C0);
    D_867268E0.sx = 0.8f;
    D_867268E0.sy = 0.8f;
    D_867268E0.sz = 0.8f;
    F32AT(&D_867268E0, 0x2C) = 0.0f;
    F32AT(&D_867268E0, 0x28) = 0.0f;
    F32AT(&D_867268E0, 0x24) = 0.0f;
    func_8003F114(&D_867268E0, 0, -1, (void *)D_8670FED8);
    func_8003F3BC(&D_867268E0, 0);
    func_8003EF60(&D_867268E0);
    for (i = 0; i < n + 1; i++) {
        D_86710C08[i] = ((f32)i * 120.0f + -240.0f) * D_8670B3C4;
    }
    for (i = 0; i != n; i++) {
        func_8003F03C(&D_867111C0[i], D_87F15B70);
        func_8003F114((u8 *)&D_867111C0[i], 0, -1, (void *)D_8670FEC8[i]);
        func_87F06430(&D_867111E4[i], i);
        F32AT(&D_867111C0[i], 0x38) = 0.3f;
        F32AT(&D_867111C0[i], 0x34) = 0.3f;
        F32AT(&D_867111C0[i], 0x30) = 0.3f;
        F32AT(&D_867111C0[i], 0x28) = 60.0f;
        *(s32 *)((u8 *)&D_86728408[i] + 0x40) = func_8003570C() % 0x2EF;
        *(s32 *)((u8 *)&D_86728408[i] + 0x2C) = 0;
        *(s32 *)((u8 *)&D_86728408[i] + 0x3C) = (s32)(2000.0f / (f32)D_8670C070[i]);
        func_8003F210(&D_867111C0[i], 0);
        ModelAnim_SetFrame((u8 *)&D_867111C0[i], guRandom() % 25);
        ModelAnim_SetEventFrame((u8 *)&D_867111C0[i], 0);
        func_8003F03C(&D_86710C20[i], D_8670C7F0);
        func_8003F03C(&D_86710668[i], D_8670C808);
        func_8003F03C(&D_867100C8[i], D_8670C7F0);
        func_8003F03C(&D_867276F0[i], D_8670C778);
        F32AT(&D_86710C20[i], 0x2C) = -280.0f;
        F32AT(&D_86710C20[i], 0x24) = ((f32)i * 120.0f + -180.0f) * D_8670B3C4;
        F32AT(&D_86710C20[i], 0x34) = F32AT(&D_8670BB48, 0x38);
        if (i == 0) {} // FAKE
        F32AT(&D_86710C20[i], 0x38) = F32AT(&D_8670BB48, 0x38);
        F32AT(&D_86710C20[i], 0x30) = F32AT(&D_8670BB48, 0x38);
        F32AT(&D_86710C20[i], 0x28) = 80.0f;
        if (*(s32 *)((u8 *)&D_86728408[i] + 0x98) == 0xCE) {
            F32AT(&D_86710C20[i], 0x38) = F32AT(&D_8670BB48, 0x60);
            F32AT(&D_86710C20[i], 0x34) = F32AT(&D_8670BB48, 0x60);
            F32AT(&D_86710C20[i], 0x30) = F32AT(&D_8670BB48, 0x60);
        }
        w = F32AT(&D_86710C20[i], 0x24);
        F32AT(&D_86710668[i], 0x2C) = -280.0f;
        F32AT(&D_86710668[i], 0x38) = 10.0f;
        F32AT(&D_86710668[i], 0x34) = 10.0f;
        F32AT(&D_86710668[i], 0x28) = F32AT(&D_86710C20[i], 0x28) + 40.0f;
        F32AT(&D_86710668[i], 0x30) = 10.0f;
        F32AT(&D_867100C8[i], 0x2C) = -280.0f;
        F32AT(&D_867100C8[i], 0x28) = F32AT(&D_86710C20[i], 0x28) + 10.0f;
        F32AT(&D_867276F0[i], 0x2C) = 0.0f;
        F32AT(&D_867276F0[i], 0x28) = 0.0f;
        F32AT(&D_867100C8[i], 0x38) = 1.5f;
        if (i == 0) {} // FAKE
        F32AT(&D_867100C8[i], 0x34) = 1.5f;
        F32AT(&D_867100C8[i], 0x30) = 1.5f;
        F32AT(&D_86710668[i], 0x24) = w;
        F32AT(&D_867100C8[i], 0x24) = w;
        F32AT(&D_867276F0[i], 0x24) = w + (f32)D_8670C084[i];
        F32AT(&D_867276F0[i], 0x30) = 0.8f;
        F32AT(&D_867276F0[i], 0x34) = 0.8f;
        F32AT(&D_867276F0[i], 0x38) = 0.8f;
        func_8003F114((u8 *)&D_867276F0[i], 0, -1, (void *)D_8670FF38[i]);
        func_80037E3C(&D_86710C20[i], func_867043AC, i);
    }
    func_86702B28();
}

#undef F32AT
#endif

#ifdef VERSION_US
extern void Font_DisableTwoCycleTexturing(void);
extern void Font_EnableTwoCycleTexturing(void);
extern void func_800495F8(s32 x, s32 y, s32 mode, const char *format, ...);
extern void func_800496A4(s32 a0, s32 a1);
extern void func_8004972C(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_800497E4(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_800498C4(void);
extern void func_800499EC(void);
extern void func_87F09040(void);
extern void func_867035A8(void);
extern s32 D_8670BDB4[];
extern s32 D_8670B3AC[];
extern f32 D_8670B3C8;
extern f32 D_8670BD9C;
extern s32 D_8670C098;
extern s32 D_8670BB4C;
extern s32 D_8670B3C0;
extern s32 D_8670B3B0;
extern s32 D_8670B3B4;
extern s32 D_8670B3B8;
extern s32 D_8670B3BC;
extern s32 D_8670B398;
extern s32 D_8670B39C;
extern s32 D_8670B3A0;
extern s32 D_8670B3A4;
extern s32 D_8670B3A8;
extern s32 D_8670BDB8;
extern s32 D_8670BDBC;
extern s32 D_8670BDC0;
extern s32 D_8670BDC4;
extern s32 D_8670B368;
extern s32 D_8670B388;
extern s32 D_8670B3D8;
extern s32 D_8670B3DC;
extern f32 D_86710C50;
extern f32 D_8670BD98;

void func_86707E2C(void) {
    func_87F09040();
    func_800498C4();
    func_800496A4(1, 0);
    Font_EnableTwoCycleTexturing();
    func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
    func_800497E4(0xFF, 0xFF, 0xFF, 0xFF);
    D_8670C098 += 1;
    if (D_8670C098 >= 21) {
        D_8670C098 = 0;
    }
    func_800495F8(90, 40, 0, "マップ:");
    if ((D_8670C098 >= 10) || (D_8670BB4C != 11)) {
        if (D_8670B3C0 == 0) {
            func_800495F8(230, 40, 0, "ランダム");
        } else {
            func_800495F8(230, 40, 0, "せってい");
        }
    }
    if ((D_8670C098 >= 10) || (D_8670BB4C != 12)) {
        if (D_8670BDB4[0] == 1) {
            func_800495F8(90, 50, 0, "R");
        }
        if (D_8670B3C0 == 0) {
            func_800495F8(100, 50, 0, "1:%d", D_8670B3AC[0]);
        } else {
            func_800495F8(100, 50, 0, "1:%d", D_8670B398);
        }
    }
    if ((D_8670C098 >= 10) || (D_8670BB4C != 13)) {
        if (D_8670BDB8 == 1) {
            func_800495F8(140, 50, 0, "R");
        }
        if (D_8670B3C0 == 0) {
            func_800495F8(150, 50, 0, "2:%d", D_8670B3B0);
        } else {
            func_800495F8(150, 50, 0, "2:%d", D_8670B39C);
        }
    }
    if ((D_8670C098 >= 10) || (D_8670BB4C != 14)) {
        if (D_8670BDBC == 1) {
            func_800495F8(190, 50, 0, "R");
        }
        if (D_8670B3C0 == 0) {
            func_800495F8(200, 50, 0, "3:%d", D_8670B3B4);
        } else {
            func_800495F8(200, 50, 0, "3:%d", D_8670B3A0);
        }
    }
    if ((D_8670C098 >= 10) || (D_8670BB4C != 15)) {
        if (D_8670BDC0 == 1) {
            func_800495F8(90, 60, 0, "R");
        }
        if (D_8670B3C0 == 0) {
            func_800495F8(100, 60, 0, "4:%d", D_8670B3B8);
        } else {
            func_800495F8(100, 60, 0, "4:%d", D_8670B3A4);
        }
    }
    if ((D_8670C098 >= 10) || (D_8670BB4C != 16)) {
        if (D_8670BDC4 == 1) {
            func_800495F8(140, 60, 0, "R");
        }
        if (D_8670B3C0 == 0) {
            func_800495F8(150, 60, 0, "5:%d", D_8670B3BC);
        } else {
            func_800495F8(150, 60, 0, "5:%d", D_8670B3A8);
        }
    }
    func_800495F8(90, 70, 0, "オムナイトスケール:");
    if ((D_8670C098 >= 10) || (D_8670BB4C != 1)) {
        func_800495F8(230, 70, 0, "%0.3f", (f64) D_86710C50);
    }
    func_800495F8(90, 80, 0, "オートスクロール:");
    if ((D_8670C098 >= 10) || (D_8670BB4C != 2)) {
        if (D_8670B388 == 1) {
            func_800495F8(230, 80, 0, "あり");
        } else {
            func_800495F8(230, 80, 0, "なし");
        }
    }
    func_800495F8(90, 90, 0, "トゲピーのはやさ(たて）:");
    if ((D_8670C098 >= 10) || (D_8670BB4C != 3)) {
        func_800495F8(230, 90, 0, "%0.3f", (f64) D_8670BD9C);
    }
    func_800495F8(90, 100, 0, "トゲピーのはやさ（よこ）:");
    if ((D_8670C098 >= 10) || (D_8670BB4C != 4)) {
        func_800495F8(230, 100, 0, "%0.3f", (f64) D_8670BD98);
    }
    func_800495F8(90, 110, 0, "トラップへんこう:");
    if ((D_8670C098 >= 10) || (D_8670BB4C != 5)) {
        if (D_8670B3D8 != 0) {
            func_800495F8(230, 110, 0, "あり");
        } else {
            func_800495F8(230, 110, 0, "なし");
        }
    }
    func_800495F8(90, 120, 0, "いどうオブジェクト:");
    if ((D_8670C098 >= 10) || (D_8670BB4C != 6)) {
        switch (D_8670B368) {
        case 0:
            func_800495F8(230, 120, 0, "なし");
            break;
        case 1:
            func_800495F8(230, 120, 0, "カメラ");
            break;
        case 2:
            func_800495F8(230, 120, 0, "キャラクター");
            break;
        }
    }
    func_800495F8(90, 130, 0, "yオブジェクトかんかく:");
    if ((D_8670C098 >= 10) || (D_8670BB4C != 7)) {
        func_800495F8(230, 130, 0, "%0.2f", (f64) D_8670B3C8);
    }
    func_800495F8(90, 140, 0, "ころがりブレーキ:");
    if ((D_8670C098 >= 10) || (D_8670BB4C != 8)) {
        if (D_8670B3DC == 0) {
            func_800495F8(230, 140, 0, "なし");
        } else {
            func_800495F8(230, 140, 0, "あり");
        }
    }
    func_800495F8(90, 150, 0, "ころがりタイプ:");
    if ((D_8670C098 >= 10) || (D_8670BB4C != 9)) {
        func_800495F8(230, 150, 0, "つうじょう");
    }
    func_800495F8(90, 160, 0, "CPUプレイ:");
    if ((D_8670C098 >= 10) || (D_8670BB4C != 10)) {
        func_800495F8(230, 160, 0, "あり");
    }
    // karodo: the retail build keeps this disabled debug line's format string in .rodata.
    if (0) {
        func_800495F8(90, 170, 0, "scale=%0.2f", 0.0);
    }
    func_867035A8();
    Font_DisableTwoCycleTexturing();
    func_800499EC();
}
#endif

void func_867086E4(void) {
}

#ifdef VERSION_US
s32 func_87F00930();
extern void func_87F01D44();

void func_867086EC(void) {
    if (func_87F00930() == 1) {
        func_87F01D44();
    }
}
#endif

#ifdef VERSION_US
extern void func_800088DC(void);
extern void GfxImage_FillCurrent(Gfx **, u16);
extern s32 D_8670C0C8;
extern s32 D_8670C0CC;
extern s32 D_8670C0D0;
extern void GeoRender_AdvanceFrameCounter(void);
extern void func_8003C6B8(void *);
extern void *D_8670FEC4;
extern void *D_8670FEB0;
extern void func_87F0CB68(void);
extern void func_87F07FE8(void *);
extern s32 D_8670D880;
extern void func_87F022F0(void);
extern void func_86707E2C(void);
extern void func_87F0A5BC(void *);
extern u8 D_8670D8B8[];
extern void func_87F0C88C(void *);
extern u8 D_8670FEB8[];
extern void func_80008648(void);
extern s16 D_8670BE80;
extern s32 D_8670B394;
extern void func_867086E4(void);
extern void func_867086EC(void);
extern Gfx * D_800D0510;
void func_86708720(void) {
    func_800088DC();
    GfxImage_FillCurrent(&D_800D0510, (D_8670C0C8 << 11) | (D_8670C0CC << 6) | (D_8670C0D0 << 1) | 1);
    if (D_8670B394 == 0) {
        GeoRender_AdvanceFrameCounter();
    }
    func_8003C6B8(D_8670FEC4);
    if (*(u8 *)((u8 *)D_8670FEB0 + 0x2180) != 4) {
        func_87F0CB68();
    }
    switch (gStage55MainState.mode) {
    case 2:
    case 12:
        if (gStage55MainState.transition_mode == 1) {
            func_87F07FE8(&D_8670D880);
        } else {
            func_867086E4();
        }
        if (gStage55MainState.transition_mode == 2) {
            D_8670BE80 -= 0x80;
            func_867086E4();
            func_87F022F0();
        }
        if (gStage55MainState.transition_mode == 3) {
            func_867086EC();
        }
        if (gStage55MainState.transition_mode == 0) {
            D_8670BE80 -= 0x80;
        }
        break;
    case 0:
    case 4:
    case 10:
        if (*(u8 *)((u8 *)D_8670FEB0 + 0x2180) != 4) {
            func_87F07FE8(&D_8670D880);
        }
        break;
    case 9:
        func_86707E2C();
        break;
    case 1:
        func_867086EC();
        func_867086E4();
        break;
    case 8:
    case 14:
        func_867086E4();
        func_87F0A5BC(D_8670D8B8);
        break;
    case 5:
    case 13:
        func_867086EC();
        break;
    case 7:
        func_87F022F0();
        break;
    }
    if (*(u8 *)((u8 *)D_8670FEB0 + 0x2180) == 4) {
        func_87F0C88C(D_8670FEB8);
    }
    func_80008648();
}
#endif

#ifdef VERSION_US
extern Row86706A30 D_86710C20[];
extern Row86706A30 D_867111C0[];
extern Row86706A30 D_867100C8[];
extern Row86706A30 D_86711760[4][60];
extern Row86706A30 D_867111E4[];
extern u8 D_86727CB0[];
extern s32 D_8670FEC8[];
extern f32 D_8670B3C4;
extern void ModelAnim_SetEventFrame(u8 *, s16);
extern void ModelAnim_SetFrame(u8 *, s16);
extern s32 ModelAnim_SetSpeed(u8 *, s32);
extern s32 func_8003F210(void *, s32);
extern void func_8003F114(u8 *, s16, s16, void *);
extern void func_8003F1DC(void *);
extern void func_87F03B8C(u8 *);
extern void func_87F06430(void *, s32);



void func_86708944(void) {
    s32 i;
    s32 j;
    f32 scale;

    func_87F03B8C(D_86727CB0);
    scale = 0.3f;
    for (i = 0; i < 4; i++) {
        *(f32 *)((u8 *)&D_86710C20[i] + 0x24) = (((f32)i * 120.0f) + -180.0f) * D_8670B3C4;
        func_8003F114((u8 *)&D_867111C0[i], 0, -1, (void *)D_8670FEC8[i]);
        ModelAnim_SetSpeed((u8 *)&D_86710C20[i], 0x10000);
        func_87F06430((u8 *)&D_867111E4[i], i);
        *(f32 *)((u8 *)&D_867111C0[i] + 0x38) = scale;
        *(f32 *)((u8 *)&D_867111C0[i] + 0x34) = scale;
        *(f32 *)((u8 *)&D_867111C0[i] + 0x30) = scale;
        *(f32 *)((u8 *)&D_867111C0[i] + 0x28) = 60.0f;
        func_8003F210((u8 *)&D_867111C0[i], 0);
        ModelAnim_SetFrame((u8 *)&D_867111C0[i], guRandom() % 25);
        ModelAnim_SetEventFrame((u8 *)&D_867111C0[i], 0);
        func_8003F1DC(&D_86710C20[i]);
        func_8003F1DC(&D_867100C8[i]);
        for (j = 0; j < 60; j++) {
            func_8003F1DC(&D_86711760[i][j]);
        }
    }
}
#endif

#ifdef VERSION_US
extern Row86706A30 D_867111C0[];
extern Row86706A30 D_867100C8[];
extern Row86706A30 D_86710C20[];
extern State86703DF4 D_86728408[];
extern u8 D_867286B8[];
extern s32 D_8670FEC8[];
extern s32 D_8670FF00;
extern s32 D_8670BB48;
extern f64 D_8670C550;
extern f64 D_8670C558;
extern s32 StageContext_GetFadeMode(void);
extern s32 StageFade_StartFromOpaque(s32);
extern void func_8003F1DC(void *);
extern void func_8003F114(u8 *, s16, s16, void *);
extern void ModelAnim_SetEventFrame(u8 *, s16);
extern void ModelAnim_SetFrame(u8 *, s16);
extern s32 func_8003F210(void *, s32);
extern s32 ModelAnim_IsFinished(void *);
extern void func_80027A28(u16, u8);
extern void func_87F00688(void);



void func_86708B18(void)
{
  u8 *actor;
  s32 i;
  f32 val;
  if (StageContext_GetFadeMode() == 1)
  {
    for (i = 0; i < 4; i++)
    {
      func_8003F1DC(&D_867111C0[i]);
      func_8003F114((u8 *) (&D_86710C20[i]), 0, -1, (void *) D_8670FEC8[i]);
      func_8003F114((u8 *) (&D_867100C8[i]), 0, -1, (void *) D_8670FF00);
      *((f32 *) (((u8 *) (&D_867100C8[i])) + 0x38)) = 1.5f;
      *((f32 *) (((u8 *) (&D_867100C8[i])) + 0x30)) = 1.5f;
      ModelAnim_SetEventFrame((u8 *) (&D_86710C20[i]), 0);
      func_8003F210((u8 *) (&D_86710C20[i]), 0);
      ModelAnim_SetFrame((u8 *) (&D_86710C20[i]), guRandom() % 25);
      D_86728408[i].unk2C = 0;
    }

    StageFade_StartFromOpaque(20);
    func_87F00688();
    D_8670BB48 = 13;
    return;
  }
  for (i = 0; i < 4; i++)
  {
    actor = (u8 *) (&D_867111C0[i]);
    if (D_86728408[i].unk2C == 0)
    {
      if (((*((s32 *) (((u32) ((u32) actor)) + 0x48))) >> 16) < 10)
      {
        *((s32 *) (((u8 *) (&D_86728408[i])) + 0x88)) = 0;
        *((s32 *) (((u8 *) (&D_86728408[i])) + 0x8C)) = 0;
      }
      if ((((*((s32 *) (((u32) ((u32) actor)) + 0x48))) >> 16) >= 14) && ((*((s32 *) (((u8 *) (&D_86728408[i])) + 0x88))) == 0))
      {
        func_80027A28(0x9F03, i);
        *((s32 *) (((u8 *) (&D_86728408[i])) + 0x88)) = 1;
      }
      if ((((*((s32 *) (((u32) ((u32) actor)) + 0x48))) >> 16) >= 32) && ((*((s32 *) (((u8 *) (&D_86728408[i])) + 0x8C))) == 0))
      {
        func_80027A28(0x9F03, i);
        *((s32 *) (((u8 *) (&D_86728408[i])) + 0x8C)) = 1;
      }
      *((s32 *) (((u8 *) (&D_8670BB48)) + 0x34)) = (*((s32 *) (((u8 *) (&D_8670BB48)) + 0x34))) + 1;
      val = ((*((s32 *) (((u8 *) (&D_8670BB48)) + 0x34))) * ((*((s32 *) (((u8 *) (&D_8670BB48)) + 0x34))) * 0.1));
      *((f32 *) (actor + 0x2C)) = val;
      *((f32 *) (actor + 0x24)) = (2000.0f - val) / ((f32) (*((s32 *) (((u8 *) (&D_86728408[i])) + 0x3C))));
      *((f32 *) (actor + 0x28)) = (val * (-0.13)) + 60.0;
      if (((f32) (*((s32 *) (((u8 *) (&D_86728408[i])) + 0x40)))) < val)
      {
        func_8003F210(actor, 3);
        D_86728408[i].unk2C = 2;
      }
    }
    else
      if ((D_86728408[i].unk2C == 2) && (((*((s32 *) ((((u8 *) D_867111C0) + (i * 0x168)) + 0x48))) >> 16) == 2))
    {
      func_80027A28(0x9F01, i);
    }
    if ((*((s32 *) (((u8 *) (&D_86728408[i])) + 0x98))) == 206)
    {
      *((s32 *) (((u8 *) (&D_8670BB48)) + 0x34)) = (*((s32 *) (((u8 *) (&D_8670BB48)) + 0x34))) + 1;
      val = ((*((s32 *) (((u8 *) (&D_8670BB48)) + 0x34))) * ((*((s32 *) (((u8 *) (&D_8670BB48)) + 0x34))) * 0.1));
      actor = (u8 *) (&D_867111C0[i]);
      *((f32 *) (actor + 0x2C)) = (*((s32 *) (((u8 *) (&D_8670BB48)) + 0x34))) * ((*((s32 *) (((u8 *) (&D_8670BB48)) + 0x34))) * 0.1);
      *((f32 *) (actor + 0x24)) = (2000.0f - val) / ((f32) (*((s32 *) (((u8 *) (&D_86728408[i])) + 0x3C))));
      *((f32 *) (actor + 0x28)) = (val * (-0.13)) + 60.0;
      if (ModelAnim_IsFinished(actor) == 1)
      {
        ModelAnim_SetFrame(actor, 0);
      }
    }
  }

}
#endif

#ifdef VERSION_US
extern Row86706A30 D_867111C0[];
extern s32 D_8670BBB0;
extern s32 D_8670D880;
extern s32 func_87F08208(void *);
extern s32 ModelAnim_SetSpeed(u8 *, s32);
extern s32 func_8003F210(void *, s32);
extern void StageContext_SetClearColor(u16);
extern void func_800225C4(s32);
extern void func_800226C0(s32);
extern void func_800279C4(u16);
extern s32 StageFade_StartFromTransparent(s32);
extern s32 D_8670BB48;
void Stage55_UpdateTransition(void) {
    s32 result;
    s32 index;
    D_8670BBB0++;
    if (D_8670BBB0 > 200) {
        D_8670BBB0 = 0;
    }
    result = func_87F08208(&D_8670D880);
    switch (result) {
    case 1:
        for (index = 0; index < 4; index++) {
            func_8003F210(&D_867111C0[index], 1);
            ModelAnim_SetSpeed((u8 *)&D_867111C0[index], 0x50000);
            if (*(s32 *)((u8 *)&D_86728408[index] + 0x98) == 206) {
                func_8003F210(&D_867111C0[index], 7);
                D_86728408[index].unk2C = 10;
                ModelAnim_SetSpeed((u8 *)&D_867111C0[index], 0x20000);
            }
        }
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(20);
        gStage55MainState.mode = 10;
        func_800225C4(40);
        func_800279C4(0xCF0B);
        break;
    case 2:
        gStage55MainState.mode = 2;
        gStage55MainState.transition_mode = 1;
        gStage55MainState.exit_result = 0;
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(10);
        func_800226C0(3);
        break;
    }
}
#endif

#ifdef VERSION_US
extern s32 D_8670BB48;
extern void *D_8670FEB0;
void func_86709040(void) {
    if ((*(u8 *)((u8 *)(D_8670FEB0) + (0x2180))) == 4) {
        StageFade_StartFromOpaque(0x14);
        func_87F00688();
        D_8670BB48 = 0xD;
        return;
    }
    if (StageContext_GetFadeMode() == 0) {
        D_8670BB48 = 4;
    }
}
#endif

#ifdef VERSION_US
extern s32 func_87F006AC(void);
extern void Audio_PlayDefaultSound(s32);
extern void func_80021ED8(s32);
extern void func_87F0CA30(void);
extern s32 D_8670B394;
extern s32 D_8670BB48;
s32 func_867090A8(void) {
    if (D_8670B394 == 1) {
        return 0;
    }
    if (func_87F006AC() == 1) {
        Audio_PlayDefaultSound(0x5F07);
    }
    if (func_87F006AC() == 2) {
        D_8670BB48 = 1;
        Audio_PlayDefaultSound(0x5F08);
        func_80021ED8(0x2E);
        func_87F0CA30();
    }
}
#endif

void func_86709128(void) {
}

#ifdef VERSION_US
/* mkdraft:func_86709130 begin */
extern u8 *D_80087200;
extern s32 D_8670BB48;
extern s32 D_8670B368;
extern s32 D_8670B388;
extern s32 D_8670B398;
extern s32 D_8670B3C0;
extern s32 D_8670B3D8;
extern s32 D_8670B3DC;
extern f32 D_8670BD98;


void func_86709130(void) {
    if (*(u16 *)(D_80087200 + 8) & 0x400) {
        *(s32 *)((u8 *)&D_8670BB48 + 4) = *(s32 *)((u8 *)&D_8670BB48 + 4) + 1;
        if (*(s32 *)((u8 *)&D_8670BB48 + 4) > 16) {
            *(s32 *)((u8 *)&D_8670BB48 + 4) = 16;
        }
    } else if (*(u16 *)(D_80087200 + 8) & 0x800) {
        *(s32 *)((u8 *)&D_8670BB48 + 4) = *(s32 *)((u8 *)&D_8670BB48 + 4) - 1;
        if (*(s32 *)((u8 *)&D_8670BB48 + 4) <= 0) {
            *(s32 *)((u8 *)&D_8670BB48 + 4) = 1;
        }
    } else if ((*(u16 *)(D_80087200 + 8) & 0x100) || (*(u16 *)(D_80087200 + 6) & 1)) {
        switch (*(s32 *)((u8 *)&D_8670BB48 + 4)) {
        case 1:
            *(f32 *)((u8 *)&D_8670BB48 + 0x60) += 0.01;
            break;
        case 2:
            D_8670B388 = 1;
            break;
        case 3:
            D_8670BD9C += 0.01;
            break;
        case 4:
            D_8670BD98 += 0.01;
            break;
        case 5:
            D_8670B3D8 = 1;
            break;
        case 6:
            D_8670B368 = D_8670B368 + 1;
            if (D_8670B368 > 0) {
                D_8670B368 = 1;
            }
            break;
        case 7:
            D_8670B3C8 += 0.1;
            break;
        case 8:
            D_8670B3DC = 1;
            break;
        case 11:
            D_8670B3C0 = 1;
            break;
        case 12:
            *(s32 *)((u8 *)&D_8670B398 + 0) = *(s32 *)((u8 *)&D_8670B398 + 0) + 1;
            if (*(s32 *)((u8 *)&D_8670B398 + 0) > 19) {
                *(s32 *)((u8 *)&D_8670B398 + 0) = 19;
            }
            break;
        case 13:
            *(s32 *)((u8 *)&D_8670B398 + 4) = *(s32 *)((u8 *)&D_8670B398 + 4) + 1;
            if (*(s32 *)((u8 *)&D_8670B398 + 4) > 19) {
                *(s32 *)((u8 *)&D_8670B398 + 4) = 19;
            }
            break;
        case 14:
            *(s32 *)((u8 *)&D_8670B398 + 8) = *(s32 *)((u8 *)&D_8670B398 + 8) + 1;
            if (*(s32 *)((u8 *)&D_8670B398 + 8) > 19) {
                *(s32 *)((u8 *)&D_8670B398 + 8) = 19;
            }
            break;
        case 15:
            *(s32 *)((u8 *)&D_8670B398 + 0xC) = *(s32 *)((u8 *)&D_8670B398 + 0xC) + 1;
            if (*(s32 *)((u8 *)&D_8670B398 + 0xC) > 19) {
                *(s32 *)((u8 *)&D_8670B398 + 0xC) = 19;
            }
            break;
        case 16:
            *(s32 *)((u8 *)&D_8670B398 + 0x10) = *(s32 *)((u8 *)&D_8670B398 + 0x10) + 1;
            if (*(s32 *)((u8 *)&D_8670B398 + 0x10) > 19) {
                *(s32 *)((u8 *)&D_8670B398 + 0x10) = 19;
            }
            break;
        }
    } else if ((*(u16 *)(D_80087200 + 8) & 0x200) || (*(u16 *)(D_80087200 + 6) & 2)) {
        switch (*(s32 *)((u8 *)&D_8670BB48 + 4)) {
        case 1:
            *(f32 *)((u8 *)&D_8670BB48 + 0x60) -= 0.01;
            break;
        case 2:
            D_8670B388 = 0;
            break;
        case 3:
            D_8670BD9C -= 0.01;
            if (D_8670BD9C < 0.03) {
                D_8670BD9C = 0.03f;
            }
            break;
        case 4:
            D_8670BD98 -= 0.01;
            if (D_8670BD98 < 0.01) {
                D_8670BD98 = 0.01f;
            }
            break;
        case 5:
            D_8670B3D8 = 0;
            break;
        case 6:
            D_8670B368 = D_8670B368 - 1;
            if (D_8670B368 <= 0) {
                D_8670B368 = 0;
            }
            break;
        case 7:
            D_8670B3C8 -= 0.1;
            if (D_8670B3C8 <= 0.0f) {
                D_8670B3C8 = 0.0f;
            }
            break;
        case 8:
            D_8670B3DC = 0;
            break;
        case 11:
            D_8670B3C0 = 0;
            func_8670211C();
            break;
        case 12:
            *(s32 *)((u8 *)&D_8670B398 + 0) = *(s32 *)((u8 *)&D_8670B398 + 0) - 1;
            if (*(s32 *)((u8 *)&D_8670B398 + 0) < 0) {
                *(s32 *)((u8 *)&D_8670B398 + 0) = 0;
            }
            break;
        case 13:
            *(s32 *)((u8 *)&D_8670B398 + 4) = *(s32 *)((u8 *)&D_8670B398 + 4) - 1;
            if (*(s32 *)((u8 *)&D_8670B398 + 4) < 0) {
                *(s32 *)((u8 *)&D_8670B398 + 4) = 0;
            }
            break;
        case 14:
            *(s32 *)((u8 *)&D_8670B398 + 8) = *(s32 *)((u8 *)&D_8670B398 + 8) - 1;
            if (*(s32 *)((u8 *)&D_8670B398 + 8) < 0) {
                *(s32 *)((u8 *)&D_8670B398 + 8) = 0;
            }
            break;
        case 15:
            *(s32 *)((u8 *)&D_8670B398 + 0xC) = *(s32 *)((u8 *)&D_8670B398 + 0xC) - 1;
            if (*(s32 *)((u8 *)&D_8670B398 + 0xC) < 0) {
                *(s32 *)((u8 *)&D_8670B398 + 0xC) = 0;
            }
            break;
        case 16:
            *(s32 *)((u8 *)&D_8670B398 + 0x10) = *(s32 *)((u8 *)&D_8670B398 + 0x10) - 1;
            if (*(s32 *)((u8 *)&D_8670B398 + 0x10) < 0) {
                *(s32 *)((u8 *)&D_8670B398 + 0x10) = 0;
            }
            break;
        }
    }
    if (*(s32 *)((u8 *)&D_8670BB48 + 4) == 6) {
        if ( *(u16 *)(D_80087200 + 6) & 8) {
            *(f32 *)((u8 *)&D_8670BB48 + 0x24) -= 20.0f;
        } else if (*(u16 *)(D_80087200 + 6) & 4) {
            *(f32 *)((u8 *)&D_8670BB48 + 0x24) += 20.0f;
        } else if (*(u16 *)(D_80087200 + 6) & 1) {
            *(f32 *)((u8 *)&D_8670BB48 + 0x20) += 10.0f;
        } else if (*(u16 *)(D_80087200 + 6) & 2) {
            *(f32 *)((u8 *)&D_8670BB48 + 0x20) -= 10.0f;
        } else if (*(u16 *)(D_80087200 + 6) & 0x8000) {
            *(f32 *)((u8 *)&D_8670BB48 + 0x1C) -= 40.0f;
        } else if (*(u16 *)(D_80087200 + 6) & 0x4000) {
            *(f32 *)((u8 *)&D_8670BB48 + 0x1C) += 40.0f;
        } else if (*(u16 *)(D_80087200 + 6) & 0x2000) {
            osSyncPrintf("cameray =%f cameraz=%f objectx =%f objecty=%f \n",
                         *(f32 *)((u8 *)&D_8670BB48 + 0x18),
                         *(f32 *)((u8 *)&D_8670BB48 + 0x1C),
                         *(f32 *)((u8 *)&D_8670BB48 + 0x20),
                         *(f32 *)((u8 *)&D_8670BB48 + 0x24));
        }
    }
}
/* mkdraft:func_86709130 end */
#endif

#ifdef VERSION_US
extern s32 StageFade_StartFromTransparent(s32);
s32 func_87F01A40();
extern s32 D_8670B394;
void func_8670972C(void) {
    s32 temp_v0;

    D_8670B394 = 1;
    temp_v0 = func_87F01A40();
    switch (temp_v0) {                              /* irregular */
    case 0:
    case 2:
        D_8670B394 = 0;
        return;
    case 3:
        (*(s32 *)((u8 *)(&D_8670BB48) + (0x48))) = 0;
        (*(s32 *)((u8 *)(&D_8670BB48) + (0))) = 2;
        (*(s32 *)((u8 *)(&D_8670BB48) + (0x30))) = 3;
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(0xA);
        return;
    case 4:
        (*(s32 *)((u8 *)(&D_8670BB48) + (0x48))) = 1;
        (*(s32 *)((u8 *)(&D_8670BB48) + (0))) = 2;
        (*(s32 *)((u8 *)(&D_8670BB48) + (0x30))) = 3;
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(0xA);
        return;
    }
}
#endif

#ifdef VERSION_US

typedef struct { s32 v[4]; } Flags8670C0D8;
extern Flags8670C0D8 D_8670C0D8;
extern State86703DF4 D_86728408[];
// D_8672843C is declared earlier in fragment55_code.c (anon struct with unk_00);
// do NOT redeclare it here - a second anonymous struct definition is a different
// type and the build fails with "conflicting types for D_8672843C".
extern s32 D_867284B0;
extern s32 D_867284E8;
extern s32 D_8672855C;
extern s32 D_86728594;
extern s32 D_86728608;
extern s32 D_86728640;
extern s32 D_867286B4;

// Ranks the four D_86728408 records by descending unk10: every pass takes the
// highest unk10 among unranked records, gives the tied records the same rank
// (written as rank + 1 at offset 0x34), then repeats until all four are ranked.
// Afterwards four optional words are copied into the targets they feed.


void func_867097D8(void) {
    f32 max;
    s32 total;
    s32 rank;
    s32 i;
    s32 flags[4];

    *((Flags8670C0D8 *) flags) = D_8670C0D8;
    i = 0;
    max = 0.0f;
    total = 0;
    if (i) { // FAKE: inert; required for the target uopt register coloring
    }
    // Assigning the chain directly to flags[3] makes it store 0x1C, 0x18, 0x14,
    // 0x10 in that order. The chain must precede rank = 0: placed earlier, rank's
    // web takes the lower live-range bit and lands in $a0 instead of $a1.
    flags[3] = flags[2] = flags[1] = flags[0] = 0;
    rank = 0;
loop:
    for (i = 0; i < 4; i++) {
        if ((max <= (*((f32 *) ((((u8 *) D_86728408) + (i * 0xAC)) + 0x10)))) && (flags[i] == 0)) {
            max = *((f32 *) ((((u8 *) D_86728408) + (i * 0xAC)) + 0x10));
        }
    }

    for (i = 0; i < 4; i++) {
        if (max == (*((f32 *) ((((u8 *) D_86728408) + (i * 0xAC)) + 0x10)))) {
            flags[i] = 1;
            total++;
            *((s32 *) ((((u8 *) D_86728408) + (i * 0xAC)) + 0x34)) = rank + 1;
        }
    }

    i++; // FAKE: discarded; without it the two loops unroll (112 instructions vs 88)
    if (total < 4) {
        if (1) { // FAKE: inert; prevents the float zero from being hoisted
        }
        max = 0.0f;
        rank = total;
        goto loop;
    }
    if (D_867284B0 != 0) {
        D_8672843C[0].unk_00 = D_867284B0;
    }
    if (D_8672855C != 0) {
        D_867284E8 = D_8672855C;
    }
    if (D_86728608 != 0) {
        D_86728594 = D_86728608;
    }
    if (D_867286B4 != 0) {
        D_86728640 = D_867286B4;
    }
}
#endif

#ifdef VERSION_US
extern Stage55Slot D_8670C980[4][60];
extern Row86706A30 D_86711760[4][60];
extern s32 D_8670FF08[];
extern void func_87F0277C(void *);
extern u8 D_8670D948[];
extern void func_867097D8(void);
extern s32 D_8670BB84;
extern s32 D_8670B394;
extern s32 D_8670BB58;
extern void func_8003F114(u8 *, s16, s16, void *);

extern s32 D_8670BB48;
extern u8 D_8670E5C0[];
extern u8 D_8670F868[];
void Stage55_UpdateResourcePools(void) {
    s32 group;
    s32 index;
    func_87F0277C(D_8670D948);
    func_87F0277C(D_8670F868);
    func_87F0277C(D_8670E5C0);
    if (D_8670B394 != 1) {
        gStage55MainState.animation_frame++;
        if (gStage55MainState.animation_frame >= 6) {
            gStage55MainState.animation_frame = 0;
        }
        for (group = 0; group < 4; group++) {

            for (index = 0; index < 60; index++) {
                if (D_8670C980[group][index].resource_index != -1) {
                    if (D_86711760[group][index].z < 450.0f) {
                        func_8003F114((u8 *)&D_86711760[group][index], 0, -1, (void *)D_8670FF08[D_8670C980[group][index].resource_index]);
                        D_8670C980[group][index].resource_index = -1;
                    }
                }
            }
        }
        func_867097D8();
        gStage55MainState.time++;
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/55/fragment55_code/func_86709AD0.s")
#endif

#ifdef VERSION_US
f32 D_8670C100 = 200.0f;
f32 D_8670C104 = 3380.0f;

extern f32 D_8670BE7C;
extern s16 D_8670BE80;
extern s16 D_8670BE84;
extern u8 D_86726A48[];
extern u8 D_86726BB0[];
extern u8 D_86726D18[];
extern u8 D_86726E80[];
extern u8 D_86726FE8[];
extern u8 D_86727150[];
extern u8 D_867272B8[];
extern void *D_8670FEDC;
extern void *D_8670FEE0;
extern void *D_8670FEE4;
extern void *D_8670FEE8;
extern void *D_8670FEEC;
extern void *D_8670FEF0;
extern void *D_8670FEF4;
extern void func_8003F114(u8 *, s16, s16, void *);
extern void func_8003F1DC(void *);

#define ST(type, off) (*(type *)((u8 *)&D_8670BB48 + (off)))

void func_8670A07C(void) {
    static s32 D_8670C108 = 192;
    s32 rel;

    if (D_8670B394 == 1) {
        return;
    }
    rel = D_8670C108 - 192;
    switch (ST(s32, 0x40)) {
        case 0:
            ST(s32, 0x40) = 2;
            D_8670BE84 = 2773;
            ST(f32, 0x1C) = 1610.0f;
            ST(f32, 0x24) = 160.0f;
            D_8670BE7C = 13.6f;
            D_8670C108 = 192;
            func_8003F114(D_86726A48, 0, -1, D_8670FEDC);
            func_8003F114(D_86726BB0, 0, -1, D_8670FEE4);
            func_8003F114(D_86726D18, 0, -1, D_8670FEE0);
            func_8003F114(D_86726E80, 0, -1, D_8670FEE8);
            func_8003F114(D_86726FE8, 0, -1, D_8670FEEC);
            func_8003F114(D_86727150, 0, -1, D_8670FEF0);
            func_8003F114(D_867272B8, 0, -1, D_8670FEF4);
            break;
        case 1:
            D_8670BE80 = (rel << 8) - 32764;
            D_8670C108++;
            if (D_8670BE80 < 0) {
                D_8670BE80 += 0xFFFF;
            }
            D_8670BE84 += 60;
            if (D_8670BE84 + 960 > 6490) {
                D_8670BE84 = 6490;
                ST(s32, 0x40) = 2;
            }
            break;
        case 2:
            if (ST(f32, 0x1C) + 93.125 <= 7570.0) {
                ST(f32, 0x1C) = ST(f32, 0x1C) + 93.125;
            } else {
                ST(f32, 0x1C) = 7570.0f;
            }
            if (D_8670BE84 + 59 < 6612) {
                D_8670BE84 = D_8670BE84 + 59;
            } else {
                D_8670BE84 = 6611;
            }
            if (7.6 <= D_8670BE7C - 0.09375) {
                D_8670BE7C = D_8670BE7C - 0.09375;
            } else {
                D_8670BE7C = 7.6f;
            }
            if (40.0f <= ST(f32, 0x24) - 10.0f) {
                ST(f32, 0x24) = ST(f32, 0x24) - 10.0f;
            } else {
                ST(f32, 0x24) = 40.0f;
            }
            if (D_8670C108 <= 256) {
                D_8670BE80 = -32764 - (rel << 8);
            } else {
                D_8670BE80 = 16388;
            }
            D_8670C108++;
            if (D_8670C108 >= 268) {
                ST(s32, 0x40) = 3;
            }
            break;
        case 3:
            ST(s32, 0x40) = 4;
            func_8003F1DC(D_86726A48);
            func_8003F1DC(D_86726BB0);
            func_8003F1DC(D_86726D18);
            func_8003F1DC(D_86726E80);
            func_8003F1DC(D_86726FE8);
            func_8003F1DC(D_86727150);
            func_8003F1DC(D_867272B8);
            break;
        case 4:
            break;
    }
}
#undef ST
#endif

#ifdef VERSION_US
extern f32 D_8670BE7C;
extern s16 D_8670BE80;
extern s16 D_8670BE84;
extern void func_8003F1DC(void *);

void func_8670A404(void) {
    f32 *var_v0 = (f32 *)&D_8670BB48;

    var_v0[5] = 0.0f;
    var_v0[6] = -140.0f;
    var_v0[7] = 7450.0f;
    var_v0[8] = 0.0f;
    var_v0[9] = 40.0f;
    var_v0[10] = 0.0f;
    D_8670BE7C = 7.6f;
    D_8670BE80 = 16388;
    D_8670BE84 = 6400;
    func_8003F1DC(&D_86726A48);
    func_8003F1DC(&D_86726BB0);
    func_8003F1DC(&D_86726D18);
    func_8003F1DC(&D_86726E80);
    func_8003F1DC(&D_86726FE8);
    func_8003F1DC(&D_86727150);
    func_8003F1DC(&D_867272B8);
}
#endif

#ifdef VERSION_US
extern s32 func_87F0C6F4(void *);
extern void func_87F006BC(void);
extern void func_86708B18(void);
extern void func_8670A07C(void);
extern void func_86709AD0(void);
extern s32 Fragment64_UpdateBounceAndConfirm(void *);
extern void func_87F02328(void);
extern void func_86708944(void);
extern void func_86702B28(void);
extern void func_86709130(void);
extern s32 func_87F02104(void);
extern void func_87F0D5B8(void *);
extern void func_87F0C9D0(s32);
extern u8 D_8670FEB8[];
extern u8 D_8670D8B8[];
extern void Stage55_UpdateResourcePools(void);
extern void Stage55_UpdateTransition(void);
extern void StageContext_SetClearColor(u16);
extern s32 StageFade_StartFromTransparent(s32);
extern void func_86709040(void);
extern s32 func_867090A8(void);
extern void func_86709128(void);
extern void func_8670972C(void);
extern void func_8670A404(void);
extern s32 func_87F00930();
extern s16 D_8670BE80;
extern u8 D_8670D920[];
extern void * D_8670FEB0;
s32 func_8670A4D4(s32 arg0) {
    if (*(u8 *)((u8 *)D_8670FEB0 + 0x2180) == 4 && func_87F0C6F4(D_8670FEB8) != 0) {
        gStage55MainState.mode = 3;
        gStage55MainState.exit_result = 3;
    }
    if (func_87F00930() == 0 && gStage55MainState.mode != 9) {
        func_87F006BC();
    }
    switch (gStage55MainState.mode) {
    case 0:
        func_86709040();
        break;
    case 4:
        Stage55_UpdateTransition();
        break;
    case 10:
        func_86708B18();
        break;
    case 5:
    case 13:
        func_8670A07C();
        func_8670972C();
        func_867090A8();
        break;
    case 14:
        func_86709AD0();
    case 8:
        func_86709128();
        if (Fragment64_UpdateBounceAndConfirm(D_8670D8B8) != 0) {
            if (*(u8 *)((u8 *)D_8670FEB0 + 0x2180) == 1) {
                gStage55MainState.exit_result = 2;
                gStage55MainState.mode = 2;
                gStage55MainState.transition_mode = 0;
                StageContext_SetClearColor(0xFFFF);
                StageFade_StartFromTransparent(10);
            } else {
                func_87F02328();
                gStage55MainState.mode = 7;
            }
        }
        break;
    case 12:
        if (StageContext_GetFadeMode() == 1) {
            gStage55MainState.mode = 11;
            func_86708944();
            func_8670A404();
            func_86702B28();
            StageFade_StartFromOpaque(10);
        }
        break;
    case 11:
        gStage55MainState.mode = 0;
        break;
    case 1:
        func_8670972C();
        Stage55_UpdateResourcePools();
        break;
    case 9:
        func_86709130();
        break;
    case 7:
        D_8670BE80 -= 0x80;
        switch (func_87F02104()) {
        case 1:
            StageContext_SetClearColor(1);
            StageFade_StartFromTransparent(10);
            gStage55MainState.mode = 12;
            gStage55MainState.transition_mode = 2;
            break;
        case 2:
            gStage55MainState.exit_result = 0;
            gStage55MainState.mode = 2;
            gStage55MainState.transition_mode = 2;
            StageContext_SetClearColor(0xFFFF);
            StageFade_StartFromTransparent(10);
            break;
        case 3:
            gStage55MainState.exit_result = 1;
            gStage55MainState.mode = 2;
            gStage55MainState.transition_mode = 2;
            StageContext_SetClearColor(0xFFFF);
            StageFade_StartFromTransparent(10);
            break;
        }
        break;
    case 2:
        if (StageContext_GetFadeMode() == 1) {
            gStage55MainState.mode = 3;
        }
        break;
    }
    func_87F0D5B8(D_8670D920);
    func_87F0C9D0(func_87F00930());
    return gStage55MainState.mode;
}
#endif

#ifdef VERSION_US
extern Row86706A30 D_867111C0[];
extern Row86706A30 D_867100C8[];
extern s32 D_8670FEC8[];
extern s32 D_8670FF00;
extern void ModelAnim_SetFrame(u8 *, s16);
extern void ModelAnim_SetEventFrame(u8 *, s16);
extern s32 func_8003F210(void *, s32);
extern void func_800086A4(s32);
extern void func_80064D28(void);
extern void func_86708720(void);
extern s32 func_8670A4D4(s32);
extern void func_8003F114(u8 *, s16, s16, void *);
extern void func_8003F1DC(void *);
extern s32 D_8670BB48;
extern f32 D_8670BE7C;
extern s16 D_8670BE80;
extern s16 D_8670BE84;
extern void * D_8670FEB0;
void Stage55_RunStage(void) {
    s32 index;
    func_800086A4(2);
    if (*((u8 *)D_8670FEB0 + 0x2180) == 4) {
        D_8670BE84 = 2773;
        D_8670BE80 = -32764;
        gStage55MainState.unk1C = 1610.0f;
        gStage55MainState.unk24 = 160.0f;
        D_8670BE7C = 13.6f;
        for (index = 0; index < 4; index++) {
            func_8003F1DC(&D_867111C0[index]);
            func_8003F114((u8 *)&D_86710C20[index], 0, -1, (void *)D_8670FEC8[index]);
            func_8003F114((u8 *)&D_867100C8[index], 0, -1, (void *)D_8670FF00);
            ModelAnim_SetEventFrame((u8 *)&D_86710C20[index], 0);
            func_8003F210((u8 *)&D_86710C20[index], 0);
            ModelAnim_SetFrame((u8 *)&D_86710C20[index], guRandom() % 25);
            D_86728408[index].unk2C = 0;
        }
    }
    StageFade_StartFromOpaque(10);
    while (1) {
        func_80064D28();
        func_86708720();
        gStage55MainState.mode = func_8670A4D4(gStage55MainState.mode);
        if (gStage55MainState.mode == 3) { break; }
    }
}
#endif

#ifdef VERSION_US
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

M2C_UNK Asset_LoadToSegment(u32, M2C_UNK *, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK Gfx_FreeDisplayListBuffers();               /* extern */
M2C_UNK Gfx_InitDisplayListBuffers(M2C_UNK, M2C_UNK); /* extern */
s32 func_800082E0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_80008514(s32);                         /* extern */
M2C_UNK func_80008574();                            /* extern */
M2C_UNK func_80027EE0(M2C_UNK);                     /* extern */
M2C_UNK func_80047588(s32, M2C_UNK);                /* extern */
M2C_UNK func_80047610();                            /* extern */
M2C_UNK func_8004C09C(M2C_UNK);                     /* extern */
M2C_UNK func_8004C398();                            /* extern */
M2C_UNK func_8004C8C0(M2C_UNK);                     /* extern */
M2C_UNK func_86706E34();                            /* extern */
void Stage55_RunStage(void);                            /* extern */
M2C_UNK func_87F00030();                            /* extern */
M2C_UNK func_87F01F34(u8 *);                      /* extern */
M2C_UNK func_87F06EAC(M2C_UNK, M2C_UNK *, u8 *);  /* extern */
s32 func_87F08E3C(s32, M2C_UNK);                    /* extern */
M2C_UNK func_87F0C980();                            /* extern */
M2C_UNK func_87F0F480(u8 *);                      /* extern */
M2C_UNK main_pool_pop_state(M2C_UNK);               /* extern */
M2C_UNK main_pool_push_state(M2C_UNK);              /* extern */
extern M2C_UNK D_1000000;
extern M2C_UNK D_446E30;
extern M2C_UNK D_447D00;
extern s32 D_8670BB90;
extern s32 D_8670C958;
extern M2C_UNK D_8670D880;
extern s32 D_8670D888;
extern s32 D_8670D8D8;

s32 func_8670A96C(s32 arg0, u8 *arg1) {
    s32 sp24;

    D_8670FEB0 = arg1;
    if (M2C_FIELD(D_8670FEB0, u8 *, 0x2180) == 4) {
        func_80027EE0(0xFFF);
    }
    main_pool_push_state(0x4D523033);
    Gfx_InitDisplayListBuffers(0x20000, 0);
    sp24 = func_800082E0(0, 1, 3, 1, 2, 1);
    func_8004C09C(0x123);
    func_87F06EAC(0x6C, &D_8670D880, D_8670FEB0);
    func_8004C8C0(0xE2);
    func_8004C8C0(0xE3);
    func_8004C8C0(0x1B2);
    func_8004C8C0(0x133);
    func_8004C8C0(0xE0);
    func_8004C8C0(0x3E);
    func_8004C8C0(0x182);
    func_8004C8C0(0x183);
    func_8004C8C0(0xCD);
    D_8670C96C = func_87F08E3C(func_8004C990(0xE3, 0), 0x0F000000);
    D_8670C958 = func_87F08E3C(func_8004C990(0xCD, 0), 0x0F000000);
    func_80047588(D_8670D888 | 5 | D_8670D8D8, 0);
    Asset_LoadToSegment((u32) ((s32) &D_1000000 & 0x0F000000) >> 0x18, &D_446E30, &D_447D00, 0);
    func_87F00030();
    func_87F01F34(D_8670FEB0);
    func_87F0C980();
    func_86706E34();
    func_80008514(sp24);
    Stage55_RunStage();
    func_80008574();
    func_80047610();
    func_8004C398();
    Gfx_FreeDisplayListBuffers();
    main_pool_pop_state(0x4D523033);
    func_87F0F480(D_8670FEB0);
    func_80027EE0(0xFFE);
    return D_8670BB90;
}
#endif
