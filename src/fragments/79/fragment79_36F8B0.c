#include "global.h"


#ifdef VERSION_US
void func_84100020(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x14) |= arg1;
}

void func_84100030(u8 *arg0, u32 arg1) {
    *(u32 *)(arg0 + 0x14) &= ~arg1;
}

void func_84100044(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x14) ^= arg1;
}

s32 func_84100054(u8 *arg0, s32 arg1) {
    s32 result = 0;
    if (*(s32 *)(arg0 + 0x14) & arg1) {
        result = 1;
    }
    return result;
}

s32 func_84100074(u8 *arg0, s32 arg1) {
    s32 result = 0;
    if ((*(s32 *)(arg0 + 0x14) & arg1) == 0) {
        result = 1;
    }
    return result;
}

void func_84100094(u8 *arg0) {
    arg0[0x92] = 0;
}

extern s32 func_84100054(u8 *arg0, s32 arg1);
extern s32 func_84100074(u8 *arg0, s32 arg1);
s32 func_8410009C(u8 *arg0) {
    s32 result;

    result = 0;
    if (arg0[0x92] == 0) {
        result = 1;
    }
    if (arg0[0x7F] == 0xFF) {
        if (func_84100074(arg0, 1) != 0) {
            result = 1;
        }
    }
    if ((func_84100054(arg0, 0x20000) != 0) && (*(f32 *)(arg0 + 0x24) <= 0.0f)) {
        result = 1;
    }
    return result;
}

extern u8 *D_8418C950;
extern s32 D_8418C954;
extern u8 *main_pool_alloc(s32 arg0, s32 arg1);
void func_84100134(void) {
    D_8418C950 = main_pool_alloc(0xB6D0, 0);
    _bzero(D_8418C950, 0xB6D0);
    D_8418C954 = 0;
}

// Resets a 0x9C-byte record that func_84100260 has just claimed from the pool at D_8418C950:
// clears its fields, sets the bytes at 0x83-0x88 and 0x8B-0x8F to 0xFF and the floats at 0x18
// and 0x1C to 1.0f, and sets byte 0x92, which func_84100094 clears and func_8410009C tests.
void func_84100174(u8 *arg0) {
    s32 value;

    *(s16 *)(arg0 + 0x6E) = 0;
    *(f32 *)(arg0 + 0x4C) = 0.0f;
    // FAKE: the do-while (0) wrapper; diff score 505 without it.
    do {
        // FAKE: the first two statements share a line; diff score 390 without it.
        value = *(s16 *)(arg0 + 0x6E); *(f32 *)(arg0 + 0x48) = *(f32 *)(arg0 + 0x4C);
        *(f32 *)(arg0 + 0x44) = *(f32 *)(arg0 + 0x4C);
        *(s16 *)(arg0 + 0x74) = 0;
        *(s16 *)(arg0 + 0x6C) = value;
        *(s16 *)(arg0 + 0x6A) = value;
        value = *(s16 *)(arg0 + 0x74);
        arg0[0x92] = 1;
        arg0[0x95] = 0;
        *(u32 *)(arg0 + 0x8) = 0;
        *(u32 *)(arg0 + 0xC) = 0;
        *(u32 *)(arg0 + 0x0) = 0;
        *(u32 *)(arg0 + 0x4) = 0;
        *(u32 *)(arg0 + 0x14) = 0;
        *(s16 *)(arg0 + 0x60) = 0;
        *(s16 *)(arg0 + 0x66) = 0;
        arg0[0x7F] = 0;
        arg0[0x80] = 0;
    } while (0);
    arg0[0x81] = 0;
    arg0[0x82] = 0;
    arg0[0x83] = 0xFF;
    arg0[0x87] = 0xFF;
    arg0[0x86] = 0xFF;
    arg0[0x85] = 0xFF;
    arg0[0x84] = 0xFF;
    arg0[0x8E] = 0xFF;
    arg0[0x8D] = 0xFF;
    arg0[0x8C] = 0xFF;
    arg0[0x8B] = 0xFF;
    arg0[0x88] = 0xFF;
    arg0[0x89] = 0;
    arg0[0x8F] = 0xFF;
    arg0[0x90] = 0;
    *(f32 *)(arg0 + 0x28) = 0.0f;
    *(f32 *)(arg0 + 0x24) = 0.0f;
    *(f32 *)(arg0 + 0x20) = 0.0f;
    *(f32 *)(arg0 + 0x34) = 0.0f;
    *(f32 *)(arg0 + 0x30) = 0.0f;
    *(f32 *)(arg0 + 0x2C) = 0.0f;
    *(f32 *)(arg0 + 0x40) = 0.0f;
    *(f32 *)(arg0 + 0x3C) = 0.0f;
    *(f32 *)(arg0 + 0x38) = 0.0f;
    *(f32 *)(arg0 + 0x58) = 0.0f;
    *(f32 *)(arg0 + 0x54) = 0.0f;
    *(f32 *)(arg0 + 0x50) = 0.0f;
    *(f32 *)(arg0 + 0x5C) = 0.0f;
    *(s16 *)(arg0 + 0x72) = value;
    *(s16 *)(arg0 + 0x70) = value;
    *(f32 *)(arg0 + 0x18) = 1.0f;
    *(f32 *)(arg0 + 0x1C) = 1.0f;
}

extern void func_84100174(u8 *arg0);
extern u8 *D_8418C950;
extern s32 D_8418C954;

u8 *func_84100260(void) {
    s32 var_v1;
    s32 var_v0;
    u8 *var_a0_2;

    var_v0 = D_8418C954;
    var_v1 = 0;
    var_a0_2 = D_8418C950 + var_v0 * 0x9C;
loop_1:
    if (*(s8 *)(var_a0_2 + 0x98) != 0) {
        var_v0 += 1;
        var_v1 += 1;
        if (var_v0 >= 300) {
            var_v0 = 0;
            var_a0_2 = D_8418C950;
        } else {
            var_a0_2 += 0x9C;
        }
        if (var_v1 != 300) {
            goto loop_1;
        }
    }
    if (var_v1 == 300) {
        var_a0_2 = NULL;
    } else {
        *(s8 *)(var_a0_2 + 0x98) = 1;
        func_84100174(var_a0_2);
        D_8418C954 = var_v0 + 1;
        if (D_8418C954 >= 300) {
            D_8418C954 = 0;
        }
    }
    return var_a0_2;
}
extern u8 *func_84100260(void);
u8 *func_84100328(void) {
    return func_84100260();
}

void func_84100348(u8 *arg0) {
    arg0[0x92] = 0;
}

void func_84100350(u8 *arg0) {
    u8 *next;
    u8 *prev;
    *(u32 *)(arg0 + 0x14) = 0;
    func_84100348(arg0);
    next = *(u8 **)(arg0 + 0x4);
    if (next != NULL) {
        *(u8 **)(next + 0x0) = *(u8 **)(arg0 + 0x0);
    }
    prev = *(u8 **)(arg0 + 0x0);
    if (prev != NULL) {
        *(u8 **)(prev + 0x4) = *(u8 **)(arg0 + 0x4);
    }
    *(u32 *)(arg0 + 0x4) = 0;
    *(u32 *)(arg0 + 0x0) = 0;
    arg0[0x98] = 0;
}

/* mkdraft:func_841003AC begin */
extern void Audio_SetChannelGroupCounts(u8 arg0, u8 arg1, u8 arg2, u8 arg3);
extern void func_84100350(u8 *arg0);
extern void func_84104818(s32 arg0);
extern s32 func_8411E188(s8 arg0);
extern u8 *D_8418C950;
extern u8 D_84190218[];
extern s32 D_84193DD0;

// Per-frame particle-system update: picks the audio channel group when the sound state byte at
// D_84193DD0+8 is one of 0x27/0x2B/0x86/0xB8, silences the 9 channel bytes of D_84190218, and then
// walks the 300 0x9C-byte records func_84100260 claims from D_8418C950, freeing (func_84104818) the
// object at 0xC and ticking (func_84100350) each active record that is not muted by its flags.


void func_841003AC(s32 arg0) {
    s32 flag;
    s32 i;
    u8 *record;
    s32 handle1;
    s32 handle2;

    record = D_8418C950;
    switch (((u8 *)D_84193DD0)[8]) {
        case 0x27:
            arg0 = 1;
            break;
        case 0x2B:
            arg0 = 1;
            break;
        case 0x86:
            arg0 = 1;
            break;
        case 0xB8:
            arg0 = 1;
            break;
    }

    D_84190218[0] = 0xFF;
    D_84190218[1] = 0xFF;
    D_84190218[2] = 0xFF;
    D_84190218[4] = 0xFF;
    D_84190218[5] = 0xFF;
    D_84190218[6] = 0xFF;
    D_84190218[8] = 0xFF;
    D_84190218[9] = 0xFF;
    D_84190218[10] = 0xFF;

    if (arg0 == 1) {
        handle1 = func_8411E188(0);
        handle2 = func_8411E188(1);
        Audio_SetChannelGroupCounts(0xFF, 0xFF, 0xFF, 0);
        func_8003F454(handle1, 0xFF, 0xFF, 0xFF, 0);
        func_8003F454(handle2, 0xFF, 0xFF, 0xFF, 0);
        func_8003F4DC((u8 *)handle1, 0xFF);
        func_8003F4DC((u8 *)handle2, 0xFF);
    }

    for (i = 0; i < 300; i++, record += 0x9C) {
        if (*(s8 *)(record + 0x98) != 0) {
            flag = 1;
            // else-if, not a second `if`: the then-branch jumps past the flag&0x10000 test.
            if ((*(u32 *)(record + 0x14) & 1) && (arg0 == 0)) {
                flag = 0;
            } else if (*(u32 *)(record + 0x14) & 0x10000) {
                flag = 0;
            }
            if (flag != 0) {
                if (*(s32 *)(record + 0xC) != 0) {
                    func_84104818(*(s32 *)(record + 0xC));
                }
                func_84100350(record);
            }
        }
    }
}
/* mkdraft:func_841003AC end */

typedef struct Func8410056CParticleS8 {
    u8 pad[0x98];
    s8 active;
    u8 tail[3];
} Func8410056CParticleS8;
s32 Particle_CountActive(void) {
    s32 i;
    s32 var_v1 = 0;
    Func8410056CParticleS8 *ptr = (Func8410056CParticleS8 *)D_8418C950;
    for (i = 0; i < 0x12C; i++, ptr++) {
        if (ptr->active != 0) {
            var_v1++;
        }
    }
    return var_v1;
}

s16 func_841005E0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4)
{
  f32 temp_fa0;
  f32 temp_fv0;
  f32 new_var;
  f32 new_var2;
  f32 temp_fv1;
  new_var = (f32) arg2;
  temp_fv1 = (f32) arg0;
  new_var2 = (f32) arg4;
  temp_fa0 = new_var2;
 do { if (temp_fv1 == temp_fa0) { return arg2; } } while (0);
  temp_fv0 = new_var;
  return (s16) ((s32) ((((((f32) arg3) - new_var) / (((f32) arg1) - temp_fv1)) * (temp_fa0 - temp_fv1)) + temp_fv0));
}
typedef struct {
    u8 pad_00[1];
    u8 mode;
    u8 divisor;
    u8 count;
    s16 *values;
} Func84100688Table;

s16 func_84100688(Func84100688Table *arg0, u32 arg1) {
    s32 i;

    if (arg0->mode == 0) {
        arg1 %= arg0->divisor;
    }
    for (i = 0; i < arg0->count - 1; i++) {
        if (arg1 >= (u32)arg0->values[i] && arg1 < (u32)arg0->values[i + 1]) {
            return (s16)i;
        }
    }
    return arg0->count - 1;
}

extern s16 func_841005E0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
u8 *func_84100710(u8 *out, Func84100688Table **anim, s32 time) {
    s16 index;
    Func84100688Table *table;
    s16 *frames;

    index = func_84100688(anim[0], time);
    table = anim[0];
    frames = table->values;
    if (index + 1 == table->count) {
        out[0] = ((u8 **)anim)[1][index * 4 + 0];
        out[1] = ((u8 **)anim)[1][index * 4 + 1];
        out[2] = ((u8 **)anim)[1][index * 4 + 2];
        out[3] = ((u8 **)anim)[1][index * 4 + 3];
    } else {
        out[0] = func_841005E0(*(s16 *)(index * 2 + (u8 *)frames), *(s16 *)(index * 2 + (u8 *)frames + 2),
                               ((u8 **)anim)[1][index * 4 + 0], ((u8 **)anim)[1][index * 4 + 4], time);
        out[1] = func_841005E0(*(s16 *)(index * 2 + (u8 *)frames), *(s16 *)(index * 2 + (u8 *)frames + 2),
                               ((u8 **)anim)[1][index * 4 + 1], ((u8 **)anim)[1][index * 4 + 5], time);
        out[2] = func_841005E0(*(s16 *)(index * 2 + (u8 *)frames), *(s16 *)(index * 2 + (u8 *)frames + 2),
                               ((u8 **)anim)[1][index * 4 + 2], ((u8 **)anim)[1][index * 4 + 6], time);
        out[3] = func_841005E0(*(s16 *)(index * 2 + (u8 *)frames), *(s16 *)(index * 2 + (u8 *)frames + 2),
                               ((u8 **)anim)[1][index * 4 + 3], ((u8 **)anim)[1][index * 4 + 7], time);
    }
    return out;
}

extern s16 func_841005E0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
u8 *func_84100874(u8 *out, Func84100688Table **anim, s32 time) {
    s16 index;
    Func84100688Table *table;
    s16 *frames;

    index = func_84100688(anim[0], time);
    table = anim[0];
    frames = table->values;
    if (index + 1 == table->count) {
        out[0] = ((u8 **)anim)[1][index * 4 + 0];
        out[1] = ((u8 **)anim)[1][index * 4 + 1];
        out[2] = ((u8 **)anim)[1][index * 4 + 2];
        out[3] = ((u8 **)anim)[1][index * 4 + 3];
    } else {
        out[0] = func_841005E0(*(s16 *)(index * 2 + (u8 *)frames), *(s16 *)(index * 2 + (u8 *)frames + 2),
                               ((u8 **)anim)[1][index * 4 + 0], ((u8 **)anim)[1][index * 4 + 4], time);
        out[1] = func_841005E0(*(s16 *)(index * 2 + (u8 *)frames), *(s16 *)(index * 2 + (u8 *)frames + 2),
                               ((u8 **)anim)[1][index * 4 + 1], ((u8 **)anim)[1][index * 4 + 5], time);
        out[2] = func_841005E0(*(s16 *)(index * 2 + (u8 *)frames), *(s16 *)(index * 2 + (u8 *)frames + 2),
                               ((u8 **)anim)[1][index * 4 + 2], ((u8 **)anim)[1][index * 4 + 6], time);
        out[3] = func_841005E0(*(s16 *)(index * 2 + (u8 *)frames), *(s16 *)(index * 2 + (u8 *)frames + 2),
                               ((u8 **)anim)[1][index * 4 + 3], ((u8 **)anim)[1][index * 4 + 7], time);
    }
    return out;
}

extern s16 func_841005E0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
u8 *func_841009D8(u8 *out, Func84100688Table **anim, s32 time) {
    s16 index;
    Func84100688Table *table;
    s16 *frames;

    index = func_84100688(anim[0], time);
    table = anim[0];
    frames = table->values;
    if (index + 1 == table->count) {
        out[0] = ((u8 **)anim)[2][index * 4 + 0];
        out[1] = ((u8 **)anim)[2][index * 4 + 1];
        out[2] = ((u8 **)anim)[2][index * 4 + 2];
        out[3] = ((u8 **)anim)[2][index * 4 + 3];
    } else {
        out[0] = func_841005E0(*(s16 *)(index * 2 + (u8 *)frames), *(s16 *)(index * 2 + (u8 *)frames + 2),
                               ((u8 **)anim)[2][index * 4 + 0], ((u8 **)anim)[2][index * 4 + 4], time);
        out[1] = func_841005E0(*(s16 *)(index * 2 + (u8 *)frames), *(s16 *)(index * 2 + (u8 *)frames + 2),
                               ((u8 **)anim)[2][index * 4 + 1], ((u8 **)anim)[2][index * 4 + 5], time);
        out[2] = func_841005E0(*(s16 *)(index * 2 + (u8 *)frames), *(s16 *)(index * 2 + (u8 *)frames + 2),
                               ((u8 **)anim)[2][index * 4 + 2], ((u8 **)anim)[2][index * 4 + 6], time);
        out[3] = func_841005E0(*(s16 *)(index * 2 + (u8 *)frames), *(s16 *)(index * 2 + (u8 *)frames + 2),
                               ((u8 **)anim)[2][index * 4 + 3], ((u8 **)anim)[2][index * 4 + 7], time);
    }
    return out;
}

extern void func_84100094(u8 *arg0);
extern u8 *func_84100710(u8 *out, Func84100688Table **anim, s32 time);
extern void Audio_SetChannelGroupCounts(u8, u8, u8, u8);

typedef struct {
    Func84100688Table *table;
    u8 *frames;
} Anim84100B3C;



void func_84100B3C(u8 *arg0) {
    u32 mode;
    u8 *result;
    u8 buffer[4];
    Anim84100B3C *anim_set;
    u32 count;
    u32 frame;
    Func84100688Table *table;

    count = arg0[0x7F];
    result = NULL;
    if (*(Anim84100B3C **)(*(u8 **)(arg0 + 0x10) + 4) != NULL) {
        anim_set = *(Anim84100B3C **)(*(u8 **)(arg0 + 0x10) + 4);
        table = anim_set->table;
        if (table != NULL) {
            mode = table->pad_00[0];
            frame = count % table->divisor;
            if (table->divisor == arg0[0x7F]) {
                func_84100094(arg0);
            } else if (anim_set->frames != NULL) {
                if (mode == 0) {
                    result = anim_set->frames + frame * 4;
                } else if (table->pad_00[0] == 1) {
                    result = func_84100710(buffer, (Func84100688Table **)anim_set, frame);
                }
            }
        } else {
            result = anim_set->frames;
        }
        if (result != NULL) {
            if (arg0[0x7C] == 2) {
                Audio_SetChannelGroupCounts(result[0], result[1], result[2], result[3]);
            } else {
                arg0[0x8B] = result[0];
                arg0[0x8C] = result[1];
                arg0[0x8D] = result[2];
                arg0[0x8E] = result[3];
            }
        }
    }
}

extern s32 D_84190194;



void func_84100C68(u8 *arg0) {
    u32 frame;
    u8 *state;
    Func84100688Table **anim;
    Func84100688Table *table;
    u32 index;
    s32 mode;
    u8 primBuf[4];
    u8 *prim;
    u8 envBuf[4];
    u8 *env;
    u8 *primTrack;
    u8 *envTrack;

    frame = arg0[0x7F];
    state = *(u8 **)(arg0 + 0x10);
    if (*(Func84100688Table ***)(state + 4) != NULL) {
        anim = *(Func84100688Table ***)(state + 4);
        if (*(u16 *)(state + 2) != 0 && frame == *(u16 *)(state + 2)) {
            func_84100020(arg0, 0x280);
        }
        table = anim[0];
        if (frame == table->divisor) {
            func_84100094(arg0);
            return;
        }
        index = frame % table->divisor;
        mode = table->pad_00[0];
        primTrack = (u8 *)anim[1];
        if (primTrack != NULL) {
            if (mode == 0) {
                prim = (u8 *)((u32)primTrack + index * 4);
            } else if (table->pad_00[0] == 1) {
                prim = func_84100874(primBuf, anim, index);
            }
            func_8003F454(D_84190194, prim[0], prim[1], prim[2], prim[3]);
        }
        envTrack = (u8 *)anim[2];
        if (envTrack != NULL) {
            if (mode == 0) {
                env = (u8 *)((u32)envTrack + index * 4);
            } else if (anim[0]->pad_00[0] == 1) {
                env = func_841009D8(envBuf, anim, index);
            }
            func_8003F4DC(D_84190194, env[3]);
        }
    }
}

/* mkdraft:func_84100DE4 begin */
extern void func_84100020(u8 *arg0, s32 arg1);
extern void func_84100094(u8 *arg0);
extern u8 *func_84100710(u8 *out, Func84100688Table **anim, s32 time);
extern u8 D_84190218[];

// Copies the first three bytes of each active layer's colour entry into
// D_84190218: layer 0 into bytes 0-2, layer 1 into bytes 4-6, layer 2 into
// bytes 8-10. The entry is looked up by the frame time against the layer's
// count and mode byte, and a layer whose count is already exhausted uses its
// last entry and leaves `ended` set.


void func_84100DE4(u8 *arg0) {
    u16 end_time;
    // Declared second so the retail stack slots line up: end_time 0x5C,
    // index 0x58, ended 0x54, time 0x50, type 0x4C, layer0 0x48, ...,
    // color2 0x28. Only end_time, index and type stay in registers.
    s32 index;
    s32 ended;
    u32 time;
    s32 type;
    u8 *layer0;
    u8 *layer1;
    u8 *layer2;
    u8 buf0[4];
    u8 *color0;
    u8 buf1[4];
    u8 *color1;
    u8 buf2[4];
    u8 *color2;

    ended = 1;
    time = arg0[0x7F];
    layer0 = *(u8 **)(*(u8 **)(arg0 + 0x10) + 4);
    layer1 = *(u8 **)(*(u8 **)(arg0 + 0x10) + 8);
    layer2 = *(u8 **)(*(u8 **)(arg0 + 0x10) + 0xC);
    end_time = *(u16 *)(*(u8 **)(arg0 + 0x10) + 2);
    if (end_time != 0 && time == end_time) {
        func_84100020(arg0, 0x280);
    }

    if (layer0 != NULL) {
        type = (*(u8 **)(layer0 + 0))[0];
        if (time > (*(u8 **)(layer0 + 0))[2] - 1) {
            index = (*(u8 **)(layer0 + 0))[2] - 1;
        } else {
            index = time % (*(u8 **)(layer0 + 0))[2];
            ended = 0;
        }
        if (*(u8 **)(layer0 + 4) != NULL) {
            if (type == 0) {
                color0 = *(u8 **)(layer0 + 4) + index * 4;
            } else if ((*(u8 **)(layer0 + 0))[0] == 1) {
                color0 = func_84100710(buf0, (Func84100688Table **)layer0, index);
            }
            D_84190218[0] = color0[0];
            D_84190218[1] = color0[1];
            D_84190218[2] = color0[2];
        }
    }
    if (layer1 != NULL) {
        type = (*(u8 **)(layer1 + 0))[0];
        if (time > (*(u8 **)(layer1 + 0))[2] - 1) {
            index = (*(u8 **)(layer1 + 0))[2] - 1;
        } else {
            index = time % (*(u8 **)(layer1 + 0))[2];
            ended = 0;
        }
        if (*(u8 **)(layer1 + 4) != NULL) {
            if (type == 0) {
                color1 = *(u8 **)(layer1 + 4) + index * 4;
            } else if ((*(u8 **)(layer1 + 0))[0] == 1) {
                color1 = func_84100710(buf1, (Func84100688Table **)layer1, index);
            }
            D_84190218[4] = color1[0];
            D_84190218[5] = color1[1];
            D_84190218[6] = color1[2];
        }
    }
    if (layer2 != NULL) {
        type = (*(u8 **)(layer2 + 0))[0];
        if (time > (*(u8 **)(layer2 + 0))[2] - 1) {
            index = (*(u8 **)(layer2 + 0))[2] - 1;
        } else {
            index = time % (*(u8 **)(layer2 + 0))[2];
            ended = 0;
        }
        if (*(u8 **)(layer2 + 4) != NULL) {
            if (type == 0) {
                color2 = *(u8 **)(layer2 + 4) + index * 4;
            } else if ((*(u8 **)(layer2 + 0))[0] == 1) {
                color2 = func_84100710(buf2, (Func84100688Table **)layer2, index);
            }
            D_84190218[8] = color2[0];
            D_84190218[9] = color2[1];
            D_84190218[10] = color2[2];
        }
    }
    if (ended != 0) {
        func_84100094(arg0);
    }
}
/* mkdraft:func_84100DE4 end */

extern s16 func_841005E0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
void func_84101084(Func84100688Table **arg0, u8 *arg1) {
    Func84100688Table *table;
    s16 index;
    s16 *frames;

    table = arg0[0];
    if (table == NULL) {
        *(s16 *)(arg1 + 0x66) = ((s16 **)arg0)[1][0];
        return;
    }
    if (table->pad_00[0] == 0) {
        *(s16 *)(arg1 + 0x66) = ((s16 **)arg0)[1][arg1[0x7F] % table->divisor];
        return;
    }
    index = func_84100688(table, arg1[0x7F]);
    table = arg0[0];
    frames = table->values;
    if (index + 1 == table->divisor) {
        *(s16 *)(arg1 + 0x66) = ((s16 **)arg0)[1][index];
        return;
    }
    *(s16 *)(arg1 + 0x66) = func_841005E0(*(s16 *)(index * 2 + (u8 *)frames), *(s16 *)(index * 2 + (u8 *)frames + 2),
                                          ((s16 **)arg0)[1][index], ((s16 **)arg0)[1][index + 1], arg1[0x7F]);
}

extern s32 ParticleMath_RandomRange(s32 arg0);

// Advances the scalar at arg0 + 0x5C from one of two descriptors hanging off arg1.
// arg1 + 4: six s16 fields; +0x00 selects the block (0), +0x02 is the frame at which
// it starts (arg0[0x7F]), +0x04 sets the base value, +0x0A jitters it, and +0x06/+0x08
// are the target and step of the move toward the target. arg1 + 8: a
// { Func84100688Table *, s16 * } pair whose index comes from arg0[0x7F]; the value is
// either the table entry itself or a func_841005E0 interpolation of the s16 pair, then
// scaled by arg0[0x64]. All 0.01f factors convert hundredths to a fraction.


void func_8410119C(u8 *arg0, u8 *arg1) {
    s16 index;
    Func84100688Table *table;
    s16 *frames;

    if (arg1 == NULL) {
        return;
    }
    if (*(u32 *)(arg1 + 4) != NULL) {
        if (*(s16 *)(*(u32 *)(arg1 + 4) + 0) == 0 && *(s16 *)(*(u32 *)(arg1 + 4) + 2) == arg0[127]) {
            *(f32 *)(arg0 + 0x5C) = *(s16 *)(*(u32 *)(arg1 + 4) + 4) * 0.01f;
            if (*(s16 *)(*(u32 *)(arg1 + 4) + 0xA) != 0) {
                s32 range = *(s16 *)(*(u32 *)(arg1 + 4) + 0xA);
                *(f32 *)(arg0 + 0x5C) += 0.01f * (u32)ParticleMath_RandomRange(range);
            }
        }
        if (*(s16 *)(*(u32 *)(arg1 + 4) + 2) < arg0[127] && *(s16 *)(*(u32 *)(arg1 + 4) + 8) != 0) {
            f32 target = *(s16 *)(*(u32 *)(arg1 + 4) + 6) * 0.01f;
            f32 step = *(s16 *)(*(u32 *)(arg1 + 4) + 8) * 0.01f;
            if (*(f32 *)(arg0 + 0x5C) < target) {
                *(f32 *)(arg0 + 0x5C) += step;
                if (target < *(f32 *)(arg0 + 0x5C)) {
                    *(f32 *)(arg0 + 0x5C) = target;
                }
            } else {
                *(f32 *)(arg0 + 0x5C) -= step;
                if (*(f32 *)(arg0 + 0x5C) < target) {
                    *(f32 *)(arg0 + 0x5C) = target;
                }
            }
        }
        return;
    }
    if (*(u32 *)(arg1 + 8) != NULL) {
        index = func_84100688(*(Func84100688Table **)(*(u32 *)(arg1 + 8)), arg0[127]);
        table = *(Func84100688Table **)(*(u32 *)(arg1 + 8));
        frames = table->values;
        if (index + 1 == table->count) {
            *(f32 *)(arg0 + 0x5C) = *(s16 *)(*(u32 *)(*(u32 *)(arg1 + 8) + 4) + index * 2) * 0.01f;
        } else {
            *(f32 *)(arg0 + 0x5C) = func_841005E0(
                *(s16 *)(index * 2 + (u8 *)frames), *(s16 *)(index * 2 + (u8 *)frames + 2),
                *(s16 *)(*(u32 *)(*(u32 *)(arg1 + 8) + 4) + index * 2),
                *(s16 *)(*(u32 *)(*(u32 *)(arg1 + 8) + 4) + index * 2 + 2),
                arg0[127]) * 0.01f;
        }
        *(f32 *)(arg0 + 0x5C) *= *(u16 *)(arg0 + 0x64) * 0.01f;
    }
}

typedef struct ParticleVec3f {
    f32 x, y, z;
} ParticleVec3f;
typedef struct ParticleVec3s {
    s16 x, y, z;
} ParticleVec3s;
extern ParticleVec3f *ParticleMath_RotateVec3fY(ParticleVec3f *, ParticleVec3f, ParticleVec3s);
extern f32 D_80087E50[];
extern f32 D_80088E50[];
extern u32 func_8411E358(s32 arg0, s32 arg1);
extern u32 func_8411EE54(u8 *arg0);
extern s32 func_84100074(u8 *arg0, s32 arg1);



void func_841013F4(u8 *arg0, s16 arg1) {
    ParticleVec3f velocity;
    ParticleVec3f rotated;
    ParticleVec3s angles;
    f32 scale;
    void *obj;

    obj = *(void **)(arg0 + 0x10);
    velocity.x = 0.0f;
    velocity.y = 0.0f;
    velocity.z = *(f32 *)(arg0 + 0x5C);
    rotated.x = 0.0f;
    rotated.y = 0.0f;
    rotated.z = 0.0f;
    angles.x = *(s16 *)(D_84190194 + 0x1E);
    angles.y = *(s16 *)(D_84190194 + 0x20);
    angles.z = *(s16 *)(D_84190194 + 0x22);
    switch (arg1) {
    case 0:
        ParticleMath_RotateVec3fY(&rotated, velocity, angles);
        break;
    case 1:
        angles.y += 0x8000;
        ParticleMath_RotateVec3fY(&rotated, velocity, angles);
        break;
    case 2:
        angles.y += 0x4000;
        ParticleMath_RotateVec3fY(&rotated, velocity, angles);
        break;
    case 3:
        angles.y += 0xC000;
        ParticleMath_RotateVec3fY(&rotated, velocity, angles);
        break;
    case 4:
        rotated.y = velocity.z;
        break;
    case 5:
        rotated.y = -velocity.z;
        break;
    case 6:
        ParticleMath_RotateVec3fY(&rotated, velocity, *(ParticleVec3s *)(arg0 + 0x6A));
        break;
    case 7:
        rotated.x = (*(f32 *)(arg0 + 0x5C) * D_80088E50[(s32)(*(u16 *)(arg0 + 0x6A)) >> 4]) *
                   D_80087E50[(s32)(*(u16 *)(arg0 + 0x6C)) >> 4];
        rotated.y = -*(f32 *)(arg0 + 0x5C) * D_80087E50[(s32)(*(u16 *)(arg0 + 0x6A)) >> 4];
        rotated.z = (*(f32 *)(arg0 + 0x5C) * D_80088E50[(s32)(*(u16 *)(arg0 + 0x6A)) >> 4]) *
                   D_80088E50[(s32)(*(u16 *)(arg0 + 0x6C)) >> 4];
        break;
    case 8:
        rotated.x = (*(f32 *)(arg0 + 0x5C) * D_80088E50[(s32)(*(u16 *)(arg0 + 0x6A)) >> 4]) *
                   D_80087E50[(s32)(*(u16 *)(arg0 + 0x6C)) >> 4];
        rotated.y = -*(f32 *)(arg0 + 0x5C) * D_80087E50[(s32)(*(u16 *)(arg0 + 0x6A)) >> 4];
        rotated.z = (*(f32 *)(arg0 + 0x5C) * D_80088E50[(s32)(*(u16 *)(arg0 + 0x6A)) >> 4]) *
                   D_80088E50[(s32)(*(u16 *)(arg0 + 0x6C)) >> 4];
        break;
    }
    if (func_84100074(arg0, 0x400) != 0) {
        if (*(s32 *)((u8 *)obj + 4) & 8) {
            scale = func_8411E358(*(s32 *)(arg0 + 8), *(u16 *)(arg0 + 0x68));
        } else {
            scale = func_8411EE54(*(u8 **)(arg0 + 8));
        }
        rotated.x *= scale * 0.01f;
        rotated.y *= scale * 0.01f;
        rotated.z *= scale * 0.01f;
    }
    if (arg1 == 8) {
        *(f32 *)(arg0 + 0x44) = rotated.x;
        *(f32 *)(arg0 + 0x48) = rotated.y;
        *(f32 *)(arg0 + 0x4C) = rotated.z;
        return;
    }
    *(f32 *)(arg0 + 0x44) += rotated.x;
    *(f32 *)(arg0 + 0x48) += rotated.y;
    *(f32 *)(arg0 + 0x4C) += rotated.z;
}

/* mkdraft:func_84101888 begin */
extern s32 ParticleMath_RandomSignedOffsetBySign(u32, s32);
extern s32 func_81100120(u32, s32);
extern s32 func_81100144(u32, s32);

// The callees take two arguments and are defined with s32 formals in fragment27_code.c; their
// first formal is spelled u32 here because retail loads state->step into v0 and copies it with
// `or a0,v0,zero` at each call. With an s32 first formal IDO loads step straight into a0 instead
// (diff score 695).
//@src/fragments/27/fragment27_code.c


void func_84101888(s16 *arg0, void *arg1, u8 arg2, s16 *arg3) {
    typedef struct {
        u16 flags;
        s16 value;
        s16 minimum;
        s16 maximum;
        s16 step;
        s16 offset;
    } State;
    State *state = arg1;
    if (((s16 *)arg1)[2] == 0 || arg2 < ((s16 *)arg1)[2]) {
        if (arg2 == state->value) {
            if (state->step == 0) {
                *arg3 = state->offset;
            } else if ((state->flags & 0xFF00) == 0x200) {
                *arg3 = ParticleMath_RandomSignedOffsetBySign(state->step, state->offset);
            } else if ((state->flags & 0xFF00) == 0x100) {
                *arg3 = func_81100120(state->step, state->offset);
            } else {
                *arg3 = func_81100144(state->step, state->offset);
            }
        }
        if (arg2 >= state->value) {
            if (state->flags == 0) {
                if (state->maximum != *arg0) {
                    if (state->maximum < *arg0) {
                        *arg0 -= *arg3;
                        if (*arg0 < state->maximum) {
                            *arg0 = state->maximum;
                        }
                    } else {
                        *arg0 += *arg3;
                        if (state->maximum < *arg0) {
                            *arg0 = state->maximum;
                        }
                    }
                }
            } else {
                *arg0 += *arg3;
            }
        }
    }
}
/* mkdraft:func_84101888 end */

void func_84101A08(f32 *arg0, u8 *arg1, u8 arg2) {
    f32 value;
    if (*(s16 *)(arg1 + 4) != 0 && arg2 >= *(s16 *)(arg1 + 4)) {
        return;
    }
    if (arg2 < *(s16 *)(arg1 + 2)) {
        return;
    }
    value = (f32)*(s16 *)(arg1 + 8);
    if (value == *arg0) {
        return;
    }
    if (value < *arg0) {
        *arg0 -= (f32)*(s16 *)(arg1 + 0xA);
        if (*arg0 < (f32)*(s16 *)(arg1 + 8)) {
            *arg0 = (f32)*(s16 *)(arg1 + 8);
        }
    } else {
        *arg0 += (f32)*(s16 *)(arg1 + 0xA);
        if ((f32)*(s16 *)(arg1 + 8) < *arg0) {
            *arg0 = (f32)*(s16 *)(arg1 + 8);
        }
    }
}

extern u32 func_8411E358(s32 arg0, s32 arg1);
extern u32 func_8411EE54(u8 *arg0);
extern s32 ParticleMath_LacksBits(void *arg0, s32 arg1);
void func_84101AF4(u8 *arg0, u8 *arg1) {
    f32 scale;

    scale = 1.0f;
    if (ParticleMath_LacksBits(arg0 + 0x14, 0x2000) && *(s32 *)(arg0 + 8) != 0 &&
        ParticleMath_LacksBits(arg1 + 4, 0x80) && ParticleMath_LacksBits(arg1 + 4, 0x40)) {
        if (*(s32 *)(arg1 + 4) & 8) {
            scale = func_8411E358(*(s32 *)(arg0 + 8), *(u16 *)(arg0 + 0x68)) * 0.01f;
        } else {
            scale = func_8411EE54(*(u8 **)(arg0 + 8)) * 0.01f;
        }
    }
    *(f32 *)(arg0 + 0x18) = *(f32 *)(arg0 + 0x1C) * scale;
}

/* mkdraft:func_84101C00 begin */
extern s16 func_841005E0(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4);
extern void func_84101AF4(u8 *arg0, u8 *arg1);

// Samples the animation table pair at *arg1 and writes the record's size at 0x1C, which
// func_84100174 initializes to 1.0f and func_84101AF4 multiplies into the scale at 0x18.
// A NULL arg1 leaves 0x1C untouched. func_84100688 maps the phase byte 0x7F to a keyframe
// interval of the table; on the last interval (index + 1 == count) the value is the anim
// sample anim[1][index], otherwise func_841005E0 interpolates between the table's keyframe
// times (the s16 * values at offset 4) and the anim samples, sampling at the phase. The
// phase is 0x7F, or 0x7F % table->divisor while table->mode is 0 - the same modulo
// func_84100688 applies internally; it is only passed to func_841005E0 and is not written
// back to 0x7F. The sampled value is then scaled by the record's u16 at 0x62 and by the
// 0.001f factor twice (retail folds both uses into one load of .late_rodata float
// D_84188B94). func_84101084 performs the same sampling into s16 0x66 with no scaling.


void func_84101C00(u8 *arg0, Func84100688Table **arg1, u8 *arg2) {
    Func84100688Table *table;
    s16 index;
    s16 *frames;
    s32 phase;

    if (arg1 != NULL) {
        index = func_84100688(arg1[0], arg0[0x7F]);
        table = arg1[0];
        frames = table->values;
        if (table->mode == 0) {
            phase = arg0[0x7F] % table->divisor;
        } else {
            phase = arg0[0x7F];
        }
        if (index + 1 == table->count) {
            *(f32 *)(arg0 + 0x1C) = (f32)((s16 *)((u8 **)arg1)[1])[index];
        } else {
            *(f32 *)(arg0 + 0x1C) = (f32)func_841005E0(*(s16 *)(index * 2 + (u8 *)frames), *(s16 *)(index * 2 + (u8 *)frames + 2),
                                                       ((s16 **)arg1)[1][index], ((s16 **)arg1)[1][index + 1],
                                                       phase);
        }
        *(f32 *)(arg0 + 0x1C) *= (f32)*(u16 *)(arg0 + 0x62) * 0.001f * 0.001f;
        func_84101AF4(arg0, arg2);
    }
}
/* mkdraft:func_84101C00 end */

#pragma GLOBAL_ASM("asm/us/nonmatchings/fragments/79/fragment79_36F8B0/func_84101D54.s")

extern u8 D_8418C958;
extern s32 GeoRender_FindAnchorPosition(s32, s16, s32);
void func_84102750(s32 arg0, void *arg1) {
    void *temp_v0;
    void *temp_v1;

    if (arg1 != NULL) {
        temp_v1 = *(void **)((u8 *)arg1 + 0x10);
        if (temp_v1 != NULL) {
            temp_v0 = *(void **)((u8 *)temp_v1 + 0x10);
            if ((temp_v0 != NULL) && (*(s16 *)temp_v0 == 0)) {
                GeoRender_FindAnchorPosition(arg0, 1, (s32)(u32)((u8 *)&D_8418C958 + *(s16 *)((u8 *)temp_v0 + 2) * 0xC));
            }
        }
    }
}

/* mkdraft:func_841027B4 begin */
#ifndef M2C_FIELD /* mkdraft: m2c --valid-syntax helpers */
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

typedef struct unk_func_841027B4_vec3f {
    /* 0x0 */ f32 x;
    /* 0x4 */ f32 y;
    /* 0x8 */ f32 z;
} unk_func_841027B4_vec3f;

typedef struct unk_func_841027B4 {
    /* 0x00 */ u8 unk_00[0x18];
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ unk_func_841027B4_vec3f unk_20;
    /* 0x2C */ unk_func_841027B4_vec3f unk_2C;
    /* 0x38 */ unk_func_841027B4_vec3f unk_38;
    /* 0x44 */ unk_func_841027B4_vec3f unk_44;
    /* 0x50 */ unk_func_841027B4_vec3f unk_50;
} unk_func_841027B4;

M2C_UNK func_84101D54(u8 *);                        /* extern */



void func_841027B4(u8 *arg0) {
    void *sp24;
    s32 temp_v0_2;
    u8 temp_v0;
    unk_func_841027B4 *rec = (unk_func_841027B4 *)arg0;

    sp24 = M2C_FIELD(arg0, void **, 0x10);
    temp_v0 = M2C_FIELD(arg0, u8 *, 0x7C);
    switch (temp_v0) {                              /* irregular */
    case 0:
        func_84101D54(arg0);
        break;
    case 1:
        func_84101D54(arg0);
        break;
    case 7:
        func_84101D54(arg0);
        break;
    }
    M2C_FIELD(arg0, f32 *, 0x20) = (f32) (rec->unk_38.x + rec->unk_2C.x + rec->unk_44.x + rec->unk_50.x);
    M2C_FIELD(arg0, f32 *, 0x24) = (f32) (rec->unk_38.y + rec->unk_2C.y + rec->unk_44.y + rec->unk_50.y);
    M2C_FIELD(arg0, f32 *, 0x28) = (f32) (rec->unk_38.z + rec->unk_2C.z + rec->unk_44.z + rec->unk_50.z);
    func_84102750(M2C_FIELD(arg0, s32 *, 0xC), sp24);
    temp_v0_2 = M2C_FIELD(arg0, s32 *, 0xC);
    if (temp_v0_2 != 0) {
        M2C_FIELD(temp_v0_2, f32 *, 0x24) = (f32) M2C_FIELD(arg0, f32 *, 0x20);
        M2C_FIELD(M2C_FIELD(arg0, s32 *, 0xC), f32 *, 0x28) = (f32) M2C_FIELD(arg0, f32 *, 0x24);
        M2C_FIELD(M2C_FIELD(arg0, s32 *, 0xC), f32 *, 0x2C) = (f32) M2C_FIELD(arg0, f32 *, 0x28);
        M2C_FIELD(M2C_FIELD(arg0, s32 *, 0xC), f32 *, 0x30) = (f32) M2C_FIELD(arg0, f32 *, 0x18);
        M2C_FIELD(M2C_FIELD(arg0, s32 *, 0xC), f32 *, 0x34) = (f32) M2C_FIELD(arg0, f32 *, 0x18);
        M2C_FIELD(M2C_FIELD(arg0, s32 *, 0xC), f32 *, 0x38) = (f32) M2C_FIELD(arg0, f32 *, 0x18);
        M2C_FIELD(M2C_FIELD(arg0, s32 *, 0xC), s16 *, 0x1E) = (s16) M2C_FIELD(arg0, s16 *, 0x6A);
        M2C_FIELD(M2C_FIELD(arg0, s32 *, 0xC), s16 *, 0x20) = (s16) M2C_FIELD(arg0, s16 *, 0x6C);
        M2C_FIELD(M2C_FIELD(arg0, s32 *, 0xC), s16 *, 0x22) = (s16) M2C_FIELD(arg0, s16 *, 0x6E);
        M2C_FIELD(M2C_FIELD(arg0, s32 *, 0xC), u8 *, 0x1D) = (u8) M2C_FIELD(arg0, u8 *, 0x87);
    }
}
/* mkdraft:func_841027B4 end */

extern s32 ParticleMath_LacksBits(void *arg0, s32 arg1);
extern s32 ParticleMath_HasBits(void *arg0, s32 arg1);
extern s32 ModelAnim_IsFinished(void *arg0);
extern void func_84100094(u8 *arg0);
void func_8410291C(u8 *arg0) {
    u8 *state = *(u8 **)(arg0 + 0x10);
    if (*(u8 **)(arg0 + 0xC) == NULL) return;
    if (state == NULL) return;
    if (*(u8 **)(*(u8 **)(arg0 + 0xC) + 0x44) == NULL) return;
    if ((*(s16 *)*(u8 **)(*(u8 **)(arg0 + 0xC) + 0x44) & 2) == 0) return;
    if (ParticleMath_LacksBits(state + 4, 0x2000) == 0) return;
    if (ParticleMath_HasBits(state + 4, 0x4000) != 0) {
        if (*(u8 **)(*(u8 **)(arg0 + 0xC) + 0x48) == NULL) func_84100094(arg0);
    } else if (ModelAnim_IsFinished(*(u8 **)(arg0 + 0xC)) != 0) func_84100094(arg0);
}

extern void func_841027B4(u8 *);
extern void func_84100B3C(u8 *);
extern void func_84100C68(u8 *);
extern void func_84100DE4(u8 *);
extern void func_8410488C(u8 *);
extern void BattleAnim_GetPointAlongCameraRay(u8 *, f32);

// Updates each active record (nonzero byte 0x98) of the 300 156-byte records at
// D_8418C950 according to its mode byte at offset 0x7C.
void func_841029DC(void) {
    s32 i;
    u8 *record = D_8418C950;

    for (i = 0; i < 300; i++, record += 156) {
        if (*(s8 *)(record + 0x98) == 0) {
            continue;
        }
        switch (record[0x7C]) {
            case 0:
                func_841027B4(record);
                func_8410291C(record);
                break;
            case 1:
                if (func_84100074(record, 0x800)) {
                    func_841027B4(record);
                }
                break;
            case 7:
                if (func_84100074(record, 0x800)) {
                    func_841027B4(record);
                }
                break;
            case 2:
                func_84100B3C(record);
                break;
            case 4:
                BattleAnim_GetPointAlongCameraRay(*(u8 **)(record + 0xC) + 0x24, 50.0f);
                func_84100B3C(record);
                break;
            case 8:
                func_84100B3C(record);
                break;
            case 5:
                func_84100C68(record);
                break;
            case 6:
                func_84100DE4(record);
                break;
            case 3:
                break;
        }
        if (func_8410009C(record)) {
            func_8410488C(record);
            func_84100350(record);
        }
    }
}

typedef struct S1_Vec3f {
    /* 0x0 */ f32 x;
    /* 0x4 */ f32 y;
    /* 0x8 */ f32 z;
} S1_Vec3f;
typedef struct S1_Vec3s {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ s16 z;
} S1_Vec3s;

extern void func_841039AC(s16, s16, s16, f32);
extern void func_841039F4(s16, s16, s16, f32);
extern void func_841043AC(S1_Vec3f, S1_Vec3s, f32);
extern void func_84104428(S1_Vec3f, S1_Vec3s, f32);
extern void func_84104528(void *, S1_Vec3f, f32);
extern void func_84104590(void *, S1_Vec3f, f32, s16);
extern void func_84104668(void *, S1_Vec3f, f32, s16);

// Passes the record's position (0x20), rotation (0x6A) and scale (0x18) to the
// handler for type, all defined in fragment79_372DE0.
//@src/fragments/79/fragment79_372DE0.c
void func_84102B3C(u8 *record, void *matrix, s32 type) {
    switch (type) {
        case 0:
            func_841043AC(*(S1_Vec3f *)(record + 0x20), *(S1_Vec3s *)(record + 0x6A), *(f32 *)(record + 0x18));
            break;
        case 1:
            func_84104528(matrix, *(S1_Vec3f *)(record + 0x20), *(f32 *)(record + 0x18));
            break;
        case 2:
            func_84104428(*(S1_Vec3f *)(record + 0x20), *(S1_Vec3s *)(record + 0x6A), *(f32 *)(record + 0x18));
            break;
        case 3:
            func_84104668(matrix, *(S1_Vec3f *)(record + 0x20), *(f32 *)(record + 0x18), *(s16 *)(record + 0x6E));
            break;
        case 4:
            func_84104590(matrix, *(S1_Vec3f *)(record + 0x20), *(f32 *)(record + 0x18), *(s16 *)(record + 0x6E));
            break;
        case 5:
            func_841039AC(*(f32 *)(record + 0x20), *(f32 *)(record + 0x24), *(s16 *)(record + 0x6E), *(f32 *)(record + 0x18));
            break;
        case 6:
            func_841039F4(*(f32 *)(record + 0x20), *(f32 *)(record + 0x24), *(s16 *)(record + 0x6E), *(f32 *)(record + 0x18));
            break;
    }
}

typedef struct GfxImage {
    u16 fmt;
    u16 size;
    u16 width;
    u16 height;
    u8 *img_p;
    void *depth_p;
} GfxImage;

extern s32 func_8411E164(s32);
extern s32 func_8411EF64(s32);
extern Gfx *D_800D0510;

// Load the other player's color buffer as an RGBA16 texture.
//@src/fragments/79/fragment79_38D510.c
//@src/7A50.c
Gfx *func_84102D38(Gfx *arg0, Gfx **arg1) {
    GfxImage *image;
    u32 width;
    u32 height;

    image = (GfxImage *)func_8411EF64(func_8411E164((s32)arg1[2]));
    width = image->width;
    height = image->height;
    gDPSetCombineMode(arg0++, G_CC_MODULATEI_PRIM, G_CC_PASS2);
    gDPLoadTextureTile(arg0++, image->img_p, G_IM_FMT_RGBA, G_IM_SIZ_16b,
                      width, height, 0, 0, width - 1, height - 1, 0,
                      G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                      G_TX_NOLOD, G_TX_NOLOD);
    gDPSetRenderMode(D_800D0510++, 0x0C184A50, 0);
    return arg0;
}

/* mkdraft:func_84102E84 begin */
extern Gfx *D_800D0510;
Gfx *func_84102D38(Gfx *, Gfx **);



void func_84102E84(u16 arg0, u8 *arg1) {
    u16 flags = arg0;

    switch (flags & 0x3F) {
    case 0x3F:
        D_800D0510 = func_84102D38(D_800D0510, (Gfx **)arg1);
        return;
    case 1:
        switch (((flags & 0x40) >> 6) + ((flags & 0x80) >> 6)) {
        case 0:
            gDPSetRenderMode(D_800D0510++, 0x0F0A4000, 0);
            break;
        case 1:
            gDPSetRenderMode(D_800D0510++, 0x0C192048, 0);
            break;
        case 2:
            gDPSetRenderMode(D_800D0510++, 0x0C192230, 0);
            break;
        case 3:
            gDPSetRenderMode(D_800D0510++, 0x0C192078, 0);
            break;
        }
        return;
    case 6:
        switch (((flags & 0x40) >> 6) + ((flags & 0x80) >> 6)) {
        case 0:
            gDPSetRenderMode(D_800D0510++, 0x0C184240, 0);
            break;
        case 1:
            gDPSetRenderMode(D_800D0510++, 0x0C1841C8, 0);
            break;
        case 2:
            gDPSetRenderMode(D_800D0510++, 0x0C184A50, 0);
            break;
        case 3:
            gDPSetRenderMode(D_800D0510++, 0x0C1849D8, 0);
            break;
        }
        return;
    case 4:
        switch (((flags & 0x40) >> 6) + ((flags & 0x80) >> 6)) {
        case 0:
            gDPSetRenderMode(D_800D0510++, 0x0F0A7008, 0);
            break;
        case 1:
            gDPSetRenderMode(D_800D0510++, 0x0C193048, 0);
            break;
        case 2:
            gDPSetRenderMode(D_800D0510++, 0x0C193078, 0);
            break;
        case 3:
            gDPSetRenderMode(D_800D0510++, 0x0C193078, 0);
            break;
        }
        return;
    }
    gDPSetRenderMode(D_800D0510++, 0x0C184240, 0);
}
/* mkdraft:func_84102E84 end */

extern Gfx *D_800D0510;
extern u8 *D_8418CA20[];
extern void *func_80003240();
extern void func_8100348C();
extern void func_84102E84(u16, u8 *);
void func_841031F4(u8 *record, void *arg1, s32 matrix) {
    s16 *id;
    u8 *entry;
    u8 *model;
    u16 type;
    u16 count;
    void (*draw)(u8 *, s32);
    s32 i;

    if (arg1 != NULL && (id = *(s16 **)((u8 *)arg1 + 0x14)) != NULL && *id != 0) {
        entry = D_8418CA20[*id];
        model = *(u8 **)(entry + 4);
        type = *(u16 *)entry;
        count = *(u16 *)(entry + 2);
        draw = (void (*)(u8 *, s32))func_80003240(func_8100348C);
        func_84102B3C(record, (void *)matrix, type);
        for (i = 0; i < count; i++) {
            draw(record, *(s32 *)model);
            func_84102E84(*(u16 *)(model + 6), record);
            gSPDisplayList(D_800D0510++, *(u32 *)(model + 8));
            model += 0x10;
        }
    }
}

extern Gfx *D_800D0510;
extern u8 *D_8418CB88;
extern void *func_80003240();
extern void func_8100348C();
extern void func_84102E84(u16, u8 *);
void func_841032F0(u8 *record, s32 matrix) {
    s32 pad[2]; // FAKE
    u8 *model;
    u16 type;
    void (*draw)(u8 *, s32);

    model = *(u8 **)(D_8418CB88 + 4);
    type = *(u16 *)D_8418CB88;
    draw = (void (*)(u8 *, s32))func_80003240(func_8100348C);
    func_84102B3C(record, (void *)matrix, type);
    draw(record, *(s32 *)model);
    func_84102E84(*(u16 *)(model + 6), record);
    gSPDisplayList(D_800D0510++, *(u32 *)(model + 8));
}

extern u8 *D_80094910;
extern void func_841031F4(u8 *, void *, s32);
extern s32 func_84100054(u8 *arg0, s32 arg1);
extern s32 func_84100074(u8 *arg0, s32 arg1);
void func_84103394(s32 arg0) {
    s32 i;
    s32 result;
    u8 *record;
    void *child;

    record = D_8418C950;
    for (i = 0; i < 0x12C; i++, record += 0x9C) {
        if (*(s8 *)(record + 0x98) != 0) {
            if (func_84100074(record, 0x102800) != 0) {
                if (func_84100054(record, 0x1000) != 0) {
                    child = *(void **)(record + 0x10);
                    result = 0;
                    if ((child != NULL) && ((*(u32 *)((u8 *)child + 8) & 2) != 0)) {
                        result = 3;
                    }
                    if (result == *(s16 *)(D_80094910 + 0x18)) {
                        func_841031F4(record, child, arg0);
                    }
                }
            }
        }
    }
}

extern void func_841032F0(u8 *, s32);
extern void func_841031F4(u8 *, void *, s32);
extern s32 func_84100054(u8 *arg0, s32 arg1);
extern s32 func_84100074(u8 *arg0, s32 arg1);
void func_84103478(s32 arg0) {
    s32 mask = 0x100800;
    s32 i;
    u8 *record;

    record = D_8418C950;
    for (i = 0; i < 0x12C; i++, record += 0x9C) {
        if ((*(s8 *)(record + 0x98) != 0) && (func_84100074(record, mask) != 0) && (func_84100054(record, 0x1000) != 0) && (func_84100054(record, 0x2000) != 0)) {
            if (func_84100074(record, 0x4000) != 0) {
                u8 *child = *(u8 **)(record + 0x10);
                func_841031F4(record, child, arg0);
            } else {
                func_841032F0(record, arg0);
            }
        }
    }
}
#endif
