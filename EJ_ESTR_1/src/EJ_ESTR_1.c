/*
 ============================================================================
 Name        : EJ_ESTR_1.c
 Author      : Adrián Marín
 Version     :
 Copyright   : Your copyright notice
 Description : EJ_1 de 6.  Introducir nombre, apellidos y edad de una persona
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "librEstr.h"


int main(void) {
	personas perso;

	pedirPersona(&perso);
	mostrarPersona(perso);
	return EXIT_SUCCESS;
}
