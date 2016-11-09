#include <iostream>
#include "Cents.h"

class Fraction
{
  private:
    int mNumerator = 0;
    int mDenominator = 1;

  public:
    Fraction(int numerator = 0, int denominator = 1) : mNumerator{numerator}, mDenominator{denominator}
    {
      reduce();
    }

    void print()
    {
      std::cout << mNumerator << "/" << mDenominator << '\n';
    }

    static int gcd(int a, int b)
    {
      return b == 0 ? a : gcd(b, a % b);
    }

    void reduce()
    {
    	int gcd = Fraction::gcd(mNumerator, mDenominator);
    	mNumerator /= gcd;
    	mDenominator /= gcd;
    }

    //member functions
    Fraction operator*(const Fraction &f2);
    Fraction operator*(const int &f2);

    //friend functions
    friend Fraction operator*(const int &f1, const Fraction &f2);
    friend std::ostream& operator<<(std::ostream& out, const Fraction &f);
    friend std::istream& operator>>(std::istream& in, Fraction &f);

};

Fraction Fraction::operator*(const Fraction &f2)
{
  return Fraction((mNumerator * f2.mNumerator), (mDenominator * f2.mDenominator));
}

Fraction Fraction::operator*(const int &f2)
{
  return Fraction(mNumerator * f2, mDenominator);
}

Fraction operator*(const int &f1, const Fraction &f2)
{
  Fraction f3((f2.mNumerator * f1), (f2.mDenominator));

  return f3;
}

std::ostream& operator<< (std::ostream& out, const Fraction &f)
{
  out << f.mNumerator << "/" << f.mDenominator;
  return out;
}

std::istream& operator>> (std::istream& in, Fraction &f)
{
  in >> f.mNumerator;
  in >> f.mDenominator;

  return in;
}

int main()
{
  Fraction f1(2, 5);
  f1.print();

  Fraction f2(3, 8);
  f2.print();

  Fraction f3 = f1 * f2;
  f3.print();

  Fraction f4 = f1 * 2;
  f4.print();

  Fraction f5 = 2 * f2;
  f5.print();

  Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
  f6.print();

  std::cout << f6;

  Cents cents1(6);
  Cents cents2(8);

  Cents centsSum = cents1 + cents2; // without the prototype in Cents.h, this would fail to compile

  std::cout << "Enter fraction: ";
  Fraction f;
  std::cin >> f;
  std::cout << f;

  return 0;
}
