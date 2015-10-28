#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

#include "element.h"


/**
   @author DREVET Olivier


   stack (pile) : First In First Out, Dernier Arrivé, premier sortie.
   Comme poser des assiettes les unes sur les autres.
   <img src="stack.png"/>
*/


typedef element* stack;     /// Une pile est un pointeur sur le premier élément


/**
   Ajoute un element (empile) en tête de liste,
   cette fonction est algorithmiquement identique a linkedList_push_front.
   <img src="stack_push.png"/>

   @version 1
*/
void stack_push(stack* pS, void* data);


/**
   Enleve un element (dépile)
   cette fonction est algorithmiquement identique a linkedList_pop_front
   <img src="stack_pop.png"/>

   @version 1
*/
element* stack_pop(stack* pS);


/**
   Efface toute la pile

   @version 1
*/
void stack_clear(stack* pS);


/**
   Visualisation

   @version 1
*/
void stack_browse(stack S, void(*fctBrowse)(void*));


/**
   Compte le nombre d'elements

   @version 1
*/
size_t stack_count(stack S);


#endif
