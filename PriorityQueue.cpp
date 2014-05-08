#include "PriorityQueue.h"

PriorityQueue::	PriorityQueue() {}

PriorityQueue::~PriorityQueue() {}

void PriorityQueue::push(int data, int level) {
	boost::shared_ptr<PQ> pointer(new PQ);
	pointer->data = data;
	pointer->level = level;
	if(head == NULL) {
		head = pointer;
		return;
	}
	boost::shared_ptr<PQ> current = head;
	boost::shared_ptr<PQ> previous = head;
	while(current) {
		if(level > current->level) {
			if(current == head) {
				boost::shared_ptr<PQ> old = head;
				head = pointer;
				head->next = old;
				return;
			}
			previous->next = pointer;
			pointer->next = current;
			return;
		}
		if(current->next == NULL) {
			current->next = pointer;
			return;
		}
		previous = current;
		current = current->next;
	}
}
	
int PriorityQueue::pop() {
	if(head == NULL)
		return -1;
	int data = head->data;
	if(head->next) {
		head = head->next;
	}
	return data;
}

void PriorityQueue::display() {
	boost::shared_ptr<PQ> current = head;
	while(current) {
		std::cout << current->data << " : " << current->level << std::endl;
		current = current->next;
	}
}

PQueue::PQueue(int size) {
	n = 0;
	pq = new int[size];
}

PQueue::~PQueue() {
	delete[] pq;
}

void PQueue::display() {
	for(int i = 1; i <= n; i++)
		std::cout << pq[i] << " ";
	std::cout << std::endl;
}

void PQueue::insert(int item) {
	pq[++n] = item;
}

int PQueue::remove() {
	int max = 0;
	for(int i = 1; i <= n; i++)
		if(pq[max] < pq[i])
			max = i;
	swap(pq[max], pq[n]);
	return pq[n--];
}

bool PQueue::empty() { return n == 0; }

void PQueue::swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

PQHeap::PQHeap(int size) {
	n = 0;
	pq = new int[size];
}

PQHeap::~PQHeap() { delete[] pq; }

void PQHeap::display() {
	for(int i = 1; i <= n; i++)
		std::cout << pq[i] << " ";
}

void PQHeap::insert(int item) {
	pq[++n] = item;
	heapify_up(pq, n);
}

//remove max element
int PQHeap::remove() {
	swap(pq[n], pq[1]);
	heapify_down(pq, 1, n-1);
	return pq[n--];
}

bool PQHeap::empty() { return n == 0; }

void PQHeap::swap(int& a, int& b) {
	int temp = b;
	b = a;
	a = temp;
}
		
void PQHeap::heapify_up(int a[], int k) {
	while(k > 1 && (a[k] > a[k/2])) {
		swap(a[k], a[k/2]);
		k = k/2;
	}
}

void PQHeap::heapify_down(int a[], int k, int n) {
	while(2*k <= n ) {
		int child = 2*k;
		if(child < n && a[child] < a[child+1]) child++;
		if(a[k] < a[child]) {
		    swap(a[k], a[child]);
		    k = child;
		}
		else
		    return;
	}
}