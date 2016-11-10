#include "gradeMap.h"
#include <string>
#include <vector>

//because this function has a return type of a reference to char (which is the students grade)
//once we perform the first part of the "equation" in grades["Joe"] = 'A', which is
//grades["Joe"], which either looks for an array element with a corresponding name
//or creates a new object
//when this is done, the grades["Joe"] part changes to &grade
//and now to the compiler it looks like &grade = 'A', meaning, we need to assign 'A' to
//Joe's grade
char& GradeMap::operator[] (const std::string studentName)
{
  for(auto &element : mMap)
  {
    if(element.name == studentName)
      return element.grade;
  }

  StudentGrade newStudent {studentName, ' '}; //initialize newStudent members
  mMap.push_back(newStudent); //push the newStudent struct into the mMap

  //returns the topmost element of the vector stack
  //to be more percise: the refference to the grade of that element
  return mMap.back().grade;
}
