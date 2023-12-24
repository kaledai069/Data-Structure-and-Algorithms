#include <bits/stdc++.h>

int main()
{
	std::vector<std::pair<int, int>> activities;
	activities.push_back(std::pair<int, int>(12,25));
	activities.push_back(std::pair<int, int>(10,20));
	activities.push_back(std::pair<int, int>(20,30));
	activities.push_back(std::pair<int, int>(10,11));
	
	// sorting the activites according to the finish time
	std::sort(activities.begin(), activities.end(), [](std::pair<int,int> x, std::pair<int, int>  y){ return x.second < y.second;
	});
	
	std::vector<std::pair<int, int>> solution;
	solution.push_back(activities[0]);
	int posSoln = 0;
	for(int i = 1 ; i < activities.size(); i++)
	{
		
		if(activities[i].first >= solution[posSoln].second)
		{
			solution.push_back(activities[i]);
			posSoln++;
		}
	} 
	std::cout << solution.size() << std::endl;

}