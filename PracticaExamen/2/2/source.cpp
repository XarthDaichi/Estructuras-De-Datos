/* Haga lo mismo que el ejercicio 1 pero recursivo
*/
#include "List.h"
#include "Double_List.h"

void print_list(const List<int>& list) {
	List<int>::listptr tmp = list.get_first_node();
	while (tmp) {
		std::cout << tmp->value << '\t';
		tmp = tmp->next;
	}
	std::cout << '\n';
}

void print_list(const Double_List<int>& list) {
	Double_List<int>::listptr tmp = list.get_first_node();
	while (tmp) {
		std::cout << tmp->value << '\t';
		tmp = tmp->next;
	}
	std::cout << '\n';
}

int main() {
	std::cout << "-------LIST--------\n";
	List<int> list;

	list.insert(43);
	list.insert(30);
	list.insert(27);
	list.insert(62);
	list.insert(8);
	list.insert(20);

	print_list(list);

	list.invert_list(list.get_first_node(), list.get_first_node());

	print_list(list);

	std::cout << "-------DOUBLE LIST---------\n";
	Double_List<int> double_list;

	double_list.insert(43);
	double_list.insert(30);
	double_list.insert(27);
	double_list.insert(62);
	double_list.insert(8);
	double_list.insert(20);

	print_list(double_list);

	double_list.invert_list(double_list.get_first_node(), double_list.get_first_node());

	print_list(double_list);
	return 0;
}