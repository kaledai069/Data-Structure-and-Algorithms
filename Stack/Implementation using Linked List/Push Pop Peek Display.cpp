#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *top = 0, *newnode, *temp;

void push(int);
void pop();
void peek();
void display();

main()
{
    push(4);
    push(6);
    push(9);
    display();
    cout << "After popping out some items from the linked list" << endl;
    pop();
    display();
    cout << "Peeking the topmost value from the stack" << endl;
    peek();
}
void peek()
{
    cout << top->data << endl;
}

void pop()
{
    temp = top;
    top = top->next;
    delete temp;
}
void push(int num)
{
    newnode = new struct node;
    newnode->data = num;
    newnode->next = top;
    top = newnode;
}

void display()
{
    temp = top;
    while (temp != 0)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}