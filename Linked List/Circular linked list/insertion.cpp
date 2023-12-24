#include <iostream>
#include <vector>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *tail, *newnode, *temp;
void createCLL(vector<int> data);
void displayCLL();
void insertAtBeg(int num);
void insertAtEnd(int num);
void insertAtPos(int num , int pos);

main()
{
    vector<int> data{1,2,3,4,5,6,7,8};
    createCLL(data);
    insertAtBeg(69);
    insertAtEnd(69);
    insertAtPos(69, 4);
    displayCLL();
}

void insertAtPos(int num, int pos)
{
    int i = 1;
    temp = tail->next;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    newnode = new struct node;
    newnode->data = num;
    newnode->next = temp->next;
    temp->next = newnode;
}


void insertAtEnd(int num)
{
    newnode = new struct node;
    newnode->data = num;
    newnode->next = tail->next;
    tail->next = newnode;
    tail = newnode;
}


void insertAtBeg(int num)
{
    newnode = new struct node;
    newnode->data = num; 
    newnode->next = tail->next;
    tail->next = newnode;
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