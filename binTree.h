#ifndef BINTREE_H
#define BINTREE_H

#include <stdlib.h>

#include "element.h"

/**
    @author DREVET Olivier


    Un arbre binaire est un type d'aborescence sp�ciale o� chaque noeud �
    aucun, un, ou deux fils.

    <img src="binTree.png"/>

    les fonctions suivantes s'appliques � tout les arbres binaires, et attendent
    un noeud racine en parametre.

    Les arbres binaires utilisables sont :

    - Implement� dans cette version :
        - kdTree.

    - Non encore implement� :
        - binSearchTree
        - exprTree
        - huffmanTree
        - avlTree
        - redBlackTree
*/


/**
    Avec un parcours pr�fix�, le parcours de l'arbre est :
    - Traiter la racine.
    - Traiter le sous arbre gauche.
    - Traiter le sous arbre droit.

    @version 1
*/
void binTree_prefixBrowse(node_bin* pParent, void(*fct(void*)));


/**
    Avec un parcours postfix�, le parcours de l'arbre est :
    - Traiter le sous arbre gauche.
    - Traiter le sous arbre droit.
    - Traiter la racine.

    @version 1
*/
void binTree_postfixBrowse(node_bin* pParent, void(*fct(void*)));


/**
    Avec un parcours infix�, le parcours de l'arbre est :
    - Traiter le sous arbre gauche.
    - Traiter la racine.
    - Traiter le sous arbre droit.

    @version 1
*/
void binTree_infixBrowse(node_bin* pParent, void(*fct(void*)));


/**
    Effectue un parcours en largeur, c'est � dire niveau par niveau.

    @version 0
    @todo cette foncton est a implementer
*/
void binTree_widthBrowse(node_bin* pParent, void(*fct(void*)));


/**
    Effacer tout.
    cette fonction doit �tre appel� kdTree_clear(&pRootNode);
    puisque qu'elle efface tout les �l�ments puis met l'& du pointeur
    de t�te de liste � NULL.

    @version 0
    @todo cette foncton est a implementer
    @param [in, out] ppRootNode Pointeur de pointeur sur node_bin

*/
void binTree_clear(node_bin** ppRootNode);


/**
    Compte le nombre de �l�ment(s).

    @version 0
    @param pointeur sur le premier node_bin.
    @return nombre d'�l�ment(s) dans la liste
*/
int binTree_count(node_bin* pRootNode);


#endif
