#include <iostream>
#include <string>

class Person
{
  public:
    std::string mName;
    int mAge;

  private:
    Person(std::string name = "", int age = 0) : mAge(age), mName(name) {}

    std::string getName() { return mName; }
    int getAge() { return mAge; }
};

class BaseballPlayer
{
  public:
    double mBattingAverage;
    int mHomeRuns;

  private:
    BaseballPlayer(double battingAverage = 0.0, int homeRuns = 0) : mBattingAverage(battingAverage), mHomeRuns(homeRuns) {}

};

int main()
{
  return 0;
}
