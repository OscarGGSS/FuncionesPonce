/******
* Función que permita leer sólo enteros (positivos o negativos) y retorne el entero 
leído, sólo hasta que sea correcto. 
* Autor: Angel
*******/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* leerCadenaAlfabetica() {
    static char cadena[100];
    int valida, i;

    do {
        valida = 1;
        fgets(cadena, sizeof(cadena), stdin);

        // Eliminar salto de línea si lo hay
        cadena[strcspn(cadena, "\n")] = '\0';

        for (i = 0; cadena[i] != '\0'; i++) {
            if (!isalpha(cadena[i])) {
                valida = 0;
                printf("Error: la cadena solo debe contener letras.\n");
                break;
            }
        }
    } while (!valida);

    return cadena;
}

int main() {
     
    printf("Introduce una cadena solo con letras: ");
    char *resultado = leerCadenaAlfabetica();
    printf("Cadena válida: %s\n", resultado);
    return 0;
}
