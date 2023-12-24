#include <iostream>
#include <cmath>
using namespace std;
void mapArray(int [], int []);


int main()
{

    int arr[5] = {1,2,3,4,5};
    int finalarr[5];

    mapArray(arr,  finalarr);
    for(int i =0 ; i < 5; i++)
    {
        cout << finalarr[i] << endl;
    }
}

void mapArray(int arr[], int finalarr[])
{
    for (int i =0; i < 5; i++)
    {
        finalarr[i] = pow(arr[i], 2);
    }
}
