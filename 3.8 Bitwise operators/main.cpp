#include <iostream>

using namespace std;

//determine which bit represents what kind of resistance
const unsigned char fireResistance  = 0x01;
const unsigned char waterResistance = 0x02;

//tell the user what he's resistant to
void checkResistance(char resistance) {
  if((waterResistance & resistance) && (fireResistance & resistance))
    cout << "You are both fire and water resistan!";
  else if (waterResistance & resistance)
    cout << "You are water resistant!";
  else if (fireResistance & resistance)
    cout << "You are fire resistant!";
  else
    cout << "You have no nature resistance :(";
}

int main() {

  unsigned char resistance = 3;

  checkResistance(resistance);

  //turn off fireResistance
  resistance &= ~fireResistance;

  checkResistance(resistance);

  char some;
  cin >> some;

}
