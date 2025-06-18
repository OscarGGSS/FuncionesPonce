#include "MenuVentas.h"
#include <stdio.h>
#include <stdlib.h> 

//Programa Principal
int main() {
	
	TaVentas aVentas = {0}; 
    int eTotalVentas = 0;
	
    FILE *pArchivoVentas = fopen("ventas.dat", "rb");
    
    if (pArchivoVentas != NULL) {
    	
        fread(&eTotalVentas, sizeof(int), 1, pArchivoVentas);
        fread(aVentas, sizeof(TrVenta), eTotalVentas, pArchivoVentas);
        fclose(pArchivoVentas);
        
    } else {

        eTotalVentas = 0;
    }

    AjustarTamanoConsola(120, 30);
	system("cls");

    MenuVentas(&aVentas, &eTotalVentas);

    pArchivoVentas = fopen("ventas.dat", "wb");
    
    return 0;

}
