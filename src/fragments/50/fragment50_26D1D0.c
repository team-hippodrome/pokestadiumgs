#include "global.h"


#ifdef VERSION_US
typedef struct SceneDirectionChoice {
    f32 origin[3];
    f32 directions[4][3];
    s16 buttons;
} SceneDirectionChoice;

extern u8 *D_8620E198;
extern f32 D_862090C0[];
extern SceneDirectionChoice D_86208F28[5];
extern f32 func_87D005E8(f32 *, f32 *, f32 *);
extern void func_8620573C(f32 *, f32 *);
extern u32 func_8003570C(void);
extern f32 func_87D0059C(f32 *, f32 *);


void func_86206790(f32 *arg0, f32 *arg1, s32 *arg2, s32 *arg3) {
    f32 temp_fv0;
    s32 temp_v0;

    temp_fv0 = *arg0;
    *arg0 = *arg1;
    *arg1 = temp_fv0;
    temp_v0 = *arg2;
    *arg2 = *arg3;
    *arg3 = temp_v0;
}

s32 SceneMotion_ComputeNearbyDirection(f32 *origin, f32 *direction, u8 *object, f32 *output) {
    f32 speed_scale;
    f32 time_scale;
    f32 x;
    f32 y;
    f32 z;
    u8 *metadata;
    s32 result;
    metadata = *(u8 **)(object + 32);
    speed_scale = 5.0f;
    speed_scale *= *(f32 *)(D_8620E198 + 216);
    time_scale = *(f32 *)(D_8620E198 + 204);
    x = (origin[0] - direction[0] * 18.0f * speed_scale * time_scale) + D_862090C0[0];
    y = D_862090C0[1] + 30.0f;
    z = (origin[2] - direction[2] * 18.0f * speed_scale * time_scale) + D_862090C0[2];
    output[0] = *(f32 *)(object + 72) - x;
    output[1] = *(f32 *)(object + 76) - y;
    output[2] = *(f32 *)(object + 80) - z;
    if (func_87D005E8(&output[0], &output[1], &output[2]) < *(f32 *)(metadata + 52) * (*(f32 *)(D_8620E198 + 100) * 0.75f * 100.0f) + 108.5f) {
        func_8620573C(output, direction);
        result = 1;
    } else {
        result = 0;
        output[2] = 0.0f;
        output[1] = 0.0f;
        output[0] = 0.0f;
    }
    return result;
}

s16 SceneInput_SelectScoredDirection(s32 index, s32 rank, f32 threshold) {
    s32 i;
    s32 direction_index;
    f32 *origin;
    SceneDirectionChoice *choices[5];
    SceneDirectionChoice **choice_cursor;
    f32 scores[5];
    f32 *score_cursor;
    s16 result;
    SceneDirectionChoice **sort_choice_slot;
    f32 relative[3];
    SceneDirectionChoice *choice;
    f32 *direction;
    u8 *object;
    u8 *metadata;
    f32 best;
    f32 (*directions)[3];
    f32 score;
    s32 j;
    u32 first;
    u32 second;
    choice = D_86208F28;
    choice_cursor = choices;
    score_cursor = scores;
    result = 0;
    for (i = 0; i < 5; i++) {
        best = 0.0f;
        object = *(u8 **)(D_8620E198 + 384);
        while (object != 0) {
            metadata = *(u8 **)(object + 32);
            directions = choice->directions;
            direction_index = *(u8 *)(D_8620E198 + 474066 + index * 24);
            origin = choice->origin;
            direction = directions[direction_index];
            relative[0] = 0.0f;
            relative[1] = 0.0f;
            relative[2] = 0.0f;
            if (SceneMotion_ComputeNearbyDirection(origin, direction, object, relative)) {
                relative[0] += *(f32 *)(object + 16);
                relative[1] = 0.0f;
                relative[2] += *(f32 *)(object + 24);
                func_87D0059C(&relative[0], &relative[2]);
                score = relative[2] * direction[2] + relative[0] * direction[0];
                score *= *(s32 *)(metadata + 48);
            } else {
                score = -1.0f;
            }
            if (best < score || object == *(u8 **)(D_8620E198 + 384)) {
                best = score;
            }
            object = *(u8 **)(object + 4);
        }
        *score_cursor = best;
        *choice_cursor = choice;
        choice++;
        choice_cursor++;
        score_cursor++;
    }
    for (i = 0; i < 5; i++) {
        first = func_8003570C() % 5;
        second = func_8003570C() % 5;
        func_86206790(&scores[first], &scores[second], (s32 *)&choices[first], (s32 *)&choices[second]);
    }
    for (i = 5 - 1; i != 0; i--) {
        for (j = i; j > 0; j--) {
            if (scores[j - 1] < scores[j]) {
                sort_choice_slot = &choices[j];
                func_86206790(&scores[j], &scores[j - 1], (s32 *)sort_choice_slot, (s32 *)&choices[j - 1]);
            }
        }
    }
    if (threshold < scores[rank]) {
        result = choices[rank]->buttons;
    }
    return result;
}

s16 SceneInput_AdvanceSelectionPhase(s32 index, s32 entry_delay, s32 rank, f32 threshold, s32 release_delay) {
    u8 *state;
    s16 buttons;
    state = D_8620E198 + 474044 + index * 24;
    buttons = *(s16 *)(state + 16);
    switch (*(u8 *)(state + 19)) {
    case 0:
        if (entry_delay < *(s32 *)(state + 8)) {
            *(u8 *)(state + 19) = 1;
            *(s32 *)(state + 8) = 0;
        }
        break;
    case 1:
        buttons = SceneInput_SelectScoredDirection(index, rank, threshold);
        if (buttons != 0) {
            *(u8 *)(state + 19) = 2;
            *(s32 *)(state + 8) = 0;
        } else {
            buttons = 0;
        }
        break;
    case 2:
        if (release_delay < *(s32 *)(state + 8)) {
            buttons |= 0x4000;
            *(u8 *)(state + 19) = 0;
            *(s32 *)(state + 8) = 0;
        }
        break;
    }
    return buttons;
}

s16 SceneInput_UpdateCpuSelection(s32 index) {
    s16 buttons;
    s32 entry_delay;
    s32 rank;
    f32 threshold;
    s32 release_delay;
    u8 *state;
    state = D_8620E198 + 474044 + index * 24;
    /* Every difficulty consumes three random draws, including fixed-rank cases. */
    switch (*(s32 *)(state + 12)) {
    case 0:
        entry_delay = func_8003570C() % 41 + 40;
        rank = func_8003570C() % 3;
        threshold = 0.0f;
        release_delay = func_8003570C() % 31;
        break;
    case 1:
        entry_delay = func_8003570C() % 18 + 17;
        rank = func_8003570C() & 1;
        threshold = 0.7f;
        release_delay = func_8003570C() % 13;
        break;
    case 2:
        entry_delay = (func_8003570C() & 0xF) + 15;
        func_8003570C();
        rank = 0;
        threshold = 0.85f;
        release_delay = func_8003570C() % 6;
        break;
    case 3:
        entry_delay = func_8003570C() % 13 + 12;
        func_8003570C();
        rank = 0;
        threshold = 0.9f;
        release_delay = func_8003570C() & 3;
        break;
    }
    buttons = SceneInput_AdvanceSelectionPhase(index, entry_delay, rank, threshold, release_delay);
    (*(s32 *)(state + 8))++;
    *(s16 *)(state + 16) = buttons & 0xBFFF;
    return buttons;
}

extern u8 *D_8620E198;



s16 func_86206EF8(void *arg0, void *arg1) {
    unsigned int current;
    s16 selected;
    unsigned int btn;

    selected = 0;
    switch (*(s32 *)((u8 *)D_8620E198 + 0x54)) {
    default:
        selected = 0;
        goto out;
    case 1:
        selected = *(s16 *)((u8 *)arg0 + 8);
        goto out;
    case 2:
        if (*(u16 *)((u8 *)arg0 + 6) & 0x200) {
            selected = 0x200;
        } else if (*(u16 *)((u8 *)arg0 + 6) & 0x100) {
            selected = 0x100;
        } else if (*(u16 *)((u8 *)arg0 + 6) & 0x800) {
            selected = 0x800;
        } else if (*(u16 *)((u8 *)arg0 + 6) & 0x400) {
            selected = 0x400;
        } else {
            selected = -0x8000;
        }
        if (*(u16 *)((u8 *)arg0 + 8) & 0x8000) {
            selected |= 0x4000;
        }
        goto out;
    case 0:
        btn = *(u16 *)((u8 *)arg0 + 6);
        if (btn != 0) {
            current = *(u16 *)((u8 *)arg1 + 0x14);
            if (current == 0) {
                *(u16 *)((u8 *)arg1 + 0x14) = current | btn;
                goto out;
            }
            if ((current & 0x200) && (current & 0x800)) {
                selected = 2;
            } else if ((current & 0x200) && (current & 0x400)) {
                selected = 4;
            } else if ((current & 0x100) && (current & 0x800)) {
                selected = 8;
            } else if ((current & 0x100) && (current & 0x400)) {
                selected = 1;
            } else if (current & 0x200) {
                selected = 0x200;
            } else if (current & 0x100) {
                selected = 0x100;
            } else if (current & 0x800) {
                selected = 0x800;
            } else if (current & 0x400) {
                selected = 0x400;
            } else if (current & 0x8000) {
                selected = -0x8000;
            }
            *(u16 *)((u8 *)arg1 + 0x14) = 0;
            goto out;
        } else {
            *(u16 *)((u8 *)arg1 + 0x14) = 0;
            goto out;
        }
    case 3:
        if (*(u16 *)((u8 *)arg0 + 8) & 0x8000) {
            selected = 0x4000;
        }
        goto out;
    }
out:
    return selected;
}





extern u8 *D_8620E198;
extern SceneDirectionChoice D_86208F28[5];
s16 SceneInput_UpdateCpuSelection(s32 index);
extern void SceneModel_SelectPlayerDirection(s32 player_index, s32 choice_index);
extern void SceneModel_StartPlayerAction(s32 player_index);
extern void func_86205724(s32 index);
extern void func_8620572C(s32 index, f32 *origin, f32 *direction);
extern u8 D_800CE060[];
s16 func_86206EF8(void *arg0, void *arg1);


void func_862070B0(void)
{
  SceneDirectionChoice *var_s0;
  SceneDirectionChoice *var_s3;
  s16 var_v0;
  s32 temp_v1;
  s32 var_s1;
  s32 var_s4;
  s16 var_s5;
  s32 var_s6;
  u8 *var_fp;
  u8 *var_s7;
  var_fp = D_800CE060;
  var_s7 = D_8620E198 + 0x73BBC;
  for (var_s4 = 0; var_s4 != 4; var_s4++)
  {
    var_s3 = D_86208F28;
    var_s6 = 0;
    var_s1 = 0;
    if (((*((u8 *) ((*((u8 **) (D_8620E198 + 0xF4))) + 0x2180))) != 4) && ((*((u32 *) var_s7)) & 0x10000000))
    {
      var_v0 = func_86206EF8(var_fp, var_s7);
      var_s5 = var_v0;
    }
    else
    {
      var_v0 = SceneInput_UpdateCpuSelection(var_s4);
      var_s5 = var_v0;
    }
    var_s0 = D_86208F28;
    loop_6_start:
    if (var_s0->buttons & var_v0)
    {
      var_s3 = var_s0;
      var_s6 = var_s1 & 0xFF;
    }
    else
    {
      var_s1++;
      var_s0 = (SceneDirectionChoice *) (((u8 *) var_s0) + 0x40);
      if (var_s1 != 5)
      {
        goto loop_6_start;
      }
    }

    temp_v1 = *((s32 *) (D_8620E198 + 0x54));
    switch (temp_v1)
    {
      case 2:
        if (var_s3 != NULL)
      {
        SceneModel_SelectPlayerDirection(var_s4, var_s6);
        if (var_s5 & 0x4000)
        {
          SceneModel_StartPlayerAction(var_s4);
        }
      }
        break;

      case 0:

      case 1:
        if (var_s3 != NULL)
      {
        func_8620572C(var_s4, var_s3->origin, (f32 *) ((((u8 *) var_s3) + (var_s6 * 0xC)) + 0xC));
      }
        break;

      case 3:
        if (var_v0 & 0x4000)
      {
        func_86205724(var_s4);
      }
        break;

    }

    var_fp += 0x28;
    var_s7 += 0x18;
  }

  if (var_s1)
  {
  }
}
#endif
