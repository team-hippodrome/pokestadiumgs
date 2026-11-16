#include "229E0.h"

#ifdef VERSION_US

void func_80035700(u32 seed) {
    D_80124D50 = seed;
}

u32 func_8003570C(void) {
    D_80124D50 = D_80124D50 * 0x0019660D + 0x3C6EF35F;
    return D_80124D50;
}

Color3573C *Color_SetRGB(Color3573C *arg0, u8 r, u8 g, u8 b) {
    arg0->r = r;
    arg0->g = g;
    arg0->b = b;
    return arg0;
}

Color3575C *Color_SetRGBA(Color3575C *arg0, u8 r, u8 g, u8 b, u8 a) {
    arg0->r = r;
    arg0->g = g;
    arg0->b = b;
    arg0->a = a;
    return arg0;
}

Vec3f35784 *Vec3f_SetComponents(Vec3f35784 *arg0, f32 x, f32 y, f32 z) {
    arg0->x = x;
    arg0->y = y;
    arg0->z = z;
    return arg0;
}

Vec3f357A8 *Vec3f_SetComponentsDuplicate(Vec3f357A8 *arg0, f32 x, f32 y, f32 z) {
    arg0->x = x;
    arg0->y = y;
    arg0->z = z;
    return arg0;
}

Vec3f357CC *Vec3f_AddInPlace(Vec3f357CC *arg0, Vec3f357CC *arg1) {
    arg0->x += arg1->x;
    arg0->y += arg1->y;
    arg0->z += arg1->z;
    return arg0;
}

Vec3f35804 *Vec3f_Add(Vec3f35804 *arg0, Vec3f35804 *arg1, Vec3f35804 *arg2) {
    arg0->x = arg1->x + arg2->x;
    arg0->y = arg1->y + arg2->y;
    arg0->z = arg1->z + arg2->z;
    return arg0;
}

Vec3f3583C *Vec3f_SubtractInPlace(Vec3f3583C *arg0, Vec3f3583C *arg1) {
    arg0->x -= arg1->x;
    arg0->y -= arg1->y;
    arg0->z -= arg1->z;
    return arg0;
}

Vec3f35874 *Vec3f_Subtract(Vec3f35874 *arg0, Vec3f35874 *arg1, Vec3f35874 *arg2) {
    arg0->x = arg1->x - arg2->x;
    arg0->y = arg1->y - arg2->y;
    arg0->z = arg1->z - arg2->z;
    return arg0;
}

Vec3f358AC *Vec3f_FromVec3s(Vec3f358AC *arg0, Vec3s358AC *arg1) {
    arg0->x = arg1->x;
    arg0->y = arg1->y;
    arg0->z = arg1->z;
    return arg0;
}

Vec3f358F0 *Vec3f_CrossProductFromPoints(Vec3f358F0 *arg0, Vec3f358F0 *arg1, Vec3f358F0 *arg2, Vec3f358F0 *arg3) {
    arg0->x = ((arg2->y - arg1->y) * (arg3->z - arg2->z)) - ((arg3->y - arg2->y) * (arg2->z - arg1->z));
    arg0->y = ((arg2->z - arg1->z) * (arg3->x - arg2->x)) - ((arg3->z - arg2->z) * (arg2->x - arg1->x));
    arg0->z = ((arg2->x - arg1->x) * (arg3->y - arg2->y)) - ((arg3->x - arg2->x) * (arg2->y - arg1->y));
    return arg0;
}

Vec3f359A0 *Vec3f_CrossProduct(Vec3f359A0 *out, Vec3f359A0 *a, Vec3f359A0 *b) {
    out->x = (a->y * b->z) - (b->y * a->z);
    out->y = (a->z * b->x) - (b->z * a->x);
    out->z = (a->x * b->y) - (b->x * a->y);
    return out;
}

Vec3f35A10 *func_80035A10(Vec3f35A10 *arg0) {
    f32 scale = 1.0f / sqrtf((arg0->x * arg0->x) + (arg0->y * arg0->y) + (arg0->z * arg0->z));
    arg0->x *= scale; arg0->y *= scale; arg0->z *= scale; return arg0;
}

void *Vec3s_SetComponents(void *arg0, s16 arg1, s16 arg2, s16 arg3) {
    (*(s16 *)((u8 *)(arg0) + (0))) = arg1;
    (*(s16 *)((u8 *)(arg0) + (2))) = arg2;
    (*(s16 *)((u8 *)(arg0) + (4))) = arg3;
    return arg0;
}

Vec3s35AA0 *Vec3s_AddInPlace(Vec3s35AA0 *arg0, Vec3s35AA0 *arg1) {
    arg0->x += arg1->x; arg0->y += arg1->y; arg0->z += arg1->z; return arg0;
}

Vec3s35AD8 *Vec3s_Add(Vec3s35AD8 *arg0, Vec3s35AD8 *arg1, Vec3s35AD8 *arg2) {
    arg0->x = arg1->x + arg2->x; arg0->y = arg1->y + arg2->y; arg0->z = arg1->z + arg2->z; return arg0;
}

Vec3s35B10 *Vec3s_SubtractInPlace(Vec3s35B10 *arg0, Vec3s35B10 *arg1) {
    arg0->x -= arg1->x; arg0->y -= arg1->y; arg0->z -= arg1->z; return arg0;
}

Vec3s35B48 *Vec3s_Subtract(Vec3s35B48 *arg0, Vec3s35B48 *arg1, Vec3s35B48 *arg2) {
    arg0->x = arg1->x - arg2->x; arg0->y = arg1->y - arg2->y; arg0->z = arg1->z - arg2->z; return arg0;
}

Vec3s35B80 *Vec3s_FromVec3f(Vec3s35B80 *arg0, Vec3f35B80 *arg1) {
    arg0->x = ROUND_MAX(arg1->x); arg0->y = ROUND_MAX(arg1->y); arg0->z = ROUND_MAX(arg1->z); return arg0;
}

void MtxF_Copy(u32 *dest, u32 *src) {
    if (dest != src) {
        s32 i; u32 *d = dest; u32 *s = src;
        for (i = 0; i < 16; i++) { *d++ = *s++; }
    }
}

void MtxF_Identity(f32 *arg0) {
    s32 i;
    f32 *dest;
    for (dest = arg0 + 1, i = 0; i < 14; dest++, i++) { *dest = 0.0f; }
    for (dest = arg0, i = 0; i < 4; dest += 5, i++) { *dest = 1.0f; }
}

void MtxF_SetTranslation(f32 *dest, f32 *source) {
    MtxF_Identity(dest);
    dest[12] = source[0];
    dest[13] = source[1];
    dest[14] = source[2];
}

void MtxF_SetLookAt(S1_MtxF *matrix, S1_Vec3f *from, S1_Vec3f *to, s16 view_angle) {
    f32 inverse_length;
    f32 dx;
    f32 dz;
    f32 x_col_y;
    f32 y_col_y;
    f32 z_col_y;
    f32 x_col_z;
    f32 y_col_z;
    f32 z_col_z;
    f32 x_col_x;
    f32 y_col_x;
    f32 z_col_x;

    dx = to->x - from->x;
    dz = to->z - from->z;

    inverse_length = -1.0 / sqrtf(dx * dx + dz * dz);
    dx *= inverse_length;
    dz *= inverse_length;

    y_col_y = D_80088E50[(u16)(view_angle) >> 4];
    x_col_y = D_80087E50[(u16)(view_angle) >> 4] * dz;
    z_col_y = -D_80087E50[(u16)(view_angle) >> 4] * dx;

    x_col_z = to->x - from->x;
    y_col_z = to->y - from->y;
    z_col_z = to->z - from->z;

    inverse_length = -1.0 / sqrtf(x_col_z * x_col_z + y_col_z * y_col_z + z_col_z * z_col_z);
    x_col_z *= inverse_length;
    y_col_z *= inverse_length;
    z_col_z *= inverse_length;

    x_col_x = y_col_y * z_col_z - z_col_y * y_col_z;
    y_col_x = z_col_y * x_col_z - x_col_y * z_col_z;
    z_col_x = x_col_y * y_col_z - y_col_y * x_col_z;

    inverse_length = 1.0 / sqrtf(x_col_x * x_col_x + y_col_x * y_col_x + z_col_x * z_col_x);

    x_col_x *= inverse_length;
    y_col_x *= inverse_length;
    z_col_x *= inverse_length;

    x_col_y = y_col_z * z_col_x - z_col_z * y_col_x;
    y_col_y = z_col_z * x_col_x - x_col_z * z_col_x;
    z_col_y = x_col_z * y_col_x - y_col_z * x_col_x;

    inverse_length = 1.0 / sqrtf(x_col_y * x_col_y + y_col_y * y_col_y + z_col_y * z_col_y);
    x_col_y *= inverse_length;
    y_col_y *= inverse_length;
    z_col_y *= inverse_length;

    matrix->mf[0][0] = x_col_x;
    matrix->mf[1][0] = y_col_x;
    matrix->mf[2][0] = z_col_x;
    matrix->mf[3][0] = -(from->x * x_col_x + from->y * y_col_x + from->z * z_col_x);

    matrix->mf[0][1] = x_col_y;
    matrix->mf[1][1] = y_col_y;
    matrix->mf[2][1] = z_col_y;
    matrix->mf[3][1] = -(from->x * x_col_y + from->y * y_col_y + from->z * z_col_y);

    matrix->mf[0][2] = x_col_z;
    matrix->mf[1][2] = y_col_z;
    matrix->mf[2][2] = z_col_z;
    matrix->mf[3][2] = -(from->x * x_col_z + from->y * y_col_z + from->z * z_col_z);

    matrix->mf[0][3] = 0.0f;
    matrix->mf[1][3] = 0.0f;
    matrix->mf[2][3] = 0.0f;
    matrix->mf[3][3] = 1.0f;
}

void MtxF_SetRotationTranslation(f32 matrix[4][4], Vec3s35AA0 *position, Vec3s35AA0 *rotation) {
    f32 sin_x;
    f32 cos_x;
    f32 sin_y;
    f32 cos_y;
    f32 sin_z;
    f32 cos_z;

    sin_x = D_80087E50[(u16)(rotation->x) >> 4];
    cos_x = D_80088E50[(u16)(rotation->x) >> 4];

    sin_y = D_80087E50[(u16)(rotation->y) >> 4];
    cos_y = D_80088E50[(u16)(rotation->y) >> 4];

    sin_z = D_80087E50[(u16)(rotation->z) >> 4];
    cos_z = D_80088E50[(u16)(rotation->z) >> 4];

    matrix[0][0] = cos_y * cos_z + (sin_x * sin_y) * sin_z;
    matrix[0][1] = -cos_y * sin_z + (sin_x * sin_y) * cos_z;
    matrix[0][2] = cos_x * sin_y;
    matrix[0][3] = position->x;

    matrix[1][0] = cos_x * sin_z;
    matrix[1][1] = cos_x * cos_z;
    matrix[1][2] = -sin_x;
    matrix[1][3] = position->y;

    matrix[2][0] = -sin_y * cos_z + (sin_x * cos_y) * sin_z;
    matrix[2][1] = sin_y * sin_z + (sin_x * cos_y) * cos_z;
    matrix[2][2] = cos_x * cos_y;
    matrix[2][3] = position->z;

    matrix[3][0] = 0.0f;
    matrix[3][1] = 0.0f;
    matrix[3][2] = 0.0f;
    matrix[3][3] = 1.0f;
}

void MtxF_SetRotationTranslationF(f32 matrix[4][4], Vec3f35784 *position, Vec3s35AA0 *rotation) {
    f32 sin_y;
    f32 cos_y;
    f32 sin_z;
    f32 cos_z;
    f32 sin_x;
    f32 cos_x;
    f32 product;

    sin_x = D_80087E50[(u16)(rotation->x) >> 4];
    cos_x = D_80088E50[(u16)(rotation->x) >> 4];

    sin_y = D_80087E50[(u16)(rotation->y) >> 4];
    cos_y = D_80088E50[(u16)(rotation->y) >> 4];

    sin_z = D_80087E50[(u16)(rotation->z) >> 4];
    cos_z = D_80088E50[(u16)(rotation->z) >> 4];

    product = sin_x * sin_y;
    matrix[0][0] = (cos_y * cos_z) + (product * sin_z);
    matrix[1][0] = (-cos_y * sin_z) + (product * cos_z);
    matrix[2][0] = cos_x * sin_y;
    matrix[3][0] = position->x;

    matrix[0][1] = cos_x * sin_z;
    matrix[1][1] = cos_x * cos_z;
    matrix[2][1] = -sin_x;
    matrix[3][1] = position->y;

    product = sin_x * cos_y;
    matrix[0][2] = (-sin_y * cos_z) + (product * sin_z);
    matrix[1][2] = (sin_y * sin_z) + (product * cos_z);
    matrix[2][2] = cos_x * cos_y;
    matrix[3][2] = position->z;

    matrix[0][3] = 0.0f;
    matrix[1][3] = 0.0f;
    matrix[2][3] = 0.0f;
    matrix[3][3] = 1.0f;
}

void MtxF_SetRotationAndTransformTranslation(f32 matrix[4][4], Vec3f35784 *position, Vec3s35AA0 *rotation) {
    f32 sin_x;
    f32 cos_x;
    f32 sin_y;
    f32 cos_y;
    f32 sin_z;
    f32 cos_z;

    sin_x = D_80087E50[(u16)(rotation->x) >> 4];
    cos_x = D_80088E50[(u16)(rotation->x) >> 4];
    sin_y = D_80087E50[(u16)(rotation->y) >> 4];
    cos_y = D_80088E50[(u16)(rotation->y) >> 4];
    sin_z = D_80087E50[(u16)(rotation->z) >> 4];
    cos_z = D_80088E50[(u16)(rotation->z) >> 4];

    matrix[0][0] = (cos_y * cos_z) + ((sin_x * sin_y) * sin_z);
    matrix[0][1] = (-cos_y * sin_z) + ((sin_x * sin_y) * cos_z);
    matrix[0][2] = cos_x * sin_y;

    matrix[1][0] = cos_x * sin_z;
    matrix[1][1] = cos_x * cos_z;
    matrix[1][2] = -sin_x;

    matrix[2][0] = (-sin_y * cos_z) + ((sin_x * cos_y) * sin_z);
    matrix[2][1] = (sin_y * sin_z) + ((sin_x * cos_y) * cos_z);
    matrix[2][2] = cos_x * cos_y;

    matrix[3][0] = (matrix[0][0] * position->x) + (matrix[1][0] * position->y) + (matrix[2][0] * position->z);
    matrix[3][1] = (matrix[0][1] * position->x) + (matrix[1][1] * position->y) + (matrix[2][1] * position->z);
    matrix[3][2] = (matrix[0][2] * position->x) + (matrix[1][2] * position->y) + (matrix[2][2] * position->z);

    matrix[0][3] = matrix[1][3] = matrix[2][3] = 0.0f;
    matrix[3][3] = 1.0f;
}

void MtxF_SetRotationScaleTranslation(S1_MtxF *matrix, S1_Vec3f *position, S1_Vec3s *rotation, S1_Vec3f *scale) {
    f32 sin_x;
    f32 cos_x;
    f32 sin_y;
    f32 cos_y;
    f32 sin_z;
    f32 cos_z;

    sin_x = D_80087E50[(u16)(rotation->x) >> 4];
    cos_x = D_80088E50[(u16)(rotation->x) >> 4];

    sin_y = D_80087E50[(u16)(rotation->y) >> 4];
    cos_y = D_80088E50[(u16)(rotation->y) >> 4];

    sin_z = D_80087E50[(u16)(rotation->z) >> 4];
    cos_z = D_80088E50[(u16)(rotation->z) >> 4];

    matrix->mf[0][0] = (cos_y * cos_z) * scale->x;
    matrix->mf[0][1] = (cos_y * sin_z) * scale->x;
    matrix->mf[0][2] = (-sin_y) * scale->x;
    matrix->mf[0][3] = 0.0f;

    matrix->mf[1][0] = (sin_x * sin_y * cos_z - cos_x * sin_z) * scale->y;
    matrix->mf[1][1] = (sin_x * sin_y * sin_z + cos_x * cos_z) * scale->y;
    matrix->mf[1][2] = (sin_x * cos_y) * scale->y;
    matrix->mf[1][3] = 0.0f;

    matrix->mf[2][0] = (cos_x * sin_y * cos_z + sin_x * sin_z) * scale->z;
    matrix->mf[2][1] = (cos_x * sin_y * sin_z - sin_x * cos_z) * scale->z;
    matrix->mf[2][2] = (cos_x * cos_y) * scale->z;
    matrix->mf[2][3] = 0.0f;

    matrix->mf[3][0] = position->x;
    matrix->mf[3][1] = position->y;
    matrix->mf[3][2] = position->z;
    matrix->mf[3][3] = 1.0f;
}

void MtxF_SetRotationAndScaledTranslation(S1_MtxF *matrix, S1_Vec3f *position, S1_Vec3s *rotation, S1_Vec3f *scale) {
    f32 sin_x;
    f32 cos_x;
    f32 sin_y;
    f32 cos_y;
    f32 sin_z;
    f32 cos_z;

    sin_x = D_80087E50[(u16)(rotation->x) >> 4];
    cos_x = D_80088E50[(u16)(rotation->x) >> 4];

    sin_y = D_80087E50[(u16)(rotation->y) >> 4];
    cos_y = D_80088E50[(u16)(rotation->y) >> 4];

    sin_z = D_80087E50[(u16)(rotation->z) >> 4];
    cos_z = D_80088E50[(u16)(rotation->z) >> 4];

    matrix->mf[0][0] = cos_y * cos_z;
    matrix->mf[0][1] = cos_y * sin_z;
    matrix->mf[0][2] = -sin_y;
    matrix->mf[0][3] = 0.0f;

    matrix->mf[1][0] = sin_x * sin_y * cos_z - cos_x * sin_z;
    matrix->mf[1][1] = sin_x * sin_y * sin_z + cos_x * cos_z;
    matrix->mf[1][2] = sin_x * cos_y;
    matrix->mf[1][3] = 0.0f;

    matrix->mf[2][0] = cos_x * sin_y * cos_z + sin_x * sin_z;
    matrix->mf[2][1] = cos_x * sin_y * sin_z - sin_x * cos_z;
    matrix->mf[2][2] = cos_x * cos_y;
    matrix->mf[2][3] = 0.0f;

    matrix->mf[3][0] = position->x * scale->x;
    matrix->mf[3][1] = position->y * scale->y;
    matrix->mf[3][2] = position->z * scale->z;
    matrix->mf[3][3] = 1.0f;
}

void func_80036714(void *a0,s32 a1,s32 a2,s32 a3,f32 a4){f32 r0,r1,r2; r0=sqrtf(((f32*)a2)[0]*((f32*)a2)[0]+((f32*)a2)[1]*((f32*)a2)[1]+((f32*)a2)[2]*((f32*)a2)[2])*a4;r1=sqrtf(((f32*)a2)[4]*((f32*)a2)[4]+((f32*)a2)[5]*((f32*)a2)[5]+((f32*)a2)[6]*((f32*)a2)[6])*a4;r2=sqrtf(((f32*)a2)[8]*((f32*)a2)[8]+((f32*)a2)[9]*((f32*)a2)[9]+((f32*)a2)[10]*((f32*)a2)[10])*a4;((f32*)a0)[0]=((f32*)a1)[0]*r0;((f32*)a0)[1]=((f32*)a1)[4]*r0;((f32*)a0)[2]=((f32*)a1)[8]*r0;((f32*)a0)[3]=0;((f32*)a0)[4]=((f32*)a1)[1]*r1;((f32*)a0)[5]=((f32*)a1)[5]*r1;((f32*)a0)[6]=((f32*)a1)[9]*r1;((f32*)a0)[7]=0;((f32*)a0)[8]=((f32*)a1)[2]*r2;((f32*)a0)[9]=((f32*)a1)[6]*r2;((f32*)a0)[10]=((f32*)a1)[10]*r2;((f32*)a0)[11]=0;((f32*)a0)[12]=((f32*)a2)[0]*((f32*)a3)[0]+((f32*)a2)[4]*((f32*)a3)[1]+((f32*)a2)[8]*((f32*)a3)[2]+((f32*)a2)[12];((f32*)a0)[13]=((f32*)a2)[1]*((f32*)a3)[0]+((f32*)a2)[5]*((f32*)a3)[1]+((f32*)a2)[9]*((f32*)a3)[2]+((f32*)a2)[13];((f32*)a0)[14]=((f32*)a2)[2]*((f32*)a3)[0]+((f32*)a2)[6]*((f32*)a3)[1]+((f32*)a2)[10]*((f32*)a3)[2]+((f32*)a2)[14];((f32*)a0)[15]=1;}

void MtxF_SetOrthonormalBasis(f32 matrix[4][4], Vec3f35784 *up_direction, Vec3f35784 *position, s32 rotation_y) {
    Vec3f35784 reference;
    Vec3f35784 lateral;
    Vec3f35784 forward;
    Vec3f_SetComponentsDuplicate(&reference, D_80087E50[(u16)rotation_y >> 4], 0.0f, D_80088E50[(u16)rotation_y >> 4]);
    func_80035A10(up_direction);
    Vec3f_CrossProduct(&lateral, up_direction, &reference);
    func_80035A10(&lateral);
    Vec3f_CrossProduct(&forward, &lateral, up_direction);
    func_80035A10(&forward);
    matrix[0][0] = lateral.x;
    matrix[0][1] = lateral.y;
    matrix[0][2] = lateral.z;
    matrix[3][0] = position->x;
    matrix[1][0] = up_direction->x;
    matrix[1][1] = up_direction->y;
    matrix[1][2] = up_direction->z;
    matrix[3][1] = position->y;
    matrix[2][0] = forward.x;
    matrix[2][1] = forward.y;
    matrix[2][2] = forward.z;
    matrix[3][2] = position->z;
    matrix[0][3] = 0.0f;
    matrix[1][3] = 0.0f;
    matrix[2][3] = 0.0f;
    matrix[3][3] = 1.0f;
}

void MtxF_Multiply(S1_MtxF* arg0, S1_MtxF* arg1, S1_MtxF* arg2) {
    f32 entry0;
    f32 entry1;
    f32 entry2;

    entry0 = arg1->mf[0][0];
    entry1 = arg1->mf[0][1];
    entry2 = arg1->mf[0][2];

    arg0->mf[0][0] = (entry0 * arg2->mf[0][0]) + (entry1 * arg2->mf[1][0]) + (entry2 * arg2->mf[2][0]);
    arg0->mf[0][1] = (entry0 * arg2->mf[0][1]) + (entry1 * arg2->mf[1][1]) + (entry2 * arg2->mf[2][1]);
    arg0->mf[0][2] = (entry0 * arg2->mf[0][2]) + (entry1 * arg2->mf[1][2]) + (entry2 * arg2->mf[2][2]);

    entry0 = arg1->mf[1][0];
    entry1 = arg1->mf[1][1];
    entry2 = arg1->mf[1][2];

    arg0->mf[1][0] = (entry0 * arg2->mf[0][0]) + (entry1 * arg2->mf[1][0]) + (entry2 * arg2->mf[2][0]);
    arg0->mf[1][1] = (entry0 * arg2->mf[0][1]) + (entry1 * arg2->mf[1][1]) + (entry2 * arg2->mf[2][1]);
    arg0->mf[1][2] = (entry0 * arg2->mf[0][2]) + (entry1 * arg2->mf[1][2]) + (entry2 * arg2->mf[2][2]);

    entry0 = arg1->mf[2][0];
    entry1 = arg1->mf[2][1];
    entry2 = arg1->mf[2][2];

    arg0->mf[2][0] = (entry0 * arg2->mf[0][0]) + (entry1 * arg2->mf[1][0]) + (entry2 * arg2->mf[2][0]);
    arg0->mf[2][1] = (entry0 * arg2->mf[0][1]) + (entry1 * arg2->mf[1][1]) + (entry2 * arg2->mf[2][1]);
    arg0->mf[2][2] = (entry0 * arg2->mf[0][2]) + (entry1 * arg2->mf[1][2]) + (entry2 * arg2->mf[2][2]);

    entry0 = arg1->mf[3][0];
    entry1 = arg1->mf[3][1];
    entry2 = arg1->mf[3][2];

    arg0->mf[3][0] = (entry0 * arg2->mf[0][0]) + (entry1 * arg2->mf[1][0]) + (entry2 * arg2->mf[2][0]) + arg2->mf[3][0];
    arg0->mf[3][1] = (entry0 * arg2->mf[0][1]) + (entry1 * arg2->mf[1][1]) + (entry2 * arg2->mf[2][1]) + arg2->mf[3][1];
    arg0->mf[3][2] = (entry0 * arg2->mf[0][2]) + (entry1 * arg2->mf[1][2]) + (entry2 * arg2->mf[2][2]) + arg2->mf[3][2];

    arg0->mf[0][3] = arg0->mf[1][3] = arg0->mf[2][3] = 0.0f;
    arg0->mf[3][3] = 1.0f;
}

void MtxF_ScaleRows(S1_MtxF* dest, S1_MtxF* mtx, S1_Vec3f* s) {
    s32 i;

    for (i = 0; i < 4; i++) {
        dest->mf[0][i] = mtx->mf[0][i] * s->x;
        dest->mf[1][i] = mtx->mf[1][i] * s->y;
        dest->mf[2][i] = mtx->mf[2][i] * s->z;
        dest->mf[3][i] = mtx->mf[3][i];
    }
}

void func_80036D8C(f32 *arg0, f32 *arg1) {
    arg1[0] = sqrtf(arg0[0] * arg0[0] + arg0[1] * arg0[1] + arg0[2] * arg0[2]);
    arg1[1] = sqrtf(arg0[4] * arg0[4] + arg0[5] * arg0[5] + arg0[6] * arg0[6]);
    arg1[2] = sqrtf(arg0[8] * arg0[8] + arg0[9] * arg0[9] + arg0[10] * arg0[10]);
}

void MtxF_TransformVec3s(S1_MtxF* arg0, S1_Vec3s* arg1) {
    f32 entry0 = arg1->x;
    f32 entry1 = arg1->y;
    f32 entry2 = arg1->z;

    arg1->x = ((entry0 * arg0->mf[0][0]) + (entry1 * arg0->mf[1][0]) + (entry2 * arg0->mf[2][0])) + arg0->mf[3][0];
    arg1->y = ((entry0 * arg0->mf[0][1]) + (entry1 * arg0->mf[1][1]) + (entry2 * arg0->mf[2][1])) + arg0->mf[3][1];
    arg1->z = ((entry0 * arg0->mf[0][2]) + (entry1 * arg0->mf[1][2]) + (entry2 * arg0->mf[2][2])) + arg0->mf[3][2];
}

void MtxF_ToFixed(void *destination, S1_MtxF *source) {
    s32 converted;
    s32 i;
    // N64 matrices store integer halves before fractional halves.
    s16 *integer = destination;
    s16 *fraction = (s16 *)destination + 16;
    f32 *input = (f32 *)source;
    for (i = 0; i < 16; i++) {
        converted = *input++ * 65536.0f;
        *integer++ = ((s16 *)&converted)[0];
        *fraction++ = ((s16 *)&converted)[1];
    }
}

void MtxF_BuildTransform(S1_MtxF *arg0, S1_Vec3f *arg1, S1_Vec3s *arg2, S1_Vec3f *arg3, S1_MtxF *arg4, S1_MtxF *arg5) {
    S1_MtxF sp60;
    S1_MtxF sp20;

    func_80036714(&sp60, (s32)arg4, (s32)arg5, (s32)arg1, 1.0f);
    MtxF_SetRotationTranslationF(sp20.mf, (void *)&D_800948D0, (void *)arg2);
    MtxF_Multiply(&sp20, &sp20, &sp60);
    MtxF_ScaleRows(arg0, &sp20, arg3);
}

void func_80037120(S1_Vec3f *arg0, S1_Vec3f *arg1, f32 *arg2, s16 *arg3, s16 *arg4) {
    f32 dx; f32 dy; f32 dz;
    dx = arg1->x - arg0->x; dy = arg1->y - arg0->y; dz = arg1->z - arg0->z;
    *arg2 = sqrtf(dx * dx + dy * dy + dz * dz);
    *arg3 = MathUtil_Atan2s(sqrtf(dx * dx + dz * dz), dy);
    *arg4 = MathUtil_Atan2s(dz, dx);
}

void Camera_ComputeEyeFromAngles(S1_Vec3f *from, S1_Vec3f *to, f32 dist, s16 pitch, s16 yaw) {
    to->x = from->x + (dist * D_80088E50[((u16)pitch >> 4)] * D_80087E50[((u16)yaw >> 4)]);
    to->y = from->y + (dist * D_80087E50[((u16)pitch >> 4)]);
    to->z = from->z + (dist * D_80088E50[((u16)pitch >> 4)] * D_80088E50[((u16)yaw >> 4)]);
}

s16 Math_StepToS(s16 current, s16 target, s16 inc) {
    s16 temp_v0 = target - current;

    if (temp_v0 < 0) {
        temp_v0 += inc;
        if (temp_v0 > 0) {
            temp_v0 = 0;
        }
    } else {
        temp_v0 -= inc;
        if (temp_v0 < 0) {
            temp_v0 = 0;
        }
    }

    return target - temp_v0;
}

s32 Math_StepToS32(s32 current, s32 target, s32 inc, s32 dec) {
    if (current < target) {
        current += inc;
        if (current > target) {
            current = target;
        }
    } else {
        current -= dec;
        if (current < target) {
            current = target;
        }
    }
    return current;
}

f32 Math_StepToF(f32 current, f32 target, f32 inc, f32 dec) {
    if (current < target) {
        current += inc;
        if (current > target) {
            current = target;
        }
    } else {
        current -= dec;
        if (current < target) {
            current = target;
        }
    }
    return current;
}

s16 func_80037360(s16* arg0, s32 arg1, s32 arg2) {
    S1_Vec2s_s32 spC;
    s16* temp_a3 = &arg0[(arg1 * arg2) / 16];
    s16* p_spC = &spC.x;

    p_spC[0] = temp_a3[0];
    p_spC[1] = temp_a3[1];

    spC.xy <<= ((arg1 * arg2) % 16);
    spC.xy >>= -arg2;
    return spC.y;
}

void Color_RGBToHSV(f32 arg0, f32 arg1, f32 arg2, S1_Vec3f* arg3) {
    f32 temp_ft4;
    f32 var_ft5;
    f32 var_fv0;
    f32 var_fv1;
    s32 var_v0;

    var_v0 = 0x47;
    if (arg1 <= arg0) {
        var_fv0 = arg0;
        var_v0 = 0x52;
    } else {
        var_fv0 = arg1;
    }

    if (var_fv0 < arg2) {
        var_fv0 = arg2;
        var_v0 = 0x42;
    }

    if (arg0 <= arg1) {
        var_fv1 = arg0;
    } else {
        var_fv1 = arg1;
    }

    if (arg2 < var_fv1) {
        var_fv1 = arg2;
    }

    temp_ft4 = var_fv0 + var_fv1;
    arg3->z = temp_ft4 - 1.0f;
    if (var_fv0 == var_fv1) {
        arg3->y = 0.0f;
        arg3->x = 0.0f;
        return;
    }

    if (arg3->z <= 0.0f) {
        var_ft5 = var_fv0 - var_fv1;
        arg3->y = var_ft5 / temp_ft4;
    } else {
        var_ft5 = var_fv0 - var_fv1;
        arg3->y = var_ft5 / (2.0 - temp_ft4);
    }

    if (var_v0 == 0x52) {
        arg3->x = (arg1 - arg2) / var_ft5;
    } else if (var_v0 == 0x47) {
        arg3->x = ((arg2 - arg0) / var_ft5) + 2.0;
    } else {
        arg3->x = ((arg0 - arg1) / var_ft5) + 4.0;
    }

    arg3->x *= 60.0f;
    if (arg3->x < 0.0f) {
        arg3->x += 360.0f;
    }
}

void Color_RGBA8ToHSV(S1_Color_RGBA8_u32 arg0, S1_Vec3f* arg1) {
    Color_RGBToHSV((s32)arg0.r / 255.0f, (s32)arg0.g / 255.0f, (s32)arg0.b / 255.0f, arg1);
}

void Color_RGB5551ToHSV(u16 arg0, S1_Vec3f* arg1) {
    Color_RGBToHSV(((arg0 & 0xF800) >> 0xB) / 31.0f, ((arg0 & 0x7C0) >> 6) / 31.0f, ((arg0 & 0x3E) >> 1) / 31.0f, arg1);
}

f32 Color_HSVInterpolate(f32 arg0, f32 arg1, f32 arg2) {
    f32 ret;

    if (arg0 < 0.0f) {
        arg0 += 360.0f;
    } else {
        while (arg0 >= 360.0f) {
            arg0 -= 360.0f;
        }
    }

    if (arg0 < 60.0f) {
        ret = (((arg2 - arg1) * arg0) / 60.0f) + arg1;
    } else if ((arg0 >= 60.0f) && (arg0 < 180.0f)) {
        ret = arg2;
    } else if ((arg0 >= 180.0f) && (arg0 < 240.0f)) {
        ret = arg1 + (((arg2 - arg1) * (240.0 - arg0)) / 60.0);
    } else {
        ret = arg1;
    }

    return ret;
}

void Color_HSVToRGB(f32* arg0, f32* arg1, f32* arg2, S1_Vec3f* arg3) {
    f32 sp24;
    f32 sp20;
    f32 temp_ft4;

    if (arg3->z < -1.0f) {
        arg3->z = -1.0f;
    } else if (arg3->z > 1.0f) {
        arg3->z = 1.0f;
    }

    if (arg3->y < 0.0f) {
        arg3->y = 0.0f;
    } else {
        sp24 = 1.0f;
        if (arg3->y > 1.0f) {
            arg3->y = 1.0f;
        }
    }

    if (arg3->x < 0.0f) {
        arg3->x += 360.0f;
    } else {
        while (arg3->x >= 360.0f) {
            arg3->x -= 360.0f;
        }
    }

    if (arg3->z <= 0.0f) {
        temp_ft4 = arg3->z + 1.0f;
        sp24 = temp_ft4 * 0.5f * (1.0f - arg3->y);
        sp20 = temp_ft4 - sp24;
    } else {
        temp_ft4 = arg3->z + 1.0f;
        sp20 = (temp_ft4 * 0.5 * (1.0f - arg3->y)) + arg3->y;
        sp24 = temp_ft4 - sp20;
    }

    *arg0 = Color_HSVInterpolate(arg3->x + 120.0f, sp24, sp20);
    *arg1 = Color_HSVInterpolate(arg3->x, sp24, sp20);
    *arg2 = Color_HSVInterpolate(arg3->x - 120.0f, sp24, sp20);
}

u16 Color_HSVToRGB5551(S1_Vec3f* arg0) {
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    s32 var_a0;
    s32 var_a1;
    s32 var_v1;

    Color_HSVToRGB(&sp2C, &sp28, &sp24, arg0);

    var_a1 = (sp2C * 31.0f) + 0.5f;
    if (var_a1 >= 0x20) {
        var_a1 = 0x1F;
    }

    var_v1 = (sp28 * 31.0f) + 0.5f;
    if (var_v1 >= 0x20) {
        var_v1 = 0x1F;
    }

    var_a0 = (sp24 * 31.0f) + 0.5f;
    if (var_a0 >= 0x20) {
        var_a0 = 0x1F;
    }

    return (var_a1 << 0xB) | (var_v1 << 6) | (var_a0 * 2) | 1;
}

S1_Color_RGBA8_u32* Color_HSVToRGBA8(S1_Color_RGBA8_u32* arg0, S1_Vec3f* arg1, s32 arg2) {
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    s32 var_a0;
    s32 var_a1;
    s32 var_v1;
    S1_Color_RGBA8_u32 sp1C;

    Color_HSVToRGB(&sp34, &sp30, &sp2C, arg1);

    var_a1 = (sp34 * 255.0f) + 0.5f;
    if (var_a1 >= 0x100) {
        var_a1 = 0xFF;
    }

    var_v1 = (sp30 * 255.0f) + 0.5f;
    if (var_v1 >= 0x100) {
        var_v1 = 0xFF;
    }

    var_a0 = (sp2C * 255.0f) + 0.5f;
    if (var_a0 >= 0x100) {
        var_a0 = 0xFF;
    }

    sp1C.r = var_a1;
    sp1C.g = var_v1;
    sp1C.b = var_a0;
    sp1C.a = arg2;

    *arg0 = sp1C;

    return arg0;
}

u16 Color_AdjustRGB5551(u16 color, S1_arg1_func_80010CA8 adjustment) {
    S1_Vec3f hsv;
    s32 column;
    s32 row;
    if (color & 1) {
        Color_RGB5551ToHSV(color, &hsv);
        if (adjustment.unk_00 != 0) {
            hsv.x += adjustment.unk_00 * 0.015625f;
        }
        if (adjustment.unk_02 != 0) {
            if (adjustment.unk_02 > 0) {
                hsv.y += (1.0f - hsv.y) * adjustment.unk_02 * 0.125f;
            } else {
                hsv.y += hsv.y * adjustment.unk_02 * 0.125f;
            }
        }
        if (adjustment.unk_03 != 0) {
            column = (hsv.z + 1.0f) * 0.5f * 255.0f;
            if (adjustment.unk_03 > 0) {
                row = adjustment.unk_03 + 7;
            } else {
                row = adjustment.unk_03 + 8;
            }
            hsv.z = (2.0f * (D_80095120[row][column] / D_800A42B0)) - 1.0f;
        }
        color = Color_HSVToRGB5551(&hsv);
    }
    return color;
}

u32 Color_AdjustRGBA8(u32 word, S1_arg1_func_80010CA8 adjustment) {
    S1_Vec3f hsv;
    S1_Color_RGBA8_u32 color;
    s32 column;
    s32 row;
    u16 *brightness;
    color.rgba = word;
    if (color.a > 0) {
        Color_RGBA8ToHSV(color, &hsv);
        if (adjustment.unk_00 != 0) {
            hsv.x += adjustment.unk_00 * 0.015625f;
        }
        if (adjustment.unk_02 != 0) {
            if (adjustment.unk_02 > 0) {
                hsv.y += (1.0f - hsv.y) * adjustment.unk_02 * 0.125f;
            } else {
                hsv.y += hsv.y * adjustment.unk_02 * 0.125f;
            }
        }
        if (adjustment.unk_03 != 0) {
            column = (hsv.z + 1.0f) * 0.5f * 255.0f;
            if (adjustment.unk_03 > 0) {
                row = adjustment.unk_03 + 7;
            } else {
                row = adjustment.unk_03 + 8;
            }
            brightness = D_80095120[row];
            hsv.z = (2.0f * (brightness[column] / D_800A42B4)) - 1.0f;
        }
        Color_HSVToRGBA8(&color, &hsv, color.a);
    }
    return color.rgba;
}

#endif
