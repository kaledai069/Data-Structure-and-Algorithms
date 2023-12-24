#include <iostream>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int lb, int ub)
{
	int pivot = arr[lb];
	int start = lb;
	int end = ub;;
	
	while(start < end)
	{
		while(arr[start] <= pivot)
		{
			start++;
		}
		while(arr[end] > pivot)
		{
			end--;
		}
		if(start < end)
		{
			swap(&arr[start], &arr[end]);
		}
			
	}
	swap(&arr[lb], &arr[end]);
	return end;
}

void quick_sort(int arr[], int lb, int ub)
{
	if(lb < ub)
	{
		int loc = partition(arr, lb, ub);
		quick_sort(arr, lb, loc - 1);
		quick_sort(arr, loc + 1, ub);
	}
}

int main()
{
	int arr[9] = {7, 6, 10, 5, 9, 2, 1, 15, 7};
	quick_sort(arr, 0, 8);
	for(int item : arr)
		std::cout << item << "\t";
}