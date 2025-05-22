/******
* Función que  permita leer un entero que pertenezca a un rango de enteros pasado 
como parámetros (límite inferior y límite superior) y retorne el entero leído 
sólo hasta que sea correcto
* Autor: Angel
*******/

#include <stdio.h>


int LeerEnteroEnRango(int limiteInferior, int limiteSuperior) {
    int valor;
    while (1) {
        valor = LeerEntero();  // Usamos la función que ya valida entero
        if (valor < limiteInferior || valor > limiteSuperior) {
            printf("Error: el numero debe estar entre %d y %d.\n", limiteInferior, limiteSuperior);
        } else {
            return valor;
                }
               }
}