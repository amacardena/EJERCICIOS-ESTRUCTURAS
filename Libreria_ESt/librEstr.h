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
	float numerador;
	float denominador;
} fraccion;

void pedirPersona(personas *per);
void mostrarPersona(personas per);
void pedirFraccion(fraccion *frac);
void mostrarFraccion(fraccion frac);

#endif /* LIBRESTR_H_ */
