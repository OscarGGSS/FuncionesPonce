/* *********
   Programa: P23AltaClientes.c
   Autor: Infosauridos
   Fecha: 21/05/2025
   Objetivo: Alta de clientes con validaciones y formato visual
   Compilador: Dev-C++ 5.11
   Versión: 1.0
********* */

#include <time.h>
#include "Funciones.h"

void AltaClientes() {
    char sRFC[14], sNombre[50], sDomicilio[31], sTelefono[12], sFechaNac[9];
    char sSaldo[20], cTipoCliente;
    float fSaldo;
    int eContinuar = 1;
    int i; // Variable para bucles
    
    // Inicializar semilla para números aleatorios
    srand(time(NULL));
    
    while (eContinuar) {
        Marco();
        Centrar("Alta de Clientes", 3);
        
        // RFC (formato AAAA999999XXX)
        GoToXY(10, 6);
        printf("R.F.C.: ");
        
        strcpy(sRFC, LeerCadenaConFormato("AAAA999999XXX"));
        
        // Nombre del cliente (solo alfabético)
        GoToXY(11, 6);
        printf("Nombre del cliente: ");
        strcpy(sNombre, LeerCadenaAlfabetica());
        
        // Domicilio (máximo 30 caracteres)
        GoToXY(12, 6);
        printf("Domicilio: ");
        strcpy(sDomicilio, ValidarCadena(sDomicilio, 30));
        
        // Teléfono (formato XX-XX-XX-XX)
        GoToXY(13, 6);
        printf("Telefono: ");
        strcpy(sTelefono, LeerCadenaConFormato("99-99-99-99"));
        
        // Fecha de nacimiento (dd/mm/aa)
        GoToXY(14, 6);
        printf("Fecha de nacimiento (dd/mm/aa): ");
        strcpy(sFechaNac, LeerCadenaConFormato("99/99/99"));
        
        // Saldo (flotante positivo)
        GoToXY(15, 6);
        printf("Saldo $: ");
        fSaldo = LeerFlotanteEnRango(0.0, 999999.99);
        
        // Tipo de cliente (F/M)
        GoToXY(16, 6);
        printf("Tipo de cliente [M/F]: ");
        cTipoCliente = LeerCaracterEnRango('A', 'Z');
        while (cTipoCliente != 'M' && cTipoCliente != 'F') {
            MensajeError(8);
            GoToXY(10, 18);
            printf("Tipo de cliente [M/F]: ");
            cTipoCliente = LeerCaracterEnRango('A', 'Z');
        }
        
        // Preguntar si desea agregar otro cliente
        GoToXY(17, 20);
        printf("%cDesea agregar otro cliente? [S/N]: ", 168);
        eContinuar = LeerSN();
        
        if (eContinuar) {
            // Borrar área de entrada de datos
            for (i = 6; i <= 20; i++) {
                GoToXY(10, i);
                printf("                                                     ");
            }
        }
    }
}

int main() {
    AltaClientes();
    return 0;
}
