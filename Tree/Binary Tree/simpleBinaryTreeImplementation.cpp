#include <iostream>
struct node
{
    int data;
    struct node *left, *right;
};
struct node *newnode, *root = 0;
struct node *create();

main()
{
    root = create();
}

struct node *create()
{
    int num;
    newnode = new struct node;
    std::cout << "Enter the value( 'enter -1 for NONODE' ): ";
    std::cin >> num;
    if (num == -1){ return 0;}
    newnode->data = num;
    std::cout << "For left child of " << num << std::endl;
    newnode->left = create();
    std::cout << "For right child of " << num << std::endl;
    newnode->right = create();
    return newnode;
}