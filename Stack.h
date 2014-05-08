#include <iostream>
#include <memory>
#include <vector>
#include <cmath>
#include <cassert>

class Stack {

public:
	Stack();
	Stack(int);
	~Stack();

	void push(int);
	int pop();
	bool empty();
	void print();
	void test();

private:
	int top;
	int* stack_array;
};