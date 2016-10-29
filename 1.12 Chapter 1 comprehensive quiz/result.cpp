#include <iostream>
 
using namespace std;

int readNumber()
{
    cout << "Enter a number: ";
    int x;
    cin >> x;
    return x;
}
 
void writeAnswer(int x)
{
    cout << "The answer is " << x << endl;
}