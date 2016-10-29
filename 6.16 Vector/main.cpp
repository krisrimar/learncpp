#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  vector<string> namesArr;

  cout << "Please enter a number of names: ";
  int *numberOfNames = new int;
  cin >> *numberOfNames;

  namesArr.resize(*numberOfNames);
  string *nameValue = new string;

  for(int count = 0; count < *numberOfNames; ++count)
  {
    cout << "Enter name: ";
    cin >> *nameValue;
    namesArr[count] = *nameValue;
    cout << "\n";
  }

  for(auto const &element : namesArr)
    cout << "Name: " << element << "\n";

  cin >> *nameValue;
}
