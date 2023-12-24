#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>
#define SIZE 100

// 234*+1623^/-

int converter(int, int, char);
int exp_evaluator(std::string);
double power(int, int);

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


int main()
{
	std::vector<std::string> expression = {"2", "3", "4", "*", "+", "16", "2", "3", "^", "/", "-"};
	Stack<std::string> convo_stack;
	for(std::string temp : expression)
	{
		if(int(temp[0]) >= 48 and int(temp[0]) <= 57)
		{
			convo_stack.push(temp);
		}
		else if(temp.length() > 1)
		{
			if(int(temp[0]) >= 48 and int(temp[0]) <= 57)
			{
				convo_stack.push(temp);
			}
		}
		else // for the operator part
		{
			int temp2 = exp_evaluator(convo_stack.top_n_pop());
			int temp1 = exp_evaluator(convo_stack.top_n_pop());
			convo_stack.push(std::to_string(converter(temp1, temp2, temp[0])));
		}
	}
	std::cout << "EVALUATION: " << convo_stack.top_n_pop() << std::endl;
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








