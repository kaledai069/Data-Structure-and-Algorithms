#include <iostream>
#define N 5
int deque[N];
int f = -1, r = -1;
void enqueuefront(int num);
void enqueuerear(int num);
void dequeuefront();
void dequeuerear();
void display();
void dequeuefront();
void dequeuerear();


main()
{
    enqueuefront(2);
    enqueuefront(5);
    enqueuerear(-1);
    enqueuerear(0);
    enqueuefront(7);
    enqueuefront(4);
    display();
    std::cout << std::endl;
    dequeuefront();
    dequeuerear();
    display();
}

void dequeuerear()
{
    if ( f == -1 && r == -1){   std::cout << "Underflow condition" << std::endl;    }
    else if ( f == r) { f = r = -1;}
    else if (r == 0){ r = N-1; }
    else { r--; }
}

void dequeuefront()
{
    if ( f == -1 && r == -1){   std::cout << "Underflow condition" << std::endl;    }
    else if ( f == r) { f = r = -1;}
    else if ( f == N-1) { f = 0;}
    else{ f++; }
}

void display()
{
    int i = f;
    while (i != r)
    {
        std::cout << deque[i] << std::endl;
        i = (i+1)%N;
    }
    std::cout << deque[i] << std::endl;
}

void enqueuerear(int num)
{
    if ( (r+1)%N == f){ std::cout << "overflow condition" << std::endl;}
    else if(f == -1 && r == -1)
    {
        f = r = 0;
        deque[r] = num;
    }
    else if (r == N-1)
    {
        r = 0;
        deque[r] = num;
    }
    else
    {
        deque[++r] = num;
    }  
}

void enqueuefront(int num)
{
    if ((f == 0 and r == N-1) || (f==r+1))
    {
        std::cout << "Overflow condition" << std::endl;
    }
    else if( f == -1 && r == -1)
    {
        f = r = 0;
        deque[f] = num;
    }
    else if (f == 0)
    {
        f = N-1;
        deque[f] = num;
    }
    else
    {
        deque[--f] = num;
    }
}