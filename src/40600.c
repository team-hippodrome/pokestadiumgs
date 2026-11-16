#include "229E0.h"

#ifdef VERSION_US

void geo_layout_cmd_branch_and_link(void)
{
  s32 p = D_80126520;
  s32 i = D_8012651A;
  if (D_8012651A)
  {
  }
  D_80126458[i] = p + 8;
  D_8012651A = i + 1;
  D_80126458[D_8012651A] = (D_80126518 << 16) + D_8012651E;
  D_8012651A = D_8012651A + 1;
  D_8012651E = D_8012651A;
  D_80126520 = (s32) func_80003240(*((s32 *) (((u8 *) p) + 4)));
}

void geo_layout_cmd_2A(void) {
    s32 new_var;
    s32 p = D_80126520;
    s32 i = D_8012651A;
    if (D_8012651A)
    {
    }
    new_var = p;
    D_80126458[i] = p + 8;
    D_8012651A = i + 1;
    D_80126458[D_8012651A] = (D_80126518 << 16) + D_8012651E;
    D_8012651A = D_8012651A + 1;
    D_8012651E = D_8012651A;
    D_80126520 = (s32)func_80003240(*((s32 *) (*((s32 **) (new_var + 4)))));
}

void func_8003FB2C(void) {
    s16 temp_v0;
    D_8012651A = D_8012651E;
    temp_v0 = D_8012651A - 1;
    D_8012651A = temp_v0;
    D_8012651E = D_80126458[temp_v0] & 0xFFFF;
    D_80126518 = (u32)D_80126458[D_8012651A] >> 16;
    temp_v0 = D_8012651A - 1;
    D_8012651A = temp_v0;
    D_80126520 = D_80126458[temp_v0];
}

void geo_layout_cmd_jump(void) {
    void *p = (void *)(u32)D_80126520;
    D_80126520 = (s32)func_80003240(*(s32 *)((u8 *)p + 4));
}

void func_8003FBE0(void) {
    s32 (*command)[2] = (s32 (*)[2])D_80126520;
    D_80126458[D_8012651A] = D_80126520 + 8;
    D_8012651A++;
    D_80126520 = (s32)func_80003240((*command)[1]);
}

void geo_layout_cmd_27(void)
{
    s32 new_var;
    s32 i = D_8012651A;
    s32 p = D_80126520;
    new_var = p;
    D_80126458[i] = p + 8;
    if (D_80126520)
    {
    }
    D_8012651A = i + 1;
    D_80126520 = (s32)func_80003240(*((s32 *) (*((s32 **) (new_var + 4)))));
}

void geo_layout_cmd_return(void) { s16 temp_v0; temp_v0 = D_8012651A - 1; D_8012651A = temp_v0; D_80126520 = D_80126458[temp_v0]; }

void geo_layout_cmd_open_node(void) {
    s32 i = D_80126518;
    s32 *table = D_80126498;
    table[i + 1] = table[i];
    D_80126518 = i + 1;
    D_80126520 += 4;
}

void geo_layout_cmd_close_node(void) {
    D_80126518--;
    D_80126520 += 4;
}

void func_8003FD34(void *arg0) {
    s32 *entry;
    s16 index;
    if (arg0 != NULL) {
        index = D_80126518;
        entry = &D_80126498[index];
        *entry = (s32)arg0;
        if (index == 0) {
            if (D_80126454 == NULL) {
                D_80126454 = arg0;
            }
        } else {
            func_80038F8C(entry[-1], arg0);
        }
    }
}

void geo_layout_cmd_attach_node(void) {
    struct Cmd {
        u8 pad[4];
        void *child;
    } *cmd;

    cmd = (struct Cmd *)(u32)D_80126520;
    func_8003FD34(cmd->child);
    D_80126520 += 8;
}

void func_8003FDD0(void) {
    S1_unk_D_800ABE00_cmd8 *cmd = (S1_unk_D_800ABE00_cmd8 *)(u32)D_80126520;
    S1_GraphNode *node = (S1_GraphNode *)D_80126498[D_80126518];
    if (node != NULL) {
        func_80037E3C(node, cmd->callback, cmd->callbackData);
    }
    D_80126520 += sizeof(S1_unk_D_800ABE00_cmd8);
}

void func_8003FE2C(void) {
    func_8003FD34(GeoNode_CreateContainer(D_80126450, NULL));
    D_80126520 += 4;
}

void geo_layout_cmd_create_reference(void) {
    struct Cmd {
        u8 pad[4];
        S1_GraphNode *reference;
    } *cmd;

    cmd = (struct Cmd *)(u32)D_80126520;
    func_8003FD34(GeoNode_CreateWithReference(D_80126450, NULL, cmd->reference));
    D_80126520 += 8;
}

void func_8003FEB8(void) {
    S1_unk_D_800ABE00_cmdB *cmd = (S1_unk_D_800ABE00_cmdB *)(u32)D_80126520;
    S1_unk_D_86002F34_00C *node = GeoNode_CreateCamera(D_80126450, NULL, (s16)cmd->viewportX, (s16)cmd->viewportY, cmd->viewportWidth, cmd->viewportHeight);
    if (node != NULL) {
        node->unk_24.fovy = (f32)cmd->fovy;
        Vec3f_FromVec3s(&node->unk_60.at, &cmd->lookAt);
        Camera_ComputeEyeFromAngles(&node->unk_60.at, &node->unk_60.eye, (f32)cmd->eyeDistance, (cmd->yaw << 15) / 180, (cmd->pitch << 15) / 180);
    }
    func_8003FD34(node);
    D_80126520 += 0x18;
}

void geo_layout_cmd_create_type3(void) {
    struct Cmd {
        u8 command;
        u8 pad;
        s16 value;
    } *cmd;

    cmd = (struct Cmd *)(u32)D_80126520;
    func_8003FD34(GeoNode_CreateType3((S1_MemoryBlock *)D_80126450, NULL, cmd->value));
    D_80126520 += 4;
}

void geo_layout_cmd_create_type4(void) {
    struct Cmd {
        u8 command;
        u8 pad;
        s16 value;
    } *cmd;

    cmd = (struct Cmd *)(u32)D_80126520;
    func_8003FD34(GeoNode_CreateType4((S1_MemoryBlock *)D_80126450, NULL, cmd->value));
    D_80126520 += 4;
}

void geo_layout_cmd_create_ortho(void) {
    struct Cmd {
        u8 command;
        u8 pad;
        s16 value;
    } *cmd;

    cmd = (struct Cmd *)(u32)D_80126520;
    func_8003FD34(func_800380B8(D_80126450, 0, cmd->value));
    D_80126520 += 4;
}

void geo_layout_cmd_create_perspective(void) {
    struct Cmd {
        u8 command;
        u8 pad;
        s16 value;
    } *cmd;

    cmd = (struct Cmd *)(u32)D_80126520;
    func_8003FD34(func_8003811C(D_80126450, 0, cmd->value));
    D_80126520 += 4;
}

void geo_layout_cmd_create_background(void) {
    struct TargetCmd16 { u8 cmd; u8 r; u8 g; u8 b; } *cmd;
    cmd = (struct TargetCmd16 *)(u32)D_80126520;
    func_8003FD34(GeoNode_CreateBackground(D_80126450, NULL, cmd->r, cmd->g, cmd->b));
    D_80126520 += sizeof(struct TargetCmd16);
}

void geo_layout_cmd_create_clear_depth(void) {
    func_8003FD34((void *)(S1_uintptr_t)func_8003820C((s32)(S1_uintptr_t)D_80126450, 0));
    D_80126520 += 4;
}

void geo_layout_cmd_noop(void) {
}

void geo_layout_cmd_create_fog(void) {
    S1_unk_D_800ABE00_cmd13* cmd = (S1_unk_D_800ABE00_cmd13*)D_80126520;

    func_8003FD34(GeoNode_CreateFog((s32)(S1_uintptr_t)D_80126450, NULL, cmd->fogNear, cmd->fogFar, cmd->r, cmd->g, cmd->b, 0xFF));

    D_80126520 += sizeof(S1_unk_D_800ABE00_cmd13);
}

void geo_layout_cmd_create_light(void) {
    S1_unk_D_800ABE00_cmd14 *cmd = (S1_unk_D_800ABE00_cmd14 *)(u32)D_80126520;
    func_8003FD34(GeoNode_CreateLight(D_80126450, NULL, (cmd->pitch << 15) / 180, (cmd->yaw << 15) / 180, cmd->r, cmd->g, cmd->b, cmd->a));
    D_80126520 += 12;
}

void geo_layout_cmd_28(void) {
    s32 *node = (s32 *)D_80126498[D_80126518];
    if (node != NULL) {
        *((u8 *)node + 2) |= 1;
    }
    D_80126520 += 4;
}

void geo_layout_cmd_29(void) {
    func_8003FD34((void *)(S1_uintptr_t)func_80038474((s32)(S1_uintptr_t)D_80126450, 0));
    D_80126520 += 4;
}

 void geo_layout_cmd_skip(void) { D_80126520 += 0xC; }

void geo_layout_cmd_create_ambient_light(void) {
    S1_unk_D_800ABE00_cmd16* cmd = (S1_unk_D_800ABE00_cmd16*)D_80126520;

    func_8003FD34(GeoNode_CreateAmbientLight(D_80126450, NULL, cmd->r, cmd->g, cmd->b));

    D_80126520 += sizeof(S1_unk_D_800ABE00_cmd16);
}

void geo_layout_cmd_17(void) {
    s32 var_v1;

    var_v1 = 0;
    if ((*(u8 *)((u8 *)(D_80126520) + (1))) & 1) {
        var_v1 = 1;
    }
    func_8003FD34(func_800384C0(D_80126450, 0, (*(s16 *)((u8 *)(D_80126520) + (2))), (*(s32 *)((u8 *)(D_80126520) + (8))), (s32) (*(s16 *)((u8 *)(D_80126520) + (4))), (*(s32 *)((u8 *)(D_80126520) + (0xC))), (s32) (*(s16 *)((u8 *)(D_80126520) + (6))), (*(s32 *)((u8 *)(D_80126520) + (0x10))), var_v1));
    D_80126520 += 0x14;
}

void geo_layout_cmd_create_shadow(void) {
    S1_unk_D_800ABE00_cmd18* cmd = (S1_unk_D_800ABE00_cmd18*)D_80126520;

    func_8003FD34(GeoNode_CreateShadow(D_80126450, NULL, cmd->unk_01, cmd->unk_04, cmd->unk_06, cmd->unk_02));

    D_80126520 += sizeof(S1_unk_D_800ABE00_cmd18);
}

void geo_layout_cmd_create_cull_distance(void) {
    S1_unk_D_800ABE00_cmd19* cmd = (S1_unk_D_800ABE00_cmd19*)D_80126520;

    func_8003FD34(GeoNode_CreateCullDistance(D_80126450, NULL, cmd->nearDistance, cmd->farDistance));

    D_80126520 += sizeof(S1_unk_D_800ABE00_cmd19);
}

void geo_layout_cmd_create_switch_case(void) {
    S1_unk_D_800ABE00_cmd1A* cmd = (S1_unk_D_800ABE00_cmd1A*)D_80126520;

    func_8003FD34(GeoNode_CreateSwitchCase(D_80126450, NULL, cmd->unk_01, cmd->caseIndex));

    D_80126520 += sizeof(S1_unk_D_800ABE00_cmd1A);
}

void geo_layout_cmd_create_translate_rotate(void) {
    S1_Vec3s sp30;
    S1_Vec3f sp24;
    UNUSED s32 pad;
    S1_unk_D_800ABE00_cmd1B* cmd = (S1_unk_D_800ABE00_cmd1B*)D_80126520;

    Vec3f_FromVec3s(&sp24, &cmd->translation);
    Vec3s_SetComponents(&sp30, (cmd->rotX << 0xF) / 180, (cmd->rotY << 0xF) / 180, (cmd->rotZ << 0xF) / 180);
    func_8003FD34(GeoNode_CreateTranslateRotate(D_80126450, NULL, &sp24, &sp30));

    D_80126520 += sizeof(S1_unk_D_800ABE00_cmd1B);
}

void geo_layout_cmd_create_translate(void) {
    S1_Vec3f sp24;
    S1_unk_D_800ABE00_cmd1C* cmd = (S1_unk_D_800ABE00_cmd1C*)D_80126520;

    sp24.x = cmd->translateX / 65536.0f;
    sp24.y = cmd->translateY / 65536.0f;
    sp24.z = cmd->translateZ / 65536.0f;
    func_8003FD34(GeoNode_CreateTranslate(D_80126450, NULL, &sp24));

    D_80126520 += sizeof(S1_unk_D_800ABE00_cmd1C);
}

void geo_layout_cmd_create_animated_part(void) {
    S1_Vec3f sp3C;
    s16 var_a3 = 1;
    S1_unk_D_800ABE00_cmd1D* cmd = (S1_unk_D_800ABE00_cmd1D*)D_80126520;

    sp3C.x = cmd->translateX / 65536.0f;
    sp3C.y = cmd->translateY / 65536.0f;
    sp3C.z = cmd->translateZ / 65536.0f;

    if (cmd->flags & 1) {
        var_a3 = 0;
    }

    if (cmd->flags & 2) {
        var_a3 |= 2;
    }

    func_8003FD34(
        GeoNode_CreateAnimatedPart(D_80126450, NULL, cmd->partIndex, var_a3, cmd->animIndex, &cmd->rotationA, &cmd->rotationB, &sp3C));

    D_80126520 += sizeof(S1_unk_D_800ABE00_cmd1D);
}

void geo_layout_cmd_create_display_list_part(void) {
    S1_unk_D_800ABE00_cmd1E* cmd = (S1_unk_D_800ABE00_cmd1E*)D_80126520;

    func_8003FD34(GeoNode_CreateDisplayListPart(D_80126450, NULL, cmd->partIndex, cmd->displayList, cmd->unk_02));

    D_80126520 += sizeof(S1_unk_D_800ABE00_cmd1E);
}

void geo_layout_cmd_create_model_part(void) {
    S1_Vec3s sp40;
    S1_Vec3f sp34;
    S1_Vec3f sp28;
    S1_unk_D_86002F58_004_000* tmp;
    S1_unk_D_800ABE00_cmd1F* cmd = (S1_unk_D_800ABE00_cmd1F*)D_80126520;

    Vec3f_FromVec3s(&sp34, &cmd->position);

    sp28.x = cmd->scaleX / 100.0f;
    sp28.y = cmd->scaleY / 100.0f;
    sp28.z = cmd->scaleZ / 100.0f;

    Vec3s_SetComponents(&sp40, (cmd->rotX << 0xF) / 180, (cmd->rotY << 0xF) / 180, (cmd->rotZ << 0xF) / 180);
    tmp = GeoNode_CreateModelPart(D_80126450, NULL, cmd->modelIndex, &sp34, &sp40, &sp28);
    func_8003FD34(tmp);

    D_80126520 += sizeof(S1_unk_D_800ABE00_cmd1F);
}

void geo_layout_cmd_create_display_list_matrix(void) {
    S1_Vec3f sp34;
    S1_Vec3s sp2C;
    void *node;
    S1_unk_D_800ABE00_cmd20 *cmd = (S1_unk_D_800ABE00_cmd20 *)D_80126520;
    Vec3f_FromVec3s(&sp34, &cmd->position);
    Vec3s_SetComponents(&sp2C, (cmd->rotX << 15) / 180, (cmd->rotY << 15) / 180, (cmd->rotZ << 15) / 180);
    node = GeoNode_CreateDisplayListMatrixFromTransform((s32)D_80126450, 0, cmd->partIndex, (s32)cmd->displayList, (s32)&sp34, (s32)&sp2C);
    func_8003FD34(node);
    D_80126520 += sizeof(S1_unk_D_800ABE00_cmd20);
}

void geo_layout_cmd_create_scale(void) {
    S1_Vec3f sp2C;
    S1_unk_D_86002F34_alt9* tmp;
    S1_unk_D_800ABE00_cmd21* cmd = (S1_unk_D_800ABE00_cmd21*)D_80126520;

    Vec3f_FromVec3s(&sp2C, &cmd->position);
    tmp = GeoNode_CreateScale(D_80126450, NULL, cmd->partIndex, cmd->displayList, &sp2C, cmd->scale / 65536.0f);
    func_8003FD34(tmp);

    D_80126520 += sizeof(S1_unk_D_800ABE00_cmd21);
}

void geo_layout_cmd_create_display_list(void) {
    S1_unk_D_800ABE00_cmd22* cmd = (S1_unk_D_800ABE00_cmd22*)D_80126520;

    func_8003FD34(GeoNode_CreateDisplayList(D_80126450, NULL, cmd->partIndex, cmd->displayList));

    D_80126520 += sizeof(S1_unk_D_800ABE00_cmd22);
}

void geo_layout_cmd_create_shadow_texture(void) {
    S1_unk_D_800ABE00_cmd23* cmd = (S1_unk_D_800ABE00_cmd23*)D_80126520;

    func_8003FD34(GeoNode_CreateShadowTexture(D_80126450, NULL, cmd->colorOverrideFlag, cmd->eventFrame, cmd->displayList, cmd->textureIndex1, cmd->textureIndex2,
                                cmd->r, cmd->g, cmd->b, cmd->a));

    D_80126520 += sizeof(S1_unk_D_800ABE00_cmd23);
}

void geo_layout_cmd_create_anchor(void) {
    S1_unk_D_800ABE00_cmd24* cmd = (S1_unk_D_800ABE00_cmd24*)D_80126520;

    func_8003FD34(GeoNode_CreateAnchor(D_80126450, NULL, cmd->anchorId));

    D_80126520 += sizeof(S1_unk_D_800ABE00_cmd24);
}

void geo_layout_cmd_set_node_flag4(void) {
    u8 *entry = (u8 *)D_80126498[D_80126518];
    if (entry != 0) { entry[2] |= 4; }
    D_80126520 += 4;
}

void geo_layout_cmd_create_group(void) {
    S1_unk_D_800ABE00_cmd26* cmd = (S1_unk_D_800ABE00_cmd26*)D_80126520;

    func_8003FD34(GeoNode_CreateGroup(D_80126450, NULL, cmd->unk_01, cmd->unk_04, cmd->unk_06, cmd->unk_08, cmd->unk_0A,
                                cmd->unk_02, cmd->unk_03, cmd->unk_0C, cmd->r, cmd->g, cmd->b, cmd->a));

    D_80126520 += sizeof(S1_unk_D_800ABE00_cmd26);
}

void *process_geo_layout(S1_MemoryBlock *pool, void *script) {
    D_80126454 = NULL;
    D_80126518 = 0;
    D_8012651A = 2;
    D_8012651E = 2;
    D_80126520 = (s32)func_80003240(script);
    D_80126450 = (S1_MainPoolState *)pool;
    D_80094BB0 = 0;
    D_80126498[0] = 0;
    D_80126458[0] = 0;
    D_80126458[1] = 0;
    while (D_80126520 != 0) {
        D_80094BB4[*((u8 *)(u32)D_80126520)]();
    }
    return D_80126454;
}

#endif
