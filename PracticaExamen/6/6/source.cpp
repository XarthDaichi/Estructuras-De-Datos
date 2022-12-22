#include <iostream>
#include <sstream>
#include <string>

std::string merge(std::string merging1, std::string merging2) {
	std::string merged;
	int i, j;
	for (i = 0, j = 0; i < merging1.length() && j < merging1.length(); i++, j++) {
		if (merging1[i] < merging2[j]) {
			merged += merging1[i];
			j--;
		}
		else {
			merged += merging2[j];
			i--;
		}
	}
	while (i < merging1.length()) merged += merging1[i++];
	while (j < merging2.length()) merged += merging2[j++];
	return merged;
}

std::string merge_sort(std::string section) {
	if (section.length() == 1) {
		return section;
	}
	std::string left = merge_sort(section.substr(0, section.length() / 2));
	std::string right = merge_sort(section.substr(section.length() / 2, section.length() - 1));
	section = merge(left, right);
	return section;
}

int main() {
	std::cout << merge_sort("estructuras de datos");
	return 0;
}