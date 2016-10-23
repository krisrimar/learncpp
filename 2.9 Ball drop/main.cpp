#include <iostream>
#include "constants.h"

using std::cout;
using std::cin;

using myConstants::gravity;

float powerOf2(float number) {
  return number * number;
}

//Calculate and print out at which height the ball is at a given time
float downfall(const float height, float second) {
  float newHeight = gravity * powerOf2(second) / 2.0;
  if (height - newHeight > 0) cout << "At " << second << " seconds, the ball is at height " << height - newHeight << " meters\n";
  else cout << "At " << second << " seconds, the ball is at height 0 meters\n";
}

int main() {

  cout << "Please enter the initial height of the tower: ";
  float towerHeight;
  cin >> towerHeight;

  const float height(towerHeight);

  downfall(height, 0);
  downfall(height, 1.0);
  downfall(height, 2.0);
  downfall(height, 3.0);
  downfall(height, 4.0);
  downfall(height, 5.0);


  cin >> towerHeight;

}
