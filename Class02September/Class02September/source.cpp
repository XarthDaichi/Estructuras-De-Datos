#include <iostream>

struct Node {
	int value;
	Node* next;

};

int insert(Node** p, int x) {
	if (*p == nullptr) {
		*p = new Node;
		(*p)->value = x;
		(*p)->next = nullptr;
		return x;
	}
	Node** tmp = p;
	while (*tmp != nullptr) {
		*tmp = (*tmp)->next;
	}
	*tmp = new Node;
	(*tmp)->value = x;
	(*tmp)->next = nullptr;
	return x;
}

void print_list(Node* p) {
	Node* tmp;
	tmp = p;
	while (tmp != nullptr) {
		std::cout << tmp->value << ' ';
	}
}

void erase(Node* start, Node* ptr) {
	if (start == ptr) {
		start = start ->next;
	}
	else {
		Node* tmp = start;
		while (tmp->next != ptr) 
			tmp = tmp->next;
		tmp->next = ptr->next;
	}
	delete ptr;
}

void erase_list(Node* start, Node* ptr) {
	while (start) {
		start = start->next;
		delete ptr;
		ptr = start;
	}
}

int main() {
	Node* start = nullptr;

	insert(&start, 10);
	insert(&start, 20);
	insert(&start, 30);
	insert(&start, 40);
	insert(&start, 50);
	insert(&start, 60);
	insert(&start, 70);
	insert(&start, 80);
	insert(&start, 90);
	insert(&start, 100);

	print_list(start);
	return 0;
}