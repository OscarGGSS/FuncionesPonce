/******
* Función  Que genere un número entero aleatorio entre 0 y un valor especificado 
como parámetro y retorne el número generado sólo hasta que sea correcto .

* Autor: Angel
*******/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int GenerarNumeroAleatorio(int limiteSuperior) {
    int numero;

    do {
        numero = rand() % (limiteSuperior + 1); // entre 0 y limiteSuperior
    } while (numero != LeerEnteroEnRango(0, limiteSuperior)); // Confirmación del usuario

    return numero;
}