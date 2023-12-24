#include <iostream>

int fact(int n)
{
	if(n == 0)
		return 1;
	else
		return n * fact(n - 1);
}

int main()
{
	int num;
	std::cout << "ENTER THE NUMBER: " << std::endl;
	std::cin >> num;
	std::cout << "The factorial of " << num << " is: " << fact(num);
	return 0;
}