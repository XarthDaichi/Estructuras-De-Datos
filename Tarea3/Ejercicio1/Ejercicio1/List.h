// Based on ListaSimple.h from El Tigre

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cstddef>

template<class T> class List {
private:
	struct Node {
		T value;
		Node* next;
		Node(T val, Node* nex = nullptr) : value(val), next(nex) {}
	};

	Node* start;

	void initialize() { start = nullptr; }

public:
	typedef Node* listptr;
	typedef const Node* const_listptr;

	List() { initialize(); }

	explicit List(const List& obj) {
		if (obj.inicio == nullptr)
			start = nullptr;
		else {
			start = new Node(obj.start->value);
			listptr actual = start;
			listptr actualObj = obj.start->next;
			while (actualObj != nullptr) {
				actual->start = new Node(actualObj->value);
				actual = actual->next;
				actualObj = actualObj->start;
			}
		}
	}

	~List() { erase_list(); }
	listptr get_first_node() { return start; }
	listptr get_first_node() const { return start; }

	void insert(const T& val) {
		listptr new_node;

		try {
			new_node = new Node(val);
		}
		catch (std::bad_alloc exception) {
			return;
		}

		if (start == nullptr)
			start = new_node;
		else {
			listptr tmp = start;
			while (tmp->next != nullptr)
				tmp = tmp->next;
			tmp->next = new_node;
		}
	}

	void eliminate(listptr pointer) {
		if (pointer == nullptr || start == nullptr)
			return;
		if (start == pointer) {
			start = start->next;
			delete pointer;
		}
		else {
			listptr tmp = start;
			listptr tmp2 = tmp->next;
			while (tmp2 != nullptr) {
				if (tmp2 == pointer) {
					tmp->next = tmp2->next;
					delete tmp2;
					return;
				}
				tmp = tmp2;
				tmp2 = tmp2->next;
			}
		}
	}

	void eliminate_in_pos(std::size_t pos) {
		if (pos <= 0)
			return;

		listptr tmp = start;
		for (std::size_t i = 1; i < pos; ++i) {
			tmp = tmp->next;
			if (tmp == nullptr)
				return;
		}
		eliminate(tmp);
	}

	void erase_list() {
		listptr tmp;
		while (start != nullptr) {
			tmp = start;
			start = start->next;
			delete tmp;
		}
	}

	// 1) Escriba una funcion que reciba dos apuntadores a nodo de una lista enlazada simple y los intercambie.Note que el intercambio debe hacerse a nivel de punteros(no intercambiar los valores)
	void exchange_nodes(listptr& node1, listptr& node2) {
		listptr tmp = start;
		listptr tmp2 = tmp->next;
		listptr changing_tmp = nullptr;
		if (tmp == node1) {
			changing_tmp = node2->next;
			start = node2;
			node2->next = node1->next;
			node1->next = changing_tmp;
			tmp2 = node2->next;
			tmp = start;
		}
		else if (tmp == node2) {
			changing_tmp = node1->next;
			start = node1;
			node1->next = node2->next;
			node2->next = changing_tmp;
			tmp2 = node1->next;
			tmp = start;
		}
		while (tmp2) {
			if (tmp2 == node1) {
				if (!changing_tmp) {
					changing_tmp = node2->next;
					tmp->next = node2;
					node2->next = node1->next;
					node1->next = changing_tmp;
					tmp2 = node2;
				}		
				else {
					tmp->next = node2;
					
				}
			}
			else if (tmp2 == node2) {
				if (!changing_tmp) {
					changing_tmp = node1->next;
					tmp->next = node1;
					node1->next = node2->next;
					node2->next = changing_tmp;
					tmp2 = node1;
				}
				else {
					tmp->next = node1;
					
				}
			}
			tmp = tmp->next;
			tmp2 = tmp->next;
		}
	}

};


#endif //LIST_H
