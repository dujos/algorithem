#include "LinkedList.h"

LinkedList::LinkedList() {
	this->root = NULL;
}

LinkedList::~LinkedList() {
	clear_linked_list();
}

void LinkedList::push_back_node(int value) {
	if(root == NULL) {
		root = new node;
		root->value = value;
		root->next = NULL;
	} else {
		struct node* pivot = root;
		while(pivot->next) {
			pivot = pivot->next;
		}
		pivot->next = new node;
		pivot = pivot->next;
		pivot->value = value;
		pivot->next = NULL;
	}
}

void LinkedList::push_front_node(int value) {
	if(root == NULL) {
		root = new node;
		root->value = value;
		root->next = NULL;
	} else {
		struct node* temp = NULL;
		
		temp = root;
		root = new node;
		root->next = temp;
		root->value = value;
		
		temp = NULL;
	}
}

void LinkedList::print_linked_list() {
	struct node* pivot = root;
	if(root) {
		while(pivot) {
			std::cout<< pivot->value << std::endl;
			pivot = pivot = pivot->next;
		}
	} else {
		std::cout << "list empty" << std::endl;
	}
}

void LinkedList::print_linked_list(LinkedList::node* r) {
	struct node* pivot = r;
	if(r) {
		while(pivot) {
			std::cout<< pivot->value << std::endl;
			pivot = pivot = pivot->next;
		}
	} else {
		std::cout << "list empty" << std::endl;
	}
}

void LinkedList::print_linked_list_reversed() {
	reverse_linked_list();
	print_linked_list();
}

void LinkedList::clear_linked_list() {
	struct node* current = root;
	struct node* temp = NULL;
	struct node* previous = NULL;

	while(current) {
		temp = current->next;
		previous = current;
		delete previous;
		current = temp;
	}

	current = NULL;
	previous = NULL;
	temp = NULL;
	root = NULL;
}

void LinkedList::reverse_linked_list() {
	struct node* previous = NULL;
	struct node* pivot = NULL;
	struct node* current = root;

	while(current) {
		pivot = current->next;
		current->next = previous;
		previous = current;
		current = pivot;
	}
	root = previous;
}

LinkedList::node* LinkedList::reverse_linked_list_recursive() {
	return reverse_helper(root, NULL);
}

LinkedList::node* LinkedList::reverse_helper(LinkedList::node* root, LinkedList::node* next) {
	if(root == NULL)
		return next;
	
	struct node* current = root;
	root = root->next;
	current->next = next;
	return reverse_helper(root, current);
}

void LinkedList::remove_node(int position) {
	/*
	struct node* current = root;
	struct node* previous = NULL;
	size_t i = 0;
	while(current != NULL) {
		if(position == i) {
			struct node* pivot = current->next;
			previous->next = pivot;
			delete current;
		}
		++i;
		previous = current;
		current = current->next;
	}
	*/
}

int LinkedList::length_linked_list() {
	if(root == NULL) {
		return 0;
	} else {
		struct node* pivot = root;
		int size = 0;
		while(pivot) {
			pivot = pivot->next;
			++size;
		}
		pivot = NULL;
		return size;
	}

}

void LinkedList::replace_node(int position, int value) {
	struct node* current = root;
	if(position > -1 && position < length_linked_list())
		for(int i = 0;  i < position; i++)
			current = current->next;
		current->value = value;
	current = NULL;
}

void LinkedList::insert_node(int position, int value) {
	struct node* current = root;
	int current_position = 0;
	int length = this->length_linked_list();
	if(position > -1 && position < length) {
		while(current->next != NULL) {
			if(position == 0) {
				this->push_front_node(value);
				break;
			} else if(current_position == position) {
				struct node* pivot = current->next;
				struct node* temp = new node;
				temp->value = value;
				temp->next = pivot;
				current->next = temp;
				break;
			} else {
				push_back_node(value);
			} 
			current_position++;
			current = current->next;
		}
	}
}

void LinkedList::pop_node_front() {
	struct node* current = root;
	root = current->next;
	delete current;
}

void LinkedList::pop_node_back() {
	struct node* current = root;
	struct node* previous = NULL;
	while(current->next != NULL) {
		previous = current;
		current = current->next;
	}
	delete current;
	previous->next = NULL;
}