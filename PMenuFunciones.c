#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    
    int opcion;
    do {
        system("cls");
        printf("MENU PRINCIPAL\n");
        printf("1. Lecturas\n");
        printf("2. Interfaz de usuario\n");
        printf("3. Conversion\n");
        printf("4. Generar numeros\n");
        printf("5. Alta cliente\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
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

            case 5: MenuAltaCliente(); 
                    break;

            case 6: printf("Saliendo del programa...\n"); 
                    break;

            default: printf("Opcion invalida\n"); system("pause");
        }

    } while (opcion != 6);

    return 0;
}

//Funciones
void MenuLecturas() {
    int opcion;
    do {
        system("cls");
        printf("Lecturas\n");
        printf("1. Leer entero\n");
        printf("2. Leer cadena\n");
        printf("3. Leer S o N\n");
        printf("4. Validar cadena de 15 caracteres\n");
        printf("5. Leer positivos\n");
        printf("6. Leer entero en rango\n");
        printf("7. Leer flotante en rango\n");
        printf("8. Leer caracter en rango\n");
        printf("9. Leer caracter de un conjunto\n");
        printf("10. Leer cadena con formato\n");
        printf("11. Leer fecha\n");
        printf("12. Regresar al menu principal\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            
            case 1: {
                        int numero;
                        fflush(stdin);
                        numero = LeerEntero();
                        printf("Numero ingresado: %d\n", numero);
                        system("pause");
                        break;
            }

            case 2: {
                        char* cadena;
                        fflush(stdin);
                        printf("Introduce una cadena alfabetica: ");
                        cadena = LeerCadenaAlfabetica();
                        printf("Cadena ingresada: %s\n", cadena);
                        system("pause");
                        break;
            }

            case 3: {
                        int resultado;
                        fflush(stdin);
                        resultado = LeerSN();
                        if (resultado){
                            printf("Seleccionaste 'S'\n");
                        }else{
                            printf("Seleccionaste 'N'\n");
                        }
                            system("pause");
                        break;
                    }

            case 4: {
                        char* cadena;
                        fflush(stdin);
                        cadena = ValidarCadena15();
                        printf("Cadena valida ingresada: %s\n", cadena);
                        system("pause");
                        break;
            }

            case 5: {
                        int numero;
                        fflush(stdin);
                        printf("Introduce un numero entero positivo: ");
                        numero = LeerEnteroPositivo();
                        printf("Numero ingresado: %d\n", numero);
                        system("pause");
                        break;
                
            }

            case 6: {
                        int minimo, maximo, numero;
                        fflush(stdin);
                        printf("Introduce el límite inferior: ");
                        scanf("%d", &minimo);
                        printf("Introduce el límite superior: ");
                        scanf("%d", &maximo);

                        if (minimo > maximo) {
                            int temp = minimo;
                            minimo = maximo;
                            maximo = temp;
                        }

                        numero = LeerEnteroEnRango(minimo, maximo);
                        printf("Número ingresado: %d\n", numero);
                        system("pause");
                        break;
                    }

            case 7: {
                        float minimo, maximo, numero;
                        fflush(stdin);
                        printf("Introduce el límite inferior: ");
                        scanf("%f", &minimo);
                        printf("Introduce el límite superior: ");
                        scanf("%f", &maximo);

                        if (minimo > maximo) {
                            float temp = minimo;
                            minimo = maximo;
                            maximo = temp;
                        }

                        numero = LeerFlotanteEnRango(minimo, maximo);
                        printf("Número ingresado: %.4f\n", numero);
                        system("pause");
                        break;
                    }
            
            case 8: {
                        char minimo, maximo, caracter;
                        fflush(stdin);
                        printf("Introduce el límite inferior (carácter): ");
                        scanf(" %c", &minimo);
                        printf("Introduce el límite superior (carácter): ");
                        scanf(" %c", &maximo);

                        caracter = LeerCaracterEnRango(minimo, maximo);
                        printf("Carácter ingresado: %c\n", caracter);
                        system("pause");
                        break;
                        }
            case 9: {
                        char conjunto[50], caracter;
                        fflush(stdin);
                        printf("Introduce el conjunto de caracteres válidos (por ejemplo: abc123): ");
                        gets(conjunto);

                        caracter = LeerCaracterValido(conjunto);
                        printf("Carácter ingresado: %c\n", caracter);
                        system("pause");
                        break;
            }

            case 10: {
                        char formato[50];
                        char *cadenaValida;
                        fflush(stdin);
                        printf("Introduce el formato (A=letra, 9=dígito, X=alfanumérico): ");
                        gets(formato);

                        cadenaValida = LeerCadenaConFormato(formato);
                        printf("Cadena válida ingresada: %s\n", cadenaValida);
                        system("pause");
                        break;
                    }
            case 11: printf("Aqui va la fecha");

            case 12: 
                        break;

            default: 
                        printf("Opcion invalida\n"); 
                        system("pause");
                        break;
        }
    
    } while (opcion != 12);
}

void MenuInterfaz() {
    int opcion;
    do {
        system("cls");
        printf("Interfaz\n");
        printf("1. Mensaje en renglon\n");
        printf("2. Mensaje centrado\n");
        printf("3. Mensaje en renglon y columna\n");
        printf("4. Borrar area en pantalla\n");
        printf("5. Margen en área\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: 
            default: printf("Opcion invalida\n"); system("pause");
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
        printf("Conversiones\n");
        printf("1. Convertir cadena a mayusculas\n");
        printf("2. Numero a cadena\n");
        printf("3. Cadena a numero\n");
        printf("4. Regresar al menu principal\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);

        switch (opcion) {
            case 1:
                system("cls");
                printf("Convertir cadena a mayusculas :\n");
                sCadena = RegresarCadenaMayusculas();
                printf("Cadena en mayusculas: %s\n", sCadena);
                free(sCadena);
                system("pause");
                break;

            case 2:
                system("cls");
                printf("Numero a cadena\n");
                eNumero = LeerNumero();
                sCadena = ConvertirNumeroCadena(eNumero);
                printf("Cadena resultante: %s\n", sCadena);
                free(sCadena);
                system("pause");
                break;

            case 3:
                system("cls");
                printf("Cadena a numero\n");
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
                printf("Opcion invalida\n");
                system("pause");
                break;
        }
    } while (opcion != 4);
}

void MenuGenerarNumeros() {
    int opcion;
    do {
        system("cls");
        printf("Generar Numeros\n");
        printf("1. Generar numero entero aleatorio\n");
        printf("2. Regresar al menu principal\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: printf("hola");
                    break;
            case 2: 
                    break;
            default: printf("Opcion invalida\n"); system("pause");
        }
    } while (opcion != 2);
}

void MenuAltaCliente() {
    system("cls");
    printf("Alta Cliente\n");
    printf("Esta seccion esta en construccion.\n");
    system("pause");
}
