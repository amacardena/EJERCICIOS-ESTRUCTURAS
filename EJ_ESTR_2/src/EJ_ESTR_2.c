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
	fraccion f1, f2, f3;
	int menu = -1;

	puts("Primera fraccion:");

	pedirFraccion(&f1);
	mostrarFraccion(f1);

	puts("\n\nSegunda fraccion:");

	pedirFraccion(&f2);
	mostrarFraccion(f2);

	do{
		printf("\n1.- Sumar");
		printf("\n2.- Restar");
		printf("\n3.- Multiplicar");
		printf("\n4.- Dividir");
		printf("\n0.- Salir");
		printf("\nElige una opcion --> ");
		fflush(stdout);		scanf("%i", &menu);

		switch(menu)
		{
		case 1:	sumarFraccion(&f1, &f2, &f3);
				mostrarFraccion(f3);
				printf("\nEl resultado es %.2f", (float)f3.numerador / f3.denominador);
		break;
		case 2:	restarFraccion(&f1, &f2, &f3);
				mostrarFraccion(f3);
				printf("\nEl resultado es %.2f", (float) f3.numerador / f3.denominador);
		break;
		case 3: multiplicarFraccion(&f1, &f2, &f3);
				mostrarFraccion(f3);
				printf("\nEl resultado es %.2f", (float) f3.numerador / f3.denominador);
		break;
		case 4:
					dividirFraccion(&f1, &f2, &f3);
					mostrarFraccion(f3);
					printf("\nEl resultado es %.2f", (float) f3.numerador / f3.denominador);
		break;
		case 0: break;
		break;
		default: printf("\nOpcion no valida. Vuelvela a introducir. \n");
		}
	} while (menu != 0);

	printf("\nAdios (:");
	return EXIT_SUCCESS;
}
