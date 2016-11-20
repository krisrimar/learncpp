#include <iostream>

template <typename anyNumberType>
anyNumberType add(anyNumberType x, anyNumberType y)
{
  return x + y;
}

template <class anyArrayType>
anyArrayType Average(anyArrayType *atArray, int nNumValues)
{
  anyArrayType tSum = 0;
  for(int nCount = 0; nCount < nNumValues; nCount++)
    tSum += atArray[nCount];

  tSum /= nNumValues;
  return tSum;
}


int main()
{
  std::cout << add(12, 3) << std::endl;
  std::cout << add(5.2,5.5) << std::endl;

  int iSomeArray[] = {1,2,3,4,5};
  double dSomeArray[] = {23.4,12.3,78.1,90.3,9.0};

  std::cout << Average(iSomeArray, 5) << std::endl;
  std::cout << Average(dSomeArray, 5) << std::endl;

  return 0;
}
