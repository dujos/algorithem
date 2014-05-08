#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() : root(NULL), count(0) {}

BinarySearchTree::~BinarySearchTree() { destroy_bst(root); }

void BinarySearchTree::destroy_bst(BinarySearchTree::node* root) {
	if(root != NULL) {
		destroy_bst(root->left);
		destroy_bst(root->right);
		delete root;
		root = NULL;
	}
}

BinarySearchTree::node* BinarySearchTree::search(int value) {
	return search(value, root);
}

BinarySearchTree::node* BinarySearchTree::search(int value, BinarySearchTree::node* leaf) {
	if(leaf) {
		if(value == leaf->value) {
			return leaf;
		} else if(value < leaf->value) {
			return search(value, leaf->left);
		} else if(value > leaf->value) {
			return search(value, leaf->right);
		}
	} 
	return NULL;
}

int BinarySearchTree::bst_length() {
	return count;
}

void BinarySearchTree::insert(int value) {
	if(root) {
		insert(value, root);
	} else {
		root = new node;
		root->left = NULL;
		root->right = NULL;
		root->value = value;
	}
}

BinarySearchTree::node* BinarySearchTree::insert(int value, BinarySearchTree::node* leaf) {
	if(value < leaf->value) {
		if(leaf->left != NULL) {
			insert(value, leaf->left);
		} else {
			leaf->left = new node;
			leaf->left->value = value;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	} else if(value >= leaf->value) {
		if(leaf->right != NULL) {
			insert(value, leaf->right);
		} else {
			leaf->right = new node;
			leaf->right->value = value;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
		}
	}
	return leaf;
}

void BinarySearchTree::inorder() { inorder(root); }

void BinarySearchTree::inorder(BinarySearchTree::node* root) {
	if(root == NULL)
		return;

	inorder(root->left);
	std::cout << root->value << " ";
	inorder(root->right);
}

void BinarySearchTree::preorder() { preorder(root); }

void BinarySearchTree::preorder(BinarySearchTree::node* root) {
	if(root) {
		std::cout << root->value << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

void BinarySearchTree::postorder() { postorder(root); }

void BinarySearchTree::postorder(BinarySearchTree::node* root) {
	if(root) {
		postorder(root->left);
		postorder(root->right);
		std::cout << root->value << " ";
	}
}

bool BinarySearchTree::print_level(int level, BinarySearchTree::node* root) {
	if(root == NULL)
		return false;
	else if(level == 1) {
		std::cout << root->value;
		return true;
	} else {
		return print_level(level - 1, root->left) | print_level(level - 1, root->right);
	}
}

void BinarySearchTree::print() {
	int level = 1;
	while(print_level(level, root)) {
		level++;
	}
}

