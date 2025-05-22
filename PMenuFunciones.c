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
            
            

            
 


            default: printf("Opcion invalida\n"); system("pause");
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
    do {
        system("cls");
        printf("Conversiones\n");
        printf("1. Convertir cadena a mayusculas\n");
        printf("2. Numero a cadena\n");
        printf("3. Cadena a numero\n");
        printf("4. Regresar al menu principal\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
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
            case 1: 
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
