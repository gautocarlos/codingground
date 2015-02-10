#ifndef TDACOLA_H_INCLUDED
#define TDACOLA_H_INCLUDED

// Archivo de cabecera: TDACola.h -versión: 1.0.0+build20130221
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
/*
    Una cola es un contenedor de objetos que se insertan y se eliminan siguien-
    do el principio de: "Primero en Entrar, Primero en Salir" (FIFO: "First In,
    First Out"). En ese sentido puede decirse que una cola es una lista con
    restricciones en el alta (enqueue) y en la baja (dequeue).
    El Frente (FRONT) de la cola corresponde al elemento que está en primer
    lugar, es decir que es el que estuvo más tiempo en espera. Y el Fondo (END)
    de la cola corresponde al último elemento ingresado a la misma.
    Primitivas:
    CREAR: crea una cola vacía.
        - Precondiciones : no tiene.
        - Postcondiciones: una cola vacía preparada para ser usada.
    FRONT: retorna el valor del primer elemento de la cola
        - Precondiciones : la cola , ya creada, no debe estar vacía.
        - Postcondiciones: no tiene.
    ENQUEUE: da de alta en la cola a un elemento que se ubicará al fondo.
        - Precondiciones : la cola debe haber sido creada.
        - Postcondiciones: la cola modificada con la inserción del nuevo nodo.
    DEQUEUE: elimina el elemento del frente de la misma.
        - Precondiciones: la cola, ya creada, no debe estar vacía.
        - Postcondiciones: cola modificada por eliminación del elemento frente.
    EMPTY: devuelve un valor indicando si la cola está vacía.
        - Precondiciones : la cola debe haber sido creada.
        - Postcondiciones: no tiene.

    NOTA: También existen las llamadas COLAS con PRIORIDAD. En estas los ele-
    mentos se atienden en el orden indicado por una prioridad asociada a cada
    uno. Si varios elementos tienen la misma prioridad, se atenderán de modo
    convencional según la posición que ocupen.
 */

#define VACIA "WARNING: La Cola está vacía.\n"
#define CREAR "WARNING: Debe crear la Cola primero.\n"
#define STOP 1
#define CONTINUE 0
#define TRUE 1
#define FALSE 0
#define ERROR -1
#define FIRST_ELEMENT 1

// TDA Definition.
typedef int DATA_TYPE;
struct stNode {
    DATA_TYPE data;
    struct stNode *next;
};
typedef struct stNode NODE;
typedef NODE *LINK;

typedef struct {
    LINK pFirst;
    LINK pLast;
    int size;
} QUEUE;

void clrscr(void);
void pause(void);
int isCreated(QUEUE *);
int createQueue(QUEUE **);
int isEmpty(QUEUE *);
void showQueue(QUEUE *);
DATA_TYPE readData(void);
LINK newNode(DATA_TYPE);
void enqueue(QUEUE **, DATA_TYPE);
void dequeue(QUEUE **);
DATA_TYPE front(QUEUE *);

#endif // TDACOLA_H_INCLUDED
