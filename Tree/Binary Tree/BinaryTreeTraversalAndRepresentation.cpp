#include <bits/stdc++.h>

class Node
{
	public:
		int data;
		Node *left, *right;	
};

Node* creatBinaryTree()
{
	int num;
	Node* newNode = new Node;
	std::cin >> num;
	newNode->data = num;
	if(num == -1)
		return NULL;
	else
	{
		std::cout << "Enter the left node of: " << num << std::endl;
		newNode->left = creatBinaryTree();
		std::cout << "Enter the righ node of: " << num << std::endl;
		newNode->right = creatBinaryTree();
		return newNode;
	}
}

void inorderTraversal(Node *root)
{
	if(root == 0)
	{
		return ;
	}
	inorderTraversal(root->left);
	std::cout << root->data << '\t';
	inorderTraversal(root->right);
}

void preOrderTraversal(Node *root)
{
	if(root == 0) return;
	std::cout << root->data << '\t';
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
	if(root == 0) return ;
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	std::cout << root->data  << '\t';
}

int main()
{
	Node* root = creatBinaryTree();
	inorderTraversal(root);
	std::cout << std::endl;
	preOrderTraversal(root);
	std::cout << std::endl;
	postOrderTraversal(root);
}






