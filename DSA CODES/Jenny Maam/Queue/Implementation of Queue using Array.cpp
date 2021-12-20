#include <iostream>
#define SIZE 5

template <class T>
class Queue
{
	public:
		T *array;
		int front, rear;
		
		Queue<T>()
		{
			array = new T[SIZE];
			front = 0;
			rear = -1;	
		}		
		
		bool isFull()
		{
			return rear >= SIZE - 1;
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
				array[++rear] = value;
				std::cout << "Item enqueued successfully." << std::endl;
			}
		}
		
		bool isEmpty()
		{
			return this->front > this->rear;
		}
		
		void dequeue()
		{
			if(this->isEmpty())
			{
				std::cout << "QUEUE IS EMPTY" << std::endl;	
			}	
			else
			{
				std::cout << "ITEM TO BE DEQUEUED: " << array[front++] << std::endl;
			}
		}
		
		void show()
		{
			if(!this->isEmpty())
			{
				std::cout << "All the items in the queue are: " << std::endl;
				for(int i = this->front; i <= this->rear; i++)
					std::cout << array[i] << std::endl;
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
				std::cout << "Item at the front: " << array[front] << std::endl;
			}
			else
			{
				std::cout << "QUEUE IS EMPTY" << std::endl;
			}
		}
		
		void makeEmpty()
		{
			this->front = 0;
			this->rear = -1;
		}
};

int main()
{
	bool isRunning = true;
	int choice = 0;
	Queue<int> linear_queue;
	std::cout << "Operations on Linear QUEUE\n1. Enqueue\n2. Dequeue\n3. Show all the items\n4. Front item\n5. Empty Queue\n6. Exit\n";
	while(isRunning)
	{
		std::cout << "Enter the index of operation: ";
		std::cin >> choice;
		switch(choice)
		{
			case 1:
				linear_queue.enqueue();
				break;
			case 2:
				linear_queue.dequeue();
				break;
			case 3:
				linear_queue.show();
				break;
			case 4:
				linear_queue.front_item();
				break;
			case 5:
				linear_queue.makeEmpty();
				break;
			case 6:
				isRunning = false;
				break;
		}
	}
}