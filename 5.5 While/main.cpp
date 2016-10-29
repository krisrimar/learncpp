#include <iostream>
#include <string>

int main() {

  using std::cout;
  using std::cin;
  using std::string;
  using std::getline;

  /*
  unsigned char currentLetter = 'a';

  while(currentLetter <= 'z') {
    cout << currentLetter << " (" << static_cast<int>(currentLetter) << ")\n";
    ++currentLetter;
  }
  */
/*
  int row = 1;
  while(row <= 5) {
    cout << ">";
    int x = 4;
    while(x >= row) {
      cout << "  ";
      int y = 1;
      --x;
    }
    int y = 1;
    while(y <= row) {
      cout << y++ << " ";
    }
    cout << "\n";
    ++row;
  }
  */

  int row = 1;
  while(row <= 5) {
    cout << ">";
    int x = 5;
    while(x >= 1) {
      if(x > row)
        cout << "  ";
      else
        cout << x << " ";
        --x;
    }
    cout << "\n";
    ++row;
  }




  int some;
  std::cin >> some;

}
