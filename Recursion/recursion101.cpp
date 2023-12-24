#include <iostream>
using namespace std;
void foo(int);

int main()
{
    foo(10);
}

void foo(int n)
{
    if (n < 1)
    {
        return ;
    }
    else
    {
        foo(n-1);
        cout << "Hello, world" << n << endl;
    }
    
}