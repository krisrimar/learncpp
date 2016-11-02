#include <iostream>
#include <cassert>

using namespace std;

int getNumber(int number)
{
  assert(number >= 5 && number <= 10);

  return number;
}

int main()
{
  cout << "Enter a number between 5 and 10: ";
  int number;
  cin >> number;
  cout << "You entered " << getNumber(number) << endl;
  return 0;
}
