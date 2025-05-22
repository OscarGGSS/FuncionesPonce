/* *********
   Programa: F18NumericoACadena.c
   Autor: Oscar
   Fecha:
   Objetivo:
   Compilador: Dev-C++ 5.11
   Version 1.0
********* */

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>

// Prototipos 
int LeerNumero();
char* ConvertirNumeroCadena(int);
void MostrarCadena(const char*);
void Conversion();

//Programa principal

int main() {
    Conversion(); 
    return 0;
}

int LeerNumero() {
    int eNumero;
    printf("Ingresa un n%cmero entero: ", 163);
    scanf("%d", &eNumero);
    return eNumero;
}


char* ConvertirNumeroCadena(int eNumero) {
    char* cCadena = (char*)malloc(12 * sizeof(char)); 
    if (cCadena != NULL) {
        sprintf(cCadena, "%d", eNumero);
    }
    return cCadena;
}


void MostrarCadena(const char* cCadena) {
    printf("N%cmero como cadena: %s\n", 163, cCadena);
}


void Conversion() {
    int eNumero = LeerNumero();
    char* cCadena = ConvertirNumeroCadena(eNumero);

    if (cCadena != NULL) {
        MostrarCadena(cCadena);
        free(cCadena); // Liberamos la memoria
    } else {
        printf("Error al convertir el número.\n");
    }
}

