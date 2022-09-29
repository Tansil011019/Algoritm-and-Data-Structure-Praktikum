#include<stdio.h>
#include "listdin.h"
// #include "listdin.c"

int main(){
    ListDin arr1, arr2, arr3;
    CreateListDin(&arr1, 200);
    CreateListDin(&arr2, 200);
    CreateListDin(&arr3, 200);
    readList(&arr1);
    readList(&arr2);
    NEFF(arr3)=NEFF(arr1);
    int i, j;
    int sum = NEFF(arr3);
    for(i=0; i<NEFF(arr1); i++){
        ELMT(arr3, i) = ELMT (arr1, i);
    }
    for(j=0; j<NEFF(arr2); j++){
        if(indexOf(arr3, ELMT(arr2, j))==IDX_UNDEF){
            insertLast(&arr3, ELMT(arr2, j));
            sum+=1;
        }
    }
    sort(&arr3, true);
    NEFF(arr3)= sum;
    printf("%d\n", NEFF(arr3));
    printList(arr3);
    printf("\n");
    dealocateList(&arr1);
    dealocateList(&arr2);
    dealocateList(&arr3);
    return 0;
}