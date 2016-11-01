#include <iostream>

static int loop = 0;

int fibonacci(int number)
{
    if (number == 0)
        return 0; // base case (termination condition)
    if (number == 1)
        return 1; // base case (termination condition)
		++loop;
		std::cout << "Adding " << number-1 << " to " << number-2 << "(loop #" << loop << " branch: " << number << ")" << std::endl;
    return fibonacci(number-1) + fibonacci(number-2);
}

// And a main program to display the first 13 Fibonacci numbers
int main()
{
    for (int count=0; count < 13; ++count)
        std:: cout << fibonacci(count) << " " << std::endl;

    return 0;
}
