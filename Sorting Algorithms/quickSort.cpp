#include <iostream>

void QuickSort(int arr[], int lb, int ub);
int partition(int arr[], int lb, int ub);
main()
{
    int arr[] = {7, 6, 10, 5, 9, 2, 1, 15, 7};
    int size = *(&arr+1) - arr;
    int lb = 0;
    int ub = size-1;
    QuickSort(arr, 0, ub);
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}

void QuickSort(int arr[], int lb, int ub)
{
    if(lb < ub)
    {
        int loc = partition(arr, lb, ub);
        QuickSort(arr, lb, loc-1);
        QuickSort(arr, loc +1 , ub);
    }
}
int partition(int arr[], int lb, int ub)
{
    int start, end;
    int pivot = arr[lb];
    start = lb;
    end = ub;
    while(start < end)
    {
        while (arr[start] <= pivot && start < ub)
        {
            start++;
        }
        while (arr[end] > pivot && end > lb)
        {
            end--;
        }
        if(start <= end)
        {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        }
    }
    arr[lb] = arr[end];
    arr[end] = pivot;
    return end;
}