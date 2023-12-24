#include <iostream>
#include <vector>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *head, *newnode, *temp;

main()
{
    vector<int> data{1,2,3,4,5};
    head = 0;
    for (int i = 0; i < data.size(); i++)
    {
        newnode = new struct node;
        newnode->data = data[i];
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
    temp->next = head;
    temp = head;
    while (temp->next != head)
    {
        cout << temp->data << '\t';
        temp = temp->next;
    }
}