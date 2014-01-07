#ifndef BINTREE_H
#define BINTREE_H

#include <stdlib.h>

#include "element.h"

/**
    @author DREVET Olivier


    Un arbre binaire est un type d'aborescence spéciale où chaque noeud à
    aucun, un, ou deux fils.

    <img src="binTree.png"/>

    les fonctions suivantes s'appliques à tout les arbres binaires, et attendent
    un noeud racine en parametre.

    Les arbres binaires utilisables sont :

    - Implementé dans cette version :
        - kdTree.

    - Non encore implementé :
        - binSearchTree
        - exprTree
        - huffmanTree
        - avlTree
        - redBlackTree
*/


/**
    Avec un parcours préfixé, le parcours de l'arbre est :
    - Traiter la racine.
    - Traiter le sous arbre gauche.
    - Traiter le sous arbre droit.

    @version 1
*/
void binTree_prefixBrowse(node_bin* pParent, void(*fct(void*)));


/**
    Avec un parcours postfixé, le parcours de l'arbre est :
    - Traiter le sous arbre gauche.
    - Traiter le sous arbre droit.
    - Traiter la racine.

    @version 1
*/
void binTree_postfixBrowse(node_bin* pParent, void(*fct(void*)));


/**
    Avec un parcours infixé, le parcours de l'arbre est :
    - Traiter le sous arbre gauche.
    - Traiter la racine.
    - Traiter le sous arbre droit.

    @version 1
*/
void binTree_infixBrowse(node_bin* pParent, void(*fct(void*)));


/**
    Effectue un parcours en largeur, c'est à dire niveau par niveau.

    @version 0
    @todo cette foncton est a implementer
*/
void binTree_widthBrowse(node_bin* pParent, void(*fct(void*)));


/**
    Effacer tout.
    cette fonction doit être appelé kdTree_clear(&pRootNode);
    puisque qu'elle efface tout les éléments puis met l'& du pointeur
    de tête de liste à NULL.

    @version 0
    @todo cette foncton est a implementer
    @param [in, out] ppRootNode Pointeur de pointeur sur node_bin

*/
void binTree_clear(node_bin** ppRootNode);


/**
    Compte le nombre de élément(s).

    @version 0
    @param pointeur sur le premier node_bin.
    @return nombre d'élément(s) dans la liste
*/
int binTree_count(node_bin* pRootNode);


#endif
