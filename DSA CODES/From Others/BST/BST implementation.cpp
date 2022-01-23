#include <iostream>
#include <vector>

class BSTNODE
{
	public:
		int data;
		BSTNODE *left, *right;
};

BSTNODE* GetNewNode(int data)
{
	BSTNODE* newnode = new BSTNODE;
	newnode->data = data;
	newnode->left = newnode->right = NULL;
	return newnode;
}

BSTNODE* Insert(BSTNODE* root, int data)
{
	if(root == NULL)
	{
		root = GetNewNode(data);
	}
	else if(data <= root->data)
	{
		root->left = Insert(root->left, data);
	}
	else
	{
		root->right = Insert(root->right, data);
	}
	return root;
}

void Traversal(BSTNODE* root)
{
	if(root == NULL)
		return;
	Traversal(root->left);
	std::cout << root->data << std::endl;
	Traversal(root->right);
}

BSTNODE* Search(BSTNODE* root, int data)
{
	if(root == NULL) return NULL;
	else if(root->data == data) return root;
	else if(data <= root->data) return Search(root->left, data);
	else return Search(root->right, data);
}

BSTNODE* FindMin(BSTNODE* root)
{
	BSTNODE* newnode = root;
	while(root->left != NULL)
	{
		root = root->left;
		if(root->data < newnode->data)
		{
			newnode = root;
		}
	}
	return newnode;
}


int main()
{
	BSTNODE *root = NULL;
	std::vector<int> vec_data = {18, 10, 26, 5, 20, 30, 4, 6, 25};
//	root = Insert(root, 15);
//	root = Insert(root, 10);
//	root = Insert(root, 20);
	for(int item : vec_data)
	{
		root = Insert(root, item);
	}
	Traversal(root);
	
//	std::cout << "Enter the item to be searched: ";
//	int temp;
//	std::cin >> temp;
//	std::cout << Search(root, temp)->data;
	BSTNODE* tempPtr = FindMin(root);
	std::cout << tempPtr->data << std::endl;
}
