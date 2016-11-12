#include <iostream>
#include <string>

class Person
{
  private:
    std::string mName;
    int mAge;

  public:
    Person(std::string name = "", int age = 0) : mAge(age), mName(name) {}

    std::string getName() const { return mName; }
    int getAge() const { return mAge; }
};

class BaseballPlayer : public Person
{
  private:
    double mBattingAverage;
    int mHomeRuns;

  public:
    BaseballPlayer(double battingAverage = 0.0, int homeRuns = 0, std::string name = "", int age = 0) : Person(name, age), mBattingAverage(battingAverage), mHomeRuns(homeRuns) {}

};

int main()
{
  BaseballPlayer joe(3.4, 4, "Joe", 43);

  std::cout << "The baseball player's name is " << joe.getName() << " his age is " << joe.getAge() << '\n';

  return 0;
}
