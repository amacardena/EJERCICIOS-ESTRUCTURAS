/*
 ============================================================================
 Name        : EJ_ESTR_5.c
 Author      : Adrián Marín
 Version     :
 Copyright   : Your copyright notice
 Description : EJ_5 de 6. Introducir personas hasta que el nombre sea blanco
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "librEstr.h"

int main(void) {

	persEj5 lista[MAXEJ5];
	int i = 0;

	do {
		fflush(stdin);
		printf("\nIntroduce la persona numero %i de %i. (Pulse solo intro si quiere salir) --> ", i+1, MAXEJ5);
		fflush(stdout); fgets(lista[i].nombre, MAXNOMBRE,stdin);
		lista[i].nombre[strlen(lista[i].nombre)-1] = '\0';

		if(strlen(lista[i].nombre) > 0)
		{
			printf("\nIntroduce la direccion de %s --> ", lista[i].nombre);
			fflush(stdout);	fgets(lista[i].direccion, MAXNOMBRE,stdin);

			printf("\nIntroduce el telefono de %s --> ", lista[i].nombre);
			fflush(stdout); scanf("%i", &lista[i].telefono);

			printf("\nIntroduce la edad de %s --> ", lista[i].nombre);
			fflush(stdout); scanf("%i", &lista[i].edad);
			i++;
		}
		else break;

	} while(i < MAXEJ5);

	printf("\nAdios (:");
	return EXIT_SUCCESS;
}
