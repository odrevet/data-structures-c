#include <stdio.h>
#include <stdlib.h>

/**
   @brief linked list test routines
*/

//include GDS headers
#include <element.h>
#include <linkedList.h>

//include test common header
#include "common.h"

void linkedList(element *pFirstElem) {
  int choice;
  int value;
  do {
    printf("\
== ADD == \n\
1:Add to the front \n\
2:Add to the back\n\
== INSERT == \n\
3:Insert at location\n\
4:Insert sorted\n\
== REMOVE == \n\
8:Clear\n\\
== VIEW == \n\
9:View\n\
10:View memory\n\
11:Count\n\
12:Get element at location\\
n-1:Quit\n\n\
Your choice : ");
    scanf("%d", &choice);
    size_t loc;
    switch (choice) {
    case 1:             //Add to the front
      value = askValue();
      pFirstElem = linkedList_push_front(pFirstElem, value);
      printf("\n-- The value %d has been added to the begin of the list --\n\n", value);
      break;
    case 2:             //Add to the back
      value = askValue();
      pFirstElem = linkedList_push_back(pFirstElem, value);
      break;
    case 3:             //Insert at loc
      printf("At which position do you want to insert ? (from 0 to %d)\n", linkedList_count(pFirstElem));
      loc = askValue();
      if (loc < 0 || loc > linkedList_count(pFirstElem))
	printf("\nThe position entered is out of range. \nEnter a value between %d and %d\n", 0, linkedList_count(pFirstElem));
      else {
	value = askValue();
	linkedList_insert_at(&pFirstElem, value, loc);
      }
      break;
    case 4:             //Insert sorted
      value = askValue();
      linkedList_insert_sorted(&pFirstElem, cmp, value);
      break;
    case 8:             //Clear
      linkedList_clear(&pFirstElem);
      break;
    case 9:             //View
      linkedList_browse(pFirstElem, view);
      break;
    case 10:            //View memory
      linkedList_browse(pFirstElem, view_memory);
      break;
    case 11:            //Count
      printf("\n-- There are %d element(s) in the list -- \n\n", linkedList_count(pFirstElem));
      break;
    case 12:            //At
      printf("At which position do you want to get an element ? \n");
      loc = askValue();
      printf("\n-- Got the element-- \n\n");
      view_memory(linkedList_at(pFirstElem, loc));
      break;
    }
  } while (choice != -1);
}

int main(void){
  element *pFirstElem = NULL;
  linkedList(pFirstElem);

  //clear memory
  linkedList_clear(&pFirstElem);
}
