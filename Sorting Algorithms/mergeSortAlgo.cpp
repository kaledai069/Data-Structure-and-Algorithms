#include <iostream>
#include <cmath>

void mergeSort(int arr[], int lb, int ub);
void merge(int arr[], int lb, int mid , int ub);

main()
{
    int arr[] = {1,5,24,8,7,3,16,10,20};
    // int arr[] = {1,3,5,7,8,10,16,20,24};
    int lb = 0;
    int size = (*(&arr+1)-arr);
    int ub = size-1;
    int mid = (lb+ub)/2;
    mergeSort(arr, 0, size-1);
    // merge(arr, 0, mid, ub);
    for(int i = 0; i < size; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}
void merge(int arr[], int lb, int mid , int ub)
{
    int i = lb;
    int j = mid+1;
    int k = 0;
    int upperBound = ub;
    int newArray[upperBound] = {0};
    
    while (i <= mid && j <= ub)
    {
        if(arr[i] <= arr[j])
        {
            newArray[k] = arr[i];
            i++;
        }
        else 
        {
            newArray[k] = arr[j];
            j++;
        }
        k++;
    }
    if (i > mid)
    {
        while(j <= ub)
        {
            newArray[k] = arr[j];
            j++; k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            newArray[k] = arr[i];
            i++; k++;
        }
    }
  
    for (i = 0, j = lb; i < k; i++, j++)
    {
        arr[j] = newArray[i];
    }
    

}
void mergeSort(int arr[], int lb, int ub)
{
    if(lb < ub)
    {
        int mid = (ub+lb)/2;
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid+1, ub);
        merge(arr, lb, mid, ub);
    }
}

// void merge(int arr[], int l, int m, int r)
// {
//     int n1 = m - l + 1;
//     int n2 = r - m;
//     // Create temp arrays 
//     int L[n1], R[n2];
//     // Copy data to temp arrays L[] and R[] 
//     for(int i = 0; i < n1; i++)
//         L[i] = arr[l + i];
//     for(int j = 0; j < n2; j++)
//         R[j] = arr[m + 1 + j];
//     int i = 0; 
//     int j = 0; 
//     int k = l;
//     while (i < n1 && j < n2)
//     {
//         if (L[i] <= R[j]) 
//         {
//             arr[k] = L[i];
//             i++;
//         }
//         else
//         {
//             arr[k] = R[j];
//             j++;
//         }
//         k++;
//     }

//     while (i < n1) 
//     {
//         arr[k] = L[i];
//         i++;
//         k++;
//     }
 
//     while (j < n2)
//     {
//         arr[k] = R[j];
//         j++;
//         k++;
//     }

// }



// void merge(int arr[], int lb, int mid, int ub)
// {
//     int i, j, k;
//     i = lb;
//     j = mid+1;
//     for (int k =0; k <= (lb+ub); k++)
//     {
//         if(arr[i]<arr[j] && i <= mid)
//         {
//             arr[k] = arr[i];
//             i++;
//         }
//         else if (arr[i]>arr[j] && j <= ub)
//         {
//             arr[k] = arr[j];
//             j++;
//         }
//     }
// }

