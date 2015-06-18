/*******************************************************************************************************************************************************************
* Irvine Valley College CS 41: Data Structure
* Instructor: A.Lane
* Assignment#: Lab 5
* Name: Shengtao Li
* ID: 1015934
* Due Date: 10/19/2014
* Description: This C++ program implement a Build a binary search tree,

********************************************************************************************************************************************************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

// class treeNode
class treeNode
{
public:
	// each node will
	int weight; // hold weight as int
	treeNode *left, *right;// have left and right pointer

	// constructor
	treeNode()
	{
		left = right = NULL;
	} // end constructor

	// constructor with parameter
	treeNode(int w, treeNode *l = NULL, treeNode *r = NULL)
	{
		this->weight = w; // initialize weight
		left = l; // initialize the left sub tree
		right = r; // initialize the right sub tree
	} // end constructor with parameter
};
// end class treeNode

// bianrySearchTree class
class binarySearchTree
{

public:
	// root pointer
	treeNode *root;

	// constructor
	binarySearchTree()
	{
		// set root to NULL
		root = NULL;
	} // end constructor

	// addNode
	bool Add ( int w)
	{
		treeNode *newNode = new treeNode( w);			// our  new node
		if (root == NULL)									// check for an empty root
		{ // if root is null
			root = newNode; // point root to the new generated node
			return true;
		}
		treeNode *temp = root;							// create a temp node to traverse the list
		while (true)
		{
			if (w < temp->weight)
			{						// check to see if we will traverse to the left
				if (temp->left == NULL)					// check to see if we have found newNode's position
				{ // if can be insert to left subtree
					temp->left = newNode;
					break;
				}
				else									// move to subtree
					temp = temp->left;
			} // end if
			else if (w > temp->weight)
			{				// check to see if we will traverse to the right
				if (temp->right == NULL)					// check to see if we have found newNode's position
				{
					temp->right = newNode;
					break;
				}
				else									// move to subtree
					temp = temp->right;
			}// end else if
			else if (w == temp->weight)
			{
				return false; // no dupes
			}				// For this implementation, we will not allow duplicates

		} // end while
		return true;
	} // end addNode



	// inorderTraversal 
	void inorderTraversal(treeNode *temp)
	{
		if (temp != 0)
		{
			inorderTraversal(temp->left);			// traverse left subtree
			cout << temp->weight << " ";				// evaluate (print) current node
			inorderTraversal(temp->right);			// traverse right subtree
		}
	} // end inorderTraversal

	// print
	// prints all the node in inorder traversal
	void Print(treeNode* temp)
	{
		inorderTraversal(temp);
	}

}; // end class binarySearchTree

int main()
{
	binarySearchTree* bst = new binarySearchTree();
	bst->Add(5);
	bst->Add(1);
	bst->Add(2);
	bst->Add(8);
	bst->Add(10);
	cout << "Printing tree in in order traversal" << endl;
	bst->Print(bst->root);

	cout << endl;
	cout << "Please enter return key to exit...";
	string dummy;
	getline(cin, dummy);
	return 0;
} // end main

/*****************SAMPLE OUTPUT
Printing tree in in order traversal
1 2 5 8 10
Please enter return key to exit...
**************************END*/