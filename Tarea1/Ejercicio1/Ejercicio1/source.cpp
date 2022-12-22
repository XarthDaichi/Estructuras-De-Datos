#include <iostream>

unsigned int binario_a_decimal(unsigned int x) {
	if (x <= 1)
		return x;
	return binario_a_decimal(x % 10) + 2 * binario_a_decimal(x / 10);
}

int main() {
	unsigned int number;
	std::cin >> number;
	std::cout << binario_a_decimal(number);
	return 0;
}