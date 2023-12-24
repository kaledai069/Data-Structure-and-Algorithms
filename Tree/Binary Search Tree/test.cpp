#include <iostream>
#include <vector>

int main()
{
	std::vector<std::vector<int>> data(4, std::vector<int>(4, 0));
	for(std::vector<int> item : data)
	{
		for(int i : item)
			std::cout << i << std::endl;
	}
}