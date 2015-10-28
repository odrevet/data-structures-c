#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <stdlib.h>

#include "element.h"

/**
    @author DREVET Olivier


    doubleLinkedList est une liste simplement chain�e.
    <img src="doubleLinkedList.png"/>
*/


/**
    renvoi l'�l�ment au num�ro indiqu�
*/
element_double* at(element_double* pFirstElem, size_t loc);


/**
    Ajoute un element_double au debut
    <img src="doubleLinkedList_push_front.png"/>

    @version 0
    @param pointeur sur le premier element_double.
    @param type g�n�rique a ajouter.
    @return pointeur sur la nouvelle t�te de liste.
    Cette fonction doit �tre appel� : pFirstElem = doubleLinkedList_push_front(pFirstElem, "type chaine");

*/
element_double* doubleLinkedList_push_front(element_double* pFirstElem, void* data);


/**
    Ajoute un element_double � la fin
    <img src="doubleLinkedList_push_back.png"/>

    @param pointeur sur le premier element_double.
    @param type g�n�rique a ajouter.
    @return pointeur sur l'�ventuelle nouvelle t�te de liste (si la liste �t� vide).
*/
element_double* doubleLinkedList_push_back(element_double* pFirstElem, void* data);


/**
    Insert un �l�ment � une position donn�e.
    Si la position donn�e est sup�rieur au nombre
    d'�l�ments, le nouvel �l�ment est ajout� � la fin
    de la liste.

    @version 0
    @todo Cette fonction est a impl�menter
    @param pointeur sur le premier element_double.
    @param type g�n�rique a ajouter.
    @param position dans la liste.

*/
void doubleLinkedList_insert_at(element_double* pFirstElem, void* data, size_t loc);


/**
    @version 0
    @todo Cette fonction est a corriger
    @bug l'�l�ment est mal ajout� du a une faute dans l'algo
    Insert un element_double tri� selon le pointeur de fonction pass� en parametre
*/
void* doubleLinkedList_insert_sorted(element_double* pFirstElem, short(*fctCmp)(const void*, const void*), void* data);


/**
    Efface et renvoi l'element_double de t�te.

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
    cette fonction doit �tre appel� doubleLinkedList_clear(&pFirstElem);
    puisque qu'elle efface tout les �l�ments puis met l'& du pointeur
    de t�te de liste � NULL.

    @version 0
    @todo cette foncton est a implementer
    @param [in, out] ppFirstElem Pointeur de pointeur sur element_double

*/
void doubleLinkedList_clear(element_double** ppFirstElem);


/**
    Visualisation des �l�ments.

    @version 0
    @param pointeur sur le premier element_double.
    @param pointeur sur la fonction d'affichage
*/
void doubleLinkedList_browse(element_double* pFirstElem, void(*fctBrowse(const void*)));


/**
    Compte le nombre d'element_doubles.

    @param pointeur sur le premier element_double.
    @return nombre d'�l�ment(s) dans la liste
*/
int doubleLinkedList_count(element_double* pFirstElem);


#endif
