#ifndef BUS_H
#define BUS_H

#include "array.h"
#include "device.h"

struct Bus {
	Array<Device*> *devices;

	Bus();
	~Bus();

	bool add(Device *device);
	bool write(u16 address, u8 value);
	u8 read(u16 address);
	bool write_u16(u16 address, u16 value);
	u16 read_u16(u16 address);
};

#endif