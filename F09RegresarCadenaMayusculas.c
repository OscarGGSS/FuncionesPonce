/******
* Función que permita leer cadenas sólo de caracteres alfabéticos, que los convierta 
en mayúsculas y retorne la cadena en mayúsculas sólo hasta que sea 
correcta
* Autor: Angel
*******/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* RegresarCadenaMayusculas() {
    char  *sCadena = LeerCadenaAlfabetica();
    int i;
    while (1) {
       for (int i = 0; sCadena[i] != '\0'; i++)
       {
              sCadena[i] = toupper(sCadena[i]);
       }
       return sCadena;

    }
}



int main() {
     
    printf("Introduce una cadena solo con letras: ");
    char *sResultado = RegresarCadenaMayusculas();
    printf("Cadena válida: %s\n", sResultado);
    return 0;
}
