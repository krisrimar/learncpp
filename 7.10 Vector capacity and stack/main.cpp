#include <vector>
#include <iostream>

void printStack(const std::vector<int> &stack)
{
	for (const auto &element : stack)
		std::cout << element << ' ';
	std::cout << "(cap " << stack.capacity() << " length " << stack.size() << ")\n";
}

int main()
{
	std::vector<int> stack;

	//reserving memory for vector is less expensive than adding it dymanically
	stack.reserve(5); // Set the capacity to (at least) 5

	printStack(stack);

	//adds an item to the vector
	stack.push_back(5);
	printStack(stack);

	stack.push_back(3);
	printStack(stack);

	stack.push_back(2);
	printStack(stack);

	//prints the topmost item in the stack
	std::cout << "top: " << stack.back() << '\n';

	//removes an item form the vector
	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	return 0;
}
