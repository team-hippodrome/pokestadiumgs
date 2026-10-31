#include "global.h"


#ifdef VERSION_US
extern s32 D_80128120;
extern u8 D_80128128[];
typedef struct Pair4EC00G { u8 bytes[4]; } Pair4EC00G;
void func_8004EC00(s32 arg0, s32 arg1) {
    s32 index;
    Pair4EC00G *entry;
    Pair4EC00G *entry2;
    index = D_80128120;
    if (index < 0x1F) {
        entry = (Pair4EC00G *)(D_80128128 + index * 4);
        entry[1] = entry[0];
        D_80128120 = index + 1;
        index = D_80128120;
    }
    entry2 = (Pair4EC00G *)(D_80128128 + index * 4);
    *(s16 *)entry2 = arg0;
    *(s16 *)((u8 *)entry2 + 2) = arg1;
}
#endif

#ifdef VERSION_US
extern s32 D_80128120; void func_8004EC5C(void) { if (D_80128120 > 0) { D_80128120--; } }
#endif

#ifdef VERSION_US
// Returns 1 if (x, y) lies within x = -640..640 and y = -479..480, else 0.
// Callers (func_8004F64C, func_8004FC58, func_80050218) branch past their following code when it returns 0.
s32 func_8004EC7C(s16 x, s16 y) {
    s32 in_bounds = 1;

    if ((x < -640) || (x > 640)) {
        in_bounds = 0;
    } else if ((y < -479) || (y > 480)) {
        in_bounds = 0;
    }
    return in_bounds;
}
#endif

#ifdef VERSION_US
extern s32 D_80128120;
extern u8 D_80128128[];
extern void func_8004EC00();
extern void func_8004EC5C(void);
typedef void (*CallbackNode_8004ECD4)();
typedef void (*RenderNode_8004ECD4)();
extern RenderNode_8004ECD4 D_80097200[];
typedef struct Node_8004ECD4 {
    u8 type; u8 pad1; u16 flags; u8 pad4[4]; s16 x; s16 y; u8 padC[8];
    struct Node_8004ECD4 *next; u8 pad18[4]; CallbackNode_8004ECD4 callback;
} Node_8004ECD4;
typedef struct Copy4_8004ECD4 { u8 bytes[4]; } Copy4_8004ECD4;
void func_8004ECD4(void *arg0, s32 arg1, s32 arg2) {
    Node_8004ECD4 *head;
    Node_8004ECD4 *node;
    CallbackNode_8004ECD4 callback;
    Copy4_8004ECD4 pair;
    s16 *coords;
    head = *(Node_8004ECD4 **)((u8 *)arg0 + 0x18);
    node = head;
    coords = (s16 *)pair.bytes;
    if (head != NULL) {
        do {
            func_8004EC00(arg1, arg2);
            if (node->flags & 1) {
                callback = node->callback;
                if (callback != NULL) {
                    callback(1, node);
                }
                pair = *(Copy4_8004ECD4 *)(D_80128128 + D_80128120 * 4);
                coords[0] += node->x;
                coords[1] += node->y;
                D_80097200[node->type](node, coords[0], coords[1]);
            }
            func_8004EC5C();
            node = node->next;
        } while (node != head);
    }
}
#endif

#ifdef VERSION_US
extern void func_8004ECD4(void *, s32, s32);
void func_8004EE04(u8 *arg0, s32 arg1, s32 arg2) {
    arg1 += *(s16 *)(arg0 + 8);
    arg2 += *(s16 *)(arg0 + 10);
    func_8004ECD4(arg0, arg1, arg2);
}
#endif

#ifdef VERSION_US
void func_8004EE30(u8 *arg0, const u8 *arg1) {
    arg0[0] = arg1[0];
    arg0[1] = arg1[1];
    arg0[2] = arg1[2];
}
#endif

#ifdef VERSION_US
void func_8004EE4C(u16 *arg0, u8 *arg1)
{
  u8 r = arg1[0];
  u8 g = arg1[1];
  u8 b = arg1[2];
  g = (g >> 3) & 0x1F;
  b = (b >> 3) & 0x1F;
  r = r >> 3;
  *arg0 = (((r << 11) | (g << 6)) | (b << 1)) | 1;
}
#endif

void func_8004EE94(void) {
}

#ifdef VERSION_US
// Same layout as TextureRenderHeader in 4CC20.c: texture data begins after this eight-byte header.
//@src/4CC20.c
typedef struct TextureRenderHeader {
    u16 width;
    u16 height;
    u8 format;
    u8 size;
    u16 unk_06;
} TextureRenderHeader;

extern u8 *func_8004CA60(TextureRenderHeader *texture);
extern void func_800459AC(u8 *image, u8 format, u8 size, u16 width, s32 height, s32 swapped, s32 palette, s32 cms,
                          s32 cmt, s32 masks, s32 maskt, s32 shifts, s32 shiftt);
extern void GfxRect_DrawTextured(s16 x, s16 y, s16 width, s16 height, s16 s, s16 t, s16 dsdx, s16 dtdy, s32 cycle);

// Draws the border of the width x height box at (x, y) from four corner textures. Each corner is drawn
// at its own size; the edges between corners are drawn with dsdx or dtdy 0, which repeats the
// corner texture's first column or row across the edge. The interior is not drawn.
// Draws nothing unless all four textures are non-NULL.
void func_8004EE9C(s32 x, s32 y, s32 width, s32 height, TextureRenderHeader *topLeft, TextureRenderHeader *topRight,
                   TextureRenderHeader *bottomLeft, TextureRenderHeader *bottomRight) {
    s32 right;
    s32 bottom;
    s32 pad[2]; // FAKE: unused; enlarges the frame from 0x68 to 0x70 bytes; diff score 186 without it.

    if ((topLeft != NULL) && (topRight != NULL) && (bottomLeft != NULL) && (bottomRight != NULL)) {
        func_800459AC(func_8004CA60(topLeft), topLeft->format, topLeft->size, topLeft->width, topLeft->height, 1, 0, 2,
                      2, 0, 0, 0, 0);
        GfxRect_DrawTextured(x, y, topLeft->width, topLeft->height, 0, 0, 0x400, 0x400, 0);

        // Top edge, then the top-right corner.
        func_800459AC(func_8004CA60(topRight), topRight->format, topRight->size, topRight->width, topRight->height, 1,
                      0, 2, 2, 0, 0, 0, 0);
        GfxRect_DrawTextured(topLeft->width + x, y, width - topLeft->width - topRight->width, topRight->height, 0, 0,
                             0, 0x400, 0);
        right = x + width;
        GfxRect_DrawTextured(right - topRight->width, y, topRight->width, topRight->height, 0, 0, 0x400, 0x400, 0);

        // Left edge, then the bottom-left corner.
        func_800459AC(func_8004CA60(bottomLeft), bottomLeft->format, bottomLeft->size, bottomLeft->width,
                      bottomLeft->height, 1, 0, 2, 2, 0, 0, 0, 0);
        GfxRect_DrawTextured(x, topLeft->height + y, bottomLeft->width, height - topLeft->height - bottomLeft->height,
                             0, 0, 0x400, 0, 0);
        bottom = y + height;
        GfxRect_DrawTextured(x, bottom - bottomLeft->height, bottomLeft->width, bottomLeft->height, 0, 0, 0x400, 0x400,
                             0);

        // Bottom edge, right edge, then the bottom-right corner.
        func_800459AC(func_8004CA60(bottomRight), bottomRight->format, bottomRight->size, bottomRight->width,
                      bottomRight->height, 1, 0, 2, 2, 0, 0, 0, 0);
        GfxRect_DrawTextured(bottomLeft->width + x, bottom - bottomLeft->height,
                             width - bottomLeft->width - bottomRight->width, bottomRight->height, 0, 0, 0, 0x400, 0);
        GfxRect_DrawTextured(right - bottomRight->width, topRight->height + y, bottomRight->width,
                             height - topRight->height - bottomRight->height, 0, 0, 0x400, 0, 0);
        GfxRect_DrawTextured(right - bottomRight->width, bottom - bottomRight->height, bottomRight->width,
                             bottomRight->height, 0, 0, 0x400, 0x400, 0);
    }
}

#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/4F800/func_8004F2D0.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/4F800/func_8004F64C.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/4F800/func_8004FA6C.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/4F800/func_8004FC58.s")
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/4F800/func_8004FE00.s")
#endif

#ifdef VERSION_US
extern s32 D_800971F8;
extern void func_8004FC58(u8 *, s32, s32);
extern void func_8004FE00(u8 *, s32, s32);
extern void func_8004ECD4(void *, s32, s32);
void func_800501A0(u8 *arg0, s32 arg1, s32 arg2) {
    if (*(u16 *)(arg0 + 2) & 2) {
        if (*(u8 *)(arg0 + 0x29) == 0) {
            func_8004FC58(arg0, arg1, arg2);
        } else {
            func_8004FE00(arg0, arg1, arg2);
        }
    }
    D_800971F8 = (s32)arg0;
    func_8004ECD4(arg0, arg1, arg2);
    D_800971F8 = 0;
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/4F800/func_80050218.s")
#endif

#ifdef VERSION_US
extern s32 D_800971F0;
extern void func_8004EE04(u8 *, s32, s32);
typedef void (*Callback_800503A4)();
void func_800503A4(u8 *arg0) {
    if (arg0 != NULL && (*(u16 *)(arg0 + 2) & 1)) {
        D_80128120 = 0;
        *(s16 *)(D_80128128 + 0) = 0;
        *(s16 *)(D_80128128 + 2) = 0;
        D_800971F0 = (s32)arg0;
        if (*(Callback_800503A4 *)(arg0 + 0x1C) != NULL) {
            (*(Callback_800503A4 *)(arg0 + 0x1C))(1, arg0);
        }
        func_8004EE04(arg0, 0, 0);
        D_800971F0 = 0;
    }
}
#endif

#ifdef VERSION_US
typedef struct TreeNode_80050428 {
    u8 pad0[4];
    s32 id;
    u8 pad8[12];
    struct TreeNode_80050428 *next;
    struct TreeNode_80050428 *children;
} TreeNode_80050428;
void *func_80050428(arg0, arg1)
TreeNode_80050428 *arg0;
s32 arg1;
{
    TreeNode_80050428 *first;
    TreeNode_80050428 *node;
    void *result;
    result = NULL;
    first = arg0->children;
    if (arg1 == arg0->id) {
        result = arg0;
    } else {
        node = first;
        if (first != NULL) {
            do {
                result = func_80050428(node, arg1);
                if (result != NULL) break;
                node = node->next;
            } while (node != first);
        }
    }
    return result;
}
#endif

#ifdef VERSION_US
void *func_8005049C(TreeNode_80050428 *arg0, s32 arg1) {
    return func_80050428(arg0, arg1);
}
#endif

#ifdef VERSION_US
void func_800504BC(s16 *arg0) {
    if (D_800971F0 != 0) {
        arg0[0] = *(s16 *)(D_80128128 + D_80128120 * 4);
        arg0[1] = *(s16 *)(D_80128128 + D_80128120 * 4 + 2);
        return;
    }
    arg0[0] = 0;
    arg0[1] = 0;
}
#endif

#ifdef VERSION_US
u8 func_80050518(u8 arg0) {
    return arg0 & 0xF;
}
#endif

#ifdef VERSION_US
void func_80050528(u8 *arg0) {
    *(s16 *)(arg0 + 0) = 0;
    *(s16 *)(arg0 + 4) = 1;
    *(s32 *)(arg0 + 8) = 0;
}
#endif

#ifdef VERSION_US
void func_8005053C(void *arg0, u8 *arg1) {
    if (arg0 != NULL) {
        func_80050528(arg1);
        (*(u8 **)((u8 *)(arg0) + (0x34))) = arg1;
    }
}
#endif

#ifdef VERSION_US
void func_80050578(u8 *arg0, s32 arg1) { if (arg0 != NULL) { u8 *value = *(u8 **)(arg0 + 0x34); if (value != NULL) { *(s16 *)(value + 0) = -1; *(s16 *)(value + 2) = 0; *(s32 *)(value + 8) = arg1; } } }
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/4F800/func_800505A4.s")
#endif

#ifdef VERSION_US
extern s32 func_800505A4(u8 *);
s32 func_80050640(u8 *arg0)
{
  s32 result = -2;
  int new_var;
  if ((*((u16 *) (arg0 + 4))) & 1)
  {
    if ((*((u8 **) (arg0 + 8))) != 0)
    {
      *((s16 *) arg0) = func_800505A4(arg0);
      result = *((s16 *) (((*((u8 **) ((*((u8 **) (arg0 + 8))) + 4))) + ((*((s16 *) (arg0 + 2))) * 4)) + (new_var = 2)));
    }
  }
  return result;
}
#endif

#ifdef VERSION_US
s32 func_800506A4(u8 *arg0) {
    s32 result = 0;
    u8 *value;
    u8 *sub;
    value = *(u8 **)(arg0 + 0x34);
    if (value != NULL) {
        sub = *(u8 **)(value + 8);
        if (sub != NULL) {
            if (*(u16 *)(sub + 2) == *(s16 *)(value + 2) + 1) {
                if (*(s16 *)(*(u8 **)(sub + 4) + (*(s16 *)(value + 2) * 4)) == *(s16 *)value + 1) result = 1;
            }
        }
    }
    return result;
}
#endif

#ifdef VERSION_US
extern s32 D_801281B4;
extern u8 D_815097B0[];
extern u8 D_800CD020[];
extern void *func_80003240();
extern void __osSetFpcCsr();
extern void Sched_InitClientQueue();
extern void func_80005568();
extern void func_80004F34();
typedef void (*CallbackThread_80050700)();
void GbTower_AudioThread(s32 arg0) {
    CallbackThread_80050700 callback = (CallbackThread_80050700)func_80003240(D_815097B0);
    __osSetFpcCsr(0x01000C01);
    Sched_InitClientQueue(D_801281B4, 0, 1);
    func_80005568(D_801281B4);
loop:
    func_80004F34(D_801281B4);
    if (*(s16 *)(D_800CD020 + 0xA38) >= 0x15) {
        goto loop;
    }
    callback(D_801281B4);
    goto loop;
}
#endif

#ifdef VERSION_US
extern s32 D_801281B0;
extern u8 D_81509440[];
extern u8 D_81509674[];
typedef void (*CallbackThread_800507B8)();
void GbTower_EmuThread(s32 arg0) {
    CallbackThread_800507B8 callback1 = (CallbackThread_800507B8)func_80003240(D_81509440);
    CallbackThread_800507B8 callback2 = (CallbackThread_800507B8)func_80003240(D_81509674);
    __osSetFpcCsr(0x01000C01);
    Sched_InitClientQueue(D_801281B0, 0, 1);
    func_80005568(D_801281B0);
    callback1(D_801281B0);
    osStartThread((OSThread *)D_801281B4);
loop:
    func_80004F34(D_801281B0);
    if (*(s16 *)(D_800CD020 + 0xA38) >= 0x15) {
        goto loop;
    }
    callback2(D_801281B0);
    goto loop;
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/4F800/func_80050878.s")
#endif

#ifdef VERSION_US
extern u8 D_801281B8;
extern u8 D_81500000[];
extern u8 D_15877A0[];
extern u8 D_15B9B60[];
extern void main_pool_push_state(s32);
extern s32 main_pool_alloc(s32, s32);
extern void Fragment_Load(s32, void *, void *);
extern s32 func_80047524(void);
extern s32 func_80047558(s32, s32);
extern s32 func_80050878(void);
extern u8 GbTower_SetPollMask(u8);
typedef struct Copy8_80050994 { u8 bytes[8]; } Copy8_80050994;

// Same code as Pokemon Stadium's GbTower_Start (src/gb_tower_audio.c): allocates the
// emulator state (D_801281B0) and audio thread (D_801281B4), loads the fragment at
// 0x81500000, and starts both threads. GS takes both fonts from the archive returned
// by func_80047524, stores func_80050878's result at 0x2204, and keeps the poll mask
// in D_801281B8.
void func_80050994(void *arg0) {
    s32 archive;

    main_pool_push_state(0x4742454D);
    D_801281B0 = main_pool_alloc(0x2210, 0);
    D_801281B4 = main_pool_alloc(0x21E0, 0);
    Fragment_Load((((u32)D_81500000 & 0x0FF00000) >> 20) - 0x10, D_15877A0, D_15B9B60);
    archive = func_80047524();
    *(s32 *)((u8 *)D_801281B0 + 0x21FC) = func_80047558(archive, 1);
    *(s32 *)((u8 *)D_801281B0 + 0x2200) = func_80047558(archive, 2);
    *(s32 *)((u8 *)D_801281B0 + 0x2204) = func_80050878();
    *(Copy8_80050994 *)((u8 *)D_801281B0 + 0x2208) = *(Copy8_80050994 *)arg0;
    osCreateMesgQueue((OSMesgQueue *)((u8 *)D_801281B0 + 0x21E4), (OSMesg *)((u8 *)D_801281B0 + 0x21E0), 1);
    osCreateThread((OSThread *)D_801281B4, 10, GbTower_AudioThread, NULL, (u8 *)D_801281B4 + 0x21E0, 17);
    osCreateThread((OSThread *)D_801281B0, 8, GbTower_EmuThread, NULL, (u8 *)D_801281B0 + 0x21E0, 15);
    D_801281B8 = GbTower_SetPollMask(0);
    osStartThread((OSThread *)D_801281B0);
}
#endif

#ifdef VERSION_US

void *GbTower_RecvExitMesg(void) {
    void *sp1C;

    osRecvMesg(D_801281B0 + 0x21E4, &sp1C, 1);
    return sp1C;
}
#endif

#ifdef VERSION_US
extern u8 D_801281B8;
extern u8 GbTower_SetPollMask(u8);
extern void Display_ApplyPendingVideoMode(void);
extern void func_800055B0();
extern void main_pool_pop_state();
typedef struct Copy8_80050B40 { u8 bytes[8]; } Copy8_80050B40;
void func_80050B40(void *arg0) {
    *(Copy8_80050B40 *)arg0 = *(Copy8_80050B40 *)((u8 *)D_801281B0 + 0x2208);
    GbTower_SetPollMask(D_801281B8);
    osViBlack(1);
    Display_ApplyPendingVideoMode();
    func_800055B0(D_801281B0);
    func_800055B0(D_801281B4);
    osDestroyThread((OSThread *)D_801281B0);
    osDestroyThread((OSThread *)D_801281B4);
    main_pool_pop_state(0x4742454D);
}
#endif
