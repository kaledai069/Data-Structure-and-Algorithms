#include <iostream>
struct node
{
    int data;
    struct node *left, *right;
};


struct node * create();
void Preorder(struct node *root);
void Inorder(struct node *root);
void Postorder(struct node *root);
main()
{
    struct node *root = 0;
    root = create();
    std::cout << "Pre-Order is: " << "\t";
    Preorder(root);
    std::cout << std::endl;
    std::cout << "Inorder Traversal is: " << "\t";
    Inorder(root);
    std::cout << std::endl;
    std::cout << "Postorder Traversal is: " << "\t";
    Postorder(root);
}

void Postorder(struct node *root)
{
    if (root == 0) {return;}
    Postorder(root->left);
    Postorder(root->right);
    std::cout << root->data << "\t";
}

void Inorder(struct node *root)
{
    if (root == 0){ return;}
    Inorder(root->left);
    std::cout << root->data << "\t";
    Inorder(root->right);
}

struct node * create()
{
    int num;
    struct node *newnode;
    newnode = new struct node;
    std::cout << "Enter the item ('enter -1 for NO NODE'): " ;
    std::cin >> num;
    if (num == -1){ return 0;}
    newnode->data =  num;
    std::cout << "For left child of " << num << std::endl;
    newnode->left = create();
    std::cout << "For right child of " << num << std::endl;
    newnode->right = create();
    return newnode;
}

void Preorder(struct node *root)
{
    if (root == 0)
    { return; }
    std::cout << root->data << '\t';
    Preorder(root->left);
    Preorder(root->right);
}