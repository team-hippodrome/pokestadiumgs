#include "global.h"


#ifdef VERSION_US
extern void StageFade_StartFromTransparent(s32);
extern void StageContext_SetClearColor(s32);
extern void *D_863075D8;
void func_86300020(s32 arg0) {
    (*(s32 *)((u8 *)(D_863075D8) + (0x8F58))) = arg0;
    (*(s32 *)((u8 *)(D_863075D8) + (0))) = 7;
    (*(s32 *)((u8 *)(D_863075D8) + (4))) = 8;
    StageContext_SetClearColor(0xFFFF);
    StageFade_StartFromTransparent(0xA);
}
#endif

#ifdef VERSION_US
typedef struct Fragment51PlayerActor Fragment51PlayerActor;
typedef struct {
    s32 player_index;
    f32 angle_degrees;
    f32 slope;
    f32 intercept;
    f32 min_x;
    f32 max_x;
    u8 unk_18[8];
    f32 spawn_x;
    f32 spawn_y;
    f32 position_x;
    f32 position_y;
    s32 unk_30;
    f32 unk_34;
    f32 unk_38;
    s32 score;
    Fragment51PlayerActor *companion;
    f32 companion_x;
    f32 companion_y;
} Fragment51PlayerRecord;
extern Fragment51PlayerRecord D_863072F8[4];
s32 Fragment51_CountTopScorers(s32 *top_score) {
    s32 ties = 0;
    s32 i;
    *top_score = 0;
    for (i = 0; i < 4; i++) {
        if ((i == 0) || (*top_score < ((Fragment51PlayerRecord *)D_863072F8)[i].score)) {
            *top_score = ((Fragment51PlayerRecord *)D_863072F8)[i].score;
        }
    }
    for (i = 0; i < 4; i++) {
        if (((Fragment51PlayerRecord *)D_863072F8)[i].score == *top_score) ties++;
    }
    return ties;
}
#endif

#ifdef VERSION_US
extern void func_87D00648(void *, void *, void *);
extern void func_87D0059C(void *, void *);
extern u8 D_863071F0[];
extern s32 D_863072B4;

typedef struct {
    char unk00[8];
    u8 unk08;
    u8 unk09;
    char unk0A[2];
} Unk_86307254;

extern Unk_86307254 D_86307254[];
void func_86300120(void) {
    Unk_86307254 *entry;
    s32 i;
    u8 *p1;
    u8 *p2;

    entry = D_86307254;
    i = 0;
    if (D_863072B4 > 0) {
        do {
            p1 = D_863071F0 + entry->unk08 * 8;
            p2 = D_863071F0 + entry->unk09 * 8;
            func_87D00648(entry, p1, p2);
            func_87D0059C(entry, (u8 *)entry + 4);
            i += 1;
            entry = (Unk_86307254 *)((u8 *)entry + 0xC);
        } while (i < D_863072B4);
    }
}
#endif

#ifdef VERSION_US
extern void *D_87F119DC;
extern Fragment51PlayerRecord D_863072F8[4];
void Fragment51_UpdateScores(void) {
    u8 *actor_state;
    s32 player_index;
    s32 quadrant;
    s32 i;
    Fragment51PlayerRecord *hit;
    actor_state = *(u8 **)((u8 *)D_87F119DC + 0x20);
    player_index = *(s8 *)(actor_state + 0x20);
    if (*(f32 *)((u8 *)D_87F119DC + 0x48) <= 0.0f) {
        if (*(f32 *)((u8 *)D_87F119DC + 0x4C) > 0.0f) quadrant = 0;
        else quadrant = 2;
    } else {
        if (*(f32 *)((u8 *)D_87F119DC + 0x4C) > 0.0f) quadrant = 1;
        else quadrant = 3;
    }
    switch (*(u8 *)((u8 *)D_863075D8 + 0x8F50)) {
    case 0:
        for (i = 0; i < 4; i++) {
            if (i != quadrant) ((Fragment51PlayerRecord *)D_863072F8)[i].score++;
        }
        if ((player_index != -1) && (player_index != quadrant)) {
            ((Fragment51PlayerRecord *)D_863072F8)[player_index].score++;
        }
        break;
    case 1:
        hit = &((Fragment51PlayerRecord *)D_863072F8)[quadrant];
        hit->score--;
        if (hit->score < 0) hit->score = 0;
        if (player_index != -1) {
            ((Fragment51PlayerRecord *)D_863072F8)[player_index].score++;
        }
        break;
    case 2:
        if ((player_index != -1) && (player_index != quadrant)) {
            hit = &((Fragment51PlayerRecord *)D_863072F8)[quadrant];
            hit->score--;
            ((Fragment51PlayerRecord *)D_863072F8)[player_index].score++;
        } else {
            hit = &((Fragment51PlayerRecord *)D_863072F8)[quadrant];
            hit->score--;
        }
        if (hit->score < 0) hit->score = 0;
        break;
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_275E40/func_863003DC.s")
#endif

#ifdef VERSION_US
extern void *D_863075D8;
extern void func_863003DC(void *);
void func_86300494(void) {
    s32 i;
    void *p;

    p = (u8 *)D_863075D8 + 0x149C;
    for (i = 0; i != 4; i += 1) {
        func_863003DC(p);
        p = (u8 *)p + 0x18C;
    }
}
#endif

void func_863004E8(void) {
}

#ifdef VERSION_US
extern Gfx *D_800D0510;
extern s32 func_8004C990(s32, s32);
extern u8 *func_8004CA60(u8 *);
extern void GeoRender_ApplyMaterialState(void);
extern u8 D_863070F0[];
void func_863004F0(s32 arg0, s32 arg1) {
    if (arg0 == 5) {
        gDPPipeSync(D_800D0510++);
        gSPSegment(D_800D0510++, 0xF, func_8004CA60((u8 *)func_8004C990(0x93, 0)));
        gDPSetEnvColor(D_800D0510++, 0x7F, 0x7F, 0x7F, 0xFF);
        gSPDisplayList(D_800D0510++, D_863070F0);
        GeoRender_ApplyMaterialState();
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_275E40/func_863005B8.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_275E40/func_863006F8.s")
#endif

#ifdef VERSION_US
u32 func_8003570C();
void func_863007B8(void *arg0) {
    (*(f32 *)((u8 *)(arg0) + (0x38))) = (f32) ((((f32) func_8003570C() / 4294967296.0f) - 0.5f) * 0.5f);
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_275E40/func_86300818.s")
#endif

#ifdef VERSION_US
extern u32 func_8003570C();
extern void * D_87F119DC;
void func_86300C74(s32 *arg0) {
    struct LocalRange {
        u8 pad00[0x10];
        f32 lower;
        f32 upper;
        u8 pad18[0x18];
        f32 target;
    } *p;

    p = *(struct LocalRange **)((u8 *)D_87F119DC + 0x20);
    if (*(u32 *)((u8 *)D_87F119DC + 0xC) & 0x80000000) {
        p->target = (func_8003570C() / 4294967296.0f) * (p->upper - p->lower) + p->lower;
        *(u32 *)((u8 *)D_87F119DC + 0xC) &= 0x7FFFFFFF;
    } else {
        *arg0 = p->target - *(f32 *)((u8 *)D_87F119DC + 0x48);
        if (((*arg0 > 0.0f) ? *arg0 : -*arg0) < 5.0f) {
            if ((func_8003570C() % 101) < 5) {
                *(u32 *)((u8 *)D_87F119DC + 0xC) |= 0x80000000;
            }
        } else if (*arg0 > 0.0f) {
            *arg0 = 0x10;
        } else {
            *arg0 = -0x10;
        }
    }
}
#endif

#ifdef VERSION_US
extern s32 func_86300818(f32 *, f32 *, f32 *, f32);
extern u32 func_8003570C(void);
void Fragment51_ComputeActorInput(s32 *arg0, s32 *arg1) {
    f32 scale;
    s32 i;
    f32 x;
    f32 y;
    f32 z;
    *arg0 = *arg1 = 0;
    scale = (*(f32 *)((u8 *)D_863075D8 + 0x8F3C));
    for (i = 0; i < (*(s32 *)((u8 *)D_863075D8 + 0xDB8)) - 1; i++) {
        scale *= (*(f32 *)((u8 *)D_863075D8 + 0x8F40));
    }
    if (func_86300818(&x, &y, &z, scale) != 0) {
        *arg0 = x - *(f32 *)((u8 *)D_87F119DC + 0x48);
        if ((func_8003570C() / 4294967296.0f) < (*(f32 *)((u8 *)D_863075D8 + 0x8F44))) {
            if (y < 42.0f) {
                *arg1 = 0x8000;
            }
        }
    } else {
        func_86300C74(arg0);
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_275E40/func_86300EF8.s")
#endif

#ifdef VERSION_US
extern void *D_87F119DC;
extern void MtxF_Copy(u32 *dest, u32 *src);
void func_86300FB4(void) {
    void *state = D_87F119DC;
    void *source = *(void **)((u8 *)state + 0x20);
    MtxF_Copy((u32 *)((u8 *)state + 0x84), (u32 *)((u8 *)source + 0x84));
}
#endif

#ifdef VERSION_US
extern void *func_87F025B8(void *, void (*)(void));
extern void func_8003F1DC(void *);
extern void func_8003F114(u8 *, s16, s16, void *);
extern s32 func_8003F210(void *, s32);
extern s32 ModelAnim_SetSpeed(u8 *, s32);
typedef struct { f32 x, y, z; } Fragment51ScaleVector;
void *Fragment51_CloneScaledActor(void *arg0) {
    u8 *node;
    node = func_87F025B8((u8 *)D_863075D8 + 0x770, func_86300FB4);
    if (node != NULL) {
        func_8003F1DC(node + 0x24);
        func_8003F210(node + 0x24, 2);
        ModelAnim_SetSpeed(node + 0x24, 0x20000);
        node[0x26] |= 0x10;
        *(void **)(node + 0x20) = arg0;
        MtxF_Copy((u32 *)(node + 0x84), (u32 *)((u8 *)arg0 + 0x84));
        *(Fragment51ScaleVector *)(node + 0x54) = *(Fragment51ScaleVector *)((u8 *)arg0 + 0x54);
        ((Fragment51ScaleVector *)(node + 0x54))->x *= 0.9f;
        ((Fragment51ScaleVector *)(node + 0x54))->y *= 0.9f;
    }
    return node;
}
#endif

#ifdef VERSION_US
typedef struct { u8 unk_00[224]; void *resources[4][2]; } Fragment51TransitionResources;
extern u8 D_8630745E;
extern u8 D_8630745F;
extern u8 D_86307458;
extern u8 D_86307459;
extern s32 ModelAnim_IsFinished(void *);
extern s32 ModelAnim_SetSpeed(u8 *, s32);
extern void func_8003F114(u8 *, s16, s16, void *);
extern void func_8003F1DC(void *);
extern s32 func_8003F210(void *, s32);
extern void * D_863075D8;
extern void * D_87F119DC;
void Fragment51_UpdatePlayerAnimations(void *arg0) {
    switch (*(s16 *)((u8 *)D_87F119DC + 0x64)) {
    case 0:
        if (ModelAnim_IsFinished((u8 *)D_87F119DC + 0x24)) {
            func_8003F1DC((u8 *)D_87F119DC + 0x24);
            func_8003F114((u8 *)D_87F119DC + 0x24, 0, -1, ((Fragment51TransitionResources *)D_863075D8)->resources[*(s32 *)arg0][D_8630745E]);
            func_8003F210((u8 *)D_87F119DC + 0x24, D_8630745F);
            func_8003F114((u8 *)*(void **)((u8 *)arg0 + 0x40) + 0x24, 0, -1, *(void **)((u8 *)D_863075D8 + 0x120));
            func_8003F210((u8 *)*(void **)((u8 *)arg0 + 0x40) + 0x24, 1);
        }
        break;
    case 1:
        if (ModelAnim_IsFinished((u8 *)D_87F119DC + 0x24)) {
            func_8003F1DC((u8 *)D_87F119DC + 0x24);
            func_8003F114((u8 *)D_87F119DC + 0x24, 0, -1, ((Fragment51TransitionResources *)D_863075D8)->resources[*(s32 *)arg0][D_86307458]);
            func_8003F210((u8 *)D_87F119DC + 0x24, D_86307459);
            ModelAnim_SetSpeed((u8 *)D_87F119DC + 0x24, 0x10000);
            func_8003F210((u8 *)*(void **)((u8 *)arg0 + 0x40) + 0x24, 2);
            ModelAnim_SetSpeed((u8 *)*(void **)((u8 *)arg0 + 0x40) + 0x24, 0x10000);
        }
        break;
    default:
        return;
    }
}
#endif

#ifdef VERSION_US
extern s32 Fragment51_CountTopScorers(s32 *);
extern s32 ModelAnim_IsFinished();
extern void ModelAnim_SetAnimation();
extern void func_8003F3BC();
extern u8 D_86307334[];
extern u8 D_86307460[];
extern u8 D_86307462[];
typedef struct Func86301250ResourceGrid { u8 pad[0xE0]; void *resources[4][2]; } Func86301250ResourceGrid;
typedef struct Func86301250ResourceRow { void *slots[2]; } Func86301250ResourceRow;
typedef struct Func86301250ResourceRows { u8 pad[0xE0]; Func86301250ResourceRow rows[4]; } Func86301250ResourceRows;
extern void * D_863075D8;
extern void * D_87F119DC;
void Fragment51_UpdateResultAnimations(void *arg0) {
    u8 *selection;
    s32 animation;
    s32 speed;
    s32 value;
    s32 winner_count;

    if ((*(s16 *)((u8 *)D_87F119DC + 0x64) == 0) ||
        ((*(s16 *)((u8 *)D_87F119DC + 0x64) == 1) && ModelAnim_IsFinished((void *)((u8 *)D_87F119DC + 0x24)))) {
        winner_count = Fragment51_CountTopScorers(&value);
        if ((winner_count < 4) && (value == ((s32 (*)[19])D_86307334)[*(s32 *)arg0][0])) {
            selection = D_86307460;
            animation = 3;
            speed = 0x40;
        } else {
            selection = D_86307462;
            animation = 4;
            speed = 0x28;
        }
        func_8003F1DC((void *)((u8 *)D_87F119DC + 0x24));
        func_8003F114((void *)((u8 *)D_87F119DC + 0x24), 0, -1,
                     ((Func86301250ResourceGrid *)D_863075D8)->resources[*(s32 *)arg0][selection[0]]);
        ModelAnim_SetAnimation((void *)((u8 *)D_87F119DC + 0x24), selection[1]);
        func_8003F3BC((void *)((u8 *)D_87F119DC + 0x24), 0);
        *(s16 *)((u8 *)*(void **)((u8 *)D_87F119DC + 0x68) + 6) = speed;
        ModelAnim_SetAnimation((void *)((u8 *)*(void **)((u8 *)arg0 + 0x40) + 0x24), animation);
        *(s16 *)((u8 *)*(void **)((u8 *)*(void **)((u8 *)arg0 + 0x40) + 0x68) + 6) = speed;
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_275E40/func_863013C8.s")
#endif

#ifdef VERSION_US
typedef struct { f32 r, g, b; } Fragment51EnvironmentColor;
extern void *D_8009491C;
extern Gfx D_86307020[];
void Fragment51_DrawTintedMaterial(s32 arg0, void *arg1) {
    u8 *scene_object;
    u8 *material;
    Fragment51EnvironmentColor color;
    if (arg0 == 5) {
        color.r = 255.0f;
        scene_object = D_8009491C;
        material = *(u8 **)(scene_object + 0x14);
        if (((*(u32 *)(material + 0xC)) & 0x40000000) != 0) {
            color.g = color.b = ((f32)(*(s32 *)(material + 0x1C)) / 31.0f) * 255.0f;
        } else {
            color.g = color.b = 255.0f;
        }
        gDPPipeSync(D_800D0510++);
        gDPSetEnvColor(D_800D0510++, color.r, color.g, color.b, 255);
        gSPDisplayList(D_800D0510++, D_86307020);
        GeoRender_ApplyMaterialState();
    }
}
#endif

#ifdef VERSION_US
typedef struct { f32 x, y, z; } Fragment51PlayerVector;
typedef struct {
    u8 unk_00[2];
    u8 flags;
    u8 unk_03[27];
    s16 rotation[3];
    Fragment51PlayerVector position;
    Fragment51PlayerVector scale;
    u8 unk_3C[300];
} Fragment51PlayerModel;
struct Fragment51PlayerActor {
    u8 unk_00[12];
    u32 flags;
    Fragment51PlayerVector unk_10;
    u8 unk_1C[4];
    Fragment51PlayerRecord *player;
    Fragment51PlayerModel model;
};
typedef struct {
    u8 unk_00[12];
    void *game_context;
    u8 unk_10[208];
    void *resources[4][2];
    u8 unk_100[0x8E24];
    f32 offset_scale;
} Fragment51PlayerSetupContext;
extern u8 D_8630745C;
extern u8 D_8630745D;
extern void func_863013C8(void);
extern void func_86300EF8(void *);
extern void func_80037E3C(void *, s32 (*)(s32, void *), void *);
extern void * Fragment51_CloneScaledActor(void *arg0);
extern s32 ModelAnim_SetSpeed(u8 *, s32);
extern u32 func_8003570C();
extern void func_8003F114(u8 *, s16, s16, void *);
extern void func_8003F1DC(void *);
extern s32 func_8003F210(void *, s32);
extern void * func_87F025B8(void *, void (*)(void));
extern void * D_863075D8;
void Fragment51_InitPlayerActor(s32 player_index) {
    Fragment51PlayerActor *actor;
    Fragment51PlayerRecord *player;
    f32 angle;
    f32 width;
    actor = func_87F025B8((u8 *)D_863075D8 + 0x12C, func_863013C8);
    if (actor != NULL) {
        player = actor->player;
        func_8003F1DC(&actor->model);
        func_8003F114((u8 *)&actor->model, 0, -1, ((Fragment51PlayerSetupContext *)D_863075D8)->resources[player_index][D_8630745C]);
        func_8003F210(&actor->model, D_8630745D);
        ModelAnim_SetSpeed((u8 *)&actor->model, 0x20000);
        func_80037E3C(&actor->model, NULL, actor);
        actor->model.position.x = -player->spawn_x * 220.0f;
        actor->model.position.y = -player->spawn_y * 220.0f;
        actor->model.position.z = 0.0f;
        angle = (player->angle_degrees / 360.0f) * 65535.0f;
        if (angle >= 0.0f) actor->model.rotation[2] = (s32)(angle + 0.5f);
        else actor->model.rotation[2] = (s32)(angle - 0.5f);
        actor->unk_10.x = actor->unk_10.y = actor->unk_10.z = 0.0f;
        actor->model.flags |= 0x10;
        actor->model.scale.x = actor->model.scale.y = actor->model.scale.z = 0.15f;
        func_86300EF8(actor);
        player->intercept = actor->model.position.y - player->slope * actor->model.position.x;
        width = ((((Fragment51PlayerSetupContext *)D_863075D8)->offset_scale + ((Fragment51PlayerSetupContext *)D_863075D8)->offset_scale) * 0.7071067691f - 120.0f) * 0.7071067691f * 0.5f;
        player->min_x = actor->model.position.x - width;
        player->max_x = actor->model.position.x + width;
        player->score = 0;
        player->position_x = actor->model.position.x;
        player->position_y = actor->model.position.y;
        player->unk_38 = func_8003570C() / 4294967296.0f - 0.5f;
        player->unk_34 = 0.5;
        player->companion = Fragment51_CloneScaledActor(actor);
        player->companion_x = player->companion->model.position.x;
        player->companion_y = player->companion->model.position.y;
        if (*(u8 *)((u8 *)((Fragment51PlayerSetupContext *)D_863075D8)->game_context + 0x2182) & (1 << player_index)) actor->flags |= 0x10000000;
        else actor->flags |= 0x20000000;
        actor->flags |= 0x80000000;
    }
}
#endif

#ifdef VERSION_US
extern void Fragment51_InitPlayerActor(s32);

void func_86301E14(void) {
    s32 var_s0;

    var_s0 = 0;
    do {
        Fragment51_InitPlayerActor(var_s0);
        var_s0 += 1;
    } while (var_s0 != 4);
}
#endif

#ifdef VERSION_US
extern void func_87F02684(void *);
extern void func_8630470C(void);
extern void func_86300494(void);
extern void * D_863075D8;
void func_86301E54(void) {
    typedef struct {
        u8 pad[0x8F24];
        f32 angle;
        s32 one;
        s32 zero;
        s32 copy;
        u8 pad2[0x18];
        s32 source;
    } State;

    func_87F02684((u8 *)D_863075D8 + 0xDB4);
    func_87F02684((u8 *)D_863075D8 + 0x12C);
    func_87F02684((u8 *)D_863075D8 + 0x770);
    func_87F02684((u8 *)D_863075D8 + 0x8298);
    func_87F02684((u8 *)D_863075D8 + 0x1F84);
    ((State *)D_863075D8)->angle = 180.0f;
    func_86300494();
    ((State *)D_863075D8)->zero = 0;
    ((State *)D_863075D8)->one = 1;
    ((State *)D_863075D8)->copy = ((State *)D_863075D8)->source;
    func_8630470C();
}
#endif

#ifdef VERSION_US
#include "color_adjustment.h"
typedef ColorAdjustment Fragment51InitTint;
typedef struct {
    u8 unk_00[32];
    void *user_data;
    u8 unk_24[360];
} Fragment51InitActor;
typedef struct {
    u8 bytes[36];
} Fragment51InitActorData;
typedef struct {
    u8 bytes[12];
} Fragment51InitConfig;
typedef struct {
    s32 state;
    u8 unk_04[4];
    void *scene;
    void *game_context;
    u8 unk_10[208];
    void *player_resources[4][2];
    void *models_100[5];
    void *models_114[3];
    void *model_120;
    void *graph_124;
    void *graph_128;
    u8 unk_12C[0x8DF4];
    s32 resource_8F20;
    u8 unk_8F24[48];
    s32 unk_8F54;
    u8 unk_8F58[132];
    u8 player_codes[4];
    s8 config_index;
} Fragment51InitContext;
extern u8 D_86306EA0[];
extern u8 D_86306F50[];
extern u8 D_86306F84[];
extern u8 D_863075C0[];
extern u8 D_86307428[];
extern s32 main_pool_get_available(void);
extern u8 *MainPool_AllocState(s32, s32);
extern void MainPool_FinalizeAllocation(void *);
extern void *process_geo_layout(void *, void *);
extern s32 func_8004DDF4(s32);
extern u8 *func_8004DF38(s32, s32, s32);
extern s32 WidgetTree_RunMessagePanelSilent(s32, s32);
extern void *func_8004DFEC(s32, s32, Fragment51InitTint);
extern Fragment51InitTint func_87F0AD50(s32, s32, s32);
extern void func_87F0C650(void *);
extern void func_87F0C694(void *, s32);
extern void func_87F01870(void *);
extern void func_87F01F34(void *);
extern void func_87F00030(void);
extern void ModelRenderer_InitDisplayRoots(void);
extern void *GeoNode_CreateContainer(void *, void *);
extern void func_87F024CC(void);
extern void func_87F024F4(void *, u8 *, s32);
extern void func_87F0252C(void *, void *, u8 *, s32);
extern void func_863005B8(void);
extern void func_863006F8(void);
extern s32 func_87F08E3C(void *, s32);
extern void func_87F0D48C(void *, void *, s32);
extern void func_863048D4(void);
extern void func_86303C00(void *);
extern void func_87F00688(void);
extern s32 func_8004C990(s32, s32);
extern void func_86300120(void);
extern void func_86301E14(void);
extern void func_86301E54(void);
extern void * D_863075D8;
void Fragment51_InitScene(void) {
    u8 *pool;
    s32 i;
    Fragment51PlayerRecord *player;
    Fragment51InitContext *context;
    Fragment51InitTint tint;
    func_87F0C650((u8 *)D_863075D8 + 0x38);
    if (*(u8 *)((u8 *)((Fragment51InitContext *)D_863075D8)->game_context + 0x2180) == 4) {
        func_87F0C694((u8 *)D_863075D8 + 0x38, 20);
    }
    func_8004DDF4(120);
    func_8004DDF4(141);
    func_8004DDF4(146);
    func_8004DDF4(154);
    pool = MainPool_AllocState(main_pool_get_available(), 0);
    ((Fragment51InitContext *)D_863075D8)->scene = process_geo_layout(pool, D_86306EA0);
    ((Fragment51InitContext *)D_863075D8)->models_114[0] = func_8004DF38((s32)pool, 120, 0);
    ((Fragment51InitContext *)D_863075D8)->models_114[1] = func_8004DF38((s32)pool, 120, 1);
    ((Fragment51InitContext *)D_863075D8)->models_114[2] = func_8004DF38((s32)pool, 120, 2);
    ((Fragment51InitContext *)D_863075D8)->models_100[0] = func_8004DF38((s32)pool, 154, 0);
    ((Fragment51InitContext *)D_863075D8)->models_100[1] = func_8004DF38((s32)pool, 120, 3);
    ((Fragment51InitContext *)D_863075D8)->models_100[2] = func_8004DF38((s32)pool, 120, 4);
    ((Fragment51InitContext *)D_863075D8)->models_100[3] = func_8004DF38((s32)pool, 120, 5);
    ((Fragment51InitContext *)D_863075D8)->models_100[4] = func_8004DF38((s32)pool, 120, 6);
    ((Fragment51InitContext *)D_863075D8)->model_120 = (void *)WidgetTree_RunMessagePanelSilent((s32)pool, 141);
    ((Fragment51InitContext *)D_863075D8)->graph_124 = process_geo_layout(pool, D_86306F50);
    ((Fragment51InitContext *)D_863075D8)->graph_128 = process_geo_layout(pool, D_86306F84);
    MainPool_FinalizeAllocation(pool);
    for (i = 0; i < 4; i++) {
        func_8004DDF4(218);
        pool = MainPool_AllocState(main_pool_get_available(), 0);
        tint = func_87F0AD50((s32)((Fragment51InitContext *)D_863075D8)->game_context, 4, i);
        ((Fragment51InitContext *)D_863075D8)->player_resources[i][0] = func_8004DFEC((s32)pool, 218, tint);
        MainPool_FinalizeAllocation(pool);
        func_8004DDF4(129);
        pool = MainPool_AllocState(main_pool_get_available(), 0);
        tint = func_87F0AD50((s32)((Fragment51InitContext *)D_863075D8)->game_context, 4, i);
        ((Fragment51InitContext *)D_863075D8)->player_resources[i][1] = func_8004DFEC((s32)pool, 129, tint);
        MainPool_FinalizeAllocation(pool);
    }
    func_87F01870(((Fragment51InitContext *)D_863075D8)->game_context);
    func_87F01F34(((Fragment51InitContext *)D_863075D8)->game_context);
    func_87F00030();
    ModelRenderer_InitDisplayRoots();
    GeoNode_CreateContainer(NULL, D_863075C0);
    func_87F024CC();
    func_87F024F4((u8 *)D_863075D8 + 0x1488, (u8 *)D_863075D8 + 0x149C, 4);
    func_863005B8();
    func_87F024F4((u8 *)D_863075D8 + 0x12C, (u8 *)D_863075D8 + 0x140, 4);
    for (i = 0, player = D_863072F8; player < D_863072F8 + 4; i++, player++) {
        ((Fragment51InitActor *)((u8 *)D_863075D8 + 0x140))[i].user_data = player;
    }
    func_87F024F4((u8 *)D_863075D8 + 0x770, (u8 *)D_863075D8 + 0x784, 4);
    func_87F0252C(D_863075C0, (u8 *)D_863075D8 + 0x1ACC, (u8 *)D_863075D8 + 0x1AE0, 3);
    func_863006F8();
    func_87F0252C(D_863075C0, (u8 *)D_863075D8 + 0x1F84, (u8 *)D_863075D8 + 0x1F98, 64);
    func_87F024F4((u8 *)D_863075D8 + 0xDB4, (u8 *)D_863075D8 + 0xDC8, 4);
    for (i = 0; i < 4; i++) {
        ((Fragment51InitActor *)((u8 *)D_863075D8 + 0xDC8))[i].user_data = &((Fragment51InitActorData *)((u8 *)D_863075D8 + 0x13F8))[i];
    }
    func_87F024F4((u8 *)D_863075D8 + 0x8298, (u8 *)D_863075D8 + 0x82AC, 4);
    ((Fragment51InitContext *)D_863075D8)->resource_8F20 = func_87F08E3C((void *)func_8004C990(151, 0), 0x0F000000);
    func_87F0D48C((u8 *)D_863075D8 + 0x10, ((Fragment51InitContext *)D_863075D8)->game_context, 0);
    func_863048D4();
    func_86300120();
    ((Fragment51InitContext *)D_863075D8)->unk_8F54 = 0;
    func_86303C00(&((Fragment51InitConfig *)D_86307428)[((Fragment51InitContext *)D_863075D8)->config_index]);
    for (i = 0; i < 4; i++) {
        context = (Fragment51InitContext *)D_863075D8;
        ((Fragment51InitContext *)D_863075D8)->player_codes[i] = (*(u8 *)((u8 *)context->game_context + 0x2182) & (1 << i) ? 6 : 2) + i;
    }
    func_86301E54();
    if (*(u8 *)((u8 *)((Fragment51InitContext *)D_863075D8)->game_context + 0x2180) == 4) {
        func_86301E14();
        ((Fragment51InitContext *)D_863075D8)->state = 3;
        func_87F00688();
    }
}
#endif

#ifdef VERSION_US
extern void func_87F0277C();
extern void * D_863075D8;
void func_86302404(void) {
    s32 i;

    for (i = 0; i != 3; i += 1) {
        func_87F0277C((u8 *)D_863075D8 + 0x12C);
        func_87F0277C((u8 *)D_863075D8 + 0xDB4);
        func_86305B44();
        func_87F0277C((u8 *)D_863075D8 + 0x8298);
        func_87F0277C((u8 *)D_863075D8 + 0x1F84);
    }
    func_87F0277C((u8 *)D_863075D8 + 0x770);
    func_87F0277C((u8 *)D_863075D8 + 0x1488);
}
#endif

#ifdef VERSION_US
typedef struct {
    u8 unk_0000[0x8F2C];
    s32 result_frame;
} Fragment51ResultFrameContext;

extern Fragment51PlayerRecord D_863072F8[4];
extern void func_87F0C930(void *);
extern void func_87F0A098(void *, void *, s32, s32, s32, s32, s32);
extern s32 func_87F0A3E8(void *);
void Fragment51_UpdateResults(void) {
    s32 top_score;
    ((Fragment51ResultFrameContext *)D_863075D8)->result_frame = ((Fragment51ResultFrameContext *)D_863075D8)->result_frame + 1;
    if (((Fragment51ResultFrameContext *)D_863075D8)->result_frame == 8) {
        if (Fragment51_CountTopScorers(&top_score) < 4) {
            if ((*(u8 *)((u8 *)*(void **)((u8 *)D_863075D8 + 12) + 0x2180)) == 4) {
                func_87F0C930((u8 *)D_863075D8 + 0x38);
            } else {
                func_87F0A098((u8 *)D_863075D8 + 0x7C, *(void **)((u8 *)D_863075D8 + 12), 4,
                              top_score == ((Fragment51PlayerRecord *)D_863072F8)[0].score,
                              top_score == ((Fragment51PlayerRecord *)D_863072F8)[1].score,
                              top_score == ((Fragment51PlayerRecord *)D_863072F8)[2].score,
                              top_score == ((Fragment51PlayerRecord *)D_863072F8)[3].score);
            }
        } else {
            if ((*(u8 *)((u8 *)*(void **)((u8 *)D_863075D8 + 12) + 0x2180)) == 4) {
                func_87F0C930((u8 *)D_863075D8 + 0x38);
            } else {
                func_87F0A098((u8 *)D_863075D8 + 0x7C, *(void **)((u8 *)D_863075D8 + 12), 4, 0, 0, 0, 0);
            }
        }
    }
    if (func_87F0A3E8((u8 *)D_863075D8 + 0x7C) != 0) {
        if ((*(u8 *)((u8 *)*(void **)((u8 *)D_863075D8 + 12) + 0x2180)) == 1) {
            func_86300020(2);
        } else {
            *(s32 *)D_863075D8 = 6;
        }
    }
    func_86302404();
}
#endif

#ifdef VERSION_US
extern void func_87F06240(s32, s32, f32, f32, s32);
void func_86302634(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 x;
    s32 y;

    if (arg0 < 10) {
        x = arg1 + arg3;
        y = arg2 + arg4;
        func_87F06240(x, y, 0.57f, 0.57f, arg0 % 10);
    } else {
        x = arg1 + arg5;
        y = arg2 + arg6;
        func_87F06240(x, y, 0.57f, 0.57f, arg0 / 10);
        func_87F06240(x + 13, y, 0.57f, 0.57f, arg0 % 10);
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/51/fragment51_275E40/func_8630271C.s")
#endif

#ifdef VERSION_US
extern void func_800088DC(void);
extern void GfxImage_FillCurrent(void *, u16);
extern void func_8000766C(Gfx **, s32, s32, s32, s32);
extern void GeoRender_AdvanceFrameCounter(void);
extern void func_8003C6B8(void *);
extern void func_8630271C(void);
extern void func_87F0A5BC(void *);
extern void func_87F07FE8(void *);
extern void func_87F022F0(void);
extern void func_87F01D44(void);
extern void func_87F0C88C(void *);
extern s32 func_80008648(void);
extern u32 func_87F00930(void);
void Fragment51_DrawSceneFrame(void) {
    func_800088DC();
    GfxImage_FillCurrent(&D_800D0510, 0xA655);
    func_8000766C(&D_800D0510, 0, 0, 320, 240);
    if (func_87F00930() == 0) {
        GeoRender_AdvanceFrameCounter();
    }
    func_8003C6B8(*(void **)((u8 *)D_863075D8 + 8));
    if (*(s32 *)D_863075D8 == 5) {
        func_8630271C();
        if ((*(s32 *)((u8 *)D_863075D8 + 0x8F2C)) >= 8) {
            func_87F0A5BC((u8 *)D_863075D8 + 0x7C);
        }
    } else {
        if (((*(s32 *)((u8 *)D_863075D8 + 0x8F54)) & 1) == 0) {
            func_8630271C();
        }
    }
    if (((*(s32 *)((u8 *)D_863075D8 + 0x8F54)) & 1) != 0) {
        func_87F07FE8((u8 *)D_863075D8 + 0x44);
    }
    if (((*(s32 *)((u8 *)D_863075D8 + 0x8F54)) & 2) != 0) {
        func_87F022F0();
    }
    if (func_87F00930() == 1) {
        func_87F01D44();
    }
    func_87F0C88C((u8 *)D_863075D8 + 0x38);
    func_80008648();
}
#endif

#ifdef VERSION_US
extern void *D_863075D8;
extern void func_863048A8(void);
extern s32 func_87F08208(void *);
extern void StageContext_SetClearColor(s32);
extern void StageFade_StartFromTransparent(s32);
extern void func_800225C4(s32);
extern void Audio_PlayDefaultSound(s32);
extern void func_86300020(s32);
extern void func_800226C0(s32);
void func_86303110(void) {
    s32 temp_v0;

    func_863048A8();
    temp_v0 = func_87F08208((u8 *)D_863075D8 + 0x44);
    switch (temp_v0) {
    case 1:
        StageContext_SetClearColor(0xFFFF);
        StageFade_StartFromTransparent(0x14);
        *(s32 *)D_863075D8 = 2;
        func_800225C4(0x28);
        Audio_PlayDefaultSound(0xCF0B);
        break;
    case 2:
        func_86300020(0);
        func_800226C0(3);
        break;
    }
}
#endif

#ifdef VERSION_US
typedef struct {
    u8 unk_0000[0xDB8];
    s32 actor_count;
    u8 unk_0DBC[0x816C];
    s32 desired_count;
    s32 elapsed_frames;
    s32 remaining_frames;
} Fragment51SpawnContext;
extern void func_86306D3C(void);
extern s32 func_80001FF0(void);
extern void * D_863075D8;
void Fragment51_UpdateSpawnCount(void) {
    if (((Fragment51SpawnContext *)D_863075D8)->remaining_frames > 0) {
        ((Fragment51SpawnContext *)D_863075D8)->elapsed_frames += 1;
        if ((func_80001FF0() >> 1) * 3 < ((Fragment51SpawnContext *)D_863075D8)->elapsed_frames) {
            ((Fragment51SpawnContext *)D_863075D8)->desired_count += 1;
            if (((Fragment51SpawnContext *)D_863075D8)->desired_count >= 4) {
                ((Fragment51SpawnContext *)D_863075D8)->desired_count = 3;
            }
            ((Fragment51SpawnContext *)D_863075D8)->elapsed_frames = 0;
        }
        if (((Fragment51SpawnContext *)D_863075D8)->actor_count < ((Fragment51SpawnContext *)D_863075D8)->desired_count) {
            func_86306D3C();
        }
    }
}
#endif

#ifdef VERSION_US
extern s32 func_80001FF0(void);
extern void func_800279C4(u16);
typedef struct {
    s32 state;
    u8 unk_0004[0x8F28];
    s32 result_frame;
    s32 remaining_frames;
    u8 unk_8F34[20];
    s32 score_limit;
    u8 unk_8F4C[4];
    u8 rule_mode;
} Fragment51ProgressContext;
extern Fragment51PlayerRecord D_863072F8[4];
extern void * D_863075D8;
void Fragment51_UpdateRoundProgress(void) {
    Fragment51PlayerRecord *score_record;
    s32 i;
    s32 j;
    s32 count;
    score_record = (Fragment51PlayerRecord *)D_863072F8;
    switch (((Fragment51ProgressContext *)D_863075D8)->rule_mode) {
    case 0:
        for (i = 0; i < 4; i++, score_record++) {
            if (((Fragment51ProgressContext *)D_863075D8)->score_limit < score_record->score) {
                ((Fragment51ProgressContext *)D_863075D8)->result_frame = 0;
                ((Fragment51ProgressContext *)D_863075D8)->state = 5;
            }
        }
        break;
    case 1:
    case 2:
        ((Fragment51ProgressContext *)D_863075D8)->remaining_frames -= 1;
        if (((Fragment51ProgressContext *)D_863075D8)->remaining_frames < 0) {
            ((Fragment51ProgressContext *)D_863075D8)->remaining_frames = 0;
            ((Fragment51ProgressContext *)D_863075D8)->result_frame = 0;
            ((Fragment51ProgressContext *)D_863075D8)->state = 5;
        }
        for (j = 0; j < 4; j++, score_record++) {
            if (score_record->score >= ((Fragment51ProgressContext *)D_863075D8)->score_limit) {
                ((Fragment51ProgressContext *)D_863075D8)->result_frame = 0;
                ((Fragment51ProgressContext *)D_863075D8)->state = 5;
            }
        }
        if (((Fragment51ProgressContext *)D_863075D8)->remaining_frames % (func_80001FF0() >> 1) + 1 == (func_80001FF0() >> 1)) {
            count = (((Fragment51ProgressContext *)D_863075D8)->remaining_frames + (func_80001FF0() >> 1) - 1) / (func_80001FF0() >> 1);
            if (count == 0) func_800279C4(0xCF06);
            else if (count < 4) func_800279C4(0xCF00);
        }
        break;
    }
}
#endif

#ifdef VERSION_US
extern void func_86302404();
extern void Fragment51_UpdateSpawnCount();
extern void Fragment51_UpdateRoundProgress();
extern s32 D_863072E8;
s32 func_80001FF0(void);
void func_80028118(u8 arg0);
void func_8630352C(void) {
    if ((*(s32 *)((u8 *)(D_863075D8) + (0x8F30))) < ((func_80001FF0() >> 1) * 0x1E)) {
        func_80028118(6U);
    }
    Fragment51_UpdateSpawnCount();
    func_86302404();
    Fragment51_UpdateRoundProgress();
    if (D_863072E8 != 4) {
loop_3:
        goto loop_3;
    }
}
#endif

#ifdef VERSION_US
extern void *D_863075D8;
extern void func_863048A8(void);
extern s32 StageContext_GetFadeMode(void);
extern void func_8630487C(void);
extern void func_86301E14(void);
extern void StageFade_StartFromOpaque(s32);
extern void func_87F00688(void);
void func_863035B0(void) {
    func_863048A8();
    if (StageContext_GetFadeMode() == 1) {
        func_8630487C();
        func_86301E14();
        StageFade_StartFromOpaque(0x14);
        *(s32 *)D_863075D8 = 3;
        func_87F00688();
    }
}
#endif

#ifdef VERSION_US
extern s32 func_87F01A40(void);
extern u32 func_87F006AC(void);
extern void func_80021ED8(s32);
extern void func_87F0277C();
extern void Audio_PlayDefaultSound(s32);
extern void func_86300020(s32 arg0);
void func_86303610(void) {
    s32 state;

    if (StageContext_GetFadeMode() == 0) {
        state = func_87F01A40();
    } else {
        state = 2;
    }
    switch (state) {
    case 0:
    case 2:
        if (func_87F006AC() == 1) {
            Audio_PlayDefaultSound(0x2F00);
        }
        if (func_87F006AC() == 2) {
            *(s32 *)D_863075D8 = 4;
            Audio_PlayDefaultSound(0x2F01);
            func_80021ED8(0x23);
        }
        break;
    case 3:
        func_86300020(0);
        break;
    case 4:
        func_86300020(1);
        break;
    }
    func_87F0277C((u8 *)D_863075D8 + 0x12C);
    func_87F0277C((u8 *)D_863075D8 + 0x770);
}
#endif

#ifdef VERSION_US
extern void func_87C037C0(void *, void *);
extern u32 func_87F00930(void);
extern void *func_87F006BC(void);
extern s32 func_87F02104(void);
extern void Fragment51_UpdateResults(void);
extern void func_87F0D5B8(void *);
extern s32 func_87F0C6F4(void *);
void Fragment51_UpdateState(void) {
    func_87C037C0((u8 *)D_863075D8 + 0x8F5C, *(void **)((u8 *)*(void **)((u8 *)D_863075D8 + 8) + 12));
    if (func_87F00930() == 0) {
        func_87F006BC();
    }
    switch ((*(s32 *)((u8 *)D_863075D8 + 0))) {
    case 0:
        (*(s32 *)((u8 *)D_863075D8 + 0x8F54)) = 1;
        if (StageContext_GetFadeMode() == 0) {
            (*(s32 *)((u8 *)D_863075D8 + 0)) = 1;
        }
        break;
    case 1:
        func_86303110();
        break;
    case 2:
        func_863035B0();
        break;
    case 3:
        (*(s32 *)((u8 *)D_863075D8 + 0x8F54)) = 0;
        func_86303610();
        break;
    case 4:
        switch (func_87F01A40()) {
        case 0:
        case 2:
            func_8630352C();
            break;
        case 3:
            func_86300020(0);
            break;
        case 4:
            func_86300020(1);
            break;
        }
        break;
    case 5:
        Fragment51_UpdateResults();
        break;
    case 6:
        (*(s32 *)((u8 *)D_863075D8 + 0x8F54)) = 2;
        switch (func_87F02104()) {
        case 1:
            StageContext_SetClearColor(0);
            (*(s32 *)((u8 *)D_863075D8 + 0)) = 7;
            (*(s32 *)((u8 *)D_863075D8 + 4)) = 0;
            StageFade_StartFromTransparent(10);
            break;
        case 2:
            func_86300020(0);
            break;
        case 3:
            func_86300020(1);
            break;
        }
        break;
    case 7:
        if (StageContext_GetFadeMode() == 1) {
            (*(s32 *)((u8 *)D_863075D8 + 0)) = (*(s32 *)((u8 *)D_863075D8 + 4));
            if ((*(s32 *)((u8 *)D_863075D8 + 0)) == 0) {
                func_86301E54();
                StageFade_StartFromOpaque(10);
            }
        }
        break;
    }
    func_87F0D5B8((u8 *)D_863075D8 + 0x10);
    if (func_87F0C6F4((u8 *)D_863075D8 + 0x38) != 0) {
        (*(s32 *)((u8 *)D_863075D8 + 0x8F58)) = 3;
        (*(s32 *)((u8 *)D_863075D8 + 0)) = 8;
    }
}
#endif

#ifdef VERSION_US
extern void *D_863075D8;
extern void func_800086A4(s32);
extern void StageFade_StartFromOpaque(s32);
extern void func_80064D28(void);
extern void Fragment51_UpdateState(void);
extern void Fragment51_DrawSceneFrame(void);
void func_86303974(void) {
    func_800086A4(2);
    StageFade_StartFromOpaque(0xA);
    do {
        func_80064D28();
        Fragment51_UpdateState();
        Fragment51_DrawSceneFrame();
    } while (*(s32 *)D_863075D8 != 8);
}
#endif

#ifdef VERSION_US
typedef struct { u8 unk_00[40]; } Fragment51ControllerRecord;
extern u8 D_863075E0[];
extern u8 D_1000000[];
extern u8 D_446E30[];
extern u8 D_447D00[];
extern Fragment51ControllerRecord D_800CE060[];
extern u8 D_800CE100[];
extern s32 main_pool_push_state(s32);
extern s32 main_pool_pop_state(s32);
extern void func_80027EE0(u16);
extern void Gfx_InitDisplayListBuffers(s32, s32);
extern void Gfx_FreeDisplayListBuffers(void);
extern s32 func_800082E0(s32, s32, s32, s32, s32, s32);
extern s32 func_8004C09C(s32);
extern s32 func_8004C8C0(u16);
extern void func_87F09EBC(void *, void *);
extern void func_87F06EAC(s32, void *, void *);
extern void func_87F061D0(void);
extern u8 *func_80047588(s32, s32);
extern u8 *Asset_LoadToSegment(s32, u8 *, u8 *, s32);
extern void func_80006148(u8 *);
extern void func_80006158(void);
extern void func_80008514(s32);
extern void func_80008574(void);
extern void func_80047610(void);
extern void func_8004C398(void);
extern s32 func_87F0F480(void *);
extern void func_86303974(void);
extern void * D_863075D8;
s32 Fragment51_Run(s32 arg0, void *arg1) {
    s32 display;
    Fragment51ControllerRecord *controller;
    Fragment51ControllerRecord *controllers_end;
    main_pool_push_state(0x4D59524D);
    D_863075D8 = D_863075E0;
    *(void **)((u8 *)D_863075D8 + 12) = arg1;
    if (*(u8 *)((u8 *)*(void **)((u8 *)D_863075D8 + 12) + 0x2182) == 15) {
        *(s8 *)((u8 *)D_863075D8 + 0x8FE0) = 1;
    } else {
        *(s8 *)((u8 *)D_863075D8 + 0x8FE0) = *(s8 *)((u8 *)*(void **)((u8 *)D_863075D8 + 12) + 0x2181);
    }
    if (*(u8 *)((u8 *)*(void **)((u8 *)D_863075D8 + 12) + 0x2180) == 4) func_80027EE0(0xFFF);
    Gfx_InitDisplayListBuffers(0x20000, 0);
    display = func_800082E0(0, 0, 2, 1, 2, 1);
    func_8004C09C(291);
    func_87F09EBC((u8 *)D_863075D8 + 0x7C, *(void **)((u8 *)D_863075D8 + 12));
    func_87F06EAC(153, (u8 *)D_863075D8 + 0x44, *(void **)((u8 *)D_863075D8 + 12));
    func_8004C8C0(260);
    func_8004C8C0(147);
    func_8004C8C0(307);
    func_8004C8C0(151);
    func_8004C8C0(434);
    func_8004C8C0(415);
    func_87F061D0();
    func_80047588(*(s32 *)((u8 *)D_863075D8 + 0x4C) | 8, 0);
    Asset_LoadToSegment(((u32)D_1000000 & 0x0F000000) >> 24, D_446E30, D_447D00, 0);
    controller = D_800CE060; controllers_end = (Fragment51ControllerRecord *)D_800CE100;
    do {
        func_80006148((u8 *)controller);
        controller++;
    } while (controller != controllers_end);
    Fragment51_InitScene();
    func_80008514(display);
    func_86303974();
    func_80008574();
    func_80006158();
    func_80047610();
    func_8004C398();
    Gfx_FreeDisplayListBuffers();
    main_pool_pop_state(0x4D59524D);
    func_87F0F480(*(void **)((u8 *)D_863075D8 + 12));
    func_80027EE0(0xFFE);
    return *(s32 *)((u8 *)D_863075D8 + 0x8F58);
}
// Preserve the two alignment words after the fragment entrypoint.
#pragma C_FUNCTION_PADDING(8)
#endif
