#include <iostream>

class Fraction
{
  private:
    int m_numberator = 0;
    int m_denominator = 1;

  public:
    Fraction(int numerator, int denominator) : m_numberator{numerator}, m_denominator{denominator} {}

    void print()
    {
      std::cout << m_numberator << "/" << m_denominator << '\n';
    }

    friend Fraction operator*(const Fraction &f1, const Fraction &f2);
    friend Fraction operator*(const Fraction &f1, const int &f2);
    friend Fraction operator*(const int &f1, const Fraction &f2);
};

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
  Fraction f3((f1.m_numberator * f2.m_numberator), (f1.m_denominator * f2.m_denominator));

  return f3;
}

Fraction operator*(const Fraction &f1, const int &f2)
{
  Fraction f3((f1.m_numberator * f2), (f1.m_denominator));

  return f3;
}

Fraction operator*(const int &f1, const Fraction &f2)
{
  Fraction f3((f2.m_numberator * f1), (f2.m_denominator));

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
    return 0;
}
