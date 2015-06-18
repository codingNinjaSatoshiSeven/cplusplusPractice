/************************************************************************************
* Irvine Valley College CS 41: Data Structure
* Instructor: A.Lane
* Assignment#: Lab4, arrayBasedQueue(C++)
* Name: Shengtao Li
* ID: 1015934
* Due Date: 10/05/2014
* Description: This C++ program will implement array based queue
**************************************************************************************************************************** */
#include<iostream>
#include<string>
using namespace std;
#define MAX_SIZE 5 //max queue size 
 
// Creating a class named Queue.
class arrayBasedQueue
{
 private:
  int arrayQ[MAX_SIZE];
  int front, back;
 public:
  // constructor
  arrayBasedQueue()
  {
    // set bot front and back to -1 to indicate empty queue.
    front = -1;
    back = -1;
  }// end constructor
 
  // To check whether queue is empty or not
  bool IsEmpty()
  {// the queue is empty only if the front and back are set to -1
   // the queue is not empty if front and back are equal, so this guarantee the boundary condition didn't happen 
    return (front == -1 && back == -1);
  } // end isEmpty
 
  // To check whether queue is full or not
  bool IsFull()
  {//if the back is looped back and coincide with front, then the queue is full
    return (back+1)%MAX_SIZE == front ? true : false;
  }// end isFull
 
  // Inserts an element in queue at rear end
  void Enqueue(int x)
  {
    cout<<"Enqueuing "<<x<<" \n";
    if(IsFull())
      { // if the queue is full, then cannot enqueue more element
	cout<<"Error: Queue is Full\n";
	return;
      }
    if (IsEmpty())
      { // if queue is empty, set the front and back so it can start putting element on array index 0
	front = back = 0;
      }
    else
      { // if queue is not empty, then back is moved 1 more further or loop back
	back = (back+1)%MAX_SIZE;
      }
    arrayQ[back] = x; // enqueue the element to the back location
  } // end Enqueue
 
  // Removes an element in Queue from front end.
  int Dequeue()
  {
    int Val;
    cout<<"Dequeuing \n";
    if(IsEmpty())
      { // if queue is empty
	cout<<"Queue is empty!!";
	throw string("Que is empty");
      } // end if
    else if(front == back )
      { // if queue has 1 element
	cout<<"The Last Element"<<endl;
	Val=arrayQ[front];
	back = front = -1;
	return Val;
      }// end if
    else
      { // if queue has many element
	// move the front to point to the new location
	Val=arrayQ[front];
	front = (front+1)%MAX_SIZE;
	return Val;
      }// end else
  } // end Dequeue
  //  Returns element at front of queue.
  int Front()
  {
    if(front == -1)
      {
	cout<<"Error: cannot return front from empty queue\n";
	throw string("cannot return front from empty queue");
      }
    return arrayQ[front];
  } // end Front
  /*
    Printing the elements in queue from front to rear.
    This function is only to test the code.
    This is not a standard function for Queue implementation.
  */
  void Print()
  {
    // Finding number of elements in queue
    int count = (back+MAX_SIZE-front)%MAX_SIZE + 1;
    cout<<"Queue : ";
    for(int i = 0; i <count; i++)
      {
	int index = (front+i) % MAX_SIZE; // Index of element while travesing circularly from front
	cout<<arrayQ[index]<<" ";
      }
    cout<<"\n\n";
  } // end Print
}; // end class arrayBasedQueue


// main function
int main()
{
 
  arrayBasedQueue Q; // creating an instance of Queue.
  Q.Enqueue(2); Q.Print();
  Q.Enqueue(4); Q.Print();
  Q.Enqueue(6); Q.Print();
  cout <<Q.Dequeue() <<endl;
  Q.Print();
  Q.Enqueue(8); Q.Print();
  Q.Enqueue(10); Q.Print();
  Q.Enqueue(12); Q.Print();
  cout << "Is the Queue full? " << (Q.IsFull() == 1 ? "True" : "False") << endl;
  cout << Q.Dequeue() <<endl;
  cout << Q.Dequeue() <<endl;
  cout << Q.Dequeue() <<endl;
  cout << Q.Dequeue() << endl;
  cout << Q.Dequeue() << endl;
  cout << "Is the Queue Empty? " << (Q.IsEmpty() == 1 ? "True" : "False") << endl;

  cout << "Please enter return key to exit...";
  string dummy;
  getline(cin, dummy);

  return 0;
}


/********************************Sample Output*************************************
Enqueuing 2
Queue : 2

Enqueuing 4
Queue : 2 4

Enqueuing 6
Queue : 2 4 6

Dequeuing
2
Queue : 4 6

Enqueuing 8
Queue : 4 6 8

Enqueuing 10
Queue : 4 6 8 10

Enqueuing 12
Queue : 4 6 8 10 12

Is the Queue full? True
Dequeuing
4
Dequeuing
6
Dequeuing
8
Dequeuing
10
Dequeuing
The Last Element
12
Is the Queue Empty? True
Press any key to continue . . .
***********************************************END*******************************/