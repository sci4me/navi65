#include <stdio.h>
#include <assert.h>

#include "types.h"
#include "device.h"
#include "bus.h"
#include "cpu.h"
#include "devices/memory.h"

s32 main(s32 argc, char **argv) {
	if(argc != 2) {
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return 1;
	}

	auto bus = new Bus();
	auto ram = new Memory({.start = 0x0000, .end = 0x7FFF}, false);
	auto rom = new Memory({.start = 0x8000, .end = 0xFFFF}, true);
	assert(bus->add(ram));
	assert(bus->add(rom));

	auto fp = fopen(argv[1], "rb");
	
	fseek(fp, 0L, SEEK_END);
	u64 size = ftell(fp);
	fseek(fp, 0L, SEEK_SET);
	
	if(size != 0x8000) {
		fclose(fp);
		fprintf(stderr, "Expected ROM size to be 0x8000, got 0x%04X\n", size);
		return 1;
	}

	assert(fread(rom->data, 1, 0x8000, fp) == 0x8000);
	assert(!fclose(fp));

	// u64 index = 0;
	// for(u32 line = 0; line < 0x8000 / 16; line++) {
	// 	printf("0x%04X: ", line * 16 + 0x8000);

	// 	for(u32 column = 0; column < 16; column++) {
	// 		printf("%02X ", bus->read(index + 0x8000));
	// 		index++;
	// 	}

	// 	printf("\n");
	// }

	auto cpu = new CPU(bus);

	u32 i = 0;
	cpu->reset();
	while(!cpu->stopped && i < 10) {
		cpu->cycle();
		i++;
	}

	delete cpu;
	delete bus;	

	return 0;
}