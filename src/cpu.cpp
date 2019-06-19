#include <assert.h>

#include "cpu.h"

CPU::CPU(Bus *_bus) : bus(_bus) {
	this->pc = 0;
	this->sp = 0xFF;
	this->a = 0;
	this->x = 0;
	this->y = 0;
	this->flags = FLAG_INTERRUPT;
}

CPU::~CPU() {
}

void CPU::cycle() {
	u8 opcode = this->read_u8();
	switch(opcode) {
		default:
			assert(false);
	}
}

u8 CPU::read_u8() {
	return this->bus->read(this->pc++);
}

u16 CPU::read_u16() {
	return this->bus->read(this->pc++) | (this->bus->read(this->pc++) << 8);
}