#include <iostream>

class B_NODE
{
	public: 
		int data;
		B_NODE* left, *right;
};

class BST
{
	public:
		B_NODE *root;
		BST()
		{
			root = NULL;
		}
		
		B_NODE* get_new_node(int data)
		{
			B_NODE* newnode = new B_NODE;
			newnode->data = data;
			newnode->left = newnode->right = NULL;
			return newnode;
		}
		
		B_NODE* insert(B_NODE* root, int data)
		{
			if(root == NULL)
			{
				root = get_new_node(data);
			}
			else if(data <= root->data)
			{
				root->left = insert(root->left, data);
			}
			else
			{
				root->right = insert(root->right, data);
			}
			return root;
		}
		
		void inorder_traversal(B_NODE* root)
		{
			if(root == NULL)
				return;
			inorder_traversal(root->left);
			std::cout << root->data << std::endl;
			inorder_traversal(root->right);
		}
		
		void preorder_traversal(B_NODE* root)
		{
			if(root == NULL)
				return;
			std::cout << root->data << std::endl;
			preorder_traversal(root->left);
			preorder_traversal(root->right);
		}	
		
		void postorder_traversal(B_NODE* root)
		{
			if(root == NULL)
				return;
			postorder_traversal(root->left);
			postorder_traversal(root->right);
			std::cout << root->data << std::endl;
		}
		
		bool check_empty_tree()
		{
			return this->root == NULL;
		}
		
		B_NODE* Search(B_NODE* root, int data)
		{
			if(root == NULL) return NULL;
			else if(root->data == data) return root;
			else if(data <= root->data) return Search(root->left, data);
			else return Search(root->right, data);
		}
		
		int FindMin(B_NODE* root)
		{
			if(root == NULL)
			{
				std::cout << "\tTHE TREE IS EMPTY!!!" << std::endl;
				return NULL;
			}
			B_NODE* newnode = root;
			while(root->left != NULL)
			{
				root = root->left;
				if(root->data < newnode->data)
				{
					newnode = root;
				}
			}
			return newnode->data;
		}
		
		int FindMax(B_NODE* root)
		{
			if(root == NULL)
			{
				std::cout << "\tTHE TREE IS EMPTY!!!" << std::endl;
				return NULL;
			}
			B_NODE* newnode = this->root;
			while(root->right != NULL)
			{
				root = root->right;
				if(root->data > newnode->data)
				{
					newnode = root;
				}
			}
			return newnode->data;
		}	
		
		B_NODE* delete_node(B_NODE* rootD, int data, bool _repeated_deletion = false)
		{
			if(rootD == NULL)
			{
				std::cout << "\tITEM NOT FOUND!!!" << std::endl;
			}
			else if(data < rootD->data)
				rootD->left = delete_node(rootD->left, data);
			else if(data > rootD->data)
				rootD->right = delete_node(rootD->right, data);
			else
			{

				// case 1: No child case;
				if(rootD->left == NULL && rootD->right == NULL)
				{
					delete rootD;
					rootD = NULL;
					
				}
				// case 2: One child
				else if(rootD->left == NULL)
				{
					B_NODE* temp = rootD;
					rootD = rootD->right;
					delete temp;
				}
				else if(rootD->right == NULL)
				{
					B_NODE* temp = rootD;
					rootD = rootD->left;
					delete temp;
				}
				// case 3: Two Children
				else
				{
					int temp = FindMin(rootD->right);
					rootD->data = temp;
					rootD->right = delete_node(rootD->right, temp, true);
				}
				if(!_repeated_deletion)
				{
					std::cout << "\tData: " << data << " found in BST" << std::endl;
					std::cout << "\tData: " << data << " deleted successfully" << std::endl;
				}
			}
			return rootD;
		}
		
		void destroy_tree()
		{
			std::cout << "\tDESTROYING BINARY SEARCH TREE\n";
			this->root = NULL;
		}
		
};

int main()
{
	bool is_running = true;
	int choice;
	std::cout << "\n\t\tIMPLEMENTATION OF BINARY SEARCH TREE\n\tMENU\n\t1. Insert a new node\n\t2. Delete a node\n\t3. Pre-order traversal\n\t4. In-order traversal\n\t5. Post-order traversal\n\t6. Search\n\t7. Find minimum\n\t8. Find maximum\n\t9. Destroy a tree\n\t10. Exit\n\n";
	BST bst_tree;
	int temp_data;
	int result;
	while(is_running)
	{
		std::cout << "\n\tEnter the choice of operation: ";
		std::cin >> choice;
		switch(choice)
		{
			case 1: 
				//insert a new node;
				std::cout << "\tINSERT A NEW NODE\n";
				std::cout << "\tEnter the data to be inserted: ";
				std::cin >> temp_data;
				bst_tree.root = bst_tree.insert(bst_tree.root, temp_data);
				break;
				
			case 2:
				// delete a node
				if(!bst_tree.check_empty_tree())
				{
					std::cout << "\tDELETE A NODE\n";
					std::cout << "\tEnter the data to be deleted: ";
					std::cin >> temp_data;
					bst_tree.delete_node(bst_tree.root, temp_data);
				}
				else
				{
					std::cout << "\tGiven Binary Search Tree is empty!!!\n";
				}
				break;
				
			case 3:
				// pre-order traversal
				if(!bst_tree.check_empty_tree())
				{
					std::cout << "\tPREORDER TRAVERSAL\n";
					bst_tree.preorder_traversal(bst_tree.root);
				}
				else
				{
					std::cout << "\tGiven Binary Search Tree is empty!!!\n";
				}
				break;
				
			case 4:
				// in-order traversal
				if(!bst_tree.check_empty_tree())
				{
					std::cout << "\tINORDER TRAVERSAL\n";
					bst_tree.inorder_traversal(bst_tree.root);
				}
				else
				{
					std::cout << "\tGiven Binary Search Tree is empty!!!\n";
				}
				break;
				
			case 5:
				// post-order traversal
				if(!bst_tree.check_empty_tree())
				{
					std::cout << "\tPOSTORDER TRAVERSAL\n";
					bst_tree.postorder_traversal(bst_tree.root);
				}
				else
				{
					std::cout << "\tGiven Binary Search Tree is empty!!!\n";
				}
				break;
				
			case 6:
				// searching
				if(!bst_tree.check_empty_tree())
				{
					std::cout << "\tSEARCHING FOR DATA IN BST\n";
					std::cout << "\tEnter the data to be searched: ";
					std::cin >> temp_data;
					if(bst_tree.Search(bst_tree.root, temp_data) != NULL)
					{
						std::cout << "\t" << temp_data << " found in BST" << std::endl;
					}
					else
					{
						std::cout << "\t" << temp_data << " not found in BST" << std::endl;
					}
				}
				else
				{
					std::cout << "\tGiven Binary Search Tree is empty!!!\n";
				}
				break;
				
			case 7:
				// find minimum
				std::cout << "\tFINDING MINIMUM IN BST\n";
				result = bst_tree.FindMin(bst_tree.root);
				if(result != NULL)
				{
					std::cout << "\tThe minimum data found in given BST is: " << result << std::endl;
				}
				break;
				
			case 8:
				// find maximum
				std::cout << "\tFINDING MAXIMUM IN BST\n";
				result = bst_tree.FindMax(bst_tree.root);
				if(result != NULL)
				{
					std::cout << "\tThe maximum data found in given BST is: " << result << std::endl;
				}
				break;
				
			case 9:
				//destroy the tree 
				bst_tree.destroy_tree();
				break;
				
			case 10: 
				// exiting
				is_running = false;
				std::cout << "\tExiting...\n";
				break;
		}
	}
}