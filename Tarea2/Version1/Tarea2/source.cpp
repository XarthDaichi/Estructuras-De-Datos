#include <iostream>
#include "VectorInt.h"

void print(VectorInt& e, unsigned int position) {
	std::cout << "| ";
	for (unsigned int i = 0; i < position; i++) {
		std::cout << e[i] << " | ";
	}
	std::cout << "\n";
}

int main() {

	/*int vec1[10];*/
	VectorInt vec;

	vec.insert(1);
	print(vec, 10);
	vec.insert(2);
	print(vec, 10);
	vec.insert(3);
	print(vec, 10);
	vec.insert(4);
	print(vec, 10);
	vec.insert(5);
	print(vec, 10);
	vec.insert(6);
	print(vec, 10);
	vec.insert(7);
	print(vec, 10);
	vec.insert(8);
	print(vec, 10);
	vec.insert(9);
	print(vec, 10);
	vec.insert(10);
	print(vec, 10);
	vec.insert(11);
	print(vec, 20);

	vec.change_value_at(0, 12);

	print(vec, 20);

	vec.change_value_at(10, 13);

	print(vec, 20);

	vec.erase(15);

	print(vec, 20);

	return 0;
}
