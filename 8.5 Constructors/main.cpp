#include <iostream>
#include <string>

class Employee
{
  private:
    std::string m_name  = "Undefined";
    int m_age           = 0;
    float m_salary      = 0.0;

  public:
    //default constructor: must be included to have the others work as well (in case no parameters are passed)
    Employee() {}
    //constructor for string only (name)
    Employee(std::string name) : m_name {name} {}
    //constructor for int only (age)
    Employee(int age) : m_age {age} {}
    //constructor for float only (salary)
    Employee(float salary) : m_salary {salary} {}
    //constructor for all of the above
    Employee(std::string name, int age, float salary) : m_name {name}, m_age {age}, m_salary {salary} {}

    //note: we can add a constructor for age, salary || name, salary || age, name, but this would make this class very long

    std::string getName() { return m_name; }
    int getAge()          { return m_age; }
    float getSalary()     { return m_salary; }

    void setName(std::string name) { m_name = name; }
};

int main()
{

  Employee employee1;
  Employee employee2("John", 24, 2300.0);
  Employee employee3(34);

  std::cout << employee1.getName() << std::endl;
  std::cout << employee2.getName() << std::endl;
  std::cout << employee3.getAge() << std::endl;

  employee1.setName("Kris");

  std::cout << employee1.getName() << std::endl;

  return 0;
}
