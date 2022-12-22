#include <iostream>
#include <cmath>

unsigned int decimal_invertido(unsigned int x) {
	if (x < 10) 
		return x;
	return  pow(10, (int) log10(x)) * decimal_invertido(x % 10) + decimal_invertido(x / 10);
}

int main() {
	unsigned int number;
	std::cin >> number;
	std::cout << decimal_invertido(number);
	return 0;
}