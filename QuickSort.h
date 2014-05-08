#include <iostream>

#define SIZE 15

class QuickSort {

public:
	QuickSort();
	~QuickSort();

	void print(int ar[], int size);
	void print(char ar[], int size);

	void qsort(int[], int, int);
	void swap(int[], int, int);

	void swap(char& a, char& b);
	int partition(char [], int , int );
	void quick(char [], int , int );
};