#include <bits/stdc++.h>
#define LOG(X) std::cout << X << std::endl;

int main()
{
	std::vector<std::pair<int, int>> items = 
	{
		std::pair<int, int>(50, 600),
		std::pair<int, int>(20, 500),
		std::pair<int, int>(30, 400)
	};
	int knapsackCapacity = 70;
	std::sort(items.begin(), items.end(), [](std::pair<int, int> x, std::pair<int, int> y){
		return (x.second/x.first) > (y.second/y.first);
	});
	for(auto item : items)
	{
		LOG(item.first);
	}
	int res = 0;
	for(auto pair : items)
	{
		if(pair.first <= knapsackCapacity)
		{
			knapsackCapacity -= pair.first;
			res += pair.second;
		}
		else
		{
			res += pair.second * float(knapsackCapacity)/pair.first;
		}
		
	}
	
	LOG(res);
}