#ifndef TERMINAL_H
#define TERMINAL_H

#include "../types.h"
#include "../device.h"

struct Terminal final : Device {
	Terminal(u16 addr) : Device({.start = addr, .end = addr}) {}
	
	bool write(u16 address, u8 value);
	u8 read(u16 address);
};

#endif