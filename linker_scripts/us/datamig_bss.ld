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
    /* Transition-control halfwords cleared by the fragment loader. The two
     * real records use this source's data and bss input sections so each can
     * retain its original address. Only zero initialization and compiler
     * alignment belong here; there are no loaded initializer bytes. */
    .fragment17_state_106B2_data 0x822106B2 (NOLOAD) : SUBALIGN(2)
    {
        build/src/fragments/17/fragment17_113A60.o(.data)
    }

    .fragment17_state_105E8_bss 0x822105E8 (NOLOAD) : SUBALIGN(2)
    {
        build/src/fragments/17/fragment17_113A60.o(.bss)
    }
}
