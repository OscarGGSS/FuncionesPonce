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

    int opcion;

    do {
        system("cls");
        Centrar("MENU PRINCIPAL", 3);
        Mensaje("1. Lecturas", 7, 7);
        Mensaje("2. Interfaz de usuario", 8, 7);
        Mensaje("3. Conversion", 9 , 7);
        Mensaje("4. Generar numeros", 10, 7);
        Mensaje("5. Alta cliente", 11, 7);
        Mensaje("6. Salir", 12, 7);
        Mensaje("Seleccione una opcion: ", 13, 7);
        scanf("%d", &opcion);

        switch (opcion) {
            
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

            case 6: Mensaje("Saliendo del programa...", 25, 7); 
                    break;

            default: Mensaje("Opcion invalida", 25, 7); 
                    system("pause");
        }

    } while (opcion != 6);
    
    system("pause");
    return 0;
}

//Funciones
void MenuLecturas() {
    int opcion;
    do {
        system("cls");
        Mensaje("Lecturas", 7, 7);
        Mensaje("1. Leer entero", 8, 7);
        Mensaje("2. Leer cadena", 9, 7);
        Mensaje("3. Leer S o N", 10, 7);
        Mensaje("4. Validar cadena de 15 caracteres", 11, 7);
        Mensaje("5. Leer positivos", 12, 7);
        Mensaje("6. Leer entero en rango",13, 7);
        Mensaje("7. Leer flotante en rango", 14, 7);
        Mensaje("8. Leer caracter en rango", 15, 7);
        Mensaje("9. Leer caracter de un conjunto", 16, 7);
        Mensaje("10. Leer cadena con formato", 17, 7);
        Mensaje("11. Leer fecha", 18, 7);
        Mensaje("12. Regresar al menu principal", 19, 7);
        Mensaje("Seleccione una opcion: ", 20, 7);
        scanf("%d", &opcion);

        switch (opcion) {
            
            case 1: {
                        system("cls");
                        int numero;
                        fflush(stdin);
                        numero = LeerEntero();
                        Mensaje("Numero ingresado", 7, 7);
                        system("pause");
                        break;
            }

            case 2: {
                        system("cls");
                        char* cadena;
                        fflush(stdin);
                        Mensaje("Introduce una cadena alfabetica: ", 7,7);
                        cadena = LeerCadenaAlfabetica();
                        Mensaje("Cadena ingresada", 8, 7);
                        system("pause");
                        break;
            }

            case 3: {
                        system("cls");
                        int resultado;
                        fflush(stdin);
                        resultado = LeerSN();
                        if (resultado){
                            Mensaje("Seleccionaste 'S'", 7, 7);
                        }else{
                            Mensaje("Seleccionaste 'N'", 7, 7);
                        }
                            system("pause");
                        break;
                    }

            case 4: {
                        system("cls");
                        char* cadena;
                        fflush(stdin);
                        cadena = ValidarCadena15();
                        Mensaje("Cadena valida ingresada", 7, 7);
                        system("pause");
                        break;
            }

            case 5: {
                        system("cls");
                        int numero;
                        fflush(stdin);
                        Mensaje("Introduce un numero entero positivo: ", 7, 7);
                        numero = LeerEnteroPositivo();
                        Mensaje("Numero ingresado", 8, 7);
                        system("pause");
                        break;
                
            }

            case 6: {
                        system("cls");
                        int minimo, maximo, numero;
                        fflush(stdin);
                        Mensaje("Introduce el límite inferior: ", 7, 7);
                        scanf("%d", &minimo);
                        Mensaje("Introduce el límite superior: ", 8, 7);
                        scanf("%d", &maximo);

                        if (minimo > maximo) {
                            int temp = minimo;
                            minimo = maximo;
                            maximo = temp;
                        }

                        numero = LeerEnteroEnRango(minimo, maximo);
                        Mensaje("Número ingresado", 10, 7);
                        system("pause");
                        break;
                    }

            case 7: {
                        system("cls");
                        float minimo, maximo, numero;
                        fflush(stdin);
                        Mensaje("Introduce el límite inferior: ", 7, 7);
                        scanf("%f", &minimo);
                        Mensaje("Introduce el límite superior: ", 8, 7);
                        scanf("%f", &maximo);

                        if (minimo > maximo) {
                            float temp = minimo;
                            minimo = maximo;
                            maximo = temp;
                        }

                        numero = LeerFlotanteEnRango(minimo, maximo);
                        Mensaje("Número ingresado", 10, 7);
                        system("pause");
                        break;
                    }
            
            case 8: {
                        system("cls");
                        char minimo, maximo, caracter;
                        fflush(stdin);
                        Mensaje("Introduce el límite inferior (carácter): ", 7, 7);
                        scanf(" %c", &minimo);
                        Mensaje("Introduce el límite superior (carácter): ", 8, 7);
                        scanf(" %c", &maximo);

                        caracter = LeerCaracterEnRango(minimo, maximo);
                        Mensaje("Carácter ingresado", 10, 7);
                        system("pause");
                        break;
                        }
            case 9: {
                        system("cls");
                        char conjunto[50], caracter;
                        fflush(stdin);
                        Mensaje("Introduce el conjunto de caracteres válidos (por ejemplo: abc123): ");
                        gets(conjunto);

                        caracter = LeerCaracterValido(conjunto);
                        Mensaje("Carácter ingresado: %c\n", caracter);
                        system("pause");
                        break;
            }

            case 10: {
                        system("cls");
                        char formato[50];
                        char *cadenaValida;
                        fflush(stdin);
                        Mensaje("Introduce el formato (A=letra, 9=dígito, X=alfanumérico): ");
                        gets(formato);

                        cadenaValida = LeerCadenaConFormato(formato);
                        Mensaje("Cadena válida ingresada: %s\n", cadenaValida);
                        system("pause");
                        break;
                    }
            case 11: system("cls");
                    Mensaje("Aqui va la fecha");
                    break;

            case 12: 
                        break;

            default: 
                        Mensaje("Opcion invalida\n"); 
                        system("pause");
                        break;
        }
    
    } while (opcion != 12);
}

void MenuInterfaz() {
    int opcion;
    do {
        system("cls");
        Mensaje("Interfaz\n");
        Mensaje("1. Mensaje en renglon\n");
        Mensaje("2. Mensaje centrado\n");
        Mensaje("3. Mensaje en renglon y columna\n");
        Mensaje("4. Borrar area en pantalla\n");
        Mensaje("5. Margen en área\n");
        Mensaje("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: 
            default: Mensaje("Opcion invalida\n"); system("pause");
        }
    } while (opcion != 5);
}

void MenuConversion() {
    int opcion;
    char* sCadena = NULL;
    int eNumero;
    double numero;

    do {
        system("cls");
        Mensaje("Conversiones\n");
        Mensaje("1. Convertir cadena a mayusculas\n");
        Mensaje("2. Numero a cadena\n");
        Mensaje("3. Cadena a numero\n");
        Mensaje("4. Regresar al menu principal\n");
        Mensaje("Seleccione una opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);

        switch (opcion) {
            case 1:
                system("cls");
                Mensaje("Convertir cadena a mayusculas :\n");
                sCadena = RegresarCadenaMayusculas();
                Mensaje("Cadena en mayusculas: %s\n", sCadena);
                free(sCadena);
                system("pause");
                break;

            case 2:
                system("cls");
                Mensaje("Numero a cadena\n");
                eNumero = LeerNumero();
                sCadena = ConvertirNumeroCadena(eNumero);
                Mensaje("Cadena resultante: %s\n", sCadena);
                free(sCadena);
                system("pause");
                break;

            case 3:
                system("cls");
                Mensaje("Cadena a numero\n");
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
                Mensaje("Opcion invalida\n");
                system("pause");
                break;
        }
    } while (opcion != 4);
}

void MenuGenerarNumeros() {
    int opcion;
    do {
        system("cls");
        Mensaje("Generar Numeros\n");
        Mensaje("1. Generar numero entero aleatorio\n");
        Mensaje("2. Regresar al menu principal\n");
        Mensaje("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: Mensaje("hola");
                    break;
            case 2: 
                    break;
            default: Mensaje("Opcion invalida\n"); system("pause");
        }
    } while (opcion != 2);
}

void AltaCliente() {
    system("cls");
    Mensaje("Alta Cliente\n");
    Mensaje("Esta seccion esta en construccion.\n");
    system("pause");
}
