/****************************************************************************
* Description: This C++ program implement a Hash table
****************************************************************************/
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

#define ARR_SIZE 27
#define LINEAR_PROBE_STEP 5

int Hash(int c){
    return c%ARR_SIZE;
} // end Hash function

void initTable(int*& tblPtr){
    tblPtr=new int[ARR_SIZE];
    for (int i=0; i<ARR_SIZE; i++){
		// initialize each element of hash table to 0
        tblPtr[i]=0;
    }
}// end initTable

void delTable(int*& tblPtr){
    delete[] tblPtr;
    tblPtr=NULL;
}

void add(int c, int*& tblPtr){
    int hashKey=Hash(c);
    int count=0;
	// linearly probe to the next space if current space is filled
	// after probing for 10 times, it's a good time to stop.
    while (tblPtr[hashKey]!=0 && count<=10){
        hashKey=(hashKey+LINEAR_PROBE_STEP)%ARR_SIZE;
        count+=1;
    }
    tblPtr[hashKey]=c;
} // end add

int lookUp(int c, int*& tblPtr){
    int hashKey=Hash(c);
    int count=0;
    while (tblPtr[hashKey]!=c && count<=10){
        hashKey=(hashKey+LINEAR_PROBE_STEP)%ARR_SIZE;
        count+=1;
    } // end while
    if (tblPtr[hashKey]==c){
        return hashKey;
    }
    else{ // not found
        return -1;
    }
    
} // end lookUp

int main (){
    int* tblPtr=NULL;
    initTable(tblPtr);
    add(112,tblPtr);
	cout<<"112 is added to table"<<endl;
	cout<<" 112 is supposed to be on index "<<Hash(112)<<endl;
    add(31, tblPtr);
	cout<<"31 is added to table"<<endl;
	cout<<" 31 is supposed to be on index "<<Hash(31)<<endl;
	cout<<"But it conflicts with 112's address"<<endl;
	cout<<"31 is moved to index "<<Hash(31)+LINEAR_PROBE_STEP<<endl;
	cout<<endl<<"Now look up the value"<<endl; 
    cout<<"112 is at index "<<lookUp(112,tblPtr)<<endl;
    cout<<"100 is at index "<<lookUp(100,tblPtr)<<" which is not found"<<endl;
    cout<<"31 is at index "<<lookUp(31,tblPtr)<<endl;
	delTable(tblPtr);

	cout << "Please enter return key to exit...";
	string dummy;
	getline(cin, dummy);
	return 0;
    return 0;
}// end main

/***********************************SAMPLE OUTPUT**********************************************
112 is added to table
 112 is supposed to be on index 4
31 is added to table
 31 is supposed to be on index 4
But it conflicts with 112's address
31 is moved to 9 index

Now look up the value
112 is at index 4
100 is at index -1 which is not found
31 is at index 9
Press any key to continue . . .



***********************************END************************************************************/