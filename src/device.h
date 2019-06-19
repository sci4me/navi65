#ifndef DEVICE_H
#define DEVICE_H

#include "memory_range.h"

struct Device {
	MemoryRange memory_range;

	Device(MemoryRange _memory_range) : memory_range(_memory_range) {}

	virtual bool write(u16 address, u8 value) = 0;
	virtual u8 read(u16 address) = 0;
};

#endif