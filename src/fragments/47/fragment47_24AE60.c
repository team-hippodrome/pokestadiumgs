#include "global.h"
#include "controller.h"


#ifdef VERSION_US
/* mkdraft:func_86004840 begin */
extern f32 __sinf(f32);
extern f32 __cosf(f32);
extern void func_80038E14(void *, f32, f32, f32, f32, f32, f32, u16);
extern void GeoCamera_SetPerspective(void *, f32, f32, f32);
extern void func_87C037C0(void *, void *);
extern f64 D_8600D840;
extern f64 D_8600D848;
extern f64 D_8600D850;
extern f64 D_8600D858;
extern f64 D_8600DFD8;
extern f64 D_8600DFE0;
extern u8 D_8600DE30[];
extern u8 *D_8600D234;

s32 func_86004840(s32 arg0, void *arg1) {
    f64 k;
    f32 s;
    f32 c;
    f64 b;

    if (arg0 != 2) {
        return 0;
    }
    s = __sinf((f32)((D_8600D840 * D_8600DFE0) / D_8600D848));
    c = __cosf((f32)((D_8600D850 * D_8600DFE0) / D_8600D858));
    k = *(f64 *)(D_8600DE30 + 0x1C0);
    b = *(f64 *)(D_8600DE30 + 0x1B8);
    func_80038E14(arg1, 0, (f32)(b + (f64)s * k),
                  (f32)((f64)c * k), 0.0f,
                  (f32)b, 0.0f, 0);
    GeoCamera_SetPerspective(arg1, (f32)D_8600DFD8, 64.0f, 32768.0f);
    if (D_8600D234 != 0) {
        func_87C037C0(D_8600D234 + 0x8150, arg1);
    }
    return 1;
}
/* mkdraft:func_86004840 end */

/* mkdraft:func_86004840_padding begin */
// Bytes at 0x86004960: the retail jr ra/nop stub between this function and
// func_86004968; no symbol covers that address. An unreferenced empty function
// compiles to those eight bytes and keeps the fragment layout (same convention
// as func_86004BC4_padding and func_860062E0_padding in this file).
void func_86004840_padding(void) {}
/* mkdraft:func_86004840_padding end */

void func_86004968(void *arg0) {
    typedef struct {
        u8 pad[0xAED0];
        f32 values[2][4][4];
    } Ctx;
    s32 i;
    s32 j;
    s32 k;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                ((Ctx *)arg0)->values[i][j][k] = 0.0f;
            }
        }
    }
}
typedef struct {
    u8 pad0[1];
    u8 flags;
    u8 pad2[0x166];
} Func860049B8Node;
typedef struct {
    u8 pad_0000[0x81D0];
    Func860049B8Node nodes[2][4][4];
    f32 values[2][4][4];
} Func860049B8Context;
extern void ModelAnim_SetAnimation(void *, s32);
extern void ModelAnim_SetSpeed(void *, s32);
extern void ModelAnim_SetFrame(void *, s16);
void func_860049B8(Func860049B8Context *arg0, f64 arg1) {
    s32 i;
    s32 j;
    s32 k;
    s32 frame;
    Func860049B8Node *node;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            for (k = j + 1; k < 4; k++) {
                node = &arg0->nodes[i][j][k];
                if (arg0->values[i][j][k] > 0.0f) {
                    frame = 16.0 - ((f64)(arg0->values[i][j][k] * 16.0f) / *(f64 *)(D_8600DE30 + 0x2D0));
                    ModelAnim_SetAnimation(node, 0);
                    ModelAnim_SetSpeed(node, 0);
                    ModelAnim_SetFrame(node, frame);
                    node->flags |= 1;
                    arg0->values[i][j][k] -= arg1;
                } else {
                    node->flags &= ~1;
                }
            }
        }
    }
}

void func_86004BC4(void) {}
void func_86004BC4_padding(void) {}

typedef struct {
    u32 words[0x50 / 4];
} Fragment47ModelBlock;
extern f64 D_8600D860;
extern f64 D_8600D868;
extern f64 D_8600D870;
extern f64 D_8600D878;
extern f64 D_8600D880;
extern f64 D_8600D888;
extern f64 D_8600D890;
extern void func_86009D7C(void *, f64, f64, f64, s32);
extern void func_86009E54(void *, void *, f64, f64, s32);
extern f64 func_8600A0C8(void *);
extern f64 func_8600A144(void *);


void func_86004BD4(u8 *arg0)
{
    f64 scale;
    f64 d888;
    f64 d890;
    f64 distance;
    u8 *second;
    u8 *first;
    first = arg0 + 0x6668;
    second = arg0 + 0x66B8;
    scale = D_8600D860;
    // FAKE: the self-subtraction makes IDO put the held scale in $fs0 and the loaded
    // angle in $ft; written as a plain product the two mul.d operand slots come out
    // swapped. The extra terms emit no code and x - x is +0.0 for the finite angles
    // in this table, so the right operand is still scale.
    func_86009D7C(first, 0.0, D_8600D868, ((*((f64 *) (D_8600DE30 + 0x100))) * ((*((f64 *) (D_8600DE30 + 0x100))) - (*((f64 *) (D_8600DE30 + 0x100))) + scale)) / D_8600D870, 0);
    func_86009E54(second, first, D_8600D878 * (*((f64 *) (D_8600DE30 + 0x110))), ((*((f64 *) (D_8600DE30 + 0x108))) * ((*((f64 *) (D_8600DE30 + 0x108))) - (*((f64 *) (D_8600DE30 + 0x108))) + scale)) / D_8600D880, (*((u32 *) (D_8600DE30 + 0x218))) != 0);
    d888 = D_8600D888;
    d890 = D_8600D890;
    *((f64 *) (arg0 + 0x66E0)) = *((f64 *) (D_8600DE30 + 0x150));
    *((f64 *) (arg0 + 0x66F0)) = *((f64 *) (D_8600DE30 + 0x140));
    *((f64 *) (arg0 + 0x6690)) = *((f64 *) (D_8600DE30 + 0x158));
    *((f64 *) (arg0 + 0x66A0)) = *((f64 *) (D_8600DE30 + 0x148));
    *((Fragment47ModelBlock *) (arg0 + 0x6708)) = *((Fragment47ModelBlock *) first);
    *((Fragment47ModelBlock *) (arg0 + 0x6758)) = *((Fragment47ModelBlock *) second);
    *((f64 *) (arg0 + 0x6730)) = *((f64 *) (D_8600DE30 + 0x138));
    *((f64 *) (arg0 + 0x6780)) = *((f64 *) (D_8600DE30 + 0x130));
    *((f64 *) (arg0 + 0x6740)) = *((f64 *) (D_8600DE30 + 0x128));
    *((f64 *) (arg0 + 0x6790)) = *((f64 *) (D_8600DE30 + 0x120));
    *((Fragment47ModelBlock *) (arg0 + 0x67A8)) = *((Fragment47ModelBlock *) first);
    *((Fragment47ModelBlock *) (arg0 + 0x67F8)) = *((Fragment47ModelBlock *) second);
    *((f64 *) (arg0 + 0x67D0)) = d888;
    *((f64 *) (arg0 + 0x6820)) = d888;
    *((f64 *) (arg0 + 0x67E0)) = d890;
    *((f64 *) (arg0 + 0x6830)) = d890;
    *((f64 *) (D_8600DE30 + 0x188)) = *((f64 *) (arg0 + 0x66D0));
    distance = func_8600A144(second) - func_8600A0C8(second);
    *((f64 *) (D_8600DE30 + 0x180)) = distance;
    *((f64 *) (D_8600DE30 + 0x178)) = *((f64 *) (arg0 + 0x66B8));
    *((f64 *) (D_8600DE30 + 0x1A0)) = *((f64 *) (arg0 + 0x6680));
    distance = func_8600A144(first) - func_8600A144(second);
    *((f64 *) (D_8600DE30 + 0x198)) = distance;
    *((f64 *) (D_8600DE30 + 0x190)) = *((f64 *) (arg0 + 0x6668));
    *((f64 *) (arg0 + 0x6868)) = *((f64 *) (D_8600DE30 + 0x238));
    *((f64 *) (arg0 + 0x6878)) = *((f64 *) (D_8600DE30 + 0x260));
    *((f64 *) (arg0 + 0x6870)) = *((f64 *) (D_8600DE30 + 0x230));
    *((f64 *) (arg0 + 0x6880)) = *((f64 *) (D_8600DE30 + 0x270));
}

typedef struct {
    u8 pad[0x7518];
    s32 value;
} Func86004E84State;
s32 func_86004E84(Func86004E84State *arg0) {
    s32 result;
    result = arg0->value == 2;
    if (result == 0) {
        result = arg0->value == 3;
    }
    return result;
}

extern s32 func_86009C08(void *, void *);
extern f64 func_86009C58(void *, void *);
extern f64 func_87C007DC(const f64 *, const f64 *);
f64 func_86004EA8(void *arg0, void *arg1)
{
    if (func_86009C08(((u8 *) arg0) + 0x66B8, arg1) != 0)
    {
        return func_86009C58(((u8 *) arg0) + 0x66B8, arg1);
    }
    if (func_86009C08(((u8 *) arg0) + 0x6668, arg1) != 0)
    {
        return func_86009C58(((u8 *) arg0) + 0x6668, arg1);
    }
    return func_87C007DC(((u8 *) arg0) + 0x6848, arg1);
}

extern s32 func_86009FB8(void *arg0, void *arg1, void *arg2);
typedef struct Fragment47Vec3d {
    f64 v[3];
} Fragment47Vec3d;
void func_86004F2C(void *arg0, void *arg1, Fragment47Vec3d *arg2)
{
    if (func_86009C08(((u8 *) arg0) + 0x66B8, arg1) != 0)
    {
        func_86009FB8(((u8 *) arg0) + 0x66B8, arg1, arg2);
    } else if (func_86009C08(((u8 *) arg0) + 0x6668, arg1) != 0)
    {
        func_86009FB8(((u8 *) arg0) + 0x6668, arg1, arg2);
    } else {
        *arg2 = *(Fragment47Vec3d *)((u8 *) arg0 + 0x6848);
    }
}

extern u8 D_8600D238[];
extern u8 D_8600D720[];
extern u8 D_8600D760[];
extern s32 MathUtil_Random16(void);
extern s32 func_80040E80(s32, void *);
extern s32 func_8004C8C0(u16 arg0);
extern s32 func_80071940(s32 arg0, s32 arg1);
extern void func_80071A40(s32 arg0, s16 *arg1);
extern s32 func_8600062C();
extern void func_86001A58(u8 *arg0, s32 arg1);
extern void func_86002234(u8 *arg0, s32 arg1, f32 arg2, void *arg3, void *arg4);
extern void func_8600CD10(void **arg0, s32 arg1);
extern void func_87F00030(void);
extern void func_87F01870(void *arg0);
extern void func_87F01F34(void *);
extern void func_87F06EAC(s32, void *, void *);
extern void func_87F09EBC(u8 *arg0, s32 arg1);
extern void func_87F0C650(void *arg0);
extern void func_87F0C694(void *arg0, s32 arg1);
extern void func_87F0D48C(void *, void *, s32);


void func_86004FDC(void *state, void *resource) {
    typedef struct { f64 values[8]; } StagePlanes;
    typedef struct { u8 b7 : 1; u8 b6 : 1; u8 b5 : 1; u8 b4 : 1; u8 b3 : 1; u8 b2 : 1; u8 b1 : 1; u8 b0 : 1; } StateFlags;

    s32 index;
    u8 *ptr;

    D_8600D234 = state;
    *(void **)((u8 *)state + 0x7580) = resource;
    ptr = (u8 *)state + 0xAF50;
    func_87F0C650(ptr);
    func_87F0D48C((u8 *)state + 0x74F0, *(void **)((u8 *)state + 0x7580), 0);
    if (*(u8 *)((u8 *)*(void **)((u8 *)state + 0x7580) + 0x2180) == 4) {
        func_87F0C694(ptr, 0x14);
    }
    *(s32 *)((u8 *)state + 0x75BC) = 0;
    func_8004C8C0(0xDF);
    ptr = (u8 *)state + 0x68A0;
    func_80071940(0, (s32)ptr);
    func_80071A40((s32)ptr, (s16 *)D_8600D760);
    {
        void *allocation;
        allocation = MainPool_AllocState(main_pool_get_available(), 0);
        *(void **)((u8 *)state + 0x6660) = func_80040E80(allocation, (u32)D_8600D238);
        MainPool_FinalizeAllocation(allocation);
    }
    func_8600CD10((u8 *)state + 0x8128, *(void **)((u8 *)state + 0x7580));
    *(StagePlanes *)((u8 *)state + 0x6848) = *(StagePlanes *)D_8600D720;
    func_86004BD4(state);
    for (index = 0; index != 4; index++) {
        func_86002234((u8 *)state + index * 0x1998, index, (f32)*(f64 *)(D_8600DE30 + 0xF8),
                      func_8600062C, state);
        func_86001A58((u8 *)state + 0x75C8 + index * 0x2D8, index);
    }
    func_87F00030();
    func_87F01870(*(void **)((u8 *)state + 0x7580));
    func_87F01F34(*(void **)((u8 *)state + 0x7580));
    func_87F06EAC(0x6D, (u8 *)state + 0x7584, *(void **)((u8 *)state + 0x7580));
    func_87F09EBC((u8 *)state + 0x751C, *(void **)((u8 *)state + 0x7580));
    ((StateFlags *)((u8 *)state + 0x75C0))->b6 = 0;
    ((StateFlags *)((u8 *)state + 0x75C0))->b5 = 1;
    ((StateFlags *)((u8 *)state + 0x75C0))->b7 = 0;
    *(u8 *)((u8 *)state + 0x75C1) = MathUtil_Random16() % 4;
    ((StateFlags *)((u8 *)state + 0x75C0))->b4 = 0;
    ((StateFlags *)((u8 *)state + 0x75C0))->b1 = 0;
    func_86004968(state);
}

/* mkdraft:func_8600520C begin */
extern void func_87F029B8(s32, u8);
extern void func_87F02CB0(s32, s32);
extern void func_86002470(s32, s32, s32);
extern void func_86001A60(s32, s32);
extern void func_8003F018(s32);
extern s32 func_80071ADC(s32, s32);
extern void func_8003F114(s32, s32, s32, s32);
extern void func_86007648(s32, s32);

// Model grid at +0x81D0: 2 sides x 4 x 4 entries of 0x168 bytes. This function
// touches the flag byte at +1 of an entry; the remainder is untouched padding.
typedef struct {
    u8 pad_0000[1];
    u8 flags;
    u8 pad_0002[0x166];
} Func8600520CNode;

typedef struct {
    u8 pad_0000[0x81D0];
    Func8600520CNode nodes[2][4][4];
} Func8600520CContext;

// Rebuilds both sides' model and animation data, then every grid entry with
// j < k, then dispatches on the byte at *(arg0 + 0x7580) + 0x2180: mode 2 when
// that byte is 4, otherwise mode 0.
//
// Loop 1 runs until the running offset reaches 0xB60 (6 iterations of 0x2D8):
// func_86002470 re-creates a side's model, submodel, effect and overlay graph
// nodes from the resource file (+0x68A0) and the model array (+0x8128),
// func_86001A60 initializes the animation block that starts at +0x75C8, and the
// object advances 0x1998 per iteration.
//
// The do/while form and the statement order (offset, object, anim) are what put
// the animation addiu in the branch delay slot.
//
// Loop 2 walks i < 2, j < 4, k < 4 and acts only on j < k. Each selected entry
// is re-created by func_8003F018, the handle from func_80071ADC (0xC7 on side 0,
// 0xC8 on side 1) is func_8003F114's fourth argument, and flag bit 0 is cleared.
//
// The entry address is spelled as a cast of arg0 at each use. With a node
// pointer local the flag load shares the call argument's base (`lbu 1($s0)`);
// retail derives the flag address from a second base, element + 0x8000 with
// displacement 0x1D1, which also lets the ~1 mask live in $fp.
//
// The declaration order below is what produces the retail 0x60-byte frame with
// resource_file at 0x40(sp) and the arg0 home at 0x60(sp): IDO homes a register
// parameter at the frame size, so an order that changes the frame moves both.


void func_8600520C(s32 arg0) {
    s32 i;
    s32 j;
    s32 k;
    s32 offset;
    s32 anim;
    s32 object;
    s32 *models;
    s32 *resource_file;

    func_87F029B8(arg0 + 0x74B0, *(u8 *)(*(u8 **)(arg0 + 0x7580) + 0x2182));
    func_87F02CB0(arg0 + 0x74D0, 0x63);
    object = arg0;
    offset = 0;
    resource_file = (s32 *)(arg0 + 0x68A0);
    models = (s32 *)(arg0 + 0x8128);
    anim = arg0 + 0x75C8;
    do {
        func_86002470(object, (s32)resource_file, (s32)models);
        func_86001A60(anim, (s32)models);
        offset += 0x2D8;
        object += 0x1998;
        anim += 0x2D8;
    } while (offset != 0xB60);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            for (k = 0; k < 4; k++) {
                if (j < k) {
                    func_8003F018((s32)&((Func8600520CContext *)arg0)->nodes[i][j][k]);
                    func_8003F114((s32)&((Func8600520CContext *)arg0)->nodes[i][j][k], 0, -1,
                                  func_80071ADC((s32)resource_file, i > 0 ? 0xC8 : 0xC7));
                    ((Func8600520CContext *)arg0)->nodes[i][j][k].flags &= ~1;
                }
            }
        }
    }
    if (*(u8 *)(*(u8 **)(arg0 + 0x7580) + 0x2180) == 4) {
        func_86007648(arg0, 2);
        return;
    }
    func_86007648(arg0, 0);
}
/* mkdraft:func_8600520C end */

typedef struct Func860053F8Record {
    u8 pad_0000[0x1814];
    s32 value;
    u8 pad_1818[0x180];
} Func860053F8Record;
s32 func_860053F8(Func860053F8Record *arg0) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if (arg0[i].value != arg0[i + 1].value) {
            return 0;
        }
    }
    return 1;
}

extern void func_86003EFC(void *arg0, s32 arg1);
extern void func_86007648(s32 arg0, s32 arg1);
extern void func_87C00120(void *arg0, f64 arg1, f64 arg2, f64 arg3);
extern f64 func_86004EA8(void *arg0, void *arg1);
extern f32 __sinf(f32 arg0);
extern f32 __cosf(f32 arg0);
extern f64 D_8600D898;
extern f32 D_8600D8A0;
extern s32 D_8600E038;


s32 func_86005434(s32 arg0) {
    u8 *obj;
    s32 i;
    s32 count;
    s32 best;
    s32 min;
    s32 total;
    s32 index;
    s32 value;
    f32 angle;
    f32 sine;
    f32 cosine;
    f64 scale;
    f64 radius;

    best = 0;
    count = 0;
    index = (total = 0);
    min = *(s32 *)(D_8600DE30 + 0x208);
    if (*(s32 *)(arg0 + 0x7518) >= 4) {
        return 0;
    }
    if (!arg0) {
    } // FAKE: empty null check; without it saved registers s4-s6 rotate.
    i = 0;
    obj = (u8 *)arg0;
    do {
        i += 0x1998;
        if (*(s32 *)(obj + 0x1828) >= 7) {
            count++;
        } else {
            value = *(s32 *)(obj + 0x1814);
            if (value >= best) {
                best = value;
            }
        }
        obj += 0x1998;
    } while (i < 0x6660);
    if ((*(f64 *)(arg0 + 0x6888) < (f64)*(s32 *)(D_8600DE30 + 0x20C)) && (count < 3) &&
        (best < *(s32 *)(D_8600DE30 + 0x210))) {
        return 0;
    }
    if (func_860053F8((Func860053F8Record *)arg0) != 0) {
        i = 0;
        obj = (u8 *)arg0;
        do {
            *(f64 *)(obj + 0x17D0) = 0.0;
            if (*(s32 *)(obj + 0x1828) < 7) {
                func_86003EFC(obj, 8);
            }
            i += 0x1998;
            obj += 0x1998;
        } while (i != 0x6660);
    } else {
        i = 0;
        obj = (u8 *)arg0;
        do {
            *(f64 *)(obj + 0x17D0) = 0.0;
            if (*(s32 *)(obj + 0x1828) < 7) {
                if (*(s32 *)(obj + 0x1814) < best) {
                    func_86003EFC(obj, 8);
                } else {
                    value = *(s32 *)(obj + 0x1820);
                    if (value < min) {
                        min = value;
                    }
                }
            }
            i += 0x1998;
            obj += 0x1998;
            if (!obj) {
            } // FAKE: empty null check; without it saved registers rotate.
        } while (i < 0x6660);
        i = 0;
        obj = (u8 *)arg0;
        do {
            value = *(s32 *)(obj + 0x1828);
            if (value < 7) {
                if ((min >= *(s32 *)(obj + 0x1820)) || (D_8600E038 == 0)) {
                    if (value != 3) {
                        func_86003EFC(obj, 1);
                        func_86003EFC(obj, 2);
                        func_86003EFC(obj, 3);
                    }
                    func_86003EFC(obj, 6);
                    total++;
                } else {
                    func_86003EFC(obj, 8);
                }
            }
            i += 0x1998;
            obj += 0x1998;
        } while (i != 0x6660);
    }
    scale = D_8600D898;
    i = 0;
    obj = (u8 *)arg0;
    do {
        if (*(s32 *)(obj + 0x1828) == 6) {
            angle = ((((f32)index - ((f32)(total - 1) * 0.5f)) * D_8600D8A0) * 30.0f) / 180.0f;
            if (!(obj + 0x1878)) {
            } // FAKE: empty pointer check; without it register assignment changes.
            sine = __sinf(angle);
            cosine = __cosf(angle);
            radius = *(f64 *)(arg0 + 0x6670) * scale;
            func_87C00120(obj + 0x1878, (f64)sine * radius, 0.0, (f64)cosine * radius);
            *(f64 *)(obj + 0x1880) =
                (*(f64 *)(obj + 0x17C8) - func_86004EA8((void *)arg0, obj + 0x1878)) +
                *(f64 *)(obj + 0x1880);
            index++;
        }
        i += 0x1998;
        obj += 0x1998;
    } while ((u32)i != 0x6660u);
    if (*(u8 *)(*(u8 **)(arg0 + 0x7580) + 0x2180) == 4) {
        *(u8 *)(arg0 + 0x75C0) = (*(u8 *)(arg0 + 0x75C0) & 0xFF) | 0x80; // FAKE: the 0xFF mask is an arithmetic nop on a value already zero-extended to u8.
    } else {
        func_86007648(arg0, 4);
    }
    return 1;
}

extern u8 D_8600D780[];
extern f64 D_8600D8A8;
extern f64 D_8600D8B0;
extern f64 D_8600DEB0;
extern void func_86001CE8(u8 *arg0, f32 *arg1, f32 *arg2);
extern void func_86007D98(void *arg0, f64 arg1, f64 arg2, f64 arg3);
extern void func_8600853C(void *arg0, void *arg1, f64 arg2, f64 arg3, void *arg4);
extern void func_86009260(void *arg0, f64 arg1, void *arg2, s32 arg3, void *arg4);
extern void func_860095B8(void *arg0, f64 arg1);
extern void func_86009674(void *arg0, void *arg1, f64 arg2);


void func_860057D0(s32 arg0, f64 arg1) {
    f64 zero;
    f64 axis[3];
    f64 vec[3];
    f32 var84;
    f32 var80;
    s32 i;
    s32 j;

    zero = 0.0;
    func_87C00120(axis, zero, -D_8600DEB0 * D_8600D8A8, D_8600D8B0 * D_8600DEB0);
    for (i = 0; i < 4; i++) {
        func_860095B8((u8 *)arg0 + i * 0x2D8 + 0x7760, arg1);
    }
    for (i = 0; i < 4; i++) {
        var84 = 0.0f;
        var80 = 0.0f;
        func_86001CE8((u8 *)arg0 + i * 0x2D8 + 0x75C8, &var84, &var80);
        func_86007D98((u8 *)arg0 + i * 0x2D8 + 0x7760, var84, var80, arg1);
    }
    for (i = 0; i < 4; i++) {
        func_86009260((u8 *)arg0 + i * 0x2D8 + 0x7760, arg1, D_8600D780, 1, vec);
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (i != j) {
                func_8600853C((u8 *)arg0 + i * 0x2D8 + 0x7760,
                              (u8 *)arg0 + j * 0x2D8 + 0x7760,
                              arg1, 5.0, vec);
            }
            // FAKE: dead mention of arg0 that fixes uopt's walk so arg0 is $s3 and anim is $s4.
            if (!arg0) {
            }
        }
    }
    for (i = 0; i < 4; i++) {
        // FAKE: constant-folded dead-if that gives zero a callee-saved FPR slot without emitting code.
        if (zero == 0.0) {
        }
        func_86009674((u8 *)arg0 + i * 0x2D8 + 0x7760, axis, arg1);
    }
}

/* mkdraft:func_86005A00 begin */
extern f32 D_8600D8B8;
extern f32 D_8600D8BC;
extern f32 D_8600D8C0;
extern f32 D_8600D8C4;
extern f32 D_8600D8C8;
extern f32 D_8600D8CC;

// Direction deltas: 64 along an axis, 64/sqrt(2) = 45.255 diagonally.
// 0x100/0x200 select +x/-x, 0x800/0x400 select +y/-y; with no axis bit set
// the direction is (0, +-64).
//
// The value pairs are block-scoped temporaries. IDO allocates a temporary
// pair per block and reuses the lowest free pair, which reproduces the retail
// register usage: $f0/$f2 in the 0x800 cases and 0x400&0x100 ($f2 alone for
// 0x400&0x200), $f4/$f6 in the 0x800-only and 0x200-only cases, $f8/$f10 in
// 0x400-only and the first s16 conversion, $f16/$f18 in 0x100-only and the
// second conversion.


void func_86005A00(void *arg0, f32 *arg1, f32 *arg2) {
    s32 temp_v0;

    temp_v0 = *(u16 *)((u8 *)arg0 + 6);
    if (temp_v0 & 0xF00) {
        if (temp_v0 & 0x800) {
            if (temp_v0 & 0x100) {
                {
                    f32 a = D_8600D8B8;
                    *arg1 = a;
                    *arg2 = a;
                }
                return;
            }
            if (temp_v0 & 0x200) {
                // The first value loaded is the one that goes to *arg2.
                {
                    f32 a = D_8600D8BC, b = D_8600D8C0;
                    *arg1 = b;
                    *arg2 = a;
                }
                return;
            }
            {
                f32 a = 0.0f, b = 64.0f;
                *arg1 = a;
                *arg2 = b;
            }
            return;
        }
        if (temp_v0 & 0x400) {
            if (temp_v0 & 0x100) {
                {
                    f32 a = D_8600D8C4, b = D_8600D8C8;
                    *arg1 = a;
                    *arg2 = b;
                }
                return;
            }
            if (temp_v0 & 0x200) {
                {
                    f32 a = D_8600D8CC, b = D_8600D8CC;
                    *arg1 = a;
                    *arg2 = b;
                }
                return;
            }
            {
                f32 a = 0.0f, b = -64.0f;
                *arg1 = a;
                *arg2 = b;
            }
            return;
        }
        if (temp_v0 & 0x100) {
            {
                f32 a = 64.0f, b = 0.0f;
                *arg1 = a;
                *arg2 = b;
            }
            return;
        }
        if (temp_v0 & 0x200) {
            {
                f32 a = -64.0f, b = 0.0f;
                *arg1 = a;
                *arg2 = b;
            }
        }
    } else {
        *arg1 = (f32) *(s16 *)((u8 *)arg0 + 2);
        *arg2 = (f32) *(s16 *)((u8 *)arg0 + 4);
    }
}
/* mkdraft:func_86005A00 end */

/* mkdraft:func_86005B3C begin */
extern s32 func_8003F210(void *, s32);

extern s32 D_8600E0DC;
extern f64 D_8600E100;



void func_86005B3C(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3, s32 arg4) {
    u8 *base;
    u8 *node;

    if (D_8600E0DC != 0) {
        base = (u8 *) ((u32) arg0 + arg1 * 0x5A0 + arg2 * 0x168);
        node = base + 0x81D0;
        ((f32 *)(base + 0x8000))[0x7D] = (f32) *(f64 *)(arg3 + 0);
        ((f32 *)(base + 0x8000))[0x7E] = (f32) *(f64 *)(arg3 + 8);
        ((f32 *)(base + 0x8000))[0x7F] = (f32) *(f64 *)(arg3 + 0x10);
        func_8003F210(node, 0);
        node[1] |= 1;
        ((f32 *)(arg0 + arg1 * 16 + arg2 * 4 + 0x8000))[0xBB4] = (f32) D_8600E100;
        if (arg4 != 0) {
            ((f32 *)(base + 0x8000))[0x61D] = (f32) *(f64 *)(arg3 + 0);
            ((f32 *)(base + 0x8000))[0x61E] = (f32) *(f64 *)(arg3 + 8);
            ((f32 *)(base + 0x8000))[0x61F] = (f32) *(f64 *)(arg3 + 0x10);
            node = base + 0x9850;
            func_8003F210(node, 0);
            node[1] |= 1;
            ((f32 *)(arg0 + arg1 * 16 + arg2 * 4 + 0x8000))[0xBC4] = (f32) D_8600E100;
        }
    }
}
/* mkdraft:func_86005B3C end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/47/fragment47_24AE60/func_86005CB4.s")

s32 func_860062E0(s32 arg0, u16 arg1) {
    if (D_800CE060[0].buttonsPressed & arg1) {
        return 1;
    }
    return 0;
}
void func_860062E0_padding(void) {}

extern void func_86001AFC(s32);
void func_86006318(s32 arg0) {
    s32 var_s0;
    s32 var_s1;

    var_s0 = 0;
    var_s1 = arg0 + 0x75C8;
    do {
        func_86001AFC(var_s1);
        var_s0 += 0x2D8;
        var_s1 += 0x2D8;
    } while (var_s0 != 0xB60);
}

extern void *func_87C007B0(f32 *, void *);
extern void func_87C03B60(void *, void *, void *);
extern void func_800278C0(u16, u8, void *, f32);
void func_86006364(s32 arg0) {
    s32 i;
    u8 *obj;
    f32 pos[3];
    void *data;

    data = *(void **)(*(u8 **)((u8 *)arg0 + 0x7590) + 0xC);
    func_87C037C0((u8 *)arg0 + 0x8150, data);
    for (i = 0; i < 4; i++) {
        if (*(s32 *)((u8 *)arg0 + i * 0x2D8 + 0x775C) != 0) {
            obj = (u8 *)arg0 + i * 0x1998 + 0x1890;
            func_87C03B60((u8 *)arg0 + 0x8150, func_87C007B0(pos, (u8 *)arg0 + i * 0x2D8 + 0x7760), obj);
            func_800278C0(0x4401, i, obj, 1.25f);
        }
    }
}

extern s32 func_87F08208(void *);
extern void func_800226C0(s32);
extern s32 StageContext_GetFadeMode(void);
extern void func_860057D0(s32, f64);
extern void func_86006318(s32 arg0);
extern void func_86006364(s32);
void func_86006448(s32 arg0) {
    typedef struct { unsigned int enabled : 1; unsigned int rest : 7; } Flags;
    s32 i;

    func_86006318(arg0);
    func_86006364(arg0);
    if (StageContext_GetFadeMode() == 0) {
        switch (func_87F08208((void *)(arg0 + 0x7584))) {
            case 1:
                func_86007648(arg0, 1);
                break;
            case 2:
                ((Flags *)(arg0 + 0x75C0))->enabled = 1;
                func_800226C0(3);
                break;
        }
    }
    for (i = 0; i < *(s32 *)D_8600DE30; i++) {
        func_860057D0(arg0, *(f64 *)(arg0 + 0x6890) / *(s32 *)D_8600DE30);
    }
}

void func_86006538(s32 arg0) {
    s32 count;
    s32 i;

    func_86006318(arg0);
    func_86006364(arg0);
    if (StageContext_GetFadeMode() == 1) {
        func_86007648(arg0, 2);
    }
    count = *(s32 *)D_8600DE30;
    i = 0;
    if (count > 0) {
        do {
            func_860057D0(arg0, *(f64 *)((u8 *)arg0 + 0x6890) / (f64)count);
            count = *(s32 *)D_8600DE30;
            i++;
        } while (i < count);
    }
}

extern s32 func_87F01A40(s32);
s32 func_860065E8(s32 arg0) {
    typedef struct { u8 b7 : 1; u8 b6 : 1; u8 b5 : 1; u8 b4 : 1; u8 rest : 4; } StateFlags;
    switch (func_87F01A40(arg0)) {
        case 3:
            ((StateFlags *)((u8 *)arg0 + 0x75C0))->b5 = 1;
            ((StateFlags *)((u8 *)arg0 + 0x75C0))->b7 = 1;
            ((StateFlags *)((u8 *)arg0 + 0x75C0))->b4 = 1;
            return 1;
        case 4:
            ((StateFlags *)((u8 *)arg0 + 0x75C0))->b5 = 0;
            ((StateFlags *)((u8 *)arg0 + 0x75C0))->b7 = 1;
            ((StateFlags *)((u8 *)arg0 + 0x75C0))->b4 = 1;
            return 1;
    }
    //!bug: no return value when the result is neither 3 nor 4
}

extern void func_86005CB4(s32, f64, s32);
extern s32 func_87F006AC(void);
extern void func_87F006BC(void);
extern s32 func_87F00930(void);
extern void func_800279C4(s32);
void func_8600666C(s32 state) {
    s32 count;
    s32 i;

    if ((func_860065E8(state) == 0) && (func_87F00930() == 0)) {
        func_87F006BC();
        count = *(s32 *)D_8600DE30;
        i = 0;
        if (count > 0) {
            do {
                func_86005CB4(state, *(f64 *)((u8 *)state + 0x6890) / (f64)count, 1);
                count = *(s32 *)D_8600DE30;
                i++;
            } while (i < count);
        }
        switch (func_87F006AC()) {
            case 1:
                func_800279C4(12032);
                break;
            case 2:
                func_800279C4(12033);
                break;
            case 3:
                func_86007648(state, 3);
                break;
            case 0:
            case 4:
            case 5:
            case 6:
                break;
        }
    }
}

extern void func_860076EC(s32);
extern s32 func_860065E8(s32);
s32 func_86005434(s32 arg0);
extern void func_80028118(s32);
void func_86006774(s32 arg0) {
    s32 count;
    s32 i;
    func_860076EC(arg0);
    if ((func_860065E8(arg0) == 0) && (func_87F00930() == 0)) {
        func_87F006BC();
        *(f64 *)(arg0 + 0x6888) += *(f64 *)(arg0 + 0x6890);
        for (i = 0; i < (count = *(s32 *)D_8600DE30); i++) {
            func_86005CB4(arg0, *(f64 *)(arg0 + 0x6890) / (f64)count, 1);
        }
        func_86005434(arg0);
        if ((f64)*(s32 *)(D_8600DE30 + 0x20C) - *(f64 *)(arg0 + 0x6888) < 30.0) {
            func_80028118(4);
            *(u8 *)(arg0 + 0x75C0) = (*(u8 *)(arg0 + 0x75C0) & 0xFF) | 4;
        }
    }
}

extern void func_87F0A098(void *, s32, s32, s32, s32, s32, s32);
void func_8600688C(u8 *arg0) {
    s32 flags[4];
    s32 all;
    s32 i;

    all = 1;
    for (i = 0; i < 4; i++) {
        flags[i] = (*(s32 *)(arg0 + i * 0x1998 + 0x1828) == 6) || (*(s32 *)(arg0 + i * 0x1998 + 0x1828) == 5);
        all = all && flags[i];
    }
    if (all) {
        func_87F0A098(arg0 + 0x751C, *(s32 *)(arg0 + 0x7580), 1, 0, 0, 0, 0);
    } else {
        func_87F0A098(arg0 + 0x751C, *(s32 *)(arg0 + 0x7580), 1, flags[0], flags[1], flags[2], flags[3]);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/47/fragment47_24AE60/func_86006964.s")

extern s32 func_87F02104(void);
void func_86006C30(s32 arg0) {
    typedef struct { u8 b7 : 1; u8 b6 : 1; u8 b5 : 1; u8 b4 : 1; u8 rest : 4; } StateFlags;
    s32 count;
    s32 i;

    count = *(s32 *)D_8600DE30;
    i = 0;
    if (count > 0) {
        do {
            func_86005CB4(arg0, *(f64 *)((u8 *)arg0 + 0x6890) / (f64)count, 0);
            count = *(s32 *)D_8600DE30;
            i++;
        } while (i < count);
    }
    switch (func_87F02104()) {
        case 1:
            func_86007648(arg0, 6);
            break;
        case 2:
            ((StateFlags *)((u8 *)arg0 + 0x75C0))->b7 = 1;
            ((StateFlags *)((u8 *)arg0 + 0x75C0))->b5 = 1;
            break;
        case 3:
            ((StateFlags *)((u8 *)arg0 + 0x75C0))->b7 = 1;
            ((StateFlags *)((u8 *)arg0 + 0x75C0))->b5 = 0;
            break;
    }
}

extern void StageFade_StartFromOpaque(s32);
s32 StageContext_GetFadeMode();

void func_86006D24(s32 arg0) {
    if (StageContext_GetFadeMode() == 1) {
        StageFade_StartFromOpaque(0xA);
        func_86007648(arg0, 0);
    }
}

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/47/fragment47_24AE60/func_86006D64.s")

extern Gfx *D_800D0510;
extern u8 D_80094E38[];
extern u8 D_80094F50[];
extern s32 func_8004C990(s32, s32);
extern void func_8004D19C(s32, s32, s32, s32, s32);
extern void func_8003C6B8(s32);
extern void func_8600AB6C(s32, s32, void *);
extern void func_8600AE6C(u8 *);
extern f32 func_87C039D4(void *, void *, f32 *);
extern void func_86000C6C(u8 *, s32, void *, f32, f32);
extern void func_86000CCC(u8 *);
typedef struct { f32 x, y, z; } Vec3;
extern Vec3 D_8600D2C0;
extern f64 D_8600DF20;
extern s32 D_8600E03C;
extern void func_8600B474(s32, s32);
extern void func_87F07FE8(void *);
extern void func_87F01D44(void);
extern void func_87F0A5BC(void *);
extern void func_87F022F0(void);
extern void func_87F0C88C(void *);



void func_86006F20(u8 *arg0) {
    s32 i;
    u8 *p;
    Gfx *g;
    f32 alpha;
    s32 delta;
    Vec3 vec;
    f32 pos[4];


    g = D_800D0510++;
    gSPDisplayList(g, D_80094E38);
    g = D_800D0510++;
    gDPSetRenderMode(g, 0, 0x0F0A7008);
    func_8004D19C(0, 0, func_8004C990(0xDF, 0), 0, 0);
    g = D_800D0510++;
    g->words.w1 = (u32)D_80094F50;
    g->words.w0 = 0xDE000000;
    func_860049B8((Func860049B8Context *)arg0, *(f64 *)(arg0 + 0x6890));
    if (*(s32 *)(arg0 + 0x7518) >= 2) {
        if (func_87F00930() == 0) {
            GeoRender_AdvanceFrameCounter();
        }
        func_8003C6B8(*(s32 *)(arg0 + 0x6660));
        i = 0;
        if ((*(u8 *)(*(u8 **)(arg0 + 0x7580) + 0x2180) == 4) == 0) {
            for (i = 0; i < 4; i++) {
                func_8600AB6C(i, (*(u8 *)(*(u8 **)(arg0 + 0x7580) + 0x2182) & (1 << i)) == 0, arg0 + 0x74F0);
            }
            for (i = 0; i < 4; i++) {
                func_8600AE6C(arg0 + i * 0x1998);
            }
        }
        if (func_87F00930() == 0) {
            for (i = 0; i < 4; i++) {
                alpha = -1.0f;
                vec = D_8600D2C0;
                if ((*(s32 *)(arg0 + i * 0x1998 + 0x1828) == 4U && *(s32 *)(arg0 + i * 0x1998 + 0x17A4) == 0) ||
                    (*(s32 *)(arg0 + i * 0x1998 + 0x1828) == 3 && *(f64 *)(arg0 + i * 0x1998 + 0x17F0) > 0.0)) {
                    alpha = func_87C039D4(arg0 + 0x8150, func_87C007B0((f32 *)&pos, arg0 + i * 0x1998), (f32 *)&vec);
                }
                func_86000C6C(arg0 + 0x189C + i * 0x1998, *(s32 *)(arg0 + i * 0x1998 + 0x1818), &vec, alpha, (f32)(*(f64 *)(arg0 + i * 0x1998 + 0x17F0) / D_8600DF20));
            }
        }
        for (i = 0; i < 4; i++) {
            func_86000CCC(arg0 + 0x189C + i * 0x1998);
        }
        if ((*(u8 *)(*(u8 **)(arg0 + 0x7580) + 0x2180) == 4) == 0) {
            delta = (s32)((f64)D_8600E03C - *(f64 *)(arg0 + 0x6888));
            if (delta != ((struct { u8 pad[0xAF5C]; s32 x; } *)arg0)->x) {
                if (delta != 0) {
                    if (delta == 1 || delta == 2 || delta == 3) {
                        func_800279C4(0xCF00);
                    }
                } else {
                    func_800279C4(0xCF06);
                }
                ((struct { u8 pad[0xAF5C]; s32 x; } *)arg0)->x = delta;
            }
            func_8600B474(delta, func_87F00930());
        }
    }
    switch (*(s32 *)(arg0 + 0x7518)) {
        case 0:
        case 1:
            func_87F07FE8(arg0 + 0x7584);
            break;
        case 2:
            if (func_87F00930() != 0) {
                func_87F01D44();
            }
            break;
        case 3:
            if (func_87F00930() != 0) {
                func_87F01D44();
            }
            break;
        case 4:
            {
                typedef struct {
                    u8 pad[0x75C0];
                    u32 a : 4;
                    u32 b : 1;
                    u32 c : 27;
                } S;
                if (((S *)arg0)->b) {
                    func_87F0A5BC(arg0 + 0x751C);
                }
            }
            break;
        case 5:
        case 6:
            func_87F022F0();
            break;
    }
    func_87F0C88C(arg0 + 0xAF50);
}

extern void func_86001B1C(s32);
void func_86007300(s32 arg0) {
    s32 var_s0;
    s32 var_s1;

    var_s0 = 0;
    var_s1 = arg0 + 0x75C8;
    do {
        func_86001B1C(var_s1);
        var_s0 += 0x2D8;
        var_s1 += 0x2D8;
    } while (var_s0 != 0xB60);
}

typedef struct Func8600734CRecord {
    u8 pad000[0x198];
    f64 value198;
    u8 pad1A0[0x118];
    f64 value2B8;
    u8 pad2C0[0x10];
    s32 value2D0;
    u8 pad2D4[4];
} Func8600734CRecord;
typedef struct Func8600734CContext {
    u8 pad0000[0x75C8];
    Func8600734CRecord records[4];
} Func8600734CContext;
extern void func_86001BFC();
extern void StageContext_SetClearColor(s32);
extern void StageFade_StartFromTransparent(s32);
extern void Audio_PlayDefaultSound(s32);
void func_8600734C(s32 arg0) {
    s32 i;
    Func8600734CRecord *selected;

    selected = &((Func8600734CContext *)arg0)->records[((s32)MathUtil_Random16() % 12) / 3];
    StageContext_SetClearColor(0xFFFF);
    StageFade_StartFromTransparent(20);
    for (i = 0; i < 4; i++) {
        func_86001BFC(&((Func8600734CContext *)arg0)->records[i]);
    }
    selected->value2D0 = selected->value2B8 < selected->value198;
    func_800225C4(40);
    Audio_PlayDefaultSound(0xCF0B);
}

/* mkdraft:func_86007428 begin */
extern void func_87F00688();
void func_86004BD4(u8 *arg0);
extern void func_86004968();
extern void func_860021C4(s32, s32, f32, void *, s32);

// Four stage slots of stride 0x1998; D_8600DE30+0x214 is the first slot that
// func_86003EFC(ptr, 7) still has to run on, and 0x6660 is 4 slots.



void func_86007428(s32 arg0) {
    s32 i;
    s32 offset;
    s32 ptr;
    void *callback;
    void *node;
    *(f64 *)(arg0 + 0x6888) = 0.0;
    *(u8 *)(arg0 + 0x75C0) &= 0xFF7F;
    *(f64 *)(arg0 + 0x6898) = 0.0;
    StageContext_SetClearColor(0xFFFF);
    StageFade_StartFromOpaque(0x14);
    func_87F00688();
    func_86004BD4(arg0);
    func_86004968(arg0);
    offset = 0;
    for (i = 0; i < 4; i++) {
        node = *(void **)(arg0 + 0x7580);
        callback = (*(u8 *)((u8 *)node + 0x2182) & (1 << i) &&
                    (*(u8 *)((u8 *)node + 0x2180) == 4) == 0) ? NULL : &func_8600062C;
        func_860021C4(arg0 + offset, i, (f32)*(f64 *)(D_8600DE30 + 0xF8), callback, arg0);
        offset += 0x1998;
    }
    i = *(s32 *)(D_8600DE30 + 0x214);
    if (i < 4) {
        offset = i * 0x1998;
        ptr = arg0 + offset;
        do {
            func_86003EFC(ptr, 7);
            offset += 0x1998;
            ptr += 0x1998;
        } while (offset != 0x6660);
    }
    *(s8 *)(arg0 + 0x75C1) = MathUtil_Random16() % 4;
    *(s32 *)(arg0 + 0xAF5C) = 0x15F90;
}
/* mkdraft:func_86007428 end */

extern void func_80021ED8(s32);
void func_860075A8(void *arg0) {
    func_80021ED8(0x21);
    func_86004968(arg0);
    (*(u8 *)((u8 *)(arg0) + (0x75C0))) = (u8) ((*(u8 *)((u8 *)(arg0) + (0x75C0))) & 0xFFFB);
}

extern void func_87F02328();
void func_860075E4(void *arg0) {
    (*(u8 *)((u8 *)(arg0) + (0x75C0))) = (u8) ((*(u8 *)((u8 *)(arg0) + (0x75C0))) & 0xFFF7);
    func_86004968(arg0);
    func_87F02328();
}

extern void StageContext_SetClearColor(s32); extern void StageFade_StartFromTransparent(s32);
void func_86007614(void *arg0) { StageContext_SetClearColor(1); StageFade_StartFromTransparent(0xA); }

void func_86007640(u8 *arg0) {}

extern void func_86007300(s32);
extern void func_8600734C(s32);
extern void func_86007428(s32);

void func_86007648(s32 arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x7518) = arg1;
    switch (arg1) {
        case 0:
            func_86007300(arg0);
            break;
        case 1:
            func_8600734C(arg0);
            break;
        case 2:
            func_86007428(arg0);
            break;
        case 3:
            func_860075A8((void *)arg0);
            break;
        case 4:
            func_860075E4((void *)arg0);
            break;
        case 6:
            func_86007614((void *)arg0);
            break;
        case 5:
            func_86007640((u8 *)arg0);
            break;
    }
}

/* mkdraft:func_860076EC begin */
extern u8 D_8600D2CC[4][4][16];
extern s32 D_8600D800[];

// D_8600D2CC holds 16-byte records, four per row. The double subscript scales
// the row by 0x40 and the record by 0x10 and adds each to the table address
// separately, which keeps the table address in rs of the first add; a flat
// byte table produces the same sums with the operands commuted. The
// 0x8600D2CC..0x8600D3CC extent (0x100 bytes) is 4 * 4 * 16.
//@{asm/us/data/fragments/47/fragment47_data.data.s}


void func_860076EC(s32 arg0) {
    u8 *ptr;
    s32 n;
    s32 i;
    u8 *list[4];
    s32 j;
    u8 *t;

    n = 0;
    for (j = 0; j < 4; j++) {
        ptr = (u8 *)arg0;
        ptr += ((*(s8 *)((u8 *)arg0 + 0x75C1) + j) % 4) * 0x1998;
        if (*(s32 *)(ptr + 0x1824) != 0) { list[n++] = ptr; }
    }

    for (i = 0; i < n - 1; i++) {
        for (j = n - 1; j > i; j--) {
            if (*(s32 *)(list[j - 1] + 0x1814) < *(s32 *)(list[j] + 0x1814)) {
                t = list[j];
                list[j] = list[j - 1];
                list[j - 1] = t;
            }
        }
    }
    for (j = 0; j < n; j++) {
        *(void **)(list[j] + 0x1894) = (void *)&D_8600D2CC[*(s8 *)(*(u8 **)((u8 *)arg0 + 0x7580) + 0x2181)][*(s32 *)((u8 *)D_8600D800 + (n - 1) * 16 + j * 4)];
    }
}
/* mkdraft:func_860076EC end */
#endif
