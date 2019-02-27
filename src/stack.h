#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

#include "element.h"

/**
   @author DREVET Olivier
   @summary stack: First In First Out
   always point on the first element
*/

typedef element* stack;

/**
   @summary stack an element
*/
void stack_push(stack* pS, void* data);

/**
   @summary remove an element
*/
element* stack_pop(stack* pS);

/**
   @summary claer the stack
*/
void stack_clear(stack* pS);

/**
   @summary callback function on all elements
*/
void stack_browse(stack S, void(*fctBrowse)(void*));

/**
   @summary count the number of element
*/
size_t stack_count(stack S);


#endif
