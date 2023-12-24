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
  int arr[10] = {1,5,6,8,9,69,36,52,58,69};
	for(int i = 0; i < 10; i++){
		newnode = new struct node;
		newnode->data = *(arr+i);
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
		cout << temp->data <<  endl;
		temp = temp->next;
	}
  // reversing the node from this point
   
   struct node *prevnode, *currentnode, *nextnode;
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
   temp = head;
   cout << "Printing the reversed linked list" << endl;
   while(temp != 0 )
   {
      cout << temp->data << endl;
      temp = temp->next;
   }

}
