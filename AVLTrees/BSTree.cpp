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

	void BSTree::insertNode(BSTree::Node*& root, int data) {
		//if root is empty, create a new node and set it as the root
		if (root == nullptr)
		{
			cout << "Tree has no root for inserting!" << endl << "attempting to create tree root" << endl;


			root = new BSTree::Node(data);
			cout << "root created" << endl;



		}
		else {
			BSTree::Node* curr = root;
			while (curr != nullptr)
			{
				if (curr->value > data)
				{
					if (curr->left == nullptr) {

						curr->left = new BSTree::Node(data);
						operation++;
						cout << "inserted node" << endl;






						break;
					}
					curr = curr->left;
					operation++;
				}
					 
					
					

				if (curr->value < data)
				{
					if (curr->right == nullptr) {
						curr->right = new BSTree::Node(data);
						operation++;


						cout << "inserted node" << endl;

						break;
					}
					curr = curr->right;


					
				


					operation++;

				}

				// if (data == curr->value) {
				// 	if (curr->twin == nullptr)
				// 	{
				// 		curr->twin = new BSTree::Node(data);
				//
				// 	}
					curr->height++;

					int balanceFactor = BalanceNum(curr);

					if (balanceFactor > 1) {
						if (data < curr->left->value && curr->left != nullptr) {
							curr = rightRotate(curr);
						}
						else if (data > curr->left->value && curr->left != nullptr) {
							curr->left = leftRotate(curr->left );
							curr = rightRotate(curr);
						}
					}
					if (balanceFactor < -1) {
						if (data > curr->right->value && curr->right != nullptr) {
							curr = leftRotate(curr);
						}
						else if (data < curr->right->value &&curr->right != nullptr) {
							curr->right = rightRotate(curr->right);
							curr = leftRotate(curr);
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

			
			if( node != nullptr )
			{
				cout << prefix;
				cout << (isLeft ? "|----" : "L____" );

				int val = node->value;				
				cout << val<< std::endl;

				printTree( prefix + (isLeft ? "|   " : "    "), node->left, true);
				printTree( prefix + (isLeft ? "|   " : "    "), node->right, false);
			}
			
		}

		 void  BSTree::callprint(BSTree mytree) 
		{
		
			mytree.printTree("", mytree.root, false);    
		}




BSTree::Node* BSTree::searchTree(Node* node, int key)
{
	
	if (node == nullptr)
	{
		cout << key + "is not in the tree" << endl;
		return nullptr;
	}
	BSTree::Node* curr = node;
	while (curr != nullptr || curr != NULL)
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
		 std::cin >> name;
		ifstream file;

		file.open(name);
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
	

		
		string line;
		// string num;
		string num;
		
		BSTree mytree;
		int iterations = 0;
		int snum = 0;
		int searches = 0;
		int inserts = 0;
		int inum = 0;
		vector<int> insertlist;
		vector<int> searchlist;
		while(file>>line && !file.eof())
		{
			if(line.empty())
			{
				cout<<"line is empty!!";
				continue;
			}
			if(line[0] == 'S')
			{
				file >> num;
				searches++;
				searchlist.emplace_back(snum);
				continue;
			}
			if(line[0] == 'I')
			{
				inserts++;
				file>>inum;
				insertlist.emplace_back(inum);
				continue;
			}
			 
			 {
			 	insertlist.emplace_back(stoi(line));

			 }
				
			
		}
		
		if(!insertlist.empty())
		{
			for (const auto& value : insertlist) {
				mytree.insertNode(mytree.root, value);
			}
		}
		
		if(!searchlist.empty())
		{
			for (const auto& value : searchlist) {
				if (!mytree.searchTree(mytree.root, value)) {
					cout << "Value " << value << " not found in tree." << endl;
				}
			}
		
		}
	
		
		mytree.callprint(mytree);
		
	}