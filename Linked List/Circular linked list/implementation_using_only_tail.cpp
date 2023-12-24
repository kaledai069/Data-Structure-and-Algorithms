#include <iostream>
#include <vector>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *head, *newnode, *temp, *tail;

main()
{
    vector<int> data{1,2,3,4,5};
    tail = 0;
    for (int i = 0; i < data.size(); i++)
    {
        newnode = new struct node;
        newnode->data = data[i];
        newnode->next = 0;
        if (tail == 0)
        {
            tail = newnode;
            tail->next = newnode;
        }
        else
        {
            newnode->next = tail->next;
            tail->next = newnode;
            tail = newnode;
        }
    }
    // displaying the cirular linked list here haii kto
    temp = tail->next;
    do
    {
        cout << temp->data << '\t';
        temp = temp->next;
    }while (temp != tail->next);
    
}