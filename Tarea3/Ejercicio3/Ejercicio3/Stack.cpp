#include "Stack.h"

Stack::Stack() : top{ nullptr }, quantity(0) {}


Stack::~Stack() {
	Node* tmp = top;
	while (top != nullptr) {
		top = top->next;
		delete tmp;
		tmp = top;
	}
}

void Stack::push(const int item) {
	Node* new_node;

	try
	{
		new_node = new Node;
	}
	catch (std::bad_alloc exception)
	{
		return;
	}

	new_node->element = item;
	new_node->next = top;
	top = new_node;
	quantity++;
}

int Stack::pop() {
	if (empty())
		return -1;

	int valor;
	Node* tmp;

	valor = top->element;
	tmp = top;
	top = top->next;
	delete tmp;
	tmp = nullptr;
	quantity--;
	return valor;
}

int Stack::peek() {
	return (!empty() ? top->element : -1);
}

bool Stack::empty() {
	return top == nullptr;
}

void Stack::exchange_nodes() {
	listptr tmp = top;
	for (int i = 0; i < quantity - 1; i++)
		tmp = tmp->next;
	listptr tmp2 = top->next;
	listptr after_tmp = tmp;
	listptr changing_tmp = top;
	
	top = tmp;
	top->next = tmp2;
	after_tmp = changing_tmp;
	for (int i = 0; i < quantity - 3; i++)
		tmp2 = tmp2->next;
	tmp2->next = after_tmp;
}

void Stack::invert_stack() {	
	if (quantity <= 1) {
		return;
	}
	exchange_nodes();
	int val = pop();
	invert_stack();
	push(val);
}