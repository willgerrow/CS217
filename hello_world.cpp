
#include<iostream>
using namespace std;

int main(){
    int number;
    cout << "Hello world! My name is Will Gerrow :)" << endl;
    cout << "Please enter a number:";
    cin >> number;
    if (number%2 == 1)
        cout << "So you like odd numbers huh?";
    else
        cout << "Ah... so you're an even number guy!";

    cout << endl;
    cout << endl;
    return 0;
}