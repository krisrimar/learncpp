#include <iostream>
#include <string>


class Employee
{
public:
    std::string m_name;
    int m_id;
    double m_wage;

    // Print employee information to the screen
    void print()
    {
        std::cout << "Name: " << m_name <<
                "  Id: " << m_id <<
                "  Wage: $" << m_wage << '\n';
    }
};

class Point3d
{
  double m_x;
  double m_y;
  double m_z;

  public:
    void setValues(double x, double y, double z)
    {
      m_x = x;
      m_y = y;
      m_z = z;
    }

    void print()
    {
      std::cout << "<" << m_x << ", " << m_y << ", " << m_z << ">" << std::endl;
    }

};

class Stack
{
  int numbers[10];
  int stackLen = 0;

  public:
    void reset()
    {
      for (int index = 0; index < stackLen; ++index)
      {
        numbers[index] = 0;
      }
      stackLen = 0;
    }

    bool push(int number)
    {
      if(stackLen < 10)
        ++stackLen;
      else
        return false;
      numbers[stackLen - 1] = number;
      return true;
    }

    int pop()
    {
      if(stackLen < 1)
      {
        std::cout << "There's nothing to pop :(" << std::endl;
        return 0;
      }
      --stackLen;
      int returnValue = numbers[stackLen];
      numbers[stackLen] = 0;
      return returnValue;
    }

    void print()
    {
      std::cout << "( ";
      for(int index = 0; index < stackLen; ++index)
      {
        std::cout << numbers[index] << " ";
      }
      std::cout << ")" << std::endl;
    }
};

int main()
{
    // Declare two employees
    Employee alex { "Alex", 1, 25.00 };
    Employee joe { "Joe", 2, 22.25 };

    // Print out the employee information
    alex.print();
    joe.print();

    Point3d point;
    point.setValues(1.0,2.0,3.0);
    point.print();

    Stack stack;
  	stack.reset();

  	stack.print();

  	stack.push(5);
  	stack.push(3);
  	stack.push(8);
  	stack.print();

  	stack.pop();
  	stack.print();

  	stack.pop();
  	stack.pop();

  	stack.print();

  	return 0;
}
