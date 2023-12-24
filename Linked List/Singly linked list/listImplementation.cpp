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
   head = 0;
   for (int i =0 ; i < 5; i++)
   {
       newnode = new struct node;
       cout << "Enter the number: ";
       cin >> newnode->data;
       newnode->next = 0;
       if(head == 0)
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
		cout << temp->data << "		" << temp->next << endl;
		temp = temp->next;
	}
   return 0;
}
