#include <iostream>
#include <vector>
struct node
{
    int data;
    struct node *next;
};
struct node *top = 0, *newnode, *temp;

void push(int);
void display();
void pop();
void peek();
main()
{
    push(45);
    push(98);
    pop();
    push(69);
    peek();
    // display();
}

void peek()
{
    std::cout << top->data << std::endl;
}

void pop()
{
    temp = top;
    top = top->next;
    delete temp;
}
void display()
{
    temp = top;
    while(temp != 0)
    {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }
}

void push(int num)
{
    newnode = new struct node;
    newnode->data = num;
    newnode->next = top;
    top = newnode;
}