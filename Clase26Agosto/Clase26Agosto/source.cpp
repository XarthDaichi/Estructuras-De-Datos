#include<iostream>

void cuenta(int x) {
	if (x < 1) {
		return;
	}
	cuenta(x - 1);
	std::cout << x << '\n';
}

int sumatoria(int x) {
	if (x <= 1)
		return x;
	return x + sumatoria(x - 1);
}

unsigned long long int factorial(unsigned long long int x) {
	if (x <= 1)
		return 1;
	return x * factorial(x - 1);
}

int main() {
	unsigned int number;
	std::cin >> number;
	/*cuenta(number);
	std::cout << "Sumatoria: " << sumatoria(number) << '\n';*/
	std::cout << "Factorial: " << factorial(number) << '\n';
	return 0;
}