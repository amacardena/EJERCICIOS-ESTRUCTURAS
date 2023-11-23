/*
 ============================================================================
 Name        : EJ_ESTR_4.c
 Author      : Adrian Marín
 Version     :
 Copyright   : Your copyright notice
 Description : EJ_4 de 6. Mostrar las personas que cumplen años en el mes que nos de el usuario
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "librEstr.h"
int main(void) {
	personas4 lista[MAXPERS4];
	int n = 0, mes = 0;

	do {
		printf("\nIntroduce el numero de personas que quieres agregar (1 - %i) --> ", MAXPERS4);
		fflush(stdout); 		scanf("%i", &n);
	} while(n < 1 || n > MAXPERS4);

	pedirPers4(lista, n);
	mostrarPers4(lista,n);
	do {

		do {
			printf("\nIntroduce el mes (1-12) de las personas que cumplan anyos en el.");
			printf("\nEn caso de querer salir, introduzca 0 --> ");
			fflush(stdout); 		scanf("%i", &mes);
		} while (mes < 0 || mes > 12);

		if (mes != 0)
		{
			mostrarCumple(lista, n, mes);
		}
	} while (mes != 0);

	printf("\nAdios (:");
	return EXIT_SUCCESS;
}
