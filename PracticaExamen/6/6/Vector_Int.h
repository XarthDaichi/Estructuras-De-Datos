// based on VectorInt from El Tigre

#ifndef VECTOR_INT_H
#define VECTOR_INT_H

#include <stdexcept>

#define MAX_DEFAULT 10

class Vector_Int {
private:
	int* start;
	unsigned int max_counter;
	unsigned int counter;

public:
	Vector_Int();
	Vector_Int(const unsigned int, int value = 0);
	Vector_Int(const Vector_Int&);
	~Vector_Int();

	void insert(int);
	void erase(unsigned int);

	int value_at(unsigned int) const;
	void change_value_at(unsigned int, int);

	unsigned int quantity() const { return counter; }

	int& operator[](unsigned int);
	int& operator[](unsigned int) const;
};


#endif // VECTOR_INT_H