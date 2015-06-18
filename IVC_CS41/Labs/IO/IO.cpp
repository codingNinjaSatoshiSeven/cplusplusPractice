/************************************************************************************
 * Description: This C++ program will read a line from console, and break the sentence into words using space as a delimiter.
 * It will iterate through all the words, and print out every word. If the word is a number, then it will print out double the number
**************************************************************************************************************************** */

#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <sstream>
 
using namespace std;
 
// words function
void words(vector<string> &list, string line)
{
  // this function splits the sentence into words using space as delimiter.
  // Pre-condition: a line is inputed from console, and a list of string is initialized
  // Post-condition: words are splitted from the sentece, and stored into the vectors of string
    int pos; 
    while(line != "")
      {
	// as long as not end
        pos = line.find_first_of(" "); // find the first positon of space
        if(pos < string::npos) 
        {
	  // if found space
	  // truncate the word up till the space
            string temp = line.substr(0, pos);
	    // leave the remaining as the sentence
            line = line.substr(pos+1);
	    // store the words into vector
            list.push_back(temp);
        }// end if
        else
        {
	  // if the line contain no more space
	  // return the entire line
            list.push_back(line);
	    // make the line empty, indicating finished, exit while loop
            line = "";
        } // end else
      } // end while
} // end function words


// function getLine
bool getLine(string &line)
{// read a line from console, and determine if it's empty string or not
 // Pre-Condition: a string variable is declared in caller function
 // Post-Condition: a line is read from console, and if it's not empty string, it will return true. If it's empty, it will return false
    cout<<"Please input a sentence: ";
    getline(cin,line);
    return line != "";
} // end getLine
 
 
// function printIO
void printIO(string line)
{
  // print each words of line, and if the word is a number, print double the number
  // Pre-condition: a line is inputed from console
  // Post-condition: a vector of words string is stored
    vector<string> list;
    double convertToNum;
    cout<<"You entered: "<<line<<endl;
    words(list, line);
    cout<<"The words in your input line are: "<<endl;
    for(int i = 0; i < list.size();i++)
      { // iterate through every words in the line
	if(istringstream(list[i])>>convertToNum)
	  {
	    // if the word can be converted to a number
	    // then modify the word to be double the number
	    stringstream s;
	    s<<convertToNum*2;
	    list[i]=s.str();
	    
	  } // end if
	// print out the word
	  cout<<list[i]<<endl;
	  
      } // end for
} // end printIO function
 



// main function
int main()
{
   
    string line;
    while(getLine(line)) // while user doesn't input a blank line
      printIO(line); // print out the words splitted off the line

	cout << "Please enter return key to exit...";
	string dummy;
	getline(cin, dummy);
    return 0;
} // end main
 
 

 
/***********************************************************************Sample output*********************************************************************************
Please input a sentence: I have 3 apples.
You entered: I have 3 apples.
The words in your input line are: 
I
have
6
apples.
Please input a sentence: It's 3.5 pounds.
You entered: It's 3.5 pounds.
The words in your input line are: 
It's
7
pounds.
Please input a sentence: It's 4.5.
You entered: It's 4.5.
The words in your input line are: 
It's
9
Please input a sentence: 
*******************************************************************END***********************************************************************************************/
