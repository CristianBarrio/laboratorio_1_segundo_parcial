/*
 ============================================================================
 Name        : Lab1Parcial2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "UTN.h"
#include "Controller.h"
#include "Servicio.h"
#include "parser.h"

int main(void) {

	setbuf(stdout,NULL);

	int continuar = 0;
	int flagGuardado = 1;
	int flagCarga = 0;

	LinkedList* listaServicios = ll_newLinkedList();

	do{
		system("cls");

		switch(menu())
		{
			case 1:
				if(controller_loadFromText("data.csv",listaServicios))
				{
					printf("Datos cargados exitosamente desde data.csv.\n");
					flagCarga = 1;
				}else
				{
					printf("Hubo un error al cargar los datos.\n");
				}
				break;
			case 2:
				if(flagCarga)
				{
					if(controller_ListServicio(listaServicios))
					{
						printf("Servicios mostrados con exito.\n");
					}else
					{
						printf("Hubo un problema al mostrar los servicios.\n");
					}
				}else
				{
					printf("La lista de servicios esta vacia. No hay pasajeros para mostrar.\n");
				}
				break;
			case 3:
				if(flagCarga)
				{
					if(controller_AsignarTotales(listaServicios))
					{
						printf("Precios totales asignados con exito.\n");
					}else
					{
						printf("Hubo un problema al asignar los precios.\n");
					}
				}else
				{
					printf("La lista de servicios esta vacia.\n");
				}
				break;
			case 4:
				if(flagCarga)
				{
					controller_filterByType(listaServicios,"dataByType.csv");
				}
				else
				{
					printf("No hay lista para filtrar.\n");
				}
				break;
			case 5:
				// TARDA EN RESPONDER PERO FUNCIONA !!
				if(flagCarga)
				{
					controller_sortServicio(listaServicios);
					if(controller_ListServicio(listaServicios))
					{
						printf("Servicios ordenados y mostrados con exito.\n");
						flagGuardado = 0;
					}else
					{
						printf("Hubo un problema al mostrar los servicios.\n");
					}
				}else
				{
					printf("La lista de servicios esta vacia. No hay pasajeros para mostrar.\n");
				}
				break;
			case 6:
				if(!flagGuardado)
				{
					if(controller_saveAsText("data.csv",listaServicios))
					{
						printf("Datos guardados con exito.\n");
						flagGuardado = 1;
					}else
					{
						printf("Hubo un problema al guardar los datos.\n");
					}
				}else
				{
					printf("No se ha realizado ningun cambio.\n");
				}
				break;
			case 7:
				if(flagGuardado)
				{
					continuar = 1;
					ll_deleteLinkedList(listaServicios);
					printf("Se elimino el LinkedList. Finaliza el programa.\n");
				}else
				{
					printf("No se puede salir del sistema sin antes guardar los datos.\n");
				}
				break;
		}
		system("pause");
	}while(continuar != 1);

	return EXIT_SUCCESS;
}
