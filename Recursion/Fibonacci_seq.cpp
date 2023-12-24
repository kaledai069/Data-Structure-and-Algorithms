#include <iostream>
#include <functional>
//int fib(int n)
//{
//	return n == 1 or n == 2 ? n - 1 : fib(n-1) + fib(n-2);
//}

int main()
{
	std::function<int(int)> fib = [&](int n){return n == 1 or n == 2? n - 1: fib(n-1) + fib(n-2);};
	std::cout << "Enter the index of sequence to reveal: ";
	int num;
	std::cin >> num;
	std::cout << "The value at that particular sequence is: " << fib(num) << std::endl;
	for(int i = 1; i <= num; i++)
		std::cout << fib(i) << '\t';
}