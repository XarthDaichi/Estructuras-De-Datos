#include "VectorInt.h"

VectorInt::VectorInt() {
	start = new int(0);
	max_counter = 10;
	counter = 0;
	for (unsigned int i = 0; i < max_counter; i++) {
		*(start + i) = 0;
	}
}

VectorInt::VectorInt(const unsigned int max) {
	start = new int(0);
	max_counter = max;
	counter = 0;
	for (unsigned int i = 0; i < max_counter; i++) {
		*(start + i) = 0;
	}
}

VectorInt::VectorInt(const VectorInt& copying) {
	start = new int(0);
	max_counter = copying.quantity();
	counter = copying.quantity();
	for (unsigned int i = 0; i < counter; i++) {
		*(start + i) = copying.value_at(i);
	}
}

VectorInt::~VectorInt() {
	/*for (unsigned int i = 1; i < max_counter; i++) {
		int* tmp = start + i;
		delete tmp;
	}*/
	//delete start; not using heap so I don't have to delete it (in part trying to delete any of these causes heap block)
}

void VectorInt::insert(int inserting) {
	if (counter == max_counter) {
		max_counter *= 2;
		for (unsigned int i = counter; i <= max_counter; i++) {
			*(start + i) = 0;
		}
		for (unsigned int i = 0; i < counter + 1; i++) {
			*(start + max_counter - 1 - i) = *(start + counter - 1 - i);
			*(start + counter - 1 - i) =  0;
		}
	}
	if (counter != 0) {
		for (int i = counter - 1; i >= 0; i--) 
			*(start + max_counter - 2 - i) = *(start + max_counter - 1 - i);
	}
	*(start + max_counter - 1) = inserting;
	counter++;
}

void VectorInt::erase(unsigned int position) {
	*(start + position) = 0;
	for (unsigned int i = position; i > 0; i--)
		*(start + i) = *(start + i - 1);
	if (*start != 0) *start = 0;
	counter--;
}

int VectorInt::value_at(unsigned int position) const {
	return *(start + position);
}

void VectorInt::change_value_at(unsigned int position, int changing_value) {
	*(start + position) = changing_value;
}

unsigned int VectorInt::quantity() const {
	return counter;
}

int VectorInt::operator [] (unsigned int position) {
	return *(start + position);
}