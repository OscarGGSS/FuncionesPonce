/* *********
   Programa: F12LeerFechaValida.c
   Autor: Ricardo
   Fecha: 20/05/2025
   Objetivo: Función que permita leer una fecha correctamente (dd/mm/aaaa) y la retorne sólo
   hasta que sea correcta (debe validar que al menos el día y el mes sean
   correctos) (reutilizar la función 6).
   Compilador: Dev-C++ 5.11
   Version 1.0
********* */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool esFechaValida(int eDia, int eMes, int eAnio) {
    // Validar mes
    if (eMes < 1 || eMes > 12) return false;

    // Validar días según el mes
    int eDiasPorMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Ajustar para años bisiestos
    if (eMes == 2) {
        if ((eAnio % 4 == 0 && eAnio % 100 != 0) || (eAnio % 400 == 0)) {
            eDiasPorMes[2] = 29;
        }
    }

    return eDia > 0 && eDia <= eDiasPorMes[eMes];
}

int leerEnteroEnRango(int eLimiteInferior, int eLimiteSuperior) {
    int eValor;
    while (1) {
        printf("Ingrese un número entre %d y %d: ", eLimiteInferior, eLimiteSuperior);
        scanf("%d", &eValor);
        if (eValor < eLimiteInferior || eValor > eLimiteSuperior) {
            printf("Error: el número debe estar entre %d y %d.\n", eLimiteInferior, eLimiteSuperior);
        } else {
            return eValor;
        }
    }
}

char* leerFecha() {
    static char cFecha[11]; // Formato "dd/mm/aaaa" + '\0'
    int dia, mes, anio;

    while (true) {
        printf("Ingrese la fecha (dd/mm/aaaa): ");
        scanf("%10s", cFecha); // Leer hasta 10 caracteres

        // Extraer día, mes y año
        sscanf(cFecha, "%d/%d/%d", &eDia, &eMes, &eAnio);

        // Validar el día y mes usando la función leerEnteroEnRango
        if (esFechaValida(eDia, eMes, eAnio)) {
            return cFecha; // Retornar la fecha válida
        } else {
            printf("Fecha inválida. Intente nuevamente.\n");
        }
    }
}

int main() {
    char* cFecha = leerFecha();
    printf("Fecha ingresada: %s\n", cFecha);
    return 0;
}
