/* *********
   Programa: F16CodigoDeError.c
   Autor: Oscar
   Fecha:
   Objetivo:
   Compilador: Dev-C++ 5.11
   Version 1.0
********* */

//Bibliotecas
#include <stdio.h>
#include <windows.h>
#include "interfaz.h"

//Prototipos

void MensajeError(int eCodigoError);

//Programa principal

int main(){
	
	int eError;  /* *****
				TODO ESTO DEL MAIN SOLO LO PUSE PARA SABER SI SI JALABA, AQUI DEBERIA IR LO DE SU FUNCION (SOLO COMO PRUEBA 
				PORQUE AL FINAL TODO IRA EN UNA BIBLIOTECA NO?),
			 	DEBERIAN METER COMO PARAMETRO EL NUMERO QUE CORRESPONDE SU FUNCION Y DEBERIA SERVIR, SI NO JALA ME DICEN PARA
				AVENTARME OTRO TIRO CON ESTA COSA JAJA
				**** */

    printf("Introduce el c%cdigo de error (1 a 11): ", 162);
    scanf("%d", &eError);

    MensajeError(eError); 



	getchar();
	return 0;
}

void MensajeError(int eCodigoError) {
    char cMensaje[100];

    switch (eCodigoError) {
        case 1:
            sprintf(cMensaje, "Error: Se necesita un entero.");
            break;
        case 2:
            sprintf(cMensaje, "Error: Solo se permiten letras.");
            break;
        case 3:
            sprintf(cMensaje, "Error: Solo se acepta 'S' o 'N'.");
            break;
        case 4:
            sprintf(cMensaje, "Error: La cadena debe tener exactamente 15 caracteres.");
            break;
        case 5:
            sprintf(cMensaje, "Error: Se necesita un entero positivo.");
            break;
        case 6:
            sprintf(cMensaje, "Error: El valor no est%c en el rango permitido.", 160);  
            break;
        case 7:
            sprintf(cMensaje, "Error: Flotante fuera del rango.");
            break;
        case 8:
            sprintf(cMensaje, "Error: Car%ccter fuera del rango.", 160); 
            break;
        case 9:
            sprintf(cMensaje, "Error: Solo se permiten letras para convertir a may%csculas.", 163); 
            break;
        case 10:
            sprintf(cMensaje, "Error: Car%ccter no v%clido en el conjunto permitido.", 160, 160); 
            break;
        case 11:
            sprintf(cMensaje, "Error: Formato inv%clido.", 160);
            break;
        default:
            sprintf(cMensaje, "Error desconocido.");
            break;
    }

    Mensaje((char *)cMensaje, 20, 5);  // Muestra el mensaje en la línea 20 (pa que no se me olvide q hace jaja)
    Beep(1000, 300);       // Sonido de error xd
}
