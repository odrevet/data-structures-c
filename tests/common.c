#include "common.h"

int askValue() {
  int value;
  printf("Enter a value : ");
  scanf("%d", &value);
  return value;
}

char cmp(int x, int y) {
  return(x <= y) ? 0 : 1;
}

void view(element* pElem) {
  printf("\n--  %d  -- \n", (intptr_t)pElem->data);
}

void view_memory(element* pElem) {
  printf("-----\n &Ox%p --> | %d |-----> &Ox%p\n \n", pElem, (intptr_t)pElem->data, pElem->next);
}
