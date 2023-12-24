// implementation of singly linear linked list
#include <iostream>

class Node
{
	public:
		int data;
		Node *next;
};

class Linked_List
{
	private:
		void creation()
		{
			std::cout << "Enter the number of nodes to create: ";	
			std::cin >> node_num;
			this->count = node_num;
			for(int i = 0; i < node_num; i++)
			{
				newnode = new Node;
				std::cout << "Enter the data: ";
				std::cin >> newnode->data;
				newnode->next = NULL;
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
		}
		
	public:
		int node_num;
		Node *temp, *prev, *head, *newnode;
		int count;
		Linked_List()
		{
			head = temp = 0;
			count = 0;
		}	
		void display()
		{
			temp = head;
			std::cout << "The elements in the linked list are: \n";
			while(temp != NULL)
			{
				std::cout << temp->data << '\n';
				temp = temp->next;
			}
		}
		
		void create_list()
		{
			this->creation();
		}
		
		void insert_at_first()
		{
			newnode = new Node;
			std::cout << "Enter the data: ";
			std::cin >> newnode->data;
			newnode->next = head;
			head = newnode;
			count++;
		}
		
		void insert_at_last()
		{
			temp = head;
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			std::cout << temp->data << std::endl;
			newnode = new Node;
			std::cout << "Enter the data: ";
			std::cin >> newnode->data;
			newnode->next = NULL;
			temp->next = newnode;
			count++;
		}
		
		void delete_from_first()
		{
			Node* temp_ptr = head;
			std::cout << "Data to be deleted: " << head->data << std::endl;
			head = head->next;
			delete temp_ptr;
			--count;
		}
		
		void delete_from_last()
		{
			temp = head;
			while(temp->next->next != NULL)
			{
				temp = temp->next;
			}
			Node* temp_ptr = temp->next;
			std::cout << "Data to be delete: " << temp_ptr->data << std::endl;
			temp->next = NULL;
			delete temp_ptr;
			--count;
		}
		
		void insert_after_certain_pos()
		{
			std::cout << "Enter the position to be inserted after: ";
			int pos;
			std::cin >> pos;
			if(pos == 0)
			{
				this->insert_at_first();
			}
			else if(pos == count)
			{
				this->insert_at_last();
			}
			else if(pos > count)
			{
				std::cout << "Outside the range." << std::endl;	
			}	
			else
			{
				newnode = new Node;
				std::cout << "Enter the data: ";
				std::cin >> newnode->data;
				int temp_c = 0;
				temp = head;
				while(temp_c < pos)
				{
					temp = temp->next;
					temp_c++;
				}
				newnode->next = temp->next;
				temp->next = newnode;
				count++;
			}
		}
		
		void delete_specified_node()
		{
			if(count == 0)
			{
				std::cout << "The linked list is empty." << std::endl;
			}
			else
			{
				int pos;
				std::cout << "Enter the position of the node to be deleted: ";
				std::cin >> pos;
				if(pos == 0)
				{
					this->delete_from_first();
				}
				else if(pos == count - 1)
				{
					this->delete_from_last();
				}
				else if(pos > count)
				{
					std::cout << "Supplied position out of range" << std::endl;
				}
				else
				{
					temp = head;
					int temp_n = 0;
					while(temp_n < pos-1)
					{
						temp = temp->next;
						temp_n++;
					}
					std::cout << temp->data << std::endl;
					Node* temp_ptr = temp->next;
					std::cout << "The element to be deleted is: " << temp_ptr->data << std::endl;
					temp->next = temp->next->next;
					delete temp_ptr;
				
				}
			}
		}
		
		void searching()
		{
			std::cout << "Enter the item / data to be searched: ";
			int count = 0, data_to_search;
			std::cin >> data_to_search;
			temp = head;
			bool found_f = false;
			while(temp != NULL)
			{
				if(temp->data == data_to_search)
				{
					std::cout << "The searched item is present at " << count << " index.\n";
					found_f = true;
					break;
				}
				count++;
				temp = temp->next;
			}
			if(!found_f)
			{
				std::cout << "The data " << data_to_search << " is not available in the given linked list.\n";
			}
		}
};

int main()
{
	Linked_List s;
	s.create_list();
	s.delete_specified_node();
	s.display();
	s.searching();
	return 0;
}