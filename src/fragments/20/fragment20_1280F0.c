#include "global.h"


#ifdef VERSION_US
typedef struct {
    u8 unk_00[0x74];
    s8 sides[4];
    s8 members[8];
    s16 pairs[2][2];
    s16 selection;
} Func826002BCState;
extern Func826002BCState *D_82615324;
extern s32 func_800356CC(s32 arg0);
extern s32 BinArchive_Open(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void _bzero(void *arg0, s32 arg1);
extern void *func_80004B4C(s32 arg0, s32 arg1);
extern s32 func_8006AFB4(s32 arg0);
extern void func_80054CC4(u8 *arg0, s32 arg1);
extern s32 TrailEffect_Initialize(void);



void func_82600020(u8 *arg0) {
    s32 archive;
    u8 *desc;
    s32 flag;
    s32 i;

    archive = BinArchive_Open(func_800356CC(0xB), 0, 1, 0);
    flag = 0;
    _bzero(arg0, 0x920);
    {
        s16 n = *(s16 *)((u8 *)D_82615324 + 4);
        if (n >= 0) {
            *(void **)(arg0 + 0xC) = func_80004B4C(archive, n);
        } else {
            *(u32 *)(arg0 + 0xC) = 0;
        }
    }
    *(u32 *)(arg0 + 0xAC) = 0;
    if ((*(u16 *)((u8 *)D_82615324 + 8) & 0xFF00) == 0x700 &&
        *(u8 *)((u8 *)D_82615324 + 0x7C) == 3) {
        flag = 1;
    }
    if (flag != 0) {
        *(void **)(arg0 + 0xAC) = func_80004B4C(archive, 5);
    }
    *(void **)arg0 = D_82615324;
    *(s16 *)(arg0 + 0x16) = *(s16 *)((u8 *)D_82615324 + 0x88);
    if (*(void **)(arg0 + 0xC) != 0) {
        if (func_8006AFB4(*(s16 *)((u8 *)D_82615324 + 4)) == 1) {
            *(s16 *)(arg0 + 0x14) = (*(u8 **)(arg0 + 0xC))[0] / 2;
            for (i = 0; i < *(s16 *)(arg0 + 0x14); i++) {
                *(s16 *)(arg0 + 0x18 + i * 2) = i * 2 + 1;
            }
        } else {
            *(s16 *)(arg0 + 0x14) = (*(u8 **)(arg0 + 0xC))[0];
            for (i = 0; i < *(s16 *)(arg0 + 0x14); i++) {
                *(s16 *)(arg0 + 0x18 + i * 2) = i;
            }
        }
    }
    *(u32 *)(arg0 + 0x9C) = 0;
    for (i = 0, desc = arg0 + 0xB0; i < 2; i++) {
        s32 off;
        s32 j;
        if (*(s8 *)((u8 *)D_82615324 + 6) != 0) {
            off = i * 2;
            if (*(s8 *)((u8 *)D_82615324 + off + 1) != -2) {
                *(s16 *)desc = 2;
            } else {
                *(s16 *)desc = 1;
            }
        } else {
            off = i;
            *(s16 *)desc = 1;
        }
        j = 0;
        while (j < 2) {
            *(s8 *)(desc + 2 + j) = -2;
            j++;
        }
        for (j = 0; j < *(s16 *)desc; j++) {
            *(s8 *)(desc + 2 + j) = *(s8 *)((u8 *)D_82615324 + off + j);
        }
        if (*(s16 *)desc == 1) {
            *(u8 *)(desc + 6) =
                (*(u8 *)((u8 *)D_82615324 + 0x7E) & (1 << off)) != 0;
        }
        desc += 0x428;
    }
    func_80054CC4(arg0 + 0x900, 0);
    TrailEffect_Initialize();
}

typedef struct {
    s16 count;
    s8 owners[2];
    u8 unk_04[2];
    u8 flag;
    u8 unk_07[0x421];
} Func826002BCDescriptor;
typedef struct {
    u8 unk_00[0x58];
    s16 defaults[22][2];
    Func826002BCDescriptor descs[2];
} Func826002BCContext;
extern Func826002BCState *D_82615324;
void func_826002BC(Func826002BCContext *arg0) {
    s16 *fallback;
    s32 i;
    s32 a;
    s32 b;
    s16 *out;
    Func826002BCDescriptor *desc;

    fallback = arg0->defaults[D_82615324->selection];
    for (i = 0; i < 2; i++) {
        a = D_82615324->sides[i];
        b = D_82615324->members[i];
        out = D_82615324->pairs[i];
        desc = &arg0->descs[i];
        if (a == -1) {
            if (desc->owners[0] >= 0) {
                if (desc->count == 1) {
                    out[0] = 0x40;
                    if (desc->flag != 0) {
                        out[1] = 0;
                    } else {
                        out[1] = 1;
                    }
                } else {
                    out[0] = 0x41;
                    out[1] = 0;
                }
            } else {
                out[0] = fallback[0];
                out[1] = fallback[1];
            }
        } else {
            out[0] = a;
            out[1] = b;
        }
    }
}

/* mkdraft:func_826003BC begin */
extern s32 main_pool_push_state(s32);
extern s32 main_pool_pop_state(s32);
extern void Gfx_InitDisplayListBuffers(s32, s32);
extern void Gfx_FreeDisplayListBuffers(void);
extern s32 func_800082E0(s32, s32, s32, s32, s32, s32);
extern s32 func_8004C09C(s32);
extern s32 func_8004C4B0(s32);
extern u8 *func_80047588(s32, s32);
extern u8 *Asset_LoadToSegment(s32, u8 *, u8 *, s32);
extern u8 D_1000000[], D_446E30[], D_447D00[];
extern void func_80008514(s32);
extern void func_80008574(void);
extern void func_80047610(void);
extern void func_8004C398(void);
extern void func_80051D64(s32, s32);
extern s32 func_80054E48(s32);
extern s32 func_80055948(s32);
extern s32 func_8006D268(u16);
extern void func_826005F0(void *);
extern void func_826009A0(void);
extern void func_826020C0(void *);
extern void func_82602A0C(void);
extern void RecordSelection_InitializeDisplayContext(u8 *);
extern void RecordSelection_RunPhaseLoop(void);
extern u8 D_82615A80[];

// Fragment entry: push the 'EYEC' pool state, run the 'mprc' phase loop until it
// reports phase 3, then tear the display down and return the selection result.


s32 func_826003BC(s32 arg0, void *arg1) {
    s32 configuration;
    s32 mode;
    s32 state;

    state = arg0;
    main_pool_push_state(0x45594543);
    D_82615324 = arg1;
    mode = *(u16 *)((u8 *)D_82615324 + 8) & 0xFF00;
    if (mode != 0x200 && mode != 0x400 && func_8006D268(0x101) != 0 && arg0 == 1) {
        state = 0;
    }
    Gfx_InitDisplayListBuffers(0x10000, 0);
    configuration = func_800082E0(1, 0, 2, 0, 2, 1);
    func_8004C09C(0x43);
    func_8004C4B0(0x29);
    func_8004C4B0(0x48);
    func_8004C4B0(0x2A);
    func_8004C4B0(0x12);
    func_8004C4B0(0x46);
    func_8004C4B0(0x47);
    func_80047588(0xC, 0);
    Asset_LoadToSegment(((u32)D_1000000 & 0x0F000000) >> 24, D_446E30, D_447D00, 0);
    func_80055948(3);
    func_82600020(&D_82615A80);
    func_80008514(configuration);
    do {
        main_pool_push_state(0x6D707263);
        switch (state) {
        case 0:
            state = 1;
            if (*(s32 *)(D_82615A80 + 0xC) != 0) {
                func_826005F0(&D_82615A80);
                func_826009A0();
            }
            break;
        case 1:
            state = 3;
            func_826020C0(&D_82615A80);
            func_82602A0C();
            break;
        case 2:
            state = 3;
            RecordSelection_InitializeDisplayContext(&D_82615A80);
            RecordSelection_RunPhaseLoop();
            break;
        }
        main_pool_pop_state(0x6D707263);
    } while (state != 3);
    func_826002BC(&D_82615A80);
    func_80008574();
    func_80051D64(0x14, 0);
    func_80054E48(3);
    func_80047610();
    func_8004C398();
    Gfx_FreeDisplayListBuffers();
    main_pool_pop_state(0x45594543);
    return *(s32 *)(D_82615A80 + 0x9C);
}
/* mkdraft:func_826003BC end */
#endif
