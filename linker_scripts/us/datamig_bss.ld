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

    /* fragment43_1E5A10's main-pool push/pop marks (function-local statics
     * in func_8AC00FFC/func_8AC01064), 0x8AC09798-0x8AC097B0. */
    .fragment43_1E5A10_bss 0x8AC09798 (NOLOAD) : SUBALIGN(4)
    {
        build/src/fragments/43/fragment43_1E5A10.o(.bss)
    }
}
