/*******************************************************************************************************************************************************************
* Description: This C++ program implement a Build a binary search tree,
* using links (not an array) for 15 records. The data in these records will hold names and their associated weights. 
* Read the data from the screen.
********************************************************************************************************************************************************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

// class treeNode
class treeNode
{
public:
// each node will
  string name; // hold name string
  int weight; // hold weight as int
  treeNode *left, *right;// have left and right pointer

  // constructor
  treeNode()
  {
   left = right = NULL;
  } // end constructor

  // constructor with parameter
  treeNode(string n, int w, treeNode *l = NULL, treeNode *r = NULL)
  {
    this->name=n; // initialize name
    this->weight=w; // initialize weight
    left = l; // initialize the left sub tree
    right = r; // initialize the right sub tree
  } // end constructor with parameter
};
// end class treeNode

// bianrySearchTree class
class binarySearchTree
{
	
public:	
	// root pointer
  treeNode *root;

  // constructor
  binarySearchTree()
  {
	  // set root to NULL
   root = NULL;
  } // end constructor

  // addNode
  bool addNode(string n, int w)
  {
    treeNode *newNode = new treeNode(n, w);			// our  new node
    if (root == NULL)									// check for an empty root
    { // if root is null
     root = newNode; // point root to the new generated node
     return true;
    }
    treeNode *temp = root;							// create a temp node to traverse the list
    while(true)
    {
      if (n < temp->name)
	{						// check to see if we will traverse to the left
	  if (temp->left == NULL)					// check to see if we have found newNode's position
	    { // if can be insert to left subtree
	      temp->left = newNode;
	      break;
	    }
	  else									// move to subtree
	    temp = temp->left;
	} // end if
       else if (n > temp->name)	
	 {				// check to see if we will traverse to the right
	   if (temp->right == NULL)					// check to see if we have found newNode's position
	     {
	       temp->right = newNode;
	       break;
	     }
	   else									// move to subtree
	     temp = temp->right;
	 }// end else if
       else if (n == temp->name)
	 {
	   return false; // no dupes
	 }				// For this implementation, we will not allow duplicates
       
    } // end while
    return true;
  } // end addNode

  

  // inorderTraversal 
	void inorderTraversal(treeNode *temp)
	{
		if (temp != 0)
		{
			inorderTraversal(temp->left);			// traverse left subtree
			cout<<temp->name << " ";				// evaluate (print) current node
			inorderTraversal(temp->right);			// traverse right subtree
		}
	} // end inorderTraversal

	// preorderTraversal
	void preorderTraversal(treeNode *temp)
	{
		if (temp != 0)
		{
			cout << temp->name<< " ";				// evaluate (print) current node
			preorderTraversal(temp->left);			// traverse left subtree
			preorderTraversal(temp->right);			// traverse right subtree
		}
	} // end preorderTraversal


	//postorderTraveral
	void postorderTraversal(treeNode *temp)
	{
		if (temp != 0)
		{
			postorderTraversal(temp->left);			// traverse left subtree
			postorderTraversal(temp->right);			// traverse right subtree
			cout << temp->name << " ";				// evaluate (print) current node
		}
	} // end postorderTraversal
	
}; // end class binarySearchTree


// maxDepth
int maxDepth(treeNode* node)
{
	if (node == NULL)
	{ // if nothing, depth is 0
		return 0;
	}
        
	else
	{
		/* compute the depth of each subtree */
		int lDepth = maxDepth(node->left);
		int rDepth = maxDepth(node->right);

		/* use the larger one */
		if (lDepth > rDepth)
		{
			return(lDepth + 1);
		}

		else
		{
			return(rDepth + 1);
		}
	}
} //maxDepth

//getLeafCount
int getLeafCount(treeNode* node)
{
	if (node == NULL)
	{
		return 0; // if nothing, there's no leaf
	}
  
  if(node->left == NULL && node->right==NULL)  
    { // a leaf is detected
    cout<<node->name<<endl;
    return 1;           
    }
  else
	{
	  return getLeafCount(node->left) +
		  getLeafCount(node->right); // return the total leaf from left subtree and right subtree
	}
         
} // end getLeafCount

// search for a node
bool search(string n, treeNode* root)
{
  treeNode *temp = root;

  while (temp != NULL)
  {
	  if (temp->name == n)
	  { // found
		  cout << temp->name << " " << temp->weight << endl;
		  break;
	  }

	  if (n > temp->name)
	  { // greater than, go to right subtree
		  temp = temp->right;
	  }

	  else
	  { // less than go to left subtree
		  temp = temp->left;
	  }
  }

  if (temp == NULL)
  { // if traverse whole list and can't find name
	  return false;
  }
        

  if (temp->name == n)
  { // if name is found
	  return true;
  }
        

   
}// end search

//maxWeight
void maxWeight(treeNode* node, int& max)
{
  if (node==NULL)
    {
      // do nothing
    }
  else 
    {
      if (node->weight>=max)
		{ // a new max found
		 max=node->weight;
		}
		maxWeight(node->left, max); // compare left subtree with new max
		maxWeight(node->right,max); // compare right subtree with new max

    }

}// end maxWeight

//alphaFirst
void alphaFirst(treeNode* node, string& alpha1st)
{
  if (node==NULL)
    {
      // do nothing
    }

  else
    {
      if (node->name<=alpha1st)
	{ // if name is more alphabetically prior
	  alpha1st=node->name;
	}
	  // look for left and right subtree to see if there's stil more prior alphabetical node
      alphaFirst(node->left, alpha1st);
      alphaFirst(node->right,alpha1st);
    }  
}// end alphaFirst



int main (void)
{
	//
	// Demonstrating addNode method
	binarySearchTree bst;
	string name;
	string weightS;
	int weight;

	for (int i = 0; i < 15; i++)
	{

		cout << "Please enter your name: ";
		getline(cin, name);
		cout << "Please enter your weight: ";
		getline(cin, weightS);
		weight = atoi(weightS.c_str());
		bst.addNode(name, weight);		
		cout << endl;
	}
	cout << "preOrder traversal with name:" << endl;
	bst.preorderTraversal(bst.root);
	cout << endl;
	cout << "inOrder traversal with name:" << endl;
	bst.inorderTraversal(bst.root) ;
	cout << endl;
	cout << "postOrder traversal with name:" << endl;
	bst.postorderTraversal(bst.root);
	cout<< endl;

	cout << "the height of the tree is :" << endl;
	cout << maxDepth(bst.root)-1 << endl;

	cout << "there are these many leaves in the tree:" << endl;
	cout << getLeafCount(bst.root) << endl;
	
	cout << "Searching for Bob in the tree" << endl;
	bool find;
	find = search("Bob", bst.root);
	cout << "found or not? " <<( (find == 1) ? "Found" : "Not Found" )<< endl;

	cout << "Searchng for Z in the tree" << endl;
	find=search("Z", bst.root);
	cout << "found or not? " << ((find == 1) ? "Found" : "Not Found") << endl;

	

	int max=-1;
	cout << "The max weight of the group is" << endl;
	maxWeight(bst.root, max);
	cout<<max<<endl;

	string alpha="~"; // ASCII #126, which is greater than any alphabeticall name starting A-Z (a-z)
	alphaFirst(bst.root, alpha);
	cout << "The first alphabetical name node is" << endl;
	cout<<alpha<<endl;
	


	cout << "Please enter return key to exit...";
	string dummy;
	getline(cin, dummy);
	return 0;
}// end main

/***************************Sample output*********************
Please enter your name: Jim
Please enter your weight: 150

Please enter your name: Tom
Please enter your weight: 212

Please enter your name: Michael
Please enter your weight: 174

Please enter your name: Abe
Please enter your weight: 199

Please enter your name: Richard
Please enter your weight: 200

Please enter your name: April
Please enter your weight: 117

Please enter your name: Claire
Please enter your weight: 124

Please enter your name: Bobby
Please enter your weight: 109

Please enter your name: Bob
Please enter your weight: 156

Please enter your name: Kevin
Please enter your weight: 145

Please enter your name: Jason
Please enter your weight: 182

Please enter your name: Brian
Please enter your weight: 150

Please enter your name: Chris
Please enter your weight: 175

Please enter your name: Steven
Please enter your weight: 164

Please enter your name: Annabelle
Please enter your weight: 99

preOrder traversal with name:
Jim Abe April Annabelle Claire Bobby Bob Brian Chris Jason Tom Michael Kevin Ric
hard Steven
inOrder traversal with name:
Abe Annabelle April Bob Bobby Brian Chris Claire Jason Jim Kevin Michael Richard
Steven Tom
postOrder traversal with name:
Annabelle Bob Chris Brian Bobby Jason Claire April Abe Kevin Steven Richard Mich
ael Tom Jim
the height of the tree is :
6
there are these many leaves in the tree:
Annabelle
Bob
Chris
Jason
Kevin
Steven
6
Searching for Bob in the tree
Bob 156
found or not? Found
Searchng for Z in the tree
found or not? Not Found
The max weight of the group is
212
The first alphabetical name node is
Abe
Please enter return key to exit...
***********************************END***************************/