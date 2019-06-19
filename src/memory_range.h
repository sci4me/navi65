#ifndef MEMORY_RANGE_H
#define MEMORY_RANGE_H

#include "types.h"

struct MemoryRange {
	u16 start;
	u16 end;

	MemoryRange(u16 _start, u16 _end) : start(_start), end(_end) {}

	bool includes(u16 addr) {
		return addr >= this->start && addr <= this->end;
	}

	bool overlaps(MemoryRange other) {
		return this->includes(other.start) || other.includes(this->start);
	}

	u16 size() {
		return this->end - this->start + 1;
	}
};

#endif