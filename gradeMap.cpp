#include "gradeMap.h"
#include <string>
#include <vector>

const char& GradeMap::operator[] (const std::string studentName) const
{
  for(const auto &element : mMap)
  {
    if(element.name == studentName)
      return element.grade;
  }

  StudentGrade newStudent;
  newStudent.name = studentName;
  mMap.push_back(newStudent);
}

// void GradeMap::operator= (char newGrade)
// {
//   this[]
// }
