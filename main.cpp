#include <iostream>
#include <string>

class Person
{
  public:
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
    BaseballPlayer(double battingAverage = 0.0, int homeRuns = 0) : mBattingAverage(battingAverage), mHomeRuns(homeRuns) {}

};

int main()
{
  BaseballPlayer joe;

  joe.mName = "Joe";

  std::cout << "The baseball player's name is " << joe.getName() << '\n';

  return 0;
}
