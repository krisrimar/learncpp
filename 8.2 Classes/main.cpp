#include <iostream>
#include <string>
#include <cassert>


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
  private:
    int m_numbers[10];
    int m_stackLen = 0;

  public:
    void reset()
    {
      for (int index = 0; index < stackLen; ++index)
        numbers[index] = 0;
      stackLen = 0;
    }

    bool push(int number)
    {
      if(stackLen == 10)
        return false;
      numbers[stackLen++] = number; //it's better to use stackLen++ here, as it first evaluets, and then is set to a new value
      return true;
    }

    int pop()
    {
      assert(stackLen > 0 && "There is nothing to pop");
      return stack[--stackLen];
    }

    void print()
    {
      std::cout << "( ";
      for(int index = 0; index < stackLen; ++index)
        std::cout << numbers[index] << " ";
      std::cout << ")\n";
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
