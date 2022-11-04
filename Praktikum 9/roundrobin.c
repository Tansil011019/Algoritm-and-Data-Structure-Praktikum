#include <stdio.h>
#include "list_circular.h"

int main(){
    List l;
    CreateList(&l);
    ElType TQ, value;
    char operation;
    do{
        // printf("!");
        scanf("%d", &TQ);
    }while(TQ<=0);

    do{
        // printf("!");
        scanf(" %c", &operation);
        if(operation == 'A'){
            scanf("%d", &value);
            if(value > 0){
                insertFirst(&l, value);
            }
        }else if(operation == 'D'){
            deleteRR(&l, TQ);
        }else if(operation == 'F'){
            if(isEmpty(l)){
                printf("Proses Selesai\n");
            }else{
                float ave= average(l);
                printf("%.2f\n", ave);
            }
        }else{
            printf("Kode Salah\n");
        }
        // displayList(l);
        // printf("\n");
    }while (operation != 'F');
}