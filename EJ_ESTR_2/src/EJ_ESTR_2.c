/*
 ============================================================================
 Name        : EJ_ESTR_2.c
 Author      : Adrián Marín
 Version     :
 Copyright   : Your copyright notice
 Description : EJ_2 de 6. Multiplicar y dividir fracciones
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "librEstr.h"

int main(void) {
	fraccion f1, f2;
	int menu = -1;
	float resultadoN, resultadoD;

	puts("Primera fraccion:");

	pedirFraccion(&f1);
	mostrarFraccion(f1);

	puts("\n\nSegunda fraccion:");

	pedirFraccion(&f2);
	mostrarFraccion(f2);

	do{
		printf("\n1.- Multiplicar");
		printf("\n2.- Dividir");
		printf("\n0.- Salir");
		printf("\nElige una opcion --> ");
		fflush(stdout);		scanf("%i", &menu);

		switch(menu)
		{
		case 1: resultadoN = f1.numerador * f2.numerador;
				resultadoD = f1.denominador * f2.denominador;

				printf("\n %.2f / %.2f = %.2f", resultadoN, resultadoD, resultadoN / resultadoD);
		break;
		case 2:
						resultadoN = f1.numerador * f2.denominador;
						resultadoD = f1.denominador * f2.numerador;
						printf("\n %.2f / %.2f = %.2f", resultadoN, resultadoD, resultadoN / resultadoD);
		break;
		case 0: break;
		break;
		default: printf("\nOpcion no valida. Vuelvela a introducir. \n");
		}
	} while (menu != 0);

	printf("\nAdios (:");
	return EXIT_SUCCESS;
}
