#include <iostream>

int main() {
    /*
    int v[10];    // memoria stack, 40 bytes (4 c/u, asumiendo arquitectura 32 bits)
    int* ptr;     // memoria stack 4 bytes
    char* ptr2;   // memoria stack 4 bytes
    double* ptr3; // memoria stack 4 bytes
    // punteros pesan lo mismo en la memoria aunque tengan un tipo diferente
    */
   
    int v[10] = {77};
    int* ptr = &v[3];

    return 0;
}