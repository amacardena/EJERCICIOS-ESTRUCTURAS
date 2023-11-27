/*
 ============================================================================
 Name        : EJ_ESTR_5.c
 Author      : Adrián Marín
 Version     :
 Copyright   : Your copyright notice
 Description : EJ_5 de 6. Introducir personas hasta que el nombre sea blanco
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "librEstr.h"

int main(void) {

	persEj5 lista[MAXEJ5];
	int i = 0, j, menu, edadUsuario;
	char inicialUsuario;

	do {
		lista[i].edad = -1;
		fflush(stdin);
		printf("\nIntroduce la persona numero %i de %i. (Pulse solo intro si quiere salir) --> ", i+1, MAXEJ5);
		fflush(stdout); fgets(lista[i].nombre, MAXNOMBRE,stdin);

		lista[i].nombre[strlen(lista[i].nombre)-1] = '\0';

		if(strlen(lista[i].nombre) > 0)
		{
			fflush(stdin);
			printf("\nIntroduce la direccion de %s --> ", lista[i].nombre);
			fflush(stdout);	fgets(lista[i].direccion, MAXNOMBRE,stdin);

			printf("\nIntroduce el telefono de %s --> ", lista[i].nombre);
			fflush(stdout); scanf("%i", &lista[i].telefono);

			do {
				printf("\nIntroduce la edad de %s --> ", lista[i].nombre);
				fflush(stdout); scanf("%i", &lista[i].edad);
			} while(lista[i].edad < 0);
			i++;
		}
		else break;
	} while(i < MAXEJ5);

	if(i > 0)
	{
		do
		{
			fflush(stdin);
			printf("\n1.- Mostrar todas las personas");
			printf("\n2.- Mostrar las personas de una cierta edad");
			printf("\n3.- Mostrar las personas cuya inicial sea la que el usuario indique");
			printf("\n0.- Salir del programa");
			printf("\nElige una opcion --> ");
			fflush(stdout);		scanf("%i", &menu);

			switch(menu)
			{
				case 1:
					for(j = 0; j < i; j++)
					{
						printf("\n\nPersona %i", j+1);
						mostrarPers5(lista, j);
					}
				break;
				case 2:
					edadUsuario = -1;
						do {
							printf("\nIntroduce la edad de las personas que estas buscando --> ");
							fflush(stdout);		scanf("%i", &edadUsuario);
						} while(edadUsuario < 0);

						for(j = 0; j < i; j++)
						{
							if(edadUsuario == lista[j].edad)
							{
								printf("\n\nPersona %i", j+1);
								mostrarPers5(lista, j);
							}
						}
				break;
				case 3:
					fflush(stdin);
						printf("\nIntroduce la inicial de las personas que quieres buscar --> ");
						fflush(stdout);	inicialUsuario=toupper(getchar());
						fflush(stdin);
						for(j = 0; j < i; j++)
						{
							lista[j].nombre[0] = toupper(lista[j].nombre[0]);

							if(inicialUsuario == lista[j].nombre[0])
							{
								printf("\n\nPersona %i", j+1);
								mostrarPers5(lista, j);
							}
						}
				break;
				case 0: 	break;
				break;
				default: printf("\nOpcion incorrecta. Vuelvela a introducir.\n");
			}
		} while (menu != 0);
	}

	printf("\nAdios (:");
	return EXIT_SUCCESS;
}
