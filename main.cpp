#include <iostream>
#include "Cents.h"

class Fraction
{
  private:
    int m_numerator = 0;
    int m_denominator = 1;

  public:
    Fraction(int numerator, int denominator) : m_numerator{numerator}, m_denominator{denominator}
    {
      reduce();
    }

    void print()
    {
      std::cout << m_numerator << "/" << m_denominator << '\n';
    }

    static int gcd(int a, int b)
    {
      return b == 0 ? a : gcd(b, a % b);
    }

    void reduce()
    {
    	int gcd = Fraction::gcd(m_numerator, m_denominator);
    	m_numerator /= gcd;
    	m_denominator /= gcd;
    }

    friend Fraction operator*(const Fraction &f1, const Fraction &f2);
    friend Fraction operator*(const Fraction &f1, const int &f2);
    friend Fraction operator*(const int &f1, const Fraction &f2);
};

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
  Fraction f3((f1.m_numerator * f2.m_numerator), (f1.m_denominator * f2.m_denominator));

  return f3;
}

Fraction operator*(const Fraction &f1, const int &f2)
{
  Fraction f3((f1.m_numerator * f2), (f1.m_denominator));

  return f3;
}

Fraction operator*(const int &f1, const Fraction &f2)
{
  Fraction f3((f2.m_numerator * f1), (f2.m_denominator));

  return f3;
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

    Cents cents1(6);
    Cents cents2(8);
    Cents centsSum = cents1 + cents2; // without the prototype in Cents.h, this would fail to compile
    std::cout << "I have " << centsSum.getCents() << " cents." << std::endl;

    return 0;
}
