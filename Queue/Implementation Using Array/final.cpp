#include <iostream>
#define N 5
int queue[N];
int front = -1;
int rear = -1;
void enqueue(int num);
void dequeue();
void display();


main()
{
    enqueue(5);
    enqueue(15);
    dequeue();
    enqueue(59);
    display();
}

void dequeue()
{
    if(front == -1 && rear == -1) { std::cout << "UnderFlow condition" << std::endl;}
    else if(front == rear) { front = rear = -1;}
    else { front++ ;}
}

void enqueue(int num)
{
    if(rear == N - 1) { std::cout << "Overflow Condition" << std::endl; }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = num;
    }
    else
    {
        queue[++rear] = num;
    }
}

void display()
{
    if (front == -1 && rear == -1){ std::cout << "Empty queue" << std::endl;}
    else 
    {
        for (int i = front; i <= rear; i++){ std::cout << queue[i] << std::endl;}
    }
}
