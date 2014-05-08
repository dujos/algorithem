#include "Bitwise.h"

Bitwise::Bitwise() {}

Bitwise::~Bitwise() {}

void Bitwise::clear_bit(int n) {
	unsigned char b = 'z';
	b &= ~(1 << n);
	std::cout << b << std::endl;
}

void Bitwise::set_bit(int n) {
	unsigned char a = 'z';
	a |= ~(1 << n);
	std::cout << a << std::endl;
}

void Bitwise::binary(unsigned n) {
	for(int i = 256; 0 < i; i = i/2) {
		if(n & i)
			std::cout << " 1";
		else
			std::cout << " 0";
	}
}

int Bitwise::set_bit(int n, int index, bool b) {
	if(b) {
		return (n | (1 << index));
	} else {
		int mask = ~(1 << index);
		return (n & mask);
	}
}

bool Bitwise::get_bit(int n, int index) {
	return ((n & (1 << index)) > 0);
}