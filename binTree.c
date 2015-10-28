#include "binTree.h"


void binTree_prefixBrowse(node_bin* pParent, void(*fct(void*)))
{
  if(pParent != NULL){
    fct(pParent);
    binTree_prefixBrowse(pParent->left, fct);
    binTree_prefixBrowse(pParent->right, fct);
  }
}


void binTree_postfixBrowse(node_bin* pParent, void(*fct(void*)))
{
  if(pParent != NULL){
    binTree_postfixBrowse(pParent->left, fct(pParent->left));
    binTree_postfixBrowse(pParent->right, fct(pParent->right));
    fct(pParent);
  }
}


void binTree_infixBrowse(node_bin* pParent, void(*fct(void*)))
{
  if(pParent != NULL){
    binTree_infixBrowse(pParent->left, fct(pParent->left));
    fct(pParent);
    binTree_infixBrowse(pParent->right, fct(pParent->right));
  }
}


void binTree_widthBrowse(node_bin* pParent, void(*fct(void*)))
{

}


void binTree_clear(node_bin** ppRootNode)
{

}


int binTree_count(node_bin* pRootNode)
{

}
