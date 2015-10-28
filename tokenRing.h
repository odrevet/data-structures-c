#ifndef TOKENRING_H
#define TOKENRING_H

#include <stdlib.h>

#include "element.h"

/**
   @author DREVET Olivier


   tokenRing est une liste simplement chainée.
   <img src="tokenRing.png"/>
*/


/**
   Ajoute un element au debut
   <img src="tokenRing_push.png"/>

   @version 0
*/
element* tokenRing_push(element* pFirstElem, void* data);


/**
   Insert un element a une position donnée

   @version 0
*/
element* tokenRing_insert_at(element* pFirstElem, void* data, size_t loc);


/**
   @version 0
*/
element* tokenRing_pop(element* pFirstElem);


/**
   @version 0
*/
void tokenRing_clear(element** pFirstElem);


/**
   Visualisation

   @version 0
*/
void tokenRing_browse(element* pFirstElem);


/**
   Compte le nombre d'elements
*/
size_t tokenRing_count(element* pFirstElem);


/**
   Transphorme un vecteur en token ring (le dernier element
   de la liste pointe vers le premier)
*/
void tokenRing_to_linkedList(element* pFirstElem);


#endif
