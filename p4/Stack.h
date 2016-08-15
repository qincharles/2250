/**		Charles Qin		**
  *		7/22/14			**
  *		Project 4		**/

/**		This class defines a stack, using the LIFO structure. It specifically handles a stack of char values. 	**/

#ifndef STACK_H
#define STACK_H

#include <cstddef>

class Stack {

private:
	
	// struct for listitems. holds the char value of the item and a pointer to the next item
	struct StackItem {
		char val;
		StackItem * next;
	};

	StackItem * top;	// points to the item at the top of the stack

public:
	Stack() {
		top = NULL;
	}

	~Stack();

	// push moves a char onto the top of the stack
	void push(char);
	
	// pop removes the top char on the stack
	void pop(char &);
	
	// isEmpty returns a bool value depending on whether the stack has any items in it
	bool isEmpty();

};

#endif	
