#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

int main()
{
    struct node *head, *newnode, *temp;
    int arr[5] = {45,89,67,83,98};
    head = 0;
    for (int i =0 ; i < 5 ; i++)
    {
        newnode = new struct node;
        newnode->data = arr[i];
        newnode->next = 0;
        newnode->prev = 0;
        if (head == 0 )
        {
            head = temp = newnode;
        }
        else
        {
            newnode->prev = temp;
            temp->next = newnode;
            temp = newnode;
        }
    }

    temp = head;
    while (temp != 0)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}