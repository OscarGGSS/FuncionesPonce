/* *********
   Programa: F17BorrarArea.c
   Autor: Ricardo
   Fecha: 19/05/2025
   Objetivo: 
   Compilador: Dev-C++ 5.11
   Version 1.0
********* */


#include <stdio.h>
#include <stdlib.h>

void borrarArea(int x1, int y1, int x2, int y2) {
    // Validar que las coordenadas sean correctas
    if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0 || x1 > x2 || y1 > y2) {
        printf("Coordenadas inválidas.\n");
        return;
    }

    // Mover el cursor a la posición (x1, y1)
    printf("\033[%d;%dH", y1, x1); 

    // Borrar el área especificada
    for (int i = y1; i <= y2; i++) {
        printf("\033[%d;%dH", i, x1); // Mover el cursor a la fila i, columna x1
        for (int j = x1; j <= x2; j++) {
            printf(" "); // Imprimir espacios para borrar
        }
    }

    // Regresar el cursor a la posición original
    printf("\033[%d;%dH", y1, x1);
}

int main() {
    // Ejemplo de uso de la función
    printf("Este es un texto que será borrado.\n");
    printf("Presione Enter para borrar el área.\n");
    getchar(); 

    // Borrar un área de 10x5 comenzando en (5, 2)
    borrarArea(5, 2, 15, 6);

    printf("Área borrada. Presione Enter para salir.\n");
    getchar(); // Esperar a que el usuario presione Enter
    return 0;
}
