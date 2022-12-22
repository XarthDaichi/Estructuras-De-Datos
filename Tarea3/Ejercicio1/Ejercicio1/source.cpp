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

	list.insert(43);
	list.insert(30);
	list.insert(27);
	list.insert(62);
	list.insert(8);
	list.insert(20);

	List<int>::listptr node2 = list.get_first_node()->next;
	List<int>::listptr node1 = list.get_first_node()->next->next->next->next;

	print_list(list);

	list.exchange_nodes(node1, node2);

	print_list(list);
	
	node1 = list.get_first_node();

	list.exchange_nodes(node1, node2);

	print_list(list);

	return 0;
}

