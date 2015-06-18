/*******************************************************************************************************************************************************************
 * Irvine Valley College CS 41: Data Structure
 * Instructor: A.Lane
 * Assignment#: Lab 8
 * Name: Shengtao Li
 * ID: 1015934
 * Due Date: 11/9/2014
 * Description: This C++ program implement Linked list based Graph
 ********************************************************************************************************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;


// node class
class Node
{
public:
	string label;
	Node* next;
	Node()
	{
		label="";
		next=NULL;
	}


};

// prompt for # of node
int promptForNode()
{
	string temp;
	cout << "Please enter the # of node" << endl;
	getline(cin, temp);
	int nodeNumber = atoi(temp.c_str());
	return nodeNumber;
}// end promptForNode


// prompt for Each nodes's name
void promptForNodeName(string*& nodeName, int nodeNumber)
{
	nodeName = new string[nodeNumber];
	for (int i = 0; i < nodeNumber; i++)
	{
		cout << "Please enter the node name" << endl;
		getline(cin, nodeName[i]);
		cout << endl;


	}
} // end promptForNodeName


// prompt to set each edge
void setEdge(string*& nodeName, Node**& nodeArray, int nodeNumber)
{
	string temp;
	int edge;
	for (int i = 0; i < nodeNumber; i++)
	{
		for (int j = 0; j <(nodeNumber-i); j++)
		{
			
		  int t = j + i; // traverse the upper halve of the matrix
		  cout << "Would you want to set an edge between Node " << nodeName[i] << " and Node " << nodeName[t] << " 1 for yes, and 0 for no"<<endl;
		  getline(cin, temp);
		  edge = atoi(temp.c_str());
		  if (edge >=1)
		    { // if There should be an edge
			if (j==0)
			{ // if the array of the link hasn't been initialized yet
			  // then initialize the first node
				Node* start=new Node();
				start->label=nodeName[i]+nodeName[t];
			     
				nodeArray[i]=start;
			} // end if

			else { // add the edge to the back of the linked list
				Node* newEdge=new Node();
				newEdge->label=nodeName[i]+nodeName[t];
				Node* temp=nodeArray[i];
				while (temp!=NULL)
				  { // go to the last node
					if (temp->next==NULL || temp==NULL)
						break; 
					temp=temp->next;
				}
				temp->next=newEdge;
				
			} // end else
		  } // end if
		
		} // end inner for
	} // end outer for
} // end setEdge

void printGraphList(Node**& nodeArray, int nodeNumber)
{
  cout<<"The Graph is displayed below"<<endl;
	for (int i=0; i<nodeNumber; i++)
	{
		Node* temp=nodeArray[i];
		while (temp!= NULL)
		{
			if (temp==NULL)
				break;
			
			cout<<temp->label<<"\t";
			temp=temp->next;
			
		}
		cout<<endl;

	} // end for

} // end printGraphList

int main()
{
	int nodeNumber = promptForNode();
	string* nodeName = NULL;
	Node** nodeArray = new Node*[nodeNumber];
	for (int i=0; i<nodeNumber; i++)
	  { // initialize each array of node pointer to NULL
		nodeArray[i]=NULL;
	  }
	promptForNodeName(nodeName, nodeNumber);
	setEdge(nodeName, nodeArray, nodeNumber);
	
	printGraphList(nodeArray,nodeNumber);
} // end main


/****************************Sample Output***********************************
Please enter the # of node
3
Please enter the node name
A

Please enter the node name
B

Please enter the node name
C

Would you want to set an edge between Node A and Node A 1 for yes, and 0 for no
1
Would you want to set an edge between Node A and Node B 1 for yes, and 0 for no
1
Would you want to set an edge between Node A and Node C 1 for yes, and 0 for no
1
Would you want to set an edge between Node B and Node B 1 for yes, and 0 for no
1
Would you want to set an edge between Node B and Node C 1 for yes, and 0 for no
0
Would you want to set an edge between Node C and Node C 1 for yes, and 0 for no
1
The Graph is displayed below
AA      AB      AC
BB
CC
***********************END******************************************/
