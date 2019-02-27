#include "linkedList.h"

element* linkedList_at(element* pFirstElem, size_t loc) {
  size_t curPos = 0;
  element* pBrowse = pFirstElem;

  while (pBrowse->next != NULL || curPos < loc) {
    pBrowse = (element*)pBrowse->next;
    curPos++;
  }

  return pBrowse;
}

element* linkedList_push_front(element* pFirstElem, void* data) {
  element *pNewElem = malloc(sizeof(element));  // allocate memory for the new element
  pNewElem->data = data;                        // set data
  pNewElem->next = (void*)pFirstElem;           // the new element point to the previous head
  return pNewElem;                              // return new head
}

element* linkedList_push_back(element* pFirstElem, void* data) {
  element* pNewElem = malloc(sizeof(element));  // allocate memory for the new element
  element* pBrowse;

  pNewElem->data = data;
  pNewElem->next = NULL;                        // the last element point to NULL

  if (pFirstElem == NULL) {                     // if list is empty
    pFirstElem = pNewElem;                      // the new element is head
  }
  else {
    pBrowse = pFirstElem;                      // search  from head
    while (pBrowse->next != NULL) {            // browse to last element (the element that point to NULL)
      pBrowse = (element*)pBrowse->next;
    }
    pBrowse->next = (void*)pNewElem;        // add the new element next of tail element
  }

  return pFirstElem;
}

void linkedList_insert_at(element** pFirstElem, void* data, size_t loc) {
  element* pNewElem = malloc(sizeof(element));  // allocate memory for the new element
  pNewElem->data = data;

  element* tmp = NULL;
  element* pBrowse = *pFirstElem;

  int i=0;

  while (pBrowse && i < loc) {
    tmp = pBrowse;
    pBrowse = (element*)pBrowse->next;
    i++;
  }

  pNewElem->next = (void*)pBrowse;
  if (tmp) tmp->next = (void*)pNewElem;
  else *pFirstElem = pNewElem;
}

void linkedList_insert_sorted(element** pFirstElem, char(*fctCmp)(const void*, const void*), void* data) {
  element* pNewElem = malloc(sizeof(element));
  pNewElem->data = data;

  element* tmp = NULL;
  element* pBrowse = *pFirstElem;

  while (pBrowse && fctCmp(data, pBrowse->data)) {
    tmp = pBrowse;
    pBrowse = (element*)pBrowse->next;
  }

  pNewElem->next = (void*)pBrowse;
  if (tmp) tmp->next = (void*)pNewElem;
  else *pFirstElem = pNewElem;
}

void linkedList_clear(element **pFirstElem) {
  element* pBrowse;

  while (*pFirstElem != NULL) {
    pBrowse = *pFirstElem;
    *pFirstElem = (element*)(*pFirstElem)->next;
    free(pBrowse);
  }

  *pFirstElem = NULL;
}

void linkedList_browse(element* pFirstElem, void(*fctBrowse(const void*))) {
  while (pFirstElem) {
    fctBrowse(pFirstElem);
    pFirstElem = (element*)pFirstElem->next;
  }
}

size_t linkedList_count(element* pFirstElem) {
  size_t number=0;
  while (pFirstElem) {
    number++;
    pFirstElem = (element*)pFirstElem->next;
  }

  return number;
}
