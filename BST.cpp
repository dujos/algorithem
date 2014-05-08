#include "BST.h"
#include <deque>

BST::BST() {}

BST::~BST() {
}

struct BST::Node* BST::search(struct BST::Node* root, int key) {
	if(root == NULL)
		return NULL;
	if(root->value == key)
		return root;
	else {
		if(root->value < key)
			return search(root->right, key);
		else
			return search(root->left, key);
	}
}

struct BST::Node* BST::create_node(int key) {
	BST::Node* node = new Node;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	node->value = key;
	return node;
}

struct BST::Node* BST::left_most_node(struct BST::Node* root) {
	if(root == NULL)
		return root;
	while(root->left != NULL)
		root = root->left;
	return root;
}

struct BST::Node* BST::insert_node(struct BST::Node* root, int key) {
	static BST::Node* parent = NULL;
	BST::Node* node = root;
	
	if(node == NULL) {
		node = new Node;
		node->value = key;
		node->parent = parent;
		return node;
	} 
	if(node != NULL) {
		parent = node;
		if(node->value <= key) {
			parent = node;
			node->right = insert_node(node->right, key);
		} else {
			parent = node;
			node->left = insert_node(node->left, key);
		}
	}
	return node;
}

void BST::clear(struct BST::Node* node) {
	if(node != NULL) {
		clear(node->left);
		clear(node->right);
		delete node;
	}
}

bool BST::is_bst(struct BST::Node* root) {
	static int last_data = INT_MIN;
	if(root == NULL)
		return true;
	is_bst(root->left);
	if(last_data < root->value)
		last_data = root->value;
	else {
		std::cout << "NOT BST" << std::endl;
		return false;
	}
	is_bst(root->right);
	return true;
}

int BST::tree_size(struct BST::Node* root) {
	if(root == NULL)
		return 0;
	else
		return tree_size(root->left) + 1 + tree_size(root->right);
}

void BST::tree_clear(struct BST::Node* root) {
	if(root != NULL) {
		tree_clear(root->left);
		tree_clear(root->right);
		delete root;
	}
}

struct BST::Node* min_node(struct BST::Node* root) {
	if(root == NULL)
		return NULL;
	while(root->left)
		root = root->left;
	return root;
}

struct BST::Node* max_node(struct BST::Node* root) {
	if(root == NULL)
		return NULL;
	while(root->right)
		root = root->right;
	return root;
}

int BST::max_depth(struct BST::Node* root) {
	if(root == NULL || (root->left == NULL && root->right == NULL))
		return 0;
	int left = max_depth(root->left);
	int right = max_depth(root->right);
	return left > right ? (left + 1) : (right + 1);
}

int BST::min_depth(struct BST::Node* root) {
	if(root == NULL || (root->left == NULL && root->right == NULL))
		return 0;
	int left = min_depth(root->left);
	int right = min_depth(root->right);
	return left < right ? (left + 1) : (right + 1);
}

void BST::reverse_order_print(struct BST::Node* node) {
	if(node == NULL)
		return;
	if(node->left == NULL && node->right == NULL) {
		std::cout << node->value << " ";
		return;
	}
	reverse_order_print(node->right);
	std::cout << node->value << " ";
	reverse_order_print(node->left);
}

void BST::inorder(struct BST::Node* node) {
	if(node == NULL)
		return;
	inorder(node->left);
	std::cout << node->value;
	inorder(node->right);
}

void BST::postorder(struct BST::Node* node) {
	if(node == NULL)
		return;
	postorder(node->left);
	postorder(node->right);
	std::cout << node->value;
}

void BST::preorder(struct BST::Node* node) {
	if(node == NULL)
		return;
	std::cout << node->value;
	preorder(node->left);
	preorder(node->right);
}

void BST::breadth_first_traversal(struct BST::Node* root) {
	if(root == NULL)
		return;
	std::deque<BST::Node* > queue;
	queue.push_back(root);
	while(!queue.empty()) {
		BST::Node* node = queue.front();
		std::cout << node->value << " ";
		queue.pop_front();

		if(node->left != NULL)
			queue.push_back(node->left);
		if(node->right != NULL)
			queue.push_back(node->right);
	}
	std::cout << std::endl;
}

int BST::get_level(struct BST::Node* root, int element, int level) {
	if(root == NULL)
		return 0;
	if(root->value == element)
		return level;
	else if(root->value < element)
		return get_level(root->right, element, level+1);
	else
		return get_level(root->left, element, level+1);
}

void BST::convert_to_array(struct BST::Node* node, int arr[]) {
	int position = 0;
	if(node) {
		convert_to_array(node->left, arr);
		arr[position++] = node->value;
		convert_to_array(node->right, arr);
	}
}

void BST::path_finder(struct BST::Node* node, int path[], int level) {
	if(node == NULL)
		return;
	if(node->left == NULL && node->right == NULL) {
		path[level] = node->value;
		for(int i = 0; i <= level; i++)
			std::cout << path[i];
		std::cout << std::endl;
		return;
	}
	path[level] = node->value;
	path_finder(node->left, path, level+1);
	path_finder(node->right, path, level+1);
}

bool BST::is_balanced(struct BST::Node* node) {
	if(max_depth(node) - min_depth(node) <= 1)
		return true;
	return false;
}