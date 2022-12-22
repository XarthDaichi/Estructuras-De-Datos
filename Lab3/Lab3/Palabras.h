#ifndef PALABRAS_H
#define PALABRAS_H

#include <vector>
#include <string>
#include <sstream>
#include <fstream>

class Palabras {
private:
	std::vector<std::string>* palabras;
public:
	Palabras();
	~Palabras();

	std::vector<std::string>* getPalabras();
	std::vector<std::string>* getPalabras() const;

	void setPalabras(std::vector<std::string>*);

	void CargarDeArchivo(std::string nombreTxt);

	int sizeVector();
	int sizeVector() const;

	std::string operator[] (int position);
	std::string operator[] (int position) const;
};

#endif // PALABRAS_H
