#include <iostream>
#include <vector>
#include <list>
#include <stack>

int main() {
	std::vector<int> v;

	v.push_back(10);
	v.push_back(3);
	v.push_back(22);
	v.push_back(30);

	for (int i = 0; i < 4; i++) { // this will fail if vactor larger than 5 because it will not print it
		std::cout << v[i] << " ";
	}
	std::cout << "\n";
	std::cout << v.capacity() << "\n";
	std::cout << v.size() << "\n";

	//v.clear();

	std::vector<int>::iterator iter;

	for (iter = v.begin(); iter != v.end(); iter++) {
		std::cout << *iter << " ";
	}

	std::list<int> l;

	l.push_front(10);
	l.push_front(3);
	l.push_front(22);
	l.push_front(30);

	std::cout << "\n";
	std::cout << l.size() << "\n";

	//v.clear();

	std::list<int>::iterator iter;
	for (iter = v.begin(); iter != v.end(); iter++) {
		std::cout << *iter << " ";
	}

	std::stack<int> s;
	s.push(10);
	s.push(3);
	s.push(22);
	s.push(30);

	int n = s.top();

	s.pop();

	return 0;
}