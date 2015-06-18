/************************************************************************************
* Description:  This C++ program will take in a sorted array, and find the index of array that contain the matching number.
* If number is not found, -1 will be returned
*****************************************************************************************************************************/

#include<iostream>
#include <cstdlib>
#include <string>
using namespace std;

// binarySearch function
int binarySearch(int* arrayPtr, int arraySize, int Val)
{
	//Pre-condition: received a sorted array
	//Post-condition: the index of the value found will be returned, or -1 if not found
	int Mid, Lbound = 0, Ubound = arraySize - 1;

	while (Lbound <= Ubound)
	{// while lower bound is less or equal to upper bound
		Mid = (Lbound + Ubound) / 2; // set the middle bound
		if (Val > arrayPtr[Mid]) // if the value is greater than the middle bound value
			Lbound = Mid + 1; // move to right of middle bound and search
		else if (Val < arrayPtr[Mid]) // if the value is less than the middle bound value
			Ubound = Mid - 1; // move to left and search
		else // if matches the middle bound value
			return Mid; // found! return the index
	}// end while
	return -1; // if not found
} // end binarySearch

void printArray(int* arrayPtr, int mySize)
{
	for (int i = 0; i < mySize; i++)
	{
		cout << arrayPtr[i] << "\t";
	}// end for
	cout << endl;
}// end printArray

int main()
{
	int array[] = { 1, 2, 5, 7, 10, 11 }; // create an array of size 6
	int mySize = 6;

	cout << "The array contain " << mySize << " elements." << endl;
	printArray(array, mySize);
	int toSearch = 3; // search for 3, should return -1
	int indexLocation;
	cout << "the index of " << toSearch << " is at ";
	indexLocation = binarySearch(array, mySize, toSearch);
	cout << indexLocation<< endl;

	toSearch = 7; // search for 7, should return 3
	cout << "the index of " << toSearch << " is at ";
	indexLocation = binarySearch(array, mySize, toSearch);
	cout << indexLocation << endl;

	toSearch = 11; // search for 11, should return 5
	cout << "the index of " << toSearch << " is at ";
	indexLocation = binarySearch(array, mySize, toSearch);
	cout << indexLocation << endl;

	int array2[] = { 2, 4, 5, 6, 9 }; // create an array of 5 elements
	mySize = 5;

	cout << endl;
	cout << "The array contain " << mySize << " elements." << endl;
	printArray(array2, mySize);
	toSearch = 5; // search for 5, should return 2
	cout << "the index of " << toSearch << " is at ";
	indexLocation = binarySearch(array2, mySize, toSearch);
	cout << indexLocation << endl;

	cout << "Please enter return key to exit...";
	string dummy;
	getline(cin, dummy);
	return 0;
}

/***********************************************************************Sample output***********************************
The array contain 6 elements.
1       2       5       7       10      11
the index of 3 is at -1
the index of 7 is at 3
the index of 11 is at 5

The array contain 5 elements.
2       4       5       6       9
the index of 5 is at 2
Please enter return key to exit...
Press any key to continue . . .
*************************************************************************************************************************/