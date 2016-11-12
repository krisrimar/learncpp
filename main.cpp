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
      mBase = tatic_cast<std::int16_t>(d); //truncates fraction

      //now we get the fractional component
      //d - mBase leaves only the fractional portion e.g. 9.617 minus 9.0 = 0.617
      //multiplied by 100 moves the point 2 positions to the left e.g. 0.617 -> 61.7
      //then we round it to the nearest integral e.g. 61.7 -> 62.0
      //and finally cast to int8_t to drop the decimals e.g. 62.0 -> 62
      mDecimal = static_cast<std::int8_t>(round((d - mBase) * 100));
    }
};

int main()
{
  FixedPoint2 a(10,55);
  FixedPoint2 b(9.617);
  return 0;
}
