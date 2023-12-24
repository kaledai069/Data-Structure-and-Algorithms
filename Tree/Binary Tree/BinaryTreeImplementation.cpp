#include <bits/stdc++.h>

struct node
{
	int data;
	node *left, *right;
};

node* create()
{
	int num;
	node* newNode = new node;
	std::cin >> num;
	newNode->data = num;
	if(num == -1)
		return NULL;
	else
	{
		std::cout << "Enter left child of: " << num << std::endl;
		newNode->left = create();
		std::cout << "Enter the right child of: " << num << std::endl;
		newNode->right = create();
		return newNode;
	}
}
int main()
{
	node* root;
	root = create();
}