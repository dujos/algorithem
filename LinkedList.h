#include <iostream>

class LinkedList {

public:
	struct node {
		int value;
		node* next;
	};

public:
	LinkedList();
	~LinkedList();

private:
	node* root;

public:
	void print_linked_list();
	void print_linked_list(LinkedList::node* root);
	void print_linked_list_reversed();
	
	void reverse_linked_list();
	LinkedList::node* reverse_linked_list_recursive();
	LinkedList::node* reverse_helper(LinkedList::node* old, LinkedList::node* next);
	
	void pop_node_front();
	void pop_node_back();

	int length_linked_list();
	
	void replace_node(int position, int value);
	void remove_node(int position);
	void clear_linked_list();

	void insert_node(int position, int value);
	
	void push_front_node(int value);
	void push_back_node(int value);
};