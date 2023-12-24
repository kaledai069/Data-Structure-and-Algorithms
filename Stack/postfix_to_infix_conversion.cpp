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
		T top_n_pop()
		{
			T temp = this->peek();
			this->pop();
			return temp;
		}
};

std::string postfix_to_infix_conversion(std::string);

int main()
{
	std::string infix_expression = "ab+ef/*";
	std::string result = postfix_to_infix_conversion(infix_expression);
	std::cout << result << std::endl;
	return 0;
}

std::string postfix_to_infix_conversion(std::string exp)
{
	Stack<std::string> temp_stack;
	std::string temp_result;
	for(int i = 0; i < exp.length(); i++)
	{
		if(int(exp[i]) >= 97 && int(exp[i]) <= 122)
		{
			std::string temp(1, exp[i]);
			temp_stack.push(temp);
		}
		else
		{
			std::string temp2 = temp_stack.top_n_pop();
			std::string temp1 = temp_stack.top_n_pop();
			temp_result = temp1 + exp[i] + temp2;
			temp_stack.push(temp_result);
		}
	}
	return temp_stack.top_n_pop();
}