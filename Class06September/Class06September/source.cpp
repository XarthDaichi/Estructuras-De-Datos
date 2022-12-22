/*
Lab 2
1) Insertar en la primera posicion (Lista)
2) Convertir a una lista doblemente enlazada
*/

#include "List.h"
#include <iostream>


void show(const List<int>& l) {
	List<int>::listptr tmp;
	tmp = l.get_first_node();

	while (tmp != nullptr) {
		std::cout << tmp->value << " ";
		tmp = tmp->next;
	}
	std::cout << "\n\n";
}

int main() {
	List<int> list;

	list.insert(43);
	list.insert(30);
	list.insert(27);
	list.insert(62);
	list.insert(8);
	list.insert(20);

	show(list);

	list.insert(1);

	show(list);

	list.eliminate_in_pos(3);

	show(list);

	std::cout << list.search(1).value << "\n\n";
	std::cout << list.search(20).value << "\n\n";
	std::cout << list.search(8).value << "\n\n";

	list.erase_list();

	return 0;
}