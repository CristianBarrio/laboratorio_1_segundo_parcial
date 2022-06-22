/*
 * Controller.h
 *
 *  Created on: 19 jun. 2022
 *      Author: Cristian
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Servicio.h"
#include "parser.h"
#include "UTN.h"

#endif /* CONTROLLER_H_ */


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char* archivo a cargar
 * \param pArrayListPassenger LinkedList* puntero a la lista de pasajeros
 * \return retorna 0 si hubo un error, de lo contrario 1
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListServicio);


/** \brief Muestra la lista de pasajeros
 *
 * \param pArrayListPassenger LinkedList* puntero a la lista de pasajeros
 * \return retorna 0 si hubo un error, de lo contrario 1
 *
 */
int controller_ListServicio(LinkedList* pArrayListServicio);

/** \brief Ordena los pasajeros por apellido
 *
 * \param pArrayListPassenger LinkedList* puntero a la lista de pasajeros
 * \return retorna 0 si hubo un error, de lo contrario 1
 *
 */
int controller_sortServicio(LinkedList* pArrayListServicio);

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char* archivo a guardar
 * \param pArrayListPassenger LinkedList* puntero a la lista de pasajeros
 * \return retorna 0 si hubo un error, de lo contrario 1
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListServicio);

int controller_AsignarTotales(LinkedList* pArrayListServicio);
int controller_filterByType(LinkedList* pArrayListServicio, char* path);
