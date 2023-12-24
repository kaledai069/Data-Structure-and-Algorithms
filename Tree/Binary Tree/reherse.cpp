#include <iostream>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};


struct node *create();
struct node * passData();
int main()
{
    struct node *root;
    root = create();
    std::cout << root->data << std::endl;
    std::cout << root->left->data << std::endl;
    std::cout << root->right->data << std::endl;
}

struct node *create()
{
    int num ;
    struct node *newnode;
    newnode = new struct node;
    std::cout << "Enter the num: " ;
    std::cin >> num;

    if (num == -1)
    {
        return 0;
    }
    newnode->data = num;
    std::cout << "The root value: " << newnode->data << std::endl;
    std::cout << "For left node of "<< num<< std::endl;
    newnode->left = create();
    std::cout << "For right node of "<< num << std::endl;
    newnode->right = create();
    std::cout << "The initial node: " << newnode << std::endl;
    std::cout << "The root value: " << newnode->data << std::endl;

    return newnode;
}


