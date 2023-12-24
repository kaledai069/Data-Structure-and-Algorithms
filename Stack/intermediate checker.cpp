#include <iostream>
#include <string>
#include <math.h>
int exp_evaluator(std::string);

int main()
{
	std::string temp = "456";
	std::cout << exp_evaluator(temp) << std::endl;
	return 0;
}

int exp_evaluator(std::string str)
{
	if(str.length() == 1)
	{
		return int(str[0]) - 48;
	}
	else
	{
		int temp_result = 0;
		for(int i = 0; i < str.length(); i++)
		{
			temp_result += (int(str[i]) - 48) * pow(10, str.length()-1-i);
		}
		return temp_result;
	}
}