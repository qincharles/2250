#include <iostream>
#include "Stack.h"

using namespace std;

/**		This class implements the definition of a dynamic char stack		**/


// Destructor that deletes every item in the stack list
Stack::~Stack() {
	StackItem * ptr, * next;

	// start at the top of the stack, then move down the list deleting each item
	ptr = top;
	while (ptr != NULL) {
		next = ptr->next;
		delete ptr;
		ptr = next;
	}
}

// push creates a new stackitem with the input char value and adds it to the top of the stack
void Stack::push(char c) {
	StackItem * newChar = new StackItem;	// new stackitem

	newChar->val = c;	// store the input char as the new stackitem's value

	if (isEmpty()) {
		// if the stack is empty, then this char is the first item in the list
		top = newChar;
		newChar->next = NULL;	// set the next of this to NULL so that traversing the stack has an end condition where next = NULL
	} else {
		// if the stack is not empty, make it the new top and set next to the previous top
		newChar->next = top;
		top = newChar;
	}
}

// pop removes the top stackitem and sets the argument variable to equal the value of that top item
void Stack::pop(char &c) {
	StackItem * temp;	// need a temporary pointer to hold the new top item while deleting the old one

	// check for empty stack - print the appropriate response if so
	if (isEmpty()) {
		cout << "Stack is empty - nothing to pop." << endl;
	} else {
		// if not empty, pop the top value
		c = top->val;
		temp = top->next;	// hold the new top in temp so can delete the old top
		delete top;
		top = temp;		// set the new top
	}
}

// isEmpty returns a bool value depenting on whether the stack is empty or not. true for empty, false for not empty
bool Stack::isEmpty() {
	if (!top) { return true; }	// if top's pointer value is 0, then there are no stackitems
	else { return false; }		// if it is not 0, then there are stackitems
}

