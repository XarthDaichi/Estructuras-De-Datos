#include <iostream>
#include <string>

std::string invertir_string(std::string s) {
	if (s.length() <= 1)
		return s;
	return s[s.length()-1] + invertir_string(s.substr(0,s.length()-1)); // s[-1] + s[0:-1]
}

int main() {
	std::string word;
	std::cin >> word;
	std::cout << invertir_string(word);
	return 0;
}