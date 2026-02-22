#include <iostream>
using namespace std;

class MyArray		
{
private:
	int* A;	    // pointer to an array for storing stack elements
    int size;   // size of the array 
	int n;      // number of elements that are currently in the array

public:
	MyArray(int s);
    ~MyArray();

    void read();
    void randGenerate();
    void display();

    void selectionSort();
    void selectionSortRecursion(int left);
    void bubbleSort();
    void bubbleSortRecursion(int right);
    void insertionSort();
    void insertionSortRecursion(int cur);
    
    void sort();
};

// Constructor: create an empty array with the specified size
MyArray::MyArray(int s)
{
    size = s;
    A = new int[size];
	n = 0;
}

MyArray::~MyArray()
{
    delete[] A;
}

void MyArray::read()
{
    int e;
    cout << "Enter elements (negative to end): " << endl;
    
    int i;
    for (i = 0; i < size; i++)        
    {
        cin >> e;  
        if (e >= 0)
            A[i] = e;                   // store a non-negative number into the array 
        else                        
            break;
    }
    n = i;                              // record the total number of elements that have been stored into the array
}

void MyArray::randGenerate()
{        
    n = rand() % (size + 1);            // random integer as the number of elements between 0 ~ size
    for (int i = 0; i < n; i++)
        A[i] = rand() % 15;             // random integer as value of an element: [0,14]
}

void MyArray::display()
{
    for(int i = 0; i < n; i++)
        cout << A[i] << " ";
        
    cout << endl;
}

/**
 * 
 * Use selection sort algorithm to sort elements a[0] ~ a[n-1] in non-decreasing order
 * Iterative approach
 */
void MyArray::selectionSort()
{
    for (int i = n-1; i >= 0; i--)        
    {   
        // consider sublist a[i] down to a[n]:
        // find the largest in the sublist and then swap it with last element in subarray (A[i])
        int idxMax = i;                     // idxMax: index of the maximum element in the sublist
        for (int j = i-1; j >= 0; j--)
        {
            if (A[j] > A[idxMax])           // a larger element, a[j], is found
                idxMax = j;
        }
        
        // swap a[i] with a[idxMax]
        int t = A[i];
        A[i] = A[idxMax];
        A[idxMax] = t;
    }
}

/**
 * 
 * Use selection sort algorithm to sort elements a[left] ~ a[n-1] in non-decreasing order
 * Recursive approach 
 */
void MyArray::selectionSortRecursion(int right)
{
   // base case
    if (right <= 1) // at most 1 element in current sublist
        return;

    // recursive case: current sublist contains more than 1 element
    // 1. Scanning: A[right] to A[0] to find largest element
    int idxMax = right; // initial guess
    for (int i = right - 1; i >= 0; i--){
        if (A[i] > A[idxMax]) // a larger element has been found
            idxMax = i;
    }
    // 2. swap largest with ending element of current sublist
    int t = A[right];
    A[right] = A[idxMax];
    A[idxMax] = t;
    // 3. sort A[left+1] ~ A[n-1]
    selectionSortRecursion(right-1);
}

/**
 * 
 * Use bubble sort algorithm to sort elements a[0] ~ a[n-1] in non-decreasing order
 * Iterative approach
 */
void MyArray::bubbleSort()
{
    bool swapped = false;                // false: no swap happened during the current round
        
    for (int i = 0; i < n; i++)             
    {   
        // move the smallest among a[n-1] ~ a[i] into a[i] by swapping between neighbors if needed
        for (int j = n-1; j > i; j--)         
        {
            if (A[j] < A[j-1]) // swap A[j] and A[j-1], if necessary
            {
                int t = A[j];
                A[j] = A[j-1];
                A[j-1] = t;
                swapped = true;
            }
        }
        this->display();
        
        if (!swapped)                       // no swap happened --> already sorted
            break;
        
        swapped = false;
    }
}

/**
 * 
 * Use bubble sort algorithm to sort elements a[0] ~ a[right] in non-decreasing order
 * Recursive approach
 */
void MyArray::bubbleSortRecursion(int left)
{
    // base case: sublist currently contains at most 1 element
    if (left >= n-1) // if left index is at the end of the list, finish recursion
        return;

    // recursive case: current sublist contains at least 2 elements
    bool swapped = false;
    // 1. compare neighbors and do swaps if needed
    for (int i = n-1; i > left; i--){ // iterate down the list from the end to the left index
        if (A[i] < A[i-1]){ // if the current element being looked at is less than element before it,
            int t = A[i];
            A[i] = A[i-1];
            A[i-1] = t; // swap current element with the one before it
            swapped = true;
        }
    }
    if (!swapped) // list had no swaps; already sorted
        return;

    // 2. sort A[left+1] to A[n-1]; 
    bubbleSortRecursion(left+1);
}

/**
 * 
 * Use insertion sort algorithm to sort elements a[0] ~ a[n-1] into non-decreasing order
 * Iterative approach
 */
void MyArray::insertionSort()
{
    for (int i=n-1; i>0; i--)           
    {   
        // insert a[i] into a[0] ~ a[i-1] so that a[0] ~ a[i] become sorted
        int t = A[i];
        int j;
        for (j = i - 1; j >= 0; j --)
        {
            if (t < A[j])
                A[j+1] = A[j];
            else
                break;
        }
        A[j - 1] = t;
    }
}

/**
 * 
 * Use insertion sort algorithm to sort elements a[0] ~ a[right] into non-decreasing order
 * Recursive approach
 */
void MyArray::insertionSortRecursion(int left)
{
    // base case: sublist contains at most 1 element
    if (left <= 0)
        return;

    // recursive case: sublist contains at least 2 elements
    // 1. sort A[left+1] to A[n-1]
    insertionSortRecursion(left+1);

    // 2. insert A[right] into sorted sublist A[0] to A[right-1]
    int t = A[left];
    int i;
    for (i = left+1; i <= n-1; i++){
        if (t < A[i])
            A[i+1] = A[i];
        else
            break;
    }
    A[i+1] = t;


}

void MyArray::sort()
{
    int sortOption;
    
    cout << "Select from:" << endl;
    cout << "1. Selection sort" << endl;
    cout << "2. Bubble sort" << endl;
    cout << "3. Insertion sort" << endl;
    cout << "0. Quit" <<endl;

    cin >> sortOption;
    switch (sortOption)
    {
        case 1:
            // selectionSort();
            selectionSortRecursion(n-1);
            break;
        case 2:
            //bubbleSort();
            bubbleSortRecursion(0);
            break;
        case 3:
            // insertionSort();
            insertionSortRecursion(0);
            break;
        case 0:
            break;
        default:
            cout << "Invalid sort option!" << endl;
    }
}

int main()
{
    MyArray arr(20);
    srand(time(0));                     // seed the random number generator

    int option;
    do
    {
        cout << "Select from:" << endl;
        cout << "1. Read Array" << endl;
        cout << "2. Generate Array" << endl;
        cout << "3. Print Array" << endl;
        cout << "4. Sort" << endl;
        cout << "0. Quit" << endl;

        cin >> option;
        switch (option)
        {
            case 1:
                arr.read();
                break;
            case 2:
                arr.randGenerate();
                break;
            case 3:
                arr.display();
                break;
            case 4:
                arr.sort();
                break;
            case 0:
                break;
            default:
                cout << "Invalid option!  Try again: " << endl;
        }
        
    } while (option != 0);

    return 0;
}