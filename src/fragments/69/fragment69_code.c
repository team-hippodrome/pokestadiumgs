#include "global.h"
#include "controller.h"


#ifdef VERSION_US
s32 func_8F10008C(s32 arg0, void *arg1);
s32 func_8F1000F4(s32 arg0, void *arg1);
extern u8 D_80126420;
extern u8 D_1000000[];

u32 D_8F103900[] = {
    0x0C00FFFF, 0x05000000, 0x0B00001E, 0x00000000, 0x014000F0, 0x00000000, 0x0000000A, 0x000004E2,
    0x05000000, 0x0D000000, 0x05000000, 0x14000000, 0x002D0019, 0xFFFFFF28, 0x08000000, (u32)func_8F10008C,
    0x00000000, 0x14000000, 0x002D0019, 0x80808028, 0x08000000, (u32)func_8F1000F4, 0x00000000, 0x16646464,
    0x0F000003, 0x05000000, 0x0A000000, (u32)&D_80126420, 0x06000000, 0x06000000, 0x06000000, 0x06000000,
    (u32)D_1000000,
};
s32 D_8F103984 = 1;
s32 D_8F103988 = -1;
u8 D_8F10398C[] = "\xA4\xC0\xA4\xDF\xA1\xBC\xA4\xAF\xA4\xF3";
u8 D_8F103998[] = "DummyMon";
s32 D_8F1039A4 = 0;
s32 D_8F1039A8 = 0;
s32 D_8F1039AC = 0;
s32 D_8F1039B0 = 0;
s32 D_8F1039B4 = 0;
s32 D_8F1039B8 = 0;
s32 D_8F1039BC = 0;
s32 D_8F1039C0 = 0;
s32 D_8F1039C4 = 0;
s16 D_8F1039C8[][5] = {
    { 50, 50, 130, 180, 1 },
    { 50, 50, 180, 74, 2 },
    { 50, 50, 180, 50, 2 },
};
u8 D_8F1039E8[] = "\xA5\xC7\xA1\xBC\xA5\xBF\xA4\xF2\xA5\xED\xA5\xE0\xA4\xCB\xA5\xBB\xA1\xBC\xA5\xD6\xA4\xB7\xA4\xDE\xA4\xB9";
u8 D_8F103A04[] = "Save current data to ROM?";
extern u8 D_8F103AD0[], D_8F103AD8[], D_8F103AE0[], D_8F103AE4[];
void *D_8F103A20[] = { D_8F103AD0, D_8F103AD8 };
void *D_8F103A28[] = { D_8F103AE0, D_8F103AE4 };
u8 D_8F103A30[] = "\xA4\xB7\xA4\xE5\xA4\xA6\xA4\xEA\xA4\xE7\xA4\xA6\xA4\xB7\xA4\xDE\xA4\xB9\xA4\xAB\xA1\xA9";
u8 D_8F103A48[] = "Quit ?";

// Debug toggle on the Z trigger; the flag is a function-local static, which is why every access
// re-forms its address instead of reusing one base register.
s32 func_8F100020(s32 arg0, u8 *arg1) {
    static s32 sDebugFlag = 1;

    if (arg0 == 2) {
        if (D_80087200->buttonsPressed & Z_TRIG) {
            sDebugFlag ^= 1;
        }
        if (sDebugFlag) {
            arg1[2] |= 0x40;
        } else {
            arg1[2] &= ~0x40;
        }
    }
    return 0;
}

#endif

#ifdef VERSION_US
extern void func_80037120(s32, s32, s32 *, s16 *, s16 *);
extern s32 D_80094908;
s32 func_8F10008C(s32 arg0, void *arg1) {
    s16 pad;
    s32 sp28;
    s16 sp26;
    s16 sp24;

    if (arg0 == 2) {
        func_80037120(D_80094908 + 0xB4, D_80094908 + 0xA8, &sp28, &sp26, &sp24);
        *(s16 *)((u8 *)arg1 + 0x1C) = (s16)(sp26 + 0x2000);
        *(s16 *)((u8 *)arg1 + 0x1E) = (s16)(sp24 - 0x2000);
    }
    return 0;
}
#endif

#ifdef VERSION_US
s32 func_8F1000F4(s32 arg0, void *arg1) {
    s16 pad;
    s32 sp28;
    s16 sp26;
    s16 sp24;

    if (arg0 == 2) {
        func_80037120(D_80094908 + 0xB4, D_80094908 + 0xA8, &sp28, &sp26, &sp24);
        *(s16 *)((u8 *)arg1 + 0x1C) = (s16)(-0x2000 - sp26);
        *(s16 *)((u8 *)arg1 + 0x1E) = (s16)(sp24 + 0x6000);
    }
    return 0;
}
#endif

#ifdef VERSION_US
extern u8 D_8F1DF270[];

void func_8F100160(void) {
    s32 i;

    for (i = 0; i < 3; i++) {
        *(s16 *)(D_8F1DF270 + i * 6) = 0;
        *(s16 *)(D_8F1DF270 + i * 6 + 2) = 0;
        *(s16 *)(D_8F1DF270 + i * 6 + 4) = 0;
    }
}
#endif

#ifdef VERSION_US
extern u8 D_8F1DF270[];
s32 func_8F10018C(s32 arg0)
{
  s16 *entry = (s16 *) (D_8F1DF270 + (arg0 * 6));
  s16 value;
  s32 result = 0;
  if (((*entry) == 0) || ((*entry) == 6))
  {
    *entry = 1;
    result = 1;
  }
  return result;
}
#endif

#ifdef VERSION_US
s32 func_8F1001D0(s32 arg0)
{
  s16 *temp_v0;
  s16 temp_a1;
  s32 var_v1;
  temp_v0 = (arg0 * 6) + D_8F1DF270;
  ;
  var_v1 = 0;
  if (((*temp_v0) == 3) || ((*temp_v0) == 4))
  {
    *temp_v0 = 5;
    var_v1 = 1;
  }
  return var_v1;
}
#endif

void func_8F100218(void) {
}

#ifdef VERSION_US
s32 func_8F100220(s32 arg0) {
    s16 *entry = (s16 *)(D_8F1DF270 + arg0 * 6);
    s32 result = -2;

    switch (*entry) {
        case 3:
            result = entry[2];
            break;
        case 4:
            result = -1;
            break;
    }
    return result;
}
#endif

#ifdef VERSION_US
extern u8 D_8F1DF274[];
void func_8F100274(s32 arg0) { struct Rec { s16 value[3]; }; ((struct Rec *)D_8F1DF274)[arg0].value[0] = 0; }
#endif

#ifdef VERSION_US
void func_8F100290(void *arg0) {
    (*(s16 *)((u8 *)(arg0) + (2))) = (s16) ((*(s16 *)((u8 *)(arg0) + (2))) + 1);
    if ((*(s16 *)((u8 *)(arg0) + (2))) >= 8) {
        (*(s16 *)((u8 *)(arg0) + (0))) = 2;
        (*(s16 *)((u8 *)(arg0) + (2))) = 8;
    }
}
#endif

#ifdef VERSION_US
void func_8F1002C4(void *arg0) {
    (*(s16 *)((u8 *)(arg0) + (2))) = (s16) ((*(s16 *)((u8 *)(arg0) + (2))) - 1);
    if ((*(s16 *)((u8 *)(arg0) + (2))) <= 0) {
        (*(s16 *)((u8 *)(arg0) + (0))) = 6;
        (*(s16 *)((u8 *)(arg0) + (2))) = 0;
    }
}
#endif

#ifdef VERSION_US
typedef struct {
    s16 state;
    s16 pad2;
    s16 index;
} Fragment69MenuRecord;
typedef struct {
    s16 values[5];
} Fragment69LimitRecord;
extern u8 D_8F1DF270[];
void func_8F1002F0(void *arg0) {
    Fragment69MenuRecord *record = (Fragment69MenuRecord *)arg0;
    s32 rowIndex;
    Fragment69LimitRecord *row;

    if ((D_80087200->buttonsRepeat) & 0x800) {
        record->index--;
        if (record->index < 0) {
            rowIndex = ((u8 *)record - D_8F1DF270) / 6;
            row = (Fragment69LimitRecord *)&D_8F1039C8[rowIndex][4];
            record->index = row->values[0] - 1;
        }
    }
    if ((D_80087200->buttonsRepeat) & 0x400) {
        rowIndex = ((u8 *)record - D_8F1DF270) / 6;
        row = (Fragment69LimitRecord *)&D_8F1039C8[rowIndex][4];
        record->index++;
        if (record->index >= row->values[0]) record->index = 0;
    }
    if ((D_80087200->buttonsRepeat) & 0x8000) {
        record->state = 3;
        return;
    }
    if ((D_80087200->buttonsRepeat) & 0x4000) record->state = 4;
}
#endif

#ifdef VERSION_US
extern u8 D_8F1DF282[];
extern void func_8F100290(void *);
extern void func_8F1002F0(void *);
extern void func_8F1002C4(void *);
void func_8F1003EC(void)
{
  u8 *ptr;
 ptr = D_8F1DF270; do {
    switch (*((s16 *) ptr))
    {
      case 1:
        func_8F100290(ptr);
        break;

      case 2:
        func_8F1002F0(ptr);
        break;

      case 5:
        func_8F1002C4(ptr);
        break;

    }

    ptr += 6;
  }
  while (ptr != D_8F1DF282);
}
#endif

#ifdef VERSION_US
typedef struct {
    s16 state;
    s16 timer;
    s16 selected;
} Fragment69MenuState;
typedef struct {
    u8 r, g, b;
} Fragment69Rgb;
#endif

#ifdef VERSION_US
extern void Ui_DrawGradientPanel(s32, s32, s32, s32, s32, s32);
// The two colors are initialized locals: IDO copies them from anonymous .data templates, which
// is why their bytes sit between func_8F100020's static and the tables below.
void func_8F10049C(Fragment69MenuState *arg0) {
    s32 index;
    s16 *rect;
    s32 width;
    s32 height;
    s32 x;
    s32 y;

    index = ((u8 *)arg0 - D_8F1DF270) / 6;
    rect = D_8F1039C8[index];
    width = (rect[2] * arg0->timer) / 8;
    height = (rect[3] * arg0->timer) / 8;
    x = (rect[2] - width) / 2 + rect[0];
    y = (rect[3] - height) / 2 + rect[1];
    {
        Fragment69Rgb top = { 0, 0, 30 };
        Fragment69Rgb bottom = { 0, 0, 150 };

        Ui_DrawGradientPanel(x, y, width, height, (s32)&top, (s32)&bottom);
    }
}

extern u8 D_8F103AE8[], D_8F103AF8[], D_8F103B0C[], D_8F103B1C[];
u8 *D_8F103A5C[] = { D_8F103AE8, D_8F103AF8 };
u8 *D_8F103A64[] = { D_8F103B0C, D_8F103B1C };
extern u8 D_8F103B64[], D_8F103B78[], D_8F103B88[], D_8F103B9C[], D_8F103BB8[], D_8F103BC4[], D_8F103BCC[], D_8F103BD4[], D_8F103BDC[], D_8F103BE8[], D_8F103C00[], D_8F103C10[];
u8 *D_8F103A6C[] = { D_8F103B64, D_8F103B78, D_8F103B88, D_8F103B9C, D_8F103BB8, D_8F103BC4, D_8F103BCC, D_8F103BD4, D_8F103BDC, D_8F103BE8, D_8F103C00, D_8F103C10 };
extern u8 D_8F103C1C[], D_8F103C2C[], D_8F103C38[], D_8F103C4C[], D_8F103C60[], D_8F103C64[], D_8F103C70[], D_8F103C7C[], D_8F103C84[], D_8F103C8C[], D_8F103C98[], D_8F103CA8[];
u8 *D_8F103A9C[] = { D_8F103C1C, D_8F103C2C, D_8F103C38, D_8F103C4C, D_8F103C60, D_8F103C64, D_8F103C70, D_8F103C7C, D_8F103C84, D_8F103C8C, D_8F103C98, D_8F103CA8, NULL };
#endif

#ifdef VERSION_US
extern s16 D_8F1039C8[][5];
extern u8 D_8F1039E8[];
extern u8 D_8F103A04[];
extern void *D_8F103A20[];
extern void *D_8F103A28[];
extern void func_800498C4(void);
extern void func_800496A4(s32, s32);
extern void func_8004972C(s32, s32, s32, s32);
extern void Font_EnableTwoCycleTexturing(void);
extern void func_800497E4(s32, s32, s32, s32);
extern s32 func_8003514C(void);
extern void func_800495BC(s32, s32, const char *, ...);
extern void Font_DisableTwoCycleTexturing(void);
extern void func_800499EC(void);
void func_8F100594(Fragment69MenuState *arg0) {
    void *text;
    void *itemText;
    s32 item;
    s32 tableOffset;
    s32 yOffset;
    s16 *position;

    func_800498C4();
    func_800496A4(0x20, 0);
    func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
    Font_EnableTwoCycleTexturing();
    func_800497E4(0, 0xFF, 0, 0xFF);
    if (func_8003514C() == 0) {
        text = D_8F1039E8;
    } else {
        text = D_8F103A04;
    }
    position = D_8F1039C8[((u8 *)arg0 - D_8F1DF270) / 6];
    func_800495BC(position[0] + 0xA, position[1] + 4, text);
    Font_DisableTwoCycleTexturing();
    item = 0; tableOffset = 0; yOffset = 0; do {
        if (item == arg0->selected) {
            func_8004972C(0xFF, 0xFF, 0, 0xFF);
        } else {
            func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
        }
        if (func_8003514C() == 0) {
            itemText = *(void **)((u8 *)D_8F103A20 + tableOffset);
        } else {
            itemText = *(void **)((u8 *)D_8F103A28 + tableOffset);
        }
        func_800495BC(position[0] + 0xA, position[1] + yOffset + 0x28, itemText);
        item++;
        tableOffset += 4;
        yOffset += 0xE;
    } while (item != 2);
    func_800499EC();
}
#endif

#ifdef VERSION_US
extern u8 D_8F103A30[];
extern u8 D_8F103A48[];
void func_8F100740(Fragment69MenuState *arg0) {
    void *text;
    void *itemText;
    s32 item;
    s32 tableOffset;
    s32 yOffset;
    s16 *position;

    func_800498C4();
    func_800496A4(0x20, 0);
    func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
    Font_EnableTwoCycleTexturing();
    func_800497E4(0xFF, 0, 0, 0xFF);
    if (func_8003514C() == 0) {
        text = D_8F103A30;
    } else {
        text = D_8F103A48;
    }
    position = D_8F1039C8[((u8 *)arg0 - D_8F1DF270) / 6];
    func_800495BC(position[0] + 0xA, position[1] + 4, text);
    Font_DisableTwoCycleTexturing();
    item = 0; tableOffset = 0; yOffset = 0; do {
        if (item == arg0->selected) {
            func_8004972C(0xFF, 0xFF, 0, 0xFF);
        } else {
            func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
        }
        if (func_8003514C() == 0) {
            itemText = *(void **)((u8 *)D_8F103A20 + tableOffset);
        } else {
            itemText = *(void **)((u8 *)D_8F103A28 + tableOffset);
        }
        func_800495BC(position[0] + 0xA, position[1] + yOffset + 0x14, itemText);
        item++;
        tableOffset += 4;
        yOffset += 0xC;
    } while (item != 2);
    func_800499EC();
}
#endif

#ifdef VERSION_US
extern s32 D_8F1DEE18;
extern s32 D_8F1DEE1C;
extern s32 D_8F1DEE20;
extern s32 func_80073420(s32);
extern void *func_8004B7A4(s32);
extern char D_8F103B2C[];
extern char D_8F103B38[];
extern char D_8F103B50[];
void func_8F1008EC(Fragment69MenuState *arg0) {
    void *title;
    s16 *position;
    s32 i;
    s32 yOffset;
    s32 index;
    s32 species;
    void *name;

    func_800498C4();
    func_800496A4(0x20, 0);
    func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
    Font_EnableTwoCycleTexturing();
    func_800497E4(0, 0xFF, 0, 0xFF);
    position = D_8F1039C8[((u8 *)arg0 - D_8F1DF270) / 6];
    if (func_8003514C() == 0) {
        title = D_8F103A5C[D_8F1DEE18];
    } else {
        title = D_8F103A64[D_8F1DEE18];
    }
    func_800495BC(position[0] + 0xA, position[1] + 4, title);
    Font_DisableTwoCycleTexturing();
    for (i = 0, yOffset = 0; i < 10; i++, yOffset += 14) {
        index = D_8F1DEE1C + i;
        if (i == D_8F1DEE20) {
            func_8004972C(0xFF, 0xFF, 0, 0xFF);
        } else {
            func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
        }
        if (D_8F1DEE18 == 0) {
            species = index;
        } else {
            species = func_80073420(index & 0xFF);
        }
        name = func_8004B7A4(species);
        if (name == NULL) {
            if (func_8003514C() == 0) {
                name = D_8F10398C;
            } else {
                name = D_8F103998;
            }
        }
        func_800495BC(position[0] + 0xA, position[1] + yOffset + 0x10, D_8F103B2C, species, name);
    }
    func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
    func_800495BC(position[0] + 0xA, position[1] + 0xA0, (func_8003514C() == 0) ? D_8F103B38 : D_8F103B50);
    func_800499EC();
}
#endif

#ifdef VERSION_US
/* mkdraft:func_8F100B54 begin */
void func_8F100B54(void) {
    u32 index;
    Fragment69MenuState *entry;

    index = 0;
    do {
        entry = (Fragment69MenuState *)D_8F1DF270 + index;
        if (entry->timer > 0) {
            func_8F10049C(entry);
            if (entry->timer >= 8) {
                switch (entry - (Fragment69MenuState *)D_8F1DF270) {
                case 0: func_8F1008EC(entry); break;
                case 1: func_8F100594(entry); break;
                case 2: func_8F100740(entry); break;
                }
            }
        }
        index += 1;
    } while ((Fragment69MenuState *)D_8F1DF282 != (Fragment69MenuState *)D_8F1DF270 + index);
}
/* mkdraft:func_8F100B54 end */
#endif

#ifdef VERSION_US
extern s32 D_8F1DECA4;
extern void Vec3f_SetComponentsDuplicate(f32 *, f32, f32, f32);
extern void Camera_ComputeEyeFromAngles(f32 *, s32 *, f32, s16, s32);
extern void func_80038E14(s32, s32, s32, s32, f32, f32, f32, s32);
extern void GeoCamera_SetPerspective(void *, f32, f32, f32);
void func_8F100C64(f32 arg0, void *arg1) {
    f32 position[3];
    s32 output[3];

    Vec3f_SetComponentsDuplicate(position, 0.0f, 250.0f / arg0, 0.0f);
    Camera_ComputeEyeFromAngles(position, output, 1.65e+03f / arg0, *(s16 *)((u8 *)arg1 + 0), *(s16 *)((u8 *)arg1 + 2));
    func_80038E14(*(s32 *)((u8 *)(u32)D_8F1DECA4 + 0xC), output[0], output[1], output[2], position[0], position[1], position[2], 0);
    GeoCamera_SetPerspective((void *)(u32)*(s32 *)((u8 *)(u32)D_8F1DECA4 + 0xC), 30.0f, 100.0f / arg0, 12800.0f / arg0);
}
#endif

#ifdef VERSION_US
extern s32 func_8004B7E0(s32, void *);
extern s32 func_8004B8E4(s32);
typedef struct { f32 x; f32 y; f32 z; } Func8F100D58Vec3f;

void func_8F100D58(s32 arg0, void *arg1) {
    Func8F100D58Vec3f sp1C;

    func_8004B7E0(arg0, &sp1C);
    if (sp1C.y > -150.0f) {
        *(f32 *)((u8 *)arg1 + 4) = (f32)(func_8004B8E4(arg0) * 4);
        return;
    }
    *(f32 *)((u8 *)arg1 + 4) = 0.0f;
}
#endif

#ifdef VERSION_US
extern void func_8004D1FC(u8 *);
extern void func_80044270(s16, s16, s16, s16, s32, s32, s32, s32, s32);
void func_8F100DCC(void *arg0, void *arg1) {
    u8 *sp3C;
    void *temp_s0;
    sp3C = *(u8 **)((u8 *)arg0 + 4);
    *(s16 *)((u8 *)arg1 + 2) = (s16)(*(s16 *)((u8 *)arg1 + 2) + 6);
    *(u16 *)((u8 *)arg1 + 4) = (u16)(*(u16 *)((u8 *)arg1 + 4) & 0xFFFD);
    temp_s0 = arg1;
    func_8004D1FC(sp3C);
    func_80044270(*(s16 *)((u8 *)temp_s0 + 0), *(s16 *)((u8 *)temp_s0 + 2),
        (s16)(*(u16 *)(u32)sp3C / 2), (s16)(*(u16 *)((u8 *)sp3C + 2) / 2), 0, 0, 0x800, 0x800, 0);
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/69/fragment69_code/func_8F100E78.s")
#endif

#ifdef VERSION_US
extern Gfx *D_800D0510;
extern u8 D_80094E38[];
extern u8 D_8F1040A0[];
extern s32 D_8F1DEE24;
extern void Gfx_DrawTextureRgba16(s16, s16, s16, s16, u8 *, s16, s32);
void func_8F10128C(void) {
    u8 *texture;

    texture = D_8F1040A0 + D_8F1DEE24 * 0xC80;
    gSPDisplayList(D_800D0510++, D_80094E38);
    Gfx_DrawTextureRgba16(0xA0, 0x1E, 0x28, 0x28, texture, 0x28, 0);
}
#endif

#ifdef VERSION_US
extern s32 D_8F1DEE28;
extern s32 D_8F1DEE2C;
extern s32 D_8F1DEE38;
extern s32 D_8F1DEE3C;
extern s8 D_8F1DEE48[];
extern s8 D_8F1DEE4A;
extern s8 D_8F1DEE4B;
extern s32 D_8F1DEE58;
extern s32 D_8F1DEE5C;
extern s32 D_8F1DEE60;
extern s8 D_8F1DED4E;
extern u8 D_8F1DECC4;
extern u8 D_8F1DECC5;
extern u8 D_8F1DECE8[];
extern s16 *D_8F1DECEC;
extern u8 D_8F1DECFC[];
extern void *D_8F1DECB4;

typedef struct {
    s16 unk00;
    s8 unk02;
    s8 unk03;
} Unk8F101318_Mode;

typedef struct Unk8F101318_AnimRec {
    u8 unk00[0x20];
    s32 unk20;
    u8 unk24[8];
    s32 unk2C;
    u8 unk30[4];
    s32 unk34;
} Unk8F101318_AnimRec;

extern s32 D_8F1DEE24;

extern Unk8F101318_AnimRec *D_8F1DECA0;
extern u16 D_80094904;
extern void *D_80094BB0;

extern u8 D_8F103CB0[];
extern u8 D_8F103CBC[];
extern u8 D_8F103CC8[];
extern u8 D_8F103CD8[];
extern u8 D_8F103CE4[];
extern u8 D_8F103CF0[];
extern u8 D_8F103D04[];
extern u8 D_8F103D14[];
extern u8 D_8F103D28[];
extern u8 D_8F103D38[];
extern u8 D_8F103D48[];
extern u8 D_8F103D5C[];

extern void func_8004989C(s32);
extern s32 ModelAnim_AdvanceCurveFrame(void *, u16);
extern s16 ModelAnim_AdvanceEventFrame(void *, u16);
extern void *func_8004B7A4(s32);
extern s16 func_8004B920(s32, s32);
extern Unk8F101318_Mode func_8004B9E0(s32);



void func_8F101318(void) {
    s32 i;
    u8 *text;
    u32 total;
    s16 hpCur;
    s16 hpMax;
    void *object;
    void *icon;
    Unk8F101318_Mode mode;

    hpCur = func_8004B920(D_8F1DEE24, 0);
    hpMax = func_8004B920(D_8F1DEE24, 1);
    object = D_8F1DECB4;
    icon = (*(void *(**)(s32, s32))((u8 *)object + 0x2C))(0, 0);
    mode = func_8004B9E0(D_8F1DEE24);
    func_800498C4();
    func_8004989C(0xE);
    func_800496A4(0x20, 0);
    Font_EnableTwoCycleTexturing();
    func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
    func_800497E4(0, 0, 0xFF, 0xFF);
    if (func_8003514C() == 0) {
        text = D_8F103A6C[D_8F1DEE58];
    } else {
        text = D_8F103A9C[D_8F1DEE58];
    }
    func_800495BC(0x1E, 0x1E, text);
    Font_DisableTwoCycleTexturing();
    switch (D_8F1DEE58) {
    case 0:
        text = func_8004B7A4(D_8F1DEE24);
        if (text == NULL) {
            text = D_8F10398C;
        }
        func_800495BC(0x1E, 0x32, D_8F103CB0, D_8F1DEE24, text);
        break;
    case 1:
        if (D_8F1DEE28 != -1) {
            func_800495BC(0x14, 0x32, D_8F103CBC, D_8F1DEE2C,
                          ModelAnim_AdvanceCurveFrame(D_8F1DECE8, D_80094904) >> 0x10);
            if ((D_8F1DECEC != NULL) && (*D_8F1DECEC & 8)) {
                Font_EnableTwoCycleTexturing();
                func_800497E4(0, 0xFF, 0xFF, 0xFF);
                if (func_8003514C() == 0) {
                    text = D_8F103CC8;
                } else {
                    text = D_8F103CD8;
                }
                func_800495BC(0x14, 0x40, text);
                Font_DisableTwoCycleTexturing();
            }
        } else {
            func_800495BC(0x14, 0x32, D_8F103CE4, D_8F1DEE2C);
        }
        if (D_8F103988 == -1) {
            if (func_8003514C() == 0) {
                text = D_8F103CF0;
            } else {
                text = D_8F103D04;
            }
            func_800495BC(0x14, 0x4E, text);
            if (func_8003514C() == 0) {
                text = D_8F103D14;
            } else {
                text = D_8F103D28;
            }
            func_800495BC(0x14, 0x5C, text);
            if (func_8003514C() == 0) {
                text = D_8F103D38;
            } else {
                text = D_8F103D48;
            }
            func_800495BC(0x14, 0x6A, text);
            if (func_8003514C() == 0) {
                text = D_8F103D5C;
            } else {
                text = "<TEX,8> With";
            }
            func_800495BC(0x14, 0x78, text);
        } else {
            if (func_8003514C() == 0) {
                text = "<TEX,0> こまおくり";
            } else {
                text = "<TEX,0> Slow-Motion";
            }
            func_800495BC(0x14, 0x4E, text);
        }
        break;
    case 2:
        if ((D_8F1DEE38 != -1) && (((u8 *)icon)[5] > 0)) {
            func_800495BC(0x14, 0x32, "%2d : %3d", D_8F1DEE3C,
                          ModelAnim_AdvanceEventFrame(D_8F1DECFC, D_80094904));
        } else {
            func_800495BC(0x14, 0x32, "%2d : ---", D_8F1DEE3C);
        }
        break;
    case 3:
        text = func_8004B7A4(D_8F1039A4);
        if (text == NULL) {
            if (func_8003514C() == 0) {
                text = D_8F10398C;
            } else {
                text = D_8F103998;
            }
        }
        func_800495BC(0x14, 0x32, "Sum %d : %s : %dK", D_8F1039A4, text, (u32)(D_8F1039B0 + 0x3FF) >> 0xA);
        text = func_8004B7A4(D_8F1039B4);
        if (text == NULL) {
            if (func_8003514C() == 0) {
                text = D_8F10398C;
            } else {
                text = D_8F103998;
            }
        }
        func_800495BC(0x14, 0x46, "Model %d : %s : %dK", D_8F1039B4, text, (u32)(D_8F1039BC + 0x3FF) >> 0xA);
        text = func_8004B7A4(D_8F1039B8);
        if (text == NULL) {
            if (func_8003514C() == 0) {
                text = D_8F10398C;
            } else {
                text = D_8F103998;
            }
        }
        func_800495BC(0x14, 0x5A, "Anime %d : %s : %dK", D_8F1039B8, text, (u32)(D_8F1039C0 + 0x3FF) >> 0xA);
        break;
    case 4:
        func_800495BC(0x14, 0x32, "%3d", *(s16 *)D_8F1DEE48 >> 6);
        func_800495BC(0x14, 0x40, "MIN %3d", hpCur);
        func_800495BC(0x14, 0x4E, "MAX %3d", hpMax);
        if (func_8003514C() == 0) {
            text = "<TEX,3>さいしょうちのセット";
        } else {
            text = "<TEX,3>Set MIN";
        }
        func_800495BC(0x14, 0x5C, text);
        if (func_8003514C() == 0) {
            text = "<TEX,5>さいだいちのセット";
        } else {
            text = "<TEX,5>Set MAX";
        }
        func_800495BC(0x14, 0x6A, text);
        if (func_8003514C() == 0) {
            text = "<TEX,0>レアポケモンのいろをセット";
        } else {
            text = "<TEX,0>Set Rare Pokemon Color";
        }
        func_800495BC(0x14, 0x78, text);
        break;
    case 5:
        func_800495BC(0x14, 0x32, "%3d", D_8F1DEE4B);
        break;
    case 6:
        func_800495BC(0x14, 0x32, "%3d", D_8F1DEE4A);
        break;
    case 7:
        i = 0;
        if (D_80094BB0 != NULL) {
            do {
                if (i == D_8F1DEE60) {
                    func_8004972C(0xFF, 0xFF, 0, 0xFF);
                } else {
                    func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
                }
                if (i == 0) {
                    func_800495BC(0x1E, i * 7 * 2 + 0x32, "X %4d", *(s16 *)((u8 *)D_80094BB0 + 0x1A));
                } else {
                    func_800495BC(0x1E, 0x40, "Z %4d", *(s16 *)((u8 *)D_80094BB0 + 0x1C));
                }
                i++;
            } while (i != 2);
            func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
            if (func_8003514C() == 0) {
                text = "<TEX,3>X-Zのきりかえ";
            } else {
                text = "<TEX,3>Change X-Z";
            }
            func_800495BC(0x1E, 0x4E, text);
            if (func_8003514C() == 0) {
                text = "<TEX,0>ぜんデータをロムにかきこむ";
            } else {
                text = "<TEX,0>Write All Data to ROM";
            }
            func_800495BC(0x1E, 0x5C, text);
        } else {
            if (func_8003514C() == 0) {
                text = "ちょうせいできません";
            } else {
                text = "Can not Control";
            }
            func_800495BC(0x1E, 0x32, text);
        }
        break;
    case 8:
        func_800495BC(0x14, 0x32, "%3d", D_8F1DECC5);
        break;
    case 9:
        func_800495BC(0x14, 0x32, "%d", D_8F1DECC4);
        break;
    case 10:
        func_800495BC(0x14, 0x32, "%d", D_8F1DEE5C);
        func_800495BC(0x14, 0x40, "H %3d", mode.unk00 >> 6);
        func_800495BC(0x14, 0x4E, "L %3d", mode.unk03);
        func_800495BC(0x14, 0x5C, "S %3d", mode.unk02);
        break;
    case 11:
        func_800495BC(0x14, 0x32, "%d", D_8F1DED4E);
        break;
    }
    total = D_8F1DECA0->unk2C + D_8F1DECA0->unk34;
    func_8004972C(0xFF, 0xFF, 0xFF, 0xFF);
    func_800495BC(0x1E, 0xB4, "MODEL %3dK", (u32)(D_8F1DECA0->unk2C + 0x3FF) >> 0xA);
    func_800495BC(0x1E, 0xC0, "ANIME %3dK", (u32)(D_8F1DECA0->unk34 + 0x3FF) >> 0xA);
    if (total >= 0x26001) {
        func_800495BC(0x1E, 0xCC, "<COL1,PUSH,255,0,0,255>Sum %3dK/%3dK<COL1,POP>", (u32)(total + 0x3FF) >> 0xA, 0x98);
    } else {
        func_800495BC(0x1E, 0xCC, "Sum %3dK/%3dK", (u32)(total + 0x3FF) >> 0xA, (u32)D_8F1DECA0->unk20 >> 0xA);
    }
    if (func_8003514C() == 0) {
        text = "<TEX,7>メッセージのオンオフ";
    } else {
        text = "<TEX,7>Message ON/OFF";
    }
    func_800495BC(0x1E, 0xD8, text);
    func_800499EC();
}
#endif

#ifdef VERSION_US
extern void BgStage_DrawFrame(void);
extern void GfxImage_FillCurrent(void *, u16);
extern void GeoRender_AdvanceFrameCounter(void);
extern void Geo_RenderRootNode(s32);
extern void func_8F10128C(void);
extern void func_8F100B54(void);
extern void func_8F101318(void);
extern void func_80008648(void);
extern s32 D_8F103988;
extern s32 D_8F1DECA4;
extern s32 D_8F103984;
void func_8F101CDC(void) {
    BgStage_DrawFrame();
    GfxImage_FillCurrent(&D_800D0510, 0x5295);
    if (D_8F103988 != 0) {
        if (D_8F103988 > 0) {
            D_8F103988--;
        }
        GeoRender_AdvanceFrameCounter();
    }
    Geo_RenderRootNode(D_8F1DECA4);
    func_8F10128C();
    if ((D_80087200->buttonsPressed) & 0x10) {
        D_8F103984 ^= 1;
    }
    if (D_8F103984 != 0) {
        func_8F101318();
    }
    func_8F100B54();
    func_80008648();
}
#endif

#ifdef VERSION_US
/* mkdraft:func_8F101DA0 begin */
extern f32 D_8F1DEE4C;
extern u8 D_8F1DEE50[];
extern Unk8F101318_AnimRec *D_8F1DECA0;
extern u8 D_8F1DECA8;
extern s32 D_8F1DEE28;
extern s32 D_8F1DEE2C;
extern s32 D_8F1DEE38;
extern s32 D_8F1DEE3C;
extern s32 func_8003F2C4(s32, u8 *, s32);
extern s32 func_8003F3BC(u8 *, s32);




void func_8F101DA0(void) {
    if (D_80087200->buttonsHeld & 4) {
        D_8F1DEE4C -= 0.1f;
        if (D_8F1DEE4C < 0.1f) {
            D_8F1DEE4C = 0.1f;
        }
    }
    if (D_80087200->buttonsHeld & 8) {
        D_8F1DEE4C += 0.1f;
        if (D_8F1DEE4C > 100.0f) {
            D_8F1DEE4C = 100.0f;
        }
    }
    if (D_80087200->stickXNorm != 0.0f) {
        *(s16 *)((u8 *)D_8F1DEE50 + 2) -= (s16)(D_80087200->stickXNorm * 32.0f);
    }
    if (D_80087200->stickYNorm != 0.0f) {
        *(s16 *)((u8 *)D_8F1DEE50 + 0) += (s16)(D_80087200->stickYNorm * 32.0f);
        if (*(s16 *)((u8 *)D_8F1DEE50 + 0) > 0x3F00) {
            *(s16 *)((u8 *)D_8F1DEE50 + 0) = 0x3F00;
        }
        if (*(s16 *)((u8 *)D_8F1DEE50 + 0) < -0x3F00) {
            *(s16 *)((u8 *)D_8F1DEE50 + 0) = -0x3F00;
        }
    }
    func_8F100C64(D_8F1DEE4C, D_8F1DEE50);
    if (D_80087200->buttonsPressed & 0x20) {
        D_8F1DEE28 = D_8F1DEE2C;
        func_8003F2C4(D_8F1DECA0, &D_8F1DECA8, -1);
        func_8003F2C4(D_8F1DECA0, &D_8F1DECA8, D_8F1DEE28);
        D_8F1DEE38 = D_8F1DEE3C;
        func_8003F3BC(&D_8F1DECA8, -1);
        func_8003F3BC(&D_8F1DECA8, D_8F1DEE38);
    }
    if (D_80087200->buttonsPressed & 0x1000) {
        if (D_8F103988 == -1) {
            D_8F103988 = 0;
        } else {
            D_8F103988 = -1;
        }
    }
    if ((D_8F103988 == 0) && (D_80087200->buttonsPressed & 0x8000)) {
        D_8F103988 = D_8F103988 + 1;
    }
}
/* mkdraft:func_8F101DA0 end */
#endif

#ifdef VERSION_US
// Four signed bytes passed to func_80041FD0 as one word.
typedef union {
    s32 word;
    s8 bytes[4];
} Fragment69PackedState;
#endif

#ifdef VERSION_US
extern s32 D_8F1DEE24;
extern s32 D_8F1DEE44;
extern s32 D_8F1DEE5C;
extern Unk8F101318_AnimRec *D_8F1DECA0;
extern s32 func_80041FD0(s32, u16, Fragment69PackedState, s32);
void func_8F101FF4(void) {
    s32 old = D_8F1DEE24;

    if (D_80087200->buttonsRepeat & 0x200) {
        D_8F1DEE24--;
        if (D_8F1DEE24 < 0) {
            D_8F1DEE24 = 0;
        }
    }
    if (D_80087200->buttonsRepeat & 0x100) {
        D_8F1DEE24++;
        if (D_8F1DEE24 > 0x118) {
            D_8F1DEE24 = 0x118;
        }
    }
    if (old != D_8F1DEE24) {
        D_8F1DEE44 = 0;
        D_8F1DEE5C = 0;
        func_80041FD0(D_8F1DECA0, D_8F1DEE24, *(Fragment69PackedState *)&D_8F1DEE44, 0);
    }
}
#endif

#ifdef VERSION_US
extern Unk8F101318_AnimRec *D_8F1DECA0;
extern u8 D_8F1DECA8;
extern void *D_8F1DECB4;
extern s32 D_8F1DEE28;
extern s32 D_8F1DEE2C;
extern s32 D_8F1DEE34;
extern s32 ModelAnim_SetResourceAnimation(s32, u8 *, s32);
extern s32 ModelAnim_IsFinished(u8 *);
extern void func_80024974();
// Debug animation selector for D_8F1DECA8. D-pad left/right steps D_8F1DEE2C through the
// animation count at byte 4 of the record returned by the callback at D_8F1DECB4 + 0x2C,
// wrapping at both ends. A plays the selected animation once (mode 0) and calls
// func_80024974 with D_8F1DEE24 when that is 1-251; C-left replays it each time
// ModelAnim_IsFinished reports the end (mode 1); C-right alternates it with animation 0
// (mode 2). Input is read only while D_8F103988 is -1.
void func_8F1020A4(void) {
    void *object;
    void *state;

    object = D_8F1DECB4;
    state = (*(void *(**)(s32, s32))((u8 *)object + 0x2C))(0, 0);
    if (*((u8 *)state + 4) > 0) {
        if (D_8F103988 == -1) {
            if (D_80087200->buttonsRepeat & L_JPAD) {
                D_8F1DEE2C--;
            }
            if (D_80087200->buttonsRepeat & R_JPAD) {
                D_8F1DEE2C++;
            }
            if (D_8F1DEE2C < 0) {
                D_8F1DEE2C = *((u8 *)state + 4) - 1;
            } else if (D_8F1DEE2C >= *((u8 *)state + 4)) {
                D_8F1DEE2C = 0;
            }
            if (D_80087200->buttonsPressed & A_BUTTON) {
                D_8F1DEE34 = 0;
                D_8F1DEE28 = D_8F1DEE2C;
                ModelAnim_SetResourceAnimation(D_8F1DECA0, &D_8F1DECA8, -1);
                ModelAnim_SetResourceAnimation(D_8F1DECA0, &D_8F1DECA8, D_8F1DEE28);
                if (D_8F1DEE24 > 0 && D_8F1DEE24 < 252) {
                    // FAKE: `^ 0` on D_8F1DEE24; diff score 135 without it.
                    func_80024974(0, D_8F1DEE24 ^ 0, D_8F1DEE28, 0, 0);
                }
            } else if (D_80087200->buttonsPressed & L_CBUTTONS) {
                D_8F1DEE34 = 1;
                D_8F1DEE28 = D_8F1DEE2C;
                ModelAnim_SetResourceAnimation(D_8F1DECA0, &D_8F1DECA8, -1);
                ModelAnim_SetResourceAnimation(D_8F1DECA0, &D_8F1DECA8, D_8F1DEE28);
            } else if (D_80087200->buttonsPressed & R_CBUTTONS) {
                D_8F1DEE34 = 2;
                D_8F1DEE28 = D_8F1DEE2C;
                ModelAnim_SetResourceAnimation(D_8F1DECA0, &D_8F1DECA8, -1);
                ModelAnim_SetResourceAnimation(D_8F1DECA0, &D_8F1DECA8, D_8F1DEE28);
            }
        }
        if (D_8F1DEE28 != -1) {
            switch (D_8F1DEE34) {
                case 1:
                    if (ModelAnim_IsFinished(&D_8F1DECA8) != 0) {
                        ModelAnim_SetResourceAnimation(D_8F1DECA0, &D_8F1DECA8, -1);
                        ModelAnim_SetResourceAnimation(D_8F1DECA0, &D_8F1DECA8, D_8F1DEE28);
                    }
                    break;

                case 2:
                    if (ModelAnim_IsFinished(&D_8F1DECA8) != 0) {
                        if (D_8F1DEE28 != 0) {
                            D_8F1DEE28 = 0;
                        } else {
                            D_8F1DEE28 = D_8F1DEE2C;
                        }
                        ModelAnim_SetResourceAnimation(D_8F1DECA0, &D_8F1DECA8, -1);
                        ModelAnim_SetResourceAnimation(D_8F1DECA0, &D_8F1DECA8, D_8F1DEE28);
                    }
                    break;
            }
        }
    }
}
#endif

#ifdef VERSION_US
extern void *D_8F1DECB4;
extern u8 D_8F1DECA8;
extern s32 D_8F1DEE38;
extern s32 D_8F1DEE3C;
extern void ModelAnim_SetEventTrack(u8 *, s32);
void func_8F102394(void) {
    void *object;
    void *temp_v0;

    object = D_8F1DECB4;
    temp_v0 = (*(void *(**)(s32, s32))((u8 *)object + 0x2C))(0, 0);
    if (*(u8 *)((u8 *)temp_v0 + 5) > 0) {
        if ((D_80087200->buttonsRepeat) & 0x200) { D_8F1DEE3C--; }
        if ((D_80087200->buttonsRepeat) & 0x100) { D_8F1DEE3C++; }
        if (D_8F1DEE3C < 0) {
            D_8F1DEE3C = *(u8 *)((u8 *)temp_v0 + 5) - 1;
        } else if (D_8F1DEE3C >= (s32)*(u8 *)((u8 *)temp_v0 + 5)) {
            D_8F1DEE3C = 0;
        }
        if ((D_80087200->buttonsPressed) & 0x8000) {
            D_8F1DEE38 = D_8F1DEE3C;
            ModelAnim_SetEventTrack(&D_8F1DECA8, -1);
            ModelAnim_SetEventTrack(&D_8F1DECA8, D_8F1DEE38);
        }
    }
}
#endif

#ifdef VERSION_US
/* mkdraft:func_8F102488 begin */
extern s32 D_8F1DECF0;
extern u16 D_8F1DEE26;
extern s32 D_8F1DEE30;
extern s8 D_8F1DEE48[];

// Fragment69PackedState (union of the four state bytes) is declared above
// func_8F101FF4 in src/fragments/69/fragment69_code.c.

extern s32 D_8F1DEE24;
extern s32 D_8F1DEE44;
extern s32 D_8F1DEE5C;
extern Unk8F101318_AnimRec *D_8F1DECA0;
extern s32 func_80041FD0(s32, u16, Fragment69PackedState, s32);
extern void func_8004BDB0(s32 arg0, s32 arg1, s16 arg2);
// The packed state reaches func_8004BE18 as a 4-byte value; the union parameter
// makes IDO copy it to the outgoing argument slot as the ROM does.
extern void func_8004BE18(s32 a, Fragment69PackedState b);


void func_8F102488(void) {
    if (D_80087200->buttonsRepeat & 0x200) {
        *(s16 *)(D_8F1DEE48 + 0) -= 0x40;
        if (*(s16 *)(D_8F1DEE48 + 0) < -0x2D00) {
            *(s16 *)(D_8F1DEE48 + 0) = 0x2CC0;
        }
    }
    if (D_80087200->buttonsRepeat & 0x100) {
        *(s16 *)(D_8F1DEE48 + 0) += 0x40;
        if (*(s16 *)(D_8F1DEE48 + 0) > 0x2D00) {
            *(s16 *)(D_8F1DEE48 + 0) = -0x2CC0;
        }
    }
    if (D_8F1DEE24 >= 0x98) {
        if (D_80087200->buttonsPressed & 2) {
            func_8004BDB0(D_8F1DEE24, 0, *(s16 *)(D_8F1DEE48 + 0) >> 6);
        }
        if (D_80087200->buttonsPressed & 1) {
            func_8004BDB0(D_8F1DEE24, 1, *(s16 *)(D_8F1DEE48 + 0) >> 6);
        }
    }
    if (D_80087200->buttonsPressed & 0x8000) {
        func_8004BE18(D_8F1DEE24, *(Fragment69PackedState *)D_8F1DEE48);
    }
    if (D_8F1DEE44 != ((Fragment69PackedState *)D_8F1DEE48)->word) {
        D_8F1DEE5C = 0;
        if (func_80041FD0(D_8F1DECA0, D_8F1DEE26,
                          *(Fragment69PackedState *)D_8F1DEE48, 0) != 0) {
            D_8F1DEE44 = ((Fragment69PackedState *)D_8F1DEE48)->word;
            D_8F1DEE30 = D_8F1DECF0;
        }
    }
}
/* mkdraft:func_8F102488 end */
#endif

#ifdef VERSION_US
extern s8 D_8F1DEE48[];
extern Unk8F101318_AnimRec *D_8F1DECA0;
extern s32 D_8F1DECF0;
extern u16 D_8F1DEE26;
extern s32 D_8F1DEE30;
extern s32 D_8F1DEE44;
extern s32 D_8F1DEE5C;
extern s32 func_80041FD0(s32, u16, Fragment69PackedState, s32);
void func_8F102618(void) {
    if (D_80087200->buttonsRepeat & 0x200) {
        D_8F1DEE48[3]--;
        if (D_8F1DEE48[3] < -8) {
            D_8F1DEE48[3] = 8;
        }
    }
    if (D_80087200->buttonsRepeat & 0x100) {
        D_8F1DEE48[3]++;
        if (D_8F1DEE48[3] >= 9) {
            D_8F1DEE48[3] = -8;
        }
    }
    if (D_8F1DEE44 != ((Fragment69PackedState *)D_8F1DEE48)->word) {
        D_8F1DEE5C = 0;
        if (func_80041FD0(D_8F1DECA0, D_8F1DEE26, *(Fragment69PackedState *)D_8F1DEE48, 0) != 0) {
            D_8F1DEE44 = ((Fragment69PackedState *)D_8F1DEE48)->word;
            D_8F1DEE30 = D_8F1DECF0;
        }
    }
}
#endif

#ifdef VERSION_US
void func_8F102708(void) {
    if (D_80087200->buttonsRepeat & 0x200) {
        D_8F1DEE48[2]--;
        if (D_8F1DEE48[2] < -8) {
            D_8F1DEE48[2] = 8;
        }
    }
    if (D_80087200->buttonsRepeat & 0x100) {
        D_8F1DEE48[2]++;
        if (D_8F1DEE48[2] >= 9) {
            D_8F1DEE48[2] = -8;
        }
    }
    if (D_8F1DEE44 != ((Fragment69PackedState *)D_8F1DEE48)->word) {
        D_8F1DEE5C = 0;
        if (func_80041FD0(D_8F1DECA0, D_8F1DEE26, *(Fragment69PackedState *)D_8F1DEE48, 0) != 0) {
            D_8F1DEE44 = ((Fragment69PackedState *)D_8F1DEE48)->word;
            D_8F1DEE30 = D_8F1DECF0;
        }
    }
}
#endif

#ifdef VERSION_US
extern void Dma_CopyChunks(s32 *, s32, s32);
s32 func_800356CC(s32);
extern u8 D_8F1DEE68;

void func_8F1027F8(void) {
    s32 temp_v0;

    temp_v0 = func_800356CC(9);
    Dma_CopyChunks(&D_8F1DEE68, temp_v0, temp_v0 + 0x408);
}
#endif

#ifdef VERSION_US
void func_8F1027F8(void);
extern void *D_80094BB0;
extern s32 D_8F1DEE60;

void func_8F10282C(void)
{
  void *temp_v0;
  if (((D_80094BB0 != NULL) && (D_8F1DEE24 >= 0x98)) && (D_8F1DEE24 < 0xFC))
  {
    temp_v0 = ((D_8F1DEE24 * 8) - 0x4C0) + (&D_8F1DEE68);
    if ((D_80087200->buttonsPressed) & 2)
    {
      D_8F1DEE60 ^= 1;
    }
    if (D_8F1DEE60 == 0)
    {
      if ((D_80087200->buttonsRepeat) & 0x200)
      {
        *((s16 *) (((u8 *) temp_v0) + 4)) = (s16) ((*((s16 *) (((u8 *) temp_v0) + 4))) - 0xA);
        if ((*((s16 *) (((u8 *) temp_v0) + 4))) < 0)
        {
          *((s16 *) (((u8 *) temp_v0) + 4)) = 0;
        }
      }
      if ((D_80087200->buttonsRepeat) & 0x100)
      {
        *((s16 *) (((u8 *) temp_v0) + 4)) = (s16) ((*((s16 *) (((u8 *) temp_v0) + 4))) + 0xA);
        if ((*((s16 *) (((u8 *) temp_v0) + 4))) >= 0xFA1)
        {
          *((s16 *) (((u8 *) temp_v0) + 4)) = 0xFA0;
        }
      }
    }
    else
    {
      if ((D_80087200->buttonsRepeat) & 0x200)
      {
        *((s16 *) (((u8 *) temp_v0) + 6)) = (s16) ((*((s16 *) (((u8 *) temp_v0) + 6))) - 0xA);
        if ((*((s16 *) (((u8 *) temp_v0) + 6))) < 0)
        {
          *((s16 *) (((u8 *) temp_v0) + 6)) = 0;
        }
      }
      if ((D_80087200->buttonsRepeat) & 0x100)
      {
        *((s16 *) (((u8 *) temp_v0) + 6)) = (s16) ((*((s16 *) (((u8 *) temp_v0) + 6))) + 0xA);
        if ((*((s16 *) (((u8 *) temp_v0) + 6))) >= 0xFA1)
        {
          *((s16 *) (((u8 *) temp_v0) + 6)) = 0xFA0;
        }
      }
    }
    if ((D_80087200->buttonsPressed) & 0x8000)
    {
      temp_v0 = temp_v0;
      func_8F1027F8();
    }
    *((s16 *) (((u8 *) D_80094BB0) + 0x1A)) = (s16) (*((s16 *) (((u8 *) temp_v0) + 4)));
    *((s16 *) (((u8 *) D_80094BB0) + 0x1C)) = (s16) (*((s16 *) (((u8 *) temp_v0) + 6)));
  }
}
#endif

#ifdef VERSION_US
extern u8 D_8F1DECA8;
void func_8F1029CC(void) {
    if ((D_80087200->buttonsRepeat) & 0x200) {
        (*(u8 *)((u8 *)(&D_8F1DECA8) + (0x1D))) = (u8) ((*(u8 *)((u8 *)(&D_8F1DECA8) + (0x1D))) - 1);
    }
    if ((D_80087200->buttonsRepeat) & 0x100) {
        (*(u8 *)((u8 *)(&D_8F1DECA8) + (0x1D))) = (u8) ((*(u8 *)((u8 *)(&D_8F1DECA8) + (0x1D))) + 1);
    }
}
#endif

#ifdef VERSION_US
void func_8F102A20(void) {
    if (D_80087200->buttonsRepeat & 0x200) {
        ((u8*)&D_8F1DECA8)[28]--;
        //!bug The byte is unsigned, so this lower clamp never executes.
        if (((u8*)&D_8F1DECA8)[28] < 0) {
            ((u8*)&D_8F1DECA8)[28] = 0;
        }
    }
    if (D_80087200->buttonsRepeat & 0x100) {
        ((u8*)&D_8F1DECA8)[28]++;
        if (((u8*)&D_8F1DECA8)[28] >= 3) {
            ((u8*)&D_8F1DECA8)[28] = 2;
        }
    }
}
#endif

#ifdef VERSION_US
extern s32 func_80041FD0(s32, u16, Fragment69PackedState, s32);
void func_8F102A98(void) {
    s32 previous;
    s32 var_a3;

    previous = D_8F1DEE5C;
    if ((D_80087200->buttonsRepeat) & 0x200) {
        D_8F1DEE5C--;
        if (D_8F1DEE5C < 0) {
            D_8F1DEE5C = 0;
        }
    }
    if ((D_80087200->buttonsRepeat) & 0x100) {
        D_8F1DEE5C++;
        if (D_8F1DEE5C >= 2) {
            D_8F1DEE5C = 1;
        }
    }
    if (previous != D_8F1DEE5C) {
        if (D_8F1DEE5C != 0) {
            var_a3 = 1;
        } else {
            var_a3 = 0;
        }
        func_80041FD0(D_8F1DECA0, D_8F1DEE26, *(Fragment69PackedState *)&D_8F1DEE44, var_a3);
    }
}
#endif

#ifdef VERSION_US
void func_8F102B48(void) {
    if ((D_80087200->buttonsRepeat) & 0x200) {
        (*(s8 *)((u8 *)(&D_8F1DECA8) + (0xA6))) = (s8) ((*(s8 *)((u8 *)(&D_8F1DECA8) + (0xA6))) - 1);
        if ((*(s8 *)((u8 *)(&D_8F1DECA8) + (0xA6))) < 0) {
            (*(s8 *)((u8 *)(&D_8F1DECA8) + (0xA6))) = 0;
        }
    }
    if ((D_80087200->buttonsRepeat) & 0x100) {
        (*(s8 *)((u8 *)(&D_8F1DECA8) + (0xA6))) = (s8) ((*(s8 *)((u8 *)(&D_8F1DECA8) + (0xA6))) + 1);
        if ((*(s8 *)((u8 *)(&D_8F1DECA8) + (0xA6))) >= 0x10) {
            (*(s8 *)((u8 *)(&D_8F1DECA8) + (0xA6))) = 0xF;
        }
    }
}
#endif

#ifdef VERSION_US
extern s32 D_8F1DEE58;
s32 func_8F102BC8(void) {
    s32 result = 0;

    if (*(u16 *)((u8 *)D_80087200 + 0xC) & 0x800) {
        D_8F1DEE58--;
        if (D_8F1DEE58 < 0) {
            D_8F1DEE58 = 11;
        }
    } else if (*(u16 *)((u8 *)D_80087200 + 0xC) & 0x400) {
        D_8F1DEE58++;
        if (D_8F1DEE58 >= 12) {
            D_8F1DEE58 = 0;
        }
    }

    switch (D_8F1DEE58) {
        case 0: func_8F101FF4(); break;
        case 1: func_8F1020A4(); break;
        case 2: func_8F102394(); break;
        case 4: func_8F102488(); break;
        case 5: func_8F102618(); break;
        case 6: func_8F102708(); break;
        case 7: func_8F10282C(); break;
        case 8: func_8F1029CC(); break;
        case 9: func_8F102A20(); break;
        case 10: func_8F102A98(); break;
        case 11: func_8F102B48(); break;
    }

    if (*(u16 *)((u8 *)D_80087200 + 8) & 0x8000) {
        if (*(u16 *)((u8 *)D_80087200 + 6) & 0x2000) {
            result = 3;
        } else {
            result = 2;
        }
    } else if (*(u16 *)((u8 *)D_80087200 + 8) & 0x4000) {
        result = 1;
    }
    return result;
}
#endif

#ifdef VERSION_US
extern s32 D_8F1DEE18;
extern s32 D_8F1DEE1C;
extern s32 D_8F1DEE20;
extern s32 func_80073420(s32);
s32 func_8F102D98(void) {
    s32 old_state;
    s32 state;

    old_state = D_8F1DEE24;
    state = func_8F100220(0);
    if (D_80087200->buttonsPressed & R_CBUTTONS) {
        D_8F1DEE18 ^= 1;
    }
    if (D_80087200->buttonsRepeat & L_JPAD) {
        D_8F1DEE1C -= 10;
    }
    if (D_80087200->buttonsRepeat & R_JPAD) {
        D_8F1DEE1C += 10;
    }
    if (D_80087200->buttonsRepeat & U_JPAD) {
        if (--D_8F1DEE20 < 0) {
            D_8F1DEE20 = 0;
            --D_8F1DEE1C;
        }
    }
    if (D_80087200->buttonsRepeat & D_JPAD) {
        if (++D_8F1DEE20 >= 10) {
            D_8F1DEE20 = 9;
            ++D_8F1DEE1C;
        }
    }
    if (D_8F1DEE1C < 0) {
        D_8F1DEE1C = 0;
    }
    if (D_8F1DEE1C >= 272) {
        D_8F1DEE1C = 271;
    }
    if (state >= 0) {
        if (D_8F1DEE18 == 0) {
            D_8F1DEE24 = D_8F1DEE1C + D_8F1DEE20;
        } else {
            D_8F1DEE24 = func_80073420((D_8F1DEE1C + D_8F1DEE20) & 0xFF);
        }
        if (D_8F1DEE24 != old_state) {
            D_8F1DEE44 = 0;
            D_8F1DEE5C = 0;
            func_80041FD0(D_8F1DECA0, (u16)D_8F1DEE24, *(Fragment69PackedState *)&D_8F1DEE44, 0);
        }
    }
    return state;
}

#endif

#ifdef VERSION_US
extern s32 func_8F100220(s32);
extern void func_8004BE50(void);
s32 func_8F102F58(void) {
    s32 var_v1;

    var_v1 = func_8F100220(1);
    if (var_v1 == 1) {
        func_8004BE50();
    }
    return var_v1;
}
#endif

#ifdef VERSION_US
extern s32 func_8F100220(s32 arg0);
// Returns the callee's value: the photo sub-screen result that state 7 of
// func_8F103478 switches on (-2/-1/0/1). func_8F100220 already leaves it in
// v0, so returning it emits the same instruction stream the void wrapper had.
s32 func_8F102F94(void) {
    return func_8F100220(2);
}
#endif

#ifdef VERSION_US
extern s8 D_8F1DEE48[];
extern u8 D_8F1DECA8;
extern u16 D_8F1DEE26;
extern s32 D_8F1DEE24;
extern s32 D_8F1DEE28;
extern s32 D_8F1DEE2C;
extern s32 D_8F1DEE34;
extern s32 D_8F1DEE38;
extern s32 D_8F1DEE3C;
extern f32 D_8F1DEE4C;
extern u8 D_8F1DEE68;
extern u8 D_8F1DECCC;
extern void *D_80094BB0;

extern void func_8003F1DC(void *);
extern void func_8003F114(u8 *, s16, s16, void *);
extern f32 func_8004B888(s32);
extern s32 func_800428F8(s32);
extern s32 func_800427B8(s32);
extern void func_8F100D58(s32, void *);





void func_8F102FB4(s32 arg0, s32 arg1) {
    s32 var_v0;
    s32 z;
    s16 *values;

    if (arg0 != 0) {
        var_v0 = func_800428F8(D_8F1DECA0);
    } else {
        var_v0 = func_800427B8(D_8F1DECA0);
    }
    if (var_v0 != 0) {
        func_8003F1DC(&D_8F1DECA8);
        func_8003F114(&D_8F1DECA8, 0, D_8F1DEE26, *(void **)(*(s32 *)(*(s32 *)((u8 *)D_8F1DECA0 + 0x38) + 8)));
        if (arg1 != 0) {
            *(s32 *)D_8F1DEE48 = 0;
            D_8F1DEE34 = 0;
            D_8F1DEE28 = 0;
            D_8F1DEE2C = 0;
            D_8F1DEE38 = 0;
            // FAKE: `z + z` (the target has no such source expression) is what
            // makes IDO schedule `or a2,zero,zero` before the D_8F1DEE3C store and
            // start the pointer-pair temps at t1 instead of t0. z is always 0 here
            // (D_8F1DEE38 was stored as 0 two statements above), so the value is
            // unchanged.
            z = D_8F1DEE38;
            D_8F1DEE3C = z + z;
            func_8003F2C4(D_8F1DECA0, &D_8F1DECA8, z);
            func_8003F3BC(&D_8F1DECA8, D_8F1DEE38);
            if (D_8F1DEE24 != 0) {
                D_8F1DEE4C = func_8004B888(D_8F1DEE24);
            } else {
                D_8F1DEE4C = 10.0f;
            }
            func_8F100D58(D_8F1DEE24, &D_8F1DECCC);
            if (D_80094BB0 != NULL) {
                if (D_8F1DEE24 >= 0x98) {
                    values = (s16 *)(((D_8F1DEE24 * 8) - 0x4C0) + (&D_8F1DEE68));
                    if ((values[2] == -1) && (values[3] == -1)) {
                        values[2] = *((s16 *)(((u8 *)D_80094BB0) + 0x1A));
                        values[3] = *((s16 *)(((u8 *)D_80094BB0) + 0x1C));
                    }
                }
            }
        } else {
            D_8F1DEE28 = -1;
            func_8003F2C4(D_8F1DECA0, &D_8F1DECA8, D_8F1DEE28);
            D_8F1DEE38 = -1;
            func_8003F3BC(&D_8F1DECA8, D_8F1DEE38);
        }
    }
}
#endif

#ifdef VERSION_US
#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/69/fragment69_code/func_8F103194.s")
#endif

#ifdef VERSION_US
/* mkdraft:func_8F103478 begin */
extern u8 StageContext_GetFadeMode(void);
extern void StageFade_StartFromTransparent(s32);
extern s32 func_8F102BC8(void);
extern s32 func_8F10018C(s32);
extern void func_8F100274(s32);
extern s32 func_8F1001D0(s32);
extern s32 func_8F102D98(void);
extern s32 func_8F102F58(void);
extern s32 func_8F102F94(void);
extern s32 func_8F103194(void);
extern s32 func_80041FD0(s32, u16, Fragment69PackedState, s32);
extern s32 D_8F1DEE24;
extern s32 D_8F1DEE28;
extern s32 D_8F1DEE44;
extern s32 D_8F1DEE58;
extern s32 D_8F1DEE5C;
extern Unk8F101318_AnimRec *D_8F1DECA0;
extern s32 D_8F1039A4;
extern s32 D_8F1039A8;
extern s32 D_8F1039AC;
extern s32 D_8F1039B0;
extern s32 D_8F1039B4;
extern s32 D_8F1039B8;
extern s32 D_8F1039BC;
extern s32 D_8F1039C0;
// One step of the main-menu state machine: returns the state to run next, and the
// caller loops until it reports 8 (the state that leaves the menu). States 0 and 6
// wait for the stage fade, 1 handles a menu input result, 5 arms a fixed camera
// position, and 3, 4 and 7 wait on the sub-screens before falling back to state 1.
//@src/fragments/69/fragment69_code.c


s32 func_8F103478(s32 arg0) {
    s32 result = arg0;
    s32 temp_v0;

    switch (arg0) {
        case 0:
            if (StageContext_GetFadeMode() == 0) {
                result = 1;
            }
            break;
        case 1:
            switch (func_8F102BC8()) {
                case 1:
                    if (func_8F10018C(2) != 0) {
                        result = 7;
                        func_8F100274(2);
                    }
                    break;
                case 2:
                    switch (D_8F1DEE58) {
                        case 0:
                            if (func_8F10018C(0) != 0) {
                                result = 3;
                            }
                            break;
                        case 3:
                            // Clears the pending camera/anim state before showing the
                            // fixed-position view; the 5 is the state that arms it.
                            D_8F1DEE24 = 0;
                            D_8F1DEE28 = 0;
                            D_8F1039A4 = 0;
                            D_8F1039B4 = 0;
                            D_8F1039B8 = 0;
                            D_8F1039A8 = 0;
                            D_8F1039AC = 0;
                            D_8F1039B0 = 0;
                            D_8F1039BC = 0;
                            result = 5;
                            D_8F1039C0 = 0;
                            break;
                    }
                    break;
                case 3:
                    if (func_8F10018C(1) != 0) {
                        result = 4;
                    }
                    break;
            }
            break;
        case 3:
            if (func_8F102D98() != -2) {
                if (func_8F1001D0(0) != 0) {
                    result = 1;
                }
            }
            break;
        case 4:
            if (func_8F102F58() != -2) {
                if (func_8F1001D0(1) != 0) {
                    result = 1;
                }
            }
            break;
        case 5:
            if (func_8F103194() != 0) {
                result = 1;
                D_8F1DEE24 = 0x97;
                D_8F1DEE44 = 0;
                D_8F1DEE5C = 0;
                // FAKE: argument 2 is the u16 D_8F1DEE26 (0x8F1DEE26), but it is
                // reached off the D_8F1DEE24 base so the address folds into the
                // base register the 0x97 store already loaded; naming D_8F1DEE26
                // scores 1130.
                func_80041FD0(D_8F1DECA0, *(u16 *)((u8 *)&D_8F1DEE24 + 2), *(Fragment69PackedState *)&D_8F1DEE44, 0);
            }
            break;
        case 7:
            temp_v0 = func_8F102F94();
            if (temp_v0 != -2) {
                switch (temp_v0) {
                    case 1:
                        result = 6;
                        StageFade_StartFromTransparent(5);
                        break;
                    case -1:
                    case 0:
                        if (func_8F1001D0(2) != 0) {
                            result = 1;
                        }
                        break;
                }
            }
            break;
        case 6:
            if (StageContext_GetFadeMode() == 1) {
                result = 8;
            }
            break;
    }
    return result;
}
/* mkdraft:func_8F103478 end */
#endif

#ifdef VERSION_US
extern void func_800086A4(s32);
extern void StageFade_StartFromOpaque(s32);
extern void func_80064D28(void);
extern void func_8F102FB4(s32, s32);
extern void func_8F101DA0(void);
extern s32 func_8F103478(s32);
extern s32 D_8F1DEE58;
extern void func_8F1003EC(void);
extern void func_8F101CDC(void);
void func_8F1036F4(void) {
    s32 var_a1;
    s32 temp_v0;
    s32 var_s0;

    var_s0 = 0;
    func_800086A4(2);
    StageFade_StartFromOpaque(5);
    do {
        func_80064D28();
        if ((4 != D_8F1DEE58) && (5 != D_8F1DEE58) && (6 != D_8F1DEE58)) {
            var_a1 = 1;
        } else {
            var_a1 = 0;
        }
        func_8F102FB4(0, var_a1);
        func_8F1003EC();
        func_8F101DA0();
        func_8F101CDC();
        temp_v0 = func_8F103478(var_s0);
        var_s0 = temp_v0;
    } while (temp_v0 != 8);
}
#endif

#ifdef VERSION_US
extern u8 D_1000000[];
extern u8 D_446E30[];
extern u8 D_447D00[];
extern u8 D_8F104D20[];
s32 func_8F1037C4(s32 arg0, s32 arg1) {
    s32 sp34;
    u8 *var_s1;
    s32 var_s0;

    main_pool_push_state(0x4D444C56); // 'MDLV'
    Gfx_InitDisplayListBuffers(0x10000, 0);
    sp34 = func_800082E0(0, 1, 3, 1, 2, 1);
    func_8004C09C(11);
    func_8004C8C0(51);
    func_8004C8C0(50);
    var_s1 = D_8F104D20;
    var_s0 = 1;
    do {
        func_8004D878(var_s1, var_s0, 0);
        var_s0++;
        var_s1 += 0xC80;
    } while (var_s0 != 280);
    func_80047588(63, 0);
    Asset_LoadToSegment(((u32)D_1000000 & 0x0F000000) >> 24, D_446E30, D_447D00, 0);
    func_8F100E78();
    func_80008514(sp34);
    func_8F1036F4();
    func_80008574();
    func_80047610();
    func_8004C398();
    Gfx_FreeDisplayListBuffers();
    main_pool_pop_state(0x4D444C56); // 'MDLV'
    return 0;
}
#endif
