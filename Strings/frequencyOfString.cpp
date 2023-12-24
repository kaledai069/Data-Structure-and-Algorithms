#include <bits/stdc++.h>

int main()
{
	std::map<char, int> stringMap;
	for(int i = 97; i <=122; i++)
	{
		stringMap[char(i)] = 0;
	}
	std::map<char, int>::iterator it = stringMap.begin();

	std::string testString = "alllksfhhasiiielawyyikaskdkfaasdfawwwwfsalsjdafasklfywkklks";
	for(auto str : testString)
	{
		stringMap[str]++;
	}

	int max = stringMap['a'];
	it = stringMap.begin();
	for(; it != stringMap.end(); ++it)
	{
		if(it->second > max)
			max = it->second;
	}
	it = stringMap.begin();
	for(; it!=stringMap.end(); it++)
	{
		std::cout << "CHAR: " << it->first << " VALUE: " << it->second << std::endl;
	}
	std::cout << "\n\nAnd the max count is: " << max << std::endl;
}