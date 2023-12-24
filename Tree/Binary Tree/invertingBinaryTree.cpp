#include <bits/stdc++.h>

class Node
{
	public:
		int data;
		Node *left, *right;
};

static int index = 0;
int arr[] = {4, 2, 1 -1, -1, 3, 7, 6, -1, -1, 9, -1, -1};

Node* createBinaryTree()
{
	int num;
	Node* newNode = new Node;
	num = arr[index];
	++index;
	std::cout << num << std::endl;
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

void invertBinaryTree(Node** rootRef)
{
	Node *root = *rootRef;
	if(!(root->left->left == NULL && root->right->left == NULL))
	{
		return ;
	}
	invertBinaryTree(&(root->left));
	int temp = root->left->data;
	root->left->data = root->right->data;
	root->right->data = temp;
	invertBinaryTree(&(root->right));
	std::cout << "Abey Chutiye" << std::endl;
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

int main()
{
	Node* root = createBinaryTree();
	invertBinaryTree(&root);
	inorderTraversal(root);
}