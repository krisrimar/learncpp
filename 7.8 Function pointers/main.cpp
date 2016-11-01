#include <iostream>

using namespace std;

//a typedef for a function that takes 2 ints as parameters and returns an int
typedef int (*arithmeticFcn) (int, int);

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

//takes an arithmetic operator as a parameter and returns a pointer to a function
arithmeticFcn getArithmeticFunction(char mathOperator)
{
  switch (mathOperator)
  {
    default:
    case '+': return add;
    case '-': return subtract;
    case '/': return divide;
    case '*': return multiply;
  }
}

int main()
{
  int number1       = getNumber();
  char mathOperator = getOperator();
  int number2       = getNumber();

  //create a variable of type int functionName(int, int) and assign it the value that the getArithmeticFunction will return (which will return a pointer to a function)
  arithmeticFcn fnc = getArithmeticFunction(mathOperator);

  cout << number1 << " " << mathOperator << " " << number2 << " = " << fnc(number1, number2);
  cout << endl;

  return 0;
}
