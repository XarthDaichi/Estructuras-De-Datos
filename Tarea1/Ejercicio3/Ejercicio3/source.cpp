#include <iostream>

int division(int dividendo, int divisor) {
	if (dividendo == divisor)
		return 1;
	if (dividendo < divisor)
		return 0;
	return division(dividendo - divisor, divisor) + 1;
}

int main() {
	int number_1, number_2;
	std::cin >> number_1 >> number_2;
	std::cout << division(number_1, number_2);
	return 0;
}