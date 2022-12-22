#include <iostream>

unsigned int decimal_a_binario(unsigned int x) {
	if (x <= 1) 
		return x;
	return 10*decimal_a_binario(x/2) + x%2;
}

int main() {
	unsigned int number;
	std::cin >> number;
	std::cout << decimal_a_binario(number);
	return 0;
}