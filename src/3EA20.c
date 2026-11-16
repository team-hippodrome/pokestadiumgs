#include "229E0.h"

#ifdef VERSION_US

f32 ModelAnim_EvaluateTranslationChannel(S1_unk_D_800ABCC0* arg0, s32 arg1) {
    f32 ret;
    s32 var_a2;
    S1_unk_D_800ABCC0_008* temp_v0 = &arg0->channels[arg1];

    if (temp_v0->translationKeyCount == 1) {
        ret = temp_v0->translationBaseIndex / 1000.0f;
    } else {
        if (arg0->currentFrame < temp_v0->translationKeyCount) {
            var_a2 = temp_v0->translationBaseIndex + arg0->currentFrame;
        } else {
            var_a2 = (temp_v0->translationBaseIndex + temp_v0->translationKeyCount) - 1;
        }

        ret = arg0->translationValues[var_a2] / 1000.0f;
    }

    return ret;
}

s16 ModelAnim_EvaluateRotationChannel(S1_unk_D_800ABCC0* arg0, s32 arg1) {
    s32 var_a1;
    s16 var_v1;
    S1_unk_D_800ABCC0_008* temp_v0 = &arg0->channels[arg1];

    if (temp_v0->rotationKeyCount == 1) {
        var_v1 = temp_v0->rotationBaseIndex * 0x10;
    } else {
        if (arg0->currentFrame < temp_v0->rotationKeyCount) {
            var_a1 = temp_v0->rotationBaseIndex + arg0->currentFrame;
        } else {
            var_a1 = (temp_v0->rotationBaseIndex + temp_v0->rotationKeyCount) - 1;
        }
        var_v1 = func_80037360(arg0->rotationValues, var_a1, 0xC) * 0x10;
    }
    return var_v1;
}

f32 ModelAnim_EvaluateScaleChannel(S1_unk_D_800ABCC0* arg0, s32 arg1) {
    f32 var_fv1;
    s16 var_a2;
    s32 var_a1;
    S1_unk_D_800ABCC0_008* temp_v0 = &arg0->channels[arg1];

    if (temp_v0->scaleKeyCount == 1) {
        if (arg0->flags & 4) {
            var_fv1 = (s16)temp_v0->scaleBaseIndex;
        } else {
            var_a2 = temp_v0->scaleBaseIndex * 0x10;
            var_fv1 = var_a2 >> 4;
        }
    } else {
        if (arg0->currentFrame < temp_v0->scaleKeyCount) {
            var_a1 = temp_v0->scaleBaseIndex + arg0->currentFrame;
        } else {
            var_a1 = (temp_v0->scaleBaseIndex + temp_v0->scaleKeyCount) - 1;
        }

        if (arg0->flags & 4) {
            var_fv1 = func_80037360(arg0->scaleValues, var_a1, 0x10);
        } else {
            var_fv1 = func_80037360(arg0->scaleValues, var_a1, 0xC);
        }
    }

    return var_fv1;
}

f32 ModelAnim_InterpolateKeyframe(S1_Vec3s* arg0, s16 arg1, s16 arg2) {
    f32 y;
    s32 i;
    f32 x;
    f32 var_fv1;

    if (arg0->x >= arg2) {
        var_fv1 = arg0->y;
    } else {
        if (arg2 >= arg0[arg1 - 1].x) {
            var_fv1 = arg0[arg1 - 1].y;
        } else {
            for (i = 0; i < arg1 - 2; i++) {
                if (arg2 < arg0[i + 1].x) {
                    break;
                }
            }

            x = (arg2 - arg0[i].x) / 30.0f;
            y = 30.0f / (arg0[i + 1].x - arg0[i].x);

            var_fv1 = (arg0[i].y * (((2.0f * x * x * x * y * y * y) - 3.0f * x * x * y * y) + 1.0f))
                    + (arg0[i + 1].y * ((-2.0f * x * x * x * y * y * y) + 3.0f * x * x * y * y))
                    + (arg0[i].z * ((x * x * x * y * y - (2.0f * x * x * y)) + x))
                    + (arg0[i + 1].z * (x * x * x * y * y - (x * x * y)));
        }
    }
    return var_fv1;
}

f32 ModelAnim_InterpolateKeyframeTangent(S1_unk_func_80016B30_arg0* arg0, s16 arg1, s16 arg2) {
    f32 y;
    s32 i;
    f32 x;
    f32 var_fv1;

    if (arg0->vec.x >= arg2) {
        var_fv1 = arg0->vec.y;
    } else {
        if (arg2 >= arg0[arg1 - 1].vec.x) {
            var_fv1 = arg0[arg1 - 1].vec.y;
        } else {
            for (i = 0; i < arg1 - 2; i++) {
                if (arg2 < arg0[i + 1].vec.x) {
                    break;
                }
            }

            x = (arg2 - arg0[i].vec.x) / 30.0f;
            y = 30.0f / (arg0[i + 1].vec.x - arg0[i].vec.x);

            var_fv1 = (arg0[i].vec.y * (((2.0f * x * x * x * y * y * y) - 3.0f * x * x * y * y) + 1.0f))
                    + (arg0[i + 1].vec.y * ((-2.0f * x * x * x * y * y * y) + 3.0f * x * x * y * y))
                    + (arg0[i].unk_06 * ((x * x * x * y * y - (2.0f * x * x * y)) + x))
                    + (arg0[i + 1].vec.z * (x * x * x * y * y - (x * x * y)));
        }
    }
    return var_fv1;
}

f32 ModelAnim_EvaluateTranslationCurve(S1_unk_D_800ABCC0* arg0, s32 arg1) {
    f32 var_fv1;
    S1_unk_D_800ABCC0_008* temp_v0 = &arg0->channels[arg1];
    s16* tmp;

    if (temp_v0->translationKeyCount < 2) {
        var_fv1 = (s16)temp_v0->translationBaseIndex / 100.0f;
    } else {
        tmp = &arg0->translationValues[temp_v0->translationBaseIndex];
        if (temp_v0->unk_03 & 4) {
            var_fv1 = ModelAnim_InterpolateKeyframeTangent(tmp, temp_v0->translationKeyCount, arg0->currentFrame) / 100.0f;
        } else {
            var_fv1 = ModelAnim_InterpolateKeyframe(tmp, temp_v0->translationKeyCount, arg0->currentFrame) / 100.0f;
        }
    }
    return var_fv1;
}

s16 ModelAnim_EvaluateRotationCurve(S1_unk_D_800ABCC0* arg0, s32 arg1) {
    f32 var_fv1;
    s16* temp_a0;
    S1_unk_D_800ABCC0_008* temp_v0 = &arg0->channels[arg1];

    if (temp_v0->rotationKeyCount < 2) {
        var_fv1 = (s16)temp_v0->rotationBaseIndex / 10.0f;
    } else {
        temp_a0 = &arg0->rotationValues[temp_v0->rotationBaseIndex];
        if (temp_v0->unk_03 & 2) {
            var_fv1 = ModelAnim_InterpolateKeyframeTangent(temp_a0, temp_v0->rotationKeyCount, arg0->currentFrame) / 10.0f;
        } else {
            var_fv1 = ModelAnim_InterpolateKeyframe(temp_a0, temp_v0->rotationKeyCount, arg0->currentFrame) / 10.0f;
        }
    }

    while (var_fv1 < 0.0f) {
        var_fv1 += 360.0f;
    }

    while (var_fv1 >= 360.0f) {
        var_fv1 -= 360.0f;
    }

    return (var_fv1 / 360.0f) * 65536.0f;
}

f32 ModelAnim_EvaluateScaleCurve(S1_unk_D_800ABCC0* arg0, s32 arg1) {
    s16* temp_a0;
    f32 var_fv0;
    f32 var_fv1;
    S1_unk_D_800ABCC0_008* temp_v0 = &arg0->channels[arg1];

    if (temp_v0->scaleKeyCount < 2) {
        var_fv1 = (s16)temp_v0->scaleBaseIndex;
    } else {
        temp_a0 = &arg0->scaleValues[temp_v0->scaleBaseIndex];
        if (temp_v0->unk_03 & 1) {
            var_fv0 = ModelAnim_InterpolateKeyframeTangent(temp_a0, temp_v0->scaleKeyCount, arg0->currentFrame);
        } else {
            var_fv0 = ModelAnim_InterpolateKeyframe(temp_a0, temp_v0->scaleKeyCount, arg0->currentFrame);
        }
        var_fv1 = var_fv0;
    }
    return var_fv1;
}

s32 ModelAnim_AdvanceCurveFrame(S1_unk_D_86002F58_004_000_040_raw* arg0, u16 arg1) {
    S1_unk_D_86002F58_004_000_040_raw_08 spC;
    S1_unk_D_86002F58_004_000_040_raw_08* ptr;
    S1_unk_D_86002F58_004_000_040_004* temp_v0;

    ptr = &spC;
    temp_v0 = arg0->unk_04;
    spC.raw = arg0->unk_08.raw;
    if (arg0->unk_12 != arg1) {
        spC.raw += arg0->unk_0C;
        if (arg0->unk_0C >= 0) {
            if (ptr->unk_00 >= temp_v0->unk_0A) {
                if (temp_v0->unk_00 & 2) {
                    ptr->unk_00 = temp_v0->unk_0A - 1;
                } else {
                    ptr->unk_00 = temp_v0->unk_06;
                }
            }
        } else {
            if (ptr->unk_00 < temp_v0->unk_06) {
                if (temp_v0->unk_00 & 2) {
                    ptr->unk_00 = temp_v0->unk_06;
                } else {
                    ptr->unk_00 = temp_v0->unk_0A - 1;
                }
            }
        }
    }

    return spC.raw;
}

 void ModelAnim_ResetCurveContext(void) { D_801263E0 = -1; }

void func_8003E7B0(S1_unk_D_86002F58_004_000_040_raw *arg0, u16 arg1, s32 arg2) {
    extern S1_unk_D_800ABCC0 D_801263B0[2];
    S1_unk_D_800ABCC0 *ctx;
    S1_unk_D_86002F58_004_000_040_004 *data;
    data = arg0->unk_04;
    ++D_801263E0;
    if (D_801263E0 < 2) {
        ctx = &D_801263B0[D_801263E0];
        if (arg0->unk_04 != 0) {
            if (arg2 != 0) {
                arg0->unk_08.raw = ModelAnim_AdvanceCurveFrame(arg0, arg1);
            }
            arg0->unk_12 = arg1;
            ctx->isActive = 1;
            ctx->flags = arg0->unk_04->unk_00;
            ctx->currentFrame = arg0->unk_08.raw >> 16;
            ctx->curveData = data;
            ctx->channels = func_80003240(data->unk_0C);
            ctx->translationValues = func_80003240(data->unk_10);
            ctx->rotationValues = func_80003240(data->unk_14);
            ctx->scaleValues = func_80003240(data->unk_18);
            if (ctx->currentFrame < 0) {
                ctx->currentFrame = 0;
            }
        } else {
            ctx->isActive = 0;
        }
    }
}

 void ModelAnim_EndCurveContext(void) { if (D_801263E0 >= 0) { D_801263E0--; } }

void func_8003E8C8(S1_Vec3f *arg0, S1_Vec3s *arg1, S1_Vec3f *arg2, s32 arg3) {
    if (D_801263E0 >= 0 && D_801263E0 < 2) {
        S1_unk_D_800ABCC0 *ctx = &D_801263B0[D_801263E0];
        if (ctx->isActive == 1 && arg3 >= 0 && arg3 + 2 < ctx->curveData->unk_08) {
            if (ctx->flags & 8) {
                arg0->x = ModelAnim_EvaluateScaleCurve(ctx, arg3);
                arg0->y = ModelAnim_EvaluateScaleCurve(ctx, arg3 + 1);
                arg0->z = ModelAnim_EvaluateScaleCurve(ctx, arg3 + 2);
                arg1->x = ModelAnim_EvaluateRotationCurve(ctx, arg3);
                arg1->y = ModelAnim_EvaluateRotationCurve(ctx, arg3 + 1);
                arg1->z = ModelAnim_EvaluateRotationCurve(ctx, arg3 + 2);
                arg2->x = ModelAnim_EvaluateTranslationCurve(ctx, arg3);
                arg2->y = ModelAnim_EvaluateTranslationCurve(ctx, arg3 + 1);
                arg2->z = ModelAnim_EvaluateTranslationCurve(ctx, arg3 + 2);
            } else {
                arg0->x = ModelAnim_EvaluateScaleChannel(ctx, arg3);
                arg0->y = ModelAnim_EvaluateScaleChannel(ctx, arg3 + 1);
                arg0->z = ModelAnim_EvaluateScaleChannel(ctx, arg3 + 2);
                arg1->x = ModelAnim_EvaluateRotationChannel(ctx, arg3);
                arg1->y = ModelAnim_EvaluateRotationChannel(ctx, arg3 + 1);
                arg1->z = ModelAnim_EvaluateRotationChannel(ctx, arg3 + 2);
                arg2->x = ModelAnim_EvaluateTranslationChannel(ctx, arg3);
                arg2->y = ModelAnim_EvaluateTranslationChannel(ctx, arg3 + 1);
                arg2->z = ModelAnim_EvaluateTranslationChannel(ctx, arg3 + 2);
            }
        }
    }
}

void ModelAnim_ClearTransformChannel(u8 *arg0) { *(s16 *)(arg0 + 0x40) = -1; *(s32 *)(arg0 + 0x44) = 0; }

s32 ModelAnim_BindTransformCurve(S1_unk_D_86002F58_004_000* arg0, s16 arg1, void* arg2, s32 arg3) {
    S1_unk_D_86002F58_004_000_040_004* temp_v0 = func_80003240(arg2);
    S1_unk_D_86002F58_004_000_040* ptr = &arg0->unk_040;

    if ((temp_v0 != ptr->unk_04) || (arg1 != ptr->unk_00)) {
        ptr->unk_00 = arg1;
        ptr->unk_04 = temp_v0;
        ptr->unk_08 = (temp_v0->unk_04 << 0x10) - arg3;
    }

    ptr->unk_0C = arg3;
    return ptr->unk_08 >> 0x10;
}

s32 ModelAnim_SetSpeed(u8 *arg0, s32 arg1) { *(s32 *)(arg0 + 0x4C) = arg1; return *(s32 *)(arg0 + 0x48) >> 16; }

void ModelAnim_SetFrame(u8 *arg0, s16 value) { *(s32 *)(arg0 + 0x48) = ((s32)value << 16) - *(s32 *)(arg0 + 0x4C); }

s32 ModelAnim_HasCrossedFrame(ModelAnim *arg0, s16 arg1) { struct { s16 pad0; void *data; s32 frame; s32 speed; } *ptr = &arg0->curve; s32 temp_v0 = ptr->frame + ptr->speed; s32 arg = arg1 << 16; s32 var_a2; s32 v = ptr->speed; if (v >= 0) { var_a2 = ptr->frame < arg; if (var_a2 != 0) var_a2 = temp_v0 >= arg; } else { var_a2 = arg < ptr->frame; if (var_a2 != 0) var_a2 = arg >= temp_v0; } return var_a2; }

s32 ModelAnim_IsAnimationDone(ModelAnim *arg0) { return ModelAnim_HasCrossedFrame(arg0, ((EventData *)arg0->curve.data)->frameCount - 1); }

s32 ModelAnim_IsFinished(Func3EC34 *arg0) { return arg0->value48 >= ((*(u16 *)(arg0->value44 + 0xA) - 1) << 16); }

s32 func_8003EC54(Func3EC54 *arg0) { s32 value = arg0->value48 + arg0->value4C; return (s16)(value >> 16); }

s32 ModelAnim_ResolveEventIndex(s32 arg0, EventIndex* arg1, s32 arg2) { EventIndex* temp_v0 = &arg1[arg2]; s32 ret; if (arg0 < temp_v0->keyCount) { ret = arg0 + temp_v0->baseIndex; } else { ret = (temp_v0->baseIndex + temp_v0->keyCount) - 1; } return ret; }

s16 ModelAnim_AdvanceEventFrame(S1_unk_D_86002F58_004_000_054* arg0, u16 arg1) {
    s16 var_v1;
    S1_unk_D_86002F58_004_000_054_004* temp_v0;

    var_v1 = arg0->unk_08;
    temp_v0 = arg0->unk_04;

    if (arg0->unk_0A != arg1) {
        var_v1 += 1;
        if (var_v1 >= temp_v0->unk_0A) {
            if (temp_v0->unk_00 & 2) {
                var_v1 = temp_v0->unk_0A - 1;
            } else {
                var_v1 = temp_v0->unk_06;
            }
        }
    }
    return var_v1;
}

 void ModelAnim_ResetEventContext(void) { D_80126410 = -1; }

void ModelAnim_BeginEventContext(S1_unk_D_86002F58_004_000_054 *state, u16 renderFrame, s32 advance) {
    S1_unk_D_86002F58_004_000_054_004 *data;
    SceneEventContext *context;
    data = state->unk_04;
    D_80126410++;
    if (D_80126410 < 2) {
        context = &((SceneEventContext *)D_801263F0)[D_80126410];
        if (state->unk_04 != NULL) {
            if (advance != 0 && (*(u16 *)((u8 *)state + 2) & 1) == 0) {
                state->unk_08 = ModelAnim_AdvanceEventFrame(state, renderFrame);
            }
            state->unk_0A = renderFrame;
            context->active = 1;
            context->frame = state->unk_08;
            context->data = data;
            context->indices = func_80003240(data->unk_0C);
            context->values = func_80003240(data->unk_10);
            if (context->frame < 0) {
                context->frame = 0;
            }
        } else {
            context->active = 0;
        }
    }
}

 void ModelAnim_EndEventContext(void) { if (D_80126410 >= 0) { D_80126410--; } }

void func_8003EE20(s32 *arg0, s32 arg1, s32 arg2) {
    u8 *record;
    s32 index;
    if (D_80126410 < 0) { return; }
    if (D_80126410 >= 2) { return; }
    record = D_801263F0 + (D_80126410 * 0x10);
    if (record[0] != 1) { return; }
    if (arg2 < 0) { return; }
    if (arg2 >= (*((u16 *) ((*((u32 *) (record + 4))) + 8)))) { return; }
    ;
    *arg0 = ((*((u8 *) ((*((u32 *) (record + 0xC))) + ModelAnim_ResolveEventIndex(*((s16 *) (record + 2)), (void *) (*((u32 *) (record + 8))), arg2)))) * 12) + arg1;
}

void ModelAnim_ClearEventTrack(u8 *arg0) { *(s16 *)(arg0 + 0x54) = -1; *(s32 *)(arg0 + 0x58) = 0; }

s16 ModelAnim_BindEventTrack(S1_unk_D_86002F58_004_000* arg0, s16 arg1, s32 arg2) {
    S1_unk_D_86002F58_004_000_054_004* temp_v0 = func_80003240(arg2);
    S1_unk_D_86002F58_004_000_054* ptr = &arg0->unk_054;

    if ((temp_v0 != ptr->unk_04) || (arg1 != ptr->unk_00)) {
        ptr->unk_00 = arg1;
        ptr->unk_04 = temp_v0;
        ptr->unk_08 = temp_v0->unk_04 - 1;
    }

    return ptr->unk_08;
}

void ModelAnim_SetEventFrame(u8 *arg0, s16 value) { *(s16 *)(arg0 + 0x5C) = value - 1; }

void func_8003EF60(u8 *arg0) { *(u16 *)(arg0 + 0x56) |= 1; }

void func_8003EF70(u8 *arg0) { *(u16 *)(arg0 + 0x56) &= (u16)~1; }

s32 ModelAnim_IsEventFrame(u8 *arg0, s16 value) { return value == *(s16 *)(arg0 + 0x5C) + 1; }

s32 ModelAnim_IsEventTrackNearEnd(u8 *arg0) { return *(u16 *)(*(s32 *)(arg0 + 0x58) + 0xA) == *(s16 *)(arg0 + 0x5C) + 2; }

s32 ModelAnim_IsEventTrackDone(u8 *arg0) { return *(u16 *)(*(s32 *)(arg0 + 0x58) + 0xA) == *(s16 *)(arg0 + 0x5C) + 1; }

#endif
