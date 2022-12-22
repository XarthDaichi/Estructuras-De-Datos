#ifndef PALABRAS_H
#define PALABRAS_H

#include <string>
#include <fstream>

#define DEFAULT	10

class Palabras {
public:
	Palabras();
	Palabras(size_t);
	Palabras(const Palabras&);
	~Palabras();

	int CargarDeArchivo(std::string);
	int GuardarEnArchivo(std::string);
	void AgregarPalabra(std::string);
	std::string** getPtrPalabras();
	void setPtrPalabras(std::string** ptrPalabrasTemp);

private:
	// La clase almacena apuntadores a string, donde se encuentra
	// cada palabra
	std::string** ptrPalabras;
};

#endif
