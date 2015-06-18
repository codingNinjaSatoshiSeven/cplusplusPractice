/*******************************************************************************************************************************************************************
* Description: This C++ program implement dynamic Array that can allocate array Dynamically and grow the size as needed
* The program will then ask user to input integer to fill up the array
* The program will terminate when user enter -1 from keyboard and return
********************************************************************************************************************************************************************/
#include<iostream>
#include<string>
#include<cstdlib>
#include<stdio.h>
#include<string.h>
#include<sstream>
using namespace std;

// prompt for arraySize function
int prompt4ArraySize()
{
	// Pre-Condition: None
	// Post-Condition: an integer greater than 0 is returned
	string readIn;
	int mySize;
	
	// as long as user entered anything other than an int, keep looping until user entered an integer
	do {
		cout << "Please enter the size of the array: " << endl;
		getline(cin, readIn); // read the input 
		istringstream iss(readIn);
		if (iss>> mySize) // if the input is an integer, or contain the 1st component as integer, then proceed
		{ 
			if (mySize <= 0) // invalid integer range
			{
				cout << "You entered a invalid array size, please enter again!" << endl;
			}
			else // else if it's valid integer
			{
				break; // stop looping, proceed further
			}
			
		} // end if
		else
		{
			// if user entered a non-integer, loop back and prompt the user again
			cout << "You entered an invalid input, please enter again!" << endl;
		} // end else
	} while (true); // the termination condition is inside do-while loop
	
	return mySize; // return the size of the initial array

} // end prompt4ArraySize

// function fillArray to prompt user to input number to fill the array until user enter -1
void fillArray(int*& dArray, int& mySize, int incrementSize, int& fillSize)
{
	//pre-condition: array is initialized
	//pos-condition: array filled with int is returned
	int newNumber;
	int indexCount = 0; // keep track of index of last filled element
	string readIn;
	do
	{ // while user didn't enter -1, keep prompt for integer input to fill the array
		cout << "Please enter the number to store in array: " << endl;
		getline(cin, readIn);
		newNumber = atoi(readIn.c_str()); // convert input string to int
		if (newNumber == -1) // if user entered -1
		{
			// then quit the function and return
			break;
		}// end if

		if (indexCount >= mySize) // if array is filled and need to expand further to accomadate new element
		{
			int previousSize = mySize; // store the current arraySize
			mySize += incrementSize; // add additional x space, this x is from user input as initial array size
			// if user entered 3 for initial array size, the new array size will be 3+3=6, and 3+3+3=9 for next arraySize
			int* temp = new int[mySize]; // create new array of larger size
			for (int i = 0; i<mySize; i++)
			{ // initialize each element in new array, it's a good practice
				temp[i] = 0;
			} // end for
			memcpy(temp, dArray, previousSize*sizeof(int)); // copy the array in dArray to the new allocated large array
			//copy(dArray, dArray+previousSize,temp); // note, in VS compiler, the copy function is not usable
			int* toDelete = dArray;
			dArray = temp; // dArray point to the new array
			delete[] toDelete; // delete the older array
			cout << "array is extended!" << endl;
		}// end if
		dArray[indexCount] = newNumber; // store new number to the index of the array
		indexCount++; // move to the next array index

	} while (newNumber != -1); // if user entered -1, the loop will terminate
	fillSize = indexCount; // keep track of the size of filled element in array

} // end fillArray

// function printArray to print each element of the array
void printArray(int*& dArray, int mySize)
{
	//Pre-condition: an array is initialized
	//Post-condition: elements of array are printed
	for (int i = 0; i<mySize; i++)
	{
		cout << "number in index " << i << " is " << dArray[i] << endl;
	}// end of
} // end printArray

int main()
{
  
  int mySize = prompt4ArraySize(); // prompt for array size
  int incrementSize = mySize; // initial array size
  int fillSize = 0;
  int* dArray=new int[mySize]; // create new array
 
  fillArray(dArray, mySize, incrementSize, fillSize); // prompt user to enter number to array until user entered -1
  printArray(dArray, fillSize); // print the array element
  delete[] dArray; // delete the array

  cout << "Please enter return key to exit...";
  string dummy;
  getline(cin, dummy);
  return 0;
}// end main


/***********************************************OUTPUT*****************************************************************
Please enter the size of the array:
a
You entered an invalid input, please enter again!
Please enter the size of the array:
-1
You entered a invalid array size, please enter again!
Please enter the size of the array:
3
Please enter the number to store in array:
1
Please enter the number to store in array:
2
Please enter the number to store in array:
34
Please enter the number to store in array:
5
array is extended!
Please enter the number to store in array:
6
Please enter the number to store in array:
8
Please enter the number to store in array:
10
array is extended!
Please enter the number to store in array:
11
Please enter the number to store in array:
-1
number in index 0 is 1
number in index 1 is 2
number in index 2 is 34
number in index 3 is 5
number in index 4 is 6
number in index 5 is 8
number in index 6 is 10
number in index 7 is 11
Please enter return key to exit...
*********************************************************END*************************************************************/