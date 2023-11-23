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
#define MAXPERS4 8
#define MAXCOMPRA 10
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

typedef struct
{
	char nombre[MAXNOMBRE];
	int diaN;
	int mesN;
	int anioN;
} personas4;

typedef struct
{
	char nombre[MAXNOMBRE];
	float precio;
	float iva;
	float cantidad;
} compra;
void pedirPersona(personas *per);
void mostrarPersona(personas per);
void pedirPaciente(pacientes pac[], int num);
void mostrarPaciente(pacientes pac[], int num);
void pedirPers4(personas4 pers[], int num);
void mostrarPers4(personas4 pers[], int num);
void pedirCarrito(compra carro[], int *num);
void mostrarCumple(personas4 pers[], int num, int mes);
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
int esBisiesto(unsigned int anio);
int existeFecha(int dias, int mes, int anio);
#endif /* LIBRESTR_H_ */
