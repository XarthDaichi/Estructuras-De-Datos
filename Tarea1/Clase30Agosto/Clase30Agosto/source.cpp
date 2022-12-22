#include <iostream>

struct Node {
	int valor;
	Node* next; // Nodo* next (tambien sirve)

};

int insertar(Node** p, int x) { // se puede hacer tambien Node*&
	if (*p == nullptr) {
		*p = new Node;
		(*p)->valor = x;
		(*p)->next = nullptr;
		return x;
	}
	Node** tmp = p;
	while (*tmp != nullptr) {
		*tmp = (*tmp)->next;
	}
	*tmp = new Node;
	(*tmp)->valor = x;
	(*tmp)->next = nullptr;
	return x;
}

void imprimir_lista(Node* p) {
	Node* tmp;
	tmp = p;
	while (tmp != nullptr) {
		std::cout << tmp->valor << ' '; // can use (*tmp).valor insted of ->
		tmp = tmp->next;
	}
}

int main() {
	Node* inicio = nullptr; // new Node; // no se puede igualar a nullptr porque entonces si se le intanta cambiar el valor entonces se desreferencia un null

	/*Node prueba;
	prueba.next = nullptr;
	prueba.valor = 500;*/

	/*inicio->valor = 100;
	inicio->next = nullptr;*/

	/*std::cout << inicio->valor;

	inicio->next = new Node;
	inicio->next->valor = 200;
	inicio->next->next = nullptr;

	inicio->next->next = &prueba;

	std::cout << inicio->next->valor;
	std::cout << inicio->next->next->valor;*/

	//Node* tmp;
	//tmp = inicio;

	//while (tmp) { // could use (tmp != nullptr) for better reading
	//	std::cout << tmp->valor;
	//	tmp = tmp->next;
	//}

	insertar(&inicio, 10);
	insertar(&inicio, 20);
	insertar(&inicio, 30);
	insertar(&inicio, 40);
	insertar(&inicio, 50);
	insertar(&inicio, 60);
	insertar(&inicio, 70);
	insertar(&inicio, 80);
	insertar(&inicio, 90);
	insertar(&inicio, 100);
	
	imprimir_lista(inicio);
	return 0;
}