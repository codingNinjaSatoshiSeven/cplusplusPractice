/*******************************************************************************************************************************************************************
* Irvine Valley College CS 41: Data Structure
* Instructor: A.Lane
* Assignment#: Assignment 2
* Name: Shengtao Li
* ID: 1015934
* Due Date: 9/21/2014
* Description: This C++ program implement a double linked list that keeps user's name and weight sorted in ascending order.
********************************************************************************************************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include "doubleLinkedList.h" // include the double linked list implementation


using namespace std;

// addNode method, to add the new node to the right location
void addNode(string a, int b, doubleLinkedList*& topName, doubleLinkedList*& topWeight, doubleLinkedList*& bottomName, doubleLinkedList*& bottomWeight)
{
	// pre-condition: a pointer to top of the node by Name, a pointer to bottom of the node by name.
	// a pointer to top of the node by weight, a pointer to bottom of the node by weight are established. 
	// Post-condition: a new node is created and inserted in the right location to maintain both name and weight ascending order

	if (topName == NULL &&  topWeight == NULL) // if the name top pointer  and weight top pointer point to null 
		//which means no node has been created
	{ // then create/initialized a new node
		doubleLinkedList* newNode = new doubleLinkedList();
		newNode->NodeNameData() = a;
		newNode->NodeWeightData() = b;
		newNode->NodeNameNext() = NULL;
		newNode->NodeWeightNext() = NULL;
		topName = newNode;
		topWeight = newNode;
		bottomName = newNode;
		bottomWeight = newNode;
	}// end if

	else {// if there are already other node existing 
		// then create/initialize a new node
		doubleLinkedList* newNode = new doubleLinkedList();
		doubleLinkedList* currentNode = topName;
		doubleLinkedList* previousNode = topName;
		doubleLinkedList* currentNodeWeight = topWeight;
		doubleLinkedList* previousNodeWeight = topWeight;
		newNode->NodeNameData() = a;
		newNode->NodeWeightData() = b;

		if (newNode->NodeNameData() < topName->NodeNameData())// if the node can be inserted in the way front by name order
		{ // then insert the node to the front by name order
			newNode->NodeNameNext() = topName;
			topName = newNode; // set the topName pointer to point to the new top node by name order
		} // end if

		else // if node will not be inserted in the way front by name order
		{
			if (newNode->NodeNameData() >= bottomName->NodeNameData())
			{// if can only be inserted way back by name order
				bottomName->NodeNameNext() = newNode;
				bottomName = newNode; // set the bottomName pointer point to the new bottom node by name order

			} // end if
			else
			{ // if the node will be inserted somewhere in the middle by name order
				while (newNode->NodeNameData() >= currentNode->NodeNameData()) // while the new node has name that's bigger than the current Node
				{
					previousNode = currentNode;
					currentNode = currentNode->NodeNameNext(); // move to next node by name order
				}// end while
				previousNode->NodeNameNext() = newNode;
				newNode->NodeNameNext() = currentNode; // inser the new node and maintain the ascending order of name
			} // end else
		} // end else

 //// Now try to maintain the weight order
		if (newNode->NodeWeightData()<topWeight->NodeWeightData())// if the node can be inserted in the way front by weight order
		{
			newNode->NodeWeightNext() = topWeight;
			topWeight = newNode; // set the topWeight pointer to point to the new top of the node by weight order
		} // end if

		else // if node cannot be inserted in the way front
		{
			if (newNode->NodeWeightData() >= bottomWeight->NodeWeightData())
			{ // if can only be inserted way back by weight order
				bottomWeight->NodeWeightNext() = newNode;
				bottomWeight = newNode; // set the bottomWeight pointer to point to the new bottom of the node by weight

			} // end if
			else
			{ // if the node will be inserted somewhere in the middle by weight orer
				while (newNode->NodeWeightData() >= currentNodeWeight->NodeWeightData()) // while the new node has name that's bigger than the current Node
				{
					previousNodeWeight = currentNodeWeight;
					currentNodeWeight = currentNodeWeight->NodeWeightNext(); // move to next node by weight order
				}// end while
				previousNodeWeight->NodeWeightNext() = newNode;
				newNode->NodeWeightNext() = currentNodeWeight; // insert the node to right location by weight order
			}// end else		

		} // end else

	}// end else

}// end addNode method

// printNode
void printNode(doubleLinkedList*& theTop, doubleLinkedList*& theBottom, bool sortByWeight)
{
	// Pre-condition: the top and bottom pointer of the Node is received, and sort by weight or by name option is selected
	// Post-condition: the node is printed one by one in ascending order with the user selected option. 
	doubleLinkedList* current = theTop; // start from top 
	if (sortByWeight == true)
	{ // if want to sort by weight
		cout << "Names & weights sorted(ascending) by Weight: ";
	}
	else
	{ // if want to sort by name
		cout << "Names & weights sorted(ascending) by Name: ";
	}
	while (current != theBottom)
	{ // as long as the not didn't hit the bottom last node
		cout << current->NodeNameData() << "-" << current->NodeWeightData() << ",";
		// print the current node content
		if (sortByWeight == true)
		{ // if user want to sort by weight, travel to next node by weight order
			current = current->NodeWeightNext();
		}
		else
		{// if user want to sort by name, travel to next node by name order
			current = current->NodeNameNext();
		}
		
	}// end while 
	cout << current->NodeNameData() << "-" << current->NodeWeightData() << endl;
	// print the last node by the appropriate order

} // end printNode

// main function
int main()
{
	// initialize the topName and topWeight pointer to null
	// initialize the bottomName and bottomWeight pointer to null
	doubleLinkedList* topName = NULL;
	doubleLinkedList* topWeight = NULL;
	doubleLinkedList* bottomName = NULL;
	doubleLinkedList* bottomWeight = NULL;
	


	for (int i = 0; i < 15; i++)
	{ // iterate 15 times
		string name;
		string weightStr;
		int weight;
		cout << "Please enter your name: ";
		getline(cin, name);
		cout << endl << "Please enter your weight: ";
		getline(cin, weightStr);
		weight = atoi(weightStr.c_str()); // convert the weight string to int
		cout << endl;
		addNode(name, weight, topName, topWeight, bottomName, bottomWeight); // add the new node to the right location
		printNode(topName, bottomName, false); // print the node ascending by name
		printNode(topWeight, bottomWeight, true); // print the node ascending by weight
	} // end for

  cout << "Please enter return key to exit...";
  string dummy;
  getline(cin, dummy);
  return 0;
}// end main

/***********************************************Sample Output**************************************************
Please enter your name: Jim

Please enter your weight: 150

Names & weights sorted(ascending) by Name: Jim-150
Names & weights sorted(ascending) by Weight: Jim-150
Please enter your name: Tom

Please enter your weight: 212

Names & weights sorted(ascending) by Name: Jim-150,Tom-212
Names & weights sorted(ascending) by Weight: Jim-150,Tom-212
Please enter your name: Michael

Please enter your weight: 174

Names & weights sorted(ascending) by Name: Jim-150,Michael-174,Tom-212
Names & weights sorted(ascending) by Weight: Jim-150,Michael-174,Tom-212
Please enter your name: Abe

Please enter your weight: 199

Names & weights sorted(ascending) by Name: Abe-199,Jim-150,Michael-174,Tom-212
Names & weights sorted(ascending) by Weight: Jim-150,Michael-174,Abe-199,Tom-212

Please enter your name: Richard

Please enter your weight: 200

Names & weights sorted(ascending) by Name: Abe-199,Jim-150,Michael-174,Richard-2
00,Tom-212
Names & weights sorted(ascending) by Weight: Jim-150,Michael-174,Abe-199,Richard
-200,Tom-212
Please enter your name: April

Please enter your weight: 117

Names & weights sorted(ascending) by Name: Abe-199,April-117,Jim-150,Michael-174
,Richard-200,Tom-212
Names & weights sorted(ascending) by Weight: April-117,Jim-150,Michael-174,Abe-1
99,Richard-200,Tom-212
Please enter your name: Claire

Please enter your weight: 124

Names & weights sorted(ascending) by Name: Abe-199,April-117,Claire-124,Jim-150,
Michael-174,Richard-200,Tom-212
Names & weights sorted(ascending) by Weight: April-117,Claire-124,Jim-150,Michae
l-174,Abe-199,Richard-200,Tom-212
Please enter your name: Bobby

Please enter your weight: 109

Names & weights sorted(ascending) by Name: Abe-199,April-117,Bobby-109,Claire-12
4,Jim-150,Michael-174,Richard-200,Tom-212
Names & weights sorted(ascending) by Weight: Bobby-109,April-117,Claire-124,Jim-
150,Michael-174,Abe-199,Richard-200,Tom-212
Please enter your name: Bob

Please enter your weight: 156

Names & weights sorted(ascending) by Name: Abe-199,April-117,Bob-156,Bobby-109,C
laire-124,Jim-150,Michael-174,Richard-200,Tom-212
Names & weights sorted(ascending) by Weight: Bobby-109,April-117,Claire-124,Jim-
150,Bob-156,Michael-174,Abe-199,Richard-200,Tom-212
Please enter your name: Kevin

Please enter your weight: 145

Names & weights sorted(ascending) by Name: Abe-199,April-117,Bob-156,Bobby-109,C
laire-124,Jim-150,Kevin-145,Michael-174,Richard-200,Tom-212
Names & weights sorted(ascending) by Weight: Bobby-109,April-117,Claire-124,Kevi
n-145,Jim-150,Bob-156,Michael-174,Abe-199,Richard-200,Tom-212
Please enter your name: Jason

Please enter your weight: 182

Names & weights sorted(ascending) by Name: Abe-199,April-117,Bob-156,Bobby-109,C
laire-124,Jason-182,Jim-150,Kevin-145,Michael-174,Richard-200,Tom-212
Names & weights sorted(ascending) by Weight: Bobby-109,April-117,Claire-124,Kevi
n-145,Jim-150,Bob-156,Michael-174,Jason-182,Abe-199,Richard-200,Tom-212
Please enter your name: Brian

Please enter your weight: 150

Names & weights sorted(ascending) by Name: Abe-199,April-117,Bob-156,Bobby-109,B
rian-150,Claire-124,Jason-182,Jim-150,Kevin-145,Michael-174,Richard-200,Tom-212
Names & weights sorted(ascending) by Weight: Bobby-109,April-117,Claire-124,Kevi
n-145,Jim-150,Brian-150,Bob-156,Michael-174,Jason-182,Abe-199,Richard-200,Tom-21
2
Please enter your name: Chris

Please enter your weight: 175

Names & weights sorted(ascending) by Name: Abe-199,April-117,Bob-156,Bobby-109,B
rian-150,Chris-175,Claire-124,Jason-182,Jim-150,Kevin-145,Michael-174,Richard-20
0,Tom-212
Names & weights sorted(ascending) by Weight: Bobby-109,April-117,Claire-124,Kevi
n-145,Jim-150,Brian-150,Bob-156,Michael-174,Chris-175,Jason-182,Abe-199,Richard-
200,Tom-212
Please enter your name: Steven

Please enter your weight: 164

Names & weights sorted(ascending) by Name: Abe-199,April-117,Bob-156,Bobby-109,B
rian-150,Chris-175,Claire-124,Jason-182,Jim-150,Kevin-145,Michael-174,Richard-20
0,Steven-164,Tom-212
Names & weights sorted(ascending) by Weight: Bobby-109,April-117,Claire-124,Kevi
n-145,Jim-150,Brian-150,Bob-156,Steven-164,Michael-174,Chris-175,Jason-182,Abe-1
99,Richard-200,Tom-212
Please enter your name: Annabelle

Please enter your weight: 99

Names & weights sorted(ascending) by Name: Abe-199,Annabelle-99,April-117,Bob-15
6,Bobby-109,Brian-150,Chris-175,Claire-124,Jason-182,Jim-150,Kevin-145,Michael-1
74,Richard-200,Steven-164,Tom-212
Names & weights sorted(ascending) by Weight: Annabelle-99,Bobby-109,April-117,Cl
aire-124,Kevin-145,Jim-150,Brian-150,Bob-156,Steven-164,Michael-174,Chris-175,Ja
son-182,Abe-199,Richard-200,Tom-212
Press any key to continue . . .

***********************************************************************************/
