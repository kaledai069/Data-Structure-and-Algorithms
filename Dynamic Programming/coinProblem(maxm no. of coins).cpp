#include <bits/stdc++.h>

//int waysOfCoinsChange(const int coins[], int amount, int arraySize)
//{
//	int array[arraySize][amount+1];
//	for(int i = 0; i < arraySize; i++)
//	{
//		for(int j = 0; j <= amount; j++)
//		{
//			if(i == 0)
//				array[i][j] = !bool(j % coins[i]);
//			else if(j == 0)
//				array[i][j] = 1;
//			else if(coins[i] > j)
//				array[i][j] = array[i-1][j];
//			else 
//				array[i][j] = array[i-1][j] + array[i][j - coins[i]];
//		}
//	}
//	for(int i = 0; i < arraySize; i++)
//	{
//		for(int j = 0; j <= amount; j++)
//			std::cout << array[i][j] << '\t';
//		std::cout << std::endl;
//	}
//	return array[arraySize-1][amount];
//}

int waysOfCoinsChange(const int coins[], int amount, int arraySize)
{
	int array[arraySize][amount+1];
	for(int i = 0; i < arraySize; i++)
	{
		for(int j = 0; j <= amount; j++)
		{
			if(i == 0)
				array[i][j] = !bool(j%coins[i]);	
			else if(j == 0)
				array[i][j] = 1;
			else if(coins[i] > j)
				array[i][j] = array[i-1][j];
			else
				array[i][j] = array[i-1][j] + array[i][j - coins[i]];
		}
	}
		for(int i = 0; i < arraySize; i++)
	{
		for(int j = 0; j <= amount; j++)
			std::cout << array[i][j] << '\t';
		std::cout << std::endl;
	}
	return array[arraySize-1][amount];
}

int main()
{
	int coins[4]={2,3,5,10};
	std::cout << waysOfCoinsChange(coins, 15, 4) << std::endl;
}