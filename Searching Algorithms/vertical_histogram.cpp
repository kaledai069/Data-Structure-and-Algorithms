#include <iostream>
#include <math.h>
#define MAX 100

int size_calc(int num)
{
	int count = 0;
	while(num != 0)
	{
		num /= 10;
		count++;
	}
	return count;
}

int* num_to_arr_parsher(int num, int size)
{
	static int temp[MAX];
	int temp_num, index = 0;
	int divisor = pow(10, size - 1);
	while(num != 0)
	{
		temp_num = num / divisor;
		*(temp + index++)= temp_num;
		num = num % divisor;
		divisor = divisor / 10;
	}
	return temp;
}

int find_maxm(int arr_from_num[], int arr_size)
{
	int max = 0;
	for(int i = 0; i < arr_size; i++)
		if(arr_from_num[i] > max)
			max = arr_from_num[i];
	return max;
}

int main()
{
	int num;
	std::cout << "Enter the number: ";
	std::cin >> num;
	int arr_size = size_calc(num);
	int *arr_from_num;
	arr_from_num = num_to_arr_parsher(num, arr_size);
	int max_dig = find_maxm(arr_from_num, arr_size);
	
	int _2d_arr[max_dig][arr_size] = {0};
	
	
	for(int i = 0; i < arr_size; i++)
		for(int k = max_dig - 1; k >= max_dig - arr_from_num[i]; k--)
			_2d_arr[k][i] = 1;
		
	
	for(int i = 0; i < max_dig; i++)
	{
		std::cout << "\n\t\t";
		for(int j = 0; j < arr_size; j++)
		{
			if(_2d_arr[i][j] == 1)
				std::cout << " * ";
			else
				std::cout << "   ";
		}
		std::cout << std::endl;
	}
}








