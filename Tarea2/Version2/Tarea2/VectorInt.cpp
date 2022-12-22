#include "VectorInt.h"

VectorInt::VectorInt() {
	start = new int[10];
	max_counter = 10;
	counter = 0;
	for (unsigned int i = 0; i < max_counter; i++) {
		start[i] = 0;
	}
}

VectorInt::VectorInt(const unsigned int max) {
	start = new int[max];
	max_counter = max;
	counter = 0;
	for (unsigned int i = 0; i < max_counter; i++) {
		start[i] = 0;
	}
}

VectorInt::VectorInt(const VectorInt& copying) {
	start = new int[copying.quantity()];
	max_counter = copying.quantity();
	counter = max_counter;
	for (int i = 0; i < counter; i++) {
		if (copying.value_at(i) != 0)
			start[i] = copying.value_at(i);
		else
			i--;
	}
}

VectorInt::~VectorInt() {
	delete[] start;
}

void VectorInt::insert(int inserting) {
	if (counter == max_counter) {
		max_counter *= 2;
		int* tmp = new int[max_counter];
		for (unsigned int i = 0; i < max_counter; i++) {
			tmp[i] = 0;
		}
		for (unsigned int i = 0; i < counter; i++)
			tmp[max_counter - 1 - i] = start[counter - 1 - i];
		delete[] start;
		start = tmp;
	}
	if (counter != 0)
		for (int i = counter -1; i >= 0; i--)
			start[max_counter - 2 - i] = start[max_counter - 1 - i];
	start[max_counter - 1] = inserting;
	counter++;
}

void VectorInt::erase(unsigned int position) {
	start[position] = 0;
	for (unsigned int i = position; i > 0; i--)
		start[i] = start[i - 1];
	if (start[0] != 0) start[0] = 0;
	counter--;
}

int VectorInt::value_at(unsigned int position) const {
	return start[position];
}
void VectorInt::change_value_at(unsigned int position, int changing) {
	start[position] = changing;
}

unsigned int VectorInt::quantity() const {
	return counter;
}

int VectorInt::operator[](unsigned int position) {
	return start[position];
}