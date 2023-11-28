/*
 ============================================================================
 Name        : EJ_ESTR_ALUMNOS.c
 Author      : Adrián Marín
 Version     :
 Copyright   : Your copyright notice
 Description : Ejercicio de estructuras sobre unos alumnos
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "librAlumnos.h"

int main(void) {
	alumnos lista[MAXALUMNOS];
	int cont = 0;
	char menu = 'z';

	do {
		printf("\na) Introducir alumnos a la lista");
		printf("\nb) Mostrar todos los alumnos");
		printf("\nc) Sacar todos los alumnos que esten en un curso concreto");
		printf("\nd) Sacar todos los alumnos que le queden menos de 3 asignaturas para terminar la carrera");
		printf("\ne) Mostrar los datos de un alumno dado su nombre");
		printf("\nf) Mostrar los datos de un alumno dado su nombre y numero");
		printf("\ng) Sacar por pantalla aquellos alumnos que tengan mas asignaturas de primer curso que de segundo y tercero juntas");
		printf("\nh) Debido a un aprobado general de una asignatura de tercero, hay que reducir el numero de asignaturas de tercero de todos los alumnos en 1, excepto de aquellos que ya hayan aprobado");
		printf("\ni) Salir");


	} while(menu != 'i');
	printf("\nADIOS(:");
	return EXIT_SUCCESS;
}
