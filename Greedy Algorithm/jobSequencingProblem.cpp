#include <bits/stdc++.h>
#define LOG(x) std::cout << x << std::endl;

int main()
{
//	std::vector<std::pair<int, int>> jobs
//	{
//		std::pair<int, int> (2, 100),
//		std::pair<int, int> (1, 50),
//		std::pair<int, int> (2, 10),
//		std::pair<int, int> (1, 20),
//		std::pair<int, int> (3, 30)
//	};
	std::vector<std::pair<int,int>> jobs
	{
		std::pair<int, int> (4,50),	
		std::pair<int, int> (1,5),
		std::pair<int, int> (1,20),
		std::pair<int, int> (5,10),
		std::pair<int, int> (5,80)
	};
	int timeSlot = jobs[0].first;
	for(auto jobP : jobs)
	{
		if(jobP.first > timeSlot)
			timeSlot = jobP.first;
	}
	std::vector resVec(timeSlot, 0);
	std::sort(jobs.begin(), jobs.end(), [](std::pair<int, int> x, std::pair<int, int> y){
		return x.second > y.second;
	});
//	for(int i = 0; i < timeSlot; ++i)
//	{
//		if(resVec[jobs[i].first-1] == 0)
//			resVec[jobs[i].first-1] = jobs[i].second;
//	}
	for(auto jobPair : jobs)
	{	
		if(resVec[jobPair.first-1] == 0)	
			resVec[jobPair.first-1] = jobPair.second;
		else
		{
			for(int j = 0; j < jobPair.first-1; j++)
			{
				if(resVec[j] == 0)
				{
					resVec[j] = jobPair.second;
				}
				LOG(resVec[j]);
			}
		 } 
	}
	for(auto item : resVec)
		LOG(item);
	LOG(std::accumulate(resVec.begin(), resVec.end(), 0)); 
}