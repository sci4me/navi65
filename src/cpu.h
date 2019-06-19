#ifndef CPU_H
#define CPU_H

#include "types.h"
#include "bus.h"

#define FLAG_CARRY 0x01
#define FLAG_ZERO 0x02
#define FLAG_INTERRUPT 0x04
#define FLAG_DECIMAL 0x08
#define FLAG_BREAK 0x10
#define FLAG_OVERFLOW 0x40
#define FLAG_NEGATIVE 0x80

struct CPU {
	Bus *bus;
	bool stopped;
	bool interrupt_waiting;
	bool break_waiting;

	u16 pc;
	u16 sp;
	u8 a;
	u8 x;
	u8 y;
	u8 flags;

	CPU(Bus *_bus);
	~CPU();

	void reset();
	void cycle();
private:
	void set_flag(u8 flag, bool value);
	bool get_flag(u8 flag);

	void set_flags(u8 flags);

	void add(u16 r1);
	void sub(u16 r1);
	void cmp(u8 mem, u8 reg);

	void push(u8 value);
	u8 pop();

	u8 read_u8();
	u16 read_u16();
};

#endif