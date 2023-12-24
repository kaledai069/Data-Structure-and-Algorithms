#include <iostream>
#include <vector>
using namespace std;
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head, *newnode, *temp, *tail;

void createDLL(vector<int> data);
void displayDLL();
void insertAtBeg(int num);
void insertAtEnd(int num);
void insertAtPos(int pos);
void insertAfterPos(int pos);
void deleteFromBeg();
void deleteFromEnd();
void deleteAtAPos(int pos);
void reverseDLL();

main()
{
    vector<int> data{1,2,6,8,9,10,34};
    createDLL(data);
    insertAtBeg(69);
    insertAtEnd(69);
    insertAtPos(4);
    insertAfterPos(5);
    deleteFromBeg();
    deleteFromEnd();
    deleteFromEnd();
    deleteAtAPos(5);
    reverseDLL();
    displayDLL();
}

void reverseDLL()
{
    struct node *current, *nextnode;
    current = head;
    while (current != 0)
    {
        nextnode = current->next;
        current->next = current->prev;
        current->prev = newnode;
        current = nextnode;
    }
    current = head;
    head = tail;
    tail = current;
}

void deleteAtAPos(int pos)
{
    int i = 1;
    temp = head;
    while (i < pos)
    {
        temp = temp->next;
        i++;
    }
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    delete temp;
}

void deleteFromEnd()
{
    // cout << "Data at last: " << tail->data << endl;
    temp = tail;
    tail = tail->prev;
    tail->next = 0;
    delete temp;
}

void deleteFromBeg()
{
    //  cout << "Data at last: " << tail->data << endl;
    temp = head;
    head = head->next;
    head->prev = 0;   
    delete temp; 
}

void insertAfterPos(int pos)
{
    temp = head;
    newnode = new struct node;
    newnode->data = 69;
    int i = 1;
    while (i < pos)
    {
        temp = temp->next;
        i++;
    }
    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next = newnode;
    newnode->next->prev = newnode;
    //  cout << "Data at last: " << tail->data << endl;
}

void insertAtPos(int pos)
{
    temp = head;
    newnode = new struct node;
    newnode->data = 69;
    int i = 1;
    while (i < pos-1)
    {
        temp = temp->next;
        i++;
    }
    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next = newnode;
    newnode->next->prev = newnode;
    //  cout << "Data at last: " << tail->data << endl;
}

void insertAtEnd(int num)
{
    newnode = new struct node;
    newnode->data = num;
    newnode->prev= tail;
    tail->next = newnode;
    tail = newnode;
    newnode->next = 0;
    //  cout << "Data at last: " << tail->data << endl;
}

void insertAtBeg(int num)
{
    newnode = new struct node;
    newnode->data = num;
    newnode->prev = 0;
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}

void createDLL(vector<int> data)
{
    head = 0;
    tail = 0;
    for( int i =0 ; i < data.size(); i++)
    {
        newnode = new struct node;
        newnode->data = data[i];
        newnode->next = 0;
        newnode->prev = 0;
        if (head == 0)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }
}

void displayDLL()
{
    temp = head;
    while(temp != 0)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}