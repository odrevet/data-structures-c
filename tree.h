#ifndef TREE_H
#define TREE_H

#include <stdlib.h>

#include "element.h"

/**
    @author DREVET Olivier


    Effacer tout.
    cette fonction doit �tre appel� kdTree_clear(&pRootNode);
    puisque qu'elle efface tout les �l�ments puis met l'& du pointeur
    de t�te de liste � NULL.

    @version 0
    @todo cette foncton est a implementer
    @param [in, out] ppRootNode Pointeur de pointeur sur node_bin

*/
void tree_clear(node** ppRootNode);


/**
    Compte le nombre de �l�ment(s).

    @version 0
    @param pointeur sur le premier node_bin.
    @return nombre d'�l�ment(s) dans la liste
*/
int tree_count(node* pRootNode);


#endif
