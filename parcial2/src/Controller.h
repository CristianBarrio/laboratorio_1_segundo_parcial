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


/** \brief Carga los datos de los servicios desde el archivo data.csv.
 *
 * \param path char* archivo a cargar
 * \param pArrayListServicio LinkedList* puntero a la lista de servicios
 * \return retorna 0 si hubo un error, de lo contrario 1
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListServicio);

/** \brief Muestra la lista de servicios
 *
 * \param pArrayListServicio LinkedList* puntero a la lista de servicios
 * \return retorna 0 si hubo un error, de lo contrario 1
 *
 */
int controller_ListServicio(LinkedList* pArrayListServicio);

/** \brief Ordena los servicios por descripcion
 *
 * \param pArrayListServicio LinkedList* puntero a la lista de servicios
 * \return retorna 0 si hubo un error, de lo contrario 1
 *
 */
int controller_sortServicio(LinkedList* pArrayListServicio);

/** \brief Guarda los datos de los servicios en el archivo data.csv.
 *
 * \param path char* archivo a guardar
 * \param pArrayListServicio LinkedList* puntero a la lista de servicios
 * \return retorna 0 si hubo un error, de lo contrario 1
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListServicio);

/** Asigna los precios totales de toda la lista de servicios, usando ll_map
 *
 * @param pArrayListServicio LinkedList* puntero a la lista de servicios
 * @return retorna 0 si hubo un error, de lo contrario 1
 */
int controller_AsignarTotales(LinkedList* pArrayListServicio);

/** Filtra los servicios del tipo seleccionado de la lista y los coloca en una nueva, luego
 *  guarda dicha lista en un nuevo archivo .csv
 *
 * @param pArrayListServicio LinkedList* puntero a la lista de servicios
 * @param path char* archivo donde guardar la nueva lista
 * @return retorna 0 si hubo un error, de lo contrario 1
 */
int controller_filterByType(LinkedList* pArrayListServicio, char* path);
