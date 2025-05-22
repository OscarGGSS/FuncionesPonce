#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

//Prototipos
int LeerEntero(); //1
char* LeerCadenaAlfabetica(); //2
int LeerSN(); //3
char* ValidarCadena15(); //4
char* ValidarCadena(char*, int); //Extra
int LeerEnteroPositivo(); //5
int LeerEnteroEnRango(int, int); //6
float LeerFlotanteEnRango(float, float); //7
int VerificarFlotante(char *); //Extra
char LeerCaracterEnRango(char, char); //8
char* RegresarCadenaMayusculas(); //9
char LeerCaracterValido(const char *); //10
char* LeerCadenaConFormato(char *); //11
//12
void Linea(int, int);
void GoToXY(int, int);
//13
void Centrar(char *, int); //14
void Mensaje(char *, int, int); //15
void MensajeError(int); //16
//17
int LeerNumero();
char* ConvertirNumeroCadena(int);
void MostrarCadena(const char*);
void Conversion();//18

char* leerCadena();
double convertirCadenaANumero(const char*);
void mostrarNumero(double);
void ejecutarConversion(); //19
//20
void Marco(); //21
int GenerarNumeroAleatorio(int); //22 
void borrarArea(int, int, int, int); //17 - Faltaba declaración

/* ******
* F16CodigoDeError
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
            sprintf(cMensaje, "Error: El valor no está en el rango permitido.");  
            break;
        case 7:
            sprintf(cMensaje, "Error: Flotante fuera del rango.");
            break;
        case 8:
            sprintf(cMensaje, "Error: Carácter fuera del rango."); 
            break;
        case 9:
            sprintf(cMensaje, "Error: Solo se permiten letras para convertir a mayúsculas."); 
            break;
        case 10:
            sprintf(cMensaje, "Error: Carácter no válido en el conjunto permitido."); 
            break;
        case 11:
            sprintf(cMensaje, "Error: Formato inválido.");
            break;
        default:
            sprintf(cMensaje, "Error desconocido.");
            break;
    }

    GoToXY(20, 5);  // Posición para mostrar error
    printf("%s", cMensaje);
    printf("\nPresione cualquier tecla para continuar...");
    getch();  // Pausa para que el usuario vea el error
    system("cls");
    Marco();  // Redibuja el marco
}

/* ******
* F01LeerEntero
* Función que permita leer sólo enteros (positivos o negativos) y retorne el entero 
leído, sólo hasta que sea correcto. 
* Autor:Soriano Aguilar José Ángel
****** */
int LeerEntero() {
    char sEntero[20];
    int eEntero, longitud, e = 0, eEsEntero;
    
    while (1) {
        GoToXY(15, 5);
        printf("Introduce un numero entero: ");
        fflush(stdin);
        fgets(sEntero, sizeof(sEntero), stdin);
        
        sEntero[strcspn(sEntero, "\n")] = '\0';  

        longitud = strlen(sEntero);
        
        if (longitud == 0) {
            MensajeError(1);
            continue;
        }
        
        if (sEntero[0] == '-' || sEntero[0] == '+') {
            e = 1;
        } else {
            e = 0;
        }
        
        eEsEntero = 1;
        for (int i = e; i < longitud; i++) {
            if (!isdigit(sEntero[i])) {
                eEsEntero = 0;
                break;
            }           
        }
        
        if (eEsEntero == 1 && longitud > e) {
            eEntero = atoi(sEntero);
            return eEntero;
        } else {
            MensajeError(1);
        }
    }
}

/* ******
* F02LeerCadenaAlfabetica
* Función que permita leer cadenas sólo de caracteres alfabéticos y retorne la 
cadena leída sólo hasta que sea correcta. 
* Autor: Soriano Aguilar José Ángel
****** */
char* LeerCadenaAlfabetica() {
    static char sCadena[100];
    int eValido, i;

    do {
        eValido = 1;
        GoToXY(15, 5);
        printf("Introduce una cadena alfabética: ");
        fflush(stdin);
        fgets(sCadena, sizeof(sCadena), stdin);

        sCadena[strcspn(sCadena, "\n")] = '\0';

        if (strlen(sCadena) == 0) {
            MensajeError(2);
            eValido = 0;
            continue;
        }

        for (i = 0; sCadena[i] != '\0'; i++) {
            if (!isalpha(sCadena[i])) {
                eValido = 0;
                MensajeError(2);
                break;
            }
        }
    } while (!eValido);

    return sCadena;
}

/* ******
* Función 3: LeerSN
* Autor: Zurisadai González de Santiago
****** */
int LeerSN() {
    char cOpcionSN;

    while (1) {
        GoToXY(15, 5);
        printf("Ingrese S o N: ");
        fflush(stdin);
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
* Función 4: ValidarCadena15
* Autor: Zurisadai González de Santiago
****** */
char* ValidarCadena15() {
    static char sCadena[20];
    int eLongitudCadena, eContador, lCadenaValida;

    while (1) {
        GoToXY(15, 5);
        printf("Ingrese una cadena de 15 caracteres: ");
        fflush(stdin);
        fgets(sCadena, sizeof(sCadena), stdin);

        // Remover el salto de línea
        sCadena[strcspn(sCadena, "\n")] = '\0';
        eLongitudCadena = strlen(sCadena);

        if (eLongitudCadena != 15) {
            MensajeError(4);
        } else {
            lCadenaValida = 1;
            eContador = 0;

            while(sCadena[eContador] != '\0') {
                if (!isalnum(sCadena[eContador])) {
                    lCadenaValida = 0;
                    break;
                }
                eContador++;
            }

            if (!lCadenaValida) {
                MensajeError(10);
            } else {
                return sCadena;
            }
        }
    }
}

/* ******
* Función: ValidarCadena
* Autor: Zurisadai González de Santiago
****** */
char* ValidarCadena(char* sCadena, int eMaxLongitud) {
    int eLongitudCadena;
    int lCadenaValida = 0;
    
    while (lCadenaValida == 0) {
        GoToXY(15, 5);
        printf("Ingrese una cadena de %d caracteres: ", eMaxLongitud);
        fflush(stdin);
        fgets(sCadena, 100, stdin);

        sCadena[strcspn(sCadena, "\n")] = '\0';
        eLongitudCadena = strlen(sCadena);
        
        if (eLongitudCadena != eMaxLongitud) {
            MensajeError(4);
        } else {
            lCadenaValida = 1;
        }
    }

    return sCadena;
}

/* ******
* F05LeerEnteroPositivo
* Función que permita leer sólo enteros positivos y retorne el entero 
leído, sólo hasta que sea correcto. 
* Autor: Soriano Aguilar José Ángel
****** */
int LeerEnteroPositivo() {
    int eEntero;
    while (1) {
        eEntero = LeerEntero();
        if (eEntero >= 0) {
            return eEntero;
        } else {
            MensajeError(5);
        }
    }
}

/* ******
* F06LeerEnteroEnRango
* Función que  permita leer un entero que pertenezca a un rango de enteros pasado 
como parámetros (límite inferior y límite superior) y retorne el entero leído 
sólo hasta que sea correcto
* Autor: Soriano Aguilar José Ángel
****** */
int LeerEnteroEnRango(int eLimiteInferior, int eLimiteSuperior) {
    int eValor;
    while (1) {
        eValor = LeerEntero();  
        if (eValor < eLimiteInferior || eValor > eLimiteSuperior) {
            MensajeError(6);
        } else {
            return eValor;
        }
    }
}

/* ******
* Función: VerificarFlotante
* Autor: Zurisadai González de Santiago
****** */
int VerificarFlotante(char *sCadena) {
    int ePuntoEncontrado = 0;
    int eContador = 0;

    if (strlen(sCadena) == 0) {
        return 0;
    }

    if (sCadena[0] == '-' || sCadena[0] == '+') {
        eContador++;
    }

    while (sCadena[eContador] != '\0') {
        if (sCadena[eContador] == '.') {
            if (ePuntoEncontrado) {
                return 0;
            }
            ePuntoEncontrado = 1;
        } else if (!isdigit(sCadena[eContador])) {
            return 0;
        }
        eContador++;
    }

    return ePuntoEncontrado; // Debe tener al menos un punto decimal
}

/* ******
* Función 7: LeerFlotanteEnRango
* Autor: Zurisadai González de Santiago
****** */
float LeerFlotanteEnRango(float fLimiteInferior, float fLimiteSuperior) {
    float fNumeroValidar;
    char sEntrada[50];

    while (1) {
        GoToXY(15, 5);
        printf("Ingrese un número flotante entre %.2f y %.2f: ", fLimiteInferior, fLimiteSuperior);
        fflush(stdin);
        fgets(sEntrada, sizeof(sEntrada), stdin);
        
        sEntrada[strcspn(sEntrada, "\n")] = '\0';

        if (VerificarFlotante(sEntrada)) {
            fNumeroValidar = atof(sEntrada);

            if (fNumeroValidar < fLimiteInferior || fNumeroValidar > fLimiteSuperior) {
                MensajeError(6);
            } else {
                return fNumeroValidar;
            }
        } else {
            MensajeError(11);
        }
    }
}

/* ******
* Función 8: LeerCaracterEnRango
* Autor: Zurisadai González de Santiago
****** */
char LeerCaracterEnRango(char cLimiteInferior, char cLimiteSuperior) {
    char cCaracterValidar;
    
    while(1) {
        GoToXY(15, 5);
        printf("Ingrese un carácter entre '%c' y '%c': ", cLimiteInferior, cLimiteSuperior);
        fflush(stdin);
        scanf(" %c", &cCaracterValidar);

        if (cCaracterValidar < cLimiteInferior || cCaracterValidar > cLimiteSuperior) {
            MensajeError(8);
        } else {
            return cCaracterValidar;
        }
    }
}

/* ******
* Función 9: RegresarCadenaMayusculas
* Función que permita leer cadenas sólo de caracteres alfabéticos, que los convierta 
en mayúsculas y retorne la cadena en mayúsculas sólo hasta que sea 
correcta
* Autor: Soriano Aguilar José Ángel
****** */
char* RegresarCadenaMayusculas() {
    char *sCadena = LeerCadenaAlfabetica();
    
    for (int i = 0; sCadena[i] != '\0'; i++) {
        sCadena[i] = toupper(sCadena[i]);
    }
    
    return sCadena;
}

/* ******
* Función 10: LeerCaracterValido
* Autor: Zurisadai González de Santiago
****** */
char LeerCaracterValido(const char *sConjuntoCaracteres) {
    char cCaracterValidar;
  
    while (1) {
        GoToXY(15, 5);
        printf("Ingrese un carácter (%s): ", sConjuntoCaracteres);
        fflush(stdin);
        scanf(" %c", &cCaracterValidar);

        if (strchr(sConjuntoCaracteres, cCaracterValidar)) {
            return cCaracterValidar;
        } else {
            MensajeError(10);
        }
    }
}

/* ******
* Función 11: LeerCadenaConFormato
* Autor: Zurisadai González de Santiago
****** */ 
char *LeerCadenaConFormato(char *sFormato) {
    static char sCadena[100];
    int eLongitud;
    int eContador;
    int lCadenaValida; 
    
    // Remover salto de línea del formato si existe
    sFormato[strcspn(sFormato, "\n")] = '\0';
    eLongitud = strlen(sFormato);

    while (1) {
        ValidarCadena(sCadena, eLongitud);

        lCadenaValida = 1;

        for (eContador = 0; eContador < eLongitud; eContador++) {
            char c = sCadena[eContador];
            char tipo = sFormato[eContador];

            if (tipo == 'A' && !isalpha(c)) {
                lCadenaValida = 0;
                break;
            } else if (tipo == '9' && !isdigit(c)) {
                lCadenaValida = 0;
                break;
            } else if (tipo == 'X' && !isalnum(c)) {
                lCadenaValida = 0;
                break;
            }
        }

        if (lCadenaValida) {
            return sCadena;
        } else {
            MensajeError(11);
        }
    }
}

//12
/* ******
* Función: Linea
****** */ 
void Linea(int eColIni, int eColFin) {
    int eCol;
    for(eCol = eColIni; eCol <= eColFin; eCol++) {
        printf("%c", 196);
    }
}

/* ******
* Función: GoToXY
****** */
void GoToXY(int eRen, int eCol) {
    COORD coordenada;
    HANDLE salida = GetStdHandle(STD_OUTPUT_HANDLE);
    
    coordenada.X = eCol;
    coordenada.Y = eRen;
    
    SetConsoleCursorPosition(salida, coordenada);
}

//13
/* ******
* Función 15: Mensaje
****** */ 
void Mensaje(char *sTexto, int eColumna, int eRenglon) {  // Corregí el orden de parámetros
    GoToXY(eRenglon, eColumna);
    printf("%s", sTexto);
}

/* ******
* Función 14: Centrar
****** */ 
void Centrar(char *sCadena, int eRenglon) {
    Mensaje(sCadena, (80 - strlen(sCadena)) / 2, eRenglon);  // Ajusté a 80 columnas
}

/* ******
* Función 17: BorrarArea
* Autor: Ricardo
****** */
void borrarArea(int x1, int y1, int x2, int y2) {
    if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0 || x1 > x2 || y1 > y2) {
        return;
    }

    for (int i = y1; i <= y2; i++) {
        GoToXY(i, x1);
        for (int j = x1; j <= x2; j++) {
            printf(" ");
        }
    }
}

/* ******
* Función 18: Conversión Número a Cadena
* Autor: Oscar
****** */
int LeerNumero() {
    return LeerEntero();  // Reutiliza la función existente
}

char* ConvertirNumeroCadena(int eNumero) {
    char* cCadena = (char*)malloc(20 * sizeof(char)); 
    if (cCadena != NULL) {
        sprintf(cCadena, "%d", eNumero);
    }
    return cCadena;
}

void MostrarCadena(const char* cCadena) {
    GoToXY(17, 5);
    printf("Número como cadena: %s", cCadena);
}

void Conversion() {
    int eNumero = LeerNumero();
    char* cCadena = ConvertirNumeroCadena(eNumero);

    if (cCadena != NULL) {
        MostrarCadena(cCadena);
        free(cCadena);
    } else {
        GoToXY(17, 5);
        printf("Error al convertir el número.");
    }
}

/* ******
* Función 19: Conversión Cadena a Número
* Autor: Oscar
****** */
char* leerCadena() {
    char* entrada = (char*)malloc(100 * sizeof(char)); 
    if (entrada != NULL) {
        GoToXY(15, 5);
        printf("Ingresa un número (puede tener punto decimal): ");
        fflush(stdin);
        fgets(entrada, 100, stdin);
        entrada[strcspn(entrada, "\n")] = '\0';  // Remover salto de línea
    }
    return entrada;
}

double convertirCadenaANumero(const char* cadena) {
    return strtod(cadena, NULL); 
}

void mostrarNumero(double fNumero) {
    GoToXY(17, 5);
    printf("Número convertido: %f", fNumero);
}

void ejecutarConversion() {
    char* cadena = leerCadena();
    if (cadena != NULL) {
        double numero = convertirCadenaANumero(cadena);
        mostrarNumero(numero);
        free(cadena); 
    } else {
        GoToXY(17, 5);
        printf("Error al leer la cadena.");
    }
}

/* ******
* Función 21: Marco
****** */ 
void Marco() {
    int eRen;
    
    system("color 3F");
    system("cls");
    
    // Esquina superior izquierda
    GoToXY(0, 0);
    printf("%c", 218);
    
    // Línea superior
    Linea(1, 78);
    printf("%c", 191);
    
    // Líneas laterales
    for(eRen = 1; eRen <= 23; eRen++) {
        GoToXY(eRen, 0);
        printf("%c", 179);
        
        GoToXY(eRen, 79);
        printf("%c", 179);
    }
    
    // Esquina inferior izquierda
    GoToXY(24, 0);
    printf("%c", 192);
    
    // Línea inferior
    Linea(1, 78);
    printf("%c", 217);
}

/* ******
* Función 22: GenerarNumeroAleatorio
* Función que genere un número entero aleatorio entre 0 y un valor especificado 
como parámetro y retorne el número generado.
* Autor: Soriano Aguilar José Ángel
****** */
int GenerarNumeroAleatorio(int eLimiteSuperior) {
    srand(time(NULL));  // Inicializar semilla aleatoria
    return rand() % (eLimiteSuperior + 1);
}

#endif // FUNCIONES_H