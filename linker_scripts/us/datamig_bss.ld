/* datamig: fixed-address NOLOAD sections for C-owned bss that must land at
 * retail addresses splat's group segments cannot pin (the group's single
 * .fragmentXX_bss section places objects in file order).
 *
 * This script is linked BEFORE the generated pokestadiumgs.ld (see the
 * Makefile LD invocation), so ld assigns the listed input sections here
 * first; the generated group bss section simply misses them.
 */

SECTIONS
{
    /* Request ticks and signed command value used by func_80027634. The
     * retail data image supplies their zero initial values. Only the fields
     * at offsets 0 and 4 belong to these objects; the tail has no load image. */
    .audio_request_state_data 0x800918EC (NOLOAD) : SUBALIGN(4)
    {
        build/src/27590.o(.data)
    }
    ASSERT(SIZEOF(.audio_request_state_data) == 16,
           "audio request storage extent changed")
    ASSERT(ADDR(.audio_request_state_data) == D_800918EC,
           "audio request tick address changed")


    /* Fragment 7's text-style slots D_8300F8F8/D_8300F900 (function-scope
     * statics of func_83004FC0) and D_8300F908/D_8300F910 (func_83005740),
     * in the fragment's loaded data (zero in the data image). */
    .fragment7_text_state_bss 0x8300F8F8 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/7/fragment7_BA250.o(.bss)
    }

    /* The preview initializer uses the work record in fragment 22's
     * loaded data. Keep IDO's static storage references on that record. */
    .fragment22_preview_state 0x827034C8 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/22/fragment22_14A2E0.o(.bss)
    }

    /* Fragment 58's text overlay state D_83404888, in the fragment's loaded
     * data. func_8340156C needs it defined in fragment58_code.c so as1 folds
     * the shared `lui $at` of its back-to-back field stores. */
    .fragment58_state_bss 0x83404888 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/58/fragment58_code.o(.bss)
    }

    /* Fragment 60's active object pointer D_86A465BC, in the fragment's
     * runtime bss. func_86A004B4 keeps it as a function-scope static so IDO
     * rematerializes its address instead of holding it in a saved register.
     * IDO pads the object's .bss to 16 bytes; only the first word is used. */
    .fragment60_obj_bss 0x86A465BC (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/60/fragment60_code.o(.bss)
    }
    ASSERT(SIZEOF(.fragment60_obj_bss) == 16,
           "fragment60 object pointer extent changed")
    ASSERT(ADDR(.fragment60_obj_bss) == D_86A465BC,
           "fragment60 object pointer address changed")

    /* Fragment 22's menu record D_827034E0 (0x2B4 bytes), in the fragment's
     * loaded data. func_827013F0 needs it defined in fragment22_14B090.c so
     * as1 folds the shared `lui $at` of its field stores. It overlaps the tail
     * of .fragment22_preview_state; both are NOLOAD views of the same data. */
    .fragment22_menu_bss 0x827034E0 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/22/fragment22_14B090.o(.bss)
    }

    /* Fragment 82's deck menu state header (func_82D00590), in the
     * fragment's loaded data at D_82D07428. */
    .fragment82_deck_menu_state_data 0x82D07428 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/82/fragment82_420EA0.o(.data)
    }

    /* func_82606B28's two function-static limits (6 and 3) live in fragment
     * 20's loaded data at D_826155C0/D_826155C4; IDO only reloads them after
     * calls when they are statics of that function. */
    .fragment20_slot_fade_data 0x826155C0 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/20/fragment20_12C460.o(.data)
    }

    /* Fragment 20's mode state block D_8261A490 (0x35DC bytes). It is
     * defined in fragment20_12C460.c so as1 folds the shared-page `lui $at`
     * for stores to its fields, as in func_82614CE0. */
    .fragment20_state_bss 0x8261A490 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/20/fragment20_12C460.o(.bss)
    }

    /* func_82801A08's pulse period and phase statics (60.0f, 0.0f). */
    .fragment10_pulse_data 0x8280283C (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/10/fragment10_D5250.o(.data)
    }

    /* func_82801D7C's last-color static, in fragment 10's loaded data. */
    .fragment10_panel_color_bss 0x82802A60 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/10/fragment10_D5250.o(.bss)
    }

    /* func_8AF176C4's redraw counter static, in fragment 44's loaded data. */
    .fragment44_redraw_count_bss 0x8AF27160 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/44/fragment44_204950.o(.bss)
    }

    .fragment61_state_bss 0x86B17A78 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/61/fragment61_code.o(.bss)
    }

    /* Fragment 59's .bss, D_8691A2C8..D_8691AD9C, defined in fragment59_code.c
     * in address order (func_86909FAC's frame counters are its last two words). */
    .fragment59_bss_vars 0x8691A2C8 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/59/fragment59_code.o(.bss)
    }

    /* func_8690073C's zero-initialized function static D_8691ADB8 (the
     * object's only .data). */
    .fragment59_adb8_data 0x8691ADB8 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/59/fragment59_code.o(.data)
    }

    /* The random byte buffer is part of fragment 79's loaded state. */
    .fragment79_random_bytes 0x84195188 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/79/fragment79_393CA0.o(.bss)
    }

    /* The compiled switch addresses the retail table in fragment 4's
     * loaded data. Its 108-byte table is followed by IDO alignment. */
    .fragment4_archive_dispatch_table 0x81805C64 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/4/fragment4_AE600.o(.rodata)
    }

    /* fragment45_22AB80's function statics: func_8AB07538's state
     * (0x8AB169A6, the 0x86 bytes used by address from other functions, and
     * the counters at 0x8AB16A2E/30), func_8AB07A34's counter at 0x8AB16A32,
     * and the two-byte timers of func_8AB07C34, func_8AB07DC4 and
     * func_8AB07E6C at 0x8AB16A34/36/38. The fragment loader clears these
     * addresses after relocation; compiler BSS alignment has no load image
     * and does not add fields to the timers. IDO rounds the input .bss up to
     * 16 bytes, so the native aligned input footprint is 0xA0 (0x94 of
     * statics, ending at 0x8AB16A3A, plus 12 bytes of pad). */
    .fragment45_message_timers_bss 0x8AB169A6 (NOLOAD) : SUBALIGN(2)
    {
        build/src/fragments/45/fragment45_22AB80.o(.bss)
    }
    ASSERT(SIZEOF(.fragment45_message_timers_bss) == 0xA0,
           "fragment45_22AB80 .bss extent changed")

    /* Eight-byte loader state, cleared by Memmap_RelocateFragment.
     * Original relocation metadata remains in the loaded image. */
    .fragment44_load_state_bss 0x8AF2BF18 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/44/fragment44_1EE290.o(.bss)
    }

    /* func_8AF0282C's row-job tag and busy byte (8 bytes, padded to 16; nothing else uses
     * 0x8AF2BF38-0x8AF2BF3F). Like the loader state above, the loaded image's relocation
     * metadata stays in place underneath. */
    .fragment44_row_job_bss 0x8AF2BF30 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/44/fragment44_1F0680.o(.bss)
    }

    /* func_8AF1AE30's list scroll state (14 bytes; the other fragment 44 functions
     * reach it through the D_8AF357C0/C2/C4 labels). */
    .fragment44_scroll_state_bss 0x8AF357C0 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/44/fragment44_207AF0.o(.bss)
    }

    /* Tag and active flag used by the fragment 44 view callback. */
    .fragment44_view_state_bss 0x8AF395B8 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/44/fragment44_20D3A0.o(.bss)
    }

    /* func_8AF25F40's zoom-step statics. */
    .fragment44_zoom_step_bss 0x8AF3A6F8 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/44/fragment44_212740.o(.bss)
    }

    /* Four-byte panel color cache. Its original loaded zero word stays in
     * the fragment data image; compiler BSS alignment has no load image. */
    .fragment11_panel_color_cache_bss 0x8160BE5C (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/11/fragment11_D9DE0.o(.bss)
    }

    .fragment77_list_cursor_bss 0x8F809FC8 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/77/fragment77_code.o(.bss)
    }

    /* Pool-drain counter, explicitly initialized to zero. Its retail zero
     * word remains in the loaded data blob. Only this scalar belongs here;
     * compiler alignment bytes have no load image. */
    .fragment56_drain_counter_data 0x86808048 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/56/fragment56_code.o(.data)
    }

    /* Texture callback's four-byte frame counter. The loaded data blob keeps
     * the retail zero initializer; compiler section alignment contributes only
     * NOLOAD tail space. This word overlays the fragment's loaded image. */
    .fragment56_texture_counter_bss 0x86807CFC (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/56/fragment56_code.o(.bss)
    }

    /* Spline trio (func_8290E040/E0FC/E1D8) function statics: retail stores
     * reach them at 0x8291BC14-0x8291BC38 (lui 0x8291 + sw 0xBC1C/18/14);
     * 0x30 bytes. */
    .fragment67_34AB40_bss 0x8291BC14 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/67/fragment67_34AB40.o(.bss)
    }

    /* func_82908B60's 14 0x40-byte records (file-scope static D_8291B880),
     * 0x8291B880-0x8291BC00. */
    .fragment67_344D70_bss 0x8291B880 (NOLOAD) : SUBALIGN(16)
    {
        build/src/fragments/67/fragment67_344D70.o(.bss)
    }

    /* fragment54_code's per-player position records (file-scope static
     * D_866098A0), 0x866098A0-0x86609E40. */
    .fragment54_code_bss 0x866098A0 (NOLOAD) : SUBALIGN(16)
    {
        build/src/fragments/54/fragment54_code.o(.bss)
    }

    /* Lookup-failure ID and adjacent byte at 0x8AC08788. The fragment loader
     * clears this runtime area after consuming its relocation table. Only the
     * all-zero lookup record belongs in this input section; compiler alignment
     * contributes no loaded bytes. */
    /* fragment32_1B6E40's animation state (frame count and four nodes). The
     * fragment loader clears this runtime area after consuming its
     * relocation table. */
    .fragment32_anim_state_data 0x88308E30 (NOLOAD) : SUBALIGN(8)
    {
        build/src/fragments/32/fragment32_1B6E40.o(.data)
    }

    .fragment43_lookup_failure_data 0x8AC08788 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/43/fragment43_1E5A10.o(.data)
    }

    /* fragment43_1E5A10's main-pool push/pop marks (function-local statics
     * in func_8AC00FFC/func_8AC01064), 0x8AC09798-0x8AC097B0, the state
     * still used from asm (D_8AC097B0) and func_8AC0202C's D_8AC099C8,
     * ending at 0x8AC099D0. IDO rounds the input .bss up to 16 bytes, so the
     * native aligned input footprint is 0x240; the trailing 8 bytes of pad
     * cover D_8AC099D0's address but carry no load image. */
    .fragment43_1E5A10_bss 0x8AC09798 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/43/fragment43_1E5A10.o(.bss)
    }
    ASSERT(SIZEOF(.fragment43_1E5A10_bss) == 0x240,
           "fragment43_1E5A10 .bss extent changed")

    /* fragment67_34B0F0's text-reveal state (file-scope static D_8291BC68),
     * 0x8291BC68-0x8291BE6E. */
    .fragment67_34B0F0_bss 0x8291BC68 (NOLOAD) : SUBALIGN(8)
    {
        build/src/fragments/67/fragment67_34B0F0.o(.bss)
    }

    /* fragment83_code's shuffle-order state (file-scope static D_82C05E80),
     * 0x82C05E80-0x82C05FCC. */
    .fragment83_code_bss 0x82C05E80 (NOLOAD) : SUBALIGN(16)
    {
        build/src/fragments/83/fragment83_code.o(.bss)
    }
    /* Scene resource, fade controls and two 100-rectangle clipping buffers.
     * This is the real 0x650-byte range cleared by Fragment17_InitFadeState. */
    .fragment17_scene_fade_bss 0x8220EC40 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/17/fragment17_1162A0.o(.bss)
    }

    /* The scene and widget transition records keep their original loader-
     * cleared addresses. Their input sections contain only the real records
     * (0x24 bytes from 0x822106B0 for the scene, a .bss static so as1 groups
     * its `lui $at` like retail) and normal compiler alignment, with no
     * loaded initializer bytes. */
    .fragment17_state_106B0_data 0x822106B0 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/17/fragment17_118870.o(.bss)
    }

    /* fragment17_1154C0's 0x18-byte scene record (three statics cleared by
     * func_82206854). The fragment loader clears this runtime area after
     * consuming its relocation table. */
    .fragment17_scene_record_data 0x8220EB80 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/17/fragment17_1154C0.o(.data)
    }

    /* fragment17_11A7F0's overlay header (state, unk_02, x, y). The fragment
     * loader clears this runtime area after consuming its relocation table. */
    .fragment17_overlay_header_data 0x822109C0 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/17/fragment17_11A7F0.o(.data)
    }

    .fragment17_state_105E8_bss 0x822105E8 (NOLOAD) : SUBALIGN(2)
    {
        build/src/fragments/17/fragment17_113A60.o(.bss)
    }
    /* func_82205C14's slide offset and base position (function statics),
     * in fragment 17's loader-cleared runtime area. */
    .fragment17_slide_state_10640_bss 0x82210640 (NOLOAD) : SUBALIGN(2)
    {
        build/src/fragments/17/fragment17_1154C0.o(.bss)
    }
    /* Loader-cleared color/state header and transition rows for fragment 19.
     * The input sections contain the real objects and compiler alignment;
     * the loaded relocation metadata retains its original bytes. */
    .fragment19_state_5EE4_data 0x82305EE4 (NOLOAD) : SUBALIGN(2)
    {
        build/src/fragments/19/fragment19_121100.o(.data)
    }

    .fragment19_transition_5EB0_bss 0x82305EB0 (NOLOAD) : SUBALIGN(2)
    {
        build/src/fragments/19/fragment19_121100.o(.bss)
    }
    /* fragment45's pulsing colour at 0x8AB16520 (sColor, defined in
     * fragment45_2251A0.c so as1 shares the `lui $at` for its stores, as in
     * func_8AB00618). It is a NOLOAD view of bytes in the loaded image. */
    .fragment45_pulse_color_bss 0x8AB16520 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/45/fragment45_2251A0.o(.bss)
    }
    /* fragment45's panel pulse phases at 0x8AB14670 (sPanelPhase, an
     * initialized static in fragment45_2251A0.c so IDO keeps the retail
     * reloads in func_8AB04038). NOLOAD view of the fragment's bss. */
    .fragment45_panel_phase_data 0x8AB14670 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/45/fragment45_2251A0.o(.data)
    }
    /* fragment44's selection pulse statics at 0x8AF26580 (func_8AF08390's
     * sObjs pointer table and sPhase counter, function-scope statics so IDO
     * keeps the retail lui/addiu bases). NOLOAD view of bytes in the loaded
     * fragment44 data. */
    .fragment44_select_pulse_data 0x8AF26580 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/44/fragment44_1F5F20.o(.data)
    }
    /* fragment79's side flags at 0x8419E918 (sFlags, a function-scope static
     * in func_84154948 so as1 shares the `lui $at` for its stores). NOLOAD view
     * of bytes in the loaded image. */
    .fragment79_side_flags_bss 0x8419E918 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/79/fragment79_3C40B0.o(.bss)
    }
    /* fragment2's state block D_81900820 (defined in fragment2_code.c so as1
     * folds the shared-page `lui $at`, as in func_81900020), then a pad and
     * the on-screen blink counter (a function-scope static in func_8190037C)
     * at 0x81900DFC, past the end of the fragment's loaded data. */
    .fragment2_blink_bss 0x81900820 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/2/fragment2_code.o(.bss)
    }

    /* func_823053A8's header statics at the start of the fragment 19 runtime
     * state; the loader clears this area. */
    .fragment19_state_6AF8_bss 0x82306AF8 (NOLOAD) : SUBALIGN(2)
    {
        build/src/fragments/19/fragment19_124E40.o(.bss)
    }
    /* State, flags and counter at the start of fragment 24's runtime state.
     * The loader clears this area; input-section alignment is NOLOAD. */
    .fragment24_state_12450_bss 0x82B12450 (NOLOAD) : SUBALIGN(2)
    {
        build/src/fragments/24/fragment24_150C10.o(.bss)
    }
    /* Complete 0x144-byte grid state, cleared by its initializer, then the
     * 12-byte overlay fade state at 0x82001EA0 (IDO aligns it to +0x148).
     * The fragment's data image supplies the fade state's load bytes. */
    .fragment16_state_1D58_bss 0x82001D58 (NOLOAD) : SUBALIGN(2)
    {
        build/src/fragments/16/fragment16_code.o(.bss)
    }
    /* func_82000794's six function-static phase lengths live in fragment
     * 16's loaded data at D_82001CD8..D_82001CEC; IDO only reloads them
     * after calls when they are statics of that function. The data image
     * supplies their values. */
    .fragment16_fade_lengths_data 0x82001CD8 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/16/fragment16_code.o(.data)
    }
    /* Adjacent state halfwords used by the fragment 17 panel helpers. */
    .fragment17_state_10C32_bss 0x82210C32 (NOLOAD) : SUBALIGN(2)
    {
        build/src/fragments/17/fragment17_11B210.o(.bss)
    }

    /* func_8F500020's preview state in fragment 73's loader-cleared area
     * at 0x8F5009A0 (fields from +8 are cleared by the function). */
    .fragment73_preview_9A0_bss 0x8F5009A0 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/73/fragment73_code.o(.bss)
    }

    /* Fragment 53's four loader-cleared 0x168-byte models at D_86510010.
     * func_86502524's unrolled scale stores share lui pairs only for a
     * section-relative static, so the array is defined in C. */
    .fragment53_models_10010_bss 0x86510010 (NOLOAD) : SUBALIGN(16)
    {
        build/src/fragments/53/fragment53_code.o(.bss)
    }

    /* func_8650515C's static table index D_8650D9D0, in fragment 53's
     * loader-cleared area over the relocation tail. It is a function
     * static so IDO keeps it in a register across the case-2 loop. */
    .fragment53_index_D9D0_bss 0x8650D9D0 (NOLOAD) : SUBALIGN(16)
    {
        build/src/fragments/53/fragment53_28E360.o(.bss)
    }

    /* Fragment 21's saved argument pair and three state halfwords. Both
     * records are loader-cleared; compiler alignment has no load image. */
    .fragment21_pair_9004_data 0x82509004 (NOLOAD) : SUBALIGN(2)
    {
        build/src/fragments/21/fragment21_144790.o(.data)
    }

    /* func_82502854's archive handle and two state halfwords, in fragment
     * 21's loaded data at D_82508D08. IDO shares one lui across the stores
     * only when the record is a function-scope static. */
    .fragment21_archive_8D08_data 0x82508D08 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/21/fragment21_13FFA0.o(.data)
    }

    /* func_82502EBC's four state halfwords at D_82508F70. IDO shares one
     * lui across the stores only when the record is a function-scope
     * static. */
    .fragment21_state_8F70_bss 0x82508F70 (NOLOAD) : SUBALIGN(2)
    {
        build/src/fragments/21/fragment21_13FFA0.o(.bss)
    }

    .fragment21_state_8FF0_bss 0x82508FF0 (NOLOAD) : SUBALIGN(2)
    {
        build/src/fragments/21/fragment21_144790.o(.bss)
    }
    /* Cellular transition state and flags. The remaining header and cell
     * mask keep their legacy views in the same loader-cleared runtime block. */
    .fragment21_transition_9680_bss 0x82509680 (NOLOAD) : SUBALIGN(2)
    {
        build/src/fragments/21/fragment21_147D10.o(.bss)
    }
    /* func_82A00C84's function-static setup state (selection, cursor, model
     * and scene handles) at D_82A01990. IDO gives the paired stores one lui
     * and reloads each handle after storing it only for a function static. */
    .fragment23_setup_state_bss 0x82A01990 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/23/fragment23_code.o(.bss)
    }
    /* fragment23_code's saved text position (func_82A0089C). The fragment
     * loader clears this runtime area after consuming its relocation table. */
    .fragment23_text_origin_data 0x82A01A24 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/23/fragment23_code.o(.data)
    }
    /* Complete fragment 74 runtime state: 24-byte context/state prefix and
     * 8200-byte image view. This is exactly the original loader/initializer
     * clear range, 0x8F600BF0-0x8F602C10; its relocation metadata stays loaded. */
    .fragment74_runtime_state_bss 0x8F600BF0 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/74/fragment74_code.o(.bss)
    }
    /* Four snapshot destination pointers; their original loaded zero words
     * remain in the data blob at these same runtime addresses. */
    .fragment79_snapshot_pointers_data 0x84186160 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/79/fragment79_3A4030.o(.data)
    }
    /* Four compacted nonzero values, cleared with the fragment's runtime
     * block after relocation metadata has been consumed. */
    /* func_882041F0's four-byte function static at 0x88234694, inside
     * fragment 31's loaded menu data. */
    .fragment31_menu_bytes_bss 0x88234694 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/31/fragment31_177430.o(.bss)
    }

    .fragment31_collected_values_bss 0x88234761 (NOLOAD) : SUBALIGN(1)
    {
        build/src/fragments/31/fragment31_18E660.o(.bss)
    }
    /* fragment72's 0x48-byte runtime state, with the playback resources at
     * +0x10 (IDO pads the section to 0x50). It is cleared after relocation
     * metadata has been consumed. */
    .fragment72_state_bss 0x8F4020C0 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/72/fragment72_code.o(.bss)
    }
    /* Four player model records, cleared after consuming the fragment
     * relocation metadata; the original loaded table bytes stay intact. */
    .fragment54_player_models_data 0x86607410 (NOLOAD) : SUBALIGN(16)
    {
        build/src/fragments/54/fragment54_code.o(.data)
    }
    /* Fragment 57's loader-cleared runtime memory: the 48-byte dialog record
     * sDialog, the camera/menu objects after it, then func_83300CB0's
     * function-scope statics (0x8330AC08-0x8330ACF8). */
    .fragment57_dialog_context_bss 0x8330AC08 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/57/fragment57_code.o(.bss)
    }
    /* Fragment 66's loader-cleared runtime memory from the two six-word
     * output bounds records (0x82E05938) through the view-state prefix
     * (0x82E06138) to func_82E01CE8's three counters (0x82E08A70). The two
     * gap arrays stand for objects still owned by asm data. */
    .fragment66_output_bounds_bss 0x82E05938 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/66/fragment66_code.o(.bss)
    }
    /* func_82E01CE8's three function statics in fragment 66's loaded data
     * (D_82E05444..D_82E0544C); the retail data image supplies their values. */
    .fragment66_intro_state_data 0x82E05444 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/66/fragment66_code.o(.data)
    }
    /* Real command queue: explicit all-zero C data, loader cleared. */
    .audio_queue_prefix_bss 0x800D1A90 (NOLOAD) : SUBALIGN(8)
    {
        build/src/290C0.o(.data)
    }
    /* Queued event state, the twenty-four recent sound IDs (shifted by
     * func_800289B0), two active slots, following bytes, and all remaining
     * audio objects. */
    .audio_remaining_bss 0x800D1AB8 (NOLOAD) : SUBALIGN(8)
    {
        build/src/290C0.o(.bss)
    }

    /* func_86701C6C's function-static context pointer (retail D_8670C850), in fragment 55's
     * reloc-table area that the game reuses as bss after loading. */
    .fragment55_ctx_ptr_bss 0x8670C850 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/55/fragment55_code.o(.bss)
    }
}

ASSERT(SIZEOF(.fragment21_archive_8D08_data) == 16,
       "fragment21 archive record must retain its compiler section footprint");

ASSERT(SIZEOF(.fragment73_preview_9A0_bss) == 32,
       "fragment73 preview state must keep its 0x20-byte footprint");

ASSERT(SIZEOF(.fragment53_models_10010_bss) == 0x5A0,
       "fragment53 models must keep four 0x168-byte records");

ASSERT(SIZEOF(.fragment53_index_D9D0_bss) == 16,
       "fragment53 table index must keep its 16-byte compiler footprint");

ASSERT(SIZEOF(.fragment32_anim_state_data) == 112,
       "fragment32 animation state must retain its compiler section footprint");

ASSERT(SIZEOF(.fragment74_runtime_state_bss) == 8224,
       "fragment74 runtime state must fit its original cleared RAM block");

ASSERT(SIZEOF(.fragment79_snapshot_pointers_data) == 16,
       "fragment79 snapshot pointers must occupy four original words");

ASSERT(SIZEOF(.fragment17_scene_record_data) == 32,
       "fragment17 scene record must retain its compiler section footprint");

ASSERT(SIZEOF(.fragment17_overlay_header_data) == 16,
       "fragment17 overlay header must retain its compiler section footprint");

ASSERT(SIZEOF(.fragment31_menu_bytes_bss) == 16,
       "fragment31 menu bytes must retain their compiler section footprint");
ASSERT(SIZEOF(.fragment31_collected_values_bss) == 16,
       "fragment31 collected values must retain their compiler section footprint");

ASSERT(SIZEOF(.fragment72_state_bss) == 80,
       "fragment72 runtime state must retain their compiler section footprint");

ASSERT(SIZEOF(.fragment23_setup_state_bss) == 64,
       "fragment23 setup state must retain its compiler section footprint");

ASSERT(SIZEOF(.fragment23_text_origin_data) == 16,
       "fragment23 text origin must retain its compiler section footprint");

ASSERT(SIZEOF(.fragment2_blink_bss) == 0x5E0,
       "fragment2 blink counter must retain its compiler section footprint");

ASSERT(SIZEOF(.fragment24_state_12450_bss) == 48,
       "fragment24 state and parameter prefix must retain its compiler section footprint");

ASSERT(SIZEOF(.fragment54_player_models_data) == 1440,
       "fragment54 player models must occupy their original runtime footprint");

ASSERT(SIZEOF(.fragment57_dialog_context_bss) == 0xF0,
       "fragment57 runtime bss must end after func_83300CB0's statics");

ASSERT(SIZEOF(.fragment66_output_bounds_bss) == 0x3150,
       "fragment66 runtime bss must end after func_82E01CE8's counters");
ASSERT(SIZEOF(.fragment66_intro_state_data) == 16,
       "fragment66 intro state must retain its 16-byte aligned footprint");

ASSERT(SIZEOF(.fragment19_state_5EE4_data) == 16,
       "fragment19 secondary state must retain its native aligned input footprint");
ASSERT(SIZEOF(.fragment19_transition_5EB0_bss) == 48,
       "fragment19 transition records must retain their native aligned input footprint");

ASSERT(SIZEOF(.fragment11_panel_color_cache_bss) == 16,
       "fragment11 panel color cache must retain its native aligned input footprint");

ASSERT(SIZEOF(.fragment44_load_state_bss) == 16,
       "fragment44 loader state must retain its native aligned input footprint");
ASSERT(SIZEOF(.fragment44_row_job_bss) == 16,
       "fragment44 row-job state must stay below D_8AF2BF40");

ASSERT(audio_storage_RAM_START == 0x800D1A90 && audio_storage_RAM_END == 0x800D2630,
       "audio RAM reservation endpoints moved");
ASSERT(SIZEOF(.audio_queue_prefix_bss) == 48,
       "audio command queue must retain its native aligned input footprint");
ASSERT(SIZEOF(.audio_remaining_bss) == 2944,
       "audio input BSS footprint changed");
ASSERT(gAudioCommandQueue == 0x800D1A90 && gAudioQueuedState == 0x800D1AB8,
       "audio queue prefix moved");
ASSERT(gAudioRecentSoundHistory == 0x800D1AD8 && gAudioHistorySelection == 0x800D1B38,
       "audio history or selection moved");
ASSERT(D_800D1B40 == 0x800D1B40 && D_800D262E + 2 == 0x800D2630,
       "remaining audio object endpoints moved");

ASSERT(ADDR(.fragment16_state_1D58_bss) == 0x82001D58 &&
       SIZEOF(.fragment16_state_1D58_bss) == 352,
       "fragment 16 grid state input footprint changed");

ASSERT(SIZEOF(.fragment4_archive_dispatch_table) == 112,
       "fragment 4 archive dispatch table footprint changed");


/* The assembly switch table targets these return blocks in the C function. */
.L81307278 = func_81307228 + 0x50;
.L81307280 = func_81307228 + 0x58;
ASSERT(SIZEOF(.fragment20_slot_fade_data) == 0x40, "fragment 20 slot fade limits footprint changed");
ASSERT(SIZEOF(.fragment16_fade_lengths_data) == 0x20, "fragment 16 fade lengths footprint changed");
ASSERT(SIZEOF(.fragment10_panel_color_bss) == 16, "fragment 10 panel color footprint changed");
ASSERT(SIZEOF(.fragment22_preview_state) == 32, "fragment 22 preview state footprint changed");
ASSERT(SIZEOF(.fragment79_random_bytes) == 16, "fragment 79 random buffer footprint changed");
ASSERT(SIZEOF(.fragment55_ctx_ptr_bss) == 16, "fragment 55 context pointer footprint changed");
ASSERT(SIZEOF(.fragment82_deck_menu_state_data) == 272,
       "fragment82 deck menu state header must retain its compiler section footprint");

/* Case targets for the two mode dispatch tables. */
.L8002B394 = func_8002B2FC + 0x98;
.L8002B3A4 = func_8002B2FC + 0xA8;
.L8002B3B4 = func_8002B2FC + 0xB8;
.L8002B3C4 = func_8002B2FC + 0xC8;
.L8002B3F0 = func_8002B2FC + 0xF4;
.L8002B400 = func_8002B2FC + 0x104;
.L8002B424 = func_8002B2FC + 0x128;

ASSERT(SIZEOF(.fragment10_pulse_data) == 16, "fragment 10 pulse statics footprint changed");
/* Case targets for fragment 45's command dispatch table. */
.L8AB06518 = func_8AB064C4 + 0x54;
.L8AB06528 = func_8AB064C4 + 0x64;
.L8AB06538 = func_8AB064C4 + 0x74;
.L8AB06548 = func_8AB064C4 + 0x84;
.L8AB06558 = func_8AB064C4 + 0x94;
.L8AB06568 = func_8AB064C4 + 0xA4;
.L8AB06578 = func_8AB064C4 + 0xB4;
.L8AB06588 = func_8AB064C4 + 0xC4;
.L8AB06598 = func_8AB064C4 + 0xD4;
.L8AB065A8 = func_8AB064C4 + 0xE4;
.L8AB065B8 = func_8AB064C4 + 0xF4;
.L8AB065C8 = func_8AB064C4 + 0x104;
.L8AB065D8 = func_8AB064C4 + 0x114;
.L8AB065E8 = func_8AB064C4 + 0x124;
.L8AB065F8 = func_8AB064C4 + 0x134;
.L8AB06608 = func_8AB064C4 + 0x144;
.L8AB06618 = func_8AB064C4 + 0x154;

/* Case targets for fragment 45's menu dispatch table. */
.L8AB062F4 = func_8AB062C4 + 0x30;
.L8AB06304 = func_8AB062C4 + 0x40;
.L8AB06314 = func_8AB062C4 + 0x50;
.L8AB06324 = func_8AB062C4 + 0x60;
.L8AB06334 = func_8AB062C4 + 0x70;
.L8AB06344 = func_8AB062C4 + 0x80;
.L8AB06354 = func_8AB062C4 + 0x90;
.L8AB06364 = func_8AB062C4 + 0xA0;
.L8AB06374 = func_8AB062C4 + 0xB0;
.L8AB06384 = func_8AB062C4 + 0xC0;
.L8AB06394 = func_8AB062C4 + 0xD0;
.L8AB063A4 = func_8AB062C4 + 0xE0;
.L8AB063B4 = func_8AB062C4 + 0xF0;
.L8AB063C4 = func_8AB062C4 + 0x100;
.L8AB063D4 = func_8AB062C4 + 0x110;
.L8AB063E4 = func_8AB062C4 + 0x120;
.L8AB063F4 = func_8AB062C4 + 0x130;
ASSERT(SIZEOF(.fragment61_state_bss) == 0x4C0, "fragment 61 state record footprint changed");
