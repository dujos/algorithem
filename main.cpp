#include <iostream>
#include <sstream>
#include <istream>
#include <ostream>
#include <iterator>
#include <conio.h>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <random>

#include <boost\shared_ptr.hpp>
#include <boost\lambda\lambda.hpp>
#include <boost\algorithm\string.hpp>
#include <boost\date_time.hpp>
#include <boost\thread.hpp>
#include <boost\foreach.hpp>
#include <boost\date_time\posix_time\posix_time.hpp>
#include <boost\bind.hpp>
#include <boost\function.hpp>

#include "Animation.h"
#include "BST.h"
#include "BT.h"
#include "Bitwise.h"
#include "Composer.h"
#include "DynamicProgramming.h"
#include "Functor.h"
#include "LL.h"
#include "Patterns.h"
#include "Power.h"
#include "Pointer.h"
#include "PriorityQueue.h"
#include "Stack.h"
#include "StringTest.h"
#include "QuickSort.h"
#include "Worker.h"

/*
#define N 3

void multiply(int a[][N], int b[][N], int c[][N]) {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			for(int k = 0; k < N; k++) {
				c[i][j] = c[i][j] + a[i][k]* b[k][j];
			}
		}
	}
}

void print_multi_array(int parray[][N], int i, int j) {
	for(int ii = 0; ii < i; ii++) {
		for(int jj = 0; jj < j; jj++) {
			std::cout << parray[ii][jj] << " ";
		}
		std::cout << std::endl;
	}
}

void worker(const char* message, unsigned delay) {
	std::cout << message << std::endl;
	boost::posix_time::seconds working_duration(delay);
	std::cout << "worker: running; " << std::endl;
	boost::this_thread::sleep(working_duration);
	std::cout << "worker: finished; " << std::endl;
}

static void static_function() {
	for(int i = 0; i < 10; i++) {
		std::cout << i << " static function " << std::endl;
		boost::this_thread::yield();
	}
}

static boost::uint64_t sum_total(boost::uint64_t* total, int size) {
	*total = 0;
	for(int i = 0; i < size; i++)
		*total +=1;
	std::cout << *total << std::endl;
	return *total;
}

static int sums(int* total) {
	*total = 5;
	return *total;
}

static void partial_sums(boost::uint64_t* final, int start, int sums, boost::mutex* cout_mutex) {
	cout_mutex->lock();
	std::cout << " starting at " << start << " sums to " << sums << std::endl;
	cout_mutex->unlock();
	boost::posix_time::ptime start_time = boost::posix_time::microsec_clock::local_time();

	boost::uint64_t sub_result = 0;
	for(int i = start; i < (start+sums); i++)
		sub_result += i;
	*final = sub_result;

	boost::posix_time::ptime end_time = boost::posix_time::microsec_clock::local_time();
	cout_mutex->lock();
	std::cout << " ending at " << (end_time-start_time) << std::endl;
	cout_mutex->unlock();
}

int val(int v) {
	return 0;
}

void get_name(std::string name) {
	std::cout << "get_name" << std::endl;
	std::cout << name << std::endl;
	std::cout << std::endl;
	std::cout << name.append(" aa") << std::endl;
}

void get_names(std::string& name) {
	std::cout << "get_names" << std::endl;
	std::cout << name << std::endl;
	std::cout << std::endl;
	std::cout << name.append(" aa") << std::endl;
}

class Entity {
public:
	virtual void draw() = 0;
};

class A : public Entity {
public:
	void draw() { std::cout << "a"; }
	void draw(Entity* en) { en->draw(); }
};

class B : public Entity {
public:
	void draw() { std::cout << "b"; }
	void draw(Entity* en) { en->draw(); }
};

int** allocate_array(int isize, int jsize) {
	int** parray = new int*[isize];
	for(int i = 0; i < isize; i++) {
		parray[i] = new int[jsize];
		for(int j = 0; j < jsize; j++) {
			parray[i][j] = 1;
		}
	}
	return parray;
}

void release_array(int** parray, int isize) {
	for(int i = 0; i < isize; i++)
		delete[] parray[i];
	delete[] parray;
}
*/

int main(int argc, char** argv) {
	/*
	std::cout << "main: startup; " << std::endl;
	Worker worker(10);
	boost::thread worker_thread(worker);
	std::cout << "main: waiting for threead " << std::endl;
	worker_thread.join();
	std::cout << "main: done " << std::endl;

	Animation animation;
	animation.start_animation();
	std::getchar();
	std::cout << " animation stopping... " << std::endl;
	animation.stop_animation();
	std::cout << " animation stopped." << std::endl;

	int m = 2;
	int n = 200;
	Power power(m, n);

	boost::thread thread(boost::ref(power));
	double result = m*n;
	thread.join();

	//display result
	std::cout << "( " << m << ", " << n << ") / (" << m << "*" << n << ") = " 
		<< power.get_result()/ result << std::endl;

	boost::uint64_t result;
	int size = 20;
	boost::thread worker(sum_total, &result, size);
	worker.join();

	int t;
	int h = sums(&t);
	std::cout << "t: " << t << " h: " << h;
	
	boost::mutex cout_mutex;
	std::vector<boost::uint64_t* > part_surmation;
	std::vector<boost::thread* > threads;
	const int thread_size = 4;
	const int sum_maximum = 10000;
	int sums_per_thread = sum_maximum/thread_size;

	for(int i = 0; i < thread_size; i++)
		part_surmation.push_back(new boost::uint64_t(0));

	for(int start = 0, i = 0; start < sum_maximum; start += sums_per_thread, i++) {
		threads.push_back(new boost::thread(partial_sums, part_surmation[i], 
			start, sums_per_thread, &cout_mutex));
	}

	for(int i = 0; i < threads.size();i++)
		threads[i]->join();

	boost::uint64_t result = 0;
	for(int i = 0; i < part_surmation.size(); i++)
		result += *part_surmation[i];

	for(int i = 0; i < thread_size; i++) {
		delete threads[i];
		delete part_surmation[i];
	}
	std::cout << "result " << result;

	//char* ch = "caco";
	//StringTest st(ch);
	//char result = st.first_repeating_char();
	//std::cout << result;

	//StringTest st;
	//const char* test = "abcdee";
	//char c = st.first_repeating_char(test);
	//std::cout << c;

	BST bst;
	BST::Node* root = bst.create_node(24);
	bst.insert_node(root, 20);
	bst.insert_node(root, 18);
	bst.insert_node(root, 16);
	bst.insert_node(root, 19);
	bst.insert_node(root, 25);
	bst.insert_node(root, 28);
	bst.insert_node(root, 27);

	std::cout << "inorder" << std::endl;
	bst.inorder(root);
	std::cout << std::endl;

	std::cout << "is BST: " << bst.is_bst(root) << std::endl;
	std::cout << "size of BST: " << bst.tree_size(root) << std::endl;

	std::cout << "max depth: " << bst.max_depth(root) << std::endl;
	std::cout << "min depth: " << bst.min_depth(root) << std::endl;

	std::cout << "balanced tree: " << std::endl;

	int key = 20;
	BST::Node* found = bst.search(root, key);
	if(found) {
		std::cout << "value in tree: " << key << std::endl;
	} else {
		std::cout << "value not in tree" << std::endl;
	}

	key = 99;
	found = bst.search(root, key);
	if(found) {
		std::cout << "value in tree: " << key << std::endl;
	} else {
		std::cout << "value not in tree" << std::endl;
	}

	std::cout << "preorder" << std::endl;
	bst.preorder(root);
	std::cout << std::endl;

	std::cout << "postorder" << std::endl;
	bst.postorder(root);
	std::cout << std::endl;

	int path[10];
	bst.path_finder(root, path, 0);

	std::cout << "breadth first traversal" << std::endl;
	bst.breadth_first_traversal(root);

	int tree_size = bst.tree_size(root);
	int* arr = new int[tree_size];
	bst.convert_to_array(root, arr);
	std::cout << "array: ";
	for (int i = 0; i < tree_size; i++)
	    std::cout << arr[i] << ' ';
	std::cout << std::endl;
	delete [] arr;

	BT bt;
	BT::Node* root;
	char chars[] = {'f', 'b', 'a', 'd', 'c', 'e', 'g', 'i', 'h'};
	//char chars[] = {'b', 'a', 'c'};

	std::vector<char> vec_chars(chars, chars + sizeof(chars)/sizeof(char));
	for(int i = 0; i <vec_chars.size(); i++) {
		if(i == 0)
			root = bt.create_node(vec_chars[i]);
		else
			bt.insert_node(root, vec_chars[i]);
	}

	boost::function<void (BT::Node*)> inorder = std::bind1st(std::mem_fun(&BT::inorder), &bt);
	boost::function<void (BT::Node*)> postorder = std::bind1st(std::mem_fun(&BT::postorder), &bt);
	boost::function<void (BT::Node*)> preorder = std::bind1st(std::mem_fun(&BT::preorder), &bt);
	
	boost::function<void (BT::Node*)> print_functions[3] = {inorder, postorder, preorder};
	std::array<std::string, 3> print_function_names = {"inorder", "postorder", "preorder"};
	
	for(int i = 0; i < 3; i++) {
		std::cout << print_function_names[i] << std::endl;
		print_functions[i](root);
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "max depth: " << bt.max_depth(root) << std::endl;
	std::cout << "min depth: " << bt.min_depth(root) << std::endl;

	BT::Node* found = bt.search_node(root, 'a');
	char key = 'a';
	if(found)
		std::cout << "value in tree: " << key << std::endl;
	else
		std::cout << "value not in tree" << std::endl;

	std::cout << std::endl;
	std::cout << "predeccesors: " << std::endl;
	char keys[3] = {'b', 'e', 'i'};
	BT::Node* predeccesor = NULL;
	for(int i = 0; i < 3; i++) {
		found = bt.search_node(root, keys[i]);
		if(found) {
			predeccesor = bt.predeccesor_inorder(found);
			if(predeccesor)
				std::cout << "predeccesor of " << keys[i] << " is " << predeccesor->key << std::endl;
			else {
				std::cout << "no predeccesor" << std::endl;
			}
		} else {
			std::cout << "no predeccesor" << std::endl;
		}
		std::cout << std::endl;
	}

	std::cout << "successor: " << std::endl;
	BT::Node* successor = NULL;
	for(int i = 0; i < 3; i++) {
		found = bt.search_node(root, keys[i]);
		if(found) {
			successor = bt.succesor_inorder(found);
			if(successor)
				std::cout << "successor of " << keys[i] << " is " << successor->key << std::endl;
			else {
				std::cout << "no successor" << std::endl;
			}
		} else {
			std::cout << "no successor" << std::endl;
		}
		std::cout << std::endl;
	}

	std::cout << "breadth first traversal: " << std::endl;
	bt.breadth_first_traversal(root);

	std::cout << "swap left and right" << std::endl;
	std::cout << "before" << std::endl;
	bt.inorder(root);
	bt.mirror(root);
	std::cout << std::endl <<"after" << std::endl;
	bt.inorder(root);
	std::cout << std::endl;

	std::cout << "make a new tree with minimal depth" << std::endl;
	std::vector<char> array_chars(chars, chars + sizeof(chars)/sizeof(char));
	std::stable_sort(array_chars.begin(), array_chars.end());

	BT::Node* node = bt.create_minimal_bst(array_chars, 9);
	std::cout << "inorder" << std::endl;
	bt.inorder(node);


	std::cout << std::endl;
	std::cout << "delete a tree" << std::endl;
	bt.clear_node(root);

	std::cout << std::endl;

	int arr[] = {23, 7, 9, 24, 34, 67, 78, 88};
	int size = sizeof(arr)/sizeof(int);
	int result;
	
	result = bt.bsearch_iterative(arr, size, 7);
	std::cout << result << ": 7" << std::endl;
	result = bt.bsearch_iterative(arr, size, 88);
	std::cout << result << ": 88" << std::endl;
	result = bt.bsearch_iterative(arr, size, 77);
	std::cout << result << ": 77" << std::endl;

	std::cout << std::endl;

	result = bt.bsearch_recursive(arr, 0, size-1, 7);
	std::cout << result << ": 7" << std::endl;
	result = bt.bsearch_recursive(arr, 0, size-1, 88);
	std::cout << result << ": 88" << std::endl;
	result = bt.bsearch_recursive(arr, 0, size-1, 77);
	std::cout << result << ": 77" << std::endl;

	std::cout << std::endl;
	
	DynamicProgramming dp;
	int n = 10;
	std::cout << "top down: " << std::endl;
	std::cout << dp.fibo_td(n) << std::endl;

	std::cout << "recursive: " << std::endl;
	std::cout << dp.fibo_recursive(n) << std::endl;

	std::cout << "bottom up: " << std::endl;
	std::cout << dp.fibo_bu(n) << std::endl;

	int steps = 10;
	std::cout << "count recursive: " << std::endl;
	std::cout << dp.count_recursive(steps) << std::endl;

	std::cout << "count dynamic programming: " << std::endl;
	std::cout << dp.count_dp(steps) << std::endl;

	std::cout << "count change recursive: " << std::endl;
	int denominations[] = {1, 5, 10, 25};
	int size = sizeof(denominations)/sizeof(int);
	int amount = 40;
	std::cout << dp.coin_change_recursive(amount, denominations, size) << std::endl;
	
	LL<int>::Node<int>* root = new LL<int>::Node<int>;
	LL<int> ll;
	ll.create_node_head(root, 10);
	ll.push_node(root, 12);
	ll.push_node(root, 14);
	ll.push_node(root, 16);
	ll.push_node(root, 18);
	
	std::cout << "is key present" << std::endl;
	ll.search_node(root, 12);
	std::cout << std::endl;
	ll.search_node(root, 2);

	ll.push_node_head(&root, 20);
	ll.push_node_head(&root, 24);

	ll.display(root);

	LL<int>::Node<int>* current_delete_node = ll.search_node(root, 20);
	LL<int>::Node<int>* next_delete_node = ll.search_node(root, 12);
		
	std::cout << "Node delete " << std::endl;
	std::cout << ll.delete_node(&root, current_delete_node) << std::endl;
	std::cout << ll.delete_node(&root, next_delete_node) << std::endl;

	ll.display(root);
	ll.delete_linked_list(&root);
	ll.display(root);

	std::cout << "reverse linked list " << std::endl;
	
	//LL<int>::Node<int>* headd = ll.reverse(root);
	//ll.display(headd);

	std::cout << std::endl << std::endl;
	LL<int>::Node<int>* tnode = new LL<int>::Node<int>;
	tnode->key = 10;
	tnode->next = NULL;
	LL<int>::Node<int>* node = ll.create_node(tnode, 20);
	std::cout << tnode->key << std::endl;

	std::cout << std::endl << std::endl;
	LL<int>::Node<int>* rroot = new LL<int>::Node<int>;
	LL<int> linked_list;

	linked_list.push_node(10);
	linked_list.push_node(12);
	linked_list.push_node(14);
	linked_list.push_node(16);
	linked_list.insert_node(14);
	linked_list.insert_node(18);
	linked_list.show(rroot);
	
	Singleton* s1 = Singleton::get_singleton();
	Singleton* s2 = Singleton::get_singleton();
	
	std::cout << std::endl << std::endl;
	Merge* merge = new Merge;
	Quick quick;

	Strategy astrategy;
	astrategy.set_sort(merge);
	astrategy.sorting();

	astrategy;
	astrategy.set_sort(&quick);
	astrategy.sorting();

	std::cout << std::endl << std::endl;
	BinaryTree binaryTree;
	HashMap* hashmap = new HashMap;

	Strategy bstrategy;
	bstrategy.set_search(&binaryTree);
	bstrategy.searching();

	bstrategy;
	bstrategy.set_search(hashmap);
	bstrategy.searching();

	int ints[5] = {1, 2, 3, 9, 5};
	std::vector<int>::iterator iter;
	std::vector<int> obs(ints, ints + sizeof(ints)/sizeof(int));
	iter = std::find(obs.begin(), obs.end(), 9);
	obs.erase(iter);
	iter = std::find(obs.begin(), obs.end(), 5);
	obs.erase(iter);
	iter = std::find(obs.begin(), obs.end(), 3);
	obs.erase(iter);

	for(int i = 0; i < obs.size(); i++)
		std::cout << obs[i] << std::endl;

	ClockTime timer;
	DigitalClock digital_clock(&timer);
	AnalogClock analog_clock(&timer);
	timer.tick();

	Factory* factory = new Factory;
	Button* button_apple;
	Button* button_windows;

	button_windows = factory->create_button("windows");
	button_windows->draw();

	button_apple = factory->create_button("apple");
	button_apple->draw();

	button_apple = factory->create_button("android");
	button_apple->draw();
	
	Rectangle rectangle;
	rectangle.draw();
	
	Circle circle;
	circle.draw();

	Square square;
	square.draw();

	Solid solid;
	solid.add(&square);
	solid.add(&circle);
	solid.add(&rectangle);
	solid.draw();
	
	//int a[SIZE] = {3, 11, 1, 8, 12, 7, 9, 13, 6, 4, 14, 5, 15, 2, 16};
	//QuickSort qs;
	//std::cout << "printing: " << std::endl;
	//qs.print(a, SIZE);
	//std::cout << "sorting: " << std::endl;
	//qs.qsort(a, 0, SIZE-1);

	//QuickSort qs;
	//char a[5] = {'e', 'b', 'a', 'd', 'c'};
	//qs.quick(a, 0, sizeof(a)/sizeof(a[0])-1);
	//qs.print(a, sizeof(a)/sizeof(a[0])-1);
	
	//typedef std::istream_iterator<int> in;
	//std::cout << "type number: ";
	//std::for_each(in(std::cin), in(), 
	//	std::cout << boost::lambda::_1 * 10 << "\ntype another number: ");

	//boost::shared_ptr<A> pointer_a(new A);
	//boost::shared_ptr<A> pointer_b(pointer_a);

	//std::cout << pointer_a.get() << std::endl;
	//std::cout << pointer_b.get() << std::endl;
	
	
	//struct Stack::stack* ss = (struct Stack::stack* )std::malloc(sizeof(Stack::stack));

	stack.create_stack(&stack.stack, 4);
	std::cout << stack.stack.length << std::endl;
	stack.create_stack(&stack.stack, 8);
	std::cout << stack.stack.length << std::endl;
	stack.create_stack(&stack.stack, 12);
	std::cout << stack.stack.length << std::endl;
	stack.create_stack(&stack.stack, 16);
	std::cout << stack.stack.length << std::endl;

	//stack.print(&stack.stack);
	//stack.create_stack(ss, 4);

	//std::cout << std::endl;
	//std::cout << sizeof(float) << " " << sizeof(int);
	
	Stack stack(5);
	
	std::array<int, 5> arr = {20, 40, 30, 10, 50};
	std::vector<int> vec(arr.begin(), arr.end());
	
	stack.push(10);
	stack.push(30);
	stack.push(40);
	stack.push(50);
	stack.print();

	stack.pop();
	stack.print();
	stack.pop();
	stack.print();
	stack.pop();
	stack.print();
	stack.pop();
	stack.print();

	std::cout << "empty:" << stack.empty() << std::endl;

	stack.pop();
	stack.print();
	stack.pop();
	stack.print();

	std::cout << "empty:" << stack.empty() << std::endl;

	PriorityQueue pq;
	pq.push(4, 400);
	pq.push(5, 500);
	pq.push(1, 100);
	pq.push(2, 200);
	pq.push(3, 300);

	pq.display();

	std::cout << std::endl;
	pq.pop();
	pq.pop();
	pq.display();
	
	int a[] = {0, 19, 17, 16, 12, 9, 15, 1, 2, 11, 7, 3, 10, 14}; 
	int sz = sizeof(a)/sizeof(a[0]);
	PQueue *q = new PQueue(sz-1);

	for(int i = 1; i < sz; i++)
		q->insert(a[i]);
	q->display();

	std::cout << "remove max " << q->remove() << std::endl;
	q->display();
	
	int a[] = {0, 19, 17, 16, 12, 9, 15, 1, 2, 11, 7, 3, 10, 14}; 
	int sz = sizeof(a)/sizeof(a[0]);
	PQHeap *q = new PQHeap(sz-1);
	for(int i = 1; i < sz; i++)
		q->insert(a[i]);
	q->display();

	std::cout << "remove max " << q->remove() << std::endl;
	q->display();
	
	std::string name = "name";
	get_name(name);

	std::cout << std::endl;
	std::cout << "name after";
	std::cout << name;

	get_names(name);

	std::cout << std::endl;
	std::cout << "name after";
	std::cout << name;
	
	Entity* entA = new A;
	Entity* entB = new B;	
	
	A* a = new A;
	B* b = new B;
	//entA->draw();
	//entB->draw();
	a->draw(b);
	std::cout << std::endl;
	b->draw(a);
	*/
	
	//std::string func = "func";
	//Functor functor(1, 2);
	//Functor(1, 2) (func);
	//functor(func);
	//std::cout << std::endl;
	//std::cout << func << std::endl;
	//functor();
	
	/*
	int arr[5] = {1, 2, 3, 4, 5};
	std::array<int, 5> ar = {1, 2, 3, 4, 5};
	std::vector<int> vec(arr, arr+sizeof(arr)/sizeof(int));
	
	//int val = 10;
	//std::for_each(vec.begin(), vec.end(), Functor(val));

	//int n = std::multiplies<int>() (4, 5);
	//std::cout << n << std::endl;

	std::set<int> ss(vec.begin(), vec.end());
	std::vector<int> v;

	std::transform(ss.begin(), ss.end(), 
		std::back_inserter(v),
		std::bind(std::multiplies<int>(), std::placeholders::_1, 100));
	for(int i = 0; i < v.size(); i++)
		std::cout << v[i] << std::endl;

	Line line;
	std::vector<int> vect;
	for(int i = 0; i < 10; i++)
		vect.push_back(i);
	
	std::for_each(vect.begin(), vect.end(), line);

	int* a;
	a = new int(1);
	std::cout << "a: " << (*a) << " " << &a << std::endl;

	int* const b = new int(2);
	int* f = new int(101);
	std::cout << "b: " << (*b) << " " << &b << std::endl;
	*b = 100;
	std::cout << "b: " << (*b) << " " << &b << std::endl;
	//b = &f; cannot point to another object

	const int* c;
	c = new int(3);
	int d = 95;
	c = &d;
	std::cout << "d: " << d << " " << &d << std::endl;
	std::cout << "c: " << (*c) << " " << &c << std::endl;
	//*c = 100; cannot reasign the value of the pointer

	int e = 100;
	int g = 200;
	const int* const final = &e;
	//*final = 100;
	//final = &g;

	Composer composer;
	std::vector<std::string> composers;
	composers.push_back("Wagner");
	composers.push_back("Debussy");
	composers.push_back("Reich");

	std::string s = composer.get_composer(&composers, 1);
	std::cout << s << std::endl;
	
	std::string* ptr = new std::string();
	*ptr = composer.get_composer(&composers, 2);
	std::cout << *ptr << std::endl;

	int* a = new int(10);
	int* b = new int(100);
	int c = 150;

	int aa[2] = {1, 2};
	//a = aa;
	a = &aa[0];
	std::cout << *a << std::endl;
	std::cout << ++*a << std::endl;

	std::cout << "aa: " << aa << std::endl;
	std::cout << "&aa: " << &aa[0] << std::endl;

	char* suits[4] = {"hearts", "diamonds", "clubs", "spades"};
	std::cout << suits[0][0];

	Card deck[52];
	char* face[] = {"Ace", "Deuce", "Three", "Four", "Five",
		            "Six", "Seven", "Eight", "Nine", "Ten",
					"Jack", "Queen", "King"};
	char* suit[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

	std::srand((unsigned)std::time(0));

	Card::set_deck(deck, face, suit);
	Card::shuffle_deal(deck);


	//two dimensional arrays;
	int arrays[][2] = {{1, 2}, 
					{2, 3}, 
					{4, 5}};

	std::cout << sizeof(arrays)/sizeof(arrays[0]) << " size of rows" << std::endl;
	std::cout << sizeof(*arrays)/sizeof(int) << " size of columns" << std::endl;
	std::cout << sizeof(arrays[0])/sizeof(int) << " size of columns" << std::endl;
	std::cout << sizeof(arrays)/sizeof(int) << " size of array" << std::endl;
	std::cout << std::endl;

	for(int i = 0; i < sizeof(arrays)/sizeof(*arrays); i++) {
		for(int j = 0; j < sizeof(*arrays)/sizeof(int); j++) {
			std::cout << arrays[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	*/
	
	//for(int i = 0; i < sizeof(arrays)/sizeof(*arrays); i++)
	//	delete[] arrays[i];
	//delete[] arrays;

	//float pfloats[4] = {1.f, 2.f, 3.f, 4.f};
	//for(int i = 0; i < sizeof(pfloats)/sizeof(float); i++)
	//	std::cout << *(pfloats+4) << " ";

	/*
	std::cout << std::endl;
	int i = 5;
	int j = 2;
	int** parray = allocate_array(i, j);
	for(int ii = 0; ii < i; ii++) {
		for(int jj = 0; jj < j; jj++) {
			std::cout << parray[ii][jj] << " ";
		}
		std::cout << std::endl;
	}
	release_array(parray, i);

	int a[][N] = {{1,2,3},
	              {4,5,6},
	              {7,8,9}};
	
	int b[][N] = {{9,8,7},
	              {6,5,4},
	              {3,2,1}};
	
	int c[N][N] = {0};

	multiply(a, b, c);
	print_multi_array(c, N, N);
	*/
	
	/*
	std::ostringstream oss;
	std::string ss;

	oss << "images" << 11 << ":" << 21;
	ss = oss.str();
	std::cout << ss;
	*/



	std::getchar();
	return 0;
}