/* *********
   Programa: F17BorrarArea.c
   Autor: Ricardo
   Fecha: 19/05/2025
   Objetivo: Función que borre un área de la pantalla especificando cuatro parámetros que
   indiquen la esquina superior izquierda y la esquina inferior derecha (4
   parámetros).
   Compilador: Dev-C++ 5.11
   Version 1.0
********* */


void borrarArea(int x1, int y1, int x2, int y2) {
    // Validar que las coordenadas sean correctas
    if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0 || x1 > x2 || y1 > y2) {
        printf("Coordenadas inválidas.\n");
        return;
    }

    // Mover la posición (x1, y1)
    printf("\033[%d;%dH", y1, x1); 

    // Borrar el área especificada
    for (int i = y1; i <= y2; i++) {
        printf("\033[%d;%dH", i, x1); 
        for (int j = x1; j <= x2; j++) {
            printf(" "); 
        }
    }


    printf("\033[%d;%dH", y1, x1);
}


    borrarArea(5, 2, 15, 6);

    printf("Área borrada. Presione Enter para salir.\n");
    getchar();
    return 0;
}
