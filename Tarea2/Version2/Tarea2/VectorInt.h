#ifndef VECTORINT_H
#define VECTROINT_H

class VectorInt {
private:
	int* start;
	unsigned int max_counter;
	unsigned int counter;
public:
	VectorInt();
	VectorInt(const unsigned int);
	VectorInt(const VectorInt&);
	~VectorInt();

	void insert(int);
	void erase(unsigned int);

	int value_at(unsigned int) const;
	void change_value_at(unsigned int, int);

	unsigned int quantity() const;

	int operator [] (unsigned int);
};

#endif // VECTORINT_H