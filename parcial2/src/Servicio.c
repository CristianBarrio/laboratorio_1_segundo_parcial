/*
 * Servicio.c
 *
 *  Created on: 19 jun. 2022
 *      Author: Cristian
 */


#include "Servicio.h"

eServicio* Servicio_new()
{
	eServicio* pasajero;

	pasajero = (eServicio*) malloc(sizeof(eServicio));

	return pasajero;
}

eServicio* Servicio_newParametros(char* idStr,char* descripcion,char* tipoStr, char* precioUnitarioStr, char* cantidadStr, char* totalServicioStr)
{
	eServicio* servicio;

	servicio = Servicio_new();


	if(servicio != NULL &&
		Servicio_setId(servicio,atoi(idStr)) &&
		Servicio_setDescripcion(servicio,descripcion) &&
		Servicio_setTipo(servicio,atoi(tipoStr)) &&
		Servicio_setPrecioUnitario(servicio,atof(precioUnitarioStr)) &&
		Servicio_setCantidad(servicio,atoi(cantidadStr)) &&
		Servicio_setTotalServicio(servicio,atof(totalServicioStr)))
	{
		return servicio;
	}else
	{
		Servicio_delete(servicio);
	}

	return 0;
}

void Servicio_delete(eServicio* this)
{
	free(this);
}

int Servicio_setId(eServicio* this,int id)
{
	int retorno = 0;

	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = 1;
	}

	return retorno;
}

int Servicio_getId(eServicio* this,int* id)
{
	int retorno = 0;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 1;
	}

	return retorno;
}

int Servicio_setDescripcion(eServicio* this,char* descripcion)
{
	int retorno = 0;

	if(this != NULL && descripcion != NULL)
	{
		strcpy(this->descripcion,descripcion);
		retorno = 1;
	}

	return retorno;
}

int Servicio_getDescripcion(eServicio* this,char* descripcion)
{
	int retorno = 0;

	if(this != NULL && descripcion != NULL)
	{
		strcpy(descripcion,this->descripcion);
		retorno = 1;
	}

	return retorno;
}

int Servicio_setTipo(eServicio* this,int tipo)
{
	int retorno = 0;

	if(this != NULL && tipo > 0)
	{
		this->tipo = tipo;;
		retorno = 1;
	}

	return retorno;
}

int Servicio_getTipo(eServicio* this,int* tipo)
{
	int retorno = 0;

	if(this != NULL && tipo != NULL)
	{
		*tipo = this->tipo;
		retorno = 1;
	}

	return retorno;
}

int Servicio_setPrecioUnitario(eServicio* this,float precioUnitario)
{
	int retorno = 0;

	if(this != NULL)
	{
		this->precioUnitario = precioUnitario;
		retorno = 1;
	}

	return retorno;
}

int Servicio_getPrecioUnitario(eServicio* this,float* precioUnitario)
{
	int retorno = 0;

	if(this != NULL && precioUnitario != NULL)
	{
		*precioUnitario = this->precioUnitario;
		retorno = 1;
	}

	return retorno;
}

int Servicio_setCantidad(eServicio* this,int cantidad)
{
	int retorno = 0;

	if(this != NULL && cantidad > 0)
	{
		this->cantidad = cantidad;
		retorno = 1;
	}

	return retorno;
}

int Servicio_getCantidad(eServicio* this,int* cantidad)
{
	int retorno = 0;

	if(this != NULL && cantidad != NULL)
	{
		*cantidad = this->cantidad;
		retorno = 1;
	}

	return retorno;
}

int Servicio_setTotalServicio(eServicio* this,float totalServicio)
{
	int retorno = 0;

	if(this != NULL)
	{
		this->totalServicio = totalServicio;
		retorno = 1;
	}

	return retorno;
}

int Servicio_getTotalServicio(eServicio* this,float* totalServicio)
{
	int retorno = 0;

	if(this != NULL && totalServicio != NULL)
	{
		*totalServicio = this->totalServicio;
		retorno = 1;
	}

	return retorno;
}

void Servicio_mostrarUnServicio(eServicio* unServicio)
{
	int id;
	char descripcion[TAM_DESC];
	int tipo;
	char tipoStr[TAM_TIPO];
	float precioUnitario;
	int cantidad;
	float totalServicio;

	if(unServicio != NULL && Servicio_getId(unServicio,&id) &&
							Servicio_getDescripcion(unServicio,descripcion) &&
							Servicio_getTipo(unServicio,&tipo) &&
							Servicio_getPrecioUnitario(unServicio,&precioUnitario) &&
							Servicio_getCantidad(unServicio,&cantidad) &&
							Servicio_getTotalServicio(unServicio,&totalServicio))
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

		printf("%d, %15s, %15s, %.2f, %d, %.2f\n", id,
													descripcion,
													tipoStr,
													precioUnitario,
													cantidad,
													totalServicio);
	}
}

int Servicio_compararDescripcion(void* servicio1, void* servicio2)
{
	int retorno;
	char descripcion1[TAM_DESC];
	char descripcion2[TAM_DESC];

	if(servicio1 != NULL && servicio2 != NULL)
	{
		if(Servicio_getDescripcion(servicio1,descripcion1) && Servicio_getDescripcion(servicio2,descripcion2))
		{
			retorno = strcmp(descripcion1,descripcion2);
		}
	}

	return retorno;
}


void Servicio_asignarTotal(void* servicio)
{
	eServicio* totales = servicio;

	Servicio_setTotalServicio(totales,totales->precioUnitario * totales->cantidad);

}

int Servicio_filtrarMinorista(void* servicio)
{
	int retorno = 0;
	eServicio* servicioFiltrado = servicio;

	if(servicioFiltrado->tipo == 1)
	{
		retorno = 1;
	}

	return retorno;
}

int Servicio_filtrarMayorista(void* servicio)
{
	int retorno = 0;
	eServicio* servicioFiltrado = servicio;

	if(servicioFiltrado->tipo == 2)
	{
		retorno = 1;
	}

	return retorno;
}

int Servicio_filtrarExportar(void* servicio)
{
	int retorno = 0;
	eServicio* servicioFiltrado = servicio;

	if(servicioFiltrado->tipo == 3)
	{
		retorno = 1;
	}

	return retorno;
}
