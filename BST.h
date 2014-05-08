#include <iostream>

class BST {

public:
struct Node {
	Node* left;
	Node* right;
	Node* parent;
	int value;

	Node() : left(NULL), right(NULL), parent(NULL), value(-1) {}
};

public:
	BST();
	~BST();

	struct BST::Node* search(struct BST::Node*, int );
	struct BST::Node* create_node(int );
	struct BST::Node* insert_node(struct BST::Node* , int );
	void clear(struct BST::Node* );
	
	struct BST::Node* left_most_node(struct BST::Node* );
	
	bool is_bst(struct BST::Node* );
	bool is_balanced(struct BST::Node* );

	int tree_size(struct BST::Node*);
	void tree_clear(struct BST::Node* );
	
	struct BST::Node* min_node(struct BST::Node* );
	struct BST::Node* max_node(struct BST::Node* );

	int max_depth(struct BST::Node* );
	int min_depth(struct BST::Node* );

	void reverse_order_print(struct BST::Node* );

	void inorder(struct BST::Node* );
	void postorder(struct BST::Node* );
	void preorder(struct BST::Node* );

	void breadth_first_traversal(struct BST::Node* );
	int get_level(struct BST::Node*, int , int);
	void convert_to_array(struct BST::Node* , int* );
	void path_finder(struct BST::Node*, int arr[], int);
};