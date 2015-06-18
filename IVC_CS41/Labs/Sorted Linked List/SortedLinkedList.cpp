/*******************************************************************************************************************************************************************
* Irvine Valley College CS 41: Data Structure
* Instructor: A.Lane
* Assignment#: Lab 4
* Name: Shengtao Li
* ID: 1015934
* Due Date: 10/19/2014
* Description: This C++ program implement a sorted linked list
********************************************************************************************************************************************************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

// class treeNode
class node
{
public:
	// each node will

	int weight; // hold weight as int
	node *next;// have left and right pointer

	// constructor
	node()
	{
		next = NULL;
	} // end constructor

	// constructor with parameter
	node(int w, node *n = NULL)
	{

		this->weight = w; // initialize weight
		next = n;
	} // end constructor with parameter
};
// end class treeNode

class SortedLinkedList
{
public:
	node* top;
	SortedLinkedList()
	{
		top = NULL;
	} // end constructor

	// add node
	bool addNode(int w)
	{
		node *newNode = new node(w);			// our  new node
		if (top == NULL)									// check for an empty root
		{ // if top is null
			top = newNode; // point top to the new generated node
			return true;
		} // end if
		else
		{
			node* temp = top;
			node* previous = top;

			if (w < top->weight)
			{ // the case in which new node is to  be added to front
				newNode->next = top;
				top = newNode;
			} // end if
			else
			{ // else if the node is not to be inserted in front
				while (temp != NULL)
				{ // traverse the linked list
					// keep track of previous node, and next node
					previous = temp;
					temp = temp->next;
					if (temp == NULL)
					{ // if search for the entire linked list, and can only be inserted at end, then exit loop
						break;
					}
					if (w < temp->weight && temp!=NULL)
					{ // insert in middle
						newNode->next = temp;
						previous->next = newNode;
						break;
					}

				} // end while

				if (temp == NULL)
				{ // traverse the entire list and can only insert to end
					previous->next = newNode;
				} // end if
			} // end else
		}

	} // end addNode

	// print the sorted linked list
	void Print()
	{
		node* temp = top;
		while (temp != NULL)
		{
			cout << temp->weight << "\t";
			temp = temp->next;
		} // end while
	} // end Print
}; // end class LinkedList

void promptToAddNode(SortedLinkedList*& ll)
{
	int toAdd;
	string toAddStr;
	do
	{// keep prompt until user enter -1, this will run for at least once. 
		cout << "Please enter the number" << endl;
		getline(cin, toAddStr);
		toAdd = atoi(toAddStr.c_str());
		if (toAdd == -1)
		{// if user entered -1, exit loop
			break;
		}
		// else, add new node and print
		ll->addNode(toAdd);
		ll->Print();
		cout << endl;
	} while (toAdd != -1);
	cout << "ending Program" << endl;

} // end promptToAddNode

int main()
{
	SortedLinkedList* ll = new SortedLinkedList();
	// prompt for linked list input, until user entered -1
	promptToAddNode(ll);


	cout << "Please enter return key to exit...";
	string dummy;
	getline(cin, dummy);
	return 0;
} // end main

/*******************SAMPLE OUTPUT******************
Please enter the number
10
10
Please enter the number
15
10      15
Please enter the number
5
5       10      15
Please enter the number
2
2       5       10      15
Please enter the number
4
2       4       5       10      15
Please enter the number
16
2       4       5       10      15      16
Please enter the number
-1
ending Program
Please enter return key to exit...
******************END******************************/