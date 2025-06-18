#ifndef ZFUNCIONES_H
#define ZFUNCIONES_H

#include <stdio.h>
#include <windows.h>
#include "ZInterfaz.h"
#include <conio.h>
#include "Tipos.h"
#include <string.h>

//Prototipos

	
void Error(int eCodigoError) {
	
    char cMensaje[100];

    switch (eCodigoError) {
        
		case 1: sprintf(cMensaje, "Error. Opci%cn no v%clida. Pulse una tecla para continuar ...", 162, 160);
				break;
            
        case 2: sprintf(cMensaje, "Error al guardar ventas en archivo.");
				break;
            
        case 3: sprintf(cMensaje, "Error. No hay espacio para registrar ventas. Pulse una tecla para continuar ...");
				break;
            
        case 4: sprintf(cMensaje, "Error. El ID no es v%clido. Pulse una tecla para continuar ...", 160);
            	break;
        
		case 5: sprintf(cMensaje, "Error. No se encontr%c el cliente. Pulse una tecla para continuar ...", 162);
				break;
				
        case 6: sprintf(cMensaje, "Error. Entrada no v%clida.", 160);
				break;
            
        case 7: sprintf(cMensaje, "Error. El d%ca no es v%clido.", 161, 160);
				break;
            
        case 8: sprintf(cMensaje, "Error. El mes no es v%clido.", 160); 
          		break;
            
        case 9: sprintf(cMensaje, "Error. El a%co no es v%clido.", 164, 160); 
            	break;
            	
        case 10: sprintf(cMensaje, "Error. El d%ca no es v%clido para esta fecha.", 161, 160); 
            	 break;
            
        case 11: sprintf(cMensaje, "Error. El insumo no existe.");
            	 break;
            	 
        case 12: sprintf(cMensaje, "Error. El dise%co no existe.", 164);
            	 break;
            	 
        case 13: sprintf(cMensaje, "Error. S%clo se permite 's' y 'n'.", 162);
            	 break;
            	 
        case 14: sprintf(cMensaje, "Error.");
            	 break;
            	 
        case 15: sprintf(cMensaje, "Error. La fecha inicial debe ser < o = a la final.");
            	 break;
				     	
        default:
            sprintf(cMensaje, "Error desconocido.");
            break;
    }

    Centrar(cMensaje, 26);
    Beep(1000, 300);
}


int LeerEntero(int eRenglon, int eColumna, int eError) {
	
    int eValor;
    char cFin;

    while (1) {
    	
        if (scanf("%d%c", &eValor, &cFin) == 2 && cFin == '\n') {
        	
            return eValor;
            
        }

        Error(eError);
        fflush(stdin);
        getch();
		BorrarZona(26, 20, 2, 80);
        //GoToXY(eRenglon, eColumna);
        BorrarZona(eRenglon, eColumna, 1, 30);
        GoToXY(eRenglon, eColumna);
        
    }
    
} //LeerEntero




int ValidarEntero(char *cTexto) {
    
	int eContador;
	
	eContador = 0;
    
	if (cTexto[0] == '-'){
		
		eContador = 1;
		
	} else {

    	for (; cTexto[eContador] != '\0'; eContador++) {
    	
        	if (!isdigit(cTexto[eContador])) {
        	
            	return 0;

        	}
    	}
    
	}

    return (eContador > 0);
}







int ValidarBisiesto(int eAnio) {
    
	if (eAnio % 4 == 0 && eAnio % 100 != 0) {
        
		return 1;
    
	}

    if (eAnio % 400 == 0) {
        
		return 1;
    
	}

    return 0;
}





int DiasDelMes(int eMes, int eAnio) {
    
    int eDias;

    if (eMes == 1 || eMes == 3 || eMes == 5 || eMes == 7 || eMes == 8 || eMes == 10 || eMes == 12) {
        
        eDias = 31;

    } else if (eMes == 4 || eMes == 6 || eMes == 9 || eMes == 11) {
        
        eDias = 30;

    } else if (eMes == 2) {
        
        if (ValidarBisiesto(eAnio) == 1) {
           
		    eDias = 29;
        
		} else {
            
			eDias = 28;
			
        }

    } else {
        
        eDias = 0;

    }

    return eDias;
}



//dividir
TrFecha LeerFecha(int eRen, int eCol) {
	
    TrFecha rFecha;
    int eDiasMax;

    do {

		BorrarZona(eRen, eCol + 5, 1, 15);
        BorrarZona(26, 20, 1, 80);
        
		Mensaje(eRen, eCol, "D%ca: ", 161);
		GoToXY(eRen, eCol + 5);
		
		if (scanf("%d", &rFecha.eDia) != 1) { //que no quede vacío o se ingrese algo q no sea entero
            
			Error(6); //Error (entrada no válida)
			getch();
            fflush(stdin);
			rFecha.eDia = 0;
            continue;
            
        }

        if (rFecha.eDia < 1 || rFecha.eDia > 31) {  // validación día entre 1-31
            
            Error(7);
            getch();
            
        }
        
    } while (rFecha.eDia < 1 || rFecha.eDia > 31);

    do {
    	    
		BorrarZona(eRen + 1, eCol + 5, 1, 15);
        BorrarZona(26, 20, 1, 80);
        
		Mensaje(eRen + 1, eCol, "Mes:");
		GoToXY(eRen + 1, eCol + 5);
		
        if (scanf("%d", &rFecha.eMes) != 1) {
        	
            Error(6);  //Error (entrada no válida)
            getch();
            fflush(stdin);
            rFecha.eMes = 0;
            continue;
            
        }

        if (rFecha.eMes < 1 || rFecha.eMes > 12) { // validación mes entre 1-12
            
			BorrarZona(26, 20, 1, 80);
			Error(8);
			getch();
			
        }
        
    } while (rFecha.eMes < 1 || rFecha.eMes > 12);

    do {
    	
    	BorrarZona(eRen + 2, eCol + 5, 1, 15);
        BorrarZona(26, 20, 1, 80);
        
		Mensaje(eRen + 2, eCol, "A%co:", 164);
		GoToXY(eRen + 2, eCol + 5);
        
        if (scanf("%d", &rFecha.eAnio) != 1) {
        	
            Error(6);
            fflush(stdin);
            getch();
            rFecha.eAnio = 0;
            continue;
            
        }

        if (rFecha.eAnio < 2020 || rFecha.eAnio > 2100) {
        	
            Error(9);
            getch();
            
        }
        
    } while (rFecha.eAnio < 2020 || rFecha.eAnio > 2100);

    eDiasMax = DiasDelMes(rFecha.eMes, rFecha.eAnio);
    
    if (rFecha.eDia > eDiasMax) {
    	
    	Error(10);
    	getch();
        
        do {
        	
            BorrarZona(eRen, eCol + 5, 1, 15);
        	BorrarZona(26, 20, 1, 80);

			GoToXY(eRen, eCol + 5);
            
            if (scanf("%d", &rFecha.eDia) != 1) {
            	
                Error(6);
                getch();
                fflush(stdin);
                rFecha.eDia = 0;
                continue;
                
            }

            if (rFecha.eDia < 1 || rFecha.eDia > eDiasMax) {
            	
                Error(7);
                getch();
                
            }
            
        } while (rFecha.eDia < 1 || rFecha.eDia > eDiasMax);
    }

    return rFecha;
}



int LeerEnteroEnRango(int eRen, int eCol, int eMin, int eMax){
	
    int eValor;
    
    do {
    	
		BorrarZona(26, 20, 1, 80);
    	BorrarZona(eRen, eCol, 1, 20);
    	
    	GoToXY(eRen, eCol);
        eValor = LeerEntero(eRen, eCol, 6);
        
        if (eValor < eMin || eValor > eMax) {
        	
            Error(6);
            getch();
            
        }
        
    } while (eValor < eMin || eValor > eMax);
    
    return eValor;
}


char LeerCaracter(int eRenglon, int eColumna) {
	
    char cCaracter, cFin;

    while (1) {
        
        BorrarZona(eRenglon, eColumna, 1, 45);
        
        GoToXY(eRenglon, eColumna);

        if (scanf(" %c%c", &cCaracter, &cFin) == 2 && cFin == '\n') {
            
			return cCaracter;
			
        } else {

	        Error(14);
	        fflush(stdin);
	        getch();
    	
		}	
	}
}


int LeerSN(int eRen, int eCol, char *sMensaje) {
	
    char cRespuesta;
    
    while (1) {
        
        Mensaje(eRen, eCol, sMensaje);
        
        cRespuesta = LeerCaracter(eRen, eCol + 31);
        
        if (cRespuesta == 'S' || cRespuesta == 's') {
        	
            return 1;
            
        } else if (cRespuesta == 'N' || cRespuesta == 'n') {
        	
            return 0;
            
        } else {

            Error(13);
            getch();  
           
        }
    }
}

void LeerCadena(int fila, int columna, char *cadena, int longitudMax) {

    printf("Ingrese texto: ");
    fgets(cadena, longitudMax, stdin);
    
	size_t len = strlen(cadena);
    
	if(len > 0 && cadena[len-1] == '\n') {
        
		cadena[len-1] = '\0';
    }
}

#endif
