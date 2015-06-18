/*******************************************************************************************************************************************************************
 * Description: This C++ program implement Stack based on array. It will set an array of MaxSize=10 (MaxSize is a constant member). 
 * It will have a member "Count" to indicate how many items are on the stack.
 * It will implement Push, Pop, and IsEmpty method. If the stack is full when trying to push element in, it will print an error. 
 * if the stack is empty when trying to pop element, it will print an error. 
 *************************************************************************************************************************************************************** */

#include<iostream> // to use cout and cin
#include<string>
using namespace std; 

/******************************** start of Stack implemented based on array*******************************************/

// class arrayBasedStack  declaration
template<typename T>
class arrayBasedStack 
{

public:
  arrayBasedStack(); // constructor
  ~arrayBasedStack();// destructor
  void Push(T);// Push to stack
  T Pop(); // Pop from stack
  bool IsEmpty(); // check if stack IsEmpty

private:
  static const int MaxSize; // MaxSize is set to 10 in implementation
  int* myStack;   // the pointer that hold the address of the array/stack
  int count;   // total elements in stack
  int top;    // top of the stack

};

// implementations of the arrayBasedStack

// initialize constant number MaxSize to 10
template<typename T>
const int arrayBasedStack<T>::MaxSize=10;


// implementation of constructor
template<typename T>
arrayBasedStack<T>::arrayBasedStack()
{
  top=-1; // top of stack
  count=top+1;
  myStack=new T[MaxSize]; // create and initialize the array used as a stack

}// end constructor


// implementation of destructor
template<typename T>
arrayBasedStack<T>::~arrayBasedStack()
{
  delete[] myStack; // delete myStack, the array that holds data for the stack
}// end destructor


// implementation of Push method
template<typename T>
void arrayBasedStack<T>::Push(T c)
{
  // Precondition: The stack has less than 10 elements before executing the push method
  // Post-condition: If the stack is not full (has less than 10 elements), it will push the new element to stack
  // Error codition: if the stack is full, it will print out error message 
  if(count>=10)
    {
      cout<<"Error: Stack is full. Cannot push more  value"<<endl;
    }// if stack is full when trying to push element in, an stack is full error is emitted
  else
    { // else, if stack is not full
      myStack[++top]=c; //top of stack is incremented, and a new element is positioned in the array where the index of "top" is 
      count=top+1;
    } // end else

}// end Push method



// implementation of Pop method
template<typename T>
T arrayBasedStack<T>::Pop()
{
  // Precondition: the stack has more than 0 elements before executing the pop method
  // Post-condition: if the stack is not empty, it will pop the top of the stack element off and return it
  // Error condition: if the stack is empty, it will print out error message
  if (count<=0)
    {// if stack is empty
      cout<<"Error: Stack is empty. Cannot pop more  value"<<endl;
    }// end if

  else
   {
     top--; // move top of the stack down as pointing to the 2nd top element
     count=top+1;
     return myStack[top+1]; // the 1st top element is returned, or popped off
   }// end else

}// end Pop method


// implementation of IsEmpty method
template<typename T>
bool arrayBasedStack<T>::IsEmpty()
{
  //Precondition: the stack is established
  //Post-condition: if stack has no element, it return true; else, it return false
  if (count==0)
    return true;
  else
    return false;

} // end IsEmpty

/**************************************End of Stack implemented based on array***************************************************************************************/


/************************************ main function******************************************************************************************************************/
int main()

{
  arrayBasedStack<int>* s=new arrayBasedStack<int>(); // initialize a new stack of int type called s
  s->Push(1); // push element 1 in the stack
  cout<<"after 1 is pushed into stack, the stack is empty(1) or not empty(0)? "<<s->IsEmpty()<<endl<<endl; // check if stack is empty, it's not because "1" is in
  cout<<"now popping of the top of stack. value popped of is: "<<s->Pop()<<endl<<endl; // pop off the only element in stack and display
  cout<<"now stack is empty."<<endl<<endl;
  s->Pop(); // pop out more value when stack is empty will give out a message
  cout<<"The stack is empty, please don't pop off more element."<<endl<<endl;; 
  cout<<"to verify if the stack is empty, check if it's empty(1), or nt empty(0)? "<<s->IsEmpty()<<endl<<endl; // check if stack is empty. yes it is. 

  cout<<"Now filling the stack with elements"<<endl;
  for (int i=0; i<10; i++)
    {
      s->Push(i); // push 0, 1, 2, ....9 into the stack to fill the stack

    }// end for
  cout<<"Now the stack is full"<<endl<<endl;
  s->Push(12); // attempt to push more value to stack when its full, this will print out an error message
  cout<<"Told you the stack is full, please don't push more element in"<<endl<<endl;
  
  cout<<"Now popping out all the element in the array"<<endl;
  while (!s->IsEmpty())
    {// pop out all the element and display them 

      cout<<s->Pop()<<endl;
    } // end while
  cout << "Please enter return key to exit...";
  string dummy;
  getline(cin, dummy);
  return 0;
}// end main


/****************************************Expected Output*************************************************************************************************************
after 1 is pushed into stack, the stack is empty(1) or not empty(0)? 0

now popping of the top of stack. value popped of is: 1

now stack is empty.

Error: Stack is empty. Cannot pop more  value
The stack is empty, please don't pop off more element.

to verify if the stack is empty, check if it's empty(1), or nt empty(0)? 1

Now filling the stack with elements
Now the stack is full

Error: Stack is full. Cannot push more  value
Told you the stack is full, please don't push more element in

Now popping out all the element in the array
9
8
7
6
5
4
3
2
1
0


**************************************************************END OF DOCUMENT***************************************************************************************/
