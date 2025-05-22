/* ******
* Función que permita leer un carácter que pertenezca a un conjunto específico pasado como parámetro y 
  regrese el carácter leído sólo hasta que sea correcto. El parámetro puede ser una cadena para admitir 
  sólo alguna de las siguientes letras ABCS y si el usuario teclea B, ese será el carácter retornado, 
  pero si teclea M volverá a pedir el carácter hasta que sea A, B, C o S.

  * Autor: Zuri
****** */

//¿Se debe validar el carácter antes?
//¿Debe ser indiferente a mayusculas y minusculas (A == a)?

#include <stdio.h>
#include <string.h>

char LeerCaracterValido(const char *sConjuntoCaracteres) {

    char cCaracterValidar;
    char sTexto[50];
  
    while (1) {
      
        sprintf(sTexto, "Ingrese un car%ccter (%s): ", 160, sConjuntoCaracteres);
        Mensaje(sTexto, 18, 5); 
        scanf(" %c", &cCaracterValidar);

        fflush(stdin);

        if (strchr(sConjuntoCaracteres, cCaracterValidar)) {
          
            return cCaracterValidar;
      
        } else {

            MensajeError(10);
      
        }
    }
}

//Probar [Borrar]
int main() {
    char valido = LeerCaracterValido("ABCS");
    printf("Carácter aceptado: %c\n", valido);
    return 0;
}
