#include <iostream>

class Node
{
	public:
		int data;
		Node *left;
		Node *right;
};

void insert(Node* root, Node* node)
{
	if(node->data < root->data)
		insert(root->left, node);
	else
		insert(root->right, node);
}

Node* head = 0;

int main()
{
	Node* newnode;
	bool is_running = true;
	for(int i = 0; i < 5; i++)
	{
		newnode = new Node;
		std::cout << "Enter the data: ";
		std::cin >> newnode->data;
		newnode->left = NULL;
		newnode->right = NULL;
		if(head == 0) // for the root node then this happens
		{
			head = newnode;
		}
		else
		{
			insert(head, newnode);
		}
	}
}