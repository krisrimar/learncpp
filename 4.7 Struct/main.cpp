#include <iostream>
#include <string>

enum Resistance {
  FIRE_RES      = 1,
  WATER_RES     = 2,
  FROST_RES     = 4,
  LIGHTNING_RES = 8
};

void getResistances(const unsigned char resistances) {

    using std::cout;

    if(resistances != 0) {
      cout << "You have resistance to ";
      if(resistances & FIRE_RES) cout << "-fire- ";
      if(resistances & WATER_RES) cout << "-water- ";
      if(resistances & FROST_RES) cout << "-frost- ";
      if(resistances & LIGHTNING_RES) cout << "-lightning- ";
    } else {
      cout << "You have no resistances :(";
    }
}

int main() {

  using std::cout;
  using std::cin;
  using std::string;
  using std::getline;

  struct Player {
    string name;
    unsigned char level;
    unsigned char resistances;
  };

  //list of all of the resistances and their values
  //user as bit flags


  Player player1;

  cout << "Enter your character name:  ";
  getline (cin, player1.name);

  player1.level = 10;

  player1.resistances |= FIRE_RES;
  player1.resistances ^= FIRE_RES;
  player1.resistances |= WATER_RES;
  player1.resistances |= LIGHTNING_RES;

  cout << "\n";
  cout << "Your name is " << player1.name << " and your level is " << static_cast<int>(player1.level) << "\n";
  cout << "\n";
  getResistances(player1.resistances);

  int some;
  std::cin >> some;

}
