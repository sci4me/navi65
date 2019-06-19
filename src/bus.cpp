#include "bus.h"

Bus::Bus() {
	this->devices = new Array<Device*>();
}

Bus::~Bus() {
	for(u64 i = 0; i < this->devices->count; i++) {
		delete this->devices->get(i);
	}
	delete this->devices;
}

bool Bus::add(Device *device) {
	for(u64 i = 0; i < this->devices->count; i++) {
		if(this->devices->get(i)->memory_range.overlaps(device->memory_range)) {
			return false;
		}
	}

	this->devices->add(device);

	return true;
}

bool Bus::write(u16 addr, u8 value) {
	for(u64 i = 0; i < this->devices->count; i++) {
		auto device = this->devices->get(i);
		if(device->memory_range.includes(addr)) {
			return device->write(addr, value);
		}
	}
	return false;
}

u8 Bus::read(u16 addr) {
	for(u64 i = 0; i < this->devices->count; i++) {
		auto device = this->devices->get(i);
		if(device->memory_range.includes(addr)) {
			return device->read(addr);
		}
	}
	return 0;
}

bool Bus::write_u16(u16 addr, u16 value) {
	for(u64 i = 0; i < this->devices->count; i++) {
		auto device = this->devices->get(i);
		if(device->memory_range.includes(addr) && device->memory_range.includes(addr + 1)) {
			return device->write(addr, value & 0xFF) && device->write(addr + 1, (value >> 8) & 0xFF);
		}
	}
	return false;
}

u16 Bus::read_u16(u16 addr) {
	for(u64 i = 0; i < this->devices->count; i++) {
		auto device = this->devices->get(i);
		if(device->memory_range.includes(addr) && device->memory_range.includes(addr + 1)) {
			return device->read(addr) | (device->read(addr + 1) << 8);
		}
	}
	return 0;
}