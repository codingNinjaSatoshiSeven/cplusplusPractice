/****************************************************************************
* Irvine Valley College CS 41: Data Structure
* Instructor: A.Lane
* Assignment#: Assignment 4: BORG using hash table
* Name: Shengtao Li
* ID: 1015934
* Due Date: 12/07/2014
* Description: This C++ program reads a BORG program file and perform operation
* accordingly, and store them into hash table
****************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <ctime>
using namespace std;

// define hash size small but prime, so allow easy collison happening. 
#define HASH_SIZE 11

// nodeHash class, the node that store each element in the hash table 
class nodeHash
{
public:
    int value; // hold the value of the variable 
	int count; // keep track of which scope the variable is in: 1 for global, then the # increment as scoping down
	string name; //hold the variable name, so when doing searching in the hash table, the value can be retrieved
    nodeHash* next; // link to next node

	// constructor
    nodeHash()
    {
		// initialize everything
        name="";
		value=0;
		count=0;
        next=NULL;
    } // end constructor
    
}; // end class nodeHash

// class stackVar to hold the variable name on a stack so depends on different scope, the stack need to be filled or popped
class stackVar{
public:
	string stack[HASH_SIZE*10]; // a stack of 10 times the hash table size is good assumption
	int TOS; 
	stackVar(){
		for (int i=0; i<HASH_SIZE*2; i++){
			stack[i]="";
		} //initialize the stack to hold empty string
		TOS=-1; // when empty stack, TOS set to -1
	}
	int count(){ // total count of element in stack
		return TOS+1;
	}
	void push(string s){
		TOS++;
		stack[TOS]=s;	
	} // end push 
	string pop(){
		string temp=stack[TOS];
		TOS--;
		return temp;
	}// end pop

}; // end class stackVar

// function Hash to hash a variable name into the corresonding hashing index
int Hash(string myVariable){
    int sum=0;
    for (int i=0; i<myVariable.length(); i++){
        int num=(int)myVariable[i];
        sum+=num*(i+1);
    } // end for
    return (sum%HASH_SIZE);
} // end Hash function

// function initTable to initialize the hash table
void initTable(nodeHash**& tblPtr){
    tblPtr=new nodeHash*[HASH_SIZE];
    for (int i=0; i<HASH_SIZE; i++){
        tblPtr[i]=NULL; // set every cell in the hash table to null
    }
}// end initTable

// function inserIntoHash to determine which cell need to be inserted, also take care of chaining
void insertIntoHash(string myVariable, int value, nodeHash**& tblPtr){
    int index=Hash(myVariable); // get the index where it should be inserted
	nodeHash* current=tblPtr[index]; // get a pointer to the cell where the variable should be inserted
    if (current!=NULL){ // if the variable slot has already taken
		if ( (current->name)==myVariable){
			// if happens to be the 1st element, and that element already exist
			current->count++; // 
			current->value=value;
		}
			
		else { // else if its further down the linked list, traverse
			while (current!=NULL && current->next!=NULL){
				if (current->name==myVariable){
					break;
				}
				else {
					current=current->next;
				}

			}
			if (current->name==myVariable){ // found down the list
				current->count++;
				current->value=value;
			}
			else { // if travel all the way till the last element still can't find the element
				//then need to insert new node
				current->next=new nodeHash();
				current->next->count=1;
				current->next->name=myVariable;
				current->next->value=value;
			}

		} // end else
		
		
		

	} // end outer if
    else
    { // else if there's no node established in the corresponding hash cell
        tblPtr[index]=new nodeHash();
		tblPtr[index]->count=1;
		tblPtr[index]->value=value;
		tblPtr[index]->name=myVariable;
    
    }
} // end insertIntoHash

// delTable to delete the hash table as garbage collection
void delTable(nodeHash**& tblPtr){
    for (int i=0; i<HASH_SIZE; i++)
    {
        delete tblPtr[i];
    }
    delete[] tblPtr;
    tblPtr=NULL;
} // end delTable function


// evaluate to evaluate a simple expression and return result
int evaluate(string line, nodeHash**& tblPtr){
    string token="";
    istringstream iss(line);
    stringstream ss;
	ss.clear ();
	ss.str ("");
    int tmp;
	int result;
	int r1=1;
	int count=0;
	string operatorString=" ";
	string varName="";
    while (iss>>token){ // scan every token in the expression
		if (token!="\n" ||"" ||"0"){
        ss << token;
        ss >> tmp;
        if (ss.fail()){ // if token is not a number
           if (token=="="){ // ignore if it's equal sign
		   }
		   else if (token=="++"){ // increment sign
			   result+=1;
			   operatorString="++";
		   }
		   else if (token=="--"){// decrement
			   result-=1;
			   operatorString="--";
		   }
		   else if (token =="+"||token =="-"||token =="*"||token =="/"||token =="%"||token =="^"){
			   // regular operators
			   operatorString=token;
		   }
		   else{ // if it's a variable name
			   if (count==0){
				   varName=token;
				   int index=Hash(token);
				   if (tblPtr[index]==NULL){
					   result=1; // initialize result
				   }
				   else{// get the var value from hash table
					   nodeHash* current=tblPtr[index];
					   while (current->name!=varName && current->next !=NULL){
						   current=current->next;
					   }
					   if (current->name==varName){
						   result=current->value;
					   }
					   else{
						   result=1;
					   }
					   
				   }
				   //cout<<result<<endl;
				   count++;
			   }
			   else { // else if it's not number but not the first in variable
				   int index=Hash(token);
				   if (tblPtr[index]==NULL){
					   r1=1;
				   }
				   else{
					   r1=tblPtr[index]->value;
				   }
				   switch (operatorString[0]){
				   case '+': result+=r1;
					   break;
				   case '-': result-=r1;
					   break;
				   case '*': result*=r1;
					   break;
				   case '/': result/=r1;
					   break;
				   case '%': result%=r1;
					   break;
				   case '^': result^=r1;
					   break;
				   default:;
				   }
			   }
		   }
            ss.clear();
            ss.str("");
        }
        else{ // else if it is a number
            r1=tmp;
			switch (operatorString[0]){
				   case '+': result+=r1;
					   break;
				   case '-': result-=r1;
					   break;
				   case '*': result*=r1;
					   break;
				   case '/': result/=r1;
					   break;
				   case '%': result%=r1;
					   break;
				   case '^': result^=r1;
					   break;
				   default:;
				   }
            ss.str("");

        }
        ss.str("");
		}
    } // end while
	if (operatorString==" "){
		result=r1;
	}
	insertIntoHash(varName, result, tblPtr);
	return result;
} // end evaluate

// evaluateP to evaluate a printed statement and return the result
string evaluateP(string line, nodeHash**& tblPtr){
	int trimIndex=line.find_first_not_of(" "); // trim the initial white space
	string line2=line.substr(trimIndex+6);
    string token="";
    istringstream iss(line);
    stringstream ss;
	ss.clear ();
	ss.str ("");
    int tmp;
	string varName;
	int result=1;
	string toReturn="";
	int r1;
	int count=0;
	int countP=0;
	bool undefinedVar=false;
	string operatorString="";

    while (iss>>token){
		if (token!="\n" ||"" ||"0"){
        ss << token;
        ss >> tmp;
        if (ss.fail()){
		   if (countP==0){ // skip the 1st instance, which is the word "PRINT"
			   countP++;
		   }
           else if (token=="="){
		   }
		   else if (token=="++"){
			   result+=1;
			   operatorString="++";
		   }
		   else if (token=="--"){
			   result-=1;
			   operatorString="--";
		   }
		   else if (token =="+"||token =="-"||token =="*"||token =="/"||token =="%"||token =="^"){
			   operatorString=token;
		   }
		   else{ // if it's a variable name
				   if (count==0){
				   varName=token;
				   int index=Hash(token);
				   if (tblPtr[index]==NULL){ // if variable is not defined
					   toReturn="UNDEFINED";
					   undefinedVar=true;

				   }
				   else{ // else, traverse the hash table cell to find variable value
					   nodeHash* current=tblPtr[index];
					   while (current->name!=varName && current->next!=NULL){
						   current=current->next;
					   }
					   if (current->name==varName){ // if found
						   result=current->value;
					   }
					   else{ // if not found
						   toReturn="UNDEFINED";
						   undefinedVar=true;
					   }
				   //toReturn=""+result;
				   }
				   
				   count++;
			   
			   }
			   else { // else if it's other expression futher down the string
				   r1=1;
				   switch (operatorString[0]){
				   case '+': result+=r1;
					   break;
				   case '-': result-=r1;
					   break;
				   case '*': result*=r1;
					   break;
				   case '/': result/=r1;
					   break;
				   case '%': result%=r1;
					   break;
				   case '^': result^=r1;
					   break;
				   default:;
				   }
			   }
		   }
            ss.clear();
            ss.str("");
        }
        else{ // if it's a number
            r1=tmp;
			switch (operatorString[0]){
				   case '+': result+=r1;
					   break;
				   case '-': result-=r1;
					   break;
				   case '*': result*=r1;
					   break;
				   case '/': result/=r1;
					   break;
				   case '%': result%=r1;
					   break;
				   case '^': result^=r1;
					   break;
				   default:;
				   }
            ss.str("");

        }
        ss.str("");
		}
    } // end while
	//cout<<result<<endl;
	if (undefinedVar==false){ // if not undefined, then convert number to a string
		ostringstream ss2;
		 ss2 << result;
		 toReturn=ss2.str();
		 ss2.clear();
	}
	return line2+ " IS "+toReturn;
} // end evaluateP
int main(){
	stackVar* ssVar=new stackVar();
	nodeHash** tblPtr=NULL;
	initTable(tblPtr);
    ifstream myfile;
    string line;
	string filename;
	cout<<"Please enter the file you want to open"<<endl;
	// please enter the name included in the zip
	// the whole name: "BORG.txt", or "CustomizedBORG.txt"
	// don't forget the ".txt"
	getline(cin, filename);
	cout<<filename<<endl;
    myfile.open(filename);

	int varIndex=0;
	int scope=0;
    if (myfile.is_open()){ // if file open successfully
        while (getline(myfile,line)){
	  if (line.find("COM")!=std::string::npos|| line.find(" COM ")!=std::string::npos){ //if it's a comment
			cout<<endl;
	  }
	  else if (line.find("VAR")!=std::string::npos){ // if it's a var expression, 
		int startVarName=line.find("VAR ")+4;
		int endVarName=line.find(" =")-1;
		int startVarValue=line.find("= ")+2;
		int endVarValue=line.find("\n")-1;
		string varName=line.substr(startVarName,endVarName-startVarName+1);
		int varValue=atoi((line.substr(startVarValue,endVarValue-startVarValue+1)).c_str());
		insertIntoHash(varName, varValue, tblPtr);
		ssVar->push(varName);
		cout<<endl;
	  }
	  
	  else if (line.find("PRINT")!=std::string::npos){ // if it's print statement
		  cout<<evaluateP(line, tblPtr)<<endl;
	  }
	  else if (line.find("TIME")!=std::string::npos){ // Xtra- if it's TIME statement to get current date;
		time_t t = time(0);   // get time now
		struct tm * now = localtime( & t );
		cout <<"Today is "<< (now->tm_year + 1900) << '-' 
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday
         << endl;
	  }
	  else if (line.find("HASHINDEX")!= std::string::npos){ //Xtra- get the hash index of a variable
		  istringstream iss(line);
		  string token="";
		  int count=0;
		  int index;
		  while (iss>>token && count<=1){
			  count++;
			  if (count==0){
			  }
			  else{
				  index=Hash(token);
			  }
		  }
		  cout<<token<<" is supposed to be at index# "<<index<<endl;


	  }
	  else if (line.find("START")!=std::string::npos){ // if its start block
		  //cout<<line<<endl;
		  ssVar->push("START");
		  cout<<endl;
		  
	    scope++;
	  }
	  else if (line.find("FINISH")!=std::string::npos){// if it's finish block
		  while (ssVar->stack[ssVar->TOS]!="START"){ // pop off all the variable name stored on the stack until hit start 
			  string myVar=ssVar->pop();
			  int index=Hash(myVar);
			  nodeHash* current=tblPtr[index];
			  nodeHash* previous=current;
			  while (current!=NULL && current->next!=NULL && current->name!=myVar){
				  previous=current;
				  current=current->next;
			  }
			  if (current->name==myVar){
				  if (current->count>1){
					  current->count--;
				  }
				  else{
					  previous->next=current->next;
					  if (current==tblPtr[index]){
						  tblPtr[index]=NULL;
					  }
					  current=NULL;
				  }
			  }


		  }
		  string junk=ssVar->pop();
		  cout<<endl;
		scope--;
	  }
	  else{ // case to do operation with variables
		  evaluate(line, tblPtr);
		  cout<<endl;
	  }
     } // end while
        myfile.close();
    }
    else 
    { // can't open file
	cout<<"Unable to open file"<<endl;
    }

    delTable(tblPtr);

	cout << "Please enter return key to exit...";
	string dummy;
	getline(cin, dummy);
	return 0;
    return 0;
} // end main
