#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<int>> graph_data=
{
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 1, 1, 0, 0, 0},	
	{0, 1, 0, 1, 0, 0, 0, 0},
	{0, 1, 1, 0, 1, 1, 0, 0},
	{0, 1, 0, 1, 0, 1, 0, 0},
	{0, 0, 0, 1, 1, 0, 1, 1},
	{0, 0, 0, 0, 0, 1, 0, 0},
	{0, 0, 0, 0, 0, 1, 0, 0},
};
std::queue<int> value_holder;
std::vector<int> visited(8, 0);

void BFS(int );

int main()
{
	BFS(1);
	BFS(2);
	BFS(3);
	BFS(4);
	BFS(5);
	BFS(6);
	BFS(7);
}

void BFS(int i)
{
	int u;
	std::cout << i << '\t';
	visited[i] = 1;
	value_holder.push(1);
	
	while(!value_holder.empty())
	{
		u = value_holder.back();
		value_holder.pop();
		for(int v = 1; v <= 7; v++)
		{
			if(graph_data[u][v] == 1 and visited[v]==0)
			{
				std::cout << v << '\t';
				visited[v] = 1;
				value_holder.push(v);
			}
		}
	}
	std::cout << std::endl;
	for(int i = 0; i < visited.size(); i++)
		visited[i] = 0;
}
