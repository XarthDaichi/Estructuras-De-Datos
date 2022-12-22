#include <iostream>

class Foo {
public:
	int* algo(int a, int b) {
		// int* x solamente causa error porque no esta inicializado
		int* x = new int;
		*x = a + b;
		return x;

		/*int x;
		x = a + b;
		return &x*/; // falla porque x es variable local de algo y cuando salga de algo (retorne) se borra el valor en esa direccion
	}
};

//class Foo {
//public:
//	int** algo(int a, int b) {
//		int* x;
//		*x = a + b;
//		return &x;
//	}
//};

int main() {
	Foo a1; // Almacenada en el STACK
	Foo* a2 = new Foo; // Una variable puntero que almacena una direccion de un Foo
	// *a2 = a1;
	// a2 = &a1 ahora a2 apunta a a1

	int* x = a1.algo(10, 20);
	std::cout << "Algo de A1: " << *x << "\n";

	int* y = a2->algo(5, 7);
	// int* y = a2.algo(5, 7); no se puede usar porque a2 (puntero) no tiene un miembro algo en si
	// int* y = *a2. algo(5, 7); no va a servir por orden de operaciones
	// int* y = (*a2).algo(5, 7); sintaxis incomoda mejor usar la flechita
	std::cout << "Algo de A2: " << *y;

	// delete a2; // con cada new hay un delete
	// delete x; // hay un new en algo
	// delete y; // hay un new en algo

	delete a2, x, y;

	return 0;
}