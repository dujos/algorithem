#include <iostream>

class BinarySearchTree {

public:
	struct node {
		node* left;
		node* right;
		int value;
	};

public:
	BinarySearchTree();
	~BinarySearchTree();

	BinarySearchTree::node* search(int value);
	void insert(int value);

	void inorder();
	void preorder();
	void postorder();

	int bst_length();

	void print();
	bool print_level(int level, BinarySearchTree::node* root);

private:
	BinarySearchTree::node* search(int value, BinarySearchTree::node* root);
	BinarySearchTree::node* insert(int value, BinarySearchTree::node* root);
	void destroy_bst(BinarySearchTree::node* root);

	void inorder(BinarySearchTree::node* root);
	void preorder(BinarySearchTree::node* root);
	void postorder(BinarySearchTree::node* root);

private:
	struct node* root;
	int count;
};