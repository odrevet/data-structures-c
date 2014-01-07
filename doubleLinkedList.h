#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <stdlib.h>

#include "element.h"

/**
    @author DREVET Olivier


    doubleLinkedList est une liste simplement chainée.
    <img src="doubleLinkedList.png"/>
*/


/**
    renvoi l'élément au numéro indiqué
*/
element_double* at(element_double* pFirstElem, size_t loc);


/**
    Ajoute un element_double au debut
    <img src="doubleLinkedList_push_front.png"/>

    @version 0
    @param pointeur sur le premier element_double.
    @param type générique a ajouter.
    @return pointeur sur la nouvelle tête de liste.
    Cette fonction doit être appelé : pFirstElem = doubleLinkedList_push_front(pFirstElem, "type chaine");

*/
element_double* doubleLinkedList_push_front(element_double* pFirstElem, void* data);


/**
    Ajoute un element_double à la fin
    <img src="doubleLinkedList_push_back.png"/>

    @param pointeur sur le premier element_double.
    @param type générique a ajouter.
    @return pointeur sur l'éventuelle nouvelle tête de liste (si la liste été vide).
*/
element_double* doubleLinkedList_push_back(element_double* pFirstElem, void* data);


/**
    Insert un élément à une position donnée.
    Si la position donnée est supérieur au nombre
    d'éléments, le nouvel élément est ajouté à la fin
    de la liste.

    @version 0
    @todo Cette fonction est a implémenter
    @param pointeur sur le premier element_double.
    @param type générique a ajouter.
    @param position dans la liste.

*/
void doubleLinkedList_insert_at(element_double* pFirstElem, void* data, size_t loc);


/**
    @version 0
    @todo Cette fonction est a corriger
    @bug l'élément est mal ajouté du a une faute dans l'algo
    Insert un element_double trié selon le pointeur de fonction passé en parametre
*/
void* doubleLinkedList_insert_sorted(element_double* pFirstElem, short(*fctCmp)(const void*, const void*), void* data);


/**
    Efface et renvoi l'element_double de tête.

    @version 0
    @todo cette fonction est a implementer
*/
element_double* doubleLinkedList_pop_front(element_double* pFirstelement_double);


/**
    Efface et renvoi l'element_double de queue.

    @version 0
    @todo cette fonction est a implementer
*/
element_double* doubleLinkedList_pop_back(element_double* pFirstelement_double);


/**
    Effacer tout.
    cette fonction doit être appelé doubleLinkedList_clear(&pFirstElem);
    puisque qu'elle efface tout les éléments puis met l'& du pointeur
    de tête de liste à NULL.

    @version 0
    @todo cette foncton est a implementer
    @param [in, out] ppFirstElem Pointeur de pointeur sur element_double

*/
void doubleLinkedList_clear(element_double** ppFirstElem);


/**
    Visualisation des éléments.

    @version 0
    @param pointeur sur le premier element_double.
    @param pointeur sur la fonction d'affichage
*/
void doubleLinkedList_browse(element_double* pFirstElem, void(*fctBrowse(const void*)));


/**
    Compte le nombre d'element_doubles.

    @param pointeur sur le premier element_double.
    @return nombre d'élément(s) dans la liste
*/
int doubleLinkedList_count(element_double* pFirstElem);


#endif
