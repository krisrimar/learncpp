#include <iostream>

static int loop = 0;

int fibonacci(int number)
{
    if (number == 0)
        return 0; // base case (termination condition)
    if (number == 1)
        return 1; // base case (termination condition)
    return fibonacci(number-1) + fibonacci(number-2);
}

int factorial(int number)
{
	if(number < 1)
		return 1;
	return number * factorial(number-1);
}

int sumOfNumbers(int number)
{
  if (number < 10)
    return number;
  return sumOfNumbers(number / 10) + number % 10;
}

int main()
{
    //for (int count=0; count < 13; ++count)
        //std:: cout << fibonacci(count) << " " << std::endl;

		std::cout << sumOfNumbers(93427) << std::endl;

    return 0;
}
