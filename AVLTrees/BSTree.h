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
		

		Node(int data) {
			this->value = data;
			left = nullptr;
			right = nullptr;
		
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

