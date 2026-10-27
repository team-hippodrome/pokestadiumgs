#include "global.h"


#ifdef VERSION_US
extern void MtxF_Multiply(void *, void *, void *);
void func_87F06094(f32 *arg0, u16 *arg1);
void func_87F05FB0(f32 out[4][4], f32 basis[4][4], f32 *pos, u16 *angles, void *arg4) {
    f32 tmp[4][4];
    f32 rot[4][4];

    func_87F06094(tmp[0], angles);
    rot[0][0] = basis[0][0];
    rot[0][1] = basis[1][0];
    rot[0][2] = basis[2][0];
    rot[0][3] = 0.0f;
    rot[1][0] = basis[0][1];
    rot[1][1] = basis[1][1];
    rot[1][2] = basis[2][1];
    rot[1][3] = 0.0f;
    rot[2][0] = basis[0][2];
    rot[2][1] = basis[1][2];
    rot[2][2] = basis[2][2];
    rot[2][3] = 0.0f;
    rot[3][0] = 0.0f;
    rot[3][1] = 0.0f;
    rot[3][2] = 0.0f;
    rot[3][3] = 1.0f;
    MtxF_Multiply(out, tmp, rot);
    out[3][0] = pos[0];
    out[3][1] = pos[1];
    out[3][2] = pos[2];
    out[3][3] = 1.0f;
}

/* mkdraft:func_87F06094 begin */
extern f32 D_80087E50[];
extern f32 D_80088E50[];

void func_87F06094(f32 *arg0, u16 *arg1) {
    f32 sx;
    f32 cx;
    f32 sy;
    f32 cy;
    f32 sz;
    f32 cz;
    volatile f32 t0;
    volatile f32 t1;

    sx = D_80087E50[arg1[0] >> 4];
    cx = D_80088E50[arg1[0] >> 4];
    sy = D_80087E50[arg1[1] >> 4];
    cy = D_80088E50[arg1[1] >> 4];
    sz = D_80087E50[arg1[2] >> 4];
    cz = D_80088E50[arg1[2] >> 4];

    arg0[0] = cy * cz;
    arg0[1] = cy * sz;
    arg0[2] = -sy;
    arg0[3] = 0.0f;
    t0 = sx * sy;
    arg0[4] = t0 * cz - cx * sz;
    arg0[5] = t0 * sz + cx * cz;
    arg0[6] = sx * cy;
    arg0[7] = 0.0f;
    t1 = cx * sy;
    arg0[8] = t1 * cz + sx * sz;
    arg0[9] = t1 * sz - sx * cz;
    arg0[10] = cx * cy;
    arg0[11] = 0.0f;
    arg0[12] = 0.0f;
    arg0[13] = 0.0f;
    arg0[14] = 0.0f;
    arg0[15] = 1.0f;
}
/* mkdraft:func_87F06094 end */
#endif
