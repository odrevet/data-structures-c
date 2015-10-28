#include "kdTree.h"


node_bin* kdTree_push(node_bin* pRoot, void* data, size_t size, size_t nbDimension, char(*fctCmp)(const void*, const void*))
{
    static size_t currentDimension;

    if(pRoot == NULL){
        pRoot = malloc(sizeof(node_bin));
        pRoot->data = data;
        pRoot->left = pRoot->right = NULL;
    }
    else{
        if(fctCmp(pRoot->data + size * currentDimension, data + size * currentDimension)){
            currentDimension = (currentDimension + 1) % nbDimension;
            pRoot->left = kdTree_push(pRoot->left, data, size, nbDimension, fctCmp);
        }
        else{
            currentDimension = (currentDimension + 1) % nbDimension;
            pRoot->right = kdTree_push(pRoot->right, data, size, nbDimension, fctCmp);
        }
        currentDimension = 0;
    }

    return pRoot;
}


void kdTree_erase(node_bin* nodeToErase)
{

}

