#include "List.h"

// 2) Escriba un metodo recursivo que imrpima los elementos de una lista enlazada de manera invertida(es decir, desde el ultimo nodo hacia el primer)
void recursive_print_list(const List<int>::listptr& node) {
	if (node->next == nullptr) {
		std::cout << node->value;
		return;
	}
	recursive_print_list(node->next);
	std::cout << '\t' << node->value;
	return;
};


int main() {
	List<int> list;

	list.insert(43);
	list.insert(30);
	list.insert(27);
	list.insert(62);
	list.insert(8);
	list.insert(20);
	recursive_print_list(list.get_first_node());
	return 0;
}