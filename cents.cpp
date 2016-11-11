#include "Cents.h"

//overload of the + operator to add two cents values
Cents operator+(const Cents &c1, const Cents &c2)
{
  return Cents(c1.getCents() + c2.getCents());
}

std::ostream& operator<< (std::ostream &out, const Cents &cent)
{
  out << cent.mCents << '\n';

  return out;
}
