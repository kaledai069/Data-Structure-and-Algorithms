#include <iostream>
#include <vector>

int binarySearchIterative(int arr[], int l, int r, int data);
int binarySearchRecursive(int arr[], int l, int r, int data);

int main()
{
    int arr[] = {5,9,17,23, 25, 45, 59, 63, 71, 89};
    int l = 0;
    int r = sizeof(arr)/sizeof(arr[0]) - 1;
    int data = 89;
    int result = binarySearchRecursive(arr, l, r, data);
    (result == -1) ? std::cout << "Element not found in the array" : std::cout << "Element found in the given array" << result;
    return 0;
}

int binarySearchRecursive(int arr[], int l, int r, int data)
{
    if(r >= l)
    {
        int mid = l + (r-l)/2;
        if (arr[mid] == data)
        return mid;
        else if (arr[mid] < data)
            return binarySearchRecursive(arr, mid + 1, r, data);
        else 
            return binarySearchRecursive(arr, l, mid - 1, data);
    }
    return -1;
}



int binarySearchIterative(int arr[], int l, int r, int data)
{
    while ( l <= r)
    {
        int mid = l + (r-l)/2;
        if (arr[mid] == data)
        return mid;
        else if(data < arr[mid])
        r = mid -1;
        else l = mid + 1;
    }
    return -1;
}
