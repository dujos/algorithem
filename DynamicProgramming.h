#include <iostream>

static const int MAX = 1001;

class DynamicProgramming {

public:
	DynamicProgramming() {};
	~DynamicProgramming() {};

public:
	int fibo_recursive(int );
	int fibo_bu(int );
	int fibo_td(int );

	int count_recursive(int );
	int count_dp(int );

	int coin_change_recursive(int, int[], int);
};