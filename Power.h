#include <iostream>

class Power {
public:
	Power(int m, int n);
	Power(const Power& power);

	void operator()();

	double get_result() { return result; }

private:
	int m;
	int n;
	double result;
};