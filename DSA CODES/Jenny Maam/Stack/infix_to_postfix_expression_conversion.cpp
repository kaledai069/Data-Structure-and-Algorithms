#include <iostream>
#include <string>
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

int main()
{
	Stack<char> infix_stack;
//	std::string exp = "k+l-m*n+(o^p)*w/u/v*t+q";
	std::string exp = "a-b+(m^n)*(o+p)-q/r^s*t+z";
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
						char temp;
						temp = infix_stack.peek();
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
						while(temp == '^')
						{
							final_result += temp;
							infix_stack.pop();
							temp = infix_stack.peek();
						}
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
	std::cout << final_result << std::endl;
	return 0;
}