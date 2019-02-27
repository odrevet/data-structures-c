#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>

#include "element.h"

/**
   @author DREVET Olivier
   @summary Simply linked list
*/


/**
   @summary get an element at position `loc`
   @param pointer on the first element
   @param location where to get the element
   @return pointer on the element at index `loc` or NULL if out of bound

*/
element* linkedList_at(element* pFirstElem, size_t loc);


/**
   @summary add an ellement at the front of the list
   pFirstElem = linkedList_push_front(pFirstElem, "My data");
   @param pointer on the first element
   @param data to add
   @return pointer on the new first element
*/
element* linkedList_push_front(element* pFirstElem, void* data);


/**
   @summary add an element at the end of the list
   @param pointer on the first element
   @param data to add
   @return if the list were empty, return pointer on new head. return NULL otherwise.
*/
element* linkedList_push_back(element* pFirstElem, void* data);

/**
   @summary insert an element at `loc`.
   @param pointer on the first element
   @param data to add
   @param location where to add

*/
void linkedList_insert_at(element** pFirstElem, void* data, size_t loc);


/**
   @summary insert an element at position as sorted by the fctCmp function
   @param pointer on the first element
   @param sort function
   @param data to add
*/
void linkedList_insert_sorted(element** pFirstElem, char(*fctCmp)(const void*, const void*), void* data);


/**
   @summary clear the list, set head to NULL
   @param pointer of pointer on the first element
*/
void linkedList_clear(element** ppFirstElem);


/**
   @summary callback on each element of the list
   @param pointer on the first element
   @param callback function
*/
void linkedList_browse(element* pFirstElem, void(*fctBrowse(const void*)));


/**
   @summary count how many element is in the list
   @param pointer on the first element
   @return number of element in the list
*/
size_t linkedList_count(element* pFirstElem);


#endif
