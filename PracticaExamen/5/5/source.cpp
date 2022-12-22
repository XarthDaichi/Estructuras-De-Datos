/* Escriba una función que retorne un apuntador a la mitad de una lista enlazada simple.
* 
* La complejidad de la funicón debe ser O(n) y la complejidad de espacio O(1).
* Además, debe realizarse en una única pasada, es decir, en un solo recorrido.
*/
#include "List.h"

void print_list(const List<int>& list) {
	List<int>::listptr tmp = list.get_first_node();
	while (tmp) {
		std::cout << tmp->value << '\t';
		tmp = tmp->next;
	}
	std::cout << '\n';
}

int main() {
	List<int> list;


	list.insert(1);
	list.insert(2);
	list.insert(3);
	list.insert(4);
	list.insert(5);

	print_list(list);

	List<int>::listptr middle = list.middle_node();

	std::cout << middle->value << '\n';

	list.insert(6);
	print_list(list);
	middle = list.middle_node();

	std::cout << middle->value << '\n';

	return 0;
}