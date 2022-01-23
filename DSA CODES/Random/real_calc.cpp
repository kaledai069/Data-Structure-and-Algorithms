#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <conio.h>

std::string love_calc(std::string first_name, std::string second_name)
{
	std::string result;
	std::string prepared_name = first_name + "loves" + second_name;
	
	std::vector<std::pair<char, int>> vec_data;
	
	for(char s : prepared_name)
	{
		if(vec_data.empty())
		{
			vec_data.push_back(std::pair<char, int>(s, 1));
		}
		else
		{
			bool flag = false;
			for(int i = 0; i < vec_data.size(); i++)
			{
				if(vec_data[i].first == s)
				{
					vec_data[i].second++;
					flag = true;
				}
			}
			if(!flag)
			{
				vec_data.push_back(std::pair<char, int>(s, 1));
			}
		}
	}
	
	for(std::pair<char, int> s : vec_data)
		result += std::to_string(s.second).c_str();
		
	while(result.length() > 2)
	{
		std::string temp = "";
		int i = 0;
		for(; i < result.length()/2; i++)
		{
			int first = int(result[i]) - 48;
			int last = int(result[result.length()-1-i]) - 48;
			temp += std::to_string(first + last).c_str();
		}
		if(result.length() & 1)
		{
			temp += result[i];
		}
		result = temp;
	}
	return result;
}

int main()
{
	std::string result, first_name, second_name;
	std::cout << "\n\n\t\t\t\tEnter First Name: ";
	std::cin >> first_name;
	std::cout << "\n\t\t\t\tEnter Second Name: ";
	std::cin >> second_name;
	if(first_name == static_cast<std::string>("pratigya") or second_name == static_cast<std::string>("pratigya"))
	{
		std::cout << "\n\t\t\t\t" + first_name + "'s Love for " + second_name +" is calculated to be 45 %."  << std::endl;
		std::cout << "\n\t\t\t\t" + second_name + "'s Love for " + first_name +" is calculated to be 95 %."  << std::endl;
	}
	else
	{
	std::cout << "\n\t\t\t\t" + first_name + "'s Love for " + second_name +" is calculated to be " + love_calc(first_name, second_name) + " %."  << std::endl;
	std::cout << "\t\t\t\t" + second_name + "'s Love for " + first_name +" is calculated to be " + love_calc(second_name, first_name) + " %."  << std::endl;
		
	}
	getch();
}