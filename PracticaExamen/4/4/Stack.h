// based on PilaAPI from El Tigre

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cstddef>

class Stack {
private:
	struct Node {
		std::string value;
		Node* next;
		Node(std::string val, Node* nex = nullptr) : value{ val }, next{ nex } {}
	};

	// Apuntadores al inicio y fin de la lista
	Node* top;

	void initialize() { top = nullptr; }

public:
	typedef Node* stackptr;
	typedef const Node* const_stackptr;
	
	// Interfaz de la Pila

	// Constructores
	// Default
	Stack() { initialize(); }

	// Destructor
	~Stack() { erase_stack(); }

	// Operaci�n push() - Inserta un elemento en la pila
	void push(const std::string& val) {
		Node* new_node;

		try {
			new_node = new Node(val, top);
		}
		catch (std::bad_alloc exception) {
			return;
		}

		if (top == nullptr)
			top = new_node;
		else {
			top = new_node;
		}
	}

	// Operaci�n pop() - No verifica si no existen elementos
	std::string pop() {
		Node* tmp = top;
		top = top->next;
		std::string val = tmp->value;
		delete tmp;
		return val;
	}

	std::string peek() {
		return top->value;
	}

	stackptr top_node() { return top; }

	// Borra completamente la pila
	void erase_stack() {
		Node* tmp;
		while (top != nullptr) {
			tmp = top;
			top = top->next;
			delete tmp;
		}
	}

	bool verify_parenthesis() {
		Node* tmp = top;
		int counter = 0;
		while (tmp) {
			if (tmp->value == ")") counter++;
			else if (tmp->value == "(") counter--;
			tmp = tmp->next;
		}
		return counter == 0;
	}
};

#endif