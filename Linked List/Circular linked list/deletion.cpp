#include <iostream>
#include <vector>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *tail, *newnode, *temp, *current, *previous, *nextnode;

void createCLL(vector<int> data);
void displayCLL();
void delAtBeg();
void delAtEnd();
void delAtPos(int pos);

main()
{
    vector<int> data{1,2,3,4,5,6,7,8};
    createCLL(data);
    delAtBeg();
    delAtEnd();
    delAtPos(4);
    displayCLL();
}

void delAtPos(int pos)
{
    current = tail->next;
    int i = 1;
    while (i < pos - 1)
    {
        current = current->next;
        i++;
    }
    nextnode = current->next;
    current->next = nextnode->next;
    delete nextnode;
}


void delAtEnd()
{
    current = tail->next;
    while (current->next != tail->next)
    {
        previous = current;
        current = current->next;
    }
    previous->next = tail->next;
    tail = previous;
    delete current;
}

void delAtBeg()
{
    temp = tail->next;
    tail->next = temp->next;
    delete temp;
}

void createCLL(vector<int> data)
{
    tail = 0;
    for(int i =0; i < data.size(); i++)
    {
        newnode = new struct node;
        newnode->data = data[i];
        newnode->next = 0;
        if (tail == 0)
        {
            tail = newnode;
            tail->next = newnode;
        }
        else
        {
            newnode->next = tail->next;
            tail->next = newnode;
            tail = newnode;
        }
    }
}

void displayCLL()
{
    temp = tail->next;
    do
    {
        cout << temp->data << endl;
        temp = temp->next;
    }while(temp != tail->next);
}