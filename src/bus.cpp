#include "bus.h"

Bus::Bus() {
	this->devices = new Array<Device*>();
}

Bus::~Bus() {
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

bool Bus::write(u16 address, u8 value) {
	for(u64 i = 0; i < this->devices->count; i++) {
		auto device = this->devices->get(i);
		if(device->memory_range.includes(address)) {
			return device->write(address, value);
		}
	}
	return false;
}

u8 Bus::read(u16 address) {
	for(u64 i = 0; i < this->devices->count; i++) {
		auto device = this->devices->get(i);
		if(device->memory_range.includes(address)) {
			return device->read(address);
		}
	}
	return 0;
}