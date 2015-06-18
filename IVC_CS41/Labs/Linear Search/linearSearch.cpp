/************************************************************************************
 * Description: This C++ program will create an array of integer with size 10, fill the array with integer 0-9, and use the
 * linearSearch function to find if the integer inputed from user is in the array. If it is, the index of the matching number
 * is returned. Otherwise, -1 is returned. 
**************************************************************************************************************************** */


#include<iostream>
#include<string>
#include<sstream>
using namespace std;

// max size of the array is defined to be 10
#define maxSize 10


// linearSearch function
int linearSearch(int c, int*& myArray)
{
  //Pre-condition: an array of integer is initialized and filled with element. a valid integer has been inputed from user
  // Post-condition: the matching number's index is return, if matched. Otherwise, -1 is returned
  for (int i=0; i<maxSize; i++)
    { // iterate one by one throughout the array, and this is the linear search
      if (myArray[i]==c)
	{
	  // if found match, then return the index, no further looping needed
	  return i;
	}//end if
    }// end for
  // if all the elements in the array are examined and for loop ends, but no return-> this indicate no match has been found, return -1
  return -1;

} // end linearSearch


// main function
int main()
{ 
  // initialize the dynamic allocated array myArray
  int* myArray= new int[maxSize];
  for (int i=0; i<maxSize; i++)
    {
      // load the array with integer 0-9
      myArray[i]=i;
    }// end for1
  
  string readIn;
  int intToSearch;
  int indexOfMatch;
  do {
    // keep looping untill a blank string is entered
  cout<<" Please enter an integer to search in the array, enter blank and enter to exit: ";
  getline(cin, readIn);
  cout<<endl;
  if(istringstream(readIn)>>intToSearch)
    {
      // if user input a string that can be intepreted as a number
      indexOfMatch=linearSearch(intToSearch, myArray); // search for the number in the array
      cout<<" the number "<<intToSearch<<" is in array index "<<indexOfMatch<<endl; // print out the result
      
    } // end if
  
  else
    {
      // if input string cannot be intepreted as a number
      if (readIn=="") // if it's an empty string, then exit the loop
	break;
      else // if it's not empty string, then it's invalid expression, prompt user to input again
	cout<<"Invalid input. Please try again"<<endl;

    }// end else
  } while (readIn!="");

  // delete the array
  delete[] myArray;
  cout << "Please enter return key to exit...";
  string dummy;
  getline(cin, dummy);
  return 0;
} // end main

/*******************************************************************EXAMPLE Output************************************************************************************

 Please enter an integer to search in the array, enter blank and enter to exit: 1

 the number 1 is in array index 1
 Please enter an integer to search in the array, enter blank and enter to exit: 0

 the number 0 is in array index 0
 Please enter an integer to search in the array, enter blank and enter to exit: 12

 the number 12 is in array index -1
 Please enter an integer to search in the array, enter blank and enter to exit: 100

 the number 100 is in array index -1
 Please enter an integer to search in the array, enter blank and enter to exit: a

Invalid input. Please try again
 Please enter an integer to search in the array, enter blank and enter to exit: Adam

Invalid input. Please try again
 Please enter an integer to search in the array, enter blank and enter to exit:

********************************************************************END*********************************************************************************************/
