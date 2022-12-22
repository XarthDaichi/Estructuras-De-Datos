#include "Palabras.h"
#include <iostream>
#include <algorithm>
#include <random>


void Imprimir(const Palabras& palabras) {
	for (int i = 0; i < palabras.sizeVector(); i++) {
		std::cout << palabras[i] << '\n';
	}
}

int main() {
	std::cout << "----------------PARTE 1---------------------\n";
	Palabras palabras;
	
	palabras.CargarDeArchivo("../archivoPalabras.txt");
    std::cout << "Tamano de palabras: " << palabras.sizeVector() << '\n';
	// elements before sorting
	Imprimir(palabras);
	
	std::cout << "------------------SORT TEST-------------------\n";
	//sorting
	sort(palabras.getPalabras()->begin(), palabras.getPalabras()->end(), std::greater<>());

	// elements after sorting
	Imprimir(palabras);

	//std::cout << "------------------ALPHABET TEST-------------------\n";
	//// other test
	//Palabras palabras2;
	//palabras2.CargarDeArchivo("../abecedario.txt");
	//sort(palabras2.getPalabras()->begin(), palabras2.getPalabras()->end(), std::greater<>());
	//Imprimir(palabras2);

    std::cout << "-----------------RANDOM TEST--------------------\n";
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::shuffle(palabras.getPalabras()->begin(), palabras.getPalabras()->end(), generator);
    Imprimir(palabras);


	std::cout << "----------------PARTE 2---------------------\n";

    std::vector<int> v;

    std::cout << "Delaracion del vector\n";
    std::cout << v.size() << " ";
    std::cout << v.capacity() << " ";
    /*
    * Las diferentes operaciones del vector hacen lo siguiente :
    * size(): retorna el nuemro de la cantidad de epacios utilizados en el vector.
    * capacity(): retorna la cantidad maxima de elementos que pueden existir en el vector.
    * reserve(): reserva un numero de espacios para la cantidad maxima.
    */

    std::cout << "\nse agrega un elemento\n";
    v.push_back(2);
    std::cout << v.size() << " ";
    std::cout << v.capacity() << " ";
    /*
        Aqui notamos que al agregar un elemento en el vector y al tener capacity y size 0,
        incrementa la capacity y size del vector por igual, pero vemos como se le aloca más
        memoria al vector para el elemento pasado por parametro.
    */

    std::cout << "\nse utiliza el metodo reserve en 5\n";
    v.reserve(5);
    std::cout << v.size() << " ";
    std::cout << v.capacity() << " ";
    /*
        reserve() en este caso cambia la capacity del vector al numero pasado por parametro
    */

    std::cout << "\nse llena la agregan 4 numeros mas y se imprime size y capacity\n";
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    std::cout << v.size() << " ";
    std::cout << v.capacity() << " ";

    std::cout << "\nagregando un numero mas\n";
    v.push_back(2);
    std::cout << v.size() << " ";
    std::cout << v.capacity() << " ";
    /*
        Aqui vemos el mismo comportamiento visto al inicio del programa donde se aloca
        memoria para un nuevo numero incluso despues de que el capacity se llenara.

            Lo que sucede en la memoria:
                Al usar el inspector y analizar las direcciones de memoria "v" se encentra
                en una direccion de memoria completamente diferentes a las que se encuentra
                "v[0]", pero el salto es tan grande que nos atrevemos a pensar que se instancian
                en el heap. Pero tambien vemos como la direccion de "v[1]" se aloca de manera
                consecutiva a "v[0]" por lo que cumple con lo la funcion de un vector al
                tener memoria continua.
    */
	return 0;
}

