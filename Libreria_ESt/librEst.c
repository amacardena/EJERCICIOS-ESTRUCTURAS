/*
 * librEst.c
 *
 *  Created on: 22 nov 2023
 *      Author: Adrian
 */

#include <stdio.h>
#include <stdlib.h>
#include "librEstr.h"

void pedirPersona(personas *per)
{
	printf("\nIntroduce el nombre de la persona --> ");
	fflush(stdout);
	fgets(per->nombre, MAXNOMBRE, stdin);

	printf("\nIntroduce el/los apellido/os de la persona --> ");
	fflush(stdout); 		fgets(per->apellido, MAXAPELLIDO, stdin);

	per->edad = -1;

	do {
		printf("\nIntroduce la edad de la persona --> ");
		fflush(stdout);		scanf("%i",&(per->edad));
	} while (per->edad < 0);
}

void mostrarPersona(personas per)
{
	printf("\nNombre --> %s", per.nombre);
	printf("\nApellido/os --> %s", per.apellido);
	printf("\nEdad --> %i", per.edad);
}

void pedirFraccion(fraccion *frac)
{
	printf("\nIntroduce el numerador --> ");
	fflush(stdout);		scanf("%f", &(frac->numerador));

	printf("\nIntroduce el denominador --> ");
	fflush(stdout);		scanf("%f", &(frac->denominador));
}

void mostrarFraccion(fraccion frac)
{
	printf("\nNumerador --> %.2f", frac.numerador);
	printf("\nDenominador --> %.2f", frac.denominador);
}
