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

    return 0;
}
