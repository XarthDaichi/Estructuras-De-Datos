/* Dada una lista enlaada simple, escriba una funci�n que calcule el n-�simo nodo a partir del �ltimo nodo de esa lista.
* La funci�n recibe por par�metro la posici�n a calcular a partir del final y retorna un apuntador al nodo corespondiente.
* 
* Por ejemplo, tome como referencia la siguiente lista enlazada:
* 
* 8->17->22->7->2->13->
* 
* Si la posici�n que se recibe es 2, entonces la funci�n debe retornar un apuntador al 7. De igual manera, si se recibe por par�metro un 5, entonces se retorna un apuntador al nodo 8.
* Debe validar que la posic��n se encuentre en el rango de la lista.
* 
* El algoritmo que proporcione debe cumplir una complejidad algoritmica no mayor a O(n).
*/

#include <iostream>
#include "List.h"


int main() {
	List<int> list;

	list.insert(8);
	list.insert(17);
	list.insert(27);
	list.insert(7);
	list.insert(2);
	list.insert(13);


	return 0;
}