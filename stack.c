#include "stack.h"


void stack_push(stack* pS, void* data)
{
    stack pNewElem = malloc(sizeof(element));  /* Declaration et allocation du nouvel element */
    pNewElem->data = data;                     /* Attribution de la valeur */
    pNewElem->next = *pS;                      /* Le nouvel element pointe maintenant vers l'ancienne tête de liste */
    *pS = pNewElem;                            /* Le désormé premier element prend l'@ du nouvel element (car l'ajout se fait en debut de liste)*/
}


element* stack_pop(stack* pS)
{
	element* pBrowse = *pS;                         /* Memorisation de l'adresse du premier élément */
    if (pBrowse != NULL) {
        *pS = pBrowse->next;
        free (pBrowse);
    }
}


void stack_clear(stack* pS)
{
    element* pBrowse;

    while (*pS != NULL) {
        pBrowse = *pS;
        *pS = (*pS)->next;
        free(pBrowse);
    }

    *pS = NULL;
}


void stack_browse(stack S, void(*fctBrowse)(void*))
{
    while (S) {
        fctBrowse(S);
        S = S->next;
    }
}


size_t stack_count(stack S)
{
    int number=0;
    element* pFirstElem = S;
    while (pFirstElem) {
        number++;
        pFirstElem = pFirstElem->next;
    }

    return number;
}
