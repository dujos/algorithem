#include "Stack.h"

Stack::Stack() {
	this->top = 0;
	this->stack_array = NULL;
}

Stack::Stack(int size) {
	this->top = 0;
	this->stack_array = new int[size];
}

Stack::~Stack() { delete this->stack_array; }

void Stack::push(int n) { stack_array[top++] = n; }

int Stack::pop() { return stack_array[--top]; }

void Stack::test() {}

bool Stack::empty() {
	return top > 0 ? true : false;
}

void Stack::print() {
	int n = top;
	while(n--)
		std::cout << stack_array[n] << " ";
	std::cout << std::endl;
}
