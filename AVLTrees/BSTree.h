#include <iostream>
#include <fstream>
#include "BSTree.cpp"/**/
//include nodes
using namespace std;

class BSTree {

public:

	struct Node {
		int value = 0;
		Node* left;
		Node* right;
		int height = 0;
		Node* twin;
		

		Node(int data) {
			this->value = data;
			left = nullptr;
			right = nullptr;
			this->height = 1;
			twin = nullptr;

		
		}
	};
	Node* rightRotate(Node* y) {

		Node* x = y->left;
		//make a temp node at the right of x
		Node* T2 = x->right;

		// set the right of x to y
		// set the left of y to T2
		x->right = y;
		y->left = T2;

		// Update heights to the max of the left and right subtrees
		y->height = max(getMaxDepth(y->left), getMaxDepth(y->right)) + 1;
		x->height = max(getMaxDepth(x->left), getMaxDepth(x->right)) + 1;

		// Return new root
		return x;
	};

	Node* leftRotate(Node* x) {
		Node* y = x->right;
		Node* T2 = y->left;

		y->left = x;
		x->right = T2;

		x->height = max(getMaxDepth(x->left), getMaxDepth(x->right)) + 1;
		y->height = max(getMaxDepth(y->left), getMaxDepth(y->right)) + 1;

		return y;
	};
	int BalanceNum(Node* node) {
		if (node->right != nullptr && node->left != nullptr)
		{
			Node* CurrRight = node->right;
			Node* CurrLeft = node->left;
			return CurrLeft->height - CurrRight->height;
		}
		else if (node->right == nullptr && node->left != nullptr)
		{
			return	1;
		}
		else if (node->right != nullptr && node->left == nullptr)
		{
			return -1;
		}
		else
		{
			return 0;
		}
	};
	Node* root;
	BSTree() {
		 root = nullptr;
	}

	int getMaxDepth(BSTree::Node* root);

	void insertNode(BSTree::Node*& root, int data);

	//void insertNode(BSTree::Node* root, int value);

	bool isTreeEmpty(Node* root);

	BSTree::Node* deleteNode(int value, Node* root);

	Node* searchTree(BSTree::Node* node, int key);

	void printTree( const std::string& prefix,const BSTree::Node* node, bool isLeft);

	BSTree::Node* inOrder( Node* root);

	void callprint(BSTree tree);




};

