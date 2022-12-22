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
};


#endif //LIST_H
