#include <bits/stdc++.h>

class Node
{
	public:
		int data;
		Node *left, *right;
};

Node* createBinaryTree()
{
	int num;
	Node* newNode = new Node;
	std::cin >> num;
	newNode->data = num;
	if(num == -1)
		return NULL;
	else
	{
		std::cout << "Enter the left child of: " << num << std::endl;
		newNode->left = createBinaryTree();
		std::cout << "Enter the right child of: " << num << std::endl;
		newNode->right = createBinaryTree();
		return newNode;
	}
}

int main()
{
	Node* root = createBinaryTree();
}