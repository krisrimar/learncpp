#include <iostream>
#include <string>

class Employee
{
  private:
    static int g_ID; //keeps track of all of the user IDs
    int m_ID;
    std::string m_name  = "No name";
    int m_age           = 0;
    float m_salary      = 0.0;
  public:
    Employee() : m_ID{g_ID++} {}
    Employee(std::string name, int age, float salary) : m_name{name}, m_age{age}, m_salary{salary}, m_ID{g_ID} {}

    int getID() { return m_ID; }

    std::string getName() const { return m_name; }
};

int Employee::g_ID = 1;

int main()
{
  Employee employee1;
  Employee employee2;
  Employee employee3;
  Employee employee4("John", 34, 344.0);
  std::cout << employee1.getName() << '\n';
  std::cout << employee1.getID() << '\n';
  std::cout << employee2.getID() << '\n';
  std::cout << employee3.getID() << '\n';
  std::cout << employee4.getName() << " " << employee4.getID() << '\n';
  return 0;
}
