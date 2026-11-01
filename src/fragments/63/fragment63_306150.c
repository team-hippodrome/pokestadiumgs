#include "global.h"


#ifdef VERSION_US
s32 func_87E10E64(s32);
s32 func_87E10EA8(s32);
s32 func_87E10F2C(s32);
extern volatile unsigned char D_87E19934;
extern s32 D_87E19964;

void func_87E027E0(void *arg0)
{
  s32 *sp1C;
  s32 temp_v0_2;
  int temp_v0;
  s32 *new_var;
  void *temp_v1;
  temp_v1 = *((void **) (((u8 *) arg0) + 0x204));
  temp_v0 = *((u8 *) (((u8 *) temp_v1) + 0x2180));
  switch (temp_v0)
  {
    case 0:

    case 1:
      if ((*((u8 *) (((u8 *) temp_v1) + 0x2182))) != 0)
    {
      sp1C = ((*((s32 *) (((u8 *) arg0) + 4))) * 0xC) + (&D_87E19934);
    }
    else
    {
      sp1C = &D_87E19964;
    }
      break;

    case 3:
      sp1C = (((*((s32 *) (((u8 *) arg0) + 4))) * 0xC) + 0x18) + (&D_87E19934);
      break;

  }

  new_var = (s32 *) (((u8 *) arg0) + 0);
  temp_v0_2 = *new_var;
  if ((temp_v0_2 == 2) || (temp_v0_2 == 3))
  {
    func_87E10EA8(-1);
    func_87E10F2C(-1);
    return;
  }
  func_87E10E64(*((s32 *) (((u8 *) sp1C) + 0)));
  func_87E10EA8(*((s32 *) (((u8 *) sp1C) + 4)));
  func_87E10F2C(*((s32 *) (((u8 *) sp1C) + 8)));
}
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_306150/func_87E028D8.s")

extern void func_8004C8C0(s32);
void func_87E02A28(void) { func_8004C8C0(0x1A8); func_8004C8C0(0x1B2); func_8004C8C0(0x1A3); func_8004C8C0(0x1A5); func_8004C8C0(0x1A6); func_8004C8C0(0x1A7); }

extern u8 D_87E19848[];
extern u8 D_87E1987C[];
extern u8 D_87E198B0[];
void func_87E02A70(void *arg0) {
    s32 state;
    s32 unk;
    s32 i;
    s32 temp;
    u8 *record;

    state = MainPool_AllocState(main_pool_get_available(), 0);
    *(s32 *)((u8 *)arg0 + 0x1F8) = func_80040E80(state, D_87E19848);
    *(s32 *)((u8 *)arg0 + 0x1FC) = func_80040E80(state, D_87E1987C);
    *(s32 *)((u8 *)arg0 + 0x200) = func_80040E80(state, D_87E198B0);
    MainPool_FinalizeAllocation(state);
    unk = func_87F08E7C(156, 51, 0, 2, 0xF000000);
    record = (u8 *)arg0 + 0x1C;
    // FAKE: the store of temp into the previous record sits in the loop's
    // increment expression instead of the body.
    for (i = 0; i != 2; i++, record += 152, *(s32 *)(record - 0x8C) = temp) {
        *(s32 *)(record + 0) = 0;
        *(s32 *)(record + 4) = i;
        *(s32 *)(record + 8) = unk;
        temp = func_800071A4(0, 2, 156, 51, 0);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_306150/func_87E02B60.s")

extern Gfx *D_800D0510;
extern void *D_8009491C;
extern void GeoRender_ApplyMaterialState(void);
void func_87E02F40(s32 arg0, s32 arg1) {
    u8 *context;
    void *temp_v0;
    void *temp_a0;
    if (arg0 == 5) {
        context = (u8 *)D_8009491C;
        temp_v0 = *(void **)(context + 0x14);
        temp_a0 = *(void **)((u8 *)temp_v0 + 0x20);
        gDPPipeSync(D_800D0510++);
        gDPSetTextureFilter(D_800D0510++, G_TF_BILERP);
        gDPSetCombine(D_800D0510++, 0xFFFFFF, 0xFFFCF238);
        gSPSegment(D_800D0510++, 0xF, *(void **)((u8 *)temp_a0 + 8));
        gSPDisplayList(D_800D0510++, *(void **)((u8 *)temp_a0 + 4));
        GeoRender_ApplyMaterialState();
    }
}

void D_87E03018(void) {}

extern s32 GbSave_GetPortAvailability(s32);
extern u8 func_8005D92C(s32 index);
extern s32 func_8004C990(s32, s32);
extern u8 *func_8004CA60(u8 *);
void func_87E03020(void *arg0) {
    s32 result = -1;
    if (GbSave_GetPortAvailability(*(u8 *)((u8 *)arg0 + 8)) != 1) {
        switch (func_8005D92C(*(u8 *)((u8 *)arg0 + 8))) {
            case 1: result = 4; break;
            case 2: result = 2; break;
            case 3: result = 0; break;
            case 4: result = 6; break;
            case 5: result = 3; break;
            case 6: result = 5; break;
            case 7: result = 1; break;
        }
    }
    if (result != -1) {
        *(void **)((u8 *)arg0 + 4) = func_8004CA60((u8 *)func_8004C990(0x1A3, result));
    } else {
        *(s32 *)((u8 *)arg0 + 4) = 0;
    }
}
extern Gfx *D_800D0510;
extern void *D_8009491C;
extern void func_87E03020(void *);
extern void GeoRender_ApplyMaterialState(void);
void func_87E030F0(s32 arg0, s32 arg1) {
    u8 *context;
    void *temp_v0;
    void *temp_s0;
    if (arg0 == 5) {
        context = (u8 *)D_8009491C;
        temp_v0 = *(void **)(context + 0x14);
        temp_s0 = *(void **)((u8 *)temp_v0 + 0x20);
        func_87E03020(temp_s0);
        if (*(s32 *)((u8 *)temp_s0 + 4) != 0) {
            gDPPipeSync(D_800D0510++);
            gDPSetCombine(D_800D0510++, 0xFFFFFF, 0xFFFCF238);
            gSPSegment(D_800D0510++, 0xF, *(void **)((u8 *)temp_s0 + 4));
            gSPDisplayList(D_800D0510++, *(void **)((u8 *)temp_s0 + 0));
            GeoRender_ApplyMaterialState();
        }
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_306150/func_87E031C0.s")

extern void func_87E031C0(void);
extern void BgStage_DrawFrame(void);
void func_87E03448(void) {
    func_87E031C0();
    BgStage_DrawFrame();
}

extern s32 func_87F08DF8(void *, f32, f32, s32);
typedef struct unk_func_87E03470 {
    s32 unk_00;
    s32 unk_04;
    u8 *unk_08;
    f32 unk_0C;
    f32 unk_10;
} unk_func_87E03470;

void func_87E03470(void *arg0) {
    s32 i;
    s32 resource;
    unk_func_87E03470 *entry;

    entry = (unk_func_87E03470 *)((u8 *)arg0 + 0x160);
    resource = func_87F08DF8((void *)func_8004C990(434, 1), 0.0f, 10.0f, 0x0F000000);
    for (i = 0; i < 4; i++) {
        entry[i].unk_00 = i;
        entry[i].unk_04 = resource;
        entry[i].unk_08 = func_8004CA60((u8 *)func_8004C990(434, 1));
        entry[i].unk_0C = 0.0f;
        entry[i].unk_10 = 0.0f;
    }
}

extern s32 func_87F08E3C(void *, s32);
void func_87E03518(void *arg0) {
    u8 *entry;
    s32 resource;
    s32 i;

    resource = func_87F08E3C((void *)func_8004C990(0x1A3, 0), 0x0F000000);
    entry = (u8 *)arg0 + 0x1C4;
    for (i = 0; i < 4; i++) {
        entry[8] = i;
        *(s32 *)entry = resource;
        func_87E03020(entry);
        entry += 0xC;
    }
}

extern void func_87E028D8(void *);
extern void func_87E02A70(void *);
extern void func_87E03470(void *);
extern void func_87E03518(void *);
void func_87E03594(void *arg0, s32 arg1) {
    (*(s32 *)((u8 *)(arg0) + (0x204))) = arg1;
    (*(s32 *)((u8 *)(arg0) + (0))) = 0;
    func_87E02A28();
    func_87E02A70(arg0);
    func_87E03470(arg0);
    func_87E03518(arg0);
    func_87E028D8(arg0);
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_306150/func_87E035E4.s")

extern Gfx *D_800D0510;
extern void *D_8009491C;
extern void GeoRender_ApplyMaterialState(void);
typedef struct {
    u8 pad_60[0x60];
    u8 red;
    u8 green;
    u8 blue;
} Func87E0375CColor;
void func_87E0375C(s32 arg0, s32 arg1) {
    u8 *context;
    Func87E0375CColor *temp_a0;
    void *temp_a1;
    if (arg0 == 5) {
        context = (u8 *)D_8009491C;
        temp_a0 = *(Func87E0375CColor **)(context + 0x14);
        temp_a1 = *(void **)((u8 *)temp_a0 + 0x20);
        gDPPipeSync(D_800D0510++);
        gDPSetCombine(D_800D0510++, 0x50FFFF, -0xDC8);
        gDPSetEnvColor(D_800D0510++, temp_a0->red, temp_a0->green,
                       temp_a0->blue, 0xFF);
        gSPSegment(D_800D0510++, 0xF,
                   *(void **)((u8 *)(*(void **)((u8 *)temp_a1 + 0xC)) + 8));
        gSPDisplayList(D_800D0510++, *(void **)((u8 *)temp_a1 + 8));
        GeoRender_ApplyMaterialState();
    }}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_306150/func_87E03850.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_306150/func_87E03A08.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_306150/func_87E03B70.s")

extern void func_87E03850(void *);
extern void func_87E03A08(void *);
extern void func_87E03B70(void *);
void func_87E03CBC(void *arg0) { func_87E03850(arg0); func_87E03A08(arg0); func_87E03B70(arg0); }

extern void func_87E13480(s32);
extern void func_87E13490();
extern void func_87E134C0();
void func_87E03CEC(void *arg0) {
    (*(s32 *)((u8 *)(arg0) + (4))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0))) = 0;
    func_87E03CBC(arg0);
    func_87E134C0();
    func_87E13490();
    func_87E13480(0);
}

extern void func_87F02684(s32);
void func_87E03D28(s32 arg0) {
    func_87F02684(arg0 + 8);
}

s32 func_87E03D48(s32 arg0) {
    u8 *p;
    s32 result;
    s32 i;
    p = (u8 *)(u32)(arg0 + 0x1C);
    result = 1;
    arg0 = 2;
    i = 0;
    do {
        if (*(s32 *)(p + 0x94) != 0) {
            result = 0;
            break;
        }
        i++;
        p += 0x98;
    } while (i != arg0);
    return result;
}

extern f32 D_87E19830[];
extern void func_87F0B1A4(u8 *, u8 *, f32, f32, f32, s32, s32);
extern void func_87F0B2F4(u8 *, u8 *, f32, f32, f32, s32, s32);
void func_87E03D80(u8 *arg0) {
    u8 *sub;
    u8 *node;
    f32 *vec;
    s32 var_s2;

    node = *(u8 **)(arg0 + 0x14);
    if (node != NULL) {
        vec = D_87E19830;
        var_s2 = 10;
        do {
            sub = *(u8 **)(node + 0x20);
            func_87F0B1A4(sub + 0x10, node + 0x48, vec[0], vec[1], vec[2], var_s2, 0x2000);
            func_87F0B2F4(sub + 0x10, node + 0x42, 180.0f, 0.0f, 0.0f, var_s2, 0);
            node = *(u8 **)(node + 4);
            vec += 3;
            var_s2 += 5;
        } while (node != NULL);
    }
}

/* mkdraft:func_87E03E48 begin */
extern void func_87F0B1A4(u8 *, u8 *, f32, f32, f32, s32, s32);
extern void func_87F0B2F4(u8 *, u8 *, f32, f32, f32, s32, s32);
extern u32 func_8003570C(void);

// Walks the list at arg0 + 0x14. Each entry's object pointer at offset 0x20
// names a state block at object + 0x10, which func_87F0B1A4 receives with the
// entry's position floats at offsets 0x48..0x50 (the second shifted by
// -360.0f, priority 15). func_87F0B2F4 then randomizes the entry's rotation at
// offset 0x42 from three LCG draws at func_8003570C, each scaled from [0,1)
// over 4294967296.0f to -45..45 degrees for the first two and -180..180
// degrees for the third. func_87E03D80 above is the same walk with the fixed
// angle table instead of the draws.


void func_87E03E48(void *arg0) {
    u32 rand_x;
    u32 rand_y;
    u32 rand_z;
    u8 *state;
    u8 *object;
    u8 *node;

    node = *(u8 **)((u8 *)arg0 + 0x14);
    if (node != NULL) {
        do {
            object = *(u8 **)(node + 0x20);
            state = object + 0x10;
            func_87F0B1A4(state, node + 0x48, *(f32 *)(node + 0x48),
                *(f32 *)(node + 0x4C) + -360.0f, *(f32 *)(node + 0x50), 0xF, 0x2000);
            rand_x = func_8003570C();
            rand_y = func_8003570C();
            rand_z = func_8003570C();
            func_87F0B2F4(state, node + 0x42, (((f32)rand_x / 4294967296.0f) * 90.0f) - 45.0f,
                (((f32)rand_y / 4294967296.0f) * 90.0f) - 45.0f,
                (((f32)rand_z / 4294967296.0f) * 360.0f) - 180.0f, 0xF, 0);
            node = *(u8 **)(node + 4);
        } while (node != NULL);
    }
}
/* mkdraft:func_87E03E48 end */

extern s32 func_87E016D8(void *);
s32 func_87E03FF0(void *arg0) {
    s32 result;
    void *p;
    p = *(void **)((u8 *)arg0 + 0x204);
    result = ((*(u8 *)((u8 *)p + 0x2182) & 1) != 0);
    if (result) {
        ;
        return func_87E016D8(p) >= 2;
    }
}

s32 func_87E04030(void *arg0, void *arg1) {
    struct Item { u8 pad[0x94]; s32 value; };
    struct Sub { u8 pad[0x20]; struct Item *item; };
    struct State { u8 pad[0x18C]; struct Sub sub; };
    struct Root { u8 pad[0x10]; struct State *state; };
    struct Sub *sub = &((struct Root *)arg0)->state->sub;
    arg1 = sub->item;
    return ((struct Item *)arg1)->value == 0;
}

typedef struct {
    u32 unk_00_31 : 1;
    u32 unk_00_30 : 1;
    u32 unk_00_29 : 30;
} unk_func_87E04048;
void func_87E04048(void *arg0) {
    u8 *node;
    u8 *state;

    if ((*(u8 **)((u8 *)arg0 + 516))[8576] == 3) {
        node = *(u8 **)((u8 *)arg0 + 16) + 396;
        state = *(u8 **)(node + 32);
        if ((*(s32 *)(state + 148) == 0) && (((unk_func_87E04048 *)(state + 120))->unk_00_30 == 0)) {
            if (func_87E03FF0(arg0) != 0) {
                func_87F0B2F4(state + 16, node + 66, 0.0f, 0.0f, 0.0f, 15, 0xC000);
            } else {
                func_87F0B2F4(state + 16, node + 66, 180.0f, 0.0f, 0.0f, 15, 0x8000);
            }
        }
    }
}

/* mkdraft:func_87E04114 begin */
extern void func_800226C0(s32);
extern s32 func_800279C4(s32);
extern void func_87E0168C(s32 arg0, u8 arg1, s32 arg2);
extern u8 *func_87E016C8(void);
extern s32 func_87E03D48(s32 arg0);
extern void func_87E03D80(u8 *arg0);
extern void func_87E03E48(void *arg0);
extern s32 func_87E03FF0(void *arg0);
extern void func_87E04048(void *arg0);
extern void func_87E134E8(void);
extern s32 func_87E13688(void);
extern s32 func_87E1369C(void);
extern void func_87E027E0(void *arg0);
extern void func_87F0277C(void *arg0);
extern s32 func_87F0E610(u8 *arg0, u8 *arg1);
#ifdef CC_CHECK
#define CALL_87E04030(arg0) func_87E04030((arg0), 0)
#else
#define CALL_87E04030(arg0) func_87E04030(arg0)
#endif
extern u8 D_800CE060[];
extern u8 *D_87E1EB78;

// NON_MATCHING: The clamp constant still changes the following temporary register allocation.
#ifdef NON_MATCHING
s32 func_87E04114(u8 *arg0)
{
  extern s32 func_87E04030();
  s32 padA;
  s32 padB;
  s32 result;
  u16 padX;
  u16 flags;
  s32 i;
  s32 state;
  s32 v;
  u8 bit;
  u8 *rec;
  u8 *p;
  u8 val;
  result = 2;
  D_87E1EB78 = arg0;
  flags = func_87F0E610(func_87E016C8(), (u8 *) (-1));
  switch (*((s32 *) arg0))
  {
    case 0:
      if (func_87E03D48((s32) arg0) != 0)
    {
      *((s32 *) arg0) = 1;
      func_87E04048(arg0);
    }
      break;

    case 1:
      state = *((s32 *) (arg0 + 4));
      switch (state)
    {
      case 0:
        rec = D_800CE060;
        if (1)
      {
        for (i = 0; i != 4; i++, rec += 0x28)
        {
          if ((*((u16 *) (rec + 8))) & 0x8000)
          {
            p = *((u8 **) (arg0 + 0x204));
            bit = (1 << i) & 0xFF;
            if ((*((u8 *) (p + 0x2182))) & bit)
            {
              *((u8 *) (p + 0x2182)) &= ~bit;
              func_800279C4(0xCF02);
            }
            else
            {
              *((u8 *) (p + 0x2182)) |= bit;
              func_800279C4(0xCF02);
            }
          }
        }

        func_87E04048(arg0);
        break;
      }

      case 1:
        if (flags & 0x8000)
      {
        func_87E03D80(arg0);
        *((s32 *) arg0) = 2;
        func_87E134E8();
        func_800279C4(0xCF02);
        func_87E0168C(3, 0x8C, 0xE);
      }
        break;

    }


      if (((func_87E1369C() != 0) && (!(flags & 0x8000))) && (!(flags & 0x4000)))
    {
      if ((*((u8 *) ((*((u8 **) (arg0 + 0x204))) + 0x2180))) == 3)
      {
        if (func_87E03FF0(arg0) == 0)
        {
          *((s32 *) (arg0 + 4)) = 0;
          flags &= 0xF3FF;
          v = 1;
        }
        if (CALL_87E04030(arg0) == 0)
        {
          flags &= 0xF3FF;
        }
      }
      v = ((*((s32 *) (arg0 + 4))) + ((flags & 0x400) > 0)) - ((flags & 0x800) > 0);
      *((s32 *) (arg0 + 4)) = v;
      if (v < 0)
      {
        *((s32 *) (arg0 + 4)) = 1;
      }
      if (v >= 2)
      {
        *((s32 *) (arg0 + 4)) = 0;
      }
      if (flags & 0xC00)
      {
        func_800279C4(0xCF01);
      }
    }
      if ((flags & 0x4000) && (func_87E13688() != 0))
    {
      func_87E03E48(arg0);
      *((s32 *) arg0) = 3;
      func_800226C0(3);
      func_87E0168C(3, 0x8C, 0xE);
    }

      break;

    case 2:
      if (func_87E03D48((s32) arg0) != 0)
    {
      result = 0;
    }
      break;

    case 3:
      if (func_87E03D48((s32) arg0) != 0)
    {

      result = 1;

    }
      break;

  }

  func_87F0277C(arg0 + 8);
  func_87F0277C(arg0 + 0x14C);
  func_87F0277C(arg0 + 0x1B0);
  func_87E027E0(arg0);
  return result;
}
#else
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_306150/func_87E04114.s")
#endif
/* mkdraft:func_87E04114 end */
#endif
