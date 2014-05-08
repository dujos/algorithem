#include <iostream>
#include <boost\shared_ptr.hpp>

struct PQ {
	int data;
	int level;
	boost::shared_ptr<PQ> next;
};

//Sorted linked list;
class PriorityQueue {

public:
	PriorityQueue();
	~PriorityQueue();

	void push(int, int);
	int pop();

	void display();
	
private:
	boost::shared_ptr<PQ> head;
};

//Sorted unsorted array;
class PQueue {

public:
	PQueue(int);
	~PQueue();

	void display();
	void insert(int);
	int remove();
	bool empty();
	void swap(int& a, int& b);

private:
	int n;
	int* pq;
};

class PQHeap {

public:
	PQHeap(int);
	~PQHeap();

	void display();
	void insert(int);
	int remove();
	bool empty();
	void swap(int& a, int& b);
		
	void heapify_up(int*, int);
	void heapify_down(int*, int, int);

private:
	int n;
	int* pq;
};