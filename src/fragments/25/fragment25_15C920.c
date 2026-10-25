#include "global.h"


#ifdef VERSION_US
extern f32 D_82104130;
extern f32 D_82104134;
extern f64 D_82104138;
extern f64 D_82104140;
extern f64 D_82104148;
extern f64 D_82104150;
f32 func_821028E0(f32 arg0, f32 arg1) {
    f32 ratio;
    f32 reduced;
    f32 fraction;
    s32 i;

    if ((arg1 == 0.0f) && (arg0 == 0.0f)) {
        return 0.0f;
    }

    if (arg1 == 0.0f) {
        if (arg0 > 0.0f) {
            return D_82104130;
        }
        return D_82104134;
    }

    ratio = arg0 / arg1;
    reduced = (ratio >= 0.0f) ? ratio : -ratio;
    reduced = (reduced <= 1.0f) ? ratio : 1.0f / ratio;
    fraction = 0.0f;

    for (i = 14; i > 0; i--) {
        fraction = (i * i) * reduced * reduced / ((2 * i + 1) + fraction);
    }

    reduced = reduced / (1.0f + fraction);

    if (ratio > 1.0f) {
        reduced = D_82104138 - reduced;
    }

    if (ratio < -1.0f) {
        reduced = D_82104140 - reduced;
    }

    if (arg1 > 0.0f) {
        return reduced;
    }

    if (arg0 > 0.0f) {
        return reduced + D_82104148;
    }

    return reduced - D_82104150;
}
#endif
