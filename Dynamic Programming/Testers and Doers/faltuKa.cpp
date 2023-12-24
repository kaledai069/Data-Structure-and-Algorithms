#include <bits/stdc++.h>
#define s 5

void fun(int val)
{
	std::cout << val << std::endl;
}

int main()
{
	void (*funcPtr)(int) = fun;
	
}