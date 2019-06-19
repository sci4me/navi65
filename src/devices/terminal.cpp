#include <stdio.h>

#include "terminal.h"

bool Terminal::write(u16 addr, u8 value) {
	putchar(value);
	return true;
}

u8 Terminal::read(u16 addr) {
	return getchar();
}