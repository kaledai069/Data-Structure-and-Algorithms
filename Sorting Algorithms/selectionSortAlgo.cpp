#include <iostream>

void selectionSortAlgo(int arr[], int size);
main()
{
    int arr[] = {7,4,10,8,3,1};
    int size = *(&arr+1) - arr;
    selectionSortAlgo(arr, size);
    for(int i =0; i < size; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}
void selectionSortAlgo(int arr[], int size)
{
    int i,j, temp;
    for(i = 0; i < size-1; i++)
    {
        int min = i;
        for(j = i+1; j< size; j++)
        {
            if(arr[j] < arr[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}