#include <iostream>

int main() {

  //using namespase std;
  using std::cout;
  using std::cin;

  cout << "Please enter your ID: ";
  int userID;
  cin >> userID;

  if(userID == 1) {
    cout << "Please enter your password: ";
    int password;
    cin >> password;

    if(password == 4334) cout << "Welcome! Your balance is 350$";
    else cout << "Access denied!";

  }
  //cout << "Your ID is:" << userID;

  cin >> userID;

  return 0;

}

/*

1. Модуль прийому номера користувача
  а) попросити юзера ввести номер
  б) записати введений юзером номер в змінну
2. Модуль провірки номера користувача (4-х юзерів)
3. Модуль провірки пароля користувача
4. Модуль повернення рахунку користувача


*/
