/*
3) Escriba un algoritmo que invierta los elementos de una pila utilizando recusion (no puede utilizar ninguna estructura de datos auxiliar)
*/
#include "Stack.h"

//void invert_stack(Node* nodo) {
//	if (inverting_stack.get_top()->next == nullptr) {
//		inverting_stack.push(inverting_stack.get_top()->value);
//		return;
//	}
//	int val = inverting_stack.pop();
//	invert_stack()
//
//}

int main() {
	Stack stack;

	stack.push(45);
	stack.push(60);
	stack.push(35);

	std::cout << stack.pop() << " ";
	std::cout << stack.pop() << " ";
	std::cout << stack.pop() << "\n";

	stack.push(45);
	stack.push(60);
	stack.push(35);

	stack.invert_stack();

	std::cout << stack.pop() << " ";
	std::cout << stack.pop() << " ";
	std::cout << stack.pop() << "\n";

	return 0;
}