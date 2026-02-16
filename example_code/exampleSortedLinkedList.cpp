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
}

// traverse the list and display the key and data of each node
void SortedLinkedList::traverse()
{
	// your code goes here
	Node* current = head;
	while(current != nullptr){
		cout << current->key << "|" << current->data << endl; // access content of current
		current = current->next; // move to next node
	}
}

// insert a node (k,d) into the list
void SortedLinkedList::insertNode(int k, string d)
{
	// your code goes here       
}

// prompt the user the enter key and data of every node, and construct the list
void SortedLinkedList::build()                   
{
 	// your code goes here       
}

// return {previous, current}
// current: the location of the node with the matching key
// previous: the location of the node immediately before the current node
pair<Node*, Node*> SortedLinkedList::search(int k)
{
	// your code goes here       

	return {nullptr, nullptr};
}


// remove the node whose key is equal to k
// return: true -- successful deletion
//         false -- item not found
bool SortedLinkedList::deleteNode(int k)
{
	// your code goes here       
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