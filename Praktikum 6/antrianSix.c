#include <stdio.h>
#include "queue.h"
// #include "queue.c"

int main(){
    Queue q;
    int done_list [CAPACITY];
    int choice, num, val, total=0, ready = 0, count =0;
    CreateQueue(&q);
    do{
        scanf("%d", &choice);
        if(choice == 1){
            scanf("%d", &num);
            if(count == CAPACITY){
                printf("Queue penuh\n");
            }else{
                enqueue(&q, num);
                count++;
            }
        }else if(choice == 2){
            if(count == 0){
                printf("Queue kosong\n");
            }else{
                dequeue(&q, &val);
                total += val;
                done_list[ready]= val; 
                ready++;
                count--;
            }
        }
    }while(choice != 0);
    // for(int i=0; i<ready; i++){
    //     printf("%d ", done_list[i]);
    // }
    printf("%d\n", ready);
    int max = done_list[0], min = done_list[0];
    if(ready == 0){
        printf("Tidak bisa dihitung\n");
        printf("Tidak bisa dihitung\n");
    }else{
        for(int i=0; i<ready; i++){
            if(max < done_list[i]){
                max = done_list[i];
            }
            if(min > done_list[i]){
                min = done_list[i];
            }
        }
        printf("%d\n%d\n", min, max);
    }
    if(ready == 0){
        printf("Tidak bisa dihitung\n");
    }else{
        printf("%.2f\n", (float)total/(float)ready);
    }
}