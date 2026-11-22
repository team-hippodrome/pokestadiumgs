#include "global.h"

#ifdef VERSION_US
struct Fragment53ActorState {
    u8 prefix[0xC];
    s32 animation;
    s32 pending;
    u8 middle14[4];
    s32 score;
    u8 middle1C[0x68];
    s32 result;
    s32 kind;
    u8 tail[0xC];
};
struct Fragment53Model { u8 opaque[0x168]; };
extern struct Fragment53ActorState D_86511698[];
extern struct Fragment53Model D_8650E120[];
#endif


#ifdef VERSION_US
extern Gfx *D_800D0510;
extern void *Gfx_AllocDisplayList(s32 arg0);
extern void func_8003CD84(void);
extern Vtx D_8650C160[];
extern s32 D_8650C5E0;
extern s32 D_8650C728[];
extern s32 D_8650C744[];
extern u8 D_8650C348[];



void func_86500020(s32 arg0, void *arg1)
{
  Vtx *vtx;
  s32 i;
  s32 j;
  if (arg0 == 5)
  {
    vtx = (Vtx *) Gfx_AllocDisplayList(0xE0);
    for (i = 0; i < 14; i++)
    {
      vtx[i] = ((Vtx *) D_8650C160)[i];
    }
    for (j = 0; j < 7; j++)
    {
      *((s16 *) (((u8 *) (vtx + D_8650C728[j])) + 2)) = (*((s32 *) (((u8 *) (&D_8650C5E0)) + 0x40))) + 0x23;
      *((s16 *) (((u8 *) (vtx + D_8650C744[j])) + 2)) = (*((s32 *) (((u8 *) (&D_8650C5E0)) + 0x40))) - 0x23;
    }
    gSPVertex(D_800D0510++, vtx, 14, 0);
    gSPDisplayList(D_800D0510++, D_8650C348);
    func_8003CD84();
  }
}
#endif

#ifdef VERSION_US
extern Gfx *D_800D0510;
extern void func_8003CD84(void);
extern Vtx D_8650BFC0;
extern void *Gfx_AllocDisplayList(s32 arg0);
extern Gfx D_8650C288[];
extern s32 D_8650C5E4;
extern s32 D_8650C814[];
extern s32 D_8650C830[];



void func_86500354(s32 arg0, void *arg1)
{
  Vtx *vtx;
  s32 d1; // FAKE: unused; widens the frame to the target's 0x28. diff score 10 without it.
  s32 sp1C;
  s32 i;
  s32 j;
  struct Fragment53ActorState *st;
  u32 v;
  v = *((u32 *) (((u8 *) arg1) + 0x14));
  if (v < 2)
  {
    sp1C = 0;
  }
  else
    if (v < 4)
  {
    sp1C = 1;
  }
  else
    if (v < 6)
  {
    sp1C = 2;
  }
  else
    if (v < 8)
  {
    sp1C = 3;
  }
  //!bug: sp1C is read uninitialized when arg1->0x14 >= 8.
  if (arg0 == 5)
  {
    vtx = (Vtx *) Gfx_AllocDisplayList(0xE0);
    for (i = 0; i < 14; i++)
    {
      vtx[i] = (&D_8650BFC0)[i];
    }

    if (!((*((u32 *) (((u8 *) arg1) + 0x14))) & 1))
    {
      st = &D_86511698[sp1C];
      for (j = 0; j < 7; j++)
      {
        *((s16 *) (((u8 *) (vtx + D_8650C830[j])) + 0xA)) = *((s32 *) (((u8 *) (&D_86511698[sp1C])) + 0x60));
      }

    }
    else
    {
      st = &D_86511698[sp1C];
      for (j = 0; j < 7; j++)
      {
        *((s16 *) (((u8 *) (vtx + D_8650C814[j])) + 0xA)) = *((s32 *) (((u8 *) st) + 0x60));
      }

    }
    { Gfx *_g = D_800D0510++; _g->words.w0 = 0xE7000000; _g->words.w1 = 0; }
    if ((((*((s32 *) (((u8 *) st) + 0x2C))) + 2) >= D_8650C5E4) && ((*((s32 *) (((u8 *) st) + 0x54))) == 3))
    {
      { Gfx *_g = D_800D0510++; _g->words.w0 = 0xFB000000; _g->words.w1 = -1U; }
      { Gfx *_g = D_800D0510++; _g->words.w0 = 0xFCFFFFFF; _g->words.w1 = 0xFFFEF238; }
    }
    { Gfx *_g = D_800D0510++; _g->words.w0 = 0x0100E01C; _g->words.w1 = (u32) vtx; }
    { Gfx *_g = D_800D0510++; _g->words.w0 = 0xDE000000; _g->words.w1 = (u32) D_8650C288; }
    func_8003CD84();
  }
}
#endif

#ifdef VERSION_US
extern s32 D_8650C84C[], D_8650C868[];

extern s32 D_8650C4CC;

void func_86500780(s32 arg0, void *arg1) {
 s32 index;
 Vtx *vtx;
 s32 i;
 s32 j = 0;
 struct Fragment53ActorState *st;
 f32 scale;
 u32 v = *(u32 *)((u8 *)arg1 + 0x14);
 if (v < 2) index = 0;
 else if (v < 4) index = 1;
 else if (v < 6) index = 2;
 else if (v < 8) index = 3;
 st = &D_86511698[index];
 if ((*(s32 *)((u8 *)st + 0x54) == 1) && !(v & 1)) j = 1;
 if ((*(s32 *)((u8 *)st + 0x54) == 2) && ((v & 1) == 1)) j = 1;
 if ((arg0 == 5) && !j) {
  vtx = Gfx_AllocDisplayList(224);
  scale = 1.0f;
  if (*(s32 *)((u8 *)st + 0x54) == 3) {
   scale = 0.5f;
   if (!(*(u32 *)((u8 *)arg1 + 0x14) & 1)) {
    *(f32 *)((u8 *)st + 0x64) = D_8650C4CC / *(s32 *)((u8 *)st + 0x38);
    *(s32 *)((u8 *)st + 0x5C) = 980;
   } else {
    *(f32 *)((u8 *)st + 0x64) = D_8650C4CC / (D_8650C4CC - *(s32 *)((u8 *)st + 0x38));
    *(s32 *)((u8 *)st + 0x5C) = -980;
   }
  }
  for (i = 0; i < 14; i++) vtx[i] = D_8650C160[i];
  scale *= 35.0f;
  for (j = 0; j < 7; j++) {
   vtx[D_8650C84C[j]].v.ob[1] = *(s32 *)((u8 *)st + 0x5C) + scale;
   vtx[D_8650C868[j]].v.ob[1] = *(s32 *)((u8 *)st + 0x5C) - scale;
  }
  gSPVertex(D_800D0510++, vtx, 14, 0);
  gSPDisplayList(D_800D0510++, D_8650C348);
  func_8003CD84();
 }
}
#endif

#ifdef VERSION_US
/* mkdraft:func_86500D5C begin */
extern Gfx *D_800D0510;
extern Gfx D_8650CEA8[];
extern Vtx D_8650BFC0;
extern Vtx D_8650BFD0;
extern Vtx D_8650BFE0;
extern Vtx D_8650BFF0;
extern u8 D_8650DB80[];
extern void *Gfx_AllocDisplayList(s32 arg0);
extern void func_8003CD84(void);



void func_86500D5C(s32 arg0, void *arg1) {
    typedef struct {
        u8 pad[0x28];
        f32 height;
        u8 rest[0x13C];
    } ModelA;
    // FAKE: decomp slop. Every use of zero_index is a constant zero index, so IDO folds
    // all three away and emits no instructions for the declaration, the assignment or the
    // subscripts. The bindings nevertheless claim $3 (v1) while the D_8650DB80 address is
    // live; that is what moves the base into $4 (a0) and the 0x168 stride constant into
    // $6 (a2) in block B. Without the three uses the score is 50 (9 diff rows, all
    // register-color changes: li/lui/addiu/multu/addu of the first subscript and the
    // multu/addu pair of each later subscript reuse).
    unsigned short zero_index;
    Vtx *vtx;

    if (arg0 == 5) {
        vtx = (Vtx *)Gfx_AllocDisplayList(0x40);
        if (((ModelA *)D_8650DB80)[*(s32 *)((u8 *)arg1 + 0x14)].height > 200.0f) {
            vtx[0] = D_8650BFC0;
            vtx[1] = D_8650BFD0;
            vtx[2] = D_8650BFE0;
            vtx[3] = D_8650BFF0;
            zero_index = 0;
            vtx[zero_index].v.ob[zero_index] = (s16)(vtx[zero_index].v.ob[zero_index] - ((ModelA *)D_8650DB80)[*(s32 *)((u8 *)arg1 + 0x14)].height);
            vtx[3].v.ob[zero_index] = (s16)(vtx[3].v.ob[zero_index] - ((ModelA *)D_8650DB80)[*(s32 *)((u8 *)arg1 + 0x14)].height);
        }
        gSPDisplayList(D_800D0510++, D_8650CEA8);
        func_8003CD84();
    }
}
/* mkdraft:func_86500D5C end */
#endif

#ifdef VERSION_US
/* mkdraft:func_86500EF8 begin */
extern Gfx *D_800D0510;
extern s32 D_8650CFB0[];
extern s32 D_8650CFC0;
extern u8 D_865116F0[];
extern Gfx D_8650CF18[];
extern Gfx D_8650CF98[];
extern s32 func_8004C990(s32, s32);
extern u8 *func_8004CA60(u8 *);
extern void func_8003CD84(void);



void func_86500EF8(s32 arg0, u8 *arg1)
{
    s32 texture_index;
    s32 frame;
    s32 texture;
    // FAKE: without this pointer (reading and writing D_8650CFC0 directly) the
    // store's address setup moves and the diff score is 893.
    s32 *frame_counter;
    Gfx *pkt;

    texture_index = *(s32 *)(arg1 + 0x14);
    if (arg0 == 5) {
        gDPPipeSync(D_800D0510++);
        if (*(s32 *)(arg1 + 0x14) == 4) {
            // D_8650CFC0 counts 0..23; D_8650CFB0 holds one texture per six frames.
            frame_counter = &D_8650CFC0;
            frame = *frame_counter + 1;
            if (frame >= 24) {
                frame = 0;
            }
            // FAKE: one comma expression keeps the counter store ahead of the
            // D_8650CFB0 load; splitting it into two statements scores 120.
            texture = D_8650CFB0[frame / 6], *frame_counter = frame;
        } else {
            texture = D_8650CFB0[*(s32 *)(D_865116F0 + texture_index * 0x98) / 6];
        }
        gDPSetCombine(D_800D0510++, 0xFFFFFF, 0xFFFCF238);
        pkt = D_800D0510++;
        gSPSegment(pkt, 15, func_8004CA60((u8 *)func_8004C990(0x18D, texture)));
        gDPSetTextureImage(D_800D0510++, G_IM_FMT_RGBA, G_IM_SIZ_32b, 1, 0x0F000000);
        gDPSetTile(D_800D0510++, G_IM_FMT_RGBA, G_IM_SIZ_32b, 0, 0, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
        gDPLoadSync(D_800D0510++);
        gDPLoadBlock(D_800D0510++, G_TX_LOADTILE, 0, 0, 679, 0);
        gDPPipeSync(D_800D0510++);
        gDPSetTile(D_800D0510++, G_IM_FMT_RGBA, G_IM_SIZ_32b, 10, 0, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
        gDPSetTileSize(D_800D0510++, G_TX_RENDERTILE, 0, 0, 156, 64);
        gSPVertex(D_800D0510++, D_8650CF18, 8, 0);
        gSP2Triangles(D_800D0510++, 0, 1, 2, 0, 0, 2, 3, 0);
        gDPSetTextureImage(D_800D0510++, G_IM_FMT_RGBA, G_IM_SIZ_32b, 1, 0x0F000A00);
        gDPSetTile(D_800D0510++, G_IM_FMT_RGBA, G_IM_SIZ_32b, 0, 0, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
        gDPLoadSync(D_800D0510++);
        gDPLoadBlock(D_800D0510++, G_TX_LOADTILE, 0, 0, 679, 0);
        gDPPipeSync(D_800D0510++);
        gDPSetTile(D_800D0510++, G_IM_FMT_RGBA, G_IM_SIZ_32b, 10, 0, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
        gDPSetTileSize(D_800D0510++, G_TX_RENDERTILE, 0, 0, 156, 64);
        gSP2Triangles(D_800D0510++, 4, 5, 6, 0, 4, 6, 7, 0);
        gSPDisplayList(D_800D0510++, D_8650CF98);
        func_8003CD84();
    }
}
/* mkdraft:func_86500EF8 end */
#endif

#ifdef VERSION_US
extern s32 D_8650C4DC;
extern s32 D_8650D9D4;
s32 func_8650123C(s32 arg0, s32 arg1) {
    s32 var_v1;

    var_v1 = (D_8650D9D4 + D_8650C4DC) - arg0;
    if (D_8650D9D4 >= arg0) {
        var_v1 = -0xA;
    }
    if (arg0 >= (D_8650D9D4 + 0xA)) {
        var_v1 = -0xA;
    }
    return var_v1;
}
#endif

#ifdef VERSION_US
extern s32 D_8650C4D4;
extern s32 D_8650C4DC;
extern s32 D_8650C45C[];
extern s32 D_8650C470;
extern s32 D_8650C5CC[];
extern s32 D_8650C5E0;
extern s32 D_8650C5F8;
extern s32 D_8650D9D4;
extern u32 func_8003570C(void);
// Words of the per-player actor records, addressed through D_86511698 so that
// IDO knows the stores do not alias the score globals.
#define ACT_F18(i) (*(s32 *)((u8 *)&D_86511698[i] + 0x18))
#define ACT_F1C(i) (*(s32 *)((u8 *)&D_86511698[i] + 0x1C))
#define ACT_F90(i) (*(s32 *)((u8 *)&D_86511698[i] + 0x90))
#define ACT_F94(i) (*(s32 *)((u8 *)&D_86511698[i] + 0x94))
// Sets word 0x1C of each active player's record from its level
// (D_8650C45C) and random rolls. Declared s32 like its callers' prototypes, but it returns no
// value (a void return type changes func_86508A14's codegen).
s32 func_86501280(void) {
    s32 i;
    s32 step;
    s32 tier;
    s32 roll;

    for (i = 0; i < 4; i++) {
        ACT_F1C(i) = 0;
    }
    for (i = 0; i < 4; i++) {
        if (D_8650C45C[i] == 0) {
            continue;
        }
        roll = (func_8003570C() % 0x4F + D_8650C5F8);
        roll = roll - (roll / 10) * 10;
        tier = ACT_F90(i) / 3;
        if (D_8650C470 != 3) {
            continue;
        }
        step = 1;
        switch (D_8650C45C[i]) {
        case 1:
            if (func_8003570C() % 0xC9 > 0x1E) {
                step = -1;
            }
            if (roll >= tier + 6) {
                ACT_F1C(i) = D_8650D9D4 + D_8650C4DC;
            } else if (roll >= tier + 4) {
                ACT_F1C(i) = D_8650D9D4 + D_8650C4DC + step;
            } else if (roll >= tier + 2) {
                ACT_F1C(i) = D_8650D9D4 + D_8650C4DC + step * 2;
            } else {
                ACT_F1C(i) = D_8650D9D4 + D_8650C4DC + step * 3;
            }
            if (D_8650D9D4 + D_8650C4DC < ACT_F1C(i)) {
                if (tier + 6 < 7) {
                    ACT_F1C(i) = D_8650D9D4 + D_8650C4DC - guRandom() % 2 - 1;
                } else {
                    ACT_F1C(i) = D_8650D9D4 + D_8650C4DC - guRandom() % 3 - 1;
                }
            }
            if (ACT_F1C(i) < D_8650D9D4) {
                ACT_F1C(i) = D_8650D9D4 + guRandom() % 4;
            }
            if (roll >= 3) {
                if (ACT_F1C(i) < D_8650D9D4) {
                    ACT_F1C(i) = func_8003570C() % 3 + D_8650D9D4;
                }
                if (D_8650D9D4 + D_8650C4DC < ACT_F1C(i)) {
                    ACT_F1C(i) = D_8650D9D4 + D_8650C4DC - func_8003570C() % 3 - 1;
                }
            }
            if (D_8650D9D4 + D_8650C4DC == ACT_F1C(i)) {
                if (D_8650C5CC[D_8650C45C[i]] + 10 < ACT_F18(i) + 0x14) {
                    ACT_F1C(i) = D_8650D9D4 + D_8650C4DC - guRandom() % 2 - 1;
                }
            }
            break;
        case 2:
            if (func_8003570C() % 0xC9 > 0x28) {
                step = -1;
            }
            if (roll >= tier + 8) {
                ACT_F1C(i) = D_8650D9D4 + D_8650C4DC;
            } else if (roll > tier + 6) {
                ACT_F1C(i) = D_8650D9D4 + D_8650C4DC + step;
            } else if (roll > tier + 4) {
                ACT_F1C(i) = D_8650D9D4 + D_8650C4DC + step * 2;
            } else if (roll > tier + 2) {
                ACT_F1C(i) = D_8650D9D4 + D_8650C4DC + step * 3;
            } else {
                ACT_F1C(i) = D_8650D9D4 + D_8650C4DC + step * 4;
            }
            if (roll >= 2) {
                if (D_8650D9D4 + D_8650C4DC < ACT_F1C(i)) {
                    if (ACT_F90(i) >= 3) {
                        ACT_F1C(i) = D_8650D9D4 + D_8650C4DC - guRandom() % 4 - 1;
                    } else {
                        ACT_F1C(i) = D_8650D9D4 + D_8650C4DC - guRandom() % 4 - 1;
                    }
                }
                if (ACT_F1C(i) < D_8650D9D4) {
                    ACT_F1C(i) = guRandom() % 3 + D_8650D9D4 + 1;
                }
            }
            if (ACT_F1C(i) < D_8650D9D4) {
                ACT_F1C(i) = guRandom() % 3 + D_8650D9D4 + 1;
            }
            if (D_8650D9D4 + D_8650C4D4 < ACT_F1C(i)) {
                ACT_F1C(i) = guRandom() % 3 + D_8650D9D4 + D_8650C4DC + 1;
            }
            if (D_8650D9D4 + D_8650C4DC == ACT_F1C(i)) {
                if (D_8650C5CC[D_8650C45C[i]] + 10 < ACT_F18(i) + 0x14) {
                    ACT_F1C(i) = D_8650D9D4 + D_8650C4DC - guRandom() % 2 - 1;
                }
            }
            break;
        case 3:
            if (func_8003570C() % 0xC9 > 0x28) {
                step = -1;
            }
            if (roll >= tier + 8) {
                ACT_F1C(i) = D_8650D9D4 + D_8650C4DC + 1;
            } else if (roll >= tier + 6) {
                ACT_F1C(i) = D_8650D9D4 + D_8650C4DC + step;
            } else if (roll >= tier + 4) {
                ACT_F1C(i) = D_8650D9D4 + D_8650C4DC + step * 2;
            } else if (tier < roll) {
                ACT_F1C(i) = D_8650D9D4 + D_8650C4DC + step * 3;
            } else {
                ACT_F1C(i) = D_8650D9D4 + D_8650C4DC + step * 4;
            }
            if (roll >= 3) {
                if (D_8650D9D4 + D_8650C4D4 < ACT_F1C(i)) {
                    ACT_F1C(i) = D_8650D9D4 + D_8650C4DC - guRandom() % 2 - 1;
                }
                if (ACT_F1C(i) < D_8650D9D4) {
                    ACT_F1C(i) = guRandom() % 3 + D_8650D9D4 + 1;
                }
            }
            break;
        case 4:
            if (func_8003570C() % 0xC9 > 0x6E) {
                step = -1;
            }
            if (roll > tier + 9) {
                ACT_F1C(i) = D_8650D9D4 + D_8650C4DC + 1;
            } else if (roll > tier + 7) {
                ACT_F1C(i) = D_8650D9D4 + D_8650C4DC + step;
            } else if (roll >= 6) {
                ACT_F1C(i) = D_8650D9D4 + D_8650C4DC + step * 2;
            } else if (roll >= 4) {
                ACT_F1C(i) = D_8650D9D4 + D_8650C4DC + step * 3;
            } else if (roll >= 3) {
                ACT_F1C(i) = D_8650D9D4 + D_8650C4DC + step * 4;
            } else {
                ACT_F1C(i) = D_8650D9D4 + D_8650C4DC + step * 5;
            }
            break;
        }
        if (D_8650C5E0 >= 4) {
            if (ACT_F18(i) + func_8650123C(ACT_F1C(i), i) <= 0) {
                if (ACT_F1C(i) < D_8650D9D4) {
                    ACT_F1C(i) = D_8650D9D4 + D_8650C4DC - (func_8003570C() & 3) - 1;
                }
                if (D_8650D9D4 + D_8650C4DC < ACT_F1C(i)) {
                    ACT_F1C(i) = D_8650D9D4 + D_8650C4DC - (func_8003570C() & 3) - 1;
                }
                if (ACT_F18(i) + func_8650123C(ACT_F1C(i), i) <= 0) {
                    if (ACT_F1C(i) < D_8650D9D4) {
                        ACT_F1C(i) = D_8650D9D4 + 2;
                    }
                    if (D_8650D9D4 + D_8650C4DC < ACT_F1C(i)) {
                        ACT_F1C(i) = D_8650D9D4 + D_8650C4DC - 2;
                    }
                }
            }
        }
        if (D_8650C5CC[D_8650C45C[i]] < ACT_F18(i)) {
            ACT_F1C(i) = D_8650D9D4 + D_8650C4DC + guRandom() % 6 + 2;
            if (D_8650D9D4 + D_8650C4DC == ACT_F1C(i)) {
                if (ACT_F94(i) >= 2) {
                    ACT_F1C(i) = guRandom() % 2 + D_8650D9D4 + D_8650C4DC + 1;
                }
            }
        }
    }
}
#undef ACT_F18
#undef ACT_F1C
#undef ACT_F90
#undef ACT_F94
#endif

#ifdef VERSION_US
extern s32 D_8650C498;
extern s32 D_8650C4B4;
extern f64 D_8650D678;
extern s32 D_8650C4AC;
extern f32 D_8650C4B8;
extern s32 D_8650C4CC;
extern s32 D_8650C4D4;
extern s32 D_8650D9D4;
void Fragment53_CountTrajectorySamplesInRange(void) {
    s32 i;
    f32 position;

    D_8650C4D4 = 0;
    D_8650C4B4 = D_8650C498 - D_8650C4CC - 10;
    for (i = 0; i < 100; i++) {
        position = (f32)((f64)D_8650C4AC - D_8650D678 * (f64)D_8650C4B8 * (f64)D_8650C4B8 * (f64)(D_8650D9D4 + i + 2) * (f64)(D_8650D9D4 + i + 2));
        if (!(position < (f32)D_8650C4B4) && !((f32)D_8650C498 < position)) {
            D_8650C4D4++;
        }
    }
}
#endif

#ifdef VERSION_US
extern s32 D_8650C634;
extern s32 D_8650C4D4;
extern s32 D_8650C4DC;
extern u32 func_8003570C(void);
void Fragment53_SelectDifficultyOffset(void) {
    s32 maximum;
    s32 minimum;

    /* Difficulty is 0..4; preserve the original lack of an invalid-mode fallback. */
    switch (D_8650C634) {
    case 0:
        minimum = 2;
        maximum = D_8650C4D4 - 4;
        break;
    case 1:
        minimum = 1;
        maximum = D_8650C4D4 - 3;
        break;
    case 2:
        minimum = 2;
        maximum = D_8650C4D4 - 4;
        break;
    case 3:
        minimum = 4;
        maximum = D_8650C4D4 - 6;
        break;
    case 4:
        minimum = 4;
        maximum = D_8650C4D4 - 7;
        break;
    }
    D_8650C4DC = func_8003570C() % (maximum + 1) + minimum;
}
#endif

void func_86501F98(void) {
}

#ifdef VERSION_US
extern s32 StageContext_GetFadeMode(void);
extern s32 StageFade_StartFromOpaque(s32);
extern void func_87F00688(void);
extern s32 D_8650C5EC;
extern f32 D_8650C4D8;
extern s32 D_8650C4DC;
extern s32 D_8650C620;
extern void Fragment53_SelectDifficultyOffset(void);
void Fragment53_UpdateTrajectoryPosition(void) {
    if (D_8650C5EC == 10) {
        D_8650C4DC++;
        if (D_8650C4DC >= D_8650C4D4 - 2) {
            D_8650C4DC = 2;
        }
        if (D_8650C4DC < 2) {
            D_8650C4DC = 2;
        }
    } else {
        Fragment53_SelectDifficultyOffset();
    }
    D_8650C4D8 = (f32)(92.0 - ((f64)D_8650C4AC - 4.9 * (f64)D_8650C4B8 * (f64)D_8650C4B8 * (f64)(D_8650D9D4 + D_8650C4DC + 2) * (f64)(D_8650D9D4 + D_8650C4DC + 2)));
    D_8650C620 = (s32)(D_8650C4D8 / (f32)D_8650C4CC * 2000.0f + -1000.0f);
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/53/fragment53_code/func_865020D8.s")
#endif

#ifdef VERSION_US
extern s32 D_8650C474;
extern s32 D_8650C498;
extern s32 D_8650C4B4;
extern s32 D_8650C4AC;
extern f32 D_8650C4B8;
extern s32 D_8650C4CC;
extern s32 D_8650D9D4;
extern f32 D_8650C4F4;
extern void func_865020D8(void);
// Four loader-cleared 0x168-byte models (scale at +0x30). Retail shares one
// lui between the +0x34/+0x30 stores, which only a section-relative static
// gives; datamig_bss.ld pins this object's .bss at 0x86510010.
static u8 D_86510010[0x5A0];
extern f32 sqrtf(f32);
#pragma intrinsic(sqrtf)
void func_86502524(void) {
    s32 i;
    D_8650C498 = D_8650C474 + 0x5C;
    D_8650C4B4 = D_8650C498 - D_8650C4CC - 10;
    D_8650D9D4 = (s32)(sqrtf((f32)((f64)(D_8650C4AC - D_8650C498) / 4.9)) / D_8650C4B8 + 1.0f - 2.0f);
    func_865020D8();
    for (i = 0; i < 4; i++) {
        *(f32 *)(D_86510010 + i * 0x168 + 0x38) = D_8650C4F4;
        *(f32 *)(D_86510010 + i * 0x168 + 0x34) = D_8650C4F4;
        *(f32 *)(D_86510010 + i * 0x168 + 0x30) = D_8650C4F4;
    }
}
#endif

#ifdef VERSION_US
extern f32 D_8650C4B8;
extern f32 D_8650C508;
extern s32 D_8650C634;
extern s32 D_8650D0A4;
void func_86502620(void) {
    if (D_8650C634 == 0) {
        D_8650D0A4 = 2;
    } else {
        D_8650D0A4 = D_8650C634;
    }
    switch (D_8650D0A4) {                           /* irregular */
    case 1:
        D_8650C4B8 = (f32) ((f64) D_8650C508 * 0.45);
        return;
    case 2:
        D_8650C4B8 = (f32) ((f64) D_8650C508 * 0.4);
        return;
    case 3:
        D_8650C4B8 = (f32) ((f64) D_8650C508 * 0.35);
        return;
    case 4:
        D_8650C4B8 = (f32) ((f64) D_8650C508 * 0.3);
        return;
    }
}
#endif

#ifdef VERSION_US
extern f32 D_8650D0A0;
extern f32 D_8650D09C;
extern f32 D_8650D094;
extern f32 D_8650D098;
extern s32 D_8650C4CC;
extern s32 D_8650C4AC;
extern s32 D_8650C5E0;
extern s32 D_8650D0A8;
extern s32 D_8650D9D8;
extern u8 D_8650D9F8[];
struct Fragment53ModelPos {
    u8 pad0[0x1E];
    s16 rotY;
    u8 pad20[2];
    s16 unk22;
    f32 x;
    f32 y;
    f32 z;
    u8 rest[0x168 - 0x30];
};
extern struct Fragment53ModelPos D_8650F200[];
extern u8 D_865105B0[];
extern u8 D_865110F0[];
extern u8 D_865118F8[];
extern u32 func_8003570C(void);
extern void func_87F034CC(void *);
extern void func_86502524(void);
extern s32 func_86501280(void);
extern void func_8003F1DC(void *);
void Fragment53_InitRoundState(void) {
    s32 i;
    s32 j;
    f32 initial;
    f32 zero;

    func_86502620();
    initial = 10000.0f;
    zero = 0.0f;
    for (i = 0; i < 4; i++) {
        *(s32 *)((u8 *)&D_86511698[i] + 4) = 0;
        *(s32 *)((u8 *)&D_86511698[i] + 8) = 0;
        *(s32 *)((u8 *)&D_86511698[i] + 0x3C) = 0;
        *(f32 *)((u8 *)&D_86511698[i] + 0x14) = initial;
        *(s32 *)((u8 *)&D_86511698[i] + 0x1C) = 0;
        *(s32 *)((u8 *)&D_86511698[i] + 0x20) = 0;
        *(s32 *)((u8 *)&D_86511698[i] + 0) = -1;
        *(s32 *)((u8 *)&D_86511698[i] + 0x2C) = 10000;
        *(s32 *)((u8 *)&D_86511698[i] + 0x38) = D_8650C4CC + 20;
        *(s32 *)((u8 *)&D_86511698[i] + 0x40) = 0;
        *(s32 *)((u8 *)&D_86511698[i] + 0x44) = 0;
        *(s32 *)((u8 *)&D_86511698[i] + 0x50) = func_8003570C() % 4;
        *(s32 *)((u8 *)&D_86511698[i] + 0x54) = 0;
        *(s32 *)((u8 *)&D_86511698[i] + 0x58) = func_8003570C() % 24;
        *(s32 *)((u8 *)&D_86511698[i] + 0x60) = 0;
        *(s32 *)((u8 *)&D_86511698[i] + 0x5C) = 0;
        *(f32 *)((u8 *)&D_86511698[i] + 0x64) = zero;
        *(f32 *)((u8 *)&D_86511698[i] + 0x68) = D_8650D0A0;
        *(f32 *)((u8 *)&D_86511698[i] + 0x6C) = D_8650D09C;
        *(f32 *)((u8 *)&D_86511698[i] + 0x70) = D_8650D094;
        *(f32 *)((u8 *)&D_86511698[i] + 0x74) = D_8650D098;
        if ((guRandom() & 1) == 0) {
            *(s32 *)((u8 *)&D_86511698[i] + 0x78) = -1;
        } else {
            *(s32 *)((u8 *)&D_86511698[i] + 0x78) = 1;
        }
        *(s32 *)((u8 *)&D_86511698[i] + 0x80) = 0;
        *(s32 *)((u8 *)&D_86511698[i] + 0x84) = 0;
    }
    *(s32 *)((u8 *)&D_8650C5E0 + 4) = 0;
    *(s32 *)((u8 *)&D_8650C5E0 + 0x14) = D_8650C4AC;
    *(s32 *)((u8 *)&D_8650C5E0 + 0x10) = 0;
    *(s32 *)((u8 *)&D_8650C5E0 + 0x30) = 0;
    *(s32 *)((u8 *)&D_8650C5E0 + 0x38) = 0;
    *(s32 *)((u8 *)&D_8650C5E0 + 0x3C) = 0;
    *(s32 *)((u8 *)&D_8650C5E0 + 0x40) = 0;
    *(s32 *)((u8 *)&D_8650C5E0 + 0x44) = 5;
    *(s32 *)((u8 *)&D_8650C5E0 + 0x48) = 5;
    func_87F034CC(D_8650D9F8);
    func_86502524();
    *(s32 *)((u8 *)&D_8650C5E0 + 0x50) = 0;
    D_8650D0A8 = 0;
    func_86501280();
    for (i = 0; i < 4; i++) {
        *(s16 *)((u8 *)D_8650F200 + i * 0x168 + 0x1E) = -512;
        func_8003F1DC((u8 *)D_8650F200 + i * 0x168);
        for (j = 0; j < 2; j++) {
            func_8003F1DC(D_865105B0 + i * 0x2D0 + j * 0x168);
        }
    }
    D_8650D9D8 = -70;
}
#endif

#ifdef VERSION_US
extern s32 D_8650D0A4;
extern s32 D_8650C49C[];
extern s32 D_8650D9E0[];
extern u8 D_8650D9F8[];
extern s32 D_8650C5E0;
extern u32 func_8003570C(void);
extern void func_87F034CC(void *);
extern void Fragment53_InitRoundState(void);
void Fragment53_InitActorStateAndOrder(void) {
    s32 i;
    s32 first;
    s32 second;
    s32 temporary;

    D_8650D0A4 = 4;
    for (i = 0; i < 4; i++) {
        *(s32 *)((u8 *)&D_86511698[i] + 0) = -1;
        D_86511698[i].score = 0;
        *(s32 *)((u8 *)&D_86511698[i] + 8) = 0;
        *(s32 *)((u8 *)&D_86511698[i] + 0x24) = func_8003570C() % 301;
        *(s32 *)((u8 *)&D_86511698[i] + 0x28) = 0;
        D_86511698[i].animation = 0;
        D_86511698[i].pending = 1;
        *(s32 *)((u8 *)&D_86511698[i] + 0x48) = 1;
        *(s32 *)((u8 *)&D_86511698[i] + 0x8C) = 0;
        temporary = -(-400 - func_8003570C() % 101);
        D_8650C49C[i] = temporary;
        *(s32 *)((u8 *)&D_86511698[i] + 0x7C) = temporary;
        *(s32 *)((u8 *)&D_86511698[i] + 0x90) = func_8003570C() % 5;
    }
    for (i = 0; i < 5; i++) {
        D_8650D9E0[i] = i;
    }
    for (i = 0; i < 10; i++) {
        first = guRandom() % 5;
        do {
            second = guRandom() % 5;
        } while (first == second);
        if (first != 0 && second != 0) {
            temporary = D_8650D9E0[first];
            D_8650D9E0[first] = D_8650D9E0[second];
            D_8650D9E0[second] = temporary;
        }
    }
    func_87F034CC(D_8650D9F8);
    *(s32 *)((u8 *)&D_8650C5E0 + 0x34) = 0;
    *(s32 *)((u8 *)&D_8650C5E0 + 0) = 0;
    *(s32 *)((u8 *)&D_8650C5E0 + 0x20) = 0;
    *(s32 *)((u8 *)&D_8650C5E0 + 0x4C) = 0;
    *(s32 *)((u8 *)&D_8650C5E0 + 0x58) = 0;
    Fragment53_InitRoundState();
}
#endif

#ifdef VERSION_US
extern s32 D_8650C600;
extern s32 D_8650C5E0;
extern void *D_8650DB10;
extern u8 D_8650DA70[];
extern u8 D_8650DA60[];
extern u8 D_865118F8[];
extern s32 D_8651171C;
extern s32 D_865117B4;
extern s32 D_8651184C;
extern s32 D_865118E4;
extern f32 D_8650D6DC;
extern void func_87F0C930(void *);
extern void Fragment64_StartPlayerPanel(void *, void *, s32, s32, s32, s32, s32);
extern void func_81900164(s32, s32, f32, f32, s32);


void func_86502B88(void)
{
  u32 maximum;
  s32 count;
  s32 values[4];
  s32 i;
  s32 score;
  count = 0;
  for (i = 0, maximum = D_8650C600; i < 4; i++)
  {
    D_86511698[i].result = 1;
    score = D_86511698[i].score;
    values[i] = 0;
    if (score >= (s32)maximum)
    {
      *((s32 *) (((u8 *) (&D_8650C5E0)) + 0x20)) = D_86511698[i].score;
      maximum = D_86511698[i].score;
    }
  }

  for (i = 0; i < 4; i++)
  {
    if (D_86511698[i].score == maximum)
    {
      values[i] = 1;
      count++;
      D_86511698[i].result = 2;
    }
  }

  if (count == 4)
  {
    for (i = 0; i < 4; i++)
    {
      D_86511698[i].result = 1;
    }

  }
  if ((*((u8 *) (((u8 *) D_8650DB10) + 0x2180))) == 4)
  {
    func_87F0C930(D_8650DA60);
    return;
  }
  Fragment64_StartPlayerPanel(D_8650DA70, D_8650DB10, 2, values[0], values[1], values[2], values[3]);
  for (i = 0; i != 4; i++)
  {
    if (D_86511698[i].score == 100)
    {
      func_81900164(*((s32 *) D_865118F8), *((s32 *) (((u8 *) (&D_8650E120[i])) + 0x24)), (*((f32 *) (((u8 *) (&D_8650E120[i])) + 0x28))) - 26.0f, 3.1f, i);
    }
  }

}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/53/fragment53_code/func_86502D80.s")
#endif

#ifdef VERSION_US
extern s32 D_8650C5E4;
extern s32 D_8650C4DC;
extern s32 D_8650C498;
extern s32 D_8650C4B4;
extern s32 D_8650C4AC;
extern s32 D_8650C4CC;
extern f32 D_8650C4B8;
extern f32 D_8650C4D8;
extern f32 D_8650C478;
extern f32 D_86511690;
extern s32 D_8650D9D4;
extern s32 D_8650D0D4[];
extern f32 D_8650D094, D_8650D098, D_8650D09C, D_8650D0A0;
extern u8 D_865105B0[];
extern void ModelAnim_SetFrame(u8 *, s16);
extern void func_80027A28(u16, u8);
extern u32 func_8003570C(void);

// Fragment53ActorState / fragment-53 entity fields accessed by raw offset.
#define ACTOR_S32(o) (*(s32 *)((u8 *)&D_86511698[arg0] + (o)))
#define ACTOR_F32(o) (*(f32 *)((u8 *)&D_86511698[arg0] + (o)))
#define ENTITY_F32(o) (*(f32 *)(D_865105B0 + arg0 * 0x2D0 + (o)))
void func_86503178(s32 arg0) {
    f32 height;
    f32 sum; // declared before ratio so ratio's stack home lands at sp+0x34
    f32 ratio;
    s32 diff;

    height = (f32)((f64)D_8650C4AC - 4.9 * (f64)D_8650C4B8 * (f64)D_8650C4B8 * (f64)(D_8650C5E4 + 2) * (f64)(D_8650C5E4 + 2));
    if (height < (f32)D_8650C4B4 || (f32)D_8650C498 < height) {
        if (ACTOR_S32(0x8) > 0) {
            ACTOR_S32(0x8) = 0;
        }
        ACTOR_S32(0x80) = -10;
        ACTOR_S32(0xC) = 4;
        ModelAnim_SetFrame((u8 *)&D_8650E120[arg0], 0);
        if (D_86511690 >= 92.0f) {
            ACTOR_S32(0x3C) = 1;
        }
        func_80027A28(0x1F01, (u8)arg0);
        return;
    }
    ACTOR_S32(0x80) = 0;
    diff = D_8650C4DC - D_8650C5E4 + D_8650D9D4;
    if (diff > 0) {
        ACTOR_S32(0x54) = 1;
    } else if (diff < 0) {
        ACTOR_S32(0x80) = diff;
        if (diff < -4) {
            ACTOR_S32(0x80) = -5;
        }
        ACTOR_S32(0x54) = 2;
    } else {
        ACTOR_S32(0x54) = 3;
    }
    if (diff < 0) {
        diff = -diff;
    }
    if (diff >= 0x10) {
        diff = 0xF;
    }
    ACTOR_S32(0x8) = D_8650D0D4[diff];
    if (ACTOR_S32(0x8) == 20) {
        ACTOR_S32(0x94)++;
    } else {
        ACTOR_S32(0x94) = 0;
    }
    ACTOR_F32(0x14) = height;
    ACTOR_S32(0x2C) = D_8650C5E4 + 2;
    if (ACTOR_S32(0x54) == 3) {
        func_80027A28(0x1F0C, (u8)arg0);
    } else {
        func_80027A28(0x1F00, (u8)arg0);
    }
    if (height > 0.0f) {
        ratio = 92.0f - height;
        ENTITY_F32(0x28) = (92.0f + height) / 2 + height;
        ENTITY_F32(0x34) = ratio / D_8650C478;
    } else {
        ratio = 92.0f - height;
        ENTITY_F32(0x28) = ratio / 2 + height;
        ENTITY_F32(0x34) = ratio / D_8650C478;
    }
    ACTOR_S32(0x38) = (s32)ratio;
    ratio = (f32)ACTOR_S32(0x38) / (f32)D_8650C4CC;
    ACTOR_F32(0x70) = (func_8003570C() / 4294967296.0f) * 0.5f + (D_8650D094 + ratio);
    ACTOR_F32(0x74) = (f32)(func_8003570C() % 31) + (D_8650D098 + 5.0f * ratio);
    ACTOR_F32(0x6C) = (f32)((f64)((func_8003570C() / 4294967296.0f) * 0.2f) + ((f64)D_8650D09C + 0.5 * (f64)ratio));
    ACTOR_F32(0x68) = (D_8650D0A0 + 4.0f * ratio) - (func_8003570C() / 4294967296.0f) * 0.5f;
    sum = (f32)D_8650C4CC + height; // named temp: retail keeps it in $f12
    height = sum - 92.0f;
    ratio = height / 2 + 92.0f;
    ENTITY_F32(0x190) = ratio;
    ENTITY_F32(0x19C) = height / D_8650C478;
    ACTOR_S32(0x30) = (s32)ENTITY_F32(0x28);
    ACTOR_S32(0x34) = (s32)ratio;
    ACTOR_S32(0xC) = 3;
    ModelAnim_SetFrame((u8 *)&D_8650E120[arg0], 0);
    ACTOR_S32(0x60) = 0x1000 - (ACTOR_S32(0x38) << 12) / D_8650C4CC;
    switch (ACTOR_S32(0x54)) {
    case 1:
        ACTOR_F32(0x64) = (f32)(D_8650C4CC / (D_8650C4CC - ACTOR_S32(0x38)));
        ACTOR_S32(0x5C) = (s32)((D_8650C4D8 - (f32)ACTOR_S32(0x38)) * (f32)D_8650C4CC / (f32)(D_8650C4CC - ACTOR_S32(0x38)) * 2000.0f / (f32)D_8650C4CC + -1000.0f);
        break;
    case 2:
        ACTOR_F32(0x64) = (f32)(D_8650C4CC / ACTOR_S32(0x38));
        ACTOR_S32(0x5C) = (s32)(1000.0f - ((f32)ACTOR_S32(0x38) - D_8650C4D8) * (f32)D_8650C4CC / (f32)ACTOR_S32(0x38) / (f32)D_8650C4CC * 2000.0f);
        break;
    case 3:
        break;
    }
}
#undef ACTOR_S32
#undef ACTOR_F32
#undef ENTITY_F32
#endif

#ifdef VERSION_US
extern void ModelAnim_SetAnimation(void *, s32);
extern void ModelAnim_SetFrame(u8 *, s16);
void Fragment53_ApplyPendingPrimaryAnimation(s32 arg0) {
    if (D_86511698[arg0].pending == 1) {
        ModelAnim_SetAnimation((u8 *)&D_8650E120[arg0], D_86511698[arg0].animation);
        ModelAnim_SetFrame((u8 *)&D_8650E120[arg0], 0);
        D_86511698[arg0].pending = 0;
    }
}
#endif

#ifdef VERSION_US
extern f32 D_86511690;
extern f32 D_8650F228[];
extern s32 D_8650C624;
extern s32 D_8650C4B0;
extern s32 D_8650C5E0;
extern void func_80027A28(u16,u8);
extern void ModelAnim_SetFrame(u8 *, s16);
extern void ModelAnim_SetAnimation(void *, s32);
void Fragment53_UpdatePrimaryAnimationState(s32 arg0) {
    s32 index;

    index = arg0;
    switch (D_86511698[index].animation) {
    case 2:
        D_86511698[index].pending = 1;
        D_86511698[index].animation = 1;
        break;
    case 4:
        D_86511698[index].pending = 1;
        D_86511698[index].animation = 1;
        *(s32 *)((u8 *)&D_86511698[index] + 4) = 0;
        *(s32 *)((u8 *)&D_86511698[index] + 0) = 0;
        if (D_86511690 < 100.0f) {
            D_86511698[index].animation = 7;
            func_80027A28(0x1F0A, (u8)index);
        }
        break;
    case 3:
        D_86511698[index].animation = 1;
        D_86511698[index].pending = 1;
        *(s32 *)((u8 *)&D_86511698[index] + 4) = 0;
        *(s32 *)((u8 *)&D_86511698[index] + 0) = -1;
        break;
    case 5:
        D_86511698[index].pending = 1;
        D_86511698[index].result = 0;
        D_86511698[index].animation = 0;
        break;
    case 6:
        if (D_8650C5E0 != D_8650C4B0) {
            D_86511698[index].pending = 1;
            D_86511698[index].animation = 0;
        }
        break;
    case 7:
        D_86511698[index].animation = 0;
        D_86511698[index].pending = 1;
        break;
    case 0:
        if (0.0f < *(f32 *)((u8 *)D_8650F228 + index * 0x168)) {
            if (D_8650C624 == 2) {
                D_86511698[index].animation = 2;
                D_86511698[index].pending = 1;
                func_80027A28(0x1F0A, (u8)index);
            }
        }
        if (D_86511698[index].result == 1) {
            D_86511698[index].animation = 6;
            ModelAnim_SetAnimation((u8 *)D_8650E120 + index * 0x168, 6);
            ModelAnim_SetFrame((u8 *)D_8650E120 + index * 0x168, 0);
        }
        if (D_86511698[index].result == 2) {
            D_86511698[index].animation = 5;
            ModelAnim_SetAnimation((u8 *)D_8650E120 + index * 0x168, 5);
            ModelAnim_SetFrame((u8 *)D_8650E120 + index * 0x168, 0);
        }
        break;
    case 1:
        if (D_86511690 < 100.0f) {
            D_86511698[index].pending = 1;
            D_86511698[index].animation = 7;
            func_80027A28(0x1F0A, (u8)index);
        }
        break;
    }
}
#endif

#ifdef VERSION_US
extern s32 D_8650C494;
extern s32 D_8650C4BC;
extern s32 D_8650C5E4;
extern s32 D_8650C5E8;
extern s32 D_8650C5EC;
extern s32 D_8650C610;
extern s32 D_8650C45C[];
struct Fragment53ControllerRecord {
    u8 pad[8];
    u16 buttonsPressed;
    u8 rest[0x1E];
};
extern struct Fragment53ControllerRecord D_800CE060[];
extern s32 D_8650DB50[];
extern s32 D_8650DB74;
extern s32 D_8650DB78;
extern f32 D_86511690;
extern u8 D_865105B0[];
extern u8 D_86510010[];
extern u32 func_8003570C(void);
extern void func_8003F114(void *, s32, s32, s32);
extern void func_8003F210(void *, s32);
extern void func_8003F1DC(void *);
extern void func_8003F3BC(void *, s32);
extern void func_80027A28(u16, u8);
extern void ModelAnim_SetEventFrame(u8 *, s16);
extern s32 ModelAnim_SetSpeed(u8 *, s32);
extern s32 ModelAnim_IsFinished(void *);
extern void func_86503178(s32);
extern void func_865038A8(s32);
extern void func_86503938(s32);


// Per-frame animation/controller update for actor slot arg1 (index read from arg1 + 0x14),
// run only for the kind-2 actor while D_8650C494 is not 1. Advances the animation timers,
// re-seeds the idle event frame, follows the model entry the current controller maps to
// (D_8650C5E4), and hands finished animations to func_86503938.
void func_86503B98(s32 arg0, u8 *arg1) {
    s32 index;
    s32 offset;
    struct Fragment53ActorState *state;
    u8 *entry;
    // FAKE: two unused locals pad the frame to the target's 0x40; without them the frame
    // is 0x38 and the saved arg1/index slots sit 8 bytes lower (diff score 162).
    s32 pad0;
    s32 pad1;

    index = *(s32 *)(arg1 + 0x14);
    if ((arg0 != 0) && (arg0 == 2) && (D_8650C494 != 1)) {
        ModelAnim_SetSpeed(arg1, D_8650C4BC << 0x10);
        state = &D_86511698[index];
        *(s32 *)((u8 *)state + 0x28) += 1;
        if ((*(s32 *)((u8 *)state + 0x24) < *(s32 *)((u8 *)state + 0x28)) && (*(s32 *)((u8 *)state + 0x28) >= 0x15)) {
            ModelAnim_SetEventFrame(arg1, 0);
            func_8003F3BC(&D_8650E120[index], 0);
            *(s32 *)((u8 *)state + 0x28) = 0;
            *(s32 *)((u8 *)state + 0x24) = func_8003570C() % 301;
        }
        offset = index * 0x168;
        if (*(s32 *)((u8 *)state + 0x20) > 0) {
            *(s32 *)((u8 *)state + 0) = 0;
            if ((D_86511690 <= 92.0f) && (*(s32 *)((u8 *)state + 0x3C) == 1)) {
                *(s32 *)((u8 *)state + 0x3C) = 2;
            } else if (*(s32 *)((u8 *)state + 0x3C) != 2) {
                *(s32 *)((u8 *)state + 0x20) += 1;
            }
            if ((*(s32 *)((u8 *)state + 0x20) >= 0x2E) || (D_8650C610 == 1)) {
                *(s32 *)((u8 *)state + 0x20) = 0;
                *(s32 *)((u8 *)state + 0x3C) = 0;
                *(s32 *)((u8 *)state + 0) = -1;
            }
        }
        if ((state->animation == 2) && (((s32)*(s32 *)(arg1 + 0x48) >> 16) == 0x21) && (state->kind == 0x37)) {
            func_80027A28(0x1F04, (u8)index);
        }
        if ((state->animation == 5) && (((s32)*(s32 *)(arg1 + 0x48) >> 16) == 0x35 || ((s32)*(s32 *)(arg1 + 0x48) >> 16) == 0x3C) && (state->kind == 0x37)) {
            func_80027A28(0x1F04, (u8)index);
        }
        if ((state->animation == 7) && (((s32)*(s32 *)(arg1 + 0x48) >> 16) == 0x10 || ((s32)*(s32 *)(arg1 + 0x48) >> 16) == 0x16) && (state->kind == 0x37)) {
            func_80027A28(0x1F04, (u8)index);
        }
        if ((((D_800CE060[index].buttonsPressed & 0x8000) && (*(s32 *)((u8 *)state + 0) == -1) && (*(s32 *)((u8 *)state + 8) == 0) && (D_8650C45C[index] == 0)) || ((D_8650C5E4 == *(s32 *)((u8 *)state + 0x1C)) && (*(s32 *)((u8 *)state + 0x1C) != 0))) && (D_8650C5EC == 1) && (D_8650C5E8 != -2) && (D_8650C610 == 0)) {
            *(s32 *)((u8 *)state + 0) = 2;
            *(s32 *)((u8 *)state + 4) = 1;
            func_86503178(index);
            state->pending = 1;
            if (*(s32 *)((u8 *)state + 8) == 0) {
                *(s32 *)((u8 *)state + 0x20) += 1;
            }
        }
        if (D_8650C5E4 == *(s32 *)((u8 *)state + 0x2C)) {
            func_8003F114(D_865105B0 + index * 0x2D0, 0, -1, *(s32 *)(D_8650DB50 + index * 2));
            func_8003F114(D_865105B0 + index * 0x2D0 + 0x168, 0, -1, *(s32 *)(D_8650DB50 + index * 2 + 1));
            entry = D_86510010 + offset;
            if (*(s32 *)((u8 *)state + 0x54) == 3) {
                entry = D_86510010 + offset;
                func_8003F114(entry, 0, -1, D_8650DB78);
            } else {
                func_8003F114(entry, 0, -1, D_8650DB74);
            }
            func_8003F210(entry, 0);
            ModelAnim_SetSpeed(entry, 0x10000);
        }
        if (((s32)*(s32 *)(D_86510010 + offset + 0x48) >> 16) == 0xF) {
            func_8003F1DC(D_86510010 + offset);
        }
        if (D_8650C5E4 == (*(s32 *)((u8 *)state + 0x2C) + 1)) {
            func_8003F1DC((u8 *)D_8650F200 + offset);
        }
        if (*(s32 *)((u8 *)state + 4) > 0) {
            *(s32 *)((u8 *)state + 4) += 1;
        }
        func_865038A8(index);
        if (ModelAnim_IsFinished(arg1) == 1) {
            func_86503938(index);
        }
    }
}

// The 8-byte stub the retail build leaves after func_86503B98 (jr ra / nop).

// Bytes at the retail stub address between the two functions: an
// unreferenced empty function compiles to the retail jr ra/nop pair
// there and keeps the fragment layout.
void func_86503B98_padding(void) {}
#endif

#ifdef VERSION_US
// Fragment 53 .data from 0x8650D130 (16-aligned) starts here; D_8650D130 is
// not referenced.
s32 D_8650D130 = 20;

extern s32 D_8650C5E0;
extern f32 D_8650C508;
extern s32 D_8650C49C[4];
extern s32 D_8650C4A0, D_8650C4A4, D_8650C4A8;
extern s32 D_8650C4AC;
extern s32 D_8650C4CC;
extern s32 D_8650C470;
extern s32 D_8650DB24;
extern s32 D_8650D13C[];
extern s32 D_865119B8[];
extern f32 D_86511690;
extern u8 D_8650DB80[];
extern u8 D_8650F7A0[];
extern u8 D_86511714[];
extern void func_8003F114(void *, s32, s32, s32);
extern void func_8003F1DC(void *);
extern u32 func_8003570C(void);
void func_865040E4(s32 arg0) {
    static f32 D_8650D134 = 0.0f;
    static s32 D_8650D138 = 0;
    s32 i;
    s32 v1;
    s32 t0;
    f32 f;

    switch (*(s32 *)((u8 *)&D_8650C5E0 + 0x44)) {
    case 5:
        D_8650D134 = 0.0f;
        *(s32 *)((u8 *)&D_8650C5E0 + 0x44) = 0;
        break;
    case 0:
        if (arg0 == 0) {
            D_8650D134 = (f32)((f64)D_8650D134 + 0.45);
        }
        D_8650C49C[arg0] = (s32)((f64)*(s32 *)(D_86511714 + arg0 * 0x98) - 4.9 * (f64)D_8650C508 * (f64)D_8650D134 * (f64)D_8650D134);
        if (D_8650C49C[arg0] < -0x1C2) {
            *(s32 *)((u8 *)&D_8650C5E0 + 0x44) = 1;
            for (i = 0; i < 4; i++) {
                func_8003F114((u8 *)D_8650F200 + i * 0x168, 0, -1, D_8650DB24);
                D_8650C49C[i] = -0x352 - D_8650C49C[i];
            }
        }
        break;
    case 1:
        if (arg0 == 0) {
            D_8650D138++;
        }
        if (D_8650D138 >= 6) {
            D_8650D138 = 0;
            *(s32 *)((u8 *)&D_8650C5E0 + 0x44) = 2;
            D_8650D134 = 0.0f;
        }
        D_865119B8[arg0] = 0;
        break;
    case 2:
        t0 = D_865119B8[arg0];
        if (t0 == 0) {
            f = 18.0f * D_8650C508;
            if (!f) {} // FAKE
            D_8650C49C[arg0] += (s32)(f + (f > 0.0f ? 0.5f : -0.5f));
            if (f == 0) {} // FAKE
        }
        v1 = 0;
        if (D_8650C49C[arg0] >= D_8650C4AC + D_8650C4CC + 15 || t0 > 0) {
            v1 = 1;
            if (D_8650C470 == 1) {
                D_8650C49C[arg0] = D_8650C4AC + D_8650C4CC + 15;
                *(f32 *)((u8 *)D_8650F228 + arg0 * 0x168) = (f32)D_8650C4AC;
                for (i = 0; i < 4; i++) {
                    if (D_8650C49C[i] < D_8650C4AC + D_8650C4CC + 15) {
                        v1 = 0;
                    }
                }
            }
            if (arg0 == 0) {} // FAKE
            if (D_8650C470 == 3) {
                if (t0 < 0x12) {
                    D_865119B8[arg0] = t0 + 1;
                    t0 = t0 + 1;
                    t0 = D_865119B8[arg0];
                }
                for (i = 0; i < 4; i++) {
                    if (D_865119B8[i] < 0x12) {
                        v1 = 0;
                    }
                }
                D_8650C49C[arg0] = D_8650D13C[t0];
            }
        }
        if (v1 == 1) {
            *(s32 *)((u8 *)&D_8650C5E0 + 0x44) = 4;
        }
        break;
    case 4:
        *(s32 *)((u8 *)&D_8650C5E0 + 8) = -1;
        *(s32 *)((u8 *)&D_8650C5E0 + 0x38) = 0;
        *(s32 *)((u8 *)&D_8650C5E0 + 0x34) = 1;
        D_86511690 = (f32)D_8650C4AC;
        for (i = 0; i < 4; i++) {
            v1 = 400 - -(s32)(func_8003570C() % 101);
            D_8650C49C[i] = v1;
            *(s32 *)((u8 *)&D_86511698[i] + 0x7C) = v1;
            func_8003F1DC(D_8650DB80 + i * 0x168);
            func_8003F1DC(D_8650F7A0 + i * 0x168);
        }
        break;
    case 3:
        break;
    }
}
#endif

#ifdef VERSION_US
extern s32 D_8650C494;
extern s32 D_8650C5E8;
extern s32 D_8650C49C[];
extern f32 D_8650DBA8[];
extern f32 D_8650F7C8[];
extern void func_865040E4(s32);
void Fragment53_UpdateActorModelHeights(s32 arg0, void *arg1) {
    s32 index;
    s32 height;
    s32 offset;

    index = *(s32 *)((u8 *)arg1 + 0x14);
    if (arg0 == 0) { return; }
    if (arg0 == 2) {
        if (D_8650C5EC == 1) {
            if (D_8650C494 == 0) {
                *(s32 *)((u8 *)&D_86511698[index] + 0x58) += 1;
                if (*(s32 *)((u8 *)&D_86511698[index] + 0x58) >= 24) { *(s32 *)((u8 *)&D_86511698[index] + 0x58) = 0; }
                func_865040E4(index);
            }
            offset = index * 0x168;
            if (D_8650C5E8 == -2) {
                height = D_8650C49C[index];
                *(f32 *)((u8 *)D_8650DBA8 + offset) = (f32)(height - 5);
                *(f32 *)((u8 *)D_8650F7C8 + offset) = (f32)(height + 60);
            } else {
                *(f32 *)((u8 *)D_8650DBA8 + offset) = (f32)D_8650C49C[index];
                *(f32 *)((u8 *)D_8650F7C8 + offset) = (f32)D_8650C49C[index];
            }
        }
    }
}
#endif

#ifdef VERSION_US
extern Gfx *D_800D0510;
extern Vtx D_8650C640[];
extern Gfx D_8650D430[];
extern void GeoRender_ApplyMaterialState();
s32 func_865046A8(s32 arg0, s32 arg1) {
    if (arg0 == 5) {
        gDPSetEnvColor(D_800D0510++, 255, 100, 100, 255);
        gSPVertex(D_800D0510++, D_8650C640, 4, 0);
        gSPDisplayList(D_800D0510++, D_8650D430);
        GeoRender_ApplyMaterialState();
    }
    return 0;
}
#endif

#ifdef VERSION_US
// D_8650D13C follows func_865040E4's function statics in .data.
s32 D_8650D13C[23] = {
    688, 698, 705, 710, 714, 717, 718, 717,
    716, 715, 713, 710, 706, 702, 698, 693,
    687, 680, 674, -800, -600, 600, 800,
};

extern s32 D_8650C49C[];
extern s32 D_8650C4C4;
extern s32 D_8650C4F0;
extern f32 D_8650C4F8;
extern f32 D_86511690;
extern f32 D_865119A0[];
extern f32 __sinf(f32);
extern f32 __cosf(f32);
typedef struct { u8 pad[0x14]; s32 idx; } F53Obj;
#define ACT4740(i, o) (*(s32 *)((u8 *)&D_86511698[i] + (o)))
void func_86504740(s32 arg0, F53Obj *arg1) {
    s32 v;
    static s32 D_8650D198 = 100;
    static f32 D_8650D19C = 60.0f;
    static f32 D_8650D1A0 = 10.0f;
    static s32 D_8650D1A4 = 120;
    static s32 D_8650D1A8 = 6;

    switch (arg0) {
    case 0:
        D_86511690 = D_8650C49C[arg1->idx] - D_8650C4CC - 20;
        do {} while (0); // FAKE
        D_8650F200[arg1->idx].y = D_86511690;
        D_8650F200[arg1->idx].unk22 = 0;
        break;
    case 2:
        if (*(s32 *)((u8 *)&D_8650C5E0 + 8) == -2) {
            D_86511690 = D_8650C49C[arg1->idx] - D_8650C4CC;
        }
        v = *(s32 *)((u8 *)&D_8650C5E0 + 0x30);
        if (v == 0 && ACT4740(arg1->idx, 0x3C) != 2) {
            D_8650F200[arg1->idx].y = (f32)D_8650C4C4 + D_86511690;
            return;
        }
        if (ACT4740(arg1->idx, 0x3C) == 2) {
            if (-3000.0f < D_8650F200[arg1->idx].y) {
                D_865119A0[arg1->idx] = D_865119A0[arg1->idx] + 0.6;
            }
            if (D_8650C4F0 == 1) {
                D_8650F200[arg1->idx].rotY = D_8650F200[arg1->idx].rotY + 64.0f * D_8650C4F8;
            }
            D_8650F200[arg1->idx].y = ((f64)(D_8650D1A4 + 0x5C) + 4.9 * (f64)D_8650D1A8 * (f64)D_8650D1A8)
                - (4.9 * (f64)D_8650C508 * (f64)(D_865119A0[arg1->idx] - (f32)D_8650D1A8)) * (f64)(D_865119A0[arg1->idx] - (f32)D_8650D1A8);
            if (D_8650C4F0 == 1) {
                switch ((u32)arg1->idx) {
                case 0:
                    D_8650F200[arg1->idx].x -= D_8650F200[arg1->idx].y / D_8650D198 * __sinf(D_8650D19C / 360.0 * 6.14);
                    D_8650F200[arg1->idx].z += D_8650F200[arg1->idx].y / D_8650D198 * __cosf(D_8650D19C / 360.0 * 6.14);
                    break;
                case 1:
                    D_8650F200[arg1->idx].x -= D_8650F200[arg1->idx].y / D_8650D198 * __sinf(D_8650D1A0 / 360.0 * 6.14);
                    D_8650F200[arg1->idx].z += D_8650F200[arg1->idx].y / D_8650D198 * __cosf(D_8650D1A0 / 360.0 * 6.14);
                    break;
                case 2:
                    D_8650F200[arg1->idx].x += D_8650F200[arg1->idx].y / D_8650D198 * __sinf(D_8650D1A0 / 360.0 * 6.14);
                    D_8650F200[arg1->idx].z += D_8650F200[arg1->idx].y / D_8650D198 * __cosf(D_8650D1A0 / 360.0 * 6.14);
                    break;
                case 3:
                    D_8650F200[arg1->idx].x += D_8650F200[arg1->idx].y / D_8650D198 * __sinf(D_8650D19C / 360.0 * 6.14);
                    D_8650F200[arg1->idx].z += D_8650F200[arg1->idx].y / D_8650D198 * __cosf(D_8650D19C / 360.0 * 6.14);
                    break;
                }
            }
        }
        break;
    }
}
#endif
