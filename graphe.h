#ifndef GRAPHE_H
#define GRAPHE_H

#include <stdlib.h>

#include "element.h"

/**
   @author DREVET Olivier


*/


typedef struct {
  struct summit* next;
  struct arc* pFirstArc;
  void* data;
}summit;

typedef struct {
  struct arc* next;
  struct summit* destination;
}arc;

#endif
