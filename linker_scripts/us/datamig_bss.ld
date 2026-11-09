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
    /* Three adjacent two-byte function-static timers for func_8AB07C34,
     * func_8AB07DC4 and func_8AB07E6C, at 0x8AB16A34/36/38. The fragment
     * loader clears these addresses after relocation; compiler BSS alignment
     * has no load image and does not add fields to the timers. */
    .fragment45_message_timers_bss 0x8AB16A34 (NOLOAD) : SUBALIGN(2)
    {
        build/src/fragments/45/fragment45_22AB80.o(.bss)
    }

    /* Eight-byte loader state, cleared by Memmap_RelocateFragment.
     * Original relocation metadata remains in the loaded image. */
    .fragment44_load_state_bss 0x8AF2BF18 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/44/fragment44_1EE290.o(.bss)
    }

    /* Four-byte panel color cache. Its original loaded zero word stays in
     * the fragment data image; compiler BSS alignment has no load image. */
    .fragment11_panel_color_cache_bss 0x8160BE5C (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/11/fragment11_D9DE0.o(.bss)
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
    .fragment43_lookup_failure_data 0x8AC08788 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/43/fragment43_1E5A10.o(.data)
    }

    /* fragment43_1E5A10's main-pool push/pop marks (function-local statics
     * in func_8AC00FFC/func_8AC01064), 0x8AC09798-0x8AC097B0. */
    .fragment43_1E5A10_bss 0x8AC09798 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/43/fragment43_1E5A10.o(.bss)
    }

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
     * cleared addresses. Their input sections contain only the real four-byte
     * records and normal compiler alignment, with no loaded initializer bytes. */
    .fragment17_state_106B2_data 0x822106B2 (NOLOAD) : SUBALIGN(2)
    {
        build/src/fragments/17/fragment17_1162A0.o(.data)
    }

    .fragment17_state_105E8_bss 0x822105E8 (NOLOAD) : SUBALIGN(2)
    {
        build/src/fragments/17/fragment17_113A60.o(.bss)
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
    /* State, flags and counter at the start of fragment 24's runtime state.
     * The loader clears this area; input-section alignment is NOLOAD. */
    .fragment24_state_12450_bss 0x82B12450 (NOLOAD) : SUBALIGN(2)
    {
        build/src/fragments/24/fragment24_150C10.o(.bss)
    }
    /* Complete 0x144-byte grid state, cleared by its initializer. Native
     * BSS adds 12 alignment bytes; those bytes are not C fields. The fade
     * initializer remains in the normal loaded data section. */
    .fragment16_state_1D58_bss 0x82001D58 (NOLOAD) : SUBALIGN(2)
    {
        build/src/fragments/16/fragment16_code.o(.bss)
    }
    /* Adjacent state halfwords used by the fragment 17 panel helpers. */
    .fragment17_state_10C32_bss 0x82210C32 (NOLOAD) : SUBALIGN(2)
    {
        build/src/fragments/17/fragment17_11B210.o(.bss)
    }

    /* Fragment 21's saved argument pair and three state halfwords. Both
     * records are loader-cleared; compiler alignment has no load image. */
    .fragment21_pair_9004_data 0x82509004 (NOLOAD) : SUBALIGN(2)
    {
        build/src/fragments/21/fragment21_144790.o(.data)
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
    .fragment31_collected_values_bss 0x88234761 (NOLOAD) : SUBALIGN(1)
    {
        build/src/fragments/31/fragment31_189760.o(.bss)
    }
    /* Playback handle and model pointer, cleared with the fragment runtime
     * state after relocation metadata has been consumed. */
    .fragment72_playback_resources_bss 0x8F4020D0 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/72/fragment72_code.o(.bss)
    }
    /* Four player model records, cleared after consuming the fragment
     * relocation metadata; the original loaded table bytes stay intact. */
    .fragment54_player_models_data 0x86607410 (NOLOAD) : SUBALIGN(16)
    {
        build/src/fragments/54/fragment54_code.o(.data)
    }
    /* Dialog geometry, transition state, counters and fraction; the
     * fragment loader clears this complete 48-byte runtime record. */
    .fragment57_dialog_context_bss 0x8330AC08 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/57/fragment57_code.o(.bss)
    }
    /* Two six-word output bounds records in loader-cleared runtime memory. */
    .fragment66_output_bounds_bss 0x82E05938 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/66/fragment66_code.o(.bss)
    }
    /* Existing view-state prefix and its two dimensions, cleared by the loader. */
    .fragment66_view_prefix_data 0x82E06138 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/66/fragment66_code.o(.data)
    }
    /* Real command/event queue prefix: explicit all-zero C data, loader cleared. */
    .audio_queue_prefix_bss 0x800D1A90 (NOLOAD) : SUBALIGN(8)
    {
        build/src/2C1B0.o(.data)
    }
    /* Twenty-four recent sound IDs, shifted by func_800289B0. */
    .audio_history_bss 0x800D1AD8 (NOLOAD) : SUBALIGN(8)
    {
        build/src/26CC0.o(.bss)
    }
    /* Two active slots, following bytes, and all unchanged remaining audio objects. */
    .audio_remaining_bss 0x800D1B38 (NOLOAD) : SUBALIGN(8)
    {
        build/src/2C1B0.o(.bss)
    }
}

ASSERT(SIZEOF(.fragment74_runtime_state_bss) == 8224,
       "fragment74 runtime state must fit its original cleared RAM block");

ASSERT(SIZEOF(.fragment79_snapshot_pointers_data) == 16,
       "fragment79 snapshot pointers must occupy four original words");

ASSERT(SIZEOF(.fragment31_collected_values_bss) == 16,
       "fragment31 collected values must retain their compiler section footprint");

ASSERT(SIZEOF(.fragment72_playback_resources_bss) == 16,
       "fragment72 playback resources must retain their compiler section footprint");

ASSERT(SIZEOF(.fragment24_state_12450_bss) == 32,
       "fragment24 state and parameter prefix must retain its compiler section footprint");

ASSERT(SIZEOF(.fragment54_player_models_data) == 1440,
       "fragment54 player models must occupy their original runtime footprint");

ASSERT(SIZEOF(.fragment57_dialog_context_bss) == 48,
       "fragment57 dialog context must retain its original 48-byte footprint");

ASSERT(SIZEOF(.fragment66_output_bounds_bss) == 48,
       "fragment66 output bounds must retain their original 48-byte footprint");
ASSERT(SIZEOF(.fragment66_view_prefix_data) == 32,
       "fragment66 view prefix must retain its original 32-byte footprint");

ASSERT(SIZEOF(.fragment19_state_5EE4_data) == 16,
       "fragment19 secondary state must retain its native aligned input footprint");
ASSERT(SIZEOF(.fragment19_transition_5EB0_bss) == 48,
       "fragment19 transition records must retain their native aligned input footprint");

ASSERT(SIZEOF(.fragment11_panel_color_cache_bss) == 16,
       "fragment11 panel color cache must retain its native aligned input footprint");

ASSERT(SIZEOF(.fragment44_load_state_bss) == 16,
       "fragment44 loader state must retain its native aligned input footprint");

ASSERT(audio_storage_RAM_START == 0x800D1A90 && audio_storage_RAM_END == 0x800D2630,
       "audio RAM reservation endpoints moved");
ASSERT(SIZEOF(.audio_queue_prefix_bss) == 80,
       "audio queue prefix must retain its native aligned input footprint");
ASSERT(SIZEOF(.audio_history_bss) == 96,
       "recent sound history must contain exactly 24 words");
ASSERT(SIZEOF(.audio_remaining_bss) == 2816,
       "remaining audio input BSS footprint changed");
ASSERT(gAudioCommandQueue == 0x800D1A90 && gAudioQueuedState == 0x800D1AB8,
       "audio queue prefix moved");
ASSERT(gAudioRecentSoundHistory == 0x800D1AD8 && gAudioHistorySelection == 0x800D1B38,
       "audio history or selection moved");
ASSERT(D_800D1B40 == 0x800D1B40 && D_800D262E + 2 == 0x800D2630,
       "remaining audio object endpoints moved");

ASSERT(ADDR(.fragment16_state_1D58_bss) == 0x82001D58 &&
       SIZEOF(.fragment16_state_1D58_bss) == 336,
       "fragment 16 grid state input footprint changed");
