/*
 ============================================================================
 Name        : EJ_ESTR_3.c
 Author      : Adrián Marín
 Version     :
 Copyright   : Your copyright notice
 Description : EJ_3 de 6. Calcular IMC de 2 pacientes
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "librEstr.h"

int main(void) {
	pacientes lista[MAXPAC];
	int n = -1;
	do {
		printf("\nIntroduce el numero de pacientes (1 - %i) --> ", MAXPAC);
		fflush(stdout); 	scanf("%i", &n);
	} while (n < 0 || n > MAXPAC);


	pedirPaciente(lista, n);
	calcularIMC(lista, n);
	mostrarPaciente(lista, n);
	return EXIT_SUCCESS;
}
