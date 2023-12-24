#include <iostream>
#define N 5
int front = -1, rear = -1;
int queue[N];

void enqueue(int num);
void dequeue();
void display();

main()
{
    enqueue(45);
    enqueue(65);
    enqueue(96);
    display();
    
    
}

void display()
{
    int i = front; 
    if (front == -1  && rear == -1){ std::cout << "The given queue is empty" << std::endl;}
    while(i != rear)
    {
        std::cout << queue[i] << std::endl;
        i = (i+1)%N;
    }
    std::cout << queue[i] << std::endl;
}

void dequeue()
{
    if (front == -1 && rear == -1) { std::cout << "Underflow condition" << std::endl;}
    else if(front == rear) {front= rear=-1;}
    else
    {
        front = (front+1)%N;
    }
}


void enqueue(int num)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = num;
    }
    else if( (rear+1)%N == front)
    {
        std::cout << "Overflow condition" << std::endl;
    }
    else
    {
        rear = (rear+1)%N;
        queue[rear] = num;
    }
    
}