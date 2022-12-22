
#include <iostream>
#include <vector>
#include "List.h"
#include <string>

List<int>::listptr Interseccion(List<int>::listptr start1, List<int>::listptr start2) {
	List<int>::listptr tmp1 = start1;
	List<int>::listptr tmp2 = start2;
	while (tmp1) {
		while (tmp2) {
			if (tmp1 == tmp2) return tmp1;
			tmp2 = tmp2->next;
		}
		tmp2 = start2;
	}
	return nullptr;
}

//int* Foo(int* n) {
//	int x;
//	n = n + 2;
//
//	x = *n;
//	return &x;
//}

//std::vector<int>* impares(int n) {
//	std::vector<int>* return_vec;
//	if (n <= 1) {
//		return_vec = new std::vector<int>();
//		return_vec->push_back(1);
//		return return_vec;
//	}
//	if (n % 2 == 0) return_vec = impares(n - 1);
//	else {
//		return_vec = impares(n - 2);
//		return_vec->push_back(n);
//	}
//	return return_vec;
//}

//class A {
//public:
//	A(const std::string t) : texto{ new std::string(t) } {}
//	~A() { delete texto; }
//private:
//	std::string* texto;
//};

int main() {
	/*int* v = new int[5]{1, 2, 3, 4, 5};
	int* ptr = Foo(v);
	std::cout << v << "\n";
	std::cout << *ptr;

	delete[] v;*/

	/*int* v = new int[7] {1, 2, 3, 4, 5, 6, 7};
	int* p;
	int* q;
	p = &v[0];
	q = &v[6];


	std::cout << *(p + 6);
	std::cout << &p;
	std::cout << *p + 7;
	std::cout << q - p;*/

	/*A primero("Programacion");
	A segundo(primero);*/

	//int* enteros = new int[6]{0,0,0,0,0,0};
	//int** ptr = &enteros;
	////*enteros[3];
	//std::cout << *(*ptr + 3);

	std::vector<int>* test = impares(3);

	return 0;
}