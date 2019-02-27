#include <stdio.h>
#include <stdlib.h>

/**
   @brief stack test routines
*/

//include GDS headers
#include <element.h>
#include <stack.h>

//include test common header
#include "common.h"

element* stack_test(stack *p_stack) {
  int choice;
  int value;

  do {
    printf("\n\
1:Stack\n\
2:Unstack\n\
3:Clear\n\
4:View\n\
5:View memory\n\
-1:Main menu\n\
Your choice : ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      value = askValue();
      stack_push(p_stack, value);
      break;
    case 2:
      stack_pop(p_stack);
      break;
    case 3:
      stack_clear(p_stack);
      break;
    case 4:
      stack_browse(*p_stack, view);
      break;
    case 5:
      stack_browse(*p_stack, view_memory);
      break;
    }
  } while (choice != -1);
}

int main(void){
  stack o_stack = NULL;
  stack_test(&o_stack);

  //clear memory
  stack_clear(&o_stack);
}
