#include <iostream>
#include <vector>
using namespace std;
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head, *tail, *newnode, *temp;

void createDCLL(vector<int> data);
void displayDCLL();
void delAtBeg();
void delAtEnd();
void delAtAPos(int pos);

main()
{
    vector<int> data{69,1,2,69,3,4,5,6,7,8,69};
    createDCLL(data);
    delAtBeg();
    delAtEnd();
    delAtAPos(3);
    displayDCLL();
}

void delAtAPos(int pos)
{
    int i = 1;
    temp = head;
    while (i < pos)
    {
        temp = temp->next;
        i++;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    // if the pos to be deleted is the last position
    if (temp->next == head)
    {
        tail = temp->prev;
        delete temp;
    }
    else
    {
        delete temp;
    }
    
}


void delAtEnd()
{
    temp = tail;
    tail = tail->prev;
    tail->next = head;
    head->prev = tail;
    delete temp;
}

void delAtBeg()
{
    temp = head;
    head = head->next;
    head->prev = tail;
    tail->next = head;
    delete temp;
}

void createDCLL(vector<int> data)
{
    head = 0;
    for (int i = 0; i < data.size(); i++)
    {
        newnode = new struct node;
        newnode->next = 0;
        newnode->data = data [i];
        newnode->prev = 0;
        if (head == 0)
        {
            head = tail = newnode;
            head->next = head;
            head->prev = head;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            newnode->next = head;
            tail = newnode;
            head->prev = tail;
        }
    }
}

void displayDCLL()
{
    temp = head;
    do
    {
        cout << temp->data << endl;
        temp = temp->next;
    }while(temp != tail->next);
}