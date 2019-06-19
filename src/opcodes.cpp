#include "opcodes.h"

const u8 OPCODE_ADDRESSING_MODES[256] = {
	//       0       1       2       3       4       5       6       7       8       9       A       B       C       D       E       F
	/* 0 */ AM_S,   AM_ZPX, AM_N,   AM_N,   AM_ZP,  AM_ZP,  AM_ZP,  AM_ZP,  AM_S,   AM_IMM, AM_ACC, AM_N,   AM_AB,  AM_AB,  AM_AB,  AM_REL,
	/* 1 */ AM_REL, AM_ZPY, AM_IZP, AM_N,   AM_ZP,  AM_ZPX, AM_ZPX, AM_ZP,  AM_IMM, AM_ABY, AM_ACC, AM_N,   AM_AB,  AM_ABX, AM_ABX, AM_REL,
	/* 2 */ AM_AB,  AM_ZPX, AM_N,   AM_N,   AM_ZP,  AM_ZP,  AM_ZP,  AM_ZP,  AM_S,   AM_IMM, AM_ACC, AM_N,   AM_AB,  AM_AB,  AM_AB,  AM_REL,
	/* 3 */ AM_REL, AM_ZPY, AM_IZP, AM_N,   AM_ZPX, AM_ZPX, AM_ZPX, AM_ZP,  AM_IMM, AM_ABY, AM_ACC, AM_N,   AM_AB,  AM_AB,  AM_AB,  AM_REL,
	/* 4 */ AM_S,   AM_ZPX, AM_N,   AM_N,   AM_N,   AM_ZP,  AM_ZP,  AM_ZP,  AM_S,   AM_IMM, AM_ACC, AM_N,   AM_AB,  AM_AB,  AM_AB,  AM_REL,
	/* 5 */ AM_REL, AM_ZPY, AM_IZP, AM_N,   AM_N,   AM_ZPX, AM_ZPX, AM_ZP,  AM_I,   AM_ABY, AM_S,   AM_N,   AM_N,   AM_ABX, AM_ABX, AM_REL,
	/* 6 */ AM_S,   AM_ZPX, AM_N,   AM_N,   AM_ZP,  AM_ZP,  AM_ZP,  AM_ZP,  AM_S,   AM_IMM, AM_ACC, AM_N,   AM_IN,  AM_AB,  AM_AB,  AM_REL,
	/* 7 */ AM_REL, AM_ZPY, AM_IZP, AM_N,   AM_ZPX, AM_ZPX, AM_ZPX, AM_ZP,  AM_I,   AM_ABY, AM_S,   AM_N,   AM_INX, AM_ABX, AM_ABX, AM_REL,
	/* 8 */ AM_REL, AM_ZPX, AM_N,   AM_N,   AM_ZP,  AM_ZP,  AM_ZP,  AM_ZP,  AM_I,   AM_IMM, AM_I,   AM_N,   AM_AB,  AM_AB,  AM_AB,  AM_REL,
	/* 9 */ AM_REL, AM_ZPY, AM_IZP, AM_N,   AM_ZPX, AM_ZPX, AM_ZPY, AM_ZP,  AM_I,   AM_ABY, AM_I,   AM_N,   AM_AB,  AM_ABX, AM_ABX, AM_REL,
	/* A */ AM_IMM, AM_ZPX, AM_IMM, AM_N,   AM_ZP,  AM_ZP,  AM_ZP,  AM_ZP,  AM_I,   AM_IMM, AM_I,   AM_N,   AM_ACC, AM_AB,  AM_AB,  AM_REL,
	/* B */	AM_REL, AM_ZPY, AM_IZP, AM_N,   AM_ZPX, AM_ZPX, AM_ZPY, AM_ZP,  AM_I,   AM_ABY, AM_I,   AM_N,   AM_ABX, AM_ABX, AM_ABY, AM_REL,
	/* C */	AM_IMM, AM_ZPX, AM_N,   AM_N,   AM_ZP,  AM_ZP,  AM_ZP,  AM_ZP,  AM_I,   AM_IMM, AM_I,   AM_IMM, AM_AB,  AM_AB,  AM_AB,  AM_REL,
	/* D */ AM_REL, AM_ZPY, AM_IZP, AM_N,   AM_N,   AM_ZPX, AM_ZPX, AM_ZP,  AM_I,   AM_ABY, AM_S,   AM_IMM, AM_N,   AM_ABX, AM_ABX, AM_REL,
	/* E */ AM_IMM, AM_ZPX, AM_N,   AM_N,   AM_ZP,  AM_ZP,  AM_ZP,  AM_ZP,  AM_I,   AM_IMM, AM_I,   AM_N,   AM_AB,  AM_AB,  AM_AB,  AM_REL,
	/* F */ AM_REL, AM_ZPY, AM_IZP, AM_N,   AM_N,   AM_ZPX, AM_ZPX, AM_ZP,  AM_I,   AM_ABY, AM_S,   AM_N,   AM_N,   AM_ABX, AM_ABX, AM_REL
};