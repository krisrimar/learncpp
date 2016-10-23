#include <iostream>



int main() {

	using namespace std;

	cout << "Please enter a number: ";
	char number;
	cin >> number;

	cout << static_cast<int>(number) << " + " << static_cast<int>(number) << " = " << static_cast<int>(number + number);

	cin >> number;

	return 0;
}