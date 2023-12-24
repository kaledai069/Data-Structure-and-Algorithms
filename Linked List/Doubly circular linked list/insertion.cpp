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
void insertAtBeg(int num);
void insertAtEnd(int num);
void insertAtPos(int pos, int num);


main()
{
    vector<int> data{1,2,3,4,5,6,7,8};
    createDCLL(data);
    insertAtBeg(69);
    insertAtEnd(69);
    insertAtPos(4, 69);
    
    displayDCLL();
}



void insertAtPos(int pos, int num)
{
    int i = 1;
    temp = head;
    newnode = new struct node; 
    newnode->data = num;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next->prev = newnode;
    newnode->prev = temp;
    temp->next = newnode;
}

void insertAtEnd(int num)
{
    newnode = new struct node;
    newnode->data = num;
    newnode->prev = tail;
    newnode->next = head;
    head->prev = newnode;
    tail->next = newnode;
    tail = newnode;
}

void insertAtBeg(int num)
{
    newnode = new struct node;
    newnode->data = num;
    newnode->next = head;
    head->prev = newnode;
    tail->next = newnode;
    newnode->prev = tail;
    head = newnode;
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
        cout << temp->data << '\t';
        temp = temp->next;
    }while(temp != tail->next);
}