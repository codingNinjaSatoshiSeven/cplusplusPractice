/*******************************************************************************************************************************************************************
* Irvine Valley College CS 41: Data Structure
* Instructor: A.Lane
* Assignment#: Lab 7, Linked List Based Stack
* Name: Shengtao Li
* ID: 1015934
* Due Date: 10/26/2014
* Description: This is C++ program implement Stack based on linked list.
* The stack will have basic push, pop, and
* It will utilize the linked list based stack to parse and operate reverse polish notation
* It will implement Push, Pop, NodeCount (count the total node, or element in the stack)and Clear (remove all the elements in stack) method.
* the linked list (which the stack is based of), contains NodeData (get/set method to get/set the data of the node), NodeNext (get/set method to
* get/set the next node it's point to), and getCount (get the total node in linked list) method
********************************************************************************************************************************************************************/


#include<iostream>
#include<string>
using namespace std;


/*******************************************************Start of Implementation of  (Nodes)***************************************************************/
// Node (linked list) class declaration
class Node
{
public:
	Node(); // constructor
	~Node(); // destructor
	int& NodeData(); // get/set the node data
	Node*& NodeNext(); // get/set the next node
private:
	int data;
	Node* next;
};


// initialization of static int nodeCount to keep track of the totoal node count



// implementation of Node constructor

Node::Node()
{
	next = NULL;

}// end constructor


// implementation of Node destructor

Node::~Node()
{

	next = NULL;

}// end destructor


// implementation of NodeData

int& Node::NodeData()
{
	return data;

}//end NodeData


// implementation of NodeNext

Node*& Node::NodeNext()
{
	return next;

}// end NodeNext


// implementation of getCount



/*****************************END OF Linked List Node Implementation*************************************************************************************************/


/***************************************Beginning of stack implementation based on linked list(node)*****************************************************************/
// stackLL class declaration

class stackLL
{
public:
	stackLL(); //constructor
	~stackLL(); // destructor
	void Push(int c); // push
	int Pop(); // pop
	int NodeCount(); // total element counts in the stack
	void Clear(); // empty the stack
	bool isEmpty(); // check if stack is empty
private:
	Node* top; // pointer to the top of the stack
	Node* bottom; // pointer to the bottom of the stack
	int Count; // count of the node on the stack


};


// implementation of stackLL constructor

stackLL::stackLL()
{
	top = NULL;
	bottom = top; // at initialization, there's no element in stack, so both top and bottom point to NULL
	Count = 0;

}// end constructor


// implementation of stackLL destructor

stackLL::~stackLL()
{
	Node* temp;
	while (top != bottom)
	{// delete every element in the stack except the bottom one
		// move the top pointer to the bottom pointer
		temp = top;
		top = top->NodeNext();
		delete temp;
	}
	delete top; // remove the last element in the stack
	Count = 0;
}// end destructor


// implementation of stackLL Push method

void stackLL::Push(int c)
{
	Node* temp = new Node(); // create a new linked list node
	temp->NodeData() = c; // set stack data
	temp->NodeNext() = top; // set the node to link to the top of the node
	top = temp; // move the top pointer to point to the new stack top
	Count++;
}// end push


// implementation of stackLL Pop method

int stackLL::Pop()
{
	Node* temp = top;
	if (this->NodeCount()==0)
	{
		cout << "Cannot pop off element. The stack is empty"<<endl;
		return -1;
	}
	int value = temp->NodeData();
	top = top->NodeNext(); // move top pointer to point to the 2nd top node
	delete temp; // delet the top most element (node)
	Count--;
	return value; // return the top most element
}// end pop


// implementation of stackLL NodeCount method

int stackLL::NodeCount()
{
	return Count; // return the total number of element (node) in the stack
}// end NodeCount

// implementation of stackLL Clear method

void stackLL::Clear()
{
	Node* temp;
	while (top != bottom)
	{
		temp = top;
		top = top->NodeNext();
		delete temp; // delete every element until the bottom one. move top pointer towards bottom
	}
	delete top; // delete the last element in the stack
	Count = 0;

}// end Clear

// check if the linked list is empty

bool stackLL::isEmpty()
{

	return (this->NodeCount()==0);
} // end isEmpty

int main()
{
	stackLL* a = new stackLL() ;
	cout << "Does the stack contain element?" << endl;
	cout << ( a->isEmpty() ? "No" :"Yes")<< endl;

	cout << "Pushing 1 into the stack" << endl;
	a->Push(1);
	cout << "After pushing in 1 element Does the stack contain element?" << endl;
	cout << (a->isEmpty() ? "No" : "Yes") << endl;

	cout << "Pushing 2 into the stack" << endl;
	a->Push(2);
	cout << "Pushing 3 into the stack" << endl;
	a->Push(3);

	cout << "Popping off the last element of stack, shows " << a->Pop() << endl;
	cout << "Popping off the last element of stack, shows " << a->Pop() << endl;
	cout << "Popping off the last element of stack, shows " << a->Pop() << endl;
	cout << "Now stack is empty, try popping our more element will cause error" << endl;
	cout << "Popping off the last element of stack, shows " << a->Pop() << endl;

	cout << "Please enter return key to exit...";
	string dummy;
	getline(cin, dummy);
	return 0;
} // end main

/*************************************SAMPLE OUTPUT******************
Does the stack contain element?
No
Pushing 1 into the stack
After pushing in 1 element Does the stack contain element?
Yes
Pushing 2 into the stack
Pushing 3 into the stack
Popping off the last element of stack, shows 3
Popping off the last element of stack, shows 2
Popping off the last element of stack, shows 1
Now stack is empty, try popping our more element will cause error
Cannot pop off element. The stack is empty
Popping off the last element of stack, shows -1
Press any key to continue . . .


*************************************END*****************************/
