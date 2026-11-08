#include "global.h"


#ifdef VERSION_US
/* mkdraft:func_87E18410 begin */
extern void func_80007444(Gfx **, s32, s32, s32, s32, u16);
extern s32 func_8004C990(s32, s32);
extern s32 func_8004D19C(s32, s32, s32, s32, s32);
extern Gfx *D_800D0510;
extern Gfx D_80094E38[];
extern Gfx D_80094F50[];
extern s32 D_87E1B468[];

void func_87E18410(u8 *arg0) {
    s32 handle;
    s32 *var_t7 = *(s32 **)(arg0 + 12);

    func_80007444(&D_800D0510, 0, 0, 100, 26, 0xFFFE);
    gSPDisplayList(D_800D0510++, D_80094E38);
    gDPSetRenderMode(D_800D0510++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
    handle = func_8004C990(426, D_87E1B468[*var_t7]);
    func_8004D19C(0, 0, handle, 0, 0);
    gSPDisplayList(D_800D0510++, D_80094F50);
}
/* mkdraft:func_87E18410 end */

typedef struct {
    f32 x, y, z;
} Vec3f_87E18504;

extern void *D_87F119DC;
extern u32 *D_87E1EC90;
extern void func_87F0B1A4(u8 *, f32 *, f32, f32, f32, s32, s32);
extern void func_87F0B2F4(u8 *, s16 *, f32, f32, f32, s32, s32);
extern void func_87E13558(void *, f32, f32, f32, s32);
extern void func_87F0B0FC(void *, f32, f32, f32, s32);
extern void func_87F0B154(void *);
extern void func_87F0B4AC(void *, f32 *, f32 *, s16 *);



void func_87E18504(void) {
    u8 *node;
    Vec3f_87E18504 pos;
    u8 *child;

    node = *(u8 **)(*(u8 **)((u8 *)D_87F119DC + 0x38) + 0xC);
    if ((*(s32 *)((u8 *)D_87E1EC90 + 4) == 2) && (*(s32 *)D_87E1EC90 == *(s32 *)node)) {
        child = node + 8;
        if (*(s32 *)(node + 0x8C) == 0) {
            func_87F0B1A4(child, (f32 *)((u8 *)D_87F119DC + 0x48), *(f32 *)((u8 *)D_87F119DC + 0x48),
                          *(f32 *)((u8 *)D_87F119DC + 0x4C) - -360.0f,
                          *(f32 *)((u8 *)D_87F119DC + 0x50), 0xA, 0x2000);
            func_87F0B2F4(child, (s16 *)((u8 *)D_87F119DC + 0x42), 180.0f, 0.0f, 0.0f, 0xA, 0x8000);
        }
    }
    child = node + 8;
    if (*(s32 *)D_87E1EC90 == *(s32 *)node) {
        pos = *(Vec3f_87E18504 *)((u8 *)D_87F119DC + 0x48);
        *(f32 *)((u8 *)D_87F119DC + 0x50) = *(f32 *)((u8 *)D_87F119DC + 0x50) + 30.0f;
        func_87E13558(D_87F119DC, -50.0f, (f32)0, (f32)0, 6);
        *(Vec3f_87E18504 *)((u8 *)D_87F119DC + 0x48) = pos;
        if (*(s32 *)((u8 *)D_87E1EC90 + 4) != 2) {
            func_87F0B0FC(child, 0, 30.0f, 10.0f, 6);
        }
        if ((s32)*(u8 *)((u8 *)D_87F119DC + 0x60) < 0xF5) {
            *(u8 *)((u8 *)D_87F119DC + 0x60) = *(u8 *)((u8 *)D_87F119DC + 0x60) + 0xA;
        } else {
            *(u8 *)((u8 *)D_87F119DC + 0x60) = 0xFF;
        }
        *(s32 *)(node + 4) = *(s32 *)(node + 4) + 1;
    } else {
        if (*(s32 *)((u8 *)D_87E1EC90 + 4) != 2) {
            func_87F0B154(child);
        }
        *(u8 *)((u8 *)D_87F119DC + 0x60) = *(u8 *)((u8 *)D_87F119DC + 0x60) - 0xA;
        if ((s32)*(u8 *)((u8 *)D_87F119DC + 0x60) < 0xC8) {
            *(u8 *)((u8 *)D_87F119DC + 0x60) = 0xC8;
        }
        *(s32 *)(node + 4) = 0;
    }
    func_87F0B4AC(child, (f32 *)((u8 *)D_87F119DC + 0x48), (f32 *)((u8 *)D_87F119DC + 0x54), (s16 *)((u8 *)D_87F119DC + 0x42));
}

extern u8 *D_8009491C;
extern void func_8003CD84(void);

// In mode 5, draws the model at *(D_8009491C + 0x14): sets a gray environment color from byte
// 0x3C of D_8009491C, binds segment 15 to the model's word at *(model + 4) + 8, runs the model's
// display list and then calls func_8003CD84.
void func_87E18738(s32 arg0, s32 arg1) {
    u8 *obj;
    u8 *model;
    Gfx *gfx;

    if (arg0 == 5) {
        obj = D_8009491C;
        gDPPipeSync(D_800D0510++);
        gDPSetCombine(D_800D0510++, 0x50FFFF, 0xFFFFF238);
        // FAKE: gDPSetEnvColor(v, v, v, 255) written out with the channels ORed green, blue,
        // red; diff score 15 with the macro's red, green, blue order.
        gfx = D_800D0510++;
        gfx->words.w0 = 0xFB000000;
        gfx->words.w1 = (obj[0x3C] << 16) | (obj[0x3C] << 8) | (obj[0x3C] << 24) | 0xFF;
        model = *(u8 **)(D_8009491C + 0x14);
        gSPSegment(D_800D0510++, 15, *(u32 *)(*(u8 **)(model + 4) + 8));
        gSPDisplayList(D_800D0510++, *(Gfx **)model);
        func_8003CD84();
    }
}

extern void func_87E0168C(s32, s32, s32);
extern void func_87F0ADE0(u8 *, u32);
extern u8 *func_87F0AEC0(void *, void *, s32, s32, s32, s32, s32);
extern s32 func_87F0AFD0(u8 *, f32 *, f32 *, s16 *);
extern void func_87F0B2F4(u8 *, s16 *, f32, f32, f32, s32, s32);
extern void func_87E18504(void);
extern u8 *main_pool_alloc(s32, s32);

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} UnkVec3s;

extern UnkVec3s D_87E1B444[3];

/*
Sets up three 0x90-byte link slots carved from one main-pool block and creates one
scene node per slot through func_87F0AEC0.

The slot/link addresses are written as `node + i * 0x90` index expressions rather
than incremented pointers. uopt strength-reduces them into the two `+= 0x90`
pointer updates at the bottom of the loop (s4 = slots, s5 = link) and hoists the
indexed `+ 8` address of the two animation calls to the top of the if-block, where
node + 0x24 is still live; the hoisted address takes s3 and node + 0x42 at the
call sites takes s2. Pointer increments produce the same operations in a
different register assignment and score 27 word diffs.
*/


void func_87E18828(u8 *arg0) {
    u8 *node;
    s32 i;
    u8 *slots;
    u8 *link;

    node = (u8 *)main_pool_alloc(0x1B0, 0);
    func_87F0ADE0(arg0 + 0xC, 3);
    for (i = 0, slots = node, link = node; i < 3; i++) {
        *(s32 *)(slots + i * 0x90) = i;
        *(s32 *)(slots + i * 0x90 + 4) = 0;
        node = func_87F0AEC0(arg0 + 0xC, func_87E18504, 0x0F000000, 0x64, 0x1A, func_87E18410, link + i * 0x90);
        if (node != NULL) {
            func_8003F1DC(node + 0x24);
            func_8003F114(node + 0x24, 0, -1, *(void **)(arg0 + 0x24));
            *(f32 *)(node + 0x5C) = 1.0f;
            *(f32 *)(node + 0x58) = 1.0f;
            *(f32 *)(node + 0x54) = 1.0f;
            *(UnkVec3s *)(node + 0x48) = D_87E1B444[i];
            *(s16 *)(node + 0x44) = -0x4000;
            func_87F0AFD0(link + i * 0x90 + 8, node + 0x48, node + 0x54, (s16 *)(node + 0x42));
            func_87F0B2F4(link + i * 0x90 + 8, (s16 *)(node + 0x42), 0.0f, 0.0f, 0.0f, 0xA, 0xC000);
        }
    }
    func_87E0168C(3, 0x8C, 9);
}

extern void func_87E01628();
extern void main_pool_pop_state(s32);

void func_87E189E8(s32 arg0) {
    func_87E01628();
    main_pool_pop_state(0x4D51414C);
}

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

s32 MainPool_AllocState(s32, M2C_UNK);              /* extern */
M2C_UNK MainPool_FinalizeAllocation(s32);           /* extern */
s32 func_80040E80(s32, M2C_UNK *);                  /* extern */
M2C_UNK func_8004C8C0(M2C_UNK, s32);                /* extern */
M2C_UNK func_87E10E64(M2C_UNK);                     /* extern */
M2C_UNK func_87E10EA8(M2C_UNK);                     /* extern */
M2C_UNK func_87E10F2C(M2C_UNK);                     /* extern */
M2C_UNK func_87E13480(M2C_UNK);                     /* extern */
M2C_UNK func_87E13490();                            /* extern */
M2C_UNK func_87E134C0();                            /* extern */
void func_87E18828(u8 *arg0);                      /* extern */
s32 main_pool_get_available();                      /* extern */
M2C_UNK main_pool_push_state(M2C_UNK);              /* extern */
extern M2C_UNK D_87E1B410;

void func_87E18A14(u8 *arg0, s32 arg1, s32 arg2) {
    s32 sp24;
    s32 temp_v0;

    main_pool_push_state(0x4D51414C);
    M2C_FIELD(arg0, s32 *, 0x28) = arg2;
    switch (arg1) {                                 /* irregular */
    default:
        M2C_FIELD(arg0, s32 *, 0) = 1;
        break;
    case 2:
        M2C_FIELD(arg0, s32 *, 0) = 0;
        break;
    case 1:
        M2C_FIELD(arg0, s32 *, 0) = 1;
        break;
    case 0:
        M2C_FIELD(arg0, s32 *, 0) = 2;
        break;
    }
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    func_8004C8C0(0x1AA, arg1);
    temp_v0 = MainPool_AllocState(main_pool_get_available(), 0);
    sp24 = temp_v0;
    M2C_FIELD(arg0, s32 *, 0x24) = func_80040E80(temp_v0, &D_87E1B410);
    MainPool_FinalizeAllocation(sp24);
    func_87E18828(arg0);
    func_87E134C0();
    func_87E13490();
    func_87E13480(0);
    func_87E10E64(1);
    func_87E10EA8(-1);
    func_87E10F2C(-1);
}
extern u32 func_8003570C(void);
extern u32 *D_87E1EC90;
extern void func_87F0B1A4(u8 *, f32 *, f32, f32, f32, s32, s32);
extern void func_87F0B2F4(u8 *, s16 *, f32, f32, f32, s32, s32);
/* mkdraft:func_87E18B0C begin */

// The two 0xC/0x8 steps follow the retail loads: the list node's 0x38 pointer leads to a
// descriptor whose 0xC word is a pointer; that pointer's first word is the id compared
// against *D_87E1EC90 and the drawing record handed to func_87F0B1A4 starts 8 bytes in.


void func_87E18B0C(void *arg0) {
    u8 *node = *(u8 **)((u8 *)arg0 + 0x18);

    while (node != NULL) {
        u8 *desc = *(u8 **)(*(u8 **)(node + 0x38) + 0xC);
        u8 *draw_record = desc + 8;

        if (*D_87E1EC90 == *(u32 *)desc) {
            func_87F0B1A4(draw_record, (f32 *)(node + 0x48), 0.0f, 20.0f,
                          *(f32 *)(node + 0x50) + 150.0f, 0xA, 0x5000);
        } else {
            func_87F0B1A4(draw_record, (f32 *)(node + 0x48), *(f32 *)(node + 0x48),
                          *(f32 *)(node + 0x4C) + -360.0f, *(f32 *)(node + 0x50), 0xF, 0x2000);
            // func_8003570C returns an unsigned 32-bit value; the divide and the -45/-180
            // offsets map it onto the 90/360 degree ranges used by func_87F0B2F4.
            func_87F0B2F4(draw_record, (s16 *)(node + 0x42),
                          ((f32) func_8003570C() / 4294967296.0f) * 90.0f - 45.0f,
                          ((f32) func_8003570C() / 4294967296.0f) * 90.0f - 45.0f,
                          ((f32) func_8003570C() / 4294967296.0f) * 360.0f - 180.0f, 0xF, 0);
        }
        node = *(u8 **)(node + 4);
    }
}
/* mkdraft:func_87E18B0C end */

/* mkdraft:func_87E18D20 begin */

// Walks the node list at arg0 + 0x18. Each node's object at node + 0x38 points at
// offset 0xC to a state block whose render state begins 8 bytes in; func_87F0B1A4
// receives it with the node's position floats at 0x48..0x50 (the second shifted by
// -360.0f) and priority 15, then func_87F0B2F4 randomizes the node's rotation at
// 0x42 from three LCG draws at func_8003570C, each scaled from [0,1) over
// 4294967296.0f to -45..45, -45..45 and -180..180 degrees.


void func_87E18D20(void *arg0) {
    f32 var_ft4;
    f32 var_ft5;
    u32 temp_s2;
    u32 temp_s3;
    u32 temp_v0;
    u8 *state;
    u8 *state_block;
    u8 *node;

    node = *(u8 **)((u8 *)arg0 + 0x18);
    if (node != NULL) {
        do {
            state_block = *(u8 **)(*(u8 **)(node + 0x38) + 0xC);
            state = state_block + 8;
            func_87F0B1A4(state, (f32 *)(node + 0x48), *(f32 *)(node + 0x48),
                *(f32 *)(node + 0x4C) + -360.0f, *(f32 *)(node + 0x50), 0xF, 0x2000);
            temp_s2 = func_8003570C();
            temp_s3 = func_8003570C();
            temp_v0 = func_8003570C();
            var_ft5 = (f32)(u32)temp_s3;
            var_ft4 = (f32)(u32)temp_v0;
            func_87F0B2F4(state, (s16 *)(node + 0x42), (((f32)temp_s2 / 4294967296.0f) * 90.0f) - 45.0f,
                ((var_ft5 / 4294967296.0f) * 90.0f) - 45.0f,
                ((var_ft4 / 4294967296.0f) * 360.0f) - 180.0f, 0xF, 0);
            node = *(u8 **)(node + 4);
        } while (node != NULL);
    }
}
/* mkdraft:func_87E18D20 end */

s32 func_87E18ECC(void *arg0)
{
  u8 *new_var;
  s32 var_v1;
  void *var_v0;
  var_v0 = *((void **) (((u8 *) arg0) + 0x18));
  var_v1 = 1;
  if (var_v0 != 0)
  {
    do
    {
      new_var = (u8 *) (*((void **) (((u8 *) (*((void **) (((u8 *) var_v0) + 0x38)))) + 0xC)));
      if ((*((s32 *) (new_var + 0x8C))) != 0)
      {
        var_v1 = 0;
      }
      var_v0 = *((void **) (((u8 *) var_v0) + 4));
    }
    while (var_v0 != 0);
  }
  return var_v1;
}

extern u8 *func_87E016C8(void);
extern s32 func_87F0E610(u8 *, u8 *);
extern s32 func_87E18ECC(void *);
extern s32 func_87E1369C(void);
extern void func_800279C4(s32);
extern void func_87E11BA4(s32);
extern s8 func_87F0E650(u8 *);
extern void Minigame_SetPlayerMask(s8);
extern void func_87E134E8(void);
extern void func_87E0168C(s32, s32, s32);
extern s32 func_87E13688(void);
extern void func_800226C0(s32);
extern void func_87F0277C(s32);



s32 func_87E18F08(u8 *arg0) {
    s32 result;
    u16 buttons;
    // Player mask from func_87F0E650, consumed by Minigame_SetPlayerMask. Routing the
    // call result through a named s8 local spills the two button-mask booleans at
    // 0x24/0x28 as retail; passing the call straight to Minigame_SetPlayerMask spills
    // them at 0x20/0x24.
    s8 mask;

    result = 0;
    D_87E1EC90 = arg0;
    buttons = func_87F0E610(func_87E016C8(), (u8 *)-1);
    switch (*(s32 *)(arg0 + 4)) {
    case 0:
        if (func_87E18ECC(arg0)) {
            *(s32 *)(arg0 + 4) = 1;
        }
        break;
    case 1:
        if (func_87E1369C() && !(buttons & 0x8000) && !(buttons & 0x4000)) {
            *(s32 *)arg0 = *(s32 *)arg0 + ((s32)(buttons & 0x400) > 0) - ((s32)(buttons & 0x800) > 0);
            if (*(s32 *)arg0 < 0) {
                *(s32 *)arg0 = 2;
            }
            if (*(s32 *)arg0 >= 3) {
                *(s32 *)arg0 = 0;
            }
            if (buttons & 0xC00) {
                func_800279C4(0xCF01);
            }
        }
        func_87E10EA8(*(s32 *)(arg0 + 0x28));
        func_87E10F2C(3);
        if (*(s32 *)(arg0 + 0x28) == 0x2C) {
            switch (*(s32 *)arg0) {
            case 2:
                func_87E11BA4(0);
                break;
            case 1:
                func_87E11BA4(1);
                break;
            case 0:
                func_87E11BA4(2);
                break;
            }
        }
        if (buttons & 0x8000) {
            mask = func_87F0E650(func_87E016C8());
            Minigame_SetPlayerMask(mask);
            func_87E18B0C(arg0);
            func_87E134E8();
            func_800279C4(0xCF02);
            *(s32 *)(arg0 + 4) = 2;
            switch (*(s32 *)arg0) {
            case 2:
                *(s32 *)(arg0 + 8) = 1;
                break;
            case 1:
                *(s32 *)(arg0 + 8) = 2;
                break;
            case 0:
                *(s32 *)(arg0 + 8) = 3;
                break;
            }
            func_87E0168C(3, 0x8C, 9);
        }
        if (buttons & 0x4000) {
            if (func_87E13688()) {
                func_87E18D20(arg0);
                func_800226C0(3);
                *(s32 *)(arg0 + 4) = 2;
                *(s32 *)(arg0 + 8) = 4;
                func_87E0168C(3, 0x8C, 0xE);
            }
        }
        break;
    case 2:
        if (func_87E18ECC(arg0)) {
            result = *(s32 *)(arg0 + 8);
        }
        func_87E10EA8(-1);
        func_87E10F2C(-1);
        break;
    }
    func_87F0277C((s32)(arg0 + 0xC));
    return result;
}

extern void func_87F0AF4C(s32);
void func_87E1918C(s32 arg0) {
    func_87F0AF4C(arg0 + 12);
}
#endif
