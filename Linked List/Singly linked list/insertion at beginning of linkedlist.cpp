#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head, *newnode, *temp;
    int arr[5] = {45,89,56,12,455};
    int pos = 3 , i = 1;
    head = 0;
    // creating a node of size five
    for (int i = 0; i < 5 ; i++)
    {
        newnode = new struct node;
        newnode->data = arr[i];
        newnode->next = 0;

        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    //traversing a linked list
    temp = head;
    while (temp != 0)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    // insertion at the beginning of the node;
    newnode = new struct node;
    newnode->data = 699;
    newnode->next = head;
    head = newnode;

    cout << "After inserting a node at the beginning of the linked list!!!" << endl;
    temp = head;
    while (temp != 0)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }

    // insertion at the end of the node
    newnode = new struct node;
    newnode->data = 786;
    newnode->next = 0;
    temp = head;
    while (temp->next != 0)
    {
        temp = temp->next;
    }
    temp->next = newnode;

    cout << "After inserting a node at the end of the linked list!!!" << endl;
    temp = head;
    while (temp != 0)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }

    // insertion at a location after a specified position

    temp = head;
    while(i < pos)
    {
        temp = temp->next;
        i++;
    }
    newnode = new struct node;
    newnode->data = 600;
    newnode->next = temp->next;
    temp->next= newnode;

    cout << "Inserting the node at the pos specified" << endl;
    temp = head;
    while (temp != 0)
    {
        cout << temp->data << endl ;
        temp = temp->next;
    }
}
