#include <bits/stdc++.h>

int minCoinChange(std::vector<int> coins, int amount)
{
	int array[coins.size()][amount+1];
	for(int i = 0; i < coins.size(); ++i)
	{
		for(int j = 0; j <= amount; ++j)
		{
			if(i == 0)
			{
				if(j % coins[i] == 0) array[i][j] = j/coins[i];			
			}	
			else if(j == 0) array[i][j] = 0;
			else if(coins[i] > j) array[i][j] = array[i-1][j];
			else if(coins[i] <= j)	array[i][j] = std::min(array[i-1][j], 1 + array[i][j - coins[i]]);
		}
	}
	for(int i = 0; i < coins.size(); i++)
	{
		for(int j = 0; j <= amount; j++)
			std::cout << array[i][j] << ' ';
		std::cout <<  std::endl;	
	}
	
	//the minM coins used 
	int i = coins.size()-1;
	int j = amount;
	std::vector<int> coinsUsed;
	while(array[i][j] != 0 || array[i][j] != array[i-1][j] )
	{
		if(array[i][j] != array[i-1][j])
		{
			coinsUsed.push_back(coins[i]);
			j = abs(array[i-1][j] - coins[i]);
		}
		else i = i-1;
		if(i == 0)
			break;
	}
	
	for(auto item : coinsUsed)
		std::cout << item << '\t';
	std::cout << std::endl;
		
	return array[coins.size()-1][amount];

}

int main()
{
	std::vector<int> coins = {1,3,7,13,19,23};
	int amount = 47;
	std::cout << minCoinChange(coins, amount) << std::endl;
	
}