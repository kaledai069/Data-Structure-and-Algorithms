#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
void createDoublyLL(int arr[]);
void displayDLL();
void insertAtBeg(int);
void insertAtEnd(int);
struct node *head, *newnode, *temp;

int main()
{
   int arr[5] = {45,89,67,83,98};
   createDoublyLL(arr);
   displayDLL();
   insertAtBeg(69);
   cout << endl << "After inserting at the beginning of the doubly linked list" << endl ;
   displayDLL();
   cout << endl << "Inserting at the end of the doubly linked list" << endl;
   insertAtEnd(699);
   displayDLL();
}

void insertAtEnd(int num)
{
   newnode = new struct node;
   newnode->data = num;
   newnode->next = 0;
   temp = head;
   while (temp->next != 0)
   {
      temp = temp->next;
   }
   newnode->prev = temp;
   temp->next = newnode;
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


void createDoublyLL(int arr[])
{
    head = 0;
    for (int i =0 ; i < 5 ; i++)
   {
        newnode = new struct node;
        newnode->data = arr[i];
        newnode->next = 0;
        newnode->prev = 0;
        if (head == 0)
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
}

void displayDLL()
{
   temp = head;
    while (temp != 0)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}