#include <iostream>
#define N 5
int queue[N];
int front = -1, rear = -1;
struct node 
{
    int data;
    struct node *next;
};
struct node *newnode, *temp, *frontl =0 , *rearl = 0;
void enqueueLL(int num);
void displayLL();
void dequeueLL();
void enqueue(int num);
void dequeue();
void display();
main()
{
    // implementation and operation on queue using classic c++ array
    // enqueue(12);
    // enqueue(69);
    // enqueue(45);
    // dequeue();
    // display();

    //implementation and operation on queue using linked list
    // enqueueLL(12);
    // enqueueLL(45);
    // enqueueLL(69);
    // dequeueLL();
    // displayLL();

    
}

void dequeueLL()
{
    temp = frontl;
    frontl = frontl->next;
    delete temp;
}

void displayLL()
{
    temp = frontl;
    while (temp != 0)
    {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }
}

void enqueueLL(int num)
{
    newnode = new struct node;
    newnode->data = num;
    newnode->next = 0;
    if (frontl == 0  && rearl == 0)
    {
        frontl = rearl = newnode;
        newnode->next = frontl;
    }
    else
    {
        rearl->next = newnode;
        rearl = newnode;
        rearl->next = frontl;
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        std::cout << "Underflow condition" <<std::endl;
    }
    else if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    } 
}

void display()
{
    if (front == -1 && rear == -1)
    {
        std::cout << "The given queue is empty" << std::endl;
    }
    else
    {
        for(int i = front; i < rear+1; i++)
        {
            std::cout << queue[i] << std::endl;
        }
    }   
}

void enqueue(int num)
{
    if(rear == N-1)
    {
        std::cout << "Overflow condition" << std::endl;
    }
    else if(front == -1 && rear == -1)
    {
        front=rear= 0;
        queue[rear] = num;
    }
    else
    {
        queue[++rear] = num;
    }   
}