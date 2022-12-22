#include "Vector_Int.h"

Vector_Int::Vector_Int() :start{ new int[MAX_DEFAULT] }, counter{ 0 }, max_counter{ 10 } {
	int* tmp = start;
	for (unsigned int i = 0; i < counter; i++) {
		*tmp++ = 0;
	}
	tmp = nullptr;
}

Vector_Int::Vector_Int(const unsigned int quantity, int value) : start{ new int[quantity] }, counter{ quantity }, max_counter{ quantity } {
	int* tmp = start;
	for (unsigned int i = 0; i < counter; i++) {
		*tmp++ = value;
	}
	tmp = nullptr;
}

Vector_Int::Vector_Int(const Vector_Int& vec) {
	start = new int[vec.max_counter] {0};
	int* tmp = start;
	for (unsigned int i = 0; i < vec.counter; i++) {
		*tmp++ = vec.value_at(i);
	}
	tmp = nullptr;
	counter = vec.counter;
	max_counter = vec.max_counter;
}

Vector_Int::~Vector_Int() {
	delete[] start;
	start = nullptr;
}

void Vector_Int::insert(int value) {
	if (counter == max_counter) {
		int* tmp = start;
		start = new int[max_counter * 2];
		for (unsigned int i = 0; i < max_counter; i++) {
			start[i] = tmp[i];
		}
		max_counter = max_counter * 2;
		delete tmp;
	}
	start[counter++] = value;
}

void Vector_Int::erase(unsigned int pos) {
	if (pos < 0 || pos > counter) {
		return;
	}
	for (unsigned int i = pos; i < counter; i++) {
		start[i] = start[i + 1];
	}
	counter--;
}

int Vector_Int::value_at(unsigned int pos) const {
	if (pos < 0 || pos > counter) {
		return 0;
	}
	return start[pos];
}

void Vector_Int::change_value_at(unsigned int pos, int value) {
	if (pos < 0 || pos > counter) {
		return;
	}
	start[pos] = value;
}

int& Vector_Int::operator[](unsigned int p) {
	if (p < 0 || p > counter) {
		throw std::out_of_range("Index out of array limits");
	}
	return start[p];
}

int& Vector_Int::operator[](unsigned int p) const {
	if (p < 0 || p > counter) {
		throw std::out_of_range("Index out of array limits");
	}
	return start[p];
}