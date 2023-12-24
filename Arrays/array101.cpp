#include <iostream>
using namespace std;
int* appendFunct(int arr[], int);


int main()
{
     int arr[5] = {1,2,3,4,5};
     int num =7;
     int* newArr = appendFunct(arr, num);
     cout << newArr[3];



}

int* appendFunct(int arr[], int num)
{
    int arra[6];
    for (int i =0 ; i< 5; i++)
    {
        arra[i] = arr[i];
    }
    arra[6] = num;
    return arra;
}
