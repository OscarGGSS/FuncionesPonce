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
            case 1: MenuLecturas(); break;
            case 2: MenuInterfaz(); break;
            case 3: MenuConversion(); break;
            case 4: MenuGenerarNumeros(); break;
            case 5: MenuAltaCliente(); break;
            case 6: printf("Saliendo del programa...\n"); break;
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
        printf("5. Leer caracter en rango\n");
        printf("6. Leer positivos\n");
        printf("7. Leer flotante en rango\n");
        printf("8. Leer caracter en rango\n");
        printf("9. Leer flotante en rango\n");
        printf("10. Leer caracter de un conjunto\n");
        printf("11. Leer cadena con formato\n");
        printf("12. Leer fecha\n");
        printf("13. Regresar al menu principal\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: 
            default: printf("Opcion invalida\n"); system("pause");
        }
    } while (opcion != 8);
}

void menuConversion() {
    int opcion;
    do {
        system("cls");
        printf("=== Conversion ===\n");
        printf("1. Numero a cadena\n");
        printf("2. Cadena a numero\n");
        printf("3. Regresar al menu principal\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: Conversion(); break;
            case 2: ejecutarConversion(); break;
            case 3: printf("Regresando...\n"); break;
            default: printf("Opcion invalida\n"); system("pause");
        }
    } while (opcion != 3);
}

void menuGenerarNumeros() {
    int opcion;
    do {
        system("cls");
        printf("=== Generar Numeros ===\n");
        printf("1. Leer numero entero\n");
        printf("2. Regresar al menu principal\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: LeerNumero(); break;
            case 2: printf("Regresando...\n"); break;
            default: printf("Opcion invalida\n"); system("pause");
        }
    } while (opcion != 2);
}

void menuAltaCliente() {
    system("cls");
    printf("=== Alta Cliente ===\n");
    printf("Esta seccion esta en construccion.\n");
    system("pause");
}
