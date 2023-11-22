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
	fflush(stdout);		scanf("%i", &(frac->numerador));

	printf("\nIntroduce el denominador --> ");
	fflush(stdout);		scanf("%i", &(frac->denominador));
}

void mostrarFraccion(fraccion frac)
{
	printf("\nNumerador --> %i", frac.numerador);
	printf("\nDenominador --> %i", frac.denominador);
}

void multiplicarFraccion(fraccion *f1, fraccion *f2, fraccion *f3)
{
	f3->numerador = f1->numerador * f2->numerador;
	f3->denominador = f1->denominador * f2->denominador;
}

void dividirFraccion(fraccion *f1, fraccion *f2, fraccion *f3)
{
	f3->numerador = f1->numerador * f2->denominador;
	f3->denominador = f1->denominador * f2->numerador;
}

void sumarFraccion(fraccion *f1, fraccion *f2, fraccion *f3)
{
	int mincom = mcm(f1->denominador, f2->denominador);
	f3->denominador = mincom;
	f3 ->numerador = f1->numerador*(mincom/f1->denominador) + f2->numerador*(mincom/f2->denominador);
}

void restarFraccion(fraccion *f1, fraccion *f2, fraccion *f3)
{
	int mincom = mcm(f1->denominador, f2->denominador);
	f3->denominador = mincom;
	f3 ->numerador = f1->numerador*(mincom/f1->denominador) - f2->numerador*(mincom/f2->denominador);
}

int mcd (int num1, int num2)
{
	int aux;

	if (num1 % num2 == 0) return num2;
	else {
		do {
			aux = num2;
			num2 = num1 % num2;
			num1 = aux;
		} while (num1 % num2 != 0);

		return num2;
	}
}

int mcm (int num1, int num2)
{
	return (num1 * num2) / mcd(num1, num2);

}
