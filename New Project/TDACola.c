// Archivo de Código Fuente: TDACola.c -versión: 1.0.0+build20130221
/******************************************************************************
 *  Instituto de Formación Técnica Superior N°18
 *  Técnico Superior en Análisis de Sistemas
 *  Mansilla 3648, Ciudad Autónoma de Buenos Aires
 *  ---------------------------------------------------------------------------
 *  Materia: Estructura de Datos
 *  Ciclo Lectivo: 2013
 *  Docente: Colombo Viña, Leandro E. <estructura AT ifts18 DOT edu DOT ar>
 *
 *  Implementación de un TDA Cola con una Lista Simplemente Encadenada.
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "TDACola.h"

void clrscr(void)
{
    /** This function clear de screen console. It uses CLS for Windows and
    clear for Linux OS.*/
    if (system("CLS")) system("clear"); // Bad Thing to do, but it works!
}

void pause(void)
{
    /** This function waits for the user to press ENTER to continue */
    printf("\n\n\n\n\n\t\t\t\t\t     Presione <ENTER> para continuar...");
    fflush(stdin);
    fgetc(stdin);
    fflush(stdin);
//    system("pause");
}

int isCreated(QUEUE *pQueue)
{
    /** Check if the QUEUE is created. Returns 1 if the QUEUE is created and 0
     if is not. */
    if(pQueue == NULL)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

int createQueue(QUEUE **pQueue)
{
    /** This function recives pFirst & pLast pointers and set them to NULL. */
    if(isCreated(*pQueue))
    {
        return FALSE;
    }
    else
    {
        *pQueue = (QUEUE*)malloc(sizeof(QUEUE));
        if(*pQueue != NULL)
        {
            (*pQueue)->pFirst = NULL;
            (*pQueue)->pLast = NULL;
            (*pQueue)->size = 0;
        }
        else
        {
            return ERROR;
        }
        return TRUE;
    }
}

int isEmpty(QUEUE *pQueue)
{
    /** If size is 0 the QUEUE is EMPTY. */
    return (pQueue->size == 0);
}

void showQueue(QUEUE *pQueue)
{
    /** Prints data and points forward while pointer->next is not NULL. */
    LINK pAux = pQueue->pFirst;

    while(pAux != pQueue->pLast)
    {
        printf("%d -> ", pAux->data);
        pAux =  pAux->next;
    }
    printf("%d -> NULL.\n", pQueue->pLast->data);
}


DATA_TYPE readData(void)
{
    /** This function ask the user to input the data. */
    DATA_TYPE data;

    printf("Ingrese el número: ");
    scanf("%d", &data);
    return data;
}

LINK newNode(DATA_TYPE data)
{
    /** This function receives the data and creates a node for it. */
    LINK pNewNode;

    pNewNode = (LINK) malloc(sizeof(NODE));
    if(pNewNode)
    {
        pNewNode->data = data;
        pNewNode->next = NULL;
    }
    return pNewNode;
}

void enqueue(QUEUE **pQueue, DATA_TYPE data)
{
    /** This function enqueue the new node at the end of the QUEUE. */
    LINK pAux;

    pAux = newNode(data);
    if(pAux!=NULL)
    {
        if((*pQueue)->pFirst != NULL) // Si no es el primer elemento
        {
//            (*pQueue)->pLast->next = pAux;
//            (*pQueue)->pLast = pAux;
//            (*pQueue)->pLast->next = NULL;

            pAux->next = (*pQueue)->pFirst;
            (*pQueue)->pFirst = pAux;
            
        }
        else
        {
            (*pQueue)->pFirst = (*pQueue)->pLast = pAux;
            pAux->next = NULL;
        }
        (*pQueue)->size++;
    }
}

void dequeue(QUEUE **pQueue)
{
    LINK pToRemove;

    pToRemove = (*pQueue)->pFirst;
    (*pQueue)->pFirst = (*pQueue)->pFirst->next;
    if((*pQueue)->pFirst == NULL)
    {
        (*pQueue)->pLast = NULL;
    }
    pToRemove->next = NULL;
    free(pToRemove);
    (*pQueue)->size--;
}

DATA_TYPE front(QUEUE *pQueue)
{
    return pQueue->pFirst->data;
}
