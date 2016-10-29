#include <iostream>
#include <string>
#include <algorithm>

main() {

  using namespace std;

  cout << "Enter number of names: ";
  int *numberOfNames = new int;
  cin >> *numberOfNames;
  cin.clear();
  cin.ignore(32767,'\n');

  string *nameArr = new string[*numberOfNames];
  string *nameValue = new string;

  for(int count = 0; count < *numberOfNames; ++count) {
    cout << "Enter name #" << count+1 << ": ";
    getline(cin,nameArr[count]);
  }

  cout << "\n";

  sort(nameArr,nameArr + *numberOfNames);

  for(int count = 0; count < *numberOfNames; ++count)
    cout << "Name #" << count+1 << ": " << nameArr[count] << "\n";

  cin >> *numberOfNames;

}
