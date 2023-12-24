#include <iostream>

void insertionSort(int arr[], int size);
void insertionAlternativeCode(int arr[],int size);
main()
{
    // int arr[] = {5,4,10,1,6,2};
    int arr[] = {56,89,45,2,0,78,999,345,65,69,34,22,99};
    int size = *(&arr+1) - arr;
    // insertionSort(arr, size);
    insertionAlternativeCode(arr, size);
    for(int i =0; i < size; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}

void insertionAlternativeCode(int arr[], int size)
{
    int i, j, temp;
    for (int i = 1; i < size; i++)
    {
        temp = arr[i];
        j = i-1;
        while(j >=0 && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

// void insertionSort(int arr[], int size)
// {
//     int i = 0, j = 0, temp;
//     for(i = 1; i < size; i++)
//     {
//         temp = arr[i];
//         for(j=i-1;j>=0;j--)
//         {
//             if(arr[j] > temp)
//             {
//                 arr[j+1] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }
// }