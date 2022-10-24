#include <stdio.h>
#include "listlinier.h"

int main(){
    List l;
    ElType val;
    CreateList(&l);
    displayList(l);
    insertFirst(&l, 1);
    insertAt(&l, 2, 1);
    insertLast(&l, 3);
    displayList(l);
    printf("%d\n", length(l));
    printf("%d\n", getElmt(l, 0));
    setElmt(&l, 0, 4);
    displayList(l);
    printf("%d\n", getElmt(l, 0));
    deleteAt(&l, 0, &val);
    displayList(l);
    printf("%d\n", getElmt(l, 1));
    deleteAt(&l, 1, &val);
    displayList(l);
    printf("%d\n", isEmpty(l));
    deleteFirst(&l, &val);
    printf("%d\n", isEmpty(l));
    return 0;
}