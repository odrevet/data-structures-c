#include "stack.h"


void stack_push(stack* pS, void* data){
  stack pNewElem = malloc(sizeof(element));
  pNewElem->data = data;
  pNewElem->next = (void*)*pS;
  *pS = pNewElem;
}

element* stack_pop(stack* pS){
  element* pBrowse = *pS;
  if (pBrowse != NULL) {
    *pS = (element*)pBrowse->next;
    free (pBrowse);
  }
}

void stack_clear(stack* pS){
  element* pBrowse;

  while (*pS != NULL) {
    pBrowse = *pS;
    *pS = (element*)(*pS)->next;
    free(pBrowse);
  }

  *pS = NULL;
}

void stack_browse(stack S, void(*fctBrowse)(void*)){
  while (S) {
    fctBrowse(S);
    S = (stack)S->next;
  }
}

size_t stack_count(stack S){
  int number=0;
  element* pFirstElem = S;
  while (pFirstElem) {
    number++;
    pFirstElem = (element*)pFirstElem->next;
  }

  return number;
}
