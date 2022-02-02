#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>

void linear_search(int array[], int size)
{
	bool found = false;
	int item_to_find, index = 0;
	std::cout << "\n\tEnter the item to be searched: ";
	std::cin >> item_to_find;
	for(int i = 0; i < 15; i++, index++)
	{
		if(array[i] == item_to_find)
		{
			found = true;
			break;
		}
	}
	if(found)
		std::cout << "\n\tThe item: " << item_to_find << " is found in the given array at index: " << index << ".\n";
	else 
		std::cout << "\n\tThe item: " << item_to_find << " is not found in the given array.\n";
}

int binary_search(int array[], int left, int right, int data )
{
	if(right >= left)
	{
		int mid = left + (right - left) / 2;
		if(array[mid] == data)
			return mid;
		else if(array[mid] > data)
			return binary_search(array, left, mid - 1, data);
		else
			return binary_search(array, mid+1, right, data);
	}
	return -1;
}

void binary_searching(int array[], int size)
{
	std::vector<int> sorted_arr(array, array + size);
	
	sort(sorted_arr.begin(), sorted_arr.end());
	for(int i= 0; i < 15; i++)
	{
		array[i] = sorted_arr[i];
		std::cout << array[i] << "  ";
	}
	
	int item_to_find;
	std::cout << "\n\tEnter the item to be searched: ";
	std::cin >> item_to_find;
	int data_index = binary_search(array, 0, 15, item_to_find);
	if(data_index != -1)
		std::cout << "\n\tThe item: " << item_to_find << " is found in the given array at index: " << data_index << ".\n";
	else 
		std::cout << "\n\tThe item: " << item_to_find << " is not found in the given array.\n";
}

int main()
{
	srand(static_cast<unsigned>(time(NULL)));
	int array[15];
	for(int i= 0; i < 15; i++)
	{
		array[i] = rand() % 100;
		std::cout << array[i] << "  ";
	}
	linear_search(array, 15);
	binary_searching(array, 15);
}