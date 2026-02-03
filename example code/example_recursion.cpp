// ----------------------------------------
// Recursive function examples
// ----------------------------------------

#include <iostream>
using namespace std;

// x^n
double power(double x, int n)
{
    return 0
}

// 1+2+3+...+ n
int series(int n)
{
	return 0;
}

// Practice
// write a recursive function multiply(double a, int b) to multiple a with b, where b is a non-negative integer
double multiply(double a, int b)
{
	return 0;
}

// Print a triangle with n left-aligned rows
// e.g., n=4
// ****
// ***
// **
// *
void printTriangle1(int n)
{
    if (n>0)
    {
        for (int i=0; i<n; i++) 
            cout << "*";
        
		cout << endl;
		
		printTriangle1(n-1);
    }
}

// Practice:
// Print a triangle with n left-aligned rows
// e.g., n=4
// *
// **
// ***
// ****
void printTriangle2(int n)
{
    if (n>0)
    {
		printTriangle2(n-1);

        for (int i=0; i<n; i++) 
            cout << "*";
        
		cout << endl;		
    }
}

int fibonacci(int n)
{ 
	return 0;
}

// reverse elements in subarray A[i]~A[j]
void reverseArray(int A[], int i, int j)
{
	if (i>=j)
		return;

	int t = A[i];
	A[i] = A[j];
	A[j] = t;

	reverseArray(A, i+1, j-1);
}

// How many even numbers are there in A[0]~A[n-1]
int countEvenInArray(int A[], int n)
{
	return 0;
}

// Return the sum of all elements in subarray A[left]~A[right]
int sumArray(int A[], int left, int right)
{
	return 0;
}

// Return true if elements in subarray A[0]~A[n-1] are in non-decreasing order
int isSorted(int A[], int n)
{
	return 0;
}

// Search for a key in subarray A[left]~A[right] and return its index
int binarySearch(int A[], int left, int right, int key)
{
	return -1;
}

// Search for a key in subarray A[left]~A[right] and return its index
int linearSearch(int A[], int left, int right, int key)
{
	return 0;
}

int main()
{
	double x;
	int n;
	cout << "--> Compute x^n" << endl << "Enter x and n: ";
	cin >> x >> n;

	double result = power(x, n);
	cout << "power(" << x << ", " << n << ")=" << result << endl;
	cout << endl;

	cout << "--> Compute 1+2+3+...+n" << endl << "Enter a non-negative integer n: ";
	cin >> n;
	result = series(n);
	cout << "1+2+3+...+" << n << " = " << result << endl;
	cout << endl;

	cout << "--> Compute a*b" << endl << "Enter a and a non-negative integer b: ";
	double a; 
	int b;
	cin >> a >> b;
	result = multiply(a, b);
	cout << a << " * " << b << " = " << result << endl;
	cout << endl;

	cout << "--> Print trangles with n left-aligned rows" << endl << "Enter a non-negative integer n: ";
	cin >> n;
	printTriangle1(n);
	cout << endl;

	printTriangle2(n);
	cout << endl;

	cout << "--> Print the n-th Fibonacci number" << endl;
	cout << "Enter non-negative integer n: ";
	cin >> n;
	cout << n << "-th Fibonacci number: " << fibonacci(n) << endl;
	cout << endl;

	cout << "--> Reverse an array" << endl;
	int myArray[] = {10, 8, 7, 5, 3, 2};	
	// int myArray[] = {8, 7, 10, 2, 3, 5};		// unsorted array

	cout << "Reversed: ";
	reverseArray(myArray, 0, 5);
	for (int i=0; i<6; i++)
		cout << myArray[i] << " ";
	cout << endl << endl;

	cout << "--> How many elements are even in the array" << endl;
	cout << countEvenInArray(myArray, 6) << " elements are even" << endl;
	cout << endl;

	cout << "--> Sum of array elements" << endl;
	cout << "sum = " << sumArray(myArray, 0, 5) << endl;
	cout << endl;

	cout << "--> Searching for a key in the array" << endl;
	int key = 3, keyIdx;
	int sorted = isSorted(myArray, 6);
	if (sorted)
	{
		cout << "Array is sorted. Let's do binary search." << endl;
		keyIdx = binarySearch(myArray, 0, 5, key);
		cout << key << " is found at index " << keyIdx << endl;
	}
	else
	{
		cout << "Array is not sorted. Let's do linear search." << endl;
		keyIdx = linearSearch(myArray, 0, 5, key);
		cout << key << " is found at index " << keyIdx << endl;
	}
	cout << endl;


	return 0;
}