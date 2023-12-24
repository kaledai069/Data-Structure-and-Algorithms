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
    int arr[8] = {45,89,56,12,45, 78,99,167};
    int pos = 3 , i = 1;
    head = 0;
    // creating a node of size five
    for (int i = 0; i < 8 ; i++)
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

    // deleting an element from the beginning of the linked list
    temp = head;
    head = head->next;
    delete temp;

    cout << "After deleting the beggining node of the linked list" << endl;
    temp = head;
    while (temp != 0)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }

    struct node *prevnode;
    temp = head;
    while (temp->next != 0)
    {
        prevnode = temp;
        temp = temp->next;
    }
    prevnode->next = 0;
    delete temp;

    cout << "After deleting from the end of the linked list" << endl; 
    temp = head;
    while( temp != 0)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }

    struct node *nextnode;
    temp = head;
    while(i < pos -1 )
    {
        temp = temp->next;
        i++;
    }
    nextnode = temp->next;
    temp->next = nextnode->next;
    delete nextnode;
    cout << "After deleting from a specified position" << endl;
    temp = head;
    while (temp != 0)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}