#ifndef COMMON_H
#define COMMON_H

/**
   @brief common to all test routines
*/

#include <stdio.h>
#include <stdlib.h>

#include "common.h"

#include "../src/element.h"

int askValue();
char cmp(int a, int b);

//view element content (when element data is an int)
void view(element* pElem);
void view_memory(element* pElem);

#endif
