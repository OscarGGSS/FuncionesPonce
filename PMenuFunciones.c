#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"

void MenuLecturas();
void MenuInterfaz();
void MenuConversion();
void MenuGenerarNumeros();
void AltaCliente();

int main() {
    
    Marco();

    int eOpcion;

    do {
        system("cls");
        Centrar("MENU PRINCIPAL", 3);
        Mensaje("1. Lecturas", 7, 7);
        Mensaje("2. Interfaz de usuario", 7, 8);
        Mensaje("3. Conversion", 7 , 9);
        Mensaje("4. Generar numeros", 7, 10);
        Mensaje("5. Alta cliente", 7, 11);
        Mensaje("6. Salir", 7, 12);
        Mensaje("Seleccione una Opcion: ", 7, 25);
        GoToXY(25, 30);
        scanf("%d", &eOpcion);

        switch (eOpcion) {
            
            case 1: MenuLecturas(); 
                    break;

            case 2: MenuInterfaz(); 
                    break;

            case 3: MenuConversion(); 
                    break;

            case 4: MenuGenerarNumeros(); 
                    break;

            case 5: AltaCliente(); 
                    break;

            case 6: Mensaje("Saliendo del programa...", 25, 30); 
                    break;

            default: Mensaje("Opcion invalida", 25, 30); 
                    system("pause");
                    break;
        }

    } while (eOpcion != 6);
    
    system("pause");
    return 0;
}

//Funciones
void MenuLecturas() {
    int eOpcion;
    do {
        system("cls");
        Mensaje("Lecturas", 7, 7);
        Mensaje("1. Leer entero", 7, 8);
        Mensaje("2. Leer cadena", 7, 9);
        Mensaje("3. Leer S o N", 7, 10);
        Mensaje("4. Validar cadena de 15 caracteres", 7, 11);
        Mensaje("5. Leer positivos", 7, 12);
        Mensaje("6. Leer entero en rango", 7, 13);
        Mensaje("7. Leer flotante en rango", 7, 14);
        Mensaje("8. Leer caracter en rango", 7, 15);
        Mensaje("9. Leer caracter de un conjunto", 7, 16);
        Mensaje("10. Leer cadena con formato", 7, 17);
        Mensaje("11. Leer fecha", 7, 18);
        Mensaje("12. Regresar al menu principal", 7, 19);
        Mensaje("Seleccione una Opcion: ", 7, 20);
        scanf("%d", &eOpcion);

        switch (eOpcion) {
            
            case 1: {
                        system("cls");
                        int numero;
                        fflush(stdin);
                        GoToXY(8,15);
                        numero = LeerEntero();
                        Mensaje("Numero ingresado", 7, 9);
                        system("pause");
                        break;
            }

            case 2: {
                        system("cls");
                        char* cadena;
                        fflush(stdin);
                        GoToXY(8,15);
                        Mensaje("Introduce una cadena alfabetica: ", 7,7);
                        cadena = LeerCadenaAlfabetica();
                        Mensaje("Cadena ingresada", 7, 9);
                        system("pause");
                        break;
            }

            case 3: {
                        system("cls");
                        int resultado;
                        fflush(stdin);
                        GoToXY(8,15);
                        resultado = LeerSN();
                        if (resultado){
                            Mensaje("Seleccionaste 'S'", 7, 15);
                        }else{
                            Mensaje("Seleccionaste 'N'", 7, 16);
                        }
                            system("pause");
                        break;
                    }

            case 4: {
                        system("cls");
                        char* cadena;
                        fflush(stdin);
                        GoToXY(8,15);
                        cadena = ValidarCadena15();
                        Mensaje("Cadena valida ingresada", 7, 9);
                        system("pause");
                        break;
            }

            case 5: {
                        system("cls");
                        int numero;
                        fflush(stdin);
                        Mensaje("Introduce un numero entero positivo: ", 7, 7);
                        GoToXY(8,15);
                        numero = LeerEnteroPositivo();
                        Mensaje("Numero ingresado", 7, 9);
                        system("pause");
                        break;
                
            }

            case 6: {
                        system("cls");
                        int minimo, maximo, numero;
                        fflush(stdin);
                        Mensaje("Introduce el límite inferior: ", 7, 7);
                        scanf("%d", &minimo);
                        Mensaje("Introduce el límite superior: ", 7, 8);
                        scanf("%d", &maximo);

                        if (minimo > maximo) {
                            int temp = minimo;
                            minimo = maximo;
                            maximo = temp;
                        }

                        numero = LeerEnteroEnRango(minimo, maximo);
                        Mensaje("Número ingresado", 7, 10);
                        system("pause");
                        break;
                    }

            case 7: {
                        system("cls");
                        float minimo, maximo, numero;
                        fflush(stdin);
                        Mensaje("Introduce el límite inferior: ", 7, 7);
                        scanf("%f", &minimo);
                        Mensaje("Introduce el límite superior: ", 7, 8);
                        scanf("%f", &maximo);

                        if (minimo > maximo) {
                            float temp = minimo;
                            minimo = maximo;
                            maximo = temp;
                        }

                        numero = LeerFlotanteEnRango(minimo, maximo);
                        Mensaje("Número ingresado", 7, 10);
                        system("pause");
                        break;
                    }
            
            case 8: {
                        system("cls");
                        char minimo, maximo, caracter;
                        fflush(stdin);
                        Mensaje("Introduce el límite inferior (carácter): ", 7, 7);
                        scanf(" %c", &minimo);
                        Mensaje("Introduce el límite superior (carácter): ", 7, 8);
                        scanf(" %c", &maximo);

                        caracter = LeerCaracterEnRango(minimo, maximo);
                        Mensaje("Carácter ingresado", 7, 10);
                        system("pause");
                        break;
                        }
            case 9: {
                        system("cls");
                        char conjunto[50], caracter;
                        fflush(stdin);
                        Mensaje("Introduce el conjunto de caracteres válidos (por ejemplo: abc123): ", 7, 7);
                        fgets(conjunto, sizeof(conjunto), stdin);

                        caracter = LeerCaracterValido(conjunto);
                        Mensaje("Carácter ingresado: ", 7, 9);
                        system("pause");
                        break;
            }

            case 10: {
                        system("cls");
                        char formato[50];
                        char *cadenaValida;
                        fflush(stdin);
                        Mensaje("Introduce el formato (A=letra, 9=dígito, X=alfanumérico): ", 7, 7);
                        fgets(formato, sizeof(formato), stdin);

                        cadenaValida = LeerCadenaConFormato(formato);
                        Mensaje("Cadena válida ingresada:", 7, 9);
                        system("pause");
                        break;
                    }
            case 11: system("cls");
                    Mensaje("Aqui va la fecha", 7, 7);
                    system("pause");
                    break;

            case 12: 
                        break;

            default: 
                        Mensaje("eOpcion invalida", 7, 7); 
                        system("pause");
                        break;
        }
    
    } while (eOpcion != 12);
}

void MenuInterfaz() {
    int eOpcion;
    do {
        system("cls");
        Centrar("Interfaz", 3);
        Mensaje("1. Mensaje en renglon", 7, 7);
        Mensaje("2. Mensaje centrado", 8, 7);
        Mensaje("3. Mensaje en renglon y columna", 9, 7);
        Mensaje("4. Borrar area en pantalla", 10, 7);
        Mensaje("5. Margen en área", 11, 7);
        Mensaje("Seleccione una eOpcion: ", 12, 7);
        scanf("%d", &eOpcion);

        switch (eOpcion) {
            case 1: 
            default: Mensaje("eOpcion invalida", 15, 7); system("pause");
        }
    } while (eOpcion != 5);
}

void MenuConversion() {
    int eOpcion;
    char* sCadena = NULL;
    int eNumero;
    double numero;

    do {
        system("cls");
        Centrar("Conversiones", 3);
        Mensaje("1. Convertir cadena a mayusculas", 7, 7);
        Mensaje("2. Numero a cadena", 8, 7);
        Mensaje("3. Cadena a numero", 9, 7);
        Mensaje("4. Regresar al menu principal", 10, 7);
        Mensaje("Seleccione una eOpcion: ", 11, 7);
        scanf("%d", &eOpcion);
        fflush(stdin);

        switch (eOpcion) {
            case 1:
                system("cls");
                Mensaje("Convertir cadena a mayusculas :", 7, 7);
                sCadena = RegresarCadenaMayusculas();
                Mensaje("Cadena en mayusculas (falta sprint aqui): ", 9, 7);
                free(sCadena);
                system("pause");
                break;

            case 2:
                system("cls");
                Mensaje("Numero a cadena", 7, 7);
                eNumero = LeerNumero();
                sCadena = ConvertirNumeroCadena(eNumero);
                Mensaje("Cadena resultante(falta sprint)", 7, 7);
                free(sCadena);
                system("pause");
                break;

            case 3:
                system("cls");
                Mensaje("Cadena a numero", 7, 7);
                sCadena = leerCadena();
                if (sCadena != NULL) {
                    numero = convertirCadenaANumero(sCadena);
                    mostrarNumero(numero);
                    free(sCadena);
                }
                system("pause");
                break;

            case 4:
                break;

            default:
                Mensaje("eOpcion invalida", 10, 7);
                system("pause");
                break;
        }
    } while (eOpcion != 4);
}

void MenuGenerarNumeros() {
    int eOpcion;
    do {
        system("cls");
        Centrar("Generar Numeros", 3);
        Mensaje("1. Generar numero entero aleatorio", 7, 7);
        Mensaje("2. Regresar al menu principal", 8, 7);
        Mensaje("Seleccione una eOpcion: ", 9, 7);
        scanf("%d", &eOpcion);

        switch (eOpcion) {
            case 1: Mensaje("hola", 7, 7);
                    break;
            case 2: 
                    break;
            default: Mensaje("eOpcion invalida", 15, 7); system("pause");
        }
    } while (eOpcion != 2);
}

void AltaCliente() {
    system("cls");
    Centrar("Alta Cliente", 3);
    Mensaje("Esta seccion esta en construccion", 7, 7);
    system("pause");
}
