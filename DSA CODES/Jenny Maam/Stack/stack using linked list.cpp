#include <iostream>

class Stack
{
	class Node
	{
		public:
			int data;
			Node *next;	
	};
	public:

		Node *head, *newnode;
		Stack()
		{
			head = NULL;
		}
		void push(int value)
		{
			newnode = new Node;
			newnode->data = value;
			newnode->next = NULL;
			if(head == NULL)
			{
				head = newnode;
			}
			else
			{
				newnode->next = head;
				head = newnode;
			}
		}
		void display_all()
		{
			Node *temp;
			temp = head;
			while(temp != 0)
			{
				std::cout << temp->data << std::endl;
				temp = temp->next;
			}
		}
		void peek()
		{
			if(head == NULL)
			{
				std::cout << "No data input" << std::endl;
			}
			else
			{
				std::cout << head->data << std::endl;
			}
		}
		void pop()
		{
			Node* temp = head;
			head = temp->next;
			delete temp;
		}
};

int main()
{
	Stack new_stack;
	new_stack.push(78);
	new_stack.push(89);
	new_stack.push(69);
	new_stack.display_all();
	std::cout << "HELL YA" << std::endl;
	new_stack.pop();
	new_stack.display_all();
	return 0;
}