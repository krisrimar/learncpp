#include <iostream>

template <typename anyNumberType>

anyNumberType add(anyNumberType x, anyNumberType y)
{
  return x + y;
}


int main()
{
  std::cout << add(12, 3) << std::endl;
  std::cout << add(5.2,5.5) << std::endl;

  return 0;
}
