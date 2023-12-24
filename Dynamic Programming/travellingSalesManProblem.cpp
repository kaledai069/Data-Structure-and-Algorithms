#include <bits/stdc++.h>

// Gloabally Available data
std::vector<std::vector<int>> graph
	{
		{0, 16, 11, 6},
		{8, 0, 13, 16},
		{4, 7, 13, 16},
		{5, 12, 2, 0}
	};
std::vector<char>::iterator it;

int travelling(int i, std::vector<char> setV)
{
	if(setV.size() == 0)
	{
		return graph[i][0];
	}
	for(int j = i+1; j < setV.size(); j++)
	{
		int weight = graph[i][j];
		it = std::find(setV.begin(), setV.end(), setV[i]);
		setV.erase(it);
		return std::min(weight, travelling(i+1, setV));
	}
}


int main()
{
	
	std::vector<char> setOfVertices{'A', 'B', 'C', 'D'};
	char startingVertex = 'A';
	int finalSum;
	finalSum =  travelling(0, setOfVertices);
	std::cout << finalSum << std::endl;
}