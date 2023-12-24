#include <iostream>
struct node
{
    int data;
    struct node *next;
};
struct node *temp, *newnode, *front = 0, *rear = 0;

void enqueue(int num);
void dequeue();
void display();

main()
{
    enqueue(45);
    enqueue(69);
    enqueue(99);
    dequeue();
    display();
}

void dequeue()
{
    temp = front;
    front = front->next;
    delete temp;
}

void display()
{
    temp = front;
    while(temp != 0)
    {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }
}

void enqueue(int num)
{
    newnode = new struct node;
    newnode->data = num;
    newnode->next = 0;
    if(front == 0 && rear == 0)
    {
        front = rear = newnode;
    }
    else{
        rear->next = newnode;
        rear = newnode;
    }
}





