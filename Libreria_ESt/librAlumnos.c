/*
 * librAlumnos.c
 *
 *  Created on: 28 nov 2023
 *      Author: Adrian
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "librAlumnos.h"

void pedirAlumnos(alumnos list[], int *num)
{
	printf("\n\nAlumno %i de %i: \n", (*num)+1, MAXALUMNOS);

	fflush(stdin);
	printf("\nNombre --> ");
	fflush(stdout); 	fgets(list[*num].nombre, MAXNOMBRE, stdin);

	list[*num].nombre[strlen(list[*num].nombre) -1] = '\0';

	fflush(stdin);
	printf("\nDNI --> ");
	fflush(stdout); 	fgets(list[*num].dni, MAXDNI, stdin);

	list[*num].dni[strlen(list[*num].dni) -1] = '\0';




}
