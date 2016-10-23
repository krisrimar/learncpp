#include <iostream>
#include <string>


int main() {

  using std::cout;
  using std::cin;
  using std::string;
  using std::getline;

  /*enum Resistance {
    FIRE_RES      = 1,
    WATER_RES     = 2,
    FROST_RES     = 4,
    LIGHTNING_RES = 8
  }

  unsigned char userResistance = 0;

  userResistance |= FIRE_RES;
  */

  cout << "Please enter your name: ";
  string name;
  getline (cin, name);

  cout << "Please enter your age: ";
  int age;
  cin >> age;

  cout << "Your name is " << name << " and your age is " << age << "\n";


  int some;
  std::cin >> some;

}
