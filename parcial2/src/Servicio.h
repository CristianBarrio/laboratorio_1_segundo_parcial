/*
 * Servicio.h
 *
 *  Created on: 19 jun. 2022
 *      Author: Cristian
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#define TAM_DESC 50
#define TAM_TIPO 15
#define TAM 10

typedef struct
{
	int id;
	char descripcion[TAM_DESC];
	int tipo;
	float precioUnitario;
	int cantidad;
	float totalServicio;
}eServicio;

#endif /* SERVICIO_H_ */


/** Crea un nuevo servicio y le da un espacio en la memoria
 *
 * @return Retorna el nuevo servicio
 */
eServicio* Servicio_new();

/** Asigna nuevos parametros al servicio
 *
 * @param idStr char* puntero al id
 * @param descripcion char* puntero a la descripcion
 * @param tipoStr char* puntero al tipo de servicio
 * @param precioUnitario char* puntero al precio unitario del servicio
 * @param cantidadStr char* puntero a la cantidad de servicios
 * @param totalServicioStr char* puntero al precio total
 * @return
 */
eServicio* Servicio_newParametros(char* idStr,char* descripcion,char* tipoStr, char* precioUnitarioStr, char* cantidadStr, char* totalServicioStr);

/** Elimina al servicio
 *
 * @param this eServicio* puntero al servicio
 */
void Servicio_delete(eServicio* this);

/** Asigna el ID al servicio
 *
 * @param this eServicio* puntero al servicio
 * @param id int ID del servicio
 * @return retorna 0 si hubo un error, de lo contrario 1
 */
int Servicio_setId(eServicio* this,int id);

/** Obtiene el ID del servicio
 *
 * @param this eServicio* puntero al servicio
 * @param id int* puntero al ID del servicio
 * @return retorna 0 si hubo un error, de lo contrario 1
 */
int Servicio_getId(eServicio* this,int* id);

/** Asigna la descripcion al servicio
 *
 * @param this eServicio* puntero al servicio
 * @param descripcion char* puntero a la descripcion del servicio
 * @return retorna 0 si hubo un error, de lo contrario 1
 */
int Servicio_setDescripcion(eServicio* this,char* descripcion);

/** Obtiene la descripcion del servicio
 *
 * @param this eServicio* puntero al servicio
 * @param descripcion char* puntero a la descripcion del servicio
 * @return retorna 0 si hubo un error, de lo contrario 1
 */
int Servicio_getDescripcion(eServicio* this,char* descripcion);

/** Asigna el tipo al servicio
 *
 * @param this eServicio* puntero al servicio
 * @param tipo int tipo de servicio
 * @return retorna 0 si hubo un error, de lo contrario 1
 */
int Servicio_setTipo(eServicio* this,int tipo);

/** Obtiene el tipo al servicio
 *
 * @param this eServicio* puntero al servicio
 * @param tipo int* puntero al tipo de servicio
 * @return retorna 0 si hubo un error, de lo contrario 1
 */
int Servicio_getTipo(eServicio* this,int* tipo);

/** Asigna el precio unitario al servicio
 *
 * @param this eServicio* puntero al servicio
 * @param precioUnitario float precio de una unidad
 * @return retorna 0 si hubo un error, de lo contrario 1
 */
int Servicio_setPrecioUnitario(eServicio* this,float precioUnitario);

/** Obtiene el precio unitario del servicio
 *
 * @param this eServicio* puntero al servicio
 * @param precioUnitario float* puntero al precio de una unidad
 * @return retorna 0 si hubo un error, de lo contrario 1
 */
int Servicio_getPrecioUnitario(eServicio* this,float* precioUnitario);

/** Asigna la cantidad de un servicio
 *
 * @param this eServicio* puntero al servicio
 * @param cantidad int cantidad del servicio
 * @return retorna 0 si hubo un error, de lo contrario 1
 */
int Servicio_setCantidad(eServicio* this,int cantidad);

/** Obtiene la cantidad de un servicio
 *
 * @param this eServicio* puntero al servicio
 * @param cantidad int* puntero a la cantidad del servicio
 * @return retorna 0 si hubo un error, de lo contrario 1
 */
int Servicio_getCantidad(eServicio* this,int* cantidad);

/** Asigna el precio total de un servicio
 *
 * @param this eServicio* puntero al servicio
 * @param totalServicio float precio total del servicio
 * @return retorna 0 si hubo un error, de lo contrario 1
 */
int Servicio_setTotalServicio(eServicio* this,float totalServicio);

/** Obtiene el precio total de un servicio
 *
 * @param this eServicio* puntero al servicio
 * @param totalServicio float* puntero al precio total del servicio
 * @return retorna 0 si hubo un error, de lo contrario 1
 */
int Servicio_getTotalServicio(eServicio* this,float* totalServicio);

/** Muestra los datos de un servicio
 *
 * @param unServicio eServicio* puntero al servicio
 */
void Servicio_mostrarUnServicio(eServicio* unServicio);

/** Compara las descripciones de dos servicios
 *
 * @param servicio1 void* puntero a un servicio de la lista
 * @param servicio2 void* puntero a otro servicio de la lista
 * @return retorna el resultado de la funcion strcmp
 */
int Servicio_compararDescripcion(void* servicio1, void* servicio2);

/** Asigna al precio total a un servicio, multiplicando
 *  el precio unitario por la cantidad
 * @param servicio void* puntero vacio a un servicio
 */
void Servicio_asignarTotal(void* servicio);

/**
 *
 * @param servicio void* puntero vacio a un servicio
 * @return retorna 1 si el tipo de servicio es minorista, de lo contrario 0
 */
int Servicio_filtrarMinorista(void* servicio);

/**
 *
 * @param servicio void* puntero vacio a un servicio
 * @return retorna 1 si el tipo de servicio es mayorista, de lo contrario 0
 */
int Servicio_filtrarMayorista(void* servicio);

/**
 *
 * @param servicio void* puntero vacio a un servicio
 * @return retorna 1 si el tipo de servicio es exportar, de lo contrario 0
 */
int Servicio_filtrarExportar(void* servicio);
