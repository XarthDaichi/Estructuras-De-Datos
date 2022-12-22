/* Haga lo mismo que el ejercicio 1 pero recursivo
*/
#include "Double_List.h"

void print_list(const Double_List<int>& list) {
	Double_List<int>::listptr tmp = list.get_first_node();
	while (tmp) {
		std::cout << tmp->value << '\t';
		tmp = tmp->next;
	}
	std::cout << '\n';
}

int main() {
	std::cout << "-------DOUBLE LIST---------\n";
	Double_List<int> double_list;

	double_list.insert(43);
	double_list.insert(30);
	double_list.insert(27);
	double_list.insert(62);
	double_list.insert(8);
	double_list.insert(20);

	print_list(double_list);

	double_list.insert_in_pos(1, 0);
	print_list(double_list);
	double_list.insert_in_pos(1, 1);
	print_list(double_list);
	double_list.insert_in_pos(1, 8);
	print_list(double_list);
	double_list.insert_in_pos(1, 11);
	print_list(double_list);
	double_list.insert_in_pos(1, 5);
	print_list(double_list);

	return 0;
}