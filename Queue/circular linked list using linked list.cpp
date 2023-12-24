#include <iostream>
struct node
{
    int data;
    struct node *next;
};
struct node *front = 0, *rear = 0, *newnode, *temp;

void enqueue(int num);
void dequeue();
void display();

main()
{
    enqueue(69);
    enqueue(100);
    enqueue(56);
    display();
    dequeue();
    display();
}

void display()
{
    temp = front;
    while (temp->next != front)
    {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }
    std::cout << temp->data << std::endl;
}

void dequeue()
{
    temp = front;
    if (front == 0 && rear == 0)
    {
        std::cout << "The queue is empty" << std::endl;
    }
    else if(front == rear)
    {
        front = rear = 0;
        delete temp;
    }
    else
    {
        front = front->next;
        rear->next = front;
        delete temp;
    }
    
}
void enqueue(int num)
{
    newnode = new struct node;
    newnode->data = num;
    newnode->next = 0;
    if (front == 0 && rear == 0)
    {
        front = rear = newnode;
        newnode->next = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
    
}