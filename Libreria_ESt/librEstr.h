/*
 * librEstr.h
 *
 *  Created on: 22 nov 2023
 *      Author: Adrian
 */

#ifndef LIBRESTR_H_
#define LIBRESTR_H_
#define MAXNOMBRE 20
#define MAXAPELLIDO 30

typedef struct
{
	char nombre[MAXNOMBRE];
	char apellido[MAXAPELLIDO];
	int edad;
} personas;

typedef struct
{
	int numerador;
	int denominador;
} fraccion;

void pedirPersona(personas *per);
void mostrarPersona(personas per);
void pedirFraccion(fraccion *frac);
void mostrarFraccion(fraccion frac);
void multiplicarFraccion(fraccion *f1, fraccion *f2, fraccion *f3);
void dividirFraccion(fraccion *f1, fraccion *f2, fraccion *f3);
void sumarFraccion(fraccion *f1, fraccion *f2, fraccion *f3);
void restarFraccion(fraccion *f1, fraccion *f2, fraccion *f3);
int mcm (int num1, int num2);
int mcd (int num1, int num2);
#endif /* LIBRESTR_H_ */
