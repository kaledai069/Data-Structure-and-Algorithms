#include <iostream>

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
	
	for(int i = 0; i < size; i++)
	{
		
		std::cout << arr[i] << std::endl;
	}
}

int main()
{
	int int_arr[] = {200, 299, 737, 172, 383, 219, 973, 233, 712, 396, 660, 960, 658, 397, 352, 642, 592, 915, 74, 111};
	selection_sort(int_arr, 20);
}