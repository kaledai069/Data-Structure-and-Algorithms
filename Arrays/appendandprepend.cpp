#include <bits/stdc++.h>
using namespace std;
void prepend(int arr[], int);
void append(int arr[], int);

int main()
{
    int num = 8;
    int arr[10] = {1,2,3,4,5,6};
    int pos = 3;
    int *q = arr;
    cout << &arr[1] << endl << &q[1];



}

void prepend(int arr[], int num)
{
    for(int i = 5 ; i >=0 ; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[0] = num;
}

void append(int arr[], int num)
{
    arr[7] = num;

}
