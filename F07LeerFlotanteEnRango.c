/* ******
* Función que permita leer un número flotante que pertenezca a un rango de valores flotantes pasado como parámetros 
  (límite inferior y límite superior) y retorne el número leído sólo hasta que sea correcto.

* Autor: Zuri
****** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/* ******
* La función "VerificarFlotante" no fue pedida en la tarea. Sin embargo, me pareció conveniente separar la validación 
  (para saber si es float) de la verificación del rango (como se hace en la función 6 con el rango de enteros).
****** */
int VerificarFlotante(char *sCadena) {

    int ePuntoEncontrado = 0;
    int eContador = 0;

    if (sCadena[0] == '-') {
        eContador++;
    }

    while (sCadena[eContador] != '\0') {

        if (sCadena[eContador] == '.') {

            if (ePuntoEncontrado) {

                printf("Error.  El valor no es v%clido\n", 160);
                return 0;
            
            }

            ePuntoEncontrado = 1;
       
        } else if (!isdigit(sCadena[eContador])) {

            printf("Error. El valor no es v%clido\n", 160);
            return 0;

        }

        eContador++;
    }

    if (!ePuntoEncontrado) {
		
        printf("Error. El valor no es v%clido [Entero]\n", 160);
        return 0;
    }

    return 1;
}


float LeerFlotanteEnRango(float fLimiteInferior, float fLimiteSuperior){
	
    float fNumeroValidar;
    char sEntrada[20];

    while (1) {

        printf("Ingrese un n%cmero flotante entre ‘%.4f’ y ‘%.4f’: ", 163, fLimiteInferior, fLimiteSuperior);
        scanf("%s", sEntrada);

        if (VerificarFlotante(sEntrada)) {

            fNumeroValidar = atof(sEntrada);

            if (fNumeroValidar < fLimiteInferior || fNumeroValidar > fLimiteSuperior) {

                printf("Error. El n%cmero no est%c en el rango.\n", 163, 160);

            } else {

                return fNumeroValidar;
                
            }
         }
    }
}

int main() {
    float numero = LeerFlotanteEnRango(-9.0, 10.0);
    printf("Número ingresado correctamente: %.2f\n", numero);
    return 0;
}