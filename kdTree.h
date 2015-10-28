#ifndef KDTREE_H
#define KDTREE_H

#include <stdlib.h>

#include "element.h"

/**
   @author DREVET Olivier

   kdTree est un arbre spécialisé
   <img src="kdTree.png"/>
*/

/**
   Ajoute un node_bin au debut
   <img src="kdTree_push_front.png"/>

   @version 1
   @param pointeur sur le node_bin racine.
   @param type générique a ajouter.
   @param taille de chaque element
   @param nombre de dimension du kdtree
   @param pointeur sur une fonction de comparaison
   @return pointeur sur la nouvelle tête de liste.

*/
node_bin* kdTree_push(node_bin* pRoot, void* data, size_t size, size_t nbDimension, char(*fctCmp)(const void*, const void*));


/**
 */
void kdTree_erase(node_bin* nodeToErase);


#endif
