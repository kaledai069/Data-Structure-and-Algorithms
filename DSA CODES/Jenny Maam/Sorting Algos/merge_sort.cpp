#include <iostream>


void merge(int arr[], int lb, int mid, int ub)
{
	int i = lb;
	int j = mid+1;
	int k = 0;
	int new_array_size = ub - lb + 1;
	
	int temp_arr[new_array_size];
	
	while(i <= mid && j <= ub)
	{
		if(arr[i] <= arr[j])
		{
			temp_arr[k] = arr[i];
			i++;
		}
		else
		{
			temp_arr[k] = arr[j];
			j++;
		}
		k++;
	}
	
	if(i > mid)
	{
		while(j <= ub)
		{
			temp_arr[k] = arr[j];
			j++; k++;
		}
	}
	else 
	{
		while(i <= mid)
		{
			temp_arr[k] = arr[i];
			k++; i++;
		}
	}

	for(i = lb, k = 0; k < new_array_size; i++, k++)
	{
		arr[i] = temp_arr[k];
	}
}

void merge_sort(int arr[], int lb, int ub)
{
	if(lb >= ub)
		return;

	int mid = (lb+ub)/2;
	merge_sort(arr, lb, mid);
	merge_sort(arr, mid+1, ub);
	merge(arr, lb, mid, ub);
}

int main()
{
	int arr[9] = {15, 5, 24, 8, 1, 3, 16, 10, 20};
	merge_sort(arr, 0, 8);
	
	for(int i = 0; i < 8; i++)
	{
		std::cout << arr[i] << "\t";
	}
	
}