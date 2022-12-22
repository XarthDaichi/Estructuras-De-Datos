#include <iostream>

int main() {
	//MEDIDAS DE MEMORIA ASUMIENDO x32 ARCH
	//PUNTEROS SIEMPRE ALOCAN 4 BYTES DE MEMORIA
	
	/*
	int v[10];     //in stack, 40 bytes, asignacion contigua
	int *ptr;      //in stack, 4 bytes
	char *ptr2;    //in stack, 4 bytes
	double *ptr3;  //in stack, 4 bytes
	*/

	int v[10] = {11, 25, 38, 43, 80, 24, 75, 82, 95, 106};
	
	int* ptr = &v[3];

	//int* ptr2 = ptr + 5; //Esto es como decir muevase 5 espacios dentro del vector v

	std::cout << *ptr;

	//ptr++;
	//*ptr++;   //Aqui no funciona por presedencia de operadores, se ejecuta ++ primero, moviendo la posicion de ptr
	//(*ptr)++; //Aqui si suma el valor uno mas

	return 0;
}