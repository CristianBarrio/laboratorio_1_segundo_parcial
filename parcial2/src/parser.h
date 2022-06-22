/*
 * parser.h
 *
 *  Created on: 19 jun. 2022
 *      Author: Cristian
 */

#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Servicio.h"

#endif /* PARSER_H_ */

/** \brief Parsea los datos los datos de los servicios desde el archivo data.csv
 *
 * @param pFile FILE* archivo a parsear
 * @param pArrayListServicio LinkedList* puntero a la lista de servicios
 * @return retorna 0 si hubo un problema, de lo contrario 1
 */
int parser_ServiceFromText(FILE* pFile , LinkedList* pArrayListServicio);
