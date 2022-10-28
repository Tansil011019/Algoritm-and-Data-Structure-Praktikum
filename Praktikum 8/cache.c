#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "listlinier.h"

int main(){
    int list_len, operation;
    List l;
    CreateList(&l);
    scanf("%d", &list_len);
    scanf("%d", &operation);
    int hit_count= 0;
    int temp_operation= operation;
    int count= 0;
    if(operation == 0){
        printf("hit ratio: 0.00\n");
    }else{
        do{
            ElType val;
            scanf("%d", &val);
            boolean found= false;
            Address p= FIRST(l);
            while(p!= NULL && !found){
                if(INFO(p)==val){
                    found= true;
                }else{
                    p = NEXT(p);
                }
            }
            if (found){
                printf("hit ");
                deleteAt(&l, indexOf(l, val), &val);
                insertFirst(&l, val);
                displayList(l);
                printf("\n");
                hit_count++;
            }else{
                printf("miss ");
                if(list_len==0){

                }else if(count < list_len){
                    insertFirst(&l, val);
                    count++;
                }else{
                    ElType temp;
                    deleteLast(&l, &temp);
                    insertFirst(&l, val);
                }
                displayList(l);
                printf("\n");
            }
            temp_operation--;
        }while(temp_operation>0);
        printf("hit ratio: %.2f\n", (float)hit_count/(double)operation);
    }
}