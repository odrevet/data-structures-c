#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>

#include "element.h"

/**
    @author DREVET Olivier


    linkedList est une liste simplement chain�e.
    <img src="linkedList.png"/>
*/


/**
    renvoi l'�l�ment au numero indiqu�

    @version 1
    @param pointeur sur le premier element.
    @param localisation du pointeur
    @return pointeur sur l'�l�ment ou NULL s'il n'est pas trouv� (localisation superieur au nombre d'�l�ments)
*/
element* linkedList_at(element* pFirstElem, size_t loc);


/**
    Ajoute un element au debut
    <img src="linkedList_push_front.png"/>

    @version 1
    @param pointeur sur le premier element.
    @param type g�n�rique a ajouter.
    @return pointeur sur la nouvelle t�te de liste.
    Cette fonction doit �tre appel� : pFirstElem = linkedList_push_front(pFirstElem, "type chaine");

*/
element* linkedList_push_front(element* pFirstElem, void* data);


/**
    Ajoute un element � la fin
    <img src="linkedList_push_back.png"/>

    @version 1
    @param pointeur sur le premier element.
    @param type g�n�rique a ajouter.
    @return pointeur sur l'�ventuelle nouvelle t�te de liste (si la liste �t� vide).
*/
element* linkedList_push_back(element* pFirstElem, void* data);


/**
    Insert un �l�ment � une position donn�e.
    Si la position donn�e est sup�rieur au nombre
    d'�l�ments, le nouvel �l�ment est ajout� � la fin
    de la liste.

    @version 1
    @param pointeur sur le premier element.
    @param type g�n�rique a ajouter.
    @param position dans la liste.

*/
void linkedList_insert_at(element** pFirstElem, void* data, size_t loc);


/**
    Insert un element tri� selon le pointeur de fonction pass� en parametre

    @version 1
*/
void linkedList_insert_sorted(element** pFirstElem, char(*fctCmp)(const void*, const void*), void* data);


/**
    Efface et renvoi l'element � une position

    @version 0
*/
element* linkedList_pop_at(size_t loc);


/**
    Efface et renvoi l'element de t�te de liste.

    @version 1
    @todo retourner l'element supprim�
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
    cette fonction doit �tre appel� linkedList_clear(&pFirstElem);
    puisque qu'elle efface tout les �l�ments puis met l'& du pointeur
    de t�te de liste � NULL.

    @version 1
    @param [out] ppFirstElem Pointeur de pointeur sur element

*/
void linkedList_clear(element** ppFirstElem);


/**
    Visualisation des �l�ments.

    @version 1
    @param pointeur sur le premier element.
    @param pointeur sur la fonction d'affichage
*/
void linkedList_browse(element* pFirstElem, void(*fctBrowse(const void*)));


/**
    Compte le nombre d'elements.
    @version 1
    @param pointeur sur le premier element.
    @return nombre d'�l�ment(s) dans la liste
*/
size_t linkedList_count(element* pFirstElem);


#endif
