#include <iostream>

struct node
{
	int data;
	struct node *next;
};

int main()
{
struct node *head, *newnode, *temp;
	head = NULL;
	
	for(int i = 0; i < 5; i++)
	{
		newnode = new struct node;
		std::cout << "Enter the number: ";
		std::cin >> newnode->data;
		newnode->next = 0;
		if(head == 0)
		{
			head = temp = newnode;
		}
		else
		{
			temp->next = newnode;
			temp = newnode;
		}
	}
	
	std::cout << "Linked list successfully created!!!" << std::endl;
	
	temp = head;
	while(temp != 0)
	{
		std::cout << temp->data << "	\n";
		temp = temp->next;
	}
	
	return 0;
}