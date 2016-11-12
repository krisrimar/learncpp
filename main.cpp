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
};

int main()
{
  FixedPoint2 a(10,55);
  return 0;
}
