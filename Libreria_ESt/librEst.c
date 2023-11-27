/*
 * librEst.c
 *
 *  Created on: 22 nov 2023
 *      Author: Adrian
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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
	printf("\n %i", frac.numerador);
	printf("\n----");
	printf("\n %i", frac.denominador);
}

void multiplicarFraccion(fraccion *f1, fraccion *f2, fraccion *f3)
{
	f3->numerador = f1->numerador * f2->numerador;
	f3->denominador = f1->denominador * f2->denominador;
	simplificar(f3);

}

void dividirFraccion(fraccion *f1, fraccion *f2, fraccion *f3)
{
	f3->numerador = f1->numerador * f2->denominador;
	f3->denominador = f1->denominador * f2->numerador;
	simplificar(f3);
}

void sumarFraccion(fraccion *f1, fraccion *f2, fraccion *f3)
{
	int mincom = mcm(f1->denominador, f2->denominador);
	f3->denominador = mincom;
	f3 ->numerador = f1->numerador*(mincom/f1->denominador) + f2->numerador*(mincom/f2->denominador);
	simplificar(f3);
}

void restarFraccion(fraccion *f1, fraccion *f2, fraccion *f3)
{
	int mincom = mcm(f1->denominador, f2->denominador);
	f3->denominador = mincom;
	f3 ->numerador = f1->numerador*(mincom/f1->denominador) - f2->numerador*(mincom/f2->denominador);
	simplificar(f3);
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

void simplificar (fraccion * f)
{
	int m=mcd(f->numerador,f->denominador);
	f->numerador=f->numerador/m;
	f->denominador=f->denominador/m;
}

void pedirPaciente(pacientes pac[], int num)
{
	int i;

	for(i = 0; i < num; i++)
	{
			fflush(stdin);
		printf("\n\nPaciente %i :\n", i+1);

		printf("\nIntroduce el nombre del paciente %i--> ", i+1);
		fflush(stdout);		fgets(pac[i].nombre, MAXNOMBRE, stdin);

		pac[i].nombre[strlen(pac[i].nombre) -1 ] = '\0';

		printf("\nIntroduce el peso del paciente %s --> ", pac[i].nombre);
		fflush(stdout);		scanf("%f", &(pac[i].peso));

		printf("\nIntroduce la altura del paciente %s --> ", pac[i].nombre);
		fflush(stdout);		scanf("%f", &(pac[i].altura));
	}
}

void mostrarPaciente(pacientes pac[], int num)
{
	int i;

	for(i = 0; i < num; i++)
	{

		printf("\n\nPaciente %i :\n", i+1);

		printf("\nNombre --> %s", pac[i].nombre);
		printf("\nPeso --> %.2f", pac[i].peso);
		printf("\nAltura --> %.2f", pac[i].altura);
		printf("\nIMC --> %.2f", pac[i].imc);
	}
}

void calcularIMC(pacientes pac[], int num)
{
	int i;

	for(i = 0; i < num; i++)
	{
		pac[i].imc = pac[i].peso / pow(pac[i].altura, 2);
	}
}

int esBisiesto(unsigned int anio) {
	if (anio%4==0) {
		if (anio%100==0 && anio%400!=0) {
			return 0;
		}else {
			return 1;
		}
	}else {
		return 0;
	}
}

int numDias(int mes, int anio) {
	if (mes==2) {
		if (esBisiesto(anio)) { return 29;}
		else { return 28;}
	} else if (mes==4 || mes ==6 || mes == 9 || mes ==11) { return 30;}
	else {
		return 31;
	}
}

int existeFecha(int dias, int mes, int anio)
{
	if(dias < 0 || dias > numDias(mes, anio) || mes < 0 || mes > 12 || anio < 0) return 0;
	else return 1;
}

void pedirPers4(personas4 pers[], int num)
{
	int i;

		for(i = 0; i < num; i++)
		{
			fflush(stdin);
			printf("\n\nPersona %i :\n", i+1);

			printf("\nIntroduce el nombre de la persona %i--> ", i+1);
			fflush(stdout);		fgets(pers[i].nombre, MAXNOMBRE, stdin);

			pers[i].nombre[strlen(pers[i].nombre) -1 ] = '\0';
			pers[i].diaN = pers[i].mesN = pers[i].anioN = 0;

			do {
				printf("\nIntroduce el dia de nacimiento de %s --> ", pers[i].nombre);
				fflush(stdout); scanf("%i", &(pers[i].diaN));


				printf("\nIntroduce el mes de nacimiento de %s --> ", pers[i].nombre);
				fflush(stdout); scanf("%i", &(pers[i].mesN));

				printf("\nIntroduce el anio de nacimiento de %s --> ", pers[i].nombre);
				fflush(stdout); scanf("%i", &(pers[i].anioN));

				if(existeFecha(pers[i].diaN,pers[i].mesN,pers[i].anioN) == 0) printf("\nFecha no valida. Introducela de nuevo.\n");

			} while(existeFecha(pers[i].diaN,pers[i].mesN,pers[i].anioN) == 0);
		}
}

void mostrarPers4(personas4 pers[], int num)
{
	int i;

		for(i = 0; i < num; i++)
		{
			printf("\nNombre --> %s", pers[i].nombre);
			printf("\nDia de nacimiento --> %i", pers[i].diaN);
			printf("\nMes de nacimiento --> %i", pers[i].mesN);
			printf("\nAnio de nacimiento --> %i", pers[i].anioN);
		}
}

void mostrarCumple(personas4 pers[], int num, int mes)
{
	int i;
	printf("\nPersonas que cumplen anios en el mes %i: \n", mes);

	for(i = 0; i < num; i++)
	{
		if(pers[i].mesN == mes)
		{
			printf("\nNombre --> %s", pers[i].nombre);
			printf("\nDia de nacimiento --> %i", pers[i].diaN);
			printf("\nMes de nacimiento --> %i", pers[i].mesN);
			printf("\nAnio de nacimiento --> %i", pers[i].anioN);
		}
	}

}

void pedirCarrito(compra carro[], int *num)
{

		carro[*num].cantidad = carro[*num].precio = -1;
		carro[*num].iva= 0.21;
		fflush(stdin);

		printf("\nIntroduce el nombre del articulo --> ");
		fflush(stdout); 	fgets(carro[*num].nombre, MAXNOMBRE, stdin);

		carro[*num].nombre[strlen(carro[*num].nombre) -1] = '\0';

		do {
			printf("\nIntroduce el precio de los %s (eur/kg) --> ", carro[*num].nombre);
			fflush(stdout);		scanf("%f", &(carro[*num].precio));
		} while(carro[*num].precio < 0);

		do {
			printf("\nIntroduce cantidad de los kilos de los %s --> ", carro[*num].nombre);
			fflush(stdout);		scanf("%f", &(carro[*num].cantidad));
		} while(carro[*num].cantidad < 0);

	(*num)++;
}

double subtotal(compra carro[], int num)
{
	double salida = 0;
	int i;
	for(i = 0; i < num; i++)
	{
		salida = salida + carro[i].precio * carro[i].cantidad;
	}
	return salida;
}

double aplicarIVA(compra carro[], int num)
{
	double salida = 0;
	int i;
	for(i = 0; i < num; i++)
	{
		salida = salida + carro[i].precio *carro[i].cantidad * carro[i].iva;
	}
	return salida;
}

void mostrarPers5(persEj5 pers[], int num)
{
		printf("\n\nNombre --> %s", pers[num].nombre);
		printf("\nDireccion --> %s", pers[num].direccion);
		printf("\nTelefono --> %i", pers[num].telefono);
		printf("\nEdad --> %i", pers[num].edad);
}
