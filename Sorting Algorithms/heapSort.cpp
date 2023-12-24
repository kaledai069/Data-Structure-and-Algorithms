#include <iostream>

void MaxHeapify(int arr[], int n, int i);

main()
{
    int arr[] = {15,5,20,1,17,10,30};
    int size = *(&arr+1) - arr;
    int largestNonLeafNode = size/2;
    for(int i = largestNonLeafNode; i>=1; i--)
    {
        MaxHeapify(arr, size, i);
    }
    //deletion operation on heap using heapify method
    for(int i = size; i >= 1; i--)
    {
        int temp = arr[i-1];
        arr[i-1] = arr[0];
        arr[0] = temp;
        MaxHeapify(arr, i-1, 1);
    }
    for(int i = 0; i < size; i++)
        std::cout << arr[i] << std::endl;
}

void MaxHeapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i;
    int r = 2*i +1;
    if(l<= n && arr[l-1]>arr[largest-1])
    {
        largest = l;
    }
    if(r<=n && arr[r-1]>arr[largest-1])
    {
        largest=r;
    }
    if(largest!=i)
    {
        int temp = arr[largest-1];
        arr[largest-1] = arr[i-1];
        arr[i-1] = temp;
        MaxHeapify(arr, n, largest);
    }
}
