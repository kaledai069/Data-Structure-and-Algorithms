#include <iostream>
#include <vector>

void bubbleSortAlgo(int arr[], int size);
void unknownSortAlgo(int arr[], int size);
main()
{
    int arr[] = {45, 69, 89, 78, 4, 20, 17, 57, 87};
    int size = *(&arr+1) - arr;
    bubbleSortAlgo(arr, size);
    for(int i = 0; i < size; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}
void bubbleSortAlgo(int arr[], int size)
{
    int temp = 0;
    for ( int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size-1-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void unknownSortAlgo(int arr[], int size)
{
    int i, j, temp;
    for (i = 0; i < size-1; i++)
    {
        for (j = i+1; j< size; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(int i = 0; i < size; i++)
    {
        std::cout << arr[i] << std::endl;
    }

}