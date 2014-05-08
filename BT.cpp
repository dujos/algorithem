#include "BT.h"
#include <deque>

BT::BT() {}

BT::~BT() {}

struct BT::Node* BT::insert_node(BT::Node* node, char key) {
	static BT::Node* parent;
	BT::Node* temp;

	if(!node) {
		temp = create_node(key);
		temp->parent = parent;
		return temp;
	}
	
	if(node) {
		if(node->key >= key) {
			parent = node;
			node->left = insert_node(node->left, key);
		} else {
			parent = node;
			node->right = insert_node(node->right, key);
		}
	}
	return node;
}

struct BT::Node* BT::search_node(BT::Node* root, char key) {
	BT::Node* node = root;
	if(node) {
		if(node->key == key)
			return node;
		else if(node->key >= key)
			node = search_node(node->left, key);
		else
			node = search_node(node->right, key);
		return node;
	}
	return node;
}

struct BT::Node* BT::create_node(char k) {
	BT::Node* node = new Node;
	node->key = k;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	return node;
}

void BT::clear_node(BT::Node* root) {
	if(root) {
		clear_node(root->left);
		clear_node(root->right);
		delete root;
	}
}

bool BT::is_bt(BT::Node* ) {
	return true;
}

bool BT::is_balanced(BT::Node* root) {
	if(min_depth(root) - max_depth(root) <= 1)
		return true;
	return false;
}

int BT::min_depth(BT::Node* root) {
	BT::Node* node = root;
	if(root == NULL || (root->left == NULL && root->right == NULL))
		return 1;
	int left = max_depth(root->left);
	int right = max_depth(root->right);
	return (left > right) ? (right+1) : (left+1);
}

int BT::max_depth(BT::Node* root) {
	BT::Node* node = root;
	if(root == NULL || (root->left == NULL && root->right == NULL))
		return 1;
	int left = max_depth(root->left);
	int right = max_depth(root->right);
	return (left > right) ? (left+1) : (right+1);
}

struct BT::Node* BT::min_node(BT::Node* root) {
	BT::Node* node = root;
	if(!node->left)
		return node;
	else
		return min_node(node->left);
}

struct BT::Node* BT::max_node(BT::Node* root) {
	BT::Node* node = root;
	if(!node->right)
		return node;
	else
		return max_node(node->right);
}

struct BT::Node* BT::maxx_node(BT::Node* root) {
	BT::Node* node = root;
	while(node->right) {
		node = node->right;
	}
	return node;
}

struct BT::Node* BT::left_node(BT::Node* root) {
	BT::Node* node = root;
	if(!node) {
		return node;
	} else if(node->left) {
		return left_node(node->left);
	}
	return node;
}

struct BT::Node* BT::left_node_tree(BT::Node* root) {
	BT::Node* node = root;
	while(node->left)
		node = node->left;
	return node;
}

int BT::bt_size(BT::Node* root) {
	BT::Node* node = root;
	if(!root) {
		return 0;
	} else {
		return bt_size(node->left) + 1 + bt_size(node->right);
	}
}

void BT::inorder(BT::Node* root) {
	BT::Node* node = root;
	if(!node)
		return;
	inorder(node->left);
	std::cout << node->key << " ";
	inorder(node->right);
}

void BT::inorder_parent(BT::Node* root) {
	BT::Node* node = root;
	if(!node)
		return;
	inorder_parent(node->left);
	std::cout << node->parent->key << " ";
	inorder_parent(node->right);
}

void BT::preorder(BT::Node* root) {
	BT::Node* node = root;
	if(!node)
		return;
	std::cout << node->key << " ";
	preorder(node->left);
	preorder(node->right);
}

void BT::postorder(BT::Node* root) {
	BT::Node* node = root;

	if(!node)
		return;
	postorder(node->left);
	postorder(node->right);
	std::cout << node->key << " ";
}

void BT::path_finder(BT::Node* root, int path[], int level) {
	BT::Node* node = root;
	if(!node)
		return;
	if(!node->left && !node->right) {
		path[level] = node->key;
		for(int i = 0; i <= level; i++)
			std::cout << path[i];
		std::cout << std::endl;
		return;
	}
	path[level] = node->key;
	path_finder(node->left, path, level+1);
	path_finder(node->right, path, level+1);
}

void BT::breadth_first_traversal(BT::Node* root) {
	if(!root)
		return;

	BT::Node* noot = root;
	std::deque<BT::Node* > qs;
	qs.push_back(noot);
	while(!qs.empty()) {
		BT::Node* temp;
		temp = qs.front();
		std::cout << temp->key << " ";
		qs.pop_front();
		if(temp->left)
			qs.push_back(temp->left);
		if(temp->right)
			qs.push_back(temp->right);
	}
	std::cout << std::endl;
}

void BT::mirror(BT::Node* root) {
	BT::Node* temp_node;
	BT::Node* node = root;
	if(!node)
		return;
	mirror(node->left);
	mirror(node->right);
	//swap
	temp_node = node->left;
	node->left = node->right;
	node->right = temp_node;
}

struct BT::Node* BT::add_to_bst(std::vector<char> arr, int start, int end) {
	if(end < start)
		return NULL;
	int mid = (start+end)/2;
	BT::Node* node = new Node;
	node->key = arr[mid];
	node->left = add_to_bst(arr, start, mid-1);
	node->right = add_to_bst(arr, mid+1, end);
	return node;
}

struct BT::Node* BT::create_minimal_bst(std::vector<char> arr, int size) {
	return add_to_bst(arr, 0, size-1);
}

struct BT::Node* BT::predeccesor_inorder(BT::Node* root) {
	BT::Node* node = root;
	if(node->left)
		return maxx_node(node->left);

	BT::Node* temp = node->parent;
	while(temp != NULL && node == temp->left) {
		node = temp;
		temp = temp->parent;
	}
	return temp;
}

struct BT::Node* BT::succesor_inorder(BT::Node* root) {
	BT::Node* node = root;
	if(node->right)
		return min_node(node->right);
	BT::Node* temp = node->parent;
	while(temp && node == temp->right) {
		node = temp;
		temp = temp->parent;
	}
	return temp;
}

void BT::delete_key(BT::Node* root, char key) {
	BT::Node* node = NULL;
	BT::Node* parent = NULL;
	BT::Node* child = NULL;
	BT::Node* predeccesor = NULL;

	node = search_node(root, key);
	//leaf node
	if(node->left == NULL && node->right == NULL) {
		if(node->parent)
			//parent = node->parent;
			//std::cout << node->parent->key;
		/*
		if(node == parent->left) {
			parent->left = NULL;
		} else {
			parent->right = NULL;
		}
		*/
		//delete node;
		return;
	}
	return;
	/*
	//two children - replace with predeccessor and delete
	if(node->left && node->right) {
		char key_predeccesor = predeccesor_inorder(node)->key;
		predeccesor = search_node(root, key_predeccesor);
		if(predeccesor->parent->left == predeccesor) {
			predeccesor->parent->left = NULL;
		} else if(predeccesor->parent->right == predeccesor) {
			predeccesor->parent->right = NULL;
		}
		node->key = predeccesor->key;
		delete node;
		return;
	}

	//one child
	if(node->left) {
		child = node->left;
	} else if(node->right) {
		child = node->right;
	}

	parent = node->parent;
	if(parent->left && parent->left == node) {
		parent->left = child;
	} else if(parent->right && parent->right == node) {
		parent->right = child;
	}

	child->parent = parent;
	delete node;
	return;
	*/
}

int BT::bsearch_recursive(int arr[], int low, int high, int key) {
	if(low > high)
		return -1;
	int mid = (low+high)/2;
	if(arr[mid] < key) {
		low = mid+1;
		bsearch_recursive(arr, low, high, key);
	} else if(arr[mid] > key) {
		high = mid-1;
		bsearch_recursive(arr, low, high, key);
	} else {
		return arr[mid];
	}
	return -1;
}

int BT::bsearch_iterative(int arr[], int size, int key) {
	int low = 0;
	int high = size-1;
	while(low <= high) {
		int mid = (low+high)/2;
		if(arr[mid] < key) {
			low = mid+1;
		} else if(arr[mid] > key) {
			high = mid-1;
		} else {
			return arr[mid];
		}
	}
	return -1;
}








