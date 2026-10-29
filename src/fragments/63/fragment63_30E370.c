#include "global.h"


#ifdef VERSION_US
extern u8 D_87E1A240[];
extern void func_87E10EA8(s32);
extern void func_87E10E64(s32);
extern void func_87E10F2C(s32);
void func_87E0AA00(void *arg0) {
    s32 *entry;
    s32 state;

    state = *(s32 *)((u8 *)arg0 + 0);
    entry = (s32 *)((u8 *)D_87E1A240 +
        (*(s32 *)*(void **)((u8 *)arg0 + 8) * 0xC));
    if ((state == 2) || (state == 3)) {
        func_87E10EA8(-1);
        func_87E10F2C(-1);
        return;
    }
    func_87E10E64(entry[0]);
    func_87E10EA8(entry[1]);
    func_87E10F2C(entry[2]);
}

extern u8 *D_87F119DC;
extern void func_87F0B4AC(void *, void *, void *, void *);
extern void func_87E13558(void *, f32, f32, f32, s32);
void func_87E0AA8C(void) {
    u8 *state = D_87F119DC;

    func_87F0B4AC(*(void **)(*(u8 **)(state + 0x38) + 0xC),
                 state + 0x48, state + 0x54, state + 0x42);
    func_87E13558(D_87F119DC, -34.0f, 11.0f, 0.0f, 6);
}

extern Gfx *D_800D0510;
extern void *D_8009491C;
extern void GeoRender_ApplyMaterialState(void);
void func_87E0AAE4(s32 arg0, s32 arg1) {
    void *context;

    if (arg0 == 5) {
        gDPPipeSync(D_800D0510++);
        gDPSetCombine(D_800D0510++, 0xFFFFFF, 0xFFFCF238);
        context = *(void **)((u8 *)D_8009491C + 0x14);
        gSPSegment(D_800D0510++, 0xF,
                   *(void **)((u8 *)*(void **)((u8 *)context + 4) + 8));
        gSPDisplayList(D_800D0510++, *(void **)context);
        GeoRender_ApplyMaterialState();
    }
}

extern void func_8004C8C0(s32);
void func_87E0AB9C(void) {
    func_8004C8C0(425);
}

extern u8 D_87E1A200[];
extern s32 main_pool_get_available(void);
extern s32 MainPool_AllocState(s32, s32);
extern s32 process_geo_layout(s32, void *);
extern void MainPool_FinalizeAllocation(s32);
void func_87E0ABBC(u8 *arg0) {
    s32 temp = MainPool_AllocState(main_pool_get_available(), 0);
    *(s32 *)(arg0 + 0x18) = process_geo_layout(temp, D_87E1A200);
    MainPool_FinalizeAllocation(temp);
}

extern void func_87F024CC(void);
extern void func_87F0ADE0(void *, u32);
extern void *main_pool_alloc(s32, s32);

void func_87E0AC0C(u8 *arg0) {
    s32 offset;

    func_87F024CC();
    func_87F0ADE0(arg0 + 0x1C, 1);
    *(void **)(arg0 + 0x34) = main_pool_alloc(0x8C, 0);
    for (offset = 0; offset < 0x8C; offset += 0x8C) {
        *(u8 **)((u8 *)*(void **)(arg0 + 0x34) + offset + 0x88) = arg0;
    }
}

extern void func_87F02684(s32);
void func_87E0AC6C(s32 arg0) {
    func_87F02684((arg0 + 28));
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_30E370/func_87E0AC8C.s")

extern void func_87E0AC0C(u8 *);
extern void func_87E11C38(s32);
void func_87F061D0(void);
extern void func_87E0AB9C(void);
extern void func_87E0ABBC(u8 *arg0);
void func_87E0ADA8(u8 *arg0, s32 arg1, s32 *arg2, s32 arg3, s32 arg4) {
    (*(s32 *)((u8 *)(arg0) + (0))) = 0;
    (*(s32 *)((u8 *)(arg0) + (4))) = arg1;
    (*(s32 **)((u8 *)(arg0) + (8))) = arg2;
    (*(s32 *)((u8 *)(arg0) + (0x10))) = arg3;
    (*(s32 *)((u8 *)(arg0) + (0xC))) = arg4;
    (*(s32 *)((u8 *)(arg0) + (0x38))) = 0;
    (*(f32 *)((u8 *)(arg0) + (0x14))) = (f32) (*arg2 << 5);
    func_87E0AB9C();
    func_87E0ABBC(arg0);
    func_87E0AC0C(arg0);
    func_87F061D0();
    func_87E11C38(*(*(s32 **)((u8 *)(arg0) + (8))));
}

s32 func_87E0AE28(void *arg0)
{
  void *new_var;
  void *node;
  void *container;
  void *state;
  s32 result;
  result = 1;
  node = *((void **) (((u8 *) arg0) + 0x28));
  if (node != 0)
  {
    do
    {
      ;
 if (1) { } if (1) { } if (1) { } if (1) { }
      ;
      new_var = *((void **) (((u8 *) (*((void **) (((u8 *) node) + 0x38)))) + 0xC));
      if ((*((s32 *) (((u8 *) new_var) + 0x84))) != 0)
      {
        result = 0;
      }
      node = *((void **) (((u8 *) node) + 4));
    }
    while (node != 0);
  }
  return result;
}

extern void func_87F0B1A4(u8 *, f32 *, f32, f32, f32, s32, s32);
extern void func_87F0B2F4(u8 *, s16 *, f32, f32, f32, s32, s32);
void func_87E0AE64(void *arg0) {
    u8 *node;
    u8 *state;

    node = *(u8 **)((u8 *)arg0 + 40);
    while (node != NULL) {
        state = *(u8 **)(*(u8 **)(node + 56) + 12);
        func_87F0B1A4(state, (f32 *)(node + 72), *(f32 *)(node + 72),
            *(f32 *)(node + 76) - -120.0f, *(f32 *)(node + 80) + 200.0f, 15, 0x2000);
        func_87F0B2F4(state, (s16 *)(node + 66), 180.0f, 0.0f, 0.0f, 15, 0);
        node = *(u8 **)(node + 4);
    }
}

extern u32 func_8003570C(void);

// Walks the node list at arg0 + 0x28 and for each node submits its state
// (the object at node + 0x38's offset 0xC) to func_87F0B1A4 with the node's
// position floats at offsets 0x48..0x50 (the second offset shifted by
// -360.0f), then randomizes the node's rotation through func_87F0B2F4:
// three draws from the LCG at func_8003570C, each scaled from [0,1) over
// 4294967296.0f to -45..45 degrees for the first two and -180..180 degrees
// for the third. func_87E0AE64 above is the same loop with fixed angles.
void func_87E0AF44(void *arg0) {
    f32 var_ft4;
    f32 var_ft5;
    u32 temp_s2;
    u32 temp_s3;
    u32 temp_v0;
    u8 *temp_s1;
    u8 *var_s0;

    var_s0 = *(u8 **)((u8 *)arg0 + 0x28);
    if (var_s0 != NULL) {
        do {
            temp_s1 = *(u8 **)(*(u8 **)(var_s0 + 0x38) + 0xC);
            func_87F0B1A4(temp_s1, var_s0 + 0x48, *(f32 *)(var_s0 + 0x48),
                *(f32 *)(var_s0 + 0x4C) + -360.0f, *(f32 *)(var_s0 + 0x50), 0xF, 0x2000);
            temp_s2 = func_8003570C();
            temp_s3 = func_8003570C();
            temp_v0 = func_8003570C();
            var_ft5 = (f32)(u32)temp_s3;
            var_ft4 = (f32)(u32)temp_v0;
            func_87F0B2F4(temp_s1, var_s0 + 0x42, (((f32)temp_s2 / 4294967296.0f) * 90.0f) - 45.0f,
                ((var_ft5 / 4294967296.0f) * 90.0f) - 45.0f,
                ((var_ft4 / 4294967296.0f) * 360.0f) - 180.0f, 0xF, 0);
            var_s0 = *(u8 **)(var_s0 + 4);
        } while (var_s0 != NULL);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_30E370/func_87E0B0EC.s")

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/63/fragment63_30E370/func_87E0B2CC.s")

extern void func_87F0AF4C(s32);
void func_87E0B6D4(s32 arg0) {
    func_87F0AF4C((arg0 + 28));
}
#endif
