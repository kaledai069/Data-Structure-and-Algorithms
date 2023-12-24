#include <iostream>
#include <vector>
std::vector<int> stack1, stack2;
int count = 0, top1 = -1, top2 = -1;
void enqueue(int num);
void dequeue();
void display();

main()
{
    enqueue(5);
    enqueue(67);
    enqueue(78);
    dequeue();
    enqueue(69);
    enqueue(73);
    display();
    dequeue();
    std::cout << std::endl;
    display();
}

void display()
{
    for(int num: stack1)
    {
        std::cout << num << std::endl;
    }
}
void dequeue()
{
    for (int i = 0; i < count; i++)
    {
        stack2.push_back(stack1.back());
        stack1.pop_back();
    }
    stack2.pop_back();
    count--;
    for(int i = 0; i < count; i++)
    {
        stack1.push_back(stack2.back());
        stack2.pop_back();
    }
}
void enqueue(int num)
{
    stack1.push_back(num);
    count++;
}
