#include <iostream>
#define SIZE 5

template <class T>
class C_Queue
{
	public:
		T *array;
		int front, rear;
		bool first_time = true;
		C_Queue<T>()
		{
			array = new T[SIZE];
			front = rear = 0;
		}
		
		bool isFull()
		{
			return this->front == ((this->rear + 1) % SIZE);
		}
		
		void enqueue()
		{
			if(this->isFull())
			{
				std::cout << "QUEUE IS FULL" << std::endl;
			}
			else 
			{
				std::cout << "Enter the item to be enqueued: ";
				T value;
				std::cin >> value;
				if(first_time)
				{
					array[rear]=value;
					first_time = false;
				}
				else
				{
				rear = (rear + 1) % SIZE;
				array[rear] = value;
					
				}
			}
		}
		
		bool isEmpty()
		{
			return this->front == this->rear;
		}
		
		void dequeue()
		{
			if(this->isEmpty())
			{
				std::cout << "QUEUE IS EMPTY" << std::endl;
			}
			else
			{
				std::cout << "Item to be dequeued: " << array[front] << std::endl;
				front = (front + 1) % SIZE;
			}
		}
		
		void show_all()
		{
			if(!this->isEmpty())
			{
				int i;
				for(i = this->front; i != this->rear; i = (i + 1) % SIZE)
					std::cout << array[i] << '\t';
				std::cout << array[i] << '\t';
				std::cout << std::endl;	
			}
			else
			{
				std::cout << "QUEUE IS EMPTY" << std::endl;
			}
		}
		
		void front_item()
		{
			if(!this->isEmpty())
			{
				std::cout << "Item at front: " << array[front] << std::endl;
			}
			else
			{
				std::cout << "QUEUE IS EMPTY" << std::endl;
			}
		}
		
		void make_empty()
		{
			this->front = this->rear = 0;
		}
};


int main()
{
	bool isRunning = true;
	int choice = 0;
	C_Queue<int> c_queue;
	std::cout << "Operations on Circular QUEUE\n1. Enqueue\n2. Dequeue\n3. Show all the items\n4. Front item\n5. Empty Queue\n6. Exit\n";
	while(isRunning)
	{
		std::cout << "Enter the index of operation: ";
		std::cin >> choice;
		switch(choice)
		{
			case 1:
				c_queue.enqueue();
				break;
			case 2:
				c_queue.dequeue();
				break;
			case 3:
				c_queue.show_all();
				break;
			case 4:
				c_queue.front_item();
				break;
			case 5:
				c_queue.make_empty();
				break;
			case 6:
				isRunning = false;
				break;
		}
	}
}