#ifndef STACK_H
#define STACK_H

#include <iostream>

class Stack {
private:
	struct Node {
		int element;
		struct Node* next;
	};
	struct Node* top;
	int quantity;
public:
	Stack();
	~Stack();

	void push(const int);
	int pop();
	int peek();
	bool empty();

	typedef Node* listptr;
	typedef const Node* const_listptr;

	void exchange_nodes();

	void invert_stack();
};

#endif