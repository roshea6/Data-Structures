#include<iostream>
#include<stdlib.h>
using namespace std; 

//STEP1: Create a conceptual "idea" of a chunk. We'll build a stack of chunks 
class chunk {
public:
	int value; 
	chunk *next; 
	//give our building blocks a default look and feel
	chunk() { 
		value = 0; 
		next = NULL;
	}
}; 

class Stack {
public: 
	chunk *top; //gateway pointer to the structure 

	//constructor
	Stack() { 
		top = NULL; //start with an empty stack
	}
	
	//Functions, with an underlying philosophy: LIFO 
	//Function 1: Add to the stack, popularly called 'push' 
	void push(int x) { 
		//get a new chunk, we are going to add this
		chunk *temp; 
		temp = new chunk; 
		temp->value = x; 

		//is my stack empty? 
		if(top == NULL) { 
			//new element becomes the top
			top = temp;
		}
		else { 
			//stack has more than one chunk in there already
			temp->next = top; 
			top = temp;
		}
		
	}

	//Function 2: Delete from stack, popularly called 'pop' 
	void pop() {
		if(top == NULL) {
			cout << "Empty stack, nothing to delete" << endl;
		}
		else {
			chunk *temp; 
			temp = top; 
			top = temp->next; //top points to the second element 
			cout << "About to delete: " << temp->value << endl; 
			delete temp;
		}
	}

	void display() {
		chunk *traverse = top; 
		if(top == NULL) { 
			cout << "Empty Stack. Nothing to display" << endl;
		}
		else {
			while(traverse != NULL) {
				cout << traverse->value << "-->" << endl;
				traverse = traverse->next; 

			}
		}
	}


};


int main()
{

	Stack ourStack; 
	int choice = 0; 

	while(1) 
	{ 
		cout << "Press 1 to add to stack" << endl;
		cout << "Press 2 to delete from stack" << endl;
		cout << "Press 3 to display" << endl;
		cout << "Anything else to quit" << endl; 
		cin >> choice;

		switch(choice) {
			case 1: cout << "Add what?" << endl;
					  int value; 
					  cin >> value; 
					  ourStack.push(value); 
					  break;

			case 2: ourStack.pop();
					  break;

			case 3: ourStack.display();
					  break;

			default: exit(1);
		}
	}


}













