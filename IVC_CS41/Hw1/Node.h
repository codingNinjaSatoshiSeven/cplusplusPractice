/*******************************************************************************************************************************************************************
 * Irvine Valley College CS 41: Data Structure
 * Instructor: A.Lane
 * Assignment#: Assignment 1 "Node.h"
 * Name: Shengtao Li
 * ID: 1015934
 * Due Date: 8/24/2014
 * Description: This is C++ program implement Stack based on linked list.  
 * The stack will have basic push, pop, and 
 * It will utilize the linked list based stack to parse and operate reverse polish notation
 * It will implement Push, Pop, NodeCount (count the total node, or element in the stack)and Clear (remove all the elements in stack) method.
 * the linked list (which the stack is based of), contains NodeData (get/set method to get/set the data of the node), NodeNext (get/set method to 
 * get/set the next node it's point to), and getCount (get the total node in linked list) method
 ********************************************************************************************************************************************************************/


#include<iostream>
using namespace std;


/*******************************************************Start of Implementation of Linked List (Nodes)***************************************************************/
// Node (linked list) class declaration
template<typename T>
class Node
{
public:
  Node(); // constructor
  ~Node(); // destructor
  T& NodeData(); // get/set the node data
  Node*& NodeNext(); // get/set the next node
  int getCount()const; // get the node count
private:
  T data;
  Node* next;
  static int nodeCount;
};


// initialization of static int nodeCount to keep track of the totoal node count
template<typename T>
int Node<T>::nodeCount=0;


// implementation of Node constructor
template<typename T>
Node<T>::Node()
{
  next=NULL;
  nodeCount++;
}// end constructor


// implementation of Node destructor
template<typename T>
Node<T>::~Node()
{
  
  next=NULL;
  nodeCount--;
}// end destructor


// implementation of NodeData
template<typename T>
T& Node<T>::NodeData()
{
  return data;

}//end NodeData


// implementation of NodeNext
template<typename T>
Node<T>*& Node<T>::NodeNext()
{
  return next;

}// end NodeNext


// implementation of getCount
template<typename T>
int Node<T>::getCount()const
{
  return nodeCount;

}// end getCount

/*****************************END OF Linked List Node Implementation*************************************************************************************************/


/***************************************Beginning of stack implementation based on linked list(node)*****************************************************************/
// stackLL class declaration
template<typename T>
class stackLL
{
 public:
  stackLL(); //constructor
  ~stackLL(); // destructor
  void Push(T c); // push
  T Pop(); // pop
  int NodeCount(); // total element counts in the stack
  void Clear(); // empty the stack
 private:
  Node<T>* top; // pointer to the top of the stack
  Node<T>* bottom; // pointer to the bottom of the stack

};


// implementation of stackLL constructor
template<typename T>
stackLL<T>::stackLL()
{
  top=NULL;
  bottom=top; // at initialization, there's no element in stack, so both top and bottom point to NULL
  
}// end constructor


// implementation of stackLL destructor
template<typename T>
stackLL<T>::~stackLL()
{
  Node<T>* temp;
  while (top!=bottom)
    {// delete every element in the stack except the bottom one
      // move the top pointer to the bottom pointer
      temp=top;
      top=top->NodeNext();
      delete temp; 
    }
  delete top; // remove the last element in the stack
}// end destructor


// implementation of stackLL Push method
template<typename T>
void stackLL<T>::Push(T c)
{
  Node<T>* temp=new Node<T>(); // create a new linked list node
  temp->NodeData()=c; // set stack data
  temp->NodeNext()=top; // set the node to link to the top of the node
  top=temp; // move the top pointer to point to the new stack top
}// end push


// implementation of stackLL Pop method
template<typename T>
T stackLL<T>::Pop()
{
  Node<T>* temp=top;
  T value=temp->NodeData();
  top=top->NodeNext(); // move top pointer to point to the 2nd top node
  delete temp; // delet the top most element (node)
  return value; // return the top most element
}// end pop


// implementation of stackLL NodeCount method
template<typename T>
int stackLL<T>::NodeCount()
{
  return top->getCount(); // return the total number of element (node) in the stack
}// end NodeCount

// implementation of stackLL Clear method
template<typename T>
void stackLL<T>::Clear()
{
  Node<T>* temp;
  while (top!=bottom)
    {
      temp=top;
      top=top->NodeNext();
      delete temp; // delete every element until the bottom one. move top pointer towards bottom
    }
  delete top; // delete the last element in the stack

}// end Clear
