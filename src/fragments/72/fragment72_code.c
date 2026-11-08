#include "global.h"



#ifdef VERSION_US
/* Playback resources used by func_8F400C58 and released by case 3 below. */
typedef struct Fragment72PlaybackResources {
    s32 handle;
    void *model;
} Fragment72PlaybackResources;
static Fragment72PlaybackResources sPlaybackResources;

extern u8 D_8F4020C0;
extern s16 D_8F4020C2;
extern s32 D_8F4020C8;
extern s32 D_8F4020D0;
extern s32 D_8F4020DC;
extern s32 D_8F4020E0;
extern s32 D_8F4020E4;
extern s16 D_8F4020E8;
extern s16 D_8F4020F4;
extern s16 D_8F4020F8;
extern void *ModelPreview_Create();
extern s32 func_80042D54(u8 *arg0, u16 arg1);
extern s32 func_80042FBC(void *state, s32 species);

// D_8F4020C0 is the base of an unnamed struct: an s16 at +0x2 and the
// ModelPreview pointer at +0xC whose u16 flags the three masks below clear.
// func_8F401918 in this file reads the same object through a u8 * base.


void func_8F400020(void) {
    s32 state_index;
    s32 width;
    s32 height;
    u8 *state;

    for (state_index = 0; state_index < 8; state_index += 4) {
        *((s16 *)(&D_8F4020C0 + state_index * 2) + 22) = 1;
        *((s16 *)(&D_8F4020C0 + state_index * 2) + 23) = 1;
        *((s16 *)(&D_8F4020C0 + state_index * 2) + 24) = 1;
        *((s16 *)(&D_8F4020C0 + state_index * 2) + 25) = 1;
    }
    switch (*((s16 *)&D_8F4020C0)) {
    case 0:
        width = 118;
        height = 144;
        D_8F4020E4 = D_8F4020DC;
        break;
    case 1:
        width = 132;
        height = 105;
        D_8F4020E4 = 0;
        D_8F4020F4 = 0;
        D_8F4020F8 = 0;
        break;
    case 3:
        width = 80;
        height = 80;
        D_8F4020E4 = D_8F4020E0;
        break;
    default:
        width = 40;
        height = 40;
        D_8F4020E4 = 0;
        D_8F4020F4 = 0;
        break;
    }
    state = (u8 *)&D_8F4020C0;
    D_8F4020D0 = 0;
    *(void **)(state + 0xC) = ModelPreview_Create((void *)D_8F4020C8, width, height);
    if (*(s16 *)state == 2) {
        func_80042D54(*(u16 **)(state + 0xC), 0x7BDF);
    }
    *(*(u16 **)(state + 0xC)) &= 0xFFFD;
    *(*(u16 **)(state + 0xC)) &= 0xFEFF;
    if (*(s16 *)state != 1) {
        *(*(u16 **)(state + 0xC)) &= 0xFFFB;
    }
    func_80042FBC(*(u16 **)(state + 0xC), *((s16 *)(state + 2)));
    D_8F4020E8 = 0;
}

extern void Dma_CopyChunks(s32, s32, s32);
s32 func_800356CC(s32);
extern s32 D_8F4020E4;

void func_8F400198(void) {
    s32 temp_v0;

    temp_v0 = func_800356CC(9);
    Dma_CopyChunks(D_8F4020E4, temp_v0, temp_v0 + 0xBDC);
}

extern void func_800226C0(s32);
extern void *D_80087200;
extern u8 D_8F4020C0;
extern s16 D_8F4020C4;
extern s32 D_8F4020C8;
extern s16 D_8F4020C2;
extern void *D_8F4020CC;
extern s16 D_8F4020E8;
extern s32 D_8F4020E4;
extern s32 func_80042FBC(void *, s32);
extern s32 func_8004B7E0(s32, void *);
extern f32 func_8004B888(s32);
extern s32 func_8004BA34(s32);
extern f32 func_8004BAE8(s32, s32);
extern s16 func_8004BB58(s32, s32);
extern s32 func_8004BBA8(s32, s32, void *);
extern s32 func_8004BC6C(s32, s32);
extern void func_8004BCBC(s32, void *);
extern void func_8004BD28(s32, f32);
extern void func_8004BD78(s32, s16);
extern void func_8004BE50();
extern void func_8004BE84(s32, s32, f32);
extern void func_8004BEEC(s32, s32, s16);
extern void func_8004BF3C(s32, s32, void *);
extern void func_8004BFC4(s32, s32, s16);




void func_8F4001CC(void)
{
  u8 *state;
  s16 index;
  s32 species;
  f32 vec[3];
  s16 value;
  s16 cv;
  s16 maximum;
  u16 buttons;
  f32 fvalue;
  s16 *ptr;
  state = &D_8F4020C0;
  index = *((s16 *) (state + 0x28));
  species = *((s16 *) (state + 2));
  ptr = &D_8F4020E8;
  if ((*((u16 *) (((u8 *) D_80087200) + 0xC))) & 0x800)
  {
    do
    {
      (*ptr)--;
      if ((*ptr) < 0)
      {
        *ptr = 7;
      }
    }
    while ((((s16 *) state)[(*((s16 *) (state + 0x28))) + 0x16]) == 0);
  }
  if ((*((u16 *) (((u8 *) D_80087200) + 0xC))) & 0x400)
  {
    do
    {
      (*ptr)++;
      if (1)
      {
        if ((*ptr) >= 8)
        {
          *ptr = 0;
        }
      }
    }
    while ((((s16 *) state)[(*((s16 *) (state + 0x28))) + 0x16]) == 0);
  }
  if (index != (*((s16 *) state)))
  {
    func_800226C0(1);
  }
  switch (*ptr)
  {
    case 0:
      ptr = &D_8F4020C2;
      if ((*((u16 *) (((u8 *) D_80087200) + 0xC))) & 0x200)
    {
      cv = (*ptr) - 1;
      *ptr = cv;
      if (cv <= 0)
      {
        *ptr = 1;
      }
    }
      if ((*((u16 *) (((u8 *) D_80087200) + 0xC))) & 0x100)
    {
      cv = (*ptr) + 1;
      *ptr = cv;
      if (cv >= 0xFE)
      {
        *ptr = 0xFD;
      }
    }
      if (species != (*ptr))
    {
      func_80042FBC(D_8F4020CC, *ptr);
      return;
    }
      break;

    case 1:
      if (D_8F4020E4 != 0)
    {
      func_8004BBA8(D_8F4020E4, D_8F4020C2, vec);
      if ((*((u16 *) (((u8 *) D_80087200) + 6))) & 0x200)
      {
        vec[0] -= 1.0f;
      }
      if ((*((u16 *) (((u8 *) D_80087200) + 6))) & 0x100)
      {
        vec[0] += 1.0f;
      }
      func_8004BF3C(D_8F4020E4, D_8F4020C2, vec);
      return;
    }
      func_8004B7E0(D_8F4020C2, vec);
      if ((*((u16 *) (((u8 *) D_80087200) + 6))) & 0x200)
    {
      vec[0] -= 1.0f;
    }
      if ((*((u16 *) (((u8 *) D_80087200) + 6))) & 0x100)
    {
      vec[0] += 1.0f;
    }
      func_8004BCBC(D_8F4020C2, vec);
      return;

    case 2:
      if (D_8F4020E4 != 0)
    {
      func_8004BBA8(D_8F4020E4, D_8F4020C2, vec);
      if ((*((u16 *) (((u8 *) D_80087200) + 6))) & 0x200)
      {
        vec[1] -= 1.0f;
      }
      if ((*((u16 *) (((u8 *) D_80087200) + 6))) & 0x100)
      {
        vec[1] += 1.0f;
      }
      func_8004BF3C(D_8F4020E4, D_8F4020C2, vec);
      return;
    }
      func_8004B7E0(D_8F4020C2, vec);
      if ((*((u16 *) (((u8 *) D_80087200) + 6))) & 0x200)
    {
      vec[1] -= 1.0f;
    }
      if ((*((u16 *) (((u8 *) D_80087200) + 6))) & 0x100)
    {
      vec[1] += 1.0f;
    }
      func_8004BCBC(D_8F4020C2, vec);
      return;

    case 3:
      if (D_8F4020E4 != 0)
    {
      func_8004BBA8(D_8F4020E4, D_8F4020C2, vec);
      if ((*((u16 *) (((u8 *) D_80087200) + 6))) & 0x200)
      {
        vec[2] -= 1.0f;
      }
      if ((*((u16 *) (((u8 *) D_80087200) + 6))) & 0x100)
      {
        vec[2] += 1.0f;
      }
      func_8004BF3C(D_8F4020E4, D_8F4020C2, vec);
      return;
    }
      if ((!D_8F4020E8) && (!D_8F4020E8))
    {
    }
      func_8004B7E0(D_8F4020C2, vec);
      if ((*((u16 *) (((u8 *) D_80087200) + 6))) & 0x200)
    {
      vec[2] -= 1.0f;
    }
      if ((*((u16 *) (((u8 *) D_80087200) + 6))) & 0x100)
    {
      vec[2] += 1.0f;
    }
      func_8004BCBC(D_8F4020C2, vec);
      return;

    case 4:
      if (D_8F4020E4 != 0)
    {
      value = func_8004BB58(D_8F4020E4, D_8F4020C2);
      ;
      if ((*((u16 *) (((u8 *) D_80087200) + 0xC))) & 0x200)
      {
        value -= 0x40;
      }
      if ((*((u16 *) (((u8 *) D_80087200) + 0xC))) & 0x100)
      {
        value += 0x40;
      }
      func_8004BEEC(D_8F4020E4, D_8F4020C2, value);
      return;
    }
      break;

    case 5:
      if (D_8F4020E4 != 0)
    {
      fvalue = func_8004BAE8(D_8F4020E4, D_8F4020C2);
      if ((*((u16 *) (((u8 *) D_80087200) + 0xC))) & 0x200)
      {
        fvalue -= 1.0f;
      }
      if ((*((u16 *) (((u8 *) D_80087200) + 0xC))) & 0x100)
      {
        fvalue += 1.0f;
      }
      func_8004BE84(D_8F4020E4, D_8F4020C2, fvalue);
      return;
    }
      fvalue = func_8004B888(D_8F4020C2);
      if ((*((u16 *) (((u8 *) D_80087200) + 0xC))) & 0x200)
    {
      fvalue = fvalue - 1.0f;
    }
      if ((*((u16 *) (((u8 *) D_80087200) + 0xC))) & 0x100)
    {
      fvalue += 1.0f;
    }
      func_8004BD28(D_8F4020C2, fvalue);
      return;

    case 6:
      if (D_8F4020E4 != 0)
    {
      value = func_8004BC6C(D_8F4020E4, D_8F4020C2);
      maximum = *((s16 *) (((u8 *) (*((u8 **) (((u8 *) (*((u8 **) (((u8 *) D_8F4020CC) + 0x1C)))) + 0x44)))) + 0xA));
      ;
      if ((*((u16 *) (((u8 *) D_80087200) + 0xC))) & 0x200)
      {
        if (value > 0)
        {
          value -= 1;
        }
      }
      if (((*((u16 *) (((u8 *) D_80087200) + 0xC))) & 0x100) && (value < (maximum - 1)))
      {
        value += 1;
      }
      func_8004BFC4(D_8F4020E4, D_8F4020C2, value);
      return;
    }
      value = func_8004BA34(D_8F4020C2);
      maximum = *((s16 *) (((u8 *) (*((u8 **) (((u8 *) (*((u8 **) (((u8 *) D_8F4020CC) + 0x1C)))) + 0x44)))) + 0xA));
      if ((*((u16 *) (((u8 *) D_80087200) + 0xC))) & 0x200)
    {
      if (value > 0)
      {
        value -= 1;
      }
    }
      if (((*((u16 *) (((u8 *) D_80087200) + 0xC))) & 0x100) && (value < (maximum - 1)))
    {
      value += 1;
    }
      func_8004BD78(D_8F4020C2, value);
      return;

    case 7:
      if ((*((u16 *) (((u8 *) D_80087200) + 8))) & 0x8000)
    {
      if (D_8F4020E4 != 0)
      {
        func_8F400198();
        return;
      }
      /* Retail keeps the tested value in a0 across the beqz and reuses it as the
         outgoing argument here, so the call carries D_8F4020E4 even though
         func_8004BE50 (src/4C2E0.c) ignores arguments. */
      func_8004BE50(D_8F4020E4);
    }
      break;

  }

}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/72/fragment72_code/func_8F4009A4.s")

u16 func_8F400A8C(u16* image, u16 stride) {
    u32 alpha = 0;
    u32 blue = 0;
    u32 green = 0;
    u32 red = 0;
    s32 row;
    s32 col;
    s32 pitch = stride;

    /* Keep the masks on the loads: a pixel temporary changes IDO allocation. */
    for (row = 0; row < 4; row++) {
        for (col = 0; col < 4; col++) {
            red += *image & 0xF800;
            green += *image & 0x7C0;
            blue += *image & 0x3E;
            alpha += *image & 1;
            image++;
        }
        image += pitch - 4;
    }
    red = (red >> 4) & 0xF800;
    green = (green >> 4) & 0x7C0;
    blue = (blue >> 4) & 0x3E;
    alpha = alpha >= 5; /* At least five covered texels out of sixteen. */
    return red | green | blue | alpha;
}

void func_8F400B88(u16* dest, u16* image) {
    u16 x;
    u16 y;
    u16* workingImage = image;
    u16* workingDest = dest;

    /* Sample each 4x4 block of the 160x160 source into a 40x40 thumbnail. */
    for (y = 0; y < 40; y++) {
        for (x = 0; x < 40; x++) {
            *workingDest++ = func_8F400A8C(workingImage, 160);
            workingImage += 4;
        }
        workingImage += 480; /* Remaining three source rows. */
    }
}

void func_8F400C08(s32 arg0, s32 arg1) {
    s32 temp_a1;

    temp_a1 = func_800356CC(4) + (arg0 * 0xC80);
    Dma_CopyChunks(arg1, temp_a1, temp_a1 + 0xC80);
}

/* mkdraft:func_8F400C58 begin */
extern s32 D_8F4020D0;
extern s32 D_8F4020D4;
extern s16 D_8F4020FC;
extern s16 D_8F4020FE;
extern s16 D_8F402100;
extern s16 D_8F402102;
extern s16 D_8F402104;
extern s16 D_8F402106;
extern void func_80043A0C(void* arg0, void* arg1, s32 arg2);
extern s32 func_8004410C();
extern s32 func_80044144();
extern void func_80044250(s8 value);



void func_8F400C58(void) {
    s16 state;
    s16* state_ptr;
    s16* counter_ptr;
    s16* timer_ptr;
    s16* index_ptr;
    s16* mode_ptr;
    s32* base_ptr;

    state_ptr = &D_8F4020FE;
    counter_ptr = &D_8F402102;
    timer_ptr = &D_8F402106;
    index_ptr = &D_8F402100;
    mode_ptr = &D_8F4020FC;
    base_ptr = &D_8F4020D0;
    state = *state_ptr;
    switch (state) {
    case 0:
        func_80043A0C(*base_ptr, 0, *index_ptr);
        if (*mode_ptr == 2) {
            func_80044250((*counter_ptr) + 1);
        }
        *state_ptr = 1;
        *timer_ptr = 0;
        break;
    case 1:
        if (func_80044144(*base_ptr) != 0) {
            *timer_ptr += 1;
            if (*timer_ptr >= 2) {
                *state_ptr = 2;
                *timer_ptr = 0;
            }
        }
        break;
    case 2:
        *counter_ptr += 1;
        func_8F400B88(*(u16**)((u8*)D_8F4020D4 + 8), func_8004410C(*base_ptr, 0));
        func_8F400C08(*counter_ptr, *(u16**)((u8*)D_8F4020D4 + 8));
        if (*counter_ptr < (D_8F402104 - 1)) {
            *state_ptr = 0;
            if (state_ptr[-1] != 2) { // FAKE: D_8F4020FC read through state_ptr (diff score 420 without it); same base symbol stops IDO hoisting the load above the store.
                *index_ptr += 1;
            }
        } else {
            *state_ptr = 3;
        }
        break;
    }
}
/* mkdraft:func_8F400C58 end */

extern void _bzero(void *, s32);
extern s32 func_80041C98(s32);
extern u8 *func_8004BA70(s32);
extern void func_80041E2C(void);

/* The fragment's 0x48-byte runtime block starts 0x10 bytes below
 * sPlaybackResources in the pinned .bss section (linker_scripts/us/datamig_bss.ld
 * places this object's .bss at 0x8F4020D0 and the block was cleared from
 * 0x8F4020C0). */
typedef struct Fragment72RuntimeBlock {
    u8 pad_00[2];
    s16 unk_02;
    s16 unk_04;
    u8 pad_06[2];
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    s32 unk_24;
} Fragment72RuntimeBlock;



void func_8F400DE8(void) {
    Fragment72RuntimeBlock *block = (Fragment72RuntimeBlock *)((u8 *)&sPlaybackResources - 0x10);

    _bzero(block, 0x48);
    block->unk_02 = 0x98;
    block->unk_04 = -1;
    block->unk_08 = func_80041C98(5);
    block->unk_0C = 0;
    block->unk_10 = 0;
    block->unk_14 = 0;
    block->unk_18 = 0;
    block->unk_1C = (s32)func_8004BA70(0);
    block->unk_20 = (s32)func_8004BA70(1);
    block->unk_24 = 0;
    func_80041E2C();
}

void func_8F400E74(s32 arg0, s32 arg1, s32 arg2) {
    if (arg0 == arg1) {
        func_8004972C(0xFF, 0xFF, 0, 0xFF);
        return;
    }
    if (arg2 == 0) {
        func_8004972C(0x80, 0x80, 0x80, 0xFF);
        return;
    }
    func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
}

extern s16 D_8F402030[];
extern s16 D_8F4020EC;
extern s16 D_8F4020EE;
extern s16 D_8F4020F0;
extern s16 D_8F4020F2;
extern s16 D_8F4020F4;
extern s16 D_8F4020F6;
extern s16 D_8F4020F8;
extern s16 D_8F4020FA;
// Text overlay drawn by func_8F401918 after the preview. Always prints message 8 of
// group 66. arg0 (draw mode 2) adds the entry named by D_8F402030 for the current
// state, and arg1 (draw mode 3) adds the species number and name in D_8F402100. While a
// model is loaded (D_8F4020CC), it lists eight rows, labels 23-31, with their current
// values. func_8F400E74 brightens the row selected by D_8F4020E8 before each pair.
void func_8F400EE0(s32 arg0, s32 arg1) {
    func_800498C4();
    Font_EnableTwoCycleTexturing();
    func_8004972C(0, 0, 0xFF, 0xFF);
    func_800497E4(0xFF, 0xFF, 0xFF, 0xFF);
    func_800496A4(16, 0);
    func_800495F8(320, 40, 1, func_8004C874(66, 8));
    if (arg0 != 0) {
        func_8004972C(0, 0, 0xFF, 0xFF);
        func_800497E4(0, 0xFF, 0xFF, 0xFF);
        func_800496A4(8, 0);
        func_800495F8(320, 64, 1, func_8004C874(66, D_8F402030[*(s16 *)&D_8F4020C0]));
    }
    if (arg1 != 0) {
        func_8004972C(0, 0, 0xFF, 0xFF);
        func_800497E4(0, 0xFF, 0xFF, 0xFF);
        func_800496A4(8, 0);
        func_800495F8(320, 64, 1, "%03d:%s", D_8F402100, func_8004B7A4(D_8F402100));
    }
    Font_DisableTwoCycleTexturing();
    if (D_8F4020CC != NULL) {
        func_800496A4(8, 0);
        func_8F400E74(D_8F4020E8, 0, D_8F4020EC);
        func_800495F8(400, 100, 2, func_8004C874(66, 23));
        func_800495F8(400, 120, 2, func_8004C874(66, 24));
        func_8F400E74(D_8F4020E8, 1, D_8F4020EE);
        func_800495F8(400, 140, 2, func_8004C874(66, 25));
        func_8F400E74(D_8F4020E8, 2, D_8F4020F0);
        func_800495F8(400, 160, 2, func_8004C874(66, 26));
        func_8F400E74(D_8F4020E8, 3, D_8F4020F2);
        func_800495F8(400, 180, 2, func_8004C874(66, 27));
        func_8F400E74(D_8F4020E8, 4, D_8F4020F4);
        func_800495F8(400, 200, 2, func_8004C874(66, 28));
        func_8F400E74(D_8F4020E8, 5, D_8F4020F6);
        func_800495F8(400, 220, 2, func_8004C874(66, 29));
        func_8F400E74(D_8F4020E8, 6, D_8F4020F8);
        func_800495F8(400, 240, 2, func_8004C874(66, 30));
        func_8F400E74(D_8F4020E8, 7, D_8F4020FA);
        func_800495F8(400, 260, 1, func_8004C874(66, 31));
        func_8F400E74(D_8F4020E8, 0, D_8F4020EC);
        func_800495F8(400, 100, 0, "%03d", D_8F4020C2);
        func_800495F8(400, 120, 0, "%s", func_8004B7A4(D_8F4020C2));
        func_8F400E74(D_8F4020E8, 1, D_8F4020EE);
        func_800495F8(400, 140, 0, "%4d", (s32)*(f32 *)(*(u8 **)((u8 *)D_8F4020CC + 0x1C) + 0x24));
        func_8F400E74(D_8F4020E8, 2, D_8F4020F0);
        func_800495F8(400, 160, 0, "%4d", (s32)*(f32 *)(*(u8 **)((u8 *)D_8F4020CC + 0x1C) + 0x28));
        func_8F400E74(D_8F4020E8, 3, D_8F4020F2);
        func_800495F8(400, 180, 0, "%4d", (s32)*(f32 *)(*(u8 **)((u8 *)D_8F4020CC + 0x1C) + 0x2C));
        func_8F400E74(D_8F4020E8, 4, D_8F4020F4);
        func_800495F8(400, 200, 0, "%04X", *(u16 *)(*(u8 **)((u8 *)D_8F4020CC + 0x1C) + 0x20));
        func_8F400E74(D_8F4020E8, 5, D_8F4020F6);
        func_800495F8(400, 220, 0, "%5.2f", *(f32 *)((u8 *)D_8F4020CC + 0x10));
        func_8F400E74(D_8F4020E8, 6, D_8F4020F8);
        func_800495F8(400, 240, 0, "%3d", *(s32 *)(*(u8 **)((u8 *)D_8F4020CC + 0x1C) + 0x48) >> 16);
    }
    func_800499EC();
}

extern s16 D_8F402030[];
extern u8 D_8F402040[];
extern u8 D_8F402044[];
extern u8 D_8F4020C0;
extern s16 D_8F4020FC;
void func_8F401464(void) {
    s32 i;
    s32 y;
    s16 *selection; // FAKE: reads D_8F4020C0 through a local pointer; diff score 655 without it.
    s16 *extra; // FAKE: reads D_8F4020FC through a local pointer; diff score 940 without it.

    Ui_DrawGradientPanel(120, 120, 400, 180, D_8F402040, D_8F402044);
    func_800498C4();
    func_800496A4(8, 0);
    Font_EnableTwoCycleTexturing();
    func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
    func_800497E4(0, 0xFF, 0xFF, 0xFF);
    func_800495BC(140, 140, func_8004C874(66, 19));
    Font_DisableTwoCycleTexturing();
    func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
    selection = (s16 *)&D_8F4020C0;
    extra = &D_8F4020FC;
    for (i = 0, y = 180; i < 5; i++, y += 22) {
        if (i != *selection) {
            func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
        } else {
            func_8004972C(0xFF, 0xFF, 0, 0xFF);
        }
        func_800495BC(140, y, func_8004C874(66, D_8F402030[i]));
        if (i == 4) {
            func_800495F8(500, y, 2, func_8004C874(66, *extra + 34));
        }
    }
    func_800499EC();
}

// Close to fragment20's func_82609938; also skips drawing when arg5 is not positive.
//@src/fragments/20/fragment20_12C460.c
extern void func_80046204(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void GfxRect_DrawTextured(s16, s16, s16, s16, s16, s16, s16, s16, s32);
void func_8F4015FC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 temp_v0;
    s32 var_s0;
    s32 var_s1;

    if (arg5 > 0) {
        for (var_s1 = 0; var_s1 < arg4; var_s1 += arg5) {
            temp_v0 = arg4 - var_s1;
            if (temp_v0 < arg5) var_s0 = temp_v0;
            else var_s0 = arg5;
            func_80046204((arg3 * var_s1 * 2) + arg2, 0, 2, arg3, var_s0, 0, 0, arg3, var_s0 - 1, 0, 2, 2, 0, 0, 0, 0);
            GfxRect_DrawTextured((s16)arg0, (s16)(arg1 + var_s1), (s16)arg3, (s16)var_s0, 0, 0, 0x400, 0x400, 0);
        }
    }
}

extern void Dma_CopyChunks(s32, s32, s32);
extern s32 func_800356CC(s32);
extern s32 D_8F4020E4;
extern void func_800226C0(s32);
extern void func_8F4001CC(void);
extern void *D_80087200;
extern Gfx *D_800D0510;
extern u8 D_80094E38[];
extern u8 D_8F4020C0;
extern void func_8F4015FC(s32, s32, s32, s32, s32, s32);
#define GFX_DL (*(Gfx **)&D_800D0510)
void func_8F401750(void) {
    s16 temp_a3;
    u8 *temp_t2;
    s32 temp_a2;
    s32 temp_t3;
    s32 temp_t7;

    temp_t2 = (u8 *)(u32)(*(u32 *)((u8 *)&D_8F4020C0 + 0xC));
    temp_a2 = *(s32 *)((u8 *)&D_8F4020C0 + 0x18);
    if ((temp_t2 != NULL) && (temp_a2 != 0)) {
        temp_a3 = *(s16 *)(temp_t2 + 4);
        temp_t3 = *(s16 *)(temp_t2 + 6);
        temp_t7 = (0x800 / temp_a3) & ~1;
        gSPDisplayList(GFX_DL++, D_80094E38);
        gDPSetRenderMode(GFX_DL++, 0x0F0A4000, 0);
        func_8F4015FC(0x64, 0x64, temp_a2, temp_a3, temp_t3, temp_t7);
    }
}

/* mkdraft:func_8F401828 begin */
extern s32 D_8F402048;
extern s32 D_8F40204C;
extern s32 D_8F4020D0;
extern s16 D_8F402102;
extern u8 D_80094E38[];
extern void Gfx_DrawTextureRgba16(s16, s16, s16, s16, u8 *, s16, s32);
#define GFX_DL (*(Gfx **)&D_800D0510)

// Draw the 40x40 preview thumbnail of grid cell D_8F402102: column (*index % 16) and
// row ((*index / 16) % 10), offset from D_8F402048/D_8F40204C.


void func_8F401828(void) {
    s32 handle;
    s16 *index;
    s32 x;
    s32 y;

    handle = D_8F4020D0;
    // FAKE: the cell index is read through an address local because that is the only
    // spelling found that makes uopt keep it in t6 for the whole body; direct reads of
    // D_8F402102 put it in t0 and move every later temporary register down one;
    // diff score 535 without it.
    index = &D_8F402102;
    if ((handle != 0) && (*index >= 0)) {
        x = *index % 16;
        y = (*index / 16) % 10;
        gSPDisplayList(GFX_DL++, D_80094E38);
        Gfx_DrawTextureRgba16((x * 40) + D_8F402048, (y * 40) + D_8F40204C, 40, 40,
                              *(u8 **)((u8 *)D_8F4020D4 + 8), 40, 0);
    }
}
/* mkdraft:func_8F401828 end */

extern void GfxImage_FillCurrent(void *, u16);
extern s32 func_80008648(void);
extern void func_800088DC(void);
extern void func_80043E70(s32, s32);
extern void func_8F400EE0(s32, s32);
extern void func_8F401464(void);
extern void func_8F401828(void);

// Per-frame draw callback; arg0 1/2/3 selects the mode-specific setup.
// D_8F4020C0 is an unnamed struct: a pointer at +0x10 and an s16 countdown at +4.
void func_8F401918(s32 arg0) {
    s32 sp1C;
    s32 sp18;
    u8 *state;

    sp1C = 0;
    sp18 = 0;
    state = (u8 *)&D_8F4020C0;
    if (*(void **)(state + 0x10) != NULL) {
        func_80043E70((s32)*(void **)(state + 0x10), 1);
    }
    func_800088DC();
    if (*(s16 *)(state + 4) != 0) {
        GfxImage_FillCurrent(&D_800D0510, 0x7BDF);
        if (*(s16 *)(state + 4) > 0) {
            *(s16 *)(state + 4) -= 1;
        }
    }
    if (arg0 == 1) {
        func_8F401464();
    }
    func_8F401750();
    func_8F401828();
    switch (arg0) {
        case 2:
            sp1C = 1;
            break;
        case 3:
            sp18 = 1;
            break;
    }
    func_8F400EE0(sp1C, sp18);
    func_80008648();
}
extern void func_800226C0(s32);
extern void *D_80087200;

s32 func_8F401A08(s16 *arg0) {
    s32 sp1C;
    s32 previous;

    sp1C = 0;
    previous = *arg0;
    if (*(u16 *)((u8 *)D_80087200 + 0xC) & 0x800) {
        (*arg0)--;
        if (*arg0 < 0) {
            *arg0 = 4;
        }
    }
    if (*(u16 *)((u8 *)D_80087200 + 0xC) & 0x400) {
        (*arg0)++;
        if (*arg0 >= 5) {
            *arg0 = 0;
        }
    }
    if (previous != *arg0) {
        func_800226C0(1);
    }
    if (*arg0 == 4) {
        if (*(u16 *)((u8 *)D_80087200 + 0xC) & 0x200) {
            *(s16 *)((u8 *)arg0 + 0x3C) -= 1;
            if (*(s16 *)((u8 *)arg0 + 0x3C) < 0) {
                *(s16 *)((u8 *)arg0 + 0x3C) = 0;
            }
        }
        if (*(u16 *)((u8 *)D_80087200 + 0xC) & 0x100) {
            *(s16 *)((u8 *)arg0 + 0x3C) += 1;
            if (*(s16 *)((u8 *)arg0 + 0x3C) >= 3) {
                *(s16 *)((u8 *)arg0 + 0x3C) = 2;
            }
        }
    }
    if (*(u16 *)((u8 *)D_80087200 + 8) & 0x8000) {
        sp1C = 1;
        func_800226C0(2);
    } else if (*(u16 *)((u8 *)D_80087200 + 8) & 0x4000) {
        sp1C = -1;
        func_800226C0(3);
    }
    return sp1C;
}
extern void func_800226C0(s32);
extern void func_8F4001CC();
extern void *D_80087200;
s32 func_8F401B74(s32 arg0) {
    s32 sp1C;

    sp1C = 0;
    func_8F4001CC();
    if ((*(u16 *)((u8 *)(D_80087200) + (8))) & 0x4000) {
        sp1C = -1;
        func_800226C0(3);
    }
    return sp1C;
}

extern void Dma_CopyChunks(s32, s32, s32);
extern s32 func_800356CC(s32);
extern s32 D_8F4020E4;
extern void func_800226C0(s32);
extern void func_8F4001CC(void);
extern void *D_80087200;
extern void func_8F400C58(void);
extern s16 D_8F402102;
extern s16 D_8F402104;
s32 func_8F401BC4(s32 arg0) {
    s32 sp1C;
    s32 sp18;

    sp18 = 0;
    func_8F400C58();
    if (((*(u16 *)((u8 *)(D_80087200) + 8)) & 0x4000) &&
        (D_8F402102 >= (D_8F402104 - 1))) {
        sp18 = -1;
        func_800226C0(3);
    }
    return sp18;
}

/* mkdraft:func_8F401C30 begin */
extern s32 D_8F40203C;
extern s16 D_8F4020C4;
extern void *D_8F4020CC;
extern s32 D_8F4020D0;
extern s32 D_8F4020D4;
extern s32 D_8F4020D8;
extern u8 StageContext_GetFadeMode(void);
extern s32 StageFade_StartFromTransparent(s32 duration);
void func_8F400020(void);
extern s32 func_8F4009A4();
extern void main_pool_pop_state(s32);
extern void main_pool_push_state(s32);

s32 func_8F401C30(s32 arg0) {
    Fragment72PlaybackResources *playback = &sPlaybackResources;
    s32 var_s0 = arg0;
    s32 temp_v0;

    switch (var_s0) {
        case 0:
            if (StageContext_GetFadeMode() == 0) {
                var_s0 = 1;
            }
            break;
        case 1:
            temp_v0 = func_8F401A08(&D_8F4020C0);
            if (temp_v0 != 0) {
                if (temp_v0 > 0) {
                    main_pool_push_state(D_8F40203C);
                    if (*(s16 *)&D_8F4020C0 != 4) {
                        var_s0 = 2;
                        func_8F400020();
                    } else {
                        var_s0 = 3;
                        D_8F4020C4 = 2;
                        func_8F4009A4();
                    }
                } else {
                    var_s0 = 4;
                    StageFade_StartFromTransparent(5);
                }
            }
            break;
        case 2:
            if (func_8F401B74((s32)&D_8F4020C0)) {
                var_s0 = 1;
                main_pool_pop_state(D_8F40203C);
                D_8F4020CC = 0;
                D_8F4020D8 = 0;
            }
            break;
        case 3:
            if (func_8F401BC4((s32)&D_8F4020C0)) {
                var_s0 = 1;
                main_pool_pop_state(D_8F40203C);
                playback->handle = 0;
                playback->model = 0;
                D_8F4020C4 = -1;
            }
            break;
        case 4:
            if (StageContext_GetFadeMode() == 1) {
                var_s0 = 5;
            }
            break;
    }
    return var_s0;
}
/* mkdraft:func_8F401C30 end */

/* mkdraft:func_8F401D88 begin */
extern s32 D_8F4020E4;
extern s16 D_8F4020C2;
extern void *D_8F4020CC;
extern s32 D_8F4020D8;
extern s16 D_8F4020F8;
extern void ModelAnim_SetFrame(u8 *arg0, s16 value);
extern s32 StageFade_StartFromOpaque(s32 duration);
extern void func_800086A4(s32 frames);
extern s32 func_80043064();
extern s32 func_80043678(s32 arg0);
extern s32 func_8004B7E0(s32, void *);
extern f32 func_8004B888(s32);
extern s32 func_8004BA34(s32);
extern f32 func_8004BAE8(s32, s32);
extern s16 func_8004BB58(s32, s32);
extern s32 func_8004BBA8(s32, s32, void *);
extern s32 func_8004BC6C(s32, s32);
extern void func_80064D28(void);
extern void func_8F401918(s32 arg0);
extern s32 func_8F401C30(s32 arg0);


void func_8F401D88(void) {
    s32 *pcc = &D_8F4020CC;
    s32 *pe4 = &D_8F4020E4;
    s16 *pc2 = &D_8F4020C2;
    s32 *pd8 = &D_8F4020D8;
    s16 *pf8 = &D_8F4020F8;
    s32 var_s0;

    var_s0 = 0;
    func_800086A4(2);
    StageFade_StartFromOpaque(5);
    do {
        func_80064D28();
        if (*pcc != 0) {
            if (func_80043064(*pcc) != 0) {
                *(s16 *)(*(u8 **)(*pcc + 0x1C) + 0x1E) = 0;
            }
            if (*pe4 != 0) {
                *(f32 *)(*pcc + 0x10) = func_8004BAE8(*pe4, *pc2);
                *(s16 *)(*(u8 **)(*pcc + 0x1C) + 0x20) = func_8004BB58(*pe4, *pc2);
                func_8004BBA8(*pe4, *pc2, *(u8 **)(*pcc + 0x1C) + 0x24);
                ModelAnim_SetFrame(*(u8 **)(*pcc + 0x1C), (s16)func_8004BC6C(*pe4, *pc2));
            } else {
                *(f32 *)(*pcc + 0x10) = func_8004B888(*pc2);
                func_8004B7E0(*pc2, *(u8 **)(*pcc + 0x1C) + 0x24);
                if (*pf8 != 0) {
                    ModelAnim_SetFrame(*(u8 **)(*pcc + 0x1C), (s16)func_8004BA34(*pc2));
                }
            }
            *pd8 = func_80043678(*pcc);
        }
        func_8F401918(var_s0);
        var_s0 = func_8F401C30(var_s0);
    } while (var_s0 != 5);
}
/* mkdraft:func_8F401D88 end */

extern void Dma_CopyChunks(s32, s32, s32);
extern s32 func_800356CC(s32);
extern s32 D_8F4020E4;
extern void func_800226C0(s32);
extern void func_8F4001CC(void);
extern void *D_80087200;
extern void main_pool_push_state(s32);
extern void main_pool_pop_state(s32);
extern void Gfx_InitDisplayListBuffers(s32, s32);
extern s32 StageContext_Allocate(s32, s32, s32, s32, s32, s32);
extern void func_8004C09C(s32);
extern void func_8004C4B0(s32);
extern void func_80047588(s32, s32);
extern void Asset_LoadToSegment(s32, u8 *, u8 *, s32);
extern void func_8F400DE8(void);
extern void func_80008514(s32);
extern void func_8F401D88(void);
extern void func_80008574(void);
extern void func_80047610(void);
extern void func_8004C398(void);
extern void Gfx_FreeDisplayListBuffers(void);
extern u8 D_1000000[];
extern u8 D_446E30[];
extern u8 D_447D00[];
s32 fragment72_main(s32 arg0, s32 arg1) {
    s32 sp24;

    main_pool_push_state(0x49434D4B);
    Gfx_InitDisplayListBuffers(0x18000, 0);
    sp24 = StageContext_Allocate(1, 0, 2, 0, 2, 1);
    func_8004C09C(3);
    func_8004C4B0(0x42);
    func_80047588(0x18, 0);
    Asset_LoadToSegment(((u32)&D_1000000 & 0x0F000000) >> 24, &D_446E30, &D_447D00, 0);
    func_8F400DE8();
    func_80008514(sp24);
    func_8F401D88();
    func_80008574();
    func_80047610();
    func_8004C398();
    Gfx_FreeDisplayListBuffers();
    main_pool_pop_state(0x49434D4B);
    return 0;
}
#endif
