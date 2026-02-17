/*
	Linked lists (sorted)
*/

#include <iostream>
using namespace std;

class Node
{
public:
	int     key;    // key of the node
	string  data;   // other data in the node
	Node*   next;   // pointer to the next node in linked list
	
	Node(int k, string d);
};

Node::Node(int k, string d)     
{
	// your code goes here  
	key = k;
	data = d;
	next = nullptr; // not sure who successor will be yet; 
					// will find out later when inserting node into list
}

class SortedLinkedList		
{
private:
	Node* head;		// pointer to the first node in this linked list; tells where head is

public:
	SortedLinkedList();
	~SortedLinkedList();
	
	void traverse();
	pair<Node*, Node*> search(int);
	void insertNode(int, string);
	void build();						
	bool deleteNode(int);
};

// construct an empty list
SortedLinkedList::SortedLinkedList()
{
	// your code goes here  
	head = nullptr; // no node in list

}

// deconstruct the list 
SortedLinkedList::~SortedLinkedList()
{
	// your code goes here       
	Node* current = head;
	Node* next;

	while(current != nullptr) 
	{
		// traverse list and delete each current node
		next = current->next;
		delete current;

		current = next;
	}

}

// traverse the list and display the key and data of each node
void SortedLinkedList::traverse()
{
	// your code goes here
	Node* current = head;
	while(current != nullptr) // not the end of the list yet
	{
		cout << current->key << "|" << current->data << endl; // access content of current
		current = current->next; 							  // move to next node
	}
}

// insert a node (k,d) into the list
void SortedLinkedList::insertNode(int k, string d)
{
	// your code goes here
	Node* current = head; // pointer to first node
	Node* previous = nullptr;

	// while(current->key < k && current != nullptr)
	// ^^^wont work, cause if current->key is nullptr then it will crash the program
	while(current != nullptr && current->key < k) // finding spot where to put node
	{
		previous = current;
		current = current->next;
	}

	Node* newNode = new Node(k, d); // construct new node with key k and data d
	newNode->next = current;

	if(previous != nullptr) // new node will not become 1st node
		previous->next = newNode;
	else					// new node will become 1st node
		head = newNode;
}

// prompt the user the enter key and data of every node, and construct the list
void SortedLinkedList::build()                   
{
 	// your code goes here
	int k; 
	string d;
	cout << "Let's build a linked list." << endl;
	while(true) // use while loop to have user enter key and data
	{
		cout << "Enter an integer as a key (negative to stop) and data: ";
		cin >> k;
		if (k < 0)
			break;
		cin >> d;

		insertNode(k, d); // insert a new node for (k, d)
	}
}

// return {previous, current}
// current: the location of the node with the matching key
// previous: the location of the node immediately before the current node
pair<Node*, Node*> SortedLinkedList::search(int k)
{
	// your code goes here       
	Node* current = head;     // pointer to 1st node if it exists
	Node* previous = nullptr; // initialize 1st node to not have predecessor

	while(current != nullptr) // haven't reached end of the list yet; current node exists
	{
		if(current->key == k) // matching key has been found
			return {previous, current}; // return pair of values with this 
		// if no match, 
		// have to set previous to current, then current to next
		previous = current;
		current = current->next;	
		
	}

	return {nullptr, nullptr}; // key is not found, return nullptrs to indicate failed search
}


// remove the node whose key is equal to k
// return: true -- successful deletion
//         false -- item not found
bool SortedLinkedList::deleteNode(int k)
{
	// your code goes here 
	pair<Node*, Node*> pre_cur = search(k); // get previous and current from search function
	Node* previous = pre_cur.first; // predecessor = previous from search function
	Node* current = pre_cur.second; // target node = current from search function

	if (current == nullptr && previous == nullptr) 
		return false; // indicates failed deletion since key was not found

	if (previous != nullptr) // target node is not first node in linked list, since previous exists
		previous->next = current->next;
	else					 // target node we want to remove is the 1st node
		head = current->next;

	delete current;			// return the memory for the removed node
	return true;
}

int main()
{
	int key;

    SortedLinkedList myList;
	
	myList.build();
	myList.traverse();

	cout << "Let's try search() ... " << endl;
    while (true)
    {
        cout << "Enter a key (-1 to stop) to be searched for: " << endl;
        cin >> key;
        if (key < 0)    break;

        pair<Node*, Node*> pre_cur = myList.search(key);	
		Node* previous = pre_cur.first;
		Node* current = pre_cur.second;
		if (previous == nullptr && current == nullptr) 	// not found
			cout << "Key not found!" << endl;
        else
            cout << "found data: " << current->key << " | " << current->data << endl;

    }
	
	cout << "Let's try deleteNode() ... " << endl;
	while (true)
    {
        cout << "Enter a key (-1 to stop) to be deleted: " << endl;
        cin >> key;
        if (key < 0)    break;

		if (myList.deleteNode(key)) 	// found and deleted
		{
			cout << "Successful deletion" << endl;
			myList.traverse();
		}
        else
            cout << "Key not found. Failed deletion. " << endl;

    }

	return 0;
}