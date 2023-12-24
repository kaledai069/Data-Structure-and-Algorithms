#include <bits/stdc++.h>

int main()
{
	std::string st = "so, clear the chat";
	std::string result;
	for(int i = st.size()-1; i>=0; i--)
	{
		result += st[i];
	}
	std::cout << result << std::endl;
}