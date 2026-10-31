#include "global.h"


#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/25/fragment25_15A060/func_82100020.s")

extern s32 func_8004C990(s32, s32);
extern s32 func_8004D1FC(u8 *);
extern void GfxRect_DrawTextured(s16, s16, s16, s16, s16, s16, s16, s16, s32);

// Close to func_8260B8CC (fragment20); draws resource 75 instead of 81, returns early when
// func_8004C990 finds no resource, and passes the resource to func_8004D1FC before drawing.
// The width is divided as it is loaded; the template's separate `tile_width /= 4` loads the
// height through a different register (diff score 5).
void func_82100214(s32 x, s32 y, s32 width, s32 height) {
    s32 resource;
    s32 tile_width;
    s32 tile_height;

    resource = func_8004C990(75, 0);
    if (resource != 0) {
        tile_width = ((u16 *)resource)[0] / 4;
        tile_height = ((u16 *)resource)[1];
        func_8004D1FC((u8 *)resource);
        GfxRect_DrawTextured(x, y, tile_width, tile_height, 0, 0, 1024, 1024, 0);
        GfxRect_DrawTextured(x + tile_width, y, width - tile_width * 2, tile_height,
                             tile_width << 5, 0, 0, 1024, 0);
        GfxRect_DrawTextured(x + width - tile_width, y, tile_width, tile_height,
                             tile_width << 5, 0, 1024, 1024, 0);
        GfxRect_DrawTextured(x, y + tile_height, tile_width, height - tile_height * 2,
                             (tile_width * 2) << 5, 0, 1024, 0, 0);
        GfxRect_DrawTextured(x, y + height - tile_height, tile_width, tile_height,
                             (tile_width * 2) << 5, 0, 1024, 1024, 0);
        GfxRect_DrawTextured(x + tile_width, y + height - tile_height,
                             width - tile_width * 2, tile_height,
                             (tile_width * 3) << 5, 0, 0, 1024, 0);
        GfxRect_DrawTextured(x + width - tile_width, y + height - tile_height,
                             tile_width, tile_height, (tile_width * 3) << 5, 0, 1024, 1024, 0);
        GfxRect_DrawTextured(x + width - tile_width, y + tile_height,
                             tile_width, height - tile_height * 2,
                             (tile_width * 3) << 5, 0, 1024, 0, 0);
    }
}

extern Gfx *D_800D0510;
extern Gfx D_80094E38[];
extern Gfx D_80094E78[];
extern u8 D_82103DE0[];
extern void func_82100020(s16, s16, s16, s16, u8 *, u8 *);

// arg1[4]-arg1[7] are passed as the x, y, width and height parameters of func_82100214;
// func_82100020 receives the same rectangle.
s32 func_82100514(s32 arg0, s16 *arg1, u8 *arg2) {
    u8 *var_v1;
    u8 *var_v0;

    switch (arg0) {
        case 0: // FAKE: empty case; diff score 360 without it.
            break;
        case 1:
            gSPDisplayList(D_800D0510++, D_80094E78);
            gDPSetCombine(D_800D0510++, 0xFC30FE61, 0x55FEF77B);
            gDPSetRenderMode(D_800D0510++, 0x0F0A4000, 0);
            var_v1 = (arg2 != NULL) ? arg2 + 0x28 : D_82103DE0;
            var_v0 = (arg2 != NULL) ? arg2 + 0x2C : D_82103DE0;
            func_82100020(arg1[4], arg1[5], arg1[6], arg1[7], var_v1, var_v0);
            gSPDisplayList(D_800D0510++, D_80094E38);
            gDPSetRenderMode(D_800D0510++, 0x0F0A4000, 0);
            func_82100214(arg1[4], arg1[5], arg1[6], arg1[7]);
            break;
    }
    return 0;
}

extern void func_8005487C(void *);
extern void func_80055EF0(void *, s32);
extern void func_80054210(void *);
void func_82100658(void *arg0) {
    s32 flag;
    func_8005487C((u8 *)arg0 + 0x20);
    if ((*(u16 *)((u8 *)arg0 + 0x22) & 1) != 0) flag = 1;
    else flag = 0;
    func_80055EF0((u8 *)arg0 + 8, flag);
    func_80054210(arg0);
}

extern s32 D_821040A4[];
extern u8 D_82104170[];
extern void *func_8005049C(void *, s32);
void func_821006AC(s32 arg0, s32 arg1) {
    s32 *p = D_821040A4;
    if (*p != 0x5F454E44) {
        do {
            void *value = func_8005049C(*(void **)((u8 *)D_82104170 + 0x14), *p);
            if (value != NULL) {
                if (arg1 != 0) *(u16 *)((u8 *)value + 2) |= 1;
                else *(u16 *)((u8 *)value + 2) &= ~1;
            }
            p++;
        } while (*p != 0x5F454E44);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/25/fragment25_15A060/func_82100764.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/25/fragment25_15A060/func_821008BC.s")

void func_82100A40(void *arg0) {
    typedef struct {
        s32 data[12];
    } Block30;
    typedef struct {
        u8 unk_00[0x28];
        s32 unk_28;
    } State;

    if (_bcmp((u8 *)arg0 + 0x70, (u8 *)arg0 + 0x40, 0x30) != 0) {
        s32 flag = ((State *)arg0)->unk_28 ? 1 : 0;

        func_80055F6C((u8 *)arg0 + 0x78, flag);
        func_80054248((u8 *)arg0 + 0x70);
        func_80051D64(20, 0);
        func_80055028();
        *(Block30 *)((u8 *)arg0 + 0x40) = *(Block30 *)((u8 *)arg0 + 0x70);
    }
}

extern u8 *D_8210418C;
s32 func_82100AEC(s32 a, void *p) {
    if (a == 1 && *(u8 *)p == 4) {
        *(s16 *)((u8 *)p + 0x30) = 0x1c;
        *(s16 *)((u8 *)p + 0x32) =
            *(s32 *)((u8 *)*(void **)((u8 *)*(void **)((u8 *)D_8210418C + 4) + 8) + 0x14);
    }
    return 0;
}

extern u8 *D_8210418C;
s32 func_82100B2C(s32 a, void *p) {
    if (a == 1 && *(u8 *)p == 4) {
        *(s16 *)((u8 *)p + 0x30) = 0x1c;
        *(s16 *)((u8 *)p + 0x32) =
            *(s32 *)((u8 *)*(void **)((u8 *)*(void **)((u8 *)D_8210418C + 4) + 8) + 0x10);
    }
    return 0;
}

extern u8 *D_8210418C;
extern s32 func_8004C874(s32, s32);
extern s32 func_80049148(u16, s32, s32, void *);
s32 func_82100B6C(s32 arg0, void *arg1) {
    if (arg0 == 1) {
        if (*(u8 *)arg1 == 4) {
            s32 value = func_8004C874(0x1C, *(s32 *)((u8 *)*(void **)((u8 *)*(void **)((u8 *)D_8210418C + 4) + 8) + 0x10));
            *(s16 *)((u8 *)arg1 + 0xC) =
                *(s32 *)((u8 *)arg1 + 0x20) +
                func_80049148(*(u16 *)((u8 *)arg1 + 0x24), 0, value, arg1) + 0x1A;
        }
        return func_82100514(arg0, arg1, *(void **)((u8 *)*(void **)((u8 *)D_8210418C + 4) + 4));
    }
    return 0;
}

extern u8 *D_82104188;
s32 func_82100C14(s32 arg0, void *arg1) {
    s32 result;
    if (arg0 == 1) result = func_82100514(arg0, arg1, D_82104188);
    else result = 0;
    return result;
}

extern void *D_80087200;
extern u8 D_82104170[];
extern void *func_821019AC(void *, void *);
extern f32 func_82101AB4();
extern f32 func_82101AFC();
extern f32 func_82101B44();
extern void func_82102190(void *, f32, f32, f32);
void func_82100C50(void *arg0, s32 arg1) {
    s32 padding;
    f32 sp28;
    f32 sp24;
    if (arg1 != 0) func_821019AC(*(void **)((u8 *)arg0 + 0x1C), D_80087200);
    sp24 = func_82101AB4(*(void **)((u8 *)*(void **)((u8 *)arg0 + 0x1C) + 4));
    sp28 = func_82101AFC(*(void **)((u8 *)*(void **)((u8 *)arg0 + 0x1C) + 4));
    func_82102190(*(void **)D_82104170, sp24, sp28,
        *(f32 *)((u8 *)arg0 + 8) * func_82101B44(*(void **)((u8 *)*(void **)((u8 *)arg0 + 0x1C) + 4)));
}

s32 func_82100CD8(void *arg0) {
    if ((*(s32 *)((u8 *)(arg0) + (0x24))) == 0) {
        return 0;
    }
    if ((*(s32 *)((u8 *)(arg0) + (0x38))) != 0) {
        return 0;
    }
    if ((*(u8 *)((u8 *)(arg0) + (0x3C))) != 0) {
        return 0;
    }
    return 1;
}

extern void func_82101420(s32);
extern void func_82101094(void *, s32, s32);
extern void func_800226C0(s32);
extern void func_82100A40(void *);
void func_82100D20(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x3D) += 1;
    if (*(u8 *)((u8 *)arg0 + 0x3D) == 0x50) {
        *(s32 *)((u8 *)arg0 + 0x2C) = 1;
        func_82101420((s32)arg0);
        func_82101094(arg0, 6, 1);
        func_800226C0(0x2E);
    }
    if (*(u8 *)((u8 *)arg0 + 0x3D) >= 0xA1) {
        *(u8 *)((u8 *)arg0 + 0x3D) = 0;
        *(s32 *)((u8 *)arg0 + 0x38) = 0;
        func_82100A40(arg0);
    }
}

/* mkdraft:func_82100D9C begin */
extern s32 StageContext_GetFadeMode();
extern s32 StageContext_SetClearColor(s32);
extern s32 StageFade_StartFromTransparent(s32);
extern s32 func_800225C4(s32);
extern s32 func_80025CBC(s32);
extern s32 func_80064D28();
extern f32 D_821040BC;
extern f32 D_821040C0;



s32 func_82100D9C(void *arg0) {
    s32 sp24;
    f32 var_fv0;
    s32 temp_v0_2;
    s32 temp_v0;

    sp24 = *(s32 *)((u8 *)arg0 + 0x24);
    func_80064D28();
    switch (sp24) {                                 /* irregular */
    case 0:
        if (StageContext_GetFadeMode() == 0) {
            sp24 = 1;
        }
        break;
    case 1:
        func_82100C50(arg0, 1);
        if (func_82100CD8(arg0) != 0) {
            temp_v0 = *(u16 *)((u8 *)D_80087200 + 8);
            if (temp_v0 & 0x8000) {
                sp24 = 2;
                func_800226C0(0x3D);
                *(s32 *)((u8 *)arg0 + 4) = *(s32 *)((u8 *)(*(void **)((u8 *)(*(void **)((u8 *)(*(void **)((u8 *)arg0 + 0x1C)) + 4)) + 8)) + 8);
                if (*(s32 *)((u8 *)arg0 + 4) != 8) {
                    func_800225C4(0x10);
                }
                StageContext_SetClearColor(0xFFFF);
                StageFade_StartFromTransparent(8);
            } else if (temp_v0 & 0x4000) {
                sp24 = 2;
                func_800226C0(3);
                *(s32 *)((u8 *)arg0 + 4) = 0;
                StageContext_SetClearColor(0xFFFF);
                StageFade_StartFromTransparent(8);
            }
        }
        break;
    case 2:
        func_82100C50(arg0, 0);
        if (*(s32 *)((u8 *)arg0 + 4) != 0) {
            var_fv0 = D_821040BC;
        } else {
            var_fv0 = D_821040C0;
        }
        *(f32 *)((u8 *)arg0 + 8) = (f32) (*(f32 *)((u8 *)arg0 + 8) * var_fv0);
        if (StageContext_GetFadeMode() == 1) {
            sp24 = 3;
            temp_v0_2 = *(s32 *)((u8 *)arg0 + 4);
            if ((temp_v0_2 != 8) && (temp_v0_2 != 0)) {
                func_80025CBC(8);
            }
        }
        break;
    }
    if (func_82100CD8(arg0) != 0) {
        func_821006AC(*(s32 *)((u8 *)arg0 + 0x14), 1);
    } else {
        if (*(s32 *)((u8 *)arg0 + 0x38) != 0) {
            func_82100D20(arg0);
        }
        func_821006AC(*(s32 *)((u8 *)arg0 + 0x14), 0);
    }
    *(s32 *)((u8 *)arg0 + 0x24) = sp24;
    return sp24;
}
/* mkdraft:func_82100D9C end */

/* mkdraft:func_82100F68 begin */
extern s32 func_800468A0(s32);
extern s32 func_800503A4(s32);
extern void func_800088DC(void);
extern void func_81801420(void);
extern s32 func_82100764(f32);
extern s32 func_82100CD8(void *);
extern s32 func_821023F4(s32);
extern void func_82101A30(void *);
extern void func_80008648(void);


void func_82100F68(void *arg0) {
    u8 temp_v0;

    func_800088DC();
    func_800468A0(*(s32 *)((u8 *)arg0 + 0xC));
    func_82101A30(*(void **)((u8 *)arg0 + 0x1C));
    func_800503A4(*(s32 *)((u8 *)arg0 + 0x14));
    func_81801420();
    if (*(s32 *)((u8 *)arg0 + 0x38) != 0) {
        temp_v0 = *(u8 *)((u8 *)arg0 + 0x3D);
        if (temp_v0 >= 0x51) {
            func_82100764((f32) (0xA0 - temp_v0) / 80.0f);
        } else {
            func_82100764((u32) temp_v0 / 80.0f);
        }
    }
    if (func_82100CD8(arg0) != 0) {
        func_821023F4(*(s32 *)((u8 *)arg0 + 0x0));
    }
    func_80008648();
}
/* mkdraft:func_82100F68 end */

extern s32 func_82100D9C(void *);
extern void func_82100F68(void *);
void func_82101040(void *arg0) {
    if ((*(s32 *)((u8 *)(arg0) + (0x24))) != 3) {
        do {
            func_82100D9C(arg0);
            func_82100F68(arg0);
        } while ((*(s32 *)((u8 *)(arg0) + (0x24))) != 3);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/25/fragment25_15A060/func_82101094.s")

extern void func_8004C398();
extern void main_pool_pop_state(s32);

void func_82101420(s32 arg0) {
    func_8004C398();
    main_pool_pop_state(0x50535253);
}

/* mkdraft:func_8210144C begin */
extern u8 D_446E30[];
extern u8 D_447D00[];
extern u8 D_82900000[];
extern u8 fragment67_ROM_START[];
extern u8 fragment68_ROM_START[];
extern u8 D_1000000[];
extern u8 *Asset_LoadToSegment(s32 id, u8 *rom_start, u8 *rom_end, s32 arg3);
extern s32 Fragment_LoadAndCall(s32 arg0, u8 *romStart, u8 *romEnd, u32 arg3, u32 arg4);
extern void Gfx_InitDisplayListBuffers(s32 arg0, s32 arg1);
extern s32 StageFade_StartFromOpaque(s32 duration);
extern s32 func_800082E0(s32, s32, s32, s32, s32, s32);
extern void func_80008514(s32 arg0);
extern void func_800086A4(s32 frames);
extern u8 *func_80047588(s32 flags, s32 side);
extern s32 func_80055948(s32 arg0);
extern void func_80057944(u8 arg0);
extern void main_pool_push_state(s32);
extern s32 func_82101E70(u8 *, s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 D_82103D94;
extern s32 D_82103D98;
extern f32 D_82103D9C;
extern f32 D_82103DA0;
extern f32 D_82103DA4;

// Clears the stage state and, when a stage fragment is pending (unk_3C is 1 or 2), loads and
// runs fragment 67's code. Then creates the stage object, loads the shared archives, sets up the
// display lists and buffer allocations, and fades in over 8 frames before the first update.


void func_8210144C(u8 *arg0, s32 arg1) {
    s32 var_s0;
    u8 *temp_v0;
    u8 temp_v1;

    _bzero(arg0, 0xA0);
    *(s32 *) (arg0 + 0x24) = 0;
    func_80055948(3);
    func_821008BC(arg0);
    temp_v1 = *(u8 *) (arg0 + 0x3C);
    if ((temp_v1 == 1) || (temp_v1 == 2)) {
        main_pool_push_state(0x504C4742);
        Fragment_LoadAndCall(((u32) ((s32) &D_82900000 & 0x0FF00000) >> 0x14) - 0x10, fragment67_ROM_START,
                             fragment68_ROM_START, 4U, *(u8 *) (arg0 + 0x3C) - 1);
        main_pool_pop_state(0x504C4742);
        func_82100A40(arg0);
        *(u8 *) (arg0 + 0x3C) = 0U;
    }
    temp_v0 = MainPool_AllocState(main_pool_get_available(), 0);
    *(s32 *) arg0 = func_82101E70(temp_v0, 0, D_82103D98, D_82103D94, D_82103DA0, D_82103D9C,
                                  D_82103DA4, 100.0f, 100.0f, 100.0f);
    MainPool_FinalizeAllocation((struct S1_MemoryBlock *) temp_v0);
    var_s0 = 0;
    do {
        func_80057944((u8) var_s0);
        var_s0 += 1;
    } while (var_s0 != 4);
    Asset_LoadToSegment((s32) ((u32) ((s32) D_1000000 & 0x0F000000) >> 0x18), D_446E30, D_447D00, 0);
    Gfx_InitDisplayListBuffers(0x10000, 0);
    func_80047588(8, 0);
    func_80008514(func_800082E0(1, 0, 2, 0, 2, 1));
    func_800086A4(2);
    StageFade_StartFromOpaque(8);
    func_82101094(arg0, arg1, 1);
    if (*(s32 *) (arg0 + 0x38) != 0) {
        func_800226C0(0x2D);
    }
}
/* mkdraft:func_8210144C end */

extern void func_80008574(void);
extern void func_80047610(void);
extern void Gfx_FreeDisplayListBuffers(void);
extern void func_82100A40(void *);
extern u8 D_82104170[];
void func_82101648(s32 arg0) {
    func_82101420(arg0);
    func_80008574();
    func_80047610();
    Gfx_FreeDisplayListBuffers();
    func_82100A40(D_82104170);
}

extern void func_8210144C(u8 *, s32);
extern void main_pool_push_state(s32);
extern s32 D_82104174;
s32 fragment25_main(s32 arg0, s32 arg1) {
    main_pool_push_state(0x50534C44);
    func_8210144C(D_82104170, arg0);
    func_82101040(D_82104170);
    func_82101648((s32) D_82104170);
    main_pool_pop_state(0x50534C44);
    return D_82104174;
}

s32 func_821016F0(void *arg0) {
    u8 *p = arg0;
    while (*(s32 *)p != 0) {
        p += 0x34;
    }
    return (p - (u8 *)arg0) / 52;
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/25/fragment25_15A060/func_82101728.s")

extern u16 D_82104104[];
extern void func_800226C0(s32);
void *func_821019AC(void *arg0, void *arg1) {
    void *result;
    u8 *entry;
    void *next;
    u16 buttons;
    s32 index;

    result = *(void **)((u8 *)arg0 + 4);
    buttons = *(u16 *)((u8 *)arg1 + 8);
    entry = result;
    for (index = 0; index < 4; index++) {
        next = *(void **)(entry + 0xC);
        if (next != NULL && (D_82104104[index] & buttons) != 0) {
            *(void **)((u8 *)arg0 + 4) = next;
            func_800226C0(0x3C);
            result = *(void **)((u8 *)arg0 + 4);
            break;
        }
        entry += 4;
    }
    return result;
}

void func_82101A30(void *arg0)
{
  s32 new_var;
  s32 var_a1;
  void *temp_a2;
  void *temp_v0;
  new_var = *((s32 *) (((u8 *) arg0) + 8));
  var_a1 = 0;
  if (new_var > 0)
  {
    do
    {
      temp_v0 = (*((s32 *) (((u8 *) arg0) + 0))) + var_a1;
      var_a1 += 0x20;
      if (temp_v0 == NULL)
      {
      }
      else
      {
        temp_a2 = *((void **) (((u8 *) temp_v0) + 0));
        if (temp_a2 == NULL)
        {
        }
        else
        {
          *((u16 *) (((u8 *) temp_a2) + 2)) = (u16) ((*((u16 *) (((u8 *) temp_a2) + 2))) | 2);
          *((u16 *) (((u8 *) (*((void **) (((u8 *) temp_v0) + 0)))) + 0x24)) = (u16) (*((u16 *) (((u8 *) (*((void **) (((u8 *) temp_v0) + 8)))) + 0x18)));
          *((u16 *) (((u8 *) (*((void **) (((u8 *) temp_v0) + 0)))) + 0x26)) = (u16) (*((u16 *) (((u8 *) (*((void **) (((u8 *) temp_v0) + 8)))) + 0x1A)));
        }
      }
    }
    while (var_a1 < ((*((s32 *) (((u8 *) arg0) + 8))) << 5));
  }
}
f32 func_82101AB4(u8 *arg0) {
    return ((f32)*(s16 *)(*(u8 **)(arg0 + 0) + 0x0C) *
            (*(f32 *)(*(u8 **)(arg0 + 8) + 0x2C) + 1.0f) * 0.5f) +
           (f32)*(s16 *)(*(u8 **)(arg0 + 0) + 0x08);
}

typedef struct { u8 padA[0xA]; s16 a; u8 padC[2]; s16 b; } S82101p;
typedef struct { u8 pad30[0x30]; f32 c; } T82101p;
typedef struct { S82101p *p; u8 pad4[4]; T82101p *q; } U82101p;
f32 func_82101AFC(U82101p *arg0) {
    return (f32)arg0->p->a + ((f32)arg0->p->b * (arg0->q->c + 1.0f) * 0.5f);
}

typedef struct {
    u8 pad[0xC];
    s16 x;
    s16 y;
} Func82101B44Record;

f32 func_82101B44(void **arg0) {
    Func82101B44Record *p = *arg0;
    return sqrtf((f32)p->x * (f32)p->y) * 0.5f;
}
#endif
