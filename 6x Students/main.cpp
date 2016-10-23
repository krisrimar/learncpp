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

  int *largestScoreIndex  = new int;
  bool *thereWereChanges  = new bool;
  *thereWereChanges       = false;

  for(int loop = 0; loop < *iterations; ++loop)
  {
    //cout << "loop #" << loop << '\n';
    *largestScoreIndex = loop;
    for(int index = loop + 1; index < *iterations; ++index)
    {
      //cout << "index #" << index << '\n';
      if(array[index].score > array[*largestScoreIndex].score)
      {
        //cout << "the new big number is " << array[index].score << '\n';
        *largestScoreIndex = index;
        *thereWereChanges = true;
      }
    }
    if(*thereWereChanges)
    {
      //cout << "swapping " << array[*largestScoreIndex].score << "(" << *largestScoreIndex << ") with " << array[loop].score << "(" << loop << ")\n";
      swap(array[loop], array[*largestScoreIndex]);
      *thereWereChanges = false;
    }
  }
}

int main()
{
  vector<Student> studentsArr;
  int *numberOfStudents = new int;

  //to prevent the user from entering: negative number, zero and 1
  do {
    cout << "Please enter a number of students: ";
    cin >> *numberOfStudents;
  } while (*numberOfStudents <= 1);

  //change the size of the students array to fit in all of the students
  studentsArr.resize(*numberOfStudents);
  string *nameValue = new string;
  int *scoreValue   = new int;

  //ask user to input all of the students names and scores
  for(int count = 0; count < *numberOfStudents; ++count)
  {
    cout << "Enter name of student " << count + 1 << ":   ";
    cin >> studentsArr[count].name;
    cout << "Enter score of student " << count + 1 << ":  ";
    cin >> studentsArr[count].score;
  }

  sortScores(studentsArr, numberOfStudents);

  cout << '\n';

  for(const Student &element : studentsArr)
    cout << element.name << " " << element.score << '\n';

}
