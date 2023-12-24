#include <bits/stdc++.h>
#include <chrono>
#include <algorithm>
#define SIZE 50

static int array[50];

int fibo(int n)
{
	if(n < 0) exit(1);
	if(n == 0) return 0;
	if(n == 1) return 1;
	int sum = fibo(n-1) + fibo(n-2);
	return sum;
}

int fibUsingDP(int n)
{
	if(array[n] != -1)
		return array[n];
	if(n < 0) exit(1);
	if(n == 0) return 0;
	if(n == 1) return 1;
	int sum = fibo(n-1) + fibo(n-2);
	array[n] = sum;
	return sum;
}

int main()
{
	std::fill(array, array+SIZE, -1);
//	auto start = std::chrono::high_resolution_clock::now();
//	std::cout << fibo(40) << std::endl;
//	auto stop = std::chrono::high_resolution_clock::now();
//	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count() << std::endl;
	
	
//	start = std::chrono::high_resolution_clock::now();
	std::cout << fibUsingDP(40) << std::endl;
//	stop = std::chrono::high_resolution_clock::now();
//	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count() << std::endl;
	
}