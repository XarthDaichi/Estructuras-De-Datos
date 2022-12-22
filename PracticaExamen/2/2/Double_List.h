// Based on code by El Tigre
// Description: double linked list

#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

#include <iostream>
#include <cstddef>

template<class T> class Double_List {
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

	Double_List() { initialize(); }

	explicit Double_List(const Double_List& obj) {
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

	~Double_List() { erase_list(); }

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

	/*void insert(const T& val) {
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
	}*/

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
			while (tmp->next != nullptr) {
				tmp = tmp->next;
			}
			tmp->next = new_node;
			new_node->before = tmp;
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
		while (start) {
			tmp = start;
			if (start->before) start->before = nullptr;
			start = start->next;
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

	void invert_list(listptr node, listptr original_start) {
		if (node->next == nullptr) {
			node->before = nullptr;
			node->next = start;
			start->before = node;
			start = node;
			return;
		}
		invert_list(node->next, start);
		if (node != original_start) {
			node->before->next = nullptr;
			node->next = original_start;
			node->before = original_start->before;
			original_start->before = node;
			node->before->next = node;
		}
		return;
	}
};

#endif //DOUBLE_LIST_H