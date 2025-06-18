//Bibliotecas
#include <stdio.h>
#include <stdlib.h> 
#include "ZInterfaz.h"
#include <conio.h>
#include "ZFunciones.h"

//prototipos
void SubMenuClientes(TaClientes, int *);
void ConsultarCliente(TaClientes, int);
void ModificarCliente(TaClientes, int *);
int BuscarCliente(TaClientes, int, int);
void ActualizarArchivoClientes(TaClientes, int);
void BorrarCliente(TaClientes, int *);
void InsertarCliente(TaClientes, int *, TrCliente);
TrCliente LeerCliente(int eGenerarId);
void GuardarClienteEnArchivo(TrCliente);
void ListarClientes();


void SubMenuClientes(TaClientes aClientes, int *eTotalClientes) {
	
    int eOpcion, eId;
	TrCliente rCliente, rClienteNuevo;
	
    do {
    	
        Pantalla4();
        Centrar("CLIENTES", 2);

        Mensaje(9, 49, "1. Registrar cliente");
        Mensaje(10, 49, "2. Borrar cliente");
        Mensaje(11, 49, "3. Modificar cliente");
        Mensaje(12, 49, "4. Consultar cliente (ID)");
        Mensaje(13, 49, "5. Listar clientes");
        Mensaje(14, 49, "0. Regresar");

        Mensaje(16, 50, "Seleccione una opci%cn: ", 162);
        eOpcion = LeerEntero(16, 73, 1);

        switch (eOpcion) {

            case 1:
            	
            	rCliente = LeerCliente(1);
                InsertarCliente(aClientes, eTotalClientes, rCliente);
                getch();
                break;

            case 2:
                BorrarCliente(aClientes, eTotalClientes);
				getch();
    			break;

            case 3:
                ModificarCliente(aClientes, eTotalClientes);
                getch();
                break;

            case 4:
                ConsultarCliente(aClientes, *eTotalClientes);
                getch();
                break;

            case 5:
                ListarClientes(aClientes, *eTotalClientes);
                getch();
                break;

            case 0:
                break;

            default:
                Error(1); // Opción no válida
                getch();
        }

    } while (eOpcion != 0);
}

int CargarClientes(TaClientes aClientes, int *eTotalClientes) {
    FILE *pArchivo = fopen("clientes.txt", "r");
    if (pArchivo == NULL) {
        *eTotalClientes = -1;
        return 0; // no archivo, nada que cargar
    }

    int i = -1;
    while (!feof(pArchivo) && i < MAX_CLIENTES - 1) {
        TrCliente rCliente;
        // Leer línea con formato: ID|Nombre|Telefono|Direccion|Correo|Activo
        int leidos = fscanf(pArchivo, "%d|%39[^|]|%19[^|]|%49[^|]|%29[^|]|%d\n",
                            &rCliente.eIdCliente,
                            rCliente.sNombre,
                            rCliente.sTelefono,
                            rCliente.sDireccion,
                            rCliente.sCorreo,
                            &rCliente.eActivo);
        if (leidos == 6) {
            i++;
            aClientes[i] = rCliente;
        } else {
            break;
        }
    }

    fclose(pArchivo);
    *eTotalClientes = i;
    return i >= 0;
}

void GuardarClienteEnArchivo(TrCliente rCliente) {
    FILE *pArchivo = fopen("clientes.txt", "a"); // modo texto, agregar al final

    if (pArchivo != NULL) {
        fprintf(pArchivo, "%d|%s|%s|%s|%s\n",
            rCliente.eIdCliente,
            rCliente.sNombre,
            rCliente.sTelefono,
            rCliente.sDireccion,
            rCliente.sCorreo);
        fclose(pArchivo);
    } else {
        Mensaje(22, 10, "No se pudo abrir el archivo para guardar");
    }
}

TrCliente LeerCliente(int eGenerarId) {
    TrCliente rCliente;

    if (eGenerarId) {
        // Generar ID automático, por ejemplo 0 o algún valor temporal
        rCliente.eIdCliente = 0; // O algún valor placeholder
    } else {
        // No genera ID, se deja sin asignar (o 0)
        rCliente.eIdCliente = 0;
    }

    Mensaje(5, 10, "Nombre:");
    LeerCadena(5, 20, rCliente.sNombre, 40);

    Mensaje(7, 10, "Teléfono:");
    LeerCadena(7, 20, rCliente.sTelefono, 20);

    Mensaje(9, 10, "Dirección:");
    LeerCadena(9, 20, rCliente.sDireccion, 50);

    Mensaje(11, 10, "Correo:");
    LeerCadena(11, 20, rCliente.sCorreo, 30);

    return rCliente;
}

void InsertarCliente(TaClientes aClientes, int *eTotal, TrCliente rCliente) {
    
	int eNuevoId;
	
	rCliente.eActivo = 1;
	
    if (*eTotal == MAX_CLIENTES - 1) {
        Mensaje(20, 10, "No hay espacio en el arreglo");
        return;
    }

    FILE *pId = fopen("ultimoidcliente.txt", "r+");
int eUltimoId = 0;
if (pId != NULL) {
    fscanf(pId, "%d", &eUltimoId);
    rewind(pId);
    eUltimoId++;
    fprintf(pId, "%d", eUltimoId);
    fclose(pId);
} else {
    // Si no existe el archivo, crear y poner ID = 1
    pId = fopen("ultimoidcliente.txt", "w");
    eUltimoId = 1;
    fprintf(pId, "%d", eUltimoId);
    fclose(pId);
}

    rCliente.eIdCliente = eUltimoId;

    // Insertar en el arreglo
    (*eTotal)++;
    aClientes[*eTotal] = rCliente;

    // ? Solo se llama
    GuardarClienteEnArchivo(rCliente);

    Mensaje(21, 10, "Cliente con ID %d agregado y guardado correctamente.", rCliente.eIdCliente);
}

void BorrarCliente(TaClientes aClientes, int *eTotal) {
    
	int eId, ePos;

    AjustarTamanoConsola(120, 30);
    MarcoPantalla();
    Marco(3, 5, 22, 110);

    if (*eTotal == -1) {
        Mensaje(10, 10, "No hay clientes registrados.");
        getch();
        return;
    }

    Mensaje(8, 10, "Ingrese el ID del cliente a borrar:");
    eId = LeerEntero(8, 45, 1);

    ePos = BuscarCliente(aClientes, *eTotal, eId);

    if (ePos == -1) {
        Mensaje(10, 10, "El cliente con ID %d no existe", eId);
    } else {
        if (aClientes[ePos].eActivo == 0) {
            Mensaje(10, 10, "El cliente con ID %d ya está borrado.", eId);
        } else {
            aClientes[ePos].eActivo = 0;  // Borrado simbólico
            ActualizarArchivoClientes(aClientes, *eTotal);
            Mensaje(12, 10, "Cliente con ID %d borrado simbólicamente.", eId);
        }
    }

    getch();
}

void ActualizarArchivoClientes(TaClientes aClientes, int eTotal) {
    int i;
    FILE *pArchivo = fopen("clientes.txt", "w");

    if (pArchivo != NULL) {
        for (i = 0; i <= eTotal; i++) {
            fprintf(pArchivo, "%d|%s|%s|%s|%s|%d\n",
                aClientes[i].eIdCliente,
                aClientes[i].sNombre,
                aClientes[i].sTelefono,
                aClientes[i].sDireccion,
                aClientes[i].sCorreo,
                aClientes[i].eActivo);
        }
        fclose(pArchivo);
    }
}

int BuscarCliente(TaClientes aClientes, int eTotal, int eId) {
    int eMenor, eMayor, eMedio;

    if (eTotal == -1) {
        return -1;
    } else {
        eMenor = 0;
        eMayor = eTotal;
        eMedio = eTotal / 2;

        while (eMayor >= eMenor && eId != aClientes[eMedio].eIdCliente) {
            if (eId < aClientes[eMedio].eIdCliente) {
                eMayor = eMedio - 1;
            } else {
                eMenor = eMedio + 1;
            }

            eMedio = (eMenor + eMayor) / 2;
        }

        if (eMayor < eMenor) {
            return -1;
        } else {
            return eMedio;
        }
    }
}

void ModificarCliente(TaClientes aClientes, int *eTotal) {
    int eId, ePos;
    TrCliente rNuevo;

    AjustarTamanoConsola(120, 30);
    MarcoPantalla();
    Marco(3, 5, 22, 110);

    if (*eTotal == -1) {
        Mensaje(10, 10, "No hay clientes registrados.");
        getch();
        return;
    }

    Mensaje(8, 10, "Ingrese el ID del cliente a modificar:");
    eId = LeerEntero(8, 48, 1);

    ePos = BuscarCliente(aClientes, *eTotal, eId);
	
    
if (aClientes[ePos].eActivo == 0) {
    Mensaje(10, 10, "El cliente con ID %d está borrado y no se puede modificar.", eId);
    getch();
    return;
}

if (ePos == -1) {
    Mensaje(10, 10, "El cliente con ID %d no existe.", eId);
    getch();
    return;
}

    // Leer nuevos datos
    rNuevo = LeerCliente(0);
	rNuevo.eIdCliente = eId;  // conservar ID original

    // Reemplazar directamente
    aClientes[ePos] = rNuevo;

    // Actualizar archivo
    ActualizarArchivoClientes(aClientes, *eTotal);

    Mensaje(12, 10, "Cliente con ID %d modificado correctamente.", eId);
    getch();
}

void ConsultarCliente(TaClientes aClientes, int eTotal) {
    int eId;

    AjustarTamanoConsola(120, 30);
    MarcoPantalla();
    Marco(3, 5, 22, 110);

    if (eTotal == -1) {
        Mensaje(10, 10, "No hay clientes registrados.");
        getch();
        return;
    }

    Mensaje(8, 10, "Ingrese el ID del cliente a consultar:");
    eId = LeerEntero(8, 48, 1);

    int ePos = BuscarCliente(aClientes, eTotal, eId);

    if (ePos == -1) {
    	
        Mensaje(12, 10, "El cliente con ID %d no existe.", eId);
        
    } else {
        Mensaje(7, 10, "ID: %d", aClientes[ePos].eIdCliente);
        Mensaje(8, 10, "Nombre: %s", aClientes[ePos].sNombre);
        Mensaje(9, 10, "Teléfono: %s", aClientes[ePos].sTelefono);
        Mensaje(10, 10, "Dirección: %s", aClientes[ePos].sDireccion);
        Mensaje(11, 10, "Correo: %s", aClientes[ePos].sCorreo);
    }

    getch();
}

void ListarClientes(TaClientes aClientes, int eTotal) {
    int i;

    MarcoPantalla();
    Marco(2, 3, 18, 75);

    printf("\n%5s | %-40s\n", "ID", "NOMBRE");
    printf("----------------------------------------------\n");

    for (i = 0; i <= eTotal; i++) {
        if (aClientes[i].eActivo == 1) {  // Solo mostrar activos
            printf("%5d | %-40s\n", aClientes[i].eIdCliente, aClientes[i].sNombre);
        }
    }

    printf("\nPresiona una tecla para continuar...");
    getch();
}


