#ifndef GRADEMAP_H
#define GRADEMAP_H
#include "studentGrade.h"
#include <vector>
#include <string>

class GradeMap
{
  private:
    std::vector <StudentGrade> mMap;
  public:
    GradeMap() {}

    const char& operator[] (const std::string studentName) const;
    //void operator= (char grade)
};

#endif
