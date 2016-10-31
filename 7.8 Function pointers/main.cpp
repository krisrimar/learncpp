#include <iostream>

using namespace std;

int getNumber()
{
  cout << "Enter number: ";
  int number;
  cin >> number;
  return number;
}

char getOperator()
{
  char mathOperator;
  do
  {
    cout << "Enter operator: ";
    cin >> mathOperator;
  } while(mathOperator != '+' && mathOperator != '-' && mathOperator != '/' && mathOperator != '*');

  return mathOperator;
}

int main()
{
  int number1       = getNumber();
  char mathOperator = getOperator();
  int number2       = getNumber();

  cout << number1 << " " << mathOperator << " " << number2;
  cout << endl;

  return 0;
}
