#ifndef MEMORY_H
#define MEMORY_H

#include "../types.h"
#include "../device.h"

struct Memory final : Device {
	u8 *data;
	bool read_only;

	Memory(MemoryRange memory_range, bool read_only);
	~Memory();

	bool write(u16 address, u8 value);
	u8 read(u16 address);
};

#endif