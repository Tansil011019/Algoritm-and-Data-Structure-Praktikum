#include <stdio.h>
#include "list_circular.h"

int main(){
    int N, k;
    scanf("%d", &N);
    scanf("%d", &k);
    List l;
    CreateList(&l);
    for(int i= 1; i<=N; i++){
        insertLast(&l, i);
    }
    boolean left_one= false;
    int count= 2;
    Address prev_loc= FIRST(l);
    Address loc= NEXT(prev_loc);
    if(k==1){
        for(int i= 1; i<=N; i++){
            if(i==N){
                printf("Pemenang %d\n", i);
            }else{
                printf("%d\n", i);
            }
        }
    }else{
        while (!left_one){
            if(prev_loc == NEXT(prev_loc)){
                left_one= true;
            }else{
                if(count == k){
                    printf("%d\n", INFO(loc));
                    NEXT(prev_loc)= NEXT(loc);
                    count= 2;
                }else{
                    count++;
                }
                prev_loc= NEXT(prev_loc);
                loc= NEXT(prev_loc);
            }
        }
        printf("Pemenang %d\n", INFO(prev_loc));
    }
}