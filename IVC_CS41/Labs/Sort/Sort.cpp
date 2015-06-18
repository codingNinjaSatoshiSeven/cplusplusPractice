/************************************************************************************
* Irvine Valley College CS 41: Data Structure
* Instructor: A.Lane
* Assignment#: Lab3, Sort (C++)
* Name: Shengtao Li
* ID: 1015934
* Due Date: 9/21/2014
* Description: This C++ program will Sort the unsorted array, and print out the sorted array. I used Bubble Sort
**************************************************************************************************************************** */
#include<iostream>
#include<string>
using namespace std;

// bubbleSort function
void BubbleSort(int*& arrayPtr, int arraySize)
{
	// pre-condition: received an array
	// post-condition: return a sorted array via bubbleSort
	int i, j;
	int flag = 1; // flag to indicate there are still element to swap
	int temp;
	int numLength = arraySize;
	for (i = 1; (i <= arraySize) && flag; i++)
	{ // as long as there are still element to swap, and not travelled to the end
		flag = 0; // reset flag
		for (j = 0; j < (arraySize - 1); j++)
		{
			if (arrayPtr[j + 1] <arrayPtr[j])
			{ // if the two neighbors can be swapped
				temp = arrayPtr[j];
				arrayPtr[j] = arrayPtr[j + 1];
				arrayPtr[j + 1] = temp;
				flag = 1; // continue scanning the array

			} // end if

		} // end for

	} // end for

} // end bubbleSort

// printArray
void printArray(int*& arrayPtr, int mySize)
{
	// pre-condition: received an array
	// post-condition: print out each element of array
	cout << "This array contains ";
	for (int i = 0; i < mySize; i++)
	{
		cout << arrayPtr[i] << "\t";
	}
	cout << endl;

} // end printArray

int main()
{
	int* arrayPtr = new int[5]; // create and array of 5 unsorted element
	int mySize = 5;
	arrayPtr[0] = 3;
	arrayPtr[1] = 8;
	arrayPtr[2] = 5;
	arrayPtr[3] = 10;
	arrayPtr[4] = 2;
	printArray(arrayPtr, mySize); // print the unsorted array
	BubbleSort(arrayPtr, mySize); // perform bubble sort
	cout << endl << "After bubble Sort" << endl;
	printArray(arrayPtr, mySize); // print the sorted array


	cout << "Please enter return key to exit...";
	string dummy;
	getline(cin, dummy);
	return 0;
	return 0;
} // end main

/***********************************************************************Sample output*************************
This array contains 3   8       5       10      2

After bubble Sort
This array contains 2   3       5       8       10
Please enter return key to exit...

*************************************************************************************************************/