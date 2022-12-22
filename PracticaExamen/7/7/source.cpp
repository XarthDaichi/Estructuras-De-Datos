/* Escriba una función recursiva que determine si los elementos de un vector se encuentran ordenados de manera ascendente.
* La función recibe por parámetro únicamente el vector y la cantidad de elements de este.
*/

#include <iostream>
#include "Vector_Int.h"

bool sorted_elements(Vector_Int vec, int quantity) {
	if (quantity == 2) {
		if (vec[0] <= vec[1]) return true;
		else return false;
	}
	Vector_Int slice_vec(vec);
	slice_vec.erase(0);
	bool returning_value = sorted_elements(slice_vec, slice_vec.quantity());
	if (returning_value) {
		if (vec[0] <= vec[1]) return true;
		else return false;
	}
	else return false;
}

void print(const Vector_Int& vec) {
	for (unsigned int i = 0; i < vec.quantity(); i++) {
		try {
			std::cout << vec[i] << " ";
		}
		catch (const std::out_of_range& error) {
			std::cout << "Error: " << error.what() << "\n";
		}
	}
	std::cout << "\n";
}

int main() {
	Vector_Int vector_a;

	Vector_Int vector_b(25, 7);


	vector_a.insert(8);
	vector_a.insert(13);
	vector_a.insert(20);
	vector_a.insert(29);
	vector_a.insert(35);

	vector_b.insert(14);
	vector_b.insert(2);
	vector_b.insert(49);
	vector_b.insert(100);
	vector_b.insert(98);

	vector_a.change_value_at(4, 75);
	vector_b.change_value_at(3, 66);

	vector_a.erase(2);

	// Invoca al constructor de copia
	Vector_Int vector_c(vector_a);

	print(vector_a);
	print(vector_b);
	print(vector_c);


	Vector_Int vector_d;
	vector_d.insert(1);
	vector_d.insert(2);
	vector_d.insert(3);
	vector_d.insert(4);
	vector_d.insert(5);

	print(vector_d);

	std::cout << sorted_elements(vector_a, vector_a.quantity()) << "\n";
	std::cout << sorted_elements(vector_b, vector_b.quantity()) << "\n";
	std::cout << sorted_elements(vector_d, vector_d.quantity()) << "\n";
	// Para probar que existe un error a la hora de acceder a una posici�n fuera del rango del vector
	try {
		std::cout << vector_c[20];
	}
	catch (const std::out_of_range& error) {
		std::cout << "Error: " << error.what() << "\n";
	}
	return 0;
}