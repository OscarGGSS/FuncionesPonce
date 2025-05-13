/* ******
* Función que permita leer un carácter que pertenezca a un rango de caracteres pasado como parámetros 
  (límite inferior y límite superior) y retorne el carácter leído sólo hasta que sea correcto.
* Autor: Zuri
****** */

#include <stdio.h>

    char LeerCaracterEnRango(char cLimiteInferior, char cLimiteSuperior) {
    char cCaracterValidar;

    while(1){

        printf("Ingrese un car%ccter entre '%c' y '%c': ", 160, cLimiteInferior, cLimiteSuperior);
        scanf(" %c", &cCaracterValidar);

        if (cCaracterValidar < cLimiteInferior || cCaracterValidar > cLimiteSuperior) {

            printf("Error. Car%ccter fuera del rango.\n", 160, 160);

        } else {

            return cCaracterValidar ;
        }
	}
}

//Probar [Borrar]
int main() {
    char caracter = LeerCaracterEnRango('a', 'z');
    printf("Carácter válido ingresado: %c\n", caracter);
    return 0;
}