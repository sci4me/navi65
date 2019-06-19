#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>

#include "types.h"

template <typename T>
struct Array final {
	T *data;
	u64 count;
	u64 capacity;

	Array() : count(0), capacity(16) {
		this->data = (T*) calloc(this->capacity, sizeof(T));
	}

	~Array() {
		free(this->data);
	}

	void add(T value) {
		if(this->count == this->capacity) {
			this->expand();
		}

		this->data[this->count++] = value;
	}

	T get(u64 index) {
		return this->data[index];
	}
private:
	void expand() {
		this->data = (T*) realloc(this->data, this->capacity * 2 * sizeof(T));
		this->capacity *= 2;
	}
};

#endif