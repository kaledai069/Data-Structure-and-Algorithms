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
    int arr[14] = {1,2,3,4,5,6,7,8,9,11,12,13,14,15};
    head = 0;
    int count = 0;
    for (int i = 0; i < 14 ; i++)
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

    temp = head;
    while (temp != 0)
    {
        temp = temp->next;
        count++;
    }
    cout << "The length of the given linked list is: " << count ;
}