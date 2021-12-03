#include <iostream>
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
		T top_n_pop()
		{
			T temp = this->peek();
			this->pop();
			return temp;
		}
};

std::map<char, std::string> exp_map_data =
{
	{'a', static_cast<std::string>("3")},
	{'b', static_cast<std::string>("2")},
	{'m', static_cast<std::string>("3")},
	{'n', static_cast<std::string>("2")},
	{'o', static_cast<std::string>("5")},
	{'p', static_cast<std::string>("7")},
	{'q', static_cast<std::string>("64")},
	{'r', static_cast<std::string>("2")},
	{'s', static_cast<std::string>("3")},
	{'t', static_cast<std::string>("9")},
	{'z', static_cast<std::string>("10")}
};

std::string reverse_string(std::string);
std::string infix_to_prefix_parsher(std::string);
int converter(int, int, char);
int exp_evaluator(std::string);
std::vector<std::string> prefix_to_map_parsher(std::string);
std::string prefix_evaluator(std::vector<std::string> );

int main()
{
	std::string temp_exp = "a-b+(m^n)*(o+p)-q/r^s*t+z";
	std::vector<std::string> expression = prefix_to_map_parsher(reverse_string(temp_exp));
	std::cout << infix_to_prefix_parsher(reverse_string(temp_exp)) << std::endl;
	for(std::string item : expression)
	{
		std::cout << item << std::endl;
	}
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
						if(temp == '-' or temp == '+' or temp == ')')
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
						while(temp == '^')
						{
							final_result += temp;
							infix_stack.pop();
							temp = infix_stack.peek();
						}
						if(temp == '*' or temp == '/' or temp == ')' or temp == '+' or temp == '-')
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
				case ')':
					infix_stack.push(')');
					break;
				case '(':
					while(infix_stack.peek() != ')')
					{
						final_result.push_back(infix_stack.peek());
						infix_stack.pop();	
					} 
					infix_stack.pop();
					break;
				case '^':
					infix_stack.push(exp[i]);
					break;	
		}
	}
}
	while(!infix_stack.empty())
	{
		final_result += infix_stack.peek();
		infix_stack.pop();
	}
	return reverse_string(final_result);
}


std::string reverse_string(std::string temp_string)
{
	std::string temp_result;
	for(int i = temp_string.length(); i >= 0; i--)
	{
		temp_result.push_back(temp_string[i]);	
	}
	return temp_result;
}

std::string prefix_evaluator(std::vector<std::string> expression)
{
	Stack<std::string> convo_stack;
	for(int i = expression.size()-1; i >= 0; i--)
	{
		if(int(expression[i][0]) >= 48 and int(expression[i][0]) <= 57)
		{
			convo_stack.push(expression[i]);
		}
		else if(expression[i].length() > 1)
		{
			if(int(expression[i][0]) >= 48 and int(expression[i][0]) <= 57)
			{
				convo_stack.push(expression[i]);
			}
		}
		else // for the operator part
		{
			int temp1 = exp_evaluator(convo_stack.top_n_pop());
			int temp2 = exp_evaluator(convo_stack.top_n_pop());
			convo_stack.push(std::to_string(converter(temp1, temp2, expression[i][0])));
		}
	}
	std::cout << convo_stack.peek() << std::endl;
	return convo_stack.top_n_pop();
}


std::vector<std::string> prefix_to_map_parsher(std::string temp)
{
	std::vector<std::string> expression;
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
	return expression;
}

int converter(int a, int b, char op)
{
	switch(op)
	{
		case '+':
			return a + b;
			break;
		case '-':
			return a - b;
			break;
		case '/':
			return a / b;
			break;
		case '^':
			return pow(a, b);
			break;
		case '*':
			return a * b;
			break;
	}
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














