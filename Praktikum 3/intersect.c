#include<stdio.h>
#include "liststatik.h"
// #include "liststatik.c"

int main(){
    ListStatik arr1, arr2, arr3;
    readList(&arr1);
    readList(&arr2);
    CreateListStatik(&arr3);
    int i, j;
    // int l=0;
    for(i=0; i<listLength(arr1); i++){
        for(j=0; j<listLength(arr2); j++){
            // printf("%d -- %d\n", ELMT(arr1, i), ELMT(arr2, j));
            if(ELMT(arr1, i)==ELMT(arr2, j)){
                insertLast(&arr3, ELMT(arr1, i));
                // printf("%d\n", ELMT(arr1, i));
                // printf("%d\n", ELMT(arr3, l));
                // break;
            }
        }
        // l++;
    }
    printf("%d\n",listLength(arr3));
    sortList(&arr3, true);
    printList(arr3);
    printf("\n");
}