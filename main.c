/*
        Credit
DREVET Olivier (odrevet@gmail.com)

*/

#include <stdio.h>
#include <stdlib.h>

#include "element.h"
#include "linkedList.h"
#include "doubleLinkedList.h"
#include "queue.h"
#include "stack.h"
#include "tokenRing.h"
#include "binTree.h"
#include "kdTree.h"

/* fonction d'appuie */
/* Demande un entier (pour les differants ajouts) */
inline int askValue() {
    int value;
    printf("Enter a value : ");
    scanf("%d", &value);
    return value;
}

char cmp(int a, int b) {
    printf("cmp %d avec %d", a, b);
    return(a<=b)?0:1;
}

char cmp_p(int* a, int* b) {
    printf("cmp %d at %p with %d at %p\n", *a, a, *b, b);
    return(*a<=*b)?0:1;
}

void view(element* pElem) {
    printf("\n--  %d  -- \n", pElem->data);
}

void view_memory(element* pElem) {
    printf("                 ----------------\n &Ox%p --> |    %d    |   |--> &Ox%p\n                 ----------------\ \n", pElem, pElem->data, pElem->next);
}

void double_view(element_double* pElem) {
    printf("\n--  %d  -- \n", pElem->data);
}


void double_view_memory(element_double* pElem) {
    printf("                       ----------------\n &Ox%p -->  &Ox%p <--|   |    %d    |   |--> &Ox%p\n                       ----------------\ \n", pElem, pElem->prev, pElem->data, pElem->next);
}


void binTree_view_memory(node_bin* pElem) {
    printf("%p -> data : {%d}, left : %p, right : %p\n", pElem, pElem->data, pElem->left, pElem->right);
}


void binTree_view_memory_p(node_bin* pElem, size_t nbelem, size_t size) {
    size_t i = 0;
    char* cdata = pElem->data;

    printf("%p -> data : {\n", pElem);
    for(i;i<nbelem;i++)
        printf(" %d \n", cdata + (i * size));
    printf("_______________________________\n");
    printf("}\n%d\nleft child : %p right child : %p\n", pElem->left, pElem->right);
}


/* Procedures de tests des differantes structures de données*/
void linkedList(element *pFirstElem) {
    int choice;
    int value;
    do {
        printf("\n1:Add to the front \n2:Add to the back\n3:Insert at loc\n4:Insert sorted\n5:Remove to the front\n6:Remove to the back \n7:Remove at loc\n8:Clear\n9:View\n10:View memory\n11:Count\n12:Get element at loc\n-1:Main menu\n\nYour choice : ");
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
            printf("At which position do you want to insert ? \n");
            loc = askValue();
            if (loc < 0 || loc > linkedList_count(pFirstElem))
                printf("\nThe position entered is out of range. \nEnter a value between %d and %d", 0, linkedList_count(pFirstElem));
            else {
                value = askValue();
                linkedList_insert_at(&pFirstElem, value, loc);
            }
            break;
        case 4:             //Insert sorted
            value = askValue();
            linkedList_insert_sorted(&pFirstElem, cmp, value);
            break;
        case 5:             //Remove front
            linkedList_pop_front(&pFirstElem);
            break;
        case 6:             //Remove back
            linkedList_pop_back(pFirstElem);
            break;
        case 7:             //Remove at loc
            linkedList_pop_at(&pFirstElem);
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


element_double* doubleLinkedList(element_double* pFirstElem) {
    int choice;
    int value;
    do {
        printf("\n1:Add to the front \n2:Add to the back\n3:Insert at loc\n4:Insert sorted\n5:Remove to the front\n6:Remove to the back \n7:Remove at loc\n8:Clear\n9:View\n10:View memory\n11:Count\n-1:Main menu\n\nYour choice : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:             //Add to the front
            value = askValue();
            pFirstElem = doubleLinkedList_push_front(pFirstElem, value);
            printf("\n-- The value %d has been added to the begin of the list --\n\n", value);
            break;
        case 2:             //Add to the back
            value = askValue();
            pFirstElem = doubleLinkedList_push_back(pFirstElem, value);
            break;
        case 3:             //Insert at loc
            printf("At which position do you want to insert ? \n");
            size_t loc = askValue();
            if (loc < 0 || loc > doubleLinkedList_count(pFirstElem))
                printf("\nThe position entered is out of range. \nEnter a value between %d and %d", 0, linkedList_count(pFirstElem));
            else {
                value = askValue();
                doubleLinkedList_insert_at(pFirstElem, value, loc);
            }
            break;
        case 4:             //Insert sorted
            value = askValue();
            doubleLinkedList_insert_sorted(pFirstElem, cmp, value);
            break;
        case 5:             //Remove front
            printf("\n -- The front element (with the value %d) was removed  \n\n", doubleLinkedList_pop_front(pFirstElem)->data);
            break;
        case 6:             //Remove back
            printf("\n -- The back element (with the value %d) was removed  \n\n", doubleLinkedList_pop_back(pFirstElem)->data);
            break;
        case 7:             //Remove at loc
            //doubleLinkedList_pop_at(pFirstElem);
            break;
        case 8:             //Clear
            doubleLinkedList_clear(&pFirstElem);
            printf("\n -- The double linked list is now empty -- \n\n");
            break;
        case 9:             //View
            doubleLinkedList_browse(pFirstElem, double_view);
            break;
        case 10:            //View memory
            doubleLinkedList_browse(pFirstElem, double_view_memory);
            break;
        case 11:            //Count
            printf("\n-- There are %d element(s) in the list -- \n\n", doubleLinkedList_count(pFirstElem));
            break;
        }
    } while (choice != -1);
}


element* stack_test(element* pFirstElem) {
    int choice;
    int value;

    stack myStack = NULL;

    do {
        printf("\n1:Stack \n2:Unstack\n3:Clear\n4:View\n5:View memory\n-1:Main menu\nYour choice : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            value = askValue();
            stack_push(&myStack, value);
            break;
        case 2:
            stack_pop(&myStack);
            break;
        case 3:
            stack_clear(&myStack);
            break;
        case 4:
            stack_browse(myStack, view);
            break;
        case 5:
            stack_browse(myStack, view_memory);
            break;
        }
    } while (choice != -1);

    if (myStack != NULL) {
        while (choice != 'y' || choice != 'Y' || choice != 'n' || choice != 'N') {
            printf("The stack is still in memory, clear it y/n ?\n");
            scanf("%c", &choice);
        }
    }
}


element* queue_test(element* pFirstElem) {
    int choice;
    int value;

    queue myQueue;

    do {
        printf("\n1:Stack \n2:Unstack\n3:Clear\n4:View\n5:View memory\n-1:Main menu\nYour choice : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            value = askValue();
            queue_push(myQueue, value);
            break;
        case 2:
            value = queue_pop(myQueue);
            printf("%d was removed from the queue", value);
            break;
        case 3:
            queue_clear(&myQueue);
            break;
        case 4:
            queue_browse(myQueue, &view);
            break;
        case 5:
            queue_browse(myQueue, &view_memory);
            break;
        }
    } while (choice != -1);
}


element* tokenRing(element *pFirstElem) {
    int choice;
    int value;
    do {
        printf("\n1:Add \n2:Remove\n3:Clear\n4:Count\n5:View\n-1:Main menu\nYour choice : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            value = askValue();
            pFirstElem = tokenRing_push(pFirstElem, value);
            printf("\n-- The value %d has been added to the ring --\n\n", value);
            break;
        case 2:
            pFirstElem = tokenRing_pop(pFirstElem);
            break;
        case 3:
            tokenRing_clear(pFirstElem);
            break;
        case 4:
            printf("\n-- There are %d element(s) in the token ring -- \n\n", tokenRing_count(pFirstElem));
            break;
        case 5:
            tokenRing_browse(&view);
            break;
        }
    } while (choice != -1);

    if (pFirstElem == NULL) {

    }
}


node_bin* binTree(node_bin* pRoot) {
    int choice;
    int value;
    node_bin* tmp;

    do {
        printf("\n1:prefix browse\n2:postfix browse\n3:infix browse\n4:Width browse\n5:Clear\n-1:Previous menu\nYour choice : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            binTree_prefixBrowse(pRoot, binTree_view_memory);
            break;
        case 2:
            binTree_postfixBrowse(pRoot, binTree_view_memory);
            break;
        case 3:
            binTree_infixBrowse(pRoot, binTree_view_memory);
            break;
        case 4:
            binTree_widthBrowse(pRoot, binTree_view_memory);
            break;
        case 5:
            binTree_clear(pRoot);
        }
    } while (choice != -1);

    return pRoot;
}


node_bin* kdTree(node_bin* pRoot, int nbDimension) {
    int choice;

    do {
        int* value = malloc(nbDimension*sizeof(int));
        printf("\n1:Add \n2:Erase a node\n3:view\n4:binary trees common features (browse, clear...) \n-1:Main menu\nYour choice : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            for(choice=0;choice<nbDimension;choice++){
                value[choice] = askValue();
            }

            pRoot = kdTree_push(pRoot, value, sizeof(int), nbDimension, cmp_p);
            printf("\n-- The value(s) has been added to the kd tree %p--\n\n", pRoot);
            break;
        case 2:
            //kdTree_erase(pRoot);
            break;
        case 3:

            break;
        case 4:
            pRoot = binTree(pRoot);
            break;
        }

    } while (choice != -1);

/*
    if (pRoot != NULL) {
        choice = NULL;
        while (choice != 'y' || choice != 'Y' || choice != 'n' || choice != 'N') {
            printf("The kdTree is still in memory, clear it y/n ? ");
            scanf("%c", &choice);
            printf("\nyou entered : %d --> %c\n", choice, choice);
        }

        if(choice != 'y' || choice != 'Y'){
            //kdTree_erase(pRoot);
        }
    }
*/
}



int main() {
    int choice;
    int value;
    element* pFirstElem = NULL;
    element_double* pFirstElemDouble = NULL;
    node_bin* pRoot = NULL;

    do {
        printf("\n-- Sequential -- \n1 : Linked list\n2 : Double Linked list\n3 : Queue\n4 : Stack\n5 : Token ring\n\n--Binary trees--\n6 : KD tree\n\n-1 : Quit\n\nYour choice : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            linkedList(pFirstElem);
            break;
        case 2:
            doubleLinkedList(pFirstElemDouble);
            break;
        case 3:
            queue_test(pFirstElem);
            break;
        case 4:
            stack_test(pFirstElem);
            break;
        case 5:
            tokenRing(pFirstElem);
            break;
        case 6:
            printf("How many dimensions your kdTree has ? \n");
            value = askValue();
            kdTree(pRoot, value);
            break;
        }
    } while (choice != -1);

    printf("So long\n");
    return EXIT_SUCCESS;
}

