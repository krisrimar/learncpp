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
  }
  while(mathOperator != '+' && mathOperator != '-' && mathOperator != '/' && mathOperator != '*');

  return mathOperator;
}

int add(int x, int y)
{
  return x + y;
}

int subtract(int x, int y)
{
  return x - y;
}

int multiply(int x, int y)
{
  return x * y;
}

int divide(int x, int y)
{
  if(y == 0)
  {
    cout << "Can't divide by zero :(";
    return 0;
  }
  else
    return x / y;
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
