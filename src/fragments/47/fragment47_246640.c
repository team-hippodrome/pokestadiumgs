#include "global.h"

#ifdef VERSION_US
extern void *func_87C00160(void *, void *, void *);
extern f64 func_87C00208(void *, void *);
extern f64 func_87C00664(void *);
extern f64 func_87C0068C(void *);
extern void *func_87C00198(void *, void *, void *);
extern void *func_87C002A8(void *, void *, f64);

f64 func_86000020(u8 *arg0, u8 *arg1, f64 horizon) {
    f64 closest_time;
    f64 dot;
    f64 speed_squared;
    struct {
        f64 x;
        f64 y;
        f64 z;
    } separation, relative_velocity, projected;

    func_87C00160(&separation, arg1, arg0);
    func_87C00160(&relative_velocity, arg1 + 0x18, arg0 + 0x18);
    relative_velocity.y = 0.0;
    separation.y = 0.0;
    dot = func_87C00208(&separation, &relative_velocity);
    speed_squared = func_87C00664(&relative_velocity);
    if (speed_squared < 0.01) {
        return func_87C0068C(&separation);
    } else {
        closest_time = -dot / speed_squared;
        if (closest_time <= 0.05) {
            return func_87C0068C(&separation);
        } else {
            if (horizon <= closest_time) {
                func_87C002A8(&projected, &relative_velocity, horizon);
                func_87C00198(&projected, &separation, &projected);
                return func_87C0068C(&projected);
            } else {
                //!bug The negative product increases the squared distance.
                return sqrtf((f32)(func_87C00664(&separation) - (closest_time * dot)));
            }
        }
    }
}
#endif

#ifdef VERSION_US
s32 func_86000170(u8 *object, s32 flag_a, s32 flag_b, f64 horizon) {
    static f64 radius_margin = 3.0;
    s32 offset;
    u8 *other;

    if (flag_a == 0 && flag_b == 0) {
        return 0;
    }
    if (*(s32 *)(object + 0x1828) != 3) {
        return 0;
    }
    offset = 0;
    do {
        other = *(u8 **)(object + 0x1870) + offset;
        if (*(s32 *)(other + 0x1810) == *(s32 *)(object + 0x1810)) {
            goto next_object;
        }
        if (*(s32 *)(other + 0x1828) != 3) {
            goto next_object;
        }
        if (flag_a == 0 && *(s32 *)(other + 0x1824) == 0) {
            goto next_object;
        }
        if (flag_b == 0 && *(s32 *)(other + 0x1824) != 0) {
            goto next_object;
        }
        if (func_86000020(object, other, horizon) <
            *(f64 *)(other + 0x17C8) + *(f64 *)(object + 0x17C8) + radius_margin) {
            return 1;
        }
next_object:
        offset += 6552;
    } while (offset != 26208);
    return 0;
}

typedef struct {
    f64 x;
    f64 y;
    f64 z;
} Fragment47SteeringVector;

typedef struct {
    f32 threshold;
    f32 probability;
    f32 speed;
    u32 flags;
} Fragment47SteeringConfig;

Fragment47SteeringVector D_8600D158 = {0.0, 0.0, 0.0};
Fragment47SteeringVector D_8600D170 = {0.0, 0.0, 0.0};
Fragment47SteeringConfig D_8600D188 = {0.65f, 0.00605f, 28.0f, 0xF3C00000};
f64 D_8600D198 = 250.0;

#endif

void func_860002A0(void) {
}

#ifdef VERSION_US

u8 *func_860002A8(u8 *arg0, s32 flag_a, s32 flag_b, f64 horizon) {
    f64 best_distance;
    u8 *closest;
    s32 offset;
    u8 *other;

    closest = NULL;
    best_distance = 10000000.0;
    if (flag_a == 0 && flag_b == 0) {
        return NULL;
    }
    if (*(s32 *)(arg0 + 0x1828) != 3) {
        return NULL;
    }
    offset = 0;
    do {
        other = *(u8 **)(arg0 + 0x1870) + offset;
        if (*(s32 *)(other + 0x1810) == *(s32 *)(arg0 + 0x1810)) {
            goto next_object;
        }
        if (*(s32 *)(other + 0x1828) != 3) {
            goto next_object;
        }
        if (flag_a == 0 && *(s32 *)(other + 0x1824) == 0) {
            goto next_object;
        }
        if (flag_b == 0 && *(s32 *)(other + 0x1824) != 0) {
            goto next_object;
        }
        {
            f64 distance = func_86000020(arg0, other, horizon);
            if (distance < best_distance) {
                best_distance = distance;
                closest = other;
            }
        }
next_object:
        offset += 0x1998;
    } while (offset != 0x6660);
    return closest;
}
#endif

#ifdef VERSION_US
u8 *func_860003DC(u8 *arg0, s32 flag_a, s32 flag_b) {
    u8 *closest;
    s32 best_score;
    s32 i;
    u8 *other;

    closest = NULL;
    best_score = 0;
    i = 0;
    do {
        other = *(u8 **)(arg0 + 0x1870) + i * 0x1998;
        if (*(s32 *)(other + 0x1810) == *(s32 *)(arg0 + 0x1810)) {
            goto next_object;
        }
        if (*(s32 *)(other + 0x1828) != 3) {
            goto next_object;
        }
        if (flag_a == 0 && *(s32 *)(other + 0x1824) == 0) {
            goto next_object;
        }
        if (flag_b == 0 && *(s32 *)(other + 0x1824) != 0) {
            goto next_object;
        }
        if (*(s32 *)(other + 0x1814) < best_score) {
            best_score = *(s32 *)(other + 0x1814);
            closest = other;
        }
next_object:
        i++;
    } while (i != 4);
    return closest;
}
#endif

#ifdef VERSION_US
extern void * func_87C00160(void *, void *, void *);
extern f64 MathUtil_Atan2d_fragment48(f64,f64);
f32 func_860004C8(void *arg0, void *arg1) {
    u8 value[0x18];
    func_87C00160(value, arg1, arg0);
    return (f32)MathUtil_Atan2d_fragment48(*(f64 *)value, *(f64 *)(value + 0x10));
}
void func_860004C8_padding(void) {}
void func_860004C8_padding2(void) {}
#endif

#ifdef VERSION_US
extern u8 D_8600DE30[];
extern void *func_87C00718(void *, void *, f64);



void func_8600050C(u8 *arg0, void *arg1, void *arg2, f64 arg3, f32 arg4, f32 *arg5, f32 *arg6) {
    struct {
        f64 x;
        f64 y;
        f64 z;
    } position, direction, normal;

    func_87C00160(&position, arg2, arg0 + 0x18);
    position.y = 0.0;
    func_87C00160(&direction, arg1, arg0);
    direction.y = 0.0;
    // The caller also passes this quotient as arg3; the body recomputes it from
    // the object at arg0 + 0x1870 instead and leaves the f64 slot unread.
    func_87C00160(&direction, &direction, func_87C002A8(&normal, &position,
        *(f64 *)(*(u8 **)(arg0 + 0x1870) + 0x6890) / (f64)*(s32 *)D_8600DE30 * 1.0f));
    if ((f64)(arg4 * arg4) < func_87C00664(&direction)) {
        func_87C00718(&direction, &direction, arg4);
    }
    *arg5 = direction.x;
    *arg6 = -direction.z;
}
#endif

#ifdef VERSION_US
extern f64 MathUtil_Atan2d_fragment48(f64, f64);
extern f64 fragment48_main(f64);
extern f32 MathUtil_Random_ZeroOne(void);
extern void *func_87C00718(void *, void *, f64);
extern f32 __sinf(f32);
extern f32 __cosf(f32);
extern u8 D_8600DE30[];



s32 func_8600062C(u8 *arg0, f32 *arg1, f32 *arg2) {
    f64 one;
    f64 zero;
    Fragment47SteeringVector position;
    Fragment47SteeringVector velocity;
    f64 ratio;
    s32 result;
    u8 *other;
    Fragment47SteeringConfig *config;
    Fragment47SteeringConfig *override;
    Fragment47SteeringVector separation;
    u8 *nearby;
    f32 distance;
    u8 *target;
    f64 angle;
    Fragment47SteeringVector direction;
    s32 pad; /* FAKE: frame pad; without it the score is 18 */

    override = *(Fragment47SteeringConfig **)(arg0 + 0x1894);
    if (override != NULL) {
        config = override;
    } else {
        config = &D_8600D188;
    }
    one = 1.0;
    zero = 0.0;
    position = D_8600D158;
    velocity = D_8600D170;
    if (0) { /* dead: reserves result's spill slot (0x60) ahead of the sqrt temp (0x5C) */
        result = func_86000170(arg0, 0, 0, 0.0) ^ (MathUtil_Random_ZeroOne() < config->probability);
    }
    distance = sqrtf((f32)(*(f64 *)(arg0 + 0x10) * *(f64 *)(arg0 + 0x10) +
                           *(f64 *)arg0 * *(f64 *)arg0));
    other = NULL;
    if (*(s32 *)(arg0 + 0x1828) != 3) {
        nearby = func_860002A8(arg0, 1, 1, 0.1f);
        if (nearby != NULL) {
            func_87C00160(&separation, arg0, nearby);
            separation.y = 0.0;
            ratio = func_87C0068C(&separation);
            if (ratio < (*(f64 *)(nearby + 0xC8) + *(f64 *)(arg0 + 0xC8)) * 2.0) {
                *arg1 = (f32)((-separation.x / ratio) * 64.0);
                *arg2 = (f32)((separation.z / ratio) * 64.0);
            }
        }
        return 0;
    }
    ratio = (f64)sqrtf((f32)(*(f64 *)(arg0 + 0x10) * *(f64 *)(arg0 + 0x10) + *(f64 *)arg0 * *(f64 *)arg0)) / *(f64 *)(*(u8 **)(arg0 + 0x1870) + 0x66C0);
    result = func_86000170(arg0, config->flags >> 31, (config->flags << 1) >> 31,
                           0.08f) ^ (MathUtil_Random_ZeroOne() < config->probability);
    if (ratio < (f64)config->threshold) {
        if (*(f64 *)(arg0 + 0x17E8) > 0.0) {
            target = func_860002A8(arg0, (config->flags << 2) >> 31,
                                   (config->flags << 3) >> 31, 0.3f);
            if (target != NULL &&
                0.01 < (*(f64 *)(arg0 + 0x10) * *(f64 *)(arg0 + 0x10) +
                              *(f64 *)arg0 * *(f64 *)arg0)) {
                MathUtil_Atan2d_fragment48(-*(f64 *)arg0, -*(f64 *)(arg0 + 0x10));
                angle = fragment48_main(
                    fragment48_main((f64)(func_860004C8(arg0, target) + 3.1415927f)) *
                        (one - zero) + zero);
                *arg2 = -__cosf((f32)angle) * config->speed;
                *arg1 = __sinf((f32)angle) * config->speed;
                return result;
            }
        } else {
            other = func_860003DC(arg0, (config->flags << 4) >> 31,
                                  (config->flags << 5) >> 31);
            if (other == NULL) {
                other = func_860002A8(arg0, (config->flags << 6) >> 31,
                                      *(u8 *)((u8 *)config + 0xC) & 1, 0.3f);
            }
            if (other == NULL) {
                other = func_860002A8(arg0, (u32)*(u8 *)((u8 *)config + 0xD) >> 7,
                                      (config->flags << 9) >> 31, 0.02f);
            }
        }
    }
    if (other != NULL) {
        direction = *(Fragment47SteeringVector *)other;
        direction.y = 0.0;
        func_87C00718(&direction, &direction, -*(f64 *)(other + 0x17C8));
        func_87C00198(&position, other, &direction);
        velocity = *(Fragment47SteeringVector *)(other + 0x18);
    }
    func_8600050C(arg0, &position, &velocity,
                  *(f64 *)(*(u8 **)(arg0 + 0x1870) + 0x6890) / *(s32 *)D_8600DE30,
                  config->speed, arg1, arg2);
    return result;
}
#endif

#ifdef VERSION_US
const Fragment47SteeringVector D_8600D4D0 = { 0.0, 0.0, 0.0 };
s32 func_86000AE0(u8 *arg0, f32 *arg1, f32 *arg2) {
    Fragment47SteeringVector vec1;
    Fragment47SteeringVector vec2; // FAKE: preserves the retail stack frame.

    func_87C00160(&vec1, arg0 + 0x1878, arg0);
    func_87C002A8(&vec1, &vec1, 0.02f);
    func_87C00198(arg0, arg0, &vec1);
    func_8600050C(arg0, arg0 + 0x1878, &D_8600D4D0,
                  *(f64 *)(*(u8 **)(arg0 + 0x1870) + 0x6890) / *(s32 *)D_8600DE30,
                  D_8600D198, arg1, arg2);
    return 0;
}
#endif

#ifdef VERSION_US
s32 func_86000B9C(u8 *arg0, s32 arg1, s32 arg2) {
    return 0;
}
#endif
