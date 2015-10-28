#include "common.h"

int askValue() {
  int value;
  printf("Enter a value : ");
  scanf("%d", &value);
  return value;
}

char cmp(int a, int b) {
  printf("cmp %d avec %d", a, b);
  return(a<=b)?0:1;
}

void view(element* pElem) {
  printf("\n--  %d  -- \n", pElem->data);
}

void view_memory(element* pElem) {
  printf("                 ----------------\n &Ox%p --> |    %d    |   |--> &Ox%p\n                 ----------------\ \n", pElem, pElem->data, pElem->next);
}

