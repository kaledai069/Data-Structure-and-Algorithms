#include <iostream>


class Linked_List
{
	private:
		class Node
		{
			public:
				int data;
				Node* next;
		};
	public:
	
		Node *newnode, *head, *temp;
		Linked_List()
		{
			head = NULL;
		}
		
		void push(int value)
		{
			newnode = new Node;
			newnode->data = value;
			newnode->next = NULL;
			if(head == 0)
			{
				head = temp = newnode;
			}
			else
			{
				temp->next = newnode;
				temp = temp->next; 
			}
		}
		void display_data()
		{
			temp = head;
			while(temp != 0)
			{
				std::cout << temp->data << std::endl;
				temp = temp->next;
			}
		}		
};

int main()
{
	Linked_List l1;
	l1.push(69);
	l1.push(36);
	l1.display_data();
	return 0;
}