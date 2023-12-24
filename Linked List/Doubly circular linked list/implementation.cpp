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

main()
{
    vector<int> data{1,2,3,4,5,6,7};
    head = 0;
    for(int i = 0; i < data.size(); i++)
    {
        newnode = new struct node;
        newnode->data = data[i];
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
            head->prev = newnode;
            tail = newnode;
        }
    }

    temp = head;
    while (temp != tail->next)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}