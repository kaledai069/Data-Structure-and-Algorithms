#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <vector>
#define SIZE 100

template <typename T>
class Stack
{
	public:
		T *array;
		int top;
		
		Stack<T>()
		{
			array = new T[SIZE];
			top = -1;
		}
		void push(T value)
		{
			top++;
			*(array + top) = value;
		}
		T peek()
		{
			return array[top];
		}
		void pop()
		{
			top--;
		}
		void display_all()
		{
			if(top != -1)
			{
				for(int i = top; i >= 0 ; i--)
				{
					std::cout << array[i] << '\t';
				}
				std::cout << std::endl;
			}
			else
			{
				std::cout << "Nothing to display at the moment" << std::endl;
			}
		}
		bool empty()
		{
			return top == -1 ? true : false;
		}
};

std::string infix_to_prefix_parsher(std::string);

int main()
{
	std::string temp = "a-b+(m^n)*(o+p)-q/r^s*t+z";
	std::map<char, std::string> exp_map_data =
	{
		{'a', static_cast<std::string>("3")},
		{'b', static_cast<std::string>("2")},
		{'m', static_cast<std::string>("3")},
		{'n', static_cast<std::string>("2")},
		{'o', static_cast<std::string>("5")},
		{'p', static_cast<std::string>("7")},
		{'q', static_cast<std::string>("64")},
		{'r', static_cast<std::string>("3")},
		{'s', static_cast<std::string>("4")},
		{'t', static_cast<std::string>("9")},
		{'z', static_cast<std::string>("10")}
	};
	std::vector<std::string> expression;
	std::cout << infix_to_prefix_parsher(temp);
	for(char item : infix_to_prefix_parsher(temp))
	{
		if(exp_map_data.find(item) != exp_map_data.end()) // if the key value can be found in the above map
		{
			expression.push_back(exp_map_data[item]);
		}
		else
		{
			std::string temp(1, item);
			expression.push_back(temp);
		}
		
	}
	for(std::string item : expression)
	{
		std::cout << item << "\t";
	}
	std::cout << std::endl;
	return 0;
}

std::string infix_to_prefix_parsher(std::string exp)
{
	Stack<char> infix_stack;
	std::string final_result;
	for(int i = 0; i < exp.length(); i++)
	{
		if((int(exp[i]) > 64 and int(exp[i]) <= 90) or (int(exp[i]) >= 97 and int(exp[i]) <= 122))
		{
			final_result += exp[i];
		}
		else
		{
			switch(exp[i])
			{
				case '+':
				case '-':
					if(!infix_stack.empty())
					{
						char temp = infix_stack.peek();
						while(temp == '*' or temp == '/' or temp == '^')
						{
							final_result += temp;
							infix_stack.pop();
							temp = infix_stack.peek();
						}
						if(temp == '-' or temp == '+')
						{
							final_result += temp;
							infix_stack.pop();
							infix_stack.push(exp[i]);
						}
						else if(temp == '(')
						{
							infix_stack.push(exp[i]);
						}
					}
					else
					{
						infix_stack.push(exp[i]);
					}
					break;
					
				case '*':
				case '/':
					if(!infix_stack.empty())
					{
						char temp = infix_stack.peek();
						if(temp == '*' or temp == '/' or temp == '(')
						{
							final_result += temp;
							infix_stack.pop();
							infix_stack.push(exp[i]);
						}	
						else if(temp == '(' or temp == '+' or temp == '-')
						{
							infix_stack.push(exp[i]);
						}
						else if(temp == '^')
						{
							while(temp == '^')
							{
								final_result += temp;
								infix_stack.pop();
								temp = infix_stack.peek();
							}
						}
					}
					else
					{
						infix_stack.push(exp[i]);
					}
					break;
				case '(':
					infix_stack.push('(');
					break;
				case ')':
					while(infix_stack.peek() != '(')
					{
						final_result.push_back(infix_stack.peek());
						infix_stack.pop();	
					} 
					infix_stack.pop();
					break;
				case '^':
					infix_stack.push('^');
					break;
			}
		}
	}
	while(!infix_stack.empty())
	{
		final_result += infix_stack.peek();
		infix_stack.pop();
	}
	return final_result;
}













