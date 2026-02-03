// ----------------------------------------
// Search algorithms on sorted values stored in an array
// ----------------------------------------

#include <iostream>
using namespace std;

// Search for a key among A[0]~A[size-1] 
// Return the index of the key if it is found; Return -1 if the key is not found
// Sequential search
int sequentialSearch(int A[], int size, int key)
{
	for (int i=0; i<size; i++)
	{
		if (A[i] == key)	return i;
	}

	return -1;		// key not found
}

// Search for a key among A[0]~A[size-1] 
// Return the index of the key if it is found; Return -1 if the key is not found
// Binary search
int binarySearch(int A[], int size, int key)
{
	// Your codes goes here
}

int main()
{
	// Read array elements that are entered in "non-decreasing" order
	
 	cout << endl << "Enter non-negative integers (-1 to stop) in non-decreasing order: " << endl;
	int numbers[20];		// array containing at most 20 elements; When out of bound, may temporarily seems working fine but could produce unpredictible errors
	
	int i = 0;
	int x;
    while (true)
    {
        cin >> x;
        if (x < 0)    break;

		numbers[i] = x;
		i ++;
    }

	// Search for a key entered by the user

	cout << endl << "Enter the search key to search: " << endl;
	int key; 
	cin >> key;
	
	cout << endl;

	int idx;		// index of the key in the array if found; -1 if the key not found
	
	cout << "Sequential search: " << endl;
	idx = sequentialSearch(numbers, i, key);
	if (idx < 0)
		cout << "Not found!" << endl;
	else
		cout << "Found at index " << idx << endl;

	cout << endl;

	cout << "Binary search: " << endl;
	idx = binarySearch(numbers, i, key);
	if (idx < 0)
		cout << "Not found!" << endl;
	else
		cout << "Found at index " << idx << endl;

	return 0;
}