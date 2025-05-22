#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Funciones.h"

void MenuLecturas();
void MenuInterfaz();
void MenuConversion();
void MenuGenerarNumeros();
void AltaCliente();

int main() {
    srand(time(NULL));  // Inicializar números aleatorios
    Marco();

    int opcion;

    do {
        system("cls");
        Marco();
        Centrar("MENU PRINCIPAL", 3);
        Mensaje("1. Lecturas", 5, 7);
        Mensaje("2. Interfaz de usuario", 5, 8);
        Mensaje("3. Conversion", 5, 9);
        Mensaje("4. Generar numeros", 5, 10);
        Mensaje("5. Alta cliente", 5, 11);
        Mensaje("6. Salir", 5, 12);
        Mensaje("Seleccione una opcion: ", 5, 14);
        
        GoToXY(14, 30);
        scanf("%d", &opcion);
        fflush(stdin);

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
            case 6: 
                    system("cls");
                    Marco();
                    Centrar("Saliendo del programa...", 12);
                    GoToXY(14, 5);
                    printf("Presione cualquier tecla para salir...");
                    getch();
                    break;
            default: 
                    system("cls");
                    Marco();
                    Centrar("Opcion invalida", 12);
                    GoToXY(14, 5);
                    printf("Presione cualquier tecla para continuar...");
                    getch();
        }

    } while (opcion != 6);
    
    return 0;
}

//Funciones
void MenuLecturas() {
    int opcion;
    do {
        system("cls");
        Marco();
        Centrar("MENU LECTURAS", 3);
        Mensaje("1. Leer entero", 5, 7);
        Mensaje("2. Leer cadena alfabetica", 5, 8);
        Mensaje("3. Leer S o N", 5, 9);
        Mensaje("4. Validar cadena de 15 caracteres", 5, 10);
        Mensaje("5. Leer enteros positivos", 5, 11);
        Mensaje("6. Leer entero en rango", 5, 12);
        Mensaje("7. Leer flotante en rango", 5, 13);
        Mensaje("8. Leer caracter en rango", 5, 14);
        Mensaje("9. Leer caracter de un conjunto", 5, 15);
        Mensaje("10. Leer cadena con formato", 5, 16);
        Mensaje("11. Convertir a mayusculas", 5, 17);
        Mensaje("12. Regresar al menu principal", 5, 18);
        Mensaje("Seleccione una opcion: ", 5, 20);
        
        GoToXY(20, 30);
        scanf("%d", &opcion);
        fflush(stdin);

        switch (opcion) {
            case 1: {
                system("cls");
                Marco();
                Centrar("LEER ENTERO", 3);
                int numero = LeerEntero();
                GoToXY(17, 5);
                printf("Numero ingresado: %d", numero);
                GoToXY(19, 5);
                printf("Presione cualquier tecla para continuar...");
                getch();
                break;
            }

            case 2: {
                system("cls");
                Marco();
                Centrar("LEER CADENA ALFABETICA", 3);
                char* cadena = LeerCadenaAlfabetica();
                GoToXY(17, 5);
                printf("Cadena ingresada: %s", cadena);
                GoToXY(19, 5);
                printf("Presione cualquier tecla para continuar...");
                getch();
                break;
            }

            case 3: {
                system("cls");
                Marco();
                Centrar("LEER S o N", 3);
                int resultado = LeerSN();
                GoToXY(17, 5);
                if (resultado) {
                    printf("Seleccionaste 'S' (Si)");
                } else {
                    printf("Seleccionaste 'N' (No)");
                }
                GoToXY(19, 5);
                printf("Presione cualquier tecla para continuar...");
                getch();
                break;
            }

            case 4: {
                system("cls");
                Marco();
                Centrar("VALIDAR CADENA 15 CARACTERES", 3);
                char* cadena = ValidarCadena15();
                GoToXY(17, 5);
                printf("Cadena valida ingresada: %s", cadena);
                GoToXY(19, 5);
                printf("Presione cualquier tecla para continuar...");
                getch();
                break;
            }

            case 5: {
                system("cls");
                Marco();
                Centrar("LEER ENTERO POSITIVO", 3);
                int numero = LeerEnteroPositivo();
                GoToXY(17, 5);
                printf("Numero positivo ingresado: %d", numero);
                GoToXY(19, 5);
                printf("Presione cualquier tecla para continuar...");
                getch();
                break;
            }

            case 6: {
                system("cls");
                Marco();
                Centrar("LEER ENTERO EN RANGO", 3);
                int minimo, maximo, numero;
                
                GoToXY(10, 5);
                printf("Introduce el limite inferior: ");
                scanf("%d", &minimo);
                GoToXY(11, 5);
                printf("Introduce el limite superior: ");
                scanf("%d", &maximo);

                if (minimo > maximo) {
                    int temp = minimo;
                    minimo = maximo;
                    maximo = temp;
                }

                numero = LeerEnteroEnRango(minimo, maximo);
                GoToXY(17, 5);
                printf("Numero en rango [%d, %d]: %d", minimo, maximo, numero);
                GoToXY(19, 5);
                printf("Presione cualquier tecla para continuar...");
                getch();
                break;
            }

            case 7: {
                system("cls");
                Marco();
                Centrar("LEER FLOTANTE EN RANGO", 3);
                float minimo, maximo, numero;
                
                GoToXY(10, 5);
                printf("Introduce el limite inferior: ");
                scanf("%f", &minimo);
                GoToXY(11, 5);
                printf("Introduce el limite superior: ");
                scanf("%f", &maximo);

                if (minimo > maximo) {
                    float temp = minimo;
                    minimo = maximo;
                    maximo = temp;
                }

                numero = LeerFlotanteEnRango(minimo, maximo);
                GoToXY(17, 5);
                printf("Numero flotante en rango [%.2f, %.2f]: %.2f", minimo, maximo, numero);
                GoToXY(19, 5);
                printf("Presione cualquier tecla para continuar...");
                getch();
                break;
            }
            
            case 8: {
                system("cls");
                Marco();
                Centrar("LEER CARACTER EN RANGO", 3);
                char minimo, maximo, caracter;
                
                GoToXY(10, 5);
                printf("Introduce el limite inferior (caracter): ");
                fflush(stdin);
                scanf(" %c", &minimo);
                GoToXY(11, 5);
                printf("Introduce el limite superior (caracter): ");
                fflush(stdin);
                scanf(" %c", &maximo);

                caracter = LeerCaracterEnRango(minimo, maximo);
                GoToXY(17, 5);
                printf("Caracter en rango ['%c', '%c']: %c", minimo, maximo, caracter);
                GoToXY(19, 5);
                printf("Presione cualquier tecla para continuar...");
                getch();
                break;
            }
            
            case 9: {
                system("cls");
                Marco();
                Centrar("LEER CARACTER DE CONJUNTO", 3);
                char conjunto[50], caracter;
                
                GoToXY(10, 5);
                printf("Introduce el conjunto de caracteres validos: ");
                fflush(stdin);
                fgets(conjunto, sizeof(conjunto), stdin);
                conjunto[strcspn(conjunto, "\n")] = '\0';  // Remover salto de línea

                caracter = LeerCaracterValido(conjunto);
                GoToXY(17, 5);
                printf("Caracter valido ingresado: %c", caracter);
                GoToXY(19, 5);
                printf("Presione cualquier tecla para continuar...");
                getch();
                break;
            }

            case 10: {
                system("cls");
                Marco();
                Centrar("LEER CADENA CON FORMATO", 3);
                char formato[50];
                char *cadenaValida;
                
                GoToXY(10, 5);
                printf("Introduce el formato (A=letra, 9=digito, X=alfanumerico): ");
                fflush(stdin);
                fgets(formato, sizeof(formato), stdin);

                cadenaValida = LeerCadenaConFormato(formato);
                GoToXY(17, 5);
                printf("Cadena valida: %s", cadenaValida);
                GoToXY(19, 5);
                printf("Presione cualquier tecla para continuar...");
                getch();
                break;
            }
            
            case 11: {
                system("cls");
                Marco();
                Centrar("CONVERTIR A MAYUSCULAS", 3);
                char* cadena = RegresarCadenaMayusculas();
                GoToXY(17, 5);
                printf("Cadena en mayusculas: %s", cadena);
                GoToXY(19, 5);
                printf("Presione cualquier tecla para continuar...");
                getch();
                break;
            }

            case 12: 
                break;

            default: 
                system("cls");
                Marco();
                Centrar("Opcion invalida", 12);
                GoToXY(14, 5);
                printf("Presione cualquier tecla para continuar...");
                getch();
                break;
        }
    
    } while (opcion != 12);
}

void MenuInterfaz() {
    int opcion;
    do {
        system("cls");
        Marco();
        Centrar("MENU INTERFAZ", 3);
        Mensaje("1. Demostrar mensaje en posicion", 5, 7);
        Mensaje("2. Demostrar mensaje centrado", 5, 8);
        Mensaje("3. Demostrar borrar area", 5, 9);
        Mensaje("4. Demostrar marco", 5, 10);
        Mensaje("5. Regresar al menu principal", 5, 11);
        Mensaje("Seleccione una opcion: ", 5, 13);
        
        GoToXY(13, 30);
        scanf("%d", &opcion);
        fflush(stdin);

        switch (opcion) {
            case 1: {
                system("cls");
                Marco();
                Centrar("DEMOSTRAR MENSAJE EN POSICION", 3);
                Mensaje("Este es un mensaje en la posicion (10, 20)", 20, 10);
                Mensaje("Este es otro mensaje en la posicion (15, 25)", 25, 12);
                GoToXY(20, 5);
                printf("Presione cualquier tecla para continuar...");
                getch();
                break;
            }
            
            case 2: {
                system("cls");
                Marco();
                Centrar("DEMOSTRAR MENSAJE CENTRADO", 3);
                Centrar("Este mensaje esta centrado", 10);
                Centrar("Este es otro mensaje centrado", 12);
                GoToXY(20, 5);
                printf("Presione cualquier tecla para continuar...");
                getch();
                break;
            }
            
            case 3: {
                system("cls");
                Marco();
                Centrar("DEMOSTRAR BORRAR AREA", 3);
                
                // Llenar un área con texto
                for(int i = 8; i <= 15; i++) {
                    for(int j = 10; j <= 50; j++) {
                        GoToXY(i, j);
                        printf("X");
                    }
                }
                
                GoToXY(17, 5);
                printf("Area llenada con 'X'. Presione una tecla para borrar...");
                getch();
                
                // Borrar el área
                borrarArea(10, 8, 50, 15);
                
                GoToXY(19, 5);
                printf("Area borrada. Presione cualquier tecla para continuar...");
                getch();
                break;
            }
            
            case 4: {
                system("cls");
                Marco();
                Centrar("DEMOSTRAR MARCO", 3);
                GoToXY(10, 5);
                printf("Este es el marco del programa.");
                GoToXY(12, 5);
                printf("Observe los bordes de la pantalla.");
                GoToXY(20, 5);
                printf("Presione cualquier tecla para continuar...");
                getch();
                break;
            }
            
            case 5:
                break;
                
            default: 
                system("cls");
                Marco();
                Centrar("Opcion invalida", 12);
                GoToXY(14, 5);
                printf("Presione cualquier tecla para continuar...");
                getch();
                break;
        }
    } while (opcion != 5);
}

void MenuConversion() {
    int opcion;

    do {
        system("cls");
        Marco();
        Centrar("MENU CONVERSIONES", 3);
        Mensaje("1. Convertir cadena a mayusculas", 5, 7);
        Mensaje("2. Numero a cadena", 5, 8);
        Mensaje("3. Cadena a numero", 5, 9);
        Mensaje("4. Regresar al menu principal", 5, 10);
        Mensaje("Seleccione una opcion: ", 5, 12);
        
        GoToXY(12, 30);
        scanf("%d", &opcion);
        fflush(stdin);

        switch (opcion) {
            case 1: {
                system("cls");
                Marco();
                Centrar("CONVERTIR A MAYUSCULAS", 3);
                char* sCadena = RegresarCadenaMayusculas();
                GoToXY(17, 5);
                printf("Cadena en mayusculas: %s", sCadena);
                GoToXY(19, 5);
                printf("Presione cualquier tecla para continuar...");
                getch();
                break;
            }

            case 2: {
                system("cls");
                Marco();
                Centrar("NUMERO A CADENA", 3);
                int eNumero = LeerNumero();
                char* sCadena = ConvertirNumeroCadena(eNumero);
                if (sCadena != NULL) {
                    GoToXY(17, 5);
                    printf("Numero: %d -> Cadena: '%s'", eNumero, sCadena);
                    free(sCadena);
                } else {
                    GoToXY(17, 5);
                    printf("Error al convertir el numero.");
                }
                GoToXY(19, 5);
                printf("Presione cualquier tecla para continuar...");
                getch();
                break;
            }

            case 3: {
                system("cls");
                Marco();
                Centrar("CADENA A NUMERO", 3);
                char* sCadena = leerCadena();
                if (sCadena != NULL) {
                    double numero = convertirCadenaANumero(sCadena);
                    GoToXY(17, 5);
                    printf("Cadena: '%s' -> Numero: %f", sCadena, numero);
                    free(sCadena);
                } else {
                    GoToXY(17, 5);
                    printf("Error al leer la cadena.");
                }
                GoToXY(19, 5);
                printf("Presione cualquier tecla para continuar...");
                getch();
                break;
            }

            case 4:
                break;

            default:
                system("cls");
                Marco();
                Centrar("Opcion invalida", 12);
                GoToXY(14, 5);
                printf("Presione cualquier tecla para continuar...");
                getch();
                break;
        }
    } while (opcion != 4);
}

void MenuGenerarNumeros() {
    int opcion;
    do {
        system("cls");
        Marco();
        Centrar("MENU GENERAR NUMEROS", 3);
        Mensaje("1. Generar numero entero aleatorio", 5, 7);
        Mensaje("2. Regresar al menu principal", 5, 8);
        Mensaje("Seleccione una opcion: ", 5, 10);
        
        GoToXY(10, 30);
        scanf("%d", &opcion);
        fflush(stdin);

        switch (opcion) {
            case 1: {
                system("cls");
                Marco();
                Centrar("GENERAR NUMERO ALEATORIO", 3);
                int limite;
                
                GoToXY(10, 5);
                printf("Introduce el limite superior (0 hasta este numero): ");
                scanf("%d", &limite);
                
                if (limite < 0) {
                    GoToXY(12, 5);
                    printf("El limite debe ser mayor o igual a 0.");
                } else {
                    int numeroAleatorio = GenerarNumeroAleatorio(limite);
                    GoToXY(12, 5);
                    printf("Numero aleatorio generado entre 0 y %d: %d", limite, numeroAleatorio);
                }
                
                GoToXY(20, 5);
                printf("Presione cualquier tecla para continuar...");
                getch();
                break;
            }
            
            case 2: 
                break;
                
            default: 
                system("cls");
                Marco();
                Centrar("Opcion invalida", 12);
                GoToXY(14, 5);
                printf("Presione cualquier tecla para continuar...");
                getch();
                break;
        }
    } while (opcion != 2);
}

void AltaCliente() {
    system("cls");
    Marco();
    Centrar("ALTA CLIENTE", 3);
    Centrar("Esta seccion esta en construccion", 12);
    GoToXY(20, 5);
    printf("Presione cualquier tecla para continuar...");
    getch();
}