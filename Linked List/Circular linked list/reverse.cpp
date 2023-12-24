#include <iostream>
#include <vector>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *tail, *newnode, *temp, *current, *prevnode, *nextnode;
void reverseCLL();
void createCLL(vector<int> data);
void displayCLL();

main()
{
    vector<int> data{1,2,3,4,5,6,7,8};
    createCLL(data);
    reverseCLL();
    displayCLL();
}

void reverseCLL()
{
    current = tail->next;
    nextnode = current->next;
    while (current != tail)
    {
        prevnode = current;
        current = nextnode;
        nextnode = current->next;
        current->next = prevnode;
    }
    nextnode->next = tail;
    tail = nextnode;
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