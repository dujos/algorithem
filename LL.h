#include <iostream>

template<class T>
class LL {

public:
	template<class T>
	struct Node {
		Node* next;
		T key;
	};

private:
	Node<T>* head;
	Node<T>* tail;

public:
	LL() {
		head = NULL;
	};

	template<class T>
	void create_node_head(Node<T>* head, T key) {
		head->next = NULL;
		head->key = key;
	}

	template<class T>
	Node<T>* create_node(Node<T>* head, T key) {
		head->key = key;
		head->next = NULL;
		return head;
	}

	template<class T>
	void display(Node<T>* head) {
		LL<T>::Node<T>* node = head;
		if(node) {
			while(node) {
				std::cout << node->key << " ";
				node = node->next;
			}
		} else {
			std::cout << "no node"<<std::endl;
		}
		std::cout << std::endl;
	}

	template<class T>
	void push_node(Node<T>* head, T key) {
		LL<T>::Node<T>* node = new LL<T>::Node<T>;
		node->key = key;
		node->next = NULL;

		LL<T>::Node<T>* current = head;
		while(current) {
			if(current->next == NULL) {
				current->next = node;
				return;
			}
			current = current->next;
		}
	}

	template<class T>
	void push_node(T key) {
		Node<T>* node = new Node<T>;
		node->key = key;
		node->next = NULL;

		if(head == NULL) {
			head = node;
			return;
		}

		Node<T>* current = head;
		while(current) {
			if(current->next == NULL) {
				current->next = node;
				return;
			}
			current = current->next;
		}
		return;
	}

	template<class T>
	void push_node_head(Node<T>** head, T key) {
		LL<T>::Node<T>* node = new LL<T>::Node<T>;
		node->key = key;
		node->next = *head;
		*head = node;
	}

	template<class T>
	void insert_node(T key) {
		Node<int>* ptr = search_node(key);
		Node<int>* node = new Node<int>;
		node->key = key;

		Node<int>* current = head;
		
		while(current) {
			if(ptr)
				if(current == ptr) {
					node->next = current->next;
					current->next = node;
					return;
				}

			current = current->next;
		}
	}

	template<class T>
	Node<T>* search_node(Node<T>* head, T key) {
		Node<T>* current = head;
		while(current) {
			if(current->key == key) {
				std::cout << " Node with key: " << key << " in list\n";
				return current;
			}
			current = current->next;
		}
		std::cout << " No node with key: " << key << " in list\n";
		return NULL;
	}

	template<class T>
	Node<T>* search_node(T key) {
		if(head == NULL)
			return head;
		Node<T>* current = head;
		while(current) {
			if(current->key == key)
				return current;
			current = current->next;
		}
		return NULL;
	}

	template<class T>
	bool delete_node(Node<T>** head, Node<T>* ptr) {
		LL<T>::Node<T>* current = *head;
		if(ptr == *head) {
			*head = current->next;
			delete ptr;
			return true;
		}
		while(current) {
			if(current->next == ptr) {
				current->next = ptr->next;
				delete ptr;
				return true;
			}
			current = current->next;
		}
		return false;
	}

	template<class T>
	Node<T>* reverse(Node<T>* head) {
		LL::Node<T>* previous = NULL;
		LL::Node<T>* pivot = NULL;
		LL::Node<T>* current = *head;

		while(current) {
			pivot = current->next;
			current->next = previous;
			previous = current;
			current = pivot;
		}
		head = previous;
		return head;
	}

	template<class T>
	void delete_linked_list(Node<T>** node) {
		Node<T>* current;
		while(*node) {
			current = *node;
			*node = current->next;
			delete current;
		}
	}

	template<class T>
	void show(Node<T>* root) {
		LL<T>::Node<T>* node = head;
		if(node) {
			while(node) {
				std::cout << node->key << " ";
				node = node->next;
			}
		} else
			std::cout << "no node"<<std::endl;
		std::cout << std::endl;
	}
};