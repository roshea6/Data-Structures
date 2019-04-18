//Ryan O'Shea CPE 360 Linked list 

#include<iostream>
using namespace std;

class chunk		//defining what a chunk is 
{
public:
	int value;
	chunk *next;

	chunk()	//Constructor
	{
		value = 0;
		next = NULL;
	}
};

class LL
{
public:
	chunk *head;
	int Length; //Everytime you add length++, everytime you delete length--

	LL()	//Constructor
	{
		head = NULL;
		Length = 0;
	}

	//Function to add: give it a value and a position
	void add(int x, int position)
	{

		if ((position > Length) || (position < 0))	//An invalid position is entered
		{
			cout << "Position entered is invalid" << endl;
		}

		else
		{
			if (head == NULL)	//If there are no chunks in the list
			{
				chunk *temp;
				temp = new chunk;

				temp->value = x;
				head = temp;
				Length++;
			}

			else if ((head->next == NULL) && (position == 1))	//If there is 1 chunk in the list
			{
				chunk *temp;
				temp = new chunk;

				head->next = temp;
				temp->value = x;

				Length++;
			}

			else if ((position == 0) && Length >= 1)	//Adding a chunk at position 0 while there are already items in the list
			{
				chunk* temp = new chunk;
				temp->value = x;

				chunk* chase = new chunk;
				chase = head;

				temp->next = chase;
				head = temp;

				Length++;

			}

			else	//Adds chunk in between two existing chunks or at the end of the list
			{
				chunk *chase;	//Goes to chunk after specified position
				chase = new chunk;
				chase = head;

				chunk *follow;	//Goes to chunk before specified position
				follow = new chunk;
				follow = chase;

				chunk *temp = new chunk;	//Gets added into the list between the chunks that chase and follow point to
				temp->value = x;

				bool last = false;

				for (int i = 0; i < (position); i++)	//Gets chase and follow to proper positions 
				{
					if (chase->next == NULL)	//If you are on the final chunk in the list
					{
						follow = chase;
						last = true;
						break;
					}

					else
					{
						follow = chase;
						chase = chase->next;
					}
				}

				if (!last)	//If you are adding a chunk in between two chunks
				{
					temp->next = chase;
					follow->next = temp;
					Length++;
				}
				
				else	//If you are adding a chunk to the end of the list
				{
					follow->next = temp;
					Length++;
				}
			}
		}
	}

	//Function to delete: give it a position
	void deleteLL(int position)
	{
		if ((position >= Length) || (position < 0))	//An invalid position is entered
		{
			cout << "Position entered is invalid" << endl;
		}

		else
		{
			if (head == NULL)	//No chunks in the list
			{
				cout << "Linked list is empty." << endl;
			}

			else if (Length == 1)	//Only one chunk in the list
			{
				delete head;
				head = NULL;
				Length--;
			}

			else
			{
				chunk *chase;
				chase = new chunk;
				chase = head;

				chunk *follow;
				follow = new chunk;
				follow = chase;

				if (position == 0)	//Deleting the first chunk in the list
				{
					head = follow->next;
					delete follow;
					Length--;
				}

				else
				{
					for (int i = 0; i < position; i++)	//Gets chase and follow to proper positions
					{
						follow = chase;
						chase = chase->next;
					}

					follow->next = chase->next;
					delete chase;
					Length--;
				}

			}
		}

	}

	//Display
	void displayLL()
	{
		if (head == NULL)
		{
			cout << "Nothing to display" << endl;
		}

		else
		{
			chunk *temp;
			temp = head;
			int pos = 0;

			for (int i = 0; i < Length; i++)	//Iterates through list and displays position and value stored in chunk at that position
			{
				cout << "Position " << i << " : " << temp->value << endl;
				temp = temp->next;
			}
		}
		cout << "Length: " << Length << endl;
	}

	//Merge
	void mergeLL(chunk *firstLL, chunk *secondLL)	//Interweaves the two linked lists into one list
	{
		if ((firstLL == NULL) || (secondLL == NULL))	//If one or both of the lists are empty
		{
			cout << "MUST HAVE AT LEAST 1 CHUNK IN EACH LIST TO MERGE" << endl;
		}

		else
		{
			chunk *follow1 = firstLL;
			chunk *chase1 = follow1->next;
			chunk *follow2 = secondLL;
			chunk *chase2 = follow2->next;

			while (1)
			{
				if (follow1->next == NULL)	//If there is only 1 chunk in the first linked list or you've reached the end of the first LL and there are still more chunks in the second LL
				{
					follow1->next = secondLL;
					break;
				}

				follow2->next = chase1;		//Connects a chunk in list 2 to the proper spot in list 1
				follow1->next = follow2;	//Adds the new chunk from list 2 to the rest of list 1

				secondLL = chase2;		//Sets the necxt chunk in list 2 as the new first chunk
				follow2 = chase2;

				if (chase2 != NULL)		//If list 2 is not at its end yet
				{
					chase2 = chase2->next;
				}

				else
				{
					break;
				}

				follow1 = chase1;
				if (chase1 != NULL)		//If list 1 is not going to hit its end after the next chunk
				{
					chase1 = chase1->next;
				}

				else	//If list 1 has reached its end and there are still chunks to add from list 2
				{
					follow1 = secondLL;
					break;
				}
			}
		}
	}

	chunk reverseLinkedList(chunk *head)	//Reverses a linked list (Basically just creates a second linked list where the chunks are reversed and makes that the new list)
	{
		if (head == NULL)	//If there is nothing in the list
		{
			cout << "List must contain something to be reversed." << endl;
		}

		else
		{
			chunk *follow1 = head;
			chunk *chase1 = head->next;

			chunk *rev = NULL;
			chunk *follow2;
			chunk *chase2;

			bool done = false;

			while (1)
			{
				if (done)
				{
					break;
				}

				follow1 = head;
				if (head->next == NULL)		//If there is only 1 chunk in the list
				{
					chase1 = follow1;
				}

				else
				{
					chase1 = head->next;
				}

				while (chase1->next != NULL)	//Moves chase1 to the last chunk in list 1 
				{
					follow1 = chase1;
					chase1 = chase1->next;
				}

				if (rev == NULL)	//If there is nothing in reversed list
				{
					rev = chase1;
					follow1->next = NULL;
				}

				else
				{
					follow2 = rev;
					chase2 = rev;

					while (chase2->next != NULL)	//Moves chase2 to the last chunk in reversed list
					{
						follow2 = chase2;
						chase2 = chase2->next;
					}

					if (head->next == NULL)		//If there is only one more chunk to be removed from list 1
					{
						done = true;;
					}

					chase2->next = chase1;	//Attaches the last chunks in reversed list to last chunk in list 1
					follow1->next = NULL;	//Points second to last chunk in list 1 to NULL so now only reversed list contains the last chunk from list 1
				}

			}

			head = rev;		//After reversed list has been formed in rev set head of list 1 = to rev 
			rev = NULL;

			return *head;	//Return head so LinkedList1 or 2 can be updated
		}
	}

	void detectAndRemoveLoops(chunk *head)
	{
		chunk *follow = head;

		chunk *chase = head->next;

		int length; //Value obtained from getLength()

		int x;

		bool loop = false;

		while (1)
		{
			follow = chase;		//Iterates through the linked list
			chase = chase->next;

			x++;	//Keeps track of how many chunks have passed

			if (x >= length)	//If more chunks have been passed than are supposed to be in the list
			{
				cout << "LOOP DETECTED. REMOVING LOOP." << endl;
				loop = true;
				break;
			}
		}


		if (loop)
		{
			follow = head;
			chase = head->next;

			for (int i = 0; i < (length - 1); i++)	//Get to where the end of the list should be
			{
				follow = chase;
				chase = chase->next;
			}

			chase->next = NULL;		//Set the last chunk->next = to NULL to eliminate the loop
		}

		else
		{
			cout << "No loops detected." << endl;
		}
	}

};



int main()
{

	LL LinkedList, LinkedList2;
	chunk *temp = new chunk;
	int choice = 0;
	int pos = 0;
	int listnum;
	bool done = false;
	bool done2 = false;

	

	while (1)
	{
		done = false;
		done2 = false;

		cout << "-------------------------------------------------------------------------------" << endl;
		cout << "Choose list you wish to edit." << endl;
		cout << "Press 1 to work on LinkedList" << endl;
		cout << "Press 2 to work on LinkedList2" << endl;
		cout << "Press 3 to merge the lists into one list contained in LinkedList" << endl;
		cout << "Press any other number to quit" << endl;
		cout << "-------------------------------------------------------------------------------" << endl;
		cin >> listnum;

		switch (listnum)
		{
		case 1:
			while (!done)
			{
				cout << "-------------------------------------------------------------------------------" << endl;
				cout << "Currently working in LinkedList." << endl;
				cout << "IMPORTANT: Position starts at 0." << endl;
				cout << "Press 1 to add to Linked list" << endl;
				cout << "Press 2 to delete from Linked list" << endl;
				cout << "Press 3 to display Linked list" << endl;
				cout << "Press 4 to reverse Linked List" << endl;
				cout << "Press 5 to return to list selection" << endl;
				cout << "Any other number to quit" << endl;
				cout << "-------------------------------------------------------------------------------" << endl;
				cin >> choice;

				switch (choice)
				{
				case 1: cout << "Add what?" << endl;
					int value;
					cin >> value;
					cout << "Add " << value << " to which postion?" << endl;
					cin >> pos;
					LinkedList.add(value, pos);

					break;

				case 2: cout << "Delete chunk at which position?" << endl;
					cin >> pos;
					LinkedList.deleteLL(pos);

					break;

				case 3:

					LinkedList.displayLL();

					break;

				case 4:
					*temp = LinkedList.reverseLinkedList(LinkedList.head);		//Sets a temporary chunk = to the reversed list

					LinkedList.head = temp;		//Updates LinkedList with the now reversed list
					temp = new chunk;

					break;

				case 5: 
					done = true;

					break;

				default: exit(1);
				}
			}
			break;

		case 2:
			while (!done2)
			{
				cout << "-------------------------------------------------------------------------------" << endl;
				cout << "Currently working in LinkedList2." << endl;
				cout << "IMPORTANT: Position starts at 0." << endl;
				cout << "Press 1 to add to Linked list" << endl;
				cout << "Press 2 to delete from Linked list" << endl;
				cout << "Press 3 to display Linked list" << endl;
				cout << "Press 4 to reverse Linked List" << endl;
				cout << "Press 5 to return to list selection" << endl;
				cout << "Any other number to quit" << endl;
				cout << "-------------------------------------------------------------------------------" << endl;
				cin >> choice;

				switch (choice)
				{
				case 1: cout << "Add what?" << endl;
					int value;
					cin >> value;
					cout << "Add " << value << " to which postion?" << endl;
					cin >> pos;
					LinkedList2.add(value, pos);

					break;

				case 2: cout << "Delete chunk at which position?" << endl;
					cin >> pos;
					LinkedList2.deleteLL(pos);

					break;

				case 3:

					LinkedList2.displayLL();

					break;

				case 4:
					*temp = LinkedList2.reverseLinkedList(LinkedList2.head);

					LinkedList2.head = temp;
					temp = new chunk;

					break;

				case 5: 
					done2 = true;

					break;

				default: exit(1);
				}
			}
			break;

		case 3:
			LinkedList.Length = LinkedList.Length + LinkedList2.Length;
			LinkedList2.Length = 0;
			LinkedList.mergeLL(LinkedList.head, LinkedList2.head);
			LinkedList2.head = NULL;

			break;
			
		default: exit(1);
		}
	}
}