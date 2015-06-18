// This header file implement double linked list

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

// double linked list class
class doubleLinkedList
{
public:
  doubleLinkedList(); //constructor
  ~doubleLinkedList(); //destructor
  string& NodeNameData(); // get/set method to get node's name data
  int& NodeWeightData();// get/set method to get node's weight data
  doubleLinkedList*& NodeNameNext(); // get/set method to get node's next, by name
  doubleLinkedList*& NodeWeightNext();// get/set method to get node's next, by weight
  int getCount() const;  // get the node count
private:
  string nameData;
  int weightData;
  doubleLinkedList* nameNext; // next node, by name
  doubleLinkedList* weightNext; // next node, by weight
  static int nodeCount; // number of node
}; // end class

int doubleLinkedList::nodeCount=0; // initialize # of node to 0

//constructor
doubleLinkedList::doubleLinkedList()
{
  nameNext=NULL;
  weightNext=NULL;
  nodeCount++; // node will increment by 1
} // end constructor

// destructor
doubleLinkedList::~doubleLinkedList()
{
  nameNext=NULL;
  weightNext=NULL;
  nodeCount--; // node will decrement by 1

}// end destructor

// get/set NodeNameData
string& doubleLinkedList::NodeNameData()
{
  return nameData;
} // end NodeNameData

// get/set NodeWeightData
int& doubleLinkedList::NodeWeightData()
{
  return weightData;
}// end NodeWeightData

// get/set NodeNameNext
doubleLinkedList*& doubleLinkedList::NodeNameNext()
{
  return nameNext;
}// end NodeNameNext

//get/set NodeWeightNext
doubleLinkedList*& doubleLinkedList::NodeWeightNext()
{
  return weightNext;
}// end NodeNameNext

// getCount
int doubleLinkedList::getCount() const
{
  return nodeCount;
}// end getCount


#endif