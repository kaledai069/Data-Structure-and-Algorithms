#include <iostream>

class NODE
{
	public:
		int data;
		NODE* left, *right;
};

NODE* FindMin(NODE* root)
{
	NODE* newnode = root;
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

NODE* Delete(NODE* root, int data)
{
	if(root == NULL) return root;
	else if(data < root->data)
		root->left = Delete(root->left, data);
	else if(data > root->data)
		root->right = Delete(root->right, data);
	else
	{
		// case 1: No child case;
		if(root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
		}
		// case 2: One child
		else if(root->left == NULL)
		{
			NODE* temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL)
		{
			NODE* temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: Two Children
		else
		{
			NODE* temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
		return root;
	}
}

int main()
{
	
}