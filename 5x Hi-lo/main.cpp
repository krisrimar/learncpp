#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>


int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

//get user input
int getNumber() {

  using std::cin;
  using std::cout;

  while(true) {

    int number;
    cin >> number;

    //validate user input
    if(cin.fail()) {
      cin.clear();
      cin.ignore(32767, '\n');
      cout << "Error: Invalid input. Try again: ";
    } else {
      cin.ignore(32767, '\n');
      return number;
    }
  }
}

//check if the user's guess is too high or too low
bool hiOrLo(int userNumber, int correctNumber) {

  using std::cout;

  if(userNumber == correctNumber)
    return true;
  if(userNumber > correctNumber)
    cout << "Your guess is too high!\n";
  if(userNumber < correctNumber)
    cout << "Your guess is too low!\n";
  return false;
}

//ask the user if he wants to play again
bool playAgain() {

  using std::cout;
  using std::cin;

  cout << "Would you like to play again? (y / n): ";
  char userAnswer;
  cin >> userAnswer;

  //validate user input
  while(true) {
    cout << userAnswer << "\n";
    if(userAnswer == 'y') cout << "Hello!" << "\n";
    if(cin.fail() || userAnswer != 'y' || userAnswer != 'n') {
      cin.clear();
      cin.ignore(32767, '\n');
      cout << "Error: Invalid input. Try again: ";
    } else {
      cin.ignore(32767, '\n');
      if(userAnswer == 'y')
        return true;
      else
        return false;
    }
  }
}

int main() {

  using std::cout;
  using std::cin;
  using std::string;
  using std::getline;

  srand(static_cast<unsigned int>(time(0)));

  while(true) {

    int randomNumber = getRandomNumber(1,100);

    int numberOfGuess = 1;
    const int maxGuesses = 7;
    int userGuess;
    bool winner = false;

    cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have " << maxGuesses << " tries!\n";

    do {
      cout << "Guess #" << numberOfGuess << ": ";
      userGuess = getNumber();
      if(hiOrLo(userGuess, randomNumber)) {
        winner = true;
        break;
      }
      ++numberOfGuess;
    } while(numberOfGuess <= maxGuesses);

    if(winner == true)
      cout << "You won!\n";
    else
      cout << "Sorry, you lost :( The correct number was " << randomNumber << "\n";

    if(!playAgain())
      break;

  }

  int some;
  std::cin >> some;

}
