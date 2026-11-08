#include "global.h"


#ifdef VERSION_US
extern void *func_8004C874(s32, s32);
extern void *func_8004C8A0(void *, s32, s32, s32);
extern void func_8004C594(s32, s32);
extern s32 func_80049148(s32 font, s32 flags, const char *format, ...);
extern s32 func_800472E0(u8 *);

typedef struct {
    // Second argument to the string lookups func_8004C874/func_8004C8A0.
    u16 unk_00;
    u8 pad02[2];
    s16 value;
    u8 pad06[2];
} Frag14Entry;

// Text box layout; func_813110F0 sizes and positions the box from its entries' strings.
typedef struct {
    u8 pad00[8];
    s16 anchor_x;
    s16 anchor_y;
    // -1 = box starts at the anchor, 0 = centered on it, 1 = ends at it.
    s16 align_x;
    s16 align_y;
    s8 unk_10;
    s8 unk_11;
    s8 unk_12;
    s8 unk_13;
    s8 font;
    s8 unk_15;
    s8 line_height;
    s8 unk_17;
    s16 fallback;
    u8 pad1A[2];
    u16 entry_count;
    u16 unk_1E;
    Frag14Entry *entries;
} Frag14Record;

typedef struct {
    Frag14Record *owner;
    f32 unk_04;
    f32 unk_08;
    s32 unk_0C;
    s16 box_x;
    s16 box_y;
    s16 box_width;
    s16 box_height;
    u8 status;
    s8 index;
    s8 unk_1A;
    u8 pad1B;
    // Set when any two consecutive entries have different values.
    s32 unk_1C;
} Frag14State;

// Binds arg0 to record arg1 and computes the box size from the widest entry string
// (func_80049148) and the total line count (func_800472E0), then places the box by its
// alignment. Returns 0 without changes if arg1 is already bound, otherwise 1.
//@src/47580.c
s32 func_813110F0(Frag14State *arg0, Frag14Record *arg1, s32 arg2) {
    char buf[256];
    s32 i;
    s32 max_width;
    s32 line_count;
    void *str;
    s32 width;

    if (arg1 == arg0->owner) {
        return 0;
    }
    arg0->owner = arg1;
    arg0->unk_1C = 0;
    arg0->unk_0C = arg2;
    line_count = 0;
    max_width = 0;
    for (i = 0; i < arg1->entry_count; i++) {
        if (arg0->unk_0C < 0) {
            str = func_8004C874(arg1->unk_1E, arg0->owner->entries[i].unk_00);
        } else {
            func_8004C594(3, arg0->unk_0C);
            str = func_8004C8A0(buf, sizeof(buf), arg1->unk_1E, arg0->owner->entries[i].unk_00);
        }
        width = func_80049148(arg1->font, arg1->unk_17 + 2, str);
        if (max_width < width) {
            max_width = width;
        }
        line_count += func_800472E0(str);
        if (i > 0) {
            if (arg1->entries[i].value != arg1->entries[i - 1].value) {
                arg0->unk_1C = 1;
            }
        }
    }
    arg0->box_width = arg1->unk_13 + max_width + arg1->unk_12;
    arg0->box_height =
        (arg1->line_height * line_count) + arg1->unk_15 - arg1->line_height + arg1->unk_10 + arg1->unk_11;
    arg0->box_x = arg1->anchor_x - arg0->box_width / 2;
    switch (arg1->align_x) {
        case 1:
            arg0->box_x = arg1->anchor_x - arg0->box_width;
            break;
        case -1:
            arg0->box_x = arg1->anchor_x;
            break;
        case 0:
            arg0->box_x = arg1->anchor_x - arg0->box_width / 2;
            break;
    }
    // The default vertical position uses anchor_x, not anchor_y; only align_y values -1, 0
    // and 1 overwrite it.
    arg0->box_y = arg1->anchor_x - arg0->box_height / 2;
    switch (arg1->align_y) {
        case 1:
            arg0->box_y = arg1->anchor_y - arg0->box_height;
            break;
        case -1:
            arg0->box_y = arg1->anchor_y;
            break;
        case 0:
            arg0->box_y = arg1->anchor_y - arg0->box_height / 2;
            break;
    }
    return 1;
}


/* mkdraft:func_81311368 begin */
extern f32 (*D_8160BD18)(f32, u8 *);
extern f32 (*D_8160BD1C)(f32);
extern void func_816072FC(void *arg0);



f32 func_81311368(u8 *arg0, s16 *arg1) {
    f32 scale;
    u8 *p;
    f32 h;
    f32 w;
    f32 base_w;
    f32 prod;

    scale = 0.0f;
    p = arg0;
    if ((*(s32 *)arg0 != 0) && (arg0[0x18] != 0)) {
        if (*(f32 *)(arg0 + 4) > 0.0f) {
            if (*(f32 *)(arg0 + 4) < 16) {
                scale = *(f32 *)(arg0 + 4) / 16;
            } else {
                scale = 1.0f;
            }
        }
    }
    D_8160BD18(scale, arg1);
    w = D_8160BD1C(scale);

    h = (f32)*(s16 *)(p + 0x16);
    // FAKE: prod's web starts at this copy so uopt walks it before base_w's; a
    // single `prod = h * w` here gives the product $f12 and h $f2 and the swap
    // cascades through mul.s/sub.s/div.s/trunc.w.s (diff score 1460).
    prod = h;
    // FAKE: block boundary; without it uopt reorders the loads below and the
    // tail shortens by two instructions (diff score 970).
    do {
        base_w = (f32)*(s16 *)(p + 0x14);
    } while (0);
    prod = prod * w;
    arg1[1] = (s16)(s32)((f32)*(s16 *)(p + 0x12) + ((h - prod) / 2));
    // FAKE: empty block; without it the tail shifts and every long-lived
    // temp is recoloured (diff score 765).
    if (!prod) {
    }
    //!bug: the minuend is reloaded from the same address as base_w, so this
    // term is always 0 and arg1[0] receives only the box origin.
    arg1[0] = (s16)(s32)((((f32)*(s16 *)(p + 0x14) - base_w) / 2)
                         + (f32)*(s16 *)(p + 0x10));
    arg1[3] = (s16)(s32)(prod);

    arg1[2] = (s16)(s32)base_w;
    func_816072FC(arg1);
    return scale;
}
/* mkdraft:func_81311368 end */

/* mkdraft:func_813114B8 begin */
extern void func_800495BC(s32, s32, const char *, ...);
extern void func_800495F8(s32, s32, s32, const char *, ...);
extern void func_800496A4(s32, s32);
extern void func_8004972C(s32, s32, s32, s32);

// Frag14Entry with offset 0x06 typed as a mode word. The draw path compares it with 0 and
// passes it to func_800495F8 as its mode argument; func_813110F0 never reads offset 0x06.
typedef struct {
    u16 unk_00;
    u8 pad02[2];
    s16 value;
    s16 unk_06;
} Frag14EntryExt;

// Draws one line of the record's text: fetches (or formats into buf) the string for entry
// arg1, sets the highlight color and font, then emits the line either left-aligned at the box
// edge or centered in it, depending on the entry's mode word.
//@src/47580.c


void func_813114B8(Frag14State *arg0, s16 arg1) {
    // The three consecutive s16 at 0x10 in Frag14State: box[0] = box_x, box[1] = box_y,
    // box[2] = box_width. The retail code keeps this one base pointer and addresses the
    // fields at 0, 2 and 4 off it.
    s16 *box;
    Frag14Record *rec;
    char buf[0x100];
    void *str;

    rec = arg0->owner;
    box = &arg0->box_x;
    if (arg0->unk_0C < 0) {
        str = func_8004C874(rec->unk_1E, arg0->owner->entries[arg1].unk_00);
    } else {
        func_8004C594(3, arg0->unk_0C);
        str = func_8004C8A0(buf, 0x100, rec->unk_1E, arg0->owner->entries[arg1].unk_00);
    }
    // White when the entry is the selected one, opaque black otherwise.
    if (arg0->unk_1C != 0 && arg1 == arg0->index) {
        func_8004972C(0xFF, 0xFF, 0, 0xFF);
    } else {
        func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
    }
    func_800496A4(rec->font, rec->unk_17 + 2);
    if (((Frag14EntryExt *)arg0->owner->entries)[arg1].unk_06 == 0) {
        func_800495BC(box[0] + rec->unk_12,
                      box[1] + rec->unk_10 + rec->line_height * arg1, str);
        return;
    }
    func_800495F8(box[2] / 2 + box[0],
                  box[1] + rec->unk_10 + rec->line_height * arg1,
                  ((Frag14EntryExt *)arg0->owner->entries)[arg1].unk_06, str);
}
/* mkdraft:func_813114B8 end */

extern s32 func_81600DA8(void *, void *);
extern void Fragment11_DrawThickPanelFrame(s32, s32, s32, s32);
extern void func_81608044(s32, s32, s32, s32, f32, s32 *);
extern void func_816073A0(void *);
extern void func_800498C4(void);
extern void func_8004989C(s32);
extern void func_800499EC(void);
extern void func_81608918(s32, s32, f32 *);
extern s32 func_8004C990(s32, s32);
extern s32 func_8004CA24(void *);
extern void func_8004D19C(s32, s32, s32, s32, s32);
extern void func_81607408(void);
extern Gfx *D_800D0510;
extern u8 D_80094E38[];
extern u8 D_80094F50[];
extern u8 D_81312170[];

// Draws the framed panel and its child object for one fragment record. The 0.1f
// cutoff is written as a literal: IDO emits it as the function's first .rodata
// word, which is where retail keeps D_81312A00, so no named definition is needed
// (a `const f32` goes to .data and would shift the whole section).


void func_81311650(Frag14State *arg0, void *arg1) {
    Frag14Record *record;
    s16 rect[4];
    f32 alpha;
    s16 i;

    record = arg0->owner;
    if (record == NULL) {
        return;
    }
    if (arg0->status == 0) {
        return;
    }
    if (func_81600DA8(arg1, arg0) == 0) {
        return;
    }
    alpha = 1.0f - func_81311368((u8 *)arg0, rect);
    Fragment11_DrawThickPanelFrame(rect[0], rect[1], rect[2], rect[3]);
    func_81608044(rect[0] + 8, rect[1] + 8, rect[2] - 0x13, rect[3] - 0x13, alpha,
                  (s32 *)(D_81312170 + *(s8 *)record * 3));
    if (alpha > 0.1f) {
        return;
    }
    func_816073A0(rect);
    func_800498C4();
    func_8004989C(record->line_height);
    for (i = 0; i < record->entry_count; i++) {
        func_813114B8(arg0, i);
    }
    func_800499EC();
    if (arg0->index >= 0 && arg0->unk_1C != 0) {
        // The position summands are written box_y + unk_10 + product: IDO flattens
        // same-typed additions left to right, and only this order puts the two
        // loads and the addu of the product last (any other order scores 205-360).
        func_81608918(arg0->box_x + record->unk_12 - 42,
                      arg0->box_y + record->unk_10 + record->line_height * arg0->index,
                      (f32 *)((u8 *)arg0 + 8));
    }
    if (*(s32 *)((u8 *)record + 4) != 0) {
        void *gfx;
        gfx = (void *)func_8004C990(0x11B, 0);
        gSPDisplayList(D_800D0510++, D_80094E38);
        func_8004D19C(arg0->box_x + 17,
                      arg0->box_y + arg0->box_height / 2 - func_8004CA24(gfx),
                      (s32)gfx, 0, 0);
        gSPDisplayList(D_800D0510++, D_80094F50);
    }
    func_81607408();
}

/* mkdraft:func_81311894 begin */
extern void func_800226C0(s32);
extern u8 D_800CE060[];



void func_81311894(u8 *arg0) {
    s16 count;
    s32 spare; // FAKE: unused word at 0x20(sp); keeps the frame at 0x28
    u16 flags;
    u8 *entry;
    Frag14Record *record;


    record = (Frag14Record *)*(void **)arg0;
    count = record->entry_count;
    if (*(s8 *)(arg0 + 0x1A) >= 0) {
        entry = D_800CE060 + *(s8 *)(arg0 + 0x1A) * 0x28;
        flags = *(u16 *)(entry + 0xC);
        if (*(u16 *)(entry + 0xC) & 0x8000) {
            s16 idx = ((Frag14State *)arg0)->index;
            ((Frag14State *)arg0)->status = 3;
            if (idx >= 0) {
                func_800226C0(*(u16 *)((u8 *)((Frag14State *)arg0)->owner->entries + idx * 8 + 2));
            }
        } else if (*(u16 *)(entry + 0xC) & 0x4000) {
            func_800226C0(*(u16 *)((u8 *)record + 0x1A));
            ((Frag14State *)arg0)->index = -1;
            ((Frag14State *)arg0)->status = 3;
        }
        if (((Frag14State *)arg0)->unk_1C != 0) {
            if (flags & 0x800) {
                func_800226C0(1);
                ((Frag14State *)arg0)->index = ((Frag14State *)arg0)->index - 1;
                if (((Frag14State *)arg0)->index < 0) {
                    ((Frag14State *)arg0)->index = count - 1;
                }
            } else if (flags & 0x400) {
                func_800226C0(1);
                ((Frag14State *)arg0)->index = ((Frag14State *)arg0)->index + 1;
                if (((Frag14State *)arg0)->index >= count) {
                    ((Frag14State *)arg0)->index = 0;
                }
            }
        }
    }
    *(f32 *)(arg0 + 4) = 16.0f;
}
/* mkdraft:func_81311894 end */

extern f32 func_816092FC(void);
void func_813119E4(u8 *arg0) {
    f32 step = func_816092FC();
    *(f32 *)(arg0 + 4) += step;
    if (*(f32 *)(arg0 + 4) >= 16.0f) {
        *(f32 *)(arg0 + 4) = 16.0f;
        arg0[0x18] = 2;
    }
}

void func_81311A3C(u8 *arg0) {
    f32 step = func_816092FC();
    *(f32 *)(arg0 + 4) -= step;
    if (*(f32 *)(arg0 + 4) <= 0.0f) {
        *(f32 *)(arg0 + 4) = 0.0f;
        arg0[0x18] = 4;
    }
}

void func_81311A90(u8 *arg0) {
    *(f32 *)(arg0 + 4) = 0.0f;
}

void func_81311A9C(u8 *arg0) {
    *(s32 *)(arg0 + 0) = 0;
    *(f32 *)(arg0 + 4) = 0.0f;
}

void func_81311894(u8 *);
f32 func_81311368(u8 *, s16 *);
extern void func_81600A34(void *, u8 *, s32, s32, s32, s32, s32);
extern void func_813119E4(u8 *arg0);
extern void func_81311A3C(u8 *arg0);
extern void func_81311A90(u8 *arg0);
extern void func_81311A9C(u8 *arg0);
void func_81311AAC(u8 *arg0, void *arg1) {
    s32 flag = 0;
    s16 rect[4];

    if (*(s32 *)arg0 != 0) {
        switch (arg0[0x18]) {
        case 2:
            func_81311894(arg0);
            flag = *(s32 *)(arg0 + 0x1C);
            break;
        case 1:
            func_813119E4(arg0);
            flag = 1;
            break;
        case 3:
            func_81311A3C(arg0);
            flag = 1;
            break;
        case 4:
            func_81311A90(arg0);
            break;
        case 0:
            func_81311A9C(arg0);
            return;
        default:
            return;
        }
        func_81311368(arg0, rect);
        func_81600A34(arg1, arg0, flag, rect[0], rect[1], rect[2], rect[3]);
    }
}

void func_81311B98(u8 *arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 sp20 = arg2;

    func_813110F0(arg0, arg1, arg3);
    switch (arg0[0x18]) {
        case 2:
            *(f32 *)(arg0 + 4) = 16.0f;
            return;
        case 0:
        case 4:
            *(f32 *)(arg0 + 4) = 0.0f;
            break;
        case 1:
        case 3:
            break;
    }
    arg0[0x18] = 1;
    arg0[0x19] = 0;
    arg0[0x1A] = sp20;
}

void func_81311C18(u8 *arg0) {
    *(s8 *)(arg0 + 0x19) = -1;
    switch (arg0[0x18]) {
        case 0:
        case 4:
            *(f32 *)(arg0 + 4) = 0.0f;
            return;
        case 2:
            *(f32 *)(arg0 + 4) = 16.0f;
            break;
        case 1:
        case 3:
            break;
    }
    arg0[0x18] = 3;
}

s32 func_81311C70(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    Frag14State *state = arg0;
    Frag14Record *record = arg1;
    s16 result;
    s8 index;
    if ((record == state->owner) && (state->status == 4)) {
        index = state->index;
        state->status = 0;
        if (index >= 0) {
            result = record->entries[index].value;
        } else {
            result = record->fallback;
        }
        return (result << 16) >> 16;
    }
    if (state->status != 3) {
        func_81311B98(arg0, arg1, arg2, arg3);
    }
    return 0;
}

void func_81311CFC(void *arg0) {
    (*(s32 *)((u8 *)(arg0) + (0))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x19))) = -1;
    (*(s8 *)((u8 *)(arg0) + (0x1A))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x18))) = 0;
    (*(s16 *)((u8 *)(arg0) + (0x10))) = 0;
    (*(s16 *)((u8 *)(arg0) + (0x12))) = 0;
    (*(s16 *)((u8 *)(arg0) + (0x14))) = 0;
    (*(s16 *)((u8 *)(arg0) + (0x16))) = 0;
    (*(f32 *)((u8 *)(arg0) + (4))) = 0.0f;
    (*(f32 *)((u8 *)(arg0) + (8))) = 0.0f;
}
#endif
