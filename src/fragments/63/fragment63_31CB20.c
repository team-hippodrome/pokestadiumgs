#include "global.h"
#include "controller.h"


#ifdef VERSION_US
void func_87E191B0(u8 *arg0, s32 arg1) {
    *(s32 *)arg0 = arg1;
    arg0[4] &= 0xFF7F;
}

extern void Audio_PlayDefaultSound(s32);
void func_87E191C4(void *arg0) {
    struct State {
        u32 unused;
        u32 enabled : 1;
        u32 rest : 31;
    };
    struct State *state = arg0;

    if (D_80087200->buttonsPressed & 0x1000) {
        state->enabled ^= 1;
        Audio_PlayDefaultSound(0xCF02);
    }
}

extern Gfx *D_800D0510;
extern void func_800498C4(void);
extern void func_800496A4(s32, s32);
extern void func_8004972C(s32, s32, s32, s32);
extern void func_800495BC(s32, s32, const char *, ...);
extern void func_800499EC(void);
extern s32 func_8005DED8(s32);
extern s32 func_80060368(s32);
extern char D_87E1B980[];
extern char D_87E1B99C[];
extern char D_87E1B9A4[];
extern char D_87E1B9AC[];
extern char D_87E1B9B4[];
extern char D_87E1B9B8[];
extern char D_87E1B9BC[];

typedef struct {
    s8 used;
    u8 pad1[0x1F];
    u8 level;
    u8 pad21[0x17];
    s8 name[10];
    u8 pad42[0x1A];
} F87E1921C_Entry; /* size 0x5C */

typedef struct {
    u8 pad0[0x30];
    F87E1921C_Entry entries[18];
    u8 pad6A8[0x10];
    u32 active : 1;
    u32 rest : 31;
    u8 pad6BC[4];
} F87E1921C_Player; /* size 0x6C0 */

typedef struct {
    F87E1921C_Player *players;
    u32 enabled : 1;
    u32 rest : 31;
} F87E1921C_State;

void func_87E1921C(F87E1921C_State *state) {
    s32 i;
    s32 j;

    if (state->enabled) {
        gDPPipeSync(D_800D0510++);
        gDPSetCycleType(D_800D0510++, G_CYC_1CYCLE);
        gDPSetTexturePersp(D_800D0510++, G_TP_NONE);
        gDPSetRenderMode(D_800D0510++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineLERP(D_800D0510++, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, 0, 0, 0, ENVIRONMENT, 0, 0, 0,
                          ENVIRONMENT);
        gDPSetEnvColor(D_800D0510++, 0, 0, 0, 200);
        gSPTextureRectangle(D_800D0510++, 0, 0, 320 << 2, 240 << 2, G_TX_RENDERTILE, 0, 0, 1024, 1024);
        func_800498C4();
        func_800496A4(1, 0);
        func_8004972C(255, 255, 255, 255);
        func_800495BC(20, 10, D_87E1B980);
        func_800495BC(20, 20, D_87E1B99C);
        for (i = 0; i < 4; i++) {
            switch (i) {
                case 0:
                    func_8004972C(130, 130, 255, 255);
                    break;
                case 1:
                    func_8004972C(130, 255, 130, 255);
                    break;
                case 2:
                    func_8004972C(255, 130, 130, 255);
                    break;
                case 3:
                    func_8004972C(255, 255, 130, 255);
                    break;
            }
            if (func_8005DED8(i) && state->players[i].active) {
                func_800495BC(60 + i * 50, 20, D_87E1B9A4, func_80060368(i));
            } else {
                func_800495BC(60 + i * 50, 20, D_87E1B9AC);
            }
            for (j = 0; j < 18; j++) {
                // Block-scoped so the GBI macro homes above sit higher than
                // buf; k after buf puts buf at 0x70(sp) as in retail.
                F87E1921C_Entry *e;
                s32 n;
                s8 buf[12];
                s32 k;

                e = &state->players[i].entries[j];
                n = 0;
                if (e->used == 0) {
                    buf[0] = buf[1] = buf[3] = buf[4] = ' ';
                    buf[2] = '-';
                    buf[5] = '\0';
                } else {
                    for (k = 0; k < 10; k++) {
                        buf[k] = e->name[k];
                    }
                    buf[10] = '\0';
                }
                // Cut the name after 5 characters (two-byte EUC glyphs count once).
                k = 0;
                do {
                    if (buf[k] & 0x80) {
                        k++;
                    }
                    n++;
                    k++;
                    if (n == 5) {
                        buf[k] = '\0';
                    }
                } while (buf[k] != '\0');
                func_800495BC(20 + i * 70, j * 10 + 30, D_87E1B9B4, (char *)buf);
                if (e->used == 0) {
                    func_800495BC(67 + i * 70, j * 10 + 30, D_87E1B9B8);
                } else {
                    func_800495BC(67 + i * 70, j * 10 + 30, D_87E1B9BC, e->level);
                }
            }
        }
        func_800499EC();
    }
}

#endif
