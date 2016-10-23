#include <iostream>

using namespace std;

int bit(int number, int power) {

  if (number >= power) {
    cout << "1";
    return number - power;
  }
  else {
    cout << "0";
    return number;
  }

}

int main() {

  cout << "Please enter a number between 0 and 255: ";
  int number;
  cin >> number;

  number = bit(number, 128);
  number = bit(number, 64);
  number = bit(number, 32);
  number = bit(number, 16);

  cout << " ";

  number = bit(number, 8);
  number = bit(number, 4);
  number = bit(number, 2);
  number = bit(number, 1);

  cin >> number;


}
