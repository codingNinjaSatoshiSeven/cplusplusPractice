/*******************************************************************************************************************************************************************
 * Irvine Valley College CS 41: Data Structure
 * Instructor: A.Lane
 * Assignment#: Lab2, Lab Loop (C++)
 * Name: Shengtao Li
 * ID: 1015934
 * Due Date: 9/7/2014
 * Description: This C++ program implements a method that uses loop to calculate summation. 
 * The loop will take an interger and return the summation . If the integer is less than 1, it will return 0, else it will return integer summation
 * all the way to the input integer. 
 *************************************************************************************************************************************************************** */


#include<iostream>
#include<string>
using namespace std;


// implementation of summation
int sum(int n)
{
  // Pre-condition: an integer is inputed
  // Post-condition: an integer sum is reteruned
  // Error-case: Since input is integer and the case handle all the integers, there's no error handling case. 
  if (n<1) // if integer is less than 1
    return 0;
  else
    { // if integer is greater or equal to 1
      int sumReturn=0; // initialize the accumulator to 0
      for (int i=1; i<=n; i++)
	{ // from 1 to n, sum up all the integer 1 each loop
	  // and return the sum
	  sumReturn=sumReturn+i; 
	}// end for
      return sumReturn;
    }// end else

}// end sum function


// main function
int main()
{
  int a;
  a=10;
  cout<<" the summation of "<<a<<" is: ";
  cout<<sum(a)<<endl;

  a=3; 
  cout<<" the summation of "<<a<<" is: ";
  cout<<sum(a)<<endl;

  cout<<" Now tryng the boundary case..."<<endl;
  a=1;
  cout<<" the summation of "<<a<<" is: ";
  cout<<sum(a)<<endl;

  a=0;
  cout<<" the summation of "<<a<<" is: ";
  cout<<sum(a)<<endl;

  a=-1;
  cout<<" the summation of "<<a<<" is: ";
  cout<<sum(a)<<endl;


  cout << "Please enter return key to exit...";
  string dummy;
  getline(cin, dummy);
  return 0;
}// end main


/***************************************************Output************************************************************************************************************* the summation of 10 is: 55
 the summation of 3 is: 6
 Now tryng the boundary case...
 the summation of 1 is: 1
 the summation of 0 is: 0
 the summation of -1 is: 0
*********************************************************************END*********************************************************************************************/
