//Todas por si las moscas
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include "interfaz.h"
#include "Funciones.h"

int main(){

    //Variables
    char* cadenaValida;
    float numero;
    char caracter;
    char valido;

    //F03
    printf("¿Desea continuar?\n");
    
    if (LeerSN()) {
        printf("Elegiste S: Continuar\n");
    } else {
        printf("Elegiste N: Salir\n");
    }

    /*
    //F04
    cadenaValida = ValidarCadena15();

    printf("Cadena válida ingresada: %s\n", cadenaValida);
    
    //F07
    numero = LeerFlotanteEnRango(-9.0, 10.0);
    printf("Número ingresado correctamente: %.2f\n", numero);
    
    //F08
    caracter = LeerCaracterEnRango('a', 'z');
    printf("Carácter válido ingresado: %c\n", caracter);
    
    //F10
    valido = LeerCaracterValido("ABCS");
    printf("Carácter aceptado: %c\n", valido);
*/
    getchar();
    return 0;
}
