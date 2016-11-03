#include <iostream>
#include <string>

class Employee
{
  private:
    std::string m_name;
    int m_age;
    float m_salary;

  public:
    Employee(std::string name = "Undefined", int age = 0, float salary = 0.0)
    {
      m_name = name;
      m_age = age;
      m_salary = salary;
    }

    std::string getName() { return m_name; }
    int getAge()          { return m_age; }
    float getSalary()     { return m_salary; }

    void setName(std::string name) { m_name = name; }
};

int main()
{

  Employee employee1;
  Employee employee2("John", 24, 2300.0);

  std::cout << employee1.getName() << std::endl;
  std::cout << employee2.getName() << std::endl;

  employee1.setName("Kris");

  std::cout << employee1.getName() << std::endl;

  return 0;
}
