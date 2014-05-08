#include <deque>
#include <iostream>
#include <vector>

class BT {

public:
	struct Node {
		Node* left;
		Node* right;
		Node* parent;
		char key;

		Node() : right(NULL), left(NULL), parent(NULL), key('0') {}
	};

public:
	BT();
	~BT();

	struct BT::Node* insert_node(BT::Node*, char);
	struct BT::Node* search_node(BT::Node*, char);
	struct BT::Node* create_node(char);
	void clear_node(BT::Node*);

	bool is_bt(BT::Node* );
	bool is_balanced(BT::Node* );

	int min_depth(BT::Node* );
	int max_depth(BT::Node* );

	struct BT::Node* min_node(BT::Node* );
	struct BT::Node* max_node(BT::Node* );
	struct BT::Node* maxx_node(BT::Node* );

	struct BT::Node* left_node(BT::Node* );
	struct BT::Node* left_node_tree(BT::Node* );

	int bt_size(BT::Node* );

	void inorder(BT::Node* );
	void inorder_parent(BT::Node* );
	void preorder(BT::Node* );
	void postorder(BT::Node* );

	void mirror(BT::Node*);

	void path_finder(BT::Node*, int[], int);
	void breadth_first_traversal(BT::Node*);
	
	struct BT::Node* add_to_bst(std::vector<char>, int, int);
	struct BT::Node* create_minimal_bst(std::vector<char>, int);

	struct BT::Node* predeccesor_inorder(BT::Node* );
	struct BT::Node* succesor_inorder(BT::Node* );

	void delete_key(BT::Node* , char);

	int bsearch_recursive(int[], int, int, int);
	int bsearch_iterative(int[], int, int);
};