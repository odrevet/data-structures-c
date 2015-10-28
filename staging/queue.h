#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

#include "element.h"


/**
    @author DREVET Olivier


    queue (file) : First In First Out, ou Premier Entré Premier Sortie.
    Comme dans une file d'attente.
    <img src="queue.png"/>
*/


typedef struct
{
    element* front;
    element* back;
}queue;


/**
    Initialise la file a NULL
*/
queue queue_new();


/**
    Ajoute un element au debut
    <img src="queue_push.png"/>

    @version 0
*/
element* queue_push(queue Q, void* data);


/**
    Retire un element
    <img src="queue_pop.png"/>

    @version 0
*/
element* queue_pop(queue Q);


/**
    Efface tout

    @version 0
*/
void queue_clear(queue* pQ);


/**
    Visualisation de la mémoire

    @version 0
*/
void queue_browse(queue Q, void (*fctBrowse)(void*));



/**
    Compte le nombre d'elements

    @version 0
*/
size_t queue_count(queue Q);


#endif
