#include "QuickSort.h"

QuickSort::QuickSort() {}

QuickSort::~QuickSort() {}

void QuickSort::swap(int a[], int left, int right) {
	int temp = a[left];
	a[left] = a[right];
	a[right] = temp;
}

void QuickSort::qsort(int a[], int l, int r) {
	if(l >= r)
		return;	
	int left = l;
	int right = r;
	int pivot = a[(left+right)/2];
	while(left <= right) {
		while(a[left] < pivot) {
			left++;
		}
		while(a[right] > pivot) {
			right--;
		}
		if(left <= right) {
			swap(a, left, right);
			left++;
			right--;
		}
		print(a, SIZE);
	}
	qsort(a, l, right);
	qsort(a, left, r);
}

void QuickSort::print(int ar[], int size) {
	for(int i = 0; i < size; i++)
		std::cout << " " << ar[i];
	std::cout << std::endl;
}

void QuickSort::print(char ar[], int size) {
	for(int i = 0; i < size; i++)
		std::cout << " " << ar[i];
	std::cout << std::endl;
}

void QuickSort::swap(char& a, char& b) {
	char temp = b;
	a = b;
	b = temp;
}

int QuickSort::partition(char a[], int left, int right) {
	char pivot = a[right];
	int i = left-1;
	int j = right;
	for(;;) {
	//while(i <= j) {
		while(a[--j] > pivot) {}
		while(a[++i] < pivot) {}
		if(i>=j)
			break;
		swap(a[i], a[j]);
	//}
	}
	swap(a[right], a[i]);
	return i;
}
	
void QuickSort::quick(char a[], int left, int right) {
	if(left >= right)
		return;
	int p = partition(a, left, right);
	quick(a, left, p-1);
	quick(a, p+1, right);
}