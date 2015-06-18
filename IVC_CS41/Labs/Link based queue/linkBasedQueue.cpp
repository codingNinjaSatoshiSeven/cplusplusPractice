/*******************************************************************************************************************************************************************
 * Description: This C++ program implement linked listed based queue
 ********************************************************************************************************************************************************************/


#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

// node class
class node
{
private:
  int value;
  node* next;
public:
  node(int c){
    value=c;
    next=NULL;
  } // end constructor

  ~node(){
    next=NULL;
  } // end destructor

  int& nodeValue(){
    return value;
  } // get/set method for setting node value

  node*& nodeNext(){
    return next;
  } // get/set  method for setting the next node it points to 

}; // end class node


// linked list Queue class
class linkBasedQueue
{
 
public:
  int Count; // # of node inside the queue
  node* Front;
  node* Back;

  linkBasedQueue(){
    Count=0;
    Front=NULL;
    Back=NULL;
  } // end constructor

 ~linkBasedQueue(){
    Count=0;
    Front=NULL;
    Back=NULL;
 } // end destructor

  bool isEmpty(){ 
    if (Count==0){ // if nothing in queue
      return true;
    }
    else{
      return false;
    }
  } // end isEmpty

  void Enqueue(node* a){
    if (isEmpty()){ // if nothing is in queue yet
      Front=a;
      Back=a;
    }
    else{ // if something is already in the queue
      Back->nodeNext()=a;
      Back=Back->nodeNext();
    }
    Count++; // increment the counter
  } // end Enqueue

  int Dequeue(){

    if (isEmpty()){ // if empty, emit error
      cout<<"Error, Queue is empty, cannot dequeue"<<endl;
      return -1;
    }
    else{ // if queue not empty
      int toReturn=Front->nodeValue();// get return value
      node* temp= Front; // node to delete
     
      if (Count==1)
	{ // if only 1 element left, queue will not have element when dequeued
	  // so set front to null
	  Front=NULL;
	}
      else{ // else, if more than 1 element

      Front=Front->nodeNext();
      }
      delete temp; // delete node to be dequeued
      Count--; // decrement count
      return toReturn;
    }
  } // end Dequeue


};// end class linkBasedQueue

// main function
int main()
{
  linkBasedQueue* ll=new linkBasedQueue();
  for (int i=0; i<10; i++)
    {
      ll->Enqueue(new node(i));
      cout<<i<<" is enqueued. Now the queue has "<<ll->Count<<" elements"<<endl;
    }
   for (int i=0; i<10; i++)
    {
      cout<<"Now dequeueing "<<ll->Dequeue()<<endl;
     
    }

   ll->Dequeue();
  
  return 0;
} // end main


/*******************SAMPLE OUTPUT***********************
0 is enqueued. Now the queue has 1 elements
1 is enqueued. Now the queue has 2 elements
2 is enqueued. Now the queue has 3 elements
3 is enqueued. Now the queue has 4 elements
4 is enqueued. Now the queue has 5 elements
5 is enqueued. Now the queue has 6 elements
6 is enqueued. Now the queue has 7 elements
7 is enqueued. Now the queue has 8 elements
8 is enqueued. Now the queue has 9 elements
9 is enqueued. Now the queue has 10 elements
Now dequeueing 0
Now dequeueing 1
Now dequeueing 2
Now dequeueing 3
Now dequeueing 4
Now dequeueing 5
Now dequeueing 6
Now dequeueing 7
Now dequeueing 8
Now dequeueing 9
Error, Queue is empty, cannot dequeue

*************************END*****************************/
