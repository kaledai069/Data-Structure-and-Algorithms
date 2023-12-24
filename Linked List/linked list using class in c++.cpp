#include <iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node* next;
};

int main()
{
	Node* head, *newnode, *temp;
	head = NULL;
	for(int i = 0; i < 5; i++)
	{
		newnode = new Node;
		cout << "Enter the number: ";
		cin >> newnode->data;
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
	temp = head;
	while(temp != 0)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
	return 0;
}