#include <iostream>
#include <time.h>

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

void selection_sort(int arr[], int size)
{
	for(int i = 0; i < size - 1; i++)
	{
		int min = i;
		for(int j = i + 1; j < size; j++)
		{
			if(arr[j] < arr[min])
			{
				min = j;
			}
		}
		if(min != i)
		{
			int temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
}

void display(int arr[], int size)
{
	for(int i = 0; i < size; i++)
	{
		std::cout << arr[i] << "  ";
	}
	std::cout << std::endl;
}

int main()
{
	srand(static_cast<unsigned>(time(NULL)));
	bool is_running = true;
	int *array;
	while(is_running)
	{
		std::cout << "\n\t\tEnter the number of items for the array to be created: ";
		int arr_count, choice;
		std::cin >> arr_count;
		array = new int[arr_count];
		for(int i = 0; i < arr_count ; i++)
		{
			array[i] = rand() % 1000;
		}
		std::cout << "\n\t\tChoose the sorting algorithm to be used as following: \n\t\t1. Merge Sort\n\t\t2. Selection Sort\n\t\t3. Exit\n\t\t";
		std::cout << "Enter your choice of sorting: ";
		std::cin >> choice;
		switch(choice)
		{
			case 1:
				std::cout << "\n\t\tMERGE SORT\n\t\t";
				std::cout << "\n\t\tBefore Sorting: \n\t\t";
				display(array, arr_count);
				merge_sort(array, 0, arr_count - 1);
				std::cout << "\n\t\tAfter Sorting: \n\t\t";
				display(array, arr_count);
				break;
			case 2:
				std::cout << "\n\t\tSELECTION SORT\n\t\t";
				std::cout << "\n\t\tBefore Sorting: \n\t\t";
				display(array, arr_count);
				selection_sort(array, arr_count);
				std::cout << "\n\t\tAfter Sorting: \n\t\t";
				display(array, arr_count);
				break;
			case 3:
				is_running = false;
				break;
		}
		delete []array;
	}	
}