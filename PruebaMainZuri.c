#include "MenuVentas.h"
#include <stdio.h>
#include <stdlib.h> 

//Programa Principal
int main() {
	
	TaVentas aVentas = {0};
	TaClientes aClientes = {0};
    int eTotalVentas = 0;
    int eTotalClientes = -1;
	
	CargarClientes(aClientes, &eTotalClientes);

    CargarVentas(aVentas, &eTotalVentas);

    AjustarTamanoConsola(120, 30);
	system("cls");

    MenuVentas(&aVentas, &eTotalVentas, &aClientes, &eTotalClientes);
    
    return 0;

}
