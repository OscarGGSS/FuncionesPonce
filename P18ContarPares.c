/* *********
   Programa: P18ContarPares.c
   Autor: Oscar Gonzalez
   Fecha: 08/05/2025
   Objetivo: Contar los pares de un arreglo usando recursividad
   Compilador: Dev-C++ 5.11
   Version 1.0
********* */

//Bibliotecas
#include <stdio.h>

//Constantes
#define MAX 5

//Tipos

typedef int TaNumeros[MAX];

//Prototipos

void LeerNumeros (TaNumeros);

int ContarPares(TaNumeros, int);

//Programa principal

int main(){
	
	//Variables
	TaNumeros aNumeros;
	
	printf("Programa que cuenta los pares de un arreglo con recursividad\n");
	
	LeerNumeros(aNumeros);
	
	printf("\nTotal de n%cmeros pares en el arreglo: %d", 163, ContarPares(aNumeros, 0));


	getchar();
	return 0;
}

void LeerNumeros (TaNumeros aNumeros){
	
	int eContador; 
	
	printf("Ingrese los valores del arreglo: \n");
	
	for(eContador = 0; eContador < MAX; eContador++){
		
		printf("N%cmero %d : ", 163, eContador + 1);
		scanf("%d", &aNumeros[eContador]);
		
	}
}

int ContarPares(TaNumeros aNumeros, int eCuenta){
	
	if(eCuenta > MAX - 1){
		
		return 0;
	}else if(aNumeros[eCuenta] % 2 == 0){
		
		return 1 + ContarPares(aNumeros, eCuenta + 1);
		
	}else{
		
		return 0 + ContarPares(aNumeros, eCuenta + 1);
	}
}
