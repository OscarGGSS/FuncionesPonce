//Alguien cambiele el nombre porfavor :c
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include "interfaz.h"

/* ******
* F16CodigoDeError
* 
* Autor: Oscar
****** */
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

/* ******
* F01
* 
* Autor:
****** */

/* ******
* F02
* 
* Autor: 
****** */

/* ******
* F03LeerSN
* Función que permita leer sólo S o N y retorne verdadero si fue S o falso si fue N sólo hasta que sea S o N.
* Autor: Zuri
****** */

int LeerSN() {

    char cOpcionSN;

    while (1) {

        Mensaje("Ingrese S o N: ", 18, 5);
        scanf(" %c", &cOpcionSN);

        cOpcionSN = toupper(cOpcionSN);

        if (cOpcionSN != 'S' && cOpcionSN != 'N') {

            MensajeError(3);

        } else if (cOpcionSN == 'S') {

            return 1;

        } else {

            return 0;

        }
    }
}

/* ******
* F04ValidarCadena
* Función que permita leer cadenas sólo de 15 caracteres cualesquiera (números o letras, no más ni menos de 15) y retorne la cadena leída sólo hasta que sea correcta.
* Autor: Zuri
****** */
char* ValidarCadena15() {

    static char sCadena[20];
    int eLongitudCadena, eContador, eCadenaValida;

    while (1) {

        Mensaje("Ingrese una cadena de 15 caracteres: ", 18, 5);
        gets(sCadena);

        eLongitudCadena = strlen(sCadena);

        if (eLongitudCadena > 15 || eLongitudCadena < 15) {

            MensajeError(4);
            
        } else {

            eCadenaValida = 1;
            eContador = 0;

            while(sCadena[eContador] != '\0') {

                if (!isalnum(sCadena[eContador])) {

                    eCadenaValida = 0;
                }

                eContador++;
            }

            if (!eCadenaValida) {

                MensajeError(10);

            } else {

                return sCadena;
            }
        }
    }
}

/* ******
* F05
* 
* Autor: 
****** */

/* ******
* F06
* 
* Autor: 
****** */

/* ******
* F07LeerFlotanteEnRango
* Función que permita leer un número flotante que pertenezca a un rango de valores flotantes pasado como parámetros 
  (límite inferior y límite superior) y retorne el número leído sólo hasta que sea correcto.
* Autor: Zuri
****** */

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

                MensajeError(11);
                return 0;
            
            }

            ePuntoEncontrado = 1;
       
        } else if (!isdigit(sCadena[eContador])) {

            MensajeError(11);
            return 0;

        }

        eContador++;
    }

    if (!ePuntoEncontrado) {
		
        MensajeError(11);
        return 0;
    }

    return 1;
}


float LeerFlotanteEnRango(float fLimiteInferior, float fLimiteSuperior){
	
    float fNumeroValidar;
    char sEntrada[50];
    char sTexto[80];

    while (1) {
        sprintf(sTexto, "Ingrese un n%cmero flotante entre %.4f y %.4f: ", 163, fLimiteInferior, fLimiteSuperior);
        Mensaje(sTexto, 18, 5);
        scanf("%s", sEntrada);

        if (VerificarFlotante(sEntrada)) {

            fNumeroValidar = atof(sEntrada);

            if (fNumeroValidar < fLimiteInferior || fNumeroValidar > fLimiteSuperior) {

                MensajeError(6);

            } else {

                return fNumeroValidar;
                
            }
         }
    }
}

/* ******
* F08LeerCaracterEnRango
* Función que permita leer un carácter que pertenezca a un rango de caracteres pasado como parámetros 
  (límite inferior y límite superior) y retorne el carácter leído sólo hasta que sea correcto.
* Autor: Zuri
****** */

char LeerCaracterEnRango(char cLimiteInferior, char cLimiteSuperior) {
    char cCaracterValidar;
    char sTexto[80];
	    
    while(1){

        sprintf(sTexto, "Ingrese un car%ccter entre '%c' y '%c': ", 160, cLimiteInferior, cLimiteSuperior);
        Mensaje(sTexto, 18, 5);
        scanf(" %c", &cCaracterValidar);

        if (cCaracterValidar < cLimiteInferior || cCaracterValidar > cLimiteSuperior) {

            MensajeError(8);

        } else {

            return cCaracterValidar ;
        }
	}
}

/* ******
* F10LeerCaracterValido
* Función que permita leer un carácter que pertenezca a un conjunto específico pasado como parámetro y 
  regrese el carácter leído sólo hasta que sea correcto. El parámetro puede ser una cadena para admitir 
  sólo alguna de las siguientes letras ABCS y si el usuario teclea B, ese será el carácter retornado, 
  pero si teclea M volverá a pedir el carácter hasta que sea A, B, C o S.
  * Autor: Zuri
****** */

//¿Se debe validar el carácter antes?
//¿Debe ser indiferente a mayusculas y minusculas (A == a)?

char LeerCaracterValido(const char *sConjuntoCaracteres) {

    char cCaracterValidar;
    char sTexto[80];
  
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