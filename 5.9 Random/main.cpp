#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>

unsigned int PRNG() {
  static unsigned int seed = 2314;

  seed = (8253729 * seed + 2396403);
  return seed % 5;
}

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
    // evenly distribute the random number across our range
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int main() {

  using std::cout;
  using std::cin;
  using std::string;
  using std::getline;

  srand(static_cast<unsigned int>(time(0)));

  for(int count = 0; count < 100; ++count) {
    cout << rand() << "\t";
    if((count + 1) % 5 == 0)
      cout << "\n";
  }

  cout << "\n\n" << getRandomNumber(1,100);

  std::random_device rd;
  std::mt19937 mersenne(rd());

  for (int count = 0; count < 48; ++count)
    {
        std::cout << mersenne() << "\t";

        // If we've printed 4 numbers, start a new row
        if ((count + 1) % 4 == 0)
            std::cout << "\n";
    }

  int some;
  std::cin >> some;

}
