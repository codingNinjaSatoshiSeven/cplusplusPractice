/*******************************************************************************************************************************************************************
* Irvine Valley College CS 41: Data Structure
* Instructor: A.Lane
* Assignment#: Lab 4
* Name: Shengtao Li
* ID: 1015934
* Due Date: 10/19/2014
* Description: This C++ program implement a linked list
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
	node( int w, node *n=NULL)
	{
		
		this->weight = w; // initialize weight
		next = n;
	} // end constructor with parameter
};
// end class treeNode

class LinkedList
{
public:
	node* top;
	LinkedList()
	{
		top = NULL;
	} // end constructor
	
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
			newNode->next = top;
			top = newNode;
		}

	} // end addNode

	// print the linked list
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

void promptToAddNode(LinkedList*& ll)
{
	int toAdd;
	string toAddStr;
	do
	{ // keep prompt until user enter -1, this will run for at least once. 
		cout << "Please enter the number" << endl;
		getline(cin, toAddStr);
		toAdd = atoi(toAddStr.c_str());
		if (toAdd == -1)
		{ // if user entered -1, exit loop
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
	LinkedList* ll = new LinkedList();
	// prompt for linked list input, until user entered -1
	promptToAddNode(ll);


	cout << "Please enter return key to exit...";
	string dummy;
	getline(cin, dummy);
	return 0;
} // end main

/*******************SAMPLE OUTPUT***************
Please enter the number
10
10
Please enter the number
15
15      10
Please enter the number
5
5       15      10
Please enter the number
2
2       5       15      10
Please enter the number
4
4       2       5       15      10
Please enter the number
-1
ending Program
Please enter return key to exit...

***************************END************/
