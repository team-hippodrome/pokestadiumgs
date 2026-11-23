# Original handwritten retail assembly, not a matching C implementation.
# Tracked here so restoring the owner does not depend on cached split output.
/* Handwritten function */
glabel func_8001FBE0
    /* 0207E0 8001FBE0 30C6FFFF */  andi        $a2, $a2, 0xFFFF
    /* 0207E4 8001FBE4 00063042 */  srl         $a2, $a2, 1
    /* 0207E8 8001FBE8 8C880028 */  lw          $t0, 0x28($a0)
    /* 0207EC 8001FBEC 8C89002C */  lw          $t1, 0x2C($a0)
    /* 0207F0 8001FBF0 14E00004 */  bnez        $a3, .L8001FC04
    /* 0207F4 8001FBF4 8CAA000C */   lw         $t2, 0xC($a1)
    /* 0207F8 8001FBF8 000A5040 */  sll         $t2, $t2, 1
    /* 0207FC 8001FBFC 010A4020 */  add         $t0, $t0, $t2 /* handwritten instruction */
    /* 020800 8001FC00 012A4820 */  add         $t1, $t1, $t2 /* handwritten instruction */
  .L8001FC04:
    /* 020804 8001FC04 8CAA0004 */  lw          $t2, 0x4($a1)
    /* 020808 8001FC08 8CAB0008 */  lw          $t3, 0x8($a1)
    /* 02080C 8001FC0C 908C0004 */  lbu         $t4, 0x4($a0)
    /* 020810 8001FC10 00073840 */  sll         $a3, $a3, 1
    /* 020814 8001FC14 01475020 */  add         $t2, $t2, $a3 /* handwritten instruction */
    /* 020818 8001FC18 01675820 */  add         $t3, $t3, $a3 /* handwritten instruction */
    /* 02081C 8001FC1C 000C6040 */  sll         $t4, $t4, 1
  .L8001FC20:
    /* 020820 8001FC20 854D0000 */  lh          $t5, 0x0($t2)
    /* 020824 8001FC24 856E0000 */  lh          $t6, 0x0($t3)
    /* 020828 8001FC28 014C5020 */  add         $t2, $t2, $t4 /* handwritten instruction */
    /* 02082C 8001FC2C 016C5820 */  add         $t3, $t3, $t4 /* handwritten instruction */
    /* 020830 8001FC30 20C6FFFF */  addi        $a2, $a2, -0x1 /* handwritten instruction */
    /* 020834 8001FC34 A50D0000 */  sh          $t5, 0x0($t0)
    /* 020838 8001FC38 21080002 */  addi        $t0, $t0, 0x2 /* handwritten instruction */
    /* 02083C 8001FC3C A52E0000 */  sh          $t6, 0x0($t1)
    /* 020840 8001FC40 1CC0FFF7 */  bgtz        $a2, .L8001FC20
    /* 020844 8001FC44 21290002 */   addi       $t1, $t1, 0x2 /* handwritten instruction */
    /* 020848 8001FC48 03E00008 */  jr          $ra
    /* 02084C 8001FC4C 00000000 */   nop
    /* 020850 8001FC50 00000000 */  nop
    /* 020854 8001FC54 00000000 */  nop
    /* 020858 8001FC58 00000000 */  nop
    /* 02085C 8001FC5C 00000000 */  nop
