#include <iostream>
#define N 5
int deque[N];
int f = -1, r = -1;
void enqueuefront(int num);
void enqueuerear(int num);
void dequeuefront();
void dequeuerear();
void display();


main()
{
    enqueuefront(2);
    enqueuefront(56);
    enqueuerear(23);
    enqueuerear(45);
    display();
    dequeuefront();
    dequeuerear();
    std::cout << std::endl;
    display();
}

void dequeuefront()
{
    if ( r == -1 && f == -1) { std::cout << "Underflow Condition" << std::endl;}
    else if (f == r){ f = r = -1;}
    else if (f == N-1){ f = 0;}
    else { f++;}
}
void dequeuerear()
{
    if ( r == -1 && f == -1) { std::cout << "Underflow Condition" << std::endl;}
    else if (f == r){ f = r = -1;}
    else if (r == 0){ r = N-1;}
    else { r--;}
}

void display()
{
    int i = f;
    while(i != r)
    {
        std::cout << deque[i] << std::endl;
        i = (i+1)%N;
    }
    std::cout << deque[r] << std::endl;
}

void enqueuerear(int num)
{
    if((f==0 && r == N-1)|| (f==r+1)){ std::cout << "Overflow Condition" << std::endl;}
    else if(f == -1 && r == -1){ f = r = 0; deque[f] = num;}
    else if(r == N-1){ r = 0; deque[r] = num;}
    else { deque[++r] = num;} 
}

void enqueuefront(int num)
{
    if((f==0 && r == N-1)|| (f==r+1)){ std::cout << "Overflow Condition" << std::endl;}
    else if(f == -1 && r == -1){ f = r = 0; deque[f] = num;}
    else if(f == 0)
    {
        f = N-1;
        deque[f] = num;
    }
    else
    {
        deque[--f] = num;
    }
}