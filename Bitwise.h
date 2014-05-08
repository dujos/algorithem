#include <iostream>

class Bitwise {

public:
	Bitwise();
	~Bitwise();

	void clear_bit(int n);
	void set_bit(int n);

	void binary(unsigned n);
	int set_bit(int n, int index, bool b);
	bool get_bit(int n, int index);
};