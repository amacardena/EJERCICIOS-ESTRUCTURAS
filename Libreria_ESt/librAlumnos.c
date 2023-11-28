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
	int i;
	list[*num].curso = 0;
	printf("\n\nAlumno %i de %i: \n", (*num)+1, MAXALUMNOS);

	fflush(stdin);
	printf("\nNombre --> ");
	fflush(stdout); 	fgets(list[*num].nombre, MAXNOMBRE, stdin);

	list[*num].nombre[strlen(list[*num].nombre) -1] = '\0';

	fflush(stdin);
	printf("\nDNI --> ");
	fflush(stdout); 	fgets(list[*num].dni, MAXDNI, stdin);

	list[*num].dni[strlen(list[*num].dni) -1] = '\0';

	do {
		printf("\nIntroduce el curso del alumno del alumno (1 - %i) -->", MAXCURSO);
		fflush(stdout); 	scanf("%i", &list[*num].curso);
	} while(list[*num].curso < 1 || list[*num].curso > MAXCURSO);

	for(i = 0; i < list[*num].curso; i++)
	{
		list[*num].asignaturas[i] = -1;
		do {
			printf("\nIntroduce las asignaturas pendientes del curso %i (1 - %i) --> ", i+1, MAXPENDIENTES);
			fflush(stdout); 	scanf("%i", &list[*num].asignaturas[i]);
		} while (list[*num].asignaturas[i] < 0 || list[*num].asignaturas[i] > MAXPENDIENTES);
	}
	(*num)++;
}

void mostrarAlumnos(alumnos list[], int num)
{
	int i;
	printf("\nNombre --> %s", list[num].nombre);
	printf("\nDNI --> %s", list[num].dni);
	printf("\nCURSO --> %i", list[num].curso);

	for(i = 0; i < list[num].curso; i++)
	{
			printf("\nAsignaturas pendientes del curso %i --> %i", i+1, list[num].asignaturas[i]);
	}

	printf("\n");
}
