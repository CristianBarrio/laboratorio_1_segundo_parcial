/*
 * Controller.c
 *
 *  Created on: 19 jun. 2022
 *      Author: Cristian
 */


#include "Controller.h"

int controller_loadFromText(char* path , LinkedList* pArrayListServicio)
{
	int retorno = 0;

	if(path != NULL && pArrayListServicio != NULL)
	{
		FILE* pFile = fopen(path,"r");

		if(pFile != NULL)
		{
			if(parser_ServiceFromText(pFile,pArrayListServicio))
			{
				printf("Archivos cargados con exito.\n");
				retorno = 1;
			}
			fclose(pFile);
		}
	}else
	{
		printf("Error al abrir el archivo.\n");
	}

	return retorno;
}


int controller_ListServicio(LinkedList* pArrayListServicio)
{
	int retorno = 0;
	eServicio* servicio;
	int tam = ll_len(pArrayListServicio);

	system("cls");
	printf("        SERVICIOS\n"
			"-----------------------------------------\n");

	if(pArrayListServicio != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			servicio = ll_get(pArrayListServicio,i);
			if(servicio != NULL)
			{
				Servicio_mostrarUnServicio(servicio);
			}
		}

		retorno = 1;
	}

	return retorno;
}


int controller_sortServicio(LinkedList* pArrayListServicio)
{
	int retorno = 0;

	if(pArrayListServicio != NULL)
	{
		if(ll_sort(pArrayListServicio,Servicio_compararDescripcion,1))
		{
			retorno = 1;
		}
	}

	return retorno;
}


int controller_saveAsText(char* path , LinkedList* pArrayListServicio)
{
	int retorno = 0;
	int id;
	char descripcion[TAM_DESC];
	int tipo;
	char tipoStr[TAM_TIPO];
	float precioUnitario;
	int cantidad;
	float totalServicio;
	eServicio* servicio;

	int tam = ll_len(pArrayListServicio);

		if(path != NULL && pArrayListServicio != NULL)
		{
			if(tam > 0)
			{
				FILE* pFile = fopen(path,"a");

				if(pFile != NULL)
				{
					fprintf(pFile,"\n\nid_servicio,descripcion,tipo,precioUnitario,cantidad,totalServicio\n");
					for(int i = 0; i < tam; i++)
					{
						servicio = ll_get(pArrayListServicio,i);

					if(servicio != NULL && Servicio_getId(servicio,&id) &&
							Servicio_getDescripcion(servicio,descripcion) &&
							Servicio_getTipo(servicio,&tipo) &&
							Servicio_getPrecioUnitario(servicio,&precioUnitario) &&
							Servicio_getCantidad(servicio,&cantidad) &&
							Servicio_getTotalServicio(servicio,&totalServicio))
					{
						switch(tipo)
						{
							case 1:
								strcpy(tipoStr,"MINORISTA");
								break;
							case 2:
								strcpy(tipoStr,"MAYORISTA");
								break;
							default:
								strcpy(tipoStr,"EXPORTAR");
								break;
						}


						fprintf(pFile,"%d,%s,%s,%.2f,%d,%.2f\n",id,descripcion,tipoStr,precioUnitario,cantidad,totalServicio);
					}
					retorno = 1;
				}
			}

			fclose(pFile);
			}
		}
    return retorno;
}

int controller_AsignarTotales(LinkedList* pArrayListServicio)
{
	int retorno = 0;

	if(pArrayListServicio != NULL)
	{
		ll_map(pArrayListServicio,Servicio_asignarTotal);
		retorno = 1;
	}

	return retorno;
}

int controller_filterByType(LinkedList* pArrayListServicio, char* path)
{
	int retorno = 0;
	int tipo;

	utn_getInt(&tipo,"Ingrese un tipo de servicio a filtrar: \n"
			"Minorista (1) Mayorista (2) Exportar (3) ","Tipo invalido.\n",1,3);

	if(pArrayListServicio != NULL)
	{
		LinkedList* listaFiltrada = ll_newLinkedList();

		switch(tipo)
		{
			case 1:
				listaFiltrada = ll_filter(pArrayListServicio,Servicio_filtrarMinorista);
				break;
			case 2:
				listaFiltrada = ll_filter(pArrayListServicio,Servicio_filtrarMayorista);
				break;
			case 3:
				listaFiltrada = ll_filter(pArrayListServicio,Servicio_filtrarExportar);
				break;
		}

		if(listaFiltrada != NULL)
		{
			if(controller_saveAsText(path,listaFiltrada))
			{
				printf("Lista filtrada guardada con exito en dataByType.csv\n");
				retorno = 1;
			}else
			{
				printf("Hubo un problema al filtrar la lista.\n");
			}
		}

	}

	return retorno;
}


