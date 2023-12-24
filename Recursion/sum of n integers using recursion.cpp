#include <iostream>
using namespace std;
int sampleRecursion(int num);


int main()
{  
    int num;
    cout << "Please enter the number your want to found out: ";
    cin >> num;
    int sum = sampleRecursion(num);
    cout << "The sum is: " << sum << endl;
    return 0;
}

int sampleRecursion(int num)
{
    if(num > 0)
    {
        return num + sampleRecursion(num-1);
    }
}
