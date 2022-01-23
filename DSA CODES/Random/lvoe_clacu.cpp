#include <iostream>
#include <map>
#include <vector>
#include <string>

int main()
{
	std::map<char, int> map_data;
	std::string result, first_name, second_name;
	
	std::cout << "Enter First Name: ";
	std::cin >> first_name;
	std::cout << "Enter Second Name: ";
	std::cin >> second_name;
	
	std::string prepared_name = first_name + "loves" + second_name;
	for(char s : prepared_name)
		map_data[s]++;
		
	for(std::map<char,int>::iterator it = map_data.begin(); it != map_data.end(); it++)
		result += std::to_string(it->second).c_str();
	
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
	std::cout << result << std::endl;
}