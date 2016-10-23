#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student {
  string name;
  int score;
};

void sortScores(vector<Student> &array, int *iterations) {

  int *biggestNumber      = new int;
  int *biggestNumberIndex = new int;
  bool *thereWereChanges  = new bool;
  *thereWereChanges       = false;

  for(int loop = 0; loop < *iterations; ++loop)
  {
    cout << "loop #" << loop << '\n';
    *biggestNumber = array[loop].score;
    for(int index = loop + 1; index < *iterations - 1; ++index)
    {
      cout << "index #" << index << '\n';
      if(array[index].score > *biggestNumber)
      {
        cout << "the new big number is " << array[index].score << '\n';
        *biggestNumber = array[index].score;
        *biggestNumberIndex = index;
        *thereWereChanges = true;
      }
    }
    if(*thereWereChanges)
    {
      swap(array[loop], array[*biggestNumberIndex]);
      *thereWereChanges = false;
    }
  }
}

int main()
{
  vector<Student> studentsArr;

  cout << "Please enter a number of students: ";
  int *numberOfStudents = new int;
  cin >> *numberOfStudents;

  studentsArr.resize(*numberOfStudents);
  string *nameValue = new string;
  int *scoreValue = new int;

  //ask user to input all of the students names and scores
  for(int count = 0; count < *numberOfStudents; ++count)
  {
    cout << "Enter name of student " << count+1 << ":   ";
    cin >> *nameValue;
    studentsArr[count].name = *nameValue;
    cout << "Enter score of student " << count+1 << ":  ";
    cin >> *scoreValue;
    studentsArr[count].score = *scoreValue;
    cout << "\n";
  }

  sortScores(studentsArr, numberOfStudents);

  for(const Student &element : studentsArr)
    cout << element.name << " " << element.score << '\n';

  //for(int count = *numberOfStudents - 1; count > 0; --count)
  //  cout << studentsArr[count].name << " " << studentsArr[count].score << '\n';

  cin >> *nameValue;
}
