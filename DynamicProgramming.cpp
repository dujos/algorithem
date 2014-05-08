#include "DynamicProgramming.h"

int DynamicProgramming::fibo_recursive(int n) {
	if(n==0) {
		return 0;
	} else if(n==1) {
		return 1;
	} else {
		return fibo_recursive(n-1) + fibo_recursive(n-2);
	}
}

int DynamicProgramming::fibo_bu(int n) {
	static int map[MAX];
	map[0] = 0;
	map[1] = 1;
	for(int i = 2; i < n; i++)
		map[i] = map[i-1] + map[i-2];
	return map[n];
}

int DynamicProgramming::fibo_td(int n) {
	static int map[MAX];

	if(map[n] > 0)
		return map[n];
	if(n == 0)
		map[n] = 0;
	else if(n == 1)
		map[n] = 1;
	else
		map[n] = fibo_td(n-1) + fibo_td(n-2);
	return map[n];
}

int DynamicProgramming::count_recursive(int n) {
	if(n < 0)
		return 0;
	if(n == 0)
		return 1;
	return count_recursive(n-3) + count_recursive(n-2) + count_recursive(n-1);
}

int DynamicProgramming::count_dp(int n) {
	static int map[MAX];
	if(n < 0)
		return 0;
	if(n == 0)
		return 1;
	if(map[n] > 0)
		return map[n];
	map[n] = count_dp(n-3) + count_dp(n-2) + count_dp(n-1);
	return map[n];
}

int DynamicProgramming::coin_change_recursive(int amount, int d[], int size) {
	if(amount <= 0)
		return 0;

	int min_coins = (int)INT_MAX;
	for(int i = 0; i < size; i++) {
		if(d[i] <= amount) {
			min_coins = std::min(min_coins, coin_change_recursive(amount-d[i], d, size));
		}
	}
	return min_coins;
}
