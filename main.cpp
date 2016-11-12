#include <iostream>
#include <cstdint>
#include <cmath>

class FixedPoint2
{
  private:
    std::int16_t mBase; //non-fractional part ->1.x
    std::int8_t mDecimal; //fractional part x.0<-

  public:
    FixedPoint2(std::int16_t base = 0, std::int8_t decimal = 0) : mBase{base}, mDecimal{decimal} {}

    FixedPoint2(double d)
    {
      //get the non-fractional (mBase) component
      //this is done by casting double into an integer
      mBase = static_cast<std::int16_t>(d); //truncates fraction

      //now we get the fractional component
      //d - mBase leaves only the fractional portion e.g. 9.617 minus 9.0 = 0.617
      //multiplied by 100 moves the point 2 positions to the left e.g. 0.617 -> 61.7
      //then we round it to the nearest integral e.g. 61.7 -> 62.0
      //and finally cast to int8_t to drop the decimals e.g. 62.0 -> 62
      mDecimal = static_cast<std::int8_t>(round((d - mBase) * 100));
    }

    friend std::ostream& operator<< (std::ostream &out, const FixedPoint2 &fixedPoint)
    {
        out << fixedPoint.mBase << '.';

        //if the decimal is a single digit, then we need to add 0 in front: e.g. 5 -> .05
        if(fixedPoint.mDecimal < 10 && fixedPoint.mDecimal > -10)
          out << '0';

        // Because some compilers typedef std::int8_t as a char, we need to cast it to an int to ensure it prints as an integer
  		  out << static_cast<int>(fp.m_decimal > 0 ? fp.m_decimal : -fp.m_decimal);

  		  return out;
    }
};

int main()
{
  FixedPoint2 a(34, 56);
	std::cout << a << '\n';

	FixedPoint2 b(9.617); // any decimal digits beyond 2 should be rounded to 2 decimals
	std::cout << b << '\n';

	FixedPoint2 c(5.01); // stored as 5.0099999... so we'll need to round this
	std::cout << c << '\n';

	FixedPoint2 d(-5.01); // stored as -5.0099999... so we'll need to round this
	std::cout << d << '\n';
  return 0;
}
