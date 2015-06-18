/************************************************************************************
* Description: This C++ program will implement array based Binary Tree
**************************************************************************************************************************** */
#include<iostream>
#include<string>
using namespace std;

// class arrayBasedBinaryTree
class arrayBasedBinaryTree {

private:
  int Count; // total element in the binary tree
  int arraySize; // size of the array

public:
  int* binaryTreeData; // pointer to the array based binary tree
  // contructor
  arrayBasedBinaryTree(int size){
    binaryTreeData=new int[size]; 
    Count=0;
    arraySize=size;

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

    return (Count==0); // if count is =0, it's empty
  }// end isEmpty
     
  // add element
  void Add(int c){
    binaryTreeData[Count]=c;
    Count++;
  }// end Add

  // print the tree
  void printTree(){
    for (int i=0; i<Count; i++)
      { // print each element of the tree in array
	cout<<binaryTreeData[i]<<"\t";
      }
    cout<<endl;
  }// end printTree   
};




int main()
{
  arrayBasedBinaryTree* a= new arrayBasedBinaryTree(10); // create a new tree
  a->Add(2);
  a->Add(4);
  a->Add(5);
  a->Add(6);
  a->Add(7);
  a->Add(9);
  a->Add(10);
  a->Add(12);
  a->Add(13);
  a->Add(15); // add 10 elements
  cout << "the binary tree contain  "<< a->getCount() <<" element"<< endl; // print the # of element of the tree
  cout<<"The root of the binary tree is "<<a->getRoot()<<endl; // print the root of the binary tree, which is 2
  cout << "Now displaying the entire tree!" << endl;
  a->printTree(); // print the entire tree
  


  cout << "Please enter return key to exit...";
  string dummy;
  getline(cin, dummy);
  return 0;
} // end main

/****************************************Sample Output
the binary tree contain  10 element
The root of the binary tree is 2
Now displaying the entire tree!
2       4       5       6       7       9       10      12      13      15

Please enter return key to exit...

**********************************END ***************/