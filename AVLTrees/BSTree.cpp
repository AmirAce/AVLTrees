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
			cout<< "Tree has no root for inserting!" << endl<< "attempting to create tree root"<<endl;

			
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
		// std::string name;
		// std::cout << "Enter file name: ";
		
		ifstream file;
		file.open("C:\\Users\\aamir_3h2utvj\\Documents\\SoftDev\\CIS 3501\\Project 1\\RequiredTests\\80search50.txt");
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
		
		if(searchlist.size() == insertlist.size() && searchlist.size() > 0)
		{
			cout<<"number of searches and inserts are the same!"<<endl;
			return 0;
		}

		// int itr = 0;
		// while(itr < insertlist.size() && itr < searchlist.size())
		// {
			
			// cout << "Read: " << line << endl;
			// if (file.eof()) {
				// cout << "End of file reached." << endl;
			// } 
		
			
			// if(line == "S")
			// {
				// if(mytree.root != nullptr)
					
				// {
					// file>>num;
					// mytree.searchTree(mytree.root,std::stoi(num));	
				// }
				// else
				// {
					// cout<<"Cant search a empty tree!"<<endl;
				// }
				// exit;
				// continue;

					
			// }
			// else if(line == "D")
			// {
				// if(mytree.root != nullptr)
				// {
					// mytree.deleteNode( std::stoi(num), mytree.root);
				// }
				// else
				// {
					// cout<<"Cant search a empty tree!";
					
				// }
				// exit;			}
		// 	 else if(line == "I")
		// 	{
		// 	 	cout<<"line starts with I, attempting to insert";
		// 	 	num = line.substr(0,line.length());
		// 		file>>num;	
		// 	 	
		// 		mytree.insertNode(mytree.root, std::stoi(num));
		// 		
		// 		// tree.searchTree();
		// 	 	exit;
		// 	}
		//
		// 	else
		// 	{
		// 		mytree.insertNode(mytree.root, std::stoi(line));
		// 		exit;
		// 	}
		// 	itr++
		//
		// }
		if(insertlist.size() > 0)
		{
			for (int itr = 0; itr < insertlist.size(); itr++)
			{
				mytree.insertNode(mytree.root ,insertlist.at(itr));
				// cout<<"A";
			}
	
		}
		
		if(searchlist.size() > 0)
		{
			for (int itr : searchlist)
			{
				mytree.searchTree(mytree.root, itr);
				// cout<<"A";
			}
		}

		
		
		mytree.callprint(mytree);
		
	}