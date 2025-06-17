/* ***
   Programa: Disenadores.c
   Autor: Oscar Gonzalez
   Fecha: 27-Mayo.2025
   Objetivo:
   Compilador: Dev-C++ 5.11
   Versión: 1.0
*** */

//Bibliotecas
#include <stdio.h>
#include <string.h>
#include "FuncionesZPrueba.h"

//Constantes 
#define MAX 50

//Tipo


typedef struct rDiseno {
	
	int eId;
	char sNombre [40];
	int ePrecio;
	
} TrDiseno;

typedef TrDiseno TaDisenos [MAX];

//Prototipos 

void MenuPrincipal(TaDisenos aDisenos, int *eTotal);
void InsertarDiseno(TaDisenos, int *, TrDiseno);
void BorrarDiseno(TaDisenos, int *, int);
int BuscarDiseno(TaDisenos, int, int);
void ConsultarDiseno(TaDisenos aDisenos, int eTotal, int eId);
void ModificarDiseno(TaDisenos, int, int, TrDiseno);
TrDiseno LeerDiseno(int);
void GuardarEnArchivo(TaDisenos aDisenos, int eTotal);
void LeerDesdeArchivo(TaDisenos aDisenos, int *eTotal);

//Programa principal

int main (){
	
    // Variables
    TaDisenos aDisenos;
    int eTotal = -1;

    // Leer los dise�adores desde archivo si existe
    LeerDesdeArchivo(aDisenos, &eTotal);

    // Interfaz gr�fica
    AjustarTamanoConsola(120, 30);
    MarcoPantalla();
    Marco(3, 5, 22, 110);

    // Llamar al men� principal
    MenuPrincipal(aDisenos, &eTotal);
	
	getchar();
    return 0;
}



void MenuPrincipal(TaDisenos aDisenos, int *eTotal) {
    int eOpcion, eId;
    TrDiseno rDiseno;

    do {
    	
    	// Limpia la pantalla y redibuja marco
        system("cls");
        AjustarTamanoConsola(120, 30);
        MarcoPantalla();
        Marco(3, 5, 22, 110);
        
        Mensaje(4, 10, "Programa de dise%co", 164);
        Mensaje(5, 10, "1. Agregar Dise%co.", 164);
        Mensaje(6, 10, "2. Borrar Dise%co.", 164);
        Mensaje(7, 10, "3. Modificar datos de Dise%co.", 164);
        Mensaje(8, 10, "4. Mostrar Dise%co.", 164);
        Mensaje(9, 10, "0. Salir");
        Mensaje(20, 10, "Recuerda que para guardar debes salir.");
        Mensaje(10, 10, "Elija una opci%cn: ", 162);
        scanf("%d", &eOpcion);
        
   

        switch (eOpcion) {
            case 1:
                system("cls");
                rDiseno = LeerDiseno(1);
                InsertarDiseno(aDisenos, eTotal, rDiseno);
                break;

            case 2:
                Mensaje(15, 10, "Ingrese el id a borrar: ");
                scanf("%d", &eId);
                BorrarDiseno(aDisenos, eTotal, eId);
                break;

            case 3:
                Mensaje(10, 10, "Ingrese el id a modificar: ");
                scanf("%d", &eId);
                rDiseno = LeerDiseno(0);
                ModificarDiseno(aDisenos, *eTotal, eId, rDiseno);
                break;

            case 4:
                system("cls");
                AjustarTamanoConsola(120, 30);
                MarcoPantalla();
                Marco(3, 5, 22, 110);
                Mensaje(10, 10, "Ingrese el ID para consultar: ");
                scanf("%d", &eId);
                ConsultarDiseno(aDisenos, *eTotal, eId);
                break;

            case 0:
                GuardarEnArchivo(aDisenos, *eTotal);
                printf("Adi%cs\n", 162);
                break;

            default:
                printf("Opci%cn no v%clida\n", 162, 160);
        }

        fflush(stdin);
        getchar();

    } while (eOpcion != 0);
}


void InsertarDiseno(TaDisenos aDisenos, int *eTotal, TrDiseno rDiseno){
    int ePos, eRecorre;

    if (*eTotal == MAX - 1){
        Mensaje(20, 10, "No hay espacio en el arreglo");
    } 
    else if (*eTotal == -1 || rDiseno.eId > aDisenos[*eTotal].eId){
        (*eTotal)++;
        aDisenos[*eTotal] = rDiseno;

        Mensaje(21, 10, "Dise%co con ID %d agregado correctamente.", 164, rDiseno.eId);
    } 
    else {
        ePos = BuscarDiseno(aDisenos, *eTotal, rDiseno.eId);

        if (ePos != -1){
            Mensaje(20, 10, "El dise%co: %d ya existe", 164, rDiseno.eId);
        } 
        else {
            eRecorre = *eTotal;

            while (eRecorre >= 0 && rDiseno.eId < aDisenos[eRecorre].eId){
                aDisenos[eRecorre + 1] = aDisenos[eRecorre];
                eRecorre--;
            }

            aDisenos[eRecorre + 1] = rDiseno;
            (*eTotal)++;

            Mensaje(10, 10, "Dise%co con ID %d agregado correctamente.  Presiona enter para continuar.", 164, rDiseno.eId);
        }
    }
}


void BorrarDiseno(TaDisenos aDisenos, int *eTotal, int eId){
	
	//Variables 
	
	int ePos, eRecorre;
	
	//Marco
	AjustarTamanoConsola(120, 30);
    MarcoPantalla();
    Marco(3, 5, 22, 110);
    
	
	if (*eTotal == -1){
		
		Mensaje(20, 10, "El arreglo est%c vac%co", 160, 161);
		
	} else {
		
		ePos = BuscarDiseno(aDisenos, *eTotal, eId);
		
		if (ePos == -1){
		
			Mensaje(20, 10, "El dise%co: %d no existe", 164,  eId);
		
		} else {
		
			for (eRecorre = ePos; eRecorre <= *eTotal -1; eRecorre ++){
			
				aDisenos[eRecorre] = aDisenos[eRecorre + 1];
				
			}
		
			(*eTotal)--;
			
			Mensaje(10, 10, "Dise%co con ID %d borrado correctamente.  Presiona enter para continuar.", 164, eId);
			
		}
		
	}
	
}

int BuscarDiseno (TaDisenos aDisenos, int eTotal, int eId){
	
	//Varaibles 
	
	int eMenor, eMayor, eMedio;
	
	if (eTotal == -1){
		
		return -1;
		
	} else {
		
		eMenor = 0;
		eMayor = eTotal;
		eMedio = eTotal / 2; 
		
	
		while (eMayor >= eMenor && eId != aDisenos[eMedio].eId){
	 	
	 		if (eId < aDisenos[eMedio].eId){
	 			
	 			eMayor = eMedio - 1;
	 		
			} else {
		 	
			 	eMenor = eMedio + 1;
		 	
			}
		 
		 	eMedio = (eMenor + eMayor) / 2;
	 	
		} 
	 
	 	if (eMayor < eMenor){
	 	
	 		return -1;
	 	
	 	} else {
	 	
	 		return eMedio;
	 	
	 	}
	 	
	}
	
} //BuscarDiseñador

void ConsultarDiseno(TaDisenos aDisenos, int eTotal, int eId){
	
	//Variables 
	int ePos;
	
	
	AjustarTamanoConsola(120, 30);
    MarcoPantalla();
    Marco(3, 5, 22, 110);
	
	if (eTotal == -1){
		
		printf("No existe el id: %d");
		
	} else{
	 	
		ePos = BuscarDiseno(aDisenos, eTotal, eId);
	
		if(ePos == -1){
			
			printf("No existe el ID: %d", ePos);
			
			return;
			
		}else{
			
			
			Mensaje(7, 10, "ID: %d", aDisenos[ePos].eId);
			Mensaje(8, 10, "Nombre: %s", aDisenos[ePos].sNombre);
			Mensaje(9, 10, "Precio: $%d", aDisenos[ePos].ePrecio);
			
		}
		
		
	}
	
	
	
}

void ModificarDiseno(TaDisenos aDisenos, int eTotal, int eId, TrDiseno rDisenadorNuevo){
    int ePos = BuscarDiseno(aDisenos, eTotal, eId);

    if (ePos != -1){
        BorrarDiseno(aDisenos, &eTotal, eId);
        rDisenadorNuevo.eId = eId;
        InsertarDiseno(aDisenos, &eTotal, rDisenadorNuevo);
        // Quita el mensaje y pausa aqu�
    } else {
        Mensaje(10, 10, "El dise%cador con ID %d no existe.", 164, eId);

    }
}


TrDiseno LeerDiseno(int leeId){
	
	//Variables 
	TrDiseno rDiseno;
	int eCalif;
	
	AjustarTamanoConsola(120, 30);
    MarcoPantalla();
    Marco(3, 5, 22, 110);
	
	Mensaje(4, 10,"Ingrese los siguientes datos del Dise%cador: ", 164);
	
	if (leeId){
		
		Mensaje(5, 10, "Id: ");
		scanf("%d", &rDiseno.eId);
	}
	
	Mensaje(6, 10, "Ingrese el nombre: ");
	fflush(stdin);
	gets(rDiseno.sNombre);

	Mensaje(7, 10, "Ingrese el precio del dise%co: $", 164);
	scanf("%d", &rDiseno.ePrecio);
	
	return rDiseno;
	
	
	
}

void GuardarEnArchivo(TaDisenos aDisenos, int eTotal) {
	
	int i;
	
    FILE *archivo = fopen("Disenos.txt", "w");
    
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para guardar.\n");
        return;
    }

    for (i = 0; i <= eTotal; i++) {
        fprintf(archivo, "%d|%s|%d\n",
            aDisenos[i].eId,
            aDisenos[i].sNombre,
            aDisenos[i].ePrecio
        );
    }

    fclose(archivo);
    Centrar("Datos guardados correctamente ", 4);
}


void LeerDesdeArchivo(TaDisenos aDisenos, int *eTotal) {
    FILE *archivo = fopen("Disenos.txt", "r");
    TrDiseno r;
    *eTotal = -1;

    if (archivo == NULL) return;

    while (fscanf(archivo, "%d|%[^|]|%d\n", &r.eId, r.sNombre, &r.ePrecio) == 3) {
        (*eTotal)++;
        aDisenos[*eTotal] = r;
    }

    fclose(archivo);
}




