#include <iostream>

enum Type {
  INT,
  FLOAT
};

void printValue(void *ptr, Type type) {

  using std::cout;

  switch(type) {
    case INT:
      cout << *static_cast<int*>(ptr);
      break;
    case FLOAT:
      cout << *static_cast<float*>(ptr);
      break;
    default:
      cout << "Sorry, can't define the type :(\n";
  }
}

int main() {

  using namespace std;

  int someInt   = 5;
  int otherInt  = 6;
  int *ptr      = nullptr;
  void *vPtr    = &someInt;
  ptr           = &someInt;

  cout << "Outputing the void ptr first: " << *static_cast<int*>(vPtr) << endl; //pointing to void ptr and converting it to <int>
  cout << *ptr << endl; //gives the value of the variable
  cout << ptr << endl;  //gives the address of the variable

  ptr = &otherInt;

  cout << *ptr << endl; //gives the value of the variable
  cout << ptr << endl;  //gives the address of the variable

  cout << endl;

  printValue(&someInt, INT);

  char someChar = 'Q';
  cout << &someChar << endl;

  cin >> someInt;

}
