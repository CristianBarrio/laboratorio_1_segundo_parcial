/*
 * LinkedList.c
 *
 *  Created on: 19 jun. 2022
 *      Author: Cristian
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = NULL;

    this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL)
    {
    	this->size = 0;
    	this->pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode = NULL;

	if(this != NULL)
	{
		int len = ll_len(this);
		if(nodeIndex >= 0 && nodeIndex < len)
		{
			pNode = this->pFirstNode;

			while(nodeIndex > 0)
			{
				pNode = pNode->pNextNode;
				nodeIndex--;
			}
		}
	}

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex, void* pElement)
{
    int returnAux = -1;
    Node* newNode = NULL;
    Node* previousNode = NULL;

    if(this != NULL)
    {
    	int len = ll_len(this);
    	if(nodeIndex >= 0 && nodeIndex <= len)
    	{
			newNode = (Node*) malloc(sizeof(Node));

			if(newNode != NULL)
			{
				newNode->pElement = pElement;
				newNode->pNextNode = getNode(this, nodeIndex);

				if(nodeIndex == 0)
				{
					this->pFirstNode = newNode;
				}else
				{
					previousNode = getNode(this, nodeIndex - 1);
					previousNode->pNextNode = newNode;
				}

				this->size++;

				returnAux = 0;
			}
    	}
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex, void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}

/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	int len = ll_len(this);
    	addNode(this, len, pElement);
    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* node = NULL;

    if(this != NULL)
    {
    	int len = ll_len(this);
    	if(index >= 0 && index < len)
    	{
			node = getNode(this, index);

			if(node != NULL)
			{
				returnAux = node->pElement;
			}
    	}
    }

    return returnAux;
}

/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    Node* auxNode = NULL;

    if(this != NULL)
    {
		int len = ll_len(this);
    	if(index >= 0 && index < len)
    	{
			auxNode = getNode(this, index);

			if(auxNode != NULL)
			{
				auxNode->pElement = pElement;
				returnAux = 0;
			}
    	}
    }

    return returnAux;
}

/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this, int index)
{
    int returnAux = -1;
    Node* nodoARemover = NULL;
    Node* nodoAnterior = NULL;

    if(this != NULL)
    {
		int len = ll_len(this);
    	if(index >= 0 && index < len)
    	{
			nodoARemover = getNode(this, index);

			if(nodoARemover != NULL)
			{
				if(index == 0)
				{
					this->pFirstNode = nodoARemover->pNextNode;

				}else
				{
					nodoAnterior = getNode(this, index - 1);
					nodoAnterior->pNextNode = nodoARemover->pNextNode;
				}

				free(nodoARemover);
				this->size--;
				returnAux = 0;

			}
    	}
    }

    return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	while(ll_len(this) > 0)
    	{
    		ll_remove(this, 0);
    	}

    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(!ll_clear(this))
    	{
			free(this);
			returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	int len = ll_len(this);
    	for(int i = 0; i < len; i++)
    	{
    		if(ll_get(this,i) == pElement)
    		{
    			returnAux = i;
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	int len = ll_len(this);
    	returnAux = 0;

    	if(len == 0)
    	{
    		returnAux = 1;
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	int len = ll_len(this);

    	if(index >= 0 && index <= len)
    	{
    		addNode(this, index, pElement);
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this != NULL)
    {
    	int len = ll_len(this);

    	if(index >= 0 && index < len)
    	{
    		returnAux = ll_get(this,index);
    		ll_remove(this,index);
    	}
    }

    return returnAux;
}

/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = 0;
    	if(ll_indexOf(this,pElement) != -1)
    	{
    		returnAux = 1;
    	}
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this, LinkedList* this2)
{
    int returnAux = -1;

    if(this != NULL && this2 != NULL)
    {
    	int len = ll_len(this2);
    	returnAux = 1;

    	for(int i = 0; i < len; i++)
    	{
    		if(!ll_contains(this,ll_get(this,i)))
    		{
    			returnAux = 0;
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
    	int len = ll_len(this);
    	if(from < to && from >= 0 && to <= len)
    	{
    		cloneArray = ll_newLinkedList();
    		if(cloneArray != NULL)
    		{
    			for(int i = from; i < to; i++)
    			{
    				ll_add(cloneArray,ll_get(this,i));
    			}
    		}
    	}
    }

    return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
    	cloneArray = ll_subList(this,0,ll_len(this));
    }

    return cloneArray;
}

/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* auxI = NULL;
    void* auxJ = NULL;

    if(this != NULL && pFunc != NULL && order >= 0 && order <= 1)
    {
    	int len = ll_len(this);

    	for(int i = 0; i < len - 1; i++)
    	{
    		for(int j = i + 1; j < len; j++)
    		{
    			auxI = ll_get(this,i);
    			auxJ = ll_get(this,j);

    			if((pFunc(auxI,auxJ) > 0 && order) ||
    				(pFunc(auxI,auxJ) < 0 && !order))
    			{
    				ll_set(this,i,auxJ);
    				ll_set(this,j,auxI);
    			}
    		}
    	}

    	returnAux = 0;
    }

    return returnAux;

}

/**
 * Filtra la lista con una condici?n, recibiendo como par?metro
 * la funci?n que sera la encargada de decidir si cada elemento
 * cumple la condici?n (1) o no (0) y si se agrega a una nueva lista filtrada.
 * Verificando que tanto el puntero this como el puntero a la funcion
 * fn sean distintos de NULL. Retorna la nueva lista filtrada.
 */
LinkedList* ll_filter(LinkedList* this, int(*pFunc)(void*))
{
    LinkedList* filterArray = NULL;

    if(this != NULL && pFunc != NULL)
    {
        filterArray = ll_newLinkedList();
        int len = ll_len(this);
        if(filterArray != NULL)
        {
            for(int i = 0; i < len; i++)
            {
            	void* elementoFiltrado = ll_get(this,i);
                if(pFunc(elementoFiltrado))
                {
                    ll_add(filterArray,elementoFiltrado);
                }
            }
        }
    }

    return filterArray;
}

/**
 * Completa un campo del elemento, recibiendo como par?metro
 * la funci?n que sera la encargada de calcular el valor de ese campo.
 * Verificando que tanto el puntero this como el puntero a la funcion
 * pFunc sean distintos de NULL.
 * Retorna la lista completa.
 */
LinkedList* ll_map(LinkedList* this, void(*pFunc)(void* element))
{
	//LinkedList* listaTotales = NULL;

	if(this != NULL && pFunc != NULL)
	{
		int tam = ll_len(this);
		for(int i = 0; i < tam; i++)
		{
			pFunc(ll_get(this,i));
		}
	}

	return this;
}

