#include <iostream>
#include <string>


int main() {

  using std::cout;
  using std::cin;
  using std::string;
  using std::getline;

  enum Resistance {
    FIRE_RES      = 1,
    WATER_RES     = 2,
    FROST_RES     = 4,
    LIGHTNING_RES = 8
  };

  unsigned char res = 0;

  res |= FIRE_RES;
  res ^= FIRE_RES;
  res |= WATER_RES;
  res |= LIGHTNING_RES;

  cout << "Please enter your name:  ";
  string name;
  getline (cin, name);

  cout << "Please enter your age:   ";
  int age;
  cin >> age;

  cout << "\n";
  cout << "Your name is " << name << " and your age is " << age << "\n";
  cout << "\n";
  cout << "Your fire resistance is:       " << static_cast<bool>(res & FIRE_RES) << "\n";
  cout << "Your water resistance is:      " << static_cast<bool>(res & WATER_RES) << "\n";
  cout << "Your lightning resistance is:  " << static_cast<bool>(res & LIGHTNING_RES) << "\n";


  int some;
  std::cin >> some;

}
