#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>

#include "element.h"

/**
    @author DREVET Olivier


    linkedList est une liste simplement chainée.
    <img src="linkedList.png"/>
*/


/**
    renvoi l'élément au numero indiqué

    @version 1
    @param pointeur sur le premier element.
    @param localisation du pointeur
    @return pointeur sur l'élément ou NULL s'il n'est pas trouvé (localisation superieur au nombre d'éléments)
*/
element* linkedList_at(element* pFirstElem, size_t loc);


/**
    Ajoute un element au debut
    <img src="linkedList_push_front.png"/>

    @version 1
    @param pointeur sur le premier element.
    @param type générique a ajouter.
    @return pointeur sur la nouvelle tête de liste.
    Cette fonction doit être appelé : pFirstElem = linkedList_push_front(pFirstElem, "type chaine");

*/
element* linkedList_push_front(element* pFirstElem, void* data);


/**
    Ajoute un element à la fin
    <img src="linkedList_push_back.png"/>

    @version 1
    @param pointeur sur le premier element.
    @param type générique a ajouter.
    @return pointeur sur l'éventuelle nouvelle tête de liste (si la liste été vide).
*/
element* linkedList_push_back(element* pFirstElem, void* data);


/**
    Insert un élément à une position donnée.
    Si la position donnée est supérieur au nombre
    d'éléments, le nouvel élément est ajouté à la fin
    de la liste.

    @version 1
    @param pointeur sur le premier element.
    @param type générique a ajouter.
    @param position dans la liste.

*/
void linkedList_insert_at(element** pFirstElem, void* data, size_t loc);


/**
    Insert un element trié selon le pointeur de fonction passé en parametre

    @version 1
*/
void linkedList_insert_sorted(element** pFirstElem, char(*fctCmp)(const void*, const void*), void* data);


/**
    Efface et renvoi l'element à une position

    @version 0
*/
element* linkedList_pop_at(size_t loc);


/**
    Efface et renvoi l'element de tête de liste.

    @version 1
    @todo retourner l'element supprimé
*/
element* linkedList_pop_front(element** pFirstElem);


/**
    Efface et renvoi l'element en queue de liste.

    @version 0
    @todo cette fonction est a implementer
*/
element* linkedList_pop_back(element* pFirstElem);


/**
    Effacer tout.
    cette fonction doit être appelé linkedList_clear(&pFirstElem);
    puisque qu'elle efface tout les éléments puis met l'& du pointeur
    de tête de liste à NULL.

    @version 1
    @param [out] ppFirstElem Pointeur de pointeur sur element

*/
void linkedList_clear(element** ppFirstElem);


/**
    Visualisation des éléments.

    @version 1
    @param pointeur sur le premier element.
    @param pointeur sur la fonction d'affichage
*/
void linkedList_browse(element* pFirstElem, void(*fctBrowse(const void*)));


/**
    Compte le nombre d'elements.
    @version 1
    @param pointeur sur le premier element.
    @return nombre d'élément(s) dans la liste
*/
size_t linkedList_count(element* pFirstElem);


#endif
