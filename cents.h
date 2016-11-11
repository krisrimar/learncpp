#ifndef CENTS_H
#define CENTS_H

#include <iostream>

class Cents
{
private:
  int mCents;

public:
  Cents(int cents) : mCents{cents} {}

  //copy constructor
  Cents(const Cents &cents) : mCents{cents.mCents} {}

  int getCents() const { return mCents; }

  friend std::ostream& operator<<(std::ostream &out, const Cents &cent);
};

//explicitly providing a prototype so other files know the overload exists
Cents operator+(const Cents &c1, const Cents &c2);

#endif
