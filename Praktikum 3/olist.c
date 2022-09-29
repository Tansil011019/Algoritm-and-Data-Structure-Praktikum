#include <stdio.h>
#include "liststatik.h"
// #include "liststatik.c"

int main(){
    ListStatik arr;
    readList(&arr);
    int number, i;
    scanf("%d", &number);
    printList(arr);
    boolean found = false;
    int total = 0;
    for(i= 0; i<listLength(arr); i++){
        if(ELMT(arr, i)==number){
            total+=1;
        }
    }
    int len = listLength(arr)-1;
    if(total>0){
        while (!found && len>=0){
            if(ELMT(arr, len)==number){
                found = true;
            }
            len--;
        }
        printf("\n%d\n%d\n", total, len+1);
        int max, min;
        extremeValues(arr, &max, &min);
        if(max == number){
            printf("maksimum\n");
        }
        if(min == number){
            printf("minimum\n");
        }
        sortList(&arr, true);
        int median;
        if(listLength(arr) % 2 !=0){
            median= ELMT(arr, listLength(arr)/2);
        }else{
            median= ELMT(arr, (listLength(arr)/2)-1);
        }
        if(median == number){
            printf("median\n");
        }
    }else{
        len=0;
        printf("\n%d\n%d tidak ada", total, number);
    }
    return 0;
}