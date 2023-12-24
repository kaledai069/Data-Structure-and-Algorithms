#include <bits/stdc++.h> 
#include <chrono>
#define NUM 60
#define ULL unsigned long long

static int count = 0;
static int cnt = 0;
static std::vector<ULL> dpVec(128, -1);
// with dynamic programming
ULL fib(int n)
{
	cnt++;
	if(dpVec[n] != -1)
		return dpVec[n];
	if(n < 0) exit(0);
	if(n == 0)	return 0;
	if(n == 1) return 1;
	ULL sum = fib(n-1) + fib(n-2);
	dpVec[n] = sum;
	return sum;
}

// without dynamic Programming
int fibi(int n)
{
	count++;
	if(n == 0)	return 0;
	if(n == 1) return 1;
	return fibi(n-1) + fibi(n-2);
}
int main()
{
//	std::cout << "Using the Simple recursive tree\n";
//	auto start = std::chrono::high_resolution_clock::now();
//	std::cout << fibi(NUM) << std::endl;
//	auto stop = std::chrono::high_resolution_clock::now();
//	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
//	std::cout << "Running Time: " << duration.count() << std::endl;
//	std::cout << count << std::endl;
	
	std::cout << "Using the dynamic programming: \n";
	auto start = std::chrono::high_resolution_clock::now();
	std::cout << fib(NUM) << std::endl;
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	std::cout << "Running Time: " << duration.count() << std::endl;
	std::cout << cnt << std::endl;
}