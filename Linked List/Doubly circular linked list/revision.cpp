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

main()
{
    vector<int> data{1,2,3,4,5,6,7,8};
    createDCLL(data);
    displayDCLL();
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