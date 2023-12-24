#include <iostream>
using namespace std;

int main()
{
    long double num = 70;
    int a = 0, b=1, c;

    for(int i = 1; i < num; i++)
    {
        c = a+b;
        a = b;
        b = c;
    }
    cout << c;
}
