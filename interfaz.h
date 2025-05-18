#include <windows.h> 


void Marco();
void Linea(int, int);
void GoToXY(int, int);
void Centrar(char *, int); 
void Mensaje(char *, int, int);

void Marco(){
	
	int eRen, eCol;
	
	system("color 3F");
	system("cls");
	
	printf("%c",218);
	
	Linea(2,115);
	printf("%c\n",191);
	for(eRen= 1; eRen <= 25; eRen++){
		
		GoToXY(eRen, 0);
		printf("%c",179);
		
		GoToXY(eRen, 115);
		printf("%c \n",179);
	}
	printf("%c",192);
	Linea (2,115);
 	printf("%c\n",217);
}
void Linea(int eColIni, int eColFin){
	int eCol;
	for(eCol = eColIni; eCol <= eColFin; eCol++){
		printf("%c",196);
 	}
}
void GoToXY(int eRen, int eCol){
	
	COORD coordenada;
	HANDLE salida = GetStdHandle(STD_OUTPUT_HANDLE);
	
	coordenada.X = eCol;
	coordenada.Y = eRen;
	
	SetConsoleCursorPosition(salida, coordenada);
}
void Centrar(char *sCadena , int eRenglon){
	
	Mensaje(sCadena , (100 - strlen(sCadena)) / 2, eRenglon);
	
}
void Mensaje(char *sTexto, int eRenglon, int eColumna){
	
	GoToXY( eColumna, eRenglon );
	printf(sTexto);
}

	

