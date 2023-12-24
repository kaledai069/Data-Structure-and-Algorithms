// using recursion to find the fibonacci series
#include <iostream>
using namespace std;

long double recursiveFibonacci(int);

int main()
{
    int num;
    cout << "Please enter the number: ";
    cin >> num;
    int result = recursiveFibonacci(num);
    cout << "The fibonacci number is: " << result;
    return 0;
}

long double  recursiveFibonacci(int num)
{
    static int num;
    if(num==1)
    {
        return 0;
    }
    else if (num ==2)
    {
        return 1;
    }
    else
    {
        num++;
        cout << num << endl;
        return recursiveFibonacci(num-1) + recursiveFibonacci(num-2);
    }
}
