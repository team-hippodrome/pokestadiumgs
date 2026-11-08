#include "global.h"


#ifdef VERSION_US
void func_87C037B0(void) {}
void func_87C037B0_padding(void) {}

typedef struct F48Vec3f { f32 x, y, z; } F48Vec3f;
typedef union F48MtxF {
    f32 mf[4][4];
    struct {
        f32 xx, yx, zx, wx,
            xy, yy, zy, wy,
            xz, yz, zz, wz,
            xw, yw, zw, ww;
    };
} F48MtxF;
typedef struct F48Projection {
    Mtx *projection;
    u16 perspective_norm;
    f32 fovy;
    f32 aspect;
    f32 near_plane;
    f32 far_plane;
    f32 perspective_scale;
} F48Projection;
typedef struct F48Viewport {
    Vp *viewport;
    s16 x, y, width, height;
} F48Viewport;
typedef struct F48CameraView {
    f32 (*view_matrix)[4];
    f32 view[4][4];
    LookAt *look_at;
    F48Vec3f eye;
    F48Vec3f at;
    F48Vec3f up;
} F48CameraView;
typedef struct F48Camera {
    u8 pad[0x18];
    F48Viewport viewport;
    F48Projection projection;
    Mtx *ortho;
    f32 left, right, bottom, top, ortho_near, ortho_far, ortho_scale;
    F48CameraView camera;
} F48Camera;

extern f32 D_87C04250;
extern void guOrthoF(f32 mf[4][4], f32 l, f32 r, f32 b, f32 t, f32 n, f32 f, f32 scale);
extern void guPerspectiveF(f32 mf[4][4], u16 *perspNorm, f32 fovy, f32 aspect, f32 near, f32 far, f32 scale);
extern void guLookAtReflectF(f32 mf[4][4], LookAt *l, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp, f32 yUp, f32 zUp);
extern void guMtxCatF(f32 m[4][4], f32 n[4][4], f32 r[4][4]);
extern void MtxF_Copy(u32 *dest, u32 *src);
extern void MtxF_Identity(f32 *arg0);



void func_87C037C0(u8 *arg0, F48Camera *camera) {
    F48MtxF ortho;
    F48MtxF persp;
    F48MtxF view;
    LookAt look_at;
    u16 persp_norm;
    F48Projection *projection;
    F48CameraView *camera_view;
    F48Viewport *viewport;
    F48Camera *cam;
    F48MtxF translate;
    F48MtxF scale;

    cam = camera;
    projection = &camera->projection;
    camera_view = &camera->camera;
    viewport = &camera->viewport;

    guOrthoF(ortho.mf, cam->left, cam->right, cam->bottom, cam->top, cam->ortho_near, cam->ortho_far, cam->ortho_scale);
    guPerspectiveF(persp.mf, &persp_norm, projection->fovy, projection->aspect, projection->near_plane, projection->far_plane, projection->perspective_scale);
    guLookAtReflectF(view.mf, &look_at, camera_view->eye.x, camera_view->eye.y, camera_view->eye.z, camera_view->at.x, camera_view->at.y, camera_view->at.z, camera_view->up.x, camera_view->up.y, camera_view->up.z);

    MtxF_Copy((u32 *)(arg0 + 0x40), (u32 *)view.mf);
    guMtxCatF((f32 (*)[4])(arg0 + 0x40), persp.mf, (f32 (*)[4])(arg0 + 0x40));
    MtxF_Copy((u32 *)arg0, (u32 *)(arg0 + 0x40));

    MtxF_Identity(translate.mf);
    translate.xx = viewport->width * 0.5f;
    translate.yy = (f32)(-viewport->height) * 0.5f;
    translate.zz = D_87C04250;
    translate.xw = (f32)viewport->x + (f32)viewport->width * 0.5f;
    translate.yw = (f32)viewport->y + (f32)viewport->height * 0.5f;
    translate.xw = (f32)viewport->x + (f32)viewport->width * 0.5f;
    translate.zw = D_87C04250;
    guMtxCatF((f32 (*)[4])(arg0 + 0x40), translate.mf, (f32 (*)[4])(arg0 + 0x40));

    MtxF_Identity(scale.mf);
    scale.xx = 64.0f;
    scale.yy = -64.0f;
    guMtxCatF((f32 (*)[4])arg0, scale.mf, (f32 (*)[4])arg0);
}

typedef struct unk_func_87C039D4 {
    f32 x;
    f32 y;
    f32 z;
} unk_func_87C039D4;

// Multiplies the point arg1 (as a row vector with w = 1) by the 4x4 float
// matrix at arg0 + 0x40, writes x, y and z divided by the resulting w to arg2,
// and returns the matrix's first element times x, divided by w.
f32 func_87C039D4(u8 *arg0, unk_func_87C039D4 *arg1, f32 *arg2) {
    unk_func_87C039D4 point;
    f64 w;

    point = *arg1;
    w = *(f32 *)(arg0 + 0x4C) * point.x + *(f32 *)(arg0 + 0x5C) * point.y + *(f32 *)(arg0 + 0x6C) * point.z + *(f32 *)(arg0 + 0x7C);
    arg2[0] = (*(f32 *)(arg0 + 0x40) * point.x + *(f32 *)(arg0 + 0x50) * point.y + *(f32 *)(arg0 + 0x60) * point.z + *(f32 *)(arg0 + 0x70)) / w;
    arg2[1] = (*(f32 *)(arg0 + 0x44) * point.x + *(f32 *)(arg0 + 0x54) * point.y + *(f32 *)(arg0 + 0x64) * point.z + *(f32 *)(arg0 + 0x74)) / w;
    arg2[2] = (*(f32 *)(arg0 + 0x48) * point.x + *(f32 *)(arg0 + 0x58) * point.y + *(f32 *)(arg0 + 0x68) * point.z + *(f32 *)(arg0 + 0x78)) / w;
    return *(f32 *)(arg0 + 0x40) * point.x / w;
}

/* mkdraft:func_87C03B10 begin */
// Return the projected x numerator divided by the homogeneous w coordinate.
// The dot product is evaluated as f32 before the f64 division.
f32 func_87C03B10(u8 *arg0, f32 *arg1) {
    f64 w;

    w = *(f32 *)(arg0 + 0x4C) * arg1[0] + *(f32 *)(arg0 + 0x5C) * arg1[1] + *(f32 *)(arg0 + 0x6C) * arg1[2] + *(f32 *)(arg0 + 0x7C);
    return (arg1[0] * *(f32 *)(arg0 + 0x40)) / w;
}
/* mkdraft:func_87C03B10 end */

/* mkdraft:func_87C03B60 begin */
extern f64 D_87C04258;
extern f64 D_87C04260;
extern f64 D_87C04268;

// Projects the point arg1 through the matrix at arg0 and stores the clamped x
// and y quotients in arg2[0] and arg2[1].
//
// The matrix is read as four columns of four f32s, 0x10 bytes apart: x uses
// +0x00/+0x10/+0x20/+0x30, y uses +0x04/+0x14/+0x28/+0x34 and the divisor (w)
// uses +0x0C/+0x1C/+0x2C/+0x3C. The y z-term reads +0x28, not +0x24, so the
// four reads for y are not a contiguous column; the ROM loads +0x28 and never
// +0x24.


void func_87C03B60(u8 *arg0, unk_func_87C039D4 *arg1, s8 *arg2) {
    unk_func_87C039D4 point;
    f64 det;
    f64 quot_x;
    f64 quot_y;

    point = *arg1;
    det = (f64)(((*(f32 *)(arg0 + 0xC) * point.x +
                  *(f32 *)(arg0 + 0x1C) * point.y) +
                 *(f32 *)(arg0 + 0x2C) * point.z) +
                *(f32 *)(arg0 + 0x3C));
    quot_x = (f64)((((*(f32 *)(arg0 + 0x0) * point.x +
                      *(f32 *)(arg0 + 0x10) * point.y) +
                     *(f32 *)(arg0 + 0x20) * point.z) +
                    *(f32 *)(arg0 + 0x30)) /
                   det);
    quot_y = (f64)((((*(f32 *)(arg0 + 0x4) * point.x +
                      *(f32 *)(arg0 + 0x14) * point.y) +
                     *(f32 *)(arg0 + 0x28) * point.z) +
                    *(f32 *)(arg0 + 0x34)) /
                   det);
    // FAKE: det is dead after the two divisions; reusing its stack home for the
    // lower clamp bound keeps the frame at 0x28. A separate f64 local claims
    // its own home, grows the frame to 0x30 and scores 39.
    det = D_87C04258;
    if (quot_x <= det) {
        *arg2 = -127;
    } else if (D_87C04260 <= quot_x) {
        *arg2 = 127;
    } else {
        *arg2 = (s8)(s32)quot_x;
    }
    if (quot_y <= det) {
        *(s8 *)(arg2 + 1) = -127;
    } else if (D_87C04268 <= quot_y) {
        *(s8 *)(arg2 + 1) = 127;
    } else {
        *(s8 *)(arg2 + 1) = (s8)(s32)quot_y;
    }
}
/* mkdraft:func_87C03B60 end */
#endif
