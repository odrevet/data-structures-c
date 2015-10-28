#ifndef ELEMENT_H
#define ELEMENT_H

/**
   @author DREVET Olivier


*/


typedef struct{
  void* data;
  struct element* next;
}element;


typedef struct{
  void* data;
  struct element_double* prev;
  struct element_double* next;
}element_double;


typedef struct{
  void* data;
  struct node_bin* link;
}node;


typedef struct{
  void* data;
  struct node_bin* left;
  struct node_bin* right;
}node_bin;


/* Les deux structures element_double et node_bin sont les mêmes mais sont
   cependant implémentées pour differancier les terminologies.

   Dans une prochaine version moins 'didactique' mais plus optimisé, il
   n'y aura qu'une structure :

   typedef struct{
   void* data;
   struct element* link;
   }element;

   ou link sera soit un simple element, soit un tableau de 2 element pour les
   liste doublement chainées ou les arbres binaires, soit plus d'elements pour
   de nouvelles structures (quadTree, ocTree).

   La bonne utilisation de cette futur structure sera à la charge de l'utilisateur.

*/


#endif
