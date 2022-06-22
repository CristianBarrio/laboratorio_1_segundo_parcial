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

/** Obtiene el apellido del pasajero
 *
 * @param this Passenger* puntero al pasajero
 * @param apellido char* puntero al apellido del pasajero
 * @return retorna 0 si hubo un error, de lo contrario 1
 */
int Servicio_getTipo(eServicio* this,int* tipo);

/** Asigna el codigo de vuelo al pasajero
 *
 * @param this Passenger* puntero al pasajero
 * @param codigoVuelo char* puntero al codigo de vuelo
 * @return retorna 0 si hubo un error, de lo contrario 1
 */
int Servicio_setPrecioUnitario(eServicio* this,float precioUnitario);

/** Obtiene el codigo de vuelo del pasajero
 *
 * @param this Passenger* puntero al pasajero
 * @param codigoVuelo char* puntero al codigo de vuelo
 * @return retorna 0 si hubo un error, de lo contrario 1
 */
int Servicio_getPrecioUnitario(eServicio* this,float* precioUnitario);

/** Asigna el tipo al pasajero
 *
 * @param this Passenger* puntero al pasajero
 * @param tipoPasajero int tipo de pasajero
 * @return retorna 0 si hubo un error, de lo contrario 1
 */
int Servicio_setCantidad(eServicio* this,int cantidad);

/** Obtiene el tipo del pasajero
 *
 * @param this Passenger* puntero al pasajero
 * @param tipoPasajero int* puntero al tipo de pasajero
 * @return retorna 0 si hubo un error, de lo contrario 1
 */
int Servicio_getCantidad(eServicio* this,int* cantidad);

/** Asigna el precio al pasajero
 *
 * @param this Passenger* puntero al pasajero
 * @param precio float Precio del vuelo
 * @return retorna 0 si hubo un error, de lo contrario 1
 */
int Servicio_setTotalServicio(eServicio* this,float totalServicio);

/** Obtiene el precio del pasajero
 *
 * @param this Passenger* puntero al pasajero
 * @param precio float* puntero al precio del vuelo
 * @return retorna 0 si hubo un error, de lo contrario 1
 */
int Servicio_getTotalServicio(eServicio* this,float* totalServicio);

/** Asigna el estado del vuelo al pasajero
 *
 * @param this Passenger* puntero al pasajero
 * @param estadoVuelo int estado del vuelo
 * @return retorna 0 si hubo un error, de lo contrario 1
 */
int Servicio_setEstadoVuelo(eServicio* this,int estadoVuelo);

/** Muestra los datos de un pasajero
 *
 * @param unPasajero Passenger* puntero al pasajero
 */
void Servicio_mostrarUnServicio(eServicio* unServicio);

/** Busca un pasajero segun su ID
 *
 * @param this LinkedList* puntero al LinkedList
 * @param id int ID a buscar
 * @return retorna 0 si hubo un error, de lo contrario devuelve el indice del pasajero en el LinkedList
 */
int Servicio_buscarServicio(LinkedList* this, int id);

/** Compara los apellidos de dos pasajeros
 *
 * @param pasajero1 void* puntero a un pasajero de la lista
 * @param pasajero2 void* puntero a otro pasajero de la lista
 * @return retorna el resultado de la funcion strcmp
 */
int Servicio_compararDescripcion(void* servicio1, void* servicio2);
void Servicio_asignarTotal(void* servicio);
int Servicio_filtrarMinorista(void* servicio);
int Servicio_filtrarMayorista(void* servicio);
int Servicio_filtrarExportar(void* servicio);
