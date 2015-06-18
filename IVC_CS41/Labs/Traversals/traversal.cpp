/************************************************************************************
* Description: This C++ program will implement 3 different traversal method recursively 
**************************************************************************************************************************** */
#include<iostream>
#include<string>
using namespace std;

class arrayBasedBinaryTree {

private:
	int Count; // total element in the binary tree
	int arraySize; // size of the array

public:
	int* binaryTreeData; // pointer to the array based binary tree
	// contructor
	arrayBasedBinaryTree(int size){
		binaryTreeData = new int[size];
		Count = 0;
		arraySize = size;

	} // end constructor

	//destructor
	~arrayBasedBinaryTree(){

		delete[] binaryTreeData;
	}// end destructor

	// get # of element in binary tree
	int getCount(){
		return Count;
	}// end getCount

	// get the root of the binary tree
	int getRoot(){
		if (isEmpty())
		{ // if tree is empty
			throw string("Tree is empty");
		}

		else
		{ // if tree is not empty
			return binaryTreeData[0]; // root of the binary tree
		}
	}// end getRoot

	// determine if a binary tree is empty or not
	bool isEmpty() {

		return (Count == 0); // if count is =0, it's empty
	}// end isEmpty

	// add element
	void Add(int c){
		binaryTreeData[Count] = c;
		Count++;
	}// end Add

	// print the tree
	void printTree(){
		for (int i = 0; i<Count; i++)
		{ // print each element of the tree in array
			cout << binaryTreeData[i] << "\t";
		}
		cout << endl;
	}// end printTree   

	// preOrder traversal
  void preOrder(int index){
    if (index<=Count){
		cout << binaryTreeData[index] << endl; // print out the node
    }// end if
    int left=index*2+1; 
    int right=index*2+2;
    if (left<Count)
      { // recursively print out left subtree
	preOrder(left);
      }
    if (right<Count)
      { // recursively print out right subtree
	preOrder(right);
      }
  }// end preOrder
// inOrder traversal
  void inOrder(int index){
    int left=index*2+1;
    int right=index*2+2;
    if (left <Count)
      {// recursively print out left subtree
	inOrder(left);
      }
    if (index<=Count)
      {
	cout<<binaryTreeData[index]<<endl;
      }

    if (right<Count)
      {// recursively print out right subtree
	inOrder(right);
      }
  }// end inOrder

  // postOrder traversal
void postOrder(int index){
    int left=index*2+1;
    int right=index*2+2;
    if (left <Count)
      {// recursively print out left subtree
	postOrder(left);
      }

    if (right<Count)
      {// recursively print out right subtree
	postOrder(right);
      }
    if (index<=Count)
      {
	cout<<binaryTreeData[index]<<endl;
      }
  }// end postOrder
}; // end class arrayBasedBinaryTree





int main()
{
  arrayBasedBinaryTree* a= new arrayBasedBinaryTree(5);
  a->Add(2);
  a->Add(4);
  a->Add(3);
  a->Add(5);
  a->Add(6);
  cout<<"the root of the binary tree is "<<a->getRoot()<<endl;
  cout << "Now print out the entire tree" << endl;
  a->printTree();
  cout << "Now print out the tree with preOrder" << endl;
  a->preOrder(0);
  cout << "Now print out the tree with inOrder" << endl;
  a->inOrder(0);
  cout << "Now print out the tree with postOrder" << endl;
  a->postOrder(0);


  cout << "Please enter return key to exit...";
  string dummy;
  getline(cin, dummy);
  return 0;
} // end main

/***********************Sample Output************************
the root of the binary tree is 2
Now print out the entire tree
2       4       3       5       6
Now print out the tree with preOrder
2
4
5
6
3
Now print out the tree with inOrder
5
4
6
2
3
Now print out the tree with postOrder
5
6
4
3
2
Please enter return key to exit...
****************************************END******************/

