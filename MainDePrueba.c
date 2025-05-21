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
    system("cls");
    printf("¿Desea continuar?\n");
    
    if (LeerSN()) {
        printf("Elegiste S: Continuar\n");
    } else {
        printf("Elegiste N: Salir\n");
    }
    system("pause");

    while (getchar() != '\n'); //Para limpiar el buffer, no sé me lo dió internet

    //F04
    system("cls");
    
    cadenaValida = ValidarCadena15();
    printf("Cadena válida ingresada: %s\n", cadenaValida);
    system("pause");

    //F07
    system("cls");
    numero = LeerFlotanteEnRango(-9.0, 10.0);
    printf("Número ingresado correctamente: %.2f\n", numero);
    system("pause");

    //F08
    system("cls");
    caracter = LeerCaracterEnRango('a', 'z');
    printf("Carácter válido ingresado: %c\n", caracter);
    system("pause");

    //F10
    system("cls");
    valido = LeerCaracterValido("ABCS");
    printf("Carácter aceptado: %c\n", valido);
    system("pause");

    return 0;
}