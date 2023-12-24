#include <iostream>
#define N 5
int stack[N];
int top = -1;
void push(int num);
void pop();
void peek();
void display();

main()
{
    push(9);
    push(10);
    push(6);
    push(9);
    pop();
    peek();
    display();
}

void peek()
{
    if (top == -1)
    {
        std::cout << "The stack is empty." << std::endl;
    }
    else
    {
        std::cout << stack[top] << std::endl;
    }
}

void display()
{
    for (int i = 0; i <= top; i++)
    {
        if (stack[i] == 0)
        {
            break;
        }
        std::cout << stack[i] << std::endl;
    }
}
void push(int num)
{
    
    if (top == N -1)
    {
        std::cout << "The condition has reached to Stack Overflow" << std::endl;
    }
    else
    {
        top++;
        stack[top] = num;
    }
}

void pop()
{
    int item;
    if (top == -1)
    {
        std::cout << "You have reached to the Stach Underflow condition" << std::endl;
    }   
    else
    {
        item = stack[top];
        // std::cout << item << std::endl;
        top--;
    }
}
