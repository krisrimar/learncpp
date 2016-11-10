#ifndef DOLLARS_H
#define DOLLARS_H

#include "cents.h"

class Dollars
{
private:
  int mDollars;

public:
  Dollars(int dollars = 0) : mDollars{dollars} {}

  int getDollars() const { return mDollars; }

  //overloading type conversion to Cents
  operator Cents() { return Cents(mDollars * 100); }

  //this will allow us to do the following
  // Dollars dollars(9);
  // printCents(dollars);
  //
  // void printCents(Cents cents)
  // {
  //   std::cout << cents; // cents will be implicitly cast to an int here
  // }
};

//explicitly providing a prototype so other files know the overload exists
Cents operator+(const Cents &c1, const Cents &c2);

#endif
