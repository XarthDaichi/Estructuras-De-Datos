#include "palabras.h"

Palabras::Palabras() : ptrPalabras{ new std::string*[DEFAULT]} {
	for (size_t i = 0; i < DEFAULT; i++) ptrPalabras[i] = new std::string;
}

Palabras::Palabras(size_t tam) : ptrPalabras{new std::string*[tam]} {
	for (size_t i = 0; i < tam; i++) ptrPalabras[i] = new std::string;
}

Palabras::Palabras(const Palabras& copia) {
	*this = copia;
}

Palabras::~Palabras() {
	for (size_t i = 0; i < sizeof(*ptrPalabras); i++) {
		delete ptrPalabras[i];
	}
	delete ptrPalabras;
}

// Retorna un número entero igual o mayor a cero si cargó correctamente
// El número puede representar la cantidad de palabras cargadas
// Retorna -1 si hubo un error 
int Palabras::CargarDeArchivo(std::string nombre) {
	std::string* tempPalabra = new std::string;
	int counter = 0;

	std::ifstream in(nombre, std::ios::in);
	if (!in.is_open()) {
		return -1;
	}

	while (in.good()) {
		getline(in, *tempPalabra, ';');
		ptrPalabras[counter++] = tempPalabra;
	}
	in.close();
	return counter;
}

// Retorna un número entero igual o mayor a cero si guardó correctamente
// El número puede representar la cantidad de palabras guardadas
// Retorna -1 si hubo un error 
int Palabras::GuardarEnArchivo(std::string nombre) {
	std::ofstream out(nombre, std::ios::trunc);
	int counter = 0;
	if (!out.is_open()) {
		return -1;
	}
	for (size_t i = 0; i < sizeof(*ptrPalabras); i++) {
		out << *ptrPalabras[i] << ';';
		counter += 1;
	}
	out.close();
	return counter;
}

// Almacena una nueva palabra en el vector
void Palabras::AgregarPalabra(std::string palabra) {
	for (size_t i = 0; i < sizeof(*ptrPalabras); i++) {
		if (ptrPalabras[i] == "") {
			*ptrPalabras[i] = palabra;
			break;
		}
	}
}

std::string** Palabras::getPtrPalabras() {
	return ptrPalabras;
}

void Palabras::setPtrPalabras(std::string** ptrPalabrasTemp)
{
	this->ptrPalabras = ptrPalabrasTemp;
}