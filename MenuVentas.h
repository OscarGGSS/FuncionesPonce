#include "Tipos.h"
#include "SubMenuClientes.h"
#include "SubMenuVentas.h"
#include "ZInterfaz.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 

//Prototipos
void MenuVentas(TaVentas *, int *, TaClientes *, int *);

void MenuVentas(TaVentas *aVentas, int *eTotalVentas, TaClientes *aClientes, int *eTotalClientes) {
    
	int eOpcion;

    do {
    	
		Pantalla4();
        
        Centrar("SUBSISTEMA DE VENTAS", 2);
        Mensaje(10, 54, "1. Clientes");
        Mensaje(11, 54, "2. Ventas");
        Mensaje(12, 54, "0. Salir");

        Mensaje(16, 50, "Seleccione una opci%cn: ", 162);
        eOpcion = LeerEntero(16, 73, 1);

        switch (eOpcion) {
           
		    case 1: SubMenuClientes(*aClientes, eTotalClientes);
                	break;
            
			case 2: SubMenuVentas(aVentas, eTotalVentas);
                	break;
            
			case 0: Mensaje(26, 45, "Saliendo del programa...");
					break;
				
            default: Error(1);
                	 getch();
        }
        
    } while(eOpcion != 0);
}
