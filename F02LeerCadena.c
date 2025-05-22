/******
* Función que permita leer cadenas sólo de caracteres alfabéticos y retorne la 
cadena leída sólo hasta que sea correcta. 
* Autor: Angel
*******/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* LeerCadenaAlfabetica() {
    static char sCadena[50];
    int eValido, i;

    do {
        eValido = 1;
        fgets(sCadena, sizeof(sCadena), stdin);

        sCadena[strcspn(sCadena, "\n")] = '\0';

        for (i = 0; sCadena[i] != '\0'; i++) {
            if (!isalpha(sCadena[i])) {
                eValido = 0;
                printf("Error: la cadena solo debe contener letras.\n");
                break;
            }
        }
    } while (!eValido);

    return sCadena;
}

int main() {
     
    printf("Introduce una cadena solo con letras: ");
    char *resultado = leerCadenaAlfabetica();
    printf("Cadena válida: %s\n", resultado);
    return 0;
}
