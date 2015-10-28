#include "linkedList.h"


element* linkedList_at(element* pFirstElem, size_t loc) {
  size_t curPos = 0;
  element* pBrowse = pFirstElem;       /* Pointeur de parcours (recherche � partir du debut jusqu'� la position) */

  while (pBrowse->next != NULL || curPos < loc) {
    pBrowse = pBrowse->next;
    curPos++;
  }

  return pBrowse;
}


element* linkedList_push_front(element* pFirstElem, void* data) {
  element *pNewElem = malloc(sizeof(element));  /* Declaration et allocation du nouvel element */
  pNewElem->data = data;                        /* Attribution de la valeur */
  pNewElem->next = pFirstElem;                  /* Le nouvel element pointe maintenant vers l'ancienne t�te de liste */

  return pNewElem;                              /* Le d�sorm� premier element prend l'@ du nouvel element (car l'ajout se fait en debut de liste)*/
}


element* linkedList_push_back(element* pFirstElem, void* data) {
  element* pNewElem = malloc(sizeof(element));  /* Declaration et allocation du nouvel element */
  element* pBrowse;                             /* Pointeur de parcours (recherche de la fin de la liste) */

  pNewElem->data = data;                        /* Attribution de la valeur */
  pNewElem->next = NULL;                        /* Le dernier element pointera vers NULL */

  if (pFirstElem == NULL) {                     /* Cas si la liste est vide */
    pFirstElem = pNewElem;                    /* Le nouvel element sera � la t�te de liste */
  } else {
    pBrowse = pFirstElem;                      /* Recherche � partir du debut */
    while (pBrowse->next != NULL) {            /* Navigue jusqu'au dernier element (c'est celui qui pointe vers NULL) */
      pBrowse = pBrowse->next;
    }
    pBrowse->next = pNewElem;                  /* Le dernier element de la liste pointe vers l'element a ajouter */
  }

  return pFirstElem;
}


void linkedList_insert_at(element** pFirstElem, void* data, size_t loc) {
  element* pNewElem = malloc(sizeof(element));                /* Declaration et allocation du nouvel element */
  pNewElem->data = data;

  element* tmp = NULL;
  element* pBrowse = *pFirstElem;

  int i=0;

  while (pBrowse && i < loc) {
    tmp = pBrowse;                  /* Retenir cet element */
    pBrowse = pBrowse->next;        /* Avancer d'un element */
    i++;
  }

  pNewElem->next = pBrowse;
  if (tmp) tmp->next = pNewElem;
  else *pFirstElem = pNewElem;
}


void linkedList_insert_sorted(element** pFirstElem, char(*fctCmp)(const void*, const void*), void* data) {
  element* pNewElem = malloc(sizeof(element));                /* Declaration et allocation du nouvel element */
  pNewElem->data = data;

  element* tmp = NULL;
  element* pBrowse = *pFirstElem;

  /* trouve la bonne place (quitte si arrive a la fin de la liste ou si fctCmp renvoie 0) */
  while (pBrowse && fctCmp(data, pBrowse->data)) {
    tmp = pBrowse;                  /* Retenir cet element */
    pBrowse = pBrowse->next;        /* Avancer d'un element */
  }

  pNewElem->next = pBrowse;
  if (tmp) tmp->next = pNewElem;
  else *pFirstElem = pNewElem;
}


element* linkedList_pop_at(size_t loc) {

}


element* linkedList_pop_front(element** pFirstElem) {
  if(*pFirstElem == NULL)
    return NULL;

  element* pBrowse = *pFirstElem;          //retenir la t�te en vue de l�effacement
  *pFirstElem = (*pFirstElem)->next;       //D�placement au prochain �l�ment
  free(pBrowse);
}


element* linkedList_pop_back(element* pFirstElem) {

}


void linkedList_clear(element **pFirstElem) {
  element* pBrowse;

  while (*pFirstElem != NULL) {
    pBrowse = *pFirstElem;
    *pFirstElem = (*pFirstElem)->next;
    free(pBrowse);
  }

  *pFirstElem = NULL;
}


void linkedList_browse(element* pFirstElem, void(*fctBrowse(const void*))) {
  while (pFirstElem) {
    fctBrowse(pFirstElem);
    pFirstElem = pFirstElem->next;
  }
}


size_t linkedList_count(element* pFirstElem) {
  size_t number=0;
  while (pFirstElem) {
    number++;
    pFirstElem = pFirstElem->next;
  }

  return number;
}

