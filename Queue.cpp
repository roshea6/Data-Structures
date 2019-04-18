//Queue

#include <iostream>
using namespace std;

class chunk
{
public:
	int value;
	chunk *next;

	chunk()
	{
		value = 0;
		next = NULL;
	}
};

class queue
{
public:
	//queue of chunks
	chunk *head;

	queue()
	{
		head = NULL;
	}

	//Add studd to Q: enqueue
	void enqueue(int x)
	{
		if (head == NULL)
		{
			//Q is empty. Grab a chunk and add to Q. It's the only element
			chunk *temp = new chunk;
			temp->value = x;
			head = temp;
		}

		else
		{
			chunk *temp = new chunk;
			temp->value = x;

			//1. add new chunk to Q
			temp->next = head;

			//2. and update head to now point to this
			head = temp;
		}
	}

	//Delete stuff: dequeue
	void dequeue()
	{
		//go to the end, and delete the last chunk

		if (head == NULL)
		{
			cout << "Nothing to delete" << endl;

		}

		else if (head->next == NULL)	//Only one chunk in the queue
		{
			delete head;
			head = NULL;
		}

		else
		{
			//take two pointers and go all the way to the end
			chunk *chase, *follow;
			chase = follow = head;

			//go to the end: chase goes to the las one, follow to the second to last

			while (chase->next != NULL)
			{
				follow = chase;
				chase = chase->next;
			}
			cout << "About to delete: " << chase->value << endl;
			delete chase;	//Deletes the last chunk
			follow->next = NULL;	//Has the NEW last chunk point to NULL
		}

	}

	//Diplay contents
	void display()
	{
		if (head == NULL)
		{
			cout << "Nothing to display" << endl;
		}

		else
		{
			chunk *temp;
			temp = head;

			while (temp != NULL)
			{
				cout << temp->value << endl;
				temp = temp->next;
			}
		}
	}
};

int main()
{
	queue myQ;
	int choice;

	while (1)
	{
		cout << "Press 1 to enqueue" << endl;
		cout << "Press 2 to dequeue" << endl;
		cout << "Press 3 to display Q contents" << endl;
		cout << "Press Anything else to quit" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1: cout << "Enqueue: ";
			int value;
			cin >> value;
			myQ.enqueue(value);
			break;

		case 2: myQ.dequeue();
			break;

		case 3: myQ.display();
			break;

		default: cout << "Bye Bye" << endl;
			exit(1);

		}
	}
	return 1;

}