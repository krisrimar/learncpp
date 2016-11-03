#include <iostream>
#include <string>

class Employee
{
  private:
    std::string m_name;
    int m_age;
    float m_salary;

  public:
    Employee(std::string name, int age, float salary) : m_name {name}, m_age {age}, m_salary {salary} {}

    Employee() : Employee("Undefined", 0, 0.0) {}
    Employee(std::string name) : Employee(name, 0, 0.0) {}
    Employee(int age) : Employee("Undefined", age, 0.0) {}
    Employee(float salary) : Employee("Undefined", 0, salary) {}

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
