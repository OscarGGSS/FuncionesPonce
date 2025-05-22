/* ******
* Función que permita leer sólo enteros (positivos o negativos) y retorne el entero 
leído, sólo hasta que sea correcto. 
* Autor: Angel
****** */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int LeerEntero()
{
    char sEntero[10];
    int eEntero, longitud, e = 0, eEsEntero;
    
    while (1)
    {
        printf("Introduce un numero entero: ");
        fgets(sEntero, sizeof(sEntero), stdin);
        
        sEntero[strcspn(sEntero, "\n")] = '\0';  

        longitud = strlen(sEntero);
        
        if (sEntero[0] == '-' || sEntero[0] == '+')
        {
            e = 1;
        }
        else
        {
            e = 0;
        }
        eEsEntero = 1;
        while (e < longitud)
        {
            if (!(isdigit(sEntero[e])))
            {
                eEsEntero = 0;
                e = longitud;
            }           
            e++;
        }
        if (eEsEntero == 1)
        {
            eEntero = atoi(sEntero);
            return eEntero;
        }
        else{
            printf("Error, introduce un numero entero: ");
        }
        
        
        
    }
}
int main() {
    int numero = LeerEntero();
    printf("Número ingresado correctamente: %d\n", numero);
    return 0;
}