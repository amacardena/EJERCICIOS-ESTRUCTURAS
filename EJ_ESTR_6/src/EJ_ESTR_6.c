/*
 ============================================================================
 Name        : EJ_ESTR_6.c
 Author      : Adrián Marín
 Version     :
 Copyright   : Your copyright notice
 Description : EJ_6 de 6. Carrito de la compra
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "librEstr.h"

int main(void) {
	compra carrito[MAXCOMPRA];
	int menu = -1, j =1;

	do {
		printf("\n\n1.- Agregar objetos al carrito");
		printf("\n2.- Calcular el subotal de importe del carrito (precio * cantidad)");
		printf("\n3.- Calcular el IVA");
		printf("\n4.- Calcular el total");
		printf("\n0.- Salir");
		printf("\nElige una opcion --> ");
		fflush(stdout);		scanf("%i", &menu);

		switch(menu)
		{
			case 1: pedirCarrito(carrito, &j);
					j++;
			break;
			case 2:
			break;
			case 3:
			break;
			case 4:
			break;
			case 0: break;
			break;
			default: printf("\nOpcion no valida, vuelve a introducirla.\n");
		}

	} while (menu != 0);

	printf("\nAdios (:");
	return EXIT_SUCCESS;
}
