#include "Palabras.h"

Palabras::Palabras() {
	palabras = new std::vector<std::string>();
}
Palabras::~Palabras() {
	delete palabras;
}

std::vector<std::string>* Palabras::getPalabras()
{
	return palabras;
}

std::vector<std::string>* Palabras::getPalabras() const
{
    return palabras;
}

void Palabras::setPalabras(std::vector<std::string>* enteringPalabras)
{
	palabras = enteringPalabras;
}

void Palabras::CargarDeArchivo(std::string nombreTxt)
{
    std::string tempPalabra;


    std::ifstream in(nombreTxt, std::ios::in);

    if (!in.is_open()) {
        throw std::invalid_argument("Could not open file [" + nombreTxt + "]");
    }
    while (in.good()) {
        // getting the word
        getline(in, tempPalabra, '\n');

        // adding string to list
        if (!tempPalabra.empty()) palabras->push_back(tempPalabra);
    }
}

int Palabras::sizeVector()
{
    return palabras->size();
}

int Palabras::sizeVector() const
{
    return palabras->size();
}

std::string Palabras::operator[] (int position) {
    return palabras->at(position);
}

std::string Palabras::operator[] (int position) const {
    return palabras->at(position);
}


