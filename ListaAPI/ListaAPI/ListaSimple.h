// Autor: El Tigre
// Descripci�n: Definici�n de una lista enlazada simple

#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

#include <iostream>
#include <cstddef>

// Lista que se construye a partir de nodos autoreferenciados
// con datos definidos por el usuario
template<class T> class ListaSimple {
private:
	// Declaraci�n de cada nodo de la lista: contiene el valor y un apuntador a un nodo
	// Queda oculto para el usuario
	struct Nodo {
		T valor;
		Nodo* next;
		// Constructor del Nodo - asigna NULL si se invoca sin el segundo par�metro
		Nodo(T val, Nodo* sig = nullptr) : valor{ val }, next{ sig } {}
	};

	// Apuntador al inicio de la lista
	Nodo* inicio;

	void Inicializar() { inicio = nullptr; }

	// Interfaz de la Lista Enlazada Simple
public:

	// Declaraci�n de definici�n de tipos
	typedef Nodo* listaptr;
	typedef const Nodo* const_listaptr;

	// Constructores
	// Default
	ListaSimple() { Inicializar(); }
	// Copia
	explicit ListaSimple(const ListaSimple& obj) {
		if (obj.inicio == nullptr)
			inicio = nullptr;
		else {
			inicio = new Nodo(obj.inicio->valor);
			listaptr actual = inicio;
			listaptr actualObj = obj.inicio->next;
			while (actualObj != nullptr) {
				actual->next = new Nodo(actualObj->valor);
				actual = actual->next;
				actualObj = actualObj->next;
			}
		}
	}

	// Destructor
	~ListaSimple() { BorrarLista(); }

	// Retorna un apuntador al primer nodo de la lista - modificable
	listaptr GetPrimerNodo() { return inicio; }

	// Retorna un apuntador al primer nodo de la lista - para un objeto const
	listaptr GetPrimerNodo() const { return inicio; }
	
	// Inserta un elemento al final de la lista enlazada
	void Insertar(const T& val) {
		listaptr nuevo;

		try {
			nuevo = new Nodo(val);
		}
		catch (std::bad_alloc exception) {
			return;
		}

		if (inicio == nullptr)
			inicio = nuevo;
		else {
			listaptr tmp = inicio;
			while (tmp->next != nullptr)
				tmp = tmp->next;
			tmp->next = nuevo;
		}
	}

	// Elimina el nodo especificado de la lista enlazada
	void Eliminar(listaptr puntero) {
		// No hay nada que borrar si la lista enlazada est� vac�a
        // o el puntero es NULL
		if (puntero == nullptr || inicio == nullptr)
			return;

		// Caso #1: El elemento a borrar es el primero de la lista enlazada
		if (inicio == puntero) {
			inicio = inicio->next;
			delete puntero;
		}
		// Caso #2: El elemento se encuentra en alguna otra posici�n de la lista
		else {
			listaptr tmp = inicio;
			listaptr tmp2 = tmp->next;
			while (tmp2 != nullptr) {
				if (tmp2 == puntero) {
					tmp->next = tmp2->next;
					delete tmp2;
					return;
				}
				tmp = tmp2;
				tmp2 = tmp2->next;
			}
		}
	}
	
	// Elimina un nodo de la lista en la posici�n especificada
	void EliminarEnPos(std::size_t pos) {
		if (pos <= 0)
			return;

		listaptr tmp = inicio;
		for (std::size_t i = 1; i < pos; ++i) {
			tmp = tmp->next;
			if (tmp == nullptr)
				return;
		}
		Eliminar(tmp);
	}

	// Borra completamente la lista
	void BorrarLista() {
		listaptr tmp;
		while (inicio != nullptr) {
			tmp = inicio;
			inicio = inicio->next;
			delete tmp;
		}
	}
};

#endif