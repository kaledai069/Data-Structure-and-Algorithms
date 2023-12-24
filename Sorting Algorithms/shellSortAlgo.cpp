#include <iostream>

void shellSortAlgo(int arr[], int size);
main()
{
    int arr[] = {23,29,15,19,31,7,9,5,2};
    int size = *(&arr+1) - arr;
    shellSortAlgo(arr, size);
    for(int i =0 ; i < size; i++) 
        std::cout << arr[i] << std::endl;
}

void shellSortAlgo(int arr[], int size)
{
    for(int gap = size/2; gap >= 1; gap/=2)
    {
        for(int j = gap; j < size; j++)
        {
            for(int i = j-gap; i>=0; i-=gap)
            {
                if(arr[i+gap] > arr[i]) break;
                else 
                {
                    int temp = arr[i+gap];
                    arr[i+gap] = arr[i];
                    arr[i] = temp;
                }
            }
        }
    }
}