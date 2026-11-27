func_80004FF4 = 0x80004FF4;
func_82000DE0 = 0x82000DE0;
func_84001094 = 0x84001094;
func_82B07AB4 = 0x82B07AB4;
func_84001B34 = 0x84001B34;
func_8FC01FBC = 0x8FC01FBC;
func_8411F718 = 0x8411F718;
func_82902634 = 0x82902634;
func_84001B0C = 0x84001B0C;
func_84001AB0 = 0x84001AB0;
func_840010CC = 0x840010CC;
func_86B09478 = 0x86B09478;
func_86B09378 = 0x86B09378;
func_86B08F18 = 0x86B08F18;
func_86B08E08 = 0x86B08E08;
func_86B08CEC = 0x86B08CEC;
func_86A06E0C = 0x86A06E0C;
func_867086E4 = 0x867086E4;
func_86709128 = 0x86709128;
func_86905804 = 0x86905804;
func_869054CC = 0x869054CC;
/* Second name for func_84125080 with an unsigned short return, used only by
   func_84128204 (fragment79_393CA0.c); the file's other callers declare it s32.
   Defined by address so it also links when func_84125080 is still asm. */
func_84125080_u16 = 0x84125080;
/* Words in other fragments' data that splat reads as pointers into fragment47
   (the fragments share VRAM). These addresses are literals in C objects
   now, so define the names by address to keep the words' values. */
D_8600D4E8 = 0x8600D4E8;
D_8600D4F0 = 0x8600D4F0;
D_8600D528 = 0x8600D528;
D_8600D538 = 0x8600D538;
D_8600D640 = 0x8600D640;
D_8600D650 = 0x8600D650;

/* fragment9_code .rodata: interior addresses of C-defined arrays used by asm */
D_8FB039E6 = 0x8FB039E6;
D_8FB03A3A = 0x8FB03A3A;
/* fragment47_251C30 .rodata: func_8600B610 C literals; other fragments' data words that look like pointers to them */
D_8600DD00 = 0x8600DD00;
D_8600DD68 = 0x8600DD68;
D_8600DD78 = 0x8600DD78;
D_8600DD80 = 0x8600DD80;
D_8600DDB0 = 0x8600DDB0;
D_8600DDF8 = 0x8600DDF8;
D_8600DE00 = 0x8600DE00;

/* fragment45 data: second halves of the D_8AB14650 / D_8AB14654 u16 pairs.
   Retail code addresses them as D_8AB14650 + 2 / D_8AB14654 + 2; func_8AB03394
   (fragment45_2251A0.c) reads and writes them as their own u16 globals. */
D_8AB14652 = 0x8AB14652;
D_8AB14656 = 0x8AB14656;
