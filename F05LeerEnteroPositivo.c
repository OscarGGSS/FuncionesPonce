/* ******
* Función que permita leer sólo enteros (positivos o negativos) y retorne el entero 
leído, sólo hasta que sea correcto. 
* Autor: Angel
****** */

#include <stdio.h>
int LeerEnteroPositivo()
{
    int eEntero;
    while (1)
    {
        eEntero = LeerEntero();
        if (eEntero >= 0)
        {
            return eEntero;
        }
        else
        {
            printf("Error, introduce un numero entero positivo: ");
        }
    }
}