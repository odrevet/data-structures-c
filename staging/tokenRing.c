#include "tokenRing.h"


element* tokenRing_push(element* pFirstElem, void* data) {
    element* pNewElem = malloc(sizeof(element));  /* Declaration et allocation du nouvel element */
    pNewElem->data = data;

    if (pFirstElem == NULL) {                     /* Cas si le token ring est vide */
        pFirstElem = pNewElem;                    /* Le premier (et unique) element du ring est le nouvel element */
        pFirstElem->next = pFirstElem;            /* Cet element pointe sur lui même */
    }
    else{
        pNewElem->next = pFirstElem->next;        /* Le nouvel element est placé après le premier*/
        pFirstElem->next = pNewElem;              /* Boucler */
    }
}


element* tokenRing_insert_at(element* pFirstElem, void* data, size_t loc)
{

}


element* tokenRing_pop(element* pFirstElem)
{

}


void tokenRing_clear(element** pFirstElem)
{

}


void tokenRing_browse(element* pFirstElem)
{

}


size_t tokenRing_count(element* pFirstElem)
{

}


void tokenRing_to_linkedList(element* pFirstElem)
{

}
