#include <iostream>
#include <string>

class Employee
{
  private:
    std::string m_name;
    int m_age;
    float m_salary;

  public:
    Employee()
    {
      m_name = "Undefined";
      m_age = 0;
      m_salary = 0.0;
    }

    std::string getName() { return m_name; }
    int getAge()          { return m_age; }
    float getSalary()     { return m_salary; }

    void setName(std::string name) { m_name = name; }
};

int main()
{

  Employee employee1;

  std::cout << employee1.getName() << std::endl;

  employee1.setName("Kris");

  std::cout << employee1.getName() << std::endl;

  return 0;
}
