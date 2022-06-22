/*
 * parser.c
 *
 *  Created on: 19 jun. 2022
 *      Author: Cristian
 */


#include "parser.h"

int parser_ServiceFromText(FILE* pFile , LinkedList* pArrayListServicio)
{
	int retorno = 0;
	char id[TAM];
	char descripcion[TAM_DESC];
	char tipo[TAM_TIPO];
	char precioUnitario[TAM];
	char cantidad[TAM];
	char totalServicio[TAM];
	eServicio* servicio;


	if(pFile != NULL && pArrayListServicio != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,descripcion,tipo,precioUnitario,cantidad,totalServicio);

		while(!feof(pFile))
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,descripcion,tipo,precioUnitario,cantidad,totalServicio) == 6)
			{

				servicio = Servicio_newParametros(id,descripcion,tipo,precioUnitario,cantidad,totalServicio);

				if(servicio != NULL)
				{
					ll_add(pArrayListServicio,servicio);
					retorno = 1;
				}
			}

		}
	}else
	{
		printf("Error al leer el archivo.\n");
	}

    return retorno;
}
