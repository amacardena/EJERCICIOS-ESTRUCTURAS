/*
 * librAlumnos.h
 *
 *  Created on: 28 nov 2023
 *      Author: Adrian
 */

#ifndef LIBRALUMNOS_H_
#define LIBRALUMNOS_H_
#define MAXALUMNOS 100
#define MAXNOMBRE 100
#define MAXDNI 10
#define MAXCURSO 3
#define MAXPENDIENTES 15
#define MAXASIGNATURAS 3

typedef struct
{
	char nombre[MAXNOMBRE];
	char dni[MAXDNI];
	int curso;
	int asignaturas[MAXASIGNATURAS];
}alumnos;

void pedirAlumnos(alumnos list[], int *num);
void mostrarTodosAlumnos(alumnos list[], int num);
void mostrarAlumnosXCurso(alumnos list[], int num, int curso);
void mostrarSoloAlumno(alumnos list[], int num);
void mostrarAlumnosFinCarrera(alumnos list[], int num);

#endif /* LIBRALUMNOS_H_ */
