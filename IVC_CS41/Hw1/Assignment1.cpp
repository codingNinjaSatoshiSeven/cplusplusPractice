/*******************************************************************************************************************************************************************
 * Irvine Valley College CS 41: Data Structure
 * Instructor: A.Lane
 * Assignment#: Assignment 1
 * Name: Shengtao Li
 * ID: 1015934
 * Due Date: 8/24/2014
 * Description: This C++ program implement Stack based on linked list.  
 * The stack will have basic push, pop, and 
 * It will utilize the linked list based stack to parse and operate reverse polish notation
 * It will implement Push, Pop, NodeCount (count the total node, or element in the stack)and Clear (remove all the elements in stack) method.
 * the linked list (which the stack is based of), contains NodeData (get/set method to get/set the data of the node), NodeNext (get/set method to 
 * get/set the next node it's point to), and getCount (get the total node in linked list) method
 * The stack and linked list implementation is in "Node.h"
 * the rpn function takes in a RPN string, parse it, and evaluate the notation
 * The rpn function will handle errors such as:
 *       Too many operators (+ - * /) 
 *       Too many operands
 *       Division by zero
 *       Syntax error (3 / 4 instead of 3 4 /)
 * The rpn function will take in a RPN string expression, and evaluate the the result and return the value as a string, if no error has occured.
 * Otherwise, the rpn function will return the error status of the RPN string as a string.
 * The main program will prompt user to enter a RPN string and evaluate and display, until user entered "0" and followed by a newline
 ********************************************************************************************************************************************************************/

#include <string>
#include <sstream> // to parse string
#include <iostream> 
#include <cmath> // to do exponent operation
#include <cstdlib>
#include "Node.h" // to include customarilly developed stack using linked list
 

//rpn function to parse the RPN string, evaluate, and return the result as a string
std::string rpn(const std::string &expr, bool& errorFlag){
  // Input: a RPN string, errorFlag
  // Output: result of the RPN string, errorFlag
  // Pre-condition: a RPN string is received, and errorFlag is reset to false
  // Post-condition: RPN expression is evaluated, and the result is returned as string to caller
  // Error-condition: RPN expression is evaluated, and the error string is returned to caller
  std::string toReturn; // string to return
  std::istringstream iss(expr);
  stackLL<double>* myStack=new stackLL<double>(); // initialize the stack
  std::string token;
  while (iss >> token) {
    // tokenize the string by default space
   
    double tokenNum;
    if (std::istringstream(token) >> tokenNum) {
      // as long as there's more token in the string remain that can be translated to double
      myStack->Push(tokenNum); // push the value to the stack
    } 
    else
      {
	// else, if the token is not a number/double
      if (token == "*" ||token=="/" || token=="-" || token=="+"|| token=="^")
	{ 
	  // if token is one of the operators
	  if (myStack->NodeCount()<2)
	    {
	      // if stack has less than 2 elements, which means there are too many operators, or there's a syntax error in RPN
	      errorFlag=true;
	      toReturn="syntax error/too many operators";
	      myStack->Clear();
	      return toReturn; // return "syntax/too many operator" error to the caller function
	    }

	  else
	    {
	      // else, if syntax is correct and not too many operators
	      double secondOperand = myStack->Pop();
	      double firstOperand=myStack->Pop(); // pop the topmost 2 values in the stack, and run corresponding operation
   
	      if (token == "*") // multiplication case
		myStack->Push(firstOperand * secondOperand);
	      else if (token == "/") // division case
		{
		  if (secondOperand==0)
		    {
		      // divide by zero case
		      errorFlag=true;
		      toReturn="divide by zero error";
		      myStack->Clear();
		      return toReturn; // return "divide by zero error" to the caller function
		    }
		  else // not divide by zero case
		myStack->Push(firstOperand / secondOperand);
		}
	      else if (token == "-") // subtraction case
		myStack->Push(firstOperand - secondOperand);
	      else if (token == "+") // addition case
		myStack->Push(firstOperand + secondOperand);
	      else if (token == "^") // exponential case
		myStack->Push(std::pow(firstOperand, secondOperand));
	      else if (token == "=") // = case, just drop the "="
		{
		}
	      else { //just in case there's other nonsense symbol in the RPN notation
		toReturn="other syntax error";
		return toReturn;
	      }// end interior else
	    }// end else


	} // end if
 
      }   
  } // end of string parsing
  
 
  if(myStack->NodeCount()>=2) // too many operands
    {
      // if finished tokenizing and parsing the string, and evaluated all the operators, 
      // but there are still more than 2 elements left in the stack
      errorFlag=true;
      toReturn="too many operands";
      myStack->Clear();
      return toReturn; // return "too many operands" error to caller function
    }

  else
    {
      // else if there are not too many operands
      if (errorFlag==true)
	{
	  // but if there's already previous error raised, then do nothing
	}// end if
      else
	{
	  // if there's no previous error raised
	  std::ostringstream strs;
	  double temp= myStack->Pop();
	  strs<<temp; // convert the double value to string
	  toReturn=strs.str(); 
	  myStack->Clear();// clear the stack
	  return toReturn; // return the converted value (from double to string) to caller function
	}// end else
      
    }// end else
}//end rpn function
 
int main() {
  bool errorFlag=false; // set the errorFlag and initialize to false=> no error
 
  std::string temp;  // temp to store the rpn evaluated result, either a value or an error message
  std::string readIn; // string to store value entered by user
  
  std::cout<<"******************************************************************"<<endl;
  std::cout<<"********This is RPN calculator evaluate the RPN expression********"<<endl;
  std::cout<<"******************************************************************"<<endl<<endl<<endl;
  do
    { // while user enter anything other than "0\n"
      cout<<"Please enter notation: "; // prompt user to enter a RPN string
      getline(cin, readIn); // read in the entire line and store to the string
      if (readIn=="0")// if user entered "0\n"... since getline will only read the value until encountered "\n", "0" is equivalent to "0\n" in other method
	break;// exit the program
     
      // else, if user entered other expression
      temp=rpn(readIn, errorFlag); // evaluate the expression and get the result
       if (errorFlag==true)
	 {
	   // if error is detected from evaluating function
	   // print out the message of the error
	   std::cout<<readIn<<"\t";
	   std::cout<<"Error:  "<<temp<<std::endl;
	 }

       else
	 {
	   // else, if there's no error in the expression
	   // print out the evaluated result
	   std::cout<<readIn<<"\t";
	   std::cout<<"Final answer: "<<temp<<std::endl;

	 }// end else
       errorFlag=false;
      
    } while (readIn!="0");
  std::cout<<"*********Program terminated. Have a nice day!***********"<<endl;

 
  return 0;
}

/******************************************************************Sample Output*************************************************************************************
***************************************************************************************************
************This is RPN calculator that takes user input and evaluate the RPN expression************
***************************************************************************************************


Please enter notation: 10 15 + =
10 15 + =       Final answer: 25
Please enter notation: 10 15 - =
10 15 - =       Final answer: -5
Please enter notation: 2.5 3.5 + =
2.5 3.5 + =     Final answer: 6
Please enter notation: 10 0 / =
10 0 / =        Error:  divide by zero error
Please enter notation: 10 20 * / =
10 20 * / =     Error:  syntax error/too many operators
Please enter notation: 12 20 30 / =
12 20 30 / =    Error:  too many operands
Please enter notation: -10 -30 - =
-10 -30 - =     Final answer: 20
Please enter notation: 100 10 50 25 / * - -2 / =
100 10 50 25 / * - -2 / =       Final answer: -40
Please enter notation: 0
*********Program terminated. Have a nice day!***********

********************************************************************END OF DOCUMENT**********************************************************************************/
