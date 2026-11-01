#include "global.h"


#ifdef VERSION_US
// 0x34-stride entry tables shared with the matched sibling func_8AF079FC
// (unk_04 is the entry payload read via table[-1] after the materialized
// decrement; the three tables are the switch's arg0 selections).
struct unk_D_8AF27E30 {
    u8 pad00[0x4];
    s32 unk_04;
    u8 pad08[0xC];
    s32 unk_14;
    u8 pad18[0x1C];
};
extern struct unk_D_8AF27E30 D_8AF27E30[];
extern struct unk_D_8AF27E30 D_8AF28274[];
extern struct unk_D_8AF27E30 D_8AF284E4[];
extern s32 D_8AF2656C;
extern s32 D_8AF26564;
extern s32 D_8AF26568;

/* mkdraft:func_8AF07960 begin */
void func_8AF07960(s16 arg0, s16 arg1) {
    struct unk_D_8AF27E30 *sp4;
    struct unk_D_8AF27E30 *table;

    switch (arg0) {
    default:
        table = sp4;
        break;
    case 0:
        table = D_8AF27E30;
        break;
    case 1:
        table = D_8AF28274;
        break;
    case 2:
        table = D_8AF284E4;
        break;
    }
    table += arg1;
    D_8AF26568 = table[-1].unk_04;
    table--;
    D_8AF2656C = table->unk_14;
    D_8AF26564 = 0;
}
/* mkdraft:func_8AF07960 end */

/* 0x44-byte entries; D_8AF27BCC and D_8AF27D20 continue the same array
 * (offsets 7*0x44 and 12*0x44 past D_8AF279F0). See func_8AF220E8, which
 * selects the same three tables and records their entry counts (7/5/4).
 * //@src/fragments/44/fragment44_20F140.c */
struct unk_D_8AF279F0 {
    u8 pad00[0x10];
    s32 unk_10;
    s32 unk_14;
    u8 pad1C[0x2C];
};
extern struct unk_D_8AF279F0 D_8AF279F0[];
extern struct unk_D_8AF279F0 D_8AF27BCC[];
extern struct unk_D_8AF279F0 D_8AF27D20[];
extern s32 D_8AF26564;
extern s32 D_8AF26568;
extern s32 D_8AF2656C;

void func_8AF079FC(s16 arg0, s16 arg1) {
    /* Never assigned on any path: when arg0 matches no case below, the switch
     * copies this uninitialized stack slot (the lw from 4(sp)). */
    struct unk_D_8AF279F0 *sp4;
    struct unk_D_8AF279F0 *table;

    switch (arg0) {
    default:
        table = sp4;
        break;
    case 0:
        table = D_8AF279F0;
        break;
    case 1:
        table = D_8AF27BCC;
        break;
    case 2:
        table = D_8AF27D20;
        break;
    }
    table += arg1;
    D_8AF26568 = table->unk_10;
    D_8AF2656C = table->unk_14;
    D_8AF26564 = 1;
}
extern s32 D_8AF26564;
extern s32 D_8AF26568;
extern s32 D_8AF2656C;
void func_8AF07A90(void) {
    D_8AF26568 = 0;
    D_8AF2656C = 0;
    D_8AF26564 = 0;
}

/* mkdraft:func_8AF07AAC begin */
extern void *D_8AF26560;
extern s32 D_8AF2656C;
extern s32 D_8AF26564;
extern s32 D_8AF26568;
extern s32 D_8AF26570;
extern s32 D_8AF2BDCC;
extern s32 D_8AF2BE84;
extern u8 *D_8AF2BDD8;
extern u16 D_8AF2C680;
extern void func_8AF05C10(void *);
extern s32 func_8AF05E94(void *);
extern void func_8AF05EE0(void *);
extern void func_8004C8C0(s32);
extern s32 func_8004C990(s32, s32);

// Copies the pending table selection into D_8AF26570 and reinitializes the
// 0xAB resource, then commits the selection to the current object. When
// D_8AF26564 is set, the selection lives in that object's 0x28 entry and is
// committed only if func_8AF05E94 returns a value other than -1 and other than
// the entry's 0x4B4 field.



void func_8AF07AAC(s32 arg0)
{
  u8 *object;
  s16 pad; // FAKE: unused; home slot 0x18(sp) for entry instead of 0x1c(sp); diff score 8 without it.
  u8 *entry;
  u8 *other;
  s32 temp_v0;
  D_8AF26570 = D_8AF26568;
  D_8AF2BE84 = arg0;
  func_8AF05C10(D_8AF26560);
  *((s32 *) D_8AF26560) = 4;
  func_8004C8C0(0xAB);
  D_8AF2BDCC = func_8004C990(0xAB, 2);
  if (D_8AF26564 != 0)
  {
    object = D_8AF26560;
    entry = object + 0x28;
    *((s32 *) (object + 0x4E0)) = D_8AF26568;
    *((s32 *) (object + 0x4E8)) = D_8AF2656C;
    temp_v0 = func_8AF05E94(entry);
    if ((temp_v0 != (-1)) && (temp_v0 != (*((s32 *) (entry + 0x4B4)))))
    {
      func_8AF05EE0(object);
    }
  }
  else
    if (D_8AF26568 != 0)
  {
    other = D_8AF26560;
    *((s32 *) (other + 0x4E0)) = D_8AF26568;
    *((s32 *) (other + 0x4E8)) = D_8AF2656C;
    // The 0x514 store reads 0x510 back; uopt forwards the first store's value,
    // so one lh of the 0x18 field feeds both sw instructions.
    *((s32 *) (other + 0x510)) = *((s16 *) (((u8 *) (*((void **) (D_8AF2BDD8 + 8)))) + 0x18));
    *((s32 *) (other + 0x514)) = *((s32 *) (other + 0x510));
  }
  D_8AF2C680 = 0;
}
/* mkdraft:func_8AF07AAC end */

extern void *D_8AF26560;
extern s32 D_8AF2BA68;
extern s16 D_8AF2BA6C;
extern u8 *D_8AF2BDD8;
extern u16 D_8AF2C680;
extern void func_8AC007FC(void);
extern s32 func_8AF065DC(void *);
// Returns the next value for the state D_8AF2BA6C: func_8AF00B74 calls this from
// its switch on D_8AF2BA6C, and func_8AF00D90 starts a transition when the
// returned value differs from D_8AF2BA6C.
//@src/fragments/44/fragment44_1EE290.c
s32 func_8AF07BC0(void) {
    s16 next_state = D_8AF2BA6C;
    s32 status;
    s16 *target;

    if (D_8AF2C680 >= 5) {
        D_8AF2C680 = 5;
        func_8AC007FC();
    }
    status = func_8AF065DC(D_8AF26560);
    if (status == -1) {
        D_8AF26568 = 0;
        next_state = 36;
    } else if (status == -2) {
        next_state = 31;
    } else if (status == -3) {
        target = *(s16 **)(D_8AF2BDD8 + 8);
        *target = 11;
        D_8AF2BA68 = 3;
    }
    D_8AF2C680++;
    return next_state;
}

extern void *D_8AF26560;
extern void func_8AF06EA4(void *);
void func_8AF07C84(void) {
    func_8AF06EA4(D_8AF26560);
}
#endif
