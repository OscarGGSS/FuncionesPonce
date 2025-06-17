#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdarg.h>


void GoToXY(int eRen, int eCol){
	
    COORD coordenada;
    HANDLE salida = GetStdHandle(STD_OUTPUT_HANDLE);
    
    coordenada.X = eCol;
    coordenada.Y = eRen;
    
    SetConsoleCursorPosition(salida, coordenada);
    
}

void Linea(int eColIni, int eColFin){
	
    int eCol;
    
    for(eCol = eColIni; eCol <= eColFin; eCol++){
        
		printf("%c", 196);
    
    }
}

void MarcoPantalla(){
	
    int eRen;
    
    system("color 3F");
	system("cls");
    
    printf("%c", 218);
    
    Linea(2, 115);
    
	printf("%c\n", 191);
    
	for(eRen = 1; eRen <= 25; eRen++){
        
		GoToXY(eRen, 0);
		printf("%c", 179);
        
		GoToXY(eRen, 115);
		printf("%c", 179);
    
	}
    
    GoToXY(25, 0);
    printf("%c", 192);
    
    Linea(2,115);
    
    printf("%c\n", 217);
}

void Marco(int eRenIni, int eColIni, int eRenFin, int eColFin){
    
    int eRen, col;
    
    GoToXY(eRenIni, eColIni);
    printf("%c", 218);


    for (col = eColIni + 1; col < eColFin; col++){
        GoToXY(eRenIni, col);
        printf("%c", 196); 
    }

    GoToXY(eRenIni, eColFin);
    printf("%c", 191);
    
    for (eRen = eRenIni + 1; eRen < eRenFin; eRen++){
        GoToXY(eRen, eColIni);
        printf("%c", 179);
        
        GoToXY(eRen, eColFin);
        printf("%c", 179);
    }
    
    GoToXY(eRenFin, eColIni);
    printf("%c", 192);

    for (col = eColIni + 1; col < eColFin; col++){
        GoToXY(eRenFin, col);
        printf("%c", 196);
    }
    
    GoToXY(eRenFin, eColFin);
    printf("%c", 217);
    
}

void Mensaje(int eRenglon, int eColumna, const char *pFormato, ...){ //const pa que no cambie el txt
	
    GoToXY(eRenglon, eColumna);
    va_list args;
    va_start(args, pFormato);
    vprintf(pFormato, args);
    va_end(args);
    
}

void Centrar(char *sCadena , int eRenglon){
	
	int eCol;
	
    eCol = (120 - (int)strlen(sCadena)) / 2;
    
    Mensaje(eRenglon, eCol, "%s", sCadena);
    
}

void AjustarTamanoConsola(int ancho, int alto) {
	
    HANDLE hConsola = GetStdHandle(STD_OUTPUT_HANDLE);
    
    COORD tamBuffer;
    tamBuffer.X = ancho;
    tamBuffer.Y = alto;
    SetConsoleScreenBufferSize(hConsola, tamBuffer);

    SMALL_RECT tamanoVentana;
    tamanoVentana.Left = 0;
    tamanoVentana.Top = 0;
    tamanoVentana.Right = ancho - 1;
    tamanoVentana.Bottom = alto - 1;
    SetConsoleWindowInfo(hConsola, TRUE, &tamanoVentana);
}

void DibujarTabla(int eRenIni, int eColIni, int eRenglones, int eColumnas, int eAnchoCelda){
    
    int eRecorreRen, eRecorreCol, eContador;

    GoToXY(eRenIni, eColIni);
    
	printf("%c", 218);

    for(eRecorreCol = 0; eRecorreCol < eColumnas; eRecorreCol++){
    	
        for(eContador = 0; eContador < eAnchoCelda; eContador++){
		
			printf("%c", 196);
        
    	}
    	
        if(eRecorreCol == eColumnas - 1){
	
            printf("%c", 191);
        
        } else{
        	
            printf("%c", 194);
            
    	}
    }

    for(eRecorreRen = 0; eRecorreRen < eRenglones; eRecorreRen++){

        GoToXY(eRenIni + 1 + eRecorreRen * 2, eColIni);
        printf("%c", 179);
        
        for(eRecorreCol = 0; eRecorreCol < eColumnas; eRecorreCol++){
        	
            for(eContador = 0; eContador < eAnchoCelda; eContador++){
			
				printf(" ");
				
			}
			
            printf("%c", 179);
        }

        if(eRecorreRen < eRenglones - 1){
        	
            GoToXY(eRenIni + 2 + eRecorreRen * 2, eColIni);
            printf("%c", 195);
            
            for(eRecorreCol = 0; eRecorreCol < eColumnas; eRecorreCol++){
            	
                for(eContador = 0; eContador < eAnchoCelda; eContador++){
				
					printf("%c", 196);
				
				}
				
                if(eRecorreCol == eColumnas - 1){
			
                    printf("%c", 180);
                    
            	} else {
            		
                    printf("%c", 197);
                    
            	}
            }
        }
    }

    GoToXY(eRenIni + eRenglones * 2, eColIni);
    printf("%c", 192);
    
    for(eRecorreCol = 0; eRecorreCol < eColumnas; eRecorreCol++){
    	
        for(eContador = 0; eContador < eAnchoCelda; eContador++){
        	
			printf("%c", 196);
			
		}
        
		if(eRecorreCol == eColumnas -1){
		
            printf("%c", 217);
            
        } else {

            printf("%c", 193);
            
    	}
    }
}
