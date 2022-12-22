// Based on code by El Tigre
// Description: double linked list

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cstddef>

template<class T> class List {
private:
	struct Node {
		T value;
		Node* before;
		Node* next;
		/*Node(T val, Node* nex = nullptr) : value{ val }, next{ nex } {}*/
		Node(T val, Node* bef = nullptr, Node* nex = nullptr) : value{ val }, before{ bef }, next{ nex } {}
	};

	Node* start;
	void initialize() { start = nullptr; }

public:
	typedef Node* listptr;
	typedef const Node* const_listptr;

	List() { initialize(); }

	explicit List(const List& obj) {
		if (obj.start == nullptr)
			start = nullptr;
		else {
			start = new Node(obj.start->value);
			start->before = nullptr;
			listptr actual = start;
			listptr actual_obj_before;
			listptr actual_obj_next = obj.start->next;
			while (actual_obj_next != nullptr) {
				actual->next = new Node(actual_obj_next->value);
				actual->next->before = actual;
				actual = actual->next;
				actual_obj_next = actual_obj_next->next;
			}
		}
	}

	~List() { erase_list(); }

	listptr get_first_node() { return start; }

	listptr get_first_node() const { return start; }

	/*void insert_first_pos(const T& val) {
		listptr new_obj;
		
		try {
			new_obj = new Node(val);
		}
		catch (std::bad_alloc exception) {
			return;
		}

		listptr tmp = start;
		tmp->before = new_obj;
		new_obj->next = tmp;
		start = new_obj;

	}*/
	
	void insert(const T& val) {
		listptr new_obj;

		try {
			new_obj = new Node(val);
		}
		catch (std::bad_alloc exception) {
			return;
		}

		if (start == nullptr) {
			start = new_obj;
		}
		else {
			listptr tmp = start;
			tmp->before = new_obj;
			new_obj->next = tmp;
			start = new_obj;
		}
	}

	void eliminate(listptr pointer) {
		if (pointer == nullptr || start == nullptr)
			return;

		if (start == pointer) {
			start->next->before = nullptr;
			start = start->next;
			delete pointer;
		}
		else {
			listptr tmp = start;
			listptr tmp2 = tmp->next;
			while (tmp2 != nullptr) {
				if (tmp2 == pointer) {
					tmp->next = tmp2->next;
					tmp2->next->before = tmp;
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
			start->before = nullptr;
			delete tmp;
		}
	}

	Node search(const T& val) {
		listptr tmp = start;
		while (tmp->next != nullptr) {
			if (tmp->value == val)
				return *tmp;
			tmp = tmp->next;
		}
		return Node(-1);
	}
};

#endif //LIST_H