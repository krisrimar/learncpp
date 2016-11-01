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
  char op;
  do
  {
    cout << "Enter operator: ";
    cin >> op;
  }
  while(op != '+' && op != '-' && op != '/' && op != '*');

  return op;
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

//a typedef for a function that takes 2 ints as parameters and returns an int
typedef int (*arithmeticFcn) (int, int);

struct arithmeticStruct
{
  char op;
  arithmeticFcn fnc;
};

static arithmeticStruct arithmeticArray[] = {{'+',add},{'-',subtract},{'*',multiply},{'/',divide}};

//takes an arithmetic operator as a parameter and returns a pointer to a function
arithmeticFcn getArithmeticFunction(char op)
{
  for(auto &element : arithmeticArray)
  {
    if(element.op == op)
      return element.fnc;
  }
  return add;
}

int main()
{
  int x     = getNumber();
  char op   = getOperator();
  int y     = getNumber();

  //create a variable of type int functionName(int, int) and assign it the value that the getArithmeticFunction will return (which will return a pointer to a function)
  arithmeticFcn fnc = getArithmeticFunction(op);

  cout << x << " " << op << " " << y << " = " << fnc(x, y);
  cout << endl;

  return 0;
}
