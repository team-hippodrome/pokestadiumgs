#include "global.h"
#include "color_adjustment.h"


#ifdef VERSION_US
extern void func_80038E14(s32, s32, s32, s32, f32, f32, f32, s32);
extern u8 D_87E1EC10;
s32 func_87E136F0(s32 arg0, s32 arg1) {
    func_80038E14(arg1, (*(s32 *)((u8 *)(&D_87E1EC10) + (0))), (*(s32 *)((u8 *)(&D_87E1EC10) + (4))), (*(s32 *)((u8 *)(&D_87E1EC10) + (8))), (*(f32 *)((u8 *)(&D_87E1EC10) + (0xC))), (*(f32 *)((u8 *)(&D_87E1EC10) + (0x10))), (*(f32 *)((u8 *)(&D_87E1EC10) + (0x14))), 0);
    return 1;
}

extern void *D_87F119DC;
void func_87E1374C(void) {
    s32 *state_ptr;
    s32 state;

    state_ptr = *(s32 **)((u8 *)D_87F119DC + 0x38);
    state = *state_ptr;
    switch (state) {
    case 1:
        *(f32 *)((u8 *)D_87F119DC + 0x18) -= 2.5f;
        *(f32 *)((u8 *)D_87F119DC + 0x50) += *(f32 *)((u8 *)D_87F119DC + 0x18);
        if (*(f32 *)((u8 *)D_87F119DC + 0x50) < 0.0f) {
            *(f32 *)((u8 *)D_87F119DC + 0x50) = 0.0f;
            *(f32 *)((u8 *)D_87F119DC + 0x18) *= -0.2f;
            return;
        }
        break;
    case 0:
        return;
    case 2:
        *(f32 *)((u8 *)D_87F119DC + 0x14) += 5.5f;
        *(f32 *)((u8 *)D_87F119DC + 0x4C) += *(f32 *)((u8 *)D_87F119DC + 0x14);
        if (*(f32 *)((u8 *)D_87F119DC + 0x4C) > 360.0f) {
            *(u8 *)((u8 *)D_87F119DC + 0x25) &= 0xFFFE;
            *state_ptr = 0;
        }
        break;
    }
}

extern Gfx *D_800D0510;
extern void *D_8009491C;
extern s32 func_8004C990(s32, s32);
extern u8 *func_8004CA60(u8 *);
extern void GeoRender_ApplyMaterialState(void);
void func_87E13848(s32 arg0, s32 arg1) {
    u8 *context;
    void *temp_v0;
    if (arg0 == 5) {
        context = (u8 *)D_8009491C;
        temp_v0 = *(void **)(context + 0x14);
        gDPPipeSync(D_800D0510++);
        gDPSetCombine(D_800D0510++, 0xFFFFFF, 0xFFFCF238);
        gSPSegment(D_800D0510++, 0xF,
                   func_8004CA60((u8 *)func_8004C990(0x166, 0)));
        gSPDisplayList(D_800D0510++, *(void **)((u8 *)temp_v0 + 4));
        GeoRender_ApplyMaterialState();
    }
}

void func_87E13924(void *arg0, s32 arg1) {
    f32 v;

    switch (*(s32 *)((u8 *)arg1 + 0x164)) {
    case 0:
    case 5:
        ((u8 *)arg0)[0x41] = 0;
        *(s32 *)((u8 *)arg0 + 0xC4) = 0xFF;
        break;
    case 1:
        v = *(f32 *)((u8 *)arg1 + 0x16C) - 0.3f;
        if (v < 0.0f) {
            v = 0.0f;
        }
        ((u8 *)arg0)[0x41] = 255.0f * v * 1.4285715f;
        *(s32 *)((u8 *)arg0 + 0xC4) = 0;
        ((u8 *)arg0)[0xC7] = (1.0f - *(f32 *)((u8 *)arg1 + 0x16C)) * 255.0f;
        break;
    case 2:
        ((u8 *)arg0)[0x41] = *(f32 *)((u8 *)arg1 + 0x16C) * 255.0f;
        *(s32 *)((u8 *)arg0 + 0xC4) = 0;
        break;
    case 3:
    case 4:
        v = (1.0f - *(f32 *)((u8 *)arg1 + 0x16C) * 2.5f) * 255.0f;
        if (v < 0.0f) {
            v = 0.0f;
        }
        ((u8 *)arg0)[0x41] = (v >= 0.0f) ? (s32)(v + 0.5f) : (s32)(v - 0.5f);
        *(s32 *)((u8 *)arg0 + 0xC4) = 0;
        ((u8 *)arg0)[0xC7] = *(f32 *)((u8 *)arg1 + 0x16C) * 255.0f;
        break;
    }
}

extern void *func_87F025B8(void *, void *);
extern void func_8003F1DC(void *);
extern void func_8003F114(void *, s32, s32, s32);
extern void func_87E1374C(void);
void *func_87E13C94(u8 *arg0) {
    u8 *obj;
    s32 *node;

    obj = func_87F025B8(arg0 + 4, func_87E1374C);
    if (obj != NULL) {
        node = (s32 *)(obj + 0x24);
        func_8003F1DC(node);
        func_8003F114(node, 0, -1, *(s32 *)(arg0 + 0x54));
        node = *(s32 **)(obj + 0x38);
        obj[0x25] &= 0xFFFE;
        node[0] = 0;
        node[1] = *(s32 *)(arg0 + 0x44);
    }
    return obj;
}

extern Gfx *D_800D0510;
extern void *D_8009491C;
extern void GeoRender_ApplyMaterialState(void);
typedef struct {
    u8 pad_1d[0x1D];
    u8 alpha;
    u8 pad_3c[0x1E];
    u8 red;
    u8 green;
    u8 blue;
} Func87E13D18Context;
void func_87E13D18(s32 arg0, s32 arg1) {
    Func87E13D18Context *context;
    void *temp_v0;
    if (arg0 == 5) {
        context = (Func87E13D18Context *)D_8009491C;
        temp_v0 = *(void **)((u8 *)context + 0x14);
        gDPPipeSync(D_800D0510++);
        gSPClearGeometryMode(D_800D0510++, 0x400);
        gDPSetCombine(D_800D0510++, 0x42FFFF, -0x5C8);
        gDPSetEnvColor(D_800D0510++, context->red, context->green,
                       context->blue, context->alpha);
        gSPDisplayList(D_800D0510++, *(void **)((u8 *)temp_v0 + 4));
        GeoRender_ApplyMaterialState();
    }
}

extern f32 D_80087E50[];
extern u32 func_8003570C(void);
extern void func_87E13924(void *, s32);
extern void * D_87F119DC;
void func_87E13E04(void) {
    if (!(*(u32 *)((u8 *)D_87F119DC + 0xC) & 0x10000000)) {
        func_87E13924(D_87F119DC, *(s32 *)((u8 *)D_87F119DC + 0x20));
    }
    *(s16 *)((u8 *)D_87F119DC + 0x42) += func_8003570C() & 0xFFF;
    *(s16 *)((u8 *)D_87F119DC + 0x44) += func_8003570C() & 0xFFF;
    *(f32 *)((u8 *)D_87F119DC + 0x48) += *(f32 *)((u8 *)D_87F119DC + 0x10) + *(f32 *)((u8 *)D_87F119DC + 0x18) * D_80087E50[(u16)((*(u32 *)((u8 *)D_87F119DC + 0x1C) % 360U) * 0x2FF) >> 4];
    *(f32 *)((u8 *)D_87F119DC + 0x4C) += *(f32 *)((u8 *)D_87F119DC + 0x14);
    if (*(f32 *)((u8 *)D_87F119DC + 0x4C) < -200.0f) {
        *(f32 *)((u8 *)D_87F119DC + 0x4C) = 200.0f;
    }
    if (*(f32 *)((u8 *)D_87F119DC + 0x48) > 200.0f) {
        *(f32 *)((u8 *)D_87F119DC + 0x48) += -400.0f;
    }
    if (*(f32 *)((u8 *)D_87F119DC + 0x48) < -200.0f) {
        *(f32 *)((u8 *)D_87F119DC + 0x48) += 400.0f;
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_317060/func_87E13F84.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_317060/func_87E1425C.s")

extern void func_87E13924(void *, s32);
extern void *D_87F119DC;

void func_87E14458(void) {
    func_87E13924(D_87F119DC, (*(s32 *)((u8 *)(D_87F119DC) + (0x20))));
}

typedef struct {
    u8 *mon;
    ColorAdjustment adjustment;
} Fragment63MonSlot;
extern u16 Pokemon_GetDisplaySpecies(u8 *);
extern ColorAdjustment func_8003F5AC(u8 *);
extern s32 func_8006456C(s32);
extern void func_80041FA0(u8 *, u16, ColorAdjustment);
extern s32 func_80041FD0(u8 *, u16, ColorAdjustment, s32);
extern void func_800428F8(u8 *);
extern void func_8003F2C4(u8 *, u8 *, s32);
extern void func_8003F3BC(void *, s32);
extern void func_8003F114(void *, s32, s32, s32);
void func_87E14480(u8 *resource, Fragment63MonSlot *slot, u8 *model, s32 arg3, s32 arg4) {
    u8 *mon = slot->mon + 4;
    u16 species;

    if (mon == NULL) {
        return;
    }
    if (*(s8 *)slot->mon == 0) {
        func_80041FA0(resource, Pokemon_GetDisplaySpecies(mon), slot->adjustment);
    } else {
        species = Pokemon_GetDisplaySpecies(mon);
        func_80041FD0(resource, species, func_8003F5AC(mon), func_8006456C(*(u16 *)(mon + 0x16)));
    }
    func_800428F8(resource);
    func_8003F114(model, 0, 0, **(s32 **)(*(u8 **)(resource + 0x38) + 8));
    func_8003F2C4(resource, model, arg3);
    func_8003F3BC(model, arg4);
    model[0x1D] = 0;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_317060/func_87E14578.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_317060/func_87E146DC.s")

extern s32 ModelAnim_IsFinished(void *);
extern void ModelAnim_SetFrame(void *, s32);
extern void ModelAnim_SetResourceAnimation(s32, void *, s32);
extern void func_8003F3BC(void *, s32);
extern void * D_87F119DC;
void func_87E14898(void *arg0) {
    s32 anim;
    u8 *entry;

    if (ModelAnim_IsFinished((u8 *)D_87F119DC + 0x24) != 0) {
        if ((((u32 (*)[3])(*(u8 **)((u8 *)arg0 + 4) + 0x90))[*(s32 *)((u8 *)arg0 + 8)][0] >> 31) != 0) {
            entry = *(u8 **)((u8 *)arg0 + 0xC);
            anim = *(s32 *)(entry + 4);
            if (anim == *(s16 *)((u8 *)D_87F119DC + 0x64)) {
                ModelAnim_SetResourceAnimation(*(s32 *)arg0, (u8 *)D_87F119DC + 0x24, *(s32 *)(entry + 0x10));
                func_8003F3BC((u8 *)D_87F119DC + 0x24, -1);
                func_8003F3BC((u8 *)D_87F119DC + 0x24, *(s32 *)(*(u8 **)((u8 *)arg0 + 0xC) + 0x14));
                return;
            }
            ModelAnim_SetResourceAnimation(*(s32 *)arg0, (u8 *)D_87F119DC + 0x24, anim);
            return;
        }
        ModelAnim_SetFrame((u8 *)D_87F119DC + 0x24, 0);
    }
}

extern s32 ModelAnim_IsEventTrackDone(u8 *);
extern u32 func_8003570C(void);
extern void ModelAnim_SetEventTrack(u8 *, s32);
void func_87E14984(void *arg0) {
    s32 sp1C;
    s32 sp18;
    void *temp_v0;
    u8 *global;

    global = (u8 *)D_87F119DC;
    temp_v0 = *(void **)((u8 *)arg0 + 0xC);
    if (*(s32 *)((u8 *)temp_v0 + 4) == *(s16 *)(global + 0x64)) {
        sp1C = *(s32 *)((u8 *)temp_v0 + 0xC);
        sp18 = *(s32 *)((u8 *)temp_v0 + 8);
    } else {
        sp1C = *(s32 *)((u8 *)temp_v0 + 0x18);
        sp18 = *(s32 *)((u8 *)temp_v0 + 0x14);
    }
    if (ModelAnim_IsEventTrackDone(global + 0x24) != 0) {
        if (sp1C != 0) {
            if ((func_8003570C() % 31U) < 2U) {
                ModelAnim_SetEventTrack((u8 *)D_87F119DC + 0x24, -1);
                ModelAnim_SetEventTrack((u8 *)D_87F119DC + 0x24, sp18);
            }
        } else {
            ModelAnim_SetEventTrack((u8 *)D_87F119DC + 0x24, -1);
            ModelAnim_SetEventTrack((u8 *)D_87F119DC + 0x24, sp18);
        }
    }
}

/* mkdraft:func_87E14A60 begin */
extern void * D_87F119DC;
extern void func_87E146DC(void *, s32, s32);



void func_87E14A60(void) {
    void *ptr;
    void *sub;
    ptr = *((void **) (((u8 *) D_87F119DC) + 0x20));
    // FAKE: the zero product keeps the child pointer, loaded from ptr + 4, in $a1 for
    // the 0x164 test; comparing against a plain 0 loads it into $v0 instead and copies
    // it with an extra move (diff score 340). The product is zero for every pointer.
    if ((*((s32 *) (((u8 *) (*((void **) (((u8 *) ptr) + 4)))) + 0x164))) == (((s32) (*((void **) (((u8 *) ptr) + 4)))) * 0)) {
        if (!((*((s32 *) (((u8 *) D_87F119DC) + 0xC))) & 0x10000000)) {
            func_87E146DC(((u8 *) D_87F119DC), (s32) ptr, 1);
            sub = *((void **) (((u8 *) (*((void **) (((u8 *) ptr) + 4)))) + 0x40));
            if (sub != NULL) {
                *((f32 *) (((u8 *) D_87F119DC) + 0x48)) += *(((f32 *) sub) + 0x34);
                *((f32 *) (((u8 *) D_87F119DC) + 0x4C)) += *((f32 *) (((u8 *) (*((void **) (((u8 *) (*((void **) (((u8 *) ptr) + 4)))) + 0x40)))) + 0xD4));
                *((f32 *) (((u8 *) D_87F119DC) + 0x50)) += *((f32 *) (((u8 *) (*((void **) (((u8 *) (*((void **) (((u8 *) ptr) + 4)))) + 0x40)))) + 0xD8));
            }
            *((u32 *) (((u8 *) D_87F119DC) + 0xC)) |= 0x10000000;
        }
    } else {
        *((u32 *) (((u8 *) D_87F119DC) + 0xC)) &= ~0x10000000;
    }
    func_87E13924(((u8 *) D_87F119DC), (s32) (*((void **) (((u8 *) ptr) + 4))));
    if ((*((u8 *) (((u8 *) D_87F119DC) + 0x41))) == 0) {
        *((u8 *) (((u8 *) D_87F119DC) + 0x25)) = (*((u8 *) (((u8 *) D_87F119DC) + 0x25)) & 0xFFFE);
    } else {
        *((u8 *) (((u8 *) D_87F119DC) + 0x25)) |= 1;
    }
    func_87E14898(ptr);
    func_87E14984(ptr);
}
/* mkdraft:func_87E14A60 end */

extern s32 ModelAnim_IsFinished(void *);
extern void ModelAnim_SetFrame(void *, s32);
extern void * D_87F119DC;
void func_87E14BA8(void) {
    extern void ModelAnim_SetAnimation(void *, s32);
    s32 state;
    u8 *ctx;
    void *ptr;
    f32 value;
    ctx = D_87F119DC;
    ptr = *((void **) (ctx + 0x20));
    do { state = *((s32 *) (((u8 *) (*((void **) ptr))) + 0x164)); } while (0);
    switch (state) {
    case 1:
    case 2:
        if ((*((s32 *) (((u8 *) D_87F119DC) + 0xC))) & 0x10000000) {
            ModelAnim_SetSpeed(((u8 *) D_87F119DC) + 0x24, 0x10000);
            ModelAnim_SetFrame(((u8 *) D_87F119DC) + 0x24, 0);
            *((u32 *) (((u8 *) D_87F119DC) + 0xC)) &= ~0x10000000;
        }
        if (ModelAnim_HasCrossedFrame(((u8 *) D_87F119DC) + 0x24, 30)) {
            ModelAnim_SetSpeed(((u8 *) D_87F119DC) + 0x24, 0);
        }
        break;
    case 3:
        ModelAnim_SetSpeed(((u8 *) D_87F119DC) + 0x24, 0x10000);
        if (ModelAnim_IsFinished(((u8 *) D_87F119DC) + 0x24)) {
            ModelAnim_SetAnimation(((u8 *) D_87F119DC) + 0x24, -1);
            ModelAnim_SetAnimation(((u8 *) D_87F119DC) + 0x24, 0);
            ModelAnim_SetSpeed(((u8 *) D_87F119DC) + 0x24, 0);
            *((u32 *) (((u8 *) D_87F119DC) + 0xC)) |= 0x10000000;
        }
        break;
    case 4:
        ModelAnim_SetSpeed(((u8 *) D_87F119DC) + 0x24, 0x30000);
        if (ModelAnim_IsFinished(((u8 *) D_87F119DC) + 0x24)) {
            *((f32 *) (((u8 *) D_87F119DC) + 0x5C)) = 0.0f;
            value = *((f32 *) (((u8 *) D_87F119DC) + 0x5C));
            *((f32 *) (((u8 *) D_87F119DC) + 0x58)) = value;
            *((f32 *) (((u8 *) D_87F119DC) + 0x54)) = value;
        }
        break;
    }
}

void func_87E14D24(void) {
    s32 rounded;
    f32 ratio;
    f32 scaled;
    s32 *child; // FAKE: single-use copy of the pointer at +0x20; diff score 75 without it.

    child = *(s32 **)((u8 *)D_87F119DC + 0x20);
    func_87E13924(D_87F119DC, *child);
    *((u8 *)D_87F119DC + 0x41) = 0xFF;
    ratio = *((u8 *)D_87F119DC + 0xC7) / 255.0f;
    scaled = (1.0f - ratio) * 220.0f;
    if (scaled >= 0.0f) {
        rounded = scaled + 0.5f;
    } else {
        rounded = scaled - 0.5f;
    }
    *((u8 *)D_87F119DC + 0xC7) = 220 - rounded;
}

void func_87E14E08(u8 *arg0) {
    s32 duration;
    s32 next;

    (*(s32 *)(arg0 + 0x160))++;
    switch (*(s32 *)(arg0 + 0x164)) {
    case 0:
        duration = 15;
        next = 1;
        break;
    case 1:
        duration = 20;
        next = 2;
        break;
    case 2:
        duration = 150;
        next = 3;
        break;
    case 3:
        duration = 30;
        next = 0;
        break;
    case 4:
        duration = 10;
        next = 5;
        break;
    case 5:
        duration = 1;
        next = 5;
        break;
    }
    if (*(s32 *)(arg0 + 0x164) == 4) {
        if (duration < *(s32 *)(arg0 + 0x160)) {
            *(s32 *)(arg0 + 0x160) = duration;
            *(s32 *)(arg0 + 0x164) = next;
        }
    } else {
        if (*(s32 *)(arg0 + 0x164) == 2 && *(s32 *)(arg0 + 0x168) != -1) {
            *(s32 *)(arg0 + 0x160) = 0;
            *(s32 *)(arg0 + 0x164) = *(s32 *)(arg0 + 0x168);
            *(s32 *)(arg0 + 0x168) = -1;
        }
        if (duration < *(s32 *)(arg0 + 0x160)) {
            *(s32 *)(arg0 + 0x160) = 0;
            if (*(s32 *)(arg0 + 0x168) != -1) {
                *(s32 *)(arg0 + 0x164) = *(s32 *)(arg0 + 0x168);
                *(s32 *)(arg0 + 0x168) = -1;
            } else {
                *(s32 *)(arg0 + 0x164) = next;
            }
        }
    }
    switch (*(s32 *)(arg0 + 0x164)) {
    case 2:
        *(f32 *)(arg0 + 0x16C) = 1.0f;
        break;
    case 0:
    case 5:
        *(f32 *)(arg0 + 0x16C) = 0.0f;
        break;
    default:
        *(f32 *)(arg0 + 0x16C) = (f32)*(s32 *)(arg0 + 0x160) / duration;
        break;
    }
}

extern void func_87E120F8(s32);
extern void func_87E1425C(s32);
extern void func_87F0277C(s32);
extern void func_87F0C3EC(s32 *);
void func_87E14F98(s32 arg0) {
    func_87E14E08((u8 *)arg0);
    func_87F0277C(arg0 + 4);
    func_87F0277C(arg0 + 0x18);
    func_87F0277C(arg0 + 0x2C);
    func_87E1425C(arg0);
    func_87E120F8(arg0 + 0x64);
    func_87F0C3EC(&D_87E1EC10);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_317060/func_87E14FF4.s")

void func_87E15324(u8 *arg0) {}

void func_87E1532C(u8 *arg0) {}

extern void func_87E14D24(void);
extern void func_87E14BA8(void);
extern void ModelAnim_SetAnimation(void *, s32);
typedef struct { u8 pad0[0x24]; u8 anim[0x1D]; u8 alpha; u8 pad42[0xA]; f32 height; u8 pad50[4]; f32 scale[3]; u8 pad60[0x64]; s32 opacity; } F15334StackChild;
extern void * func_87F025B8(void *, void *);
void func_87E15334(u8 *arg0)
{
    F15334StackChild *child;
    u8 *pool[2];
    f32 scale;
     do {         pool[0] = arg0 + 0x2C;         child = func_87F025B8(pool[0], func_87E14D24);         if (child != 0) {             func_8003F1DC(child->anim);             func_8003F114(child->anim, 0, -1, *(s32 *)(arg0 + 0x60));             scale = 0.15f;             child->scale[0] = scale;             child->scale[1] = scale;             child->scale[2] = scale;             child->opacity = 0xFF;             *(F15334StackChild **)(arg0 + 0x40) = child;         }         child = func_87F025B8(pool[0], func_87E14BA8);         if (child != 0) {             func_8003F1DC(child->anim);             func_8003F114(child->anim, 0, -1, *(s32 *)(arg0 + 0x5C));             ModelAnim_SetAnimation(child->anim, 0);             scale = 0.32f;             child->scale[2] = scale;             child->scale[1] = scale;             child->scale[0] = scale;             child->height = 5.0f;             child->alpha = 0xC8;         }     } while (0);
}

extern void *func_87F025B8(void *, void *);
extern void func_87E146DC(void *, s32, s32);
extern void func_87E14A60(void);
void func_87E15430(void *arg0) {
    void *result;
    result = func_87F025B8((u8 *)arg0 + 0x18, (void *)func_87E14A60);
    if (result != NULL) {
        func_87E146DC(result, *(s32 *)((u8 *)result + 0x20), 1);
        *(u8 *)((u8 *)result + 0x41) = 0;
    }
}

void func_87E15478(u8 *arg0) {
    s32 temp_v1;
    u8 *var_v0;

    if ((var_v0 = func_87E13C94(arg0)) != NULL) {
        temp_v1 = *(s32 *)(var_v0 + 0x38);
        *(s32 *)temp_v1 = 1;
        var_v0[0x25] |= 1;
        *(f32 *)(var_v0 + 0x10) = 0.0f;
        *(f32 *)(var_v0 + 0x14) = 0.0f;
        // FAKE: spelling this zero 0.f keeps it out of the shared $f0 zero;
        // diff score 215 with 0.0f.
        *(f32 *)(var_v0 + 0x48) = 0.f;
        *(f32 *)(var_v0 + 0x18) = 0.0f;
        *(f32 *)(var_v0 + 0x4C) = 30.0f;
        *(f32 *)(var_v0 + 0x50) = 500.0f;
    }
}

extern void func_87E13F84(s32, s32);
void func_87E154E4(s32 arg0) {
    func_87E13F84(arg0, 0x10000000);
}

extern void *func_87E12070(void *, s32, s32);
void func_87E15504(u8 *arg0, s32 arg1) {
    u8 *context = *(u8 **)(arg0 + 0xC);
    s32 *resource = *(s32 **)(context + 0x38);
    s32 i;
    u8 *entry;

    *resource = 2;
    *(f32 *)(context + 0x10) = 0.0f;
    *(f32 *)(context + 0x14) = 0.0f;
    context[0x25] |= 1;
    *(f32 *)(context + 0x18) = 0.0f;
    *(s32 *)(arg0 + 0x80) = arg1;
    *(f32 *)(arg0 + 0x84) = 0.0f;
    for (i = 0; i < *(s32 *)(arg0 + 0x80); i++) {
        entry = func_87E12070(arg0 + 0x64, (s32)func_87E14458, i);
        if (entry != NULL) {
            *(u8 **)(entry + 0x20) = arg0;
            entry[0x41] = 0;
        }
    }
    func_87E15334(arg0);
    func_87E15430(arg0);
    func_87E13F84((s32)arg0, 0);
    *(s32 *)(arg0 + 0x160) = 0;
    *(s32 *)(arg0 + 0x164) = 0;
}

void func_87E155DC(u8 *arg0) {
    *(s32 *)(arg0 + 0x168) = 4;
}

extern void func_87F0ACDC(void *, s32, void *, s32);
typedef struct { u8 high : 1; u8 next : 1; u8 rest : 6; } F155E8I7Flags;
typedef struct { u32 color; u32 data; F155E8I7Flags flags; u8 pad[3]; } F155E8I7Record;
typedef struct { void *head; u8 pad[0x84]; F155E8I7Record records[1]; } F155E8I7Owner;
typedef struct { void *head; u8 pad[0x84]; u32 color; u32 data; F155E8I7Flags flags; u8 tail[3]; } F155E8I7Overlay;
typedef struct { u8 r; u8 g; u8 b; u8 a; } F155E8I7Color;
void func_87E155E8(F155E8I7Owner *arg0, s32 arg1, s32 arg2, f32 arg3, s32 arg4, s32 arg5) {
    arg0->records[arg2].color = *(u32 *)&arg3;
    func_87F0ACDC(&arg0->records[arg2].data, arg2, arg0->head, arg1);
    arg0->records[arg2].flags.high = arg4;
    arg0->records[arg2].flags.next = arg5;
}

extern void Geo_RenderRootNode(s32);
void WidgetTree_OpenMessagePanel_fragment63(u8 *arg0) {
    Geo_RenderRootNode(*(s32 *)(arg0 + 0x170));
}

s32 func_87E15698(u8 *arg0) {
    return *(s32 *)(arg0 + 0x164);
}
#endif
