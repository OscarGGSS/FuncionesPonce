/* *********
   Programa: F19CadenaANumerico.c
   Autor: Oscar
   Fecha:
   Objetivo:
   Compilador: Dev-C++ 5.11
   Version 1.0
********* */

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>

// --- Prototipos ---
char* leerCadena();
double convertirCadenaANumero(const char*);
void mostrarNumero(double);
void ejecutarConversion();

int main() {
    ejecutarConversion(); // Solo ejecuta el flujo
    return 0;
}

// --- Funciones ---

// Lee una cadena desde el teclado
char* leerCadena() {
    char* entrada = (char*)malloc(100 * sizeof(char)); // espacio para 99 caracteres + '\0'
    if (entrada != NULL) {
        printf("Ingresa un n%cmero (puede tener punto decimal): ", 163);
        scanf("%99s", entrada); // lee hasta 99 caracteres para evitar desbordamiento
    }
    return entrada;
}

// Convierte una cadena a número (double)
double convertirCadenaANumero(const char* cadena) {
    return strtod(cadena, NULL); // Convierte a double, ignora errores básicos
}

// Muestra el número convertido
void mostrarNumero(double fNumero) {
    printf("N%cmero convertido: %f\n", 163, fNumero);
}

// Función principal del flujo
void ejecutarConversion() {
    char* cadena = leerCadena();
    if (cadena != NULL) {
        double numero = convertirCadenaANumero(cadena);
        mostrarNumero(numero);
        free(cadena); // Liberamos memoria
    } else {
        printf("Error al leer la cadena.\n");
    }
}

