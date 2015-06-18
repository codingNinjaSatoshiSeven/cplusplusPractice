/*******************************************************************************************************************************************************************
 * Irvine Valley College CS 41: Data Structure
 * Instructor: A.Lane
 * Assignment#: Lab2, Simple Array (C++)
 * Name: Shengtao Li
 * ID: 1015934
 * Due Date: 9/7/2014
 * Description: This C++ program will implement simple array of 5 elements
 * It will load the array from keyboard, and print the contents of the array
**************************************************************************************************************************** */

#include<iostream>
#include<string>
#include<sstream>
using namespace std;

#define maxSize 5


// function loadArray
void loadArray(int* myArray)
{
  for (int i=0; i<maxSize; i++)
    { // iterate maxSize times
      int toLoad;
      string temp;
      cout<<"Please enter an integer: ";
      getline(cin, temp);// read data from keyboard
      cout<<endl;
      if (istringstream(temp)>>toLoad)
	{ // if the input from user can be intepreted as an int
	  myArray[i]=toLoad; // load the data into array
	} // end if
      else
	{ // if the input from user CANNOT be intepreted as an int
	  cout<<" you entered a non-integer, please enter an integer again"<<endl;
	  i--; // repeat the loop to ask user to enter the number again to load to the array
	} // end else  
    }// END FOR
}//end loadArray

// function printArray
void printArray(int* myArray)
{
  cout<<" now printing the entire array!..."<<endl;
  for (int i=0; i<maxSize; i++)
    {
      // iterate through each element in array
      cout<<myArray[i]<<endl; // print the array
    }// end for


}// end print Array

// main function
int main ()
{
  int myArray[maxSize]; // initialize the array
  loadArray(myArray); // load the array with integers
  printArray(myArray); // print the array

  cout << "Please enter return key to exit...";
  string dummy;
  getline(cin, dummy);
  
  return 0;
} // end main


/******************************************************Sample OUTPUT1*************************************************************************************************
Please enter an integer: 11

Please enter an integer: 2

Please enter an integer: 131

Please enter an integer: 4

Please enter an integer: 6

 now printing the entire array!...
11
2
131
4
6


*******************************************************Sample OUTPUT2*************************************************************************************************
Please enter an integer: 1

Please enter an integer: 2

Please enter an integer: as

 you entered a non-integer, please enter an integer again
Please enter an integer: f

 you entered a non-integer, please enter an integer again
Please enter an integer: 3

Please enter an integer: t

 you entered a non-integer, please enter an integer again
Please enter an integer: 5

Please enter an integer: y

 you entered a non-integer, please enter an integer again
Please enter an integer: 6

 now printing the entire array!...
1
2
3
5
6
********************************************************************END**********************************************************************************************/
