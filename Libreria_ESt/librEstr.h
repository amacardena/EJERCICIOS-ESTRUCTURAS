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
#define MAXPAC 3
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

typedef struct
{
	char nombre[MAXNOMBRE];
	float peso;
	float altura;
	float imc;
} pacientes;

void pedirPersona(personas *per);
void mostrarPersona(personas per);
void pedirPaciente(pacientes pac[], int num);
void mostrarPaciente(pacientes pac[], int num);
void pedirFraccion(fraccion *frac);
void mostrarFraccion(fraccion frac);
void multiplicarFraccion(fraccion *f1, fraccion *f2, fraccion *f3);
void dividirFraccion(fraccion *f1, fraccion *f2, fraccion *f3);
void sumarFraccion(fraccion *f1, fraccion *f2, fraccion *f3);
void restarFraccion(fraccion *f1, fraccion *f2, fraccion *f3);
int mcm (int num1, int num2);
int mcd (int num1, int num2);
void simplificar (fraccion *f);
void calcularIMC(pacientes pac[], int num);
#endif /* LIBRESTR_H_ */
