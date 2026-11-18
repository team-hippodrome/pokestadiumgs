#include "229E0.h"

#ifdef VERSION_US

extern u8 D_800901B0;
extern u8 D_800901B4;
extern u32 D_800901B8;
extern u8 D_80090BAC;
extern u32 func_800194A0(void);
extern void func_80025294(s32, s32, s32);
extern void func_800258F4(s32);
void func_800226C0(u32 arg0) {
    s32 cue;
    union { u8 *bank; s32 stop_id; } scratch;
    for (;;) {
        switch (arg0) {
case 52: cue = 2; break;
case 54: cue = 3; break;
case 60: cue = 5; break;
case 4: cue = 103; break;
case 6: cue = 104; break;
case 70: cue = 7; break;
case 71: cue = 8; break;
case 72: cue = 9; break;
case 73: cue = 11; break;
case 74: cue = 10; break;
case 75: cue = 13; break;
case 76: cue = 12; break;
case 77: cue = 14; break;
case 78: cue = 15; break;
case 79: cue = 16; break;
case 80: cue = 17; break;
case 100: cue = 18; break;
case 101: func_80025848(18); return;
case 102: cue = 19; break;
case 103: cue = 24; break;
case 104: cue = 25; break;
case 105: cue = 20; break;
case 106: cue = 21; break;
case 107: cue = 22; break;
case 108: cue = 23; break;
case 109: cue = 30; break;
case 110: cue = 24; break;
case 111: cue = 25; break;
case 112: cue = 28;
reset_112:
D_800901B0 = 0; break;
case 113: cue = 29; break;
case 114: cue = 26; break;
case 115: cue = 27; break;
case 116: cue = 28; break;
case 117: cue = 27; break;
case 118: cue = 28; break;
case 180: cue = 32; break;
case 181: cue = 33; break;
case 190: cue = 34; break;
case 191: cue = 35; break;
case 192: cue = 36; break;
case 193: cue = 37; break;
case 194: cue = 38; break;
case 195: cue = 39; break;
case 196: cue = 40; break;
case 120: cue = 43; break;
case 121: cue = 44; func_80025848(42);
reset_121:
D_800901B0 = 0; break;
case 123: cue = 31; break;
case 124: cue = 28; break;
case 152: cue = 46; break;
case 65: cue = 47; break;
case 66: cue = 48; break;
case 68: cue = 49; break;
case 173: cue = 45; break;
case 165: cue = 50; break;
case 166: cue = 51; break;
case 167: cue = 52; break;
case 168: cue = 53; break;
case 169: cue = 54; break;
case 170: cue = 55; break;
case 171: cue = 56; break;
case 172: cue = 57; break;
case 119: cue = 58; break;
case 50: cue = 59; break;
case 320: cue = 60; break;
case 321: cue = 61; break;
case 322: cue = 62; break;
case 323: cue = 63; break;
case 324: cue = 64; break;
case 325: cue = 65; break;
case 81: cue = 66; break;
case 82: cue = 67; break;
case 83: cue = 68; break;
case 84: cue = 69; break;
case 85: arg0 = 163; continue;
case 91: cue = 70; break;
case 92: cue = 71; break;
case 93: case 95: cue = 71; break;
case 99: cue = 72; break;
case 94: case 96: cue = 73; break;
case 97: func_80025848(92); cue = 74; break;
case 63: cue = 75; break;
case 64: cue = 76; break;
case 98: cue = 77; break;
case 300: cue = 78; break;
case 301: cue = 79; break;
case 302: cue = 80; break;
case 308: cue = 81; break;
case 309: cue = 82; break;
case 303: cue = 83; break;
case 304: cue = 84; break;
case 305: cue = 85; break;
case 306: cue = 86; break;
case 307: cue = 87; break;
case 86: case 90: cue = 88; break;
case 310: cue = 89; break;
case 311: cue = 90; break;
case 335: cue = 91; break;
case 200:
switch (func_800194A0() % 3) {
case 0: cue = 65537; break;
case 1: cue = 65538; break;
case 2: cue = 65539; break;
default: cue = 65539; break;
}
break;
case 201:
switch (func_800194A0() % 3) {
case 0: cue = 65540; break;
case 1: cue = 65541; break;
case 2: cue = 65542; break;
default: cue = 65542; break;
}
break;
case 202:
switch (func_800194A0() % 3) {
case 0: cue = 65543; break;
case 1: cue = 65544; break;
case 2: cue = 65545; break;
default: cue = 65545; break;
}
break;
case 203:
switch (func_800194A0() % 3) {
case 0: cue = 65546; break;
case 1: cue = 65547; break;
case 2: cue = 65548; break;
default: cue = 65548; break;
}
break;
case 220: cue = 65537; break;
case 221: cue = 65538; break;
case 222: cue = 65539; break;
case 223: cue = 65540; break;
case 224: cue = 65541; break;
case 225: cue = 65542; break;
case 226: cue = 65543; break;
case 227: cue = 65544; break;
case 228: cue = 65545; break;
case 229: cue = 65546; break;
case 230: cue = 65547; break;
case 231: cue = 65548; break;
case 205: cue = 93; break;
case 206: cue = 94; break;
case 207: cue = 95; break;
case 175: cue = 98; break;
case 176: cue = 99; break;
case 177: cue = 100; break;
case 178: cue = 105; break;
case 270: cue = 107; break;
case 271: cue = 123; if (D_80090BAC >= 3) return; D_80090BAC++; break;
case 272: cue = 109; break;
case 273: cue = 110; break;
case 274: cue = 111; break;
case 275: cue = 112; break;
case 276: cue = 113; break;
case 277: cue = 114; break;
case 278: cue = 115; break;
case 280: cue = 117; break;
case 281: cue = 118; break;
case 282: cue = 119; break;
case 284: cue = 122; break;
case 290: func_80025848(113); return;
case 295: cue = 121; break;
case 62: cue = 96; break;
case 235: cue = 97; break;
case 236: cue = 106; break;
case 237: cue = 108; break;
case 341: cue = 124; break;
case 342: cue = 125; break;
case 343: cue = 126; break;
case 344: cue = 41; break;
case 293: cue = 120; break;
case 45: cue = 116; break;
case 46: cue = 127; break;
case 350: cue = 65555; break;
case 287: cue = 65557; break;
case 140: scratch.stop_id = 1;
stop_group:
func_800258F4(scratch.stop_id); return;
case 141: scratch.stop_id = 2; goto stop_group;
case 142: cue = 31; break;
case 143: scratch.stop_id = 3; goto stop_group;
case 144: arg0 = 11; goto legacy;
case 145: arg0 = 2; goto legacy;
case 146: scratch.stop_id = 4; goto stop_group;
case 130: case 147: scratch.stop_id = 5; goto stop_group;
case 148: scratch.stop_id = 6; goto stop_group;
case 149: arg0 = 3; goto legacy;
case 133: case 150: scratch.stop_id = 7; goto stop_group;
case 132: case 151: scratch.stop_id = 8; goto stop_group;
case 160: arg0 = 2; goto legacy;
case 161: scratch.stop_id = 9; goto stop_group;
case 162: arg0 = 3; goto legacy;
case 210: scratch.stop_id = 10; goto stop_group;
case 131: scratch.stop_id = 11; goto stop_group;
case 163: scratch.stop_id = 12; goto stop_group;
case 67: scratch.stop_id = 13; goto stop_group;
case 330: func_80025294(92, 0, 0); scratch.stop_id = 14; goto stop_group;
case 331: func_80025294(92, 0, 0); scratch.stop_id = 15; goto stop_group;
case 332: scratch.stop_id = 16; goto stop_group;
case 333: scratch.stop_id = 17; goto stop_group;
case 334: scratch.stop_id = 18; goto stop_group;
case 122: case 197: case 208: case 209: case 215: case 250: case 279: case 283: case 285:
return;
default: goto legacy;
}
break;
}
if (arg0 == 120 && D_800901B0 == 0) {
func_80025294(42, 0, 0);
D_800901B0 = 1;
}
func_80025294(cue, 0, 0);
return;
legacy:
scratch.bank = &D_800901B4;
if (D_80090B80 != 1) {
func_80018728(0x82010000, 0);
func_80018704(0x41010000, 0.63f);
func_800187AC();
func_80018728(0xF8000000, 0);
func_80018728(0xF8000000, 0);
func_80018728(0xF8000000, 0);
D_80090B80 = 1;
}
if (arg0 == D_800901B8) {
} else {
(*scratch.bank) ^= 1;
}
if (arg0 == 1) D_80090BAC = 2;
switch (arg0) {
case 1: case 2: case 3: case 8: case 9: case 10: case 11: case 14: case 15: case 16: case 18: case 19: case 20: case 21:
func_8001874C(0x06010000 | (((s32)(*scratch.bank) & 0xFF) << 8), (s8)arg0);
break;
case 5: case 17:
func_80025848(92);
func_8001874C(0x06010000 | (((s32)(*scratch.bank) & 0xFF) << 8), (s8)arg0);
break;
case 51:
func_80025294(1, 0, 0);
func_8001874C(0x06010000 | (((s32)(*scratch.bank) & 0xFF) << 8), 11);
break;
case 55: case 56: case 57:
func_80025294(4, 0, 0);
func_8001874C(0x06010000 | (((s32)(*scratch.bank) & 0xFF) << 8), 12);
break;
case 61:
func_8001874C(0x06010000 | (((s32)(*scratch.bank) & 0xFF) << 8), 13);
func_80025294(6, 0, 0);
break;
default: return;
}
D_800901B8 = arg0;
}
#endif
