/*******************************************************************************************************************************************************************
* Irvine Valley College CS 41: Data Structure
* Instructor: A.Lane
* Assignment#: Lab 7, Graph Matrix
* Name: Shengtao Li
* ID: 1015934
* Due Date: 11/02/2014
* Description: This is C++ program implement matrix representation of graph
**************************************************************************************************************************************************/


#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

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
void setEdge(string*& nodeName, vector< vector<int> >& graphMatrix, int nodeNumber)
{
	string temp;
	int edge;
	for (int i = 0; i < nodeNumber; i++)
	{
		for (int j = 0; j <(nodeNumber-i); j++)
		{
			
		  int t = j + i; // traverse the upper halve of the matrix
		  cout << "Would you want to set an edge between Node " << nodeName[i] << " and Node " << nodeName[t] << endl;
		  getline(cin, temp);
		  edge = atoi(temp.c_str());
		  graphMatrix[i][t] = edge;
		  graphMatrix[t][i] = edge;
		}
	}
} // end setEdge


// print the graph
void printGraphMatrix(string*& nodeName, vector< vector<int> >& graphMatrix, int nodeNumber)
{
	for (int i = 0; i <= nodeNumber; i++)
	{
		if (i == 0)
		{
			cout << " \t";
		}
		else
		{
			cout << nodeName[i - 1] << "\t";
		}

	}
	cout << endl;
	for (int i = 0; i < nodeNumber; i++)
	{
		cout << nodeName[i] << "\t";
		for (int j = 0; j < nodeNumber; j++)
		{
			cout << graphMatrix[i][j] << "\t";
		}
		cout << endl;
	}
} // end printGraphMatrix

int main()
{

	int nodeNumber = promptForNode();
	vector< vector<int> > graphMatrix(nodeNumber, vector<int>(nodeNumber, 0));
	string* nodeName = NULL;
	promptForNodeName(nodeName, nodeNumber);
	setEdge(nodeName, graphMatrix, nodeNumber);
	printGraphMatrix(nodeName, graphMatrix, nodeNumber);
	return 0;
} // end main

/***********************SAMPLE OUTPUT*************************************************
./GraphMatrix_v2
Please enter the # of node
3
Please enter the node name
A

Please enter the node name
B

Please enter the node name
C

Would you want to set an edge between Node A and Node A
1
Would you want to set an edge between Node A and Node B
0
Would you want to set an edge between Node A and Node C
1
Would you want to set an edge between Node B and Node B
0
Would you want to set an edge between Node B and Node C
1
Would you want to set an edge between Node C and Node C
1
        A       B       C
A       1       0       1
B       0       0       1
C       1       1       1



*************************************************END***********************************/
