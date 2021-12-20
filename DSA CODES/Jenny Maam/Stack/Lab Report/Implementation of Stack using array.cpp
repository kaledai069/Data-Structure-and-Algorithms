#include <iostream>
#define SIZE 5

template <class T>
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
		
		bool isEmpty()
		{
			return top == -1;
		}
		
		bool isFull()
		{
			return top == SIZE - 1;
		}
		void push(T value)
		{
			if(this->isFull())
			{
				std::cout << "STACK OVERFLOW" << std::endl;
			}
			else
			{
				array[++top] = value;
				std::cout << "Element pushed successfully." << std::endl;
			}
		}
		
		T TOS()
		{
			if(this->isEmpty())
			{
				std::cout << "STACK IS EMPTY" << std::endl;
				return static_cast<T>(0);
			}
			else
			{
				return array[top];
			}
		}
		
		void pop()
		{
			if(this->isEmpty())
			{
				std::cout << "STACK UNDERFLOW" << std::endl;
			}
			else
			{
				std::cout << "Element to be deleted: " << array[top--] << std::endl;
				std::cout << "Element deleted successfully." << std::endl;
			}
		}
		
		void display_all()
		{
			if(!this->isEmpty())
			{
				std::cout << "All the elements in the stack are: " << std::endl;
				for(int i = top; i >= 0; i--)
				{
					std::cout << array[i] << std::endl;
				}
				std::cout << std::endl;
			}
			else
			{
				std::cout << "STACK IS EMPTY" << std::endl;
			}
		}
		~Stack()
		{
			delete []array;
		}
};

int main()
{
	bool isRunning = true;
	Stack<int> int_stack;
	std::cout << "\nOperations On Stack\n1. Push Element\n2. Pop Element\n3. Display All The Elements\n4. Display Top Element\n5. Exit\n";
	while(isRunning)
	{
		int choice = 0;
		std::cout << "\nEnter the index of operation: ";
		std::cin >> choice;
		switch(choice)
		{
			case 1:
				int temp;
				std::cout << "Enter the element to be pushed: ";
				std::cin >> temp;
				int_stack.push(temp);
				break;
			case 2:
				int_stack.pop();
				break;
			case 3:
				int_stack.display_all();
				break;
			case 4:
				std::cout << "The top of the stack is: " << int_stack.TOS() << std::endl;
				break;
			case 5:
				isRunning = false;
				break;
		}
	}
	return 0;
}