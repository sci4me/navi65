#include <stdlib.h>

#include "memory.h"

Memory::Memory(MemoryRange memory_range, bool read_only) : Device(memory_range) {
	this->data = (u8*) malloc(this->memory_range.size());
	this->read_only = read_only;
}

Memory::~Memory() {
	free(this->data);
}

bool Memory::write(u16 addr, u8 value) {
	if(this->memory_range.includes(addr) && !this->read_only) {
		this->data[addr - this->memory_range.start] = value;
		return true;
	}

	return false;
}

u8 Memory::read(u16 addr) {
	if(addr >= this->memory_range.start && addr <= this->memory_range.end) {
		return this->data[addr - this->memory_range.start];
	}

	return 0;
}