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
			printf("\nIntroduce las asignaturas pendientes del curso %i (0 - %i) --> ", i+1, MAXPENDIENTES);
			fflush(stdout); 	scanf("%i", &list[*num].asignaturas[i]);
		} while (list[*num].asignaturas[i] < 0 || list[*num].asignaturas[i] > MAXPENDIENTES);
	}
	(*num)++;
}

void mostrarTodosAlumnos(alumnos list[], int num)
{
	int i, j;
	for(i = 0; i < num; i++)
	{
		printf("\n\nAlumno %i : \n", i+1);

		printf("\nNombre --> %s", list[i].nombre);
		printf("\nDNI --> %s", list[i].dni);
		printf("\nCURSO --> %i", list[i].curso);

		for(j = 0; j < list[i].curso; j++)
		{
				printf("\nAsignaturas pendientes del curso %i --> %i", j+1, list[i].asignaturas[j]);
		}
	}
	printf("\n");
}

void mostrarAlumnosXCurso(alumnos list[], int num, int curso)
{
	int i;
	for(i = 0; i < num; i++)
	{
		if(list[i].curso == curso)
		{
			mostrarSoloAlumno(list, i);
		}
	}
	printf("\n");
}

void mostrarSoloAlumno(alumnos list[], int num)
{
	int j;

	printf("\n\nAlumno %i : \n", num+1);

	printf("\nNombre --> %s", list[num].nombre);
	printf("\nDNI --> %s", list[num].dni);
	printf("\nCURSO --> %i", list[num].curso);

	for(j = 0; j < list[num].curso; j++)
	{
		printf("\nAsignaturas pendientes del curso %i --> %i", j+1, list[num].asignaturas[j]);
	}
}
