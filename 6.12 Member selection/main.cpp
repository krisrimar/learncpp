#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Person {
  int age;
  string name;
  float weightInKg;
};

main() {

  Person Kris;

  Person *pKris = &Kris;

  pKris->age = 22;
  pKris->name = "Kris";
  pKris->weightInKg = 70.0;

  cout << "The person's name is " << pKris->name << " he or she is " << pKris->age << " years old and weighs " << pKris->weightInKg << " kilograms\n";

  int someInt;
  cin >> someInt;
}
