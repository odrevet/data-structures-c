#ifndef TREE_H
#define TREE_H

#include <stdlib.h>

#include "element.h"

/**
    @author DREVET Olivier


    Effacer tout.
    cette fonction doit être appelé kdTree_clear(&pRootNode);
    puisque qu'elle efface tout les éléments puis met l'& du pointeur
    de tête de liste à NULL.

    @version 0
    @todo cette foncton est a implementer
    @param [in, out] ppRootNode Pointeur de pointeur sur node_bin

*/
void tree_clear(node** ppRootNode);


/**
    Compte le nombre de élément(s).

    @version 0
    @param pointeur sur le premier node_bin.
    @return nombre d'élément(s) dans la liste
*/
int tree_count(node* pRootNode);


#endif
