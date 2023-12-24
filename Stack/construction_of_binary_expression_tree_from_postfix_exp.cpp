#include <iostream>
#include <string>
#include <vector>
#include <map>
#define LOG(X) std::cout << X << std::endl
#define SIZE 100

template <typename T>
class Stack
{
	public:
		T *array;
		int top;
		
		Stack<T>()
		{
			array = new T[SIZE];
			top = -1;
		}
		void push(T value)
		{
			top++;
			*(array + top) = value;
		}
		T peek()
		{
			return array[top];
		}
		void pop()
		{
			top--;
		}
		void display_all()
		{
			if(top != -1)
			{
				for(int i = top; i >= 0 ; i--)
				{
					std::cout << array[i] << '\t';
				}
				std::cout << std::endl;
			}
			else
			{
				std::cout << "Nothing to display at the moment" << std::endl;
			}
		}
		bool empty()
		{
			return top == -1 ? true : false;
		}
		T top_n_pop()
		{
			T temp = this->peek();
			this->pop();
			return temp;
		}
};

class Node
{
	public:
		char data;
		Node* left;
		Node* right;
};

void postorder_traversal(Node*);
void preorder_traversal(Node*);

int main()
{
	std::string postfix_exp = "ab*c/ef/g*+k+xy*-";
	Stack<Node*> node_stack;
	Node* newnode, *temp;
	for(int i = 0; i < postfix_exp.length(); i++)
	{
		if(int(postfix_exp[i]) >= 97 && int(postfix_exp[i]) <= 122)
		{
			newnode = new Node;
			newnode->data = postfix_exp[i];
			newnode->left = NULL;
			newnode->right = NULL;
			node_stack.push(newnode);
		}
		else // if the operator is encountered
		{
			newnode = new Node;
			newnode->data = postfix_exp[i];
			newnode->right = node_stack.top_n_pop();
			newnode->left = node_stack.top_n_pop();
			node_stack.push(newnode);
		}
	}
	postorder_traversal(node_stack.peek());
	LOG('\n');
	preorder_traversal(node_stack.peek());
	LOG('\n');
}

void postorder_traversal(Node* root)
{
	if(root == NULL)
	{
		return;
	}
	postorder_traversal(root->left);
	postorder_traversal(root->right);
	std::cout << root->data << "  ";
}
void preorder_traversal(Node* root)
{
	if(root == NULL)
	{
		return;
	}
	std::cout << root->data << "  ";
	postorder_traversal(root->left);
	postorder_traversal(root->right);
}