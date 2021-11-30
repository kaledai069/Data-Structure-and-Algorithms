#include <iostream>
#define SIZE 10

template <class T>
class Stack
{
	public:
		T *array;
		int index;
		
		Stack<T>()
		{
			array = new T[SIZE];
			index = -1;
		}
		void push(T value)
		{
			index++;
			*(array + index) = value;
		}
		T peek()
		{
			return array[index];
		}
		void pop()
		{
			index--;
			std::cout << "Item deleted" << std::endl;
		}
		void display_all()
		{
			if(index != -1)
			{
				for(int i = 0; i <= index; i++)
				{
					std::cout << array[i] << std::endl;
				}
				std::cout << std::endl;
			}
			else
			{
				std::cout << "Nothing to display at the moment" << std::endl;
			}
		}
};

int main()
{
	std::cout << "Hello world" << std::endl;
	Stack<double> new_stack;
	Stack<char> char_stack;
//	new_stack.push(6.9);
//	new_stack.push(69.69);
//	new_stack.push(69.36);
//	new_stack.push(69.52);
//	new_stack.pop();
//	new_stack.display_all();
	char_stack.push('h');
	char_stack.push('e');
	char_stack.push('l');
	char_stack.push('l');
	char_stack.push('o');
	char_stack.display_all();
	return 0;
}