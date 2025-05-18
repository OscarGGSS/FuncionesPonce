/* ******
* Función que permita leer cadenas sólo de 15 caracteres cualesquiera (números o letras, no más ni menos de 15) y retorne la cadena leída sólo hasta que sea correcta.
* Autor: Zuri
****** */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* ValidarCadena15() {

    static char sCadena[20];
    int eLongitudCadena, eContador, eCadenaValida;

    while (1) {

        printf("Ingrese una cadena de 15 caracteres: ");
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

//Probar [Borrar]
int main() {
    char* cadenaValida;

    cadenaValida = ValidarCadena15();

    printf("Cadena válida ingresada: %s\n", cadenaValida);

    getchar();
    return 0;
}
