/* Utilizando una pila, escriba un programa que permita realizar la validación de paréntesis.
* El programa recibe una expresión de tipo string de la siguiente manera.
* 7-((X*((X+Y)/(J-3))+Y)/(4-2.5))
* 
* La expresión podría llevar espacios o no
* 
* Así, la salida del programa determinaría si los paréntesis se encuentran balanceados.
* En el ejemplo anterior, los paréntesis se encuentran balanceados - es decir, para cada paréntesis que abre '(' existe un paréntesis que cierra ')'.
*/
#include "Stack.h"
#include <string>
#include <sstream>

void enter_expression_to_stack(Stack& entering_stack, std::string expression) {
	std::stringstream s;
	for (int i = 0; i < expression.length(); i++) {
		if (expression[i] != '\n' || expression[i] != '\t' || expression[i] != ' ') {
			if (expression[i + 1] == '.') {
				s << expression[i] << expression[i + 1] << expression[i + 2];
				i += 2;
			}
			else
				s << expression[i];
			entering_stack.push(s.str());
			s.str("");
		}
	}
}

void print_stack(Stack& printing_stack) {
	std::string printing_expression = "";
	while (printing_stack.top_node()) {
		printing_expression = printing_stack.pop() + printing_expression;
	}
	std::cout << printing_expression << '\n';

	enter_expression_to_stack(printing_stack, printing_expression);
}

int main() {
	std::string expression = "7-((X*((X+Y)/(J-3))+Y)/(4-2.5))";
	Stack stack;

	enter_expression_to_stack(stack, expression);

	print_stack(stack);

	print_stack(stack);

	std::cout << stack.verify_parenthesis() << '\n';

	return 0;
}