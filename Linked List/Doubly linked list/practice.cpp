#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

main()
{
    struct node *head, *tail, *newnode, *temp;  
    int arr[9] = {3,5,7,9,11, 13, 15, 17, 19};
    int i = 1, pos = 3;
    head = 0;
    tail = 0;
    for (int i = 0; i < 9 ;i ++)
    {
        newnode = new struct node;
        newnode->prev = 0;
        newnode->data = arr[i];
        newnode->next = 0;
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
    // cout << "Printing the data part of the linked list in forward direction" << endl;
    // temp = head;
    // while(temp != 0)
    // {
    //     cout << temp->data << endl ;
    //     temp = temp->next;
    // }
    // cout << "Printing the data part of the linked list in reverse direction" << endl;
    // temp = tail;
    // while(temp != 0)
    // {
    //     cout << temp->data << endl;
    //     temp = temp->prev;
    // }

    newnode = new struct node;
    newnode->data = 69;
    newnode->prev = tail;
    tail->next = newnode;
    tail = newnode;

    // cout << "Updating the linked list" << endl;
    // temp = head;
    // while (temp != 0)
    // {
    //     cout << temp->data << endl;
    //     temp = temp->next;
    // }
    
    temp = head;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    newnode = new struct node;
    newnode->data = 699;
    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next = newnode;
    newnode->next->prev = newnode;

    cout << "Insertion at the 3rd pos" << endl;
    temp = head;
    while (temp != 0)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << endl << "deletion from the beginning" << endl;
    temp = head;
    head->next->prev = 0;
    head = head->next;
    delete temp;

    temp = head;
    while (temp != 0)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    
    cout << endl << "Deletion from the end" << endl;
    temp = tail;
    tail->prev->next = 0;
    tail = tail->prev;
    delete temp;

     temp = head;
    while (temp != 0)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    i = 1;
    pos = 3;
    temp = head;
    struct node *prevnode;
    while (i < pos)
    {
        prevnode = temp;
        temp = temp->next;
        
        i++;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    // prevnode->next = temp->next;
    // temp->next->prev = prevnode; 
    delete temp;

    cout << endl << "Deletion from the 3rd position" << endl ;
      temp = head;
    while (temp != 0)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }

    //reversing the doubly linked list
    struct node *current, *nextnode;
    current = head;
    while (current != 0)
    {
        nextnode = current->next;
        current->next = current->prev;
        current->prev = nextnode;
        current = nextnode;
    }

    temp = head;
    head = tail;
    tail = temp;
    
    cout <<  endl << "The reverse of the linked list" << endl;
    temp = head;
    while (temp != 0)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }

}