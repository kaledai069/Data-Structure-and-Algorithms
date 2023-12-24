#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *head, *newnode, *temp;
void createLinkedList(int arr[]);
void displayLinkedList();
void insertAtBeg(int);
void insertAtEnd(int);
void insertAtNth(int num, int pos);
void delAtBeg();
void delAtEnd();
void delAtNth(int pos);
void reverseLL();

int main()
{
    int arr[10] = {45,67,83,69,23,64,99,12,36,28};
    createLinkedList(arr);
    // displayLinkedList();
    insertAtBeg(101);
    // displayLinkedList();
    insertAtEnd(404);
    // displayLinkedList();
    insertAtNth(808, 4);
    // cout << "After inserting the element at Nth position" << endl ;
    // displayLinkedList();
    // cout << endl << "Deleting from the beginning of the linked list" << endl ;
    delAtBeg();
    // displayLinkedList();
    // cout << endl << "Deleting from the end of the linked list" << endl ;
    delAtEnd();
    // displayLinkedList();
    cout << endl << "Deleting 4th element from the linked list" << endl;
    delAtNth(4);
    displayLinkedList();
    reverseLL();
    cout << endl << "Reversing the linked list" << endl;
    displayLinkedList();

}

void reverseLL()
{
    struct node *prevnode, *nextnode, *currentnode;
    prevnode = 0;
    currentnode = nextnode = head;
    while(nextnode != 0)
    {
        nextnode = nextnode->next;
        currentnode->next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
    head = prevnode;
}


void delAtNth(int pos)
{
    int i = 1;
    struct node *nextnode;
    temp = head;
    while( i < pos-1)
    {
        temp = temp->next;
        i++;
    }
    nextnode = temp->next;
    temp->next = nextnode->next;
    delete nextnode;
}


void delAtEnd()
{
    temp = head;
    struct node *prevnode;
    while (temp->next != 0)
    {
        prevnode = temp;
        temp = temp->next;
    }
    prevnode->next = 0;
    delete temp;
}


void delAtBeg()
{
    temp = head;
    head = head->next;
    delete temp;
}

void insertAtNth(int num, int pos)
{
    int i = 1;
    temp = head;
    while (i < pos)
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
    temp = head;
    while(temp->next != 0)
    {
        temp = temp->next;
    }
    newnode = new struct node;
    newnode->data = num;
    newnode->next = 0;
    temp->next = newnode;
}

void insertAtBeg(int num)
{
    newnode = new struct node;
    newnode->data = num;
    newnode->next = head;
    head = newnode;
}

void createLinkedList(int arr[])
{
    head = 0;
    for(int i = 0 ; i < 10; i++)
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
}

void displayLinkedList()
{
    temp = head;
    while (temp != 0)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}


