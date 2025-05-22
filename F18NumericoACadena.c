/* *********
   Programa: F18NumericoACadena.c
   Autor:
   Fecha:
   Objetivo:
   Compilador: Dev-C++ 5.11
   Version 1.0
********* */

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>

// --- Prototipos de funciones ---
int LeerNumero();
char* ConvertirNumeroCadena(int);
void MostrarCadena(const char*);
void Conversion();

int main() {
    Conversion(); // Solo ejecuta todo el flujo
    return 0;
}

// --- Implementación de funciones ---

// Lee un número entero desde el teclado
int LeerNumero() {
    int eNumero;
    printf("Ingresa un n%cmero entero: ", 163);
    scanf("%d", &eNumero);
    return eNumero;
}

// Convierte un número entero a cadena de caracteres
char* ConvertirNumeroCadena(int eNumero) {
    char* cCadena = (char*)malloc(12 * sizeof(char)); // Para enteros de 32 bits
    if (cCadena != NULL) {
        sprintf(cCadena, "%d", eNumero);
    }
    return cCadena;
}

// Muestra una cadena por pantalla
void MostrarCadena(const char* cCadena) {
    printf("N%cmero como cadena: %s\n", 163, cCadena);
}

// Ejecuta todo el flujo de conversión
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

