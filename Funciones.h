//podemos quitar de aqui las bibliotecas???
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

//Prototipos
//1
//2
int LeerSN(); //3
char* ValidarCadena15(); //4
char* ValidarCadena(char*, int); //Extra
//5
//6
float LeerFlotanteEnRango(float, float); //7
int VerificarFlotante(char *); //Extra
char LeerCaracterEnRango(char, char); //8
//9
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
void ejecutarConversion();

char* leerCadena();
double convertirCadenaANumero(const char*);
void mostrarNumero(double);
void ejecutarConversion(); //19
//20
void Marco(); //21
//22

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

    Mensaje((char *)cMensaje, 5, 20);  // Muestra el mensaje en la línea 20 (pa que no se me olvide q hace jaja)
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
* Función 3: LeerSN
* Autor: Zurisadai González de Santiago
****** */

int LeerSN() {

    //Variables
    char cOpcionSN;

    while (1) {

        Mensaje("Ingrese S o N: ", 15, 8);
        GoToXY(8, 30);
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
    
    //Variables
    static char sCadena[20];
    int eLongitudCadena, eContador, lCadenaValida;

    while (1) {

        Mensaje("Ingrese una cadena de 15 caracteres: ", 15, 8);
        GoToXY(8, 52);
        gets(sCadena);

        eLongitudCadena = strlen(sCadena);

        if (eLongitudCadena > 15 || eLongitudCadena < 15) {

            MensajeError(4);
            
        } else {

            lCadenaValida = 1;
            eContador = 0;

            while(sCadena[eContador] != '\0') {

                if (!isalnum(sCadena[eContador])) {

                    lCadenaValida = 0;
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
    char sMensaje[50];
    
    sprintf(sMensaje, "Ingrese una cadena de %d caracteres: ", eMaxLongitud);
    
    while (lCadenaValida == 0) {
        
        Mensaje(sMensaje, 15, 8);
        GoToXY(8, 52);
        gets(sCadena);

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
* Función: VerificarFlotante
* Autor: Zurisadai González de Santiago
****** */

int VerificarFlotante(char *sCadena) {

    //Variables
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

/* ******
* Función 7: LeerFlotanteEnRango
* Autor: Zurisadai González de Santiago
****** */

float LeerFlotanteEnRango(float fLimiteInferior, float fLimiteSuperior){

	//Variables
    float fNumeroValidar;
    char sEntrada[50];
    char sTexto[80];

    while (1) {
        sprintf(sTexto, "Ingrese un n%cmero flotante entre %.4f y %.4f: ", 163, fLimiteInferior, fLimiteSuperior);
        Mensaje(sTexto, 15, 8);
        GoToXY(8, 67);
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
* Función 8: LeerCaracterEnRango
* Autor: Zurisadai González de Santiago
****** */

char LeerCaracterEnRango(char cLimiteInferior, char cLimiteSuperior) {
    
    //Variables
    char cCaracterValidar;
    char sTexto[80];
	    
    while(1){

        sprintf(sTexto, "Ingrese un car%ccter entre '%c' y '%c': ", 160, cLimiteInferior, cLimiteSuperior);
        Mensaje(sTexto, 15, 8);
        GoToXY(8, 52);
        scanf(" %c", &cCaracterValidar);

        if (cCaracterValidar < cLimiteInferior || cCaracterValidar > cLimiteSuperior) {

            MensajeError(8);

        } else {

            return cCaracterValidar ;
        }
	}
}

/* ******
* Función 10: LeerCaracterValido
* Autor: Zurisadai González de Santiago
****** */

char LeerCaracterValido(const char *sConjuntoCaracteres) {
    
    //Variables
    char cCaracterValidar;
    char sTexto[80];
  
    while (1) {
      
        sprintf(sTexto, "Ingrese un car%ccter (%s): ", 160, sConjuntoCaracteres);
        Mensaje(sTexto, 15, 8); 
        GoToXY(8, 43);
        scanf(" %c", &cCaracterValidar);

        fflush(stdin);

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

    //Variables
    static char sCadena[100];
    int eLongitud;
    int eContador;
    int lCadenaValida; 
    
    eLongitud = strlen(sFormato);

    while (1) {
        ValidarCadena(sCadena, eLongitud);

        lCadenaValida = 1;

        for (eContador = 0; eContador < eLongitud; eContador++) {
            char c = sCadena[eContador];
            char tipo = sFormato[eContador];

            if (tipo == 'A' && !isalpha(c)) {
                lCadenaValida = 0;
            } else if (tipo == '9' && !isdigit(c)) {
                lCadenaValida = 0;
            } else if (tipo == 'X' && !isalnum(c)) {
                lCadenaValida = 0;
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
void Linea(int eColIni, int eColFin){
	int eCol;
	for(eCol = eColIni; eCol <= eColFin; eCol++){
		printf("%c",196);
 	}
}

/* ******
* Función: GoToXY
****** */
void GoToXY(int eRen, int eCol){
	
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

void Mensaje(char *sTexto, int eRenglon, int eColumna){
	
	GoToXY( eColumna, eRenglon );
	printf("%s", sTexto);
}

/* ******
* Función 14: Centrar
 ****** */ 

void Centrar(char *sCadena , int eRenglon){
	
	Mensaje(sCadena , (100 - strlen(sCadena)) / 2, eRenglon);
	
}

/* *********
   Programa: F17BorrarArea.c
   Autor: Ricardo
   Fecha: 19/05/2025
   Objetivo: 
   Compilador: Dev-C++ 5.11
   Version 1.0
********* */


void borrarArea(int x1, int y1, int x2, int y2) {
    // Validar que las coordenadas sean correctas
    if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0 || x1 > x2 || y1 > y2) {
        printf("Coordenadas inválidas.\n");
        return;
    }

    // Mover el cursor a la posición (x1, y1)
    printf("\033[%d;%dH", y1, x1); 

    // Borrar el área especificada
    for (int i = y1; i <= y2; i++) {
        printf("\033[%d;%dH", i, x1); // Mover el cursor a la fila i, columna x1
        for (int j = x1; j <= x2; j++) {
            printf(" "); // Imprimir espacios para borrar
        }
    }

    // Regresar el cursor a la posición original
    printf("\033[%d;%dH", y1, x1);
}



/* *********
   Programa: F18NumericoACadena.c
   Autor: Oscar
   Fecha:
   Objetivo:
   Compilador: Dev-C++ 5.11
   Version 1.0
********* */

int LeerNumero() {
    int eNumero;
    printf("Ingresa un n%cmero entero: ", 163);
    scanf("%d", &eNumero);
    return eNumero;
}


char* ConvertirNumeroCadena(int eNumero) {
    char* cCadena = (char*)malloc(12 * sizeof(char)); 
    if (cCadena != NULL) {
        sprintf(cCadena, "%d", eNumero);
    }
    return cCadena;
}


void MostrarCadena(const char* cCadena) {
    printf("N%cmero como cadena: %s\n", 163, cCadena);
}


void Conversion() {
    int eNumero = LeerNumero();
    char* cCadena = ConvertirNumeroCadena(eNumero);

    if (cCadena != NULL) {
        MostrarCadena(cCadena);
        free(cCadena); // Liberamos la memoria
    } else {
        printf("Error al convertir el número.\n");
    }
}


/* *********
   Programa: F19CadenaANumerico.c
   Autor: Oscar
   Fecha:
   Objetivo:
   Compilador: Dev-C++ 5.11
   Version 1.0
********* */

char* leerCadena() {
    char* entrada = (char*)malloc(100 * sizeof(char)); 
    if (entrada != NULL) {
        printf("Ingresa un n%cmero (puede tener punto decimal): ", 163);
        scanf("%99s", entrada); 
    }
    return entrada;
}


double convertirCadenaANumero(const char* cadena) {
    return strtod(cadena, NULL); 
}

void mostrarNumero(double fNumero) {
    printf("N%cmero convertido: %f\n", 163, fNumero);
}

void ejecutarConversion() {
    char* cadena = leerCadena();
    if (cadena != NULL) {
        double numero = convertirCadenaANumero(cadena);
        mostrarNumero(numero);
        free(cadena); 
    } else {
        printf("Error al leer la cadena.\n");
    }
}

/* ******
* Función 21: Marco
 ****** */ 

void Marco(){
	
	int eRen, eCol;
	
	system("color 3F");
	system("cls");
	
	printf("%c",218);
	
	Linea(2,115);
	printf("%c\n",191);
	for(eRen= 1; eRen <= 25; eRen++){
		
		GoToXY(eRen, 0);
		printf("%c",179);
		
		GoToXY(eRen, 115);
		printf("%c \n",179);
	}
	printf("%c",192);
	Linea (2,115);
 	printf("%c\n",217);
}
void Linea(int eColIni, int eColFin){
	int eCol;
	for(eCol = eColIni; eCol <= eColFin; eCol++){
		printf("%c",196);
 	}
}
void GoToXY(int eRen, int eCol){
	
	COORD coordenada;
	HANDLE salida = GetStdHandle(STD_OUTPUT_HANDLE);
	
	coordenada.X = eCol;
	coordenada.Y = eRen;
	
	SetConsoleCursorPosition(salida, coordenada);
}
void Centrar(char *sCadena , int eRenglon){
	
	Mensaje(sCadena , (100 - strlen(sCadena)) / 2, eRenglon);
	
}
void Mensaje(char *sTexto, int eRenglon, int eColumna){
	
	GoToXY( eColumna, eRenglon );
	printf("%s", sTexto);
}



