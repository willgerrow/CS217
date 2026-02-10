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
    for (int i = 0; i < n-1; i ++)        
    {   
        // consider sublist a[i] ~ a[n-1]:
        // find the smallest in the sublist and then swap it with a[i]
        int idxMin = i;                     // idxMin: index of the minimum element in the sublist
        for (int j = i + 1; j < n; j ++)
        {
            if (A[j] < A[idxMin])           // a smaller element, a[j], is found
                idxMin = j;
        }
        
        // swap a[i] with a[idxMin]
        int t = A[i];
        A[i] = A[idxMin];
        A[idxMin] = t;
    }
}

/**
 * 
 * Use selection sort algorithm to sort elements a[left] ~ a[n-1] in non-decreasing order
 * Recursive approach 
 */
void MyArray::selectionSortRecursion(int left)
{
    // your code goes here
    // base case
    if (left >= n-1) // at most 1 element in current sublist
        return;

    // recursive case: // current sublist contains more than 1 element
    // 1. Scanning: A[left] to A[n-1] to find smallest element
    int idxMin = left; // initial guess
    for (int i = left + 1; i <= n-1; i++){
        if (A[i] < A[idxMin]) // a smaller element has been found
            idxMin = i;
    }

    // 2. swap smallest with beginning element of current sublist
    int t = A[left];
    A[left] = A[idxMin];
    A[idxMin] = t;

    // 3. sort A[left+1] ~ A[n-1]
    selectionSortRecursion(left+1);
}

/**
 * 
 * Use bubble sort algorithm to sort elements a[0] ~ a[n-1] in non-decreasing order
 * Iterative approach
 */
void MyArray::bubbleSort()
{
    bool swapped = false;                // false: no swap happened during the current round
        
    for (int i = n - 1; i > 1; i --)             
    {   
        // move the largest among a[0] ~ a[i] into a[i] by swapping between neighbors if needed
        for (int j = 0; j < i; j++)         // swap A[j] and A[j+1], if necessary
        {
            if (A[j] > A[j + 1])
            {
                int t = A[j];
                A[j] = A[j + 1];
                A[j + 1] = t;
                swapped = true;
            }
        }
        
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
void MyArray::bubbleSortRecursion(int right)
{
    // your code goes here
    // base case: sublist currently contains at most 1 element
    if (right <= 0)
        return;
    
    // recursive case: current sublist contains at least 2 elements
    bool swapped = false;

    // 1. compare neighbors and do swaps if needed
    for (int i = 0; i < right; i++){
        if (A[i] > A[i+1]){
            int t = A[i];
            A[i] = A[i+1];
            A[i+1] = t;
            swapped = true;
        }
    }
    if (!swapped) // list had no swaps; already sorted
        return;

    // 2. sort A[0] to A[right-1]
    bubbleSortRecursion(right-1);
}

/**
 * 
 * Use insertion sort algorithm to sort elements a[0] ~ a[n-1] into non-decreasing order
 * Iterative approach
 */
void MyArray::insertionSort()
{
    for (int i=1; i < n; i++)           
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
        A[j + 1] = t;
    }
}

/**
 * 
 * Use insertion sort algorithm to sort elements a[0] ~ a[right] into non-decreasing order
 * Recursive approach
 */
void MyArray::insertionSortRecursion(int right)
{
    // your code goes here
    // base case: sublist contains at most 1 element
    if (right <= 0)
        return;

    // recursive case: sublist contains at least 2 elements
    // 1. sort A[0] to A[right-1]
    insertionSortRecursion(right-1);

    // 2. insert A[right] into sorted sublist A[0] to A[right-1]
    int t = A[right];
    int i;
    for (i = right-1; i >= 0; i--){
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
            selectionSortRecursion(0);
            break;
        case 2:
            // bubbleSort();
            bubbleSortRecursion(n-1);
            break;
        case 3:
            // insertionSort();
            insertionSortRecursion(n-1);
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