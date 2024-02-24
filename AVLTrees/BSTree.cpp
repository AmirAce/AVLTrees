#pragma once
#include "BSTree.h"
#include "ErrorCheck.h"
#include <iostream>
#include <stack>
#include <queue>

#include <fstream>
#include <string>


using namespace std;



	int height = 0;
	int operation = 0;
	

     // BSTree tree;
			
	int BSTree::getMaxDepth(BSTree::Node* root) {
		int Depth = 0;
		if (root == nullptr) {
			return 0;
		}
		else {
			BSTree::Node* curr = root;
			while (curr != nullptr )
			{
				if (curr->left != nullptr) {
					Depth++;
					operation++;
					curr = curr->left;
				}
				else if (curr->right != nullptr) {
					Depth++;
					operation++;
						curr = curr->right;
				}
				else if (curr->left == nullptr || curr->right == nullptr)
				{
					break;
				}
				
				
			}
			return Depth;
		}
	
	
	}

	void BSTree::insertNode(BSTree::Node*& root,int data) {
		//if root is empty, create a new node and set it as the root
		if (root == nullptr)
		{
			cout<< "Tree has no root" << endl<< "attempting to create tree root"<<endl;

			
			root = new BSTree::Node(data);
			cout<<"root created"<<endl;
			// return;
		}
		else {
			BSTree::Node* curr = root;
			while (curr != nullptr)
			{
				if (curr->value > data)
				{
					
					if (curr->right == nullptr) {
						
					curr->right = new BSTree::Node(data);
					operation++;
						cout<<"inserted node"<<endl;

						return;
					}
					else {
						curr = curr->right;
						operation++;
					}
				
					
				}
				if (curr->value < data)
				{
					if (curr->left == nullptr) {
						curr->left = new BSTree::Node(data);
						operation++;


						cout<<"inserted node"<<endl;

						return;
					}
					
					
						curr = curr->left;
					
						operation++;
					

				}
				else if(data == curr->value) {
					if(curr->right == nullptr)
					{
						curr->left = new BSTree::Node(data);

					}
					else
					{
						curr = curr->left;
					}
    }
				
			}
			
		}
}

bool BSTree::isTreeEmpty(Node* root)
{
	//check if the root node is empty, if so tell user tree is empty and return true
	if (root == nullptr)
	{
		cout << "Tree is empty" << endl;
		return true;
	}
	//if the root node is not empty, tell user tree is not empty and return false
	else
	{
		cout << "Tree is not empty" << endl;
		return false;
	}
	
}

BSTree::Node* BSTree::deleteNode(int value, Node* root)
{
	return nullptr;
}

void BSTree::printTree( const std::string& prefix,const BSTree::Node* node, bool isLeft) {

			// BSTree::Node* node = root;
			/*bool isLeft = false;
			string prefix = "---|";
			string postfix = "--->";*/
			// cout<<node->value<<endl;
			if( node != nullptr )
			{
				cout << prefix;
				// cout<<"AAAAAA"<<endl;
				cout << (isLeft ? "|----" : "L____" );

				// print the value of the node
				int val = node->value;				
				cout << val<< std::endl;

				// enter the next tree level - left and right branch
				printTree( prefix + (isLeft ? "|   " : "    "), node->left, true);
				printTree( prefix + (isLeft ? "|   " : "    "), node->right, false);
			}
		}

		 void  BSTree::callprint(BSTree mytree) 
		{
		
			mytree.printTree("", mytree.root, false);    
		}



// pass the root node of your binary tree
		



// BSTree::Node* BSTree::deleteNode(int value, Node* node) {
// 	Node* target = searchTree(node, value);
// 	if (target == nullptr) {
// 		cout << value << " is not in the tree" << endl;
// 		return node;
// 	}
// 	else {
// 		cout << target->value << " is deleted!" << endl;
// 		// Implement the actual deletion logic here
// 		// You need to adjust the tree structure
// 		// (e.g., reconnect parent to child or find the inorder successor)
// 		// and then delete the target node.
// 		// Return the modified tree.
// 		// ...
// 		return node;
// 	}
// }

BSTree::Node* BSTree::searchTree(Node* node, int key)
{
	
	if (node == nullptr)
	{
		cout << key + "is not in the tree" << endl;
		return nullptr;
	}
	BSTree::Node* curr = node;
	while (curr != nullptr)
	{
		if (curr->value > key)
		{

	
				curr = curr->right;
		


		}
		if (curr->value < key)
		{
	
			curr = curr->left;
		}
		else if (curr->value == key) {
			//cout << "value is found!" << endl << "number of operations:" + ' ' + operation << endl;
			return curr;
		}
	}


	
	return nullptr;
}

//add main
int main()
	{
		std::string name;
		std::cout << "Enter file name: ";
		// std::cin >> name;
		// std::string filename = "C:\\Users\\aamir_3h2utvj\\Documents\\SoftDev\\CIS 3501\\Project 1\\RequiredTests\\" + name + ".txt";
		// std::ifstream file(filename);
		ifstream file;
		file.open("C:\\Users\\aamir_3h2utvj\\Documents\\SoftDev\\CIS 3501\\Project 1\\RequiredTests\\80-20inserts.txt");
		if (!file.is_open()) {
			std::cout << "File cannot be opened. Please try again.\n";
			return 0;
		}
		if(file.peek() == NULL)
		{
			cout<<"file is empty";
			return 1;
		}
	
		ErrorCheck error_check;
	
		/*
		if (!error_check.isTypeValid(name)) {
			cout<<"data type is not valid!";
		return 1;
		}
		*/
		
		string line;
		string num;
		
		
		BSTree mytree;
		// mytree.callprint(mytree);
		int iterations = 0;
		while(file >> line && !file.eof())
		{
			cout << "Read: " << line << endl;
			// if (file.eof()) {
			// 	cout << "End of file reached." << endl;
			// } 
		
			
			if(all_of(line.begin(), line.end(), isdigit))
			{
				mytree.insertNode(mytree.root, std::stoi(line));
				// iterations++;
			
				// continue;
			}

			
			
			if(line == "S")
			{
				if(mytree.root != nullptr)
					
				{
					mytree.searchTree(mytree.root,std::stoi(num));	
				}
				else
				{
					cout<<"Cant search a empty tree!"<<endl;
				}
				// continue;

					
			}
			 if(line == "D")
			{
				if(mytree.root != nullptr)
				{
					mytree.deleteNode( std::stoi(num), mytree.root);
				}
				else
				{
					cout<<"Cant search a empty tree!";
					
				}
				// continue;
			}
			 if(line == "I")
			{
					
				mytree.insertNode(mytree.root, std::stoi(num));
				// return 0;
				// tree.searchTree();
			}
		
			// tree.callprintTree(tree.root);/*/*/
			// mytree.callprint(mytree);
			// iterations++;
			

		}
		mytree.callprint(mytree);
		return 0;
	}