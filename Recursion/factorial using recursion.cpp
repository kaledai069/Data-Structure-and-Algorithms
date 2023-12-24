#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
long double factorialRecursion(long double);
int main()
{
    long double num = 1754;
   /* cout << "Please enter the number whose factorial is to be found: ";
    cin >> num; */
    auto start = high_resolution_clock::now();
    cout << factorialRecursion(num) << endl ;
   
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout << duration.count();

    return 0;
}
long double factorialRecursion(long double num)
{
    if (num == 0)
    {
        return 1;
    }
    else
    {
        return num*factorialRecursion(num-1);
    }
}
